#include "Empleado.h"
#include <iostream>
#include <iomanip>


 class Gerente:public Empleado{

private:
public:
    Gerente(){
        salario =5000;
        codigo=generarAleatorio(1000, 9999);
        }
    ~Gerente();
    void  CalculoInfo() {
   
    cout<<"Salario Empleado: $"<<salario<<endl;
    BonoMensual();
    double afp=DescuentoAFPEmpleado();
    double iss=DescuentoSeguroEmpleado();
    double afpEmpleador=DescuentoAFPEmpleador();
    double issEmpleador=DescuentoSeguroEmpleador();
    double renta= CalculoRenta();
    double salarioNeto= salario-renta-afp-iss;

    cout<<"Descuento AFP Empleado: $"<<fixed<<setprecision(2)<<afp<<endl;
    cout<<"Descuento Seguro Empleado: $"<<iss<<endl;
    cout<<"Descuento AFP al Empleador: $"<<afpEmpleador<<endl;
    cout<<"Descuento Seguro al Empleador: $"<<issEmpleador<<endl;
    cout<<"Renta a pagar: $"<<renta<<endl;
    cout<<"Seguro Neto: $"<<iss+issEmpleador<<endl;
    cout<<"AFP Neta: $"<<afp+ afpEmpleador<<endl;
    cout<<"Salario Neto: $"<<salarioNeto<<endl;


    }
    void BonoMensual(){
        //se le dara un bono al 10% de su salario
        int bono =10;
        salario=salario+((salario/100)*bono);
    }
};