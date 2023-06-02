#include "Empleado.h"
class Supervisor:Empleado{

public:
    Supervisor(){
        salario =750;
        codigo=generarAleatorio(1000, 9999);
        }
    ~Supervisor();
    void  CalculoInfo() {
    locale mylocale("");
    cout<<"Salario Empleado: $"<<salario<<endl;
    double afp=DescuentoAFPEmpleado();
    double iss=DescuentoSeguroEmpleado();
    double afpEmpleador=DescuentoAFPEmpleador();
    double issEmpleador=DescuentoSeguroEmpleador();
    double renta= CalculoRenta();
    double salarioNeto= salario-renta;

    cout<<"Descuento AFP Empleado: $ "<<afp<<endl;
    cout<<"Descuento Seguro Empleado: $"<<iss<<endl;
    cout<<"Descuento AFP al Empleador: $"<<afpEmpleador<<endl;
    cout<<"Descuento Seguro al Empleador: $"<<issEmpleador<<endl;
    cout<<"Renta a pagar: $"<<renta<<endl;
    cout<<"Seguro Neto: $"<<iss+issEmpleador<<endl;
    cout<<"AFP Neta: $"<<afp+ afpEmpleador<<endl;
    cout<<"Salario Neto: $"<<salarioNeto<<endl;
    }

    void BonoMensual(){
        //se le dara un bono al 6% de su salario
        int bono =6;
        salario=salario+((salario/100)*bono);
    }
    //setters
    void SetNombres(string nombres){
        this->nombres=nombres;
    }
    void SetApellidos(string apellidos){
        this->apellidos=apellidos;
    }
    void SetDireccion(string direccion){
        this->direccion=direccion;
    }
    void  setFechaNacimiento(int dia, int mes, int año){
        this->fechaNacimiento.año=año;
        this->fechaNacimiento.mes=mes;
        this->fechaNacimiento.dia=dia;
    }
    void setTelefono(string telefono){
        this->telefono=telefono;
    }
    void setSexo(char sexo){
        this->sexo=sexo;
    }
    
};