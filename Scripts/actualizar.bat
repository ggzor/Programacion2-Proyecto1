@echo off

echo [1mActualizando archivos...[0m

rem Para restaurar si hay error
set directorio=%CD%

cd Scripts ^
 && python generarDatosPrueba.py ^
 && cd .. ^
 && python Scripts\generarCodigoCompilacion.py

if %ERRORLEVEL% EQU 0 (
  echo [32mActualizacion correcta.[0m
) else (
  chdir /d %directorio%
  echo [91mActualizacion fallida.[0m && exit /B 1
)