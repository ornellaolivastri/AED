#pragma once
#include <iostream> // lo necesito para el tipo uint8_t
#include<array>

/* El tipo de dato uint8_t sirve para las intensidades, ya que representa un numero natural
   que solo puede almacenar numeros de 0 a 255 (o sea, lo que se pueda representar con 8 bits) */

   // Tipo de dato color y algunos colores ----------------------------------------------------

struct tipo_color { uint8_t intensidadRed, intensidadGreen, intensidadBlue; };

const tipo_color red{ 255,0,0 };
const tipo_color green{ 0,255,0 };
const tipo_color blue{ 0,0,255 };

const tipo_color cyan{ 0,255,255 };
const tipo_color magenta{ 255,0,255 };
const tipo_color yellow{ 255,255,0 };

const tipo_color white{ 255,255,255 };
const tipo_color black{ 0,0,0 };


// Prototipos 

tipo_color mezcla(tipo_color color1, tipo_color color2);

tipo_color suma_colores(tipo_color color1, tipo_color color2);

tipo_color resta_colores(tipo_color color1, tipo_color color2);

bool IsIgual(tipo_color color1, tipo_color color2);


// Tipo vértice: cada vértice estará formado por dos coordenadas double: x e y   ----------------------------------------------------


struct tipo_vertice { double x, y; };


// Prototipos 

bool IsIgual(tipo_vertice a, tipo_vertice b);

double getDistancia(tipo_vertice a, tipo_vertice b);

double getDistanciaAlOrigen(tipo_vertice a, tipo_vertice origen);

bool AreNear(double a, double b, double tolerancia);



// Tipo Poligono ---------------------------------------------------------------------------------------------------------

unsigned const MAXIMA_CANTIDAD_DE_VERTICES = 5;


/* Tipo poligono sin índice: cada uno tendrá espacio para 5 vértices    --------------------
   Cada uno de esos vértices serán llamados según su posición 0,1,2,3,4    ----------------- */

using poligono_sin_indice = std::array <tipo_vertice, MAXIMA_CANTIDAD_DE_VERTICES>;


/* Poligonos con Índice: son polígonos formados por 3 componentes con diferentes funciones:
- un poligono sin índice que tiene 5 espacios para guardar información sobre 5 vértices
- un natural que indica la cantidad de vertices con información relevante que posee el poligono
- un color: de tipo color, basado en el modelo RGB con rango [0,255] y 3 canales de 8 bits */

struct poligono_con_indice {
	//poligono_sin_indice vertices{ {0,0},{0,0},{0,0},{0,0},{0,0} };  no funciona
	poligono_sin_indice vertices;
	unsigned cantidad_de_vertices;
	tipo_color color;
};


// Prototipos / Firmas / Operaciones sobre el tipo de dato poligono_con_indice  ------------------

void set_vertex(poligono_con_indice& poligono, unsigned vertice, double x, double y);

tipo_vertice get_vertex(poligono_con_indice poligono, unsigned verticeX);

void remove_end_vertex(poligono_con_indice& poligono);

void add_vertex_at_end(poligono_con_indice& poligono, double x, double y);

poligono_con_indice suma_de_poligonos(poligono_con_indice poligono1, poligono_con_indice poligono2);

unsigned get_cantidad_de_lados(poligono_con_indice poligono);

double get_perimetro(poligono_con_indice);