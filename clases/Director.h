#include "Empleado.h"
#include <iostream>

class Director : Empleado
{

public:
    Director()
    {
        salario = 1200;
        rutaArchivo = "../archivos/Directores.txt";
    }
    ~Director(){
        
    };

    void AgregarDirector()
    {
         system("cls");
         cout<<"\n\nNUEVO DIRECTOR\n\n"<<endl;
        AgregarDatosEmpleado();
    }
};