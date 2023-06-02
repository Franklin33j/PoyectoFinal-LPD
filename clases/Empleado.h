#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <ctime>
#include <random>
using namespace std;

class Empleado
{

private:
    struct Fecha
    {
        int año;
        int mes;
        int dia;
    };

protected:
    Empleado(){};
    /*Al declarar el constructor como protected le estoy diciendo al complidador que no
    se puede crear una instacia para esta clase mas que solo sus clases hijas*/

    string nombres;
    string apellidos;
    string direccion;
    Fecha fechaNacimiento;
    string telefono;
    char sexo;
    string codigo;
    double salario;

    double DescuentoSeguroEmpleado()
    {
        return (salario / 100) * 3;
    };
    double DescuentoAFPEmpleado()
    {
        return (salario / 100) * 7.25;
    }
    double DescuentoSeguroEmpleador()
    {
        return (salario / 100) * 7.5;
    };
    double DescuentoAFPEmpleador()
    {
        return (salario / 100) * 7.75;
    }
    // usar este metodo involucra restar el afp y iss al salario
    double CalculoRenta()
    {
        salario = salario - DescuentoSeguroEmpleado() - DescuentoAFPEmpleado();

        if (salario > 0.01 && salario <= 472.00)
        {
            cout << "salario: " << salario << endl;
            return 0.00;
        }
        else if (salario >= 472.01 && salario <= 895.24)
        {
            return this->Retencion(salario, 10, 472.00, 17.67);
        }
        else if (salario >= 895.25 && salario <= 2038.10)
        {
            return this->Retencion(salario, 20, 895.24, 60.00);
        }
        else
        {
            return this->Retencion(salario, 30, 2038.10, 288.57);
        }
    }
    double Retencion(double salario, int tasa, double excedente, double cuotaFija)
    {
        double sobreExcedente = salario - excedente;
        double producto = (sobreExcedente / 100) * tasa;
        double isr = cuotaFija + producto;
        return isr;
    }
    int generarAleatorio(int min, int max)
    {

        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> distribucion(min, max);
        int numeroAleatorio = distribucion(rng);
        return numeroAleatorio;
    }
};

#endif