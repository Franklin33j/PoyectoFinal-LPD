#include <iostream>
#include <iomanip> // Para usar std::fixed y std::setprecision
#include <string>
#include <iostream>
#include <random>
#include "manejoArchivos/Archivo.h";

using namespace std;
int generarAleatorio(int min, int max)
{

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribucion(min, max);
    int numeroAleatorio = distribucion(rng);
    return numeroAleatorio;
}
int main()
{
    Archivo::LeerDatosDirectores(1);
    return 0;
}