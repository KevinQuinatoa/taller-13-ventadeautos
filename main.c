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
            mostrarVehiculos();
            break;
         case 3:
            mostrarVentas();
            break;
         case 4:
            buscarVehiculoPorPlaca();
            break;
         case 5:
            buscarVehiculosPorMarca();
            break;
         case 6:
            buscarVehiculosPorPresupuesto();
            break;
         case 7:
            venderVehiculo(&eco);
            break;
         case 8:
            eliminarVehiculo();
            break;
         case 9:
            informeGanancias(&eco);
            break;
         case 10:
            printf("Saliendo del sistema...\n");
            return 0;
        
        default:
        printf("Opcion no valida\n");
            break;
        }
   
    } while(opc1 != 10);

  return 0;  
}
