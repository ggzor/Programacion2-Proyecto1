@echo off

gcc Datos/Almacenamiento/Cargar.c Datos/Almacenamiento/Guardar.c Datos/Constructores/Mesa.c Datos/Constructores/Reservacion.c Datos/Constructores/Restaurante.c Datos/Impresion/FormatoCompleto.c Datos/Impresion/FormatoCorto.c Datos/InformacionReservacion.c Datos/Lectura/Cliente.c Datos/Lectura/Fecha.c Datos/Lectura/Hora.c Datos/Lectura/Horario.c Datos/Manejo/Mesas.c Datos/Manejo/Reservaciones.c Datos/Pruebas/ValoresPrueba.c Interfaz/Lectura.c Operaciones/Administrador.c Operaciones/Administrador/VerDatosDeMesas.c Operaciones/Administrador/VerHorariosDeMesas.c Operaciones/Cliente.c Operaciones/Cliente/BuscarReservacion.c Operaciones/Cliente/HacerReservacion.c Operaciones/Cliente/NotificarLlegada.c Operaciones/Menus.c Operaciones/Pruebas.c Operaciones/Pruebas/EstablecerTiempo.c Operaciones/Pruebas/RestablecerTiempo.c Programa.c Tiempo/Horario.c Tiempo/Impresion.c Tiempo/Intervalos/IntervaloFechas.c Tiempo/Intervalos/IntervaloHoras.c Tiempo/Primitivas/Fecha.c Tiempo/Primitivas/FechaHora.c Tiempo/Primitivas/Hora.c Tiempo/Tiempo.c -o Programa -lm -g

if %ERRORLEVEL% EQU 0 (
  echo [32mCompilación correcta.[0m
) else (
  chdir /d %directorio%
  echo [91mCompilación fallida.[0m && exit /B 1
)
