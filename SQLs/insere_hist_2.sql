insert into G3_SERIE_HIST_INDCA_2 (Nu_indca_perfm, Nu_vision, Nu_instan_dimen__1,
Nu_instan_dimen__2,Nu_instan_dimen__3,Nu_instan_dimen__4,Nu_instan_dimen__5,Nu_instan_dimen__6,
Nu_instan_dimen__7,Nu_instan_dimen__8,Nu_instan_dimen__9,Nu_instan_dimen__10,Nu_instan_dimen__11,
Nu_instan_dimen__12,Nu_instan_dimen__13,Nu_instan_dimen__14,Nu_instan_dimen__15,Nu_instan_dimen__16,
fc_Refr_serie_hist, cd_grnl_serie_hist, ct_valor_serie_hist,nu_fuente_indca_perfm, fc_gen_fuente_indca_perfm)

(select Nu_indca_perfm, Nu_vision, Nu_instan_dimen__1,
Nu_instan_dimen__2,Nu_instan_dimen__3,Nu_instan_dimen__4,Nu_instan_dimen__5,Nu_instan_dimen__6,
Nu_instan_dimen__7,Nu_instan_dimen__8,Nu_instan_dimen__9,Nu_instan_dimen__10,Nu_instan_dimen__11,
Nu_instan_dimen__12,Nu_instan_dimen__13,Nu_instan_dimen__14,Nu_instan_dimen__15,Nu_instan_dimen__16,
fc_refr_movt, 'D', ct_indca_perfm_movt, nu_fuente_dato_movt, fc_gen_movt from g3_movt_serie_hist)