
CREATE OR REPLACE
package body WAREHOUSE.G3_LOG_ERR as
Dir_Salida_Log constant VARCHAR2(120):= 'D:\Datawarehouse\Produccion\Log';
type R_LOG is record(
   FC_MSJ      date,
   TX_MSJ      varchar2(500),
   CD_TIPO_MSJ char(1),
   NU_FUENTE   number(5),
   FC_GEN      date,
   FC_REFR     date,
   NU_INDCA    number(5),
   NU_INSTAN_1 number(8),
   NU_INSTAN_2 number(8),
   NU_INSTAN_3 number(8),
   NU_INSTAN_4 number(8),
   NU_INSTAN_5 number(8),
   NU_INSTAN_6 number(8),
   NU_INSTAN_7 number(8),
   NU_INSTAN_8 number(8),
   NU_INSTAN_9 number(8),
   NU_INSTAN_10 number(8),
   NU_INSTAN_11 number(8),
   NU_INSTAN_12 number(8),
   NU_INSTAN_13 number(8),
   NU_INSTAN_14 number(8),
   NU_INSTAN_15 number(8),
   NU_INSTAN_16 number(8),
   CD_INSTAN_1  varchar2(20),
   CD_INSTAN_2  varchar2(20),
   CD_INSTAN_3  varchar2(20),
   CD_INSTAN_4  varchar2(20),
   CD_INSTAN_5  varchar2(20),
   CD_INSTAN_6  varchar2(20),
   CD_INSTAN_7  varchar2(20),
   CD_INSTAN_8  varchar2(20),
   CD_INSTAN_9  varchar2(20),
   CD_INSTAN_10 varchar2(20),
   CD_INSTAN_11 varchar2(20),
   CD_INSTAN_12 varchar2(20),
   CD_INSTAN_13 varchar2(20),
   CD_INSTAN_14 varchar2(20),
   CD_INSTAN_15 varchar2(20),
   CD_INSTAN_16 varchar2(20),
   CT_DATO      number(25, 7),
   NU_DIMEN     number(5),
   NU_INSTAN_DIMEN number(8),
   NU_ATRB_DIMEN   number(5),
   CD_INSTAN_DIMEN varchar2(20),
   TX_ATRB         varchar2(2000)
);
type T_LOG is table of R_LOG index by binary_integer;
LOG_MSG     T_LOG;
LOG_CTRL binary_integer:= 0;
LOG_NM_RUTINA  varchar2(5):= NULL;
LOG_FC_INIC date:= NULL;
LOG_UID     number(5);
----------------------------------------------------------------------
--   Procedure: Inic_Log
--      Inicializa los controles para registrar mensajes de log.
--   Parametros:
--      P_Nm_Rutina: Nombre de la rutina generadora de mensajes
----------------------------------------------------------------------
procedure Inic_Log(P_Nm_Rutina in VARCHAR2) is
begin
   if Log_Nm_Rutina is not NULL then
      Termina_Log;
   end if;
   Log_Ctrl:= 1;
   Log_Fc_Inic:= sysdate;
   Log_Nm_Rutina:= P_Nm_Rutina;
   select UID
      into LOG_UID
      from DUAL;

   Log_Msj('D', 'Inicio del log.');
exception
   when STORAGE_ERROR then
      NULL;
   when OTHERS then NULL;
end Inic_Log;
-------------------------------------------------------------------------
--  Procedure: Log_Err_Sh_Nu
--     Registra un mensaje de error en un registro de datos. El error
--     ocurrio despues de la traduccion de las dimensiones.
-------------------------------------------------------------------------
procedure Log_Err_SH_Nu(
   P_Texto in varchar2,       /* Texto de la mensaje */
   P_Fuente in number,        /* Fuente de los datos */
   P_Fc_Gen in date,       /* Fecha de generacion */
   P_Fc_Refr in date,         /* Fecha de referencia */
   P_Nu_Indca in number,         /* Codigo del indicador */
   P_Ct_Dato in number,       /* Valor del dato */
   P_Nu_Instan_1 in number,      /* Instancia 1 (numero) */
   P_Nu_Instan_2 in number:= NULL,     /* Instancia 2 (numero) */
   P_Nu_Instan_3 in number:= NULL,     /* Instancia 3 (numero) */
   P_Nu_Instan_4 in number:= NULL,     /* Instancia 4 (numero) */
   P_Nu_Instan_5 in number:= NULL,     /* Instancia 5 (numero) */
   P_Nu_Instan_6 in number:= NULL,     /* Instancia 6 (numero) */
   P_Nu_Instan_7 in number:= NULL,     /* Instancia 7 (numero) */
   P_Nu_Instan_8 in number:= NULL,     /* Instancia 8 (numero) */
   P_Nu_Instan_9 in number:= NULL,     /* Instancia 9 (numero) */
   P_Nu_Instan_10 in number:= NULL, /* Instancia 10 (numero) */
   P_Nu_Instan_11 in number:= NULL, /* Instancia 11 (numero) */
   P_Nu_Instan_12 in number:= NULL, /* Instancia 12 (numero) */
   P_Nu_Instan_13 in number:= NULL, /* Instancia 13 (numero) */
   P_Nu_Instan_14 in number:= NULL, /* Instancia 14 (numero) */
   P_Nu_Instan_15 in number:= NULL, /* Instancia 15 (numero) */
   P_Nu_Instan_16 in number:= NULL) is /* Instancia 16 (numero) */
begin
   LOG_MSG(LOG_CTRL).FC_MSJ:= SYSDATE;
   LOG_MSG(LOG_CTRL).TX_MSJ:= P_Texto;
   LOG_MSG(LOG_CTRL).CD_TIPO_MSJ:= 'E';
   LOG_MSG(LOG_CTRL).NU_FUENTE:= P_Fuente;
   LOG_MSG(LOG_CTRL).FC_GEN:= P_Fc_Gen;
   LOG_MSG(LOG_CTRL).FC_REFR:= P_Fc_Refr;
   LOG_MSG(LOG_CTRL).NU_INDCA:= P_Nu_Indca;
   LOG_MSG(LOG_CTRL).NU_INSTAN_1:= P_Nu_Instan_1;
   LOG_MSG(LOG_CTRL).NU_INSTAN_2:= P_Nu_Instan_2;
   LOG_MSG(LOG_CTRL).NU_INSTAN_3:= P_Nu_Instan_3;
   LOG_MSG(LOG_CTRL).NU_INSTAN_4:= P_Nu_Instan_4;
   LOG_MSG(LOG_CTRL).NU_INSTAN_5:= P_Nu_Instan_5;
   LOG_MSG(LOG_CTRL).NU_INSTAN_6:= P_Nu_Instan_6;
   LOG_MSG(LOG_CTRL).NU_INSTAN_7:= P_Nu_Instan_7;
   LOG_MSG(LOG_CTRL).NU_INSTAN_8:= P_Nu_Instan_8;
   LOG_MSG(LOG_CTRL).NU_INSTAN_9:= P_Nu_Instan_9;
   LOG_MSG(LOG_CTRL).NU_INSTAN_10:= P_Nu_Instan_10;
   LOG_MSG(LOG_CTRL).NU_INSTAN_11:= P_Nu_Instan_11;
   LOG_MSG(LOG_CTRL).NU_INSTAN_12:= P_Nu_Instan_12;
   LOG_MSG(LOG_CTRL).NU_INSTAN_13:= P_Nu_Instan_13;
   LOG_MSG(LOG_CTRL).NU_INSTAN_14:= P_Nu_Instan_14;
   LOG_MSG(LOG_CTRL).NU_INSTAN_15:= P_Nu_Instan_15;
   LOG_MSG(LOG_CTRL).NU_INSTAN_16:= P_Nu_Instan_16;
   LOG_MSG(LOG_CTRL).CD_INSTAN_1:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_2:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_3:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_4:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_5:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_6:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_7:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_8:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_9:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_10:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_11:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_12:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_13:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_14:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_15:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_16:= NULL;
   LOG_MSG(LOG_CTRL).CT_DATO:= P_Ct_Dato;
   LOG_MSG(LOG_CTRL).NU_DIMEN:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_DIMEN:= NULL;
   LOG_MSG(LOG_CTRL).NU_ATRB_DIMEN:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_DIMEN:= NULL;
   LOG_MSG(LOG_CTRL).TX_ATRB:= NULL;
   log_ctrl:= log_ctrl + 1;
exception
   when STORAGE_ERROR then
      NULL;
   when OTHERS then
      NULL;
end Log_Err_SH_Nu;
-------------------------------------------------------------------------
--  Procedure: Log_Err_Sh_Cd
--     Registra un mensaje de error en un registro de datos. El error
--     ocurrio antes de la traduccion de las dimensiones.
-------------------------------------------------------------------------
procedure Log_Err_SH_Cd(
   P_Texto in varchar2,       /* Texto de la mensaje */
   P_Fuente in number,        /* Fuente de los datos */
   P_Fc_Gen in date,       /* Fecha de generacion */
   P_Fc_Refr in date,         /* Fecha de referencia */
   P_Nu_Indca in number,         /* Codigo del indicador */
   P_Ct_Dato in number,       /* Valor del dato */
   P_Cd_Instan_1 in varchar2,    /* Instancia 1 (codigo) */
   P_Cd_Instan_2 in varchar2:= NULL,   /* Instancia 2 (codigo) */
   P_Cd_Instan_3 in varchar2:= NULL,   /* Instancia 3 (codigo) */
   P_Cd_Instan_4 in varchar2:= NULL,   /* Instancia 4 (codigo) */
   P_Cd_Instan_5 in varchar2:= NULL,   /* Instancia 5 (codigo) */
   P_Cd_Instan_6 in varchar2:= NULL,   /* Instancia 6 (codigo) */
   P_Cd_Instan_7 in varchar2:= NULL,   /* Instancia 7 (codigo) */
   P_Cd_Instan_8 in varchar2:= NULL,   /* Instancia 8 (codigo) */
   P_Cd_Instan_9 in varchar2:= NULL,   /* Instancia 9 (codigo) */
   P_Cd_Instan_10 in varchar2:= NULL,  /* Instancia 10 (codigo) */
   P_Cd_Instan_11 in varchar2:= NULL,  /* Instancia 11 (codigo) */
   P_Cd_Instan_12 in varchar2:= NULL,  /* Instancia 12 (codigo) */
   P_Cd_Instan_13 in varchar2:= NULL,  /* Instancia 13 (codigo) */
   P_Cd_Instan_14 in varchar2:= NULL,  /* Instancia 14 (codigo) */
   P_Cd_Instan_15 in varchar2:= NULL,  /* Instancia 15 (codigo) */
   P_Cd_Instan_16 in varchar2:= NULL) is  /* Instancia 16 (codigo) */
begin
   LOG_MSG(LOG_CTRL).FC_MSJ:= SYSDATE;
   LOG_MSG(LOG_CTRL).TX_MSJ:= P_Texto;
   LOG_MSG(LOG_CTRL).CD_TIPO_MSJ:= 'E';
   LOG_MSG(LOG_CTRL).NU_FUENTE:= P_Fuente;
   LOG_MSG(LOG_CTRL).FC_GEN:= P_Fc_Gen;
   LOG_MSG(LOG_CTRL).FC_REFR:= P_Fc_Refr;
   LOG_MSG(LOG_CTRL).NU_INDCA:= P_Nu_Indca;
   LOG_MSG(LOG_CTRL).CD_INSTAN_1:= P_Cd_Instan_1;
   LOG_MSG(LOG_CTRL).CD_INSTAN_2:= P_Cd_Instan_2;
   LOG_MSG(LOG_CTRL).CD_INSTAN_3:= P_Cd_Instan_3;
   LOG_MSG(LOG_CTRL).CD_INSTAN_4:= P_Cd_Instan_4;
   LOG_MSG(LOG_CTRL).CD_INSTAN_5:= P_Cd_Instan_5;
   LOG_MSG(LOG_CTRL).CD_INSTAN_6:= P_Cd_Instan_6;
   LOG_MSG(LOG_CTRL).CD_INSTAN_7:= P_Cd_Instan_7;
   LOG_MSG(LOG_CTRL).CD_INSTAN_8:= P_Cd_Instan_8;
   LOG_MSG(LOG_CTRL).CD_INSTAN_9:= P_Cd_Instan_9;
   LOG_MSG(LOG_CTRL).CD_INSTAN_10:= P_Cd_Instan_10;
   LOG_MSG(LOG_CTRL).CD_INSTAN_11:= P_Cd_Instan_11;
   LOG_MSG(LOG_CTRL).CD_INSTAN_12:= P_Cd_Instan_12;
   LOG_MSG(LOG_CTRL).CD_INSTAN_13:= P_Cd_Instan_13;
   LOG_MSG(LOG_CTRL).CD_INSTAN_14:= P_Cd_Instan_14;
   LOG_MSG(LOG_CTRL).CD_INSTAN_15:= P_Cd_Instan_15;
   LOG_MSG(LOG_CTRL).CD_INSTAN_16:= P_Cd_Instan_16;
   LOG_MSG(LOG_CTRL).NU_INSTAN_1:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_2:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_3:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_4:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_5:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_6:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_7:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_8:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_9:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_10:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_11:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_12:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_13:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_14:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_15:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_16:= NULL;
   LOG_MSG(LOG_CTRL).CT_DATO:= P_Ct_Dato;
   LOG_MSG(LOG_CTRL).NU_DIMEN:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_DIMEN:= NULL;
   LOG_MSG(LOG_CTRL).NU_ATRB_DIMEN:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_DIMEN:= NULL;
   LOG_MSG(LOG_CTRL).TX_ATRB:= NULL;
   log_ctrl:= log_ctrl + 1;
exception
   when STORAGE_ERROR then
      NULL;
   when OTHERS then
      NULL;
end Log_Err_SH_Cd;
---------------------------------------------------------------------------
--  Procedure: Log_Err_Atrib
--     Guarda mensajes de errores en la carga de atributos de datos.
---------------------------------------------------------------------------
   procedure Log_Err_Atrib(
   P_Texto in varchar2,       /* Texto de la mensaje */
   P_Fuente in number,        /* Fuente de los datos */
   P_Fc_Gen in date,       /* Fecha de generacion */
   P_Tx_Atrb in varchar2,        /* Valor del atributo */
   P_Nu_Dimen in number,         /* Dimension siendo importada */
   P_Nu_Atrb_Dimen in number,    /* Atributo siendo importado */
   P_Nu_Instan_Dimen in number:= NULL, /* Instancia siendo importada */
   P_Cd_Instan_Dimen in varchar2:= NULL) is  /* Instancia siendo importada */
begin
   LOG_MSG(LOG_CTRL).FC_MSJ:= SYSDATE;
   LOG_MSG(LOG_CTRL).TX_MSJ:= P_Texto;
   LOG_MSG(LOG_CTRL).CD_TIPO_MSJ:= 'E';
   LOG_MSG(LOG_CTRL).NU_FUENTE:= P_Fuente;
   LOG_MSG(LOG_CTRL).FC_GEN:= P_Fc_Gen;
   LOG_MSG(LOG_CTRL).NU_DIMEN:= P_Nu_Dimen;
   LOG_MSG(LOG_CTRL).NU_INSTAN_DIMEN:= P_Nu_Instan_Dimen;
   LOG_MSG(LOG_CTRL).NU_ATRB_DIMEN:= P_Nu_Atrb_Dimen;
   LOG_MSG(LOG_CTRL).CD_INSTAN_DIMEN:= P_Cd_Instan_Dimen;
   LOG_MSG(LOG_CTRL).TX_ATRB:= P_Tx_Atrb;
   LOG_MSG(LOG_CTRL).FC_REFR:= NULL;
   LOG_MSG(LOG_CTRL).NU_INDCA:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_1:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_2:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_3:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_4:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_5:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_6:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_7:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_8:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_9:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_10:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_11:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_12:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_13:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_14:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_15:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_16:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_1:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_2:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_3:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_4:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_5:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_6:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_7:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_8:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_9:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_10:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_11:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_12:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_13:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_14:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_15:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_16:= NULL;
   LOG_MSG(LOG_CTRL).CT_DATO:= NULL;
   log_ctrl:= log_ctrl + 1;
exception
   when STORAGE_ERROR then
      NULL;
   when OTHERS then
      NULL;
end Log_Err_Atrib;
-------------------------------------------------------------------------
--  Procedure: Log_Msj
--     Guarda mensajes generales en el log.
-------------------------------------------------------------------------
procedure Log_Msj(
   P_Tipo_Msj in char,        /* Tipo de la mensaje */
   P_Texto in varchar2) is       /* Texto de la mensaje */
begin
   LOG_MSG(LOG_CTRL).FC_MSJ:= SYSDATE;
   LOG_MSG(LOG_CTRL).TX_MSJ:= P_Texto;
   LOG_MSG(LOG_CTRL).CD_TIPO_MSJ:= P_Tipo_Msj;
   LOG_MSG(LOG_CTRL).NU_FUENTE:= NULL;
   LOG_MSG(LOG_CTRL).FC_GEN:= NULL;
   LOG_MSG(LOG_CTRL).NU_DIMEN:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_DIMEN:= NULL;
   LOG_MSG(LOG_CTRL).NU_ATRB_DIMEN:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_DIMEN:= NULL;
   LOG_MSG(LOG_CTRL).TX_ATRB:= NULL;
   LOG_MSG(LOG_CTRL).FC_REFR:= NULL;
   LOG_MSG(LOG_CTRL).NU_INDCA:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_1:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_2:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_3:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_4:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_5:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_6:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_7:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_8:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_9:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_10:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_11:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_12:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_13:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_14:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_15:= NULL;
   LOG_MSG(LOG_CTRL).CD_INSTAN_16:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_1:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_2:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_3:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_4:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_5:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_6:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_7:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_8:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_9:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_10:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_11:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_12:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_13:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_14:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_15:= NULL;
   LOG_MSG(LOG_CTRL).NU_INSTAN_16:= NULL;
   LOG_MSG(LOG_CTRL).CT_DATO:= NULL;
   log_ctrl:= log_ctrl + 1;
exception
   when STORAGE_ERROR then
      NULL;
   when OTHERS then
      NULL;
end Log_Msj;
------------------------------------------------------------------------
--  Procedure: Archiva_Log_Term
--     Envia el log de errores para la pantalla cuando
--     no se puede grabar en la tabla de log, por algun problema.
------------------------------------------------------------------------
procedure Archiva_Log_Term is
   i binary_integer;
   Aux_Log R_LOG;
begin
   if LOG_NM_RUTINA is not NULL then
      for i in LOG_MSG.FIRST..Log_Ctrl-1 loop
      begin
         Aux_Log:= LOG_MSG(i);
    dbms_output.put_line('Rutina: ' || Log_Nm_Rutina);
    dbms_output.put_line('Usuario: ' || Log_UID);
    dbms_output.put_line('Fecha Inic. Log: ' || Log_Fc_Inic);
    dbms_output.put_line('Fecha Msj: ' || Aux_Log.FC_MSJ);
    dbms_output.put_line('Mensaje: ' || Aux_Log.TX_MSJ);
    dbms_output.put_line('Tipo ' || Aux_Log.CD_TIPO_MSJ);
    dbms_output.put_line('Fuente: ' || Aux_Log.NU_FUENTE);
    dbms_output.put_line('Fecha Gen: ' || Aux_Log.FC_GEN);
      end;
      LOG_MSG.delete(i);
      end loop;
   end if;
exception
   when OTHERS then
      NULL;
end;

------------------------------------------------------------------------
--  Procedure: Archiva_Log
--     Envia el log de errores para un archivo cuando
--     no se puede grabar en la tabla de log, por algun problema.
------------------------------------------------------------------------
procedure Archiva_Log is
   i binary_integer;
   Aux_Log R_LOG;
   f UTL_FILE.FILE_TYPE;
   fName VARCHAR2(40);
begin
   if LOG_NM_RUTINA is not NULL then
      select to_char(Log_Fc_Inic, 'DDMMHH24MISS') || '.LOGERR.' ||
             Log_Nm_Rutina || '.' || Log_UID
         into fName
         from DUAL;
      f:= UTL_FILE.fopen(Dir_Salida_Log, fName, 'w');
      UTL_FILE.putf(f, 'Sistema Data Warehouse\n' ||
            'Log de Mensajes del procesamiento de la rutina %s\n' ||
            'Generado en %s por el usuario %s\n' ||
            '-----------------------------------------------------------\n',
            Log_Nm_Rutina, to_char(Log_Fc_Inic, 'DD/MM/YYY HH24:MI:SS'),
            to_char(Log_UID));
      for i in LOG_MSG.FIRST..Log_Ctrl-1 loop
      begin
         Aux_Log:= LOG_MSG(i);
         if (Aux_Log.CD_TIPO_MSJ = 'E') then
            UTL_FILE.put_line(f, '#### Error ####');
         elsif (Aux_Log.CD_TIPO_MSJ = 'A') then
            UTL_FILE.put_line(f, '## Aviso ##');
         else
            UTL_FILE.new_line(f);
         end if;

         UTL_FILE.putf(f, 'Mensaje %s en %s:\n %s\n' || i, Aux_Log.FC_MSJ,  Aux_Log.TX_MSJ);
         if Aux_Log.NU_INDCA is not null then
            UTL_FILE.putf(f, 'Indicador: %s Fecha     : %s\n' ||
                     'Fuente   : %s  Generacion: %s\n', Aux_Log.NU_INDCA,  Aux_Log.FC_REFR,
                     Aux_Log.NU_FUENTE, Aux_Log.FC_GEN);
            if Aux_Log.NU_INSTAN_1 is not null then
               UTL_FILE.put_line(f, 'Numeros de instancias de dimension:');
               UTL_FILE.putf(f, 'Inst. 1: %s      Inst. 2: %s\n' ||
                        'Inst. 3: %s      Inst. 4: %s\nInst. 5: %s      ',
                        Aux_Log.NU_INSTAN_1, Aux_Log.NU_INSTAN_2, Aux_Log.NU_INSTAN_3,
                        Aux_Log.NU_INSTAN_4, Aux_Log.NU_INSTAN_5);
               UTL_FILE.putf(f, 'Inst. 6: %s\n' ||
                       'Inst. 7: %s      Inst. 8: %s\nInst. 9: %s      Inst. 10: %s\n',
                       Aux_Log.NU_INSTAN_6, Aux_Log.NU_INSTAN_7, Aux_Log.NU_INSTAN_8,
                       Aux_Log.NU_INSTAN_9, Aux_Log.NU_INSTAN_10);
               UTL_FILE.putf(f, 'Inst. 11: %s     Inst. 12: %s\n' ||
                        'Inst. 13: %s     Inst. 14: %s\nInst. 15: %s     ',
                        Aux_Log.NU_INSTAN_11, Aux_Log.NU_INSTAN_12, Aux_Log.NU_INSTAN_13,
                        Aux_Log.NU_INSTAN_14, Aux_Log.NU_INSTAN_15);
               UTL_FILE.putf(f, 'Inst. 16: %s\n', Aux_Log.NU_INSTAN_16);
            end if;
            if Aux_Log.CD_INSTAN_1 is not null then
               UTL_FILE.put_line(f, 'Codigos de instancias de dimension:');
               UTL_FILE.putf(f, 'Inst. 1: %s      Inst. 2: %s\n' ||
                        'Inst. 3: %s      Inst. 4: %s\nInst. 5: %s      ',
                        Aux_Log.CD_INSTAN_1, Aux_Log.CD_INSTAN_2, Aux_Log.CD_INSTAN_3,
                        Aux_Log.CD_INSTAN_4, Aux_Log.CD_INSTAN_5);
               UTL_FILE.putf(f, 'Inst. 6: %s\nInst. 7: %s      Inst. 8: %s\n' ||
                       'Inst. 9: %s      Inst. 10: %s\n', Aux_Log.CD_INSTAN_6,
                       Aux_Log.CD_INSTAN_7, Aux_Log.CD_INSTAN_8, Aux_Log.CD_INSTAN_9,
                       Aux_Log.CD_INSTAN_10);
               UTL_FILE.putf(f, 'Inst. 11: %s     Inst. 12: %s\n' ||
                        'Inst. 13: %s     Inst. 14: %s\nInst. 15: %s     ',
                        Aux_Log.CD_INSTAN_11, Aux_Log.CD_INSTAN_12, Aux_Log.CD_INSTAN_13,
                        Aux_Log.CD_INSTAN_14, Aux_Log.CD_INSTAN_15);
               UTL_FILE.putf(f, 'Inst. 16: %s\n', Aux_Log.CD_INSTAN_16);
            end if;
            UTL_FILE.putf(f, 'Valor del dato: %s\n', Aux_Log.CT_DATO);
         end if;
         if Aux_Log.Nu_Dimen is not null then
            UTL_FILE.putf(f, 'Dimen: %s     Atributo: %s\n', Aux_Log.NU_DIMEN,
                     Aux_Log.NU_ATRB_DIMEN);
            UTL_FILE.putf(f, 'Num. Inst: %s Cod. Inst: %s\n', Aux_Log.NU_INSTAN_DIMEN,
                     Aux_Log.CD_INSTAN_DIMEN);
            UTL_FILE.putf(f, 'Valor del atributo: %s\n', Aux_Log.TX_ATRB);
         end if;
      end;
      LOG_MSG.delete(i);
      end loop;
   end if;
   UTL_FILE.fclose(f);
exception
   when OTHERS then
      UTL_FILE.fclose(f);
      Archiva_Log_Term;
end;
------------------------------------------------------------------------
--  Procedure: Termina_Log
--     Termina y graba un log de mensajes. Es un error terminar un log que
--     no estea abierto. Este error sera grabado en el log.
--     IMPORTANTE: ESTA PROCEDURE EJECUTA UN COMMIT;
------------------------------------------------------------------------
procedure Termina_Log is
   i binary_integer;
   contador binary_integer;
   Aux_Log R_LOG;
begin
   Log_Msj('D', 'Fin del log.');
   if LOG_NM_RUTINA is not NULL then
      contador:= 0;
      lock table g3_log_error in exclusive mode;
      for i in 1..Log_Ctrl-1 loop
      begin
         Aux_Log:= LOG_MSG(i);
         insert into G3_LOG_ERROR(
            Nm_Rutina, Nu_Usuario,
            Fc_Inicio_Log_Error,
       Nu_Ocrr_Log_Error,
            Fc_Msj_Log_Error,
       Tx_Msj_Error,
            Cd_Tipo_Log,
            Nu_Fuente_Indca_Perfm,
            Fc_Gen_Fuente_Indca_Perfm,
            Fc_Refr_Fuente_Indca_Perfm,
            Nu_Indca_Perfm,
            Nu_Instan_Dimen__1,  Nu_Instan_Dimen__2,
            Nu_Instan_Dimen__3,  Nu_Instan_Dimen__4,
            Nu_Instan_Dimen__5,  Nu_Instan_Dimen__6,
            Nu_Instan_Dimen__7,  Nu_Instan_Dimen__8,
            Nu_Instan_Dimen__9,  Nu_Instan_Dimen__10,
            Nu_Instan_Dimen__11, Nu_Instan_Dimen__12,
            Nu_Instan_Dimen__13, Nu_Instan_Dimen__14,
            Nu_Instan_Dimen__15, Nu_Instan_Dimen__16,
            Cd_Instan_Dimen__1,  Cd_Instan_Dimen__2,
            Cd_Instan_Dimen__3,  Cd_Instan_Dimen__4,
            Cd_Instan_Dimen__5,  Cd_Instan_Dimen__6,
            Cd_Instan_Dimen__7,  Cd_Instan_Dimen__8,
            Cd_Instan_Dimen__9,  Cd_Instan_Dimen__10,
            Cd_Instan_Dimen__11, Cd_Instan_Dimen__12,
            Cd_Instan_Dimen__13, Cd_Instan_Dimen__14,
            Cd_Instan_Dimen__15, Cd_Instan_Dimen__16,
            Ct_Dato,
            Nu_Dimen,
            Nu_Instan_Dimen,
            Nu_Atrb_Dimen,
            Cd_Instan_Dimen,
            Tx_Valor_Atrb_Dimen)
       values(
          Log_Nm_Rutina,
          Log_UID,
          Log_Fc_Inic,
          i,
          Aux_Log.FC_MSJ,
          Aux_Log.TX_MSJ,
          Aux_Log.CD_TIPO_MSJ,
          Aux_Log.NU_FUENTE,
          Aux_Log.FC_GEN,
          Aux_Log.FC_REFR,
          Aux_Log.NU_INDCA,
          Aux_Log.NU_INSTAN_1,  Aux_Log.NU_INSTAN_2,
          Aux_Log.NU_INSTAN_3,  Aux_Log.NU_INSTAN_4,
          Aux_Log.NU_INSTAN_5,  Aux_Log.NU_INSTAN_6,
          Aux_Log.NU_INSTAN_7,  Aux_Log.NU_INSTAN_8,
          Aux_Log.NU_INSTAN_9,  Aux_Log.NU_INSTAN_10,
          Aux_Log.NU_INSTAN_11, Aux_Log.NU_INSTAN_12,
          Aux_Log.NU_INSTAN_13, Aux_Log.NU_INSTAN_14,
          Aux_Log.NU_INSTAN_15, Aux_Log.NU_INSTAN_16,
          Aux_Log.CD_INSTAN_1,  Aux_Log.CD_INSTAN_2,
          Aux_Log.CD_INSTAN_3,  Aux_Log.CD_INSTAN_4,
          Aux_Log.CD_INSTAN_5,  Aux_Log.CD_INSTAN_6,
          Aux_Log.CD_INSTAN_7,  Aux_Log.CD_INSTAN_8,
          Aux_Log.CD_INSTAN_9,  Aux_Log.CD_INSTAN_10,
          Aux_Log.CD_INSTAN_11, Aux_Log.CD_INSTAN_12,
          Aux_Log.CD_INSTAN_13, Aux_Log.CD_INSTAN_14,
          Aux_Log.CD_INSTAN_15, Aux_Log.CD_INSTAN_16,
          Aux_Log.CT_DATO,
          Aux_Log.NU_DIMEN,
          Aux_Log.NU_INSTAN_DIMEN,
          Aux_Log.NU_ATRB_DIMEN,
          Aux_Log.CD_INSTAN_DIMEN,
          Aux_Log.TX_ATRB);
      end;
      if (contador > 1000) then
    commit;
    lock table g3_log_error in exclusive mode;
    contador:= 0;
      end if;
      contador:= contador + 1;
      log_msg.delete(i);
      end loop;
   else
      insert into G3_LOG_ERROR(
         Nm_Rutina, Nu_Usuario,
         Fc_Inicio_Log_Error,
         Nu_Ocrr_Log_Error,
         Fc_Msj_Log_Error,
         Tx_Msj_Error,
         Cd_Tipo_Log)
         values('LOGER', UID, SYSDATE, 1,
            SYSDATE, 'Log cerrado sin antes abrir.', 'E');
   end if;
   commit;
   Log_Ctrl:= 0;
   Log_Fc_Inic:= NULL;
   Log_Nm_Rutina:= NULL;
   LOG_UID:= NULL;
   LOG_MSG.delete;
exception
   when STORAGE_ERROR then
      dbms_output.put_line('Storage: ' || SQLERRM);
      Log_Ctrl:= 0;
      Log_Fc_Inic:= NULL;
      Log_Nm_Rutina:= NULL;
      LOG_UID:= NULL;
      LOG_MSG.delete;
      commit;
   when OTHERS then  -- Algun error no me permitio guardar.
      dbms_output.put_line('Termina_Log' || SQLERRM);
      Archiva_Log;
      Log_Ctrl:= 0;
      Log_Fc_Inic:= NULL;
      Log_Nm_Rutina:= NULL;
      LOG_UID:= NULL;
      LOG_MSG.delete;
      commit;
end Termina_Log;
------------------------------------------------------------------------
--  Procedure: Aborta_Log
--     Termina, sin grabar, un log de mensajes. Es un error terminar un
--     log que no estea abierto. Este error sera grabado en el log.
------------------------------------------------------------------------
procedure Aborta_Log IS
   i binary_integer;
begin
   if LOG_NM_RUTINA is not NULL then
      LOG_MSG.delete;
   else
      insert into G3_LOG_ERROR(
         Nm_Rutina, Nu_Usuario,
         Fc_Inicio_Log_Error,
    Nu_Ocrr_Log_Error,
         Fc_Msj_Log_Error,
    Tx_Msj_Error,
         Cd_Tipo_Log)
    values('LOGER', UID, SYSDATE, 1,
       SYSDATE, 'Log cerrado sin antes abrir.', 'E');
   end if;
   Log_Ctrl:= 0;
   Log_Fc_Inic:= NULL;
   Log_Nm_Rutina:= NULL;
   LOG_UID:= NULL;
end Aborta_Log;
end G3_LOG_ERR;
/

CREATE OR REPLACE
package body WAREHOUSE.G3_PROC_ADMIN is
type T_INSTAN_DIMEN is table of G3_INSTAN_DIMEN%ROWTYPE index by binary_integer;
type T_OPER_DIMEN is table of char(1) index by binary_integer;
T_Abonos T_INSTAN_DIMEN;
T_Opers T_OPER_DIMEN;
Atualizando Boolean;
procedure SAVE_DERIV(lNU_INDCA_PERFM NUMBER,lNU_ORDEN NUMBER,
              lCD_TIPO_OPERADOR CHAR,lCD_OPERADOR CHAR, lCD_GRUPO CHAR) AS
Begin
   NULL;
END;
PROCEDURE Save_Dimensiones (lIndicador NUMBER,lOrden NUMBER) AS
BEGIN
   NULL;
END;
function Hay_Datos(P_Dimen in NUMBER, P_Inst in NUMBER) return boolean is
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
             ' and NU_INSTAN_DIMEN__' || R_Vision.NU_DIMEN || ' = ' || P_Inst ||
             ' and ROWNUM = 1';
       dbms_sql.parse(l_cursor, L_Tx_SQL, dbms_sql.v7);
       dbms_sql.define_column(l_cursor, 1, L_Dummy);
       L_Dummy:= dbms_sql.execute_and_fetch(l_cursor);
       if L_Dummy > 0 then
          dbms_sql.close_cursor(L_Cursor);
          return TRUE;
       end if;
    exception
       when NO_DATA_FOUND then
          NULL;
    end;
    end loop;
      end loop;
   end loop;
   dbms_sql.close_cursor(L_Cursor);
   return FALSE;
end Hay_Datos;
procedure Reg_Cambio_Dimen_24(reg in G3_INSTAN_DIMEN%ROWTYPE,
               Cambio in char) is
   i pls_integer;
begin
   i:= nvl(T_Abonos.Last, 0) + 1;
   T_Abonos(i).NU_DIMEN:= reg.NU_DIMEN;
   T_Abonos(i).NU_INSTAN_DIMEN:= reg.NU_INSTAN_DIMEN;
   T_Abonos(i).NM_INSTAN_DIMEN:= reg.NM_INSTAN_DIMEN;
   T_Abonos(i).FC_ULT_ATUAL_INSTAN_DIMEN:= reg.FC_ULT_ATUAL_INSTAN_DIMEN;
   T_Abonos(i).CD_JRQC_INSTAN_DIMEN:= reg.CD_JRQC_INSTAN_DIMEN;
   T_Abonos(i).NU_NIVL_INSTAN_DIMEN:= reg.NU_NIVL_INSTAN_DIMEN;
   T_Abonos(i).NU_NIVL_LOGC_DIMEN:= reg.NU_NIVL_LOGC_DIMEN;
   T_Opers(i):= Cambio;
   if not T_Abonos.Exists(1) then
      dbms_output.put_line('No grabo el cambio');
   end if;
end Reg_Cambio_Dimen_24;
procedure Sinc_Dimen_25 is
   i pls_integer;
begin
   if (Atualizando) or (not T_Abonos.Exists(1)) then
      return; -- No hace nada
   else
      Atualizando:= TRUE;
      for i in 1..T_Abonos.Last loop
         if T_Opers(i) = 'I' then -- Insert
       insert into G3_INSTAN_DIMEN
               (NU_DIMEN, NU_INSTAN_DIMEN,
          NM_INSTAN_DIMEN, FC_ULT_ATUAL_INSTAN_DIMEN,
          CD_JRQC_INSTAN_DIMEN, NU_NIVL_INSTAN_DIMEN,
          NU_NIVL_LOGC_DIMEN)
       values
          (25, T_Abonos(i).NU_INSTAN_DIMEN,
          T_Abonos(i).NM_INSTAN_DIMEN, sysdate,
          T_Abonos(i).CD_JRQC_INSTAN_DIMEN,
          T_Abonos(i).NU_NIVL_INSTAN_DIMEN,
          T_Abonos(i).NU_NIVL_LOGC_DIMEN);
    else
       if T_Opers(i) = 'U' then -- Update
               update G3_INSTAN_DIMEN set
                  NM_INSTAN_DIMEN =  T_Abonos(i).NM_INSTAN_DIMEN,
                  FC_ULT_ATUAL_INSTAN_DIMEN = sysdate,
             CD_JRQC_INSTAN_DIMEN = T_Abonos(i).CD_JRQC_INSTAN_DIMEN,
                  NU_NIVL_INSTAN_DIMEN = T_Abonos(i).NU_NIVL_INSTAN_DIMEN,
             NU_NIVL_LOGC_DIMEN = T_Abonos(i).NU_NIVL_LOGC_DIMEN
                  where NU_DIMEN = 25 and
                        NU_INSTAN_DIMEN = T_Abonos(i).NU_INSTAN_DIMEN;
       else begin
               delete from G3_INSTAN_DIMEN where
                  NU_DIMEN = 25 and
                  NU_INSTAN_DIMEN = T_Abonos(i).NU_INSTAN_DIMEN;
            exception
               when NO_DATA_FOUND then
                  NULL;
            end;
            end if;
    end if;
      end loop;
   end if;
   T_Abonos.delete;
   T_Opers.delete;
   Atualizando:= FALSE;
end Sinc_Dimen_25;
end G3_PROC_ADMIN;
/

CREATE OR REPLACE
package body WAREHOUSE.G3_PROC_ATRB_DIMEN as
g_dt_hoje        date:= NULL;
type R_INST is record (
   Nu_Inst NUMBER(8),
   Nu_Nivel NUMBER(2));
type T_F_INST is table of R_INST index by binary_integer;
type T_MAX_INST is table of number(8) index by binary_integer;
max_inst T_MAX_INST;
-----------------------------------------------------------------------------------
-- Procedure: POVOA_TEMPORARIA
--    Puebla (sob demanda) la tabla temporaria (G3_TEMP_INSTAN_ATRB_DIMEN) a partir
--    de la tabla de instancias de atributos de dimension (G3_INSTAN_ATRB_DIMEN).
-----------------------------------------------------------------------------------
procedure POVOA_TEMPORARIA(p_dimen in number, p_instan in number) is
   l_dt_hoje date;
begin
   l_dt_hoje:= SYSDATE;
   if g_dt_hoje is NULL then
      g_dt_hoje:= l_dt_hoje;
   end if;
   -- Para cada atributo de la dimension informada
   for r_atrb in (
      select NU_ATRB_DIMEN, NM_ATRB_DIMEN,
             CD_TIPO_ATRB_DIMEN,
             CD_ATRB_VALOR_LIBRE,
             CT_TAMN_ATRB_DIMEN
         from G3_ATRB_DIMEN
         where NU_DIMEN = p_dimen) loop
   begin
      -- Crea los registros vacios en la tabla temporaria para editar los valores
      insert into G3_TEMP_INSTAN_ATRB_DIMEN(
         NU_DIMEN, NU_ATRB_DIMEN,
         NU_INSTAN_DIMEN, NM_ATRB_DIMEN,
         CD_TIPO_ATRB_DIMEN, CD_ATRB_VALOR_LIBRE,
         CT_TAM_ATRB_DIMEN,
         FC_ULT_ATUAL_INSTAN_ATRB)
         values(p_dimen, r_atrb.NU_ATRB_DIMEN,
                p_instan, r_atrb.NM_ATRB_DIMEN,
                r_atrb.CD_TIPO_ATRB_DIMEN,
                r_atrb.CD_ATRB_VALOR_LIBRE,
                r_atrb.CT_TAMN_ATRB_DIMEN,
                l_dt_hoje);
   exception
      -- Esta excepcion no deberia ocurrir nunca.
      when DUP_VAL_ON_INDEX then NULL;
   end;
   end loop;
   commit;
   -- Completa los registros para los cuales yo tengo valor
   for r_inst_atrb in (
      select NU_DIMEN, NU_INSTAN_DIMEN,
             NU_ATRB_DIMEN, TX_VALOR_ATRB_DIMEN,
             FC_ULT_ATUAL_INSTAN_ATRB
         from G3_INSTAN_ATRB_DIMEN
         where NU_DIMEN = p_dimen and
               NU_INSTAN_DIMEN = p_instan) loop
      -- Actualiza solamente el valor y la fecha de la ultima actualizacion
      update G3_TEMP_INSTAN_ATRB_DIMEN set
             TX_VALOR_ATRB_DIMEN = r_inst_atrb.TX_VALOR_ATRB_DIMEN,
             FC_ULT_ATUAL_INSTAN_ATRB = r_inst_atrb.FC_ULT_ATUAL_INSTAN_ATRB
         where NU_DIMEN = p_dimen and
               NU_INSTAN_DIMEN = p_instan and
               NU_ATRB_DIMEN = r_inst_atrb.NU_ATRB_DIMEN;
   end loop;
   commit;
end POVOA_TEMPORARIA;
---------------------------------------------------------------------------------
-- Procedure: ATUALIZA_ATRIBUTOS
--    Actualiza la tabla de instancias de atributos de dimension
--    (G3_INSTAN_ATRB_DIMEN) a partir de la tabela temporaria de instancias
--    de atributos de dimension (G3_TEMP_INSTAN_ATRB_DIMEN).
---------------------------------------------------------------------------------
procedure ATUALIZA_ATRIBUTOS(p_dimen in number) is
begin
   -- Para todas las instancias que fueran editadas
   for r_inst_atrb in (
      select NU_DIMEN, NU_ATRB_DIMEN,
             NU_INSTAN_DIMEN, TX_VALOR_ATRB_DIMEN,
             FC_ULT_ATUAL_INSTAN_ATRB
         from G3_TEMP_INSTAN_ATRB_DIMEN
         where FC_ULT_ATUAL_INSTAN_ATRB >= g_dt_hoje) loop
   begin
      if (r_inst_atrb.TX_VALOR_ATRB_DIMEN is NOT NULL) then  -- Tiene valor; intentar insertar
         insert into G3_INSTAN_ATRB_DIMEN(
               NU_DIMEN, NU_ATRB_DIMEN,
               NU_INSTAN_DIMEN, TX_VALOR_ATRB_DIMEN,
               FC_ULT_ATUAL_INSTAN_ATRB)
            values(r_inst_atrb.NU_DIMEN, r_inst_atrb.NU_ATRB_DIMEN,
                r_inst_atrb.NU_INSTAN_DIMEN, r_inst_atrb.TX_VALOR_ATRB_DIMEN,
                r_inst_atrb.FC_ULT_ATUAL_INSTAN_ATRB);
      else  -- Borro la linea; eliminar de la tabla permanente.
         delete from G3_INSTAN_ATRB_DIMEN
       where NU_ATRB_DIMEN = r_inst_atrb.NU_ATRB_DIMEN and
        NU_INSTAN_DIMEN = r_inst_atrb.NU_INSTAN_DIMEN and
        NU_DIMEN = r_inst_atrb.NU_DIMEN;
      end if;
   exception
      when DUP_VAL_ON_INDEX then
         update G3_INSTAN_ATRB_DIMEN set
               TX_VALOR_ATRB_DIMEN = r_inst_atrb.TX_VALOR_ATRB_DIMEN,
               FC_ULT_ATUAL_INSTAN_ATRB = r_inst_atrb.FC_ULT_ATUAL_INSTAN_ATRB
            where NU_DIMEN = r_inst_atrb.NU_DIMEN and
                  NU_ATRB_DIMEN = r_inst_atrb.NU_ATRB_DIMEN and
                  NU_INSTAN_DIMEN = r_inst_atrb.NU_INSTAN_DIMEN;
   end;
   update G3_INSTAN_DIMEN set
         FC_ULT_ATUAL_INSTAN_DIMEN = sysdate
      where NU_DIMEN = r_inst_atrb.NU_DIMEN and
       NU_INSTAN_DIMEN = r_inst_atrb.NU_INSTAN_DIMEN;
   end loop;
   delete from G3_TEMP_INSTAN_ATRB_DIMEN;
   commit;
end ATUALIZA_ATRIBUTOS;
-----------------------------------------------------------------------------------------------
-- Function : GRAVA_DESC
--
-- Registra las instancias de dimension desconocidas descubiertas durante el proceso
-- de traduccion de claves. Ritorna 0 si la instancia ya estaba grabada, 1 si no estaba.
--
-----------------------------------------------------------------------------------------------
function Grava_Desc(p_nu_dimen in number, p_cd_inst in varchar2, p_nu_fonte in number) return number is
begin
   insert into G3_INSTAN_DIMEN_DESC(NU_DIMEN, CD_INSTAN_DIMEN,
   NU_FUENTE_INDCA_PERFM, CT_REGS_RECZ)
      values(p_nu_dimen, p_cd_inst, p_nu_fonte, 0);
   return(1);
exception
   when DUP_VAL_ON_INDEX then
      update G3_INSTAN_DIMEN_DESC
    set CT_REGS_RECZ = CT_REGS_RECZ + 1
    where NU_DIMEN = p_nu_dimen and
          CD_INSTAN_DIMEN = p_cd_inst;
      return(0);
end;
---------------------------------------------------------------------------------------
-- Function CRIA_NOVA_INSTANCIA :
--    Crea una nueva instancia de dimension. Ritorna el codigo de la instancia
---------------------------------------------------------------------------------------
function CRIA_NOVA_INSTANCIA(p_nu_dimen in number, p_cd_instan in char,
      p_nu_nivl_logc in number, p_nm_instan in varchar2) return NUMBER is
   l_nu_instan        number(8);
   l_nu_nivl_logc    number(3);
   l_dummy           char;
   JaTem        BOOLEAN;
   NOME_DUPLICADO    exception;
   NIVEL_DESCONOCIDO exception;
   pragma exception_init(NIVEL_DESCONOCIDO, -2291);
begin
  -- Recupera el proximo numero de instancia disponible
  if not (max_inst.exists(p_nu_dimen)) then
     select nvl(max(nu_instan_dimen),0) + 1
        into max_inst(p_nu_dimen)
        from G3_INSTAN_DIMEN
        where nu_dimen = p_nu_dimen;
  end if;
  l_nu_instan:= max_inst(p_nu_dimen);
  -- Recupera el nivel logico donde la instancia debe ser puesta. La
  --  instancia siempre sera puesta en el nivel logico mas bajo (input)
  if (p_nu_nivl_logc is NULL) then
     select nvl(max(nu_nivl_logc_dimen),1)
       into l_nu_nivl_logc
       from G3_NIVL_LOGC_DIMEN
       where nu_dimen = p_nu_dimen;
  else
     l_nu_nivl_logc:= p_nu_nivl_logc;
  end if;
  begin
    -- Verifica si ya existe una instancia de dimension con aquel nombre
    JaTem:= FALSE;
    select NU_INSTAN_DIMEN
      into l_nu_instan
      from G3_INSTAN_DIMEN
      where nm_instan_dimen = substr(p_nm_instan, 1, 24)
            and nu_dimen = p_nu_dimen
       and rownum = 1;
    JaTem:= TRUE;
    raise NO_DATA_FOUND;
  exception
     -- puedo seguir con la grabacion sin problemas
     when NO_DATA_FOUND then
        begin
          if not JaTem then
             insert into G3_INSTAN_DIMEN
               (NU_DIMEN, NU_INSTAN_DIMEN,  NM_INSTAN_DIMEN,
                FC_ULT_ATUAL_INSTAN_DIMEN, CD_JRQC_INSTAN_DIMEN, NU_NIVL_INSTAN_DIMEN,
                NU_NIVL_LOGC_DIMEN)
             values (p_nu_dimen, l_nu_instan, substr(p_nm_instan, 1, 24),
                     sysdate, '0', 1, l_nu_nivl_logc);
             max_inst(p_nu_dimen):= max_inst(p_nu_dimen) + 1;
          end if;
          begin
             insert into G3_COD_INSTAN_DIMEN(NU_DIMEN, NU_INSTAN_DIMEN,
               CD_INSTAN_DIMEN) values
               (p_nu_dimen, l_nu_instan, rtrim(p_cd_instan));
          exception
             when DUP_VAL_ON_INDEX then
                G3_Log_Err.Log_Msj('E',
                     'Instancia ' || p_cd_instan || ' ya existente.');
                return NULL;
          end;
        exception
           when NIVEL_DESCONOCIDO then
              G3_Log_Err.Log_Msj('E', 'Nivel ' || p_nu_nivl_logc ||
                ' de la dimension ' || p_nu_dimen || ' desconocido.');
              select nvl(max(nu_nivl_logc_dimen),1)
                 into l_nu_nivl_logc
                 from G3_NIVL_LOGC_DIMEN
                 where nu_dimen = p_nu_dimen;
              G3_Log_Err.Log_Msj('D', 'Cambiando nivel ' || p_nu_nivl_logc ||
                 ' de la dimension ' || p_nu_dimen || ' por ' ||
                 l_nu_nivl_logc ||'.');
                        insert into G3_INSTAN_DIMEN
                          (NU_DIMEN, NU_INSTAN_DIMEN,  NM_INSTAN_DIMEN,
                           FC_ULT_ATUAL_INSTAN_DIMEN, CD_JRQC_INSTAN_DIMEN, NU_NIVL_INSTAN_DIMEN,
                           NU_NIVL_LOGC_DIMEN)
                        values (p_nu_dimen, l_nu_instan, substr(p_nm_instan, 1, 24),
                                sysdate, '0', 1, l_nu_nivl_logc);
                        max_inst(p_nu_dimen):= max_inst(p_nu_dimen) + 1;
              begin
                 insert into G3_COD_INSTAN_DIMEN(NU_DIMEN, NU_INSTAN_DIMEN,
                    CD_INSTAN_DIMEN) values
                    (p_nu_dimen, l_nu_instan, rtrim(p_cd_instan));
              exception
                 when DUP_VAL_ON_INDEX then
                    G3_Log_Err.Log_Msj('E',
                   'Instancia ' || p_cd_instan || ' ya existente.');
                    return NULL;
              end;
           when OTHERS then
              G3_Log_Err.Log_Msj('E',
                         'Instancia ' || p_cd_instan || ': ' || sqlerrm);
              return NULL;
        end;
    end;
    return(l_nu_instan);
  exception
     when NO_DATA_FOUND then
       G3_Log_Err.Log_Msj('E',
             'Instancia ' || p_cd_instan || ' desconocida y no grabada : nombre no informado en el archivo.');
       return NULL;
     when OTHERS then
       G3_Log_Err.Log_Msj('E',
             'Instancia ' || p_cd_instan || ': ' || SQLERRM);
       return NULL;
end;
---------------------------------------------------------------------------------------
-- Procedure IMPORTA_ATRIBUTOS:
--    Traduz as chaves de instancia de dimensao e atualiza as instancias de atributos
--    da tabela temporaria de carga de instancias de atributos (G3_EXTRT_SIG_ATRB)
--    para a tabela definitiva de instancias de atributos (G3_INSTAN_ATRB_DIMEN).
---------------------------------------------------------------------------------------
procedure IMPORTA_ATRIBUTOS(p_nu_usuario in number) is
   type R_ATRB is record (TIPO_ATRB G3_ATRB_DIMEN.CD_TIPO_ATRB_DIMEN%TYPE,
           E_LIVRE G3_ATRB_DIMEN.CD_ATRB_VALOR_LIBRE%TYPE);
   type T_ATRB is table of R_ATRB index by binary_integer;
   l_instan_dimen number(8);
   contador binary_integer;
   l_valor varchar2(2000);
   l_dummy char(1);
   l_dimen_ant number(5) := 0;
   l_dimen G3_DIMEN.NU_DIMEN%type;
   l_atrb_dimen G3_ATRB_DIMEN.NU_ATRB_DIMEN%type;
   l_cd_instan_dimen G3_COD_INSTAN_DIMEN.CD_INSTAN_DIMEN%type;
   l_cd_instan_dimen_ant varchar2(20):= ' ';
   atributos T_ATRB;
   VALOR_INVALIDO exception;
   DIA_INVALIDO exception;
   pragma EXCEPTION_INIT(DIA_INVALIDO, -1847);  /* Erro ORA-1847: Numero do dia invalido */
   MES_INVALIDO exception;
   pragma EXCEPTION_INIT(MES_INVALIDO, -1843);  /* Erro ORA-1843: mes invalido */
   ANO_INVALIDO exception;
   pragma EXCEPTION_INIT(ANO_INVALIDO, -1841);  /* Erro ORA-1841: ano invalido */
   NOT_A_NUMBER exception;
   pragma EXCEPTION_INIT(NOT_A_NUMBER, -1858);  /* Erro ORA-1858: valor nao-numerico */
begin
   g_dt_hoje:= SYSDATE;
   G3_Log_Err.Inic_Log('CGATR');
   -- Tomando cada instancia de atributo de dimension y traducindo
   contador:= 0;
   lock table g3_instan_dimen in exclusive mode;
   lock table g3_cod_instan_dimen in exclusive mode;
   UPDATE G3_EXTRT_SIG_ATRB SET CD_INSTAN_DIMEN=RTRIM(CD_INSTAN_DIMEN);
   UPDATE G3_COD_INSTAN_DIMEN SET CD_INSTAN_DIMEN=RTRIM(CD_INSTAN_DIMEN);
   for r_dimen in
      (select E.ROWID RID, E.NU_DIMEN, rtrim(E.CD_INSTAN_DIMEN) CD_INSTAN_DIMEN,
           E.NU_NIVL_LOGC_DIMEN, E.NU_ATRB_DIMEN, E.TX_VALOR_ATRB_DIMEN,
           E.FC_ULT_ATUAL_INSTAN_ATRB, C.NU_INSTAN_DIMEN
         from G3_EXTRT_SIG_ATRB E,
              G3_COD_INSTAN_DIMEN C
         where E.NU_DIMEN = C.NU_DIMEN (+) and
               E.CD_INSTAN_DIMEN = C.CD_INSTAN_DIMEN (+)
         order by E.NU_DIMEN, E.NU_ATRB_DIMEN)
   loop
      l_dimen:= r_dimen.nu_dimen;
      l_atrb_dimen:= r_dimen.nu_atrb_dimen;
      l_cd_instan_dimen:=  r_dimen.cd_instan_dimen;
      begin
         -- Caso la dimension tenga cambiado, convalida el codigo de la dimension
         if r_dimen.NU_DIMEN != l_dimen_ant then
            select 'x'
               into l_dummy
               from G3_DIMEN
               where nu_dimen = r_dimen.NU_DIMEN;
            l_dimen_ant := r_dimen.NU_DIMEN;
         end if;
         begin
           -- Caso el codigo de instancia tenga cambiado, traducirla
           if r_dimen.CD_INSTAN_DIMEN != l_cd_instan_dimen_ant then
              if r_dimen.NU_INSTAN_DIMEN is not NULL then
                 l_instan_dimen:= r_dimen.NU_INSTAN_DIMEN;
              else
                 raise NO_DATA_FOUND;
              end if;
              l_cd_instan_dimen_ant:= r_dimen.CD_INSTAN_DIMEN;
           end if;
           -- Procesando los atributos, con tratamento especial para
           -- actualizacion de instancia de dimension.
           -- La creacion de la instancia es tratada
           -- en la exception despues de este if
           if r_dimen.NU_ATRB_DIMEN != 0 then
           begin
              if not atributos.exists(r_dimen.NU_ATRB_DIMEN) then
                  select A.CD_TIPO_ATRB_DIMEN, A.CD_ATRB_VALOR_LIBRE
                     into atributos(r_dimen.NU_ATRB_DIMEN).TIPO_ATRB,
                          atributos(r_dimen.NU_ATRB_DIMEN).E_LIVRE
                     from G3_ATRB_DIMEN A
                     where A.NU_DIMEN = r_dimen.NU_DIMEN and
                           A.NU_ATRB_DIMEN = r_dimen.NU_ATRB_DIMEN;
              end if;
              -- Convalidando y formateando los atributos
              -- Formateando fechas. Si der error, no graba y registra en el log
              l_valor:= r_dimen.TX_VALOR_ATRB_DIMEN;
              if atributos(r_dimen.NU_ATRB_DIMEN).TIPO_ATRB = 'F' then
                 l_valor:= to_char(to_date(l_valor, 'DDMMYYYY'), 'DD/MM/YYYY');
              end if;
              -- Chequeando si el valor es valido.
              -- Si no, no graba y registra en el log
              if (atributos(r_dimen.NU_ATRB_DIMEN).E_LIVRE = '0') then
              begin
                 select 'x' into l_dummy
                    from G3_VL_VALD_ATRB_DIMEN
                    where NU_DIMEN = r_dimen.NU_DIMEN and
                          NU_ATRB_DIMEN = r_dimen.NU_ATRB_DIMEN and
                          l_valor = TX_VALOR_VALD_ATRB_DIMEN;
              exception
                 when NO_DATA_FOUND then
                    raise VALOR_INVALIDO;
                 when OTHERS then NULL;
              end;
              end if;
              -- Estoy suponendo que actualizaciones son mas comunes que
              -- inserciones
              update G3_INSTAN_ATRB_DIMEN
                 set TX_VALOR_ATRB_DIMEN = l_valor,
                     FC_ULT_ATUAL_INSTAN_ATRB = r_dimen.FC_ULT_ATUAL_INSTAN_ATRB
                 where NU_DIMEN = r_dimen.NU_DIMEN and
                       NU_INSTAN_DIMEN = l_instan_dimen and
                       NU_ATRB_DIMEN = r_dimen.NU_ATRB_DIMEN;
              if sql%notfound then
                 insert into G3_INSTAN_ATRB_DIMEN
                    (NU_DIMEN, NU_INSTAN_DIMEN, NU_ATRB_DIMEN,
                     FC_ULT_ATUAL_INSTAN_ATRB, TX_VALOR_ATRB_DIMEN)
                  values (r_dimen.NU_DIMEN, l_instan_dimen, r_dimen.NU_ATRB_DIMEN,
                          r_dimen.FC_ULT_ATUAL_INSTAN_ATRB, l_valor);
              end if;
             -- reemplaza la presuncion anterior
     /*        begin
                     insert into G3_INSTAN_ATRB_DIMEN
                        (NU_DIMEN, NU_INSTAN_DIMEN, NU_ATRB_DIMEN,
                         FC_ULT_ATUAL_INSTAN_ATRB, TX_VALOR_ATRB_DIMEN)
                     values(r_dimen.NU_DIMEN, l_instan_dimen, r_dimen.NU_ATRB_DIMEN,
                             r_dimen.FC_ULT_ATUAL_INSTAN_ATRB, l_valor);
             exception
                when dup_val_on_index then
                  update G3_INSTAN_ATRB_DIMEN
                     set TX_VALOR_ATRB_DIMEN = l_valor,
                         FC_ULT_ATUAL_INSTAN_ATRB = r_dimen.FC_ULT_ATUAL_INSTAN_ATRB
                     where NU_DIMEN = r_dimen.NU_DIMEN and
                           NU_INSTAN_DIMEN = l_instan_dimen and
                           NU_ATRB_DIMEN = r_dimen.NU_ATRB_DIMEN;
             end;
     */
              delete from G3_EXTRT_SIG_ATRB
                 where ROWID = r_dimen.rid;
           exception
              when NO_DATA_FOUND then
                 G3_Log_Err.Log_Err_Atrib('Atributo desconocido.', 0, g_dt_hoje, l_valor,
                    r_dimen.NU_DIMEN, r_dimen.NU_ATRB_DIMEN, l_instan_dimen);
              when VALOR_INVALIDO then
                 G3_Log_Err.Log_Err_Atrib('Valor invalido.', 0, g_dt_hoje, l_valor,
                    r_dimen.NU_DIMEN, r_dimen.NU_ATRB_DIMEN, l_instan_dimen);
              when DIA_INVALIDO then
                 G3_Log_Err.Log_Err_Atrib('Dia invalido.', 0, g_dt_hoje, l_valor,
                    r_dimen.NU_DIMEN, r_dimen.NU_ATRB_DIMEN, l_instan_dimen);
              when MES_INVALIDO then
                 G3_Log_Err.Log_Err_Atrib('Mes invalido.', 0, g_dt_hoje, l_valor,
                    r_dimen.NU_DIMEN, r_dimen.NU_ATRB_DIMEN, l_instan_dimen);
              when ANO_INVALIDO then
                 G3_Log_Err.Log_Err_Atrib('Ano invalido.', 0, g_dt_hoje, l_valor, r_dimen.NU_DIMEN,
                      r_dimen.NU_ATRB_DIMEN, l_instan_dimen);
              when NOT_A_NUMBER then
                 G3_Log_Err.Log_Err_Atrib('Fecha invalida.', 0, g_dt_hoje, l_valor,
                    r_dimen.NU_DIMEN, r_dimen.NU_ATRB_DIMEN, l_instan_dimen);
           end;
           else  -- Update en Instancias de dimension
              -- Solo cambia el nombre de la instancia.
              update G3_INSTAN_DIMEN set
                  NM_INSTAN_DIMEN = substr(r_dimen.TX_VALOR_ATRB_DIMEN, 1, 24),
                  NU_NIVL_LOGC_DIMEN = r_dimen.NU_NIVL_LOGC_DIMEN
                  where NU_DIMEN = r_dimen.NU_DIMEN and
                        NU_INSTAN_DIMEN = l_instan_dimen;
               delete from G3_EXTRT_SIG_ATRB
                  where ROWID = r_dimen.rid;
           end if;
         exception  -- Creacion de Instancias de dimension
            -- Caso la instancia no exista, ejecuta el procedimiento que vay
            -- creala, SI EL ATRIBUTO ES 0. Si no, es uno error.
            when NO_DATA_FOUND then
               if r_dimen.NU_ATRB_DIMEN = 0 then
                  l_instan_dimen:= Cria_Nova_Instancia(r_dimen.NU_DIMEN, r_dimen.CD_INSTAN_DIMEN,
                     r_dimen.NU_NIVL_LOGC_DIMEN, r_dimen.TX_VALOR_ATRB_DIMEN);
                  if (l_instan_dimen is not NULL) then
                     delete from G3_EXTRT_SIG_ATRB
                        where ROWID = r_dimen.rid;
                  end if;
               else
                  G3_Log_Err.Log_Err_Atrib('Instancia desconocida.', 0, g_dt_hoje, l_valor,
                     r_dimen.NU_DIMEN, r_dimen.NU_ATRB_DIMEN, NULL, r_dimen.CD_instan_dimen);
               end if;
         end;
         atributos.delete;
      exception
         -- Caso la dimension no exista, graba mensaje en el log y borra
         -- los registros de la tabla G3_EXTRT_SIG_ATRB
         WHEN NO_DATA_FOUND then
            delete from G3_EXTRT_SIG_ATRB
               where nu_dimen = r_dimen.NU_DIMEN;
            G3_Log_Err.Log_Err_Atrib('Dimension desconocida.', 0, g_dt_hoje, l_valor,
               r_dimen.NU_DIMEN, r_dimen.NU_ATRB_DIMEN, NULL, r_dimen.CD_instan_dimen);
      end;
      if contador > 1000 then
         commit;
         lock table g3_instan_dimen in exclusive mode;
         lock table g3_cod_instan_dimen in exclusive mode;
         contador:= 0;
      end if;
      contador:= contador + 1;
   end loop;
   max_inst.delete;
   G3_Log_Err.Termina_Log;
   commit;
exception
   when others then
         G3_Log_Err.Log_Err_Atrib(SQLERRM, 0, g_dt_hoje, l_valor,
            l_DIMEN, l_ATRB_DIMEN, l_instan_dimen, l_cd_instan_dimen);
      rollback;
      max_inst.delete;
      G3_Log_Err.Termina_Log;
end IMPORTA_ATRIBUTOS;
---------------------------------------------------------------------------
--  Procedure: NIVEL_HIJOS
--     Hace una busqueda en el arbol bajo la instancia pasada, arreglando
--     el nivel jerarquico de las instancias hijas, de acuerdo con el nuevo
--     padre.
----------------------------------------------------------------------------
procedure Nivel_Hijos(P_Dimen in NUMBER,
      P_Inst in Number, P_Level in Number) is
   I_Fila pls_integer;
   T_Fila pls_integer;
   Fila T_F_INST;
   L_Nivel number(2);
begin
   I_Fila:= 0;
   T_Fila:= 1;
   L_Nivel:= P_Level;
   Fila(0).Nu_Inst:= P_Inst;
   Fila(0).Nu_Nivel:= L_Nivel;
   while I_Fila < T_Fila loop
      L_Nivel:= Fila(I_Fila).Nu_Nivel + 1;
      for r_inst in (select I.NU_INSTAN_DIMEN_HIJO
      from G3_INSTAN_DIMEN_INSTAN_DIMEN I
      where I.NU_DIMEN_PADRE = P_Dimen and
            I.NU_INSTAN_DIMEN_PADRE = Fila(I_Fila).Nu_Inst) loop
      begin
         Fila(T_Fila).Nu_Inst:= r_inst.NU_INSTAN_DIMEN_HIJO;
         Fila(T_Fila).Nu_Nivel:= L_Nivel;
         T_Fila:= T_Fila + 1;
      end;
      end loop;
      update G3_INSTAN_DIMEN set
            NU_NIVL_INSTAN_DIMEN = Fila(I_Fila).Nu_Nivel,
            FC_ULT_ATUAL_INSTAN_DIMEN = sysdate
    where NU_DIMEN = P_Dimen and
          NU_INSTAN_DIMEN = Fila(I_Fila).Nu_Inst;
      Fila.delete(I_Fila);
      I_Fila:= I_Fila + 1;
   end loop;
   Fila.delete;
end Nivel_Hijos;
---------------------------------------------------------------------------------------
-- Procedure IMPORTA_JERARQUIAS:
--    Traduz as chaves de instancia de dimens?o e atualiza as hierarquias
--    da tabela temporaria de carga de hierarquias (G3_EXTRT_SIG_JRQC)
--    para a tabela definitiva de hierarquias (G3_INSTAN_DIMEN_INSTAN_DIMEN).
---------------------------------------------------------------------------------------
procedure IMPORTA_JERARQUIAS(p_nu_usuario in number) is
   l_nu_inst_padre number(8);
   l_nu_inst_hijo number(8);
   l_nivl_inst_padre number(2);
   l_nivl_logc_padre number(2);
   l_nivl_logc_hijo number(2);
   contador binary_integer;
begin
   G3_Log_Err.Inic_Log('CGJRQ');
   contador:= 0;
   lock table G3_INSTAN_DIMEN_INSTAN_DIMEN in exclusive mode;
   for r_jerarq in(
      select J.rowid rid, J.NU_DIMEN, J.CD_INSTAN_DIMEN_PADRE, J.CD_INSTAN_DIMEN_HIJO,
             C1.NU_INSTAN_DIMEN InstanPadre, C2.NU_INSTAN_DIMEN InstanHijo
      from G3_EXTRT_SIG_JRQC J,
              G3_COD_INSTAN_DIMEN C1,
              G3_COD_INSTAN_DIMEN C2
         where C1.NU_DIMEN (+) = J.NU_DIMEN and
               C1.CD_INSTAN_DIMEN (+) = rtrim(J.CD_INSTAN_DIMEN_PADRE) and
               C2.NU_DIMEN (+) = J.NU_DIMEN and
               C2.CD_INSTAN_DIMEN (+) = rtrim(J.CD_INSTAN_DIMEN_HIJO))
   loop
   begin
      begin
         if r_jerarq.InstanPadre is not NULL then
         l_nu_inst_padre:= r_jerarq.InstanPadre;
         else
            raise NO_DATA_FOUND;
         end if;
         begin
            if r_jerarq.InstanHijo is not NULL then
               l_nu_inst_hijo:= r_jerarq.InstanHijo;
            else
               raise NO_DATA_FOUND;
            end if;
            begin
               select NU_NIVL_INSTAN_DIMEN,
                      NU_NIVL_LOGC_DIMEN
                  into l_nivl_inst_padre, l_nivl_logc_padre
                  from G3_INSTAN_DIMEN
                  where NU_DIMEN = r_jerarq.NU_DIMEN and
                        NU_INSTAN_DIMEN = l_nu_inst_padre;
               select NU_NIVL_LOGC_DIMEN
                  into l_nivl_logc_hijo
                  from G3_INSTAN_DIMEN
                  where NU_DIMEN = r_jerarq.NU_DIMEN and
                        NU_INSTAN_DIMEN = l_nu_inst_hijo;
               if (l_nivl_logc_padre < l_nivl_logc_hijo) then
                  insert into G3_INSTAN_DIMEN_INSTAN_DIMEN
                     (NU_DIMEN_PADRE, NU_INSTAN_DIMEN_PADRE,
                      NU_DIMEN_HIJO, NU_INSTAN_DIMEN_HIJO)
                     values (r_jerarq.NU_DIMEN, l_nu_inst_padre,
                             r_jerarq.NU_DIMEN, l_nu_inst_hijo);
                             nivel_hijos(r_jerarq.NU_DIMEN,
                             l_nu_inst_hijo, l_nivl_inst_padre + 1);
                  update G3_INSTAN_DIMEN set
                         CD_JRQC_INSTAN_DIMEN = '1',
                         FC_ULT_ATUAL_INSTAN_DIMEN = sysdate
                     where NU_DIMEN = r_jerarq.NU_DIMEN and
                           NU_INSTAN_DIMEN = l_nu_inst_padre;
                  delete from G3_EXTRT_SIG_JRQC
                     where ROWID = r_jerarq.rid;
               else
                  G3_Log_err.Log_Msj('E', 'Padre de nivel logico mas bajo que el hijo.');
                  G3_Log_Err.Log_Msj('E', 'Dimen: ' || r_jerarq.NU_DIMEN ||
                               ', Padre: ' || l_nu_inst_padre ||', Hijo: ' || l_nu_inst_hijo);
               end if;
            exception
               when DUP_VAL_ON_INDEX then
                  -- Accion anterior -> permitia dos padres para un hijo;
                  begin
                     update G3_INSTAN_DIMEN_INSTAN_DIMEN set
                            NU_INSTAN_DIMEN_PADRE = l_nu_inst_padre,
                            NU_DIMEN_PADRE = r_jerarq.NU_DIMEN
                        where NU_DIMEN_HIJO = r_jerarq.NU_DIMEN and
                              NU_INSTAN_DIMEN_HIJO = l_nu_inst_hijo;
                  exception
                     when DUP_VAL_ON_INDEX then
                        null;
                  end;
               when OTHERS then
                  G3_Log_Err.Log_Msj('E', 'Insercion: ' || SQLERRM);
                  G3_Log_Err.Log_Msj('E', 'Dimen: ' || r_jerarq.NU_DIMEN ||
                                ', Padre: ' || l_nu_inst_padre ||', Hijo: ' || l_nu_inst_hijo);
            end;
         exception
            when NO_DATA_FOUND then
               G3_LOG_ERR.Log_Err_Atrib('Jerarquia no creada. Instancia hijo desconocida.',
                NULL, NULL, NULL, r_jerarq.NU_DIMEN, NULL, NULL, r_jerarq.CD_INSTAN_DIMEN_HIJO);
            when OTHERS then
               G3_Log_Err.Log_Msj('E', 'Inst. Hijo: ' || SQLERRM);
         end;
      exception
         when NO_DATA_FOUND then
            G3_LOG_ERR.Log_Err_Atrib('Jerarquia no creada. Instancia padre desconocida.',
               NULL, NULL, NULL, r_jerarq.NU_DIMEN, NULL, NULL, r_jerarq.CD_INSTAN_DIMEN_PADRE);
         when OTHERS then
            G3_Log_Err.Log_Msj('E', 'Inst. Padre:' || SQLERRM);
      end;
      if (contador > 1000) then
         commit;
         contador:= 0;
         lock table g3_instan_dimen_instan_dimen in exclusive mode;
      end if;
      contador:= contador + 1;
   end;
   end loop;
   G3_Log_Err.Termina_Log;
   commit;
end IMPORTA_JERARQUIAS;
end G3_PROC_ATRB_DIMEN;
/

CREATE OR REPLACE
PACKAGE BODY WAREHOUSE.G3_PROC_CONS IS
procedure INF_CLIENTE(SESSIONID in VARCHAR2) is
   num_clie number(8);
   nm_clie  varchar2(24);
   nm_largo varchar2(50);
   Dir_Clie varchar2(50);
   Tel_Clie varchar2(15);
   Cd_Postal varchar2(6);
   D_cuit varchar2(20);
   F_ingre varchar2(14);
   Cod_esta varchar2(10);
   nivl_clie number(2);
   curs_sel integer;
   curs_upd integer;
   Ok integer;
   RID ROWID;
begin
   curs_upd:= dbms_sql.open_cursor;
   dbms_sql.parse(curs_upd, 'alter table G3_TEMP_' || SESSIONID ||
   ' modify(NM_CLIENTE varchar2(24))', DBMS_SQL.V7);
   Ok:= dbms_sql.execute(curs_upd);
   dbms_sql.close_cursor(curs_upd);

   -- Creando las columnas de los atributos del cliente
   curs_upd:= dbms_sql.open_cursor;
   dbms_sql.parse(curs_upd, 'alter table G3_TEMP_' || SESSIONID ||
   ' add(NM_CL_LARGO varchar2(50), DIR_CLIENTE varchar2(50),'||
   ' TEL_TIERRA varchar2(15), CD_POSTAL varchar2(6),' ||
        ' DOC_CUIT varchar2(20), FEC_INGRE varchar2(14),' ||
   ' ESTADO varchar2(10))', DBMS_SQL.V7);
   Ok:= dbms_sql.execute(curs_upd);
   dbms_sql.close_cursor(curs_upd);

   curs_sel:= dbms_sql.open_cursor;
   dbms_sql.parse(curs_sel, 'select ROWID, NU_CLIENTE from G3_TEMP_' ||
   SESSIONID, DBMS_SQL.V7);
   dbms_sql.define_column_rowid(curs_sel, 1, rid);
   dbms_sql.define_column(curs_sel, 2, num_clie);

   curs_upd:= dbms_sql.open_cursor;
   dbms_sql.parse(curs_upd, 'update G3_TEMP_' || SESSIONID ||
   ' set NM_CLIENTE = :i1, NIVL_CLIE = :i2,' ||
   ' NM_CL_LARGO = :i3, DIR_CLIENTE = :i4, TEL_TIERRA = :i5,' ||
   ' CD_POSTAL = :i6, DOC_CUIT = :i7, FEC_INGRE = :i8, ' ||
        ' ESTADO = :i9 where ROWID = :i10'
   , DBMS_SQL.V7);
   Ok:= dbms_sql.execute(curs_sel);
   loop
      if dbms_sql.fetch_rows(curs_sel) > 0 then
         dbms_sql.column_value(curs_sel, 1, rid);
         dbms_sql.column_value(curs_sel, 2, num_clie);
         select NM_INSTAN_DIMEN, NU_NIVL_LOGC_DIMEN
       into NM_CLIE, NIVL_CLIE
       from G3_INSTAN_DIMEN
       where NU_DIMEN = 13 and
        NU_INSTAN_DIMEN = num_clie;
    begin
       select TX_VALOR_ATRB_DIMEN
          into Nm_largo
          from G3_INSTAN_ATRB_DIMEN
          where NU_DIMEN = 13 and
           NU_INSTAN_DIMEN = num_clie and
           NU_ATRB_DIMEN = 1;
    exception
       when NO_DATA_FOUND then
          Nm_Largo:= NULL;
    end;
    begin
            select TX_VALOR_ATRB_DIMEN
          into Dir_Clie
          from G3_INSTAN_ATRB_DIMEN
          where NU_DIMEN = 13 and
           NU_INSTAN_DIMEN = num_clie and
           NU_ATRB_DIMEN = 2;
    exception
       when NO_DATA_FOUND then
          Dir_Clie:= NULL;
    end;
    begin
            select TX_VALOR_ATRB_DIMEN
          into Tel_Clie
          from G3_INSTAN_ATRB_DIMEN
          where NU_DIMEN = 13 and
           NU_INSTAN_DIMEN = num_clie and
           NU_ATRB_DIMEN = 3;
    exception
       when NO_DATA_FOUND then
          Tel_Clie:= NULL;
    end;
    begin
            select TX_VALOR_ATRB_DIMEN
          into Cd_Postal
          from G3_INSTAN_ATRB_DIMEN
          where NU_DIMEN = 13 and
           NU_INSTAN_DIMEN = num_clie and
           NU_ATRB_DIMEN = 4;
    exception
       when NO_DATA_FOUND then
          Cd_Postal:= NULL;
    end;


    begin
            select TX_VALOR_ATRB_DIMEN
          into D_cuit
          from G3_INSTAN_ATRB_DIMEN
          where NU_DIMEN = 13 and
           NU_INSTAN_DIMEN = num_clie and
           NU_ATRB_DIMEN = 5;
     exception
       when NO_DATA_FOUND then
          D_cuit:= NULL;
     end;

     begin
            select TX_VALOR_ATRB_DIMEN
          into F_ingre
          from G3_INSTAN_ATRB_DIMEN
          where NU_DIMEN = 13 and
           NU_INSTAN_DIMEN = num_clie and
           NU_ATRB_DIMEN = 6;
      exception
        when NO_DATA_FOUND then
           F_ingre:= NULL;
      end;

      begin
             select TX_VALOR_ATRB_DIMEN
           into Cod_esta
          from G3_INSTAN_ATRB_DIMEN
          where NU_DIMEN = 13 and
           NU_INSTAN_DIMEN = num_clie and
           NU_ATRB_DIMEN = 7;
           exception
        when NO_DATA_FOUND then
          Cod_esta:= NULL;
       end;


    dbms_sql.bind_variable(curs_upd, 'i1', nm_clie);
    dbms_sql.bind_variable(curs_upd, 'i2', nivl_clie);
    dbms_sql.bind_variable(curs_upd, 'i3', nm_largo);
    dbms_sql.bind_variable(curs_upd, 'i4', dir_clie);
    dbms_sql.bind_variable(curs_upd, 'i5', tel_clie);
    dbms_sql.bind_variable(curs_upd, 'i6', cd_postal);
    dbms_sql.bind_variable(curs_upd, 'i7', D_cuit);
    dbms_sql.bind_variable(curs_upd, 'i8', F_ingre);
    dbms_sql.bind_variable(curs_upd, 'i9', Cod_esta);
    dbms_sql.bind_variable_rowid(curs_upd, 'i10', rid);
    Ok:= dbms_sql.execute(curs_upd);
      else
    exit;
      end if;
   end loop;
   dbms_sql.close_cursor(curs_upd);
   dbms_sql.close_cursor(curs_sel);
   commit;
end INF_CLIENTE;

procedure INF_DIMEN(SESSIONID in VARCHAR2) is
dimension varchar2(30);
nu_dimension number;
curs_sel integer;
curs_upd integer;
Ok integer;
begin
   curs_sel:= dbms_sql.open_cursor;
   dbms_sql.parse(curs_sel, 'select a.column_name, b.nu_dimen '||
                 'from user_tab_columns a, g3_dimen b '||
       'where table_name = ''G3_TEMP_' || SESSIONID ||
                 ''' and a.column_name = upper(b.nm_dimen)', DBMS_SQL.V7);
   dbms_sql.define_column(curs_sel, 1, dimension, 30);
   dbms_sql.define_column(curs_sel, 2, nu_dimension);
   Ok:= dbms_sql.execute(curs_sel);

   -- Creando las columnas para descripcion de dimensiones
   curs_upd:= dbms_sql.open_cursor;

  loop
      if dbms_sql.fetch_rows(curs_sel) > 0 then
         dbms_sql.column_value(curs_sel, 1, dimension);
         dbms_sql.column_value(curs_sel, 2, nu_dimension);

         dbms_sql.parse(curs_upd, 'alter table G3_TEMP_' || SESSIONID ||
       ' add(NM_' || dimension || ' varchar2(50))', DBMS_SQL.V7);

         Ok:= dbms_sql.execute(curs_upd);

        dbms_sql.parse(curs_upd, 'update G3_TEMP_' || SESSIONID ||' t ' ||
        ' set NM_' || dimension || '= (select nm_instan_dimen ' ||
        ' from g3_instan_dimen d where d.nu_dimen = '|| nu_dimension ||
        ' and t.' || dimension || '= d.nu_instan_dimen)', DBMS_SQL.V7);

        Ok:= dbms_sql.execute(curs_upd);


     else
    exit;
     end if;
  end loop;

   dbms_sql.close_cursor(curs_upd);
   dbms_sql.close_cursor(curs_sel);
   commit;
end INF_DIMEN;

END G3_PROC_CONS;
/

CREATE OR REPLACE
package body WAREHOUSE.G3_SRV_CRIA_DIMEN as
  type TABELA is table of number(8) index by binary_integer;
  type TABELA_STR is table of varchar2(24) index by binary_integer;
  tab_hierarquia tabela;  /* vetor onde sao armazenados os numeros das */
                          /* instancias de dimensao que comporao uma   */
                          /* linha da tabela temporaria                */
  tab_nomes tabela_str;   /* vetor onde sao armazenados os nomes das   */
                          /* instancias de dimensao que comporao uma   */
                          /* linha da tabela temporaria                */
  tab_atrib tabela;       /* vetor onde sao armazenados os numeros dos */
                          /* atributos que representam classes na      */
                          /* dimensao sendo construida                 */
  tab_classes tabela_str; /* vetor onde sao armazenados os valores das */
                          /* classes associadas as instancias de       */
                          /* dimensao que comporao uma linha da tabela */
                          /* temporaria.                               */
  l_level_ant number(2);
  g_nu_base number(5);
--------------------------------------------------------------------------
-- Procedure : INICIALIZA_HIERARQUIA
--
-- Objetivo  : Limpar o vetor de instancias de dimensao (tab_hierarquia)
--             da posicao P_INDICE em diante.
--------------------------------------------------------------------------
procedure INICIALIZA_HIERARQUIA
          (P_INDICE IN NUMBER) is
begin
  for i in p_indice..10 loop
      tab_hierarquia(i) := NULL;
  end loop;
end;
--------------------------------------------------------------------------
-- Procedure : INICIALIZA_CLASSES
--
-- Objetivo  : Inicializar o vetor de atributos com as dez primeiras
--             classes da dimensao, selecionadas por ordem de codigo.
--------------------------------------------------------------------------
procedure INICIALIZA_CLASSES(P_DIMEN in NUMBER, P_NU_BASE in NUMBER) is
begin
   for i in 1..10 loop
      tab_atrib(i):= NULL;
   end loop;
   for r_classe in (
      select rownum, A.NU_ATRB_DIMEN
         from G3_ATRB_DIMEN A, G3_BASE_CNST_ATRB_DIMEN B
         where ROWNUM <= 10 and
               A.NU_DIMEN = P_DIMEN and
          A.NU_ATRB_DIMEN = B.NU_ATRB_DIMEN and
               B.NU_DIMEN = P_DIMEN and
               B.NU_BASE_CNST = P_NU_BASE
      order by A.NU_ATRB_DIMEN) loop
      tab_atrib(r_classe.rownum):= r_classe.NU_ATRB_DIMEN;
   end loop;
end;
--------------------------------------------------------------------------
-- Procedure : LIMPA_NOMES
--
-- Objetivo  : Limpar o vetor de nomes de instancias de dimens?o (tab_nomes)
--------------------------------------------------------------------------
procedure LIMPA_NOMES is
begin
  for i in 1..10 loop
      tab_nomes(i) := NULL;
  end loop;
end;
--------------------------------------------------------------------------
-- Procedure : LIMPA_CLASSES
--
-- Objetivo  : Limpar o vetor de classes de instancias de dimens?o (tab_classes)
--------------------------------------------------------------------------
procedure LIMPA_CLASSES is
begin
  for i in 1..10 loop
      tab_classes(i) := NULL;
  end loop;
end;
---------------------------------------------------------------------------
-- Procedure : INSERE_NOMES
--
-- Objetivo  : Monta o vetor de nomes de instancias de dimens?o (tab_nomes)
--             a partir de um vetor de numeros de instancias de dimens?o
--             (tab_hierarquia) para a dimens?o P_DIMEN
---------------------------------------------------------------------------
procedure INSERE_NOMES (P_DIMEN IN NUMBER) is
begin
  for i in 1..10 loop begin
      if tab_hierarquia(i) is not null then
         begin
           select nm_instan_dimen
             into tab_nomes(i)
             from g3_instan_dimen
            where nu_dimen = P_DIMEN
              and nu_instan_dimen = tab_hierarquia(i);
         end;
      end if;
  exception
    when NO_DATA_FOUND then NULL;
  end;
  end loop;
end;
---------------------------------------------------------------------------
-- Procedure : INSERE_CLASSES
--
-- Objetivo  : Monta o vetor de classes de instancias de dimens?o (tab_classes)
--             a partir de um vetor de numeros de instancias de dimens?o
--             (tab_hierarquia) e um de atributos (tab_atrib) para a dimens?o P_DIMEN
---------------------------------------------------------------------------
procedure INSERE_CLASSES (P_DIMEN IN NUMBER) is
begin
  for i in 1..10 loop
  begin
      if tab_atrib(i) is not null then
         begin
           select substr(tx_valor_atrb_dimen, 1, 24)
             into tab_classes(i)
             from g3_instan_atrb_dimen
             where nu_dimen = P_DIMEN and
                   nu_instan_dimen in (
                      tab_hierarquia(1), tab_hierarquia(2),
                      tab_hierarquia(3), tab_hierarquia(4),
                      tab_hierarquia(5), tab_hierarquia(6),
                      tab_hierarquia(7), tab_hierarquia(8),
                      tab_hierarquia(9), tab_hierarquia(10)) and
                   nu_atrb_dimen = tab_atrib(i);
         exception
            when TOO_MANY_ROWS then
               tab_classes(i):= 'ERRO';
            when NO_DATA_FOUND then
               null;
         end;
      end if;
  exception
    when NO_DATA_FOUND then NULL;
  end;
  end loop;
end;
--------------------------------------------------------------------------
-- Procedure : INSERE_HIERARQUIA
--
-- Objetivo  : Inserir uma linha na tabela temporaria G3_Srv_Hirqc_Dimen
--             para a dimens?o P_DIMEN combinando os conteudos dos ve-
--             tores de numeros e nomes de instancias de dimens?o
--             (tab_hierarquia e tab_nomes, respectivamente),
--             assim como o de classes (tab_classes).
--------------------------------------------------------------------------
procedure INSERE_HIERARQUIA
          (P_DIMEN IN NUMBER) is
   i pls_integer;
begin
   limpa_nomes;
   limpa_classes;
   insere_classes(p_dimen);
   insere_nomes (p_dimen);
   insert into g3_srv_jrqc_dimen
      (nu_base_cnst, nu_dimen, nu_instan_dimen_nivl__1,
       nm_instan_dimen_nivl__1,
       nu_instan_dimen_nivl__2, nm_instan_dimen_nivl__2,
       nu_instan_dimen_nivl__3, nm_instan_dimen_nivl__3,
       nu_instan_dimen_nivl__4, nm_instan_dimen_nivl__4,
       nu_instan_dimen_nivl__5, nm_instan_dimen_nivl__5,
       nu_instan_dimen_nivl__6, nm_instan_dimen_nivl__6,
       nu_instan_dimen_nivl__7, nm_instan_dimen_nivl__7,
       nu_instan_dimen_nivl__8, nm_instan_dimen_nivl__8,
       nu_instan_dimen_nivl__9, nm_instan_dimen_nivl__9,
       nu_instan_dimen_nivl__10, nm_instan_dimen_nivl__10,
       nm_instan_clas__1, nm_instan_clas__2,
       nm_instan_clas__3, nm_instan_clas__4,
       nm_instan_clas__5, nm_instan_clas__6,
       nm_instan_clas__7, nm_instan_clas__8,
       nm_instan_clas__9, nm_instan_clas__10)
   values
      (g_nu_base, p_dimen, tab_hierarquia(1), tab_nomes(1),
       tab_hierarquia(2), tab_nomes(2), tab_hierarquia(3), tab_nomes(3),
       tab_hierarquia(4), tab_nomes(4), tab_hierarquia(5), tab_nomes(5),
       tab_hierarquia(6), tab_nomes(6), tab_hierarquia(7), tab_nomes(7),
       tab_hierarquia(8), tab_nomes(8), tab_hierarquia(9), tab_nomes(9),
       tab_hierarquia(10), tab_nomes(10), tab_classes(1), tab_classes(2),
       tab_classes(3), tab_classes(4), tab_classes(5), tab_classes(6),
       tab_classes(7), tab_classes(8), tab_classes(9), tab_classes(10));
exception
   when NO_DATA_FOUND then NULL;
end;
---------------------------------------------------------------------------
-- Procedure : CRIA_DIMEN
--
-- Modulo principal do package
--
-- Parametros : P_NU_BASE - numero da base de consulta para a qual a tabela
--              sera gerada
--
---------------------------------------------------------------------------
procedure CRIA_DIMEN (p_nu_base in NUMBER) is
  l_cont number;
  l_nivel_logico number;
  i pls_integer;
  l_dummy char(1);
begin
  g_nu_base := p_nu_base;
  for r_dimen in
     (select nu_dimen, nu_nivl_logc_min, nu_nivl_logc_max, fc_ult_gen_jrqc
         from g3_base_cnst_dimen
         where nu_base_cnst = g_nu_base)  /* Recupera cada uma das dimensoes */
  loop
     if r_dimen.Fc_Ult_Gen_Jrqc is not NULL then
        begin
           select /*+ INDEX(I) */ 'x'
              into l_dummy
              from G3_INSTAN_DIMEN I
              where I.NU_DIMEN = r_dimen.NU_DIMEN and
                    I.NU_NIVL_LOGC_DIMEN between r_dimen.NU_NIVL_LOGC_MAX and
                                                 r_dimen.NU_NIVL_LOGC_MIN and
                    I.FC_ULT_ATUAL_INSTAN_DIMEN > r_dimen.Fc_Ult_Gen_Jrqc and
                    ROWNUM = 1;
        exception
           when NO_DATA_FOUND then
              l_dummy:= 'o';
        end;
        if l_dummy = 'o' then
           begin
              select /*+ INDEX(A) */ 'x'
                 into l_dummy
                 from G3_INSTAN_ATRB_DIMEN A, G3_BASE_CNST_ATRB_DIMEN B
                 where A.NU_DIMEN = r_dimen.NU_DIMEN and
                       A.NU_ATRB_DIMEN = B.NU_ATRB_DIMEN and
                       A.FC_ULT_ATUAL_INSTAN_ATRB > r_dimen.Fc_Ult_Gen_Jrqc and
                       B.NU_DIMEN = r_dimen.NU_DIMEN and
                       B.NU_BASE_CNST = g_nu_base and
                       ROWNUM = 1;
           exception
              when NO_DATA_FOUND then
                 NULL;
           end;
        end if;
     end if;
     if r_dimen.Fc_Ult_Gen_Jrqc is null or l_dummy = 'x' then
        /* Limpa a tabela temporaria */
        delete from g3_srv_jrqc_dimen
           where nu_base_cnst = g_nu_base and
               nu_dimen = r_dimen.nu_dimen;
        inicializa_classes(r_dimen.nu_dimen, p_nu_base);
        /* Recupera as instancias de dimensao que estao no nivel mais alto  */
        /* da hierarquia da base multi-dimensional(os results do Server)    */
        for r_result in
           (select nu_instan_dimen, nu_nivl_logc_dimen
              from g3_instan_dimen
             where nu_dimen = r_dimen.nu_dimen
               and nu_nivl_logc_dimen = r_dimen.nu_nivl_logc_max)
        loop
           l_cont := 0;
           l_level_ant := 0;
           inicializa_hierarquia(1); /* limpa o vetor de hierarquia */
           /* Insere o result na primeira posicao do vetor */
           tab_hierarquia(1) := r_result.nu_instan_dimen;
           /* Recupera toda a hierarquia que esteja abaixo daquele result;  */
           /* Obs : a coluna level e preenchida automaticamente pelo Oracle */
           /* e contem (neste caso) o nivel do elemento na arvore - 1       */
           for r_hierarquia in
              (select nu_instan_dimen_hijo, level
                 from g3_instan_dimen_instan_dimen
                 where nu_dimen_padre = r_dimen.nu_dimen and
                  level <= r_dimen.nu_nivl_logc_min - 1
               connect by nu_dimen_padre = prior nu_dimen_hijo
                      and nu_instan_dimen_padre = prior nu_instan_dimen_hijo
               start with nu_dimen_padre = r_dimen.nu_dimen
                      and nu_instan_dimen_padre = r_result.nu_instan_dimen)
           loop
              l_cont := l_cont + 1;
              /* Caso o nivel do dado seja menor que o anterior, significa */
              /* que um novo sub-ramo da arvore sera percorrido. O vetor   */
              /* atual e gravado e inicializado do nivel onde se inicia o  */
              /* novo sub-ramo em diante.                                  */
              /* Outra possibilidade de corte eh passar do nivel maximo    */
              /* a ser importado para aquela dimensao.                     */
              select nu_nivl_logc_dimen
                 into l_nivel_logico
                 from G3_INSTAN_DIMEN
                 where NU_DIMEN = r_dimen.nu_dimen and
                       NU_INSTAN_DIMEN = r_hierarquia.nu_instan_dimen_hijo;
              if l_nivel_logico is NULL then
                 l_nivel_logico:= r_hierarquia.level;
              end if;
              if l_nivel_logico <= r_dimen.nu_nivl_logc_min then begin
                 --
                 -- Caso o nivel logico do novo registro seja menor do que o anterior, inicializa
                 -- a hierarquia a partir de nivel logico + 1; caso seja igual ao anterior,
                 -- inicializa a hierarquia a partir do nivel logico atual. Isso considera a regra
                 -- nivel logico nao pode ser menor que nivel fisico.
                 --
                 if r_hierarquia.level < l_level_ant then
                    insere_hierarquia(r_dimen.nu_dimen);
                    inicializa_hierarquia(r_hierarquia.level+1);
                 elsif r_hierarquia.level = l_level_ant then
                    insere_hierarquia(r_dimen.nu_dimen);
                    inicializa_hierarquia(l_nivel_logico);
                 end if;
                 /* Insere o novo elemento no vetor de hierarquia             */
                 tab_hierarquia(l_nivel_logico) := r_hierarquia.nu_instan_dimen_hijo;
                 l_level_ant := r_hierarquia.level;
             end;
              else
                 l_nivel_logico:= l_level_ant;
              end if;
           end loop;
           /* Insere o ultimo vetor do loop na tabela temporaria           */
           if l_cont <> 1 then
              insere_hierarquia(r_dimen.nu_dimen);
           end if;
        end loop;
        update G3_BASE_CNST_DIMEN set
         FC_ULT_GEN_JRQC = sysdate
         where NU_BASE_CNST = p_nu_base and
          NU_DIMEN = r_dimen.NU_DIMEN;
     commit;
     end if;
  end loop;
end;
end G3_SRV_CRIA_DIMEN;
/

CREATE OR REPLACE
package body WAREHOUSE.G3_SUP_CONS_TEMP is
-- Procedimiento que devuelve las fechas desde - hasta reales, dependiendo de
-- la granularidad del indicador.  Asume como formato de la fecha:
-- 'dd-mm-yyyy hh24:mi:ss'.
procedure ObtenerFechas(Granul in varchar2,
   FDesde in out date,
   FHasta in out date,
   SigHasta out date)is
auxChar varchar2(20);
diaNro  number(1);
begin
if granul = 'A' then
   FDesde:= trunc(FDesde, 'YEAR');
   FHasta := Last_Day(Add_Months(trunc(FHasta, 'YEAR'), 11)) + 0.99998843;
        SigHasta := Last_Day(Add_Months(trunc(FDesde, 'YEAR'), 11)) + 0.99998843;
elsif granul = 'M' then
   FDesde := TRUNC(FDesde, 'MONTH');
   FHasta := last_day(FHasta) + 0.99998843;
        SigHasta:= last_day(FDesde) + 0.99998843;
elsif granul = 'S' then
   diaNro := to_number(to_char(FDesde, 'd'));
   if diaNro = 2 then   -- es lunes, el primer dia de la semana
      auxChar := to_char(FDesde, 'dd-mm-yyyy');
   elsif diaNro = 1 then  -- es domingo
      auxChar := to_char(FDesde - 6, 'dd-mm-yyyy');
   else  -- no es lunes ni domingo
      auxChar := to_char(FDesde - (diaNro - 2), 'dd-mm-yyyy');
   end if;
   FDesde := auxChar || ' 00:00:00';
   diaNro := to_number(to_char(FHasta, 'd'));
   if diaNro = 1 then   -- es domingo, el ultimo dia de la semana
      auxChar := to_char(FHasta, 'dd-mm-yyyy');
   else  -- no es domingo
      auxChar := to_char(FHasta + (7 - diaNro + 1), 'dd-mm-yyyy');
   end if;
   FHasta := auxChar || ' 23:59:59';
        SigHasta:= FDesde + 6.99998843;
else
   auxChar := to_char(FDesde, 'dd-mm-yyyy');
   FDesde := auxChar || ' 00:00:00';
   auxChar := to_char(FHasta, 'dd-mm-yyyy');
   FHasta := auxChar || ' 23:59:59';
        SigHasta:= FDesde + 0.99998843;
end if;
end ObtenerFechas;
-- Funcion que determina si el intervalo de busqueda ya fue recorrido;
-- va desplazando la fecha desde segun la granularidad.
function FinIntervalo(Granul in varchar2,
   FDesde in out date,
   FHasta in out date) return integer is
auxChar varchar2(20);
auxDesde number(8);
auxHasta number(8);
begin
if Granul = 'A' then
   auxChar := to_char(FDesde, 'dd-mm-');
   auxChar := auxChar || ltrim(to_char(to_number(to_char(FDesde, 'yyyy')) + 1));
elsif Granul = 'M' then
   auxChar := '01-';
   auxChar := auxChar || ltrim(to_char(add_months(FDesde, 1), 'mm-yyyy'));
elsif Granul = 'S' then
   auxChar := to_char(FDesde + 7, 'dd-mm-yyyy');
else
   auxChar := to_char(FDesde + 1, 'dd-mm-yyyy');
end if;
FDesde := auxChar || ' 00:00:00';
if FDesde > FHasta then
   if Granul = 'A' then
      FHasta := Last_Day(Add_Months(trunc(FDesde, 'YEAR'), 11)) + 0.99998843;
   elsif Granul = 'M' then
      FHasta:= last_day(FDesde) + 0.99998843;
   elsif Granul = 'S' then
      FHasta:= FDesde + 6.99998843;
   elsif Granul = 'D' then
      FHasta:= FDesde + 0.99998843;
   end if;
   return 1;
else
   return 0;
end if;
end FinIntervalo;

-- Funcion que devuelve el valor obtenido al aplicar la funcion de trans-
-- formacion solicitada sobre la vista que contiene los datos a sumarizar.
function CalcularValor(indice in integer,
   instan in T_ENTERO,
   fdesde in date,
   fhasta in date,
   granul in char,
   consol in varchar2,
        Resul out number) return integer is
fc_temp date;
begin
if rtrim(consol) = 'SUM' then
   select nvl(sum(ct_valor_serie_hist), 0.0)
   into Resul from v_serie_hist
   where nu_indca_perfm = indice
   and nu_instan_dimen__1  = instan(1)
   and nu_instan_dimen__2  = instan(2)
   and nu_instan_dimen__3  = instan(3)
   and nu_instan_dimen__4  = instan(4)
   and nu_instan_dimen__5  = instan(5)
   and nu_instan_dimen__6  = instan(6)
   and nu_instan_dimen__7  = instan(7)
   and nu_instan_dimen__8  = instan(8)
   and nu_instan_dimen__9  = instan(9)
   and nu_instan_dimen__10 = instan(10)
   and nu_instan_dimen__11 = instan(11)
   and nu_instan_dimen__12 = instan(12)
   and nu_instan_dimen__13 = instan(13)
   and nu_instan_dimen__14 = instan(14)
   and nu_instan_dimen__15 = instan(15)
   and nu_instan_dimen__16 = instan(16)
   and fc_refr_serie_hist between   fdesde   and fhasta
   and cd_grnl_serie_hist =  granul;
elsif rtrim(consol) = 'AVG' then
   select nvl(avg(ct_valor_serie_hist), 0.0)
   into Resul from v_serie_hist
   where nu_indca_perfm = indice
   and nu_instan_dimen__1  = instan(1)
   and nu_instan_dimen__2  = instan(2)
   and nu_instan_dimen__3  = instan(3)
   and nu_instan_dimen__4  = instan(4)
   and nu_instan_dimen__5  = instan(5)
   and nu_instan_dimen__6  = instan(6)
   and nu_instan_dimen__7  = instan(7)
   and nu_instan_dimen__8  = instan(8)
   and nu_instan_dimen__9  = instan(9)
   and nu_instan_dimen__10 = instan(10)
   and nu_instan_dimen__11 = instan(11)
   and nu_instan_dimen__12 = instan(12)
   and nu_instan_dimen__13 = instan(13)
   and nu_instan_dimen__14 = instan(14)
   and nu_instan_dimen__15 = instan(15)
   and nu_instan_dimen__16 = instan(16)
   and fc_refr_serie_hist between   fdesde   and fhasta
   and cd_grnl_serie_hist =  granul;
elsif rtrim(consol) = 'FIRST' then
   select min(fc_refr_serie_hist)
   into fc_temp from v_serie_hist
   where nu_indca_perfm = indice
   and nu_instan_dimen__1  = instan(1)
   and nu_instan_dimen__2  = instan(2)
   and nu_instan_dimen__3  = instan(3)
   and nu_instan_dimen__4  = instan(4)
   and nu_instan_dimen__5  = instan(5)
   and nu_instan_dimen__6  = instan(6)
   and nu_instan_dimen__7  = instan(7)
   and nu_instan_dimen__8  = instan(8)
   and nu_instan_dimen__9  = instan(9)
   and nu_instan_dimen__10 = instan(10)
   and nu_instan_dimen__11 = instan(11)
   and nu_instan_dimen__12 = instan(12)
   and nu_instan_dimen__13 = instan(13)
   and nu_instan_dimen__14 = instan(14)
   and nu_instan_dimen__15 = instan(15)
   and nu_instan_dimen__16 = instan(16)
   and fc_refr_serie_hist between   fdesde and fhasta
   and cd_grnl_serie_hist =  granul;
   select ct_valor_serie_hist
   into resul from v_serie_hist
   where nu_indca_perfm = indice
   and nu_instan_dimen__1  = instan(1)
   and nu_instan_dimen__2  = instan(2)
   and nu_instan_dimen__3  = instan(3)
   and nu_instan_dimen__4  = instan(4)
   and nu_instan_dimen__5  = instan(5)
   and nu_instan_dimen__6  = instan(6)
   and nu_instan_dimen__7  = instan(7)
   and nu_instan_dimen__8  = instan(8)
   and nu_instan_dimen__9  = instan(9)
   and nu_instan_dimen__10 = instan(10)
   and nu_instan_dimen__11 = instan(11)
   and nu_instan_dimen__12 = instan(12)
   and nu_instan_dimen__13 = instan(13)
   and nu_instan_dimen__14 = instan(14)
   and nu_instan_dimen__15 = instan(15)
   and nu_instan_dimen__16 = instan(16)
   and fc_refr_serie_hist = fc_temp
   and cd_grnl_serie_hist =  granul;
else  -- asume last
   select max(fc_refr_serie_hist)
   into fc_temp from v_serie_hist
   where nu_indca_perfm = indice
   and nu_instan_dimen__1  = instan(1)
   and nu_instan_dimen__2  = instan(2)
   and nu_instan_dimen__3  = instan(3)
   and nu_instan_dimen__4  = instan(4)
   and nu_instan_dimen__5  = instan(5)
   and nu_instan_dimen__6  = instan(6)
   and nu_instan_dimen__7  = instan(7)
   and nu_instan_dimen__8  = instan(8)
   and nu_instan_dimen__9  = instan(9)
   and nu_instan_dimen__10 = instan(10)
   and nu_instan_dimen__11 = instan(11)
   and nu_instan_dimen__12 = instan(12)
   and nu_instan_dimen__13 = instan(13)
   and nu_instan_dimen__14 = instan(14)
   and nu_instan_dimen__15 = instan(15)
   and nu_instan_dimen__16 = instan(16)
   and fc_refr_serie_hist between   fdesde   and fhasta
   and cd_grnl_serie_hist =  granul;
   select ct_valor_serie_hist
   into resul from v_serie_hist
   where nu_indca_perfm = indice
   and nu_instan_dimen__1  = instan(1)
   and nu_instan_dimen__2  = instan(2)
   and nu_instan_dimen__3  = instan(3)
   and nu_instan_dimen__4  = instan(4)
   and nu_instan_dimen__5  = instan(5)
   and nu_instan_dimen__6  = instan(6)
   and nu_instan_dimen__7  = instan(7)
   and nu_instan_dimen__8  = instan(8)
   and nu_instan_dimen__9  = instan(9)
   and nu_instan_dimen__10 = instan(10)
   and nu_instan_dimen__11 = instan(11)
   and nu_instan_dimen__12 = instan(12)
   and nu_instan_dimen__13 = instan(13)
   and nu_instan_dimen__14 = instan(14)
   and nu_instan_dimen__15 = instan(15)
   and nu_instan_dimen__16 = instan(16)
   and fc_refr_serie_hist = fc_temp
   and cd_grnl_serie_hist =  granul;
end if;
return 1;
exception
   when no_data_found then
      return 0;
   when others then
      return -1;
end CalcularValor;
end G3_SUP_CONS_TEMP;
/

CREATE OR REPLACE
package body WAREHOUSE.IMPORTA_DATOS as
type T_STRING_SHORT is table of varchar2(40) index by binary_integer;
type T_NUMBER       is table of number(8) index by binary_integer;
type T_CODE         is table of varchar2(20) index by binary_integer;
g_erro_tratado char(1) := '0';
g_dt_hoje date;
-----------------------------------------------------------------------------------------------
-- Procedure : INICIALIZA_TABELAS
-----------------------------------------------------------------------------------------------
procedure INICIALIZA_TABELAS (p_nu_fonte in number) is
  l_ultima_geracao date;
  i pls_integer;
begin
  -- Borrando de la tabla de instancias de dimension desconocidas las
  -- instancias que ya fueran importadas
  commit;
  set transaction use rollback segment r01;
  for r_dimen in (
     select distinct NU_DIMEN from G3_INSTAN_DIMEN_DESC)
  loop
     i:= 1;
     for r_old_desc in (select ROWID rid
           from G3_INSTAN_DIMEN_DESC
           where CD_INSTAN_DIMEN in
                 (select CD_INSTAN_DIMEN
                     from G3_COD_INSTAN_DIMEN
                     where NU_DIMEN = r_dimen.NU_DIMEN) and
                 NU_DIMEN = r_dimen.NU_DIMEN)
     loop
        delete from G3_INSTAN_DIMEN_DESC
           where ROWID = r_old_desc.rid;
        i:= i + 1;
        if i > 1000 then
           commit;
           i:= 1;
           set transaction use rollback segment r01;
        end if;
     end loop;
  end loop;
  commit;
  -- Seteando para cero el campo que informa el numero de registros rechazados para
  -- las instancias que ya estan en la tabla hace mas de una semana; esto
  -- es para evitar overflow del campo
  update G3_INSTAN_DIMEN_DESC
     set ct_regs_recz = 0
   where FC_INCL_INSTAN_DIMEN < g_dt_hoje - 7;
  -- Seteando los registros originarios de fuentes de aquel perfil para 0 (no rechazados)
  i:= 1;
  for r_dato in (select rowid rid from G3_EXTRT_SIG_DATO
                    where NU_FUENTE_INDCA_PERFM = p_nu_fonte and
                          CD_REGS_RECZ = '1') loop
  begin
     update G3_EXTRT_SIG_DATO
           set CD_REGS_RECZ = '0'
        where rowid = r_dato.rid;

     UPDATE G3_EXTRT_SIG_DATO
        SET CD_INSTAN_DIMEN__1=RTRIM(CD_INSTAN_DIMEN__1),
            CD_INSTAN_DIMEN__2=RTRIM(CD_INSTAN_DIMEN__2),
            CD_INSTAN_DIMEN__3=RTRIM(CD_INSTAN_DIMEN__3),
            CD_INSTAN_DIMEN__4=RTRIM(CD_INSTAN_DIMEN__4),
            CD_INSTAN_DIMEN__5=RTRIM(CD_INSTAN_DIMEN__5),
            CD_INSTAN_DIMEN__6=RTRIM(CD_INSTAN_DIMEN__6)
        WHERE rowid = r_dato.rid;

     i:= i + 1;
     if i > 1000 then
        commit;
        i:= 1;
     end if;
  end;
  end loop;
  commit;
end;
-----------------------------------------------------------------------------------------------
-- Function : GRAVA_DESC
--
-- Registra las instancias de dimension desconocidas encontradas durante el proceso de traduccion
-- de claves. Ritorna 0 si la instancia ya estaba grabada, 1 si no estaba.
--
-----------------------------------------------------------------------------------------------
function Grava_Desc(p_nu_dimen in number, p_cd_inst in varchar2, p_nu_fonte in number) return number is
begin
   insert into G3_INSTAN_DIMEN_DESC(
                  NU_DIMEN, CD_INSTAN_DIMEN,
                  NU_FUENTE_INDCA_PERFM,
                  CT_REGS_RECZ, FC_INCL_INSTAN_DIMEN)
      values(p_nu_dimen, p_cd_inst, p_nu_fonte, 1, g_dt_hoje);
   dbms_output.put_line('Inserte ' || p_cd_inst);
   return(1);
exception
   when DUP_VAL_ON_INDEX then
      update G3_INSTAN_DIMEN_DESC
         set CT_REGS_RECZ = nvl(CT_REGS_RECZ, 0) + 1
         where NU_DIMEN = p_nu_dimen and
               CD_INSTAN_DIMEN = p_cd_inst;
      return(0);
end;
-----------------------------------------------------------------------------------------------
-- Procedure : IMPORTA_VALORES
--
-- Traduce los codigos de las instancias de dimension y convalida los indicadores.
-- Ritorna TRUE si por lo menos uno registro tuver sido transferido para la tabla
-- movimiento (parte del lote fue importada) o FALSE si todos los registros tuverem sido rechazados.
--
-----------------------------------------------------------------------------------------------
function IMPORTA_VALORES (p_nu_fonte in NUMBER, p_nm_fonte in CHAR,
                          p_dt_gera in DATE) return BOOLEAN is
   l_debug VARCHAR2(500);
   l_dummy CHAR;
   insercao_ok exception;
   nao_traduziu exception;
   l_rejt char;  -- Sinaliza si el registro fue rechazado antes de la traduccion de claves
   Conta_Rejs_Instan binary_integer := 0; -- Numero de registros rechazados por instancia desconocida
   Conta_Rejs_Outros binary_integer := 0; -- Numero de registros rechazados por otros motivos
   Conta_Regs binary_integer := 0; -- Numero de registros procesados
   L_Visao_Ant number(5) := 0;
   l_t_dimens T_NUMBER; -- Vector que almacena los numeros de las dimensiones componentes de la vision
   l_t_inst_ant T_NUMBER;
   l_t_cd_ant T_CODE;
   l_t_nm_dimens T_STRING_SHORT; -- Vector que almacena los nombres de las dimensiones componentes de la vision
   l_t_instancias T_CODE; -- Vector que almacena la clave (antes y despues de la traduccion) de la instancia de vision
   i binary_integer;
   l_visao_indic number;
   l_indca_ant number := 0; -- Ultimo indicador procesado
   l_ult_indca_rej number := 0; -- Ultimo indicador rechazado
   contador pls_integer;
begin
  -- Para cada valor de la fecha de generacion especificada
  L_DEBUG:= 'Antes del loop';
  lock table G3_MOVT_SERIE_HIST in exclusive mode;
  G3_Log_Err.Log_Msj('A', 'Fecha gen: ' || p_dt_gera || '   Fuente: ' || p_nu_fonte);
  contador:= 1;
  for r_valor in (select /*+ ORDERED */ a.*,
             C1.NU_INSTAN_DIMEN NuInst1,
             C2.NU_INSTAN_DIMEN NuInst2,
             C3.NU_INSTAN_DIMEN NuInst3,
             C4.NU_INSTAN_DIMEN NuInst4,
             C5.NU_INSTAN_DIMEN NuInst5,
             C6.NU_INSTAN_DIMEN NuInst6
          from
               V_DATOS_CON_VISION a,
               G3_COD_INSTAN_DIMEN C1,
               G3_COD_INSTAN_DIMEN C2,
               G3_COD_INSTAN_DIMEN C3,
               G3_COD_INSTAN_DIMEN C4,
               G3_COD_INSTAN_DIMEN C5,
               G3_COD_INSTAN_DIMEN C6
          where C1.CD_INSTAN_DIMEN (+) = a.CD_INSTAN_DIMEN__1 and
                C1.NU_DIMEN (+) = a.NU_DIMEN__1 and
                C2.CD_INSTAN_DIMEN (+) = a.CD_INSTAN_DIMEN__2 and
                C2.NU_DIMEN (+) = a.NU_DIMEN__2 and
                C3.CD_INSTAN_DIMEN (+) = a.CD_INSTAN_DIMEN__3 and
                C3.NU_DIMEN (+) = a.NU_DIMEN__3 and
                C4.CD_INSTAN_DIMEN (+) = a.CD_INSTAN_DIMEN__4 and
                C4.NU_DIMEN (+) = a.NU_DIMEN__4 and
                C5.CD_INSTAN_DIMEN (+) = a.CD_INSTAN_DIMEN__5 and
                C5.NU_DIMEN (+) = a.NU_DIMEN__5 and
                C6.CD_INSTAN_DIMEN (+) = a.CD_INSTAN_DIMEN__6 and
                C6.NU_DIMEN (+) = a.NU_DIMEN__6 and
                a.FC_GEN_FUENTE_INDCA_PERFM = p_dt_gera and
                a.NU_FUENTE_INDCA_PERFM = p_nu_fonte)
  loop
     begin
       l_rejt := '0';
       -- Cambio la vision
       if L_Visao_Ant != r_valor.nu_vision then
          L_Visao_Ant := r_valor.nu_vision;
          -- Identificando dimensiones
          l_t_dimens(1):= r_valor.NU_DIMEN__1;
          l_t_dimens(2):= r_valor.NU_DIMEN__2;
          l_t_dimens(3):= r_valor.NU_DIMEN__3;
          l_t_dimens(4):= r_valor.NU_DIMEN__4;
          l_t_dimens(5):= r_valor.NU_DIMEN__5;
          l_t_dimens(6):= r_valor.NU_DIMEN__6;
          l_t_dimens(7):= r_valor.NU_DIMEN__7;
          l_t_dimens(8):= r_valor.NU_DIMEN__8;
          l_t_dimens(9):= r_valor.NU_DIMEN__9;
          l_t_dimens(10):= r_valor.NU_DIMEN__10;
          l_t_dimens(11):= r_valor.NU_DIMEN__11;
          l_t_dimens(12):= r_valor.NU_DIMEN__12;
          l_t_dimens(13):= r_valor.NU_DIMEN__13;
          l_t_dimens(14):= r_valor.NU_DIMEN__14;
          l_t_dimens(15):= r_valor.NU_DIMEN__15;
          l_t_dimens(16):= r_valor.NU_DIMEN__16;
          for i in 1..16 loop -- Guardo los nombres para mensajes posteriores
             l_t_inst_ant.delete(i);
             l_t_cd_ant.delete(i);
             select NM_DIMEN
                into l_t_nm_dimens(i)
                from G3_DIMEN
                where NU_DIMEN = l_t_dimens(i);
          end loop;
          L_DEBUG:= 'Despues Sel NmDim';
       end if;
       Conta_Regs:= Conta_Regs + 1;
       if r_valor.NU_INDCA_PERFM <> l_indca_ant then
          l_visao_indic:= r_valor.NU_VISION;
       else
          if r_valor.NU_INDCA_PERFM = l_ult_indca_rej then
             Conta_Rejs_Outros := Conta_Rejs_Outros + 1;
             l_rejt := '1';
          end if;
       end if;
       l_indca_ant := r_valor.NU_INDCA_PERFM;
       if l_rejt = '0' then begin
          g_erro_tratado := '0';
          -------------------------------------
          -- Traducion de Claves
          -------------------------------------
          -- Es mas facil lidar con un vector que con dieciseis campos
          -- Las 6 primeras se traducen en el cursor, por eficiencia
          L_DEBUG:= 'Ponendo en el vector';
          l_t_instancias(1):= r_valor.NuInst1;
          l_t_instancias(2):= r_valor.NuInst2;
          l_t_instancias(3):= r_valor.NuInst3;
          l_t_instancias(4):= r_valor.NuInst4;
          l_t_instancias(5):= r_valor.NuInst5;
          l_t_instancias(6):= r_valor.NuInst6;
          l_t_instancias(7):= rtrim(r_valor.CD_INSTAN_DIMEN__7);
          l_t_instancias(8):= rtrim(r_valor.CD_INSTAN_DIMEN__8);
          l_t_instancias(9):= rtrim(r_valor.CD_INSTAN_DIMEN__9);
          l_t_instancias(10):= rtrim(r_valor.CD_INSTAN_DIMEN__10);
          l_t_instancias(11):= rtrim(r_valor.CD_INSTAN_DIMEN__11);
          l_t_instancias(12):= rtrim(r_valor.CD_INSTAN_DIMEN__12);
          l_t_instancias(13):= rtrim(r_valor.CD_INSTAN_DIMEN__13);
          l_t_instancias(14):= rtrim(r_valor.CD_INSTAN_DIMEN__14);
          l_t_instancias(15):= rtrim(r_valor.CD_INSTAN_DIMEN__15);
          l_t_instancias(16):= rtrim(r_valor.CD_INSTAN_DIMEN__16);
          for i in 1..16 loop
          -- Intentar traducir
            begin
               if i > 6 then
                 L_DEBUG:= 'Traducire ' || i || '#' || l_t_instancias(i) || '#';
                 if l_t_cd_ant.exists(i) then  -- Si tengo algun codigo ant.
                    L_Debug:= 'Hay codigo anterior ' || l_t_cd_ant(i);
                    if l_t_cd_ant(i) = l_t_instancias(i) then -- y es igual
                       L_Debug:= 'Traduci de ' || l_t_instancias(i) || ' para ' || l_t_inst_ant(i);
                       l_t_instancias(i):= l_t_inst_ant(i);  -- Usar la traduc.
                    elsif l_t_dimens(i) != 0 then  -- Si la dimension no es dummy
                       l_t_cd_ant(i):= l_t_instancias(i);  -- almacenar codigo
                       L_Debug:= 'Voy buscar el numero de ' || l_t_nm_dimens(i);
                       select NU_INSTAN_DIMEN
                          into l_t_instancias(i)
                          from G3_COD_INSTAN_DIMEN
                          where NU_DIMEN = l_t_dimens(i) and
                                CD_INSTAN_DIMEN = l_t_instancias(i);
                       L_Debug:= 'Voy poner ' || l_t_instancias(i) || ' en ' || l_t_nm_dimens(i);
                       l_t_inst_ant(i):= l_t_instancias(i);  -- almacenar nombre
                    else
                       l_t_instancias(i):= 0;
                    end if;
                 elsif l_t_dimens(i) != 0 then  -- Si la dimension no es dummy
                    L_Debug:= 'Voy buscar el numero de ' || l_t_nm_dimens(i);
                    l_t_cd_ant(i):= l_t_instancias(i);
                    select NU_INSTAN_DIMEN
                       into l_t_instancias(i)
                       from G3_COD_INSTAN_DIMEN
                       where NU_DIMEN = l_t_dimens(i) and
                             CD_INSTAN_DIMEN = l_t_instancias(i);
                    L_Debug:= 'Voy poner ' || l_t_instancias(i) || ' en ' || l_t_nm_dimens(i);
                    l_t_inst_ant(i):= l_t_instancias(i);
                 else
                    l_t_instancias(i):= 0;
                 end if;
                 L_DEBUG:= 'Traduci ' || i;
               elsif l_t_instancias(i) is NULL then
                  if i = 1 then
                     l_t_instancias(i):= r_valor.CD_INSTAN_DIMEN__1;
                  elsif i = 2 then
                     l_t_instancias(i):= r_valor.CD_INSTAN_DIMEN__2;
                  elsif i = 3 then
                     l_t_instancias(i):= r_valor.CD_INSTAN_DIMEN__3;
                  elsif i = 4 then
                     l_t_instancias(i):= r_valor.CD_INSTAN_DIMEN__4;
                  elsif i = 5 then
                     l_t_instancias(i):= r_valor.CD_INSTAN_DIMEN__5;
                  elsif i = 6 then
                     l_t_instancias(i):= r_valor.CD_INSTAN_DIMEN__6;
                  end if;
                  raise NO_DATA_FOUND;
               end if;
            exception
            when TOO_MANY_ROWS then   -- Hay mas de una traduccion posible - error de usuario
                l_t_cd_ant.delete(i);
                G3_Log_Err.Log_Err_SH_Cd('Codigo duplicado en la dimension '
                   ||i|| '.',
                   p_nu_fonte, p_dt_gera, r_valor.FC_REFR_FUENTE_INDCA_PERFM,
                   r_valor.NU_INDCA_PERFM, r_valor.CT_DATO,
                   r_valor.CD_INSTAN_DIMEN__1, r_valor.CD_INSTAN_DIMEN__2,
                   r_valor.CD_INSTAN_DIMEN__3, r_valor.CD_INSTAN_DIMEN__4,
                   r_valor.CD_INSTAN_DIMEN__5, r_valor.CD_INSTAN_DIMEN__6,
                   r_valor.CD_INSTAN_DIMEN__7, r_valor.CD_INSTAN_DIMEN__8,
                   r_valor.CD_INSTAN_DIMEN__9, r_valor.CD_INSTAN_DIMEN__10,
                   r_valor.CD_INSTAN_DIMEN__11, r_valor.CD_INSTAN_DIMEN__12,
                   r_valor.CD_INSTAN_DIMEN__13, r_valor.CD_INSTAN_DIMEN__14,
                   r_valor.CD_INSTAN_DIMEN__15, r_valor.CD_INSTAN_DIMEN__16);
                Conta_Rejs_Outros := Conta_Rejs_Outros + 1;
                raise nao_traduziu;
             when NO_DATA_FOUND then  -- No halle el codigo - rechazar
                l_t_cd_ant.delete(i);
                if (Grava_Desc(l_t_dimens(i), l_t_instancias(i), p_nu_fonte) = 1) then
                   G3_Log_Err.Log_Err_SH_Cd('Codigo desconocido en la dimension '
                      ||i|| ' (' || l_t_nm_dimens(i) || ').',
                      p_nu_fonte, p_dt_gera, r_valor.FC_REFR_FUENTE_INDCA_PERFM,
                      r_valor.NU_INDCA_PERFM, r_valor.CT_DATO,
                      r_valor.CD_INSTAN_DIMEN__1, r_valor.CD_INSTAN_DIMEN__2,
                      r_valor.CD_INSTAN_DIMEN__3, r_valor.CD_INSTAN_DIMEN__4,
                      r_valor.CD_INSTAN_DIMEN__5, r_valor.CD_INSTAN_DIMEN__6,
                      r_valor.CD_INSTAN_DIMEN__7, r_valor.CD_INSTAN_DIMEN__8,
                      r_valor.CD_INSTAN_DIMEN__9, r_valor.CD_INSTAN_DIMEN__10,
                      r_valor.CD_INSTAN_DIMEN__11, r_valor.CD_INSTAN_DIMEN__12,
                      r_valor.CD_INSTAN_DIMEN__13, r_valor.CD_INSTAN_DIMEN__14,
                      r_valor.CD_INSTAN_DIMEN__15, r_valor.CD_INSTAN_DIMEN__16);
                end if;
                Conta_Rejs_Instan := Conta_Rejs_Instan + 1;
                raise nao_traduziu;
             end;
           end loop;
           -- Traducio todos. Insertar el valor en la tabla
           L_DEBUG:= 'Al insertar';
           insert into G3_Movt_Serie_Hist
               (nu_indca_perfm, nu_vision, nu_instan_dimen__1,
                nu_instan_dimen__2, nu_instan_dimen__3, nu_instan_dimen__4,
                nu_instan_dimen__5, nu_instan_dimen__6, nu_instan_dimen__7,
                nu_instan_dimen__8, nu_instan_dimen__9, nu_instan_dimen__10,
                nu_instan_dimen__11, nu_instan_dimen__12, nu_instan_dimen__13,
                nu_instan_dimen__14, nu_instan_dimen__15, nu_instan_dimen__16,
                fc_refr_movt, ct_indca_perfm_movt, nu_fuente_dato_movt,
                fc_gen_movt)
              values (r_valor.NU_INDCA_PERFM, r_valor.NU_VISION,
                      l_t_instancias(1), l_t_instancias(2),
                      l_t_instancias(3), l_t_instancias(4),
                      l_t_instancias(5), l_t_instancias(6),
                      l_t_instancias(7), l_t_instancias(8),
                      l_t_instancias(9), l_t_instancias(10),
                      l_t_instancias(11), l_t_instancias(12),
                      l_t_instancias(13), l_t_instancias(14),
                      l_t_instancias(15), l_t_instancias(16),
                      r_valor.fc_REFR_FUENTE_INDCA_PERFM,
                      r_valor.CT_DATO, p_nu_fonte, p_dt_gera);
--           Para sistemas poco confiables - garantiza la recuperacion del proceso
--           update G3_EXTRT_SIG_DATO
--              set CD_REGS_RECZ = '2'
--              where ROWID = r_valor.ROWID_DADO;
           exception
              when DUP_VAL_ON_INDEX then  -- Ja estava la. Acertar o valor.
                g_erro_tratado := '1';
                L_DEBUG:= 'Al update';
                update G3_Movt_Serie_Hist
                   set ct_indca_perfm_movt = r_valor.CT_DATO,
                       fc_gen_movt = p_dt_gera
                   where nu_instan_dimen__16 = l_t_instancias(16)
                     and nu_instan_dimen__15 = l_t_instancias(15)
                     and nu_instan_dimen__14 = l_t_instancias(14)
                     and nu_instan_dimen__13 = l_t_instancias(13)
                     and nu_instan_dimen__12 = l_t_instancias(12)
                     and nu_instan_dimen__11 = l_t_instancias(11)
                     and nu_instan_dimen__10 = l_t_instancias(10)
                     and nu_instan_dimen__9 = l_t_instancias(9)
                     and nu_instan_dimen__8 = l_t_instancias(8)
                     and nu_instan_dimen__7 = l_t_instancias(7)
                     and nu_instan_dimen__6 = l_t_instancias(6)
                     and nu_instan_dimen__5 = l_t_instancias(5)
                     and nu_instan_dimen__4 = l_t_instancias(4)
                     and nu_instan_dimen__3 = l_t_instancias(3)
                     and nu_instan_dimen__2 = l_t_instancias(2)
                     and nu_instan_dimen__1 = l_t_instancias(1)
                     and nu_vision = r_valor.NU_VISION
                     and fc_refr_movt = r_valor.FC_REFR_FUENTE_INDCA_PERFM
                     and nu_indca_perfm = r_valor.NU_INDCA_PERFM;
             when NAO_TRADUZIU then  -- Marca el registro como rechazado
                update G3_EXTRT_SIG_DATO set cd_regs_recz = '1'
                      where ROWID = r_valor.ROWID_DADO;
          end;
       end if;
     end;
     if contador > 1000 then
        commit;
        set transaction use rollback segment r01;
        contador:= 1;
        lock table g3_movt_serie_hist in exclusive mode;
     end if;
     if L_rejt = 0 then
        contador:= contador + 1;
     end if;
  end loop;
  G3_Log_Err.Log_Msj('D', Conta_Regs || ' registros processados.');
  if Conta_Rejs_Instan + Conta_Rejs_Outros > 0 then
     G3_Log_Err.Log_Msj('A', Conta_Rejs_Instan + Conta_Rejs_Outros || ' registros rechazados.');
  else
     delete from G3_EXTRT_SIG_CTRL
        where nu_fuente_indca_perfm = p_nu_fonte
          and FC_GEN_FUENTE_INDCA_PERFM = p_dt_gera;
  end if;
  contador:= 0;
  L_Debug:= 'Borrando datos procesados';

  -- ##### IMPORTANTE #####
  -- Si se desea la funcionalidad para sistemas poco confiables, el valor contra lo cual se
  -- compara cd_regs_recz debe ser '2'
  for r_del in (select rowid rid
                   from g3_extrt_sig_dato
                   where cd_regs_recz  ='0' and
                         nu_fuente_indca_perfm = p_nu_fonte and
                         FC_GEN_FUENTE_INDCA_PERFM = p_dt_gera) loop
  begin
     delete from G3_EXTRT_SIG_DATO
        where ROWID = r_del.rid;
     if contador > 1000 then
        commit;
        contador:= 0;
     end if;
     contador:= contador + 1;
  end;
  end loop;
  commit;
  -- Caso el numero de registros procesados sea mas grande que el numero de rechazados, significa
  -- que por lo menos uno registro fue importado. En este caso, la funcion ritorna TRUE; caso contrario
  -- la funcion ritorna FALSE
  if Conta_Regs > Conta_Rejs_Instan + Conta_Rejs_Outros then
     return TRUE;
  else
     return FALSE;
  end if;
exception
   when OTHERS then
      G3_Log_Err.Log_Msj('E', SQLERRM);
      G3_Log_Err.Log_Msj('E', l_dEBUG);
      RAISE;
end;
-----------------------------------------------------------------------------------------------
-- Procedure : TRADUCE_CLAVES
-----------------------------------------------------------------------------------------------
procedure TRADUCE_CLAVES (p_nu_usuario in NUMBER, p_nu_perfil in number, p_nu_fuente in number) is
  l_dummy char(1);
  l_importado boolean; -- TRUE si por lo menos uno registro del lote fue importado; FALSE si
                       -- todos tuverem sido rechazados
  l_reprocessamento boolean; -- TRUE si el lote estuver siendo reprocesado (por
                             -- de rechazamiento de registros)
begin
  g_dt_hoje := sysdate;
  Inicializa_Tabelas (p_nu_fuente);
  -- Para cada registro de controle de archivo importado
  set transaction use rollback segment r01;
  for r_sist in
    (select a.*, b.nm_fuente_indca_perfm
        from G3_EXTRT_SIG_CTRL a, G3_Fuente_Indca_Perfm b
        where a.NU_FUENTE_INDCA_PERFM = b.nu_fuente_indca_perfm
          and a.NU_FUENTE_INDCA_PERFM = p_nu_fuente
        order by a.fc_gen_fuente_indca_perfm desc)
  loop
    begin
      G3_Log_Err.Log_Msj('D',  'Inicio del procesamiento de la fuente '
                         || P_NU_FUENTE);
      -- Estos datos ya fueran importados ?
      select 'x' into l_dummy
         from G3_Log_Fuente_Indca_Perfm
         where nu_fuente_indca_perfm = r_sist.NU_FUENTE_INDCA_PERFM
           and fc_gen_fuente_indca_perfm = r_sist.FC_GEN_FUENTE_INDCA_PERFM;
      raise too_many_rows;
      exception
         -- Estos datos ya fueran importados. Voy actualizar los valores.
         when too_many_rows then
            l_reprocessamento := TRUE;
         -- Estos datos todavia no fueran importados.
         when no_data_found then
             -- Graba el registro de controle del log de la fuente de datos
            insert into G3_LOG_FUENTE_INDCA_PERFM(
                    NU_FUENTE_INDCA_PERFM,
                    FC_GEN_FUENTE_INDCA_PERFM,
                    FC_REFR_FUENTE_INDCA_PERFM,
                    FC_EJEC_INTERF)
                values(r_sist.NU_FUENTE_INDCA_PERFM,
                       r_sist.FC_GEN_FUENTE_INDCA_PERFM,
                       r_sist.FC_GEN_FUENTE_INDCA_PERFM,
                       g_dt_hoje);
            l_reprocessamento := FALSE;
      end;
      -- Importar os dados e traduzir as chaves
      l_importado :=  Importa_Valores (r_sist.NU_FUENTE_INDCA_PERFM, r_sist.nm_fuente_indca_perfm,
                                       r_sist.FC_GEN_FUENTE_INDCA_PERFM);
      -- Caso el lote estea siendo reprocesado y por lo menos uno registro tuver pasado para
      -- la tabla movimiento. En este caso, tengo que setear el campo FC_ATUALIZ_DW como nulo para
      -- indicar que el lote debe ser procesado por la rutina ATUALIZA_DW
      if l_reprocessamento = TRUE and l_importado = TRUE then
         update G3_LOG_FUENTE_INDCA_PERFM set
                FC_ATUALIZ_DW = NULL,
                FC_EJEC_INTERF = g_dt_hoje
             where NU_FUENTE_INDCA_PERFM = r_sist.NU_FUENTE_INDCA_PERFM and
                   FC_GEN_FUENTE_INDCA_PERFM = r_sist.FC_GEN_FUENTE_INDCA_PERFM and
                   FC_REFR_FUENTE_INDCA_PERFM = r_sist.FC_GEN_FUENTE_INDCA_PERFM;
      else
         -- Caso el lote estea siendo procesado por la primera vez y ningun registro tuver
         -- pasado para la tabla movimiento, borra el registro de controle
         -- del log de la fuente de datos
         if l_reprocessamento = FALSE and l_importado = FALSE then
            delete from G3_LOG_FUENTE_INDCA_PERFM
               where NU_FUENTE_INDCA_PERFM = r_sist.NU_FUENTE_INDCA_PERFM
                 and FC_GEN_FUENTE_INDCA_PERFM = r_sist.FC_GEN_FUENTE_INDCA_PERFM
                 and FC_REFR_FUENTE_INDCA_PERFM = r_sist.FC_GEN_FUENTE_INDCA_PERFM;
         end if;
      end if;
      G3_Log_Err.Log_Msj('D', 'Fin del procesamiento de la fuente '
                         || p_nu_fuente);
  end loop;
  commit;
  exception
    when others then
       if g_erro_tratado = '0' then
          G3_Log_Err.Log_Msj('E', SQLERRM(sqlcode));
          rollback;
       end if;
       G3_Log_Err.Log_Msj('E', 'Fim del procesamiento de la fuente ' || p_nu_fuente || ' con errores.');
  end;
end IMPORTA_DATOS;
/

CREATE OR REPLACE
package body WAREHOUSE.SUP_DW
as
-- Tipos para almacenar el cache de visiones
type R_CACHE_VISION is record (
   NU_PRIM_TABLA  pls_integer,
   NU_CANT_TABLAS pls_integer
);
type T_CACHE_VISION is table of R_CACHE_VISION index by binary_integer;
-- Tipos para almacenar el cache de limites de tablas de datos
type R_CACHE_TABLAS is record (
   NM_TABLA_SH    varchar2(35),
   FC_MIN_TABLA_SH   date,
   FC_MAX_TABLA_SH   date,
   NU_DIMEN_TABLA_SH number(5),
   NU_NIVL_LOGC_MIN  number(2),
   NU_NIVL_LOGC_MAX  number(2)
);
type T_CACHE_TABLAS is table of R_CACHE_TABLAS index by binary_integer;
-- Para el cache de tablas de datos
type T_TABLE_NAMES is table of varchar2(35) index by binary_integer;
type T_TABLE_CURSORS is table of integer index by binary_integer;
-- Para hacer el cache de fechas de indicadores
type R_FECHAS is record (
   Fc_Gen DATE,
   Fc_Min DATE,
   Fc_Max DATE);
type T_FECHAS is table of R_FECHAS index by binary_integer;
-- Para hacer el cache de niveles de instancias de dimension
type R_INST_LEVEL is record (
   Nu_Inst G3_INSTAN_DIMEN.NU_INSTAN_DIMEN%TYPE,
   Nu_Nivl G3_INSTAN_DIMEN.NU_NIVL_LOGC_DIMEN%TYPE);
type T_INST_LEVELS is table of R_INST_LEVEL index by binary_integer;
type T_VISIONS is table of G3_VISION%rowtype index by binary_integer;
Tb_Cache_Vision T_CACHE_VISION;
Tb_Cache_Tablas T_CACHE_TABLAS;
-- Almacena los nombres de las tablas de serie historica
T_Tablas T_TABLE_NAMES;
-- Almacena los cursores de insercion en las tablas de serie historica
T_Cursores T_TABLE_CURSORS;
-- Almacena los niveles de la ultima instancia de cada dimension
T_Cache T_INST_LEVELS;
-- Almacena las fechas de actualizacion de los indicadores
T_Fc_Indca T_FECHAS;
T_Visiones T_VISIONS;
-- SQL Dinamico de insercion en tablas de serie historica
P1_SQL constant varchar2(2000):= 'begin insert into ';
P2_SQL constant varchar2(2000):= '(NU_INDCA_PERFM,NU_VISION,NU_INSTAN_DIMEN__1,' ||
   'NU_INSTAN_DIMEN__2,NU_INSTAN_DIMEN__3,NU_INSTAN_DIMEN__4,NU_INSTAN_DIMEN__5,' ||
   'NU_INSTAN_DIMEN__6,NU_INSTAN_DIMEN__7,NU_INSTAN_DIMEN__8,NU_INSTAN_DIMEN__9,' ||
   'NU_INSTAN_DIMEN__10,NU_INSTAN_DIMEN__11,NU_INSTAN_DIMEN__12,NU_INSTAN_DIMEN__13,' ||
   'NU_INSTAN_DIMEN__14,NU_INSTAN_DIMEN__15,NU_INSTAN_DIMEN__16,FC_REFR_SERIE_HIST,' ||
   'CD_GRNL_SERIE_HIST,CT_VALOR_SERIE_HIST,NU_FUENTE_INDCA_PERFM,' ||
   'FC_GEN_FUENTE_INDCA_PERFM) values (:A,:B,:C,:D,:E,:F,:G,:H,:I,:J,:L,' ||
   ':M,:N,:O,:P,:Q,:R,:S,:T,:U,:V,:X,:Z); exception when DUP_VAL_ON_INDEX then update ';
P3_SQL constant varchar2(2000):= ' set CT_VALOR_SERIE_HIST=:V,NU_FUENTE_INDCA_PERFM=:X,' ||
   'FC_GEN_FUENTE_INDCA_PERFM=:Z where NU_INDCA_PERFM=:A and NU_VISION=:B and ' ||
   'NU_INSTAN_DIMEN__1=:C and NU_INSTAN_DIMEN__2=:D and NU_INSTAN_DIMEN__3=:E and NU_INSTAN_DIMEN__4=:F and ' ||
   'NU_INSTAN_DIMEN__5=:G and NU_INSTAN_DIMEN__6=:H and NU_INSTAN_DIMEN__7=:I and ' ||
   'NU_INSTAN_DIMEN__8=:J and NU_INSTAN_DIMEN__9=:L and NU_INSTAN_DIMEN__10=:M and ' ||
   'NU_INSTAN_DIMEN__11=:N and NU_INSTAN_DIMEN__12=:O and NU_INSTAN_DIMEN__13=:P and NU_INSTAN_DIMEN__14=:Q and ' ||
   'NU_INSTAN_DIMEN__15=:R and NU_INSTAN_DIMEN__16=:S and FC_REFR_SERIE_HIST=:T and CD_GRNL_SERIE_HIST=:U; end;';
LOG_DETALLADO constant BOOLEAN := TRUE;  /* Controla la cantidad de log
                   generado por las rutinas de este
                   package. Con TRUE, genera detalle
                   de cada paso. Con FALSE, solo errores. */
FUENTE_DATOS_CALC constant varchar2(30):= 'DATOS CALCULADOS';
Fc_Inic_Calc date:= NULL;         -- Fecha de inicio de los calculos
Id_Var_calc number(5):= NULL;     -- Indicador siendo calculado
Id_Fuente_Datos number(5):= NULL; -- Fuente pasada a la rutina de calculo
-------------------------------------------------------------------------
--  Function: Inic_Calc
--     Debe ser llamada antes de la ejecucion del calculo de cada indicador
--  Parametros:
--     P_Id_Var:    Identificador del indicador a calcular
--     P_Id_Fuente: Codigo de la fuente de datos con que guardar los valores
--                  calculados
--     P_Fc_Gen:    Fecha de generacion con que guardar los valores
--                  calculados
--  Valor de Retorno:
--     True : Puede seguir con el calculo.
--     False: Calculo no autorizado; interromper.
--------------------------------------------------------------------------
function Inic_Calc(P_Id_Var in number,
         P_Id_Fuente out number,
         P_Fc_Gen out date) return boolean is
   L_TIPO_IND char(2);
   L_DUMMY char(1);
begin
   -- Estamos en estado de calculo ?
   if (Estado_DW != 'A') and (Estado_DW != 'F') then
      G3_LOG_ERR.Log_Msj('E', 'Intento de calcular indicador ' ||
    to_char(P_Id_Var) || ' fuera del estado de calculo.');
      return FALSE;
   end if;
   -- Hay otro indicador en calculo ?
   if Id_Var_Calc is not NULL then
      G3_LOG_ERR.Log_Msj('E', 'Calculo del indicador ' ||
         to_char(Id_Var_Calc) ||' no fue finalizado.');
      return(FALSE);
   end if;
   -- Verificar si el indicador es calculado
   select CD_TIPO_INDCA_PERFM
      into L_TIPO_IND
      from G3_INDCA_PERFM
      where NU_INDCA_PERFM = P_Id_Var;
   if L_TIPO_IND != 'CC' then
      G3_LOG_ERR.Log_Msj('E', 'Indicador ' || to_char(P_Id_Var) ||
       ' no es calculate full.');
      return FALSE;
   end if;
   begin
      select NU_FUENTE_INDCA_PERFM
         into Id_Fuente_Datos
         from G3_FUENTE_INDCA_PERFM
         where upper(NM_FUENTE_INDCA_PERFM) = FUENTE_DATOS_CALC;
   exception
      when NO_DATA_FOUND then
         G3_LOG_ERR.Log_Msj('E', 'No hay fuente de datos para los calculos.');
         return FALSE;
   end;
   -- Generando un log para la fuente de datos
   begin
      -- Ya tiene una fecha de generacion ?
      if Fc_Inic_Calc is not NULL then
         -- Ya fue creado el log de la fuente ?
         select 'x'
            into L_DUMMY
            from G3_LOG_FUENTE_INDCA_PERFM
            where NU_FUENTE_INDCA_PERFM = Id_Fuente_Datos and
                  FC_GEN_FUENTE_INDCA_PERFM = Fc_Inic_Calc and
                  FC_REFR_FUENTE_INDCA_PERFM = Fc_Inic_Calc;
         update G3_LOG_FUENTE_INDCA_PERFM
            set FC_ATUALIZ_DW = NULL,
                FC_EJEC_INTERF = Fc_Inic_Calc
            where NU_FUENTE_INDCA_PERFM = Id_Fuente_Datos and
                  FC_GEN_FUENTE_INDCA_PERFM = Fc_Inic_Calc and
                  FC_REFR_FUENTE_INDCA_PERFM = Fc_Inic_Calc;
      else
         Fc_Inic_Calc:= SYSDATE;
         raise NO_DATA_FOUND;
      end if;
   exception
      when NO_DATA_FOUND then -- Crear el log de la fuente
         insert into G3_LOG_FUENTE_INDCA_PERFM(
            NU_FUENTE_INDCA_PERFM, FC_GEN_FUENTE_INDCA_PERFM,
            FC_REFR_FUENTE_INDCA_PERFM, NU_ASU_INFM,
            FC_EJEC_INTERF, FC_ATUALIZ_DW)
            values(Id_Fuente_Datos, Fc_Inic_Calc,
                   Fc_Inic_Calc, NULL, Fc_Inic_Calc, NULL);
         commit;
   end;
   P_Id_Fuente:= Id_Fuente_Datos;
   P_Fc_Gen:= Fc_Inic_Calc;
   Id_Var_Calc:= P_Id_Var;
   if LOG_DETALLADO then
      G3_LOG_ERR.Log_Msj('D', 'Inicio del calculo del indicador ' || to_char(P_Id_Var) || '.');
   end if;
   return(TRUE);
exception
   when NO_DATA_FOUND then
      G3_LOG_ERR.Log_Msj('E', 'Indicador ' || to_char(P_Id_Var) || ' desconocido.');
      return FALSE;
   when OTHERS then
      G3_LOG_ERR.Log_Msj('E', 'Error de Oracle: ' || SQLERRM);
      return FALSE;
end Inic_Calc;
---------------------------------------------------------------------------
--  Procedure: Fin_Calc
--     Llamada al final de cada calculo de indicadores.
--  Parametros:
--     P_Id_Var:  Identificador del indicador que fue calculado.
--     P_Ct_Regs: Cantidad de registros generados
---------------------------------------------------------------------------
procedure Fin_Calc(P_Id_Var in number,
         P_Ct_Regs in number) is
begin
   -- Hay algun indicador en calculo ?
   if Id_Var_Calc is NULL then
      G3_LOG_ERR.Log_Msj('E', 'No hay ningun indicador en calculo.');
      return;
   end if;
   -- Es el mismo indicador que se empezo a calcular ?
   if P_Id_Var != Id_Var_Calc then
      G3_LOG_ERR.Log_Msj('E', 'El indicador ' || to_char(P_Id_Var) ||
         ' no esta en calculo.');
      return;
   end if;
   -- Fue generado algun registro ?
   if P_Ct_Regs < 1 then
      G3_LOG_ERR.Log_Msj('E', 'No fue generado ningun registro para el indicador ' ||
      to_char(P_Id_Var) || '.');
   end if;
   Id_Var_Calc:= NULL;
   Id_Fuente_Datos:= NULL;
   commit;
   if LOG_DETALLADO then
      G3_LOG_ERR.Log_Msj('D', 'Fin del calculo del indicador ' || to_char(P_Id_Var) ||
                         '. ' || to_char(P_Ct_Regs) || ' registros generados.');
   end if;
end Fin_Calc;
--------------------------------------------------------------------------
--  Function: Nm_Tab_Sh
--     Retorna la tabla donde se encuentran los datos para una dada fecha,
--     vision y combinacion de niveles logicos de dimensiones.
--  Parametros:
--     P_Fc_Ref:    Fecha de referencia de los datos a que se desea acceder
--     P_Nu_Vision: Vision de los datos a que se desea acceder
--     P_Niveles:   Niveles de las dimensiones de los datos a que se desea acceder
--                  Es obligacion del usuario de esta rutina informar los
--                  niveles para todas las dimensiones involucradas, o la
--                  rutina puede retornar un nombre de tabla errado.
--  Valor de Retorno:
--     Nombre de la tabla donde estan los datos a que se desea acceder.
---------------------------------------------------------------------------
procedure Carga_Caches is
   Rec_Tabla R_CACHE_TABLAS;
   L_Ult_Vis number(5);
   i pls_integer;
begin
   I:= 1;
   L_Ult_Vis:= 0;
   for R_Vision in (select NU_VISION, NU_TABLA_SH
                       from G3_TABLA_SH_VISION
                       order by NU_VISION) loop
   begin
      select NM_TABLA_SH,
             FC_MIN_TABLA_SH,
             FC_MAX_TABLA_SH,
             NU_DIMEN_TABLA_SH,
             NU_NIVL_LOGC_MIN,
             NU_NIVL_LOGC_MAX
         into Rec_Tabla
         from G3_TABLA_SH
         where NU_TABLA_SH = R_Vision.NU_TABLA_SH;
      Tb_Cache_Tablas(i):= Rec_Tabla;
      if L_Ult_Vis != R_Vision.NU_VISION then
         if L_Ult_Vis != 0 then
            Tb_Cache_Vision(L_Ult_Vis).Nu_Cant_Tablas:=
                           i - Tb_Cache_Vision(L_Ult_Vis).Nu_Prim_Tabla;
         end if;
         Tb_Cache_Vision(R_Vision.NU_VISION).Nu_Prim_Tabla:= i;
         L_Ult_Vis:= R_Vision.NU_VISION;
      end if;
      i:= i + 1;
   end;
   end loop;
   Tb_Cache_Vision(L_Ult_Vis).Nu_Cant_Tablas:=
                  i - Tb_Cache_Vision(L_Ult_Vis).Nu_Prim_Tabla;
end Carga_Caches;
------------------------
function Nm_Tab_Sh(P_Fc_Ref in date,
         P_Nu_Vision in number,
         P_Niveles in T_NIVL_DIMEN) return varchar2 is
   i pls_integer;
   j pls_integer;
begin
   if Tb_Cache_Vision.First is NULL then
      Carga_Caches;
   end if;
   for i in Tb_Cache_Vision(P_Nu_Vision).Nu_Prim_Tabla..
       Tb_Cache_Vision(P_Nu_Vision).Nu_Prim_Tabla +
       Tb_Cache_Vision(P_Nu_Vision).Nu_Cant_Tablas - 1
   loop
      if (P_Fc_Ref between
                 nvl(TB_Cache_Tablas(i).Fc_Min_Tabla_SH, to_date('01011900', 'DDMMYYYY')) and
                 nvl(Tb_Cache_Tablas(i).Fc_Max_Tabla_SH, to_date('31122099', 'DDMMYYYY'))) then
         if (Tb_Cache_Tablas(i).Nu_Dimen_Tabla_SH is not null) then
            for j in P_Niveles.First..P_Niveles.Last loop
               if (P_Niveles(j).Nu_Dimen = Tb_Cache_Tablas(i).Nu_Dimen_Tabla_SH) and
                  (P_Niveles(j).Nu_Nivl between Tb_Cache_Tablas(i).Nu_Nivl_Logc_Max and
                                                Tb_Cache_Tablas(i).Nu_Nivl_Logc_Min) then
                  return(Tb_Cache_Tablas(i).Nm_Tabla_SH);
               end if;
            end loop;
         else
            return(Tb_Cache_Tablas(i).Nm_Tabla_SH);
         end if;
      end if;
   end loop;
   return('G3_SERIE_HIST_OTROS');
exception
   when NO_DATA_FOUND then
      G3_LOG_ERR.Log_Msj('E', 'Vision ' || P_Nu_Vision || ' no tiene tablas asociadas en G3_TABLA_SH_VISION.');
      return('G3_SERIE_HIST_OTROS');
   when OTHERS then
      G3_LOG_ERR.Log_Msj('E', 'Vision ' || P_Nu_Vision || ' Dimen ' || P_Niveles(j).Nu_Dimen);
      raise;
end Nm_Tab_SH;
---------------------------------------------------------------------------
--  Procedure: Lim_Tab_Sh
--     Retorna los limites de tiempo, todas las visiones y niveles de las
--     dimensiones para los cuales hay datos en una determinada tabla.
--     Datos para cualquier combinacion de estas restricciones debem
--     estar en esta tabla.
--  Parametros:
--     P_Nm_Tab:   Nombre de la tabla para la cual se quieren los limites
--     P_Fc_Inic:  Fecha inicial de los datos en la tabla
--     P_Fc_Fin:   Fecha final de los datos en la tabla
--     P_Visiones: Lista de visiones cuyos datos estan en la tabla
--     P_Niveles:  Lista de niveles de dimension cuyos datos estan en la tabla
---------------------------------------------------------------------------
procedure Lim_Tab_Sh(P_Nm_Tab in varchar2,
                     P_Fc_Inic out date,
                     P_Fc_Fin out date,
                     P_Visiones out T_VISION,
                     P_Niveles out T_NIVL_DIMEN) is
   Nu_Tabla number;
   i pls_integer;
begin
   select FC_MIN_TABLA_SH,
          FC_MAX_TABLA_SH,
          NU_TABLA_SH,
          NU_DIMEN_TABLA_SH,
          NU_NIVL_LOGC_MIN,
          NU_DIMEN_TABLA_SH,
          NU_NIVL_LOGC_MAX
      into P_Fc_Inic, P_Fc_Fin, Nu_Tabla,
           P_Niveles(1).Nu_Dimen,
           P_Niveles(1).Nu_Nivl,
           P_Niveles(2).Nu_Dimen,
           P_Niveles(2).Nu_Nivl
      from G3_TABLA_SH
      where NM_TABLA_SH = upper(P_Nm_Tab);
   i:= 1;
   for r_vision in (select NU_VISION from G3_TABLA_SH_VISION where NU_TABLA_SH = Nu_Tabla) loop
      P_Visiones(i):= r_vision.NU_VISION;
      i:= i + 1;
   end loop;
exception
   when NO_DATA_FOUND then
      G3_LOG_ERR.Log_Msj('E', 'Tabla ' || P_Nm_Tab || ' desconocida.');
end Lim_Tab_Sh;
---------------------------------------------------------------------------
--  Function: Estado_DW
--     Retorna el estado actual de la maquina de calculo, donde
--        I: Importacion de instancias de dimensiones
--        J: Importacion de jerarquias
--        D: Importacion de datos
--        A: Calculo de indicadores calculate/consolidate
--        W: Transferencia de datos al Warehouse
--        C: Consolidacion Jerarquica
--        F: Calculo de indicadores calculate full
--        T: Consolidacion temporal
--        M: Transferencia de datos a los data marts
--        L: Limpieza del data warehouse
--   -: Idle
---------------------------------------------------------------------------
function Estado_DW return char is
   Val_Estado char(1);
begin
   select TX_VL_PARM_SIST
      into Val_Estado
      from G3_PARM_SIST
      where NU_PARM_SIST = 1;
   return(Val_Estado);
exception
   when NO_DATA_FOUND then
      G3_LOG_ERR.Log_Msj('E', 'Parametro "Estado del Data Warehouse" no encontrado.');
      return(NULL);
end Estado_DW;
-----------------------------------------------------------------------------
--  De este punto adelante estan las rutinas, tipos e variables del entorno de
--  grabacion dinamica de registros.
-----------------------------------------------------------------------------
-------------------------------------------------
--   Prepara_Dinamico: Prepara el entorno para la insercion de valores en
--   las tablas de serie historica a traves de SQL dinamico. Deber ser llamada
--   una sola vez, antes del primer uso de Graba_Reg_SH.
--------------------------------------------------
procedure Prepara_Dinamico is
   i pls_integer;
begin
   if T_Tablas.Exists(1) then
      return;
   end if;
   T_Cache.delete;
   i:= 0;
   for r_tabs in (select TABLE_NAME
                     from ALL_TABLES
                     where OWNER = 'WAREHOUSE' and
                           TABLE_NAME like 'G3_SERIE_HIST%')
   loop
      i:= i + 1;
      T_Tablas(i):= r_tabs.TABLE_NAME;
   end loop;
end Prepara_Dinamico;
-----------------------------------------------------
function Determ_Nivel(Dimen in number, Inst in Number) return number is
begin
   if T_Cache.Exists(Dimen) then
      if T_Cache(Dimen).Nu_Inst = Inst then
         return(T_Cache(Dimen).Nu_Nivl);
      end if;
   end if;
   begin
      select NU_NIVL_LOGC_DIMEN
         into T_Cache(Dimen).Nu_Nivl
         from G3_INSTAN_DIMEN
         where NU_DIMEN = Dimen and
               NU_INSTAN_DIMEN = Inst;
   exception
      when NO_DATA_FOUND then
         T_Cache(Dimen).Nu_Nivl:= 1;
   end;
   T_Cache(Dimen).Nu_Inst:= Inst;
   return(T_Cache(Dimen).Nu_Nivl);
end;
---------------------------------------------------------
-- Function: Determ_Tab_SH. Dado un registro de dados determina la tabla
-- donde estes deberan ser guardados
---------------------------------------------------------
function Determ_Tab_SH(Reg in G3_SERIE_HIST_INDCA%rowtype) return varchar2 is
   i pls_integer;
   Niveles T_NIVL_DIMEN;
begin
   if NOT T_Visiones.Exists(Reg.NU_VISION) then
      select *
         into T_Visiones(Reg.NU_VISION)
         from G3_VISION
         where NU_VISION = Reg.NU_VISION;
   end if;
   if T_Visiones(Reg.NU_VISION).NU_DIMEN__1 != 0 then
      Niveles(1).Nu_Dimen:= T_Visiones(Reg.NU_VISION).NU_DIMEN__1;
      Niveles(1).Nu_Nivl:= determ_nivel(T_Visiones(Reg.NU_VISION).NU_DIMEN__1,
                           Reg.NU_INSTAN_DIMEN__1);
   end if;
   if T_Visiones(Reg.NU_VISION).NU_DIMEN__2 != 0 then
      Niveles(2).Nu_Dimen:= T_Visiones(Reg.NU_VISION).NU_DIMEN__2;
      Niveles(2).Nu_Nivl:= determ_nivel(T_Visiones(Reg.NU_VISION).NU_DIMEN__2,
                           Reg.NU_INSTAN_DIMEN__2);
   end if;
   if T_Visiones(Reg.NU_VISION).NU_DIMEN__3 != 0 then
      Niveles(3).Nu_Dimen:= T_Visiones(Reg.NU_VISION).NU_DIMEN__3;
      Niveles(3).Nu_Nivl:= determ_nivel(T_Visiones(Reg.NU_VISION).NU_DIMEN__3,
                           Reg.NU_INSTAN_DIMEN__1);
   end if;
   if T_Visiones(Reg.NU_VISION).NU_DIMEN__4 != 0 then
      Niveles(4).Nu_Dimen:= T_Visiones(Reg.NU_VISION).NU_DIMEN__4;
      Niveles(4).Nu_Nivl:= determ_nivel(T_Visiones(Reg.NU_VISION).NU_DIMEN__4,
                           Reg.NU_INSTAN_DIMEN__4);
   end if;
   if T_Visiones(Reg.NU_VISION).NU_DIMEN__5 != 0 then
      Niveles(5).Nu_Dimen:= T_Visiones(Reg.NU_VISION).NU_DIMEN__5;
      Niveles(5).Nu_Nivl:= determ_nivel(T_Visiones(Reg.NU_VISION).NU_DIMEN__5,
                           Reg.NU_INSTAN_DIMEN__5);
   end if;
   if T_Visiones(Reg.NU_VISION).NU_DIMEN__6 != 0 then
      Niveles(6).Nu_Dimen:= T_Visiones(Reg.NU_VISION).NU_DIMEN__6;
      Niveles(6).Nu_Nivl:= determ_nivel(T_Visiones(Reg.NU_VISION).NU_DIMEN__6,
                           Reg.NU_INSTAN_DIMEN__6);
   end if;
   if T_Visiones(Reg.NU_VISION).NU_DIMEN__7 != 0 then
      Niveles(7).Nu_Dimen:= T_Visiones(Reg.NU_VISION).NU_DIMEN__7;
      Niveles(7).Nu_Nivl:= determ_nivel(T_Visiones(Reg.NU_VISION).NU_DIMEN__7,
                           Reg.NU_INSTAN_DIMEN__7);
   end if;
   if T_Visiones(Reg.NU_VISION).NU_DIMEN__8 != 0 then
      Niveles(8).Nu_Dimen:= T_Visiones(Reg.NU_VISION).NU_DIMEN__8;
      Niveles(8).Nu_Nivl:= determ_nivel(T_Visiones(Reg.NU_VISION).NU_DIMEN__8,
                           Reg.NU_INSTAN_DIMEN__8);
   end if;
   if T_Visiones(Reg.NU_VISION).NU_DIMEN__9 != 0 then
      Niveles(9).Nu_Dimen:= T_Visiones(Reg.NU_VISION).NU_DIMEN__9;
      Niveles(9).Nu_Nivl:= determ_nivel(T_Visiones(Reg.NU_VISION).NU_DIMEN__9,
                           Reg.NU_INSTAN_DIMEN__9);
   end if;
   if T_Visiones(Reg.NU_VISION).NU_DIMEN__10 != 0 then
      Niveles(10).Nu_Dimen:= T_Visiones(Reg.NU_VISION).NU_DIMEN__10;
      Niveles(10).Nu_Nivl:= determ_nivel(T_Visiones(Reg.NU_VISION).NU_DIMEN__10,
                            Reg.NU_INSTAN_DIMEN__10);
   end if;
   if T_Visiones(Reg.NU_VISION).NU_DIMEN__11 != 0 then
      Niveles(11).Nu_Dimen:= T_Visiones(Reg.NU_VISION).NU_DIMEN__11;
      Niveles(11).Nu_Nivl:= determ_nivel(T_Visiones(Reg.NU_VISION).NU_DIMEN__11,
                            Reg.NU_INSTAN_DIMEN__11);
   end if;
   if T_Visiones(Reg.NU_VISION).NU_DIMEN__12 != 0 then
      Niveles(12).Nu_Dimen:= T_Visiones(Reg.NU_VISION).NU_DIMEN__12;
      Niveles(12).Nu_Nivl:= determ_nivel(T_Visiones(Reg.NU_VISION).NU_DIMEN__12,
                            Reg.NU_INSTAN_DIMEN__12);
   end if;
   if T_Visiones(Reg.NU_VISION).NU_DIMEN__13 != 0 then
      Niveles(13).Nu_Dimen:= T_Visiones(Reg.NU_VISION).NU_DIMEN__13;
      Niveles(13).Nu_Nivl:= determ_nivel(T_Visiones(Reg.NU_VISION).NU_DIMEN__13,
                            Reg.NU_INSTAN_DIMEN__13);
   end if;
   if T_Visiones(Reg.NU_VISION).NU_DIMEN__14 != 0 then
      Niveles(14).Nu_Dimen:= T_Visiones(Reg.NU_VISION).NU_DIMEN__14;
      Niveles(14).Nu_Nivl:= determ_nivel(T_Visiones(Reg.NU_VISION).NU_DIMEN__14,
                            Reg.NU_INSTAN_DIMEN__14);
   end if;
   if T_Visiones(Reg.NU_VISION).NU_DIMEN__15 != 0 then
      Niveles(15).Nu_Dimen:= T_Visiones(Reg.NU_VISION).NU_DIMEN__15;
      Niveles(15).Nu_Nivl:= determ_nivel(T_Visiones(Reg.NU_VISION).NU_DIMEN__15,
                            Reg.NU_INSTAN_DIMEN__15);
   end if;
   if T_Visiones(Reg.NU_VISION).NU_DIMEN__16 != 0 then
      Niveles(16).Nu_Dimen:= T_Visiones(Reg.NU_VISION).NU_DIMEN__16;
      Niveles(16).Nu_Nivl:= determ_nivel(T_Visiones(Reg.NU_VISION).NU_DIMEN__16,
                            Reg.NU_INSTAN_DIMEN__16);
   end if;
   return Nm_Tab_SH(Reg.FC_REFR_SERIE_HIST, Reg.NU_VISION, Niveles);
exception
   when OTHERS then
      dbms_output.put_line('Em Determ_Tab_SH');
      raise;
end Determ_tab_SH;
-------------------------------------------------------------
procedure Graba_Reg_SH(Reg in G3_SERIE_HIST_INDCA%ROWTYPE) is
   TabName varchar2(35);
   Actualizar boolean;
   Cd_Ind char(1);
   i pls_integer;
   dummy pls_integer;
begin
   TabName:= determ_tab_sh(Reg);
   i:= 1;
   while (i <= T_Tablas.Last) and
         (T_Tablas(i) != TabName)
   loop
      i:= i + 1;
   end loop;
   if i > T_Tablas.Last then   -- Tabla desconocida
      return;
   end if;
   if not T_Cursores.Exists(i) then  -- El cursor de insercion en TabName todavia no fue creado
      T_Cursores(i):= dbms_sql.open_cursor;
      dbms_sql.parse(T_Cursores(i), P1_SQL || TabName || P2_SQL || TabName || P3_SQL, dbms_sql.V7);
   end if;
   dbms_sql.bind_variable(T_Cursores(i), ':A', Reg.NU_INDCA_PERFM);
   dbms_sql.bind_variable(T_Cursores(i), ':B', Reg.NU_VISION);
   dbms_sql.bind_variable(T_Cursores(i), ':C', Reg.NU_INSTAN_DIMEN__1);
   dbms_sql.bind_variable(T_Cursores(i), ':D', Reg.NU_INSTAN_DIMEN__2);
   dbms_sql.bind_variable(T_Cursores(i), ':E', Reg.NU_INSTAN_DIMEN__3);
   dbms_sql.bind_variable(T_Cursores(i), ':F', Reg.NU_INSTAN_DIMEN__4);
   dbms_sql.bind_variable(T_Cursores(i), ':G', Reg.NU_INSTAN_DIMEN__5);
   dbms_sql.bind_variable(T_Cursores(i), ':H', Reg.NU_INSTAN_DIMEN__6);
   dbms_sql.bind_variable(T_Cursores(i), ':I', Reg.NU_INSTAN_DIMEN__7);
   dbms_sql.bind_variable(T_Cursores(i), ':J', Reg.NU_INSTAN_DIMEN__8);
   dbms_sql.bind_variable(T_Cursores(i), ':L', Reg.NU_INSTAN_DIMEN__9);
   dbms_sql.bind_variable(T_Cursores(i), ':M', Reg.NU_INSTAN_DIMEN__10);
   dbms_sql.bind_variable(T_Cursores(i), ':N', Reg.NU_INSTAN_DIMEN__11);
   dbms_sql.bind_variable(T_Cursores(i), ':O', Reg.NU_INSTAN_DIMEN__12);
   dbms_sql.bind_variable(T_Cursores(i), ':P', Reg.NU_INSTAN_DIMEN__13);
   dbms_sql.bind_variable(T_Cursores(i), ':Q', Reg.NU_INSTAN_DIMEN__14);
   dbms_sql.bind_variable(T_Cursores(i), ':R', Reg.NU_INSTAN_DIMEN__15);
   dbms_sql.bind_variable(T_Cursores(i), ':S', Reg.NU_INSTAN_DIMEN__16);
   dbms_sql.bind_variable(T_Cursores(i), ':T', Reg.FC_REFR_SERIE_HIST);
   dbms_sql.bind_variable(T_Cursores(i), ':U', Reg.CD_GRNL_SERIE_HIST);
   dbms_sql.bind_variable(T_Cursores(i), ':V', Reg.CT_VALOR_SERIE_HIST);
   dbms_sql.bind_variable(T_Cursores(i), ':X', Reg.NU_FUENTE_INDCA_PERFM);
   dbms_sql.bind_variable(T_Cursores(i), ':Z', Reg.FC_GEN_FUENTE_INDCA_PERFM);
   dummy:= dbms_sql.execute(T_Cursores(i));
   Actualizar:= False;
   -- Tengo el indicador en el cache de fechas ?
   if not T_Fc_Indca.Exists(reg.NU_INDCA_PERFM) then
      select FC_ULT_ATUAL_INDCA,
             nvl(FC_LIM_INF_INDCA, reg.FC_REFR_SERIE_HIST),
             nvl(FC_LIM_SUP_INDCA, reg.FC_REFR_SERIE_HIST),
             nvl(CD_INDCA_ATUAL, '0')
         into T_Fc_Indca(reg.NU_INDCA_PERFM).Fc_Gen,
              T_Fc_Indca(reg.NU_INDCA_PERFM).Fc_Min,
              T_Fc_Indca(reg.NU_INDCA_PERFM).Fc_Max,
              Cd_Ind
         from G3_INDCA_PERFM
         where NU_INDCA_PERFM = reg.NU_INDCA_PERFM;
   end if;
   if (Cd_Ind = '0') or (Cd_Ind = '2') then
      --G3_LOG_ERR.Log_Msj('A', 'Actualizando para ' || reg.FC_GEN_FUENTE_INDCA_PERFM ||
      --                   ', ' || reg.FC_REFR_SERIE_HIST);
      Actualizar:= True;
      T_Fc_Indca(reg.NU_INDCA_PERFM).Fc_Gen:= reg.FC_GEN_FUENTE_INDCA_PERFM;
      T_Fc_Indca(reg.NU_INDCA_PERFM).Fc_Min:= reg.FC_REFR_SERIE_HIST;
      T_Fc_Indca(reg.NU_INDCA_PERFM).Fc_Max:= reg.FC_REFR_SERIE_HIST;
   else
      -- Es necesario actualizar la fecha de ultima actualizacion ?
      if reg.FC_GEN_FUENTE_INDCA_PERFM < T_Fc_Indca(reg.NU_INDCA_PERFM).Fc_Gen then
         Actualizar:= True;
         --G3_LOG_ERR.Log_Msj('A', 'Actualizando FC_GEN para ' || reg.FC_GEN_FUENTE_INDCA_PERFM);
         T_Fc_Indca(reg.NU_INDCA_PERFM).Fc_Gen:= reg.FC_GEN_FUENTE_INDCA_PERFM;
      end if;
      -- Es necesario actualizar el limite isquierdo ?
      if reg.FC_REFR_SERIE_HIST < T_Fc_Indca(reg.NU_INDCA_PERFM).Fc_Min then
         Actualizar:= True;
         --G3_LOG_ERR.Log_Msj('A', 'Actualizando FC_MIN para ' || reg.FC_REFR_SERIE_HIST);
         T_Fc_Indca(reg.NU_INDCA_PERFM).Fc_Min:= reg.FC_REFR_SERIE_HIST;
      end if;
      -- Es necesario actualizar el limite derecho ?
      if reg.FC_REFR_SERIE_HIST > T_Fc_Indca(reg.NU_INDCA_PERFM).Fc_Max then
         Actualizar:= True;
         --G3_LOG_ERR.Log_Msj('A', 'Actualizando FC_MAX para ' || reg.FC_REFR_SERIE_HIST);
         T_Fc_Indca(reg.NU_INDCA_PERFM).Fc_Max:= reg.FC_REFR_SERIE_HIST;
      end if;
   end if;
   if Actualizar then
      update G3_INDCA_PERFM
         set CD_INDCA_ATUAL = '1',
             FC_ULT_ATUAL_INDCA = T_Fc_Indca(reg.NU_INDCA_PERFM).Fc_Gen,
             FC_LIM_INF_INDCA = T_Fc_Indca(reg.NU_INDCA_PERFM).Fc_Min,
             FC_LIM_SUP_INDCA = T_Fc_Indca(reg.NU_INDCA_PERFM).Fc_Max
         where NU_INDCA_PERFM = reg.NU_INDCA_PERFM;
      --G3_LOG_ERR.Log_Msj('A', 'Actualizado.');
   end if;
end Graba_Reg_SH;
------------------------------------------------
procedure Libera_Dinamico is
   i pls_integer;
begin
   if not T_Tablas.exists(1) then
      return;
   end if;
   for i in T_Cursores.First..T_Cursores.Last loop
      if T_Cursores.Exists(i) then
         dbms_sql.close_cursor(T_Cursores(i));
         T_Cursores.delete(i);
      end if;
   end loop;
   T_Fc_Indca.delete;
   T_Tablas.delete;
   T_Cache.delete;
   T_Visiones.delete;
end Libera_Dinamico;
begin
   Prepara_Dinamico;
end SUP_DW;
/
