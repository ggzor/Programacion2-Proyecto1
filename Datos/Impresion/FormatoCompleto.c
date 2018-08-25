#include "../Impresion.h"
#include "../Color.h"
#include "../Tiempo/Tiempo.h"

void imprimirCliente(Cliente *cliente)
{
  printf("Nombre: %s\n", cliente->nombre);
  printf("Telefono: %lld\n", cliente->telefono);
  printf("Dirección %s\n", cliente->direccion);
}

void imprimirFecha(Fecha *fecha)
{
  enMorado(printf("%02d/%02d/%04d", fecha->dia, fecha->mes, fecha->anio));
}

void imprimirIntervaloFechas(const char *mensaje, IntervaloFechas *intervalo)
{
  imprimirCadena(mensaje);
  imprimirFecha(&intervalo->inicio);
  printf(" - ");
  imprimirFecha(&intervalo->fin);
  puts("");
}

void imprimirHora(Hora *hora)
{
  enAzul(printf("%02d:%02d", hora->hora, hora->minuto));
}

void imprimirIntervaloHoras(const char *mensaje, IntervaloHoras *intervalo)
{
  imprimirCadena(mensaje);
  imprimirHora(&intervalo->inicio);
  printf(" - ");
  imprimirHora(&intervalo->fin);
}

void imprimirFechaHora(FechaHora *fechaHora)
{
  imprimirFecha(&fechaHora->fecha);
  putchar(' ');
  imprimirHora(&fechaHora->hora);
}

void imprimirHorario(Horario *horario)
{
  printf("Fecha: ");
  imprimirFecha(&horario->fecha);
  puts("");

  printf("Hora de inicio: ");
  imprimirHora(&horario->horas.inicio);
  puts("");

  printf("Hora de fin: ");
  imprimirHora(&horario->horas.fin);
  puts("");
}

void imprimirClaveReservacion(int clave)
{
  enVerde(printf("%04X", clave));
}

void imprimirReservacion(Reservacion *reservacion)
{
  printf("Clave de reservación: ");
  imprimirClaveReservacion(reservacion->clave);
  puts("\n");
  printf("Cantidad de personas: %d\n", reservacion->cantidadPersonas);
  imprimirCliente(&reservacion->cliente);
  printf("Confirmada: ");
  if (reservacion->confirmada)
  {
    enVerde(printf("✔"));
  }
  else
  {
    enAmarillo(printf("No."));
  }
  puts("\n");

  imprimirHorario(&reservacion->horario);
  puts("");
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
      puts("");

      actual = actual->siguiente;
    }
  }
}

void imprimirMesa(Mesa *mesa)
{
  printf("Numero de mesa %d \n", mesa->numero);
  printf("Capacidad de la mesa: %d\n\n", mesa->capacidad);

  puts("Lista reservaciones:");
  imprimirListaReservaciones(mesa->reservaciones);
  puts("\n");

  enRojo(puts("Lista reservaciones canceladas:"));
  imprimirListaReservaciones(mesa->reservacionesCanceladas);
  puts("\n");
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
      puts("= = = = = = = = = = = = = = = =");
      imprimirMesa(actual->mesa);
      puts("");
      actual = actual->siguiente;
    }
  }
}

void imprimirRestaurante(Restaurante *restaurante)
{
  imprimirListaMesas(restaurante->mesas);
}

void imprimirFechaHoraActual()
{
  FechaHora ahora = obtenerAhora();
  imprimirCadena("Fecha y hora: ");
  imprimirFechaHora(&ahora);
  puts("\n");
}

void imprimirEncabezado()
{
  enVerde(puts("Fonda Doña Yoyis"));
  imprimirFechaHoraActual();
}