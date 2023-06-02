#include <iostream>
#include <vector>
#include <algorithm>

// Clase base Empleado
class Empleado {
protected:
    std::string nombre;
    std::string direccion;
    std::string fechaNacimiento;
    std::string sexo;
public:
    Empleado(const std::string& nombre, const std::string& direccion, const std::string& fechaNacimiento, const std::string& sexo)
        : nombre(nombre), direccion(direccion), fechaNacimiento(fechaNacimiento), sexo(sexo) {}

    virtual ~Empleado() {}

    virtual double calcularSalario() const = 0;

    // Getters
    std::string getNombre() const { return nombre; }
    std::string getDireccion() const { return direccion; }
    std::string getFechaNacimiento() const { return fechaNacimiento; }
    std::string getSexo() const { return sexo; }
};

// Clase Gerente
class Gerente : public Empleado {
private:
    double sueldo;
public:
    Gerente(const std::string& nombre, const std::string& direccion, const std::string& fechaNacimiento, const std::string& sexo)
        : Empleado(nombre, direccion, fechaNacimiento, sexo), sueldo(5000) {}

    double calcularSalario() const override {
        double descuentos = sueldo * (0.075 + 0.0775); // ISSS (7.5%) + AFP (7.75%)
        return sueldo - descuentos;
    }
};

// Clase Técnico
class Tecnico : public Empleado {
private:
    double sueldo;
public:
    Tecnico(const std::string& nombre, const std::string& direccion, const std::string& fechaNacimiento, const std::string& sexo)
        : Empleado(nombre, direccion, fechaNacimiento, sexo), sueldo(350) {}

    double calcularSalario() const override {
        double descuentos = sueldo * (0.075 + 0.0775); // ISSS (7.5%) + AFP (7.75%)
        return sueldo - descuentos;
    }
};

// Clase Jefe de área
class JefeArea : public Empleado {
private:
    double sueldo;
public:
    JefeArea(const std::string& nombre, const std::string& direccion, const std::string& fechaNacimiento, const std::string& sexo)
        : Empleado(nombre, direccion, fechaNacimiento, sexo), sueldo(1500) {}

    double calcularSalario() const override {
        double descuentos = sueldo * (0.075 + 0.0775); // ISSS (7.5%) + AFP (7.75%)
        return sueldo - descuentos;
    }
};

// Clase Supervisor
class Supervisor : public Empleado {
private:
    double sueldo;
public:
    Supervisor(const std::string& nombre, const std::string& direccion, const std::string& fechaNacimiento, const std::string& sexo)
        : Empleado(nombre, direccion, fechaNacimiento, sexo), sueldo(750) {}

    double calcularSalario() const override {
        double descuentos = sueldo * (0.075 + 0.0775); // ISSS (7.5%) + AFP (7.75%)
        return sueldo - descuentos;
    }
};

// Función para ordenar empleados alfabéticamente por el primer apellido
bool compararPorApellido(const Empleado* empleado1, const Empleado* empleado2) {
    std::string apellido1 = empleado1->getNombre().substr(empleado1->getNombre().find_last_of(' ') + 1);
    std::string apellido2 = empleado2->getNombre().substr(empleado2->getNombre().find_last_of(' ') + 1);
    return apellido1 < apellido2;
}

int main() {
    std::vector<Empleado*> empleados;

    // Agregar empleados a la lista
    empleados.push_back(new Gerente("Juan Perez", "San Salvador", "01/01/1990", "M"));
    empleados.push_back(new Tecnico("Maria Rodriguez", "Santa Ana", "15/06/1995", "F"));
    empleados.push_back(new JefeArea("Pedro Gomez", "San Miguel", "10/10/1985", "M"));
    empleados.push_back(new Supervisor("Ana Lopez", "La Libertad", "05/03/1992", "F"));

    int opcion;
    do {
        std::cout << "---- Menú ----" << std::endl;
        std::cout << "1. Ordenar empleados alfabéticamente por apellido" << std::endl;
        std::cout << "2. Ordenar empleados por salario (de menor a mayor)" << std::endl;
        std::cout << "3. Ordenar empleados por salario (de mayor a menor)" << std::endl;
        std::cout << "4. Mostrar cantidad de empleados según roles" << std::endl;
        std::cout << "5. Agregar nuevo empleado" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::sort(empleados.begin(), empleados.end(), compararPorApellido);
                std::cout << "---- Empleados ordenados alfabéticamente por apellido ----" << std::endl;
                for (const auto& empleado : empleados) {
                    std::cout << empleado->getNombre() << std::endl;
                }
                break;
            case 2:
                std::sort(empleados.begin(), empleados.end(), [](const Empleado* e1, const Empleado* e2) {
                    return e1->calcularSalario() < e2->calcularSalario();
                });
                std::cout << "---- Empleados ordenados por salario (de menor a mayor) ----" << std::endl;
                for (const auto& empleado : empleados) {
                    std::cout << empleado->getNombre() << " - Salario: $" << empleado->calcularSalario() << std::endl;
                }
                break;
            case 3:
                std::sort(empleados.begin(), empleados.end(), [](const Empleado* e1, const Empleado* e2) {
                    return e1->calcularSalario() > e2->calcularSalario();
                });
                std::cout << "---- Empleados ordenados por salario (de mayor a menor) ----" << std::endl;
                for (const auto& empleado : empleados) {
                    std::cout << empleado->getNombre() << " - Salario: $" << empleado->calcularSalario() << std::endl;
                }
                break;
            case 4:
                int contadorGerentes = 0, contadorTecnicos = 0, contadorJefesArea = 0, contadorSupervisores = 0;
                for (const auto& empleado : empleados) {
                    if (dynamic_cast<Gerente*>(empleado)) {
                        contadorGerentes++;
                    } else if (dynamic_cast<Tecnico*>(empleado)) {
                        contadorTecnicos++;
                    } else if (dynamic_cast<JefeArea*>(empleado)) {
                        contadorJefesArea++;
                    } else if (dynamic_cast<Supervisor*>(empleado)) {
                        contadorSupervisores++;
                    }
                }
                std::cout << "---- Cantidad de empleados según roles ----" << std::endl;
                std::cout << "Gerentes: " << contadorGerentes << std::endl;
                std::cout << "Técnicos: " << contadorTecnicos << std::endl;
                std::cout << "Jefes de área: " << contadorJefesArea << std::endl;
                std::cout << "Supervisores: " << contadorSupervisores << std::endl;
                break;
            case 5: {
                std::string nombre, direccion, fechaNacimiento, sexo, rol;
                std::cout << "Ingrese el nombre del nuevo empleado: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);
                std::cout << "Ingrese la dirección del nuevo empleado: ";
                std::getline(std::cin, direccion);
                std::cout << "Ingrese la fecha de nacimiento del nuevo empleado: ";
                std::getline(std::cin, fechaNacimiento);
                std::cout << "Ingrese el sexo del nuevo empleado (M/F): ";
                std::getline(std::cin, sexo);
                std::cout << "Ingrese el rol del nuevo empleado (Gerente/Tecnico/JefeArea/Supervisor): ";
                std::getline(std::cin, rol);

                Empleado* nuevoEmpleado = nullptr;
                if (rol == "Gerente") {
                    nuevoEmpleado = new Gerente(nombre, direccion, fechaNacimiento, sexo);
                } else if (rol == "Tecnico") {
                    nuevoEmpleado = new Tecnico(nombre, direccion, fechaNacimiento, sexo);
                } else if (rol == "JefeArea") {
                    nuevoEmpleado = new JefeArea(nombre, direccion, fechaNacimiento, sexo);
                } else if (rol == "Supervisor") {
                    nuevoEmpleado = new Supervisor(nombre, direccion, fechaNacimiento, sexo);
                }

                if (nuevoEmpleado) {
                    empleados.push_back(nuevoEmpleado);
                    std::cout << "Nuevo empleado agregado exitosamente." << std::endl;
                } else {
                    std::cout << "Rol inválido. No se pudo agregar el nuevo empleado." << std::endl;
                }
                break;
            }
            case 6:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida. Por favor, ingrese una opción válida." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (opcion != 6);

    // Liberar memoria de los empleados
    for (const auto& empleado : empleados) {
        delete empleado;
    }

    return 0;
}
