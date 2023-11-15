#ifndef ARCHIVO_VENTA_H
#define ARCHIVO_VENTA_H
#include "Venta.h"

class archivo_venta
{
     public:

        int archivoVentaContar();
        Venta leerVenta(int pos, Venta reg);

        bool BorrarVenta(Venta reg, int pos);
        bool ModificarVenta(Venta reg,int pos);
        bool GuardarVenta(Venta reg);
        bool ListarVentas();
        int BuscarIdVenta(int id, Venta reg);
        archivo_venta(std::string nombre ){
        _nombre=nombre;
        }
         archivo_venta();
        void borrarVentaVoid(int posicion);
         void mostrarVenta();

    private:

        std::string _nombre;
};

#endif // ARCHIVO_VENTA_H
