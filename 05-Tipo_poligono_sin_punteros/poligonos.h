#pragma once       
#include<array>
#include"color.h"
#include"vertices.h"


unsigned const MAXIMA_CANTIDAD_DE_VERTICES = 5;


/* Tipo poligono sin �ndice: cada uno tendr� espacio para 5 v�rtices    --------------------
   Cada uno de esos v�rtices ser�n llamados seg�n su posici�n 0,1,2,3,4    ----------------- */

using poligono_sin_indice = std::array <tipo_vertice, MAXIMA_CANTIDAD_DE_VERTICES>;


/* Poligonos con �ndice: son pol�gonos formados por 3 componentes con diferentes funciones: 
- un poligono sin �ndice que tiene 5 espacios para guardar informaci�n sobre 5 v�rtices
- un natural que indica la cantidad de vertices con informaci�n relevante que posee el poligono
- un color: de tipo color, basado en el modelo RGB con rango [0,255] y 3 canales de 8 bits */

struct poligono_con_indice { poligono_sin_indice vertices; unsigned cantidad_de_vertices; tipo_color color; };


// Prototipos / Firmas / Operaciones sobre el tipo de dato poligono_con_indice  ------------------

void set_vertex(poligono_con_indice& poligono, unsigned vertice, double x, double y);

tipo_vertice get_vertex(poligono_con_indice poligono, unsigned verticeX);

void remove_end_vertex(poligono_con_indice& poligono);

void add_vertex_at_end(poligono_con_indice& poligono, double x, double y);

poligono_con_indice suma_de_poligonos(poligono_con_indice poligono1, poligono_con_indice poligono2);

unsigned get_cantidad_de_lados(poligono_con_indice poligono);

double get_perimetro(poligono_con_indice);