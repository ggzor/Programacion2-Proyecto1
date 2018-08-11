typedef struct Cliente
{
   char nombre[50];
   char direccion[100];
   long long telefono;
} Cliente;

typedef struct Fecha
{
   int dia;
   int mes;
   int anio;
} Fecha;

typedef struct Hora
{
   int segundo;
   int minuto;
   int hora;
} Hora;

typedef struct Intervalo
{
   Fecha fecha;
   Hora inicio;
   Hora fin;
} Intervalo;

typedef struct Reservacion
{
   Intervalo intervalo;
   Cliente cliente;
} Reservacion;

typedef struct NodoReservacion
{
   Reservacion *reservacion;
   struct NodoReservacion *siguiente;
} NodoReservacion;

typedef struct Mesa
{
   int numero;
   int maximoPersonas;
   NodoReservacion *reservaciones;
} Mesa;

typedef struct NodoMesa
{
   Mesa *mesa;
   struct NodoMesa *siguiente;
} NodoMesa;

typedef struct Restaurante
{
   NodoMesa *mesas;
   NodoReservacion *reservacion;
} Restaurante;
