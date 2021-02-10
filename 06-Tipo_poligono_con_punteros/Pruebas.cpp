#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include "Poligonos_con_Punteros_Junto2.h"

int main() {

    Polygon poligono1;
    inicializacion_de_Poligono(poligono1, cyan);
    show_poligono(poligono1);

    add_vertice_al_final(poligono1, 50.1, 310.2);
    std::cout << "Primer vertice:"; show_vertice(poligono1, 0);


    add_vertice_al_final(poligono1, 5.5, 450.6);
    add_vertice_al_final(poligono1, 7.3, 470.4);

    std::cout << "Segundo vertice:"; show_vertice(poligono1, 2);
    std::cout << "Tercer vertice:"; show_vertice(poligono1, 3);

    show_poligono(poligono1); std::cout << std::endl;

    cambiar_datos_del_vertice(poligono1, 0, 300.9, 350.9);
    std::cout << "Ahora, el primer vertice es:"; show_vertice(poligono1, 0);

    add_vertice_al_final(poligono1, 470.7, 480.8);

    std::cout << "Agrego otro vertice, y entonces ahora.. \n";
    show_poligono(poligono1);


    Polygon poligono2;
    inicializacion_de_Poligono(poligono2, green);
    cambiar_datos_del_vertice(poligono2, 0, 300.9, 35.9);
    add_vertice_al_final(poligono2, 300, 100);
    add_vertice_al_final(poligono2, 100, 300);
    add_vertice_al_final(poligono2, 400, 300);
    add_vertice_al_final(poligono2, 400, 100);


    Polygon poligono3;
    inicializacion_de_Poligono(poligono3, red);
    cambiar_datos_del_vertice(poligono3, 0, 200.9, 34.9);
    add_vertice_al_final(poligono3, 100, 100);
    add_vertice_al_final(poligono3, 100, 200);
    add_vertice_al_final(poligono3, 200, 190);
    add_vertice_al_final(poligono3, 200, 100);

    remove_vertice(poligono3, 4);
    remove_vertice(poligono3, 0);

    show_poligono(poligono3);

    assert(AreNear(getPerimetro(poligono3), 449.093, 0.001));

    Polygon cuadrado1;
    inicializacion_de_Poligono(cuadrado1, magenta);
    cambiar_datos_del_vertice(cuadrado1, 0, 5, 5);
    add_vertice_al_final(cuadrado1, 10, 5);
    add_vertice_al_final(cuadrado1, 10, 10);
    add_vertice_al_final(cuadrado1, 5, 10);

    Polygon cuadrado2;
    inicializacion_de_Poligono(cuadrado2, yellow);
    cambiar_datos_del_vertice(cuadrado2, 0, 25, 25);
    add_vertice_al_final(cuadrado2, 30, 25);
    add_vertice_al_final(cuadrado2, 30, 30);
    add_vertice_al_final(cuadrado2, 25, 30);

    Polygon cuadrado3;
    inicializacion_de_Poligono(cuadrado3, black);
    cambiar_datos_del_vertice(cuadrado3, 0, 45, 45);
    add_vertice_al_final(cuadrado3, 50, 45);
    add_vertice_al_final(cuadrado3, 50, 50);
    add_vertice_al_final(cuadrado3, 45, 50);

    PolygonsList lista1;
    inicializacion_de_PolygonList(lista1, yellow);
    cambiar_datos_del_vertice(*lista1.puntero_a_poligono_raiz, 0, 45, 45);
    add_poligono_al_final(lista1, cuadrado1);
    add_poligono_al_final(lista1, cuadrado2);
    add_poligono_al_final(lista1, cuadrado3);
    show_polygons_list(lista1);

    PolygonsList lista3;
    add_poligono_al_final(lista3, cuadrado1);
    show_polygons_list(lista3);



    //Dibujo SVG -----------------------------------------------------------------------

    std::ofstream dibujin("dibujo_de_poligonos_SVG.html");

    dibujin << " <!DOCTYPE html> <html> <body><svg height = \"500\" width = \"500\">";
    dibujin << "<svg height = \"500\" width = \"500\"> ";

    dibujin << "<polygon points = \"" << show_vertice_para_svg(poligono1) << "\" style = \"fill:" << get_color_for_svn(poligono1.color) << "; stroke:black;stroke-width:1\"/>";

    dibujin << "<polygon points = \"" << show_vertice_para_svg(poligono2) << "\" style = \"fill:" << get_color_for_svn(poligono2.color) << "; stroke:black;stroke-width:1\"/>";

    dibujin << "<polygon points = \"" << show_vertice_para_svg(poligono3) << "\" style = \"fill:" << get_color_for_svn(poligono3.color) << "; stroke:black;stroke-width:1\"/>";

    dibujin << "<polygon points = \"" << show_vertice_para_svg(cuadrado1) << "\" style = \"fill:" << get_color_for_svn(cuadrado1.color) << "; stroke:black;stroke-width:1\"/>";

    //<text x = "0" y = "15" fill = "red">I love SVG!< / text>

    dibujin << "Sorry, you are an ass :C </svg> </body> </html>";

    //-----------------------------------------------------------------------------------------------------------


    /*

    // Output to file -------------------------------------------------------------------------------------------

    std::ofstream flujo_salida("flujo_salida.txt"); //inicio del flujo de salida

    for (unsigned i = 0; i < lista1.cantidad_poligonos; i++) {
        give_polygon(flujo_salida,*(get_polygon ( lista1, i ))    );
    }

    flujo_salida.close();

    */

    // Entry from file  --------------------------------------------------------------------------------------------

    /*
    PolygonsList lista2;
    inicializacion_de_PolygonList(lista2, white);

    std::ifstream flujo_entrada("flujo_entrada.txt");    //inicio del flujo de entrada

   
    Color color_stream;
    
    get_polygons_color_from_stream(flujo_entrada, color_stream);

    unsigned vertex_amount;

    get_polygons_amount_from_stream(flujo_entrada, vertex_amount);

    Vertex vertex_stream;

    for (unsigned i = 0; i < vertex_amount; ++i) {
        get_vertex_from_stream(flujo_entrada, vertex_stream);
        add_vertice_al_final 
    }

    get_vertex_from_stream(flujo_entrada, vertex_stream);
    

    
    for (unsigned i = 0; get_polygon_from_stream(flujo_entrada, *(get_polygon(lista2, i))); i++) {
        lista2.cantidad_poligonos++;
        new poligono
    }
    */




    //ESTO ES PARA CONFIRMAR QUE LO QUE EXTRAEMOS ES LO QUE QUEREMOS ---------------------

    /*   for (unsigned n = 0; n < lista2.cantidad_poligonos; n++) {
        std::cout << std::endl << "El color del poligono es :" << "(" 
            << (unsigned) (get_polygon(lista2, n) ) ->color.intensidadRed << ","
            << (unsigned) (get_polygon(lista2, n)) -> color.intensidadGreen << "," 
            << (unsigned) (get_polygon(lista2, n)) -> color.intensidadBlue << ")";

        for (unsigned i = 0; i < get_polygon(lista2, n) -> vertex_amount ; i++) {
            
            std::cout << std::endl << "vertices: " << get_vertice ( *get_polygon(lista2, n), i)->vertex_coordinates.x 
                                                   << "," 
                                                   << get_vertice(*get_polygon(lista2, n), i)->vertex_coordinates.y;

        }
        
        std::cout << "\n";

    }

   

    flujo_entrada.close();
  

 */
    
    

}

