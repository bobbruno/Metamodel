
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
           char  filnam[11];
};
static const struct sqlcxp sqlfpn =
{
    10,
    ".\\lmpdw.pc"
};


static const unsigned long sqlctx = 880600612;


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
   unsigned char    *sqhstv[8];
   unsigned long    sqhstl[8];
	    short   *sqindv[8];
   unsigned long    sqharm[8];
   unsigned long     *sqharc[8];
} sqlstm = {8,8};

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
"select NU_INDCA_PERFM ,NU_VISION ,nvl(CT_DIAS_PERM_INDCA_PERFM,0) ,nvl(CT_SE\
M_PERM_INDCA_PERFM,0) ,nvl(CT_MESES_PERM_INDCA_PERFM,0) ,nvl(CT_ANOS_PERM_INDC\
A_PERFM,0)  from G3_INDCA_PERFM  order by NU_INDCA_PERFM            ";
 static const char *sq0005 = 
"select T.NM_TABLA_SH ,to_number(to_char(T.FC_MIN_TABLA_SH,'J'))  from G3_TAB\
LA_SH T ,G3_TABLA_SH_VISION V where (T.NU_TABLA_SH=V.NU_TABLA_SH and V.NU_VISI\
ON=:b0)           ";
typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{8,4130,
2,0,0,1,72,0,4,50,0,1,0,0,1,0,2,3,0,0,
20,0,0,2,221,0,6,57,0,1,1,0,1,0,1,3,0,0,
38,0,0,3,222,0,9,87,0,0,0,0,1,0,
52,0,0,3,0,0,13,91,0,6,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
90,0,0,4,521,0,6,94,0,8,8,0,1,0,1,3,0,0,2,3,0,0,1,3,0,0,2,3,0,0,1,3,0,0,2,3,0,
0,1,3,0,0,2,3,0,0,
136,0,0,5,172,0,9,125,0,1,1,0,1,0,1,3,0,0,
154,0,0,5,0,0,13,128,0,2,0,0,1,0,2,9,0,0,2,3,0,0,
176,0,0,6,0,0,24,139,0,1,1,0,1,0,1,97,0,0,
194,0,0,7,0,0,24,146,0,1,1,0,1,0,1,97,0,0,
212,0,0,8,0,0,24,153,0,1,1,0,1,0,1,97,0,0,
230,0,0,9,0,0,24,160,0,1,1,0,1,0,1,97,0,0,
248,0,0,10,0,0,29,162,0,0,0,0,1,0,
};


/*****************************************************************************
 *                                                                           *
 *                   ACTUALIZACION DEL DATA WAREHOUSE                        *
 *    Limpieza de datos del Data Warehouse. Borra de las tablas de serie     *
 *    historica los valores para cada indicador en acuerdo con sus           *
 *    parametros de historico en G3_INDCA_PERFM (CT_xxx_PERM_INDCA_PERFM).   *
 *                                                                           *
 *                                                                           *
 *  Desarrollado por Roberto Bruno Martins - Price Waterhouse                *
 *  en 10/1996.                                                              *
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


static char delete_command[] = "declare\n"
			       "   l_dummy char(1);\n"
			       "begin\n"
			       "   select /*+ INDEX(S) */ 'x' into l_dummy\n"
			       "      from %s S\n"
			       "      where NU_INDCA_PERFM = %d and\n"
			       "            NU_VISION = %d and\n"
			       "            CD_GRNL_SERIE_HIST = '%c' and\n"
			       "            FC_REFR_SERIE_HIST < to_date(%d, 'J') and\n"
			       "            ROWNUM = 1;\n"
			       "   G3_Log_Err.Log_Msj('D', 'Borrando indicador %d antes de ' ||\n"
			       "      to_date(%d, 'J'));\n"
			       "   delete from %s where NU_INDCA_PERFM = %d and\n"
			       "            NU_VISION = %d and\n"
			       "            CD_GRNL_SERIE_HIST = '%c' and\n"
			       "            FC_REFR_SERIE_HIST < to_date(%d, 'J');\n"
			       "exception\n"
			       "   when NO_DATA_FOUND then\n"
			       "      NULL;\n"
			       "end;";
void limpa_log()
{
   int Limpar;

   /* EXEC SQL whenever SQLERROR do sql_error("Oracle error"); */ 


   /* EXEC SQL
      select TX_VL_PARM_SIST into :Limpar
         from G3_PARM_SIST
         where NU_PARM_SIST = 15; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 1;
   sqlstm.stmt = "select TX_VL_PARM_SIST into :b0  from G3_PARM_SIST where N\
U_PARM_SIST=15";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)2;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)&Limpar;
   sqlstm.sqhstl[0] = (unsigned long  )4;
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



   if (Limpar) {
      Paso_Esencial = 0;
      /* EXEC SQL EXECUTE
      begin
	 G3_Log_Err.Log_Msj('D', 'Borrando log de errores antes de ' || trunc(sysdate - :Limpar, 'MONTH'));
	 delete from G3_LOG_ERROR
	    where FC_INICIO_LOG_ERROR < trunc(sysdate - :Limpar, 'MONTH');
	 commit;
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 1;
      sqlstm.stmt = "begin G3_Log_Err . Log_Msj ( 'D' , 'Borrando log de err\
ores antes de ' || trunc ( sysdate -:Limpar , 'MONTH' ) ) ; delete from G3_LOG\
_ERROR where FC_INICIO_LOG_ERROR < trunc ( sysdate -:Limpar , 'MONTH' ) ; comm\
it ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)20;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Limpar;
      sqlstm.sqhstl[0] = (unsigned long  )4;
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


      Paso_Esencial = 1;
   }
}

void limpa_dw()
{
   char buf_delete[2048];
   /* VARCHAR Tabla[40]; */ 
struct { unsigned short len; unsigned char arr[40]; } Tabla;

   int FcMin, FcDias, FcSemanas, FcMeses, FcAnos;
   int Indca, Vision, Dias, Semanas, Meses, Anos;

   /* EXEC SQL whenever SQLERROR do sql_error("Oracle error"); */ 



   /* Para cada indicador en el Data Warehouse */
   /* EXEC sql declare c_indca cursor for
      select NU_INDCA_PERFM, NU_VISION, nvl(CT_DIAS_PERM_INDCA_PERFM, 0),
	     nvl(CT_SEM_PERM_INDCA_PERFM, 0), nvl(CT_MESES_PERM_INDCA_PERFM, 0),
	     nvl(CT_ANOS_PERM_INDCA_PERFM, 0)
	 from G3_INDCA_PERFM
	 order by NU_INDCA_PERFM; */ 


   /* EXEC SQL open c_indca; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 1;
   sqlstm.stmt = sq0003;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)38;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Oracle error");
}



   /* EXEC SQL whenever NOT FOUND do break; */ 

   for (;;) {
      /* EXEC SQL fetch c_indca into :Indca, :Vision,
	       :Dias, :Semanas, :Meses, :Anos; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 6;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)52;
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
      sqlstm.sqhstv[2] = (unsigned char  *)&Dias;
      sqlstm.sqhstl[2] = (unsigned long  )4;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&Semanas;
      sqlstm.sqhstl[3] = (unsigned long  )4;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&Meses;
      sqlstm.sqhstl[4] = (unsigned long  )4;
      sqlstm.sqindv[4] = (         short *)0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqhstv[5] = (unsigned char  *)&Anos;
      sqlstm.sqhstl[5] = (unsigned long  )4;
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


      
      /* EXEC SQL EXECUTE
      declare
	 Ahora DATE;
      begin
	 Ahora:= sysdate;
	 if :Dias != 0 then
	    :FcDias:= to_number(to_char(trunc(Ahora) - :Dias, 'J'));
	 end if;

	 if :Semanas != 0 then
	    :FcSemanas:= to_number(to_char((trunc(Ahora, 'DAY') - 7 * :Semanas), 'J'));
	 end if;

	 if :Meses != 0 then
	    :FcMeses:= to_number(to_char(add_months(trunc(Ahora, 'MONTH') , - :Meses), 'J'));
	 end if;

	 if :Anos != 0 then
	    :FcAnos:= to_number(to_char(add_months(trunc(Ahora, 'YEAR'), -12 * :Anos), 'J'));
	 end if;
      end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 8;
      sqlstm.stmt = "declare Ahora DATE ; begin Ahora := sysdate ; if :Dias \
!= 0 then :FcDias := to_number ( to_char ( trunc ( Ahora ) -:Dias , 'J' ) ) ; \
end if ; if :Semanas != 0 then :FcSemanas := to_number ( to_char ( ( trunc ( A\
hora , 'DAY' ) -7 * :Semanas ) , 'J' ) ) ; end if ; if :Meses != 0 then :FcMes\
es := to_number ( to_char ( add_months ( trunc ( Ahora , 'MONTH' ) , -:Meses )\
 , 'J' ) ) ; end if ; if :Anos != 0 then :FcAnos := to_number ( to_char ( add_\
months ( trunc ( Ahora , 'YEAR' ) , -12 * :Anos ) , 'J' ) ) ; end if ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)90;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Dias;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&FcDias;
      sqlstm.sqhstl[1] = (unsigned long  )4;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&Semanas;
      sqlstm.sqhstl[2] = (unsigned long  )4;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&FcSemanas;
      sqlstm.sqhstl[3] = (unsigned long  )4;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&Meses;
      sqlstm.sqhstl[4] = (unsigned long  )4;
      sqlstm.sqindv[4] = (         short *)0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqhstv[5] = (unsigned char  *)&FcMeses;
      sqlstm.sqhstl[5] = (unsigned long  )4;
      sqlstm.sqindv[5] = (         short *)0;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqhstv[6] = (unsigned char  *)&Anos;
      sqlstm.sqhstl[6] = (unsigned long  )4;
      sqlstm.sqindv[6] = (         short *)0;
      sqlstm.sqharm[6] = (unsigned long )0;
      sqlstm.sqhstv[7] = (unsigned char  *)&FcAnos;
      sqlstm.sqhstl[7] = (unsigned long  )4;
      sqlstm.sqindv[7] = (         short *)0;
      sqlstm.sqharm[7] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) break;
      if (sqlca.sqlcode < 0) sql_error("Oracle error");
}



      /* Para cada tabla donde es posible haver datos para este indicador */
      /* EXEC SQL declare c_tablas cursor for
	 select T.NM_TABLA_SH, to_number(to_char(T.FC_MIN_TABLA_SH, 'J'))
	    from G3_TABLA_SH T,
		 G3_TABLA_SH_VISION V
	    where T.NU_TABLA_SH = V.NU_TABLA_SH and
		  V.NU_VISION = :Vision; */ 


      /* EXEC SQL open c_tablas; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 8;
      sqlstm.stmt = sq0005;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)136;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Vision;
      sqlstm.sqhstl[0] = (unsigned long  )4;
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



      for (;;) {
	 /* EXEC SQL fetch c_tablas into :Tabla, :FcMin; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 8;
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)154;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlstm.sqhstv[0] = (unsigned char  *)&Tabla;
  sqlstm.sqhstl[0] = (unsigned long  )42;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&FcMin;
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
  if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


	 Tabla.arr[Tabla.len] = 0;

#ifdef __DEBUG
	 printf(delete_command, Tabla.arr, Indca, Vision,
		  'D', FcDias, Indca, FcDias, Tabla.arr, Indca, Vision, 'D', FcDias);
#endif
	 /* Borrando datos diarios */
	 if ((Dias) && (FcDias >= FcMin)) {
	    sprintf(buf_delete, delete_command, Tabla.arr, Indca, Vision,
		     'D', FcDias, Indca, FcDias, Tabla.arr, Indca, Vision, 'D', FcDias);
	    /* EXEC SQL execute immediate :buf_delete; */ 

{
     struct sqlexd sqlstm;

     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 8;
     sqlstm.arrsiz = 8;
     sqlstm.stmt = "";
     sqlstm.iters = (unsigned long  )1;
     sqlstm.offset = (unsigned short)176;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)0;
     sqlstm.sqhstv[0] = (unsigned char  *)buf_delete;
     sqlstm.sqhstl[0] = (unsigned long  )2048;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode == 1403) break;
     if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


	 }

	 /* Borrando datos semanales */
	 if ((Semanas) && (FcSemanas >= FcMin)) {
	    sprintf(buf_delete, delete_command, Tabla.arr, Indca, Vision,
		     'S', FcSemanas, Indca, FcSemanas, Tabla.arr, Indca, Vision, 'S', FcSemanas);
	    /* EXEC SQL execute immediate :buf_delete; */ 

{
     struct sqlexd sqlstm;

     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 8;
     sqlstm.arrsiz = 8;
     sqlstm.stmt = "";
     sqlstm.iters = (unsigned long  )1;
     sqlstm.offset = (unsigned short)194;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)0;
     sqlstm.sqhstv[0] = (unsigned char  *)buf_delete;
     sqlstm.sqhstl[0] = (unsigned long  )2048;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode == 1403) break;
     if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


	 }

	 /* Borrando datos mensuales */
	 if ((Meses) && (FcMeses >= FcMin)) {
	    sprintf(buf_delete, delete_command, Tabla.arr, Indca, Vision,
		     'M', FcMeses, Indca, FcMeses, Tabla.arr, Indca, Vision, 'M', FcMeses);
	    /* EXEC SQL execute immediate :buf_delete; */ 

{
     struct sqlexd sqlstm;

     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 8;
     sqlstm.arrsiz = 8;
     sqlstm.stmt = "";
     sqlstm.iters = (unsigned long  )1;
     sqlstm.offset = (unsigned short)212;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)0;
     sqlstm.sqhstv[0] = (unsigned char  *)buf_delete;
     sqlstm.sqhstl[0] = (unsigned long  )2048;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode == 1403) break;
     if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


	 }

	 /* Borrando datos anuales */
	 if ((Anos) && (FcAnos >= FcMin)) {
	    sprintf(buf_delete, delete_command, Tabla.arr, Indca, Vision,
		     'A', FcAnos, Indca, FcAnos, Tabla.arr, Indca, Vision, 'A', FcAnos);
	    /* EXEC SQL execute immediate :buf_delete; */ 

{
     struct sqlexd sqlstm;

     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 8;
     sqlstm.arrsiz = 8;
     sqlstm.stmt = "";
     sqlstm.iters = (unsigned long  )1;
     sqlstm.offset = (unsigned short)230;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)0;
     sqlstm.sqhstv[0] = (unsigned char  *)buf_delete;
     sqlstm.sqhstl[0] = (unsigned long  )2048;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode == 1403) break;
     if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


	 }
	 /* EXEC SQL commit; */ 

{
  struct sqlexd sqlstm;

  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 8;
  sqlstm.arrsiz = 8;
  sqlstm.iters = (unsigned long  )1;
  sqlstm.offset = (unsigned short)248;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Oracle error");
}


      }
   }
}
