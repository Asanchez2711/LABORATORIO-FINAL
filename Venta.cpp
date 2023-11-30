#include "Venta.h"
#include "archivo_vendedor.h"



Venta::Venta()
{
    //ctor
}


Fecha Venta::getFechaVenta() const
{
    return _fechaVenta;
}
float Venta::getPrecioVenta() const
{
    return _precioVenta;
}
int Venta::getCantidad() const
{
    return _cantidad;
}
int Venta::getidVenta() const
{
    return _idVenta;
}

const int* Venta::getidproducto() const
{
    return _idproducto;
}
int Venta::getidvendedor() const
{
    return _idvendedor;
}
int Venta::getidCliente () const
{
    return _idCliente;
}

void Venta::setFecha()
{
    _fechaVenta.cargar();
}
void Venta::setPrecioVenta(float precioventa)
{
    _precioVenta=precioventa;
}
void Venta::setCantidad(int cantidad)
{
    _cantidad=cantidad;
}
void Venta::setidVenta (int idventa)
{
    _idVenta=idventa;
}

void Venta::setidproducto( int* idproducto)
{
    for ( int i = 0; i<_cantprod; i++)
    {
        _idproducto[i] = idproducto[i];
    }
}
void Venta::setidvendedor(int idvendedor)
{
    _idvendedor=idvendedor;
}
void Venta::setidCliente(int idcliente)
{
    _idCliente=idcliente;
}
void Venta::mostrarVenta()
{

    std::cout<<"ID Venta: "<<_idVenta<<std::endl;
    std::cout<<"Fecha de venta: "<<_fechaVenta.toString()<<std::endl;
    std::cout<<"Productos: ";
    for (int i=0; i<_cantprod;i++)
    {
        if (_idproducto[i] !=0)
        {
            std::cout << _idproducto[i]<< " - ";
        }
    }
    std::cout<<std::endl;
    std::cout<<"ID Vendedor: "<<_idvendedor<<std::endl;
     std::cout<<"ID Cliente: "<<_idCliente<<std::endl;
    std::cout<<"Total vendido: $"<<_precioVenta<<std::endl;

}

void Venta::setcantprod(int cantprod)
{
    _cantprod=cantprod;
}



float Venta::calcularTotalVenta() const
{
    return _precioVenta * _cantidad;
}


