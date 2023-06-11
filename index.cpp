#include <iostream>
#include "clases/Gerente.h"
#include "clases/Empleado.h"
#include "clases/Director.h"
#include "manejoArchivos/Archivo.h"
using namespace std;

void ManejadorOpciones(int);
void OrdenarPosiciones(int);

int main()
{
    Empleado* emp=new Gerente;
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
            cout << "Seleccione una opcion para listar los empleados por apellido" << endl;
            cout << "1-Directores" << endl;
            cout << "2-Gerentes" << endl;
            cout << "3-Jefes de Area" << endl;
            cout << "4-Supervisores" << endl;
            cout << "5-Tecnicos" << endl;
            cout << "6-Todos" << endl;
            cout << "7-Salir" << endl;
            cin >> opcionMenu;
            if (opcionMenu >= 1 && opcionMenu <= 6)
            {
               
                OrdenarPosiciones(opcionMenu);
            }
        } while (opcionMenu == 7);

        break;
    case 2:

        do
        {
            system("cls");
            cout << "Seleccione una opcion para listar los empleados por salario" << endl;
            cout << "1-Directores" << endl;
            cout << "2-Gerentes" << endl;
            cout << "3-Jefes de Area" << endl;
            cout << "4-Supervisores" << endl;
            cout << "5-Tecnicos" << endl;
            cout << "6-Todos" << endl;
            cout << "7-Salir" << endl;
            cin >> opcionMenu;
            if (opcionMenu >= 1 && opcionMenu <= 6)
            {
                OrdenarPosiciones(opcionMenu);
            }

        } while (opcion == 7);

        break;
    case 3:

        break;
    case 4:

        break;

       
    }
    return;
}

void OrdenarPosiciones(int op)
{
    switch (op)
    {
    case 1:
    system("cls");
       
        system("pause");
        break;
    case 2:
    system("cls");
        Archivo::LeerDatosGerentes();
        break;
    case 3:
    system("cls");
        Archivo::LeerDatosJefesArea();
        break;
    case 4:
    system("cls");
        Archivo::LeerDatosSupervisores();
        break;
    case 5:
    system("cls");
        Archivo::LeerDatosTecnicos();
        break;
        case 6:
    system("cls");

     Archivo::LeerDatosDirectores();

    Archivo::LeerDatosGerentes();
    Archivo::LeerDatosJefesArea();
    Archivo::LeerDatosSupervisores();
        Archivo::LeerDatosTecnicos();
        break;
    }
    return;
    
}
