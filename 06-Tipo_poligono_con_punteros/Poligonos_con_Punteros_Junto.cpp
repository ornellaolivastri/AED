#include <iostream>
#include<string>
#include <math.h>
#include "Poligonos_con_Punteros_Junto.h"
#include <fstream>

Color mezcla(Color color1, Color color2) {
	Color color_nuevo;
	color_nuevo.intensidadRed = (color1.intensidadRed + color2.intensidadRed) / 2;
	color_nuevo.intensidadGreen = (color1.intensidadGreen + color2.intensidadGreen) / 2;
	color_nuevo.intensidadBlue = (color1.intensidadBlue + color2.intensidadBlue) / 2;

	return color_nuevo;
}

Color suma_colores(Color color1, Color color2) {
	Color z;
	z.intensidadRed = color1.intensidadRed + color2.intensidadRed > 255 ? 255 : color1.intensidadRed + color2.intensidadRed;
	z.intensidadGreen = color1.intensidadGreen + color2.intensidadGreen > 255 ? 255 : color1.intensidadGreen + color2.intensidadGreen;
	z.intensidadBlue = color1.intensidadBlue + color2.intensidadBlue > 255 ? 255 : color1.intensidadBlue + color2.intensidadBlue;

	return z;
}

Color resta_colores(Color color1, Color color2) {
	Color z;
	z.intensidadRed = color1.intensidadRed - color2.intensidadRed < 0 ? 0 : color1.intensidadRed - color2.intensidadRed;
	z.intensidadGreen = color1.intensidadGreen - color2.intensidadGreen < 0 ? 0 : color1.intensidadGreen - color2.intensidadGreen;
	z.intensidadBlue = color1.intensidadBlue - color2.intensidadBlue < 0 ? 0 : color1.intensidadBlue - color2.intensidadBlue;

	return z;
}

bool IsIgual(Color color1, Color color2) {
	return (color1.intensidadRed == color2.intensidadRed) and
		(color1.intensidadGreen == color2.intensidadGreen) and
		(color1.intensidadBlue == color2.intensidadBlue);
}

void show_color(Color color_random) {
	//(255,255,255)
	std::cout << "El color es: (" << (int)color_random.intensidadRed << ", "
		<< (int)color_random.intensidadGreen << ", "
		<< (int)color_random.intensidadBlue << ")\n";
};

std::string get_color_for_svn(Color color_random) {
	//rgb(255,255,255)

	std::string color_for_svn;
	int intensidadRed = (int)color_random.intensidadRed;
	int intensidadGreen = (int)color_random.intensidadGreen;
	int intensidadBlue = (int)color_random.intensidadBlue;

	return "rgb(" + std::to_string(intensidadRed) + ", " + std::to_string(intensidadGreen) + ", " + std::to_string(intensidadBlue) + ")\n";

}

// Coordinates -----------------------------------------------

bool IsIgual(coordinate a, coordinate b) {
	return (a.x == b.x) and (a.y == b.y);
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

//Tolerancia= +- 0.001
//AreNear devuelve true or false si la diferencia entre los dos double a y b supera la diferencia


bool AreNear(double a, double b, double tolerancia) {
	//             ? = entonces         : = sino
	return a >= b ? (a - b) <= tolerancia      //si a es mayor o igual que b ? restar a - b y comprobar si la resta es menor a la tolerancia
		: (b - a) <= tolerancia;     //                            : restar b - a y comprobar si la resta es menor a la tolerancia

}


//Definiciones de funciones de poligonos ---------------------------------------------------
//el operador . es para variables de la stack
//el operador -> es para variables de la heap
//recordar siempre que los nodos empiezan desde el cero 
//si por ej si quiero cambiar el segundo nodo, ese va a tener el indice 1

void inicializacion_de_Poligono(Polygon& poligono_random, Color color_a_agregar) { //CREO LA LISTA SIN NADA AAAAAAAAAAH

    poligono_random.root_vertex_pointer = new Vertex;
    poligono_random.root_vertex_pointer->next_vertex_pointer = nullptr;
    poligono_random.vertex_amount = 1;

    poligono_random.color = color_a_agregar;
    poligono_random.root_vertex_pointer->vertex_coordinates.x = 0;
    poligono_random.root_vertex_pointer->vertex_coordinates.y = 0;

    /*nodoRaiz -> datoDelNodo = 5; es igual a escribir (*nodoRaiz).datoDelNodo = 5;

    hay que pasarlo con el & porque sino estas pasando valores
    pero no le das el control a la funcion para que modifique las
    variables mismas(originales) sino copias*/

}

std::string show_vertice_para_svg(Polygon& poligono_random) {

    std::string vertices = "";

    Vertex* puntero_a_vertice_actual = poligono_random.root_vertex_pointer;
    do {
        vertices = vertices + std::to_string(puntero_a_vertice_actual->vertex_coordinates.x) + ", " + std::to_string(puntero_a_vertice_actual->vertex_coordinates.y) + " ";
        puntero_a_vertice_actual = puntero_a_vertice_actual->next_vertex_pointer;
    } while (puntero_a_vertice_actual != nullptr);

    return vertices;
}

void show_vertice(Polygon& poligono_random, unsigned numero_del_vertice_a_imprimir) {
    Vertex* selected_vertex_pointer = poligono_random.root_vertex_pointer;
    for (unsigned i = 0; i < numero_del_vertice_a_imprimir; i++) {
        selected_vertex_pointer = selected_vertex_pointer->next_vertex_pointer;
    }

    std::cout << "(" << selected_vertex_pointer->vertex_coordinates.x << ", " << selected_vertex_pointer->vertex_coordinates.y << ")\n";
}

void cambiar_datos_del_vertice(Polygon& poligono_random, unsigned numero_del_vertice_a_modificar, double x, double y) {
    Vertex* selected_vertex_pointer = poligono_random.root_vertex_pointer;
    for (unsigned i = 0; i < numero_del_vertice_a_modificar; i++) {
        selected_vertex_pointer = selected_vertex_pointer->next_vertex_pointer;
    }
    selected_vertex_pointer->vertex_coordinates.x = x;
    selected_vertex_pointer->vertex_coordinates.y = y;
}

void add_vertice_al_final(Polygon& poligono_random, double x, double y) {
    Vertex* new_vertex_pointer = new Vertex; //devuelve la direccion de memoria del principio del espacio reservado

    //inicializacion del nuevo vertice: (va a tener estos datos)
    new_vertex_pointer->next_vertex_pointer = nullptr;
    new_vertex_pointer->vertex_coordinates.x = x;
    new_vertex_pointer->vertex_coordinates.y = y;

    //el nuevo nodo va a ser ubicado aca:
    Vertex* puntero_a_raiz = poligono_random.root_vertex_pointer;

    while (puntero_a_raiz->next_vertex_pointer != nullptr) {
        puntero_a_raiz = puntero_a_raiz->next_vertex_pointer;
    }
    puntero_a_raiz->next_vertex_pointer = new_vertex_pointer;

    poligono_random.vertex_amount = poligono_random.vertex_amount + 1;

}

void add_poligono_al_final(PolygonsList& lista_random, Polygon& poligono_a_agregar) {
    Polygon* new_polygon_pointer = new Polygon; //devuelve la direccion de memoria del principio del espacio reservado

    //inicializacion del nuevo poligono: (va a tener estos datos)
    new_polygon_pointer->next_polygon_pointer = nullptr;

    //el nuevo nodo va a ser ubicado aca:
    Polygon* selected_polygon_pointer = lista_random.puntero_a_poligono_raiz;

    while (selected_polygon_pointer->next_polygon_pointer != nullptr) {
        selected_polygon_pointer = selected_polygon_pointer->next_polygon_pointer;
    }
    selected_polygon_pointer->next_polygon_pointer = &poligono_a_agregar; // & es pasar la dirección de memoria de poligono_a_agregar

    lista_random.cantidad_poligonos = lista_random.cantidad_poligonos + 1;

}

Vertex* get_vertice(Polygon& poligono_random, unsigned numero_del_vertice_a_devolver) {
    Vertex* selected_vertex_pointer = poligono_random.root_vertex_pointer;
    for (unsigned i = 0; i < numero_del_vertice_a_devolver; i++) {
        selected_vertex_pointer = selected_vertex_pointer->next_vertex_pointer;
    }
    return selected_vertex_pointer;
}

void remove_vertice(Polygon& poligono_random, unsigned numero_del_vertice_a_eliminar) {
    Vertex* selected_vertex_pointer = poligono_random.root_vertex_pointer;

    if (numero_del_vertice_a_eliminar == 0) {
        poligono_random.root_vertex_pointer->next_vertex_pointer = poligono_random.root_vertex_pointer->next_vertex_pointer->next_vertex_pointer;
    }

    else {
        for (unsigned i = 0; i < numero_del_vertice_a_eliminar - 1; i++) // voy hasta el vertice anterior al que quiero eliminar
        {
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

void inicializacion_de_PolygonList(PolygonsList& RandomPolygonList, Color color_a_agregar) {
    RandomPolygonList.puntero_a_poligono_raiz = new Polygon;
    RandomPolygonList.puntero_a_poligono_raiz->next_polygon_pointer = nullptr;
    RandomPolygonList.cantidad_poligonos = 1;
    inicializacion_de_Poligono(*RandomPolygonList.puntero_a_poligono_raiz, color_a_agregar);
}

void show_polygons_list(PolygonsList& RandomPolygonList) {
    Polygon* selected_vertex_pointer = RandomPolygonList.puntero_a_poligono_raiz;

    std::cout << "La lista de poligonos es: ";

    for (unsigned i = 0; i < RandomPolygonList.cantidad_poligonos; i++) {
        show_poligono(*selected_vertex_pointer);
        selected_vertex_pointer = selected_vertex_pointer->next_polygon_pointer;
    }
}

void show_poligono(Polygon& poligono_random) {

    Vertex* selected_vertex_pointer = poligono_random.root_vertex_pointer;

    std::cout << "El poligono es: ";

    for (unsigned i = 0; i < poligono_random.vertex_amount; i++) {
        show_vertice(poligono_random, i);
        selected_vertex_pointer = selected_vertex_pointer->next_vertex_pointer;
    }

    show_color(poligono_random.color);
}

Polygon* get_polygon(PolygonsList& RandomPolygonList, unsigned numero_del_poligono_a_devolver) {

    Polygon* selected_polygon_pointer = RandomPolygonList.puntero_a_poligono_raiz;

    for (unsigned i = 0; i < numero_del_poligono_a_devolver; i++) {
        selected_polygon_pointer = selected_polygon_pointer->next_polygon_pointer;
    }
    return selected_polygon_pointer;
}



//Funciones para extraer ------------------------------------------------------

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

void get_polygons_amount_from_stream(std::istream& istr, unsigned& vertex_amount) {
    istr >> vertex_amount;
}

void get_vertex_from_stream(std::istream& istr, Vertex& vertex) {
    istr >> vertex.vertex_coordinates.x;
    istr >> vertex.vertex_coordinates.y;
}

bool get_separator_from_stream(std::istream& istr) {
    istr.clear();
    char written_caracter = 0;
    istr >> written_caracter;
    return ((istr) && (written_caracter == '*'));
}

bool get_polygon_from_stream(std::istream& istr, Polygon& polygon) {

    Vertex* selected_vertex_pointer = polygon.root_vertex_pointer;

    get_polygons_color_from_stream(istr, polygon.color);

    get_polygons_amount_from_stream(istr, polygon.vertex_amount);

    for (unsigned i = 0; i < polygon.vertex_amount; ++i) {
        get_vertex_from_stream(istr, polygon.vertex_amount[selected_vertex_pointer]);
    }

    return get_separator_from_stream(istr); // Por más que ya tenga la cantidad de vértices, 
                                // me sirve para saber si hay más
}


//Funciones para introducir --------------------------------------------------


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
