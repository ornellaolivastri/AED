/* Ornella Olivastri Legajo 1674201
11 / 06 / 2020
TP: isBisiesto
Dado un año, determinar si es bisiesto
*/

#include <cassert>  

bool isBisiesto(int a);  //Declaracion de la funcion isBisiesto que devuelve true si el año es bisiesto    

int main()
{
    /* Cómo saber si un año es bisiesto? (Condiciones de wikipedia) 

    Debe ser: (mayor a 1582 ∧ divisible por 4 ∧ no divisible por 100) ∨ (mayor a 1582 ∧ divisible por 4 ∧ divisible por 100 ∧ divisible por 400).  
    
              (mayor a 1582 ∧ divisible por 4) ∧ [no divisible por 100 ∨ (divisible por 100 ∧ divisible por 400)].
    
    */

    assert(isBisiesto(1581) == false);   //Menor a 1582
                  //Mayores a 1582
    assert(isBisiesto(1582) == false);   //No divisible por 4
                  //Divisibles por 4
    assert(isBisiesto(1996) == true);    //No divisible por 100
    assert(isBisiesto(1700) == false);   //Divisible por 100 y no divisible por 400
    assert(isBisiesto(1600) == true);    //Divisible por 100 y divisible por 400
}

//Definicion de la funcion isBisiesto

bool isBisiesto(int a)
{
    bool resultado;
    //         (mayor a 1582 ∧ divisible por 4) ∧ [no divisible por 100 ∨ (divisible por 100 ∧ divisible por 400)]
    resultado = ((a > 1582)  and  (a % 4 == 0)) and  (   (a % 100 != 0)   or    (a % 100 == 0  and  a % 400 == 0));
    return resultado;
    }