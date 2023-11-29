#include <iostream>
using namespace std;

#include "Fecha.h"
#include "manager.h"

void ManagerProducto::Cargar(){

    Producto reg;
    int pos=0, id;


    cout<<"INGRESE CODIGO DE PRODUCTO: ";
    cin>>id;
    while(id<0){
      cout<<" !! INGRESE CODIGO MAYOR IGUAL A 0 !!"<<endl;
      cout<<"INGRESE CODIGO DE PRODUCTO: ";
      cin>>id;
    }
    pos = arch.BuscarIdProducto(id);
    reg = arch.leerProducto(pos,reg);
    if(pos >= 0 && reg.getEstado()==true){
        cout<<" ¡¡ CODIGO DE PRODUCTO EXISTENTE, INTENTE CON OTRO !! "<<endl;
        system("pause");
        system("cls");
    }

    if(pos<0 || reg.getEstado()==false){
    reg.cargar(id);
    reg.set_estado(true);
    bool ok = arch.GuardarProducto(reg);
    if(ok){
        cout<<"**EL PRODUCTO SE GUARDO CORRECTAMENTE**"<<endl;
    }
    else{
        cout<<"!!EL PRODUCTO NO SE GUARDO CORRECTAMENTE!!"<<endl;
        }
    }
}

void ManagerProducto::BuscarXID(){

int ID, pos;

cout<<"INGRESE CODIGO A BUSCAR: ";
cin>>ID;

pos = arch.BuscarIdProducto(ID);

if(pos >= 0){
    MostrarRegistro(arch.LeerProductoBuscado(pos));
}
else{
    cout<<"NO SE ENCONTRO EL PRODUCTO CON ID: "<<ID<<endl;
}
}

void ManagerProducto::MostrarRegistro(Producto reg){
Fecha f;
cout<<"CODIGO PRODUCTO: "<<reg.getId()<<endl;
cout<<"PRECIO: $"<<reg.getPrecio()<<endl;
cout<<"DESCRIPCION: "<<reg.getDescripcion()<<endl;
cout<<"STOCK: "<<reg.getCantidad()<<endl;
cout<<"PROVEEDOR: "<<reg.getProveedor()<<endl;
cout<<"TEMPORADA: "<<reg.getTemporada()<<endl;
///FIX
//  cout<<"FECHA DE ALTA: "<<f.toString()<<endl;
cout<<"ELIMINADO: "<<(reg.getEstado()?"SI":"NO")<<endl;


}

void ManagerProducto::ListarProductos(){

int cant;
cant = arch.archivoProductoContar();
    cout<<"PRODUCTOS DADOS DE ALTA: "<<endl;
    cout<<"**************************"<<endl;
for(int i=0;i<cant;i++){
    Producto reg = arch.LeerProductoBuscado(i);
    if(reg.getEstado() == true){
    MostrarRegistro(reg);
    cout<<"**************************"<<endl;
    }
  }
}
/// HAY QUE ARMARLO BIEN CUANDO SE TENGA LA CLASE VENTAS 13/11
/*
void ManagerProducto::ListarRecaudado(){

    int cant;
    float Total=0;
    cant = arch.archivoProductoContar();
    for(int i=0;i<cant;i++){
        Producto reg = arch.LeerProductoBuscado(i);
        Total+=reg.getPrecio();
    }
    cout<<"******************"<<endl;
    cout<<"TOTAL RECAUDADO: $"<<Total<<endl;
    cout<<"******************"<<endl;
}
*/

void ManagerProducto::EliminarArticulo(){

        int id;

        Producto producto;
        int cantidad=arch.archivoProductoContar();

        cout<<"INGRESE CODIGO DE PRODUCTO A ELIMINAR: "<<endl;
        cin>>id;
        int pos = arch.BuscarIdProducto(id);
        producto=arch.leerProducto(pos,producto);

        if(pos >= 0 && producto.getEstado()==true){
        for(int i=0;i<cantidad;i++){
            Producto reg = arch.LeerProductoBuscado(i);
            if(id == reg.getId() && reg.getEstado()==true){
                reg.set_estado(false);
                arch.ModificarProducto(reg, i);
                cout<<"**PRODUCTO ELIMINADO CORRECTAMENTE**"<<endl;
                }
            }
        }
        else{
            cout<<"¡¡ PRODUCTO NO ENCONTRADO EN LOS ARCHIVOS !!"<<endl;
        }
}

void ManagerProducto::ModificarProducto(){

        int id, pos;
        int cantidad = arch.archivoProductoContar();
        cout<<"INGRESE ID A MODIFICAR"<<endl;
        cin>>id;
        pos = arch.BuscarIdProducto(id);
        if(pos>=0){
        for(int i=0;i<cantidad;i++){
            Producto reg = arch.LeerProductoBuscado(i);
                if(reg.getId() == id){
                    reg.cargar(id);
                    arch.ModificarProducto(reg,i);

                }
            }
        }
    else{
        cout<<"¡¡ PRODUCTO NO ENCONTRADO EN LOS ARCHIVOS, INTENTELO NUEVAMENTE !!"<<endl;
    }
}
