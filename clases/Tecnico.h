#include "Empleado.h"
#include <iostream>

class Tecnico:Empleado{

public:
    Tecnico(){
        salario =350;
        rutaArchivo = "../archivos/Tecnicos.txt";
        }
    ~Tecnico(){};
    void AgregarTecnico()
    {
         system("cls");
         cout<<"\n\nNUEVO TECNICO\n\n"<<endl;
        AgregarDatosEmpleado();
    }

};