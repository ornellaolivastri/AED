//  Definiciones de funciones para tipo vertice -----------------------------------
#pragma once
#include <math.h>
#include"vertices.h"

tipo_vertice origen{ 0.0, 0.0 };  //esta variable la puse aca porque sino me sale repetida

bool IsIgual(tipo_vertice a, tipo_vertice b) {
    return (a.x == b.x) and (a.y == b.y);
}

double getDistancia(tipo_vertice a, tipo_vertice b) {
    tipo_vertice distancia;
    distancia.x = a.x > b.x ? a.x - b.x : b.x - a.x;
    distancia.y = a.y > b.y ? a.y - b.y : b.y - a.y;
    return pow(pow(distancia.x, 2) + pow(distancia.y, 2), 0.5);
}

double getDistanciaAlOrigen(tipo_vertice a, tipo_vertice origen) {
    tipo_vertice distancia;
    distancia.x = a.x - 0;
    distancia.y = a.y - 0;
    return pow(pow(distancia.x, 2) + pow(distancia.y, 2), 0.5);
}

