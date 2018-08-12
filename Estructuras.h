#ifndef _ESTRUCTURAS_H_
#define _ESTRUCTURAS_H_

typedef struct
{
   char nombre[50];
   char direccion[100];
   long long telefono;
} Cliente;

typedef struct
{
   int anio;
   int mes;
   int dia;
} Fecha;

typedef struct
{
   int hora;
   int minuto;
} Hora;

typedef struct
{
   Fecha fecha;
   Hora inicio;
   Hora fin;
} Intervalo;

typedef struct
{
   Cliente cliente;
   Intervalo intervalo;
} Reservacion;

typedef struct
{
   Reservacion *reservacion;
   struct NodoReservacion *siguiente;
} NodoReservacion;

typedef struct
{
   int numero;
   int capacidad;
   NodoReservacion *reservaciones;
} Mesa;

typedef struct
{
   Mesa *mesa;
   struct NodoMesa *siguiente;
} NodoMesa;

typedef struct
{
   int mesaCapacidadMaxima;
   NodoMesa *mesas;
   NodoReservacion *reservacionesCanceladas;
} Restaurante;

#endif