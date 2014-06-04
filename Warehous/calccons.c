
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
           char  filnam[14];
};
static const struct sqlcxp sqlfpn =
{
    13,
    ".\\calccons.pc"
};


static const unsigned long sqlctx = 880600661;


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
   unsigned char    *sqhstv[6];
   unsigned long    sqhstl[6];
	    short   *sqindv[6];
   unsigned long    sqharm[6];
   unsigned long     *sqharc[6];
} sqlstm = {8,6};

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

 static const char *sq0002 = 
"select distinct FC_REFR_MOVT  from G3_MOVT_SERIE_HIST S ,G3_INDCA_PERFM_INDC\
A_PERFM C where (S.NU_INDCA_PERFM=C.NU_INDCA_PERFM_ORIG and C.NU_INDCA_PERFM_D\
EST=:b0)           ";
typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{8,4130,
2,0,0,1,55,0,1,25,0,0,0,0,1,0,
16,0,0,2,173,0,9,53,0,1,1,0,1,0,1,3,0,0,
34,0,0,2,0,0,13,56,0,1,0,0,1,0,2,97,0,0,
52,0,0,3,0,0,17,109,0,1,1,0,1,0,1,97,0,0,
70,0,0,3,0,0,21,110,0,1,1,0,1,0,1,3,0,0,
88,0,0,2,0,0,15,112,0,0,0,0,1,0,
102,0,0,4,217,0,4,135,0,2,1,0,1,0,2,3,0,0,1,97,0,0,
124,0,0,5,318,0,4,149,0,6,1,0,1,0,2,3,0,0,2,3,0,0,2,9,0,0,2,1,0,0,2,3,0,0,1,97,
0,0,
162,0,0,6,70,0,5,168,0,1,1,0,1,0,1,3,0,0,
180,0,0,7,109,0,6,174,0,1,1,0,1,0,1,3,0,0,
198,0,0,8,182,0,4,187,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
220,0,0,9,1221,0,6,203,0,3,3,0,1,0,3,97,0,0,3,97,0,0,1,3,0,0,
246,0,0,10,100,0,6,249,0,3,3,0,1,0,1,3,0,0,2,3,0,0,2,97,0,0,
272,0,0,11,0,0,24,268,0,1,1,0,1,0,1,97,0,0,
290,0,0,12,51,0,6,270,0,1,1,0,1,0,1,3,0,0,
308,0,0,13,0,0,29,277,0,0,0,0,1,0,
322,0,0,14,70,0,5,286,0,0,0,0,1,0,
336,0,0,15,0,0,29,290,0,0,0,0,1,0,
};


/*****************************************************************************
 *                                                                           *
 *                   ATUALIZACION DEL DATA WAREHOUSE                         *
 *                                                                           *
 *             Entorno del calculo de indicadores compostos                  *
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

static void arma_tablas()
{
   Paso_Esencial = 0;
   /* EXEC SQL whenever SQLERROR do sql_error("Lock de tablas"); */ 

   /* EXEC SQL lock table G3_MOVT_SERIE_HIST in exclusive mode nowait; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 0;
   sqlstm.stmt = "lock table G3_MOVT_SERIE_HIST in exclusive mode nowait ";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)2;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Lock de tablas");
}


   Paso_Esencial = 1;
}

/****************************************************************************/
/* Hay datos para los componentes de este indicador ? */
/****************************************************************************/

static int determ_compos(int Nu_IndComp, char Grnl_Comp, T_DATE Fc_Ult_Atual)
{
   T_DATE Fc_Compon;
   char aux_sql[10000];
   long N_Regs;


   /* EXEC SQL whenever SQLERROR DO sql_error("Composicion de Indicador"); */ 


   arma_tablas();

   /* Buscando las fechas de los componentes */
   /* EXEC SQL DECLARE r_compon CURSOR for
      select distinct FC_REFR_MOVT
	 from G3_MOVT_SERIE_HIST S,
	      G3_INDCA_PERFM_INDCA_PERFM C
	 where S.NU_INDCA_PERFM = C.NU_INDCA_PERFM_ORIG and
	       C.NU_INDCA_PERFM_DEST = :Nu_IndComp; */ 


   N_Regs = 0;
   /* EXEC SQL open r_compon; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 1;
   sqlstm.stmt = sq0002;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)16;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)&Nu_IndComp;
   sqlstm.sqhstl[0] = (unsigned long  )4;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Composicion de Indicador");
}


   /* EXEC SQL whenever NOT FOUND do break; */ 

   for (;;) {
      /* EXEC SQL fetch r_compon into
	 :Fc_Compon; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 1;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)34;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)Fc_Compon;
      sqlstm.sqhstl[0] = (unsigned long  )20;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) break;
      if (sqlca.sqlcode < 0) sql_error("Composicion de Indicador");
}


      /* EXEC SQL whenever NOT FOUND do sql_error("Composicion de Indicador"); */ 

      /* Traendo los valores de los demas componentes para las fechas para las
	 cuales hay datos nuevos para algun componente */
      sprintf(aux_sql, "begin\n "
	 "for dtcalc in ( \n"
	 "SELECT /*+ ORDERED */ S.NU_INDCA_PERFM,S.NU_VISION,\n"
	 "S.NU_INSTAN_DIMEN__1,S.NU_INSTAN_DIMEN__2,S.NU_INSTAN_DIMEN__3,\n"
	 "S.NU_INSTAN_DIMEN__4,S.NU_INSTAN_DIMEN__5,S.NU_INSTAN_DIMEN__6,\n"
	 "S.NU_INSTAN_DIMEN__7,S.NU_INSTAN_DIMEN__8,S.NU_INSTAN_DIMEN__9,\n"
	 "S.NU_INSTAN_DIMEN__10,S.NU_INSTAN_DIMEN__11,S.NU_INSTAN_DIMEN__12,\n"
	 "S.NU_INSTAN_DIMEN__13,S.NU_INSTAN_DIMEN__14,S.NU_INSTAN_DIMEN__15,\n"
	 "S.NU_INSTAN_DIMEN__16,S.FC_REFR_SERIE_HIST,S.CT_VALOR_SERIE_HIST,\n"
	 "S.NU_FUENTE_INDCA_PERFM,S.FC_GEN_FUENTE_INDCA_PERFM,1 \n"
	 "FROM G3_INDCA_PERFM_INDCA_PERFM C,G3_INDCA_PERFM I,V_SERIE_HIST S \n"
	 "WHERE S.FC_REFR_SERIE_HIST='%s' AND \n"
	 "S.CD_GRNL_SERIE_HIST='%c' AND \n"
	 "S.NU_VISION=I.NU_VISION AND \n"
	 "S.NU_INDCA_PERFM=I.NU_INDCA_PERFM AND \n"
	 "I.NU_INDCA_PERFM=C.NU_INDCA_PERFM_ORIG AND \n"
	 "C.NU_INDCA_PERFM_DEST=%d", Fc_Compon, Grnl_Comp, Nu_IndComp);
      strcat(aux_sql, 
	 ") loop \n"
	 "begin \n"
	 "INSERT INTO G3_MOVT_SERIE_HIST(NU_INDCA_PERFM,NU_VISION,\n"
	 "NU_INSTAN_DIMEN__1,NU_INSTAN_DIMEN__2,NU_INSTAN_DIMEN__3,\n"
	 "NU_INSTAN_DIMEN__4,NU_INSTAN_DIMEN__5,NU_INSTAN_DIMEN__6,\n"
	 "NU_INSTAN_DIMEN__7,NU_INSTAN_DIMEN__8,NU_INSTAN_DIMEN__9,\n"
	 "NU_INSTAN_DIMEN__10,NU_INSTAN_DIMEN__11,NU_INSTAN_DIMEN__12,\n"
	 "NU_INSTAN_DIMEN__13,NU_INSTAN_DIMEN__14,NU_INSTAN_DIMEN__15,\n"
	 "NU_INSTAN_DIMEN__16,FC_REFR_MOVT,CT_INDCA_PERFM_MOVT,\n"
	 "NU_FUENTE_DATO_MOVT,FC_GEN_MOVT) values(\n"
	 "dtcalc.NU_INDCA_PERFM,dtcalc.NU_VISION,dtcalc.NU_INSTAN_DIMEN__1,\n"
	 "dtcalc.NU_INSTAN_DIMEN__2,dtcalc.NU_INSTAN_DIMEN__3,\n"
	 "dtcalc.NU_INSTAN_DIMEN__4,dtcalc.NU_INSTAN_DIMEN__5,\n"
	 "dtcalc.NU_INSTAN_DIMEN__6,dtcalc.NU_INSTAN_DIMEN__7,\n"
	 "dtcalc.NU_INSTAN_DIMEN__8,dtcalc.NU_INSTAN_DIMEN__9,\n"
	 "dtcalc.NU_INSTAN_DIMEN__10,dtcalc.NU_INSTAN_DIMEN__11,\n"
	 "dtcalc.NU_INSTAN_DIMEN__12,dtcalc.NU_INSTAN_DIMEN__13,\n"
	 "dtcalc.NU_INSTAN_DIMEN__14,dtcalc.NU_INSTAN_DIMEN__15,\n"
	 "dtcalc.NU_INSTAN_DIMEN__16,dtcalc.FC_REFR_SERIE_HIST,\n"
	 "dtcalc.CT_VALOR_SERIE_HIST,dtcalc.NU_FUENTE_INDCA_PERFM,\n"
	 "dtcalc.FC_GEN_FUENTE_INDCA_PERFM); \n"
	 ":N_Regs:= :N_Regs + 1; \n"
	 "exception \n"
	 "when DUP_VAL_ON_INDEX then NULL; \n"
	 "end; \n"
	 "end loop; \n"
	 "end;");
#ifdef __DEBUG
      printf("%s\n", aux_sql);
#endif
      /* EXEC SQL prepare sql_stmt from :aux_sql; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 1;
      sqlstm.stmt = "";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)52;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)aux_sql;
      sqlstm.sqhstl[0] = (unsigned long  )10000;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Composicion de Indicador");
}


      /* EXEC SQL EXECUTE sql_stmt using :N_Regs; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 1;
      sqlstm.stmt = "";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)70;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&N_Regs;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Composicion de Indicador");
      if (sqlca.sqlcode < 0) sql_error("Composicion de Indicador");
}


   }
   /* EXEC SQL close r_compon; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 1;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)88;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Composicion de Indicador");
}


   return(N_Regs > 0);
}


void calcula_indicadores(char *Tipo)
{
   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      int      Nu_IndComp,
	       Nu_Cant_Indic,
               Nu_Vis_IndComp,
	       Nu_Nivl_Indic,
	       Nu_Fuente;
      char     Cd_Grnl_IndComp, aux[100];
      long     Ct_Componentes;
      /* VARCHAR  Nm_Rutn_Calc[40]; */ 
struct { unsigned short len; unsigned char arr[40]; } Nm_Rutn_Calc;

      T_DATE   FcMin, FcMax, Fc_Gen;
      short    Ind_Rutn_Calc;
   /* EXEC SQL END DECLARE SECTION; */ 

   char buf_rutn_espec[300]; /* Para rutinas de calculo especiales */

   /* EXEC SQL whenever SQLERROR DO sql_error("Oracle error"); */ 


   /* EXEC SQL
      select count(*)
	 into Nu_Cant_Indic
	 from V_INDCA_DERIV_NIVL D, G3_INDCA_PERFM I
	 where I.CD_TIPO_INDCA_PERFM = :Tipo and
	       I.NU_INDCA_PERFM = D.NU_INDCA_DERIV and
	       I.CD_INDCA_ATUAL = '0' and
	       ROWNUM = 1
      order by D.NU_NIVL_INDCA_DERIV; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 2;
   sqlstm.stmt = "select count(*)  into :b0  from V_INDCA_DERIV_NIVL D ,G3_I\
NDCA_PERFM I where (((I.CD_TIPO_INDCA_PERFM=:b1 and I.NU_INDCA_PERFM=D.NU_INDC\
A_DERIV) and I.CD_INDCA_ATUAL='0') and rownum =1) order by D.NU_NIVL_INDCA_DER\
IV ";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)102;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)&Nu_Cant_Indic;
   sqlstm.sqhstl[0] = (unsigned long  )4;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqhstv[1] = (unsigned char  *)Tipo;
   sqlstm.sqhstl[1] = (unsigned long  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode == 1403) sql_error("Composicion de Indicador");
   if (sqlca.sqlcode < 0) sql_error("Oracle error");
}



   if (Nu_Cant_Indic) {
      for (;;) {       /* Para cada indicador derivado todavia no calculado */
	 /* EXEC SQL whenever NOT FOUND do break; */ 
 
	 /* Buscando el proximo indicador a calcular */
	 /* EXEC SQL
	    select I.NU_INDCA_PERFM, I.NU_VISION,
		   I.NM_RUTN_CALC, I.CD_GRNL_INDCA_PERFM, D.NU_NIVL_INDCA_DERIV
	       into :Nu_IndComp, :Nu_Vis_IndComp, 
		    :Nm_Rutn_Calc:Ind_Rutn_Calc,
		    :Cd_Grnl_IndComp, :Nu_Nivl_Indic
	       from V_INDCA_DERIV_NIVL D, G3_INDCA_PERFM I
	       where I.CD_TIPO_INDCA_PERFM = :Tipo and
		     I.NU_INDCA_PERFM = D.NU_INDCA_DERIV and
		     I.CD_INDCA_ATUAL = '0' and
		     ROWNUM = 1
	       order by D.NU_NIVL_INDCA_DERIV; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 6;
  sqlstm.stmt = "select I.NU_INDCA_PERFM ,I.NU_VISION ,I.NM_RUTN_CALC ,I.CD_\
GRNL_INDCA_PERFM ,D.NU_NIVL_INDCA_DERIV into :b0,:b1,:b2:b3,:b4,:b5  from V_IN\
DCA_DERIV_NIVL D ,G3_INDCA_PERFM I where (((I.CD_TIPO_INDCA_PERFM=:b6 and I.NU\
_INDCA_PERFM=D.NU_INDCA_DERIV) and I.CD_INDCA_ATUAL='0') and rownum =1) order \
by D.NU_NIVL_INDCA_DERIV ";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)124;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (unsigned char  *)&Nu_IndComp;
  sqlstm.sqhstl[0] = (unsigned long  )4;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&Nu_Vis_IndComp;
  sqlstm.sqhstl[1] = (unsigned long  )4;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&Nm_Rutn_Calc;
  sqlstm.sqhstl[2] = (unsigned long  )42;
  sqlstm.sqindv[2] = (         short *)&Ind_Rutn_Calc;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&Cd_Grnl_IndComp;
  sqlstm.sqhstl[3] = (unsigned long  )1;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&Nu_Nivl_Indic;
  sqlstm.sqhstl[4] = (unsigned long  )4;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqhstv[5] = (unsigned char  *)Tipo;
  sqlstm.sqhstl[5] = (unsigned long  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("Oracle error");
}



   #ifdef __DEBUG
	 printf("Calculando %d\n", Nu_IndComp);
   #endif
	 /* EXEC SQL whenever NOT FOUND DO sql_error("Oracle error"); */ 

	 /* Indicando que ya pase por este indicador */
	 /* Si algun registro es generado, CD_INDCA_ATUAL se cambia para 1 */
	 /* EXEC SQL 
	    update G3_INDCA_PERFM set CD_INDCA_ATUAL = '2'
	       where NU_INDCA_PERFM = :Nu_IndComp; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 6;
  sqlstm.stmt = "update G3_INDCA_PERFM  set CD_INDCA_ATUAL='2' where NU_INDC\
A_PERFM=:b0";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)162;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (unsigned char  *)&Nu_IndComp;
  sqlstm.sqhstl[0] = (unsigned long  )4;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) sql_error("Oracle error");
  if (sqlca.sqlcode < 0) sql_error("Oracle error");
}



	 /* EXEC SQL whenever NOT FOUND do sql_error("Oracle error"); */ 
 
	 if (Ind_Rutn_Calc == -1) {
	    /* EXEC SQL EXECUTE
	       begin
		  G3_Log_Err.Log_Msj('A', 'El indicador ' || :Nu_IndComp ||
			' no tiene rutina de calculo.');
	       end;
	    END-EXEC; */ 

{
     struct sqlexd sqlstm;

     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 8;
     sqlstm.arrsiz = 6;
     sqlstm.stmt = "begin G3_Log_Err . Log_Msj ( 'A' , 'El indicador ' || :N\
u_IndComp || ' no tiene rutina de calculo.' ) ; end ;";
     sqlstm.iters = (unsigned long  )1;
     sqlstm.offset = (unsigned short)180;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)0;
     sqlstm.sqhstv[0] = (unsigned char  *)&Nu_IndComp;
     sqlstm.sqhstl[0] = (unsigned long  )4;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode == 1403) sql_error("Oracle error");
     if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


	    printf("El indicador %d no tiene rutina de calculo.\n", Nu_IndComp);
	    continue;
	 }
   #ifdef __DEBUG
	 printf("Intentando el calculo del indicador %d\n", Nu_IndComp);
   #endif
	 /* Hay nuevos datos para los componentes de este indicador  ? */
	 /* EXEC SQL
	    select count(*)
	       into :Ct_Componentes
	       from G3_INDCA_PERFM I,
		    G3_INDCA_PERFM_INDCA_PERFM C
	       where I.CD_INDCA_ATUAL = '1' and
		     I.NU_INDCA_PERFM = C.NU_INDCA_PERFM_ORIG and
		     C.NU_INDCA_PERFM_DEST = :Nu_IndComp; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 6;
  sqlstm.stmt = "select count(*)  into :b0  from G3_INDCA_PERFM I ,G3_INDCA_\
PERFM_INDCA_PERFM C where ((I.CD_INDCA_ATUAL='1' and I.NU_INDCA_PERFM=C.NU_IND\
CA_PERFM_ORIG) and C.NU_INDCA_PERFM_DEST=:b1)";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)198;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (unsigned char  *)&Ct_Componentes;
  sqlstm.sqhstl[0] = (unsigned long  )4;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&Nu_IndComp;
  sqlstm.sqhstl[1] = (unsigned long  )4;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) sql_error("Oracle error");
  if (sqlca.sqlcode < 0) sql_error("Oracle error");
}



   #ifdef __DEBUG
	    printf("Hay componentes ?\n");
   #endif
	 if ((Ct_Componentes)) { 
   #ifdef __DEBUG
	    printf("Hay componentes. Determinando rango de fechas.\n");
   #endif
	    /* EXEC SQL EXECUTE
	       declare
		  L_Fc_Min DATE;
		  L_Fc_Max DATE;
	       begin
		  :FcMin:= NULL;
		  :FcMax:= NULL;
		  for r_Compon in (
			select i.NU_INDCA_PERFM, i.NU_VISION,
			       i.CD_GRNL_INDCA_PERFM, i.FC_ULT_ATUAL_INDCA,
			       i.FC_LIM_INF_INDCA, i.FC_LIM_SUP_INDCA
			   from G3_INDCA_PERFM i, G3_INDCA_PERFM_INDCA_PERFM ii
			   where i.CD_INDCA_ATUAL = '1' and
				 i.NU_INDCA_PERFM = ii.NU_INDCA_PERFM_ORIG and
				 ii.NU_INDCA_PERFM_DEST = :Nu_IndComp)
		  loop
		     if r_Compon.FC_LIM_INF_INDCA is not null then
			L_Fc_Min:= r_Compon.FC_LIM_INF_INDCA;
			L_Fc_Max:= r_Compon.FC_LIM_SUP_INDCA;
		     else
			select min(s.FC_REFR_SERIE_HIST), max(s.FC_REFR_SERIE_HIST)
			   into L_Fc_Min, L_Fc_Max 
			   from V_SERIE_HIST s
			   where s.NU_INDCA_PERFM = r_Compon.NU_INDCA_PERFM and
				 s.NU_VISION = r_Compon.NU_VISION and
				 s.CD_GRNL_SERIE_HIST = r_Compon.CD_GRNL_INDCA_PERFM and
				 s.FC_GEN_FUENTE_INDCA_PERFM >= r_Compon.FC_ULT_ATUAL_INDCA;
		     end if;
		     if (:FcMin is NULL) or (L_Fc_Min < :FcMin) then
			:FcMin:= L_Fc_Min;
		     end if;

		     if (:FcMax is NULL) or (L_Fc_Max > :FcMax) then
			:FcMax:= L_Fc_Max;
		     end if;
		  end loop;
		  G3_Log_Err.Log_Msj('D', 'Calculando el indicador ' || :Nu_IndComp ||
		       ' de ' || :FcMin || ' hasta ' || :FcMax || '.');
		  commit;
	       end;
	    END-EXEC; */ 

{
     struct sqlexd sqlstm;

     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 8;
     sqlstm.arrsiz = 6;
     sqlbuft((void **)0, 
       "declare L_Fc_Min DATE ; L_Fc_Max DATE ; begin :FcMin := NULL ; :FcMa\
x := NULL ; for r_Compon in ( select i . NU_INDCA_PERFM , i . NU_VISION , i \
. CD_GRNL_INDCA_PERFM , i . FC_ULT_ATUAL_INDCA , i . FC_LIM_INF_INDCA , i . \
FC_LIM_SUP_INDCA from G3_INDCA_PERFM i , G3_INDCA_PERFM_INDCA_PERFM ii where\
 i . CD_INDCA_ATUAL = '1' and i . NU_INDCA_PERFM = ii . NU_INDCA_PERFM_ORIG \
and ii . NU_INDCA_PERFM_DEST = :Nu_IndComp ) loop if r_Compon . FC_LIM_INF_I\
NDCA is not null then L_Fc_Min := r_Compon . FC_LIM_INF_INDCA ; L_Fc_Max := \
r_Compon . FC_LIM_SUP_INDCA ; else select min ( s . FC_REFR_SERIE_HIST ) , m\
ax ( s . FC_REFR_SERIE_HIST ) into L_Fc_Min , L_Fc_Max from V_SERIE_HIST s w\
here s . NU_INDCA_PERFM = r_Compon . NU_INDCA_PERFM and s . NU_VISION = r_Co\
mpon . NU_VISION and s . CD_GRNL_SERIE_HIST = r_Compon . CD_GRNL_INDCA_PERFM\
 and s . FC_GEN_FUENTE_INDCA_PERFM >= r_Compon . FC_ULT_ATUAL_INDCA ; end if\
 ; if ( :FcMin is NULL ) or ( L_Fc_Min < :FcMin ) then :FcMin := L_Fc_Min ; \
end if ; if ( :FcMax is NULL ) or ( L_Fc_Max");
     sqlstm.stmt = " > :FcMax ) then :FcMax := L_Fc_Max ; end if ; end loop \
; G3_Log_Err . Log_Msj ( 'D' , 'Calculando el indicador ' || :Nu_IndComp || ' \
de ' || :FcMin || ' hasta ' || :FcMax || '.' ) ; commit ; end ;";
     sqlstm.iters = (unsigned long  )1;
     sqlstm.offset = (unsigned short)220;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)0;
     sqlstm.sqhstv[0] = (unsigned char  *)FcMin;
     sqlstm.sqhstl[0] = (unsigned long  )20;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqhstv[1] = (unsigned char  *)FcMax;
     sqlstm.sqhstl[1] = (unsigned long  )20;
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqhstv[2] = (unsigned char  *)&Nu_IndComp;
     sqlstm.sqhstl[2] = (unsigned long  )4;
     sqlstm.sqindv[2] = (         short *)0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode == 1403) sql_error("Oracle error");
     if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


	    printf("Calculando %d de %s a %s.\n", Nu_IndComp, FcMin, FcMax);

	    strcpy(buf_rutn_espec, "begin ");
	    strncat(buf_rutn_espec, (const char *)Nm_Rutn_Calc.arr, Nm_Rutn_Calc.len);
	    if (buf_rutn_espec[strlen(buf_rutn_espec)-1] != ';') {
	       /* EXEC SQL EXECUTE
		  declare
		     Aux boolean;
		  begin
		     Aux:= Sup_DW.Inic_Calc(:Nu_IndComp, :Nu_Fuente, :Fc_Gen);
		  end;
	       END-EXEC; */ 

{
        struct sqlexd sqlstm;

        sqlorat((void **)0, &sqlctx, &oraca);
        sqlstm.sqlvsn = 8;
        sqlstm.arrsiz = 6;
        sqlstm.stmt = "declare Aux boolean ; begin Aux := Sup_DW . Inic_Calc\
 ( :Nu_IndComp , :Nu_Fuente , :Fc_Gen ) ; end ;";
        sqlstm.iters = (unsigned long  )1;
        sqlstm.offset = (unsigned short)246;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)0;
        sqlstm.sqhstv[0] = (unsigned char  *)&Nu_IndComp;
        sqlstm.sqhstl[0] = (unsigned long  )4;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&Nu_Fuente;
        sqlstm.sqhstl[1] = (unsigned long  )4;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqhstv[2] = (unsigned char  *)Fc_Gen;
        sqlstm.sqhstl[2] = (unsigned long  )20;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode == 1403) sql_error("Oracle error");
        if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


	       sprintf(aux, "(%d, '%s', '%s', '%s'); end;", 
		     Nu_Fuente, Fc_Gen, FcMin, FcMax);
	       strcat(buf_rutn_espec, aux);
	    }
	    else
	       strcat(buf_rutn_espec, " end;"); 
	    /* EXEC SQL whenever SQLERROR DO sql_error("Oracle error"); */ 

	    /* EXEC SQL whenever NOT FOUND DO sql_error("Oracle error"); */ 


   #ifdef __DEBUG
	    printf("%s\n", buf_rutn_espec);
   #endif
	    /* EXEC SQL execute immediate :buf_rutn_espec; */ 

{
     struct sqlexd sqlstm;

     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 8;
     sqlstm.arrsiz = 6;
     sqlstm.stmt = "";
     sqlstm.iters = (unsigned long  )1;
     sqlstm.offset = (unsigned short)272;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)0;
     sqlstm.sqhstv[0] = (unsigned char  *)buf_rutn_espec;
     sqlstm.sqhstl[0] = (unsigned long  )300;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode == 1403) sql_error("Oracle error");
     if (sqlca.sqlcode < 0) sql_error("Oracle error");
}



	    /* EXEC SQL EXECUTE
	       begin
		  Sup_DW.Fin_Calc(:Nu_IndComp, 0);
	       end;
	    END-EXEC; */ 

{
     struct sqlexd sqlstm;

     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 8;
     sqlstm.arrsiz = 6;
     sqlstm.stmt = "begin Sup_DW . Fin_Calc ( :Nu_IndComp , 0 ) ; end ;";
     sqlstm.iters = (unsigned long  )1;
     sqlstm.offset = (unsigned short)290;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)0;
     sqlstm.sqhstv[0] = (unsigned char  *)&Nu_IndComp;
     sqlstm.sqhstl[0] = (unsigned long  )4;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode == 1403) sql_error("Oracle error");
     if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


	    printf("Calculado.\n");

	    /* EXEC SQL commit; */ 

{
     struct sqlexd sqlstm;

     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 8;
     sqlstm.arrsiz = 6;
     sqlstm.iters = (unsigned long  )1;
     sqlstm.offset = (unsigned short)308;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


	 }
   #ifdef __DEBUG
	 else
	    printf("%d no tiene componentes (%d) o no llegaran datos para sus componentes.\n", Nu_IndComp, Ct_Componentes);
   #endif
      }

      /* Volvendo todos los indicadores para los cuales no fueran calculados datos para 0 en CD_INDCA_ATUAL */
      /* EXEC SQL
	 update G3_INDCA_PERFM
	    set CD_INDCA_ATUAL = '0'
	    where CD_INDCA_ATUAL = '2'; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 6;
      sqlstm.stmt = "update G3_INDCA_PERFM  set CD_INDCA_ATUAL='0' where CD_\
INDCA_ATUAL='2'";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)322;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Oracle error");
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      /* EXEC SQL commit; */ 

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
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


   }
}
