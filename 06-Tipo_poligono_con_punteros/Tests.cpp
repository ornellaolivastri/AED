#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include "Poligonos_punteros.h"

int main() {
    
    Polygon poligono1;
    change_polygon_color(poligono1, cyan);
    //show_poligono(poligono1);
    add_vertice_al_final(poligono1, 5.5, 450.6);
    //show_poligono(poligono1);
    add_vertice_al_final(poligono1, 7.3, 470.4);
    add_vertice_al_final(poligono1, 50.1, 310.2);
    //show_poligono(poligono1);
    cambiar_datos_vertice(poligono1, 0, 300.9, 350.9); 
       
    Polygon poligono2;
    change_polygon_color(poligono2, green);
    add_vertice_al_final(poligono2, 300, 100);
    add_vertice_al_final(poligono2, 100, 300);
    add_vertice_al_final(poligono2, 400, 300);
    add_vertice_al_final(poligono2, 400, 100);

    Polygon poligono3;
    change_polygon_color(poligono3, red);
    add_vertice_al_final(poligono3, 100, 100);
    add_vertice_al_final(poligono3, 100, 200);
    add_vertice_al_final(poligono3, 200, 190);
    add_vertice_al_final(poligono3, 200, 100);

    remove_vertice(poligono3, 0);
    remove_vertice(poligono3, 2);

    //show_poligono(poligono3);
    
    Polygon cuadrado1;
    change_polygon_color(cuadrado1, magenta);
    add_vertice_al_final(cuadrado1, 10, 5);
    add_vertice_al_final(cuadrado1, 10, 10);
    add_vertice_al_final(cuadrado1, 5, 10);
    
    Polygon cuadrado2;
    change_polygon_color(cuadrado2, yellow);
    add_vertice_al_final(cuadrado2, 30, 25);
    add_vertice_al_final(cuadrado2, 30, 30);
    add_vertice_al_final(cuadrado2, 25, 30);

    Polygon cuadrado3;
    change_polygon_color(cuadrado3, black);
    add_vertice_al_final(cuadrado3, 50, 45);
    add_vertice_al_final(cuadrado3, 50, 50);
    add_vertice_al_final(cuadrado3, 45, 50);

    
    PolygonsList lista1;
    //show_polygons_list(lista1);
    add_poligono_al_final(lista1, cuadrado1);
    //show_polygons_list(lista1);
    add_poligono_al_final(lista1, cuadrado2);
    //show_polygons_list(lista1);

    
    //Dibujo SVG -----------------------------------------------------------------------
    /*
    std::ofstream dibujin("dibujo_de_poligonos_SVG.html");

    dibujin << " <!DOCTYPE html> <html> <body><svg height = \"500\" width = \"500\">";
    
    dibujin << "<polygon points = \"" << show_vertice_para_svg(poligono1) << "\" style = \"fill:"
            << get_color_for_svn(poligono1.color) << "; stroke:black;stroke-width:1\"/>";

    dibujin << "<polygon points = \"" << show_vertice_para_svg(poligono2) << "\" style = \"fill:"
            << get_color_for_svn(poligono2.color) << "; stroke:black;stroke-width:1\"/>";

    dibujin << "<polygon points = \"" << show_vertice_para_svg(poligono3) << "\" style = \"fill:"
            << get_color_for_svn(poligono3.color) << "; stroke:black;stroke-width:1\"/>";

    dibujin << "<polygon points = \"" << show_vertice_para_svg(cuadrado1) << "\" style = \"fill:"
            << get_color_for_svn(cuadrado1.color) << "; stroke:black;stroke-width:1\"/>";

    //<text x = "0" y = "15" fill = "red">I love SVG!< / text>

    dibujin << "Sorry, something stopped working :C:C </svg> </body> </html>";
    */
    //-----------------------------------------------------------------------------------------------------------
        

    // Output to file -------------------------------------------------------------------------------------------
    /*
    std::ofstream flujo_salida("flujo_salida.txt"); //inicio del flujo de salida

    for (unsigned i = 0; i < lista1.cantidad_poligonos; i++) {
        give_polygon(flujo_salida,*(get_polygon ( lista1, i ))    );
    }

    flujo_salida.close();

    */


    

    // Entry from file  ------------------------------------------------------------------------------------------

    PolygonsList lista2;
   


    std::fstream flujo_entrada("flujo_entrada.txt", std::ios::in);    //inicio del flujo de entrada
    
    /*for (; get_polygon_from_stream(flujo_entrada, lista2);) {
        lista2.cantidad_poligonos++;
    }*/

    while (!flujo_entrada.eof()) {
        get_polygon_from_stream(flujo_entrada, lista2);
        //lista2.cantidad_poligonos++;
    }
    show_polygons_list(lista2);
    //std::cout << lista2.puntero_a_poligono_raiz->vertex_amount;
   




    flujo_entrada.close();


 



}

