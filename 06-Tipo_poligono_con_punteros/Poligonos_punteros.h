#pragma once
#include <iostream> //incluye el tipo uint8_t (y otras cosas)
#include <string>

/* Definicion del tipo color y variables globales -------------------------------------- */
// Definicion del tipo color y variables globales --------------------------------------

struct Color { uint8_t intensidadRed, intensidadGreen, intensidadBlue; };

const Color red{ 255,0,0 };
const Color green{ 0,255,0 };
const Color blue{ 0,0,255 };

const Color cyan{ 0,255,255 };
const Color magenta{ 255,0,255 };
const Color yellow{ 255,255,0 };

const Color white{ 255,255,255 };
const Color black{ 0,0,0 };


// Prototipos del tipo color 

Color mixture(Color color1, Color color2);

Color color_sum(Color color1, Color color2);

Color color_subtraction(Color color1, Color color2);

bool IsIgual(Color color1, Color color2);

void show_color(Color color_random);

std::string get_color_for_svn(Color color_random);


// Definicion del tipo coordinates: ---------------------------------------------------
// cada punto estará formado por dos coordenadas doubles (x e y) ----------------------

struct coordinate { double x, y; };


// Prototipos del tipo coordinates: 

bool IsIgual(coordinate a, coordinate b);

double getDistancia(coordinate a, coordinate b);

double getDistanciaAlOrigen(coordinate a, coordinate origen);

bool AreNear(double a, double b, double tolerancia);


//Definicion del tipo vertice (de poligonos con punteros) --------------------------------------

struct Vertex {
    Vertex* next_vertex_pointer = nullptr;
    coordinate vertex_coordinates{ 0,0 };
};



//Definicion del tipo poligono (con punteros) --------------------------------------

struct Polygon {
    Vertex* root_vertex_pointer = nullptr;
    unsigned vertex_amount = 0;
    Color color = white;                               // Initialize white by default
    Polygon* next_polygon_pointer = nullptr;
};


//Prototipos del tipo poligono (con punteros) 

void change_polygon_color(Polygon& poligono_random, Color color_a_agregar);

void cambiar_datos_vertice(Polygon& poligono_random, unsigned numero_del_vertice_a_modificar, double x, double y);

Vertex* get_vertice(Polygon& poligono_random, unsigned numero_del_vertice_a_devolver);

void show_poligono(Polygon& poligono_random);

void show_vertice(Polygon& poligono_random, unsigned numero_del_vertice_a_imprimir);

std::string show_vertice_para_svg(Polygon& poligono_random);

double getPerimetro(Polygon& poligono_random);

void remove_vertice(Polygon& poligono_random, unsigned numero_del_vertice_a_eliminar);

void add_vertice_al_final(Polygon& poligono_random, double x, double y);


//Definicion del tipo lista de poligonos (con punteros) --------------------------------------

struct PolygonsList {
    Polygon* puntero_a_poligono_raiz = nullptr;
    unsigned cantidad_poligonos = 0;
};


//Prototipos del tipo lista de poligonos (con punteros) 

void add_poligono_al_final(PolygonsList& lista_random, Polygon& poligono_a_agregar);



//void inicializacion_de_PolygonList(PolygonsList& RandomPolygonList, Color color_random);

void show_polygons_list(PolygonsList& RandomPolygonList);

Polygon* get_polygon(PolygonsList& RandomPolygonList, unsigned numero_del_poligono_a_devolver);





//Prototipos/funciones para extraer datos ----------------------------------------------------

void get_polygons_color_from_stream(std::istream& istr, Color& color);

unsigned get_polygons_amount_from_stream(std::istream& istr);

void get_vertex_from_stream(std::istream& istr, Polygon* poligono_random);

bool get_separator_from_stream(std::istream& istr);

void get_polygon_from_stream(std::istream& istr, PolygonsList& lista_random);



//Prototipos/funciones para introducir datos --------------------------------------------------


void give_polygons_color(std::ofstream& ostr, Color& color);

void give_polygons_amount(std::ofstream& ostr, unsigned& vertex_amount);

void give_vertex(std::ofstream& ostr, Vertex& vertex);

void give_polygon(std::ofstream& ostr, Polygon& polygon);



