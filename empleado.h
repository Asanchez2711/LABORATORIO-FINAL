#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdio>

#include "Fecha.h"
#include "Persona.h"

class Empleado: public Persona{
    private:
        bool _eliminado;
        float _totalVendido=0;
        Fecha _fechaDeAlta;

    public:
        Empleado();
        void SetEliminado(bool eliminado);
        bool GetEliminado()const;
        void setTotalVendido(float totalVendido);
        float getTotalVendido() const;
        Empleado LeerEmpleadoArchivo(int legajo);

        void mostrar() const;



};


#endif // EMPLEADO_H_INCLUDED
