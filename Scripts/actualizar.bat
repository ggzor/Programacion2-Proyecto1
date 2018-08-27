@echo off

echo [1mActualizando archivos...[0m

rem Para restaurar si hay error
set directorio=%CD%

chcp 65001

cd Scripts ^
 && python generarDatosPrueba.py ^
 && cd .. ^
 && python Scripts\generarCodigoCompilacion.py

if %ERRORLEVEL% EQU 0 (
  echo [32mActualización correcta.[0m
) else (
  chdir /d %directorio%
  echo [91mActualización fallida.[0m && exit /B 1
)