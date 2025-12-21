#include <stdio.h>
typedef struct {
    char placa[10];
    char marca[20];
    char modelo[20];
    char tipo[20];
    char estado[20];
    float precio;
    float precioCompra;
    int tipoIngreso; 
    int disponible;
} Vehiculo;

typedef struct{
    char nombre[50];
    int edad;
    char telefono[15];
} Cliente;

typedef struct {
    Vehiculo vehiculo;
    Cliente cliente;
    float montoVenta;
} Venta;

typedef struct {
    float totalGastado;
    float totalGanado;
} Economia;


int menu();
int opcionValida(int min, int max);
void eliminarSaltoLinea(char *cadena, int n);   
int menu2();
int menuToyota();
int menuChevrolet();
int menuHyundai();
int menuTipo();
int menuEstado();
void ingresarVehiculo(Economia *eco);
void registrarCliente();
int menuIngreso();
void mostrarVehiculos();
int leerVehiculos(Vehiculo *vehiculos);
int placaExiste(char *placa);
void registrarCliente();
void guardarVehiculo(Vehiculo *vehiculo);
void guardarCliente(Cliente *cliente);
int leerClientes(Cliente *clientes);
void buscarVehiculoPorPlaca();
void buscarVehiculosPorMarca();
void buscarVehiculosPorPresupuesto();
void guardarVenta(Venta *venta);
void venderVehiculo(Economia *eco);
void mostrarVentas();
void pedirDatosClienteVenta(Cliente *c);
void informeGanancias(Economia *eco);
void cargarEconomia(Economia *eco);
void guardarEconomia(Economia *eco);