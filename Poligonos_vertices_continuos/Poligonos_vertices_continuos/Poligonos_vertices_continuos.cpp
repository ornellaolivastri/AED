#include <math.h>
#include "Poligonos_vertices_continuos.h"

// Definiciones de funciones del tipo color ---------------------------

tipo_color mezcla(tipo_color color1, tipo_color color2) {
	tipo_color color_nuevo;
	color_nuevo.intensidadRed = (color1.intensidadRed + color2.intensidadRed) / 2;
	color_nuevo.intensidadGreen = (color1.intensidadGreen + color2.intensidadGreen) / 2;
	color_nuevo.intensidadBlue = (color1.intensidadBlue + color2.intensidadBlue) / 2;

	return color_nuevo;
}

tipo_color suma_colores(tipo_color color1, tipo_color color2) {
	tipo_color z;
	z.intensidadRed = color1.intensidadRed + color2.intensidadRed > 255 ? 255 : color1.intensidadRed + color2.intensidadRed;
	z.intensidadGreen = color1.intensidadGreen + color2.intensidadGreen > 255 ? 255 : color1.intensidadGreen + color2.intensidadGreen;
	z.intensidadBlue = color1.intensidadBlue + color2.intensidadBlue > 255 ? 255 : color1.intensidadBlue + color2.intensidadBlue;

	return z;
}

tipo_color resta_colores(tipo_color color1, tipo_color color2) {
	tipo_color z;
	z.intensidadRed = color1.intensidadRed - color2.intensidadRed < 0 ? 0 : color1.intensidadRed - color2.intensidadRed;
	z.intensidadGreen = color1.intensidadGreen - color2.intensidadGreen < 0 ? 0 : color1.intensidadGreen - color2.intensidadGreen;
	z.intensidadBlue = color1.intensidadBlue - color2.intensidadBlue < 0 ? 0 : color1.intensidadBlue - color2.intensidadBlue;

	return z;
}

bool IsIgual(tipo_color color1, tipo_color color2) {
	return (color1.intensidadRed == color2.intensidadRed) and
		(color1.intensidadGreen == color2.intensidadGreen) and
		(color1.intensidadBlue == color2.intensidadBlue);
}


//  Definiciones de funciones para tipo vertice -----------------------------------------------

tipo_vertice origen{ 0.0, 0.0 };  //esta variable la puse aca porque sino me sale repetida

bool IsIgual(tipo_vertice a, tipo_vertice b) {
	return (a.x == b.x) and (a.y == b.y);
}

double getDistancia(tipo_vertice a, tipo_vertice b) {
	tipo_vertice distancia;
	distancia.x = a.x > b.x ? a.x - b.x : b.x - a.x;
	distancia.y = a.y > b.y ? a.y - b.y : b.y - a.y;
	return pow(pow(distancia.x, 2) + pow(distancia.y, 2), 0.5);
}

double getDistanciaAlOrigen(tipo_vertice a, tipo_vertice origen) {
	tipo_vertice distancia;
	distancia.x = a.x - 0;
	distancia.y = a.y - 0;
	return pow(pow(distancia.x, 2) + pow(distancia.y, 2), 0.5);
}


// Funcion que compara doubles ----------------------------------

bool AreNear(double a, double b, double tolerancia) {
	return a >= b ? (a - b) <= tolerancia
		: (b - a) <= tolerancia;
}


// Definiciones de funciones de los tipos Poligono -----------------------------------------------------------

void set_vertex(poligono_con_indice& poligono, unsigned vertice, double x, double y) {
	poligono.vertices.at(vertice).x = x;
	poligono.vertices.at(vertice).y = y;
}

tipo_vertice get_vertex(poligono_con_indice poligono, unsigned verticeX) {
	return poligono.vertices.at(verticeX);
}

void remove_end_vertex(poligono_con_indice& poligono) {
	poligono.cantidad_de_vertices = poligono.cantidad_de_vertices - 1;
}

void add_vertex_at_end(poligono_con_indice& poligono, double nuevo_valor_x, double nuevo_valor_y) {
	poligono.cantidad_de_vertices = poligono.cantidad_de_vertices + 1;
	poligono.vertices.at(poligono.cantidad_de_vertices).x = nuevo_valor_x;
	poligono.vertices.at(poligono.cantidad_de_vertices).y = nuevo_valor_y;
}

poligono_con_indice suma_de_poligonos(poligono_con_indice poligono1, poligono_con_indice poligono2) {

	poligono_con_indice poligono_nuevo;

	poligono_con_indice poligono_de_indice_mayor = poligono1.cantidad_de_vertices >= poligono2.cantidad_de_vertices ?
		poligono1 : poligono2;

	unsigned mayor_indice = poligono1.cantidad_de_vertices >= poligono2.cantidad_de_vertices ?
		poligono1.cantidad_de_vertices : poligono2.cantidad_de_vertices;

	poligono_nuevo.cantidad_de_vertices = mayor_indice;

	unsigned menor_indice = poligono1.cantidad_de_vertices <= poligono2.cantidad_de_vertices ?
		poligono1.cantidad_de_vertices : poligono2.cantidad_de_vertices;

	for (int i = 0; i < menor_indice; i = i + 1) {
		poligono_nuevo.vertices.at(i).x = poligono1.vertices.at(i).x + poligono2.vertices.at(i).x;
		poligono_nuevo.vertices.at(i).y = poligono1.vertices.at(i).y + poligono2.vertices.at(i).y;
	}

	for (int i = menor_indice; i < mayor_indice; i = i + 1) {
		poligono_nuevo.vertices.at(i).x = poligono_de_indice_mayor.vertices.at(i).x;
		poligono_nuevo.vertices.at(i).x = poligono_de_indice_mayor.vertices.at(i).x;
	}
	poligono_nuevo.color = mezcla(poligono1.color, poligono2.color);

	return poligono_nuevo;

}

unsigned get_cantidad_de_lados(poligono_con_indice poligono) {
	return poligono.cantidad_de_vertices;
}

double get_perimetro(poligono_con_indice poligono) {
	double distancia = 0.0;
	for (unsigned i = 0; i < poligono.cantidad_de_vertices; i++) {
		distancia = distancia + getDistancia(poligono.vertices.at(i), poligono.vertices.at(i + 1));
	}

	distancia = distancia + getDistancia(poligono.vertices.at(poligono.cantidad_de_vertices), poligono.vertices.at(0));

	return distancia;
}
