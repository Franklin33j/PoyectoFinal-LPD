#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

class Archivo
{

private:
    struct DatosPersona
    {
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
   
    static vector<DatosPersona> OrdenarPorApellido(vector<DatosPersona> &vec)
    {
        int n = vec.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (vec[j].apellido1[0] > vec[j + 1].apellido1[0])
                {
                    swap(vec[j], vec[j + 1]);
                }
            }
        }
        return vec;
    }
    static vector<DatosPersona> OrdenarPorSalarioNeto(vector<DatosPersona> &vec)
    {
        int n = vec.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (vec[j].SalarioNeto > vec[j + 1].SalarioNeto)
                {
                    swap(vec[j], vec[j + 1]);
                }
            }
        }
        return vec;
    }
    static void LeerArchivos(string rutaRelativa, int opcion){
        ifstream archivoEntrada(rutaRelativa, ios::in);

        if (archivoEntrada.is_open())
        {
            vector<DatosPersona> personas;
            string linea;
            while (getline(archivoEntrada, linea))
            {
                stringstream ss(linea);
                DatosPersona persona;
                ss >> persona.cod >> persona.nombre1 >> persona.nombre2 >> persona.apellido1 >> persona.apellido2 >> persona.salario >> persona.SalarioNeto >> persona.telefono >> persona.fechaNacimiento >> persona.cod >> persona.direccion;
                persona.cod = linea.substr(0, 6);
                personas.push_back(persona);
            }
            archivoEntrada.close();

            if (opcion == 1)
                personas = OrdenarPorApellido(personas);
            else if (opcion == 2)
                personas = OrdenarPorSalarioNeto(personas);

            size_t g = 0;
            cout << "Cod\t\t"
                 << "Nombre\t\t"
                 << "Nombre\t\t"
                 << "Apellido\t"
                 << "Apellido\t"
                 << "Salario($)\t\t"
                 << "SalarioNeto($)\t\t"
                 << "FechaNac" << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

            while (g < personas.size())
            {
                cout << personas[g].cod << "\t\t" << personas[g].nombre1 << "\t\t" << personas[g].nombre2 << "\t\t" << personas[g].apellido1 << "\t\t" << personas[g].apellido2 << "\t\t" << personas[g].salario << "\t\t\t" << personas[g].SalarioNeto << "\t\t\t" << personas[g].fechaNacimiento << endl;
                g++;
            }
        }
        else
        {
            cout << "No se pudo abrir el archivo para lectura." << endl;
        }
        return;
    }
public:
    static void LeerDatosDirectores(int opcion)
    {

        string rutaRelativa = "../archivos/Directores.txt";
        LeerArchivos(rutaRelativa, opcion);
        return;
    }

    static void LeerDatosGerentes(int opcion)
    {

        string rutaRelativa = "../archivos/Gerentes.txt";
        LeerArchivos(rutaRelativa, opcion);
        return;
    }
    static void LeerDatosJefesArea(int opcion)
    {
        string rutaRelativa = "../archivos/JefesArea.txt";
        LeerArchivos(rutaRelativa, opcion);
  
        return;
    }
    static void LeerDatosSupervisores(int opcion)
    {
        string rutaRelativa = "../archivos/Supervisores.txt";
        LeerArchivos(rutaRelativa, opcion);
        return;
    }
    static void LeerDatosTecnicos(int opcion)
    {
        cout<<"hiiiiiiiiiiiiiiiiiiiiiii"<<endl;
        string rutaRelativa = "../archivos/Tecnicos.txt";
        LeerArchivos(rutaRelativa, opcion);
        return;
    }

};

#endif