@echo off
set filename=%1

if not exist "%filename%" (
    echo File not found: %filename%
    exit /b 1
)

gcc "%filename%" -o "%~n1.exe"
if exist "%~n1.exe" (
    echo.
    echo PS ManasSingh\2219046\B2\36^>.\a.exe
    .\%~n1.exe
    echo.
    rm -f "%~n1.exe"
)
