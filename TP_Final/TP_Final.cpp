#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>

struct Color { uint8_t intensidadRed, intensidadGreen, intensidadBlue; };
struct coordinate { double x, y; };
struct Vertex {
    Vertex* next_vertex_pointer = nullptr;
    coordinate vertex_coordinates{ 0,0 };
};
struct Polygon {
    Vertex* root_vertex_pointer = nullptr;
    unsigned vertex_amount = 0;
    Color color = { 0,0,0 };
    Polygon* next_polygon_pointer = nullptr;
};
struct PolygonsList {
    Polygon* puntero_a_poligono_raiz = nullptr;
    unsigned cantidad_poligonos = 0;
};

Color get_color_from_file(std::istream& istr) {
    Color read_color;

    double red, green, blue; 

    istr >> red;
    istr >> green;
    istr >> blue;

    read_color.intensidadRed = red;
    read_color.intensidadGreen = green;
    read_color.intensidadBlue = blue;


    return read_color;
}

Vertex get_vertex_from_string(std::string vertex) {

    std::stringstream ss(vertex);
    Vertex read_vertex;
    ss >> read_vertex.vertex_coordinates.x;
    ss >> read_vertex.vertex_coordinates.y;
    return read_vertex;
}

void add_vertex(Vertex* vertex_list, Vertex* new_vertex) {
    Vertex* current_vertex = vertex_list;
    if (current_vertex == nullptr) {
        vertex_list = new_vertex;
    }
    else {
        while (current_vertex->next_vertex_pointer != nullptr) {
            current_vertex = current_vertex->next_vertex_pointer;
        }
        current_vertex->next_vertex_pointer = new_vertex;
    }
}

Vertex* get_vertex_list_from_file(std::ifstream& istr) {
    bool continuar = true;
    std::string current_line;
    Vertex* vertex_list = nullptr;

    while (continuar) {
        getline(istr, current_line);
        if (current_line == "polygonend") {
            continuar = false;
        }
        else {
            Vertex current_vertex = get_vertex_from_string(current_line);
            add_vertex(vertex_list, &current_vertex);
        }
    }
    return vertex_list;
}

Polygon get_next_polygon_from_file(std::ifstream& file) {

    std::string current_line;
    Polygon read_polygon;

    getline(file, current_line);
    if (current_line != "polygonstart") {
        return read_polygon;
    }
    read_polygon.color = get_color_from_file(file);
    read_polygon.root_vertex_pointer = get_vertex_list_from_file(file);
    return read_polygon;
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

PolygonsList get_polygons_from_file(std::ifstream& file) {
    std::string current_line;
    PolygonsList polygons_list;

    //getline(file, currentLine);
    while (!file.eof()) {
        Polygon new_polygon = get_next_polygon_from_file(file);
        add_poligono_al_final(polygons_list, new_polygon);
    }

    return polygons_list;
}



void show_color(Color color_random) {
    //(255,255,255)
    std::cout << "El color es: (" << (int)color_random.intensidadRed << ", "
        << (int)color_random.intensidadGreen << ", "
        << (int)color_random.intensidadBlue << ")\n";
};

void show_vertex(Polygon& poligono_random, unsigned numero_del_vertice_a_imprimir) {

    Vertex* selected_vertex_pointer = poligono_random.root_vertex_pointer;

    for (unsigned i = 0; i < numero_del_vertice_a_imprimir; i++) {
        selected_vertex_pointer = selected_vertex_pointer->next_vertex_pointer;
    }

    std::cout << "(" << selected_vertex_pointer->vertex_coordinates.x << ", " 
        << selected_vertex_pointer->vertex_coordinates.y << ") ";
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


double getDistancia(coordinate a, coordinate b) {
    coordinate distancia;
    distancia.x = a.x > b.x ? a.x - b.x : b.x - a.x;
    distancia.y = a.y > b.y ? a.y - b.y : b.y - a.y;
    return pow(pow(distancia.x, 2) + pow(distancia.y, 2), 0.5);
}



int main()
{
    std::ifstream flujo_entrada("test.txt");
    PolygonsList polygon = get_polygons_from_file(flujo_entrada);
    show_polygons_list(polygon);
    
    std::cout << "todo ok";

}


