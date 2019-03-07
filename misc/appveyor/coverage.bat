@ECHO OFF

REM Extract absolute path to the source directory
SET SOURCES=%0
IF NOT "%SOURCES:~-27%"=="\misc\appveyor\coverage.bat" EXIT /B 100
SET SOURCES="%SOURCES:~0,-27%"

REM The first argument is
REM --log-file=PATH_TO_LOG_FILE
REM Let's extract the path!
SET LOG=%1
SHIFT
REM Fail fast if arguments are strange.
IF NOT "%LOG:~1,11%"=="--log-file=" EXIT /B 100
REM Strip the --log-file= part.
SET LOG="%LOG:~12,-1%"


REM There should be "--@" argument to
REM delimit actual test suite command.
SET TOKEN=%1
IF NOT "%TOKEN:~1,-1%"=="--@" EXIT /B 101
SHIFT


REM Remaining arguments are the actual
REM test binary with all its arguments.
IF "%1"=="" GOTO ARGS_CONT
SET "ARGS=%1"
SHIFT
:ARGS_LOOP
IF "%1"=="" GOTO ARGS_CONT
SET "ARGS=%ARGS% %1"
SHIFT
GOTO ARGS_LOOP
:ARGS_CONT


REM Run the actual test command
OpenCppCoverage --export_type binary:%LOG% --quiet --sources %SOURCES% --cover_children -- %ARGS%
EXIT /B
