import re
import yaml
from collections import namedtuple
from datetime import datetime
from itertools import count

entrada = 'DatosPrueba.yaml'
datos = None
with open(entrada) as archivo:
  datos = yaml.load(archivo)

Hora = namedtuple('Hora', ['hora', 'minuto'])
Intervalo = namedtuple('Intervalo', ['fecha', 'inicio', 'fin'])
Mesa = namedtuple('Mesa', ['capacidad', 'reservaciones'])
Restaurante = namedtuple('Restaurante', ['mesas'])

def extraerHora(hora):
  h, m = hora.split(':')
  return Hora(int(h), int(m))

def extraerIntervaloHoras(intervalo):
  return list(map(extraerHora, intervalo.split(' ')))

def extraerReservaciones(reservaciones):
  fecha = list(reservaciones.keys())[0]
  intervalos = list(map(extraerIntervaloHoras, reservaciones[fecha]))

  return [Intervalo(fecha, inicio, fin) for inicio, fin in intervalos]

patronMesa = re.compile(r"Mesa (\d+)")
def extraerMesa(mesa):
  clave = list(mesa.keys())[0]
  capacidad = int(patronMesa.match(clave)[1])

  return Mesa(capacidad, [r for g in list(map(extraerReservaciones, mesa[clave])) for r in g])

def extraerRestaurante(restaurante):
  mesas = restaurante['Restaurante']
  return Restaurante(list(map(extraerMesa, mesas)))

restaurantes = list(map(extraerRestaurante, datos))

salida = "../Datos/Pruebas/ValoresPrueba.c"
funcion = "obtenerDatosPrueba"

restaurante = restaurantes[0]
with open(salida, 'w') as a:
  w = a.write

  w('#include "../Constructores.h"\n')
  w('#include "../Estructuras.h"\n')
  w('#include "../Pruebas.h"\n\n')

  w('Restaurante *{}()\n{{\n'.format(funcion))

  w('\tRestaurante *restaurante = crearRestaurante();\n')
  w('\tCliente cliente = { "Axol", "Rio Jamapa", 2211509121 };')

  for numeroMesa, mesa in zip(count(1), restaurante.mesas):
    nombreMesa = 'mesa{}'.format(numeroMesa)
    w('\n\n\tMesa *{} = crearMesa({}, {});\n'.format(nombreMesa, numeroMesa, mesa.capacidad))
    for numeroIntervalo, intervalo in zip(count(1), mesa.reservaciones):
      nombreIntervalo = 'intervalo{}_{}'.format(numeroMesa, numeroIntervalo)
      w('\n\tHorario {} =  {{ {{ {}, {}, {} }}, {{ {{ {}, {} }}, {{ {}, {} }} }}'.format(
        nombreIntervalo,
        intervalo.fecha.year, intervalo.fecha.month, intervalo.fecha.day,
        intervalo.inicio.hora, intervalo.inicio.minuto, intervalo.fin.hora, intervalo.fin.minuto)
      )
      w('\t};\n')
      w('\tagregarReservacion({}, crearReservacion({}, cliente, {}));\n'.format(nombreMesa, mesa.capacidad, nombreIntervalo))
    w('\n\tagregarMesa(restaurante, {});\n'.format(nombreMesa))

  w('\n\treturn restaurante;\n')
  w('}\n')