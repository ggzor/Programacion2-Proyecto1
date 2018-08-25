#include "../Constructores.h"

Restaurante *crearRestaurante()
{
   Restaurante *restaurante = (Restaurante *)malloc(sizeof(Restaurante));

   restaurante->mesas = NULL;

   return restaurante;
}

void agregarMesa(Restaurante *restaurante, Mesa *mesa)
{
   NodoMesa *nuevoNodo = crearNodoMesa(mesa);
   NodoMesa *actual = restaurante->mesas;

   if (restaurante->mesas == NULL)
   {
      restaurante->mesas = nuevoNodo;
   }
   else
   {
      while (actual->siguiente != NULL)
      {
         actual = actual->siguiente;
      }

      actual->siguiente = nuevoNodo;
   }
}
