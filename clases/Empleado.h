#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <ctime>
#include <random>
using namespace std;

class Empleado
{

protected:
    Empleado(){};
    /*Al declarar el constructor como protected le estoy diciendo al complidador que no
    se puede crear una instacia para esta clase mas que solo sus clases hijas*/
    struct Fecha
    {
        int año;
        int mes;
        int dia;
    };
    string nombre1;
    string nombre2;
    string apellido1;
    string apellido2;
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
         double salRenta = salario - DescuentoSeguroEmpleado() - DescuentoAFPEmpleado();

        if (salRenta > 0.01 && salRenta <= 472.00)
        {
            cout << "salario: " << salRenta << endl;
            return 0.00;
        }
        else if (salRenta >= 472.01 && salRenta <= 895.24)
        {
            return this->Retencion(salRenta, 10, 472.00, 17.67);
        }
        else if (salRenta >= 895.25 && salRenta <= 2038.10)
        {
            return this->Retencion(salRenta, 20, 895.24, 60.00);
        }
        else
        {
            return this->Retencion(salRenta, 30, 2038.10, 288.57);
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
        
        random_device rd;
        mt19937 rng(rd());
        uniform_int_distribution<int> distribucion(min, max);
        int numeroAleatorio = distribucion(rng);
        return numeroAleatorio;
    }
};

#endif