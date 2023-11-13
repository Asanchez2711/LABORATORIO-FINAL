#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

#include "Fecha.h"
#include "Persona.h"

class Cliente:public Persona{

    private:
    int _totalGastado;
    public:



    void setTotalGastado(int totalGastado);

    int getTotalGastado() const;



    void Mostrar()const;



};

#endif // CLIENTE_H_INCLUDED
