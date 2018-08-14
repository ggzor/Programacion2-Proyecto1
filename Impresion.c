#include <stdio.h>

#include "Impresion.h"
#include "Interfaz.h"

//TE AMO beio Axel come pan. :p :D
void imprimirCeros(int a)
{
  if (a < 10)
  {
    printf("0");
  }
}

void imprimirCliente(Cliente *cliente)
{
  printf("Nombre: %s\n", cliente->nombre);
  printf("Dirección: %s\n", cliente->direccion);
  printf("Telefono: %lld\n", cliente->telefono);
}

void imprimirFecha(Fecha *fecha)
{
  imprimirCeros(fecha->dia);
  printf("%d/", fecha->dia);
  imprimirCeros(fecha->mes);
  printf("%d/", fecha->mes);
  printf("%4d", fecha->anio);
}

void imprimirHora(Hora *hora)
{
  imprimirCeros(hora->hora);
  printf("%d:", hora->hora);
  imprimirCeros(hora->minuto);
  printf("%d", hora->minuto);
}

void imprimirIntervalo(Intervalo *intervalo)
{
  printf("Fecha: ");
  imprimirFecha(&intervalo->fecha);
  printf("\nHora de inicio: ");
  imprimirHora(&intervalo->inicio);
  printf("\nHora de fin: ");
  imprimirHora(&intervalo->fin);
  puts("");
}

void imprimirReservacion(Reservacion *reservacion)
{
  printf("\nDatos del cliente: \n");
  imprimirCliente(&reservacion->cliente);
  imprimirIntervalo(&reservacion->intervalo);
}

void imprimirListaReservaciones(NodoReservacion *lista)
{
  NodoReservacion *actual;
  actual = lista;
  if (actual == NULL)
  {
    printf("La lista está vacía\n");
  }
  else
  {
    while (actual != NULL)
    {
      imprimirReservacion(actual->reservacion);
      actual = actual->siguiente;
    }
  }
}

void imprimirMesa(Mesa *mesa)
{
  printf("♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ \n");
  printf("Numero de mesa %d \n", mesa->numero);
  printf("Capacidad de la mesa: %d\n", mesa->capacidad);
  printf("\nLista reservaciones:\n");
  imprimirListaReservaciones(mesa->reservaciones);
  printf("\nLista reservaciones canceladas:\n");
  imprimirListaReservaciones(mesa->reservacionesCanceladas);
  printf("\n\n");
}

void imprimirListaMesas(NodoMesa *lista)
{
  NodoMesa *actual;
  actual = lista;
  if (actual == NULL)
  {
    printf("La lista está vacía\n");
  }
  else
  {
    while (actual != NULL)
    {
      imprimirMesa(actual->mesa);
      actual = actual->siguiente;
    }
  }
}

void imprimirRestaurante(Restaurante *restaurante)
{
  imprimirListaMesas(restaurante->mesas);
}

void imprimirHoraformatocorto(Hora hora)
{
  imprimirCeros(hora.hora);
  printf("%d:", hora.hora);
  imprimirCeros(hora.minuto);
  printf("%d ", hora.minuto);
}

void imprimirMesaformatocorto(Intervalo intervalo)
{
  imprimirHoraformatocorto(intervalo.inicio);
  imprimirHoraformatocorto(intervalo.fin);
}

int sonFechasiguales(Fecha fecha1, Fecha fecha2)
{
}

void verificarFecha(Reservacion *reservacion)
{
  int anio1 = 0, mes1 = 0, dia1 = 0, anio2, mes2, dia2;
  anio2 = reservacion->intervalo.fecha.anio;
  mes2 = reservacion->intervalo.fecha.mes;
  dia2 = reservacion->intervalo.fecha.dia;

  if ((anio1 != anio2) && (mes1 != mes2) && (dia1 != dia2))
  {
    anio1 = anio2;
    mes1 = mes2;
    dia1 = dia2;
    imprimirFecha(&reservacion->intervalo.fecha);
    imprimirMesaformatocorto(reservacion->intervalo);
    printf("\n");
  }
  else
  {
    imprimirMesaformatocorto(reservacion->intervalo);
  }
}

void imprimirListaReservaciones2(NodoReservacion *lista)
{
  NodoReservacion *actual;
  actual = lista;
  if (actual == NULL)
  {
    printf("La lista está vacía\n");
  }
  else
  {
    while (actual != NULL)
    {
      verificarFecha(actual->reservacion);
      actual = actual->siguiente;
    }
  }
}

void imprimirMesa2(Mesa *mesa)
{
  printf("\nNumero de mesa %d ", mesa->numero);
  printf("\nLista reservaciones:\n");
  imprimirListaReservaciones2(mesa->reservaciones);
}

void imprimirListaMesas2(NodoMesa *lista)
{
  NodoMesa *actual;
  actual = lista;
  if (actual == NULL)
  {
    printf("La lista está vacía\n");
  }
  else
  {
    while (actual != NULL)
    {
      imprimirMesa2(actual->mesa);
      actual = actual->siguiente;
    }
  }
}

void imprimirHorarios(Restaurante *restaurante)
{
  imprimirListaMesas2(restaurante->mesas);
}

void imprimirIntervaloHoras(const char *mensaje, Hora *inicio, Hora *fin)
{
  imprimirCadena(mensaje);
  imprimirHora(inicio);
  printf(" - ");
  imprimirHora(fin);
  puts("");
}

void imprimirIntervaloFechas(const char *mensaje, Fecha *inicio, Fecha *fin)
{
  imprimirCadena(mensaje);
  imprimirFecha(inicio);
  printf(" - ");
  imprimirFecha(fin);
  puts("");
}