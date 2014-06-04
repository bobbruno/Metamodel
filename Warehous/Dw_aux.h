
#ifndef __DW_AUX
#define __DW_AUX

typedef char T_DATE[20];
typedef int T_VISAO[16];
typedef T_VISAO *T_VISAO_ARR;

typedef int T_NIVEL[2];
typedef struct {
   char   Nombre[36];
   int    Dimen, Nivel_Inf, Nivel_Sup;
   T_DATE Fc_Min, Fc_Max;
} T_TABLA_SH;

typedef struct {
   int Nu_Tablas;
   T_TABLA_SH **Tablas;
} T_TABLA_VISION;

typedef struct {
   int Indic, Vision, Inst1, Inst2, Inst3, Inst4, Inst5, Inst6, Inst7, Inst8,
       Inst9, Inst10, Inst11, Inst12, Inst13, Inst14, Inst15, Inst16;
   T_DATE Fc_Refr;
   double Valor;
   int Fuente;
   T_DATE Fc_Gen;
} T_REG_MOVT;

typedef struct {
   int Indic, Vision, Inst1, Inst2, Inst3, Inst4, Inst5, Inst6, Inst7, Inst8,
       Inst9, Inst10, Inst11, Inst12, Inst13, Inst14, Inst15, Inst16;
   T_DATE Fc_Refr;
   double Valor;
   int Fuente;
   T_DATE Fc_Gen;
   char Grnl[2];
} T_REG_SH;

#define BASE 70
#define USERNAME "WAREHOUSE"
#define PASSWORD "WAREHOUSE"          

void sql_error(char *);
void determ_tab_movt(char *, const T_REG_MOVT *);
void getp(char *p);
void determ_tab_sh(char *, const T_REG_SH *);
/* void Insere_Log_Proc_Server(int, T_DATE, T_DATE); */
int prepara_oci();
void libera_oci();
void Graba_Reg_SH(T_REG_SH *);
void limpa_log(void);
void limpa_dw(void);
void calcula_indicadores(char *);
void atualiza_dw(int);
void cons_jerarq(void);
void cons_temporal(void);

extern char username[30], password[30], Paso_Esencial;

#endif
