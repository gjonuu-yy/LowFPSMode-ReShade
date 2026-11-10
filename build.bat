@echo off
setlocal
cd /d "%~dp0"

where git >nul 2>nul
if errorlevel 1 (
    echo Git is required. Install Git for Windows and run this file again.
    pause
    exit /b 1
)

where cmake >nul 2>nul
if errorlevel 1 (
    echo CMake is required. Install CMake and run this file again.
    pause
    exit /b 1
)

if not exist "external\reshade\include\reshade.hpp" (
    if not exist "external" mkdir external
    git clone --depth 1 https://github.com/crosire/reshade.git external\reshade
    if errorlevel 1 exit /b 1
)

cmake -S . -B build -A x64 -DRESHADE_INCLUDE_DIR="%CD%\external\reshade\include"
if errorlevel 1 goto :failed

cmake --build build --config Release
if errorlevel 1 goto :failed

echo.
echo Build complete. Look for build\Release\LowFPSMode.addon64
pause
exit /b 0

:failed
echo.
echo Build failed. Check that Visual Studio 2022 with the Desktop development with C++ workload is installed.
pause
exit /b 1
