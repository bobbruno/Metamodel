CREATE INDEX pk_extdat
 ON g3_extrt_sig_dato
  ( nu_fuente_indca_perfm,
    fc_gen_fuente_indca_perfm,
    fc_refr_fuente_indca_perfm,
    nu_indca_perfm,
    cd_instan_dimen__1,
    cd_instan_dimen__2,
    cd_instan_dimen__3,
    cd_instan_dimen__4,
    cd_instan_dimen__5,
    cd_instan_dimen__6,
    cd_instan_dimen__7,
    cd_instan_dimen__8,
    cd_instan_dimen__9,
    cd_instan_dimen__10,
    cd_instan_dimen__11,
    cd_instan_dimen__12  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE WAREHOUSE_IDX
 STORAGE (
   INITIAL     100M
   NEXT        10M
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  512
   )
 UNRECOVERABLE;

CREATE INDEX pk_extctr
 ON g3_extrt_sig_ctrl
  ( nu_fuente_indca_perfm,
    fc_gen_fuente_indca_perfm  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE warehouse_idx
 STORAGE (
   INITIAL     20480
   NEXT        20480
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
 UNRECOVERABLE;

EXIT
