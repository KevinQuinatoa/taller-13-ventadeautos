#include <stdio.h>
#include <string.h> 
#include "funcion.h"

int main(int argc, char const *argv[])
{
   Vehiculo vehiculo;
   int opc1, opc2, opc3;
   int cont;
   Economia eco;

   cargarEconomia(&eco);

    do {
        opc1=menu();
        switch (opc1)
        {
        case 1:
            ingresarVehiculo(&eco);
            break;
         case 2:
            registrarCliente();
            break;
         case 3:
            mostrarVehiculos();
            break;
         case 4:
            mostrarVentas();
            break;
         case 5:
            buscarVehiculoPorPlaca();
            break;
         case 6:
            buscarVehiculosPorMarca();
            break;
         case 7:
            buscarVehiculosPorPresupuesto();
            break;
         case 8: 
            buscarClienteMenu();
            break;

         case 9:
            venderVehiculo(&eco);
            break;
         case 10:
            eliminarVehiculo();
            break;
         case 11:
            informeGanancias(&eco);
            break;
         case 12:
            printf("Saliendo del sistema...\n");
            return 0;
        
        default:
        printf("Opcion no valida\n");
            break;
        }
   
    } while(opc1 != 12);

  return 0;  
}
