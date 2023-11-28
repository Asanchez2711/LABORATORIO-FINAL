#ifndef MANAGER_VENDEDOR_H_INCLUDED
#define MANAGER_VENDEDOR_H_INCLUDED

#include <iostream>
#include <cstdio>
#include "archivo_vendedor.h"
#include "empleado.h"
#include "Persona.h"
#include "Fecha.h"
#include "producto.h"
#include "Venta.h"
#include "archivo_venta.h"
#include "archivo_producto.h"

class manager_vendedor{

public:
    void CargarVendedor();
    void TotalRecaudado();
    void TotalRecaudadoXVendedor();
    void BuscarVendedor();
    void ModificarVendedor();
    void ListarVendedores();
    void EliminarVendedor();
    void MostrarVendedor(Empleado reg);
    void CargarVenta();
    void buscarCliente();

private:

archivo_empleado arch = archivo_empleado("empleado.dat");
};

#endif // MANAGER_VENDEDOR_H_INCLUDED
