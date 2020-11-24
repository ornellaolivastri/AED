//aca van las definiciones de operaciones/funciones
#pragma once
#include"color.h"

tipo_color mezcla(tipo_color color1, tipo_color color2) {
	tipo_color color_nuevo;
	color_nuevo.intensidadRed = (color1.intensidadRed + color2.intensidadRed) / 2;
	color_nuevo.intensidadGreen = (color1.intensidadGreen + color2.intensidadGreen) / 2;
	color_nuevo.intensidadBlue = (color1.intensidadBlue + color2.intensidadBlue) / 2;

	return color_nuevo;
}

tipo_color suma_colores(tipo_color color1, tipo_color color2) {
	tipo_color z;
	z.intensidadRed = color1.intensidadRed + color2.intensidadRed > 255 ? 255 : color1.intensidadRed + color2.intensidadRed;
	z.intensidadGreen = color1.intensidadGreen + color2.intensidadGreen > 255 ? 255 : color1.intensidadGreen + color2.intensidadGreen;
	z.intensidadBlue = color1.intensidadBlue + color2.intensidadBlue > 255 ? 255 : color1.intensidadBlue + color2.intensidadBlue;

	return z;
}

tipo_color resta_colores(tipo_color color1, tipo_color color2) {
	tipo_color z;
	z.intensidadRed = color1.intensidadRed - color2.intensidadRed < 0 ? 0 : color1.intensidadRed - color2.intensidadRed;
	z.intensidadGreen = color1.intensidadGreen - color2.intensidadGreen < 0 ? 0 : color1.intensidadGreen - color2.intensidadGreen;
	z.intensidadBlue = color1.intensidadBlue - color2.intensidadBlue < 0 ? 0 : color1.intensidadBlue - color2.intensidadBlue;

	return z;
}

bool IsIgual(tipo_color color1, tipo_color color2) {
	return (color1.intensidadRed == color2.intensidadRed)     and 
	       (color1.intensidadGreen == color2.intensidadGreen) and
		   (color1.intensidadBlue == color2.intensidadBlue);
}
