#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <iostream>
#include <string>
#include <limits>

#include "Fecha.h"
using namespace std;
class Persona{

protected:
        int _legajo;
        char _nombre[30];
        char _apellido[30];
        class Fecha _fechaDeAlta;
        float _totalVendido;
        bool _estado;

public:

        void setLegajo(int legajo);
        void setNombre(string nombre);
        void setApellido(string apellido);
        void setFechaDeAlta(class Fecha fechaDeAlta);
        void setEstado(bool estado);

        int getLegajo() const;
        string getNombre() const;
        string getApellido() const;
        class Fecha getFechaDeAlta() const;
        bool getEstado() const;
        bool esSoloLetras(const char *cadena);

        void cargar(int f);
         void mostrar();




};

#endif // PERSONA_H_INCLUDED
