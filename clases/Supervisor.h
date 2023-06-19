#include "Empleado.h"
#include <iostream>

class Supervisor:Empleado{

public:
    Supervisor(){
        salario =750;
       rutaArchivo = "../archivos/Supervisores.txt";
        }
    ~Supervisor(){};
    void AgregarSupervisor()
    {
         system("cls");
         cout<<"\n\nNUEVO SUPERVISOR\n\n"<<endl;
        AgregarDatosEmpleado();
    }
    
};