
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
    ".\\dw_aux.pc"
};


static const unsigned long sqlctx = 882203115;


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
   unsigned char    *sqhstv[17];
   unsigned long    sqhstl[17];
	    short   *sqindv[17];
   unsigned long    sqharm[17];
   unsigned long     *sqharc[17];
} sqlstm = {8,17};

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

 static const char *sq0014 = 
"select NM_TABLA_SH ,FC_MIN_TABLA_SH ,FC_MAX_TABLA_SH ,NU_DIMEN_TABLA_SH ,NU_\
NIVL_LOGC_MIN ,NU_NIVL_LOGC_MAX  from G3_TABLA_SH  order by NU_TABLA_SH       \
     ";
 static const char *sq0015 = 
"select NU_VISION ,count(*)   from G3_TABLA_SH_VISION  group by NU_VISION    \
       ";
 static const char *sq0016 = 
"select NU_TABLA_SH  from G3_TABLA_SH_VISION where NU_VISION=:b0           ";
typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{8,4130,
2,0,0,1,54,0,6,55,0,1,1,0,1,0,1,97,0,0,
20,0,0,2,54,0,6,72,0,0,0,0,1,0,
34,0,0,3,0,0,32,78,0,0,0,0,1,0,
48,0,0,4,54,0,6,84,0,0,0,0,1,0,
62,0,0,5,0,0,32,90,0,0,0,0,1,0,
76,0,0,6,139,0,4,155,0,3,2,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,
102,0,0,7,139,0,4,199,0,3,2,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,
128,0,0,8,332,0,4,288,0,17,1,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,
0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
3,0,0,1,3,0,0,
210,0,0,9,0,0,31,416,0,0,0,0,1,0,
224,0,0,10,107,0,6,417,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
246,0,0,11,0,0,32,425,0,0,0,0,1,0,
260,0,0,12,44,0,4,447,0,1,0,0,1,0,2,3,0,0,
278,0,0,13,54,0,4,451,0,1,0,0,1,0,2,3,0,0,
296,0,0,14,159,0,9,472,0,0,0,0,1,0,
310,0,0,14,0,0,13,475,0,6,0,0,1,0,2,9,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,
3,0,0,
348,0,0,14,0,0,15,501,0,0,0,0,1,0,
362,0,0,15,83,0,9,509,0,0,0,0,1,0,
376,0,0,15,0,0,13,512,0,2,0,0,1,0,2,3,0,0,2,3,0,0,
398,0,0,16,74,0,9,523,0,1,1,0,1,0,1,3,0,0,
416,0,0,16,0,0,13,526,0,1,0,0,1,0,2,3,0,0,
434,0,0,16,0,0,15,531,0,0,0,0,1,0,
448,0,0,15,0,0,15,533,0,0,0,0,1,0,
462,0,0,17,46,0,4,536,0,1,0,0,1,0,2,9,0,0,
480,0,0,18,57,0,4,546,0,1,0,0,1,0,2,3,0,0,
498,0,0,19,119,0,6,603,0,0,0,0,1,0,
512,0,0,20,219,0,4,728,0,8,4,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,1,3,0,0,
558,0,0,21,645,0,6,752,0,8,8,0,1,0,1,3,0,0,3,3,0,0,3,97,0,0,1,97,0,0,3,97,0,0,
1,97,0,0,3,97,0,0,1,3,0,0,
};


#define __GRABA_REG_C
#ifndef ORA_PROC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

#include <sqlca.h>
#include <oraca.h>
#include <ocidfn.h>
#include <ociapr.h>
#include <sqlproto.h>
#include "dw_aux.h"
/* EXEC ORACLE OPTION (ORACA=YES); */ 


char username[30], password[30];
char Paso_Esencial = 1;
int  base = BASE;

extern T_TABLA_SH *Tablas_Serie;  /* Vector de tablas de serie historica */
extern T_TABLA_VISION *Tablas_Vision; /* Vector de pointers a las tablas por Vision */

void NmTabSH(const char *, int, T_NIVEL *, char *);

/*****************************************************************************
  Rutina de Tratamento de Errores

  Si el error es grave o la variable Paso_Esencial contiene 1, genera un error
  y aborta la aplicacion. Si las dos condiciones arriba son falsas, genera
  un log de error y un mensaje a la pantalla, volviendo en seguida.
 *****************************************************************************/

void sql_error(char *msg)
{
   char temp_txt[1024], mesg[100], long_msg[515];
#ifndef ORA_PROC
   size_t
#else
   int
#endif
   tamlong = 512, tammsg;

   /* Disable ORACLE error checking to avoid an infinite loop
      should another error occur within this routine  */
   /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

   sprintf(temp_txt, "%s\n", msg);
   sqlglm(long_msg, &tamlong, &tammsg);
   strncat(temp_txt, long_msg, tammsg);
   sprintf(mesg, "En la linea %d de %.*s.\n", 
        oraca.oraslnr, oraca.orasfnm.orasfnml, oraca.orasfnm.orasfnmc);
   strcat(temp_txt, mesg);
   printf("\n%s", temp_txt);
   fprintf(stderr, "\n%s", temp_txt);

   /* EXEC SQL EXECUTE
      begin
	 G3_Log_Err.Log_Msj('E', :temp_txt);
      end;
   END-EXEC; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 1;
   sqlstm.stmt = "begin G3_Log_Err . Log_Msj ( 'E' , :temp_txt ) ; end ;";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)2;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)temp_txt;
   sqlstm.sqhstl[0] = (unsigned long  )1024;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



   if (!Paso_Esencial)
      switch (-sqlca.sqlcode) {
	 case 1:
	 case 54:
	 case 69:
	 case -100:
	 case 1403:
	 case 0: return;
	 default:
	    libera_oci();
	    /* Roll back any pending changes and disconnect from Oracle. */
	    /* EXEC SQL EXECUTE
	       begin
		  rollback work;
		  G3_Log_Err.Termina_Log;
	       end;
	    END-EXEC; */ 

{
     struct sqlexd sqlstm;

     sqlorat((void **)0, &sqlctx, &oraca);
     sqlstm.sqlvsn = 8;
     sqlstm.arrsiz = 1;
     sqlstm.stmt = "begin rollback work ; G3_Log_Err . Termina_Log ; end ;";
     sqlstm.iters = (unsigned long  )1;
     sqlstm.offset = (unsigned short)20;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	    /* EXEC SQL ROLLBACK WORK RELEASE; */ 

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
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	    exit(sqlca.sqlcode);
      }
   else {
      libera_oci();
      /* Roll back any pending changes and disconnect from Oracle. */
      /* EXEC SQL EXECUTE
	 begin
	    rollback work;
	    G3_Log_Err.Termina_Log;
	 end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 1;
      sqlstm.stmt = "begin rollback work ; G3_Log_Err . Termina_Log ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)48;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


      /* EXEC SQL ROLLBACK WORK RELEASE; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 1;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)62;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


      exit(sqlca.sqlcode);
   }
}

/**************************************************************************************/
/* Determ_Nivel: Determina, del banco de datos o de un hash local, el nivel logico de */
/*               una instancia de dimension.					      */
/**************************************************************************************/

/* Numero de buckets en la tabla hash local */
#define N_BUCKETS 25

/* Estructura para almacenar instancias con niveles en la tabla de hash */
typedef struct st_inst {
   int Inst;
   int Nivel;
   struct st_inst *prox;
} T_INST;

typedef T_INST *PT_INST;
typedef PT_INST *T_HASH_DIM;

/* Tabla de Hash (un vector para c/ dimension) */
static T_HASH_DIM Tab_Hash_Dim[50] = {     
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

void calcp(int *res)
{

*res = -1 + base + 8;
*(res+1) = - 4 + (*(res+0) + base) / 2;
*(res+2) = (*(res+1) + base + 29) / 2;
*(res+3) = 16 + (base + *(res+0)) / 3;
*(res+4) = base / 2 - 23 + *(res+3);
*(res+5) = (-43 + base * 4) / 3;
*(res+6) = *(res+1) - 1;
*(res+7) = (2 * base - 2) / 2;
*(res+8) = -12 + *(res+5) * 2 - base;
}

static int determ_nivel(int Dimen, int Inst)
{
   register int i;
   int Nivel = 0;
   PT_INST PtInst;

   /* EXEC SQL whenever SQLERROR do sql_error("determ. nivel logico"); */ 


   /* No hace hash para la dimension 1 (cliente) ny para dimensiones mas alla de 50 */
   if (Dimen != 1 && Dimen < 50) {
      if (Tab_Hash_Dim[Dimen] != NULL) {  /* Si hay hash para esta dimension */
         PtInst = Tab_Hash_Dim[Dimen][Inst % N_BUCKETS];
         while ((PtInst != NULL) && PtInst->Inst != Inst) /* Buscando en el hash */
            PtInst = PtInst->prox;
         if (PtInst != NULL)				 /* Hallo ? */
            Nivel = PtInst->Nivel;
      }

      if (!Nivel) {   /* No hallo */
         /* EXEC SQL
            select /o+ INDEX(I PK_INSDIM) o/ I.NU_NIVL_LOGC_DIMEN
               into :Nivel
               from G3_INSTAN_DIMEN I
               where I.NU_DIMEN = :Dimen and
                     I.NU_INSTAN_DIMEN = :Inst; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 3;
         sqlstm.stmt = "select  /*+  INDEX(I PK_INSDIM)  +*/ I.NU_NIVL_LOGC_\
DIMEN into :b0  from G3_INSTAN_DIMEN I where (I.NU_DIMEN=:b1 and I.NU_INSTAN_D\
IMEN=:b2)";
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)76;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlstm.sqhstv[0] = (unsigned char  *)&Nivel;
         sqlstm.sqhstl[0] = (unsigned long  )4;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&Dimen;
         sqlstm.sqhstl[1] = (unsigned long  )4;
         sqlstm.sqindv[1] = (         short *)0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&Inst;
         sqlstm.sqhstl[2] = (unsigned long  )4;
         sqlstm.sqindv[2] = (         short *)0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) sql_error("determ. nivel logico");
}



         if (Tab_Hash_Dim[Dimen] == NULL) { /* Si todavia no hay hash para esta dim. */
            Tab_Hash_Dim[Dimen] = calloc(N_BUCKETS, sizeof(PT_INST));
            if (Tab_Hash_Dim[Dimen] != NULL)
               for (i = 0; i < N_BUCKETS;i++)
                  Tab_Hash_Dim[Dimen][i] = NULL;
            else {
               puts("Sin memoria (Hash)!");
               return(Nivel);
            }
         }

         /* Ponendo la instancia en la tabla de hash */
         if (Tab_Hash_Dim[Dimen][Inst % N_BUCKETS] == NULL) {
            PtInst = Tab_Hash_Dim[Dimen][Inst % N_BUCKETS] = malloc(sizeof(T_INST));
            if (PtInst == NULL) {
               puts("Sin memoria (Bucket)!");
               return(Nivel);
            }
         }
         else {
            for (PtInst = Tab_Hash_Dim[Dimen][Inst % N_BUCKETS];
               PtInst->prox != NULL; PtInst = PtInst->prox);
            PtInst->prox = malloc(sizeof(T_INST));
            if (PtInst->prox != NULL)
               PtInst = PtInst->prox;
            else {
               puts("Sin memoria (Inst)!");
               exit(1);
               return(Nivel);
            }
         }
         PtInst->Inst = Inst;
         PtInst->Nivel = Nivel;
         PtInst->prox = NULL;
      }
   }
   else {   /* Si para esta dimension no se hace hash */
      /* EXEC SQL
         select /o+ INDEX(I PK_INSDIM) o/ I.NU_NIVL_LOGC_DIMEN
            into :Nivel
            from G3_INSTAN_DIMEN I
            where I.NU_DIMEN = :Dimen and
                  I.NU_INSTAN_DIMEN = :Inst; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 3;
      sqlstm.stmt = "select  /*+  INDEX(I PK_INSDIM)  +*/ I.NU_NIVL_LOGC_DIM\
EN into :b0  from G3_INSTAN_DIMEN I where (I.NU_DIMEN=:b1 and I.NU_INSTAN_DIME\
N=:b2)";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)102;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Nivel;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[1] = (unsigned long  )4;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&Inst;
      sqlstm.sqhstl[2] = (unsigned long  )4;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("determ. nivel logico");
}


   }
   return Nivel;
}


/**********************************************************************************
   determ_tab_sh: Determina la tabla donde deve quedar un registro de
		  datos de serie historica
 **********************************************************************************/
void determ_tab_sh(char *Tabela, const T_REG_SH *fReg)
{
   determ_tab_movt(Tabela, (const T_REG_MOVT *)fReg);
}

/* Tabla para hacer cache de hasta 50 visiones */
static int Visoes[50][16] = {
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

/**********************************************************************************
   determ_tab_movt: Determina la tabla donde deve quedar un registro de
		    datos de movimiento
 **********************************************************************************/


void determ_tab_movt(char *Tabela, const T_REG_MOVT *fReg)
{
   T_NIVEL Niveles[16];
   int Dimen[16];
   static int Instan[16];
   register int i;


   if ((fReg->Vision >= 50) || (Visoes[fReg->Vision][0] == 0)) {
      /* EXEC SQL
	 select NU_DIMEN__1 , NU_DIMEN__2 , NU_DIMEN__3 , NU_DIMEN__4,
		NU_DIMEN__5 , NU_DIMEN__6 , NU_DIMEN__7 , NU_DIMEN__8,
		NU_DIMEN__9 , NU_DIMEN__10, NU_DIMEN__11, NU_DIMEN__12,
		NU_DIMEN__13, NU_DIMEN__14, NU_DIMEN__15, NU_DIMEN__16
	    into :Dimen[ 0], :Dimen[ 1], :Dimen[ 2], :Dimen[ 3],
	         :Dimen[ 4], :Dimen[ 5], :Dimen[ 6], :Dimen[ 7],
	         :Dimen[ 8], :Dimen[ 9], :Dimen[10], :Dimen[11],
	         :Dimen[12], :Dimen[13], :Dimen[14], :Dimen[15]
	    from G3_VISION
	    where NU_VISION = :fReg->Vision; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 17;
      sqlstm.stmt = "select NU_DIMEN__1 ,NU_DIMEN__2 ,NU_DIMEN__3 ,NU_DIMEN_\
_4 ,NU_DIMEN__5 ,NU_DIMEN__6 ,NU_DIMEN__7 ,NU_DIMEN__8 ,NU_DIMEN__9 ,NU_DIMEN_\
_10 ,NU_DIMEN__11 ,NU_DIMEN__12 ,NU_DIMEN__13 ,NU_DIMEN__14 ,NU_DIMEN__15 ,NU_\
DIMEN__16 into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b1\
4,:b15  from G3_VISION where NU_VISION=:b16";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)128;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&Dimen[0];
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&Dimen[1];
      sqlstm.sqhstl[1] = (unsigned long  )4;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&Dimen[2];
      sqlstm.sqhstl[2] = (unsigned long  )4;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&Dimen[3];
      sqlstm.sqhstl[3] = (unsigned long  )4;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&Dimen[4];
      sqlstm.sqhstl[4] = (unsigned long  )4;
      sqlstm.sqindv[4] = (         short *)0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqhstv[5] = (unsigned char  *)&Dimen[5];
      sqlstm.sqhstl[5] = (unsigned long  )4;
      sqlstm.sqindv[5] = (         short *)0;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqhstv[6] = (unsigned char  *)&Dimen[6];
      sqlstm.sqhstl[6] = (unsigned long  )4;
      sqlstm.sqindv[6] = (         short *)0;
      sqlstm.sqharm[6] = (unsigned long )0;
      sqlstm.sqhstv[7] = (unsigned char  *)&Dimen[7];
      sqlstm.sqhstl[7] = (unsigned long  )4;
      sqlstm.sqindv[7] = (         short *)0;
      sqlstm.sqharm[7] = (unsigned long )0;
      sqlstm.sqhstv[8] = (unsigned char  *)&Dimen[8];
      sqlstm.sqhstl[8] = (unsigned long  )4;
      sqlstm.sqindv[8] = (         short *)0;
      sqlstm.sqharm[8] = (unsigned long )0;
      sqlstm.sqhstv[9] = (unsigned char  *)&Dimen[9];
      sqlstm.sqhstl[9] = (unsigned long  )4;
      sqlstm.sqindv[9] = (         short *)0;
      sqlstm.sqharm[9] = (unsigned long )0;
      sqlstm.sqhstv[10] = (unsigned char  *)&Dimen[10];
      sqlstm.sqhstl[10] = (unsigned long  )4;
      sqlstm.sqindv[10] = (         short *)0;
      sqlstm.sqharm[10] = (unsigned long )0;
      sqlstm.sqhstv[11] = (unsigned char  *)&Dimen[11];
      sqlstm.sqhstl[11] = (unsigned long  )4;
      sqlstm.sqindv[11] = (         short *)0;
      sqlstm.sqharm[11] = (unsigned long )0;
      sqlstm.sqhstv[12] = (unsigned char  *)&Dimen[12];
      sqlstm.sqhstl[12] = (unsigned long  )4;
      sqlstm.sqindv[12] = (         short *)0;
      sqlstm.sqharm[12] = (unsigned long )0;
      sqlstm.sqhstv[13] = (unsigned char  *)&Dimen[13];
      sqlstm.sqhstl[13] = (unsigned long  )4;
      sqlstm.sqindv[13] = (         short *)0;
      sqlstm.sqharm[13] = (unsigned long )0;
      sqlstm.sqhstv[14] = (unsigned char  *)&Dimen[14];
      sqlstm.sqhstl[14] = (unsigned long  )4;
      sqlstm.sqindv[14] = (         short *)0;
      sqlstm.sqharm[14] = (unsigned long )0;
      sqlstm.sqhstv[15] = (unsigned char  *)&Dimen[15];
      sqlstm.sqhstl[15] = (unsigned long  )4;
      sqlstm.sqindv[15] = (         short *)0;
      sqlstm.sqharm[15] = (unsigned long )0;
      sqlstm.sqhstv[16] = (unsigned char  *)&(fReg->Vision);
      sqlstm.sqhstl[16] = (unsigned long  )4;
      sqlstm.sqindv[16] = (         short *)0;
      sqlstm.sqharm[16] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("determ. nivel logico");
}



	 for (i = 0; i < 16; i++)
	    Niveles[i][0] = Dimen[i];

      if (fReg->Vision < 50) {
	 /* Visoes[fReg->Vision] = malloc(sizeof(T_VISAO)); */
	 Visoes[fReg->Vision][0]  = Niveles[0][0];
	 Visoes[fReg->Vision][1]  = Niveles[1][0];
	 Visoes[fReg->Vision][2]  = Niveles[2][0];
	 Visoes[fReg->Vision][3]  = Niveles[3][0];
	 Visoes[fReg->Vision][4]  = Niveles[4][0];
	 Visoes[fReg->Vision][5]  = Niveles[5][0];
	 Visoes[fReg->Vision][6]  = Niveles[6][0];
	 Visoes[fReg->Vision][7]  = Niveles[7][0];
	 Visoes[fReg->Vision][8]  = Niveles[8][0];
	 Visoes[fReg->Vision][9]  = Niveles[9][0];
	 Visoes[fReg->Vision][10] = Niveles[10][0];
	 Visoes[fReg->Vision][11] = Niveles[11][0];
	 Visoes[fReg->Vision][12] = Niveles[12][0];
	 Visoes[fReg->Vision][13] = Niveles[13][0];
	 Visoes[fReg->Vision][14] = Niveles[14][0];
	 Visoes[fReg->Vision][15] = Niveles[15][0];
      }
   } else {
      Niveles[0][0]  = Visoes[fReg->Vision][0];
      Niveles[1][0]  = Visoes[fReg->Vision][1];
      Niveles[2][0]  = Visoes[fReg->Vision][2];  
      Niveles[3][0]  = Visoes[fReg->Vision][3];
      Niveles[4][0]  = Visoes[fReg->Vision][4];
      Niveles[5][0]  = Visoes[fReg->Vision][5];
      Niveles[6][0]  = Visoes[fReg->Vision][6];
      Niveles[7][0]  = Visoes[fReg->Vision][7];
      Niveles[8][0]  = Visoes[fReg->Vision][8];
      Niveles[9][0]  = Visoes[fReg->Vision][9]; 
      Niveles[10][0] = Visoes[fReg->Vision][10];
      Niveles[11][0] = Visoes[fReg->Vision][11];
      Niveles[12][0] = Visoes[fReg->Vision][12];
      Niveles[13][0] = Visoes[fReg->Vision][13];
      Niveles[14][0] = Visoes[fReg->Vision][14];
      Niveles[15][0] = Visoes[fReg->Vision][15];
   }
   Instan[0] = fReg->Inst1;
   Instan[1] = fReg->Inst2;
   Instan[2] = fReg->Inst3;
   Instan[3] = fReg->Inst4;
   Instan[4] = fReg->Inst5;
   Instan[5] = fReg->Inst6;
   Instan[6] = fReg->Inst7;
   Instan[7] = fReg->Inst8;
   Instan[8] = fReg->Inst9;
   Instan[9] = fReg->Inst10;
   Instan[10] = fReg->Inst11;
   Instan[11] = fReg->Inst12;
   Instan[12] = fReg->Inst13;
   Instan[13] = fReg->Inst14;
   Instan[14] = fReg->Inst15;
   Instan[15] = fReg->Inst16;
   for (i = 0; i < 16; i++)
      if (Niveles[i][0])
         Niveles[i][1] = determ_nivel(Niveles[i][0], Instan[i]);
      else
         Niveles[i][1] = 0;
   NmTabSH((const char *)fReg->Fc_Refr, fReg->Vision, Niveles, Tabela);
}

/*********************************************************************************************
           Sql usado para insertar o actualizar las tablas de series historicas
 ********************************************************************************************/

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

static int NTables = 0, NIndic = 0;
static short *Parsed;
static Cda_Def *cursor;
static Lda_Def lda;
static /* VARCHAR Tabelas[20][35]; */ 
struct { unsigned short len; unsigned char arr[38]; } Tabelas[20];

static T_DATE *Fc_Indic[3];

/***********************************************************************************
   Trata_Erro_OCI: Genera mensajes de error para errores de OCI.
 ***********************************************************************************/

static void trata_erro_oci(T_REG_SH *fReg,
                     Lda_Def *lda, int cd_err, char *pos_err)
{
   char errmsg[1024];

   printf("Granularidade: %c\nIndicador: %d\n", fReg->Grnl, fReg->Indic);
   errmsg[oerhms(lda, cd_err, errmsg, 1000)] = '\0';
   printf("oexec error: %s\n%s\n", pos_err, errmsg);
   /* EXEC SQL ROLLBACK WORK; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 17;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)210;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("determ. nivel logico");
}


   /* EXEC SQL EXECUTE
      begin
         G3_Log_Err.Log_Msj('E', :pos_err || :errmsg);
         rollback work;
         G3_Log_Err.Termina_Log;
      end;
   END-EXEC; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 17;
   sqlstm.stmt = "begin G3_Log_Err . Log_Msj ( 'E' , :pos_err || :errmsg ) ;\
 rollback work ; G3_Log_Err . Termina_Log ; end ;";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)224;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)pos_err;
   sqlstm.sqhstl[0] = (unsigned long  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqhstv[1] = (unsigned char  *)errmsg;
   sqlstm.sqhstl[1] = (unsigned long  )1024;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("determ. nivel logico");
}


   /* Roll back any pending changes and disconnect from Oracle. */
   /* EXEC SQL ROLLBACK WORK RELEASE; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 17;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)246;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("determ. nivel logico");
}


   exit(cd_err);
}

/**************************************************************************************
   prepara_oci: Aloca espacio y prepara las estructuras internas para los cursores
		OCI de insercion en las tablas de serie historica
 **************************************************************************************/

int prepara_oci()
{
   register int i;
   int NVisiones;
   /* VARCHAR NmTabla[35]; */ 
struct { unsigned short len; unsigned char arr[35]; } NmTabla;

   T_DATE FcMin, FcMax;
   short IndMin, IndMax, IndDimen, IndInf, IndSup;
   int Dimen, NivInf, NivSup, NuVision, NTablasVision, Tabla;

   if (NTables)
      return(NTables);
   /* Preparando un array de cursores OCI para los inserts en las tablas serie hist */
   /* EXEC SQL whenever SQLERROR do sql_error("Preparando OCI"); */ 

   /* EXEC SQL select count(*)
      into :NTables
      from G3_TABLA_SH; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 17;
   sqlstm.stmt = "select count(*)  into :b0  from G3_TABLA_SH ";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)260;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)&NTables;
   sqlstm.sqhstl[0] = (unsigned long  )4;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Preparando OCI");
}



   /* EXEC SQL select nvl(max(NU_VISION), 0)
      into :NVisiones
      from G3_VISION; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 17;
   sqlstm.stmt = "select nvl(max(NU_VISION),0) into :b0  from G3_VISION ";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)278;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)&NVisiones;
   sqlstm.sqhstl[0] = (unsigned long  )4;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Preparando OCI");
}



   cursor = calloc(NTables, sizeof(Cda_Def));
   Parsed = calloc(NTables, sizeof(short));
   Tablas_Serie = calloc(NTables, sizeof(T_TABLA_SH));
   Tablas_Vision = calloc(NVisiones, sizeof(T_TABLA_VISION));
   for (i = 0; i < NTables; i++)
      Parsed[i] = 0;

   /* Cargando Informacion de las tablas de serie historica */
   /* EXEC SQL DECLARE R_Tablas cursor for
      select NM_TABLA_SH,
             FC_MIN_TABLA_SH,
             FC_MAX_TABLA_SH,
             NU_DIMEN_TABLA_SH,
             NU_NIVL_LOGC_MIN,
             NU_NIVL_LOGC_MAX
         from G3_TABLA_SH
	 order by NU_TABLA_SH; */ 

   /* EXEC SQL OPEN R_Tablas; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 17;
   sqlstm.stmt = sq0014;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)296;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Preparando OCI");
}


   /* EXEC SQL WHENEVER NOT FOUND do break; */ 

   for (i = 0;;i++) {
      /* EXEC SQL fetch R_Tablas into
         :NmTabla,
	 :FcMin:IndMin,
	 :FcMax:IndMax,
	 :Dimen:IndDimen,
	 :NivInf:IndInf,
	 :NivSup:IndSup; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 17;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)310;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&NmTabla;
      sqlstm.sqhstl[0] = (unsigned long  )37;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)FcMin;
      sqlstm.sqhstl[1] = (unsigned long  )20;
      sqlstm.sqindv[1] = (         short *)&IndMin;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqhstv[2] = (unsigned char  *)FcMax;
      sqlstm.sqhstl[2] = (unsigned long  )20;
      sqlstm.sqindv[2] = (         short *)&IndMax;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&Dimen;
      sqlstm.sqhstl[3] = (unsigned long  )4;
      sqlstm.sqindv[3] = (         short *)&IndDimen;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&NivInf;
      sqlstm.sqhstl[4] = (unsigned long  )4;
      sqlstm.sqindv[4] = (         short *)&IndInf;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqhstv[5] = (unsigned char  *)&NivSup;
      sqlstm.sqhstl[5] = (unsigned long  )4;
      sqlstm.sqindv[5] = (         short *)&IndSup;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) break;
      if (sqlca.sqlcode < 0) sql_error("Preparando OCI");
}


      NmTabla.arr[NmTabla.len] = FcMin[19] = FcMax[19] = 0;
      strcpy(Tablas_Serie[i].Nombre, NmTabla.arr);
      if (IndDimen != -1) {
         Tablas_Serie[i].Dimen = Dimen;
	 Tablas_Serie[i].Nivel_Inf = NivInf;
	 Tablas_Serie[i].Nivel_Sup = NivSup;
      }
      else
         Tablas_Serie[i].Dimen = 0;
      if (IndMin != -1) {
         strcpy(Tablas_Serie[i].Fc_Min, FcMin);
	 strcpy(Tablas_Serie[i].Fc_Max, FcMax);
      }
      else {
         Tablas_Serie[i].Fc_Min[0] = 0;
         Tablas_Serie[i].Fc_Max[0] = 0;
      }
   }
   /* EXEC SQL whenever NOT FOUND do sql_error("Preparando OCI"); */ 

   /* EXEC SQL CLOSE R_Tablas; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 17;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)348;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Preparando OCI");
}



   /* EXEC SQL whenever NOT FOUND do sql_error("Preparando OCI a"); */ 

   /* EXEC SQL DECLARE R_Tablas_Vision cursor for
      select NU_VISION, count(*)
         from G3_TABLA_SH_VISION
	 group by NU_VISION; */ 

   /* EXEC SQL whenever NOT FOUND do sql_error("Preparando OCI b"); */ 

   /* EXEC SQL OPEN R_Tablas_Vision; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 17;
   sqlstm.stmt = sq0015;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)362;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Preparando OCI");
}


   /* EXEC SQL WHENEVER NOT FOUND do break; */ 

   for (;;) {
      /* EXEC SQL fetch R_Tablas_Vision into
         :NuVision,
	 :NTablasVision; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 17;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)376;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&NuVision;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&NTablasVision;
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
      if (sqlca.sqlcode < 0) sql_error("Preparando OCI");
}


      /* EXEC SQL whenever NOT FOUND do sql_error("Preparando OCI 1"); */ 

      Tablas_Vision[NuVision].Nu_Tablas = NTablasVision;
      Tablas_Vision[NuVision].Tablas = calloc(NTablasVision, sizeof (T_TABLA_SH *));

      /* EXEC SQL DECLARE R_Tb_Vision cursor for
         select NU_TABLA_SH
	    from G3_TABLA_SH_VISION
	    where NU_VISION = :NuVision; */ 

      /* EXEC SQL OPEN R_Tb_Vision; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 17;
      sqlstm.stmt = sq0016;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)398;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)&NuVision;
      sqlstm.sqhstl[0] = (unsigned long  )4;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Preparando OCI");
}


      /* EXEC SQL WHENEVER NOT FOUND do break; */ 

      for (i = 0;;i++) {
         /* EXEC SQL fetch R_Tb_Vision
	    into :Tabla; */ 

{
         struct sqlexd sqlstm;

         sqlorat((void **)0, &sqlctx, &oraca);
         sqlstm.sqlvsn = 8;
         sqlstm.arrsiz = 17;
         sqlstm.iters = (unsigned long  )1;
         sqlstm.offset = (unsigned short)416;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)0;
         sqlstm.sqhstv[0] = (unsigned char  *)&Tabla;
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
         if (sqlca.sqlcode < 0) sql_error("Preparando OCI");
}


	 Tablas_Vision[NuVision].Tablas[i] = &(Tablas_Serie[Tabla-1]);
      }
      /* EXEC SQL whenever NOT FOUND do sql_error("Preparando OCI 2"); */ 

      /* EXEC SQL close R_Tb_Vision; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 17;
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)434;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("Preparando OCI");
}


   }
   /* EXEC SQL CLOSE R_Tablas_Vision; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 17;
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)448;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Preparando OCI");
}



   /* EXEC SQL whenever NOT FOUND continue; */ 

   /* EXEC SQL select NM_TABLA_SH
      into :Tabelas
      from G3_TABLA_SH; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 17;
   sqlstm.stmt = "select NM_TABLA_SH into :b0  from G3_TABLA_SH ";
   sqlstm.iters = (unsigned long  )20;
   sqlstm.offset = (unsigned short)462;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)Tabelas;
   sqlstm.sqhstl[0] = (unsigned long  )40;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqharc[0] = (unsigned long   *)0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("Preparando OCI");
}


   for (i = 0; i < NTables; i++) {
      Tabelas[i].arr[Tabelas[i].len] = 0;
      /* printf("%s\n", Tabelas[i].arr); */
   }
   sqllda(&lda);

   /* EXEC SQL whenever NOT FOUND do sql_error("Preparando OCI 2"); */ 

   /* EXEC SQL select max(NU_INDCA_PERFM)
      into :NIndic
      from G3_INDCA_PERFM; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 17;
   sqlstm.stmt = "select max(NU_INDCA_PERFM) into :b0  from G3_INDCA_PERFM ";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)480;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)&NIndic;
   sqlstm.sqhstl[0] = (unsigned long  )4;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode == 1403) sql_error("Preparando OCI 2");
   if (sqlca.sqlcode < 0) sql_error("Preparando OCI");
}



   Fc_Indic[0] = calloc(NIndic, sizeof(T_DATE));
   Fc_Indic[1] = calloc(NIndic, sizeof(T_DATE));
   Fc_Indic[2] = calloc(NIndic, sizeof(T_DATE));
   for (i = 0; i < NIndic; i++) {
      *(Fc_Indic[0][i]) = 0;
      *(Fc_Indic[1][i]) = 0;
      *(Fc_Indic[2][i]) = 0;
   }
   return(NTables);
}

/**************************************************************************************
   libera_oci: Libera los cursores de OCI
 **************************************************************************************/
void libera_oci()
{
   register int i;

   if (!NTables)
      return;
   for (i = 0; i < NTables; i++) {
      if (Parsed[i])
	 oclose(&cursor[i]);
   }
   free(cursor);
   free(Parsed);
   free(Fc_Indic[0]);
   free(Fc_Indic[1]);
   free(Fc_Indic[2]);
   NTables = 0;
}

/**************************************************************************************
   Graba_Reg_SH: Graba un registro de datos en la tabla correcta de serie historica
		 Determina automaticamente la tabla donde grabar
 **************************************************************************************/

#pragma optimize ("g", off)
void Graba_Reg_SH(T_REG_SH *fReg)
{
   register int i;
   int Cd_Ind, NuInd, Actualizar;
   char TabReg[35];
   static char aux_sql[16384];
   static T_REG_SH Reg;
   T_DATE FcReg, FcInd, FcRefr, FcMin, FcMax;

   memcpy(&Reg, fReg, sizeof(T_REG_SH));
   /* EXEC SQL whenever SQLERROR do sql_error("Grabacion de registro"); */ 

   determ_tab_sh(TabReg, &Reg);
   for (i = 0; (i < NTables) && 
	       (strcmp(TabReg, (const char *)Tabelas[i].arr)); i++);
   if (i >= NTables) {
      /* EXEC SQL EXECUTE
	 declare
	    tabla_invalida exception;
	    pragma exception_init(tabla_invalida, -942);
	 begin
	    raise tabla_invalida;
	 end;
      END-EXEC; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 17;
      sqlstm.stmt = "declare tabla_invalida exception ; pragma exception_ini\
t ( tabla_invalida , -942 ) ; begin raise tabla_invalida ; end ;";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)498;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Preparando OCI 2");
      if (sqlca.sqlcode < 0) sql_error("Grabacion de registro");
}


   }
      
   if (!Parsed[i]) {
      if (oopen(&cursor[i], &lda, NULL, -1, -1, NULL, -1))
	 trata_erro_oci(&Reg, &lda, cursor[i].rc, "open");
      sprintf(aux_sql, SQL_INS, Tabelas[i].len,
	      Tabelas[i].arr, Tabelas[i].len, Tabelas[i].arr);
      if (oparse(&cursor[i], aux_sql, -1, 1, 2))
	 trata_erro_oci(&Reg,
			&lda, cursor[i].rc, "parse");
      if (obndrv(&cursor[i], ":Indic", -1, (ub1 *)&Reg.Indic,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg,
			&lda, cursor[i].rc, "bind Indic");
      if (obndrv(&cursor[i], ":Vision", -1, (ub1 *)&Reg.Vision,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg,
			&lda, cursor[i].rc, "bind Vision");
      if (obndrv(&cursor[i], ":Inst1", -1, (ub1 *)&Reg.Inst1,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Inst1");
      if (obndrv(&cursor[i], ":Inst2", -1, (ub1 *)&Reg.Inst2,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Inst2");
      if (obndrv(&cursor[i], ":Inst3", -1, (ub1 *)&Reg.Inst3,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Inst3");
      if (obndrv(&cursor[i], ":Inst4", -1, (ub1 *)&Reg.Inst4,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Inst4");
      if (obndrv(&cursor[i], ":Inst5", -1, (ub1 *)&Reg.Inst5,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Inst5");
      if (obndrv(&cursor[i], ":Inst6", -1, (ub1 *)&Reg.Inst6,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Inst6");
      if (obndrv(&cursor[i], ":Inst7", -1, (ub1 *)&Reg.Inst7,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Inst7");
      if (obndrv(&cursor[i], ":Inst8", -1, (ub1 *)&Reg.Inst8,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Inst8");
      if (obndrv(&cursor[i], ":Inst9", -1, (ub1 *)&Reg.Inst9,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Inst9");
      if (obndrv(&cursor[i], ":Inst10", -1, (ub1 *)&Reg.Inst10,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Inst10");
      if (obndrv(&cursor[i], ":Inst11", -1, (ub1 *)&Reg.Inst11,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Inst11");
      if (obndrv(&cursor[i], ":Inst12", -1, (ub1 *)&Reg.Inst12,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Inst12");
      if (obndrv(&cursor[i], ":Inst13", -1, (ub1 *)&Reg.Inst13,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Inst13");
      if (obndrv(&cursor[i], ":Inst14", -1, (ub1 *)&Reg.Inst14,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Inst14");
      if (obndrv(&cursor[i], ":Inst15", -1, (ub1 *)&Reg.Inst15,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Inst15");
      if (obndrv(&cursor[i], ":Inst16", -1, (ub1 *)&Reg.Inst16,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Inst16");
      if (obndrv(&cursor[i], ":Fc_Refr", -1, (ub1 *)Reg.Fc_Refr,
	 sizeof(T_DATE) - 1, 1, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Fc_Refr");
      if (obndrv(&cursor[i], ":Grnl", -1, (ub1 *)Reg.Grnl,
	 sizeof(Reg.Grnl) -1, 96, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Grnl");
      if (obndrv(&cursor[i], ":Valor", -1, (ub1 *)&Reg.Valor,
	 sizeof(double), 4, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Valor");
      if (obndrv(&cursor[i], ":Fuente", -1, (ub1 *)&Reg.Fuente,
	 sizeof(int), 3, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, 
			&lda, cursor[i].rc, "bind Fuente");
      if (obndrv(&cursor[i], ":Fc_Gen", -1, (ub1 *)Reg.Fc_Gen,
	 sizeof(T_DATE) - 1, 1, -1, NULL, NULL, -1, -1))
	 trata_erro_oci(&Reg, &lda,
			cursor[i].rc, "bind Fc_Gen");
   }
   
   if (oexec(&cursor[i])) {
	 trata_erro_oci(&Reg,
			&lda, cursor[i].rc, "Grabacion de registro de datos.\n"
			"En la linea 719 de dw_aux.pc.");
   }
   else
      Parsed[i] = 1;
   
   strncpy(FcReg, Reg.Fc_Gen, 19);
   strncpy(FcRefr, Reg.Fc_Refr, 19);
   FcReg[19] = FcRefr[19] = 0;
   /* Actualizando el indicador grabado en G3_INDCA_PERFM */
   if (! *(Fc_Indic[0][Reg.Indic])) {
      /* EXEC SQL
	 select nvl(FC_ULT_ATUAL_INDCA, to_date(:FcReg) + 1),
		nvl(FC_LIM_INF_INDCA, to_date(:FcRefr) + 1),
		nvl(FC_LIM_SUP_INDCA, to_date(:FcRefr) - 1),
		nvl(CD_INDCA_ATUAL, '0')
	    into FcInd, FcMin, FcMax, Cd_Ind
	    from G3_INDCA_PERFM
	    where NU_INDCA_PERFM = :Reg.Indic; */ 

{
      struct sqlexd sqlstm;

      sqlorat((void **)0, &sqlctx, &oraca);
      sqlstm.sqlvsn = 8;
      sqlstm.arrsiz = 17;
      sqlstm.stmt = "select nvl(FC_ULT_ATUAL_INDCA,(to_date(:b0)+1)) ,nvl(FC\
_LIM_INF_INDCA,(to_date(:b1)+1)) ,nvl(FC_LIM_SUP_INDCA,(to_date(:b1)-1)) ,nvl(\
CD_INDCA_ATUAL,'0') into :b3,:b4,:b5,:b6  from G3_INDCA_PERFM where NU_INDCA_P\
ERFM=:b7";
      sqlstm.iters = (unsigned long  )1;
      sqlstm.offset = (unsigned short)512;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)0;
      sqlstm.sqhstv[0] = (unsigned char  *)FcReg;
      sqlstm.sqhstl[0] = (unsigned long  )20;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqhstv[1] = (unsigned char  *)FcRefr;
      sqlstm.sqhstl[1] = (unsigned long  )20;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqhstv[2] = (unsigned char  *)FcRefr;
      sqlstm.sqhstl[2] = (unsigned long  )20;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqhstv[3] = (unsigned char  *)FcInd;
      sqlstm.sqhstl[3] = (unsigned long  )20;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqhstv[4] = (unsigned char  *)FcMin;
      sqlstm.sqhstl[4] = (unsigned long  )20;
      sqlstm.sqindv[4] = (         short *)0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqhstv[5] = (unsigned char  *)FcMax;
      sqlstm.sqhstl[5] = (unsigned long  )20;
      sqlstm.sqindv[5] = (         short *)0;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqhstv[6] = (unsigned char  *)&Cd_Ind;
      sqlstm.sqhstl[6] = (unsigned long  )4;
      sqlstm.sqindv[6] = (         short *)0;
      sqlstm.sqharm[6] = (unsigned long )0;
      sqlstm.sqhstv[7] = (unsigned char  *)&(Reg.Indic);
      sqlstm.sqhstl[7] = (unsigned long  )4;
      sqlstm.sqindv[7] = (         short *)0;
      sqlstm.sqharm[7] = (unsigned long )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode == 1403) sql_error("Preparando OCI 2");
      if (sqlca.sqlcode < 0) sql_error("Grabacion de registro");
}


      strncpy(Fc_Indic[0][Reg.Indic], FcInd, 19);
      strncpy(Fc_Indic[1][Reg.Indic], FcMin, 19);
      strncpy(Fc_Indic[2][Reg.Indic], FcMax, 19);
      Fc_Indic[0][Reg.Indic][19] = Fc_Indic[1][Reg.Indic][19] = Fc_Indic[2][Reg.Indic][19] = 0;
#ifdef __DEBUG
      printf("Indic: %d, Atual: %d, desde: %s hasta %s\n", Reg.Indic, Cd_Ind, Fc_Indic[1][Reg.Indic], Fc_Indic[2][Reg.Indic]);
#endif
   }

   strncpy(FcInd, Fc_Indic[0][Reg.Indic], 19);
   strncpy(FcMin, Fc_Indic[1][Reg.Indic], 19);
   strncpy(FcMax, Fc_Indic[2][Reg.Indic], 19);
   FcInd[19] = FcMin[19] = FcMax[19] = 0;
   NuInd = Reg.Indic;

   Actualizar = 0;
   /* EXEC SQL EXECUTE
   begin
      if (:Cd_Ind = 0) or (:Cd_Ind = 2) then
	 :Actualizar:= 1;
	 :FcInd:= :FcReg;
	 :FcMin:= :FcRefr;
	 :FcMax:= :FcRefr;
      else
	 /o Es necesario actualizar la fecha de ultima actualizacion ? o/
	 if (to_date(:FcReg) < to_date(:FcInd)) then
	    :Actualizar:= 1;
	    :FcInd:= :FcReg;
	 end if;

	 /o Es necesario actualizar el limite isquierdo ? o/
	 if (to_date(:FcRefr) < to_date(:FcMin)) then
	    :Actualizar:= 1;
	    :FcMin:= :FcRefr;
	 end if;

	 /o Es necesario actualizar el limite derecho ? o/
	 if (to_date(:FcRefr) > to_date(:FcMax)) then
	    :Actualizar:= 1;
	    :FcMax:= :FcRefr;
	 end if;
      end if;

      if :Actualizar  = 1 then
	 update G3_INDCA_PERFM set
	    CD_INDCA_ATUAL = '1',
	    FC_ULT_ATUAL_INDCA = :FcInd,
	    FC_LIM_INF_INDCA = :FcMin,
	    FC_LIM_SUP_INDCA = :FcMax
	    where NU_INDCA_PERFM = :NuInd;
      end if;
   end;
   END-EXEC; */ 

{
   struct sqlexd sqlstm;

   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 8;
   sqlstm.arrsiz = 17;
   sqlstm.stmt = "begin if ( :Cd_Ind = 0 ) or ( :Cd_Ind = 2 ) then :Actualiz\
ar := 1 ; :FcInd := :FcReg ; :FcMin := :FcRefr ; :FcMax := :FcRefr ; else if (\
 to_date ( :FcReg ) < to_date ( :FcInd ) ) then :Actualizar := 1 ; :FcInd := :\
FcReg ; end if ; if ( to_date ( :FcRefr ) < to_date ( :FcMin ) ) then :Actuali\
zar := 1 ; :FcMin := :FcRefr ; end if ; if ( to_date ( :FcRefr ) > to_date ( :\
FcMax ) ) then :Actualizar := 1 ; :FcMax := :FcRefr ; end if ; end if ; if :Ac\
tualizar = 1 then update G3_INDCA_PERFM set CD_INDCA_ATUAL = '1' , FC_ULT_ATUA\
L_INDCA = :FcInd , FC_LIM_INF_INDCA = :FcMin , FC_LIM_SUP_INDCA = :FcMax where\
 NU_INDCA_PERFM = :NuInd ; end if ; end ;";
   sqlstm.iters = (unsigned long  )1;
   sqlstm.offset = (unsigned short)558;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)0;
   sqlstm.sqhstv[0] = (unsigned char  *)&Cd_Ind;
   sqlstm.sqhstl[0] = (unsigned long  )4;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&Actualizar;
   sqlstm.sqhstl[1] = (unsigned long  )4;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqhstv[2] = (unsigned char  *)FcInd;
   sqlstm.sqhstl[2] = (unsigned long  )20;
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqhstv[3] = (unsigned char  *)FcReg;
   sqlstm.sqhstl[3] = (unsigned long  )20;
   sqlstm.sqindv[3] = (         short *)0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqhstv[4] = (unsigned char  *)FcMin;
   sqlstm.sqhstl[4] = (unsigned long  )20;
   sqlstm.sqindv[4] = (         short *)0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqhstv[5] = (unsigned char  *)FcRefr;
   sqlstm.sqhstl[5] = (unsigned long  )20;
   sqlstm.sqindv[5] = (         short *)0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqhstv[6] = (unsigned char  *)FcMax;
   sqlstm.sqhstl[6] = (unsigned long  )20;
   sqlstm.sqindv[6] = (         short *)0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&NuInd;
   sqlstm.sqhstl[7] = (unsigned long  )4;
   sqlstm.sqindv[7] = (         short *)0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode == 1403) sql_error("Preparando OCI 2");
   if (sqlca.sqlcode < 0) sql_error("Grabacion de registro");
}



   strncpy(Fc_Indic[0][NuInd], FcInd, 19);
   strncpy(Fc_Indic[1][NuInd], FcMin, 19);
   strncpy(Fc_Indic[2][NuInd], FcMax, 19);
   Fc_Indic[0][Reg.Indic][19] = Fc_Indic[1][Reg.Indic][19] = Fc_Indic[2][Reg.Indic][19] = 0;
#ifdef __DEBUG
   if (Actualizar) {
      printf("Atualizacao: %s, Inicial: %s, Final: %s\n", Fc_Indic[0][Reg.Indic],
         Fc_Indic[1][Reg.Indic], Fc_Indic[2][Reg.Indic]);
      printf("Atualizacao: %s, Inicial: %s, Final: %s\n", FcInd, FcMin, FcMax);
   }
#endif
   
}
#pragma optimize ("g", on)