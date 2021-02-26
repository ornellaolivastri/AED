#include <iostream>
#include <string>
#include <math.h>
#include "Poligonos_vertices_enlazados.h"
#include <fstream>


// Color --------------------------------------------------------------------------------------

Color mixture(Color color1, Color color2) {
    Color color_nuevo;
    color_nuevo.intensidadRed = (color1.intensidadRed + color2.intensidadRed) / 2;
    color_nuevo.intensidadGreen = (color1.intensidadGreen + color2.intensidadGreen) / 2;
    color_nuevo.intensidadBlue = (color1.intensidadBlue + color2.intensidadBlue) / 2;

    return color_nuevo;
}

Color color_sum(Color color1, Color color2) {
    Color z;
    z.intensidadRed = color1.intensidadRed + color2.intensidadRed >
        255 ? 255 : color1.intensidadRed + color2.intensidadRed;
    z.intensidadGreen = color1.intensidadGreen + color2.intensidadGreen >
        255 ? 255 : color1.intensidadGreen + color2.intensidadGreen;
    z.intensidadBlue = color1.intensidadBlue + color2.intensidadBlue >
        255 ? 255 : color1.intensidadBlue + color2.intensidadBlue;

    return z;
}

Color color_subtraction(Color color1, Color color2) {
    Color z;
    z.intensidadRed = color1.intensidadRed - color2.intensidadRed < 0 ? 0 :
        color1.intensidadRed - color2.intensidadRed;
    z.intensidadGreen = color1.intensidadGreen - color2.intensidadGreen < 0 ? 0 :
        color1.intensidadGreen - color2.intensidadGreen;
    z.intensidadBlue = color1.intensidadBlue - color2.intensidadBlue < 0 ? 0 :
        color1.intensidadBlue - color2.intensidadBlue;

    return z;
}

bool IsIgual(Color color1, Color color2) {
    return (color1.intensidadRed == color2.intensidadRed) &&
        (color1.intensidadGreen == color2.intensidadGreen) &&
        (color1.intensidadBlue == color2.intensidadBlue);
}

void show_color(Color color_random) {
    //(255,255,255)
    std::cout << "El color es: (" << (int)color_random.intensidadRed << ", "
        << (int)color_random.intensidadGreen << ", "
        << (int)color_random.intensidadBlue << ")\n";
};

std::string get_color_for_SVG(Color color_random) {
    //rgb(255,255,255)

    std::string color_for_svn;
    int intensidadRed = (int)color_random.intensidadRed;
    int intensidadGreen = (int)color_random.intensidadGreen;
    int intensidadBlue = (int)color_random.intensidadBlue;

    return "rgb(" + std::to_string(intensidadRed) + ", " + std::to_string(intensidadGreen) + ", " + std::to_string(intensidadBlue) + ")\n";

}



// Coordinates --------------------------------------------------------------------------------

bool IsIgual(coordinate a, coordinate b) {
    return (a.x == b.x) && (a.y == b.y);
}

double getDistancia(coordinate a, coordinate b) {
    coordinate distancia;
    distancia.x = a.x > b.x ? a.x - b.x : b.x - a.x;
    distancia.y = a.y > b.y ? a.y - b.y : b.y - a.y;
    return pow(pow(distancia.x, 2) + pow(distancia.y, 2), 0.5);
}

double getDistanciaAlOrigen(coordinate a, coordinate origen) {
    coordinate distancia;
    distancia.x = a.x - 0;
    distancia.y = a.y - 0;
    return pow(pow(distancia.x, 2) + pow(distancia.y, 2), 0.5);
}

bool AreNear(double a, double b, double tolerancia) {
    return a >= b ? (a - b) <= tolerancia : (b - a) <= tolerancia;
}



//Polygons ------------------------------------------------------------------------------------

void change_polygon_color(Polygon& poligono_random, Color color_a_agregar) {
    poligono_random.color = color_a_agregar;
}

std::string show_vertex_for_SVG(Polygon& poligono_random) {

    std::string vertices = "";

    Vertex* puntero_a_vertice_actual = poligono_random.root_vertex_pointer;
    do {
        vertices = vertices + std::to_string(puntero_a_vertice_actual->vertex_coordinates.x) + ", " + std::to_string(puntero_a_vertice_actual->vertex_coordinates.y) + " ";
        puntero_a_vertice_actual = puntero_a_vertice_actual->next_vertex_pointer;
    } while (puntero_a_vertice_actual != nullptr);

    return vertices;
}

void show_vertex(Polygon& poligono_random, unsigned numero_del_vertice_a_imprimir) {

    Vertex* selected_vertex_pointer = poligono_random.root_vertex_pointer;

    for (unsigned i = 0; i < numero_del_vertice_a_imprimir; i++) {
        selected_vertex_pointer = selected_vertex_pointer->next_vertex_pointer;
    }

    std::cout << "(" << selected_vertex_pointer->vertex_coordinates.x << ", " << selected_vertex_pointer->vertex_coordinates.y << ") ";
}

void change_vertex_data(Polygon& poligono_random, unsigned numero_vertice_a_modificar, double x, double y) {
    Vertex* selected_vertex_pointer = poligono_random.root_vertex_pointer;
    for (unsigned i = 0; i < numero_vertice_a_modificar; i++) {
        selected_vertex_pointer = selected_vertex_pointer->next_vertex_pointer;
    }
    selected_vertex_pointer->vertex_coordinates.x = x;
    selected_vertex_pointer->vertex_coordinates.y = y;
}

void add_end_vertex(Polygon& poligono_random, double x, double y) {

    Vertex* new_vertex_pointer = new Vertex; //devuelve la direccion de memoria del principio del espacio reservado

    //inicializacion del nuevo vertice: (va a tener estos datos)
    new_vertex_pointer->next_vertex_pointer = nullptr;
    new_vertex_pointer->vertex_coordinates.x = x;
    new_vertex_pointer->vertex_coordinates.y = y;

    if (poligono_random.vertex_amount == 0) {
        poligono_random.root_vertex_pointer = new_vertex_pointer;
    }
    //el ultimo vertice del poligono tiene que apuntar al que acabo de crear
    else {
        Vertex* selected_vertex = poligono_random.root_vertex_pointer;
        while (selected_vertex->next_vertex_pointer != nullptr) {
            selected_vertex = selected_vertex->next_vertex_pointer;
        }
        selected_vertex->next_vertex_pointer = new_vertex_pointer;
    }

    poligono_random.vertex_amount = poligono_random.vertex_amount + 1;

}

void add_poligono_al_final(PolygonsList& lista_random, Polygon& poligono_a_agregar) {

    if (lista_random.cantidad_poligonos == 0) {
        lista_random.puntero_a_poligono_raiz = &poligono_a_agregar;
    }
    else {

        Polygon* selected_polygon_pointer = lista_random.puntero_a_poligono_raiz;

        while (selected_polygon_pointer->next_polygon_pointer != nullptr) {
            selected_polygon_pointer = selected_polygon_pointer->next_polygon_pointer;
        }
        selected_polygon_pointer->next_polygon_pointer = &poligono_a_agregar;
        // & es pasar la dirección de memoria de poligono_a_agregar
    }

    lista_random.cantidad_poligonos = lista_random.cantidad_poligonos + 1;

}

Vertex* get_vertice(Polygon& poligono_random, unsigned numero_del_vertice_a_devolver) {
    Vertex* selected_vertex_pointer = poligono_random.root_vertex_pointer;
    for (unsigned i = 0; i < numero_del_vertice_a_devolver; i++) {
        selected_vertex_pointer = selected_vertex_pointer->next_vertex_pointer;
    }
    return selected_vertex_pointer;
}

void remove_vertex(Polygon& poligono_random, unsigned numero_del_vertice_a_eliminar) {

    if (numero_del_vertice_a_eliminar == 0) {
        Vertex* vertice_a_borrar_ptr = poligono_random.root_vertex_pointer;
        poligono_random.root_vertex_pointer = poligono_random.root_vertex_pointer->next_vertex_pointer;
        delete vertice_a_borrar_ptr;
    }
    else {
        Vertex* selected_vertex_pointer = poligono_random.root_vertex_pointer;

        for (unsigned i = 0; i < numero_del_vertice_a_eliminar - 1; i++) // voy hasta el vertice anterior al que quiero eliminar
        {
            //el vertice actual no es el que quiero eliminar, entonces voy al anterior
            selected_vertex_pointer = selected_vertex_pointer->next_vertex_pointer;
        }

        selected_vertex_pointer->next_vertex_pointer = selected_vertex_pointer->next_vertex_pointer->next_vertex_pointer;

        delete selected_vertex_pointer->next_vertex_pointer;
    }

    poligono_random.vertex_amount = poligono_random.vertex_amount - 1;

}

double getPerimetro(Polygon& poligono_random) {

    Vertex* selected_vertex_pointer = poligono_random.root_vertex_pointer;
    double perimetro = 0;

    for (unsigned i = 0; i < poligono_random.vertex_amount - 1; i++) {

        perimetro = perimetro + getDistancia(selected_vertex_pointer->vertex_coordinates, selected_vertex_pointer->next_vertex_pointer->vertex_coordinates);

        selected_vertex_pointer = selected_vertex_pointer->next_vertex_pointer;
    }

    perimetro = perimetro + getDistancia(selected_vertex_pointer->vertex_coordinates, get_vertice(poligono_random, 0)->vertex_coordinates);

    return perimetro;
}



//Polygon's Lists ------------------------------------------------------------------------------------

void show_polygons_list(PolygonsList& RandomPolygonList) {

    if (RandomPolygonList.cantidad_poligonos == 0) {
        std::cout << "La lista esta vacia.\n";
    }
    else {
        std::cout << "La lista de poligonos es: \n";

        Polygon* selected_vertex_pointer = RandomPolygonList.puntero_a_poligono_raiz;

        for (unsigned i = 0; i < RandomPolygonList.cantidad_poligonos; i++) {
            show_polygon(*selected_vertex_pointer);
            selected_vertex_pointer = selected_vertex_pointer->next_polygon_pointer;
        }

        std::cout << "\n";
    }
}

void show_polygon(Polygon& poligono_random) {

    if (poligono_random.vertex_amount == 0) {
        std::cout << "El poligono esta vacio.\n";
    }
    else {
        std::cout << "El poligono es: ";

        Vertex* selected_vertex_pointer = poligono_random.root_vertex_pointer;

        for (unsigned i = 0; i < poligono_random.vertex_amount; i++) {
            show_vertex(poligono_random, i);
            selected_vertex_pointer = selected_vertex_pointer->next_vertex_pointer;
        }
    }

    std::cout << "\n";
    show_color(poligono_random.color);
}

Polygon* get_polygon(PolygonsList& RandomPolygonList, unsigned numero_del_poligono_a_devolver) {

    Polygon* selected_polygon_pointer = RandomPolygonList.puntero_a_poligono_raiz;

    for (unsigned i = 0; i < numero_del_poligono_a_devolver; i++) {
        selected_polygon_pointer = selected_polygon_pointer->next_polygon_pointer;
    }
    return selected_polygon_pointer;
}



//Funciones para extraer desde un archivo ----------------------------------------------------

void get_polygons_color_from_stream(std::istream& istr, Color& color) {

    unsigned written_byte;
    istr >> written_byte;
    written_byte = written_byte > 255 ? 255 : written_byte;
    written_byte = written_byte < 0 ? 0 : written_byte;
    color.intensidadRed = written_byte;
    istr >> written_byte;
    written_byte = written_byte > 255 ? 255 : written_byte;
    written_byte = written_byte < 0 ? 0 : written_byte;
    color.intensidadGreen = written_byte;
    istr >> written_byte;
    written_byte = written_byte > 255 ? 255 : written_byte;
    written_byte = written_byte < 0 ? 0 : written_byte;
    color.intensidadBlue = written_byte;
}

unsigned get_polygons_amount_from_stream(std::istream& istr) {
    unsigned amount;
    istr >> amount;
    return amount;
}

void get_vertex_from_stream(std::istream& istr, Polygon* poligono_random) {
    double x, y;
    istr >> x;
    istr >> y;
    add_end_vertex(*poligono_random, x, y);
}

bool get_separator_from_stream(std::istream& istr) {
    istr.clear();
    char written_caracter = 0;
    istr >> written_caracter;
    return !istr.eof();
}

void get_polygon_from_stream(std::istream& istr, PolygonsList& lista_random) {

    Polygon* new_polygon_pointer = new Polygon;

    add_poligono_al_final(lista_random, *new_polygon_pointer);

    get_polygons_color_from_stream(istr, new_polygon_pointer->color);

    unsigned amount = get_polygons_amount_from_stream(istr);

    if (istr.eof()) {
        return;
    }

    for (unsigned i = 0; i < amount; ++i) {

        get_vertex_from_stream(istr, new_polygon_pointer);
    }
}



//Funciones para introducir a un archivo --------------------------------------------------

void give_polygons_color(std::ofstream& ostr, Color& color) {
    ostr << "Color: " << (unsigned)color.intensidadRed << " ";
    ostr << (unsigned)color.intensidadGreen << " ";
    ostr << (unsigned)color.intensidadBlue << " \n";
}

void give_polygons_amount(std::ofstream& ostr, unsigned& vertex_amount) {
    ostr << "Cantidad de vertices: " << vertex_amount << "\n";
}

void give_vertex(std::ofstream& ostr, Vertex& vertex) {
    ostr << "Vertice: " << vertex.vertex_coordinates.x << " ";
    ostr << vertex.vertex_coordinates.y << " \n";
}

void give_polygon(std::ofstream& ostr, Polygon& polygon) {

    Vertex* selected_vertex_pointer = polygon.root_vertex_pointer;

    give_polygons_color(ostr, polygon.color);

    give_polygons_amount(ostr, polygon.vertex_amount);

    for (unsigned i = 0; i < polygon.vertex_amount; ++i) {
        give_vertex(ostr, *(get_vertice(polygon, i)));
    }

    ostr << "*\n";
}
