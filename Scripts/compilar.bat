@echo off
rem Para restaurar si hay error
set directorio=%CD%

chcp 65001
cls
Scripts\actualizar^
 && echo [1mCompilando...[0m^
 && Scripts\invocar_compilador
