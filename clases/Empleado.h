#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

class Empleado
{

protected:
    Empleado(){};
    ~Empleado(){
    };
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
    double salarioNeto;
    string rutaArchivo;

private:

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

    void CalculoInfoEmpleado()
    {
        
        cout << nombre1 << " " << apellido1 << " los detalles de sus salario son:" << endl;
        cout << "Salario Empleado: $" << salario << endl;
        double afp = DescuentoAFPEmpleado();
        double iss = DescuentoSeguroEmpleado();
        double afpEmpleador = DescuentoAFPEmpleador();
        double issEmpleador = DescuentoSeguroEmpleador();
        double renta = CalculoRenta();
        salarioNeto = salario - renta-iss-afp;

        cout << "Descuento AFP Empleado: $" << fixed << setprecision(2) << afp << endl;
        cout << "Descuento Seguro Empleado: $" << iss << endl;
        cout << "Descuento AFP al Empleador: $" << afpEmpleador << endl;
        cout << "Descuento Seguro al Empleador: $" << issEmpleador << endl;
        cout << "Renta a pagar: $" << renta << endl;
        cout << "AFP + ISS + renta $" << iss + afp + renta << endl;
        cout << "Salario Neto: $" << salarioNeto << endl;
    }
     void GuardarEmpleado()
    {
        
        ofstream ArchivoSalida(rutaArchivo, ios::app);
        if (ArchivoSalida.is_open())
        {
            codigo = to_string(generarAleatorio(100000, 999999));
            stringstream stream;
            stream << fixed << setprecision(2) << salario;
            string salarioF = stream.str();
            stream.str("");
            stream << fixed << setprecision(2) << salarioNeto;
            string salarioNetoF = stream.str();
            string data = codigo + " " +  nombre1 + " " + nombre2 + " " + apellido1 + " " + apellido2 + " " + salarioF + " " + salarioNetoF + " " + telefono + " " + to_string(fechaNacimiento.dia) + "/" + to_string(fechaNacimiento.mes) + "/" + to_string(fechaNacimiento.año) + " " + direccion + "\n";
            ArchivoSalida << data;
            ArchivoSalida.close();
        }
        else
        {
            cout << "Error al leer el archivo";
        }
    }
protected:
    void AgregarDatosEmpleado()
    {
        
        cout << "Ingrese su primer Nombre " << endl;
        cin >> nombre1;
        cout << "Ingrese su segundo Nombre " << endl;
        cin >> nombre2;
        cout << "Ingrese su primer Apellido " << endl;
        cin >> apellido1;
        cout << "Ingrese su segundo Apellido " << endl;
        cin >> apellido2;
        cout << "Ingrese su sexo (M o F) " << endl;
        cin >> sexo;
        cin.ignore();
        cout << "Ingrese su direccion completa " << endl;
        getline(cin, direccion);
        cout << "Ingrese su numero de telefono" << endl;

        cin >> telefono;
        /* Se puede omitir la validacion de la
        if (telefono.length() == 8)
        {
            cout << "Ingrese su numero de telefono con 8 digitos" << endl;
            cin >> telefono;
        }*/
        cout << "Ingrese su dia de nacimiento (numero ) " << endl;
        cin >> fechaNacimiento.dia;
        cout << "Ingrese su mes  de nacimiento (numero) " << endl;
        cin >> fechaNacimiento.mes;
        cout << "Ingrese su año  de nacimiento (numero) " << endl;
        cin >> fechaNacimiento.año;

        if (apellido2.empty())
            {apellido2 = "default";}


        CalculoInfoEmpleado();
        GuardarEmpleado();
        system("pause");
    }

};

#endif