#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <iostream>
#include <fstream>
using namespace std;

class Archivo
{

    private:
    struct NombreCompleto {
    string nombre1;
    string nombre2;
    string apellido1;
    string apellido2;
    string salario;
   string SalarioNeto; 
    string telefono; 
    string fechaNacimiento;
    string cod;
    string direccion;
};

public:
    static void LeerDatosDirectores()
    {
        string rutaRelativa = "../archivos/Directores.txt";
        ifstream archivoEntrada(rutaRelativa, ios::in);
 
        if (archivoEntrada.is_open())
        {

            vector<NombreCompleto> personas;
            string linea;
            while (getline(archivoEntrada, linea))
            {
                stringstream ss(linea);
                string palabra;
                NombreCompleto persona;
                ss>>persona.nombre1>>persona.nombre2>>persona.apellido1>>persona.apellido2>>persona.salario>>persona.SalarioNeto>>persona.telefono>>persona.fechaNacimiento>>persona.cod>>persona.direccion;
               personas.push_back(persona);
              
            }
            archivoEntrada.close();
            size_t i = 0;
            while (i < personas.size())
            {
                cout << personas[i].nombre1 << endl;
                cout << personas[i].nombre2 << endl;
                cout << personas[i].apellido1<< endl;
                cout << personas[i].apellido2<< endl;
                cout<<"---------------------------"<<endl;
                i++;
            }
        }
        else
        {
            cout << "No se pudo abrir el archivo para lectura." << endl;
        }
        return;
    }

    static void LeerDatosGerentes()
    {
        int cont = 0;
        string rutaRelativa = "../archivos/Gerentes.txt";
        ifstream archivoEntrada(rutaRelativa, ios::in);
        if (archivoEntrada.is_open())
        {
            string linea;
            while (getline(archivoEntrada, linea))
            {
                cout << linea << endl;
            }
            archivoEntrada.close();
        }
        else
        {
            cout << "No se pudo abrir el archivo para lectura." << endl;
        }
        return;
    }
    static void LeerDatosJefesArea()
    {
        string rutaRelativa = "../archivos/JefesArea.txt";
        ifstream archivoEntrada(rutaRelativa, ios::in);
        if (archivoEntrada.is_open())
        {
            string linea;
            while (getline(archivoEntrada, linea))
            {
                cout << linea << endl;
            }
            archivoEntrada.close();
        }
        else
        {
            cout << "No se pudo abrir el archivo para lectura." << endl;
        }
        return;
    }
    static void LeerDatosSupervisores()
    {
        string rutaRelativa = "../archivos/Supervisores.txt";
        ifstream archivoEntrada(rutaRelativa, ios::in);
        if (archivoEntrada.is_open())
        {
            string linea;
            while (getline(archivoEntrada, linea))
            {
                cout << linea << endl;
            }
            archivoEntrada.close();
        }
        else
        {
            cout << "No se pudo abrir el archivo para lectura." << endl;
        }
        return;
    }
    static void LeerDatosTecnicos()
    {
        string rutaRelativa = "../archivos/Tecnicos.txt";
        ifstream archivoEntrada(rutaRelativa, ios::in);
        if (archivoEntrada.is_open())
        {
            string linea;
            while (getline(archivoEntrada, linea))
            {
                cout << linea << endl;
            }
            archivoEntrada.close();
        }
        else
        {
            cout << "No se pudo abrir el archivo para lectura." << endl;
        }
        return;
    }
};
#endif