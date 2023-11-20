#ifndef ARCHIVO_CLIENTE_H_INCLUDED
#define ARCHIVO_CLIENTE_H_INCLUDED

#include <iostream>
#include <string>
#include "Cliente.h"

class archivo_cliente
{
    public:

        int archivoClienteContar();
        Cliente leerCliente(int pos, Cliente reg);
        bool BorrarCliente(Cliente reg, int pos);
        bool ModificarCliente(Cliente reg,int pos);
        bool GuardarCliente(Cliente reg);
        bool ListarClientes();
        int BuscarIdCliente(int legajo);
        int BuscarLegajoCliente(int legajo, Cliente reg);
        archivo_cliente(std::string nombre ){
        _nombre=nombre;
        }


    private:

        std::string _nombre;
};

#endif // ARCHIVO_CLIENTE_H_INCLUDED
