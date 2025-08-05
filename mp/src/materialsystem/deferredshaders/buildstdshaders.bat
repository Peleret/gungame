@echo off
setlocal

rem This script builds all the shaders... like you're a real game or something.

set BUILD_SHADER=call buildshaders.bat

set SOURCE_DIR="C:\stardust-sdk\source-sdk-2013\src"
set GAME_DIR="C:\stardust-sdk\source-sdk-2013\game\mod_hl2mp"

//%BUILD_SHADER% stdshader_dx9_20b       -game %GAME_DIR% -source %SOURCEDIR%
%BUILD_SHADER% deferred_shaders_sm2  -game %GAME_DIR% -source %SOURCEDIR%
%BUILD_SHADER% deferred_shaders       -game %GAME_DIR% -source %SOURCEDIR%

pause