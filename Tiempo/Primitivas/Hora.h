#ifndef _HORA_H_
#define _HORA_H_

typedef struct {
  int hora;
  int minuto;
} Hora;

int esHoraValida(Hora *hora);

int compararHoras(Hora *hora1, Hora *hora2);
Hora *obtenerHoraMayor(Hora *hora1, Hora *hora2);

int obtenerDiferenciaEnMinutosEntreHoras(Hora *hora1, Hora *hora2);

#endif