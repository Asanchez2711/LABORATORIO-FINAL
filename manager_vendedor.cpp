#include "manager_vendedor.h"
#include "archivo_cliente.h"

void manager_vendedor::CargarVendedor(){

int v,r;
archivo_empleado arch("empleado.dat");
    cout<<" ESTA POR INGRESAR UN VENDEDOR "<<endl;
    cout<<endl;
    cout<<"Ingrese el id del vendedor"<<endl;
    cin>>v;
    cout<<endl;
   r=arch.BuscarEmpleadoenArchivo(v);

   if(r==-1){

    Empleado obj;
    obj.cargar(v);//lo paso por parametro para no cargar 2 veces el id, lo mismo hice en el metodo para cargar el cliente.
    obj.setLegajo(v);

    arch.GuardarEmpleado(obj);}

  if(r!=-1){cout<<"EL ID QUE YA EXISTE !!"<<endl;}
cout<<endl;
  system("pause");
    system("cls");
}

void manager_vendedor::TotalRecaudado(){

        int i;
        float total=0;
        int cantidad=arch.archivoEmpleadoContar();
        Empleado empleado;

        for(i=0;i<cantidad;i++){
            empleado=arch.leerEmpleado(i,empleado);
            total=empleado.getTotalVendido()+total;
        }

        cout<<"El total recaudado es "<<total<<endl<<endl;
}

void manager_vendedor::TotalRecaudadoXVendedor(){

        int i;
        int cantidad=arch.archivoEmpleadoContar();
        Empleado empleado;

        for(i=0;i<cantidad;i++){
            empleado=arch.leerEmpleado(i,empleado);

            cout<<"EL TOTAL RECAUDADO POR EL VENDEDOR "<<empleado.getNombre()<<" ES: $"<<empleado.getTotalVendido()<<endl<<endl;
        }
}

void manager_vendedor::ModificarVendedor(){

        int i,legajo,cantidad;
        cantidad=arch.archivoEmpleadoContar();
        Empleado empleado;

        cout<<"Ingrese legajo de empleado a modificar"<<endl;
        cin>>legajo;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Valor invalido, ingrese solo numeros"<<endl;
            cout<<"Ingrese nuevamente el valor"<<endl;
            cin>>legajo;

        }

        for(i=0;i<cantidad;i++){
                empleado=arch.leerEmpleado(i,empleado);

                if(legajo==empleado.getLegajo()){
                    empleado.cargar(legajo);
                    arch.ModificarEmpleado(empleado,i);
                    break;
                }
                if(i==cantidad-1){

                    cout<<" Legajo NO encontrado "<<endl;
                }
        }
}

void manager_vendedor::ListarVendedores(){
    arch.ListarEmpleados();
}

void manager_vendedor::EliminarVendedor(){
    int legajo, posicion;

    cout<<"INGRESE LEGAJO DE VENDEDOR A ELIMINAR: ";
    cin>>legajo;
    posicion=arch.BuscarEmpleadoenArchivo(legajo);
    if(posicion>=0){
        Empleado reg = arch.Leer(posicion);

        cout<<"VENDEDOR A ELIMINAR: "<<endl;
        MostrarVendedor(reg);
        cout<<"¿ESTA SEGURO QUE DESEA ELIMINAR EL VENDEDOR? S/N: ";
        char r;
        cin>>r;
        if(toupper(r) == 'S'){
                reg.setEstado(false);
            reg.SetEliminado(true);
            arch.BorrarEmpleado(reg, posicion);
            cout<<endl;
            cout<<"VENDEDOR ELIMINADO CORRECTAMENTE"<<endl;
        }

        else{
            cout<<endl;
            cout<<"OPERACION CANCELADA"<<endl;
        }

    }
    else{
        cout<<"¡¡ REGISTRO: "<<legajo<<" NO EXISTE, NO ES POSIBLE ELIMINAR !!"<<endl;
    }
}

void manager_vendedor::MostrarVendedor(Empleado reg){
    cout<<"LEGAJO: "<<reg.getLegajo()<<endl;
    cout<<"NOMBRE: "<<reg.getNombre()<<endl;
    cout<<"APELLIDO: "<<reg.getApellido()<<endl;

}


void manager_vendedor::BuscarVendedor(){
    int legajo;
    cout<<"INGRESE LEGAJO A BUSCAR :";
    cin>>legajo;
    int pos;
    pos = arch.BuscarEmpleadoenArchivo(legajo);
    if(pos>=0){
        Empleado reg = arch.Leer(pos);
        reg.mostrar();
    }
    else{
    cout<<"¡¡ LEGAJO NO SE ENCUENTRA EN LOS ARCHIVOS !! "<<endl;
    }
}

 void manager_vendedor::CargarVenta()
 {

     Venta venta;
    archivo_venta archventa;
    Producto prod;
    archivo_producto archpro("producto.dat");
    int cantprod = archpro.archivoProductoContar();
    Empleado emple;
    archivo_empleado archemple ("empleado.dat");
    int cantemple = archemple.archivoEmpleadoContar();
    int idvendedor;
    int idproducto;
    int cantidad;
    int pos;
    int  numerodeproductos=0;
    int cantidadproductos [100];
    float totalventa=0;
    bool band=true;
    string resp;
    int val=1;
    int posidemple;
    int ncliente;
    archivo_cliente archivoCLiente("cliente.dat");

    while(val==1){
    cout<<"Ingrese ID vendedor"<<endl;
    cin>>idvendedor;
   int posidemple= archemple.BuscarLegajoEmpleado(idvendedor,emple);
    while (posidemple==-1)
        {
            cout<<"El empleado ingresado no existe  vuelva a ingresar ID de empleado"<<endl;
            cin>>idvendedor;
            posidemple=archemple.BuscarLegajoEmpleado(idvendedor,emple); // verificar si la posicion que otorga el metodo existe por que al mostrar el objeto cargado por leerEmpleado ya a arroja basura

        }/// ingrese id de cliente(verificar que el cliente existe)
        //verificar si al momento de la venta el cliente exitia, lo mismo con el stock del producto y el cliente.
        // osea no podemos cargar una venta con id de vendedor con fecha de alta 20/11/2023 y pretender que ese venddedor se cargue una venta fecha anterior
        //lo mismo con empleado.




       cout<<"Ingrese fecha de la venta "<<endl;
       venta.setFecha();
    emple =archemple.leerEmpleado(posidemple,emple);
    emple.mostrar();
    if(venta.getFechaVenta().getAnio()>emple.getFechaDeAlta().getAnio()){
            val=0;
    venta.setidvendedor(idvendedor);}
    else{if(venta.getFechaVenta().getMes()>emple.getFechaDeAlta().getMes())

        {
            venta.setidvendedor(idvendedor);
            val=0;
        }
        else{
                if(venta.getFechaVenta().getDia()>=emple.getFechaDeAlta().getDia()){
                venta.setidvendedor(idvendedor);
                val=0;


                }

        else{
                cout<<endl;
                cout<<"Al momento de realizar esta venta no hay registros del vendedor indicado"<<endl;
                cout<<endl; val=1;
        }
                }

    }

    }




    while (band && resp != "no")
    {
        cout<<"Ingrese ID producto"<<endl;
        cin>>idproducto;
        cout<<"Ingrese cantidad"<<endl;
        cin>>cantidad;
        pos=archpro.BuscarIdProducto(idproducto);
        while (pos==-1)
        {
            cout<<"El producto ingresado no existe vuelva a ingresar ID de producto"<<endl;
            cin>>idproducto;
            pos=archpro.BuscarIdProducto(idproducto);

        }
        int clte;



        cout<<"Ingrese el numero del  cliente: "<<endl;
        cin>>ncliente;
        clte=archivoCLiente.BuscarIdCliente(ncliente);//agregue la funcion buscar id cliente que solo necesita un int.


 while(clte==-1){

            cout<<endl;
            cout<<"El cliente no existe! "<<endl;
            cout<<endl;
            cout<<"Ingrese un cliente existente: "<<endl;
            cin>>ncliente;

            clte=archivoCLiente.BuscarIdCliente(ncliente);



        }


        cantidadproductos[numerodeproductos]=idproducto;
        numerodeproductos++;

         prod= archpro.leerProducto(pos,prod);
         cout <<"Usted a seleccionado "<<cantidad<<" prendas de la marca "<<prod.getMarca()<<endl;
         while (prod.getCantidad()<cantidad)
         {
             cout<<"No se dispone de dicha cantidad en stock, hay en existencia: "<<prod.getCantidad()<<endl;
            cout<<"Ingrese nuevamente la cantidad"<<endl;
            cin>>cantidad;

         }

         totalventa+=(prod.getPrecio()*cantidad);
         int c= prod.getCantidad()-cantidad;
         prod.setCantidad(c);
         archpro.ModificarProducto(prod,pos);
         cout<<"¿Desea ingresar otro producto? si/no"<<endl;
         cin.ignore();
          cin>>resp;
         while (resp!="si"&&resp!="no")
         {


             cout<<"Ha ingresado un parametro invalido. Por favor, ingrese si o no"<<endl;
             cout<<"¿Desea ingresar otro producto? si/no"<<endl;

         if (resp=="no")
         {
              band=false;
         }
    }
    }
     cout<<"Se finalizo la carga de venta"<<endl;
     venta.setcantprod(numerodeproductos);
     int totalventaorigen = emple.getTotalVendido();
     totalventa+=totalventaorigen;
    venta.setidproducto(cantidadproductos);
    venta.setPrecioVenta(totalventa);
    emple.setTotalVendido(totalventa);
    venta.setidVenta((archventa.archivoVentaContar()+1));
    archventa.GuardarVenta(venta);
    archemple.ModificarEmpleado(emple,posidemple); ///Verificar donde se rompe y se corrempe empleado al modificar pos en archivo_empleado




 }

