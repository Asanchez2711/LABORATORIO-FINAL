#ifndef MANAGER_VENDEDOR_H_INCLUDED
#define MANAGER_VENDEDOR_H_INCLUDED

#include <iostream>
#include <cstdio>
#include "archivo_vendedor.h"
#include "empleado.h"
#include "Persona.h"
#include "Fecha.h"

class manager_vendedor{

public:
    void CargarVendedor();
    void TotalRecaudado();
    void TotalRecaudadoXVendedor();
    void ModificarVendedor();
    void ListarVendedores();
    void EliminarVendedor();
    void MostrarVendedor(Empleado reg);
private:

archivo_empleado arch = archivo_empleado("empleado.dat");
};

#endif // MANAGER_VENDEDOR_H_INCLUDED
