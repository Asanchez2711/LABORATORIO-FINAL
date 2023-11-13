#ifndef ARCHIVO_PRODUCTO_H_INCLUDED
#define ARCHIVO_PRODUCTO_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <cstring>

#include "Producto.h"

class archivo_producto
{
    public:

        int archivoProductoContar();
        Producto leerProducto(int pos, Producto reg);
        Producto LeerProductoBuscado(int nro);
        bool BorrarProducto(Producto reg, int pos);
        bool ModificarProducto(Producto reg,int pos);
        bool GuardarProducto(Producto reg);
        bool ListarProductos();
        int BuscarIdProducto(int id);
        archivo_producto(std::string nombre ){
        _nombre=nombre;
        }
        void borrarProductoVoid(int posicion);
        void MostrarProducto(Producto reg);

    private:

        std::string _nombre;
};

#endif // ARCHIVO_PRODUCTO_H_INCLUDED
