## Ornella Olivastri - Legajo 1674201 - Curso K1051 - Año 2020
---
## TP 02-EjemploTipos
---
### Etapa 1: Análisis del problema
#### Enunciado
 Escribir un programa que ejemplifique el uso de los tipos de datos basicos de C++ vistos en clase:
- int - char - double - string - bool - unsigned

#### Restricciones
No extraer valores de cin, usar valores literales (constantes)

#### Hipotesis de trabajo
1. El problema a resolver es hallar una forma de expresar de forma clara y correcta la aplicacion de los tipos de datos, cumpliendo con las restricciones y recomendaciones del trabajo.
1. Los tipos de datos son conjuntos de valores y operaciones cerradas posibles sobre esos valores. Que las operaciones sean cerradas impone restricciones sobre qué valores y operaciones pueden realizarse sobre cada conjunto.
2. Las operaciones entre valores de un tipo de dato ejemplifican la aplicacion de los tipos de datos.

#### Modelo IPO

![](modelo%20IPO.PNG)


#### Creditos extra
1. **No utilizar cout**. En mi caso no seguí esta recomendación porque interpreté que *"el programa debe ejemplificar el uso de tipos de datos"* significaba que la ejecución debía mostrar el uso de datos por pantalla, lo cual no era así (pensé que *"programa"* era lo que se mostraba por pantalla al ejecutar el código, y no el código en sí).
2. Utilizar la funcion assert.
3. **Responder: ¿son estos realmente todos los tipos que vimos en clase?** No lo son, ya que en clase nombramos muchos tipos de datos, con valores pertenecientes a multiples conjuntos asociados a diversas operaciones. Concluimos que todo tipo de información puede ser un tipo de dato.

---
### Etapa 2: Diseño de la solucion
Para comenzar a diseñar hay que tener en cuenta el objetivo del programa: ejemplificar el uso de los tipos de datos. Para ello primero pensé en las cosas que voy a necesitar: valores de ejemplo pertenecientes a un conjunto y operaciones que sean cerradas en él. Separé mi programa en secciones que analizan cada tipo de dato, dando ejemplos y realizando una o dos operaciones posibles.

### Representaciones del algoritmo utilizado

##### Escrita
1. Ver listado de tipos de dato indicados por el profe
2. Elegir un tipo de dato que me falte ejemplificar
3. Mencionar el tipo de dato
4. Mostrar las operaciones que se pueden realizar con él
5. Elegir pruebas y comprobar con assert.
6. ¿Falta ejemplificar algún tipo de dato?
7. Si la respuesta es sí, volver al punto 2.
8. Si la respuesta es no, terminar el programa.

##### Visual

![](representacion%20visual%20del%20algoritmo.PNG)
