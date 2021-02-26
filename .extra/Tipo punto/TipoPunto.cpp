// TipoPunto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cassert>
#include <math.h> 
// #include <stdlib.h> para usar la funcion abs(a-b) valor absoluto

struct Punto { double x, y; };

Punto origen{ 0.0, 0.0 };

bool IsIgual(Punto a, Punto b);
double getDistancia(Punto a, Punto b);
double getDistanciaAlOrigen(Punto a, Punto origen);
bool AreNear(double double1, double double2, double tolerancia = 0.01);

int main()
{
    Punto p1{ 1,1 };
    Punto p2{ 1,1 };
    Punto p3{ 3,5 };
    assert(IsIgual(p1, p2));
    assert(AreNear(getDistancia(p2, p3), 4.4721));
    assert(AreNear(getDistanciaAlOrigen(p2, origen), sqrt(2)));
}

bool IsIgual(Punto a, Punto b) {
    //return (a.x == b.x) and (a.y == b.y) ? true : false ; 
    //eso es redundante, porque [(a.x==b.x)and(a.y==b.y)] ya va a valer true 
    return (a.x == b.x) and (a.y == b.y);
}

// la distancia entre puntos siempre será positiva

double getDistancia(Punto a, Punto b) {
    Punto distancia;
    distancia.x = a.x > b.x ? a.x - b.x : b.x - a.x;
    distancia.y = a.y > b.y ? a.y - b.y : b.y - a.y;
    return pow(pow(distancia.x, 2) + pow(distancia.y, 2), 0.5);
}

double getDistanciaAlOrigen(Punto a, Punto origen) {
    Punto distancia;
    distancia.x = a.x - 0;
    distancia.y = a.y - 0;
    return pow(pow(distancia.x, 2) + pow(distancia.y, 2), 0.5);
}

bool AreNear(double a, double b, double tolerancia) {
    return a >= b ? (a - b) <= tolerancia                    //si a es mayor o igual que b ? restar a - b y comprobar si la resta es menor a la tolerancia
        : (b - a) <= tolerancia;                             //                            : restar b - a y comprobar si la resta es menor a la tolerancia
}

