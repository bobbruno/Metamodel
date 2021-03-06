CREATE TABLESPACE INTERFASE
   DEFAULT STORAGE (
      INITIAL 8M NEXT 16M PCTINCREASE 0 MINEXTENTS 10 MAXEXTENTS 250)
   DATAFILE 'E:\ORADATA\INTERFASE01.DBF' SIZE 335M,
            'F:\ORADATA\INTERFASE02.DBF' SIZE 335M,
            'G:\ORADATA\INTERFASE03.DBF' SIZE 335M
/

CREATE TABLESPACE DW_OTROS
   DEFAULT STORAGE (
      INITIAL 48M NEXT 48M PCTINCREASE 0 MINEXTENTS 1 MAXEXTENTS 250)
   DATAFILE 'E:\ORADATA\DW_OTROS01.DBF' SIZE 1024M
/

CREATE TABLESPACE DW_OTROS_IDX
   DEFAULT STORAGE (
      INITIAL 16M NEXT 32M PCTINCREASE 0 MINEXTENTS 1 MAXEXTENTS 250)
   DATAFILE 'F:\ORADATA\DW_OTROS_IDX01.DBF' SIZE 1024M
/

CREATE TABLESPACE DW_DATA
   DEFAULT STORAGE (
      INITIAL 32M NEXT 32M PCTINCREASE 0 MINEXTENTS 5 MAXEXTENTS 250)
   DATAFILE 'E:\ORADATA\DW_DATA01.DBF' SIZE 1024M,
            'F:\ORADATA\DW_DATA02.DBF' SIZE 1024M,
            'G:\ORADATA\DW_DATA03.DBF' SIZE 1024M
/

CREATE TABLESPACE DW_IDX
   DEFAULT STORAGE (
      INITIAL 32M NEXT 32M PCTINCREASE 0 MINEXTENTS 5 MAXEXTENTS 250)
   DATAFILE 'G:\ORADATA\DW_IDX01.DBF' SIZE 1024M,
            'E:\ORADATA\DW_IDX02.DBF' SIZE 1024M,
            'F:\ORADATA\DW_IDX03.DBF' SIZE 1024M
/

CREATE TABLESPACE DW_TEMP
   DEFAULT STORAGE (
      INITIAL 8M NEXT 8M PCTINCREASE 0 MINEXTENTS 10 MAXEXTENTS 250)
   DATAFILE 'G:\ORADATA\DW_TEMP01.DBF' SIZE 256M,
            'E:\ORADATA\DW_TEMP02.DBF' SIZE 256M,
            'F:\ORADATA\DW_TEMP03.DBF' SIZE 256M
/

CREATE TABLESPACE DW_TEMP_IDX
   DEFAULT STORAGE (
      INITIAL 18M NEXT 8M PCTINCREASE 0 MINEXTENTS 10 MAXEXTENTS 250)
   DATAFILE 'F:\ORADATA\DW_IDX01.DBF' SIZE 128M,
            'G:\ORADATA\DW_IDX02.DBF' SIZE 128M,
            'E:\ORADATA\DW_IDX03.DBF' SIZE 128M
/

