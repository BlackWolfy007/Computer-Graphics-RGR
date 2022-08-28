::@echo off

set Bat_Path=%~dp0
set Curr_Path=%cd%\

set x32=x32\
set x64=x64\
set incl=include\
set build=build\
set freegl=freeglut\
set gl=GL\
set source=src\
set lib=lib\
set Debug=Debug\
set Release=Release\
set bin=bin\
set freeglut=freeglut
set stat=_static
set fg_d=d

set /A sys_arch=0
set /A config=0

::File extensions
set lib_f=.lib
set exp=.exp
set pdb=.pdb
set dll=.dll

::Project directories
set Freeglut_Path=%Bat_Path%%source%%freegl%
set Freeglut_include=%Freeglut_Path%%incl%
set Freeglut_GL=%Freeglut_include%%gl%

set Freeglut_lib=%Freeglut_Path%%lib%

set Freeglut_x32=%Freeglut_lib%%x32%
set Freeglut_x32Debug=%Freeglut_x32%%Debug%
set Freeglut_x32Release=%Freeglut_x32%%Release%

set Freeglut_x64=%Freeglut_lib%%x64%
set Freeglut_x64Debug=%Freeglut_x64%%Debug%
set Freeglut_x64Release=%Freeglut_x64%%Release%

::Freeglut source directories
set Curr_Path_include=%Curr_Path%%incl%
set Curr_Path_GL=%Curr_Path_include%%gl%
set Curr_Path_build=%Curr_Path%%build%

set Curr_Path_x32=%Curr_Path_build%%x32%

set Curr_Path_x32_lib=%Curr_Path_x32%%lib%
set Curr_Path_x32_libDebug=%Curr_Path_x32_lib%%Debug%
set Curr_Path_x32_libRelease=%Curr_Path_x32_lib%%Release%

set Curr_Path_x32_bin=%Curr_Path_x32%%bin%
set Curr_Path_x32_binDebug=%Curr_Path_x32_bin%%Debug%
set Curr_Path_x32_binRelease=%Curr_Path_x32_bin%%Release%

set Curr_Path_x64=%Curr_Path_build%%x64%

set Curr_Path_x64_lib=%Curr_Path_x64%%lib%
set Curr_Path_x64_libDebug=%Curr_Path_x64_lib%%Debug%
set Curr_Path_x64_libRelease=%Curr_Path_x64_lib%%Release%

set Curr_Path_x64_bin=%Curr_Path_x64%%bin%
set Curr_Path_x64_binDebug=%Curr_Path_x64_bin%%Debug%
set Curr_Path_x64_binRelease=%Curr_Path_x64_bin%%Release%

::echo %Freeglut_GL%
::echo %Curr_Path_include%
::echo %Freeglut_Path%
::mkdir %Freeglut_Path%
::echo %cd%

::BEGIN
goto BEGIN

:BEGIN
::Project path
set dir=%Freeglut_Path%
call :FG_EXIST %dir%

set dir=%Freeglut_include%
call :FG_EXIST %dir%

set dir=%Freeglut_GL%
call :FG_EXIST %dir%

set dir=%Freeglut_lib%
call :FG_EXIST %dir%

set dir=%Freeglut_x32%
call :FG_EXIST %dir%

set dir=%Freeglut_x64%
call :FG_EXIST %dir%

set dir=%Freeglut_x32Debug%
call :FG_EXIST %dir%

set dir=%Freeglut_x32Release%
call :FG_EXIST %dir%

set dir=%Freeglut_x64Debug%
call :FG_EXIST %dir%

set dir=%Freeglut_x64Release%
call :FG_EXIST %dir%
::Current path
set dir=%Curr_Path_include%
call :CP_EXIST %dir% %sys_arch% %config%

set dir=%Curr_Path_GL%
call :CP_EXIST %dir% %sys_arch% %config%

set file=%Curr_Path_GL%
set dir=%Freeglut_GL%
call :COPY_FILES %file% %dir% %config%

set dir=%Curr_Path_build%
call :CP_EXIST %dir% %sys_arch% %config%

set /A sys_arch=1
set dir=%Curr_Path_x32%
call :CP_EXIST %dir% %sys_arch% %config%

if (%sys_arch%==1) (
	set dir=%Curr_Path_x32_bin%
	call :CP_EXIST %dir% %sys_arch% %config%
	
	set dir=%Curr_Path_x32_binDebug%
	set /A config=1
	call :CP_EXIST %dir% %sys_arch% %config%
	if (%config%==1) (
		call :CPY_FILES_DEBUG %dir% %sys_arch%
	)
)

goto EXIT

:FG_EXIST
if not exist "%dir%" (
	mkdir "%dir%"
)
exit /b

:CP_EXIST
(if not exist "%dir%") && (if %sys_arch%==0) && (if %config%==0) (
	echo There is no "%dir%" folder. Program shuts down...
	goto EXIT
)
(if not exist "%dir%") && (if %sys_arch%==1) && (if %config%==0) (
	set /A sys_arch=0
)
(if not exist "%dir%") && (if %sys_arch%==1) && (if %config%==1) (
	set /A config=2
)
(if not exist "%dir%") && (if %sys_arch%==1) && (if %config%==2) (
	echo There is no "%dir%" folder. Program shuts down...
	goto EXIT
)
exit /b

:COPY_FILES
xcopy "%file%" "%dir%" /y /q
exit /b

:CPY_FILES_DEBUG
if (%sys_arch%==1) (
	xcopy "%dir%%freeglut%%d%%dll%" "%Freeglut_x32Debug%" /y /q
	xcopy "%dir%%freeglut%%d%%pdb%" "%Freeglut_x32Debug%" /y /q
) else (
	xcopy "%dir%%freeglut%%d%%dll%" "%Freeglut_x64Debug%" /y /q
	xcopy "%dir%%freeglut%%d%%pdb%" "%Freeglut_x64Debug%" /y /q
)

exit /b

:CPY_FILES_RELEASE
if (%sys_arch%==1) (
	xcopy "%dir%%freeglut%%dll%" "%Freeglut_x32Release%" /y /q
	xcopy "%dir%%freeglut%%pdb%" "%Freeglut_x32Release%" /y /q
) else (
	xcopy "%dir%%freeglut%%dll%" "%Freeglut_x64Release%" /y /q
	xcopy "%dir%%freeglut%%pdb%" "%Freeglut_x64Release%" /y /q
)

exit /b

:EXIT
exit


	

