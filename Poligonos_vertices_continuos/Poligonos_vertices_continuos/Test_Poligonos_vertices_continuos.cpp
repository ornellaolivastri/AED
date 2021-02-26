// Poligonos_estructuras_continuas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<cassert>
#include "Poligonos_vertices_continuos.h"

int main() {

	tipo_vertice vertice0{ 1.1,2.2 }, vertice1{ 3.3,4.4 }, vertice2{ 5.5,6.6 },
		vertice3{ 7.7,8.8 }, vertice4{ 9.9,10.1 };

	poligono_sin_indice poligono1_sin_indice{ vertice0,vertice1,vertice2,vertice3,vertice4 };
	poligono_sin_indice poligono2_sin_indice{ vertice1,vertice3,vertice2,vertice4,vertice0 };

	poligono_con_indice poligono1_con_indice{ poligono1_sin_indice, 3, red };
	poligono_con_indice poligono2_con_indice{ poligono2_sin_indice, 4, green };

	set_vertex(poligono1_con_indice, 3, 1.2, 1.3);
	assert(poligono1_con_indice.vertices.at(3).x == 1.2);

	assert(get_vertex(poligono1_con_indice, 2).x == 5.5);

	remove_end_vertex(poligono1_con_indice);
	assert(poligono1_con_indice.cantidad_de_vertices == 2);

	add_vertex_at_end(poligono1_con_indice, 2.3, 3.4);
	assert(poligono1_con_indice.vertices.at(3).x == 2.3);

	poligono_con_indice poligono3 = suma_de_poligonos(poligono1_con_indice, poligono2_con_indice);
	assert(poligono3.cantidad_de_vertices == 4);
	assert(poligono3.vertices.at(2).x == 11);
	assert(poligono3.color.intensidadGreen == 127);
	assert(poligono3.color.intensidadRed == 127);
	assert(poligono3.color.intensidadBlue == 0);

	assert(get_cantidad_de_lados(poligono2_con_indice) == 4);

	assert(AreNear(get_perimetro(poligono2_con_indice), 29.8931756, 0.0001));

	assert(AreNear(get_perimetro(poligono1_con_indice), 12.445075, 0.0001));

	std::cout << "Todo salio bien con los poligonos de vertices continuos:3 " << std::endl;
}