# Microsoft Developer Studio Project File - Name="PROCDW" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=PROCDW - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "PROCDW.MAK".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PROCDW.MAK" CFG="PROCDW - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PROCDW - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "PROCDW - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PROCDW - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /G5 /MT /W3 /GX /O2 /Ob2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR /YX /FD /c
# SUBTRACT CPP /nologo
# ADD BASE RSC /l 0x416 /d "NDEBUG"
# ADD RSC /l 0x416 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "PROCDW - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x416 /d "_DEBUG"
# ADD RSC /l 0x416 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "PROCDW - Win32 Release"
# Name "PROCDW - Win32 Debug"
# Begin Group "Pro*C Files"

# PROP Default_Filter "pc"
# Begin Source File

SOURCE=.\Atual2.pc

!IF  "$(CFG)" == "PROCDW - Win32 Release"

# Begin Custom Build - Compilando Atual2.pc
ProjDir=.
InputPath=.\Atual2.pc
InputName=Atual2

"$(ProjDir)\$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	proc iname=$(ProjDir)\$(InputName).pc userid=warehouse/warehouse@nabiscoprod

# End Custom Build

!ELSEIF  "$(CFG)" == "PROCDW - Win32 Debug"

# Begin Custom Build
ProjDir=.
InputPath=.\Atual2.pc
InputName=Atual2

"$(ProjDir)\$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	c:\orawin95\bin\proc $(ProjDir)\$(InputName).pc\
             include=c:\orawin95\pro22\c\include include=c:\orawin95\oci73\include\
             include=d:\archiv~1\devstudio\vc\include sqlcheck=full\
             userid=warehouse/warehouse oraca=yes parse=full

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Calc.pc

!IF  "$(CFG)" == "PROCDW - Win32 Release"

# Begin Custom Build - Compilando Calc.PC
ProjDir=.
InputPath=.\Calc.pc
InputName=Calc

"$(ProjDir)\$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	proc iname=$(ProjDir)\$(InputName).pc userid=warehouse/warehouse@nabiscoprod

# End Custom Build

!ELSEIF  "$(CFG)" == "PROCDW - Win32 Debug"

# Begin Custom Build
ProjDir=.
InputPath=.\Calc.pc
InputName=Calc

"$(ProjDir)\$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	c:\orawin95\bin\proc $(ProjDir)\$(InputName).pc\
             include=c:\orawin95\pro22\c\include include=c:\orawin95\oci73\include\
             include=d:\archiv~1\devstudio\vc\include sqlcheck=full\
             userid=warehouse/warehouse oraca=yes parse=full

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Calccons.pc

!IF  "$(CFG)" == "PROCDW - Win32 Release"

# Begin Custom Build - Compilando CalcCons.PC
ProjDir=.
InputPath=.\Calccons.pc
InputName=Calccons

"$(ProjDir)\$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	proc iname=$(ProjDir)\$(InputName).pc userid=warehouse/warehouse@nabiscoprod

# End Custom Build

!ELSEIF  "$(CFG)" == "PROCDW - Win32 Debug"

# Begin Custom Build
ProjDir=.
InputPath=.\Calccons.pc
InputName=Calccons

"$(ProjDir)\$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	c:\orawin95\bin\proc $(ProjDir)\$(InputName).pc\
             include=c:\orawin95\pro22\c\include include=c:\orawin95\oci73\include\
             include=d:\archiv~1\devstudio\vc\include sqlcheck=full\
             userid=warehouse/warehouse oraca=yes parse=full

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Constemp.pc

!IF  "$(CFG)" == "PROCDW - Win32 Release"

# Begin Custom Build - Compilando ConsTemp.PC
ProjDir=.
InputPath=.\Constemp.pc
InputName=Constemp

"$(ProjDir)\$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	proc iname=$(ProjDir)\$(InputName).pc userid=warehouse/warehouse@nabiscoprod

# End Custom Build

!ELSEIF  "$(CFG)" == "PROCDW - Win32 Debug"

# Begin Custom Build
ProjDir=.
InputPath=.\Constemp.pc
InputName=Constemp

"$(ProjDir)\$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	c:\orawin95\bin\proc $(ProjDir)\$(InputName).pc\
             include=c:\orawin95\pro22\c\include include=c:\orawin95\oci73\include\
             include=d:\archiv~1\devstudio\vc\include sqlcheck=full\
             userid=warehouse/warehouse oraca=yes parse=full

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Dw_aux.pc

!IF  "$(CFG)" == "PROCDW - Win32 Release"

# Begin Custom Build - Compilando DW_AUX.PC
ProjDir=.
InputPath=.\Dw_aux.pc
InputName=Dw_aux

"$(ProjDir)\$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	proc iname=$(ProjDir)\$(InputName).pc userid=warehouse/warehouse@nabiscoprod

# End Custom Build

!ELSEIF  "$(CFG)" == "PROCDW - Win32 Debug"

# Begin Custom Build
ProjDir=.
InputPath=.\Dw_aux.pc
InputName=Dw_aux

"$(ProjDir)\$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	c:\orawin95\bin\proc $(ProjDir)\$(InputName).pc\
             include=c:\orawin95\pro22\c\include include=c:\orawin95\oci73\include\
             include=d:\archiv~1\devstudio\vc\include sqlcheck=full\
             userid=warehouse/warehouse oraca=yes parse=full

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Jerarq.pc

!IF  "$(CFG)" == "PROCDW - Win32 Release"

# Begin Custom Build - Compilando Jerarq.PC
ProjDir=.
InputPath=.\Jerarq.pc
InputName=Jerarq

"$(ProjDir)\$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	proc iname=$(ProjDir)\$(InputName).pc userid=warehouse/warehouse@nabiscoprod

# End Custom Build

!ELSEIF  "$(CFG)" == "PROCDW - Win32 Debug"

# Begin Custom Build
ProjDir=.
InputPath=.\Jerarq.pc
InputName=Jerarq

"$(ProjDir)\$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	c:\orawin95\bin\proc $(ProjDir)\$(InputName).pc\
             include=c:\orawin95\pro22\c\include include=c:\orawin95\oci73\include\
             include=d:\archiv~1\devstudio\vc\include sqlcheck=full\
             userid=warehouse/warehouse oraca=yes parse=full

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Lmpdw.pc

!IF  "$(CFG)" == "PROCDW - Win32 Release"

# Begin Custom Build - Compilando LMPDW.PC
ProjDir=.
InputPath=.\Lmpdw.pc
InputName=Lmpdw

"$(ProjDir)\$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	proc iname=$(ProjDir)\$(InputName).pc userid=warehouse/warehouse@nabiscoprod

# End Custom Build

!ELSEIF  "$(CFG)" == "PROCDW - Win32 Debug"

# Begin Custom Build
ProjDir=.
InputPath=.\Lmpdw.pc
InputName=Lmpdw

"$(ProjDir)\$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	c:\orawin95\bin\proc $(ProjDir)\$(InputName).pc\
             include=c:\orawin95\pro22\c\include include=c:\orawin95\oci73\include\
             include=d:\archiv~1\devstudio\vc\include sqlcheck=full\
             userid=warehouse/warehouse oraca=yes parse=full

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Generated C Files"

# PROP Default_Filter "c"
# Begin Source File

SOURCE=.\atual2.c
# End Source File
# Begin Source File

SOURCE=.\calc.c
# End Source File
# Begin Source File

SOURCE=.\calccons.c
# End Source File
# Begin Source File

SOURCE=.\constemp.c
# End Source File
# Begin Source File

SOURCE=.\dw_aux.c
# End Source File
# Begin Source File

SOURCE=.\jerarq.c
# End Source File
# Begin Source File

SOURCE=.\lmpdw.c
# End Source File
# Begin Source File

SOURCE=.\nmtabla.c
# End Source File
# End Group
# Begin Group "Libraries"

# PROP Default_Filter "lib"
# Begin Source File

SOURCE=C:\Orawin95\Oci73\Lib\Msvc\Ociw32.lib
# End Source File
# Begin Source File

SOURCE=C:\Orawin95\Oci73\Lib\Msvc\Ora73.lib
# End Source File
# Begin Source File

SOURCE=C:\Orawin95\Pro22\Lib\Msvc\Sqllib18.lib
# End Source File
# End Group
# End Target
# End Project
