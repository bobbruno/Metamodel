SELECT  sum(ct_valor_serie_hist) 
 FROM G3_SERIE_HIST_INDCA
 where NU_FUENTE_INDCA_PERFM=5
  and NU_INSTAN_DIMEN__1=1
  and NU_INSTAN_DIMEN__3=1
  and NU_INSTAN_DIMEN__4=37
  and NU_INSTAN_DIMEN__5=1
  and fc_refr_serie_hist='01-oct-97'
