
CREATE UNIQUE INDEX pk_extctr
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
   );


ALTER TABLE WAREHOUSE.G3_EXTRT_SIG_CTRL
 ADD CONSTRAINT PK_EXTCTR
 PRIMARY KEY
 ( NU_FUENTE_INDCA_PERFM
  ,FC_GEN_FUENTE_INDCA_PERFM
 )
/
