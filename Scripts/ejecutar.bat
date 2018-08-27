@echo off
rem Para restaurar si hay error
set directorio=%CD%

chcp 65001
IF NOT EXIST .configurado (
  echo [33mIMPORTANTE: Cambia el tipo de fuente de la consola para que se muestren los caracteres correctamente[0m
  echo https://www.downloadsource.es/como-personalizar-la-fuente-y-color-de-simbolo-del-sistema-letras-y-fondo-del-cmd/n/9269/
  echo Se recomienda usar la fuente 'DejaVu Sans Mono'
  echo Los caracteres siguientes deberían mostrarse correctamente: ↻ ✔ ⚑ ◴ ◴ ✘
  echo. 2>.configurado
  pause
)

Scripts\compilar^
 && echo [1mComenzando ejecución...[0m^
 && Programa.exe

if %ERRORLEVEL% EQU 0 (
  echo [32mEjecución correcta.[0m
) else (
  chdir /d %directorio%
  echo [91mEjecución fallida.[0m && exit /B 1
)
