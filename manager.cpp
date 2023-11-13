#include <iostream>
using namespace std;

#include "Fecha.h"
#include "manager.h"

void ManagerProducto::Cargar(){

    Producto reg;
    cout<<"INGRESE CODIGO DE PRODUCTO: ";
    int id;
    cin>>id;
    reg.cargar(id);
    arch.GuardarProducto(reg);

    bool ok = arch.GuardarProducto(reg);
    if(ok){
        cout<<"**EL PRODUCTO SE GUARDO CORRECTAMENTE**"<<endl;
    }
    else{
        cout<<"!!EL PRODUCTO NO SE GUARDO CORRECTAMENTE!!"<<endl;
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
for(int i=0;i<cant;i++){
    Producto reg = arch.LeerProductoBuscado(i);
    MostrarRegistro(reg);
    cout<<"**************************"<<endl;
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
/// PARA REVISAR SI ELIMINA CORRECTAMENTE 13/11 ///
void ManagerProducto::EliminarArticulo(){

        int i,cantidad,id;
        Producto producto;
        cantidad=arch.archivoProductoContar();

        cout<<"INGRESE CODIGO DE PRODUCTO A ELIMINAR: "<<endl;
        cin>>id;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Valor invalido, ingrese solo numeros"<<endl;
            cout<<"Ingrese nuevamente el valor"<<endl;
            cin>>id;

        }

        for(i=0;i<cantidad;i++){
            producto=arch.leerProducto(i,producto);
            if(id==producto.getId()){
                arch.borrarProductoVoid(i);

            }
    }
}
///FIX
void ManagerProducto::ModificarProducto(){

        int i,id,cantidad;

        archivo_producto arch("producto.dat");
        cantidad=arch.archivoProductoContar();
        Producto producto;

        cout<<"Ingrese id de producto a modificar"<<endl;
        cin>>id;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Valor invalido, ingrese solo numeros"<<endl;
            cout<<"Ingrese nuevamente el valor"<<endl;
            cin>>id;

        }

        for(i=0;i<cantidad;i++){

                producto=arch.leerProducto(i,producto);

                if(id==producto.getId()){
                    producto.cargar(i);
                    arch.ModificarProducto(producto,i);
                    break;
                }
                if(i==cantidad-1){

                    cout<<" Id no encontrado "<<endl;
                }
        }


}
