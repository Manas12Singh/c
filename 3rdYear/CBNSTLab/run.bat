@echo off
setlocal enabledelayedexpansion

if "%~1" neq "" (
    cd /d "%~1" || (
        echo Failed to change directory to %~1
        exit /b 1
    )
)

for %%f in (*.c) do (
    gcc "%%f" -o "%%~nf.exe"
    if exist "%%~nf.exe" (
        echo.
        echo PS ManasSingh\2219046\B2\36^>.\a.exe
        .\%%~nf.exe
        echo.
    )
    rm -f "%%~nf.exe"
)