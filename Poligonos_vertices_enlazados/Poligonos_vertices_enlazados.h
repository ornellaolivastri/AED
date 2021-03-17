#pragma once
#include <iostream> //incluye el tipo uint8_t 
#include <string>



// Definicion del tipo color y variables globales --------------------------------------

struct Color { uint8_t red, green, blue; };

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

std::string get_color_for_SVG(Color color_random);




// Definicion del tipo coordinates: ---------------------------------------------------
// cada punto estará formado por dos coordenadas de tipo double (x e y) ---------------

struct Coordinate { double x, y; };

// Prototipos del tipo coordinates: 

bool IsIgual(Coordinate a, Coordinate b);

double getDistancia(Coordinate a, Coordinate b);

double getDistanciaAlOrigen(Coordinate a, Coordinate origen);

bool AreNear(double a, double b, double tolerancia);




//Definicion del tipo vertice (de poligonos con punteros) --------------------------------------

struct Vertex {
    Vertex* next_vertex_pointer = nullptr;
    Coordinate vertex_coordinates{ 0,0 };
};


//Definicion del tipo poligono (con punteros) --------------------------------------

struct Polygon {
    Vertex* root_vertex_pointer = nullptr;
    unsigned vertex_amount = 0;
    Color color = white;
   
};

//Prototipos del tipo poligono (con punteros) 

void change_polygon_color(Polygon& poligono_random, Color color_a_agregar);

void change_vertex_data(Polygon& poligono_random, unsigned numero_del_vertice_a_modificar, double x, double y);

Vertex* get_vertice(Polygon& poligono_random, unsigned numero_del_vertice_a_devolver);

void show_polygon(Polygon& poligono_random);

void show_vertex(Polygon& poligono_random, unsigned numero_del_vertice_a_imprimir);

std::string show_vertex_for_SVG(Polygon& poligono_random);

double getPerimetro(Polygon& poligono_random);

void remove_vertex(Polygon& poligono_random, unsigned numero_del_vertice_a_eliminar);

void add_end_vertex(Polygon& poligono_random, double x, double y);


//Definicion del tipo lista de poligonos (con punteros) --------------------------------------

struct PolygonNode {
    Polygon polygon;
    PolygonNode* next_node;
};

struct PolygonsList {
    PolygonNode* root_polygon_node_pointer = nullptr;
    unsigned polygons_amount = 0;
};


//Prototipos del tipo lista de poligonos (con punteros) 

void add_poligono_al_final(PolygonsList& lista_random, const Polygon& poligono_a_agregar);

void show_polygons_list(PolygonsList RandomPolygonList);

PolygonNode* get_polygon(PolygonsList& RandomPolygonList, unsigned numero_del_poligono_a_devolver);



// FLUJOS -----------------------------------------------------------------------------------


// Funciones necesarias para extraer poligonos desde un archivo ---------------------------------------------

Color get_polygons_color_from_file(std::istream& istr);

Vertex* get_vertex_from_string(std::string vertex);

void add_vertex(Vertex* vertex_list, Vertex* new_vertex);

Vertex* get_vertex_list_from_file(std::ifstream& istr, unsigned& vertex_amount);

Polygon get_next_polygon_from_file(std::ifstream& file);

PolygonsList get_polygons_list_from_file(std::ifstream& file);



//Funciones necesarias para filtrar poligonos 

// double getDistancia(Coordinate a, Coordinate b)    

// Vertex* get_vertice(Polygon& poligono_random, unsigned numero_del_vertice_a_devolver)   

// double getPerimetro(Polygon& poligono_random) 

/* La funcion filtrar poligonos debe declarar una lista filtrada y :
1 - Leer un poligono de la lista principal.
2 - Calcularle el perimetro.
3 - Si es mayor o igual al limite, agregarlo a la lista filtrada.
4 - Repetir 1 hasta que llegue al ultimo poligono.
*/

PolygonsList filtrar_lista_poligonos(double perimetro_minimo, const PolygonsList& lista);





// Funciones necesarias para introducir poligonos a un archivo ---------------------------------------

void give_polygons_color(std::ofstream& ostr, Color& color);

void give_polygons_amount(std::ofstream& ostr, unsigned& vertex_amount);

void give_vertex(std::ofstream& ostr, Vertex& vertex);

void give_polygon(std::ofstream& ostr, Polygon& polygon);

void escribirEnArchivo(PolygonsList lista, std::ofstream& outFile);

