/* Ornella Olivastri Legajo 1674201
28 / 04 / 2020
TP: Tipos de Datos
Diseñar un programa C++ que ejemplifique la aplicación de los tipos de datos vistos en clases. */

/* Los tipos de datos son: conjuntos de valores y operaciones cerradas posibles sobre esos valores.
Por lo tanto, imponen restricciones sobre qué valores y operaciones pueden realizarse sobre los conjuntos. */

/* Tipos de datos basicos en C++ vistos en clase:
char - string - bool - int - unsigned - double - unsigned   */

//Bibliotecas
#include <iostream>    // para poder usar funciones basicas de c++
#include<string>       // para poder hacer cadenas -> string
#include <math.h>      // para hacer la potecia -> funcion pow()
#include<assert.h>     // para usar la funcion assert -> assert()   
//#include<conio.h>      // para usar la funcion invertir cadena -> strrev()    || no pude usarla
//#include<cstring>    // hubiera sido necesaria para usar la funcion concatenar -> strcat()  ||  AL FINAL strcat() NO FUNCIONA SI AÑADO ESTA BIBLIOTECA

int ascii(char letra)        //Funcion que recibe valores tipo char y devuelve valores tipo int
{
    int valorASCII = letra;
    return valorASCII;
}

int main()
{
    //Tipo de dato char: un caracter
    char caracter1 = '&', caracter2 = 'a', caracter3 = 'A', caracter4 = '3';
    std::cout << "Ejemplos de datos de tipo char (caracter): " << caracter1 << ", " << caracter2 << ", " << caracter3 << " y " << caracter4 << ".\n";
    //Operaciones que pueden efectuarse en este tipo: concatenacion, dar valor ascii    
    std::cout << "Operaciones que pueden efectuarse en este tipo:" << '\n';
    std::cout << "Valores ASCII de los caracteres ejemplo respectivamente: " << ascii(caracter1) << ", " << ascii(caracter2);
    std::cout << ", " << ascii(caracter3) << " y " << ascii(caracter4) << ".\n";
    assert(ascii(caracter1) == 38);
    assert(ascii(caracter2) == 97);
    assert(ascii(caracter3) == 65);
    assert(ascii(caracter4) == 51);
    std::cout << "Concatenar: " << caracter1 << caracter2 << caracter3 << caracter4 <<". \n";  // Hay alguna funcion que concatene chars?
    
    /*std::cout << "Concatenacion: " << caracter1 + caracter2 + caracter3 + caracter4 <<std::endl;  Esto no concatena, sino que suma los valores ascii de cada caracter
    
    Otra opcion para concatenar char es usar la funcion strcat que concatena arrays de char y NO STRINGS. Almacena el nuevo arreglo donde estaba el primero.
    char caracter1[50] = { "&" }, caracter2[50] = { "a" }, caracter3[50] = { "A" }, caracter4[50] = { "3" };
    std::cout << "Ejemplos de datos de tipo char array: " << caracter1 << " y " << caracter2 << ".\n";
    strcat_s(caracter1, caracter2);
    std::cout << "Se pueden concatenar: " << caracter1 << std::endl;
    assert(caracter1 == {&a}); /--???---/     */
    
    std::cout << "\n";                      
    
    //__________________________________________________________________________________________________________________________________________________

    //Tipo de dato string: secuencias de caracteres  |  Acá debí añadir la libreria <string> y llamar a la standar (std) para poder usar el string
    std::string cadena1 = ("cadena!"), cadena2 = ("de-caracteres!");
    std::cout << "Ejemplos de datos de tipo string (cadena): " << cadena1 << " y " << cadena2 << ".\n";

    //Operaciones que pueden efectuarse en este tipo: concatenacion, inversion
    std::cout << "Operaciones que pueden efectuarse en este tipo:" << '\n';
    std::cout << "Se pueden concatenar: " << cadena1 + cadena2 << ".\n";        //SE PODIAN CONCATENAR CON UNA SUMAAA
    std::string concatenacion = cadena1 + cadena2;
        
    /*std::cout << "Se puede saber la cantidad de caracteres que ocupa una cadena: " << cadena1.length() << ".\n";                      No funcionó
    strrev(cadena1);                                                                                                                      sospecha
    std::cout << "Se pueden invertir (por ejemplo, la primer cadena): " << strrev(cadena1);                                   no funciona con datos tipo string
    std::cout << ". Esto puede ser util para comprobar si un numero es capicua, o si una palabra es polindroma. \n";            sino con arrays de caracteres
    */

    assert(concatenacion == "cadena!de-caracteres!");
    std::cout << "\n";

    //__________________________________________________________________________________________________________________________________________________

    //Tipo de dato bool: dos posibles valores (true or false, on or off, high or low)
    bool verdadero = 1, falso = 0;
    std::cout << "Los dos valores pertenecientes al conjunto de datos de tipo boole (true or false, on or off, high or low) son: " << verdadero << " y " << falso << ". \n";
    //Operaciones que pueden efectuarse en este tipo: comprobacion de estados (si un condicional se cumple o no)
    std::cout << "Operaciones que pueden efectuarse en este tipo: comprobacion de estados (por ejemplo, si una situacion ocurrira o no, o el valor de verdad de una sentencia. \n";
    std::cout << "Por ejemplo, si tengo un auto con nafta pero nadie esta acelerandolo, se movera? \n";
    bool nafta = true;
    bool acelerando = false;
    bool coche_avanza = nafta & acelerando;
    std::cout << coche_avanza << '\n'; //Como el resultado cerá falso, se mostrará un 0. 
    //En caso de querer mostrar que el resultado es falso con una palabra, por ejemplo false, hay que usar un condicional
    if (coche_avanza == true)
    {
        std::cout << "True \n";
    }
    else
    {
        std::cout << "False \n";
    }
    //assert(coche_avanza == "False \n");   Esta opcion no funciona porque los tipos de operando no son compatibles (bool y char) porque coche_avanza es de tipo bool dah
    assert(coche_avanza == false);
    std::cout << "\n";

    //__________________________________________________________________________________________________________________________________________________

    //Tipo de dato int: un numero entero
    int entero1 = 5; int entero2 = 2;
    std::cout << "Ejemplos de datos de tipo int (entero): " << entero1 << " y " << entero2 << ".\n";
    //Operaciones que pueden efectuarse en este tipo: suma, resta, multiplicacion
    std::cout << "Operaciones que pueden efectuarse en este tipo:" << "\n";
    int suma, resta, multiplicacion, division1, potencia1;
    suma = entero1 + entero2;
    std::cout << "Se pueden sumar: " << suma << ".\n";
    resta = entero1 - entero2;
    std::cout << "Se pueden restar: " << resta << ".\n";
    multiplicacion = entero1 * entero2;
    division1 = entero1 / entero2;
    potencia1 = pow(entero1, -2);
    std::cout << "Se pueden multiplicar: " << multiplicacion << ".\n";
    std::cout << "Estas operaciones mencionadas son cerradas, lo cual indica que los resultados son del mismo tipo que los operandos.\n";
    std::cout << "Por ejemplo, en el caso de la division y la potenciacion, ciertos resultados no seran precisos, ya que estas operaciones no son cerradas en enteros.\n";
    std::cout << "Su division resulta: " << division1 << " y la potencia del primer entero con numero negativo (por ejemplo -2) resulta: " << potencia1;
    std::cout << ". (No se estan mostrando los decimales).\n";
    std::cout << "Para efectuar correctamente esta operacion debemos usar el tipo de dato flotante double." << '\n';
    assert(suma == 7);
    assert(resta == 3);                       //Tuve que ponerle 1 a la division y a la potencia porque tuve que hacer la operacion tambien en doubles 
    assert(multiplicacion == 10);             //entonces iba a repetirse el nombre de la variable
    assert(division1 == 2);
    assert(potencia1 == 0);
    std::cout << '\n';

    //__________________________________________________________________________________________________________________________________________________

    //Tipo de dato double: un numero de tipo flotante (enteros con valores entre 0 y 1)
    double flotante1 = 5; double flotante2 = 2;
    std::cout << "Ejemplos de datos de tipo double (flotante): " << flotante1 << " y " << flotante2 << ". (Aqui los valores fueron indicados como tipo double)\n";
    //Operaciones que pueden efectuarse en este tipo: suma, resta, multiplicacion, division, potencia
    double division2, potencia2;
    division2 = flotante1 / flotante2;
    potencia2 = pow(flotante1, -2);
    std::cout << "Se pueden sumar, restar y multiplicar al igual que los enteros, pero a diferencia de ellos los resultados de divisiones y potencias siempre seran precisos.\n";
    std::cout << "Su division resulta: " << division2 << " y la potencia del primer flotante con numero negativo (por ejemplo -2) resulta: " << potencia2 << ".\n";
    assert(division2 == 2.5);
    assert(potencia2 == 0.04);
    std::cout << '\n';

    //__________________________________________________________________________________________________________________________________________________

    //Tipo de dato unsigned: determina los tamaños que tendran los espacios donde se almacenaran los datos https://www.youtube.com/watch?v=VTI61rhTcLE
    unsigned int noSignado1 = 0, noSignado2 = 5, noSignado3 = 429496967295;   //El noSignado3 es el maximo numero que puede ser almacenado en este tipo
    std::cout << "Ejemplos de datos de tipo unsigned: " << noSignado1 << ", " << noSignado2 << " y " << noSignado3 << ".\n";
    std::cout << "Las operaciones posibles dependeran del tipo de dato unsigned que estemos utilizando. Se aplicaran las operaciones mencionadas anteriormente.";
    std::cout << '\n';
    
    //getch(); tambien se puede usar para dar una pausa antes de que termine el programa y que debamos tocar alguna tecla para que se cierre la ventana de la ejecucion
    system("pause");
    return 0;
}
