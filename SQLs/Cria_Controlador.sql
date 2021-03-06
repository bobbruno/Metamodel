
CREATE USER CONTROLADORIA_1 IDENTIFIED
 BY CONTROLADORIA_1
 DEFAULT TABLESPACE WAREHOUSE
 TEMPORARY TABLESPACE TEMP
/

GRANT CONNECT TO CONTROLADORIA_1
/

GRANT RESOURCE TO CONTROLADORIA_1
/

GRANT CONTROLADORIA TO CONTROLADORIA_1
/

CREATE SYNONYM CONTROLADORIA_1.G3_LOG_FUENTE_INDCA_PERFM
   FOR WAREHOUSE.G3_LOG_FUENTE_INDCA_PERFM
/

CREATE SYNONYM CONTROLADORIA_1.G3_FUENTE_INDCA_PERFM
   FOR WAREHOUSE.G3_FUENTE_INDCA_PERFM
/

CREATE SYNONYM CONTROLADORIA_1.G3_PRVD_DATO
   FOR WAREHOUSE.G3_PRVD_DATO
/

CREATE SYNONYM CONTROLADORIA_1.G3_UNID_ORGN
   FOR WAREHOUSE.G3_UNID_ORGN
/

CREATE SYNONYM CONTROLADORIA_1.G3_MOVT_SERIE_HIST
   FOR WAREHOUSE.G3_MOVT_SERIE_HIST
/

CREATE SYNONYM CONTROLADORIA_1.G3_EXTRT_SIG_CTRL
   FOR WAREHOUSE.G3_EXTRT_SIG_CTRL
/
