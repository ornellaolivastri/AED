
// Funcion que compara doubles ----------------------------------



bool AreNear(double a, double b, double tolerancia) {
    return a >= b ? (a - b) <= tolerancia
        : (b - a) <= tolerancia;
}