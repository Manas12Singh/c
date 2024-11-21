@echo off
setlocal enabledelayedexpansion

.\%1.exe
rm -f .\%1.exe