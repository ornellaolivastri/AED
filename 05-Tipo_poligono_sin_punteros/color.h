// Tipo de dato color y algunos colores

#pragma once
#include <iostream> //lo necesito para el tipo uint8_t

/* El tipo de dato uint8_t sirve para las intensidades, ya que representa un numero natural 
   que solo puede almacenar numeros de 0 a 255 (o sea, lo que se pueda representar con 8 bits) */

struct tipo_color { uint8_t intensidadRed, intensidadGreen, intensidadBlue; };

const tipo_color red{ 255,0,0 };
const tipo_color green{ 0,255,0 };
const tipo_color blue{ 0,0,255 };

const tipo_color cyan{ 0,255,255 };
const tipo_color magenta{ 255,0,255 };
const tipo_color yellow{ 255,255,0 };

const tipo_color white{ 255,255,255 };
const tipo_color black{ 0,0,0 };


// Prototipos ----------------------------------------------------

tipo_color mezcla(tipo_color color1, tipo_color color2);

tipo_color suma_colores(tipo_color color1, tipo_color color2);

tipo_color resta_colores(tipo_color color1, tipo_color color2);

bool IsIgual(tipo_color color1, tipo_color color2);
