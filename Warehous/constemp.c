
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned long magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[12];
};
static const struct sqlcxp sqlfpn =
{
    11,
    "constemp.pc"
};


static const unsigned long sqlctx = 882458415;


static struct sqlexd {
   unsigned long    sqlvsn;
   unsigned long   arrsiz;
   unsigned long   iters;
   unsigned short   offset;
   unsigned short   selerr;
   unsigned short   sqlety;
   unsigned short   unused;
	 const    short   *cud;
   unsigned char    *sqlest;
	 const    char    *stmt;
   unsigned char  * *sqphsv;
   unsigned long   *sqphsl;
	    short  * *sqpind;
   unsigned long   *sqparm;
   unsigned long   * *sqparc;
   unsigned char    *sqhstv[23];
   unsigned long    sqhstl[23];
	    short   *sqindv[23];
   unsigned long    sqharm[23];
   unsigned long     *sqharc[23];
} sqlstm = {8,23};

/* Prototypes */
extern void sqlcxt (void **, const unsigned long *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, const unsigned long *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, const unsigned long *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(char *, unsigned long *);

 static const char *sq0001 = 
"select I.nu_indca_perfm ,I.nu_vision ,I.cd_grnl_indca_perfm ,ltrim(rtrim(I.c\
d_metd_cons_tiempo)) ,I.fc_ult_atual_indca ,I.FC_LIM_INF_INDCA ,I.FC_LIM_SUP_I\
NDCA ,sysdate   from G3_INDCA_PERFM I where (I.CD_INDCA_ATUAL='1' and INSTR(:b\
0,CD_GRNL_INDCA_PERFM)>0)           ";
 static const char *sq0005 = 
"select T.NM_TABLA_SH  from G3_TABLA_SH T ,G3_TABLA_SH_VISION V where (((T.FC\
_MIN_TABLA_SH<=:b0 and T.FC_MAX_TABLA_SH>=:b1) and T.NU_TABLA_SH=V.NU_TABLA_SH\
) and V.NU_VISION=:b2)           ";
 static const char *sq0007 = 
"select nu_indca_perfm ,nu_vision ,nu_instan_dimen__1 ,nu_instan_dimen__2 ,nu\
_instan_dimen__3 ,nu_instan_dimen__4 ,nu_instan_dimen__5 ,nu_instan_dimen__6 ,\
nu_instan_dimen__7 ,nu_instan_dimen__8 ,nu_instan_dimen__9 ,nu_instan_dimen__1\
0 ,nu_instan_dimen__11 ,nu_instan_dimen__12 ,nu_instan_dimen__13 ,nu_instan_di\
men__14 ,nu_instan_dimen__15 ,nu_instan_dimen__16 ,fc_refr_serie_hist ,ct_valo\
r_serie_hist ,nu_fuente_indca_perfm ,fc_gen_fuente_indca_perfm ,cd_grnl_serie_\
hist  from g3_temp_cons_temp            ";
typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{8,4130,
2,0,0,1,268,0,9,114,0,1,1,0,1,0,1,97,0,0,
20,0,0,1,0,0,15,122,0,0,0,0,1,0,
34,0,0,2,0,0,24,221,0,1,1,0,1,0,1,97,0,0,
52,0,0,1,0,0,13,251,0,8,0,0,1,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,
98,0,0,3,113,0,6,266,0,1,1,0,1,0,1,3,0,0,
116,0,0,4,96,0,6,281,0,4,4,0,1,0,1,9,0,0,3,97,0,0,3,97,0,0,2,97,0,0,
146,0,0,5,187,0,9,301,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,
172,0,0,5,0,0,13,304,0,1,0,0,1,0,2,9,0,0,
190,0,0,6,28,0,1,310,0,0,0,0,1,0,
204,0,0,7,506,0,9,354,0,0,0,0,1,0,
218,0,0,7,0,0,13,358,0,23,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,
0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
324,0,0,8,0,0,29,364,0,0,0,0,1,0,
338,0,0,7,0,0,15,369,0,0,0,0,1,0,
352,0,0,9,28,0,1,370,0,0,0,0,1,0,
366,0,0,5,0,0,15,373,0,0,0,0,1,0,
380,0,0,10,96,0,6,377,0,4,4,0,1,0,2,3,0,0,1,9,0,0,3,97,0,0,3,97,0,0,
410,0,0,11,142,0,6,388,0,2,2,0,1,0,1,3,0,0,1,9,0,0,
432,0,0,12,0,0,29,396,0,0,0,0,1,0,
446,0,0,13,40,0,1,397,0,0,0,0,1,0,
460,0,0,14,0,0,29,413,0,0,0,0,1,0,
474,0,0,15,40,0,1,414,0,0,0,0,1,0,
488,0,0,16,118,0,4,417,0,1,0,0,1,0,2,3,0,0,
};


#ifndef ORA_PROC
#include <stdio.h>
#include <string.h>
#endif
#include <sqlca.h>
#include <oraca.h>
#include "dw_aux.h"

static char Validos[20];

/******************************************************************************/
/* Funcion que determina las granularidades para las cuales debo intentar     */
/* consolidar temporalmente                                                   */
/******************************************************************************/

void determ_granul_valida(const char *opciones)
{
   register int i;

   *Validos = 0;
   for (i = 0; opciones[i]; i++) {
      switch (opciones[i]) {
	 case 'A':
	    strcat(Validos, "T");
	 case 'T':
	    strcat(Validos, "M");
	 case 'M':
	    strcat(Validos, "S");
	 case 'S':
	    strcat(Validos, "D");
	 case 'D':
	    break;
      }
   }
}

/******************************************************************************/
/* Funcion que determina si una opcion es valida.                             */
/******************************************************************************/
IsValidOption(char *opciones, char opcion)
{
   int 	i;

   for (i = 0; i < strlen(opciones); i++)
      if (opciones[i] == opcion)
         return(1);
   return(0);
}

/******************************************************************************/
/* Funcion que trae la siguiente granularidad a consolidar.                   */
/******************************************************************************/
char GetNextGranul(char *opciones, char orig, char grnl)
{
   switch(grnl)	{
      case 'D':
         if (IsValidOption(opciones, 'S'))
            return('S');
         else if(IsValidOption(opciones, 'M') && orig != 'S')
            return('M');
         else if(IsValidOption(opciones, 'A'))
            return('A');
         break;
      case 'S':
         if(orig == 'S') /* No se pueden pasar de semanales a mensuales */
	 {
            if (IsValidOption(opciones, 'A'))
               return('A');
         } 
	 else	{
            if (IsValidOption(opciones, 'M'))
               return('M');
            else
	    if (IsValidOption(opciones, 'A'))
               return('A');
         }
         break;
      case 'M':
         if (IsValidOption(opciones, 'A'))
            return('A');
         break;
      default:
         break;
   }
   return(' ');
}

/******************************************************************************/
/* Funcion de validacion del metodo de consolidacion.                         */
/******************************************************************************/
ValidMethod(char *Metodo)
{
   if (strcmp(Metodo, "SUM") != 0 &&
       strcmp(Metodo, "AVG") != 0 &&
       strcmp(Metodo, "FIRST") != 0 &&
       strcmp(Metodo, "LAST") != 0)
      return(0);
   return(1);
}

/******************************************************************************/
/* Funcion de declaracion del cursor por indicador                            */
/******************************************************************************/
static void DecCursorIndicador()
{
   /* EXEC SQL DECLARE Indicador CURSOR FOR	
      select I.nu_indca_perfm, I.nu_vision,
             I.cd_grnl_indca_perfm, ltrim(rtrim(I.cd_metd_cons_tiempo)),
	     I.fc_ult_atual_indca,
             I.FC_LIM_INF_INDCA, I.FC_LIM_SUP_INDCA, sysdate
	 from G3_INDCA_PERFM I
	 where I.CD_INDCA_ATUAL = '1' and
	       INSTR(:Validos, CD_GRNL_INDCA_PERFM) > 0; */ 

   /* EXEC SQL OPEN Indicador; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 1;
   sqlstm.stmt = sq0001;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)2;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)Validos;
   sqlstm.sqhstl[0] = (unsigned long  )20;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


}

/******************************************************************************/
/* Funcion de cierre del cursor por indicador                                 */
/******************************************************************************/
static void CerrarCursorIndicador()
{
   /* EXEC SQL CLOSE Indicador; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 1;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)20;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


}

/******************************************************************************/
/* Funcion de creacion de una tabla auxiliar para mejorar la performance de   */
/* la consolidacion.  Tomada de Gen_Tab_Temp_Cons (jerarq.pc).                */
/******************************************************************************/
static void GenTabAux(int Indca, int Vision, T_DATE Fc_Desde, 
                      T_DATE Fc_Hasta, char Grnl, char NueGrnl, T_DATE Fc_Ref,
		      T_DATE Fc_Gen, int Fuente, char *Metodo,
		      char *Nombre_Tabla)
{
   register int 	i;
   char	aux_sql[8192], temp[512];

   /* EXEC SQL whenever SQLERROR do sql_error("Consolidacion Temporal"); */ 


   /* Comienza a armar la estructura de la tabla */
   strcpy(aux_sql, "create table g3_temp_cons_temp(nu_indca_perfm,nu_vision,\n"
	"ct_valor_serie_hist,nu_instan_dimen__1,nu_instan_dimen__2,nu_instan_dimen__3,\n"
	"nu_instan_dimen__4,nu_instan_dimen__5,nu_instan_dimen__6,nu_instan_dimen__7,\n"
	"nu_instan_dimen__8,nu_instan_dimen__9,nu_instan_dimen__10,\n"
	"nu_instan_dimen__11,nu_instan_dimen__12,nu_instan_dimen__13,\n"
	"nu_instan_dimen__14,nu_instan_dimen__15,nu_instan_dimen__16,\n"
	"fc_refr_serie_hist,cd_grnl_serie_hist,\n"
	"nu_fuente_indca_perfm,fc_gen_fuente_indca_perfm) \n"
	"storage(INITIAL 4M NEXT 4M PCTINCREASE 0 MINEXTENTS 5 MAXEXTENTS UNLIMITED) \n"
	"TABLESPACE DW_TEMP UNRECOVERABLE PARALLEL (DEGREE 4) \n");
   sprintf(temp, "as select %d, %d, ", Indca, Vision);
   strcat(aux_sql, temp);

   /* Decide que metodo de consolidacion hay que aplicar -> define la estructura */
   /* del select.                                                                */
   if (strcmp(Metodo, "SUM") == 0 || strcmp(Metodo, "AVG") == 0) {
      sprintf(temp, "%s(ct_valor_serie_hist)\n", Metodo);
      strcat(aux_sql, temp);
      for (i = 0; i < 16; i++) {
         sprintf(temp, ",nu_instan_dimen__%d",i+1);
         strcat(aux_sql, temp);
      }
      sprintf(temp, ",\n'%s', '%c', %d, '%s' from \n", Fc_Ref, NueGrnl, Fuente, Fc_Gen);
      strcat(aux_sql, temp);
      strcat(aux_sql, Nombre_Tabla);
      strcat(aux_sql, " where nu_indca_perfm = ");
      sprintf(temp, "%d and nu_vision = %d \nand cd_grnl_serie_hist = '%c' \nand ", Indca, Vision, Grnl);
      strcat(aux_sql, temp);
      sprintf(temp, "fc_refr_serie_hist between '%s' and '%s'", Fc_Desde, Fc_Hasta);
      strcat(aux_sql, temp);
      strcat(aux_sql, "\n group by ");
      for (i = 0; i < 16; i++) {
         if (i > 0)
            strcat(aux_sql, ",");
         sprintf(temp, "nu_instan_dimen__%d",i+1);
         strcat(aux_sql, temp);
      }
   }
   else
   if (strcmp(Metodo, "FIRST") == 0 || strcmp(Metodo, "LAST") == 0) {
      strcat(aux_sql, "max(ct_valor_serie_hist)\n");
      for (i = 0; i < 16; i++) {
         sprintf(temp, ",nu_instan_dimen__%d",i+1);
         strcat(aux_sql, temp);
      }
      sprintf(temp, ",\n'%s', '%c', %d, '%s' from \n", Fc_Ref, NueGrnl, Fuente, Fc_Gen);
      strcat(aux_sql, temp);
      strcat(aux_sql, Nombre_Tabla);
      strcat(aux_sql, " a where nu_indca_perfm = ");
      sprintf(temp, "%d and nu_vision = %d and cd_grnl_serie_hist = '%c' \nand ",
              Indca, Vision, Grnl);
      strcat(aux_sql, temp);
      strcat(aux_sql, "fc_refr_serie_hist = (select ");
      if (strcmp(Metodo, "FIRST") == 0)
         strcat(aux_sql, " min(b.fc_refr_serie_hist) from \n");
      else
         strcat(aux_sql, " max(b.fc_refr_serie_hist) from \n");
      strcat(aux_sql, Nombre_Tabla);
      sprintf(temp, " b where b.nu_indca_perfm = %d and b.nu_vision = %d \n", Indca, Vision);
      strcat(aux_sql, temp);
      for (i = 0; i < 16; i++) {
         if (i == 6 || i == 11)
            strcat(aux_sql, "\n");
         sprintf(temp, "and a.nu_instan_dimen__%d = b.nu_instan_dimen__%d ",i+1, i+1);
         strcat(aux_sql, temp);
      }
      sprintf(temp, "\nand b.cd_grnl_serie_hist = '%c' and ", Grnl);
      strcat(aux_sql, temp);
      sprintf(temp, "fc_refr_serie_hist between '%s' and '%s')", Fc_Desde, Fc_Hasta);
      strcat(aux_sql, temp);
      strcat(aux_sql, "\n group by ");
      for (i = 0; i < 16; i++) {
         if (i > 0)
            strcat(aux_sql, ",");
         sprintf(temp, "nu_instan_dimen__%d",i+1);
         strcat(aux_sql, temp);
      }
   }
#ifdef __DEBUG
   printf("%s\n", aux_sql);
#else
   /* EXEC SQL EXECUTE IMMEDIATE :aux_sql; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 1;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)34;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)aux_sql;
   sqlstm.sqhstl[0] = (unsigned long  )8192;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Consolidacion Temporal");
}


#endif
}

/******************************************************************************/
/* Funcion de consolidacion que recibe los siguientes parametros:             */
/*    Fuente del dato.                                                        */
/*    Fecha de generacion.                                                    */
/*    Fecha desde.                                                            */
/*    Fecha hasta.                                                            */
/******************************************************************************/
static int Consolidar(char *opciones, int fuente)
{
   int	 OperOK;
   int	 NroIndic;
   int	 NroVision;
   register int i;
   short IndDesde, IndHasta;
   /* VARCHAR	Granul[2], LastGranul[2], Metodo[11], Nombre_Tabla[35]; */ 
struct { unsigned short len; unsigned char arr[2]; } Granul;

struct { unsigned short len; unsigned char arr[2]; } LastGranul;

struct { unsigned short len; unsigned char arr[11]; } Metodo;

struct { unsigned short len; unsigned char arr[35]; } Nombre_Tabla;

   T_DATE	fdesde, fhasta, FcUlt;
   T_DATE	AjDesde, AjHasta, SigDesde, SigHasta;
   T_REG_SH RgIn;
   T_DATE	fgeneracion;

   determ_granul_valida(opciones);
   printf("Consolidando los indicadores de granularidad dentro de <%s>...\n", Validos);
   /*	Apertura del cursor de indicadores	*/
   DecCursorIndicador();
   for (;;) {
      /* EXEC SQL WHENEVER NOT FOUND DO break; */ 

      /* EXEC SQL 
         FETCH Indicador 
	    into :NroIndic, :NroVision, :Granul, :Metodo, :FcUlt,
	         :fdesde:IndDesde, :fhasta:IndHasta, :fgeneracion; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 8;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)52;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&NroIndic;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&NroVision;
      sqlstm.sqhstl[1] = (unsigned long  )4;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&Granul;
      sqlstm.sqhstl[2] = (unsigned long  )4;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&Metodo;
      sqlstm.sqhstl[3] = (unsigned long  )13;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqhstv[4] = (unsigned char  *)FcUlt;
      sqlstm.sqhstl[4] = (unsigned long  )20;
      sqlstm.sqindv[4] = (         short *)0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqhstv[5] = (unsigned char  *)fdesde;
      sqlstm.sqhstl[5] = (unsigned long  )20;
      sqlstm.sqindv[5] = (         short *)&IndDesde;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqhstv[6] = (unsigned char  *)fhasta;
      sqlstm.sqhstl[6] = (unsigned long  )20;
      sqlstm.sqindv[6] = (         short *)&IndHasta;
      sqlstm.sqharm[6] = (unsigned long )0;
      sqlstm.sqhstv[7] = (unsigned char  *)fgeneracion;
      sqlstm.sqhstl[7] = (unsigned long  )20;
      sqlstm.sqindv[7] = (         short *)0;
      sqlstm.sqharm[7] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) break;
      if (sqlca.sqlcode < 0) sql_error("Consolidacion Temporal");
}


      /* EXEC SQL WHENEVER NOT FOUND continue; */ 

      Granul.arr[Granul.len] = '\0';
      strcpy((char *)LastGranul.arr, (char *)Granul.arr);
      LastGranul.len = Granul.len;
      LastGranul.arr[LastGranul.len] = '\0';
      Metodo.arr[Metodo.len] = '\0';
      fgeneracion[19] = '\0';
      printf("Indicador <%d>\n", NroIndic);

      /* Valida el metodo */
      if(!ValidMethod((char *)Metodo.arr)) {
	  /* EXEC SQL EXECUTE
	  begin
	     G3_LOG_ERR.Log_Msj('E', 'Metodo desconocido para indicador ' || to_char(:NroIndic) || '.');
	  end;
	  END-EXEC; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 8;
   sqlstm.stmt = "begin G3_LOG_ERR . Log_Msj ( 'E' , 'Metodo desconocido par\
a indicador ' || to_char ( :NroIndic ) || '.' ) ; end ;";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)98;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)&NroIndic;
   sqlstm.sqhstl[0] = (unsigned long  )4;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Consolidacion Temporal");
}


      }

      /*	Loop por granularidad */
      for(LastGranul.arr[0] = GetNextGranul(opciones, Granul.arr[0], LastGranul.arr[0]);
          LastGranul.arr[0] != ' ';
          LastGranul.arr[0] = GetNextGranul(opciones, Granul.arr[0], LastGranul.arr[0]))
      {
         /*	Se ajustan las fechas segun la granularidad	*/
	 strncpy(AjDesde, fdesde, 20);
	 strncpy(AjHasta, fhasta, 20);
	 /* EXEC SQL EXECUTE
	 begin
	    G3_SUP_CONS_TEMP.ObtenerFechas(:LastGranul, :AjDesde, :AjHasta, :SigHasta);
	 end;
	 END-EXEC; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 8;
  sqlstm.stmt = "begin G3_SUP_CONS_TEMP . ObtenerFechas ( :LastGranul , :AjD\
esde , :AjHasta , :SigHasta ) ; end ;";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)116;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (unsigned char  *)&LastGranul;
  sqlstm.sqhstl[0] = (unsigned long  )4;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqhstv[1] = (unsigned char  *)AjDesde;
  sqlstm.sqhstl[1] = (unsigned long  )20;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqhstv[2] = (unsigned char  *)AjHasta;
  sqlstm.sqhstl[2] = (unsigned long  )20;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqhstv[3] = (unsigned char  *)SigHasta;
  sqlstm.sqhstl[3] = (unsigned long  )20;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Consolidacion Temporal");
}


	 strncpy(SigDesde, AjDesde, 20);
	 printf("Obtencion de fechas desde: <%s> hasta: <%s>\n", AjDesde, AjHasta);
	 /*	Loop por fechas	*/
	 for(;;)
	 {
	    printf("Fecha de comienzo <%s>\n", SigDesde);

	    /* EXEC SQL DECLARE Tabelas cursor for
	       select T.NM_TABLA_SH
	          from G3_TABLA_SH T,
		       G3_TABLA_SH_VISION V
	          where T.FC_MIN_TABLA_SH <= :SigDesde and
		        T.FC_MAX_TABLA_SH >= :SigHasta and
			T.NU_TABLA_SH = V.NU_TABLA_SH and
			V.NU_VISION = :NroVision; */ 

	    /* EXEC SQL open Tabelas; */ 

{
     struct sqlexd sqlstm;

     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 8;
     sqlstm.arrsiz = 8;
     sqlstm.stmt = sq0005;
     sqlstm.iters = (unsigned long  )1;
     sqlstm.offset = (unsigned short)146;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)0;
     sqlstm.sqhstv[0] = (unsigned char  *)SigDesde;
     sqlstm.sqhstl[0] = (unsigned long  )20;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqhstv[1] = (unsigned char  *)SigHasta;
     sqlstm.sqhstl[1] = (unsigned long  )20;
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqhstv[2] = (unsigned char  *)&NroVision;
     sqlstm.sqhstl[2] = (unsigned long  )4;
     sqlstm.sqindv[2] = (         short *)0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode < 0) sql_error("Consolidacion Temporal");
}


	    for (;;) {
	       /* EXEC SQL WHENEVER NOT FOUND do break; */ 

	       /* EXEC SQL fetch Tabelas into :Nombre_Tabla; */ 

{
        struct sqlexd sqlstm;

        sqlorat((void **)0, &sqlctx, &oraca);
        sqlstm.sqlvsn = 8;
        sqlstm.arrsiz = 8;
        sqlstm.iters = (unsigned long  )1;
        sqlstm.offset = (unsigned short)172;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)0;
        sqlstm.sqhstv[0] = (unsigned char  *)&Nombre_Tabla;
        sqlstm.sqhstl[0] = (unsigned long  )37;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode == 1403) break;
        if (sqlca.sqlcode < 0) sql_error("Consolidacion Temporal");
}


	       /* EXEC SQL WHENEVER NOT FOUND continue; */ 

	       Nombre_Tabla.arr[Nombre_Tabla.len] = 0;
	       /* Se crea la tabla auxiliar con las fechas y tabla de origen estipuladas */
#ifndef __DEBUG
	       /* EXEC SQL whenever SQLERROR continue; */ 

	       /* EXEC SQL drop table g3_temp_cons_temp; */ 

{
        struct sqlexd sqlstm;

        sqlorat((void **)0, &sqlctx, &oraca);
        sqlstm.sqlvsn = 8;
        sqlstm.arrsiz = 8;
        sqlstm.stmt = "drop table g3_temp_cons_temp";
        sqlstm.iters = (unsigned long  )1;
        sqlstm.offset = (unsigned short)190;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


#endif
	       /* EXEC SQL whenever SQLERROR do sql_error("Cons. Temporal"); */ 

	       GenTabAux(NroIndic, NroVision, SigDesde, SigHasta, Granul.arr[0], LastGranul.arr[0], SigDesde, fgeneracion, fuente, (char *)Metodo.arr, Nombre_Tabla.arr);

	       /* Se declara la tabla creada */
	       /* EXEC SQL
		  DECLARE g3_temp_cons_temp TABLE (
			nu_indca_perfm number,
			nu_vision number,
			ct_valor_serie_hist number,
			nu_instan_dimen__1 number,
			nu_instan_dimen__2 number,
			nu_instan_dimen__3 number,
			nu_instan_dimen__4 number,
			nu_instan_dimen__5 number,
			nu_instan_dimen__6 number,
			nu_instan_dimen__7 number,
			nu_instan_dimen__8 number,
			nu_instan_dimen__9 number,
			nu_instan_dimen__10 number,
			nu_instan_dimen__11 number,
			nu_instan_dimen__12 number,
			nu_instan_dimen__13 number,
			nu_instan_dimen__14 number,
			nu_instan_dimen__15 number,
			nu_instan_dimen__16 number,
			fc_refr_serie_hist char(19),
			cd_grnl_serie_hist char(1),
			nu_fuente_indca_perfm number,
			fc_gen_fuente_indca_perfm char(19)); */ 


#ifndef __DEBUG
	       /*	Loop por los registros de la tabla */
	       /* EXEC SQL DECLARE CurTabla CURSOR FOR
		  select nu_indca_perfm, nu_vision, nu_instan_dimen__1,
			 nu_instan_dimen__2, nu_instan_dimen__3, nu_instan_dimen__4,
			 nu_instan_dimen__5, nu_instan_dimen__6, nu_instan_dimen__7,
			 nu_instan_dimen__8, nu_instan_dimen__9, nu_instan_dimen__10,
			 nu_instan_dimen__11, nu_instan_dimen__12, nu_instan_dimen__13,
			 nu_instan_dimen__14, nu_instan_dimen__15, nu_instan_dimen__16,
			 fc_refr_serie_hist, ct_valor_serie_hist, nu_fuente_indca_perfm,
			 fc_gen_fuente_indca_perfm, cd_grnl_serie_hist
		     from g3_temp_cons_temp; */ 

	       /* EXEC SQL OPEN CurTabla; */ 

{
        struct sqlexd sqlstm;

        sqlorat((void **)0, &sqlctx, &oraca);
        sqlstm.sqlvsn = 8;
        sqlstm.arrsiz = 8;
        sqlstm.stmt = sq0007;
        sqlstm.iters = (unsigned long  )1;
        sqlstm.offset = (unsigned short)204;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sql_error("Cons. Temporal");
}



	       for (i = 0;; i++) {
		  /* EXEC SQL whenever NOT FOUND do break; */ 

		  /* EXEC SQL fetch CurTabla into :RgIn; */ 

{
    struct sqlexd sqlstm;

    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 8;
    sqlstm.arrsiz = 23;
    sqlstm.iters = (unsigned long  )1;
    sqlstm.offset = (unsigned short)218;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)0;
    sqlstm.sqhstv[0] = (unsigned char  *)&RgIn.Indic;
    sqlstm.sqhstl[0] = (unsigned long  )4;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&RgIn.Vision;
    sqlstm.sqhstl[1] = (unsigned long  )4;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&RgIn.Inst1;
    sqlstm.sqhstl[2] = (unsigned long  )4;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&RgIn.Inst2;
    sqlstm.sqhstl[3] = (unsigned long  )4;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&RgIn.Inst3;
    sqlstm.sqhstl[4] = (unsigned long  )4;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&RgIn.Inst4;
    sqlstm.sqhstl[5] = (unsigned long  )4;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&RgIn.Inst5;
    sqlstm.sqhstl[6] = (unsigned long  )4;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&RgIn.Inst6;
    sqlstm.sqhstl[7] = (unsigned long  )4;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqhstv[8] = (unsigned char  *)&RgIn.Inst7;
    sqlstm.sqhstl[8] = (unsigned long  )4;
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqhstv[9] = (unsigned char  *)&RgIn.Inst8;
    sqlstm.sqhstl[9] = (unsigned long  )4;
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqhstv[10] = (unsigned char  *)&RgIn.Inst9;
    sqlstm.sqhstl[10] = (unsigned long  )4;
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqhstv[11] = (unsigned char  *)&RgIn.Inst10;
    sqlstm.sqhstl[11] = (unsigned long  )4;
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqhstv[12] = (unsigned char  *)&RgIn.Inst11;
    sqlstm.sqhstl[12] = (unsigned long  )4;
    sqlstm.sqindv[12] = (         short *)0;
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqhstv[13] = (unsigned char  *)&RgIn.Inst12;
    sqlstm.sqhstl[13] = (unsigned long  )4;
    sqlstm.sqindv[13] = (         short *)0;
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqhstv[14] = (unsigned char  *)&RgIn.Inst13;
    sqlstm.sqhstl[14] = (unsigned long  )4;
    sqlstm.sqindv[14] = (         short *)0;
    sqlstm.sqharm[14] = (unsigned long )0;
    sqlstm.sqhstv[15] = (unsigned char  *)&RgIn.Inst14;
    sqlstm.sqhstl[15] = (unsigned long  )4;
    sqlstm.sqindv[15] = (         short *)0;
    sqlstm.sqharm[15] = (unsigned long )0;
    sqlstm.sqhstv[16] = (unsigned char  *)&RgIn.Inst15;
    sqlstm.sqhstl[16] = (unsigned long  )4;
    sqlstm.sqindv[16] = (         short *)0;
    sqlstm.sqharm[16] = (unsigned long )0;
    sqlstm.sqhstv[17] = (unsigned char  *)&RgIn.Inst16;
    sqlstm.sqhstl[17] = (unsigned long  )4;
    sqlstm.sqindv[17] = (         short *)0;
    sqlstm.sqharm[17] = (unsigned long )0;
    sqlstm.sqhstv[18] = (unsigned char  *)RgIn.Fc_Refr;
    sqlstm.sqhstl[18] = (unsigned long  )20;
    sqlstm.sqindv[18] = (         short *)0;
    sqlstm.sqharm[18] = (unsigned long )0;
    sqlstm.sqhstv[19] = (unsigned char  *)&RgIn.Valor;
    sqlstm.sqhstl[19] = (unsigned long  )8;
    sqlstm.sqindv[19] = (         short *)0;
    sqlstm.sqharm[19] = (unsigned long )0;
    sqlstm.sqhstv[20] = (unsigned char  *)&RgIn.Fuente;
    sqlstm.sqhstl[20] = (unsigned long  )4;
    sqlstm.sqindv[20] = (         short *)0;
    sqlstm.sqharm[20] = (unsigned long )0;
    sqlstm.sqhstv[21] = (unsigned char  *)RgIn.Fc_Gen;
    sqlstm.sqhstl[21] = (unsigned long  )20;
    sqlstm.sqindv[21] = (         short *)0;
    sqlstm.sqharm[21] = (unsigned long )0;
    sqlstm.sqhstv[22] = (unsigned char  *)RgIn.Grnl;
    sqlstm.sqhstl[22] = (unsigned long  )2;
    sqlstm.sqindv[22] = (         short *)0;
    sqlstm.sqharm[22] = (unsigned long )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode == 1403) break;
    if (sqlca.sqlcode < 0) sql_error("Cons. Temporal");
}


		  /* EXEC SQL whenever NOT FOUND continue; */ 

		  /* EXEC SQL whenever SQLERROR do sql_error("Cons. Temporal"); */ 

		  Graba_Reg_SH(&RgIn);
		  if (i > 1000) {
		     i = 1;
		     /* EXEC SQL commit; */ 

{
       struct sqlexd sqlstm;

       sqlorat((void **)0, &sqlctx, &oraca);
       sqlstm.sqlvsn = 8;
       sqlstm.arrsiz = 23;
       sqlstm.iters = (unsigned long  )1;
       sqlstm.offset = (unsigned short)324;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)0;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) sql_error("Cons. Temporal");
}


		     putchar('.');
		  }
	       }
	       /* EXEC SQL whenever SQLERROR do sql_error("Cons. Temporal"); */ 

	       /* EXEC SQL CLOSE CurTabla; */ 

{
        struct sqlexd sqlstm;

        sqlorat((void **)0, &sqlctx, &oraca);
        sqlstm.sqlvsn = 8;
        sqlstm.arrsiz = 23;
        sqlstm.iters = (unsigned long  )1;
        sqlstm.offset = (unsigned short)338;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sql_error("Cons. Temporal");
}


	       /* EXEC SQL drop table g3_temp_cons_temp; */ 

{
        struct sqlexd sqlstm;

        sqlorat((void **)0, &sqlctx, &oraca);
        sqlstm.sqlvsn = 8;
        sqlstm.arrsiz = 23;
        sqlstm.stmt = "drop table g3_temp_cons_temp";
        sqlstm.iters = (unsigned long  )1;
        sqlstm.offset = (unsigned short)352;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sql_error("Cons. Temporal");
}


#endif
	    }
	    /* EXEC SQL close Tabelas; */ 

{
     struct sqlexd sqlstm;

     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 8;
     sqlstm.arrsiz = 23;
     sqlstm.iters = (unsigned long  )1;
     sqlstm.offset = (unsigned short)366;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode < 0) sql_error("Cons. Temporal");
}



	    /*	Obtiene el siguiente periodo	*/
	    strncpy(SigHasta, AjHasta, 20);
	    /* EXEC SQL EXECUTE
	    begin
               :OperOK := G3_SUP_CONS_TEMP.FinIntervalo(:LastGranul, :SigDesde, :SigHasta);
	    end;
	    END-EXEC; */ 

{
     struct sqlexd sqlstm;

     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 8;
     sqlstm.arrsiz = 23;
     sqlstm.stmt = "begin :OperOK := G3_SUP_CONS_TEMP . FinIntervalo ( :Last\
Granul , :SigDesde , :SigHasta ) ; end ;";
     sqlstm.iters = (unsigned long  )1;
     sqlstm.offset = (unsigned short)380;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)0;
     sqlstm.sqhstv[0] = (unsigned char  *)&OperOK;
     sqlstm.sqhstl[0] = (unsigned long  )4;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqhstv[1] = (unsigned char  *)&LastGranul;
     sqlstm.sqhstl[1] = (unsigned long  )4;
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqhstv[2] = (unsigned char  *)SigDesde;
     sqlstm.sqhstl[2] = (unsigned long  )20;
     sqlstm.sqindv[2] = (         short *)0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqhstv[3] = (unsigned char  *)SigHasta;
     sqlstm.sqhstl[3] = (unsigned long  )20;
     sqlstm.sqindv[3] = (         short *)0;
     sqlstm.sqharm[3] = (unsigned long )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode < 0) sql_error("Cons. Temporal");
}



	    if (OperOK)
	       break;
	 }

	 /* Hace el log */
	 /* EXEC SQL EXECUTE
	 begin
	    G3_Log_Err.Log_Msj('A', 'Consolidacion indicador: ' || to_char(:NroIndic) || ' a granularidad: ' || :LastGranul || '.');
	 end;
	 END-EXEC; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 23;
  sqlstm.stmt = "begin G3_Log_Err . Log_Msj ( 'A' , 'Consolidacion indicador\
: ' || to_char ( :NroIndic ) || ' a granularidad: ' || :LastGranul || '.' ) ; \
end ;";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)410;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (unsigned char  *)&NroIndic;
  sqlstm.sqhstl[0] = (unsigned long  )4;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&LastGranul;
  sqlstm.sqhstl[1] = (unsigned long  )4;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Cons. Temporal");
}


      }

      /*	Hace un commit por cada indicador	*/
      /* EXEC SQL COMMIT; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 23;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)432;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Cons. Temporal");
}


      /* EXEC SQL set transaction use rollback segment R01; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 23;
      sqlstm.stmt = "set transaction use rollback segment R01";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)446;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Cons. Temporal");
}


   }

   CerrarCursorIndicador();
   return(1);
}

/***************************************************************************************/
/* Funcion de consolidacion temporal llamada desde el programa principal.              */
/***************************************************************************************/
void cons_temporal()
{
   int 	Fuente;

   /* EXEC SQL whenever SQLERROR do sql_error("Cons. Temporal"); */ 

   /* EXEC SQL whenever NOT FOUND do sql_error("Cons. Temporal"); */ 

   /* EXEC SQL commit; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 23;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)460;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Cons. Temporal");
}


   /* EXEC SQL set transaction use rollback segment R01; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 23;
   sqlstm.stmt = "set transaction use rollback segment R01";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)474;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Cons. Temporal");
}




   /* EXEC SQL
      select NU_FUENTE_INDCA_PERFM
         into :Fuente
         from G3_FUENTE_INDCA_PERFM
         where NM_FUENTE_INDCA_PERFM like 'DATOS CALCULADOS%'; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 23;
   sqlstm.stmt = "select NU_FUENTE_INDCA_PERFM into :b0  from G3_FUENTE_INDC\
A_PERFM where NM_FUENTE_INDCA_PERFM like 'DATOS CALCULADOS%'";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)488;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)&Fuente;
   sqlstm.sqhstl[0] = (unsigned long  )4;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode == 1403) sql_error("Cons. Temporal");
   if (sqlca.sqlcode < 0) sql_error("Cons. Temporal");
}



   Consolidar("DM", Fuente);
}
