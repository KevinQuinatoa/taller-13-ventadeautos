#include <stdio.h>
typedef struct {
    char placa[10];
    char marca[20];
    char modelo[20];
    char tipo[20];
    char estado[20];
    char color[20];      // NUEVO
    int anio;            // NUEVO
    float precio;
    float precioCompra;
    int tipoIngreso;
    int disponible;
    int eliminado;
} Vehiculo;


typedef struct{
    char nombre[50];
    int edad;
    char cedula[15];
    char telefono[15];
    char asesor[50];
    float efectivo;   // Dinero disponible del cliente
} Cliente;


typedef struct {
    Vehiculo vehiculo;
    Cliente cliente;
    char vendedor[50];   // 👈 NUEVO
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
int pedirCedulaClienteVenta(Cliente *clienteVenta);
void guardarVenta(Venta *venta);
void venderVehiculo(Economia *eco);
void mostrarVentas();
void buscarClienteMenu();
void eliminarVehiculo();
void informeGanancias(Economia *eco);
void cargarEconomia(Economia *eco);
void guardarEconomia(Economia *eco);
int buscarClientePorCedula(char *cedula, Cliente *clienteEncontrado);