#ifndef VENTA_H
#define VENTA_H


#include <iostream>
#include "Producto.h"
#include "Empleado.h"
#include "Fecha.h"

class Venta {
private:

    Fecha _fechaVenta;
    int _idproducto[100];
    int _cantprod;
    int _idvendedor;
    int _idCliente;
    float _precioVenta;
    int _cantidad;
    int _idVenta;


public:


    Venta();

Fecha getFechaVenta() const;
    float getPrecioVenta() const;
    int getCantidad() const;
    int getidVenta() const;
    const int* getidproducto() const;
    int getidvendedor() const;
    int getidCliente () const;


    void setFecha();
    void setPrecioVenta(float precioventa);
    void setCantidad(int cantidad);
    void setidVenta (int idventa);
    void setidproducto( int *idproducto);
    void setidvendedor(int idvendedor) ;
    void setcantprod(int cantprod);
    void setidCliente(int idcliente);
    float calcularTotalVenta () const;
     void mostrarVenta();




};
#endif // VENTA_H
