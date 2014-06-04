
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
    ".\\atual2.pc"
};


static const unsigned long sqlctx = 884300535;


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
   unsigned char    *sqhstv[22];
   unsigned long    sqhstl[22];
	    short   *sqindv[22];
   unsigned long    sqharm[22];
   unsigned long     *sqharc[22];
} sqlstm = {8,22};

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

 static const char *sq0003 = 
"select  /*+  INDEX(S IX_MOVTSH01)  +*/ NU_INDCA_PERFM ,NU_VISION ,NU_INSTAN_\
DIMEN__1 ,NU_INSTAN_DIMEN__2 ,NU_INSTAN_DIMEN__3 ,NU_INSTAN_DIMEN__4 ,NU_INSTA\
N_DIMEN__5 ,NU_INSTAN_DIMEN__6 ,NU_INSTAN_DIMEN__7 ,NU_INSTAN_DIMEN__8 ,NU_INS\
TAN_DIMEN__9 ,NU_INSTAN_DIMEN__10 ,NU_INSTAN_DIMEN__11 ,NU_INSTAN_DIMEN__12 ,N\
U_INSTAN_DIMEN__13 ,NU_INSTAN_DIMEN__14 ,NU_INSTAN_DIMEN__15 ,NU_INSTAN_DIMEN_\
_16 ,FC_REFR_MOVT ,CT_INDCA_PERFM_MOVT ,NU_FUENTE_DATO_MOVT ,FC_GEN_MOVT  from\
 G3_MOVT_SERIE_HIST S where (NU_FUENTE_DATO_MOVT=:b0 and FC_GEN_MOVT=:b1)     \
      ";
 static const char *sq0006 = 
"select distinct a.NU_FUENTE_INDCA_PERFM ,a.FC_GEN_FUENTE_INDCA_PERFM ,b.NM_F\
UENTE_INDCA_PERFM ,b.CD_TIPO_ORIG_FUENTE_INDCA  from G3_LOG_FUENTE_INDCA_PERFM\
 a ,G3_FUENTE_INDCA_PERFM b where (a.FC_ATUALIZ_DW is null  and a.NU_FUENTE_IN\
DCA_PERFM=b.NU_FUENTE_INDCA_PERFM)           ";
typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{8,4130,
2,0,0,1,57,0,4,68,0,1,0,0,1,0,2,3,0,0,
20,0,0,2,81,0,4,74,0,2,1,0,1,0,2,97,0,0,1,3,0,0,
42,0,0,3,550,0,9,93,0,2,2,0,1,0,1,3,0,0,1,97,0,0,
64,0,0,3,0,0,13,102,0,22,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,
0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,3,0,0,2,97,0,0,
166,0,0,4,0,0,29,109,0,0,0,0,1,0,
180,0,0,3,0,0,15,115,0,0,0,0,1,0,
194,0,0,5,79,0,6,118,0,1,1,0,1,0,1,3,0,0,
212,0,0,6,277,0,9,146,0,0,0,0,1,0,
226,0,0,6,0,0,13,151,0,4,0,0,1,0,2,3,0,0,2,97,0,0,2,9,0,0,2,97,0,0,
256,0,0,7,117,0,6,155,0,2,2,0,1,0,1,3,0,0,1,97,0,0,
278,0,0,8,109,0,4,164,0,3,2,0,1,0,2,3,0,0,1,3,0,0,1,97,0,0,
304,0,0,9,128,0,5,174,0,2,2,0,1,0,1,3,0,0,1,97,0,0,
326,0,0,10,207,0,6,181,0,2,2,0,1,0,1,3,0,0,1,97,0,0,
348,0,0,11,95,0,6,195,0,0,0,0,1,0,
362,0,0,12,129,0,6,202,0,2,2,0,1,0,1,3,0,0,1,97,0,0,
384,0,0,13,0,0,29,208,0,0,0,0,1,0,
398,0,0,6,0,0,15,210,0,0,0,0,1,0,
412,0,0,14,0,0,29,212,0,0,0,0,1,0,
};


/*****************************************************************************
 *                                                                           *
 *                   ACTUALIZACION DEL DATA WAREHOUSE                        *
 *                                                                           *
 *             Actualizacion del Data Warehouse de datos importados o        *
 *                                calculado                                  *
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
#include <ocidfn.h>

#include "dw_aux.h"

static char SQL_INS[] =
   "begin \n"
   "insert into %.*s(NU_INDCA_PERFM,NU_VISION,NU_INSTAN_DIMEN__1,\n "
   "NU_INSTAN_DIMEN__2,NU_INSTAN_DIMEN__3,NU_INSTAN_DIMEN__4,NU_INSTAN_DIMEN__5,"
   "NU_INSTAN_DIMEN__6,NU_INSTAN_DIMEN__7,NU_INSTAN_DIMEN__8,NU_INSTAN_DIMEN__9,"
   "NU_INSTAN_DIMEN__10,NU_INSTAN_DIMEN__11,NU_INSTAN_DIMEN__12,NU_INSTAN_DIMEN__13,"
   "NU_INSTAN_DIMEN__14,NU_INSTAN_DIMEN__15,NU_INSTAN_DIMEN__16,FC_REFR_SERIE_HIST,"
   "CD_GRNL_SERIE_HIST,CT_VALOR_SERIE_HIST,NU_FUENTE_INDCA_PERFM,"
   "FC_GEN_FUENTE_INDCA_PERFM) values (:Indic, :Vision, :Inst1, :Inst2, :Inst3,"
   ":Inst4, :Inst5, :Inst6, :Inst7, :Inst8, :Inst9, :Inst10, :Inst11, :Inst12,"
   ":Inst13, :Inst14, :Inst15, :Inst16, :Fc_Refr, :Grnl, :Valor,"
   ":Fuente, :Fc_Gen); "
   "exception \n"
   "when DUP_VAL_ON_INDEX then \n"
   "update %.*s set CT_VALOR_SERIE_HIST=:Valor,"
   "NU_FUENTE_INDCA_PERFM=:Fuente, "
   "FC_GEN_FUENTE_INDCA_PERFM=:Fc_Gen "
   "where NU_INDCA_PERFM=:Indic and NU_VISION=:Vision and "
   "NU_INSTAN_DIMEN__1=:Inst1 and NU_INSTAN_DIMEN__2=:Inst2 and "
   "NU_INSTAN_DIMEN__3=:Inst3 and NU_INSTAN_DIMEN__4=:Inst4 and "
   "NU_INSTAN_DIMEN__5=:Inst5 and NU_INSTAN_DIMEN__6=:Inst6 and "
   "NU_INSTAN_DIMEN__7=:Inst7 and NU_INSTAN_DIMEN__8=:Inst8 and "
   "NU_INSTAN_DIMEN__9=:Inst9 and NU_INSTAN_DIMEN__10=:Inst10 and "
   "NU_INSTAN_DIMEN__11=:Inst11 and NU_INSTAN_DIMEN__12=:Inst12 and "
   "NU_INSTAN_DIMEN__13=:Inst13 and NU_INSTAN_DIMEN__14=:Inst14 and "
   "NU_INSTAN_DIMEN__15=:Inst15 and NU_INSTAN_DIMEN__16=:Inst16 and "
   "FC_REFR_SERIE_HIST=:Fc_Refr and CD_GRNL_SERIE_HIST=:Grnl; \n"
   "end;\n";

/*************************************************************************************
  Actualiza las tablas de serie historica para fuentes de datos del tipo Sistema
 *************************************************************************************/

static void Atualiza_Serie_Hist_Sist(int Fuente, T_DATE Fc_Gen)
{
   T_REG_MOVT Reg_Movt;
   T_REG_SH Reg_SH;
   int NIndca, NRegs;
   int i;
   T_DATE Last_Date;
   char Grnl[2], *GrnlArr;

   /* Traendo las granularidades de los indicadores para un vector en memoria */
   /* EXEC SQL select max(NU_INDCA_PERFM)
      into :NIndca
      from G3_INDCA_PERFM; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 1;
   sqlstm.stmt = "select max(NU_INDCA_PERFM) into :b0  from G3_INDCA_PERFM ";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)2;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)&NIndca;
   sqlstm.sqhstl[0] = (unsigned long  )4;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


   GrnlArr = calloc(NIndca, sizeof(char));
   /* EXEC SQL whenever NOT FOUND continue; */ 

   for (i = 1; i <= NIndca; i++) {
      /* EXEC SQL select CD_GRNL_INDCA_PERFM
	    into :Grnl
	    from G3_INDCA_PERFM
	    where NU_INDCA_PERFM = :i; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 2;
      sqlstm.stmt = "select CD_GRNL_INDCA_PERFM into :b0  from G3_INDCA_PERF\
M where NU_INDCA_PERFM=:b1";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)20;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)Grnl;
      sqlstm.sqhstl[0] = (unsigned long  )2;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&i;
      sqlstm.sqhstl[1] = (unsigned long  )4;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


      GrnlArr[i-1] = *Grnl;
   }
	 /* antes estaba incluido en el cursor order by FC_REFR_MOVT; */
      /* hint comentado select + INDEX(S PK_MOVTSH) */ 
   /* EXEC SQL declare r_mov cursor for
      select /o+ INDEX(S IX_MOVTSH01) o/ NU_INDCA_PERFM, NU_VISION,
      NU_INSTAN_DIMEN__1, NU_INSTAN_DIMEN__2, NU_INSTAN_DIMEN__3, NU_INSTAN_DIMEN__4,
      NU_INSTAN_DIMEN__5, NU_INSTAN_DIMEN__6, NU_INSTAN_DIMEN__7, NU_INSTAN_DIMEN__8,
      NU_INSTAN_DIMEN__9, NU_INSTAN_DIMEN__10, NU_INSTAN_DIMEN__11, NU_INSTAN_DIMEN__12,
      NU_INSTAN_DIMEN__13, NU_INSTAN_DIMEN__14, NU_INSTAN_DIMEN__15, NU_INSTAN_DIMEN__16,
      FC_REFR_MOVT, CT_INDCA_PERFM_MOVT, NU_FUENTE_DATO_MOVT, FC_GEN_MOVT
	 from G3_MOVT_SERIE_HIST S
         where NU_FUENTE_DATO_MOVT = :Fuente and
	       FC_GEN_MOVT = :Fc_Gen; */ 


   /* EXEC SQL open r_mov; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 2;
   sqlstm.stmt = sq0003;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)42;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)&Fuente;
   sqlstm.sqhstl[0] = (unsigned long  )4;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqhstv[1] = (unsigned char  *)Fc_Gen;
   sqlstm.sqhstl[1] = (unsigned long  )20;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


   NRegs = 0;
   strcpy(Last_Date, "");

   /* Procesando los datos de la Fuente */
   printf("Efectuo la apertura del cursor\n");
   Reg_SH.Grnl[1] = 0;
   /* EXEC SQL whenever NOT FOUND do break; */ 

   for (;;) {
      /* EXEC SQL fetch r_mov into :Reg_Movt; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 22;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)64;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Reg_Movt.Indic;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&Reg_Movt.Vision;
      sqlstm.sqhstl[1] = (unsigned long  )4;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&Reg_Movt.Inst1;
      sqlstm.sqhstl[2] = (unsigned long  )4;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&Reg_Movt.Inst2;
      sqlstm.sqhstl[3] = (unsigned long  )4;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&Reg_Movt.Inst3;
      sqlstm.sqhstl[4] = (unsigned long  )4;
      sqlstm.sqindv[4] = (         short *)0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqhstv[5] = (unsigned char  *)&Reg_Movt.Inst4;
      sqlstm.sqhstl[5] = (unsigned long  )4;
      sqlstm.sqindv[5] = (         short *)0;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqhstv[6] = (unsigned char  *)&Reg_Movt.Inst5;
      sqlstm.sqhstl[6] = (unsigned long  )4;
      sqlstm.sqindv[6] = (         short *)0;
      sqlstm.sqharm[6] = (unsigned long )0;
      sqlstm.sqhstv[7] = (unsigned char  *)&Reg_Movt.Inst6;
      sqlstm.sqhstl[7] = (unsigned long  )4;
      sqlstm.sqindv[7] = (         short *)0;
      sqlstm.sqharm[7] = (unsigned long )0;
      sqlstm.sqhstv[8] = (unsigned char  *)&Reg_Movt.Inst7;
      sqlstm.sqhstl[8] = (unsigned long  )4;
      sqlstm.sqindv[8] = (         short *)0;
      sqlstm.sqharm[8] = (unsigned long )0;
      sqlstm.sqhstv[9] = (unsigned char  *)&Reg_Movt.Inst8;
      sqlstm.sqhstl[9] = (unsigned long  )4;
      sqlstm.sqindv[9] = (         short *)0;
      sqlstm.sqharm[9] = (unsigned long )0;
      sqlstm.sqhstv[10] = (unsigned char  *)&Reg_Movt.Inst9;
      sqlstm.sqhstl[10] = (unsigned long  )4;
      sqlstm.sqindv[10] = (         short *)0;
      sqlstm.sqharm[10] = (unsigned long )0;
      sqlstm.sqhstv[11] = (unsigned char  *)&Reg_Movt.Inst10;
      sqlstm.sqhstl[11] = (unsigned long  )4;
      sqlstm.sqindv[11] = (         short *)0;
      sqlstm.sqharm[11] = (unsigned long )0;
      sqlstm.sqhstv[12] = (unsigned char  *)&Reg_Movt.Inst11;
      sqlstm.sqhstl[12] = (unsigned long  )4;
      sqlstm.sqindv[12] = (         short *)0;
      sqlstm.sqharm[12] = (unsigned long )0;
      sqlstm.sqhstv[13] = (unsigned char  *)&Reg_Movt.Inst12;
      sqlstm.sqhstl[13] = (unsigned long  )4;
      sqlstm.sqindv[13] = (         short *)0;
      sqlstm.sqharm[13] = (unsigned long )0;
      sqlstm.sqhstv[14] = (unsigned char  *)&Reg_Movt.Inst13;
      sqlstm.sqhstl[14] = (unsigned long  )4;
      sqlstm.sqindv[14] = (         short *)0;
      sqlstm.sqharm[14] = (unsigned long )0;
      sqlstm.sqhstv[15] = (unsigned char  *)&Reg_Movt.Inst14;
      sqlstm.sqhstl[15] = (unsigned long  )4;
      sqlstm.sqindv[15] = (         short *)0;
      sqlstm.sqharm[15] = (unsigned long )0;
      sqlstm.sqhstv[16] = (unsigned char  *)&Reg_Movt.Inst15;
      sqlstm.sqhstl[16] = (unsigned long  )4;
      sqlstm.sqindv[16] = (         short *)0;
      sqlstm.sqharm[16] = (unsigned long )0;
      sqlstm.sqhstv[17] = (unsigned char  *)&Reg_Movt.Inst16;
      sqlstm.sqhstl[17] = (unsigned long  )4;
      sqlstm.sqindv[17] = (         short *)0;
      sqlstm.sqharm[17] = (unsigned long )0;
      sqlstm.sqhstv[18] = (unsigned char  *)Reg_Movt.Fc_Refr;
      sqlstm.sqhstl[18] = (unsigned long  )20;
      sqlstm.sqindv[18] = (         short *)0;
      sqlstm.sqharm[18] = (unsigned long )0;
      sqlstm.sqhstv[19] = (unsigned char  *)&Reg_Movt.Valor;
      sqlstm.sqhstl[19] = (unsigned long  )8;
      sqlstm.sqindv[19] = (         short *)0;
      sqlstm.sqharm[19] = (unsigned long )0;
      sqlstm.sqhstv[20] = (unsigned char  *)&Reg_Movt.Fuente;
      sqlstm.sqhstl[20] = (unsigned long  )4;
      sqlstm.sqindv[20] = (         short *)0;
      sqlstm.sqharm[20] = (unsigned long )0;
      sqlstm.sqhstv[21] = (unsigned char  *)Reg_Movt.Fc_Gen;
      sqlstm.sqhstl[21] = (unsigned long  )20;
      sqlstm.sqindv[21] = (         short *)0;
      sqlstm.sqharm[21] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) break;
}



      memcpy(&Reg_SH, &Reg_Movt, sizeof(Reg_Movt));
      Reg_SH.Grnl[0] = GrnlArr[Reg_Movt.Indic-1];

      Graba_Reg_SH(&Reg_SH);
      if (!(++NRegs % 1000)) {
         /* EXEC SQL commit; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 22;
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)166;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


         putchar('.');
      }

   }
   printf("%d registros procesados\n", NRegs);
   /* EXEC SQL close r_mov; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 22;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)180;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


   /* EXEC SQL whenever SQLERROR continue; */ 

   /* EXEC SQL whenever NOT FOUND continue; */ 

   /* EXEC SQL EXECUTE
   begin
      G3_Log_Err.Log_Msj('D', :NRegs || ' registros procesados.');
   end;
   END-EXEC; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 22;
   sqlstm.stmt = "begin G3_Log_Err . Log_Msj ( 'D' , :NRegs || ' registros p\
rocesados.' ) ; end ;";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)194;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)&NRegs;
   sqlstm.sqhstl[0] = (unsigned long  )4;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


   free(GrnlArr);
}

/*****************************************************************************
 Procedure atualiza_dw

 Actualiza los valores del DW
 *****************************************************************************/

void atualiza_dw(int Proceso_Completo)
{
   T_DATE Fc_Gen;
   char Tipo_Fuente[2];
   int Fuente, Todo_Procesado;
   /* VARCHAR Nm_Fuente[40]; */ 
struct { unsigned short len; unsigned char arr[40]; } Nm_Fuente;

   
   /* EXEC SQL declare r_fontes CURSOR for
      select distinct a.NU_FUENTE_INDCA_PERFM, a.FC_GEN_FUENTE_INDCA_PERFM,
             b.NM_FUENTE_INDCA_PERFM, b.CD_TIPO_ORIG_FUENTE_INDCA
         from G3_LOG_FUENTE_INDCA_PERFM a, G3_FUENTE_INDCA_PERFM b
         where a.FC_ATUALIZ_DW is NULL and
               a.NU_FUENTE_INDCA_PERFM = b.NU_FUENTE_INDCA_PERFM; */ 

   
   /* EXEC SQL open r_fontes; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 22;
   sqlstm.stmt = sq0006;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)212;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



   /* EXEC SQL whenever SQLERROR do sql_error("Actualizacion del DW"); */ 

   /* EXEC SQL whenever NOT FOUND do break; */ 

   for (;;)   {  /* Para cada fuente de datos con datos en movimiento */
      /* EXEC SQL fetch r_fontes into :Fuente, :Fc_Gen, :Nm_Fuente, :Tipo_Fuente; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 22;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)226;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Fuente;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)Fc_Gen;
      sqlstm.sqhstl[1] = (unsigned long  )20;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&Nm_Fuente;
      sqlstm.sqhstl[2] = (unsigned long  )42;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqhstv[3] = (unsigned char  *)Tipo_Fuente;
      sqlstm.sqhstl[3] = (unsigned long  )2;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) break;
      if (sqlca.sqlcode < 0) sql_error("Actualizacion del DW");
}



      /* EXEC SQL whenever NOT FOUND do sql_error("Actualizacion del DW"); */ 

      printf("Procesando lote de fuente %d, generado en %s\n", Fuente, Fc_Gen);
      /* EXEC SQL EXECUTE
      begin
         G3_Log_Err.Log_Msj('D', 'Procesando lote de la fuente ' ||
                            :Fuente || ' generado en ' || :Fc_Gen);
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 22;
      sqlstm.stmt = "begin G3_Log_Err . Log_Msj ( 'D' , 'Procesando lote de \
la fuente ' || :Fuente || ' generado en ' || :Fc_Gen ) ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)256;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Fuente;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)Fc_Gen;
      sqlstm.sqhstl[1] = (unsigned long  )20;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Actualizacion del DW");
      if (sqlca.sqlcode < 0) sql_error("Actualizacion del DW");
}



      Todo_Procesado = 1;
      /* EXEC SQL whenever NOT FOUND continue; */ 

      /* EXEC SQL
         select 0
            into :Todo_Procesado
            from G3_EXTRT_SIG_CTRL
            where NU_FUENTE_INDCA_PERFM = :Fuente and
                  FC_GEN_FUENTE_INDCA_PERFM = :Fc_Gen; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 22;
      sqlstm.stmt = "select 0 into :b0  from G3_EXTRT_SIG_CTRL where (NU_FUE\
NTE_INDCA_PERFM=:b1 and FC_GEN_FUENTE_INDCA_PERFM=:b2)";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)278;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Todo_Procesado;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&Fuente;
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
      if (sqlca.sqlcode < 0) sql_error("Actualizacion del DW");
}



      /* EXEC SQL whenever NOT FOUND do sql_error("Actualizacion del DW"); */ 

      if (Todo_Procesado) {
         Atualiza_Serie_Hist_Sist(Fuente, Fc_Gen);
         /* EXEC SQL
            update G3_LOG_FUENTE_INDCA_PERFM
               set FC_ATUALIZ_DW = sysdate
               where NU_FUENTE_INDCA_PERFM = :Fuente and
                     FC_GEN_FUENTE_INDCA_PERFM = :Fc_Gen; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 22;
         sqlstm.stmt = "update G3_LOG_FUENTE_INDCA_PERFM  set FC_ATUALIZ_DW=\
sysdate  where (NU_FUENTE_INDCA_PERFM=:b0 and FC_GEN_FUENTE_INDCA_PERFM=:b1)";
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)304;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlstm.sqhstv[0] = (unsigned char  *)&Fuente;
         sqlstm.sqhstl[0] = (unsigned long  )4;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqhstv[1] = (unsigned char  *)Fc_Gen;
         sqlstm.sqhstl[1] = (unsigned long  )20;
         sqlstm.sqindv[1] = (         short *)0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode == 1403) sql_error("Actualizacion del DW");
         if (sqlca.sqlcode < 0) sql_error("Actualizacion del DW");
}



         if (Proceso_Completo) {
            /* EXEC SQL EXECUTE
            declare 
               JobNum number;
            begin
               G3_Log_Err.Log_Msj('D', 'Borrando registros...');
	       dbms_job.submit(JobNum, 'begin borra_movimiento(' ||
	                       :Fuente || ', ''' || :Fc_Gen || '''); end;');
               commit;
            end;
            END-EXEC; */ 

{
            struct sqlexd sqlstm;

            sqlorat((void **)0, &sqlctx, &oraca);
            sqlstm.sqlvsn = 8;
            sqlstm.arrsiz = 22;
            sqlstm.stmt = "declare JobNum number ; begin G3_Log_Err . Log_Ms\
j ( 'D' , 'Borrando registros...' ) ; dbms_job . submit ( JobNum , 'begin borr\
a_movimiento(' || :Fuente || ', ''' || :Fc_Gen || '''); end;' ) ; commit ; end\
 ;";
            sqlstm.iters = (unsigned long  )1;
            sqlstm.offset = (unsigned short)326;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)0;
            sqlstm.sqhstv[0] = (unsigned char  *)&Fuente;
            sqlstm.sqhstl[0] = (unsigned long  )4;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqhstv[1] = (unsigned char  *)Fc_Gen;
            sqlstm.sqhstl[1] = (unsigned long  )20;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode == 1403) sql_error("Actualizacion del DW");
            if (sqlca.sqlcode < 0) sql_error("Actualizacion del DW");
}


         }
      }
      else {
         printf("Lote no procesado. Todavia hay datos rechazados.\n");
         /* EXEC SQL EXECUTE
         begin
            G3_Log_Err.Log_Msj('D', 'Lote no procesado. Todavia hay datos rechazados.');
         end;
         END-EXEC; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 22;
         sqlstm.stmt = "begin G3_Log_Err . Log_Msj ( 'D' , 'Lote no procesad\
o. Todavia hay datos rechazados.' ) ; end ;";
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)348;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode == 1403) sql_error("Actualizacion del DW");
         if (sqlca.sqlcode < 0) sql_error("Actualizacion del DW");
}


      }

      /* EXEC SQL EXECUTE
      begin
         G3_Log_Err.Log_Msj('D', 'Fin del procesamiento del lote de fuente ' ||
            :Fuente || ' generado en ' || :Fc_Gen);
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 22;
      sqlstm.stmt = "begin G3_Log_Err . Log_Msj ( 'D' , 'Fin del procesamien\
to del lote de fuente ' || :Fuente || ' generado en ' || :Fc_Gen ) ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)362;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Fuente;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)Fc_Gen;
      sqlstm.sqhstl[1] = (unsigned long  )20;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Actualizacion del DW");
      if (sqlca.sqlcode < 0) sql_error("Actualizacion del DW");
}


      /* EXEC SQL commit work; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 22;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)384;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Actualizacion del DW");
}


   }
   /* EXEC SQL close r_fontes; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 22;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)398;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Actualizacion del DW");
}



   /* EXEC SQL commit work; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 22;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)412;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Actualizacion del DW");
}


}
