#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <limits>
#include <cstring>
#include "archivo_producto.h"
#include "producto.h"

class ManagerProducto{

public:
    void Cargar();
    void BuscarXID();
    void MostrarRegistro(Producto reg);
    void ListarProductos();
    /// VA EN MANAGER VENDEDOR: void ListarRecaudado();
    void EliminarArticulo();
    void ModificarProducto();

private:
    archivo_producto arch = archivo_producto("producto.dat");

};

#endif // MANAGER_H_INCLUDED
