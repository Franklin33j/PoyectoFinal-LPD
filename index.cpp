#include <iostream>
#include "clases/Gerente.h"
#include "clases/Empleado.h"
using namespace std;


int main(){
  //Empleado* empleado = new Empleado();


/*Implementar Menu Principal:
    1-Mostrar Empleados(leer desde los archivos la informacion de los empleados crear clase y funciones que lean estos archivos) 
        -Preguntar el tipo a mostrar:Director, Gerente. JefeArea, Supervisor, Tecnioc, Todos
    2-Agregar Empleados
        Implementar la entrada de Empleados pedir los datos 
            1-Tipo de empleado usar switch 
            2-Pedir los datos:
                -nombres
                -apellidos
                -direccion
                -fechaNacimiento
                -telefono
                -sexo(1-Masculino 2 femenino)
            3-Guardar el empleado en el documento y mostrar la info
    3-Ordenar Empleados por sueldo:
        -preguntar el tipo a mostrar: Director, Gerente. JefeArea, Supervisor, Tecnioc, Todos
    4-Ordenar los empleados por los apellidos
         -Preguntar el tipo a mostrar:Director, Gerente. JefeArea, Supervisor, Tecnioc, Todos
     */
  Gerente* gerente =new Gerente();
  gerente->CalculoInfo();
  
  return 0;
 
}