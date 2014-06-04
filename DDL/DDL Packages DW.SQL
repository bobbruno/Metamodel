
CREATE OR REPLACE
package WAREHOUSE.G3_LOG_ERR as
   /* Inicia el log de mensajes para la rutina informada.
      Parm: Nombre (codigo) de la rutina, hasta 5 caracteres. */
   procedure Inic_Log(P_Nm_Rutina in VARCHAR2);
  ------------------------------------------------------------------------
   /* Graba una mensaje de error para un registro rechazado
      en la carga de datos. Para los casos en que se pueda hacer
      la traduccion. */
   procedure Log_Err_SH_Nu(
   P_Texto in varchar2,       /* Texto del mensaje */
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
   P_Nu_Instan_16 in number:= NULL);   /* Instancia 16 (numero) */
                       -------------------------------
   procedure Log_Err_SH_Cd(
   P_Texto in varchar2,       /* Texto del mensaje */
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
   P_Cd_Instan_16 in varchar2:= NULL); /* Instancia 16 (codigo) */
                       -------------------------------
   procedure Log_Err_Atrib(
   P_Texto in varchar2,       /* Texto del mensaje */
   P_Fuente in number,        /* Fuente de los datos */
   P_Fc_Gen in date,       /* Fecha de generacion */
   P_Tx_Atrb in varchar2,        /* Valor del atributo */
   P_Nu_Dimen in number,         /* Dimension siendo importada */
   P_Nu_Atrb_Dimen in number,    /* Atributo siendo importado */
   P_Nu_Instan_Dimen in number,     /* Instancia siendo importada */
   P_Cd_Instan_Dimen in varchar2:= NULL); /* Instancia siendo importada */
                       -------------------------------
   procedure Log_Msj(
   P_Tipo_Msj in char,        /* Tipo del mensaje */
   P_Texto in varchar2);         /* Texto de la mensaje */
  ------------------------------------------------------------------------
   -- Termina y graba un log de mensajes. Es un error terminar un log que
   -- no estea abierto. Este error sera grabado en el log.
   -- IMPORTANTE: ESTA PROCEDURE EJECUTA UN COMMIT;
   procedure Termina_Log;
                       -------------------------------
   -- Termina, sin grabar, un log de mensajes. Es un error terminar un log
   -- que no estea abierto. Este error sera grabado en el log.
   procedure Aborta_Log;
end G3_LOG_ERR;
/

CREATE OR REPLACE
package WAREHOUSE.G3_PROC_ADMIN is
   procedure Save_Deriv(lNU_INDCA_PERFM NUMBER,lNU_ORDEN NUMBER,
              lCD_TIPO_OPERADOR CHAR,lCD_OPERADOR CHAR, lCD_GRUPO CHAR);
   procedure Save_Dimensiones(lIndicador NUMBER,lOrden NUMBER);
   function Hay_Datos(P_Dimen in NUMBER, P_Inst in NUMBER) return boolean;
   procedure Sinc_Dimen_25;
   procedure Reg_Cambio_Dimen_24(reg in G3_INSTAN_DIMEN%ROWTYPE,
      Cambio in char);

end G3_PROC_ADMIN;
/

CREATE OR REPLACE
package WAREHOUSE.G3_PROC_ATRB_DIMEN as
   procedure POVOA_TEMPORARIA(p_dimen in number, p_instan in number);
   procedure ATUALIZA_ATRIBUTOS(p_dimen in number);
   procedure IMPORTA_ATRIBUTOS(p_nu_usuario in number);
   procedure IMPORTA_JERARQUIAS(p_nu_usuario in number);
end G3_PROC_ATRB_DIMEN;
/

CREATE OR REPLACE
PACKAGE WAREHOUSE.G3_PROC_CONS IS
   procedure INF_CLIENTE(SESSIONID in VARCHAR2);
   procedure INF_DIMEN(SESSIONID in VARCHAR2);
END;
/

CREATE OR REPLACE
package WAREHOUSE.G3_SRV_CRIA_DIMEN as
   procedure CRIA_DIMEN (p_nu_base in NUMBER);
end G3_SRV_CRIA_DIMEN;
/

CREATE OR REPLACE
package WAREHOUSE.G3_SUP_CONS_TEMP is
   -- Tipo de tabla de enteros
   type T_ENTERO is table of integer index by binary_integer;
   procedure ObtenerFechas(Granul in varchar2,
   FDesde in out date,
   FHasta in out date,
   SigHasta out date);
   function FinIntervalo(Granul in varchar2,
   FDesde in out date,
   FHasta in out date) return integer;
   function CalcularValor(indice in integer,
   instan in T_ENTERO,
   fdesde in date,
   fhasta in date,
   granul in char,
   consol in varchar2,
   resul out number) return integer;
end G3_SUP_CONS_TEMP;
/

CREATE OR REPLACE
package WAREHOUSE.IMPORTA_DATOS as
   procedure TRADUCE_CLAVES (p_nu_usuario in NUMBER, p_nu_perfil in number, p_nu_fuente in NUMBER);
end IMPORTA_DATOS;
/

CREATE OR REPLACE
package WAREHOUSE.SUP_DW as
   -- Record para informar o retornar los niveles de cada dimension
   type R_NIVL_DIMEN is record(
      Nu_Dimen G3_DIMEN.NU_DIMEN%TYPE,
      Nu_Nivl  G3_NIVL_LOGC_DIMEN.NU_NIVL_LOGC_DIMEN%TYPE);
   -- Tabla para informar o retornar los niveles de todas las dimensiones
   type T_NIVL_DIMEN is table of R_NIVL_DIMEN index by binary_integer;
   -- Tabla para retornar una lista de visiones
   type T_VISION is table of G3_VISION.NU_VISION%TYPE index by binary_integer;
   -- No hay tabla para las condiciones informadas o tabla desconocida
   TABLA_INDEFINIDA exception;

   -------------------------------------------------------------------
   --  Function: Nm_Tab_Sh
   --     Retorna la tabla donde se encuentran los datos para una dada fecha,
   --     vision y combinacion de niveles logicos de dimensiones. Las dimensiones
   --     son lasde la tabla G3_Dimen.
   --  Parametros:
   --     P_Fc_Ref:    Fecha de referencia de los datos a que se desea acceder
   --     P_Nu_Vision: Vision de los datos a que se desea acceder
   --     P_Niveles:   Niveles de las dimensiones de los datos a que se desea acceder
   --                  Es obligacion del usuario de esta rutina informar los
   --                  niveles para todas las dimensiones involucradas, o la
   --                  rutina puede retornar un nombre de tabla errado.
   --  Valor de Retorno:
   --     Nombre de la tabla donde estan los datos a que se desea acceder.
   function NM_TAB_SH(P_Fc_Ref in date,
            P_Nu_Vision in number,
            P_Niveles in T_NIVL_DIMEN) return varchar2;

   -------------------------------------------------------------------
   -- Retorna los limites de fecha, vision y niveles para una tabla
   --    P_Nm_Tab: Nombre de la tabla cuyos limites deseas saber
   --    P_Fc_Inic: Fecha inicial (mas antigua) que puede estar en la tabla
   --    P_Fc_Fin:  Fecha final (mas reciente) que puede estar en la tabla
   --    P_Visiones: Lista de visiones que pueden estar en la tabla
   --    P_Niveles: Lista de niveles de dimensiones que pueden estar en
   --               la tabla
   --    Los limites son combinados por AND.
   procedure LIM_TAB_SH(P_Nm_Tab in varchar2,
         P_Fc_Inic out date,
         P_Fc_Fin out date,
         P_Visiones out T_VISION,
         P_Niveles out T_NIVL_DIMEN);

   -------------------------------------------------------------------
   -- Debe ser llamada antes de cada proceso de calculo,
   --    informando el codigo del indicador (P_Id_Var), y recibiendo
   --    el codigo de la fuente de datos a grabar (P_Id_Fuente)
   --    y la fecha de generacion a grabar (P_Fc_Gen)
   --    Si la funcion retorna FALSE, la rutina de calculo debe retornar
   --    sin ejecutar el calculo. Es recomendable generar un mensaje de error
   --    en estos casos.
   function Inic_Calc(P_Id_Var in number,
            P_Id_Fuente out number,
            P_Fc_Gen out date) return boolean;

   -------------------------------------------------------------------
   -- Debe ser llamada despues de cada proceso de calculo,
   --    informando el numero del indicador calculado y la cantidad de
   --    de registros generados.
   procedure Fin_Calc(P_Id_Var in number, P_Ct_Regs in number);

   -------------------------------------------------------------------
   -- Retorna el estado actual de la maquina de calculo
   --    I: Importacion de instancias de dimensiones
   --    J: Importacion de jerarquias
   --    D: Importacion de datos
   --    A: Calculo de indicadores calculate/consolidate
   --    W: Transferencia de datos al Warehouse
   --    C: Consolidacion Jerarquica
   --    F: Calculo de indicadores calculate full
   --    T: Consolidacion temporal
   --    M: Transferencia de datos a los data marts
   --    -: Idle
   function Estado_DW return char;

   /*--------------------------------------------------------------------
     Procedure: Prepara_Dinamico
     Prepara el entorno de grabacion dinamica de registros de serie
     historica para que la procedure Graba_Reg_SH pueda ser utilizada.

     Esta rutina debe ser llamada antes de la primera ejecucion
     de Graba_Reg_SH.
    ---------------------------------------------------------------------*/
   procedure Prepara_Dinamico;

   /*--------------------------------------------------------------------
     Procedure: Graba_Reg_SH
     Graba un registro de serie historica en la tabla en la cual debe ser
     almacenado, determinada por la rutina Nm_Tab_SH.
     --------------------------------------------------------------------*/
   procedure Graba_Reg_SH(Reg in G3_SERIE_HIST_INDCA%ROWTYPE);

   /*--------------------------------------------------------------------
     Procedure: Libera_Dinamico
     Libera el espacio alocado al entorno de grabacion dinamica de registros
     utilizado por la rutina Graba_Reg_SH.

     Esta rutina deber ser llamada despues del termino de la grabacion
     a traves de Graba_Reg_SH.
     --------------------------------------------------------------------*/

   procedure Libera_Dinamico;
end SUP_DW;
/
