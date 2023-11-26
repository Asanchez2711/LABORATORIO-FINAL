#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

#include "Fecha.h"
#include "Persona.h"

class Cliente:public Persona{

    private:
    float _totalGastado;
    public:



    void setTotalGastado(float totalGastado);

    float getTotalGastado() const;



    void Mostrar()const;



};

#endif // CLIENTE_H_INCLUDED
