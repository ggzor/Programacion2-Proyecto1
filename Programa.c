#include <stdio.h>

typedef struct
{
   NodoMesa *mesas;
   NodoReservacion *reservacion;
} Restaurante;

typedef struct
{
   Mesa *mesa;
   NodoMesa *siguiente;
} NodoMesa;

typedef struct
{
   Reservacion *reservacion;
   NodoReservacion *siguiente;
} NodoReservacion;

typedef struct
{
   int numero;
   int maximoPersonas;
   NodoReservacion *reservaciones;
} Mesa;

typedef struct
{
   Intervalo intervalo;
   Cliente cliente;
} Reservacion;

typedef struct
{
   Fecha fecha;
   Hora inicio;
   Hora fin;
} Intervalo;

typedef struct
{
   char nombre[50];
   char direccion[100];
   long long telefono;
} Cliente;

typedef struct
{
   int dia;
   int mes;
   int año;
} Fecha;

typedef struct
{
   int segundo;
   int minuto;
   int hora;
} Hora;

int main(int argc, char **argv)
{
   return 0;
}