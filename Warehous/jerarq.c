
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
    ".\\jerarq.pc"
};


static const unsigned long sqlctx = 882203558;


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

 static const char *sq0007 = 
"select NU_INDCA_PERFM ,CD_METD_CONS_JRQC ,CD_GRNL_INDCA_PERFM ,FC_ULT_ATUAL_\
INDCA ,FC_LIM_INF_INDCA ,FC_LIM_SUP_INDCA  from G3_INDCA_PERFM where (((NU_VIS\
ION=:b0 and CD_TIPO_INDCA_PERFM<>'CF') and CD_METD_CONS_JRQC<>'SC') and CD_IND\
CA_ATUAL='1') order by CD_METD_CONS_JRQC            ";
 static const char *sq0015 = 
"select NU_INDCA_PERFM ,NU_VISION ,NU_INSTAN_DIMEN__1 ,NU_INSTAN_DIMEN__2 ,NU\
_INSTAN_DIMEN__3 ,NU_INSTAN_DIMEN__4 ,NU_INSTAN_DIMEN__5 ,NU_INSTAN_DIMEN__6 ,\
NU_INSTAN_DIMEN__7 ,NU_INSTAN_DIMEN__8 ,NU_INSTAN_DIMEN__9 ,NU_INSTAN_DIMEN__1\
0 ,NU_INSTAN_DIMEN__11 ,NU_INSTAN_DIMEN__12 ,NU_INSTAN_DIMEN__13 ,NU_INSTAN_DI\
MEN__14 ,NU_INSTAN_DIMEN__15 ,NU_INSTAN_DIMEN__16 ,FC_REFR_SERIE_HIST ,CT_VALO\
R_SERIE_HIST ,NU_FUENTE_INDCA_PERFM ,FC_GEN_FUENTE_INDCA_PERFM ,CD_GRNL_SERIE_\
HIST  from G3_TEMP_CONS_JRQC            ";
 static const char *sq0021 = 
"select NU_DIMEN  from G3_DIMEN where CD_CONS_JRQC='1'           ";
 static const char *sq0024 = 
"select NU_VISION ,NU_DIMEN__1 ,NU_DIMEN__2 ,NU_DIMEN__3 ,NU_DIMEN__4 ,NU_DIM\
EN__5 ,NU_DIMEN__6 ,NU_DIMEN__7 ,NU_DIMEN__8 ,NU_DIMEN__9 ,NU_DIMEN__10 ,NU_DI\
MEN__11 ,NU_DIMEN__12 ,NU_DIMEN__13 ,NU_DIMEN__14 ,NU_DIMEN__15 ,NU_DIMEN__16 \
 from G3_VISION where (((((((((((((((NU_DIMEN__1=:b0 or NU_DIMEN__2=:b0) or NU\
_DIMEN__3=:b0) or NU_DIMEN__4=:b0) or NU_DIMEN__5=:b0) or NU_DIMEN__6=:b0) or \
NU_DIMEN__7=:b0) or NU_DIMEN__8=:b0) or NU_DIMEN__9=:b0) or NU_DIMEN__10=:b0) \
or NU_DIMEN__11=:b0) or NU_DIMEN__12=:b0) or NU_DIMEN__13=:b0) or NU_DIMEN__14\
=:b0) or NU_DIMEN__15=:b0) or NU_DIMEN__16=:b0)           ";
 static const char *sq0025 = 
"select NU_NIVL_LOGC_DIMEN  from G3_NIVL_LOGC_DIMEN where ((NU_NIVL_LOGC_DIME\
N<:b0 and NU_NIVL_LOGC_DIMEN>=:b1) and NU_DIMEN=:b2) order by NU_NIVL_LOGC_DIM\
EN desc             ";
typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{8,4130,
2,0,0,1,0,0,24,118,0,1,1,0,1,0,1,97,0,0,
20,0,0,2,0,0,29,122,0,0,0,0,1,0,
34,0,0,3,40,0,1,123,0,0,0,0,1,0,
48,0,0,4,153,0,4,148,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
70,0,0,5,110,0,6,158,0,1,1,0,1,0,1,3,0,0,
88,0,0,6,102,0,6,170,0,2,2,0,1,0,1,3,0,0,1,3,0,0,
110,0,0,7,284,0,9,187,0,1,1,0,1,0,1,3,0,0,
128,0,0,7,0,0,13,190,0,6,0,0,1,0,2,3,0,0,2,9,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,
166,0,0,8,153,0,6,193,0,3,3,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,
192,0,0,9,210,0,4,203,0,6,4,0,1,0,2,97,0,0,2,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,
97,0,0,
230,0,0,10,96,0,6,216,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
252,0,0,11,82,0,6,226,0,1,1,0,1,0,1,97,0,0,
270,0,0,12,289,0,6,235,0,5,5,0,1,0,1,3,0,0,1,3,0,0,2,9,0,0,1,97,0,0,1,3,0,0,
304,0,0,13,0,0,17,259,0,1,1,0,1,0,1,97,0,0,
322,0,0,13,0,0,45,261,0,0,0,0,1,0,
336,0,0,13,0,0,13,263,0,2,0,0,1,0,2,3,0,0,2,3,0,0,
358,0,0,14,36,0,4,271,0,1,0,0,1,0,2,97,0,0,
376,0,0,13,0,0,15,272,0,0,0,0,1,0,
390,0,0,15,506,0,9,317,0,0,0,0,1,0,
404,0,0,15,0,0,13,320,0,23,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,
0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
510,0,0,15,0,0,15,324,0,0,0,0,1,0,
524,0,0,16,28,0,1,325,0,0,0,0,1,0,
538,0,0,13,0,0,15,329,0,0,0,0,1,0,
552,0,0,17,0,0,17,339,0,1,1,0,1,0,1,97,0,0,
570,0,0,17,0,0,45,341,0,0,0,0,1,0,
584,0,0,17,0,0,13,343,0,1,0,0,1,0,2,97,0,0,
602,0,0,17,0,0,15,347,0,0,0,0,1,0,
616,0,0,18,345,0,6,350,0,4,4,0,1,0,1,97,0,0,3,97,0,0,1,97,0,0,2,3,0,0,
646,0,0,7,0,0,15,370,0,0,0,0,1,0,
660,0,0,19,40,0,1,383,0,0,0,0,1,0,
674,0,0,20,28,0,1,394,0,0,0,0,1,0,
688,0,0,21,64,0,9,402,0,0,0,0,1,0,
702,0,0,21,0,0,13,406,0,1,0,0,1,0,2,3,0,0,
720,0,0,22,90,0,4,407,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
742,0,0,23,88,0,4,412,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
764,0,0,24,602,0,9,453,0,16,16,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,
842,0,0,24,0,0,13,458,0,17,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,
0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
3,0,0,2,3,0,0,
924,0,0,25,174,0,9,470,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,
950,0,0,25,0,0,13,474,0,1,0,0,1,0,2,3,0,0,
968,0,0,25,0,0,15,480,0,0,0,0,1,0,
982,0,0,26,0,0,29,481,0,0,0,0,1,0,
996,0,0,27,40,0,1,482,0,0,0,0,1,0,
1010,0,0,24,0,0,15,484,0,0,0,0,1,0,
1024,0,0,28,0,0,29,485,0,0,0,0,1,0,
1038,0,0,29,40,0,1,486,0,0,0,0,1,0,
1052,0,0,21,0,0,15,489,0,0,0,0,1,0,
};


/*****************************************************************************
 *                                                                           *
 *                   CONSOLIDACION DEL DATA WAREHOUSE                        *
 *                                                                           *
 *             Consolidacion Jerarquica del Data Warehouse                   *
 *                                                                           *
 *  Desarrollado por Roberto Bruno Martins - Price Waterhouse                *
 *  en 09/1996.                                                              *
 *                                                                           *
 *****************************************************************************/

#ifndef ORA_PROC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

#include <sqlca.h>
#include <oraca.h>
#include "dw_aux.h"

/*************************************************************************************

   Acha_Dimensao: Determina la posicion de Dimen dentro de la Vision

 *************************************************************************************/

static int acha_dimensao(int Dimen, T_VISAO Visao)
{
   register int i;
   for (i = 0; Visao[i] != Dimen; i++);
   return(i);
}

/************************************************************************************

   Gen_Tab_Temp_Cons: Genera la consolidacion de un nivel para un indicador y una fecha

 *************************************************************************************/

static void Gen_Tab_Temp_Cons(int Indca, T_DATE Fc_Calc, int Visao, int Nivl_Logc,
                              int Dimen, int PosVisao, char *TabDe, char *MetdCons,
                              int *DimVis, int Fuente, T_DATE Fc_Gen, char Grnl)
{
   register int i;
   static char aux_sql[8192], temp[512];

   /* EXEC SQL whenever SQLERROR do sql_error("Consolidacion Jerarquica"); */ 

   strcpy(aux_sql, "create table G3_TEMP_CONS_JRQC(NU_INDCA_PERFM,NU_VISION,\n"
        "CT_VALOR_SERIE_HIST,NU_INSTAN_DIMEN__1,NU_INSTAN_DIMEN__2,NU_INSTAN_DIMEN__3,\n"
        "NU_INSTAN_DIMEN__4, NU_INSTAN_DIMEN__5, NU_INSTAN_DIMEN__6, NU_INSTAN_DIMEN__7,"
        "NU_INSTAN_DIMEN__8, NU_INSTAN_DIMEN__9, NU_INSTAN_DIMEN__10,\n"
        "NU_INSTAN_DIMEN__11, NU_INSTAN_DIMEN__12, NU_INSTAN_DIMEN__13,\n"
        "NU_INSTAN_DIMEN__14, NU_INSTAN_DIMEN__15, NU_INSTAN_DIMEN__16,\n"
        "FC_REFR_SERIE_HIST, CD_GRNL_SERIE_HIST,\n"
        "NU_FUENTE_INDCA_PERFM, FC_GEN_FUENTE_INDCA_PERFM) \n"
        "STORAGE(INITIAL 4M NEXT 4M PCTINCREASE 0 MINEXTENTS 5 MAXEXTENTS UNLIMITED) \n"
        "TABLESPACE DW_TEMP UNRECOVERABLE PARALLEL (DEGREE 4) \n");
   /* hint anterior + ORDERED INDEX(II PK_INDIND) */
   sprintf(temp, "as SELECT /*+ ORDERED INDEX(II PK_INDIND) */ "
              "%d, %d, %s(S.CT_VALOR_SERIE_HIST)", Indca, Visao, MetdCons);
   strcat(aux_sql, temp);

   /* Generando las columnas NU_INSTAN_DIMEN__xx del INSERT...SELECT */
   for (i = 0; i < PosVisao; i++) {
      sprintf(temp, ",S.NU_INSTAN_DIMEN__%d",i+1);
      strcat(aux_sql, temp);
   }
   strcat(aux_sql, ",I.NU_INSTAN_DIMEN");
   for (i = PosVisao + 1; i < 16; i++) {
      if (DimVis[i]) {
         sprintf(temp, ",S.NU_INSTAN_DIMEN__%d",i+1);
         strcat(aux_sql, temp);
      }
      else
         strcat(aux_sql, ",0");
   }

   /* Fecha de referencia, granularidad, fuente de datos, fecha de generacion */
   sprintf(temp, ", to_date('%s'), '%c', %d, to_date('%s')\n", Fc_Calc, Grnl, Fuente, Fc_Gen);
   strcat(aux_sql, temp);

   /* Generando el FROM */
   sprintf(temp, " from G3_INSTAN_DIMEN I, G3_INSTAN_DIMEN_INSTAN_DIMEN II, %s S"
          " where S.NU_INDCA_PERFM = ", TabDe);
   strcat(aux_sql, temp);

   /* Generando filtros para la consolidacion (WHERE) */
   sprintf(temp, "%d and S.FC_REFR_SERIE_HIST = '%s' and ", Indca, Fc_Calc);
   strcat(aux_sql, temp);
   sprintf(temp, "S.NU_VISION = %d and S.CD_GRNL_SERIE_HIST = '%c' and ",
         Visao, Grnl);
   strcat(aux_sql, temp);
   sprintf(temp, "S.NU_INSTAN_DIMEN__%d = II.NU_INSTAN_DIMEN_HIJO and ",
         PosVisao + 1);
   strcat(aux_sql, temp);
   sprintf(temp, "II.NU_DIMEN_PADRE = %d and ", Dimen);
   strcat(aux_sql, temp);
   strcat(aux_sql, "II.NU_INSTAN_DIMEN_PADRE = I.NU_INSTAN_DIMEN and ");
   sprintf(temp, "I.NU_DIMEN = %d and I.NU_NIVL_LOGC_DIMEN = %d",
         Dimen, Nivl_Logc);
   strcat(aux_sql, temp);
   strcat(aux_sql, " GROUP BY ");
   for (i = 0; i < 16; i++) {
      if (i != PosVisao) {
         if (DimVis[i]) {
            sprintf(temp, "S.NU_INSTAN_DIMEN__%d,",i+1);
            strcat(aux_sql, temp);
         }
      }
      else
         strcat(aux_sql, "I.NU_INSTAN_DIMEN,");
   }
   aux_sql[strlen(aux_sql)-1] = 0;
#ifdef __DEBUG
   printf("Creando tabla temporal...");
#endif
   /* EXEC SQL EXECUTE IMMEDIATE :aux_sql; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 1;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)2;
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
   if (sqlca.sqlcode < 0) sql_error("Consolidacion Jerarquica");
}


#ifdef __DEBUG
   printf("Creada\n");
#endif
   /* EXEC SQL commit; */ 

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
   if (sqlca.sqlcode < 0) sql_error("Consolidacion Jerarquica");
}


   /* EXEC SQL set transaction use rollback segment R01; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 1;
   sqlstm.stmt = "set transaction use rollback segment R01";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)34;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Consolidacion Jerarquica");
}


} /* Gen_Tab_Temp_Cons */

/**************************************************************************************

  consolida_instancias: Consolida las instancias en la vision y nivel especificados

 **************************************************************************************/

static void consolida_instancias(int Dimen, int NivDim,
                                 int Visao, int PosVisao, int *DimVis)
{
   T_DATE Fc_Min, Fc_Max, Fc_Calc, Fc_Gen, Fc_Ult_Atual;
   T_REG_SH Reg_SH;
   short Passou, IndMin, IndMax, IndFuen, Primeiro = 1, IndCalc;
   char aux_sql[8000], Grnl[2];
   int Indca, Fuente, NIndca, Cont_No_Data = 0;
   static int HayDat;
   /* VARCHAR TabDe[40], MetdCons[10]; */ 
struct { unsigned short len; unsigned char arr[40]; } TabDe;

struct { unsigned short len; unsigned char arr[10]; } MetdCons;

   long Conta_Regs = 0;
 
   /* EXEC SQL whenever SQLERROR do sql_error("Consolidacion jerarquica"); */ 

   /* EXEC SQL whenever NOT FOUND do sql_error("Consolidacion jerarquica"); */ 


   /* Evaluando cuantos indicadores consolidables hay para esta vision */
   /* EXEC SQL
      select count(*)
         into :NIndca
         from G3_INDCA_PERFM
         where NU_VISION = :Visao and
               CD_TIPO_INDCA_PERFM != 'CF' and
               CD_METD_CONS_JRQC != 'SC' and
               CD_INDCA_ATUAL = '1'; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 2;
   sqlstm.stmt = "select count(*)  into :b0  from G3_INDCA_PERFM where (((NU\
_VISION=:b1 and CD_TIPO_INDCA_PERFM<>'CF') and CD_METD_CONS_JRQC<>'SC') and CD\
_INDCA_ATUAL='1')";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)48;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)&NIndca;
   sqlstm.sqhstl[0] = (unsigned long  )4;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&Visao;
   sqlstm.sqhstl[1] = (unsigned long  )4;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode == 1403) sql_error("Consolidacion jerarquica");
   if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


   if (!NIndca) {
      printf("La vision %d no tiene indicadores para consolidar\n", Visao);
      /* EXEC SQL execute
	 begin
	    G3_Log_Err.Log_Msj('D', 'La vision ' || :Visao || ' no tiene indicadores para consolidar');
	 end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 2;
      sqlstm.stmt = "begin G3_Log_Err . Log_Msj ( 'D' , 'La vision ' || :Vis\
ao || ' no tiene indicadores para consolidar' ) ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)70;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Visao;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Consolidacion jerarquica");
      if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


      return;
   }
#ifdef __DEBUG
   printf("Tem %d indicadores\n",NIndca);
#endif

   printf("Consolidando Nivel %d, Vision %d\n", NivDim, Visao);
   /* EXEC SQL execute
      begin
         G3_Log_Err.Log_Msj('D', 'Consolidando nivel ' || :NivDim || ', Vision ' || :Visao);
      end;
   END-EXEC; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 2;
   sqlstm.stmt = "begin G3_Log_Err . Log_Msj ( 'D' , 'Consolidando nivel ' |\
| :NivDim || ', Vision ' || :Visao ) ; end ;";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)88;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)&NivDim;
   sqlstm.sqhstl[0] = (unsigned long  )4;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&Visao;
   sqlstm.sqhstl[1] = (unsigned long  )4;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode == 1403) sql_error("Consolidacion jerarquica");
   if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


   /* Para cada indicador consolidable de la vision */
   /* EXEC SQL declare r_indca CURSOR FOR
      select NU_INDCA_PERFM, CD_METD_CONS_JRQC,
             CD_GRNL_INDCA_PERFM, FC_ULT_ATUAL_INDCA,
             FC_LIM_INF_INDCA, FC_LIM_SUP_INDCA
         from G3_INDCA_PERFM
         where NU_VISION = :Visao and
               CD_TIPO_INDCA_PERFM != 'CF' and
               CD_METD_CONS_JRQC != 'SC' and
               CD_INDCA_ATUAL = '1'
               order by CD_METD_CONS_JRQC; */ 


   /* EXEC SQL open r_indca; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 2;
   sqlstm.stmt = sq0007;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)110;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)&Visao;
   sqlstm.sqhstl[0] = (unsigned long  )4;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


   /* EXEC SQL whenever NOT FOUND do break; */ 

   for (;;) {  /* loop r_indca */
      /* EXEC SQL fetch r_indca into :Indca, :MetdCons, :Grnl, :Fc_Ult_Atual, :Fc_Min:IndMin, :Fc_Max:IndMax; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 6;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)128;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Indca;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&MetdCons;
      sqlstm.sqhstl[1] = (unsigned long  )12;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqhstv[2] = (unsigned char  *)Grnl;
      sqlstm.sqhstl[2] = (unsigned long  )2;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqhstv[3] = (unsigned char  *)Fc_Ult_Atual;
      sqlstm.sqhstl[3] = (unsigned long  )20;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqhstv[4] = (unsigned char  *)Fc_Min;
      sqlstm.sqhstl[4] = (unsigned long  )20;
      sqlstm.sqindv[4] = (         short *)&IndMin;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqhstv[5] = (unsigned char  *)Fc_Max;
      sqlstm.sqhstl[5] = (unsigned long  )20;
      sqlstm.sqindv[5] = (         short *)&IndMax;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) break;
      if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


      /* EXEC SQL whenever NOT FOUND do sql_error("Cons. Jerarquica"); */ 

      printf("\nConsolidando indicador %d, Gran. %c, actualizado en <%s> ", Indca, Grnl[0], Fc_Ult_Atual);
      /* EXEC SQL execute
         begin
            G3_Log_Err.Log_Msj('D', 'Consolidando indicador ' || :Indca || ',  gran. ' || :Grnl ||
                               ', actualizado en <' || :Fc_Ult_Atual || '>.');
         end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 6;
      sqlstm.stmt = "begin G3_Log_Err . Log_Msj ( 'D' , 'Consolidando indica\
dor ' || :Indca || ',  gran. ' || :Grnl || ', actualizado en <' || :Fc_Ult_Atu\
al || '>.' ) ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)166;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Indca;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)Grnl;
      sqlstm.sqhstl[1] = (unsigned long  )2;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqhstv[2] = (unsigned char  *)Fc_Ult_Atual;
      sqlstm.sqhstl[2] = (unsigned long  )20;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Cons. Jerarquica");
      if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}




      /* Determinando el rango de fechas a consolidar */
      if (IndMin == -1 || IndMax == -1) {
         /* EXEC SQL
            select min(FC_REFR_SERIE_HIST),
                   max(FC_REFR_SERIE_HIST)
               into :Fc_Min:IndMin, :Fc_Max:IndMax
               from V_SERIE_HIST_INPUT
               where NU_INDCA_PERFM = :Indca and
                     NU_VISION = :Visao and
                     CD_GRNL_SERIE_HIST = :Grnl and
                     FC_GEN_FUENTE_INDCA_PERFM >= :Fc_Ult_Atual; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 6;
         sqlstm.stmt = "select min(FC_REFR_SERIE_HIST) ,max(FC_REFR_SERIE_HI\
ST) into :b0:b1,:b2:b3  from V_SERIE_HIST_INPUT where (((NU_INDCA_PERFM=:b4 an\
d NU_VISION=:b5) and CD_GRNL_SERIE_HIST=:b6) and FC_GEN_FUENTE_INDCA_PERFM>=:b\
7)";
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)192;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlstm.sqhstv[0] = (unsigned char  *)Fc_Min;
         sqlstm.sqhstl[0] = (unsigned long  )20;
         sqlstm.sqindv[0] = (         short *)&IndMin;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqhstv[1] = (unsigned char  *)Fc_Max;
         sqlstm.sqhstl[1] = (unsigned long  )20;
         sqlstm.sqindv[1] = (         short *)&IndMax;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&Indca;
         sqlstm.sqhstl[2] = (unsigned long  )4;
         sqlstm.sqindv[2] = (         short *)0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&Visao;
         sqlstm.sqhstl[3] = (unsigned long  )4;
         sqlstm.sqindv[3] = (         short *)0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqhstv[4] = (unsigned char  *)Grnl;
         sqlstm.sqhstl[4] = (unsigned long  )2;
         sqlstm.sqindv[4] = (         short *)0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqhstv[5] = (unsigned char  *)Fc_Ult_Atual;
         sqlstm.sqhstl[5] = (unsigned long  )20;
         sqlstm.sqindv[5] = (         short *)0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode == 1403) sql_error("Cons. Jerarquica");
         if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


      }
      if (IndMin == -1 || IndMax == -1)
         continue;
      printf("de <%s> hasta <%s>\n", Fc_Min, Fc_Max);
      /* EXEC SQL execute
         begin
            G3_Log_Err.Log_Msj('D', 'de <' || :Fc_Min || '> hasta <' || :Fc_Max || '>.');
         end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 6;
      sqlstm.stmt = "begin G3_Log_Err . Log_Msj ( 'D' , 'de <' || :Fc_Min ||\
 '> hasta <' || :Fc_Max || '>.' ) ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)230;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)Fc_Min;
      sqlstm.sqhstl[0] = (unsigned long  )20;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)Fc_Max;
      sqlstm.sqhstl[1] = (unsigned long  )20;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Cons. Jerarquica");
      if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


      strncpy(Fc_Calc, Fc_Min, 19);
      Fc_Calc[19] = 0;
      Passou = 0;
      do {
         printf("Para la fecha %s\n", Fc_Calc);
         /* EXEC SQL execute
            begin
               G3_Log_Err.Log_Msj('D', 'Para la fecha <' || :Fc_Calc || '>.');
            end;
         END-EXEC; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 6;
         sqlstm.stmt = "begin G3_Log_Err . Log_Msj ( 'D' , 'Para la fecha <'\
 || :Fc_Calc || '>.' ) ; end ;";
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)252;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlstm.sqhstv[0] = (unsigned char  *)Fc_Calc;
         sqlstm.sqhstl[0] = (unsigned long  )20;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode == 1403) sql_error("Cons. Jerarquica");
         if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


         /* Determinando la tabla de origen */
#ifdef __DEBUG
         printf("Dimen: %d, Nivel: %d\n", Dimen, NivDim);
#endif
         /* EXEC SQL EXECUTE
            declare
               Nivel SUP_DW.T_NIVL_DIMEN;
            begin
               Nivel(1).Nu_Dimen:= :Dimen;
               select min(NU_NIVL_LOGC_DIMEN)
                  into Nivel(1).Nu_Nivl
                  from G3_NIVL_LOGC_DIMEN
                  where NU_DIMEN = :Dimen and
                        NU_NIVL_LOGC_DIMEN > :NivDim;
               :TabDe:= SUP_DW.Nm_Tab_SH(:Fc_Calc, :Visao, Nivel);
            end;
         END-EXEC; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 6;
         sqlstm.stmt = "declare Nivel SUP_DW . T_NIVL_DIMEN ; begin Nivel ( \
1 ) . Nu_Dimen := :Dimen ; select min ( NU_NIVL_LOGC_DIMEN ) into Nivel ( 1 ) \
. Nu_Nivl from G3_NIVL_LOGC_DIMEN where NU_DIMEN = :Dimen and NU_NIVL_LOGC_DIM\
EN > :NivDim ; :TabDe := SUP_DW . Nm_Tab_SH ( :Fc_Calc , :Visao , Nivel ) ; en\
d ;";
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)270;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlstm.sqhstv[0] = (unsigned char  *)&Dimen;
         sqlstm.sqhstl[0] = (unsigned long  )4;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&NivDim;
         sqlstm.sqhstl[1] = (unsigned long  )4;
         sqlstm.sqindv[1] = (         short *)0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&TabDe;
         sqlstm.sqhstl[2] = (unsigned long  )42;
         sqlstm.sqindv[2] = (         short *)0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqhstv[3] = (unsigned char  *)Fc_Calc;
         sqlstm.sqhstl[3] = (unsigned long  )20;
         sqlstm.sqindv[3] = (         short *)0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&Visao;
         sqlstm.sqhstl[4] = (unsigned long  )4;
         sqlstm.sqindv[4] = (         short *)0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode == 1403) sql_error("Cons. Jerarquica");
         if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


         TabDe.arr[TabDe.len] = 0;

         /* Determinando si hay datos para la fecha de calculo */
         sprintf(aux_sql, "select 1, NU_FUENTE_INDCA_PERFM from %.*s where "
               "NU_INDCA_PERFM = %d and NU_VISION = %d and CD_GRNL_SERIE_HIST = '%c' "
               "and FC_REFR_SERIE_HIST = '%s' and ROWNUM = 1", TabDe.len, TabDe.arr,
               Indca, Visao, *Grnl, Fc_Calc);
         HayDat = 0;
#ifdef __DEBUG
         printf("%s\n", aux_sql);
#endif
         /* EXEC SQL prepare hay_stmt from :aux_sql; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 6;
         sqlstm.stmt = "";
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)304;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlstm.sqhstv[0] = (unsigned char  *)aux_sql;
         sqlstm.sqhstl[0] = (unsigned long  )8000;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


         /* EXEC SQL declare r_dat CURSOR FOR hay_stmt; */ 

         /* EXEC SQL open r_dat; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 6;
         sqlstm.stmt = "";
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)322;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


         /* EXEC SQL whenever NOT FOUND continue; */ 

         /* EXEC SQL fetch r_dat into :HayDat, :Fuente:IndFuen; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 6;
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)336;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlstm.sqhstv[0] = (unsigned char  *)&HayDat;
         sqlstm.sqhstl[0] = (unsigned long  )4;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&Fuente;
         sqlstm.sqhstl[1] = (unsigned long  )4;
         sqlstm.sqindv[1] = (         short *)&IndFuen;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}



         /* Hay datos para esta fecha ? */
         if (sqlca.sqlcode == 0 && HayDat) {
            Cont_No_Data = 0;
#ifdef __DEBUG
            printf("Hay datos para %s\n", Fc_Calc);
#endif
            /* EXEC SQL SELECT sysdate into :Fc_Gen from DUAL; */ 

{
            struct sqlexd sqlstm;

            sqlorat((void **)0, &sqlctx, &oraca);
            sqlstm.sqlvsn = 8;
            sqlstm.arrsiz = 6;
            sqlstm.stmt = "select sysdate  into :b0  from DUAL ";
            sqlstm.iters = (unsigned long  )1;
            sqlstm.offset = (unsigned short)358;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)0;
            sqlstm.sqhstv[0] = (unsigned char  *)Fc_Gen;
            sqlstm.sqhstl[0] = (unsigned long  )20;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


            /* EXEC SQL close r_dat; */ 

{
            struct sqlexd sqlstm;

            sqlorat((void **)0, &sqlctx, &oraca);
            sqlstm.sqlvsn = 8;
            sqlstm.arrsiz = 6;
            sqlstm.iters = (unsigned long  )1;
            sqlstm.offset = (unsigned short)376;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}



            TabDe.arr[TabDe.len] = 0; MetdCons.arr[MetdCons.len] = 0;

            Gen_Tab_Temp_Cons(Indca, Fc_Calc, Visao, NivDim, Dimen, PosVisao, 
               (char *)TabDe.arr, (char *)MetdCons.arr, DimVis, Fuente, Fc_Gen, *Grnl);

            /* Este DECLARE TABLE es necesario porque G3_TEMP_CONS_JRQC no existe en
               el momento de la compilacion. */
            /* EXEC SQL
               DECLARE G3_TEMP_CONS_JRQC TABLE(
                    NU_INDCA_PERFM number,
                    NU_VISION number,
                    CT_VALOR_SERIE_HIST number,
                    NU_INSTAN_DIMEN__1 number,
                    NU_INSTAN_DIMEN__2 number,
                    NU_INSTAN_DIMEN__3 number,
                    NU_INSTAN_DIMEN__4 number,
                    NU_INSTAN_DIMEN__5 number,
                    NU_INSTAN_DIMEN__6 number,
                    NU_INSTAN_DIMEN__7 number,
                    NU_INSTAN_DIMEN__8 number,
                    NU_INSTAN_DIMEN__9 number,
                    NU_INSTAN_DIMEN__10 number,
                    NU_INSTAN_DIMEN__11 number,
                    NU_INSTAN_DIMEN__12 number,
                    NU_INSTAN_DIMEN__13 number,
                    NU_INSTAN_DIMEN__14 number,
                    NU_INSTAN_DIMEN__15 number,
                    NU_INSTAN_DIMEN__16 number,
                    FC_REFR_SERIE_HIST char(19),
                    CD_GRNL_SERIE_HIST char(1),
                    NU_FUENTE_INDCA_PERFM number,
                    FC_GEN_FUENTE_INDCA_PERFM char(19)); */ 


            /* EXEC SQL declare r_Consol CURSOR FOR
               select NU_INDCA_PERFM, NU_VISION, NU_INSTAN_DIMEN__1,
                      NU_INSTAN_DIMEN__2, NU_INSTAN_DIMEN__3, NU_INSTAN_DIMEN__4,
                      NU_INSTAN_DIMEN__5, NU_INSTAN_DIMEN__6, NU_INSTAN_DIMEN__7,
                      NU_INSTAN_DIMEN__8, NU_INSTAN_DIMEN__9, NU_INSTAN_DIMEN__10,
                      NU_INSTAN_DIMEN__11, NU_INSTAN_DIMEN__12, NU_INSTAN_DIMEN__13,
                      NU_INSTAN_DIMEN__14, NU_INSTAN_DIMEN__15, NU_INSTAN_DIMEN__16,
                      FC_REFR_SERIE_HIST, CT_VALOR_SERIE_HIST, NU_FUENTE_INDCA_PERFM,
                      FC_GEN_FUENTE_INDCA_PERFM, CD_GRNL_SERIE_HIST
                  from G3_TEMP_CONS_JRQC; */ 

            /* EXEC SQL open r_Consol; */ 

{
            struct sqlexd sqlstm;

            sqlorat((void **)0, &sqlctx, &oraca);
            sqlstm.sqlvsn = 8;
            sqlstm.arrsiz = 6;
            sqlstm.stmt = sq0015;
            sqlstm.iters = (unsigned long  )1;
            sqlstm.offset = (unsigned short)390;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


            /* EXEC SQL whenever NOT FOUND do break; */ 

            for (;;) {
               /* EXEC SQL fetch r_Consol into :Reg_SH; */ 

{
               struct sqlexd sqlstm;

               sqlorat((void **)0, &sqlctx, &oraca);
               sqlstm.sqlvsn = 8;
               sqlstm.arrsiz = 23;
               sqlstm.iters = (unsigned long  )1;
               sqlstm.offset = (unsigned short)404;
               sqlstm.cud = sqlcud0;
               sqlstm.sqlest = (unsigned char  *)&sqlca;
               sqlstm.sqlety = (unsigned short)0;
               sqlstm.sqhstv[0] = (unsigned char  *)&Reg_SH.Indic;
               sqlstm.sqhstl[0] = (unsigned long  )4;
               sqlstm.sqindv[0] = (         short *)0;
               sqlstm.sqharm[0] = (unsigned long )0;
               sqlstm.sqhstv[1] = (unsigned char  *)&Reg_SH.Vision;
               sqlstm.sqhstl[1] = (unsigned long  )4;
               sqlstm.sqindv[1] = (         short *)0;
               sqlstm.sqharm[1] = (unsigned long )0;
               sqlstm.sqhstv[2] = (unsigned char  *)&Reg_SH.Inst1;
               sqlstm.sqhstl[2] = (unsigned long  )4;
               sqlstm.sqindv[2] = (         short *)0;
               sqlstm.sqharm[2] = (unsigned long )0;
               sqlstm.sqhstv[3] = (unsigned char  *)&Reg_SH.Inst2;
               sqlstm.sqhstl[3] = (unsigned long  )4;
               sqlstm.sqindv[3] = (         short *)0;
               sqlstm.sqharm[3] = (unsigned long )0;
               sqlstm.sqhstv[4] = (unsigned char  *)&Reg_SH.Inst3;
               sqlstm.sqhstl[4] = (unsigned long  )4;
               sqlstm.sqindv[4] = (         short *)0;
               sqlstm.sqharm[4] = (unsigned long )0;
               sqlstm.sqhstv[5] = (unsigned char  *)&Reg_SH.Inst4;
               sqlstm.sqhstl[5] = (unsigned long  )4;
               sqlstm.sqindv[5] = (         short *)0;
               sqlstm.sqharm[5] = (unsigned long )0;
               sqlstm.sqhstv[6] = (unsigned char  *)&Reg_SH.Inst5;
               sqlstm.sqhstl[6] = (unsigned long  )4;
               sqlstm.sqindv[6] = (         short *)0;
               sqlstm.sqharm[6] = (unsigned long )0;
               sqlstm.sqhstv[7] = (unsigned char  *)&Reg_SH.Inst6;
               sqlstm.sqhstl[7] = (unsigned long  )4;
               sqlstm.sqindv[7] = (         short *)0;
               sqlstm.sqharm[7] = (unsigned long )0;
               sqlstm.sqhstv[8] = (unsigned char  *)&Reg_SH.Inst7;
               sqlstm.sqhstl[8] = (unsigned long  )4;
               sqlstm.sqindv[8] = (         short *)0;
               sqlstm.sqharm[8] = (unsigned long )0;
               sqlstm.sqhstv[9] = (unsigned char  *)&Reg_SH.Inst8;
               sqlstm.sqhstl[9] = (unsigned long  )4;
               sqlstm.sqindv[9] = (         short *)0;
               sqlstm.sqharm[9] = (unsigned long )0;
               sqlstm.sqhstv[10] = (unsigned char  *)&Reg_SH.Inst9;
               sqlstm.sqhstl[10] = (unsigned long  )4;
               sqlstm.sqindv[10] = (         short *)0;
               sqlstm.sqharm[10] = (unsigned long )0;
               sqlstm.sqhstv[11] = (unsigned char  *)&Reg_SH.Inst10;
               sqlstm.sqhstl[11] = (unsigned long  )4;
               sqlstm.sqindv[11] = (         short *)0;
               sqlstm.sqharm[11] = (unsigned long )0;
               sqlstm.sqhstv[12] = (unsigned char  *)&Reg_SH.Inst11;
               sqlstm.sqhstl[12] = (unsigned long  )4;
               sqlstm.sqindv[12] = (         short *)0;
               sqlstm.sqharm[12] = (unsigned long )0;
               sqlstm.sqhstv[13] = (unsigned char  *)&Reg_SH.Inst12;
               sqlstm.sqhstl[13] = (unsigned long  )4;
               sqlstm.sqindv[13] = (         short *)0;
               sqlstm.sqharm[13] = (unsigned long )0;
               sqlstm.sqhstv[14] = (unsigned char  *)&Reg_SH.Inst13;
               sqlstm.sqhstl[14] = (unsigned long  )4;
               sqlstm.sqindv[14] = (         short *)0;
               sqlstm.sqharm[14] = (unsigned long )0;
               sqlstm.sqhstv[15] = (unsigned char  *)&Reg_SH.Inst14;
               sqlstm.sqhstl[15] = (unsigned long  )4;
               sqlstm.sqindv[15] = (         short *)0;
               sqlstm.sqharm[15] = (unsigned long )0;
               sqlstm.sqhstv[16] = (unsigned char  *)&Reg_SH.Inst15;
               sqlstm.sqhstl[16] = (unsigned long  )4;
               sqlstm.sqindv[16] = (         short *)0;
               sqlstm.sqharm[16] = (unsigned long )0;
               sqlstm.sqhstv[17] = (unsigned char  *)&Reg_SH.Inst16;
               sqlstm.sqhstl[17] = (unsigned long  )4;
               sqlstm.sqindv[17] = (         short *)0;
               sqlstm.sqharm[17] = (unsigned long )0;
               sqlstm.sqhstv[18] = (unsigned char  *)Reg_SH.Fc_Refr;
               sqlstm.sqhstl[18] = (unsigned long  )20;
               sqlstm.sqindv[18] = (         short *)0;
               sqlstm.sqharm[18] = (unsigned long )0;
               sqlstm.sqhstv[19] = (unsigned char  *)&Reg_SH.Valor;
               sqlstm.sqhstl[19] = (unsigned long  )8;
               sqlstm.sqindv[19] = (         short *)0;
               sqlstm.sqharm[19] = (unsigned long )0;
               sqlstm.sqhstv[20] = (unsigned char  *)&Reg_SH.Fuente;
               sqlstm.sqhstl[20] = (unsigned long  )4;
               sqlstm.sqindv[20] = (         short *)0;
               sqlstm.sqharm[20] = (unsigned long )0;
               sqlstm.sqhstv[21] = (unsigned char  *)Reg_SH.Fc_Gen;
               sqlstm.sqhstl[21] = (unsigned long  )20;
               sqlstm.sqindv[21] = (         short *)0;
               sqlstm.sqharm[21] = (unsigned long )0;
               sqlstm.sqhstv[22] = (unsigned char  *)Reg_SH.Grnl;
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
               if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


               Graba_Reg_SH(&Reg_SH);
	       Conta_Regs++;
            }
            /* EXEC SQL close r_Consol; */ 

{
            struct sqlexd sqlstm;

            sqlorat((void **)0, &sqlctx, &oraca);
            sqlstm.sqlvsn = 8;
            sqlstm.arrsiz = 23;
            sqlstm.iters = (unsigned long  )1;
            sqlstm.offset = (unsigned short)510;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


            /* EXEC SQL drop table G3_TEMP_CONS_JRQC; */ 

{
            struct sqlexd sqlstm;

            sqlorat((void **)0, &sqlctx, &oraca);
            sqlstm.sqlvsn = 8;
            sqlstm.arrsiz = 23;
            sqlstm.stmt = "drop table G3_TEMP_CONS_JRQC";
            sqlstm.iters = (unsigned long  )1;
            sqlstm.offset = (unsigned short)524;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


         }
         else {
            Cont_No_Data++;
            /* EXEC SQL close r_dat; */ 

{
            struct sqlexd sqlstm;

            sqlorat((void **)0, &sqlctx, &oraca);
            sqlstm.sqlvsn = 8;
            sqlstm.arrsiz = 23;
            sqlstm.iters = (unsigned long  )1;
            sqlstm.offset = (unsigned short)538;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


         }

         if (Cont_No_Data > 10) {
            Cont_No_Data = 0;
            sprintf(aux_sql, "select min(FC_REFR_SERIE_HIST) from %.*s where "
                  "NU_INDCA_PERFM = %d and NU_VISION = %d and CD_GRNL_SERIE_HIST = '%c' "
                  "and FC_REFR_SERIE_HIST > '%s'", TabDe.len, TabDe.arr,
                  Indca, Visao, *Grnl, Fc_Calc);
            HayDat = 0;
            /* EXEC SQL prepare next_stmt from :aux_sql; */ 

{
            struct sqlexd sqlstm;

            sqlorat((void **)0, &sqlctx, &oraca);
            sqlstm.sqlvsn = 8;
            sqlstm.arrsiz = 23;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned long  )1;
            sqlstm.offset = (unsigned short)552;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)0;
            sqlstm.sqhstv[0] = (unsigned char  *)aux_sql;
            sqlstm.sqhstl[0] = (unsigned long  )8000;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


            /* EXEC SQL declare r_fecha CURSOR FOR next_stmt; */ 

            /* EXEC SQL open r_fecha; */ 

{
            struct sqlexd sqlstm;

            sqlorat((void **)0, &sqlctx, &oraca);
            sqlstm.sqlvsn = 8;
            sqlstm.arrsiz = 23;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned long  )1;
            sqlstm.offset = (unsigned short)570;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


            /* EXEC SQL whenever NOT FOUND continue; */ 

            /* EXEC SQL fetch r_fecha into :Fc_Calc:IndCalc; */ 

{
            struct sqlexd sqlstm;

            sqlorat((void **)0, &sqlctx, &oraca);
            sqlstm.sqlvsn = 8;
            sqlstm.arrsiz = 23;
            sqlstm.iters = (unsigned long  )1;
            sqlstm.offset = (unsigned short)584;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)0;
            sqlstm.sqhstv[0] = (unsigned char  *)Fc_Calc;
            sqlstm.sqhstl[0] = (unsigned long  )20;
            sqlstm.sqindv[0] = (         short *)&IndCalc;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


            if ((sqlca.sqlcode == -1403) ||
                (IndCalc == -1))
               Passou = 1;
            /* EXEC SQL close r_fecha; */ 

{
            struct sqlexd sqlstm;

            sqlorat((void **)0, &sqlctx, &oraca);
            sqlstm.sqlvsn = 8;
            sqlstm.arrsiz = 23;
            sqlstm.iters = (unsigned long  )1;
            sqlstm.offset = (unsigned short)602;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


         }
         else {
            /* EXEC SQL EXECUTE
               begin
                  if :Grnl = 'D' then
                     :Fc_Calc:= to_date(:Fc_Calc) + 1;
                  elsif :Grnl = 'S' then
                     :Fc_Calc:= to_date(:Fc_Calc) + 7;
                  elsif :Grnl = 'M' then
                     :Fc_Calc:= add_months(to_date(:Fc_Calc), 1);
                  end if;
                  if to_date(:Fc_Calc) > to_date(:Fc_Max) then
                     :Passou:= 1;
                  end if;
                  commit;
                  set transaction use rollback segment R01;
               end;
            END-EXEC; */ 

{
            struct sqlexd sqlstm;

            sqlorat((void **)0, &sqlctx, &oraca);
            sqlstm.sqlvsn = 8;
            sqlstm.arrsiz = 23;
            sqlstm.stmt = "begin if :Grnl = 'D' then :Fc_Calc := to_date ( :\
Fc_Calc ) + 1 ; elsif :Grnl = 'S' then :Fc_Calc := to_date ( :Fc_Calc ) + 7 ; \
elsif :Grnl = 'M' then :Fc_Calc := add_months ( to_date ( :Fc_Calc ) , 1 ) ; e\
nd if ; if to_date ( :Fc_Calc ) > to_date ( :Fc_Max ) then :Passou := 1 ; end \
if ; commit ; set transaction use rollback segment R01 ; end ;";
            sqlstm.iters = (unsigned long  )1;
            sqlstm.offset = (unsigned short)616;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)0;
            sqlstm.sqhstv[0] = (unsigned char  *)Grnl;
            sqlstm.sqhstl[0] = (unsigned long  )2;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqhstv[1] = (unsigned char  *)Fc_Calc;
            sqlstm.sqhstl[1] = (unsigned long  )20;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqhstv[2] = (unsigned char  *)Fc_Max;
            sqlstm.sqhstl[2] = (unsigned long  )20;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&Passou;
            sqlstm.sqhstl[3] = (unsigned long  )2;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


         }
         Fc_Calc[19] = 0;
      } while (!Passou);
   }  /* loop r_indca */
   /* EXEC SQL close r_indca; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 23;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)646;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


}   /* consolida_instancias */

/*************************************************************************************

  cons_jerarq: rutina principal de la consolidacion jerarquica.

 *************************************************************************************/
void cons_jerarq()
{
   int Dimen, MaxNivl, MinNivl, NivDim, Visao, PosVisao;
   T_VISAO DimVis;

   /* EXEC SQL set transaction use rollback segment R01; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 23;
   sqlstm.stmt = "set transaction use rollback segment R01";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)660;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Consolidacion jerarquica");
}


   /* EXEC SQL whenever SQLERROR do sql_error("Cons. Jerarq"); */ 

   /* EXEC SQL whenever NOT FOUND do sql_error("Cons. Jerarq"); */ 


#ifdef __DEBUG
   printf("Entrando en CNJRQ\n");
#endif

   /* Borrando los objetos auxiliares que puedan estar creados */
   /* EXEC SQL whenever SQLERROR continue; */ 

   /* EXEC SQL whenever NOT FOUND continue; */ 

   /* EXEC SQL drop table G3_TEMP_CONS_JRQC; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 23;
   sqlstm.stmt = "drop table G3_TEMP_CONS_JRQC";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)674;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



   /* EXEC SQL whenever SQLERROR do sql_error("Cons. Jerarq"); */ 

   /* EXEC SQL whenever NOT FOUND do sql_error("Cons. Jerarq"); */ 

   /* EXEC SQL declare r_dimen CURSOR FOR
      select NU_DIMEN from G3_DIMEN
         where CD_CONS_JRQC = '1'; */ 


   /* EXEC SQL open r_dimen; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 23;
   sqlstm.stmt = sq0021;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)688;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Cons. Jerarq");
}


   /* EXEC SQL whenever NOT FOUND do break; */ 


   for (;;) {    /* Para cada dimension a consolidar */
      /* EXEC SQL fetch r_dimen into :Dimen; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 23;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)702;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) break;
      if (sqlca.sqlcode < 0) sql_error("Cons. Jerarq");
}


      /* EXEC SQL select nvl(max(NU_NIVL_LOGC_DIMEN), 0)
         into :MaxNivl
         from G3_NIVL_LOGC_DIMEN
         where NU_DIMEN = :Dimen; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 23;
      sqlstm.stmt = "select nvl(max(NU_NIVL_LOGC_DIMEN),0) into :b0  from G3\
_NIVL_LOGC_DIMEN where NU_DIMEN=:b1";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)720;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&MaxNivl;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[1] = (unsigned long  )4;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) break;
      if (sqlca.sqlcode < 0) sql_error("Cons. Jerarq");
}



      /* EXEC SQL select nvl(min(NU_NIVL_LOGC_MIN), 0)
         into :MinNivl
         from G3_BASE_CNST_DIMEN
         where NU_DIMEN = :Dimen; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 23;
      sqlstm.stmt = "select nvl(min(NU_NIVL_LOGC_MIN),0) into :b0  from G3_B\
ASE_CNST_DIMEN where NU_DIMEN=:b1";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)742;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&MinNivl;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[1] = (unsigned long  )4;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) break;
      if (sqlca.sqlcode < 0) sql_error("Cons. Jerarq");
}



#ifdef __DEBUG
      printf("Procesando dimension %d, niveles %d a %d\n", Dimen, MinNivl, MaxNivl);
#endif
      /* EXEC SQL declare r_visao CURSOR FOR
         select NU_VISION, NU_DIMEN__1, NU_DIMEN__2,
                NU_DIMEN__3, NU_DIMEN__4, NU_DIMEN__5,
                NU_DIMEN__6, NU_DIMEN__7, NU_DIMEN__8,
                NU_DIMEN__9, NU_DIMEN__10, NU_DIMEN__11,
                NU_DIMEN__12, NU_DIMEN__13, NU_DIMEN__14,
                NU_DIMEN__15, NU_DIMEN__16 
            from G3_VISION
            where (NU_DIMEN__1 = :Dimen) or
                  (NU_DIMEN__2 = :Dimen) or
                  (NU_DIMEN__3 = :Dimen) or
                  (NU_DIMEN__4 = :Dimen) or
                  (NU_DIMEN__5 = :Dimen) or
                  (NU_DIMEN__6 = :Dimen) or
                  (NU_DIMEN__7 = :Dimen) or
                  (NU_DIMEN__8 = :Dimen) or
                  (NU_DIMEN__9 = :Dimen) or
                  (NU_DIMEN__10 = :Dimen) or
                  (NU_DIMEN__11 = :Dimen) or
                  (NU_DIMEN__12 = :Dimen) or
                  (NU_DIMEN__13 = :Dimen) or
                  (NU_DIMEN__14 = :Dimen) or
                  (NU_DIMEN__15 = :Dimen) or
                  (NU_DIMEN__16 = :Dimen); */ 


      /* Cursor para recorrer los niveles logicos de cada dimension */
      /* EXEC SQL declare r_nivel CURSOR FOR
         select NU_NIVL_LOGC_DIMEN from G3_NIVL_LOGC_DIMEN
            where NU_NIVL_LOGC_DIMEN < :MaxNivl and
                  NU_NIVL_LOGC_DIMEN >= :MinNivl and
                  NU_DIMEN = :Dimen
            order by NU_NIVL_LOGC_DIMEN DESC; */ 
 

      /* EXEC SQL open r_visao; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 23;
      sqlstm.stmt = sq0024;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)764;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[1] = (unsigned long  )4;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[2] = (unsigned long  )4;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[3] = (unsigned long  )4;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[4] = (unsigned long  )4;
      sqlstm.sqindv[4] = (         short *)0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqhstv[5] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[5] = (unsigned long  )4;
      sqlstm.sqindv[5] = (         short *)0;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqhstv[6] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[6] = (unsigned long  )4;
      sqlstm.sqindv[6] = (         short *)0;
      sqlstm.sqharm[6] = (unsigned long )0;
      sqlstm.sqhstv[7] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[7] = (unsigned long  )4;
      sqlstm.sqindv[7] = (         short *)0;
      sqlstm.sqharm[7] = (unsigned long )0;
      sqlstm.sqhstv[8] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[8] = (unsigned long  )4;
      sqlstm.sqindv[8] = (         short *)0;
      sqlstm.sqharm[8] = (unsigned long )0;
      sqlstm.sqhstv[9] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[9] = (unsigned long  )4;
      sqlstm.sqindv[9] = (         short *)0;
      sqlstm.sqharm[9] = (unsigned long )0;
      sqlstm.sqhstv[10] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[10] = (unsigned long  )4;
      sqlstm.sqindv[10] = (         short *)0;
      sqlstm.sqharm[10] = (unsigned long )0;
      sqlstm.sqhstv[11] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[11] = (unsigned long  )4;
      sqlstm.sqindv[11] = (         short *)0;
      sqlstm.sqharm[11] = (unsigned long )0;
      sqlstm.sqhstv[12] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[12] = (unsigned long  )4;
      sqlstm.sqindv[12] = (         short *)0;
      sqlstm.sqharm[12] = (unsigned long )0;
      sqlstm.sqhstv[13] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[13] = (unsigned long  )4;
      sqlstm.sqindv[13] = (         short *)0;
      sqlstm.sqharm[13] = (unsigned long )0;
      sqlstm.sqhstv[14] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[14] = (unsigned long  )4;
      sqlstm.sqindv[14] = (         short *)0;
      sqlstm.sqharm[14] = (unsigned long )0;
      sqlstm.sqhstv[15] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[15] = (unsigned long  )4;
      sqlstm.sqindv[15] = (         short *)0;
      sqlstm.sqharm[15] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Cons. Jerarq");
}


      /* EXEC SQL whenever NOT FOUND do break; */ 


      /* Para cada Vision */
      for (;;) {
         /* EXEC SQL fetch r_visao into
            :Visao, :DimVis[0], :DimVis[1], :DimVis[2],
            :DimVis[3], :DimVis[4], :DimVis[5], :DimVis[6],
            :DimVis[7], :DimVis[8], :DimVis[9], :DimVis[10],
            :DimVis[11], :DimVis[12], :DimVis[13], :DimVis[14],
            :DimVis[15]; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 23;
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)842;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlstm.sqhstv[0] = (unsigned char  *)&Visao;
         sqlstm.sqhstl[0] = (unsigned long  )4;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&DimVis[0];
         sqlstm.sqhstl[1] = (unsigned long  )4;
         sqlstm.sqindv[1] = (         short *)0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&DimVis[1];
         sqlstm.sqhstl[2] = (unsigned long  )4;
         sqlstm.sqindv[2] = (         short *)0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&DimVis[2];
         sqlstm.sqhstl[3] = (unsigned long  )4;
         sqlstm.sqindv[3] = (         short *)0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&DimVis[3];
         sqlstm.sqhstl[4] = (unsigned long  )4;
         sqlstm.sqindv[4] = (         short *)0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&DimVis[4];
         sqlstm.sqhstl[5] = (unsigned long  )4;
         sqlstm.sqindv[5] = (         short *)0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&DimVis[5];
         sqlstm.sqhstl[6] = (unsigned long  )4;
         sqlstm.sqindv[6] = (         short *)0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&DimVis[6];
         sqlstm.sqhstl[7] = (unsigned long  )4;
         sqlstm.sqindv[7] = (         short *)0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&DimVis[7];
         sqlstm.sqhstl[8] = (unsigned long  )4;
         sqlstm.sqindv[8] = (         short *)0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&DimVis[8];
         sqlstm.sqhstl[9] = (unsigned long  )4;
         sqlstm.sqindv[9] = (         short *)0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&DimVis[9];
         sqlstm.sqhstl[10] = (unsigned long  )4;
         sqlstm.sqindv[10] = (         short *)0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&DimVis[10];
         sqlstm.sqhstl[11] = (unsigned long  )4;
         sqlstm.sqindv[11] = (         short *)0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqhstv[12] = (unsigned char  *)&DimVis[11];
         sqlstm.sqhstl[12] = (unsigned long  )4;
         sqlstm.sqindv[12] = (         short *)0;
         sqlstm.sqharm[12] = (unsigned long )0;
         sqlstm.sqhstv[13] = (unsigned char  *)&DimVis[12];
         sqlstm.sqhstl[13] = (unsigned long  )4;
         sqlstm.sqindv[13] = (         short *)0;
         sqlstm.sqharm[13] = (unsigned long )0;
         sqlstm.sqhstv[14] = (unsigned char  *)&DimVis[13];
         sqlstm.sqhstl[14] = (unsigned long  )4;
         sqlstm.sqindv[14] = (         short *)0;
         sqlstm.sqharm[14] = (unsigned long )0;
         sqlstm.sqhstv[15] = (unsigned char  *)&DimVis[14];
         sqlstm.sqhstl[15] = (unsigned long  )4;
         sqlstm.sqindv[15] = (         short *)0;
         sqlstm.sqharm[15] = (unsigned long )0;
         sqlstm.sqhstv[16] = (unsigned char  *)&DimVis[15];
         sqlstm.sqhstl[16] = (unsigned long  )4;
         sqlstm.sqindv[16] = (         short *)0;
         sqlstm.sqharm[16] = (unsigned long )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode == 1403) break;
         if (sqlca.sqlcode < 0) sql_error("Cons. Jerarq");
}



#ifdef __DEBUG
         printf("Vision %d\n", Visao);
#endif
         PosVisao = acha_dimensao(Dimen, DimVis);

         /* EXEC SQL open r_nivel; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 23;
         sqlstm.stmt = sq0025;
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)924;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlstm.sqhstv[0] = (unsigned char  *)&MaxNivl;
         sqlstm.sqhstl[0] = (unsigned long  )4;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&MinNivl;
         sqlstm.sqhstl[1] = (unsigned long  )4;
         sqlstm.sqindv[1] = (         short *)0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&Dimen;
         sqlstm.sqhstl[2] = (unsigned long  )4;
         sqlstm.sqindv[2] = (         short *)0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) sql_error("Cons. Jerarq");
}


         /* EXEC SQL whenever NOT FOUND do break; */ 


         for (;;) {  /* Para cada nivel de la dimension */
            /* EXEC SQL fetch r_nivel into :NivDim; */ 

{
            struct sqlexd sqlstm;

            sqlorat((void **)0, &sqlctx, &oraca);
            sqlstm.sqlvsn = 8;
            sqlstm.arrsiz = 23;
            sqlstm.iters = (unsigned long  )1;
            sqlstm.offset = (unsigned short)950;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)0;
            sqlstm.sqhstv[0] = (unsigned char  *)&NivDim;
            sqlstm.sqhstl[0] = (unsigned long  )4;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode == 1403) break;
            if (sqlca.sqlcode < 0) sql_error("Cons. Jerarq");
}


#ifdef __DEBUG
            printf("Nivel %d\n", NivDim);
#endif
            consolida_instancias(Dimen, NivDim, Visao, PosVisao, DimVis);
         } /* Loop niveles */
         /* EXEC SQL close r_nivel; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 23;
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)968;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) sql_error("Cons. Jerarq");
}


         /* EXEC SQL commit; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 23;
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)982;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) sql_error("Cons. Jerarq");
}


         /* EXEC SQL set transaction use rollback segment R01; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 23;
         sqlstm.stmt = "set transaction use rollback segment R01";
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)996;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) sql_error("Cons. Jerarq");
}


      }  
      /* EXEC SQL close r_visao; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 23;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)1010;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Cons. Jerarq");
}


      /* EXEC SQL commit; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 23;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)1024;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Cons. Jerarq");
}


      /* EXEC SQL set transaction use rollback segment R01; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 23;
      sqlstm.stmt = "set transaction use rollback segment R01";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)1038;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Cons. Jerarq");
}


   }  /* Loop dimensiones */

   /* EXEC SQL close r_dimen; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 23;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)1052;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Cons. Jerarq");
}



   /* EXEC SQL whenever NOT FOUND do sql_error("Cons. Jerarq."); */ 

}
