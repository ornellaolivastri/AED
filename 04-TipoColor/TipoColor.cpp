/* TipoColor.cpp : TP Nº 4 - Tipo de dato color
Fecha de comienzo del trabajo: 20-10-2020
	- Crear tipo basado en el modelo RGB con 3 canales de 8 bits
	- Cada color tiene su intensidad con rango [0,255]
	- Colores a definir: rojo, azul, verde, cyan, magenta, amarillo, negro y blanco
	- Desarrollar operacion mezclar, produciendo un nuevo color al cual corresponderá 
	  el promedio de intensidad de cada componente
	- Utilizar el tipo de dato uint8_t (sirve para las intensidades, ya que es un tipo de dato 
	que representa un numero entero (como el int), sin signo (como el unsigned, de ahi viene la u), 
	pero que solo puede almacenar numeros de 0 a 255 (o sea, lo que se pueda representar con 8 bits)

	//RGB RED GREEN BLUE   | PRIMARIOS | FF0000: RED  00FF00: GREEN  0000FF: BLUE |
*/

#include <iostream>
#include <cassert>


struct Color { uint8_t intensidadRed, intensidadGreen, intensidadBlue; };

Color Mezcla(Color x, Color y);
Color Suma(Color x, Color y);
Color Resta(Color x, Color y);
bool IsIgual(Color x, Color y);

const Color red{ 255,0,0 };
const Color green{ 0,255,0 };
const Color blue{ 0,0,255 };

const Color lightBlue{ 0,255,255 };
const Color purple{ 255,0,255 };
const Color yellow{ 255,255,0 };

const Color white{ 255,255,255 };
const Color black{ 0,0,0 };


int main(){

	Color a{ 5,20,255 };
	Color b{ 15,30,255 };
	Color c{ 10, 25, 255 };
	assert ( IsIgual(Mezcla(a, b),c));
}


Color Mezcla(Color x, Color y) {
	Color z;
	z.intensidadRed = (x.intensidadRed + y.intensidadRed) / 2;
	z.intensidadGreen = (x.intensidadGreen + y.intensidadGreen) / 2;
	z.intensidadBlue = (x.intensidadBlue + y.intensidadBlue) / 2;

	return z;
}

Color Suma(Color x, Color y) {
	Color z;
	  z.intensidadRed = x.intensidadRed   + y.intensidadRed   > 255 ? 255 : x.intensidadRed + y.intensidadRed ;
	z.intensidadGreen = x.intensidadGreen + y.intensidadGreen > 255 ? 255 : x.intensidadGreen + y.intensidadGreen;
	 z.intensidadBlue = x.intensidadBlue  + y.intensidadBlue  > 255 ? 255 : x.intensidadBlue + y.intensidadBlue;

	return z;
}

Color Resta(Color x, Color y) {
	Color z;
	z.intensidadRed = x.intensidadRed - y.intensidadRed < 0 ? 0 : x.intensidadRed - y.intensidadRed;
	z.intensidadGreen = x.intensidadGreen - y.intensidadGreen < 0 ? 0 : x.intensidadGreen - y.intensidadGreen;
	z.intensidadBlue = x.intensidadBlue - y.intensidadBlue < 0 ? 0 : x.intensidadBlue - y.intensidadBlue;

	return z;
}

bool IsIgual(Color x, Color y) {
	return (x.intensidadRed == y.intensidadRed) and (x.intensidadGreen == y.intensidadGreen) and (x.intensidadBlue == y.intensidadBlue);
}

/*
bool IsIgual(Color x, Color y){
	return (x.intensidadRed == y.intensidadRed ?
			x.intensidadGreen == y.intensidadGreen ?
			x.intensidadBlue == y.intensidadBlue ? true : false : false : false ) ;
} no conviene hacerlo asi, es redundante

Color SumaDeColores(Color x, Color y) {
	Color z;
	z.intensidadRed = x.intensidadRed + y.intensidadRed;
	z.intensidadGreen = x.intensidadGreen + y.intensidadGreen;
	z.intensidadBlue = x.intensidadBlue + y.intensidadBlue;

	z.intensidadRed > 255 ? 255 : z.intensidadRed;
	z.intensidadGreen > 255 ? 255 : z.intensidadGreen;
	z.intensidadBlue > 255 ? 255 : z.intensidadBlue;

	return z;
	no esta bien hacerlo asi porque la suma se hace primero en int y despues se vuelve uint8, 
	entonces hay que meter el condicional todo junto para que evalúe el resultado y 
	justo despues transforme -de ser necesario.
} */
