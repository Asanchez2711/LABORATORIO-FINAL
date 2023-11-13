#ifndef ADMINISTRADOR_H_INCLUDED
#define ADMINISTRADOR_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <cstring>
#include "manager.h"
#include "manager_vendedor.h"

class Admin{

public:
    void MenuAdmin();

private:
    ManagerProducto _manager;
    manager_vendedor _managerVendedor;
};

#endif // ADMINISTRADOR_H_INCLUDED
