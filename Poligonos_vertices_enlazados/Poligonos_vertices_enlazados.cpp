#include <iostream>
#include <string>
#include <math.h>
#include "Poligonos_vertices_enlazados.h"
#include <fstream>
#include <sstream>



// Color --------------------------------------------------------------------------------------

Color mixture(Color color1, Color color2) {
    Color color_nuevo;
    color_nuevo.red = (color1.red + color2.red) / 2;
    color_nuevo.green = (color1.green + color2.green) / 2;
    color_nuevo.blue = (color1.blue + color2.blue) / 2;

    return color_nuevo;
}

Color color_sum(Color color1, Color color2) {
    Color z;
    z.red = color1.red + color2.red >
        255 ? 255 : color1.red + color2.red;
    z.green = color1.green + color2.green >
        255 ? 255 : color1.green + color2.green;
    z.blue = color1.blue + color2.blue >
        255 ? 255 : color1.blue + color2.blue;

    return z;
}

Color color_subtraction(Color color1, Color color2) {
    Color z;
    z.red = color1.red - color2.red < 0 ? 0 :
        color1.red - color2.red;
    z.green = color1.green - color2.green < 0 ? 0 :
        color1.green - color2.green;
    z.blue = color1.blue - color2.blue < 0 ? 0 :
        color1.blue - color2.blue;

    return z;
}

bool IsIgual(Color color1, Color color2) {
    return (color1.red == color2.red) &&
        (color1.green == color2.green) &&
        (color1.blue == color2.blue);
}

void show_color(Color color_random) {
    std::cout << "El color es: (" << (int)color_random.red << ", "
        << (int)color_random.green << ", "
        << (int)color_random.blue << ")\n";
};


std::string get_color_for_SVG(Color color_random) {
    //rgb(255,255,255)

    std::string color_for_svn;
    int red = (int)color_random.red;
    int green = (int)color_random.green;
    int blue = (int)color_random.blue;

    return "rgb(" + std::to_string(red) + ", " + std::to_string(green) + ", " + std::to_string(blue) + ")\n";

}



// Coordinates --------------------------------------------------------------------------------

bool IsIgual(Coordinate a, Coordinate b) {
    return (a.x == b.x) && (a.y == b.y);
}

double getDistancia(Coordinate a, Coordinate b) {
    Coordinate distancia;
    distancia.x = a.x > b.x ? a.x - b.x : b.x - a.x;
    distancia.y = a.y > b.y ? a.y - b.y : b.y - a.y;
    return pow(pow(distancia.x, 2) + pow(distancia.y, 2), 0.5);
}

double getDistanciaAlOrigen(Coordinate a, Coordinate origen) {
    Coordinate distancia;
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

    std::cout << "(" << selected_vertex_pointer->vertex_coordinates.x << ", "
        << selected_vertex_pointer->vertex_coordinates.y << ") ";
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
    
    std::cout << "El perimetro es: " << getPerimetro(poligono_random) << "\n" << std::endl;
    
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

void add_poligono_al_final(PolygonsList& lista_random, const Polygon& poligono_a_agregar) {

    PolygonNode* new_node = new PolygonNode;
    new_node->polygon = poligono_a_agregar;
    new_node->next_node = nullptr;

    if (lista_random.polygons_amount== 0) {
        lista_random.root_polygon_node_pointer = new_node;
    }
    else {

        PolygonNode* selected_polygon_pointer = lista_random.root_polygon_node_pointer;

        while (selected_polygon_pointer->next_node != nullptr) {
            selected_polygon_pointer = selected_polygon_pointer->next_node;
        }
        selected_polygon_pointer->next_node = new_node;
    }
    lista_random.polygons_amount = lista_random.polygons_amount + 1;
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





//Polygon's Lists ------------------------------------------------------------------------------------

void show_polygons_list(PolygonsList RandomPolygonList) {

    if (RandomPolygonList.polygons_amount == 0) {
        std::cout << "La lista esta vacia.\n";
    }
    else {
        std::cout << "La lista de poligonos es: \n";

        PolygonNode* selected_polygon_pointer = RandomPolygonList.root_polygon_node_pointer;

        for (unsigned i = 0; i < RandomPolygonList.polygons_amount; i++) {
            show_polygon(selected_polygon_pointer->polygon);
            selected_polygon_pointer = selected_polygon_pointer->next_node;
        }

        std::cout << "\n";
    }
}

PolygonNode* get_polygon(PolygonsList& RandomPolygonList, unsigned numero_del_poligono_a_devolver) {

    PolygonNode* selected_polygon_pointer = RandomPolygonList.root_polygon_node_pointer;

    for (unsigned i = 0; i < numero_del_poligono_a_devolver; i++) {
        selected_polygon_pointer = selected_polygon_pointer->next_node;
    }
    return selected_polygon_pointer;
}



//Funciones para extraer desde un archivo ----------------------------------------------------

Color get_polygons_color_from_file(std::istream& istr) {
    Color read_color;
    double red, green, blue;
    istr >> red;
    red = red > 255 ? 255 : red;
    red = red < 0 ? 0 : red;
    istr >> green;
    green = green > 255 ? 255 : green;
    green = green < 0 ? 0 : green;
    istr >> blue;
    blue = blue > 255 ? 255 : blue;
    blue = blue < 0 ? 0 : blue;
    read_color.red = red;
    read_color.green = green;
    read_color.blue = blue;

    //Para limpiar el salto de linea
    std::string eol;
    getline(istr, eol);

    return read_color;
}

Vertex* get_vertex_from_string(std::string vertex) {

    std::stringstream ss(vertex);     //convierte el string en un stream
    Vertex* read_vertex = new Vertex;
    ss >> read_vertex->vertex_coordinates.x;
    ss >> read_vertex->vertex_coordinates.y;
    return read_vertex;
}

void add_vertex(Vertex* vertex_list, Vertex* new_vertex) {
    Vertex* current_vertex = vertex_list;
    while (current_vertex->next_vertex_pointer != nullptr) {
        current_vertex = current_vertex->next_vertex_pointer;
    }
    current_vertex->next_vertex_pointer = new_vertex;
}

Vertex* get_vertex_list_from_file(std::ifstream& istr, unsigned& vertex_amount) {
    bool continuar = true;
    std::string current_line;

    Vertex* vertex_list = nullptr;
    Vertex* current_vertex;
    while (continuar) {
        getline(istr, current_line);
        if (current_line == "polygonend") {
            continuar = false;
        }
        else {
            current_vertex = get_vertex_from_string(current_line);
            if (vertex_list == nullptr) {
                vertex_list = current_vertex;
            }
            else {
                add_vertex(vertex_list, current_vertex);
            }
            vertex_amount++;
        }
    }
    return vertex_list;
}

Polygon get_next_polygon_from_file(std::ifstream& file) {

    std::string current_line;
    Polygon read_polygon;
    unsigned vertex_amount = 0;

    getline(file, current_line);
    if (current_line != "polygonstart") {
        std::cout << "El formato del archivo es incorrecto";
        exit(0);
    }

    read_polygon.color = get_polygons_color_from_file(file);
    read_polygon.root_vertex_pointer = get_vertex_list_from_file(file, vertex_amount);
    read_polygon.vertex_amount = vertex_amount;
    return read_polygon;
}

PolygonsList get_polygons_list_from_file(std::ifstream& file) {
    std::string current_line;
    PolygonsList polygons_list;

    while (!file.eof()) {
        Polygon new_polygon = get_next_polygon_from_file(file);
        add_poligono_al_final(polygons_list, new_polygon);
    }

    return polygons_list;
}



// Funciones necesarias para filtrar poligonos ----------------------------------------------------

// double getDistancia(Coordinate a, Coordinate b)    definida mas arriba

// Vertex* get_vertice(Polygon& poligono_random, unsigned numero_del_vertice_a_devolver)   definida mas arriba

// double getPerimetro(Polygon& poligono_random) definida mas arriba

/* La funcion filtrar poligonos debe declarar una lista filtrada y :
1 - Leer un poligono de la lista principal.
2 - Calcularle el perimetro.
3 - Si es mayor o igual al limite, agregarlo a la lista filtrada.
4 - Repetir 1 hasta que llegue al ultimo poligono.
*/

PolygonsList filtrar_lista_poligonos(double perimetro_minimo, const PolygonsList& lista) {

    PolygonsList lista_filtrada;

    PolygonNode* selected_polygon_pointer = lista.root_polygon_node_pointer;

    while (selected_polygon_pointer != nullptr) {

        double perimetro = getPerimetro(selected_polygon_pointer->polygon);

        if (perimetro >= perimetro_minimo) {
            add_poligono_al_final(lista_filtrada, selected_polygon_pointer->polygon);
        }

        selected_polygon_pointer = selected_polygon_pointer->next_node;
    }

    return lista_filtrada;
}





//Funciones para introducir poligonos a un archivo --------------------------------------------------

void give_polygons_color(std::ofstream& ostr, Color& color) {
    ostr << "Color: " << (unsigned)color.red << " ";
    ostr << (unsigned)color.green << " ";
    ostr << (unsigned)color.blue << " \n";
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
    ostr << "Perimetro: " << getPerimetro(polygon) << "\n";
    ostr << "*\n";
}

void escribirEnArchivo(PolygonsList lista, std::ofstream& outFile) {

    PolygonNode* selected_polygon_pointer = lista.root_polygon_node_pointer;

    while (selected_polygon_pointer != nullptr) {

        give_polygon(outFile, selected_polygon_pointer->polygon);

        selected_polygon_pointer = selected_polygon_pointer->next_node;
    }

    outFile << "holi :3 \n";
}

