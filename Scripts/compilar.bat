@echo off
rem Para restaurar si hay error
set directorio=%CD%

cls
Scripts\actualizar^
 && echo [1mCompilando...[0m^
 && Scripts\invocar_compilador

if %ERRORLEVEL% EQU 0 (
  echo [32mCompilacion correcta.[0m
) else (
  chdir /d %directorio%
  echo [91mCompilacion fallida.[0m && exit /B 1
)
