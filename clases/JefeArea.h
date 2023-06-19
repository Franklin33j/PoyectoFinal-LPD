#include "Empleado.h"
#include <iostream>

class JefeArea:Empleado{
public:
    JefeArea(){
        salario =1500;
         rutaArchivo = "../archivos/JefesArea.txt";
        }
    ~JefeArea(){};
   void AgregarJefeArea()
    {
         system("cls");
         cout<<"\n\nNUEVO JEFE DE AREA\n\n"<<endl;
        AgregarDatosEmpleado();
    }
    
};