#include "manager_vendedor.h"

void manager_vendedor::CargarVendedor(){

    cout<<" ESTA POR INGRESAR UN VENDEDOR "<<endl;
    cout<<endl;
    Empleado obj;
    obj.cargar();
    arch.GuardarEmpleado(obj);

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
                    empleado.cargar();
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
    system("pause");
    system("cls");
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
        cout<<"!!REGISTRO: "<<legajo<<" NO ES POSIBLE ELIMINAR!!"<<endl;
    }
}

void manager_vendedor::MostrarVendedor(Empleado reg){
    cout<<"LEGAJO: "<<reg.getLegajo()<<endl;
    cout<<"NOMBRE: "<<reg.getNombre()<<endl;
    cout<<"APELLIDO: "<<reg.getApellido()<<endl;

}
