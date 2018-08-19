#ifndef _ESTRUCTURAS_H_
#define _ESTRUCTURAS_H_

#include "Tiempo/Horario.h"

typedef struct
{
   char nombre[50];
   char direccion[100];
   long long telefono;
} Cliente;

typedef struct
{
   int clave;
   Cliente cliente;
   Horario horario;
} Reservacion;

typedef struct _NodoReservacion
{
   Reservacion *reservacion;
   struct _NodoReservacion *siguiente;
} NodoReservacion;

typedef struct
{
   int numero;
   int capacidad;
   NodoReservacion *reservaciones;
   NodoReservacion *reservacionesCanceladas;
} Mesa;

typedef struct _NodoMesa
{
   Mesa *mesa;
   struct _NodoMesa *siguiente;
} NodoMesa;

typedef struct
{
   NodoMesa *mesas;
} Restaurante;

#endif