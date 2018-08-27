@echo off
rem Para restaurar si hay error
set directorio=%CD%

Scripts\compilar^
 && echo [1mComenzando ejecucion...[0m^
 && Programa.exe

if %ERRORLEVEL% EQU 0 (
  echo [32mEjecucion correcta.[0m
) else (
  chdir /d %directorio%
  echo [91mEjecucion fallida.[0m && exit /B 1
)
