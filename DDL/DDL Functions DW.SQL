
CREATE OR REPLACE
function WAREHOUSE.Del_Instan_Ok(P_Dimen in NUMBER, P_Nivl in NUMBER, P_Instan in NUMBER) return BOOLEAN is
   L_Cursor INTEGER;
   L_Dummy  PLS_INTEGER;
   L_Tx_SQL VARCHAR2(2000);
begin
   L_Cursor:= dbms_sql.open_cursor;
   for R_Vision in (
      select NU_VISION, decode(P_Dimen, NU_DIMEN__1, 1, NU_DIMEN__2, 2, NU_DIMEN__3, 3, NU_DIMEN__4, 4,
                NU_DIMEN__5, 5, NU_DIMEN__6, 6, NU_DIMEN__7, 7, NU_DIMEN__8, 8,
                NU_DIMEN__9, 9, NU_DIMEN__10, 10, NU_DIMEN__11, 11, NU_DIMEN__12, 12,
                NU_DIMEN__13, 13, NU_DIMEN__14, 14, NU_DIMEN__15, 15, 16) NU_DIMEN
    from G3_VISION
    where (NU_DIMEN__1 = P_Dimen) or
          (NU_DIMEN__2 = P_Dimen) or
          (NU_DIMEN__3 = P_Dimen) or
          (NU_DIMEN__4 = P_Dimen) or
          (NU_DIMEN__5 = P_Dimen) or
          (NU_DIMEN__6 = P_Dimen) or
          (NU_DIMEN__7 = P_Dimen) or
          (NU_DIMEN__8 = P_Dimen) or
          (NU_DIMEN__9 = P_Dimen) or
          (NU_DIMEN__10 = P_Dimen) or
          (NU_DIMEN__11 = P_Dimen) or
          (NU_DIMEN__12 = P_Dimen) or
          (NU_DIMEN__13 = P_Dimen) or
          (NU_DIMEN__14 = P_Dimen) or
          (NU_DIMEN__15 = P_Dimen) or
          (NU_DIMEN__16 = P_Dimen))
   loop
      for R_Tabla in (
    select NM_TABLA_SH
       from G3_TABLA_SH T,
       G3_TABLA_SH_VISION V
       where T.NU_TABLA_SH = V.NU_TABLA_SH and
        T.NU_NIVL_LOGC_MAX <= P_Nivl and
        T.NU_NIVL_LOGC_MIN >= P_Nivl and
        V.NU_VISION = R_Vision.NU_VISION)
      loop
    for R_Indic in (
       select NU_INDCA_PERFM
          from G3_INDCA_PERFM
          where NU_VISION = R_Vision.NU_VISION)
    loop
    begin
       L_Tx_SQL:= 'select 1 from ' || R_Tabla.NM_TABLA_SH || ' where NU_INDCA_PERFM = ' ||
             R_Indic.NU_INDCA_PERFM || ' and NU_VISION = ' || R_Vision.NU_VISION ||
             ' and NU_INSTAN_DIMEN__' || R_Vision.NU_DIMEN || ' = ' || P_Instan ||
             ' and ROWNUM = 1';
       dbms_sql.parse(l_cursor, L_Tx_SQL, dbms_sql.v7);
       dbms_sql.define_column(l_cursor, 1, L_Dummy);
       L_Dummy:= dbms_sql.execute_and_fetch(l_cursor);
       if L_Dummy > 0 then
          dbms_sql.close_cursor(L_Cursor);
          return FALSE;
       end if;
    exception
       when NO_DATA_FOUND then
          NULL;
    end;
    end loop;
      end loop;
   end loop;
   dbms_sql.close_cursor(L_Cursor);
   return TRUE;
end Del_Instan_Ok;
/
