#include "../Constructores.h"
#include "DatosPrueba.h"

Restaurante *obtenerDatos()
{
	Restaurante *restaurante = crearRestaurante();
	Cliente cliente = { "Axol", "Rio Jamapa", 2211509121 };

	Mesa *mesa1 = crearMesa(1, 4);

	Horario intervalo1_1 =  { { 2018, 8, 12 }, { { 9, 30 }, { 10, 0 } }	};
	agregarReservacion(mesa1, crearReservacion(cliente, intervalo1_1));

	Horario intervalo1_2 =  { { 2018, 8, 13 }, { { 10, 0 }, { 12, 0 } }	};
	agregarReservacion(mesa1, crearReservacion(cliente, intervalo1_2));

	Horario intervalo1_3 =  { { 2018, 8, 13 }, { { 15, 0 }, { 16, 0 } }	};
	agregarReservacion(mesa1, crearReservacion(cliente, intervalo1_3));

	Horario intervalo1_4 =  { { 2018, 8, 13 }, { { 13, 0 }, { 14, 0 } }	};
	agregarReservacion(mesa1, crearReservacion(cliente, intervalo1_4));

	Horario intervalo1_5 =  { { 2018, 8, 14 }, { { 8, 0 }, { 9, 0 } }	};
	agregarReservacion(mesa1, crearReservacion(cliente, intervalo1_5));

	agregarMesa(restaurante, mesa1);


	Mesa *mesa2 = crearMesa(2, 6);

	Horario intervalo2_1 =  { { 2018, 8, 11 }, { { 8, 0 }, { 9, 30 } }	};
	agregarReservacion(mesa2, crearReservacion(cliente, intervalo2_1));

	Horario intervalo2_2 =  { { 2018, 8, 11 }, { { 16, 0 }, { 18, 30 } }	};
	agregarReservacion(mesa2, crearReservacion(cliente, intervalo2_2));

	agregarMesa(restaurante, mesa2);


	Mesa *mesa3 = crearMesa(3, 10);

	Horario intervalo3_1 =  { { 2018, 8, 12 }, { { 13, 0 }, { 15, 0 } }	};
	agregarReservacion(mesa3, crearReservacion(cliente, intervalo3_1));

	agregarMesa(restaurante, mesa3);

	return restaurante;
}
