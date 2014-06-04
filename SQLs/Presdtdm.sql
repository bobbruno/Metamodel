UPDATE G3_INDCA_PERFM
SET 
   CD_INDCA_OK_DM = '1'
WHERE
   CD_INDCA_ATUAL = '1';

UPDATE G3_INDCA_PERFM
SET 
   CD_INDCA_OK_DM = '2'
WHERE
   CD_INDCA_OK_DM <> '0' AND
   EXISTS (SELECT CD_INDCA_ATUAL FROM G3_INDCA_PERFM WHERE CD_INDCA_ATUAL = '1') AND
   NOT EXISTS(
      (SELECT A.NU_FUENTE_INDCA_PERFM 
        FROM G3_FUENTE_INDCA_PERFM A,
             G3_PRVD_DATO B
        WHERE 
           A.NU_PRVD_DATO = B.NU_PRVD_DATO AND
           B.NM_SISTEMA = 'SPCO')
      MINUS 
      (SELECT
          A.NU_FUENTE_INDCA_PERFM
       FROM G3_LOG_FUENTE_INDCA_PERFM A,
            G3_FUENTE_INDCA_PERFM B,
            G3_PRVD_DATO C
       WHERE
          A.FC_REFR_FUENTE_INDCA_PERFM IN ( 
                                     SELECT 
                                        TO_DATE(TX_VL_PARM_SIST,'DD-MM-YYYY HH24:MI:SS')
                                     FROM G3_PARM_SIST
                                     WHERE
                                        NU_PARM_SIST=1000)
          AND A.CD_ESTD_LOTE_DATOS = 'L'
          AND A.FC_ATUALIZ_DW IS NOT NULL
          AND A.NU_FUENTE_INDCA_PERFM =B.NU_FUENTE_INDCA_PERFM
          AND B.NU_PRVD_DATO = C.NU_PRVD_DATO 
          AND C.NM_SISTEMA = 'SPCO'));

UPDATE G3_PARM_SIST
SET TX_VL_PARM_SIST = 
TO_CHAR(ADD_MONTHS(TO_DATE(TX_VL_PARM_SIST, 'DD-MM-YYYY HH24:MI:SS'), 1), 'DD-MM-YYYY HH24:MI:SS')
WHERE
   G3_PARM_SIST.NU_PARM_SIST = 1000 AND
   EXISTS (SELECT CD_INDCA_ATUAL FROM G3_INDCA_PERFM WHERE CD_INDCA_ATUAL = '1') AND
   NOT EXISTS(
      (SELECT A.NU_FUENTE_INDCA_PERFM 
        FROM G3_FUENTE_INDCA_PERFM A,
             G3_PRVD_DATO B
        WHERE 
           A.NU_PRVD_DATO = B.NU_PRVD_DATO AND
           B.NM_SISTEMA = 'SPCO')
      MINUS 
      (SELECT
          A.NU_FUENTE_INDCA_PERFM
       FROM G3_LOG_FUENTE_INDCA_PERFM A,
            G3_FUENTE_INDCA_PERFM B,
            G3_PRVD_DATO C
       WHERE
          A.FC_REFR_FUENTE_INDCA_PERFM IN ( 
                                     SELECT 
                                        TO_DATE(TX_VL_PARM_SIST,'DD-MM-YYYY HH24:MI:SS')
                                     FROM G3_PARM_SIST
                                     WHERE
                                        NU_PARM_SIST=1000)
          AND A.CD_ESTD_LOTE_DATOS = 'L'
          AND A.FC_ATUALIZ_DW IS NOT NULL
          AND A.NU_FUENTE_INDCA_PERFM =B.NU_FUENTE_INDCA_PERFM
          AND B.NU_PRVD_DATO = C.NU_PRVD_DATO 
          AND C.NM_SISTEMA = 'SPCO'));

COMMIT;

EXIT