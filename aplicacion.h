#ifndef APLICACION_H_INCLUDED
#define APLICACION_H_INCLUDED

#include <iostream>
#include <cstdio>

#include "administrador.h"
#include "Vendedor.h"
#include "manager.h"

class Aplicacion{

public:
    void MenuApp();
private:
    Admin _admin;
    Vendedor_menu _vendedor;
};


#endif // APLICACION_H_INCLUDED
