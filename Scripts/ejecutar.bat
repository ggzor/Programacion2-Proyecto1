@echo off
rem Para restaurar si hay error
set directorio=%CD%

chcp 65001
Scripts\compilar^
 && echo [1mComenzando ejecución...[0m^
 && Programa.exe

if %ERRORLEVEL% EQU 0 (
  echo [32mEjecución correcta.[0m
) else (
  chdir /d %directorio%
  echo [91mEjecución fallida.[0m && exit /B 1
)
