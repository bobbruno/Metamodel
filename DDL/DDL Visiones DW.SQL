
CREATE OR REPLACE VIEW warehouse.v_datos_con_vision (
   rowid_dado,
   nu_fuente_indca_perfm,
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
   cd_instan_dimen__12,
   cd_instan_dimen__13,
   cd_instan_dimen__14,
   cd_instan_dimen__15,
   cd_instan_dimen__16,
   ct_dato,
   cd_regs_recz,
   nu_vision,
   nu_dimen__1,
   nu_dimen__2,
   nu_dimen__3,
   nu_dimen__4,
   nu_dimen__5,
   nu_dimen__6,
   nu_dimen__7,
   nu_dimen__8,
   nu_dimen__9,
   nu_dimen__10,
   nu_dimen__11,
   nu_dimen__12,
   nu_dimen__13,
   nu_dimen__14,
   nu_dimen__15,
   nu_dimen__16 )
AS
(select a.ROWID ROWID_DADO, a.*, i.NU_VISION,
                     V.NU_DIMEN__1, V.NU_DIMEN__2,
                     V.NU_DIMEN__3, V.NU_DIMEN__4,
                     V.NU_DIMEN__5, V.NU_DIMEN__6,
                     V.NU_DIMEN__7, V.NU_DIMEN__8,
                     V.NU_DIMEN__9, V.NU_DIMEN__10,
                     V.NU_DIMEN__11, V.NU_DIMEN__12,
                     V.NU_DIMEN__13, V.NU_DIMEN__14,
                     V.NU_DIMEN__15, V.NU_DIMEN__16
                 from G3_EXTRT_SIG_DATO a,
                      G3_INDCA_PERFM i,
                      G3_VISION V
                 where v.NU_VISION = i.NU_VISION and
                       a.NU_INDCA_PERFM = i.NU_INDCA_PERFM)
/

CREATE OR REPLACE VIEW warehouse.v_indca_deriv_nivl (
   nu_nivl_indca_deriv,
   nu_indca_deriv )
AS
select max(level) NU_NIVL_INDCA_DERIV, nu_indca_perfm_dest NU_INDCA_DERIV
from g3_indca_perfm_indca_perfm
connect by nu_indca_perfm_orig = prior nu_indca_perfm_dest
group by nu_indca_perfm_dest
/

CREATE OR REPLACE VIEW warehouse.v_serie_hist (
   nu_indca_perfm,
   nu_vision,
   nu_instan_dimen__1,
   nu_instan_dimen__2,
   nu_instan_dimen__3,
   nu_instan_dimen__4,
   nu_instan_dimen__5,
   nu_instan_dimen__6,
   nu_instan_dimen__7,
   nu_instan_dimen__8,
   nu_instan_dimen__9,
   nu_instan_dimen__10,
   nu_instan_dimen__11,
   nu_instan_dimen__12,
   nu_instan_dimen__13,
   nu_instan_dimen__14,
   nu_instan_dimen__15,
   nu_instan_dimen__16,
   fc_refr_serie_hist,
   cd_grnl_serie_hist,
   ct_valor_serie_hist,
   nu_fuente_indca_perfm,
   fc_gen_fuente_indca_perfm )
AS
select "NU_INDCA_PERFM","NU_VISION","NU_INSTAN_DIMEN__1","NU_INSTAN_DIMEN__2","NU_INSTAN_DIMEN__3","NU_INSTAN_DIMEN__4","NU_INSTAN_DIMEN__5","NU_INSTAN_DIMEN__6","NU_INSTAN_DIMEN__7","NU_INSTAN_DIMEN__8","NU_INSTAN_DIMEN__9","NU_INSTAN_DIMEN__10","NU_INSTAN_DIMEN__11","NU_INSTAN_DIMEN__12","NU_INSTAN_DIMEN__13","NU_INSTAN_DIMEN__14","NU_INSTAN_DIMEN__15","NU_INSTAN_DIMEN__16","FC_REFR_SERIE_HIST","CD_GRNL_SERIE_HIST","CT_VALOR_SERIE_HIST","NU_FUENTE_INDCA_PERFM","FC_GEN_FUENTE_INDCA_PERFM" from G3_SERIE_HIST_INDCA union
select "NU_INDCA_PERFM","NU_VISION","NU_INSTAN_DIMEN__1","NU_INSTAN_DIMEN__2","NU_INSTAN_DIMEN__3","NU_INSTAN_DIMEN__4","NU_INSTAN_DIMEN__5","NU_INSTAN_DIMEN__6","NU_INSTAN_DIMEN__7","NU_INSTAN_DIMEN__8","NU_INSTAN_DIMEN__9","NU_INSTAN_DIMEN__10","NU_INSTAN_DIMEN__11","NU_INSTAN_DIMEN__12","NU_INSTAN_DIMEN__13","NU_INSTAN_DIMEN__14","NU_INSTAN_DIMEN__15","NU_INSTAN_DIMEN__16","FC_REFR_SERIE_HIST","CD_GRNL_SERIE_HIST","CT_VALOR_SERIE_HIST","NU_FUENTE_INDCA_PERFM","FC_GEN_FUENTE_INDCA_PERFM" from G3_SERIE_HIST_CONS_1 union
select "NU_INDCA_PERFM","NU_VISION","NU_INSTAN_DIMEN__1","NU_INSTAN_DIMEN__2","NU_INSTAN_DIMEN__3","NU_INSTAN_DIMEN__4","NU_INSTAN_DIMEN__5","NU_INSTAN_DIMEN__6","NU_INSTAN_DIMEN__7","NU_INSTAN_DIMEN__8","NU_INSTAN_DIMEN__9","NU_INSTAN_DIMEN__10","NU_INSTAN_DIMEN__11","NU_INSTAN_DIMEN__12","NU_INSTAN_DIMEN__13","NU_INSTAN_DIMEN__14","NU_INSTAN_DIMEN__15","NU_INSTAN_DIMEN__16","FC_REFR_SERIE_HIST","CD_GRNL_SERIE_HIST","CT_VALOR_SERIE_HIST","NU_FUENTE_INDCA_PERFM","FC_GEN_FUENTE_INDCA_PERFM" from G3_SERIE_HIST_INDCA_2
/

CREATE OR REPLACE VIEW warehouse.v_serie_hist_cons (
   nu_indca_perfm,
   nu_vision,
   nu_instan_dimen__1,
   nu_instan_dimen__2,
   nu_instan_dimen__3,
   nu_instan_dimen__4,
   nu_instan_dimen__5,
   nu_instan_dimen__6,
   nu_instan_dimen__7,
   nu_instan_dimen__8,
   nu_instan_dimen__9,
   nu_instan_dimen__10,
   nu_instan_dimen__11,
   nu_instan_dimen__12,
   nu_instan_dimen__13,
   nu_instan_dimen__14,
   nu_instan_dimen__15,
   nu_instan_dimen__16,
   fc_refr_serie_hist,
   cd_grnl_serie_hist,
   ct_valor_serie_hist,
   nu_fuente_indca_perfm,
   fc_gen_fuente_indca_perfm )
AS
select   "NU_INDCA_PERFM","NU_VISION","NU_INSTAN_DIMEN__1",
         "NU_INSTAN_DIMEN__2","NU_INSTAN_DIMEN__3","NU_INSTAN_DIMEN__4",
         "NU_INSTAN_DIMEN__5","NU_INSTAN_DIMEN__6","NU_INSTAN_DIMEN__7",
         "NU_INSTAN_DIMEN__8","NU_INSTAN_DIMEN__9","NU_INSTAN_DIMEN__10",
         "NU_INSTAN_DIMEN__11","NU_INSTAN_DIMEN__12","NU_INSTAN_DIMEN__13",
         "NU_INSTAN_DIMEN__14","NU_INSTAN_DIMEN__15","NU_INSTAN_DIMEN__16",
         "FC_REFR_SERIE_HIST","CD_GRNL_SERIE_HIST","CT_VALOR_SERIE_HIST",
         "NU_FUENTE_INDCA_PERFM","FC_GEN_FUENTE_INDCA_PERFM"
   from G3_SERIE_HIST_CONS_1
/

CREATE OR REPLACE VIEW warehouse.v_serie_hist_input (
   nu_indca_perfm,
   nu_vision,
   nu_instan_dimen__1,
   nu_instan_dimen__2,
   nu_instan_dimen__3,
   nu_instan_dimen__4,
   nu_instan_dimen__5,
   nu_instan_dimen__6,
   nu_instan_dimen__7,
   nu_instan_dimen__8,
   nu_instan_dimen__9,
   nu_instan_dimen__10,
   nu_instan_dimen__11,
   nu_instan_dimen__12,
   nu_instan_dimen__13,
   nu_instan_dimen__14,
   nu_instan_dimen__15,
   nu_instan_dimen__16,
   fc_refr_serie_hist,
   cd_grnl_serie_hist,
   ct_valor_serie_hist,
   nu_fuente_indca_perfm,
   fc_gen_fuente_indca_perfm )
AS
select "NU_INDCA_PERFM","NU_VISION","NU_INSTAN_DIMEN__1","NU_INSTAN_DIMEN__2","NU_INSTAN_DIMEN__3","NU_INSTAN_DIMEN__4","NU_INSTAN_DIMEN__5","NU_INSTAN_DIMEN__6","NU_INSTAN_DIMEN__7","NU_INSTAN_DIMEN__8","NU_INSTAN_DIMEN__9","NU_INSTAN_DIMEN__10","NU_INSTAN_DIMEN__11","NU_INSTAN_DIMEN__12","NU_INSTAN_DIMEN__13","NU_INSTAN_DIMEN__14","NU_INSTAN_DIMEN__15","NU_INSTAN_DIMEN__16","FC_REFR_SERIE_HIST","CD_GRNL_SERIE_HIST","CT_VALOR_SERIE_HIST","NU_FUENTE_INDCA_PERFM","FC_GEN_FUENTE_INDCA_PERFM" from G3_SERIE_HIST_INDCA union
select "NU_INDCA_PERFM","NU_VISION","NU_INSTAN_DIMEN__1","NU_INSTAN_DIMEN__2","NU_INSTAN_DIMEN__3","NU_INSTAN_DIMEN__4","NU_INSTAN_DIMEN__5","NU_INSTAN_DIMEN__6","NU_INSTAN_DIMEN__7","NU_INSTAN_DIMEN__8","NU_INSTAN_DIMEN__9","NU_INSTAN_DIMEN__10","NU_INSTAN_DIMEN__11","NU_INSTAN_DIMEN__12","NU_INSTAN_DIMEN__13","NU_INSTAN_DIMEN__14","NU_INSTAN_DIMEN__15","NU_INSTAN_DIMEN__16","FC_REFR_SERIE_HIST","CD_GRNL_SERIE_HIST","CT_VALOR_SERIE_HIST","NU_FUENTE_INDCA_PERFM","FC_GEN_FUENTE_INDCA_PERFM" from G3_SERIE_HIST_INDCA_2
/
