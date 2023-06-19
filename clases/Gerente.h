#include "Empleado.h"
#include <iostream>

class Gerente : public Empleado
{

public:
    Gerente()
    {
        salario = 5000;
        rutaArchivo = "../archivos/Gerentes.txt";
    }
    ~Gerente(){};
   void AgregarGerente()
    {
         system("cls");
         cout<<"\n\nNUEVO GERENTE\n\n"<<endl;
        AgregarDatosEmpleado();
    }
};