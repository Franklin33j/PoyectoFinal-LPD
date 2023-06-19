#include "Empleado.h"
#include <iomanip>
#include <iostream>
#include <fstream>
class Director : Empleado
{

public:
    Director()
    {
        salario = 1200;
    }
    ~Director(){};

private:
    double salarioNeto;
    Fecha fechaNacimiento;
    void CalculoInfo()
    {
        ofstream ArchivoSalida("../archivos/Directores.txt", ios::app);

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

    void GuardarDirector()
    {
        
        ofstream ArchivoSalida("../archivos/Directores.txt", ios::app);
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

public:
    void AgregarDirector()
    {
         system("cls");
        cout<<salario;
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


        CalculoInfo();
        GuardarDirector();
        system("pause");
    }
};