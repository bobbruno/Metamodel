
CREATE OR REPLACE
procedure WAREHOUSE.borra_dimen(p_dimen in number,
                      p_nivl_desde in number default 0,
                      p_nivl_hasta in number default 99) is
   i pls_integer;
begin
   commit;
   set transaction use rollback segment r01;
   i:= 1;
   for r_instan in (
      select ROWID rid, NU_INSTAN_DIMEN
         from G3_INSTAN_DIMEN
         where NU_DIMEN = p_dimen and
               NU_NIVL_LOGC_DIMEN between p_nivl_desde and
                                          p_nivl_hasta)
   loop
   begin
      savepoint INST_ATUAL;
      delete from G3_INSTAN_DIMEN_INSTAN_DIMEN
         where NU_DIMEN_PADRE = p_dimen and
               NU_INSTAN_DIMEN_PADRE = r_instan.NU_INSTAN_DIMEN;
      delete from G3_INSTAN_ATRB_DIMEN
         where NU_DIMEN = p_dimen and
               NU_INSTAN_DIMEN = r_instan.NU_INSTAN_DIMEN;
      delete from G3_INSTAN_DIMEN_INSTAN_DIMEN
         where NU_DIMEN_PADRE = p_dimen and
               NU_INSTAN_DIMEN_HIJO = r_instan.NU_INSTAN_DIMEN;
      delete from G3_COD_INSTAN_DIMEN
         where NU_DIMEN = p_dimen and
               NU_INSTAN_DIMEN = r_instan.NU_INSTAN_DIMEN;
      delete from G3_INSTAN_DIMEN where
         ROWID = r_instan.rid;
      i:= i + 1;
      if i > 500 then
         commit;
         set transaction use rollback segment r01;
         i:= 1;
      end if;
   exception
      when OTHERS then
         rollback to INST_ATUAL;
   end;
   end loop;
   commit;
end;
/

CREATE OR REPLACE
procedure WAREHOUSE.Valida_Dimen(P_Dimen in Number) is
   L_NM_INSTAN_DIMEN G3_INSTAN_DIMEN.NM_INSTAN_DIMEN%type;
   L_NIVL_LOGC_MAX   G3_NIVL_LOGC_DIMEN.NU_NIVL_LOGC_DIMEN%type;
begin
   G3_Log_Err.Inic_Log('VLDIM');

   /* Primeira validação: buscando órfãos */
   for r_dimen in (SELECT * FROM G3_INSTAN_DIMEN
                      WHERE NU_DIMEN = P_Dimen AND
                            NU_INSTAN_DIMEN not in (
                               select NU_INSTAN_DIMEN_HIJO
                                  from G3_INSTAN_DIMEN_INSTAN_DIMEN
                                  where NU_DIMEN_HIJO = P_Dimen) and
                            NU_NIVL_LOGC_DIMEN > 1)
   loop
      G3_Log_Err.Log_Err_Atrib('Instancia Huérfano', 0, sysdate,
         r_dimen.nm_instan_dimen, r_dimen.nu_dimen,
         0, r_dimen.nu_instan_dimen);
   end loop;  -- Validação de órfãos

   /* Segunda Validação: buscando filhos com dois pais */
   for r_dimen in (SELECT NU_INSTAN_DIMEN_HIJO NU_INSTAN_DIMEN, COUNT(*) Cantidad
                      from G3_INSTAN_DIMEN_INSTAN_DIMEN
                      where NU_DIMEN_HIJO = P_Dimen
                      group by NU_INSTAN_DIMEN_HIJO
                      having count(*) > 1)
   loop
      select NM_INSTAN_DIMEN
         into L_NM_INSTAN_DIMEN
         from G3_INSTAN_DIMEN
         where NU_DIMEN = P_Dimen and
               NU_INSTAN_DIMEN = r_dimen.NU_INSTAN_DIMEN;

      G3_Log_Err.Log_Err_Atrib('Instancia tiene ' || r_dimen.Cantidad ||
         ' padres', 0, sysdate, l_nm_instan_dimen, P_Dimen,
         0, r_dimen.nu_instan_dimen);
   end loop;  -- filhos com dois pais

   /* Terceira validação: nível físico maior que o lógico */
   for r_dimen in (SELECT * FROM G3_INSTAN_DIMEN
                      WHERE NU_DIMEN = P_Dimen AND
                            NU_NIVL_INSTAN_DIMEN > NU_NIVL_LOGC_DIMEN)
   loop
      G3_Log_Err.Log_Err_Atrib('Instancia con nivel físico ' ||
         r_dimen.NU_NIVL_INSTAN_DIMEN || ' y nivel logico ' ||
         r_dimen.NU_NIVL_LOGC_DIMEN, 0, sysdate,
         r_dimen.nm_instan_dimen, r_dimen.nu_dimen,
         0, r_dimen.nu_instan_dimen);
   end loop;  -- nivel fisico maior que o logico

   /* Quarta validação: Suposta folha com filhos */
   select max(NU_NIVL_LOGC_DIMEN)
      into L_NIVL_LOGC_MAX
      from G3_NIVL_LOGC_DIMEN
      where NU_DIMEN = P_Dimen;
   for r_dimen in (SELECT * FROM G3_INSTAN_DIMEN
                      WHERE NU_DIMEN = P_Dimen AND
                            NU_NIVL_LOGC_DIMEN = L_NIVL_LOGC_MAX and
                            NU_INSTAN_DIMEN in (
                               select NU_INSTAN_DIMEN_PADRE
                                  from G3_INSTAN_DIMEN_INSTAN_DIMEN
                                  where NU_DIMEN_PADRE = P_Dimen))
   loop
      G3_Log_Err.Log_Err_Atrib('Hoja con hijos', 0, sysdate,
         r_dimen.nm_instan_dimen, r_dimen.nu_dimen,
         0, r_dimen.nu_instan_dimen);
   end loop;   -- folhas com filhos

   /* Quinta validação: pai de mais de um nível acima */
   for r_dimen in (SELECT II.NU_INSTAN_DIMEN_HIJO, IH.NM_INSTAN_DIMEN HIJO,
                          II.NU_INSTAN_DIMEN_PADRE, IP.NM_INSTAN_DIMEN PADRE
                      from G3_INSTAN_DIMEN_INSTAN_DIMEN II,
                           G3_INSTAN_DIMEN IP,
                           G3_INSTAN_DIMEN IH
                      where II.NU_DIMEN_PADRE = P_Dimen and
                            II.NU_DIMEN_HIJO  = P_Dimen and
                            IP.NU_DIMEN       = P_Dimen and
                            IH.NU_DIMEN       = P_Dimen and
                            II.NU_INSTAN_DIMEN_PADRE = IP.NU_INSTAN_DIMEN and
                            II.NU_INSTAN_DIMEN_HIJO = IH.NU_INSTAN_DIMEN and
                            IH.NU_NIVL_LOGC_DIMEN - IP.NU_NIVL_LOGC_DIMEN > 1)
   loop
      G3_Log_Err.Log_Err_Atrib('Aviso: Hijo ' || R_DIMEN.NU_INSTAN_DIMEN_HIJO || '(' ||
         R_DIMEN.HIJO || ') tiene padre ' || R_DIMEN.NU_INSTAN_DIMEN_PADRE || '(' ||
         R_DIMEN.PADRE || ') de más de un nivel arriba.', 0, sysdate,
         r_dimen.hijo, P_Dimen,
         0, r_dimen.nu_instan_dimen_hijo);
   end loop;

   /* Sexta validação: instancias sem hierarquia com filhos */
   for r_dimen in (SELECT * from G3_INSTAN_DIMEN
                      WHERE NU_DIMEN = P_Dimen and
                            CD_JRQC_INSTAN_DIMEN = '0' and
                            NU_INSTAN_DIMEN in (
                               SELECT NU_INSTAN_DIMEN_PADRE
                                  from G3_INSTAN_DIMEN_INSTAN_DIMEN
                                  where NU_DIMEN_PADRE = P_Dimen))
   loop
      G3_Log_Err.Log_Err_Atrib('Instancia con hijos sin señalizar en CD_JRQC_INSTAN_DIMEN',
         0, sysdate, r_dimen.nm_instan_dimen, r_dimen.nu_dimen,
         0, r_dimen.nu_instan_dimen);
   end loop;

   /* Sétima validação: instancias com hierarquia sem filhos */
   for r_dimen in (SELECT * from G3_INSTAN_DIMEN
                      WHERE NU_DIMEN = P_Dimen and
                            CD_JRQC_INSTAN_DIMEN = '1' and
                            NU_INSTAN_DIMEN not in (
                               SELECT NU_INSTAN_DIMEN_PADRE
                                  from G3_INSTAN_DIMEN_INSTAN_DIMEN
                                  where NU_DIMEN_PADRE = P_Dimen))
   loop
      G3_Log_Err.Log_Err_Atrib('Instancia sin hijos marcadas con CD_JRQC_INSTAN_DIMEN',
         0, sysdate, r_dimen.nm_instan_dimen, r_dimen.nu_dimen,
         0, r_dimen.nu_instan_dimen);
   end loop;

   G3_Log_Err.Termina_Log;
end;
/
