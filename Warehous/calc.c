
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
           char  filnam[10];
};
static const struct sqlcxp sqlfpn =
{
    9,
    ".\\calc.pc"
};


static const unsigned long sqlctx = 884878627;


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
   unsigned char    *sqhstv[4];
   unsigned long    sqhstl[4];
	    short   *sqindv[4];
   unsigned long    sqharm[4];
   unsigned long     *sqharc[4];
} sqlstm = {8,4};

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
"select NU_INDCA_PERFM ,NU_VISION ,CD_GRNL_INDCA_PERFM ,FC_ULT_ATUAL_INDCA  f\
rom G3_INDCA_PERFM where CD_INDCA_ATUAL='1'           ";
 static const char *sq0008 = 
"select distinct s.NU_FUENTE_INDCA_PERFM ,s.FC_GEN_FUENTE_INDCA_PERFM ,s.FC_R\
EFR_SERIE_HIST  from V_SERIE_HIST s where (((s.NU_INDCA_PERFM=:b0 and s.NU_VIS\
ION=:b1) and s.CD_GRNL_SERIE_HIST=:b2) and s.FC_GEN_FUENTE_INDCA_PERFM>=:b3)  \
         ";
typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{8,4130,
2,0,0,1,70,0,5,34,0,0,0,0,1,0,
16,0,0,2,74,0,4,41,0,1,0,0,1,0,2,97,0,0,
34,0,0,3,65,0,5,48,0,1,1,0,1,0,1,97,0,0,
52,0,0,4,65,0,5,54,0,1,1,0,1,0,1,97,0,0,
70,0,0,5,65,0,5,62,0,0,0,0,1,0,
84,0,0,6,0,0,29,66,0,0,0,0,1,0,
98,0,0,7,130,0,9,86,0,0,0,0,1,0,
112,0,0,7,0,0,13,89,0,4,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
142,0,0,8,241,0,9,100,0,4,4,0,1,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
172,0,0,8,0,0,13,104,0,3,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,
198,0,0,8,0,0,15,111,0,0,0,0,1,0,
212,0,0,7,0,0,15,113,0,0,0,0,1,0,
226,0,0,9,0,0,27,261,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
252,0,0,10,59,0,1,264,0,0,0,0,1,0,
266,0,0,11,43,0,1,265,0,0,0,0,1,0,
280,0,0,12,36,0,4,266,0,1,0,0,1,0,2,97,0,0,
298,0,0,13,71,0,4,279,0,1,0,0,1,0,2,3,0,0,
316,0,0,14,34,0,1,284,0,0,0,0,1,0,
330,0,0,15,138,0,6,285,0,0,0,0,1,0,
344,0,0,16,35,0,1,295,0,0,0,0,1,0,
358,0,0,17,71,0,4,309,0,1,0,0,1,0,2,3,0,0,
376,0,0,18,34,0,1,314,0,0,0,0,1,0,
390,0,0,19,139,0,6,315,0,0,0,0,1,0,
404,0,0,20,35,0,1,325,0,0,0,0,1,0,
418,0,0,21,71,0,4,339,0,1,0,0,1,0,2,3,0,0,
436,0,0,22,34,0,1,344,0,0,0,0,1,0,
450,0,0,23,362,0,6,345,0,0,0,0,1,0,
464,0,0,24,35,0,1,362,0,0,0,0,1,0,
478,0,0,25,71,0,4,378,0,1,0,0,1,0,2,3,0,0,
496,0,0,26,34,0,1,383,0,0,0,0,1,0,
510,0,0,27,127,0,6,384,0,0,0,0,1,0,
524,0,0,28,38,0,6,399,0,0,0,0,1,0,
538,0,0,29,35,0,1,404,0,0,0,0,1,0,
552,0,0,30,71,0,4,417,0,1,0,0,1,0,2,3,0,0,
570,0,0,31,34,0,1,422,0,0,0,0,1,0,
584,0,0,32,220,0,6,423,0,0,0,0,1,0,
598,0,0,33,119,0,6,434,0,0,0,0,1,0,
612,0,0,34,35,0,1,442,0,0,0,0,1,0,
626,0,0,35,71,0,4,455,0,1,0,0,1,0,2,3,0,0,
644,0,0,36,34,0,1,460,0,0,0,0,1,0,
658,0,0,37,127,0,6,461,0,0,0,0,1,0,
672,0,0,38,38,0,6,471,0,0,0,0,1,0,
686,0,0,39,35,0,1,478,0,0,0,0,1,0,
700,0,0,40,72,0,4,490,0,1,0,0,1,0,2,3,0,0,
718,0,0,41,34,0,1,495,0,0,0,0,1,0,
732,0,0,42,127,0,6,496,0,0,0,0,1,0,
746,0,0,43,38,0,6,505,0,0,0,0,1,0,
760,0,0,44,35,0,1,512,0,0,0,0,1,0,
774,0,0,45,72,0,4,521,0,1,0,0,1,0,2,3,0,0,
792,0,0,46,72,0,4,532,0,1,0,0,1,0,2,3,0,0,
810,0,0,47,34,0,1,537,0,0,0,0,1,0,
824,0,0,48,127,0,6,538,0,0,0,0,1,0,
838,0,0,49,38,0,6,547,0,0,0,0,1,0,
852,0,0,50,35,0,1,554,0,0,0,0,1,0,
866,0,0,51,72,0,4,567,0,1,0,0,1,0,2,3,0,0,
884,0,0,52,34,0,1,572,0,0,0,0,1,0,
898,0,0,53,127,0,6,573,0,0,0,0,1,0,
912,0,0,54,38,0,6,582,0,0,0,0,1,0,
926,0,0,55,35,0,1,587,0,0,0,0,1,0,
940,0,0,56,72,0,4,601,0,1,0,0,1,0,2,3,0,0,
958,0,0,57,34,0,1,606,0,0,0,0,1,0,
972,0,0,58,127,0,6,608,0,0,0,0,1,0,
986,0,0,59,72,0,4,616,0,1,0,0,1,0,2,3,0,0,
1004,0,0,60,38,0,6,625,0,0,0,0,1,0,
1018,0,0,61,35,0,1,630,0,0,0,0,1,0,
1032,0,0,62,0,0,30,649,0,0,0,0,1,0,
};


#ifndef ORA_PROC
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#endif
#include <errno.h>

#include <sqlca.h>
#include <oraca.h>
#include "dw_aux.h"
/* EXEC ORACLE OPTION (ORACA=YES); */ 


char username[30], password[30], dbname[30];
T_DATE Fc_Inic_Proc;

extern char **environ;

/*****************************************
   Cierra_DW: Cierre de la aplicacion del mantenimiento del DW.

      Marca todos los indicadores como actualizados, pone el Data Warehouse en estado
      idle (-) y prepara la fecha inicial para el proximo calculo.
 *****************************************/
void Cierra_DW(int tudo)
{
   T_DATE Fc_Dt_Recz;
   short  In_Dt_Recz;

   /* EXEC SQL whenever SQLERROR do sql_error("Oracle error"); */ 

   if (tudo) {
      /* Seteando fecha de ultima atualizacion de los indicadores */
      /* EXEC SQL update G3_INDCA_PERFM
 	    set CD_INDCA_ATUAL = '0'
	    where CD_INDCA_ATUAL = '1'; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 0;
      sqlstm.stmt = "update G3_INDCA_PERFM  set CD_INDCA_ATUAL='0' where CD_\
INDCA_ATUAL='1'";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)2;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


	    
      /* Ajustando ultima fecha de generacion */

      /* Hay algun dato rechazado que tendra que ser reprocesado ? */
      /* EXEC SQL 
         select min(FC_GEN_FUENTE_INDCA_PERFM)
            into :Fc_Dt_Recz:In_Dt_Recz
            from G3_EXTRT_SIG_DATO; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 1;
      sqlstm.stmt = "select min(FC_GEN_FUENTE_INDCA_PERFM) into :b0:b1  from\
 G3_EXTRT_SIG_DATO ";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)16;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)Fc_Dt_Recz;
      sqlstm.sqhstl[0] = (unsigned long  )20;
      sqlstm.sqindv[0] = (         short *)&In_Dt_Recz;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}



      /* No, procesar a partir del ultimo procesamiento */
      if (In_Dt_Recz == -1) {
         /* EXEC SQL
            update G3_PARM_SIST
			   set TX_VL_PARM_SIST = :Fc_Inic_Proc
               where NU_PARM_SIST = 2; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 1;
         sqlstm.stmt = "update G3_PARM_SIST  set TX_VL_PARM_SIST=:b0 where N\
U_PARM_SIST=2";
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)34;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlstm.sqhstv[0] = (unsigned char  *)Fc_Inic_Proc;
         sqlstm.sqhstl[0] = (unsigned long  )20;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      }
      else {  /* Si, reprocesarlos en el proximo procesamiento */
         /* EXEC SQL
            update G3_PARM_SIST
			   set TX_VL_PARM_SIST = :Fc_Dt_Recz
               where NU_PARM_SIST = 2; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 1;
         sqlstm.stmt = "update G3_PARM_SIST  set TX_VL_PARM_SIST=:b0 where N\
U_PARM_SIST=2";
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)52;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlstm.sqhstv[0] = (unsigned char  *)Fc_Dt_Recz;
         sqlstm.sqhstl[0] = (unsigned long  )20;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      }
   }

   /* Ponendo el Warehouse en estado Idle */
   /* EXEC SQL
      update G3_PARM_SIST
	     set TX_VL_PARM_SIST = '-'
         where NU_PARM_SIST = 1; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 1;
   sqlstm.stmt = "update G3_PARM_SIST  set TX_VL_PARM_SIST='-' where NU_PARM\
_SIST=1";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)70;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


   /* EXEC SQL commit; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 1;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)84;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


}

/**********************************
  Crea_Flags_DM: Crea los registro de control que informan a los Data Marts cuales son
	los nuevos lotes de informacion que deben procesar.
 **********************************/
void Crea_Flags_DM()
{
   int Fuente;
   int Indca, Vision;
   char Grnl[2];
   T_DATE FcIndca, FcGen, FcRefr;

   /* EXEC SQL whenever SQLERROR do sql_error("Oracle error"); */ 

   /* EXEC SQL declare c_Indca cursor for
     select NU_INDCA_PERFM, NU_VISION, CD_GRNL_INDCA_PERFM, FC_ULT_ATUAL_INDCA
        from G3_INDCA_PERFM
        where CD_INDCA_ATUAL = '1'; */ 


   /* EXEC SQL open c_Indca; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 1;
   sqlstm.stmt = sq0007;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)98;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


   /* EXEC SQL whenever NOTFOUND do break; */ 

   for (;;) {
      /* EXEC SQL fetch c_Indca into :Indca, :Vision, :Grnl, :FcIndca; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)112;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Indca;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&Vision;
      sqlstm.sqhstl[1] = (unsigned long  )4;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqhstv[2] = (unsigned char  *)Grnl;
      sqlstm.sqhstl[2] = (unsigned long  )2;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqhstv[3] = (unsigned char  *)FcIndca;
      sqlstm.sqhstl[3] = (unsigned long  )20;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) break;
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}



      /* EXEC SQL whenever NOTFOUND do sql_error("Oracle error"); */ 

      /* EXEC SQL declare c_Fuente CURSOR FOR 
         select distinct s.NU_FUENTE_INDCA_PERFM, s.FC_GEN_FUENTE_INDCA_PERFM,
                s.FC_REFR_SERIE_HIST
            from V_SERIE_HIST s
            where s.NU_INDCA_PERFM = :Indca and
                  s.NU_VISION = :Vision and
                  s.CD_GRNL_SERIE_HIST = :Grnl and
                  s.FC_GEN_FUENTE_INDCA_PERFM >= :FcIndca; */ 

      /* EXEC SQL open c_Fuente; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = sq0008;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)142;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Indca;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&Vision;
      sqlstm.sqhstl[1] = (unsigned long  )4;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqhstv[2] = (unsigned char  *)Grnl;
      sqlstm.sqhstl[2] = (unsigned long  )2;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqhstv[3] = (unsigned char  *)FcIndca;
      sqlstm.sqhstl[3] = (unsigned long  )20;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}



      /* EXEC SQL whenever NOTFOUND do break; */ 

      for (;;) {
         /* EXEC SQL fetch c_Fuente into :Fuente, :FcGen, :FcRefr; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 4;
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)172;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlstm.sqhstv[0] = (unsigned char  *)&Fuente;
         sqlstm.sqhstl[0] = (unsigned long  )4;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqhstv[1] = (unsigned char  *)FcGen;
         sqlstm.sqhstl[1] = (unsigned long  )20;
         sqlstm.sqindv[1] = (         short *)0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqhstv[2] = (unsigned char  *)FcRefr;
         sqlstm.sqhstl[2] = (unsigned long  )20;
         sqlstm.sqindv[2] = (         short *)0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode == 1403) break;
         if (sqlca.sqlcode < 0) sql_error("Oracle error");
}



         /* EXEC SQL whenever SQLERROR do sql_error("Oracle error"); */ 

         /* EXEC SQL whenever NOTFOUND do sql_error("Oracle error"); */ 


	     /* Insere_Log_Proc_Server(Fuente, FcGen, FcRefr); */
      }
      /* EXEC SQL close c_Fuente; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)198;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


   }
   /* EXEC SQL close c_Indca; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 4;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)212;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


}

static char User_Name[60], PassWord[60];
void dispara_anterior(char *nombre)
{
   char comando[128];

   printf("Iniciando calculo de procesos anteriores a %s\n", nombre);
   sprintf(comando, "%s\\jobs\\ant%s.bat", getenv("WAREHOME"), nombre);
   fflush(stdout);
   sprintf(User_Name, "USERNAME=%s", username);
   _putenv(User_Name);
   sprintf(PassWord, "PASSWORD=%s", password);
   _putenv(PassWord);
   if (_spawnlp(_P_WAIT, comando, comando, NULL) &&
       (errno != ENOENT) && (errno != EINVAL)) {
      printf("Error %d en pre%s.bat!\n", errno, nombre);
      exit(1);
   }
}

void dispara_paralelo(char *nombre)
{
   char comando[128];

   printf("Iniciando calculo de procesos paralelos a %s\n", nombre);
   sprintf(comando, "%s\\jobs\\par%s.bat", getenv("WAREHOME"), nombre);
   fflush(stdout);
   sprintf(User_Name, "USERNAME=%s", username);
   _putenv(User_Name);
   sprintf(PassWord, "PASSWORD=%s", password);
   _putenv(PassWord);
   if (_spawnlp(_P_NOWAIT, comando, comando, NULL) &&
       (errno != ENOENT) && (errno != EINVAL)) {
      printf("Error %d en par%s.bat!\n", errno, nombre);
      exit(1);
   }
}

void dispara_posterior(char *nombre)
{
   char comando[128];

   printf("Iniciando calculo de procesos posteriores a %s\n", nombre);
   sprintf(comando, "%s\\jobs\\pos%s.bat", getenv("WAREHOME"), nombre);
   fflush(stdout);
   sprintf(User_Name, "USERNAME=%s", username);
   _putenv(User_Name);
   sprintf(PassWord, "PASSWORD=%s", password);
   _putenv(PassWord);
   if (_spawnlp(_P_WAIT, comando, comando, NULL) &&
       (errno != ENOENT) && (errno != EINVAL)) {
      printf("Error %d en pos%s.bat!\n", errno, nombre);
      exit(1);
   }
}

/******************************
   Programa Principal
 ******************************/

void main(int argc, char *argv[])
{
   char operacao[10];
   int Trace, Limpiar, ConsTemp;

   oraca.orastxtf = ORASTFERR;
 
   switch (argc) {
      case 5:
	 if (strcmp (argv[1], "COMP"    ) && strncmp(argv[1], "CGATR", 5) &&
	     strncmp(argv[1], "CGJRQ", 5) && strncmp(argv[1], "CGDAT", 5) &&
	     strncmp(argv[1], "CCONS", 5) && strncmp(argv[1], "ACTDW", 5) &&
	     strncmp(argv[1], "CNJRQ", 5) && strncmp(argv[1], "CCOMP", 5) &&
	     strncmp(argv[1], "CNTMP", 5) && strncmp(argv[1], "LMPDW", 5) &&
	     strncmp(argv[1], "SDTDM", 5) && strncmp(argv[1], "RESET", 5) &&
	     strcmp (argv[1], "CARG"    ) && strcmp (argv[1], "WCON"    )) {
	    printf("Error: parametro %s desconocido.\n", argv[1]);
	    printf("Formato: procdw [<oper>] [<usuario> <password> <dbname>]\n");
	    printf("\noper puede ser:\n");
	    printf("\tCARG : Desde CGATR hasta CGDAT\n");
	    printf("\tWCON : De ACTDW en adelante\n");
	    printf("\tCOMP : Proceso completo (todos los seguintes)\n");
	    printf("\tCGATR: Carga de atributos y instancias de dimension\n");
	    printf("\tCGJRQ: Carga de jerarquias de dimensiones\n");
	    printf("\tCGDAT: Convalidacion y carga de datos para tablas intermedias.\n");
	    printf("\tCCONS: Calculo de indicadores consolidables\n");
	    printf("\tACTDW: Actualizacion del Data Warehouse\n");
	    printf("\tCNJRQ: Consolidacion jerarquica\n");
	    printf("\tCCOMP: Calculo de indicadores no consolidables\n");
	    printf("\tCNTMP: Consolidacion temporal\n");
	    printf("\tSDTDM: Senalizar datos nuevos para los data marts.\n");
	    printf("\tLMPDW: Limpeza del Data Warehouse\n");
	    exit(1);
	 }
	 else {
	    strcpy(operacao, argv[1]);
	    strcpy(username, argv[2]);
	    strcpy(password, argv[3]);
       strcpy(dbname,   argv[4]);
	 }
	 break;
      case 4:
         strcpy(operacao, "COMP");
         strcpy(username, argv[1]);
         strcpy(password, argv[2]);
         strcpy(dbname,   argv[3]);
         break;
      case 3:
       if (strcmp (argv[1], "COMP"    ) && strncmp(argv[1], "CGATR", 5) &&
           strncmp(argv[1], "CGJRQ", 5) && strncmp(argv[1], "CGDAT", 5) &&
           strncmp(argv[1], "CCONS", 5) && strncmp(argv[1], "ACTDW", 5) &&
           strncmp(argv[1], "CNJRQ", 5) && strncmp(argv[1], "CCOMP", 5) &&
           strncmp(argv[1], "CNTMP", 5) && strncmp(argv[1], "RESET", 5) &&
           strncmp(argv[1], "SDTDM", 5) && strncmp(argv[1], "LMPDW", 5) &&
           strcmp (argv[1], "CARG"    ) && strcmp (argv[1], "WCON"    )) {
         printf("Error: parametro %s desconocido.\n", argv[1]);
      default:
         printf("Formato: procdw [<oper>[+]] [<usuario> <password> <dbname>]\n");
         printf("\noper puede ser:\n");
         printf("\tCARG : Desde CGATR hasta CGDAT\n");
         printf("\tWCON : De ACTDW en adelante\n");
         printf("\tCOMP : Proceso completo (todos los seguintes)\n");
         printf("\tCGATR: Carga de atributos y instancias de dimension\n");
         printf("\tCGJRQ: Carga de jerarquias de dimensiones\n");
         printf("\tCGDAT: Convalidacion y carga de datos para tablas intermedias.\n");
         printf("\tCCONS: Calculo de indicadores consolidables\n");
         printf("\tACTDW: Actualizacion del Data Warehouse\n");
         printf("\tCNJRQ: Consolidacion jerarquica\n");
         printf("\tCCOMP: Calculo de indicadores no consolidables\n");
         printf("\tCNTMP: Consolidacion temporal\n");
         printf("\tSDTDM: Senalizar datos nuevos para los data marts.\n");
         printf("\tLMPDW: Limpieza del Data Warehouse\n");
         printf("\n Un '+' pegado a <oper> hace con que se haga el calculo desde la operacion\n\thasta el final.\n");
         #ifdef __DEBUG
            printf("Debug encendido\n");
         #endif
         exit(1);
	 }
	 else {
       strcpy(operacao, argv[1]);
       strcpy(username, USERNAME);
       strcpy(password, PASSWORD);
       strcpy(dbname,   "METAMODELO");
	 }
	 break;
   }
   /* EXEC SQL CONNECT :username IDENTIFIED BY :password using :dbname; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 4;
   sqlstm.iters = (unsigned long  )10;
   sqlstm.offset = (unsigned short)226;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)username;
   sqlstm.sqhstl[0] = (unsigned long  )30;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqhstv[1] = (unsigned char  *)password;
   sqlstm.sqhstl[1] = (unsigned long  )30;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqhstv[2] = (unsigned char  *)dbname;
   sqlstm.sqhstl[2] = (unsigned long  )30;
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


   printf("Inicio del procesamiento - conectado con usuario %s\n", username);

   /* EXEC SQL alter session set NLS_DATE_FORMAT = 'DD-MM-YYYY HH24:MI:SS'; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 4;
   sqlstm.stmt = "alter session set NLS_DATE_FORMAT = 'DD-MM-YYYY HH24:MI:SS\
'";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)252;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


   /* EXEC SQL alter session set OPTIMIZER_GOAL = ALL_ROWS; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 4;
   sqlstm.stmt = "alter session set OPTIMIZER_GOAL = ALL_ROWS";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)266;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


   /* EXEC SQL select sysdate into Fc_Inic_Proc from dual; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 4;
   sqlstm.stmt = "select sysdate  into :b0  from dual ";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)280;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)Fc_Inic_Proc;
   sqlstm.sqhstl[0] = (unsigned long  )20;
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


   prepara_oci();

   /************************************
    Carga de Atributos
    ************************************/

   if (!strcmp(operacao, "COMP") || !strncmp(operacao, "CGATR", 5) ||
       !strcmp(operacao, "CARG")) {
      dispara_anterior("CGATR");
      printf("Inicio de la carga de atributos.\n");
      dispara_paralelo("CGATR");
      Trace = 0;
      /* EXEC SQL select TX_VL_PARM_SIST
		  into :Trace
		  from G3_PARM_SIST
		  where NU_PARM_SIST = 4; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "select TX_VL_PARM_SIST into :b0  from G3_PARM_SIST wher\
e NU_PARM_SIST=4";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)298;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Trace;
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


      if (Trace)
	 /* EXEC SQL alter session set SQL_TRACE = TRUE; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 4;
  sqlstm.stmt = "alter session set SQL_TRACE = TRUE";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)316;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      /* EXEC SQL EXECUTE
      begin
	 update G3_PARM_SIST set TX_VL_PARM_SIST = 'I'  -- Estado Import. Instancias
	    where NU_PARM_SIST = 1;
	 commit;
	 G3_Proc_Atrb_Dimen.Importa_Atributos(1);
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "begin update G3_PARM_SIST set TX_VL_PARM_SIST = 'I' whe\
re NU_PARM_SIST = 1 ; commit ; G3_Proc_Atrb_Dimen . Importa_Atributos ( 1 ) ; \
end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)330;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Oracle error");
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      if (strcmp(operacao, "CARG") && operacao[5] == '+')
	 strcpy(operacao, "COMP");
      /* EXEC SQL alter session set SQL_TRACE = FALSE; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "alter session set SQL_TRACE = FALSE";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)344;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      dispara_posterior("CGATR");
   }

   /************************************
    Carga de Jerarquias
    ************************************/

   if (!strcmp(operacao, "COMP") || !strncmp(operacao, "CGJRQ", 5) ||
       !strcmp(operacao, "CARG")) {
      dispara_anterior("CGJRQ");
      printf("Inicio de la carga de jerarquias.\n");
      dispara_paralelo("CGJRQ");
      Trace = 0;
      /* EXEC SQL select TX_VL_PARM_SIST
		  into :Trace
		  from G3_PARM_SIST
		  where NU_PARM_SIST = 5; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "select TX_VL_PARM_SIST into :b0  from G3_PARM_SIST wher\
e NU_PARM_SIST=5";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)358;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Trace;
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


      if (Trace)
	 /* EXEC SQL alter session set SQL_TRACE = TRUE; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 4;
  sqlstm.stmt = "alter session set SQL_TRACE = TRUE";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)376;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      /* EXEC SQL EXECUTE
      begin
	 update G3_PARM_SIST set TX_VL_PARM_SIST = 'J'  -- Estado Import. Jerarquias
	    where NU_PARM_SIST = 1;
	 commit;
	 G3_Proc_Atrb_Dimen.Importa_Jerarquias(1); 
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "begin update G3_PARM_SIST set TX_VL_PARM_SIST = 'J' whe\
re NU_PARM_SIST = 1 ; commit ; G3_Proc_Atrb_Dimen . Importa_Jerarquias ( 1 ) ;\
 end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)390;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Oracle error");
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      if (strcmp(operacao, "CARG") && operacao[5] == '+')
	 strcpy(operacao, "COMP");
      /* EXEC SQL alter session set SQL_TRACE = FALSE; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "alter session set SQL_TRACE = FALSE";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)404;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      dispara_posterior("CGJRQ");
   }

   /************************************
    Carga de datos
    ************************************/

   if (!strcmp(operacao, "COMP") || !strncmp(operacao, "CGDAT", 5) ||
       !strcmp(operacao, "CARG")) {
      dispara_anterior("CGDAT");
      printf("Inicio de la importacion de datos.\n");
      dispara_paralelo("CGDAT");
      Trace = 0;
      /* EXEC SQL select TX_VL_PARM_SIST
		  into :Trace
		  from G3_PARM_SIST
		  where NU_PARM_SIST = 6; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "select TX_VL_PARM_SIST into :b0  from G3_PARM_SIST wher\
e NU_PARM_SIST=6";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)418;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Trace;
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


      if (Trace)
	 /* EXEC SQL alter session set SQL_TRACE = TRUE; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 4;
  sqlstm.stmt = "alter session set SQL_TRACE = TRUE";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)436;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      /* EXEC SQL EXECUTE
      begin
	 update G3_PARM_SIST set TX_VL_PARM_SIST = 'D'  -- Estado Import. Datos
	    where NU_PARM_SIST = 1;
	 commit;
	 G3_Log_Err.Inic_Log('CGDAT');
	 for r_fontes in (
	    select NU_FUENTE_INDCA_PERFM
	       from G3_FUENTE_INDCA_PERFM
	       where NU_PERFIL_RESP_FUENTE_INDCA = 1) loop
	    Importa_Datos.Traduce_Claves(1, 1, r_fontes.NU_FUENTE_INDCA_PERFM);
	 end loop;
	 G3_Log_Err.Termina_Log;
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "begin update G3_PARM_SIST set TX_VL_PARM_SIST = 'D' whe\
re NU_PARM_SIST = 1 ; commit ; G3_Log_Err . Inic_Log ( 'CGDAT' ) ; for r_fonte\
s in ( select NU_FUENTE_INDCA_PERFM from G3_FUENTE_INDCA_PERFM where NU_PERFIL\
_RESP_FUENTE_INDCA = 1 ) loop Importa_Datos . Traduce_Claves ( 1 , 1 , r_fonte\
s . NU_FUENTE_INDCA_PERFM ) ; end loop ; G3_Log_Err . Termina_Log ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)450;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Oracle error");
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      if (strcmp(operacao, "CARG") && operacao[5] == '+')
	 strcpy(operacao, "COMP");
      /* EXEC SQL alter session set SQL_TRACE = FALSE; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "alter session set SQL_TRACE = FALSE";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)464;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      dispara_posterior("CGDAT");
   }

   if (!strcmp(operacao, "WCON"))
	strcpy(operacao, "COMP");

   /************************************
    Actualizacion del Data Warehouse por los datos en movimiento
    ************************************/

   if (!strcmp(operacao, "COMP") || !strncmp(operacao, "ACTDW", 5)) {
      dispara_anterior("ACTDW");
      printf("Inicio de la distribuicion de los datos.\n");
      dispara_paralelo("ACTDW");
      Trace = 0;
      /* EXEC SQL select TX_VL_PARM_SIST
		  into :Trace
		  from G3_PARM_SIST
		  where NU_PARM_SIST = 8; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "select TX_VL_PARM_SIST into :b0  from G3_PARM_SIST wher\
e NU_PARM_SIST=8";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)478;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Trace;
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


      if (Trace)
	 /* EXEC SQL alter session set SQL_TRACE = TRUE; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 4;
  sqlstm.stmt = "alter session set SQL_TRACE = TRUE";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)496;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      /* EXEC SQL EXECUTE
      begin
	 update G3_PARM_SIST set TX_VL_PARM_SIST = 'W'  -- Estado Transf. DW
	    where NU_PARM_SIST = 1;
	 commit;
	 G3_Log_Err.Inic_Log('ACTDW');
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "begin update G3_PARM_SIST set TX_VL_PARM_SIST = 'W' whe\
re NU_PARM_SIST = 1 ; commit ; G3_Log_Err . Inic_Log ( 'ACTDW' ) ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)510;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Oracle error");
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      prepara_oci();
      if (operacao[5] == '+')
	 strcpy(operacao, "COMP");
      if (!strcmp(operacao, "COMP"))
	 atualiza_dw(1);
      else
	 atualiza_dw(0);
      /* EXEC SQL EXECUTE
      begin
	 G3_Log_Err.Termina_Log;
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "begin G3_Log_Err . Termina_Log ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)524;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Oracle error");
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      /* EXEC SQL alter session set SQL_TRACE = FALSE; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "alter session set SQL_TRACE = FALSE";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)538;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      dispara_posterior("ACTDW");
   }

   /************************************
    Calculo de Indicadores del tipo Calculate/Consolidate
    ************************************/
   
   if (!strcmp(operacao, "COMP") || !strncmp(operacao, "CCONS", 5)) {
      dispara_anterior("CCONS");
      printf("Inicio del calculo de indicadores consolidables.\n");
      dispara_paralelo("CCONS");
      Trace = 0;
      /* EXEC SQL select TX_VL_PARM_SIST
		  into :Trace
		  from G3_PARM_SIST
		  where NU_PARM_SIST = 7; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "select TX_VL_PARM_SIST into :b0  from G3_PARM_SIST wher\
e NU_PARM_SIST=7";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)552;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Trace;
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


      if (Trace)
	 /* EXEC SQL alter session set SQL_TRACE = TRUE; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 4;
  sqlstm.stmt = "alter session set SQL_TRACE = TRUE";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)570;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      /* EXEC SQL EXECUTE 
      begin
	 update G3_PARM_SIST set TX_VL_PARM_SIST = 'A'  -- Estado Calculate/Consolidate
	    where NU_PARM_SIST = 1;
	 commit;
	 G3_Log_Err.Inic_Log('CCONS');
	 G3_Log_Err.Log_Msj('D', 'Inicio del calculo de indicadores consolidables.');
	 commit;
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "begin update G3_PARM_SIST set TX_VL_PARM_SIST = 'A' whe\
re NU_PARM_SIST = 1 ; commit ; G3_Log_Err . Inic_Log ( 'CCONS' ) ; G3_Log_Err \
. Log_Msj ( 'D' , 'Inicio del calculo de indicadores consolidables.' ) ; commi\
t ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)584;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Oracle error");
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      calcula_indicadores("CC");
      /* EXEC SQL EXECUTE
      begin
	 G3_Log_Err.Log_Msj('D', 'Fin del calculo de indicadores consolidables.');
	 G3_Log_Err.Termina_Log;
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "begin G3_Log_Err . Log_Msj ( 'D' , 'Fin del calculo de \
indicadores consolidables.' ) ; G3_Log_Err . Termina_Log ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)598;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Oracle error");
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      if (operacao[5] == '+')
	 strcpy(operacao, "COMP");
      /* EXEC SQL alter session set SQL_TRACE = FALSE; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "alter session set SQL_TRACE = FALSE";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)612;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      dispara_posterior("CCONS");
   }
   
   /**************************************
    Consolidacion Jerarquica
    **************************************/
  
  if (!strcmp(operacao, "COMP") || !strncmp(operacao, "CNJRQ", 5)) {
      dispara_anterior("CNJRQ");
      printf("Inicio de la consolidacion jerarquica.\n");
      dispara_paralelo("CNJRQ");
      Trace = 0;
      /* EXEC SQL select TX_VL_PARM_SIST
		  into :Trace
		  from G3_PARM_SIST
		  where NU_PARM_SIST = 9; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "select TX_VL_PARM_SIST into :b0  from G3_PARM_SIST wher\
e NU_PARM_SIST=9";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)626;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Trace;
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


      if (Trace)
	 /* EXEC SQL alter session set SQL_TRACE = TRUE; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 4;
  sqlstm.stmt = "alter session set SQL_TRACE = TRUE";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)644;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      /* EXEC SQL EXECUTE
      begin
	 update G3_PARM_SIST set TX_VL_PARM_SIST = 'C'   -- Estado Cons. Jerarq.
	    where NU_PARM_SIST = 1;
	 commit;
	 G3_Log_Err.Inic_Log('CNJRQ');
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "begin update G3_PARM_SIST set TX_VL_PARM_SIST = 'C' whe\
re NU_PARM_SIST = 1 ; commit ; G3_Log_Err . Inic_Log ( 'CNJRQ' ) ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)658;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Oracle error");
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      prepara_oci();
      cons_jerarq();
      /* EXEC SQL EXECUTE
      begin
	 G3_Log_Err.Termina_Log;
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "begin G3_Log_Err . Termina_Log ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)672;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Oracle error");
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      if (operacao[5] == '+')
	 strcpy(operacao, "COMP");
      /* EXEC SQL alter session set SQL_TRACE = FALSE; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "alter session set SQL_TRACE = FALSE";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)686;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      dispara_posterior("CNJRQ");
   }

   /************************************
    Calculo de Indicadores del tipo Calculate Full
    ************************************/
   if (!strcmp(operacao, "COMP") || !strncmp(operacao, "CCOMP", 5)) {
      dispara_anterior("CCOMP");
      printf("Inicio del calculo de indicadores no consolidables.\n");
      dispara_paralelo("CCOMP");
      Trace = 0;
      /* EXEC SQL select TX_VL_PARM_SIST
		  into :Trace
		  from G3_PARM_SIST
		  where NU_PARM_SIST = 10; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "select TX_VL_PARM_SIST into :b0  from G3_PARM_SIST wher\
e NU_PARM_SIST=10";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)700;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Trace;
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


      if (Trace)
	 /* EXEC SQL alter session set SQL_TRACE = TRUE; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 4;
  sqlstm.stmt = "alter session set SQL_TRACE = TRUE";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)718;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      /* EXEC SQL EXECUTE
      begin
	 update G3_PARM_SIST set TX_VL_PARM_SIST = 'F'  -- Estado Calculate Full
	    where NU_PARM_SIST = 1;
	 commit;
	 G3_Log_Err.Inic_Log('CCOMP');
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "begin update G3_PARM_SIST set TX_VL_PARM_SIST = 'F' whe\
re NU_PARM_SIST = 1 ; commit ; G3_Log_Err . Inic_Log ( 'CCOMP' ) ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)732;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Oracle error");
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      calcula_indicadores("CF");
      /* EXEC SQL EXECUTE
      begin
	 G3_Log_Err.Termina_Log;
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "begin G3_Log_Err . Termina_Log ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)746;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Oracle error");
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      if (operacao[5] == '+')
	 strcpy(operacao, "COMP");
      /* EXEC SQL alter session set SQL_TRACE = FALSE; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "alter session set SQL_TRACE = FALSE";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)760;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      dispara_posterior("CCOMP");
   }

   /**************************************
    Consolidacion Temporal
    **************************************/

   if (!strcmp(operacao, "COMP") || !strncmp(operacao, "CNTMP", 5)) {
      /* EXEC SQL select TX_VL_PARM_SIST
		  into :ConsTemp
		  from G3_PARM_SIST
		  where NU_PARM_SIST = 51; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "select TX_VL_PARM_SIST into :b0  from G3_PARM_SIST wher\
e NU_PARM_SIST=51";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)774;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&ConsTemp;
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


      if (ConsTemp) {
	 if (!strcmp(operacao, "CNTMP"))
	    prepara_oci();
	 dispara_anterior("CNTMP");
	 printf("Inicio de la consolidacion temporal.\n");
	 dispara_paralelo("CNTMP");
	 Trace = 0;
	 /* EXEC SQL select TX_VL_PARM_SIST
		     into :Trace
		     from G3_PARM_SIST
		     where NU_PARM_SIST = 11; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 4;
  sqlstm.stmt = "select TX_VL_PARM_SIST into :b0  from G3_PARM_SIST where NU\
_PARM_SIST=11";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)792;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (unsigned char  *)&Trace;
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


	 if (Trace)
	    /* EXEC SQL alter session set SQL_TRACE = TRUE; */ 

{
     struct sqlexd sqlstm;

     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 8;
     sqlstm.arrsiz = 4;
     sqlstm.stmt = "alter session set SQL_TRACE = TRUE";
     sqlstm.iters = (unsigned long  )1;
     sqlstm.offset = (unsigned short)810;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


	 /* EXEC SQL EXECUTE
	 begin
	    update G3_PARM_SIST set TX_VL_PARM_SIST = 'T'  -- Estado Cons. Temporal
	       where NU_PARM_SIST = 1;
	    commit;
	    G3_Log_Err.Inic_Log('CNTMP');
	 end;
	 END-EXEC; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 4;
  sqlstm.stmt = "begin update G3_PARM_SIST set TX_VL_PARM_SIST = 'T' where N\
U_PARM_SIST = 1 ; commit ; G3_Log_Err . Inic_Log ( 'CNTMP' ) ; end ;";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)824;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) sql_error("Oracle error");
  if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


	 cons_temporal();
	 /* EXEC SQL EXECUTE
	 begin
	    G3_Log_Err.Termina_Log;
	 end;
	 END-EXEC; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 4;
  sqlstm.stmt = "begin G3_Log_Err . Termina_Log ; end ;";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)838;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) sql_error("Oracle error");
  if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


	 if (operacao[5] == '+')
	    strcpy(operacao, "COMP");
	 /* EXEC SQL alter session set SQL_TRACE = FALSE; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 4;
  sqlstm.stmt = "alter session set SQL_TRACE = FALSE";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)852;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


	 dispara_posterior("CNTMP");
      }
   }

   /**************************************
    Senalizando los nuevos datos para los data marts
    **************************************/

   if (!strcmp(operacao, "COMP") || !strncmp(operacao, "SDTDM", 5)) {
      dispara_anterior("SDTDM");
      dispara_paralelo("SDTDM");
      Trace = 0;
      /* EXEC SQL select TX_VL_PARM_SIST
		  into :Trace
		  from G3_PARM_SIST
		  where NU_PARM_SIST = 14; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "select TX_VL_PARM_SIST into :b0  from G3_PARM_SIST wher\
e NU_PARM_SIST=14";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)866;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Trace;
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


      if (Trace)
	 /* EXEC SQL alter session set SQL_TRACE = TRUE; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 4;
  sqlstm.stmt = "alter session set SQL_TRACE = TRUE";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)884;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      /* EXEC SQL EXECUTE
      begin
	 update G3_PARM_SIST set TX_VL_PARM_SIST = 'M'  -- Estado Transferencia a los data marts
	    where NU_PARM_SIST = 1;
	 commit;
	 G3_Log_Err.Inic_Log('SDTDM');
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "begin update G3_PARM_SIST set TX_VL_PARM_SIST = 'M' whe\
re NU_PARM_SIST = 1 ; commit ; G3_Log_Err . Inic_Log ( 'SDTDM' ) ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)898;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Oracle error");
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}



      /* EXEC SQL EXECUTE
      begin
	 G3_Log_Err.Termina_Log;
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "begin G3_Log_Err . Termina_Log ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)912;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Oracle error");
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      /* EXEC SQL alter session set SQL_TRACE = FALSE; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "alter session set SQL_TRACE = FALSE";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)926;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      if (operacao[5] == '+')
	 strcpy(operacao, "COMP");
      dispara_posterior("SDTDM");
   }

   /**************************************
    Limpiando el Data Warehouse de los datos viejos
    **************************************/

   if (!strcmp(operacao, "COMP") || !strncmp(operacao, "LMPDW", 5)) {
      dispara_anterior("LMPDW");
      dispara_paralelo("LMPDW");
      Trace = 0;
      /* EXEC SQL select TX_VL_PARM_SIST
		  into :Trace
		  from G3_PARM_SIST
		  where NU_PARM_SIST = 12; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "select TX_VL_PARM_SIST into :b0  from G3_PARM_SIST wher\
e NU_PARM_SIST=12";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)940;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Trace;
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


      if (Trace)
	 /* EXEC SQL alter session set SQL_TRACE = TRUE; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 4;
  sqlstm.stmt = "alter session set SQL_TRACE = TRUE";
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)958;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Oracle error");
}



      /* EXEC SQL EXECUTE
      begin
	 update G3_PARM_SIST set TX_VL_PARM_SIST = 'L'  -- Estado Limpieza Data Warehouse
	    where NU_PARM_SIST = 1;
	 commit;
	 G3_Log_Err.Inic_Log('LMPDW');
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "begin update G3_PARM_SIST set TX_VL_PARM_SIST = 'L' whe\
re NU_PARM_SIST = 1 ; commit ; G3_Log_Err . Inic_Log ( 'LMPDW' ) ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)972;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Oracle error");
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      /* EXEC SQL select TX_VL_PARM_SIST
		  into :Limpiar
		  from G3_PARM_SIST
		  where NU_PARM_SIST = 13; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "select TX_VL_PARM_SIST into :b0  from G3_PARM_SIST wher\
e NU_PARM_SIST=13";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)986;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Limpiar;
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


      limpa_log();

      if (Limpiar)
	 limpa_dw();

      /* EXEC SQL EXECUTE
      begin
	 G3_Log_Err.Termina_Log;
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "begin G3_Log_Err . Termina_Log ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)1004;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Oracle error");
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      /* EXEC SQL alter session set SQL_TRACE = FALSE; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 4;
      sqlstm.stmt = "alter session set SQL_TRACE = FALSE";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)1018;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      if (operacao[5] == '+')
	 strcpy(operacao, "COMP");
      dispara_posterior("LMPDW");
   }

   if (!strcmp(operacao, "RESET")) {
      dispara_anterior("RESET");
      dispara_paralelo("RESET");
      strcpy(operacao, "COMP");
      dispara_posterior("RESET");
   }

   if (!strcmp(operacao, "COMP"))
      Cierra_DW(1);
   else
      Cierra_DW(0);
   printf("Fin del procesamiento - desconectando.\n");
   libera_oci();
   /* EXEC SQL COMMIT WORK RELEASE; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 4;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)1032;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Oracle error");
}



   exit(0);
}
