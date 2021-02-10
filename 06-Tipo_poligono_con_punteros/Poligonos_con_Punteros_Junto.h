#pragma once
#include <iostream> //lo necesito para el tipo uint8_t (y otras cosas)
#include <string>

/* El tipo de dato uint8_t sirve para las intensidades, ya que representa un numero natural
   que solo puede almacenar numeros de 0 a 255 (o sea, lo que se pueda representar con 8 bits) */

struct Color { uint8_t intensidadRed, intensidadGreen, intensidadBlue; };

const Color red{ 255,0,0 };
const Color green{ 0,255,0 };
const Color blue{ 0,0,255 };

const Color cyan{ 0,255,255 };
const Color magenta{ 255,0,255 };
const Color yellow{ 255,255,0 };

const Color white{ 255,255,255 };
const Color black{ 0,0,0 };


// Prototipos ----------------------------------------------------

Color mezcla(Color color1, Color color2);

Color suma_colores(Color color1, Color color2);

Color resta_colores(Color color1, Color color2);

bool IsIgual(Color color1, Color color2);

void show_color(Color color_random);

std::string get_color_for_svn(Color color_random);



// Tipo coordinates: cada punto estará formado por dos coordenadas double: x e y   ------------

struct coordinate { double x, y; };

// revisar el tipo de x e y para svg

// Prototipos ----------------------------------------------------

bool IsIgual(coordinate a, coordinate b);

double getDistancia(coordinate a, coordinate b);

double getDistanciaAlOrigen(coordinate a, coordinate origen);

bool AreNear(double a, double b, double tolerancia);


//Definicion del tipo vertice (de poligonos con punteros) --------------------------------------

struct Vertex {
    Vertex* next_vertex_pointer = nullptr;
    coordinate vertex_coordinates{0,0};
};


//Definicion del tipo poligono (con punteros) --------------------------------------

struct Polygon {
    Vertex* root_vertex_pointer = nullptr;
    unsigned vertex_amount = 0;
    Color color = white;                               // Initialize white by default
    Polygon* next_polygon_pointer = nullptr;
};


//Definicion del tipo lista de poligonos (con punteros) --------------------------------------

struct PolygonsList {
    Polygon* puntero_a_poligono_raiz = nullptr;
    unsigned cantidad_poligonos = 0;
};



//PROTOTIPOS DE FUNCIONES

//Del tipo poligono (con punteros)

void inicializacion_de_Poligono(Polygon& poligono_random, Color color_a_agregar);

void cambiar_datos_del_vertice(Polygon& poligono_random, unsigned numero_del_vertice, double x, double y);

Vertex* get_vertice(Polygon& poligono_random, unsigned numero_del_vertice_a_imprimir);

void show_poligono(Polygon& poligono_random);

void show_vertice(Polygon& poligono_random, unsigned numero_del_vertice_a_imprimir);

std::string show_vertice_para_svg(Polygon& poligono_random);

double getPerimetro(Polygon& poligono_random);

void remove_vertice(Polygon& poligono_random, unsigned numero_del_vertice_a_eliminar);

void add_vertice_al_final(Polygon& poligono_random, double x, double y);



//Del tipo lista de poligonos (con punteros) 

void add_poligono_al_final(PolygonsList& lista_random, Polygon& poligono_a_agregar);

void inicializacion_de_PolygonList(PolygonsList& RandomPolygonList, Color color_random);

void show_polygons_list(PolygonsList& RandomPolygonList);

Polygon* get_polygon(PolygonsList& RandomPolygonList, unsigned numero_del_poligono_a_devolver);







//Funciones para extraer ------------------------------------------------------

void get_polygons_color_from_stream(std::istream& istr, Color& color);

void get_polygons_amount_from_stream(std::istream& istr, unsigned& vertex_amount);

void get_vertex_from_stream(std::istream& istr, Vertex& vertex);

bool get_separator_from_stream(std::istream& istr);

bool get_polygon_from_stream(std::istream& istr, Polygon& polygon);



//Funciones para introducir --------------------------------------------------


void give_polygons_color(std::ofstream& ostr, Color& color);

void give_polygons_amount(std::ofstream& ostr, unsigned& vertex_amount);

void give_vertex(std::ofstream& ostr, Vertex& vertex);

void give_polygon(std::ofstream& ostr, Polygon& polygon);

