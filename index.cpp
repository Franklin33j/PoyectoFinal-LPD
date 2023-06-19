#include <iostream>
#include "clases/Gerente.h"
#include "clases/Empleado.h"
#include "clases/Director.h"
#include "clases/JefeArea.h"
#include "clases/Supervisor.h"
#include "clases/Tecnico.h"
#include "manejoArchivos/Archivo.h"
using namespace std;

void ManejadorOpciones(int);
void OrdenarPorApellido(int);
void OrdenarPorSalario(int);
int Menu();
void MostrarPorRoles(int);
void AgregarEmpleado(int);
int main()
{
    int opcion = 0;
    do
    {
        system("cls");
        cout << "Seleccione una opcion:" << endl;
        cout << "1-Ordenar empleados en orden alfabetico por primer apellido" << endl;
        cout << "2-Ordenar a los empleados por el salario Neto" << endl;
        cout << "3-Mostrar empleados por roles" << endl;
        cout << "4-Agregar empleados" << endl;
        cout << "5-Salir" << endl;
        cin >> opcion;
        if (opcion >= 1 && opcion <= 4)
        {
            system("cls");
            ManejadorOpciones(opcion);
        }

    } while (opcion != 5);
}

void ManejadorOpciones(int opcion)
{
    int opcionMenu;
    switch (opcion)
    {
    case 1:
        do
        {
            system("cls");
            cout << "Seleccione una opcion para listar los empleados por orden del primer Apellido(a-z)" << endl;
            opcionMenu = Menu();
            if (opcionMenu >= 1 && opcionMenu <= 6)
            {

                OrdenarPorApellido(opcionMenu);
            }

        } while (opcionMenu != 7);
        break;
    case 2:

        do
        {
            system("cls");
            cout << "Seleccione una opcion para listar los empleados por orden del primer Salario Neto(menor-mayor)" << endl;
            opcionMenu = Menu();
            if (opcionMenu >= 1 && opcionMenu <= 6)
            {
                OrdenarPorSalario(opcionMenu);
            }

        } while (opcionMenu != 7);

        break;
    case 3:

        do
        {
            system("cls");
            cout << "Seleccione una opcion para listar los empleados por puestos" << endl;
            opcionMenu = Menu();
            if (opcionMenu >= 1 && opcionMenu <= 6)
            {
                MostrarPorRoles(opcionMenu);
            }

        } while (opcionMenu != 7);
        break;
    case 4:
        do
        {
            system("cls");
            cout << "Seleccione una opcion para agregar un empleado por puesto" << endl;
            cout << "1-Directores" << endl;
            cout << "2-Gerentes" << endl;
            cout << "3-Jefes de Area" << endl;
            cout << "4-Supervisores" << endl;
            cout << "5-Tecnicos" << endl;
            cout << "6-Salir" << endl;
            cin>>opcionMenu;
            if (opcionMenu >= 1 && opcionMenu <= 6)
            {
                AgregarEmpleado(opcionMenu);
            }

        } while (opcionMenu != 6);
        break;
    }
    return;
}

int Menu()
{
    int opcionMenu;
    cout << "1-Directores" << endl;
    cout << "2-Gerentes" << endl;
    cout << "3-Jefes de Area" << endl;
    cout << "4-Supervisores" << endl;
    cout << "5-Tecnicos" << endl;
    cout << "6-Todos" << endl;
    cout << "7-Salir" << endl;
    cin >> opcionMenu;
    return opcionMenu;
}

void OrdenarPorApellido(int op)
{
    switch (op)
    {
    case 1:
        system("cls");
        Archivo::LeerDatosDirectores(1);
        system("pause");
        break;
    case 2:
        system("cls");
        Archivo::LeerDatosGerentes(1);
        system("pause");
        break;
    case 3:
        system("cls");
        Archivo::LeerDatosJefesArea(1);
        system("pause");
        break;
    case 4:
        system("cls");
        Archivo::LeerDatosSupervisores(1);
        system("pause");
        break;
    case 5:
        system("cls");
        Archivo::LeerDatosTecnicos(1);
        system("pause");
        break;
    case 6:
        system("cls");
        cout << "DIRECTORES\n\n"
             << endl;
        Archivo::LeerDatosDirectores(1);
        cout << "\n\nGERENTES\n"
             << endl;
        Archivo::LeerDatosGerentes(1);
        cout << "\n\nGEFES AREA\n"
             << endl;
        Archivo::LeerDatosJefesArea(1);
        cout << "\n\nSUPERVISORES\n"
             << endl;
        Archivo::LeerDatosSupervisores(1);
        cout << "\n\nTECNICOS\n"
             << endl;
        Archivo::LeerDatosTecnicos(1);
        system("pause");
        break;
    }
    return;
}
void OrdenarPorSalario(int op)
{
    switch (op)
    {
    case 1:
        system("cls");
        Archivo::LeerDatosDirectores(2);
        system("pause");
        break;
    case 2:
        system("cls");
        Archivo::LeerDatosGerentes(2);
        system("pause");
        break;
    case 3:
        system("cls");
        Archivo::LeerDatosJefesArea(2);
        system("pause");
        break;
    case 4:
        system("cls");
        Archivo::LeerDatosSupervisores(2);
        system("pause");
        break;
    case 5:
        system("cls");
        Archivo::LeerDatosTecnicos(2);
        system("pause");
        break;
    case 6:
        system("cls");
        cout << "DIRECTORES\n\n"
             << endl;
        Archivo::LeerDatosDirectores(2);
        cout << "\n\nGERENTES\n"
             << endl;
        Archivo::LeerDatosGerentes(2);
        cout << "\n\nGEFES AREA\n"
             << endl;
        Archivo::LeerDatosJefesArea(2);
        cout << "\n\nSUPERVISORES\n"
             << endl;
        Archivo::LeerDatosSupervisores(2);
        cout << "\n\nTECNICOS\n"
             << endl;
        Archivo::LeerDatosTecnicos(2);
        system("pause");
        break;
    }
    return;
}
void MostrarPorRoles(int op)
{
    switch (op)
    {
    case 1:
        system("cls");
        Archivo::LeerDatosDirectores(3);
        system("pause");
        break;
    case 2:
        system("cls");
        Archivo::LeerDatosGerentes(3);
        system("pause");
        break;
    case 3:
        system("cls");
        Archivo::LeerDatosJefesArea(3);
        system("pause");
        break;
    case 4:
        system("cls");
        Archivo::LeerDatosSupervisores(3);
        system("pause");
        break;
    case 5:
        system("cls");
        Archivo::LeerDatosTecnicos(3);
        system("pause");
        break;
    case 6:
        system("cls");
        cout << "DIRECTORES\n\n"
             << endl;
        Archivo::LeerDatosDirectores(3);
        cout << "\n\nGERENTES\n"
             << endl;
        Archivo::LeerDatosGerentes(3);
        cout << "\n\nGEFES AREA\n"
             << endl;
        Archivo::LeerDatosJefesArea(3);
        cout << "\n\nSUPERVISORES\n"
             << endl;
        Archivo::LeerDatosSupervisores(3);
        cout << "\n\nTECNICOS\n"
             << endl;
        Archivo::LeerDatosTecnicos(3);
        system("pause");
        break;
    }
    return;
}
void AgregarEmpleado(int op)
{
    switch (op)
    {
    case 1:
    {
        system("cls");
        Director *director = new Director;
        director->AgregarDirector();
        system("pause");
        delete director;
    }
    break;
    case 2:
    {
        system("cls");
        Gerente *gerente = new Gerente;
        gerente->AgregarGerente();
        system("pause");
        delete gerente;
    }
    break;
    case 3:
    {
        system("cls");
        JefeArea *jefeArea= new JefeArea;
        jefeArea->AgregarJefeArea();
        system("pause");
        delete (jefeArea);
    }
    break;
    case 4:
    {
        system("cls");
        Supervisor *supervisor = new Supervisor;
        supervisor->AgregarSupervisor();
        system("pause");
        delete supervisor;
        break;
    }
    case 5:
    {
        system("cls");
        Tecnico *tecnico = new Tecnico;
        tecnico->AgregarTecnico(); 
        system("pause");
        delete tecnico;
    }
    break;
    }
}