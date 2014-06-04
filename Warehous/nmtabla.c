#include "dw_aux.h"
#include <string.h>

T_TABLA_SH *Tablas_Serie;  /* Vector de tablas de serie historica */
T_TABLA_VISION *Tablas_Vision; /* Vector de pointers a las tablas por Vision;


/*******************************************************************************************
  NmTabSH: Determina el nombre de la tabla de datos donde se guarda el registro
  ******************************************************************************************/

static __inline void Date_To_Number(char *Number, const char *Date)
{
   strncpy(Number, Date + 6, 4);
   strncat(Number, Date + 3, 2);
   strncat(Number, Date, 2);
}

void NmTabSH(const char *Fc_Refr, int Vision, T_NIVEL *Niveis, char *Retorno)
{
   char Tabela[36];
   register int i, j;
   T_TABLA_SH *Tabla;
   char FcMin[9], FcMax[9], FcRefr[9], *aux;

   Tabela[0] = 0;
   for (i = 0; i < Tablas_Vision[Vision].Nu_Tablas; i++) {
      Tabla = Tablas_Vision[Vision].Tablas[i];
      if (Tabla->Fc_Min[0] != 0) {
	 /* Preparando las fechas para comparacion por string */
	 Date_To_Number(FcRefr, Fc_Refr);
         aux = Tabla->Fc_Min;
	 Date_To_Number(FcMin, aux);
         aux = Tabla->Fc_Max;
	 Date_To_Number(FcMax, aux);

	 /* Si la fecha esta dentro del rango de la tabla */
         if ((strcmp((const char *)FcRefr, (const char *)FcMin)) >= 0 && strcmp(FcRefr, FcMax) <= 0) {

	    /* Si la tabla tiene un corte por dimension */
	    if (Tabla->Dimen) {
	       for (j = 0; j < 16 && Niveis[j][0] != Tabla->Dimen; j++);

	       /* Si la dimension esta en los datos, dentro del rango de niveles */
	       if (j < 16 &&
	           Niveis[j][1] <= Tabla->Nivel_Inf &&
                   Niveis[j][1] >= Tabla->Nivel_Sup) {
                  strcpy(Tabela, Tabla->Nombre);
                  break;
	       }
	    }
	    else {
               strcpy(Tabela, Tabla->Nombre);
	       break;
	    }    
	 }
      }
      else {
         strcpy(Tabela, Tabla->Nombre);
      }
   }

   if (! Tabela[0])
      strcpy(Tabela, "G3_SERIE_HIST_OTROS");
   strcpy(Retorno, Tabela);
}
