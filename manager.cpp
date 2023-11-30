#include <iostream>
using namespace std;

#include "Fecha.h"
#include "manager.h"

int VerificarCaracteres(){
    int numero;
    while (!(std::cin >> numero)) {
        std::cin.clear();  // Limpiar el estado de error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Descartar la entrada no válida
        std::cout << "Entrada no valida. Por favor, ingrese un numero entero: ";
    }
    system("cls");
    return numero;
}

void ManagerProducto::Cargar(){

    Producto reg;
    int pos=0, id;
    string ids;


    cout<<"INGRESE CODIGO DE PRODUCTO: ";
    cin>>ids;

    while (esNumero(ids))
    {
      cout<<"EL VALOR INGRESADO ES INVALIDO"<<endl;
      cout<<"INGRESE UN NUMERO"<<endl;
      cin>>ids;
    }

    id=stoi(ids);

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

    ID = VerificarCaracteres();

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
cout<<"ELIMINADO: "<<(reg.getEstado()?"NO":"SI")<<endl;


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

void ManagerProducto::EliminarArticulo(){

        int id;

        Producto producto;

        cout<<"INGRESE CODIGO DE PRODUCTO A ELIMINAR: "<<endl;
        id = VerificarCaracteres();
        int pos = arch.BuscarIdProducto(id);

        if(pos >= 0){
            Producto reg = arch.LeerProductoBuscado(pos);
            cout<<"PRODUCTO A ELIMINAR: ";
            MostrarRegistro(reg);
            cout<<"ESTA SEGURO QUE DESEA ELIMINAR PRODUCTO? S/N";
            char r;
            cin>>r;
            while(r!='s' && r!='S' && r!='n' && r!='N')
            if(r!='s' && r!='S' && r!='n' && r!='N'){
            cout<<"Solo se acepta 'S' o 'N'!!"<<endl;
            cout<<"¿ESTA SEGURO QUE DESEA ELIMINAR EL VENDEDOR? S/N: ";
            cin>>r;
            }

            if(toupper(r) == 'S'){
                reg.set_estado(false);
                arch.ModificarProducto(reg, pos);
                cout<<"**PRODUCTO ELIMINADO CORRECTAMENTE**"<<endl;
                }
           else{
            cout<<"!! OPERACION CANCELADA !! "<<endl;
           }
        }
        else{
            cout<<"¡¡ PRODUCTO NO ENCONTRADO EN LOS ARCHIVOS !!"<<endl;
        }
}

void ManagerProducto::ModificarProducto(){

        int id, pos;
        Producto producto;
        int cantidad = arch.archivoProductoContar();


        cout<<"INGRESE ID A MODIFICAR"<<endl;
        cin>>id;
        while(cin.fail()){
            if (std::cin.fail()) {
            std::cin.clear();  // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Descartar la entrada no válida
            std::cout << "Entrada no valida. Por favor, ingrese un numero entero.\n";
            cin>>id;


        }
        }
        pos = arch.BuscarIdProducto(id);
        producto=arch.leerProducto(pos,producto);

        if(pos>=0 && producto.getEstado()==true){
        for(int i=0;i<cantidad;i++){
            Producto reg = arch.LeerProductoBuscado(i);
                if(reg.getId() == id && reg.getEstado()==true){
                    reg.cargar(id);
                    arch.ModificarProducto(reg,i);

                }
            }
        }
    else{
        cout<<"¡¡ PRODUCTO NO ENCONTRADO EN LOS ARCHIVOS, INTENTELO NUEVAMENTE !!"<<endl;
    }
}
 bool ManagerProducto::esNumero(string numero)
 {
     for (char cad : numero )
     {
         if(!isdigit(cad))
         {
             return true;
         }
     }

     return false;

 }
