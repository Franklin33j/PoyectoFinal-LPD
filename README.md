# Detalles Proyecto  para Logica de Programacion LPD135

## SO recomendado

``` system("cls ") ``` no existe por lo que en SO Linux no generara el comportamiento esperado(borrar la consola), o si se quisiera usar se deberia cambiar todas las lineas a: ``` system("clear ") ```

## General 

El proyecto consiste en listar y registrar empleados de acuerdo a sus posiciones, el salario ya esta establecido por defecto para cada posicion.Las posiciones de trabajo son:
- Director
- Gerente
- JefeArea
- Supervisor
- Tecnico
 
Los archivos .txt tienen la siguiente estructura respecto a la columnas:

cod| Nombre1| Nombre2| Apellido1| Apellido2|  salario| salarioNeto| FechaNacimiento|  Telefono| Direccion

Cada puesto tiene atribtos en comun de la clase empleado pero implementan funcionalidades diferentes

## Registro de empleados

Para registrar un empleado se debe considerar:
- Ingresar nombres y apellidos  puede generar un problema en la estructura del archivo si no se trata, por ejemplo: para los nombres: **Maria de los Angeles**, como primer nombre: **Maria** y segundo nombre: **de los angeles**.En este caso el segundo nombre generaria problemas por lo que una solucion posible es: **de-los-Angeles** para evitar comportamiento inesperados al visualizar los datos.

- Ingresar la edad solo con numeros, tener cuidado de no ingresar ningun  otro caracter alfanumerico.

-Ingresar el sexo en M o F, una sola letra
