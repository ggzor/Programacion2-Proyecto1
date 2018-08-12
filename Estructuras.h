typedef struct Cliente
{
   char nombre[50];
   char direccion[100];
   long long telefono;
} Cliente;

typedef struct Fecha
{
   int anio;
   int mes;
   int dia;
} Fecha;

typedef struct Hora
{
   int hora;
   int minuto;
} Hora;

typedef struct Intervalo
{
   Fecha fecha;
   Hora inicio;
   Hora fin;
} Intervalo;

typedef struct Reservacion
{
   Cliente cliente;
   Intervalo intervalo;
} Reservacion;

typedef struct NodoReservacion
{
   Reservacion *reservacion;
   struct NodoReservacion *siguiente;
} NodoReservacion;

typedef struct Mesa
{
   int numero;
   int capacidad;
   NodoReservacion *reservaciones;
} Mesa;

typedef struct NodoMesa
{
   Mesa *mesa;
   struct NodoMesa *siguiente;
} NodoMesa;

typedef struct Restaurante
{
   int mesaCapacidadMaxima;
   NodoMesa *mesas;
   NodoReservacion *reservacionesCanceladas;
} Restaurante;
