## Ornella Olivastri - Legajo 1674201 - Curso K1051 - Año 2020 
---
## TP 4 - Tipo de dato Color
---
### Etapa 1: Análisis del problema
#### Enunciado
- Crear tipo basado en el modelo RGB con 3 canales de 8 bits
- Cada color tiene su intensidad con rango [0,255]
- Colores a definir: rojo, azul, verde, cyan, magenta, amarillo, negro y blanco
- Desarrollar una funcion que mezcle colores, produciendo uno nuevo al cual corresponderá el promedio de intensidad de cada componente

#### Restricciones
- No definir getters y setters especiales para las operaciones de proyeccion. 
- Usar el tipo uint8_t de cstdint (o en su defecto usar unsigned char) 
- Los colores primarios, secundarios, negro y blanco deben implementarse como 8 variables declaradas fuera del main y de toda funcion con el calificador const para que no puedan modificarse.
- Implementar la operación IsIgual que retorne true si un color es igual a otro, y sino false. 

#### Hipotesis de trabajo
1. Los tipos de datos estan definidos por dos cosas principales: su conjunto de valores y las operaciones asociadas a ese conjunto de valores.
2. En el enunciado del TP se nos mencionan 3 funciones iniciales a implementar: mezcla, suma y resta de colores. Esas serán 3 de las operaciones asociadas al conjunto tipo color.
3. El conjunto tipo color tendrá todos los colores que se pueden generar con los componentes del sistema RGB.
4. El sistema RGB se basa en que cada color tiene un porcentaje de ROJO, uno de VERDE y otro de AZUL, y que la conjunción de estos valores (llamados colores primarios) generarán a todos los demás. 
5. De lo anterior podemos deducir que cada elemento del conjunto color (o sea, cada color) estará compuesto por 3 elementos internos: intensidad de Rojo, intensidad de Verde e intensidad de Azul.

#### Modelo IPO (con su léxico): 
![](IPO.PNG)

---
### Etapa 2: Diseño de la solucion
Para comenzar a diseñar hay que tener en cuenta el objetivo del programa: crear e implementar el tipo de dato Color, el cual debe estar basado en el modelo RGB con 3 canales de 8 bits, que representa la intensidad de cada componente con el rango [0,255]. Para ello voy a necesitar un conjunto de valores y operaciones asignadas a él con el que trabajar. En el enunciado, se nos indica que creemos una función que mezcle los colores haciendo el promedio de las intensidades; por lo tanto esa sería la primera de las operaciones. Luego se nos mencionan otras dos, suma y resta de colores, con lo cual ya tenemos 3. 
El conjunto de valores del tipo Color serán todos los colores que podemos formar, y como hipítesis sabemos que cada color tendrá a su vez 3 componentes internas. Por eso, voy a definir cada color posible matemáticamente como un vector (para C++, un struct o array) para indicar las intensidades de cada color primario: ROJO, VERDE Y AZUL.

#### Definición para C++ del conjunto:

struct Color { uint8_t intensidadRed, intensidadGreen, intensidadBlue; };

#### Definición para C++ de las funciones:
    
	Color Mezcla(Color x, Color y) {
	    Color z;
	    z.intensidadRed = (x.intensidadRed + y.intensidadRed) / 2;
	    z.intensidadGreen = (x.intensidadGreen + y.intensidadGreen) / 2;
	    z.intensidadBlue = (x.intensidadBlue + y.intensidadBlue) / 2;
	    return z;
	    }
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
        z.intensidadRed = x.intensidadRed   - y.intensidadRed   > 255 ? 255 : x.intensidadRed - y.intensidadRed ;
	    z.intensidadGreen = x.intensidadGreen - y.intensidadGreen > 255 ? 255 : x.intensidadGreen - y.intensidadGreen;
	    z.intensidadBlue = x.intensidadBlue  - y.intensidadBlue  > 255 ? 255 : x.intensidadBlue - y.intensidadBlue;
        return z;
}








