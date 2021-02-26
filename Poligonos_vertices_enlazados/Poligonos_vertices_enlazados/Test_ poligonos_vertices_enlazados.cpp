/*
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include "Poligonos_punteros.h"


int main() {

    Polygon poligono1;
    show_polygon(poligono1);
    change_polygon_color(poligono1, cyan);
    assert(poligono1.color.intensidadRed == 0);
    assert(poligono1.color.intensidadGreen == 255);
    assert(poligono1.color.intensidadBlue == 255);

    add_end_vertex(poligono1, 5.5, 450.6);
    assert(poligono1.root_vertex_pointer->vertex_coordinates.x == 5.5);
    assert(poligono1.root_vertex_pointer->vertex_coordinates.y == 450.6);

    add_end_vertex(poligono1, 7.3, 470.4);
    add_end_vertex(poligono1, 50.1, 310.2);
    show_polygon(poligono1);

    change_vertex_data(poligono1, 0, 300.9, 350.9);
    assert(poligono1.root_vertex_pointer->vertex_coordinates.x == 300.9);
    assert(poligono1.root_vertex_pointer->vertex_coordinates.y == 350.9);

    Polygon poligono2;
    change_polygon_color(poligono2, green);
    add_end_vertex(poligono2, 300, 100);
    add_end_vertex(poligono2, 100, 300);
    add_end_vertex(poligono2, 400, 300);
    add_end_vertex(poligono2, 400, 100);

    Polygon poligono3;
    change_polygon_color(poligono3, red);
    add_end_vertex(poligono3, 100, 100);
    add_end_vertex(poligono3, 100, 200);
    add_end_vertex(poligono3, 200, 190);
    add_end_vertex(poligono3, 200, 100);

    remove_vertex(poligono3, 0);
    assert(poligono3.root_vertex_pointer->vertex_coordinates.x == 100);
    assert(poligono3.root_vertex_pointer->vertex_coordinates.y == 200);

    remove_vertex(poligono3, 2);
    assert(poligono3.root_vertex_pointer->next_vertex_pointer->vertex_coordinates.x == 200);
    assert(poligono3.root_vertex_pointer->next_vertex_pointer->vertex_coordinates.y == 190);

    Polygon cuadrado1;
    change_polygon_color(cuadrado1, magenta);
    add_end_vertex(cuadrado1, 10, 5);
    add_end_vertex(cuadrado1, 10, 10);
    add_end_vertex(cuadrado1, 5, 10);

    Polygon cuadrado2;
    change_polygon_color(cuadrado2, yellow);
    add_end_vertex(cuadrado2, 30, 25);
    add_end_vertex(cuadrado2, 30, 30);
    add_end_vertex(cuadrado2, 25, 30);

    Polygon cuadrado3;
    change_polygon_color(cuadrado3, black);
    add_end_vertex(cuadrado3, 50, 45);
    add_end_vertex(cuadrado3, 50, 50);
    add_end_vertex(cuadrado3, 45, 50);


    PolygonsList lista1;
    show_polygons_list(lista1);
    add_poligono_al_final(lista1, cuadrado1);
    assert(lista1.puntero_a_poligono_raiz->root_vertex_pointer->vertex_coordinates.x == 10);
    assert(lista1.puntero_a_poligono_raiz->root_vertex_pointer->vertex_coordinates.y == 5);
    assert(lista1.puntero_a_poligono_raiz->root_vertex_pointer->next_vertex_pointer->vertex_coordinates.x == 10);
    assert(lista1.puntero_a_poligono_raiz->root_vertex_pointer->next_vertex_pointer->vertex_coordinates.y == 10);
    assert(lista1.puntero_a_poligono_raiz->root_vertex_pointer->next_vertex_pointer->next_vertex_pointer->vertex_coordinates.x == 5);
    assert(lista1.puntero_a_poligono_raiz->root_vertex_pointer->next_vertex_pointer->next_vertex_pointer->vertex_coordinates.y == 10);

    add_poligono_al_final(lista1, cuadrado2);
    show_polygons_list(lista1);



    //  Streams ------------------------------------------------------------------------------------------------


    // Entry from file  -----------------------------------------------------------------

    PolygonsList lista2;

    std::fstream flujo_entrada("flujo_entrada.txt", std::ios::in);    //inicio del flujo de entrada

    while (!flujo_entrada.eof()) { get_polygon_from_stream(flujo_entrada, lista2); }

    show_polygons_list(lista2);

    flujo_entrada.close();



    // Output to file ----------------------------------------------------------------

    std::ofstream flujo_salida("flujo_salida.txt"); //inicio del flujo de salida

    for (unsigned i = 0; i < lista1.cantidad_poligonos; i++) {
        give_polygon (flujo_salida,*(get_polygon ( lista1, i )) );
    }

    flujo_salida.close();







    //Dibujo SVG -----------------------------------------------------------------------------------------

    std::ofstream dibujin("dibujo_de_poligonos_SVG.html");

    dibujin << " <!DOCTYPE html> <html> <body><svg height = \"500\" width = \"500\">";

    dibujin << "<polygon points = \"" << show_vertex_for_SVG(poligono1) << "\" style = \"fill:"
            << get_color_for_SVG(poligono1.color) << "; stroke:black;stroke-width:1\"/>";

    dibujin << "<polygon points = \"" << show_vertex_for_SVG(poligono2) << "\" style = \"fill:"
            << get_color_for_SVG(poligono2.color) << "; stroke:black;stroke-width:1\"/>";

    dibujin << "<polygon points = \"" << show_vertex_for_SVG(poligono3) << "\" style = \"fill:"
            << get_color_for_SVG(poligono3.color) << "; stroke:black;stroke-width:1\"/>";

    dibujin << "<polygon points = \"" << show_vertex_for_SVG(cuadrado1) << "\" style = \"fill:"
            << get_color_for_SVG(cuadrado1.color) << "; stroke:black;stroke-width:1\"/>";

    dibujin << "Sorry, something stopped working :C:C </svg> </body> </html>";

    //------------------------------------------------------------------------------------------------------




}

*/

// Created by Orne on 24/02/2021.
//  Streams --------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include "Poligonos_vertices_enlazados.h"


int main() {

    // Entry from file  -----------------------------------------------------------------

    std::fstream flujo_entrada("lista_de_poilgonos_para_filtrar.txt");    //inicio del flujo de entrada: abro txt

    std::string color_string;
    getline(flujo_entrada, color_string);     //la funcion getline tiene dos versiones; en �sta el caracter delimitante es new line  
    assert(color_string == "Color");          //no me funcion� el assert poniendo dos puntos luego de "Color"

    std::string color_RGB;
    getline(flujo_entrada, color_RGB);        //cada vez que se usa getline se lee la siguiente linea a la leida anteriormente 

//no voy a poder pasar todo como string porque entonces no voy a poder filtrar los poligonos por perimetro

    flujo_entrada.close();



    // Output to file ----------------------------------------------------------------

    std::ofstream flujo_salida("flujo_salida.txt"); //inicio del flujo de salida


    std::cout << "todo salio bien :3" << std::endl;

}