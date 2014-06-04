
CREATE TABLE warehouse.chained_rows
 (
  owner_name                 VARCHAR2(30),
  table_name                 VARCHAR2(30),
  cluster_name               VARCHAR2(30),
  head_rowid                 ROWID,
  timestamp                  DATE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  121
   )
/

CREATE TABLE warehouse.exceptions
 (
  row_id                     ROWID,
  owner                      VARCHAR2(30),
  table_name                 VARCHAR2(30),
  constraint                 VARCHAR2(30)
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        40960
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_area_infm
 (
  nu_area_infm               NUMBER(5) NOT NULL,
  nm_area_infm               VARCHAR2(30) NOT NULL,
  CONSTRAINT pk_areinf PRIMARY KEY (nu_area_infm) DISABLE,
  CONSTRAINT un_areinf UNIQUE (nm_area_infm) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_area_infm IS 'Areas de informacion por las quales los datos estan agrupados para mejor entendimento
    de los usuarios responsables por la alimentacion del Data Warehouse.'
/

COMMENT ON COLUMN warehouse.g3_area_infm.nm_area_infm IS 'Nombre del area de informacion.'
/
COMMENT ON COLUMN warehouse.g3_area_infm.nu_area_infm IS 'Secuencial identificador del area de informacion.'
/

CREATE UNIQUE INDEX warehouse.pk_areinf
 ON warehouse.g3_area_infm
  ( nu_area_infm  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE UNIQUE INDEX warehouse.un_areinf
 ON warehouse.g3_area_infm
  ( nm_area_infm  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_asu_infm
 (
  nu_asu_infm                NUMBER(5) NOT NULL,
  nu_area_infm               NUMBER(5) NOT NULL,
  nm_asu_infm                VARCHAR2(40) NOT NULL,
  CONSTRAINT pk_asuinf PRIMARY KEY (nu_asu_infm) DISABLE,
  CONSTRAINT un_asuinf UNIQUE (nm_asu_infm) DISABLE,
  CONSTRAINT fk_asuinf_areinf FOREIGN KEY (nu_area_infm)
      REFERENCES warehouse.g3_area_infm(nu_area_infm)  DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_asu_infm IS 'Asuntos (divisiones de las areas de informacion) por los cuales los datos estan agrupados
    para mejor entendimiento de los usuarios responsables por la alimentacion del Data Warehouse.'
/

COMMENT ON COLUMN warehouse.g3_asu_infm.nm_asu_infm IS 'Nombre do assunto.'
/
COMMENT ON COLUMN warehouse.g3_asu_infm.nu_area_infm IS 'Secuencial identificador del area de informacion a que pertenece el asunto.'
/
COMMENT ON COLUMN warehouse.g3_asu_infm.nu_asu_infm IS 'Secuencial identificador del asunto.'
/

CREATE UNIQUE INDEX warehouse.pk_asuinf
 ON warehouse.g3_asu_infm
  ( nu_asu_infm  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE UNIQUE INDEX warehouse.un_asuinf
 ON warehouse.g3_asu_infm
  ( nm_asu_infm  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_atrb_dimen
 (
  nu_dimen                   NUMBER(5) NOT NULL,
  nu_atrb_dimen              NUMBER(5) NOT NULL,
  nm_atrb_dimen              VARCHAR2(35) NOT NULL,
  cd_tipo_atrb_dimen         CHAR(1) NOT NULL,
  cd_cls_atrb_dimen          CHAR(1) NOT NULL,
  cd_atrb_valor_libre        CHAR(1) NOT NULL,
  ct_tamn_atrb_dimen         NUMBER(4) NOT NULL,
  CONSTRAINT pk_atrdim PRIMARY KEY (nu_dimen,nu_atrb_dimen) DISABLE,
  CONSTRAINT fk_atrdim_dimens FOREIGN KEY (nu_dimen)
      REFERENCES warehouse.g3_dimen(nu_dimen) ON DELETE CASCADE DISABLE,
  CONSTRAINT ck_atrdim_atrb_libre CHECK (Cd_Atrb_Valor_Libre in ('0', '1')) DISABLE,
  CONSTRAINT ck_atrdim_cd_cls CHECK (Cd_Cls_Atrb_Dimen IN ('U', 'C')) DISABLE,
  CONSTRAINT ck_atrdim_cd_tipo CHECK ( Cd_Tipo_Atrb_Dimen IN ('C', 'D', 'N')  ) DISABLE,
  CONSTRAINT ck_atrdim_tamn_atrb CHECK ((Cd_Tipo_Atrb_Dimen = 'C' and Ct_Tamn_Atrb_Dimen <= 2000) or       (Cd_Tipo_Atrb_Dimen = 'N' and Ct_Tamn_Atrb_Dimen <= 38) or       (Cd_Tipo_Atrb_Dimen = 'D' and Ct_Tamn_Atrb_Dimen = 10)) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_atrb_dimen IS 'Definicion de atributos de dimensiones. Un atributo es cualquer informacion
 que se quiera guardar sobre las instancias de dimension, como la direccion del cliente,
 si un terminal es mobil o portable, etc...'
/

COMMENT ON COLUMN warehouse.g3_atrb_dimen.cd_atrb_valor_libre IS 'Flag indicando si el atributo permite valores libres (1) o posee lista
 de valores (0).'
/
COMMENT ON COLUMN warehouse.g3_atrb_dimen.cd_cls_atrb_dimen IS 'Flag indicando si o atributo es una clase. Clases son exportadas para el
 multi-dimensional, y pueden ser usadas alla como criterio de seleccion.
 Classes tienen que tener listas de valores.'
/
COMMENT ON COLUMN warehouse.g3_atrb_dimen.cd_tipo_atrb_dimen IS 'Tipo de datos del atributo. Puede ser (C)aracter, (N)umerico ou (F)echa.'
/
COMMENT ON COLUMN warehouse.g3_atrb_dimen.ct_tamn_atrb_dimen IS 'Tama?o maximo del atributo de la dimension. Son respetados los limites
 de Oracle para caracteres e numeros, y fechas tienen siempre tama?o 10.'
/
COMMENT ON COLUMN warehouse.g3_atrb_dimen.nm_atrb_dimen IS 'Nombre del atributo.'
/
COMMENT ON COLUMN warehouse.g3_atrb_dimen.nu_atrb_dimen IS 'Identificador secuencial del atributo, unico para cada dimension.'
/
COMMENT ON COLUMN warehouse.g3_atrb_dimen.nu_dimen IS 'Identificador de la dimension a que el atributo pertenece.'
/

CREATE UNIQUE INDEX warehouse.pk_atrdim
 ON warehouse.g3_atrb_dimen
  ( nu_dimen,
    nu_atrb_dimen  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_base_cnst
 (
  nu_base_cnst               NUMBER(5) NOT NULL,
  nm_base_cnst               VARCHAR2(20) NOT NULL,
  sg_tipo_base_cnst          VARCHAR2(10) NOT NULL,
  nm_soft_util_base_cnst     VARCHAR2(20) NOT NULL,
  cd_grnl_min_base           CHAR(1) NOT NULL,
  ct_meses_base              NUMBER(3) NOT NULL,
  CONSTRAINT pk_bascns PRIMARY KEY (nu_base_cnst) DISABLE,
  CONSTRAINT un_bascns UNIQUE (nm_base_cnst) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_base_cnst IS 'Bases de consulta a partir de las cuales los usuarios acederan al Data Warehouse. Representa,
    por ejemplo, cada uno de los OLAPs que seran construidos sobre el Data Warehouse.'
/

COMMENT ON COLUMN warehouse.g3_base_cnst.nm_base_cnst IS 'Nombre de la base de consulta.'
/
COMMENT ON COLUMN warehouse.g3_base_cnst.nm_soft_util_base_cnst IS 'Nombre del software utilizado para implementar la base de consulta. LightShip Server,
    por ejemplo.'
/
COMMENT ON COLUMN warehouse.g3_base_cnst.nu_base_cnst IS 'Secuencial identificador de la base de consulta.'
/
COMMENT ON COLUMN warehouse.g3_base_cnst.sg_tipo_base_cnst IS 'Tipo de la base de consulta (Relacional, OLAP, Caches). Utilizado apenas
    para documentacion.'
/

CREATE UNIQUE INDEX warehouse.pk_bascns
 ON warehouse.g3_base_cnst
  ( nu_base_cnst  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE UNIQUE INDEX warehouse.un_bascns
 ON warehouse.g3_base_cnst
  ( nm_base_cnst  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_base_cnst_atrb_dimen
 (
  nu_base_cnst               NUMBER(5) NOT NULL,
  nu_dimen                   NUMBER(5) NOT NULL,
  nu_atrb_dimen              NUMBER(5) NOT NULL,
  CONSTRAINT pk_basatr PRIMARY KEY (nu_base_cnst,nu_dimen,nu_atrb_dimen) DISABLE,
  CONSTRAINT fk_basatr_atrdim FOREIGN KEY (nu_dimen,nu_atrb_dimen)
      REFERENCES warehouse.g3_atrb_dimen(nu_dimen,nu_atrb_dimen) ON DELETE CASCADE DISABLE,
  CONSTRAINT fk_basatr_basdim FOREIGN KEY (nu_base_cnst,nu_dimen)
      REFERENCES warehouse.g3_base_cnst_dimen(nu_base_cnst,nu_dimen) ON DELETE CASCADE DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_base_cnst_atrb_dimen IS 'Relacionamiento Base de Consulta x Atributo de Dimension. Indica cuales
 atributos deben ser importados para las bases de consulta.'
/

COMMENT ON COLUMN warehouse.g3_base_cnst_atrb_dimen.nu_atrb_dimen IS 'Identificador del atributo a importar para la base de consulta.'
/
COMMENT ON COLUMN warehouse.g3_base_cnst_atrb_dimen.nu_base_cnst IS 'Identificador de la base de consulta.'
/
COMMENT ON COLUMN warehouse.g3_base_cnst_atrb_dimen.nu_dimen IS 'Identificador de la dimension del atributo.'
/

CREATE UNIQUE INDEX warehouse.pk_basatr
 ON warehouse.g3_base_cnst_atrb_dimen
  ( nu_base_cnst,
    nu_dimen,
    nu_atrb_dimen  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_base_cnst_dimen
 (
  nu_base_cnst               NUMBER(5) NOT NULL,
  nu_dimen                   NUMBER(5) NOT NULL,
  nu_nivl_logc_min           NUMBER(2) DEFAULT 1 NOT NULL,
  nu_nivl_logc_max           NUMBER(2) DEFAULT 99 NOT NULL,
  fc_ult_gen_jrqc            DATE,
  CONSTRAINT pk_basdim PRIMARY KEY (nu_base_cnst,nu_dimen) DISABLE,
  CONSTRAINT fk_basdim_bascns FOREIGN KEY (nu_base_cnst)
      REFERENCES warehouse.g3_base_cnst(nu_base_cnst) ON DELETE CASCADE DISABLE,
  CONSTRAINT fk_basdim_dimens FOREIGN KEY (nu_dimen)
      REFERENCES warehouse.g3_dimen(nu_dimen) ON DELETE CASCADE DISABLE,
  CONSTRAINT fk_basdim_nivdim1 FOREIGN KEY (nu_dimen,nu_nivl_logc_min)
      REFERENCES warehouse.g3_nivl_logc_dimen(nu_dimen,nu_nivl_logc_dimen)  DISABLE,
  CONSTRAINT fk_basdim_nivdim2 FOREIGN KEY (nu_dimen,nu_nivl_logc_max)
      REFERENCES warehouse.g3_nivl_logc_dimen(nu_dimen,nu_nivl_logc_dimen)  DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_base_cnst_dimen IS 'Relacionamiento n x n entre bases de consulta y dimensiones. Restringe las
 dimensiones que seran importadas para cada base de consulta y informa los
 niveles logicos de estas que seran generados.'
/

COMMENT ON COLUMN warehouse.g3_base_cnst_dimen.nu_base_cnst IS 'Identificador de la base de consulta.'
/
COMMENT ON COLUMN warehouse.g3_base_cnst_dimen.nu_dimen IS 'Identificador de la dimension.'
/
COMMENT ON COLUMN warehouse.g3_base_cnst_dimen.nu_nivl_logc_max IS 'Identificador del nivel mas alto a importar para la base de consulta.
 El nivel mas alto possible es nivel 1. Este campo debe estar con um valor <= Nu_Nivl_Logc_Min.'
/
COMMENT ON COLUMN warehouse.g3_base_cnst_dimen.nu_nivl_logc_min IS 'Identificador del nivel mas bajo a importar para la base de consulta.
 El nivel mas alto es nivel 1. Este campo debe estar con um valor >= Nu_Nivl_Logc_Max.'
/

CREATE UNIQUE INDEX warehouse.pk_basdim
 ON warehouse.g3_base_cnst_dimen
  ( nu_base_cnst,
    nu_dimen  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_cnst_infm
 (
  nu_base_cnst               NUMBER(5) NOT NULL,
  nu_cnst_infm               NUMBER(5) NOT NULL,
  nm_cnst_infm               VARCHAR2(50) NOT NULL,
  CONSTRAINT pk_cnsinf PRIMARY KEY (nu_base_cnst,nu_cnst_infm) DISABLE,
  CONSTRAINT fk_cnsinf_bascns FOREIGN KEY (nu_base_cnst)
      REFERENCES warehouse.g3_base_cnst(nu_base_cnst)  DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_cnst_infm IS 'Consultas predefinidas que seran construidas a partir de las bases de consulta.
    Cada una de las pantallas construidas en LightShip (inclusive a de Ad-Hoc) es cadastrada
    en esta tabla.'
/

COMMENT ON COLUMN warehouse.g3_cnst_infm.nm_cnst_infm IS 'Nombre de la consulta.'
/
COMMENT ON COLUMN warehouse.g3_cnst_infm.nu_base_cnst IS 'Secuencial identificador de la base de consulta a la cual pertenece la consulta.'
/
COMMENT ON COLUMN warehouse.g3_cnst_infm.nu_cnst_infm IS 'Secuencial identificador de la consulta para una determinada base de consulta.'
/

CREATE UNIQUE INDEX warehouse.pk_cnsinf
 ON warehouse.g3_cnst_infm
  ( nu_base_cnst,
    nu_cnst_infm  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_cod_instan_dimen
 (
  nu_dimen                   NUMBER(5) NOT NULL,
  nu_instan_dimen            NUMBER(8) NOT NULL,
  cd_instan_dimen            VARCHAR2(20) NOT NULL,
  CONSTRAINT pk_codins PRIMARY KEY (nu_dimen,cd_instan_dimen) DISABLE,
  CONSTRAINT fk_codins_insdim FOREIGN KEY (nu_dimen,nu_instan_dimen)
      REFERENCES warehouse.g3_instan_dimen(nu_dimen,nu_instan_dimen) ON DELETE CASCADE DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     2097152
      NEXT        2097152
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

CREATE UNIQUE INDEX warehouse.pk_codins
 ON warehouse.g3_cod_instan_dimen
  ( nu_dimen,
    cd_instan_dimen  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     2097152
   NEXT        2097152
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_dato_extn
 (
  nu_fuente_dato_extn        NUMBER(5) NOT NULL,
  nu_dato_extn               NUMBER(5) NOT NULL,
  nm_dato_extn               VARCHAR2(240) NOT NULL,
  nu_asu_dato_extn           NUMBER(5) NOT NULL,
  nu_indca_perfm             NUMBER(5) NOT NULL,
  nu_vision                  NUMBER(5),
  nu_instan_dimen__1         NUMBER(8),
  nu_instan_dimen__2         NUMBER(8),
  nu_instan_dimen__3         NUMBER(8),
  nu_instan_dimen__4         NUMBER(8),
  nu_instan_dimen__5         NUMBER(8),
  nu_instan_dimen__6         NUMBER(8),
  nu_instan_dimen__7         NUMBER(8),
  nu_instan_dimen__8         NUMBER(8),
  nu_instan_dimen__9         NUMBER(8),
  nu_instan_dimen__10        NUMBER(8),
  nu_instan_dimen__11        NUMBER(8),
  nu_instan_dimen__12        NUMBER(8),
  nu_instan_dimen__13        NUMBER(8),
  nu_instan_dimen__14        NUMBER(8),
  nu_instan_dimen__15        NUMBER(8),
  nu_instan_dimen__16        NUMBER(8),
  nm_folder_recp             VARCHAR2(40),
  nm_cell_inic_recp          VARCHAR2(8),
  nu_ord_dato_extn           NUMBER(3),
  CONSTRAINT pk_datext PRIMARY KEY (nu_fuente_dato_extn,nu_dato_extn) DISABLE,
  CONSTRAINT fk_datext_asuinf FOREIGN KEY (nu_asu_dato_extn)
      REFERENCES warehouse.g3_asu_infm(nu_asu_infm)  DISABLE,
  CONSTRAINT fk_datext_fueind FOREIGN KEY (nu_fuente_dato_extn)
      REFERENCES warehouse.g3_fuente_indca_perfm(nu_fuente_indca_perfm) ON DELETE CASCADE DISABLE,
  CONSTRAINT fk_datext_indprf FOREIGN KEY (nu_indca_perfm)
      REFERENCES warehouse.g3_indca_perfm(nu_indca_perfm) ON DELETE CASCADE DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     65536
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_dato_extn IS 'Datos que componem cada fuente de datos. En el caso de fuentes de datos del tipo Sistema, esta
    tabla define que indicador es informado por cuales sistemas. En el caso de fuentes de datos
    del tipo Planilla o Manual, esta tabla compone un mapeamento'
/

COMMENT ON COLUMN warehouse.g3_dato_extn.nm_cell_inic_recp IS 'Apenas para fuentes de datos tipo Planilla. Indica la celda del folder
    NM_FOLDER_RECP de la planilla Excel donde el dato se ubica.
    Para planillas que apresentem valores historicos, este campo
    contendra la celda inicial del periodo.'
/
COMMENT ON COLUMN warehouse.g3_dato_extn.nm_dato_extn IS 'Nombre del dato externo, montado a partir del nombre del indicador, de la unidad de medida
    del indicador e de la instancia de vision (cuando for o caso) que componem el
    dato externo.'
/
COMMENT ON COLUMN warehouse.g3_dato_extn.nm_folder_recp IS 'Apenas para fuentes de datos tipo Planilla. Indica el
    folder de la planilla Excel donde el dato se ubica.'
/
COMMENT ON COLUMN warehouse.g3_dato_extn.nu_asu_dato_extn IS 'Secuencial identificador del asunto a lo cual pertenece el dato externo.'
/
COMMENT ON COLUMN warehouse.g3_dato_extn.nu_dato_extn IS 'Secuencial identificador del dato externo para aquella fuente de datos.'
/
COMMENT ON COLUMN warehouse.g3_dato_extn.nu_fuente_dato_extn IS 'Secuencial identificador de la fuente de datos a la cual pertenece el dato externo.'
/
COMMENT ON COLUMN warehouse.g3_dato_extn.nu_indca_perfm IS 'Secuencial identificador del indicador que compone el dato externo.'
/
COMMENT ON COLUMN warehouse.g3_dato_extn.nu_ord_dato_extn IS 'Apenas para fuente de datos tipo Manual o Planilla. Indica la orden
    de presentacion del dato en el programa de Input Manual de Datos.'
/
COMMENT ON COLUMN warehouse.g3_dato_extn.nu_vision IS 'apenas para fuentes de datos de los tipos Manual o Planilla.
    Parte de la clave de la instancia de vision que compone el dato externo.'
/

CREATE UNIQUE INDEX warehouse.pk_datext
 ON warehouse.g3_dato_extn
  ( nu_fuente_dato_extn,
    nu_dato_extn  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     65536
   NEXT        8192
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_dimen
 (
  nu_dimen                   NUMBER(5) NOT NULL,
  nm_dimen                   VARCHAR2(35) NOT NULL,
  cd_cons_jrqc               CHAR(1) DEFAULT '0' NOT NULL,
  cd_cache_dimen             CHAR(1) DEFAULT '0' NOT NULL,
  CONSTRAINT pk_dimens PRIMARY KEY (nu_dimen) DISABLE,
  CONSTRAINT un_dimens UNIQUE (nm_dimen) DISABLE,
  CONSTRAINT ckdimens_cd_cons CHECK (Cd_Cons_Jrqc in ('0', '1')) DISABLE,
  CONSTRAINT ck_dimens_cd_cons CHECK ( CD_CONS_JRQC IN ('0', '1')) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_dimen IS 'Dimensiones sobre las quales el negocio es analisado. Ex : Vendedor, Cliente, Producto.'
/

COMMENT ON COLUMN warehouse.g3_dimen.cd_cache_dimen IS 'Flag de cache para las instancias de la dimensión'
/
COMMENT ON COLUMN warehouse.g3_dimen.cd_cons_jrqc IS 'Informa si la dimension tiene consolidacion jerarquica.'
/
COMMENT ON COLUMN warehouse.g3_dimen.nm_dimen IS 'Nombre de la dimension.'
/
COMMENT ON COLUMN warehouse.g3_dimen.nu_dimen IS 'Secuencial identificador de la dimension.'
/

CREATE UNIQUE INDEX warehouse.pk_dimens
 ON warehouse.g3_dimen
  ( nu_dimen  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE UNIQUE INDEX warehouse.un_dimens
 ON warehouse.g3_dimen
  ( nm_dimen  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_extrt_sig_atrb
 (
  nu_dimen                   NUMBER(5) NOT NULL,
  nu_atrb_dimen              NUMBER(5) NOT NULL,
  cd_instan_dimen            VARCHAR2(20) NOT NULL,
  tx_valor_atrb_dimen        VARCHAR2(2000) NOT NULL,
  fc_ult_atual_instan_atrb   DATE NOT NULL,
  nu_nivl_logc_dimen         NUMBER(5)
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE interfase
 STORAGE   (
      INITIAL     4194304
      NEXT        4194304
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  256
   )
/

GRANT DELETE,INSERT,SELECT,UPDATE ON warehouse.g3_extrt_sig_atrb TO ods
/

CREATE TABLE warehouse.g3_extrt_sig_ctrl
 (
  nu_fuente_indca_perfm      NUMBER(5) NOT NULL,
  fc_gen_fuente_indca_perfm  DATE NOT NULL,
  fc_refr_fuente_indca_perfm  DATE,
  ct_regs_import             NUMBER(9),
  cd_proc_sist               CHAR(1),
  CONSTRAINT pk_extctr PRIMARY KEY (nu_fuente_indca_perfm,fc_gen_fuente_indca_perfm) DISABLE,
  CONSTRAINT ck_extctr_cd_proc_sist CHECK (Cd_Proc_Sist IN ('0','1')) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_extrt_sig_ctrl IS 'Tabla temporaria utilizada por el importador de datos de sistemas para controle del
    procesamiento. En el caso de datos que son disponibilizados a traves de
    tablas temporarias, los registro son grabados por los extratores.'
/

COMMENT ON COLUMN warehouse.g3_extrt_sig_ctrl.cd_proc_sist IS '0 - El lote no fue seleccionado para importacion
    1 - El lote fue seleccionado para importacion.'
/
COMMENT ON COLUMN warehouse.g3_extrt_sig_ctrl.ct_regs_import IS 'Cantidad de registros importados.'
/
COMMENT ON COLUMN warehouse.g3_extrt_sig_ctrl.fc_gen_fuente_indca_perfm IS 'Fecha de generacion de la fuente de datos procesada.'
/
COMMENT ON COLUMN warehouse.g3_extrt_sig_ctrl.fc_refr_fuente_indca_perfm IS 'Fecha de referencia de la fuente de datos procesada.'
/
COMMENT ON COLUMN warehouse.g3_extrt_sig_ctrl.nu_fuente_indca_perfm IS 'Secuencial identificador de la fuente de datos procesada.'
/

GRANT DELETE,INSERT,SELECT,UPDATE ON warehouse.g3_extrt_sig_ctrl TO ods
/

CREATE UNIQUE INDEX warehouse.pk_extctr
 ON warehouse.g3_extrt_sig_ctrl
  ( nu_fuente_indca_perfm,
    fc_gen_fuente_indca_perfm  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_extrt_sig_dato
 (
  nu_fuente_indca_perfm      NUMBER(5) NOT NULL,
  fc_gen_fuente_indca_perfm  DATE NOT NULL,
  fc_refr_fuente_indca_perfm  DATE NOT NULL,
  nu_indca_perfm             NUMBER(5) NOT NULL,
  cd_instan_dimen__1         VARCHAR2(20) NOT NULL,
  cd_instan_dimen__2         VARCHAR2(20) NOT NULL,
  cd_instan_dimen__3         VARCHAR2(20) NOT NULL,
  cd_instan_dimen__4         VARCHAR2(20) NOT NULL,
  cd_instan_dimen__5         VARCHAR2(20) NOT NULL,
  cd_instan_dimen__6         VARCHAR2(20) NOT NULL,
  cd_instan_dimen__7         VARCHAR2(20) NOT NULL,
  cd_instan_dimen__8         VARCHAR2(20) NOT NULL,
  cd_instan_dimen__9         VARCHAR2(20) NOT NULL,
  cd_instan_dimen__10        VARCHAR2(20) NOT NULL,
  cd_instan_dimen__11        VARCHAR2(20) NOT NULL,
  cd_instan_dimen__12        VARCHAR2(20) NOT NULL,
  cd_instan_dimen__13        VARCHAR2(20) NOT NULL,
  cd_instan_dimen__14        VARCHAR2(20) NOT NULL,
  cd_instan_dimen__15        VARCHAR2(20) NOT NULL,
  cd_instan_dimen__16        VARCHAR2(20) NOT NULL,
  ct_dato                    NUMBER(25,7) NOT NULL,
  cd_regs_recz               CHAR(1) NOT NULL
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE interfase
 STORAGE   (
      INITIAL     4194304
      NEXT        4194304
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  121
   )
/

GRANT DELETE,INSERT,SELECT,UPDATE ON warehouse.g3_extrt_sig_dato TO ods
/

CREATE TABLE warehouse.g3_extrt_sig_jrqc
 (
  nu_dimen                   NUMBER(5) NOT NULL,
  cd_instan_dimen_padre      VARCHAR2(20) NOT NULL,
  cd_instan_dimen_hijo       VARCHAR2(20) NOT NULL
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE interfase
 STORAGE   (
      INITIAL     2097152
      NEXT        2097152
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  256
   )
/

GRANT DELETE,INSERT,SELECT,UPDATE ON warehouse.g3_extrt_sig_jrqc TO ods
/

CREATE TABLE warehouse.g3_fuente_indca_perfm
 (
  nu_fuente_indca_perfm      NUMBER(5) NOT NULL,
  cd_tipo_orig_fuente_indca  CHAR(1) NOT NULL,
  nm_fuente_indca_perfm      VARCHAR2(40) NOT NULL,
  nu_prvd_dato               NUMBER(5) NOT NULL,
  cd_grnl_fuente_indca_perfm  CHAR(1),
  cd_hist_fuente_indca_perfm  CHAR(1),
  cd_orgn_tiempo_fuente_indca  CHAR(1),
  cd_peri_recp_fuente_indca  CHAR(1),
  ct_tiempo_carga_fuente_indca  NUMBER(5,2),
  cd_tipo_impt_fuente_indca  CHAR(1),
  cd_situa_fuente_indca_perfm  CHAR(1) DEFAULT '1' NOT NULL,
  nu_perfil_resp_fuente_indca  NUMBER(5),
  CONSTRAINT pk_fueind PRIMARY KEY (nu_fuente_indca_perfm) DISABLE,
  CONSTRAINT fk_fueind_perfil FOREIGN KEY (nu_perfil_resp_fuente_indca)
      REFERENCES warehouse.g3_perfil_usuario(nu_perf_usua)  DISABLE,
  CONSTRAINT fk_fueind_prvdat FOREIGN KEY (nu_prvd_dato)
      REFERENCES warehouse.g3_prvd_dato(nu_prvd_dato)  DISABLE,
  CONSTRAINT ck_fueind_cd_grnl CHECK (Cd_Grnl_Fuente_Indca_Perfm IN ('H', 'D','S','M','A')) DISABLE,
  CONSTRAINT ck_fueind_cd_hist CHECK (Cd_Hist_Fuente_Indca_Perfm IN ('0','1')) DISABLE,
  CONSTRAINT ck_fueind_cd_orgn_tiempo CHECK (Cd_Orgn_Tiempo_Fuente_Indca IN ('L','C')) DISABLE,
  CONSTRAINT ck_fueind_cd_peri_recp CHECK (Cd_Peri_Recp_Fuente_Indca IN ('1','2')) DISABLE,
  CONSTRAINT ck_fueind_cd_situa CHECK (Cd_Situa_Fuente_Indca_Perfm IN ('0','1')) DISABLE,
  CONSTRAINT ck_fueind_cd_tipo_impt CHECK (Cd_Tipo_Impt_Fuente_Indca IN ('A','T')) DISABLE,
  CONSTRAINT ck_fueind_cd_tipo_orig CHECK (Cd_Tipo_Orig_Fuente_Indca IN ('P','S','M','R')) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_fuente_indca_perfm IS 'Fuentes de datos del Data Warehouse. Medios por los cuales los proveedores informam los
    datos para el Data Warehouse.'
/

COMMENT ON COLUMN warehouse.g3_fuente_indca_perfm.cd_grnl_fuente_indca_perfm IS 'Granularidade de la fuente de datos. Apenas para fuentes del tipo Planilla o
    Manual.
    H - Horaria (datos abiertos hora a hora)
    D - Diaria (datos abiertos dia a dia)
    M - Mensal (datos abiertos mes a mes)
    S - Semanal (datos abiertos seman'
/
COMMENT ON COLUMN warehouse.g3_fuente_indca_perfm.cd_hist_fuente_indca_perfm IS 'Apenas para fuentes de datos del tipo Planilla.
    0 - no apresenta valores historicos (solo apresenta un dia o un mes, por ejemplo)
    1 - apresenta valores historicos (apresenta un a?o abierto en meses, por ejemplo).'
/
COMMENT ON COLUMN warehouse.g3_fuente_indca_perfm.cd_orgn_tiempo_fuente_indca IS 'Apenas para fuentes de datos del tipo Planilla que apresentem valores
    historicos. Indica la disposicion del tiempo en la planilla.
    L - El tiempo esta disposto en las lineas
    C - El tiempo esta disposto en las columnas.'
/
COMMENT ON COLUMN warehouse.g3_fuente_indca_perfm.cd_peri_recp_fuente_indca IS 'Apenas para fuentes de datos del tipo Planilla que apresentem valores
    historicos. Indica como los datos de la planilla seran leidos :
    1 - Es siempre recuperado el periodo completo (definido por Ct_Tiempo_Carga_Fuente_Indca)
    2 - Es recuperado a'
/
COMMENT ON COLUMN warehouse.g3_fuente_indca_perfm.cd_situa_fuente_indca_perfm IS 'Situacion de la funte de datos.
    0 - Fuente desabilitada (no considerada en las interfaces de importacion de datos)
    1 - Fuente habilitada (considerada en las interfaces de importacion de datos).'
/
COMMENT ON COLUMN warehouse.g3_fuente_indca_perfm.cd_tipo_impt_fuente_indca IS 'Apenas para fuentes de datos del tipo Sistema. Indica el modo como los datos
    seran disponibilizados para el Data Warehouse.
    A - Archivo texto
    T - Tabla Temporaria.'
/
COMMENT ON COLUMN warehouse.g3_fuente_indca_perfm.cd_tipo_orig_fuente_indca IS 'Tipo da fuente de datos.
    P - Planilla
    S - Sistema
    M - Entrada Manual
    R - Server.'
/
COMMENT ON COLUMN warehouse.g3_fuente_indca_perfm.ct_tiempo_carga_fuente_indca IS 'Apenas para fuentes de datos del tipo Planilla que apresentem valores
    historicos. Indica cuanto tiempo (en meses) sera considerado en el momento de la carga.'
/
COMMENT ON COLUMN warehouse.g3_fuente_indca_perfm.nm_fuente_indca_perfm IS 'Nombre de la fuente de datos.'
/
COMMENT ON COLUMN warehouse.g3_fuente_indca_perfm.nu_fuente_indca_perfm IS 'Secuencial identificador de la fuente de datos.'
/
COMMENT ON COLUMN warehouse.g3_fuente_indca_perfm.nu_perfil_resp_fuente_indca IS 'Secuencial identificador del perfil de usuario responsable por la importacion de la
    fuente de datos.'
/
COMMENT ON COLUMN warehouse.g3_fuente_indca_perfm.nu_prvd_dato IS 'Secuencial identificador del proveedor responsable por la fuente de datos.'
/

GRANT SELECT ON warehouse.g3_fuente_indca_perfm TO ods
/

GRANT REFERENCES(nu_fuente_indca_perfm) ON warehouse.g3_fuente_indca_perfm TO ods
/

CREATE INDEX warehouse.ix_fueind01
 ON warehouse.g3_fuente_indca_perfm
  ( nu_perfil_resp_fuente_indca  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros
 STORAGE (
   INITIAL     24576
   NEXT        24576
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE UNIQUE INDEX warehouse.pk_fueind
 ON warehouse.g3_fuente_indca_perfm
  ( nu_fuente_indca_perfm  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_indca_cnst_infm
 (
  nu_base_cnst               NUMBER(5) NOT NULL,
  nu_cnst_infm               NUMBER(5) NOT NULL,
  nu_indca_perfm             NUMBER(5) NOT NULL,
  CONSTRAINT pk_indcon PRIMARY KEY (nu_base_cnst,nu_cnst_infm,nu_indca_perfm) DISABLE,
  CONSTRAINT fk_indcon_cnsinf FOREIGN KEY (nu_base_cnst,nu_cnst_infm)
      REFERENCES warehouse.g3_cnst_infm(nu_base_cnst,nu_cnst_infm) ON DELETE CASCADE DISABLE,
  CONSTRAINT fk_indcon_indprf FOREIGN KEY (nu_indca_perfm)
      REFERENCES warehouse.g3_indca_perfm(nu_indca_perfm) ON DELETE CASCADE DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     65536
      NEXT        8192
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_indca_cnst_infm IS 'Define que indicadores estan en cuales consultas. A traves de este relacionamiento
    se define cuales los indicadores que deben ser cargados para una determinada base
    de consulta.'
/

COMMENT ON COLUMN warehouse.g3_indca_cnst_infm.nu_base_cnst IS 'Secuencial identificador de la base de consulta a la cual pertenece la consulta.'
/
COMMENT ON COLUMN warehouse.g3_indca_cnst_infm.nu_cnst_infm IS 'Secuencial identificador de la consulta.'
/
COMMENT ON COLUMN warehouse.g3_indca_cnst_infm.nu_indca_perfm IS 'Secuencial identificador del indicador asociado a la consulta.'
/

CREATE UNIQUE INDEX warehouse.pk_indcon
 ON warehouse.g3_indca_cnst_infm
  ( nu_base_cnst,
    nu_cnst_infm,
    nu_indca_perfm  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     40960
   NEXT        8192
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_indca_perfm
 (
  nu_indca_perfm             NUMBER(5) NOT NULL,
  nm_indca_perfm             VARCHAR2(60) NOT NULL,
  nm_abrev_indca_perfm       VARCHAR2(24),
  tx_indca_perfm             VARCHAR2(500),
  nu_vision                  NUMBER(5) NOT NULL,
  cd_grnl_indca_perfm        CHAR(1) NOT NULL,
  ct_dias_perm_indca_perfm   NUMBER(5),
  ct_sem_perm_indca_perfm    NUMBER(5),
  ct_meses_perm_indca_perfm  NUMBER(5),
  ct_anos_perm_indca_perfm   NUMBER(5),
  nu_unid_medd               NUMBER(5) NOT NULL,
  cd_metd_cons_jrqc          VARCHAR2(10) NOT NULL,
  cd_metd_cons_tiempo        VARCHAR2(10) NOT NULL,
  cd_indca_dato_extn         CHAR(1) DEFAULT '0' NOT NULL,
  cd_tipo_indca_perfm        CHAR(2) NOT NULL,
  nm_rutn_calc               VARCHAR2(80),
  fc_ult_atual_indca         DATE,
  cd_indca_atual             CHAR(1),
  fc_lim_inf_indca           DATE,
  fc_lim_sup_indca           DATE,
  CONSTRAINT pk_indprf PRIMARY KEY (nu_indca_perfm) DISABLE,
  CONSTRAINT un_indprf UNIQUE (nm_indca_perfm,nu_unid_medd,cd_grnl_indca_perfm) DISABLE,
  CONSTRAINT fk_indprf_unimed FOREIGN KEY (nu_unid_medd)
      REFERENCES warehouse.g3_unid_medd(nu_unid_medd)  DISABLE,
  CONSTRAINT fk_indprf_vision FOREIGN KEY (nu_vision)
      REFERENCES warehouse.g3_vision(nu_vision)  DISABLE,
  CONSTRAINT ck_indprf_cd_grnl CHECK (Cd_Grnl_Indca_Perfm IN ('H', 'D', 'S', 'M', 'A')) DISABLE,
  CONSTRAINT ck_indprf_cd_indca_dato_extn CHECK (Cd_Indca_Dato_Extn IN ('0','1')) DISABLE,
  CONSTRAINT ck_indprf_cd_metd_cons_jrqc CHECK (Cd_Metd_Cons_Jrqc IN ('SUM','AVG','SC')) DISABLE,
  CONSTRAINT ck_indprf_cd_metd_cons_tiempo CHECK (Cd_Metd_Cons_Tiempo IN ('SUM','AVG','FIRST', 'LAST')) DISABLE,
  CONSTRAINT ck_indprf_cd_tipo CHECK (Cd_Tipo_Indca_Perfm IN ('IM', 'CC', 'CF', 'CD')) DISABLE,
  CONSTRAINT ck_indprf_nm_rutn_calc CHECK (Cd_Tipo_Indca_Perfm != 'IM' OR Nm_Rutn_Calc IS NULL) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     262144
      NEXT        32768
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_indca_perfm IS 'Indicadores de desempeño. Representam las variables por las quales el negocio es analisado.
    Define QUE datos seran almacenados en el Data Warehouse.'
/

COMMENT ON COLUMN warehouse.g3_indca_perfm.cd_grnl_indca_perfm IS 'Granularidad del indicador. Define el nivel de detalle de tempo en que los
    datos de aquel indicador seran almacenados en el Data Warehouse.
    H - Horaria (valores abertos hora a hora)
    D - Diaria (valores abertos dia a dia)
    M - Mensual (valor'
/
COMMENT ON COLUMN warehouse.g3_indca_perfm.cd_indca_dato_extn IS '0 - El indicador no esta asociado a ningun dato externo    1 - El indicador esta asociado a por lo menos uno dato externo.'
/
COMMENT ON COLUMN warehouse.g3_indca_perfm.cd_metd_cons_jrqc IS 'Metodo de consolidacion de los valores del indicador en las jerarquias de dimension.    SUM - Soma    AVG - Media    SC - Sin Consolidacao.'
/
COMMENT ON COLUMN warehouse.g3_indca_perfm.cd_metd_cons_tiempo IS 'Metodo de consolidacion de los valores del indicador en el tiempo.    SUM - Soma    AVG - Media    FIRST - Primero valor del intervalo    LAST - Ultimo valor del intervalo.'
/
COMMENT ON COLUMN warehouse.g3_indca_perfm.cd_tipo_indca_perfm IS 'Tipo del indicador.    IM - Importado via interface con sistemas, planillas o entrada manual.    CC - Calculado, con consolidacion.
    CF - Calculado, sin consolidacion
    CD - Calculado en el Datamart'
/
COMMENT ON COLUMN warehouse.g3_indca_perfm.ct_anos_perm_indca_perfm IS 'Cantidad de a?os que los valores anuales de aquel indicador quedaran almacenados en el Data Warehouse.'
/
COMMENT ON COLUMN warehouse.g3_indca_perfm.ct_dias_perm_indca_perfm IS 'Cantidad de dias que los valores diarios de aquel indicador quedaran almacenados en el Data Warehouse.'
/
COMMENT ON COLUMN warehouse.g3_indca_perfm.ct_meses_perm_indca_perfm IS 'Cantidad de meses que los valores mensuales de aquel indicador quedaran almacenados en el Data Warehouse.'
/
COMMENT ON COLUMN warehouse.g3_indca_perfm.ct_sem_perm_indca_perfm IS 'Cantidad de semanas que los valores semanales de aquel indicador quedaran almacenados en el Data Warehouse.'
/
COMMENT ON COLUMN warehouse.g3_indca_perfm.nm_abrev_indca_perfm IS 'Nombre abreviado del indicador (hasta 24 posiciones). Corresponde al short-name de la variable en Server.'
/
COMMENT ON COLUMN warehouse.g3_indca_perfm.nm_indca_perfm IS 'Nombre del indicador de desempeño.'
/
COMMENT ON COLUMN warehouse.g3_indca_perfm.nu_indca_perfm IS 'Secuencial identificador del indicador de desempe?o.'
/
COMMENT ON COLUMN warehouse.g3_indca_perfm.nu_unid_medd IS 'Secuencial identificador de la unidade de medida en que los valores del indicador
    estan almacenados en el Data Warehouse.'
/
COMMENT ON COLUMN warehouse.g3_indca_perfm.nu_vision IS 'Vision de negocio a la cual el indicador pertenece. Define el nivel de abertura (de
    dimensiones) en que los datos de aquel indicador seran almacenados en el Data Warehouse'
/
COMMENT ON COLUMN warehouse.g3_indca_perfm.tx_indca_perfm IS 'Descripcion del indicador de desempe?o (glosario).'
/

CREATE UNIQUE INDEX warehouse.pk_indprf
 ON warehouse.g3_indca_perfm
  ( nu_indca_perfm  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     65536
   NEXT        8192
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE UNIQUE INDEX warehouse.un_indprf
 ON warehouse.g3_indca_perfm
  ( nm_indca_perfm,
    nu_unid_medd,
    cd_grnl_indca_perfm  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     163840
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_indca_perfm_indca_perfm
 (
  nu_indca_perfm_orig        NUMBER(5) NOT NULL,
  nu_indca_perfm_dest        NUMBER(5) NOT NULL,
  CONSTRAINT pk_inpinp PRIMARY KEY (nu_indca_perfm_orig,nu_indca_perfm_dest) DISABLE,
  CONSTRAINT fk_inpinp_indprf_01 FOREIGN KEY (nu_indca_perfm_orig)
      REFERENCES warehouse.g3_indca_perfm(nu_indca_perfm)  DISABLE,
  CONSTRAINT fk_inpinp_indprf_02 FOREIGN KEY (nu_indca_perfm_dest)
      REFERENCES warehouse.g3_indca_perfm(nu_indca_perfm) ON DELETE CASCADE DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  121
   )
/

CREATE UNIQUE INDEX warehouse.pk_inpinp
 ON warehouse.g3_indca_perfm_indca_perfm
  ( nu_indca_perfm_orig,
    nu_indca_perfm_dest  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        8192
   PCTINCREASE 50
   MINEXTENTS  1
   MAXEXTENTS  121
   )
/

CREATE TABLE warehouse.g3_instan_atrb_dimen
 (
  nu_dimen                   NUMBER(5) NOT NULL,
  nu_atrb_dimen              NUMBER(5) NOT NULL,
  nu_instan_dimen            NUMBER(8) NOT NULL,
  tx_valor_atrb_dimen        VARCHAR2(2000) NOT NULL,
  fc_ult_atual_instan_atrb   DATE NOT NULL,
  CONSTRAINT pk_insatr PRIMARY KEY (nu_dimen,nu_instan_dimen,nu_atrb_dimen) DISABLE,
  CONSTRAINT fk_insatr_atrdim FOREIGN KEY (nu_dimen,nu_atrb_dimen)
      REFERENCES warehouse.g3_atrb_dimen(nu_dimen,nu_atrb_dimen)  DISABLE,
  CONSTRAINT fk_insatr_insdim FOREIGN KEY (nu_dimen,nu_instan_dimen)
      REFERENCES warehouse.g3_instan_dimen(nu_dimen,nu_instan_dimen)  DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     2097152
      NEXT        1048576
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_instan_atrb_dimen IS 'Instancias de atributos de dimensiones. Cada atributo puede asumir un valor
 para cada instancia de la dimension a que el esta asociado. Estos valores
 ficam almacenados en esta tabla.'
/

COMMENT ON COLUMN warehouse.g3_instan_atrb_dimen.fc_ult_atual_instan_atrb IS 'Fecha de la ultima atualizacion de la instancia del atributo de la dimension.'
/
COMMENT ON COLUMN warehouse.g3_instan_atrb_dimen.nu_atrb_dimen IS 'Identificador del atributo de la dimension.'
/
COMMENT ON COLUMN warehouse.g3_instan_atrb_dimen.nu_dimen IS 'Identificador unico de la dimension de la instancia del atributo.'
/
COMMENT ON COLUMN warehouse.g3_instan_atrb_dimen.nu_instan_dimen IS 'Identificador de la instancia de la dimension a que el valor del
 atributo esta asociado.'
/
COMMENT ON COLUMN warehouse.g3_instan_atrb_dimen.tx_valor_atrb_dimen IS 'Valor de la instancia del atributo de la dimension.'
/

CREATE INDEX warehouse.ix_insatr01
 ON warehouse.g3_instan_atrb_dimen
  ( nu_dimen,
    nu_atrb_dimen  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     1048576
   NEXT        1048576
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE UNIQUE INDEX warehouse.pk_insatr
 ON warehouse.g3_instan_atrb_dimen
  ( nu_dimen,
    nu_instan_dimen,
    nu_atrb_dimen  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     1048576
   NEXT        516096
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  2048
   )
/

CREATE TABLE warehouse.g3_instan_dimen
 (
  nu_dimen                   NUMBER(5) NOT NULL,
  nu_instan_dimen            NUMBER(8) NOT NULL,
  nm_instan_dimen            VARCHAR2(24) NOT NULL,
  fc_ult_atual_instan_dimen  DATE NOT NULL,
  cd_jrqc_instan_dimen       CHAR(1) NOT NULL,
  nu_nivl_instan_dimen       NUMBER(2) DEFAULT 1 NOT NULL,
  nu_nivl_logc_dimen         NUMBER(2),
  CONSTRAINT pk_insdim PRIMARY KEY (nu_dimen,nu_instan_dimen) DISABLE,
  CONSTRAINT un_insdim01 UNIQUE (nu_dimen,nu_nivl_logc_dimen,nu_instan_dimen) DISABLE,
  CONSTRAINT fk_insdim_dimens FOREIGN KEY (nu_dimen)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE,
  CONSTRAINT fk_insdim_nivdim FOREIGN KEY (nu_dimen,nu_nivl_logc_dimen)
      REFERENCES warehouse.g3_nivl_logc_dimen(nu_dimen,nu_nivl_logc_dimen)  DISABLE,
  CONSTRAINT ck_insdim_cd_jrqc CHECK (Cd_Jrqc_Instan_Dimen IN ('0','1')) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     4194304
      NEXT        2097152
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_instan_dimen IS 'Ocorrencias de las dimensiones, independientemente del nivel en la jerarquia. Para la dimension Cliente, por ejemplo, esta tabla contendra de manera indistinta los canales, subcanales y los clientes.'
/

COMMENT ON COLUMN warehouse.g3_instan_dimen.cd_jrqc_instan_dimen IS '0 - La instancia no posee hijos en la jerarquia    1 - La instancia posee hijos en la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_instan_dimen.fc_ult_atual_instan_dimen IS 'Fecha de la ultima alteracion realizada en la instancia de dimension.'
/
COMMENT ON COLUMN warehouse.g3_instan_dimen.nm_instan_dimen IS 'Nombre de la instancia de dimension.'
/
COMMENT ON COLUMN warehouse.g3_instan_dimen.nu_dimen IS 'Identificador de la dimension a que la instancia pertenece.'
/
COMMENT ON COLUMN warehouse.g3_instan_dimen.nu_instan_dimen IS 'Identificador de la instancia para una determinada dimension.'
/
COMMENT ON COLUMN warehouse.g3_instan_dimen.nu_nivl_instan_dimen IS 'Nivel fisico de la instancia en la jerarquia de la dimension, donde 1 indica que la instancia esta en el topo del arbol, o sea, no esta subordinada a ninguna otra instancia.'
/
COMMENT ON COLUMN warehouse.g3_instan_dimen.nu_nivl_logc_dimen IS 'Secuencial identificador del nivel logico de la dimension a que la instancia pertenece'
/

CREATE OR REPLACE TRIGGER warehouse.t_bdr_insdim_01
BEFORE  DELETE
ON warehouse.g3_instan_dimen
REFERENCING NEW AS NEW OLD AS OLD
FOR EACH ROW
declare
   CHILD_FOUND EXCEPTION;
   pragma exception_init(CHILD_FOUND, -2292);
begin
   if not Del_Instan_Ok(:old.NU_DIMEN, :old.NU_NIVL_LOGC_DIMEN, :old.NU_INSTAN_DIMEN) then
      raise CHILD_FOUND;
   end if;
end;
/

CREATE INDEX warehouse.ix_insdim01
 ON warehouse.g3_instan_dimen
  ( nu_dimen,
    nm_instan_dimen  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     2097152
   NEXT        2097152
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE UNIQUE INDEX warehouse.pk_insdim
 ON warehouse.g3_instan_dimen
  ( nu_dimen,
    nu_instan_dimen  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     2097152
   NEXT        1048576
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE UNIQUE INDEX warehouse.un_insdim01
 ON warehouse.g3_instan_dimen
  ( nu_dimen,
    nu_nivl_logc_dimen,
    nu_instan_dimen  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     2097152
   NEXT        1048576
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  121
   )
/

CREATE TABLE warehouse.g3_instan_dimen_desc
 (
  nu_dimen                   NUMBER(5) NOT NULL,
  cd_instan_dimen            VARCHAR2(20) NOT NULL,
  nu_fuente_indca_perfm      NUMBER(5) NOT NULL,
  ct_regs_recz               NUMBER(9),
  fc_incl_instan_dimen       DATE NOT NULL,
  CONSTRAINT pk_insdsc PRIMARY KEY (nu_dimen,cd_instan_dimen) DISABLE,
  CONSTRAINT fk_insdsc_fueind FOREIGN KEY (nu_fuente_indca_perfm)
      REFERENCES warehouse.g3_fuente_indca_perfm(nu_fuente_indca_perfm)  DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     81920
      NEXT        65536
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_instan_dimen_desc IS 'Ocurrencias de las dimensiones desconocidas que son localizadas durante
    el proceso de carga de datos.'
/

COMMENT ON COLUMN warehouse.g3_instan_dimen_desc.cd_instan_dimen IS 'Codigo por lo cual la instancia de dimension es conocida en la empresa.
    Este codigo puede estar errado o no haber sido informado.'
/
COMMENT ON COLUMN warehouse.g3_instan_dimen_desc.ct_regs_recz IS 'Cantidad de registros rechazados en la carga de aquella fuente de datos
    por instancia de dimension desconocida'
/
COMMENT ON COLUMN warehouse.g3_instan_dimen_desc.nu_dimen IS 'Secuencial identificador de la dimension a la cual la instancia
    supuestamente pertenece.'
/
COMMENT ON COLUMN warehouse.g3_instan_dimen_desc.nu_fuente_indca_perfm IS 'Fuente de datos a traves de la cual surgio la instancia de dimension
    desconocida.'
/

CREATE UNIQUE INDEX warehouse.pk_insdsc
 ON warehouse.g3_instan_dimen_desc
  ( nu_dimen,
    cd_instan_dimen  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     49152
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_instan_dimen_instan_dimen
 (
  nu_dimen_padre             NUMBER(5) NOT NULL,
  nu_instan_dimen_padre      NUMBER(8) NOT NULL,
  nu_dimen_hijo              NUMBER(5) NOT NULL,
  nu_instan_dimen_hijo       NUMBER(8) NOT NULL,
  CONSTRAINT pk_indind PRIMARY KEY (nu_dimen_padre,nu_instan_dimen_padre,nu_dimen_hijo,
 nu_instan_dimen_hijo) DISABLE,
  CONSTRAINT fk_indind_insdim_01 FOREIGN KEY (nu_dimen_padre,nu_instan_dimen_padre)
      REFERENCES warehouse.g3_instan_dimen(nu_dimen,nu_instan_dimen) ON DELETE CASCADE DISABLE,
  CONSTRAINT fk_indind_insdim_02 FOREIGN KEY (nu_dimen_hijo,nu_instan_dimen_hijo)
      REFERENCES warehouse.g3_instan_dimen(nu_dimen,nu_instan_dimen) ON DELETE CASCADE DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     4194304
      NEXT        2097152
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_instan_dimen_instan_dimen IS 'Estrutura de los arboles que representam las jerarquias de las dimensiones.
    Mapea la forma como los datos seran consolidados. Una instancia puede tener mas de uno padre (estar subordinada
    a mas de una instancia), desde que los dos padres estean en'
/

COMMENT ON COLUMN warehouse.g3_instan_dimen_instan_dimen.nu_dimen_hijo IS 'Identificador de la dimension a que pertenece la instancia-hijo. Es siempre igual
    a Nu_Dimen_Padre, ya que l jerarquia es siempre dentro de la misma dimension.'
/
COMMENT ON COLUMN warehouse.g3_instan_dimen_instan_dimen.nu_dimen_padre IS 'Identificador de la dimension a que pertenece la instancia-padre.'
/
COMMENT ON COLUMN warehouse.g3_instan_dimen_instan_dimen.nu_instan_dimen_hijo IS 'Identificador de la instancia-hijo.'
/
COMMENT ON COLUMN warehouse.g3_instan_dimen_instan_dimen.nu_instan_dimen_padre IS 'Identificador de la instancia-padre.'
/

CREATE INDEX warehouse.ix_indind_01
 ON warehouse.g3_instan_dimen_instan_dimen
  ( nu_dimen_hijo,
    nu_instan_dimen_hijo  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     1048576
   NEXT        1048576
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  121
   )
/

CREATE UNIQUE INDEX warehouse.pk_indind
 ON warehouse.g3_instan_dimen_instan_dimen
  ( nu_dimen_padre,
    nu_instan_dimen_padre,
    nu_dimen_hijo,
    nu_instan_dimen_hijo  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     4194304
   NEXT        2097152
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_log_error
 (
  nm_rutina                  VARCHAR2(5) NOT NULL,
  nu_usuario                 NUMBER(5) NOT NULL,
  fc_inicio_log_error        DATE NOT NULL,
  nu_ocrr_log_error          NUMBER(5) NOT NULL,
  fc_msj_log_error           DATE NOT NULL,
  tx_msj_error               VARCHAR2(500) NOT NULL,
  cd_tipo_log                CHAR(1) DEFAULT 'D' NOT NULL,
  nu_fuente_indca_perfm      NUMBER(5),
  fc_gen_fuente_indca_perfm  DATE,
  fc_refr_fuente_indca_perfm  DATE,
  nu_indca_perfm             NUMBER(5),
  nu_instan_dimen__1         NUMBER(8),
  nu_instan_dimen__2         NUMBER(8),
  nu_instan_dimen__3         NUMBER(8),
  nu_instan_dimen__4         NUMBER(8),
  nu_instan_dimen__5         NUMBER(8),
  nu_instan_dimen__6         NUMBER(8),
  nu_instan_dimen__7         NUMBER(8),
  nu_instan_dimen__8         NUMBER(8),
  nu_instan_dimen__9         NUMBER(8),
  nu_instan_dimen__10        NUMBER(8),
  nu_instan_dimen__11        NUMBER(8),
  nu_instan_dimen__12        NUMBER(8),
  nu_instan_dimen__13        NUMBER(8),
  nu_instan_dimen__14        NUMBER(8),
  nu_instan_dimen__15        NUMBER(8),
  nu_instan_dimen__16        NUMBER(8),
  cd_instan_dimen__1         VARCHAR2(20),
  cd_instan_dimen__2         VARCHAR2(20),
  cd_instan_dimen__3         VARCHAR2(20),
  cd_instan_dimen__4         VARCHAR2(20),
  cd_instan_dimen__5         VARCHAR2(20),
  cd_instan_dimen__6         VARCHAR2(20),
  cd_instan_dimen__7         VARCHAR2(20),
  cd_instan_dimen__8         VARCHAR2(20),
  cd_instan_dimen__9         VARCHAR2(20),
  cd_instan_dimen__10        VARCHAR2(20),
  cd_instan_dimen__11        VARCHAR2(20),
  cd_instan_dimen__12        VARCHAR2(20),
  cd_instan_dimen__13        VARCHAR2(20),
  cd_instan_dimen__14        VARCHAR2(20),
  cd_instan_dimen__15        VARCHAR2(20),
  cd_instan_dimen__16        VARCHAR2(20),
  ct_dato                    NUMBER(25,7),
  nu_dimen                   NUMBER(5),
  nu_instan_dimen            NUMBER(8),
  nu_atrb_dimen              NUMBER(5),
  cd_instan_dimen            VARCHAR2(20),
  tx_valor_atrb_dimen        VARCHAR2(2000),
  CONSTRAINT pk_logerr PRIMARY KEY (nm_rutina,nu_usuario,fc_inicio_log_error,
 nu_ocrr_log_error) DISABLE,
  CONSTRAINT ck_logerr_cd_tipo_log CHECK (CD_TIPO_LOG IN ('E','A','D')) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     1048576
      NEXT        1048576
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_log_error IS 'Log del procesamiento de las rutinas de importacion y atualizacion del Data Warehouse.'
/

COMMENT ON COLUMN warehouse.g3_log_error.cd_instan_dimen IS 'Apenas para errores en la importacion de atributos. Codigo de la instancia dimension cuyos atributos estan siendo importados.'
/
COMMENT ON COLUMN warehouse.g3_log_error.cd_instan_dimen__1 IS 'Apenas para errores en la importacion de sistemas. Codigo de la instancia como estava en el archivo de interface.'
/
COMMENT ON COLUMN warehouse.g3_log_error.cd_instan_dimen__10 IS 'Apenas para errores en la importacion de sistemas. Codigo de la instancia como estava en el archivo de interface.'
/
COMMENT ON COLUMN warehouse.g3_log_error.cd_instan_dimen__11 IS 'Apenas para errores en la importacion de sistemas. Codigo de la instancia como estava en el archivo de interface.'
/
COMMENT ON COLUMN warehouse.g3_log_error.cd_instan_dimen__12 IS 'Apenas para errores en la importacion de sistemas. Codigo de la instancia como estava en el archivo de interface.'
/
COMMENT ON COLUMN warehouse.g3_log_error.cd_instan_dimen__13 IS 'Apenas para errores en la importacion de sistemas. Codigo de la instancia como estava en el archivo de interface.'
/
COMMENT ON COLUMN warehouse.g3_log_error.cd_instan_dimen__14 IS 'Apenas para errores en la importacion de sistemas. Codigo de la instancia como estava en el archivo de interface.'
/
COMMENT ON COLUMN warehouse.g3_log_error.cd_instan_dimen__15 IS 'Apenas para errores en la importacion de sistemas. Codigo de la instancia como estava en el archivo de interface.'
/
COMMENT ON COLUMN warehouse.g3_log_error.cd_instan_dimen__16 IS 'Apenas para errores en la importacion de sistemas. Codigo de la instancia como estava en el archivo de interface.'
/
COMMENT ON COLUMN warehouse.g3_log_error.cd_instan_dimen__2 IS 'Apenas para errores en la importacion de sistemas. Codigo de la instancia como estava en el archivo de interface.'
/
COMMENT ON COLUMN warehouse.g3_log_error.cd_instan_dimen__3 IS 'Apenas para errores en la importacion de sistemas. Codigo de la instancia como estava en el archivo de interface.'
/
COMMENT ON COLUMN warehouse.g3_log_error.cd_instan_dimen__4 IS 'Apenas para errores en la importacion de sistemas. Codigo de la instancia como estava en el archivo de interface.'
/
COMMENT ON COLUMN warehouse.g3_log_error.cd_instan_dimen__5 IS 'Apenas para errores en la importacion de sistemas. Codigo de la instancia como estava en el archivo de interface.'
/
COMMENT ON COLUMN warehouse.g3_log_error.cd_instan_dimen__6 IS 'Apenas para errores en la importacion de sistemas. Codigo de la instancia como estava en el archivo de interface.'
/
COMMENT ON COLUMN warehouse.g3_log_error.cd_instan_dimen__7 IS 'Apenas para errores en la importacion de sistemas. Codigo de la instancia como estava en el archivo de interface.'
/
COMMENT ON COLUMN warehouse.g3_log_error.cd_instan_dimen__8 IS 'Apenas para errores en la importacion de sistemas. Codigo de la instancia como estava en el archivo de interface.'
/
COMMENT ON COLUMN warehouse.g3_log_error.cd_instan_dimen__9 IS 'Apenas para errores en la importacion de sistemas. Codigo de la instancia como estava en el archivo de interface.'
/
COMMENT ON COLUMN warehouse.g3_log_error.cd_tipo_log IS 'Tipo de la mensaje del log.    D - Documentacion    A - Advertencia    E - Error.'
/
COMMENT ON COLUMN warehouse.g3_log_error.ct_dato IS 'Apenas para errores en la importacion de sistemas. Valor del dato que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.fc_gen_fuente_indca_perfm IS 'Fecha de generacion de la fuente de datos procesada.'
/
COMMENT ON COLUMN warehouse.g3_log_error.fc_inicio_log_error IS 'Fecha del inicio de la grabacion del log.'
/
COMMENT ON COLUMN warehouse.g3_log_error.fc_msj_log_error IS 'Fecha de grabacion de la mensaje de error.'
/
COMMENT ON COLUMN warehouse.g3_log_error.fc_refr_fuente_indca_perfm IS 'Fecha de referencia de la fuente de datos procesada.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nm_rutina IS 'Nombre de la rutina para la cual esta siendo grabado el log.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_atrb_dimen IS 'Apenas para errores en la importacion de atributos. Identificador del atributo que esta siendo importado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_dimen IS 'Apenas para errores en la importacion de atributos. Numero de la dimension cuyos atributos estan siendo importados.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_fuente_indca_perfm IS 'Secuencial identificador de la fuente de datos procesada.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_indca_perfm IS 'Apenas para errores en la importacion de sistemas. Secuencial identificador del indicador que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_instan_dimen IS 'Apenas para errores en la importacion de atributos. Numero de la instancia dimension cuyos atributos estan siendo importados.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_instan_dimen__1 IS 'Apenas para errores en la importacion de sistemas. Parte de la clave de la instancia de vision que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_instan_dimen__10 IS 'Apenas para errores en la importacion de sistemas. Parte de la clave de la instancia de vision que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_instan_dimen__11 IS 'Apenas para errores en la importacion de sistemas. Parte de la clave de la instancia de vision que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_instan_dimen__12 IS 'Apenas para errores en la importacion de sistemas. Parte de la clave de la instancia de vision que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_instan_dimen__13 IS 'Apenas para errores en la importacion de sistemas. Parte de la clave de la instancia de vision que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_instan_dimen__14 IS 'Apenas para errores en la importacion de sistemas. Parte de la clave de la instancia de vision que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_instan_dimen__15 IS 'Apenas para errores en la importacion de sistemas. Parte de la clave de la instancia de vision que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_instan_dimen__16 IS 'Apenas para errores en la importacion de sistemas. Parte de la clave de la instancia de vision que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_instan_dimen__2 IS 'Apenas para errores en la importacion de sistemas. Parte de la clave de la instancia de vision que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_instan_dimen__3 IS 'Apenas para errores en la importacion de sistemas. Parte de la clave de la instancia de vision que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_instan_dimen__4 IS 'Apenas para errores en la importacion de sistemas. Parte de la clave de la instancia de vision que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_instan_dimen__5 IS 'Apenas para errores en la importacion de sistemas. Parte de la clave de la instancia de vision que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_instan_dimen__6 IS 'Apenas para errores en la importacion de sistemas. Parte de la clave de la instancia de vision que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_instan_dimen__7 IS 'Apenas para errores en la importacion de sistemas. Parte de la clave de la instancia de vision que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_instan_dimen__8 IS 'Apenas para errores en la importacion de sistemas. Parte de la clave de la instancia de vision que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_instan_dimen__9 IS 'Apenas para errores en la importacion de sistemas. Parte de la clave de la instancia de vision que compone el registro rechazado.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_ocrr_log_error IS 'Numero de ocorrencia del log para una combinacion Rutina + Usuario + Fecha de Inicio.'
/
COMMENT ON COLUMN warehouse.g3_log_error.nu_usuario IS 'Secuencial identificador del usuario que empiezo el procedimiento que esta grabando el log.'
/
COMMENT ON COLUMN warehouse.g3_log_error.tx_msj_error IS 'Mensaje de error.'
/
COMMENT ON COLUMN warehouse.g3_log_error.tx_valor_atrb_dimen IS 'Apenas para errores en la importacion de atributos. Valor del atributo que esta siendo importado.'
/

CREATE UNIQUE INDEX warehouse.pk_logerr
 ON warehouse.g3_log_error
  ( nm_rutina,
    nu_usuario,
    fc_inicio_log_error,
    nu_ocrr_log_error  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     131072
   NEXT        65536
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_log_fuente_indca_perfm
 (
  nu_fuente_indca_perfm      NUMBER(5) NOT NULL,
  fc_gen_fuente_indca_perfm  DATE NOT NULL,
  fc_refr_fuente_indca_perfm  DATE NOT NULL,
  nu_asu_infm                NUMBER(5),
  fc_ejec_interf             DATE NOT NULL,
  fc_atualiz_dw              DATE,
  CONSTRAINT pk_logfue PRIMARY KEY (nu_fuente_indca_perfm,fc_gen_fuente_indca_perfm,
 fc_refr_fuente_indca_perfm) DISABLE,
  CONSTRAINT fk_logfue_asuinf FOREIGN KEY (nu_asu_infm)
      REFERENCES warehouse.g3_asu_infm(nu_asu_infm)  DISABLE,
  CONSTRAINT fk_logfue_fueind FOREIGN KEY (nu_fuente_indca_perfm)
      REFERENCES warehouse.g3_fuente_indca_perfm(nu_fuente_indca_perfm)  DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     311296
      NEXT        32768
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_log_fuente_indca_perfm IS 'Log de todas las entradas de datos en el Data Warehouse. Permite agrupar los datos de la tabla
    de Serie Historica segundo los lotes por los cuales ellos fueran importados, posibilitando
    verificaciones y documentacion de reimportaciones, remocion d'
/

COMMENT ON COLUMN warehouse.g3_log_fuente_indca_perfm.fc_atualiz_dw IS 'Fecha en que el lote paso de la tabla Movimiento para la tabla de Serie Historica (fecha
    de ejecucion del procedimiento de atualizacion del Data Warehouse.'
/
COMMENT ON COLUMN warehouse.g3_log_fuente_indca_perfm.fc_ejec_interf IS 'Fecha de entrada del lote en la tabla Movimiento del Data Warehouse (fecha de ejecucion de la
    interface).'
/
COMMENT ON COLUMN warehouse.g3_log_fuente_indca_perfm.fc_gen_fuente_indca_perfm IS 'Fecha de generacion de la fuente de datos que compone el lote.'
/
COMMENT ON COLUMN warehouse.g3_log_fuente_indca_perfm.fc_refr_fuente_indca_perfm IS 'Fecha a que se refiere el lote de datos.'
/
COMMENT ON COLUMN warehouse.g3_log_fuente_indca_perfm.nu_asu_infm IS 'Secuencial identificador del asunto al cual se refiere el lote. Para
    fuentes del tipo Manual o ajustes manuales realizados sobre datos de Planillas.'
/
COMMENT ON COLUMN warehouse.g3_log_fuente_indca_perfm.nu_fuente_indca_perfm IS 'Secuencial identificador de la fuente de datos que compone el lote.'
/

CREATE UNIQUE INDEX warehouse.pk_logfue
 ON warehouse.g3_log_fuente_indca_perfm
  ( nu_fuente_indca_perfm,
    fc_gen_fuente_indca_perfm,
    fc_refr_fuente_indca_perfm  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     163840
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_movt_serie_hist
 (
  nu_indca_perfm             NUMBER(5) NOT NULL,
  nu_vision                  NUMBER(5) NOT NULL,
  nu_instan_dimen__1         NUMBER(8) NOT NULL,
  nu_instan_dimen__2         NUMBER(8) NOT NULL,
  nu_instan_dimen__3         NUMBER(8) NOT NULL,
  nu_instan_dimen__4         NUMBER(8) NOT NULL,
  nu_instan_dimen__5         NUMBER(8) NOT NULL,
  nu_instan_dimen__6         NUMBER(8) NOT NULL,
  nu_instan_dimen__7         NUMBER(8) NOT NULL,
  nu_instan_dimen__8         NUMBER(8) NOT NULL,
  nu_instan_dimen__9         NUMBER(8) NOT NULL,
  nu_instan_dimen__10        NUMBER(8) NOT NULL,
  nu_instan_dimen__11        NUMBER(8) NOT NULL,
  nu_instan_dimen__12        NUMBER(8) NOT NULL,
  nu_instan_dimen__13        NUMBER(8) NOT NULL,
  nu_instan_dimen__14        NUMBER(8) NOT NULL,
  nu_instan_dimen__15        NUMBER(8) NOT NULL,
  nu_instan_dimen__16        NUMBER(8) NOT NULL,
  fc_refr_movt               DATE NOT NULL,
  ct_indca_perfm_movt        NUMBER(25,7) NOT NULL,
  nu_fuente_dato_movt        NUMBER(5) NOT NULL,
  nu_dato_extn_movt          NUMBER(5),
  fc_gen_movt                DATE NOT NULL,
  CONSTRAINT pk_movtsh PRIMARY KEY (nu_indca_perfm,nu_vision,nu_instan_dimen__1,
 nu_instan_dimen__2,nu_instan_dimen__3,nu_instan_dimen__4,nu_instan_dimen__5,
 nu_instan_dimen__6,nu_instan_dimen__7,nu_instan_dimen__8,nu_instan_dimen__9,
 nu_instan_dimen__10,nu_instan_dimen__11,nu_instan_dimen__12,fc_refr_movt) DISABLE,
  CONSTRAINT fk_movtsh_fueind FOREIGN KEY (nu_fuente_dato_movt)
      REFERENCES warehouse.g3_fuente_indca_perfm(nu_fuente_indca_perfm)  DISABLE,
  CONSTRAINT fk_movtsh_indprf FOREIGN KEY (nu_indca_perfm)
      REFERENCES warehouse.g3_indca_perfm(nu_indca_perfm)  DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_temp
 STORAGE   (
      INITIAL     4194304
      NEXT        4194304
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_movt_serie_hist IS 'Tabla temporaria que contiene apenas un movimiento de entrada de datos en el Data Warehouse (datos para apenas un periodo - un dia, un mes etc.).'
/

COMMENT ON COLUMN warehouse.g3_movt_serie_hist.ct_indca_perfm_movt IS 'Valor del movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.fc_gen_movt IS 'Fecha de generacion de la fuente de dados que genero el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.fc_refr_movt IS 'Fecha a que se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_dato_extn_movt IS 'Secuencial identificador del dato externo que compone el movimiento (apenas para fuentes de datos de los tipos Planilla o Manual.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_fuente_dato_movt IS 'Secuencial identificador de la fuente de datos que genero el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_indca_perfm IS 'Secuencial identificador del indicador de desempeqo al cual se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_instan_dimen__1 IS 'Parte de la clave de la instancia de vision a la cual se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_instan_dimen__10 IS 'Parte de la clave de la instancia de vision a la cual se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_instan_dimen__11 IS 'Parte de la clave de la instancia de vision a la cual se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_instan_dimen__12 IS 'Parte de la clave de la instancia de vision a la cual se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_instan_dimen__13 IS 'Parte de la clave de la instancia de vision a la cual se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_instan_dimen__14 IS 'Parte de la clave de la instancia de vision a la cual se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_instan_dimen__15 IS 'Parte de la clave de la instancia de vision a la cual se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_instan_dimen__16 IS 'Parte de la clave de la instancia de vision a la cual se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_instan_dimen__2 IS 'Parte de la clave de la instancia de vision a la cual se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_instan_dimen__3 IS 'Parte de la clave de la instancia de vision a la cual se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_instan_dimen__4 IS 'Parte de la clave de la instancia de vision a la cual se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_instan_dimen__5 IS 'Parte de la clave de la instancia de vision a la cual se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_instan_dimen__6 IS 'Parte de la clave de la instancia de vision a la cual se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_instan_dimen__7 IS 'Parte de la clave de la instancia de vision a la cual se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_instan_dimen__8 IS 'Parte de la clave de la instancia de vision a la cual se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_instan_dimen__9 IS 'Parte de la clave de la instancia de vision a la cual se refiere el movimiento.'
/
COMMENT ON COLUMN warehouse.g3_movt_serie_hist.nu_vision IS 'Parte de la clave de la instancia de vision a la cual se refiere el movimiento.'
/

CREATE INDEX warehouse.ix_movtsh01
 ON warehouse.g3_movt_serie_hist
  ( nu_fuente_dato_movt,
    fc_gen_movt  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_temp_idx
 STORAGE (
   INITIAL     4194304
   NEXT        4194304
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE UNIQUE INDEX warehouse.pk_movtsh
 ON warehouse.g3_movt_serie_hist
  ( nu_indca_perfm,
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
    fc_refr_movt  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_temp_idx
 STORAGE (
   INITIAL     4194304
   NEXT        4194304
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_nivl_logc_dimen
 (
  nu_dimen                   NUMBER(5) NOT NULL,
  nu_nivl_logc_dimen         NUMBER(2) NOT NULL,
  nm_nivl_logc_dimen         VARCHAR2(24) NOT NULL,
  CONSTRAINT pk_nivdim PRIMARY KEY (nu_dimen,nu_nivl_logc_dimen) DISABLE,
  CONSTRAINT fk_nivdim_dimens FOREIGN KEY (nu_dimen)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_nivl_logc_dimen IS 'Tabla de niveles logicos de dimension. El nivel logico agrupa todas las instancias en um mismo nivel de la jerarquia.'
/

COMMENT ON COLUMN warehouse.g3_nivl_logc_dimen.nm_nivl_logc_dimen IS 'Nombre del nivel logico de la dimension.'
/
COMMENT ON COLUMN warehouse.g3_nivl_logc_dimen.nu_dimen IS 'Identificador unico de la dimension.'
/
COMMENT ON COLUMN warehouse.g3_nivl_logc_dimen.nu_nivl_logc_dimen IS 'Identificador del nivel logico de la dimension.'
/

CREATE UNIQUE INDEX warehouse.pk_nivdim
 ON warehouse.g3_nivl_logc_dimen
  ( nu_dimen,
    nu_nivl_logc_dimen  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_parm_sist
 (
  nu_parm_sist               NUMBER(5) NOT NULL,
  nm_parm_sist               VARCHAR2(30) NOT NULL,
  tx_vl_parm_sist            VARCHAR2(2000),
  CONSTRAINT pk_parsis PRIMARY KEY (nu_parm_sist) DISABLE,
  CONSTRAINT un_parsis UNIQUE (nm_parm_sist) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        8192
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_parm_sist IS 'Tabla de parametros internos del sistema.'
/

COMMENT ON COLUMN warehouse.g3_parm_sist.nm_parm_sist IS 'Nombre del parametro del sistema.'
/
COMMENT ON COLUMN warehouse.g3_parm_sist.nu_parm_sist IS 'Identificador unico del parametro del sistema.'
/
COMMENT ON COLUMN warehouse.g3_parm_sist.tx_vl_parm_sist IS 'Valor del parametro del sistema.'
/

CREATE UNIQUE INDEX warehouse.pk_parsis
 ON warehouse.g3_parm_sist
  ( nu_parm_sist  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        8192
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE UNIQUE INDEX warehouse.un_parsis
 ON warehouse.g3_parm_sist
  ( nm_parm_sist  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        8192
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_perfil_indca
 (
  nu_perf_usua               NUMBER(5) NOT NULL,
  nu_indca_perfm             NUMBER(5) NOT NULL,
  CONSTRAINT pk_prfind PRIMARY KEY (nu_perf_usua,nu_indca_perfm) DISABLE,
  CONSTRAINT fk_prfind_indca FOREIGN KEY (nu_indca_perfm)
      REFERENCES warehouse.g3_indca_perfm(nu_indca_perfm) ON DELETE CASCADE DISABLE,
  CONSTRAINT fk_prfind_perfil FOREIGN KEY (nu_perf_usua)
      REFERENCES warehouse.g3_perfil_usuario(nu_perf_usua) ON DELETE CASCADE DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     32768
      NEXT        8192
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_perfil_indca IS 'Define los indicadores que puedem ser vistos por cada uno de los perfiles tipo N (Normal).'
/

COMMENT ON COLUMN warehouse.g3_perfil_indca.nu_indca_perfm IS 'Identificador del indicador de desempe?o que puede ser visto por aquele
    perfil.'
/
COMMENT ON COLUMN warehouse.g3_perfil_indca.nu_perf_usua IS 'Identificador del perfil de usuario.'
/

CREATE UNIQUE INDEX warehouse.pk_prfind
 ON warehouse.g3_perfil_indca
  ( nu_perf_usua,
    nu_indca_perfm  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        8192
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_perfil_usuario
 (
  nu_perf_usua               NUMBER(5) NOT NULL,
  nm_perf_usua               VARCHAR2(30) NOT NULL,
  cd_tipo_perf_usua          CHAR(1) NOT NULL,
  CONSTRAINT pk_perfil PRIMARY KEY (nu_perf_usua) DISABLE,
  CONSTRAINT ck_perfil_cd_tipo CHECK (Cd_Tipo_Perf_Usua IN ('A','N')) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_perfil_usuario IS 'Perfiles de usuarios que acceden a los datos del Data Warehouse.'
/

COMMENT ON COLUMN warehouse.g3_perfil_usuario.cd_tipo_perf_usua IS 'Tipo del perfil de usuario.    A - Alimentador de datos : responsable por la entrada de datos en el sistema    N - Normal : apenas consulta los datos a traves de las diversas bases de consulta.'
/
COMMENT ON COLUMN warehouse.g3_perfil_usuario.nm_perf_usua IS 'Nombre del perfil de usuario.'
/
COMMENT ON COLUMN warehouse.g3_perfil_usuario.nu_perf_usua IS 'Secuencial identificador del perfil de usuario.'
/

CREATE UNIQUE INDEX warehouse.pk_perfil
 ON warehouse.g3_perfil_usuario
  ( nu_perf_usua  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_prvd_dato
 (
  nu_prvd_dato               NUMBER(5) NOT NULL,
  nu_unid_orgn_supr          NUMBER(5) NOT NULL,
  nu_unid_orgn               NUMBER(5),
  nm_resp_prvd_dato__1       VARCHAR2(30) NOT NULL,
  nm_resp_prvd_dato__2       VARCHAR2(30),
  nu_tel_prvd_dato__1        VARCHAR2(8) NOT NULL,
  nu_tel_prvd_dato__2        VARCHAR2(8),
  CONSTRAINT pk_prvdat PRIMARY KEY (nu_prvd_dato) DISABLE,
  CONSTRAINT fk_prvdat_uniorg_01 FOREIGN KEY (nu_unid_orgn)
      REFERENCES warehouse.g3_unid_orgn(nu_unid_orgn)  DISABLE,
  CONSTRAINT fk_prvdat_uniorg_02 FOREIGN KEY (nu_unid_orgn_supr)
      REFERENCES warehouse.g3_unid_orgn(nu_unid_orgn)  DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_prvd_dato IS 'Proveedores de datos para el Data Warehouse. Son los departamientos responsables por los datos que alimentaran el Data Warehouse.'
/

COMMENT ON COLUMN warehouse.g3_prvd_dato.nm_resp_prvd_dato__1 IS 'Nombre del responsable por este proveedor.'
/
COMMENT ON COLUMN warehouse.g3_prvd_dato.nm_resp_prvd_dato__2 IS 'Nombre de uno segundo responsable por este proveedor.'
/
COMMENT ON COLUMN warehouse.g3_prvd_dato.nu_prvd_dato IS 'Secuencial identificador del proveedor de datos.'
/
COMMENT ON COLUMN warehouse.g3_prvd_dato.nu_tel_prvd_dato__1 IS 'Telefono del responsable por este proveedor.'
/
COMMENT ON COLUMN warehouse.g3_prvd_dato.nu_tel_prvd_dato__2 IS 'Telefono de um secundo responsable por este proveedor.'
/
COMMENT ON COLUMN warehouse.g3_prvd_dato.nu_unid_orgn IS 'Secuencial identificador de la unidad organizacional que compone el proveedor de datos.'
/
COMMENT ON COLUMN warehouse.g3_prvd_dato.nu_unid_orgn_supr IS 'Secuencial identificador de la unidad organizacional superior que compone el proveedor de datos.'
/

CREATE UNIQUE INDEX warehouse.pk_prvdat
 ON warehouse.g3_prvd_dato
  ( nu_prvd_dato  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_serie_hist_cons_1
 (
  nu_indca_perfm             NUMBER(5) NOT NULL,
  nu_vision                  NUMBER(5) NOT NULL,
  nu_instan_dimen__1         NUMBER(8) NOT NULL,
  nu_instan_dimen__2         NUMBER(8) NOT NULL,
  nu_instan_dimen__3         NUMBER(8) NOT NULL,
  nu_instan_dimen__4         NUMBER(8) NOT NULL,
  nu_instan_dimen__5         NUMBER(8) NOT NULL,
  nu_instan_dimen__6         NUMBER(8) NOT NULL,
  nu_instan_dimen__7         NUMBER(8) NOT NULL,
  nu_instan_dimen__8         NUMBER(8) NOT NULL,
  nu_instan_dimen__9         NUMBER(8) NOT NULL,
  nu_instan_dimen__10        NUMBER(8) NOT NULL,
  nu_instan_dimen__11        NUMBER(8) NOT NULL,
  nu_instan_dimen__12        NUMBER(8) NOT NULL,
  nu_instan_dimen__13        NUMBER(8) NOT NULL,
  nu_instan_dimen__14        NUMBER(8) NOT NULL,
  nu_instan_dimen__15        NUMBER(8) NOT NULL,
  nu_instan_dimen__16        NUMBER(8) NOT NULL,
  fc_refr_serie_hist         DATE NOT NULL,
  cd_grnl_serie_hist         CHAR(1) NOT NULL,
  ct_valor_serie_hist        NUMBER(25,7) NOT NULL,
  nu_fuente_indca_perfm      NUMBER(5) NOT NULL,
  fc_gen_fuente_indca_perfm  DATE NOT NULL,
  CONSTRAINT pk_srhc01 PRIMARY KEY (nu_indca_perfm,nu_vision,cd_grnl_serie_hist,
 fc_refr_serie_hist,nu_instan_dimen__1,nu_instan_dimen__2,nu_instan_dimen__3,
 nu_instan_dimen__4,nu_instan_dimen__5,nu_instan_dimen__6,nu_instan_dimen__7,
 nu_instan_dimen__8,nu_instan_dimen__9,nu_instan_dimen__10,nu_instan_dimen__11) DISABLE,
  CONSTRAINT fk_srhc01_fueind FOREIGN KEY (nu_fuente_indca_perfm)
      REFERENCES warehouse.g3_fuente_indca_perfm(nu_fuente_indca_perfm)  DISABLE,
  CONSTRAINT fk_srhc01_indprf FOREIGN KEY (nu_indca_perfm)
      REFERENCES warehouse.g3_indca_perfm(nu_indca_perfm)  DISABLE,
  CONSTRAINT ck_srhc01_cd_grnl_serie_hist CHECK (Cd_Grnl_Serie_Hist in ('H', 'D', 'S', 'M', 'A')) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_data
 STORAGE   (
      INITIAL     4194304
      NEXT        4194304
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  8192
   )
/

CREATE UNIQUE INDEX warehouse.pk_srhc01
 ON warehouse.g3_serie_hist_cons_1
  ( nu_indca_perfm,
    nu_vision,
    cd_grnl_serie_hist,
    fc_refr_serie_hist,
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
    nu_instan_dimen__11  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_idx
 STORAGE (
   INITIAL     4194304
   NEXT        4194304
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  2048
   )
/

CREATE TABLE warehouse.g3_serie_hist_indca
 (
  nu_indca_perfm             NUMBER(5) NOT NULL,
  nu_vision                  NUMBER(5) NOT NULL,
  nu_instan_dimen__1         NUMBER(8) NOT NULL,
  nu_instan_dimen__2         NUMBER(8) NOT NULL,
  nu_instan_dimen__3         NUMBER(8) NOT NULL,
  nu_instan_dimen__4         NUMBER(8) NOT NULL,
  nu_instan_dimen__5         NUMBER(8) NOT NULL,
  nu_instan_dimen__6         NUMBER(8) NOT NULL,
  nu_instan_dimen__7         NUMBER(8) NOT NULL,
  nu_instan_dimen__8         NUMBER(8) NOT NULL,
  nu_instan_dimen__9         NUMBER(8) NOT NULL,
  nu_instan_dimen__10        NUMBER(8) NOT NULL,
  nu_instan_dimen__11        NUMBER(8) NOT NULL,
  nu_instan_dimen__12        NUMBER(8) NOT NULL,
  nu_instan_dimen__13        NUMBER(8) NOT NULL,
  nu_instan_dimen__14        NUMBER(8) NOT NULL,
  nu_instan_dimen__15        NUMBER(8) NOT NULL,
  nu_instan_dimen__16        NUMBER(8) NOT NULL,
  fc_refr_serie_hist         DATE NOT NULL,
  cd_grnl_serie_hist         CHAR(1) NOT NULL,
  ct_valor_serie_hist        NUMBER(25,7) NOT NULL,
  nu_fuente_indca_perfm      NUMBER(5) NOT NULL,
  fc_gen_fuente_indca_perfm  DATE NOT NULL,
  CONSTRAINT pk_serhst PRIMARY KEY (nu_indca_perfm,nu_vision,cd_grnl_serie_hist,
 fc_refr_serie_hist,nu_instan_dimen__1,nu_instan_dimen__2,nu_instan_dimen__3,
 nu_instan_dimen__4,nu_instan_dimen__5,nu_instan_dimen__6,nu_instan_dimen__7,
 nu_instan_dimen__8,nu_instan_dimen__9,nu_instan_dimen__10,nu_instan_dimen__11) DISABLE,
  CONSTRAINT fk_serhst_fueind FOREIGN KEY (nu_fuente_indca_perfm)
      REFERENCES warehouse.g3_fuente_indca_perfm(nu_fuente_indca_perfm)  DISABLE,
  CONSTRAINT fk_serhst_indprf FOREIGN KEY (nu_indca_perfm)
      REFERENCES warehouse.g3_indca_perfm(nu_indca_perfm)  DISABLE,
  CONSTRAINT ck_serhst_cd_grnl_serie_hist CHECK (Cd_Grnl_Serie_Hist in ('H', 'D', 'S', 'M', 'A')) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_data
 STORAGE   (
      INITIAL     4194304
      NEXT        4194304
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  8192
   )
/

COMMENT ON TABLE warehouse.g3_serie_hist_indca IS 'Serie historica de los indicadores de desempeño. En esta tabla son almacenados los datos propriamente dichos.'
/

COMMENT ON COLUMN warehouse.g3_serie_hist_indca.ct_valor_serie_hist IS 'Valor de aquel indicador para aquella instancia de vision en aquella fecha de referencia.'
/
COMMENT ON COLUMN warehouse.g3_serie_hist_indca.fc_gen_fuente_indca_perfm IS 'Fecha de generacion de la fuente de datos a partir de la cual el valor fue importado.'
/
COMMENT ON COLUMN warehouse.g3_serie_hist_indca.fc_refr_serie_hist IS 'Fecha a la cual se refiere la Serie Historica. En el caso de datos com granularidade menor que diaria (mensual o semanal, por ejemplo), la fecha refleja el primero dia del periodo (primero dia del mes o de la semana).'
/
COMMENT ON COLUMN warehouse.g3_serie_hist_indca.nu_fuente_indca_perfm IS 'Identificador de la fuente de datos a partir de la cual el valor fue importado.'
/
COMMENT ON COLUMN warehouse.g3_serie_hist_indca.nu_indca_perfm IS 'Identificador del indicador de desempeño al cual se refiere la Serie Historica.'
/
COMMENT ON COLUMN warehouse.g3_serie_hist_indca.nu_vision IS 'Identificador de la vision a la cual se refiere la Serie Historica.'
/

CREATE UNIQUE INDEX warehouse.pk_serhst
 ON warehouse.g3_serie_hist_indca
  ( nu_indca_perfm,
    nu_vision,
    cd_grnl_serie_hist,
    fc_refr_serie_hist,
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
    nu_instan_dimen__11  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_idx
 STORAGE (
   INITIAL     4194304
   NEXT        4194304
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  2048
   )
/

CREATE TABLE warehouse.g3_serie_hist_indca_2
 (
  nu_indca_perfm             NUMBER(5) NOT NULL,
  nu_vision                  NUMBER(5) NOT NULL,
  nu_instan_dimen__1         NUMBER(8) NOT NULL,
  nu_instan_dimen__2         NUMBER(8) NOT NULL,
  nu_instan_dimen__3         NUMBER(8) NOT NULL,
  nu_instan_dimen__4         NUMBER(8) NOT NULL,
  nu_instan_dimen__5         NUMBER(8) NOT NULL,
  nu_instan_dimen__6         NUMBER(8) NOT NULL,
  nu_instan_dimen__7         NUMBER(8) NOT NULL,
  nu_instan_dimen__8         NUMBER(8) NOT NULL,
  nu_instan_dimen__9         NUMBER(8) NOT NULL,
  nu_instan_dimen__10        NUMBER(8) NOT NULL,
  nu_instan_dimen__11        NUMBER(8) NOT NULL,
  nu_instan_dimen__12        NUMBER(8) NOT NULL,
  nu_instan_dimen__13        NUMBER(8) NOT NULL,
  nu_instan_dimen__14        NUMBER(8) NOT NULL,
  nu_instan_dimen__15        NUMBER(8) NOT NULL,
  nu_instan_dimen__16        NUMBER(8) NOT NULL,
  fc_refr_serie_hist         DATE NOT NULL,
  cd_grnl_serie_hist         CHAR(1) NOT NULL,
  ct_valor_serie_hist        NUMBER(25,7) NOT NULL,
  nu_fuente_indca_perfm      NUMBER(5) NOT NULL,
  fc_gen_fuente_indca_perfm  DATE NOT NULL,
  CONSTRAINT pk_srhst2 PRIMARY KEY (nu_indca_perfm,nu_vision,cd_grnl_serie_hist,
 fc_refr_serie_hist,nu_instan_dimen__1,nu_instan_dimen__2,nu_instan_dimen__3,
 nu_instan_dimen__4,nu_instan_dimen__5,nu_instan_dimen__6,nu_instan_dimen__7,
 nu_instan_dimen__8,nu_instan_dimen__9,nu_instan_dimen__10,nu_instan_dimen__11) DISABLE,
  CONSTRAINT fk_srhst2_fueind FOREIGN KEY (nu_fuente_indca_perfm)
      REFERENCES warehouse.g3_fuente_indca_perfm(nu_fuente_indca_perfm)  DISABLE,
  CONSTRAINT fk_srhst2_indprf FOREIGN KEY (nu_indca_perfm)
      REFERENCES warehouse.g3_indca_perfm(nu_indca_perfm)  DISABLE,
  CONSTRAINT ck_srhst2_cd_grnl_serie_hist CHECK (Cd_Grnl_Serie_Hist in ('H', 'D', 'S', 'M', 'A')) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_data
 STORAGE   (
      INITIAL     4194304
      NEXT        4194304
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  512
   )
/

CREATE UNIQUE INDEX warehouse.pk_srhst2
 ON warehouse.g3_serie_hist_indca_2
  ( nu_indca_perfm,
    nu_vision,
    cd_grnl_serie_hist,
    fc_refr_serie_hist,
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
    nu_instan_dimen__11  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_idx
 STORAGE (
   INITIAL     4194304
   NEXT        4194304
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  2048
   )
/

CREATE TABLE warehouse.g3_srv_jrqc_dimen
 (
  nu_base_cnst               NUMBER(5) NOT NULL,
  nu_dimen                   NUMBER(5) NOT NULL,
  nu_instan_dimen_nivl__1    NUMBER(5) NOT NULL,
  nm_instan_dimen_nivl__1    VARCHAR2(24) NOT NULL,
  nu_instan_dimen_nivl__2    NUMBER(8),
  nm_instan_dimen_nivl__2    VARCHAR2(24),
  nu_instan_dimen_nivl__3    NUMBER(8),
  nm_instan_dimen_nivl__3    VARCHAR2(24),
  nu_instan_dimen_nivl__4    NUMBER(8),
  nm_instan_dimen_nivl__4    VARCHAR2(24),
  nu_instan_dimen_nivl__5    NUMBER(8),
  nm_instan_dimen_nivl__5    VARCHAR2(24),
  nu_instan_dimen_nivl__6    NUMBER(8),
  nm_instan_dimen_nivl__6    VARCHAR2(24),
  nu_instan_dimen_nivl__7    NUMBER(8),
  nm_instan_dimen_nivl__7    VARCHAR2(24),
  nu_instan_dimen_nivl__8    NUMBER(8),
  nm_instan_dimen_nivl__8    VARCHAR2(24),
  nu_instan_dimen_nivl__9    NUMBER(8),
  nm_instan_dimen_nivl__9    VARCHAR2(24),
  nu_instan_dimen_nivl__10   NUMBER(8),
  nm_instan_dimen_nivl__10   VARCHAR2(24),
  nm_instan_clas__1          VARCHAR2(24),
  nm_instan_clas__2          VARCHAR2(24),
  nm_instan_clas__3          VARCHAR2(24),
  nm_instan_clas__4          VARCHAR2(24),
  nm_instan_clas__5          VARCHAR2(24),
  nm_instan_clas__6          VARCHAR2(24),
  nm_instan_clas__7          VARCHAR2(24),
  nm_instan_clas__8          VARCHAR2(24),
  nm_instan_clas__9          VARCHAR2(24),
  nm_instan_clas__10         VARCHAR2(24),
  CONSTRAINT fk_srvdim_bascns FOREIGN KEY (nu_base_cnst)
      REFERENCES warehouse.g3_base_cnst(nu_base_cnst) ON DELETE CASCADE DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     2097152
      NEXT        1048576
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_srv_jrqc_dimen IS 'Tabla temporaria montada por el procedimiento que exporta las jerarquias de dimensiones para el Server.'
/

COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_clas__1 IS 'Nombre del atributo asociado a la instancia de dimension.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_clas__10 IS 'Nombre del atributo asociado a la instancia de dimension.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_clas__2 IS 'Nombre del atributo asociado a la instancia de dimension.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_clas__3 IS 'Nombre del atributo asociado a la instancia de dimension.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_clas__4 IS 'Nombre del atributo asociado a la instancia de dimension.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_clas__5 IS 'Nombre del atributo asociado a la instancia de dimension.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_clas__6 IS 'Nombre del atributo asociado a la instancia de dimension.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_clas__7 IS 'Nombre del atributo asociado a la instancia de dimension.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_clas__8 IS 'Nombre del atributo asociado a la instancia de dimension.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_clas__9 IS 'Nombre del atributo asociado a la instancia de dimension.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_dimen_nivl__1 IS 'Nombre de la instancia de dimension que compone el primero nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_dimen_nivl__10 IS 'Nombre de la instancia de dimension que compone el decimo nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_dimen_nivl__2 IS 'Nombre de la instancia de dimension que compone el secundo nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_dimen_nivl__3 IS 'Nombre de la instancia de dimension que compone el tercero nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_dimen_nivl__4 IS 'Nombre de la instancia de dimension que compone el cuarto nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_dimen_nivl__5 IS 'Nombre de la instancia de dimension que compone el quinto nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_dimen_nivl__6 IS 'Nombre de la instancia de dimension que compone el sexto nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_dimen_nivl__7 IS 'Nombre de la instancia de dimension que compone el septimo nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_dimen_nivl__8 IS 'Nombre de la instancia de dimension que compone el ochavo nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nm_instan_dimen_nivl__9 IS 'Nombre de la instancia de dimension que compone el nono nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nu_base_cnst IS 'Identificador de la base de consulta para la cual esta siendo exportada la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nu_dimen IS 'Identificador de la dimension a la cual pertenece la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nu_instan_dimen_nivl__1 IS 'Identificador de la instancia de dimension que compone el primero nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nu_instan_dimen_nivl__10 IS 'Identificador de la instancia de dimension que compone el
    decimo nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nu_instan_dimen_nivl__2 IS 'Identificador de la instancia de dimension que compone el
    secundo nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nu_instan_dimen_nivl__3 IS 'Identificador de la instancia de dimension que compone el
    tercero nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nu_instan_dimen_nivl__4 IS 'Identificador de la instancia de dimension que compone el
    cuarto nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nu_instan_dimen_nivl__5 IS 'Identificador de la instancia de dimension que compone el
    quinto nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nu_instan_dimen_nivl__6 IS 'Identificador de la instancia de dimension que compone el
    sexto nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nu_instan_dimen_nivl__7 IS 'Identificador de la instancia de dimension que compone el
    septimo nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nu_instan_dimen_nivl__8 IS 'Identificador de la instancia de dimension que compone el
    ochavo nivel de la jerarquia.'
/
COMMENT ON COLUMN warehouse.g3_srv_jrqc_dimen.nu_instan_dimen_nivl__9 IS 'Identificador de la instancia de dimension que compone el
    noveno nivel de la jerarquia.'
/

CREATE TABLE warehouse.g3_tabla_sh
 (
  nu_tabla_sh                NUMBER(5) NOT NULL,
  nm_tabla_sh                VARCHAR2(35) NOT NULL,
  fc_min_tabla_sh            DATE DEFAULT to_date('01-01-1900', 'DD-MM-YYYY'),
  fc_max_tabla_sh            DATE DEFAULT to_date('31-12-2050', 'DD-MM-YYYY'),
  nu_dimen_tabla_sh          NUMBER(5),
  nu_nivl_logc_min           NUMBER(2),
  nu_nivl_logc_max           NUMBER(2),
  CONSTRAINT pk_tabsrh PRIMARY KEY (nu_tabla_sh) DISABLE,
  CONSTRAINT un_tabsrh UNIQUE (nm_tabla_sh) DISABLE,
  CONSTRAINT fk_tabsrh_dimens_01 FOREIGN KEY (nu_dimen_tabla_sh)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE,
  CONSTRAINT fk_tabsrh_nivdim_01 FOREIGN KEY (nu_dimen_tabla_sh,nu_nivl_logc_min)
      REFERENCES warehouse.g3_nivl_logc_dimen(nu_dimen,nu_nivl_logc_dimen)  DISABLE,
  CONSTRAINT fk_tabsrh_nivdim_02 FOREIGN KEY (nu_dimen_tabla_sh,nu_nivl_logc_max)
      REFERENCES warehouse.g3_nivl_logc_dimen(nu_dimen,nu_nivl_logc_dimen)  DISABLE,
  CONSTRAINT ck_fc_tabsrh_01 CHECK (FC_MIN_TABLA_SH < FC_MAX_TABLA_SH) DISABLE,
  CONSTRAINT ck_nivl_tabsrh_01 CHECK (NU_NIVL_LOGC_MIN >= NU_NIVL_LOGC_MAX) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  2048
   )
/

CREATE UNIQUE INDEX warehouse.pk_tabsrh
 ON warehouse.g3_tabla_sh
  ( nu_tabla_sh  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        8192
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  121
   )
/

CREATE UNIQUE INDEX warehouse.un_tabsrh
 ON warehouse.g3_tabla_sh
  ( nm_tabla_sh  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        8192
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  121
   )
/

CREATE TABLE warehouse.g3_tabla_sh_vision
 (
  nu_tabla_sh                NUMBER(5) NOT NULL,
  nu_vision                  NUMBER(5) NOT NULL,
  CONSTRAINT pk_tshvis PRIMARY KEY (nu_vision,nu_tabla_sh) DISABLE,
  CONSTRAINT fk_tshvis_tabsrh FOREIGN KEY (nu_tabla_sh)
      REFERENCES warehouse.g3_tabla_sh(nu_tabla_sh)  DISABLE,
  CONSTRAINT fk_tshvis_vision FOREIGN KEY (nu_vision)
      REFERENCES warehouse.g3_vision(nu_vision) ON DELETE CASCADE DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     32768
      NEXT        32768
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  121
   )
/

CREATE UNIQUE INDEX warehouse.pk_tshvis
 ON warehouse.g3_tabla_sh_vision
  ( nu_vision,
    nu_tabla_sh  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  121
   )
/

CREATE TABLE warehouse.g3_temp_carga_cons
 (
  nu_indca_perfm             NUMBER(5) NOT NULL,
  nu_vision                  NUMBER(5) NOT NULL,
  nu_instan_dimen__1         NUMBER(8) NOT NULL,
  nu_instan_dimen__2         NUMBER(8) NOT NULL,
  nu_instan_dimen__3         NUMBER(8) NOT NULL,
  nu_instan_dimen__4         NUMBER(8) NOT NULL,
  nu_instan_dimen__5         NUMBER(8) NOT NULL,
  nu_instan_dimen__6         NUMBER(8) NOT NULL,
  nu_instan_dimen__7         NUMBER(8) NOT NULL,
  nu_instan_dimen__8         NUMBER(8) NOT NULL,
  nu_instan_dimen__9         NUMBER(8) NOT NULL,
  nu_instan_dimen__10        NUMBER(8) NOT NULL,
  nu_instan_dimen__11        NUMBER(8) NOT NULL,
  nu_instan_dimen__12        NUMBER(8) NOT NULL,
  nu_instan_dimen__13        NUMBER(8) NOT NULL,
  nu_instan_dimen__14        NUMBER(8) NOT NULL,
  nu_instan_dimen__15        NUMBER(8) NOT NULL,
  nu_instan_dimen__16        NUMBER(8) NOT NULL,
  fc_refr_serie_hist         DATE NOT NULL,
  cd_grnl_serie_hist         CHAR(1),
  ct_valor_serie_hist        NUMBER(25,7) NOT NULL,
  nu_fuente_indca_perfm      NUMBER(5) NOT NULL,
  fc_gen_fuente_indca_perfm  DATE NOT NULL
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_temp
 STORAGE   (
      INITIAL     20971520
      NEXT        5242880
      PCTINCREASE 0
      MINEXTENTS  10
      MAXEXTENTS  250
   )
/

CREATE TABLE warehouse.g3_temp_carga_det
 (
  nu_indca_perfm             NUMBER(5) NOT NULL,
  nu_vision                  NUMBER(5) NOT NULL,
  nu_instan_dimen__1         NUMBER(8) NOT NULL,
  nu_instan_dimen__2         NUMBER(8) NOT NULL,
  nu_instan_dimen__3         NUMBER(8) NOT NULL,
  nu_instan_dimen__4         NUMBER(8) NOT NULL,
  nu_instan_dimen__5         NUMBER(8) NOT NULL,
  nu_instan_dimen__6         NUMBER(8) NOT NULL,
  nu_instan_dimen__7         NUMBER(8) NOT NULL,
  nu_instan_dimen__8         NUMBER(8) NOT NULL,
  nu_instan_dimen__9         NUMBER(8) NOT NULL,
  nu_instan_dimen__10        NUMBER(8) NOT NULL,
  nu_instan_dimen__11        NUMBER(8) NOT NULL,
  nu_instan_dimen__12        NUMBER(8) NOT NULL,
  nu_instan_dimen__13        NUMBER(8) NOT NULL,
  nu_instan_dimen__14        NUMBER(8) NOT NULL,
  nu_instan_dimen__15        NUMBER(8) NOT NULL,
  nu_instan_dimen__16        NUMBER(8) NOT NULL,
  fc_refr_serie_hist         DATE NOT NULL,
  cd_grnl_serie_hist         CHAR(1),
  ct_valor_serie_hist        NUMBER(25,7) NOT NULL,
  nu_fuente_indca_perfm      NUMBER(5) NOT NULL,
  fc_gen_fuente_indca_perfm  DATE NOT NULL
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_temp
 STORAGE   (
      INITIAL     20971520
      NEXT        5242880
      PCTINCREASE 0
      MINEXTENTS  10
      MAXEXTENTS  250
   )
/

CREATE TABLE warehouse.g3_temp_instan_atrb_dimen
 (
  nu_dimen                   NUMBER(5) NOT NULL,
  nu_atrb_dimen              NUMBER(5) NOT NULL,
  nu_instan_dimen            NUMBER(8) NOT NULL,
  tx_valor_atrb_dimen        VARCHAR2(2000),
  nm_atrb_dimen              VARCHAR2(35) NOT NULL,
  cd_tipo_atrb_dimen         CHAR(1) NOT NULL,
  cd_atrb_valor_libre        CHAR(1) NOT NULL,
  ct_tam_atrb_dimen          NUMBER(4),
  fc_ult_atual_instan_atrb   DATE NOT NULL,
  CONSTRAINT pk_tmpatr PRIMARY KEY (nu_dimen,nu_atrb_dimen,nu_instan_dimen) DISABLE,
  CONSTRAINT fk_tmpatr_atrdim FOREIGN KEY (nu_dimen,nu_atrb_dimen)
      REFERENCES warehouse.g3_atrb_dimen(nu_dimen,nu_atrb_dimen) ON DELETE CASCADE DISABLE,
  CONSTRAINT fk_tmpatr_insdim FOREIGN KEY (nu_dimen,nu_instan_dimen)
      REFERENCES warehouse.g3_instan_dimen(nu_dimen,nu_instan_dimen) ON DELETE CASCADE DISABLE,
  CONSTRAINT ck_tmpatr_atrb_libre CHECK (Cd_Atrb_Valor_Libre in ('0', '1')) DISABLE,
  CONSTRAINT ck_tmpatr_cd_tipo CHECK (Cd_Tipo_Atrb_Dimen IN ('C', 'F', 'N')) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     65536
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_temp_instan_atrb_dimen IS 'Tabla temporaria para entrada manual de instancias de atributos.'
/

COMMENT ON COLUMN warehouse.g3_temp_instan_atrb_dimen.cd_atrb_valor_libre IS 'Flag indicando si el atributo permite o no valores libres.'
/
COMMENT ON COLUMN warehouse.g3_temp_instan_atrb_dimen.cd_tipo_atrb_dimen IS 'Tipo del atributo de la dimension. Puede ser (C)aracter, (N)umerico o (F)echa.'
/
COMMENT ON COLUMN warehouse.g3_temp_instan_atrb_dimen.ct_tam_atrb_dimen IS 'Tamaño maximo del atributo de la dimension.'
/
COMMENT ON COLUMN warehouse.g3_temp_instan_atrb_dimen.fc_ult_atual_instan_atrb IS 'Fecha de la ultima atualizacion del valor del atributo.'
/
COMMENT ON COLUMN warehouse.g3_temp_instan_atrb_dimen.nm_atrb_dimen IS 'Nombre del atributo de la dimension'
/
COMMENT ON COLUMN warehouse.g3_temp_instan_atrb_dimen.nu_atrb_dimen IS 'Identificador del atributo de la dimension.'
/
COMMENT ON COLUMN warehouse.g3_temp_instan_atrb_dimen.nu_dimen IS 'Identificador unico de la dimension del atributo.'
/
COMMENT ON COLUMN warehouse.g3_temp_instan_atrb_dimen.nu_instan_dimen IS 'Identificador de la instancia de la dimension.'
/
COMMENT ON COLUMN warehouse.g3_temp_instan_atrb_dimen.tx_valor_atrb_dimen IS 'Valor de la instancia do atributo de la dimension.'
/

CREATE UNIQUE INDEX warehouse.pk_tmpatr
 ON warehouse.g3_temp_instan_atrb_dimen
  ( nu_dimen,
    nu_atrb_dimen,
    nu_instan_dimen  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     32768
   NEXT        32768
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_temp_jrqc_dimen
 (
  nu_dimen_padre             NUMBER(5) NOT NULL,
  nu_instan_dimen_padre      NUMBER(5) NOT NULL,
  nm_instan_dimen_padre      VARCHAR2(24) NOT NULL,
  nu_dimen_hijo              NUMBER(5) NOT NULL,
  nu_instan_dimen_hijo       NUMBER(5) NOT NULL,
  nm_instan_dimen_hijo       VARCHAR2(24) NOT NULL,
  CONSTRAINT pk_tempjd PRIMARY KEY (nu_dimen_padre,nu_instan_dimen_padre,nu_dimen_hijo,
 nu_instan_dimen_hijo) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     49152
      NEXT        49152
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_temp_jrqc_dimen IS 'Tabla temporaria utilizada por la aplicacion de entrada de dimensiones.'
/

COMMENT ON COLUMN warehouse.g3_temp_jrqc_dimen.nm_instan_dimen_hijo IS 'Nombre de la instancia filha.'
/
COMMENT ON COLUMN warehouse.g3_temp_jrqc_dimen.nm_instan_dimen_padre IS 'Nombre de la instancia padre.'
/
COMMENT ON COLUMN warehouse.g3_temp_jrqc_dimen.nu_dimen_hijo IS 'Secuencial identificador de la dimension a la cual pertenece la instancia filha. Es siempre igual a Nu_Dimen_Padre, ya que la jerarquia es siempre dentro de la misma dimension.'
/
COMMENT ON COLUMN warehouse.g3_temp_jrqc_dimen.nu_dimen_padre IS 'Secuencial identificador de la dimension a la cual pertenece la instancia padre.'
/
COMMENT ON COLUMN warehouse.g3_temp_jrqc_dimen.nu_instan_dimen_hijo IS 'Secuencial identificador de la instancia hija.'
/
COMMENT ON COLUMN warehouse.g3_temp_jrqc_dimen.nu_instan_dimen_padre IS 'Secuencial identificador de la instancia padre.'
/

CREATE UNIQUE INDEX warehouse.pk_tempjd
 ON warehouse.g3_temp_jrqc_dimen
  ( nu_dimen_padre,
    nu_instan_dimen_padre,
    nu_dimen_hijo,
    nu_instan_dimen_hijo  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     49152
   NEXT        32768
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_unid_medd
 (
  nu_unid_medd               NUMBER(5) NOT NULL,
  sg_unid_medd               VARCHAR2(10) NOT NULL,
  nm_unid_medd               VARCHAR2(50),
  cd_moeda_crrnt             CHAR(1) NOT NULL,
  CONSTRAINT pk_unimed PRIMARY KEY (nu_unid_medd) DISABLE,
  CONSTRAINT un_unimed UNIQUE (sg_unid_medd) DISABLE,
  CONSTRAINT ck_unimed_cd_moeda_crrnt CHECK (CD_MOEDA_CRRNT IN ('0','1')) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_unid_medd IS 'Unidades de medida por las cuales son informados los indicadores de desempeño. Ej : toneladas, US$, $, Cantidades.'
/

COMMENT ON COLUMN warehouse.g3_unid_medd.cd_moeda_crrnt IS '0 - La unidad de medida no es moneda corriente    1 - La unidad de medida es moneda corriente.'
/
COMMENT ON COLUMN warehouse.g3_unid_medd.nm_unid_medd IS 'Nombre completo de la unidad de medida.'
/
COMMENT ON COLUMN warehouse.g3_unid_medd.nu_unid_medd IS 'Secuencial identificador de la unidad de medida.'
/
COMMENT ON COLUMN warehouse.g3_unid_medd.sg_unid_medd IS 'Sigla de la unidad de medida. Ex : t, US$.'
/

CREATE UNIQUE INDEX warehouse.pk_unimed
 ON warehouse.g3_unid_medd
  ( nu_unid_medd  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE UNIQUE INDEX warehouse.un_unimed
 ON warehouse.g3_unid_medd
  ( sg_unid_medd  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_unid_orgn
 (
  nu_unid_orgn               NUMBER(5) NOT NULL,
  sg_unid_orgn               VARCHAR2(10) NOT NULL,
  nm_unid_orgn               VARCHAR2(20) NOT NULL,
  CONSTRAINT pk_uniorg PRIMARY KEY (nu_unid_orgn) DISABLE,
  CONSTRAINT un_uniorg UNIQUE (sg_unid_orgn) DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_unid_orgn IS 'Unidades organizacionales de la empresa.'
/

COMMENT ON COLUMN warehouse.g3_unid_orgn.nm_unid_orgn IS 'Nombre de la unidade organizacional.'
/
COMMENT ON COLUMN warehouse.g3_unid_orgn.nu_unid_orgn IS 'Secuencial identificador de la unidad organizacional.'
/
COMMENT ON COLUMN warehouse.g3_unid_orgn.sg_unid_orgn IS 'Sigla de la unidade organizacional.'
/

CREATE UNIQUE INDEX warehouse.pk_uniorg
 ON warehouse.g3_unid_orgn
  ( nu_unid_orgn  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE UNIQUE INDEX warehouse.un_uniorg
 ON warehouse.g3_unid_orgn
  ( sg_unid_orgn  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_usuario
 (
  nu_usua                    NUMBER(5) NOT NULL,
  nm_usua                    VARCHAR2(15) NOT NULL,
  nu_perf_usua               NUMBER(5) NOT NULL,
  CONSTRAINT pk_usuari PRIMARY KEY (nu_usua) DISABLE,
  CONSTRAINT un_usuari UNIQUE (nm_usua) DISABLE,
  CONSTRAINT fk_usuari_perfil FOREIGN KEY (nu_perf_usua)
      REFERENCES warehouse.g3_perfil_usuario(nu_perf_usua)  DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     65536
      NEXT        8192
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_usuario IS 'Usuarios del Data Warehouse. Contiene todas las personas que acceden al banco de datos.'
/

COMMENT ON COLUMN warehouse.g3_usuario.nm_usua IS 'Nombre del usuario.'
/
COMMENT ON COLUMN warehouse.g3_usuario.nu_perf_usua IS 'Secuencial identificador del perfil al cual pertenece el usuario.'
/
COMMENT ON COLUMN warehouse.g3_usuario.nu_usua IS 'Secuencial identificador del usuario.'
/

CREATE UNIQUE INDEX warehouse.pk_usuari
 ON warehouse.g3_usuario
  ( nu_usua  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE UNIQUE INDEX warehouse.un_usuari
 ON warehouse.g3_usuario
  ( nm_usua  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros
 STORAGE (
   INITIAL     16384
   NEXT        8192
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  2147483645
   )
/

CREATE TABLE warehouse.g3_vision
 (
  nu_vision                  NUMBER(5) NOT NULL,
  nm_vision                  VARCHAR2(180) NOT NULL,
  nu_dimen__1                NUMBER(5) NOT NULL,
  nu_dimen__2                NUMBER(5) NOT NULL,
  nu_dimen__3                NUMBER(5) NOT NULL,
  nu_dimen__4                NUMBER(5) NOT NULL,
  nu_dimen__5                NUMBER(5) NOT NULL,
  nu_dimen__6                NUMBER(5) NOT NULL,
  nu_dimen__7                NUMBER(5) NOT NULL,
  nu_dimen__8                NUMBER(5) NOT NULL,
  nu_dimen__9                NUMBER(5) NOT NULL,
  nu_dimen__10               NUMBER(5) NOT NULL,
  nu_dimen__11               NUMBER(5) NOT NULL,
  nu_dimen__12               NUMBER(5) NOT NULL,
  nu_dimen__13               NUMBER(5) NOT NULL,
  nu_dimen__14               NUMBER(5) NOT NULL,
  nu_dimen__15               NUMBER(5) NOT NULL,
  nu_dimen__16               NUMBER(5) NOT NULL,
  CONSTRAINT pk_vision PRIMARY KEY (nu_vision) DISABLE,
  CONSTRAINT un_vision UNIQUE (nm_vision) DISABLE,
  CONSTRAINT fk_vision_dimens_01 FOREIGN KEY (nu_dimen__1)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE,
  CONSTRAINT fk_vision_dimens_02 FOREIGN KEY (nu_dimen__2)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE,
  CONSTRAINT fk_vision_dimens_03 FOREIGN KEY (nu_dimen__3)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE,
  CONSTRAINT fk_vision_dimens_04 FOREIGN KEY (nu_dimen__4)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE,
  CONSTRAINT fk_vision_dimens_05 FOREIGN KEY (nu_dimen__5)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE,
  CONSTRAINT fk_vision_dimens_06 FOREIGN KEY (nu_dimen__6)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE,
  CONSTRAINT fk_vision_dimens_07 FOREIGN KEY (nu_dimen__7)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE,
  CONSTRAINT fk_vision_dimens_08 FOREIGN KEY (nu_dimen__8)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE,
  CONSTRAINT fk_vision_dimens_09 FOREIGN KEY (nu_dimen__9)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE,
  CONSTRAINT fk_vision_dimens_10 FOREIGN KEY (nu_dimen__10)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE,
  CONSTRAINT fk_vision_dimens_11 FOREIGN KEY (nu_dimen__11)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE,
  CONSTRAINT fk_vision_dimens_12 FOREIGN KEY (nu_dimen__12)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE,
  CONSTRAINT fk_vision_dimens_13 FOREIGN KEY (nu_dimen__13)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE,
  CONSTRAINT fk_vision_dimens_14 FOREIGN KEY (nu_dimen__14)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE,
  CONSTRAINT fk_vision_dimens_15 FOREIGN KEY (nu_dimen__15)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE,
  CONSTRAINT fk_vision_dimens_16 FOREIGN KEY (nu_dimen__16)
      REFERENCES warehouse.g3_dimen(nu_dimen)  DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_vision IS 'Cruces de dimensiones que definem la forma como los datos existem en la empresa. Una vision puede ser compuesta por hasta 16 dimensiones.'
/

COMMENT ON COLUMN warehouse.g3_vision.nm_vision IS 'Nombre de la vision de negocio, armado a partir de los nombres de las dimensiones que componem la vision'
/
COMMENT ON COLUMN warehouse.g3_vision.nu_dimen__1 IS 'Identificador de la primera dimension que compone la vision.'
/
COMMENT ON COLUMN warehouse.g3_vision.nu_dimen__10 IS 'Identificador de la decima dimension que compone la vision. Caso no exista, se pone el valor 0.'
/
COMMENT ON COLUMN warehouse.g3_vision.nu_dimen__11 IS 'Identificador de la decima-primera dimension que compone la vision. Caso no exista, se pone el valor 0.'
/
COMMENT ON COLUMN warehouse.g3_vision.nu_dimen__12 IS 'Identificador de la decima-secunda dimension que compone la vision. Caso no exista, se pone el valor 0.'
/
COMMENT ON COLUMN warehouse.g3_vision.nu_dimen__2 IS 'Identificador de la secunda dimension que compone la vision. Caso no exista, se pone el valor 0.'
/
COMMENT ON COLUMN warehouse.g3_vision.nu_dimen__3 IS 'Identificador de la tercera dimension que compone la vision. Caso no exista, se pone el valor 0.'
/
COMMENT ON COLUMN warehouse.g3_vision.nu_dimen__4 IS 'Identificador de la cuarta dimension que compone la vision. Caso no exista, se pone el valor 0.'
/
COMMENT ON COLUMN warehouse.g3_vision.nu_dimen__5 IS 'Identificador de la quinta dimension que compone la vision. Caso no exista, se pone el valor 0.'
/
COMMENT ON COLUMN warehouse.g3_vision.nu_dimen__6 IS 'Identificador de la sexta dimension que compone la vision. Caso no exista, se pone el valor 0.'
/
COMMENT ON COLUMN warehouse.g3_vision.nu_dimen__7 IS 'Identificador de la septima dimension que compone la vision. Caso no exista, se pone el valor 0.'
/
COMMENT ON COLUMN warehouse.g3_vision.nu_dimen__8 IS 'Identificador de la ochava dimension que compone la vision. Caso no exista, se pone el valor 0.'
/
COMMENT ON COLUMN warehouse.g3_vision.nu_dimen__9 IS 'Identificador de la nona dimension que compone la vision. Caso no exista, se pone el valor 0.'
/
COMMENT ON COLUMN warehouse.g3_vision.nu_vision IS 'Identificador de la vision del negocio.'
/

CREATE UNIQUE INDEX warehouse.pk_vision
 ON warehouse.g3_vision
  ( nu_vision  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        16384
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE UNIQUE INDEX warehouse.un_vision
 ON warehouse.g3_vision
  ( nm_vision  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     16384
   NEXT        32768
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.g3_vl_vald_atrb_dimen
 (
  nu_dimen                   NUMBER(5) NOT NULL,
  nu_atrb_dimen              NUMBER(5) NOT NULL,
  nu_valor_vald_atrb_dimen   NUMBER(5) NOT NULL,
  tx_valor_vald_atrb_dimen   VARCHAR2(2000) NOT NULL,
  CONSTRAINT pk_vlvald PRIMARY KEY (nu_dimen,nu_atrb_dimen,nu_valor_vald_atrb_dimen) DISABLE,
  CONSTRAINT fk_vlvald_atrdim FOREIGN KEY (nu_dimen,nu_atrb_dimen)
      REFERENCES warehouse.g3_atrb_dimen(nu_dimen,nu_atrb_dimen) ON DELETE CASCADE DISABLE
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     262144
      NEXT        65536
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  249
   )
/

COMMENT ON TABLE warehouse.g3_vl_vald_atrb_dimen IS 'Valores validos de atributos de dimension. Cuando el atributo no permite valores libres, debe ser informada una lista de valores validos para el. Esta lista es almacenada en esta tabla.'
/

COMMENT ON COLUMN warehouse.g3_vl_vald_atrb_dimen.nu_atrb_dimen IS 'Identificador unico del atributo de la dimension.'
/
COMMENT ON COLUMN warehouse.g3_vl_vald_atrb_dimen.nu_dimen IS 'Identificador unico de la dimension del atributo.'
/
COMMENT ON COLUMN warehouse.g3_vl_vald_atrb_dimen.nu_valor_vald_atrb_dimen IS 'Identificador secuencial del valor valido del atributo.'
/
COMMENT ON COLUMN warehouse.g3_vl_vald_atrb_dimen.tx_valor_vald_atrb_dimen IS 'Valor valido del atributo.'
/

CREATE UNIQUE INDEX warehouse.pk_vlvald
 ON warehouse.g3_vl_vald_atrb_dimen
  ( nu_dimen,
    nu_atrb_dimen,
    nu_valor_vald_atrb_dimen  )
  PCTFREE    10
  INITRANS   2
  MAXTRANS   255
  TABLESPACE dw_otros_idx
 STORAGE (
   INITIAL     65536
   NEXT        32768
   PCTINCREASE 0
   MINEXTENTS  1
   MAXEXTENTS  249
   )
/

CREATE TABLE warehouse.plan_table
 (
  statement_id               VARCHAR2(30),
  timestamp                  DATE,
  remarks                    VARCHAR2(80),
  operation                  VARCHAR2(30),
  options                    VARCHAR2(30),
  object_node                VARCHAR2(128),
  object_owner               VARCHAR2(30),
  object_name                VARCHAR2(30),
  object_instance            NUMBER,
  object_type                VARCHAR2(30),
  optimizer                  VARCHAR2(255),
  search_columns             NUMBER,
  id                         NUMBER,
  parent_id                  NUMBER,
  position                   NUMBER,
  other                      LONG,
  other_tag                  VARCHAR2(255)
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        16384
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  121
   )
/

GRANT DELETE,INSERT,SELECT,UPDATE ON warehouse.plan_table TO public
/

CREATE TABLE warehouse.temp_indca_24
 (
  nu_indca_perfm             NUMBER(5) NOT NULL,
  nu_vision                  NUMBER(5) NOT NULL,
  nu_instan_dimen__1         NUMBER(8) NOT NULL,
  nu_instan_dimen__2         NUMBER(8) NOT NULL,
  nu_instan_dimen__3         NUMBER(8) NOT NULL,
  nu_instan_dimen__4         NUMBER(8) NOT NULL,
  nu_instan_dimen__5         NUMBER(8) NOT NULL,
  nu_instan_dimen__6         NUMBER(8) NOT NULL,
  nu_instan_dimen__7         NUMBER(8) NOT NULL,
  nu_instan_dimen__8         NUMBER(8) NOT NULL,
  nu_instan_dimen__9         NUMBER(8) NOT NULL,
  nu_instan_dimen__10        NUMBER(8) NOT NULL,
  nu_instan_dimen__11        NUMBER(8) NOT NULL,
  nu_instan_dimen__12        NUMBER(8) NOT NULL,
  nu_instan_dimen__13        NUMBER(8) NOT NULL,
  nu_instan_dimen__14        NUMBER(8) NOT NULL,
  nu_instan_dimen__15        NUMBER(8) NOT NULL,
  nu_instan_dimen__16        NUMBER(8) NOT NULL,
  fc_refr_serie_hist         DATE NOT NULL,
  cd_grnl_serie_hist         CHAR(1) NOT NULL,
  ct_valor_serie_hist        NUMBER(25,7) NOT NULL,
  nu_fuente_indca_perfm      NUMBER(5) NOT NULL,
  fc_gen_fuente_indca_perfm  DATE NOT NULL
 )
 PCTFREE    10
 PCTUSED    40
 INITRANS   1
 MAXTRANS   255
 TABLESPACE dw_otros
 STORAGE   (
      INITIAL     16384
      NEXT        8192
      PCTINCREASE 0
      MINEXTENTS  1
      MAXEXTENTS  2147483645
   )
/
