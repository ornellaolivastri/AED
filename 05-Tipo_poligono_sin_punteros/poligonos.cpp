//aca van las definiciones de operaciones/funciones
#pragma once
#include"poligonos.h"



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
		
	for (int i = 0; i < menor_indice ; i = i + 1) {
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
		distancia = distancia + getDistancia( poligono.vertices.at(i), poligono.vertices.at(i + 1) );
	}

	distancia = distancia + getDistancia(poligono.vertices.at(poligono.cantidad_de_vertices), poligono.vertices.at(0));

	return distancia;
}


