#ifndef ARCHIVO_VENDEDOR_H_INCLUDED
#define ARCHIVO_VENDEDOR_H_INCLUDED


#include <iostream>
#include <string>
#include <cstdio>
#include "Persona.h"
#include "empleado.h"
class archivo_empleado{

public:
        int archivoEmpleadoContar();
        Empleado leerEmpleado(int pos, Empleado reg);
        bool BorrarEmpleado(Empleado reg, int pos);
        bool ModificarEmpleado(Empleado reg,int pos);
        bool GuardarEmpleado(Empleado reg);
        bool ListarEmpleados();
        int BuscarLegajoEmpleado(int legajo, Empleado reg);
        int BuscarEmpleadoenArchivo(int codigo);
        archivo_empleado(std::string nombre){
        _nombre=nombre;
        }
        Empleado Leer(int legajo);
    private:
        string _nombre;

};

#endif // ARCHIVO_VENDEDOR_H_INCLUDED
