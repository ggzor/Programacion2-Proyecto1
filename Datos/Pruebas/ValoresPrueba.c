#include "../Constructores.h"
#include "../Estructuras.h"
#include "../Pruebas.h"

Restaurante *obtenerDatosPrueba()
{
	Restaurante *restaurante = crearRestaurante();
	Cliente cliente = { "Axol", "Rio Jamapa", 2211509121 };

	Mesa *mesa1 = crearMesa(1, 4);

	Horario intervalo1_1 =  { { 2018, 8, 29 }, { { 9, 30 }, { 10, 0 } }	};
	agregarReservacion(mesa1, crearReservacion(4, cliente, intervalo1_1));

	Horario intervalo1_2 =  { { 2018, 8, 30 }, { { 15, 0 }, { 16, 0 } }	};
	agregarReservacion(mesa1, crearReservacion(4, cliente, intervalo1_2));

	Horario intervalo1_3 =  { { 2018, 8, 30 }, { { 10, 0 }, { 12, 0 } }	};
	agregarReservacion(mesa1, crearReservacion(4, cliente, intervalo1_3));

	Horario intervalo1_4 =  { { 2018, 8, 30 }, { { 13, 0 }, { 14, 0 } }	};
	agregarReservacion(mesa1, crearReservacion(4, cliente, intervalo1_4));

	Horario intervalo1_5 =  { { 2018, 8, 30 }, { { 9, 0 }, { 10, 0 } }	};
	agregarReservacion(mesa1, crearReservacion(4, cliente, intervalo1_5));

	agregarMesa(restaurante, mesa1);


	Mesa *mesa2 = crearMesa(2, 6);

	Horario intervalo2_1 =  { { 2018, 8, 30 }, { { 9, 0 }, { 9, 30 } }	};
	agregarReservacion(mesa2, crearReservacion(6, cliente, intervalo2_1));

	Horario intervalo2_2 =  { { 2018, 8, 30 }, { { 16, 0 }, { 18, 30 } }	};
	agregarReservacion(mesa2, crearReservacion(6, cliente, intervalo2_2));

	agregarMesa(restaurante, mesa2);


	Mesa *mesa3 = crearMesa(3, 10);

	Horario intervalo3_1 =  { { 2018, 8, 30 }, { { 13, 0 }, { 15, 0 } }	};
	agregarReservacion(mesa3, crearReservacion(10, cliente, intervalo3_1));

	agregarMesa(restaurante, mesa3);

	return restaurante;
}
