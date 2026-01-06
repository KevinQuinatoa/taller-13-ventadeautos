    #include <stdio.h>
    #include <string.h> 
    #include "funcion.h"

    int menu(){
        int opc;
        printf("----------------   CONCESIONARIA 'RUEDAS DE ORO' SISTEMA DE GESTION SGIC  ----------------\n");
        printf("1. Registrar vehiculo\n");
        printf("2. Registrar cliente\n");
        printf("3. Mostrar vehiculos registrados\n");
        printf("4. Mostrar datos de ventas\n");
        printf("5. Buscar vehiculo por placa\n");
        printf("6. Buscar vehiculos por marca\n");
        printf("7. Buscar vehiculo por presupuesto\n");
        printf("8. Buscar cliente\n");
        printf("9. Vender vehiculo\n");
        printf("10. Eliminar vehiculo\n");
        printf("11. Informe de ganancias\n");
        printf("12. Salir\n");
        printf("Seleccione una opcion: ");
        opc = opcionValida(1,12);
        return opc;
    }

    int opcionValida(int min, int max){
        int numero;
        while (1)
        {
            if (scanf ("%d", &numero) ==1 && numero >= min && numero<=max)
            {
                while(getchar()!='\n');
                return numero;
            }else{
                printf("Error, ingrese una opcion valida: ");
                while(getchar()!='\n');
            } 
        }
    }

    void eliminarSaltoLinea(char *cadena, int n){
        fflush(stdin);
        fgets(cadena, n, stdin);
        int len= strlen(cadena) - 1;
        cadena[len] = '\0';
    }

    int menu2(){
        int opc2;
        printf("Seleccione la marca del vehiculo:\n");
        printf("1. Toyota\n");
        printf("2. Chevrolet\n");
        printf("3. hyundai\n");
        printf("Seleccione una opcion: ");
        opc2 = opcionValida(1,3);
        return opc2;
    }

    int menuToyota(){
        int opc3;
        printf("Seleccione el modelo del vehiculo:\n");
        printf("1. Hilux\n");
        printf("2. Corolla\n");
        printf("3. RAV4\n");
        printf("Seleccione una opcion: ");
        opc3 = opcionValida(1,3);
        return opc3;
    }

    int menuChevrolet(){
        int opc3;
        printf("Seleccione el modelo del vehiculo:\n");
        printf("1. Silverado\n");
        printf("2. Malibu\n");
        printf("3. Equinox\n");
        printf("Seleccione una opcion: ");
        opc3 = opcionValida(1,3);
        return opc3;
    }

    int menuHyundai(){
        int opc3;
        printf("Seleccione el modelo del vehiculo:\n");
        printf("1. Tucson\n");
        printf("2. Elantra\n");
        printf("3. Santa Fe\n");
        printf("Seleccione una opcion: ");
        opc3 = opcionValida(1,3);
        return opc3;
    }

    int menuTipo(){
        int opc4;
        printf("Seleccione el tipo del vehiculo:\n");
        printf("1. Sedan\n");
        printf("2. SUV\n");
        printf("3. Camioneta\n");
        printf("Seleccione una opcion: ");
        opc4 = opcionValida(1,3);
        return opc4;
    }

    int menuEstado(){
        int opc5;
        printf("Seleccione el estado del vehiculo:\n");
        printf("1. Nuevo\n");
        printf("2. Usado\n");
        printf("Seleccione una opcion: ");
        opc5 = opcionValida(1,2);
        return opc5;
    }

    void ingresarVehiculo(Economia *eco){
        Vehiculo vehiculo;
        int opc2, opc3, opc4, opc5;

        printf("Ingrese la placa del vehiculo: ");
        while (1) {
        eliminarSaltoLinea(vehiculo.placa, 10);
        // Validación: NO permitir cadena vacía ni solo espacios
        if (strlen(vehiculo.placa) == 0) {
            printf("La placa no puede estar vacio. Ingrese nuevamente: ");
            continue;
        }

        // NO permitir negativo: si comienza con '-'
        if (vehiculo.placa[0] == '-') {
            printf("No se permiten placas negativas. Ingrese nuevamente: ");
            continue;
        }
        break;
        }  
        
    if (placaExiste(vehiculo.placa)){
        printf("Error: la placa ya existe.\n");
        return;
    }


        printf("Ingrese la marca del vehiculo:\n");
        opc2 = menu2();
        switch (opc2)
        {
        case 1:
            strcpy(vehiculo.marca, "Toyota");
            opc3 = menuToyota();
            switch (opc3)
            {
            case 1:
                strcpy(vehiculo.modelo, "Hilux");
                break;
            case 2:
                strcpy(vehiculo.modelo, "Corolla");
                break;
            case 3:
                strcpy(vehiculo.modelo, "RAV4");
                break;
            }
            break;
        case 2:
            strcpy(vehiculo.marca, "Chevrolet");
            opc3 = menuChevrolet();
            switch (opc3)
            {
            case 1:
                strcpy(vehiculo.modelo, "Silverado");
                break;
            case 2:
                strcpy(vehiculo.modelo, "Malibu");
                break;
            case 3:
                strcpy(vehiculo.modelo, "Equinox");
                break;
            }
            break;
        case 3:
            strcpy(vehiculo.marca, "Hyundai");
            opc3 = menuHyundai();
            switch (opc3)
            {
            case 1:
                strcpy(vehiculo.modelo, "Tucson");
                break;
            case 2:
                strcpy(vehiculo.modelo, "Elantra");
                break;
            case 3:
                strcpy(vehiculo.modelo, "Santa Fe");
                break;
            }
            break;
        }

        opc4 = menuTipo();
        switch (opc4)
        {
        case 1:
            strcpy(vehiculo.tipo, "Sedan");
            break;
        case 2:
            strcpy(vehiculo.tipo, "SUV");
            break;
        case 3:
            strcpy(vehiculo.tipo, "Camioneta");
            break;
        }

        opc5 = menuEstado();
        switch (opc5)
        {
        case 1:
            strcpy(vehiculo.estado, "Nuevo");
            break;
        case 2:
            strcpy(vehiculo.estado, "Usado");
            break;
        }
          vehiculo.tipoIngreso = menuIngreso();

       if (vehiculo.tipoIngreso == 1){
        printf("Ingrese el precio de compra del vehiculo: ");
        vehiculo.precioCompra = opcionValida(1000,1000000);

        eco->totalGastado += vehiculo.precioCompra;
        guardarEconomia(eco);
        } else {
        vehiculo.precioCompra = 0;
        }

        printf("Ingrese el precio de venta del vehiculo: ");
        vehiculo.precio = opcionValida(1000,1000000);

        vehiculo.disponible = 1;
        vehiculo.eliminado = 0;

        guardarVehiculo(&vehiculo);
    }


    int menuIngreso(){
    int opc;
    printf("Seleccione el tipo de ingreso del vehiculo:\n");
    printf("1. Compra (la concesionaria compra el vehiculo)\n");
    printf("2. Consignacion (solo para vender)\n");
    printf("Seleccione una opcion: ");
    opc = opcionValida(1,2);
    return opc;
    }

    void registrarCliente(){
    Cliente cliente;

    printf("Ingrese el nombre del cliente: ");
    eliminarSaltoLinea(cliente.nombre, 50);

    // Edad
    printf("Ingrese la edad del cliente: ");
    cliente.edad = opcionValida(18, 100);

    // Cedula
    int valido = 0;
    while (!valido){
        printf("Ingrese la cedula del cliente (10 digitos): ");
        eliminarSaltoLinea(cliente.cedula, 15);

        if (strlen(cliente.cedula) != 10){
            printf("Error: la cedula debe tener 10 digitos.\n");
            continue;
        }

        int esNumero = 1;
        for (int i = 0; i < 10; i++){
            if (cliente.cedula[i] < '0' || cliente.cedula[i] > '9'){
                esNumero = 0;
                break;
            }
        }

        if (!esNumero){
            printf("Error: la cedula solo debe contener numeros.\n");
            continue;
        }

        valido = 1;
    }

    // Teléfono
    valido = 0;
    while (!valido){
        printf("Ingrese el telefono del cliente (10 digitos): ");
        eliminarSaltoLinea(cliente.telefono, 15);

        if (strlen(cliente.telefono) != 10){
            printf("Error: el telefono debe tener 10 digitos.\n");
            continue;
        }

        int esNumero = 1;
        for (int i = 0; i < 10; i++){
            if (cliente.telefono[i] < '0' || cliente.telefono[i] > '9'){
                esNumero = 0;
                break;
            }
        }

        if (!esNumero){
            printf("Error: el telefono solo debe contener numeros.\n");
            continue;
        }

        valido = 1;
    }

    // Asesor
    printf("Ingrese el nombre del asesor que atiende al cliente: ");
    eliminarSaltoLinea(cliente.asesor, 50);

    // Efectivo disponible
    printf("Ingrese el efectivo disponible del cliente: ");
    while (scanf("%f", &cliente.efectivo) != 1 || cliente.efectivo < 0){
        printf("Error. Ingrese un monto valido: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    guardarCliente(&cliente);
    printf("Cliente registrado correctamente.\n");
    }



    void mostrarVehiculos(){
        Vehiculo vehiculos[100];
        int cont = leerVehiculos(vehiculos);
        int hay = 0;

        if (cont == 0){
            printf("No hay vehiculos registrados.\n");
            return;
        }

        for (int i = 0; i < cont; i++){
            if (vehiculos[i].disponible == 1 && vehiculos[i].eliminado == 0) {
                printf("Placa: %s\n", vehiculos[i].placa);
                printf("Marca: %s\n", vehiculos[i].marca);
                printf("Modelo: %s\n", vehiculos[i].modelo);
                printf("Tipo: %s\n", vehiculos[i].tipo);
                printf("Estado: %s\n", vehiculos[i].estado);
                printf("Precio: $%.2f\n", vehiculos[i].precio);
                printf("-------------------------------------\n");
                hay = 1;
            }
        }

        if (!hay) {
            printf("No hay vehiculos disponibles para mostrar.\n");
        }
    }



    void guardarVehiculo(Vehiculo *vehiculo){
    FILE *f;
    f = fopen("vehiculos.dat", "ab+");

    if (f == NULL){
        printf("No se puede abrir el archivo de vehiculos.\n");
        return;
    }

    fwrite(vehiculo, sizeof(Vehiculo), 1, f);
    fclose(f);

    printf("Vehiculo registrado correctamente.\n");
    }

    int leerVehiculos(Vehiculo *vehiculos){
    FILE *f;
    f = fopen("vehiculos.dat", "rb");

    if (f == NULL){
        return 0;
    }

    int count = fread(vehiculos, sizeof(Vehiculo), 100, f);
    fclose(f);
    return count;
    }



    void guardarCliente(Cliente *cliente){
    FILE *f;
    f = fopen("clientes.dat", "ab+");

    if (f == NULL){
        printf("No se puede abrir el archivo de clientes.\n");
        return;
    }

    fwrite(cliente, sizeof(Cliente), 1, f);
    fclose(f);

    printf("Cliente registrado correctamente.\n");
    }


    int leerClientes(Cliente *clientes){
    FILE *f;
    f = fopen("clientes.dat", "rb");

    if (f == NULL){
        return 0;
    }

    int count = fread(clientes, sizeof(Cliente), 50, f);
    fclose(f);
    return count;
    }


    int placaExiste(char *placa) {
    FILE *f;
    Vehiculo v;

    f = fopen("vehiculos.dat", "rb");
    if (f == NULL) return 0;

    while (fread(&v, sizeof(Vehiculo), 1, f)) {
        if (strcmp(v.placa, placa) == 0 && v.eliminado == 0) {
            fclose(f);
            return 1; // SOLO si NO está eliminado
        }
    }

    fclose(f);
    return 0;
    }



    void buscarVehiculoPorPlaca(){
        FILE *f;
        Vehiculo v;
        char placaBuscada[10];
        int encontrado = 0;

        printf("Ingrese la placa a buscar: ");
        while (1) {
        eliminarSaltoLinea(placaBuscada, 10);
        // Validación: NO permitir cadena vacía ni solo espacios
        if (strlen(placaBuscada) == 0) {
            printf("La placa no puede estar vacio. Ingrese nuevamente: ");
            continue;
        }

        // NO permitir negativo: si comienza con '-'
        if (placaBuscada[0] == '-') {
            printf("No se permiten placas negativas. Ingrese nuevamente: ");
            continue;
        }
        break;
        }   

        f = fopen("vehiculos.dat", "rb");
        if (f == NULL){
            printf("No hay vehiculos registrados.\n");
            return;
        }

        while (fread(&v, sizeof(Vehiculo), 1, f)){
            if (strcmp(v.placa, placaBuscada) == 0 &&
            v.disponible == 1 &&
            v.eliminado == 0){
                printf("\nVehiculo encontrado:\n");
                printf("Placa: %s\n", v.placa);
                printf("Marca: %s\n", v.marca);
                printf("Modelo: %s\n", v.modelo);
                printf("Tipo: %s\n", v.tipo);
                printf("Estado: %s\n", v.estado);
                printf("Precio: $%.2f\n", v.precio);
                printf("Disponible: %s\n", v.disponible ? "SI" : "NO");

                encontrado = 1;
                break;
            }
        }

        fclose(f);

        if (!encontrado){
            printf("Vehiculo no encontrado.\n");
        }
    }

    void buscarVehiculosPorMarca(){
        FILE *f;
        Vehiculo v;
        char marcaBuscado[20];
        int encontrados = 0;

        printf("Ingrese el modelo a buscar: ");
        eliminarSaltoLinea(marcaBuscado, 20);

        f = fopen("vehiculos.dat", "rb");
        if (f == NULL){
            printf("No hay vehiculos registrados.\n");
            return;
        }

        while (fread(&v, sizeof(Vehiculo), 1, f)){
            if (strcmp(v.marca, marcaBuscado) == 0 &&
            v.disponible == 1 &&
            v.eliminado == 0){
                printf("\nPlaca: %s\n", v.placa);
                printf("Marca: %s\n", v.marca);
                printf("Modelo: %s\n", v.modelo);
                printf("Precio: $%.2f\n", v.precio);
                printf("---------------------------------\n");
                encontrados++;
            }
        }

        fclose(f);

        if (encontrados == 0){
            printf("No se encontraron vehiculos con esa marca.\n");
        }
    }

    void buscarVehiculosPorPresupuesto(){
        FILE *f;
        Vehiculo v;
        float presupuesto;
        int encontrados = 0;

        printf("Ingrese el presupuesto maximo del cliente: ");
        presupuesto = opcionValida(1000, 1000000);

        f = fopen("vehiculos.dat", "rb");
        if (f == NULL){
            printf("No hay vehiculos registrados.\n");
            return;
        }

        while (fread(&v, sizeof(Vehiculo), 1, f)){
            if (v.precio <= presupuesto &&
            v.disponible == 1 &&
            v.eliminado == 0){
                printf("\nPlaca: %s\n", v.placa);
                printf("Marca: %s\n", v.marca);
                printf("Modelo: %s\n", v.modelo);
                printf("Precio: $%.2f\n", v.precio);
                printf("---------------------------------\n");
                encontrados++;
            }
        }

        fclose(f);

        if (encontrados == 0){
            printf("No hay vehiculos dentro del presupuesto.\n");
        }
    }


    int pedirCedulaClienteVenta(Cliente *clienteVenta) {
    char cedula[15];

    printf("\nIngrese la cedula del cliente: ");
    eliminarSaltoLinea(cedula, 15);

    if (buscarClientePorCedula(cedula, clienteVenta)) {
        return 1; // cliente encontrado
    }

    printf("Cliente no registrado. Debe registrarlo primero.\n");
    return 0;
    }

    void guardarVenta(Venta *venta) {
    FILE *f = fopen("ventas.dat", "ab+");
    if (f == NULL) {
        printf("Error al guardar la venta.\n");
        return;
    }

    fwrite(venta, sizeof(Venta), 1, f);
    fclose(f);
    }

    void guardarEconomia(Economia *eco) {
        FILE *f = fopen("economia.dat", "wb+");
        if (f == NULL) {
            printf("Error al guardar economia\n");
            return;
        }
        fwrite(eco, sizeof(Economia), 1, f);
        fclose(f);
    }

    void cargarEconomia(Economia *eco) {
        FILE *f = fopen("economia.dat", "rb+");
        if (f == NULL) {
            eco->totalGastado = 0;
            eco->totalGanado = 0;
            return;
        }
        fread(eco, sizeof(Economia), 1, f);
        fclose(f);
    }


    void venderVehiculo(Economia *eco) {
    FILE *f;
    Vehiculo v;
    char placaBuscada[10];
    int encontrado = 0;
    Cliente clienteVenta;
    long pos;
    Venta venta;

    f = fopen("vehiculos.dat", "rb+");
    if (f == NULL) {
        printf("Error al abrir el archivo de vehiculos\n");
        return;
    }

    printf("Ingrese la placa del vehiculo a vender: ");
    eliminarSaltoLinea(placaBuscada, 10);

    while (fread(&v, sizeof(Vehiculo), 1, f)) {
        if (strcmp(v.placa, placaBuscada) == 0 && v.eliminado == 0) {
            encontrado = 1;

            if (v.disponible == 0) {
                printf("El vehiculo ya fue vendido.\n");
                fclose(f);
                return;
            }

            // Mostrar datos del vehiculo
            printf("\nVehiculo encontrado:\n");
            printf("Marca: %s\n", v.marca);
            printf("Modelo: %s\n", v.modelo);
            printf("Precio: $%.2f\n", v.precio);

            printf("\nDesea vender este vehiculo?\n");
            printf("1. Si\n2. No\n>> ");
            int opc = opcionValida(1, 2);

            if (opc == 2) {
                fclose(f);
                return;
            }

            // Buscar cliente por cedula
            char cedula[15];
            printf("Ingrese la cedula del cliente: ");
            eliminarSaltoLinea(cedula, 15);

            if (!buscarClientePorCedula(cedula, &clienteVenta)) {
                printf("Cliente no registrado.\n");
                fclose(f);
                return;
            }

            // VALIDAR EFECTIVO
            if (clienteVenta.efectivo < v.precio) {
                printf("\nEl cliente NO tiene suficiente efectivo.\n");
                printf("Disponible: $%.2f\n", clienteVenta.efectivo);
                printf("Precio del vehiculo: $%.2f\n", v.precio);
                fclose(f);
                return;
            }

            // Calcular ganancias
            if (v.tipoIngreso == 1) { // Compra
                eco->totalGanado += (v.precio - v.precioCompra);
            } else { // Consignación
                eco->totalGanado += v.precio;
            }

            guardarEconomia(eco);

            // Descontar dinero al cliente
            clienteVenta.efectivo -= v.precio;
            guardarCliente(&clienteVenta); // función que reescribe el cliente

            // Marcar vehiculo como vendido
            v.disponible = 0;

            // Preparar venta
            venta.vehiculo = v;
            venta.cliente = clienteVenta;
            venta.montoVenta = v.precio;

            // Sobrescribir vehiculo en archivo
            pos = ftell(f) - sizeof(Vehiculo);
            fseek(f, pos, SEEK_SET);
            fwrite(&v, sizeof(Vehiculo), 1, f);
            printf("Ingrese el nombre del vendedor: ");
            eliminarSaltoLinea(venta.vendedor, 50);
            // Guardar venta
            guardarVenta(&venta);

            printf("\nVehiculo vendido exitosamente.\n");
            fclose(f);
            return;
        }
    }

    if (!encontrado) {
        printf("Vehiculo no encontrado.\n");
    }

    fclose(f);
    }


    void eliminarVehiculo() {
        FILE *f;
        Vehiculo v;
        char placaBuscada[10];
        long pos;
        int encontrado = 0;

        f = fopen("vehiculos.dat", "rb+");
        if (f == NULL) {
            printf("No se pudo abrir el archivo de vehiculos.\n");
            return;
        }

        printf("Ingrese la placa del vehiculo a eliminar: ");
        eliminarSaltoLinea(placaBuscada, 10);

        while (fread(&v, sizeof(Vehiculo), 1, f)) {
            if (strcmp(v.placa, placaBuscada) == 0) {
                encontrado = 1;

                if (v.disponible == 0) {
                    printf("El vehiculo ya no esta disponible.\n");
                    fclose(f);
                    return;
                }

                printf("\nVehiculo encontrado:\n");
                printf("Marca: %s\n", v.marca);
                printf("Modelo: %s\n", v.modelo);
                printf("Precio: $%.2f\n", v.precio);

                printf("\nDesea eliminar este vehiculo?\n");
                printf("1. Si\n2. No\n>> ");
                int opc = opcionValida(1, 2);

                if (opc == 2) {
                    fclose(f);
                    return;
                }

                v.disponible = 0;
                v.eliminado = 1;

                pos = ftell(f) - sizeof(Vehiculo);
                fseek(f, pos, SEEK_SET);
                fwrite(&v, sizeof(Vehiculo), 1, f);

                printf("Vehiculo eliminado correctamente.\n");
                fclose(f);
                return;
            }
        }

        if (!encontrado) {
            printf("Vehiculo no encontrado.\n");
        }

        fclose(f);
    }


    void informeGanancias(Economia *eco) {
        printf("----- Informe de Ganancias -----\n");
        printf("Total Gastado: $%.2f\n", eco->totalGastado);
        printf("Total Ganado: $%.2f\n", eco->totalGanado);
        printf("Ganancia Neta: $%.2f\n", eco->totalGanado - eco->totalGastado);
        printf("--------------------------------\n");
    }

    void mostrarVentas() {
    FILE *f = fopen("ventas.dat", "rb");
    Venta v;

    if (f == NULL) {
        printf("No existen ventas registradas.\n");
        return;
    }

    printf("\n====== HISTORIAL DE VENTAS ======\n");

    while (fread(&v, sizeof(Venta), 1, f)) {

        printf("\n--- DATOS DEL CLIENTE ---\n");
        printf("Nombre: %s\n", v.cliente.nombre);
        printf("Edad: %d años\n", v.cliente.edad);
        printf("Telefono: %s\n", v.cliente.telefono);

        printf("\n--- DATOS DEL VENDEDOR ---\n");
        printf("Atendido por: %s\n", v.vendedor);

        printf("\n--- DATOS DEL VEHICULO ---\n");
        printf("Placa: %s\n", v.vehiculo.placa);
        printf("Marca: %s\n", v.vehiculo.marca);
        printf("Modelo: %s\n", v.vehiculo.modelo);
        printf("Precio de venta: $%.2f\n", v.montoVenta);

        printf("---------------------------------\n");
    }

    fclose(f);
    }


    void buscarClienteMenu() {
    char cedula[15];
    Cliente cliente;

    // Limpiar buffer antes de fgets
    while (getchar() != '\n');

    printf("Ingrese la cedula del cliente: ");
    eliminarSaltoLinea(cedula, 15);

    if (strlen(cedula) == 0) {
        printf("No se ingreso ninguna cedula.\n");
        return;
    }

    if (buscarClientePorCedula(cedula, &cliente)) {
        printf("\n--- CLIENTE ENCONTRADO ---\n");
        printf("Nombre  : %s\n", cliente.nombre);
        printf("Cedula  : %s\n", cliente.cedula);
        printf("Telefono: %s\n", cliente.telefono);
    } else {
        printf("Cliente no encontrado.\n");
    }
    }


    int buscarClientePorCedula(char *cedula, Cliente *clienteEncontrado) {
    FILE *f;
    Cliente c;

    f = fopen("clientes.dat", "rb+");
    if (f == NULL) {
        return 0; // No hay archivo o no existen clientes
    }

    while (fread(&c, sizeof(Cliente), 1, f)) {
        if (strcmp(c.cedula, cedula) == 0) {
            *clienteEncontrado = c; // Copiar datos del cliente
            fclose(f);
            return 1; // Cliente encontrado
        }
    }

    fclose(f);
    return 0; // Cliente no encontrado
}
