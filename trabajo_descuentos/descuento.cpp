#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Producto {
    string nombre;
    double precio;
    int stockRegistrado;
};

// ==========================================
// MÓDULO 1: Carga y Visualización
// ==========================================
bool cargarCatalogo(const string& nombreArchivo, vector<Producto>& catalogo) {
    ifstream archivoEntrada(nombreArchivo); 

    if (!archivoEntrada.is_open()) {
        cerr << "Error: No se pudo abrir " << nombreArchivo << "\n";
        return false; 
    }

    string nombre;
    double precio;
    int cantidad;

    while (archivoEntrada >> nombre >> precio >> cantidad) {
        catalogo.push_back({nombre, precio, cantidad});
    }

    archivoEntrada.close();
    return true;
}

void mostrarMenu(const vector<Producto>& catalogo) {
    cout << "\n--- CATALOGO DE PRODUCTOS ---\n";
    cout << left << setw(5) << "Nro" << setw(20) << "Producto" << "Precio\n";
    cout << "-----------------------------------\n";
    for (size_t i = 0; i < catalogo.size(); ++i) {
        cout << left << setw(5) << (i + 1) 
             << setw(20) << catalogo[i].nombre 
             << "$" << fixed << setprecision(2) << catalogo[i].precio << "\n";
    }
    cout << "-----------------------------------\n";
}

// ==========================================
// MÓDULO 2: Procesamiento y Salida
// ==========================================
void registrarVenta(const Producto& p, int cantidadComprada, double descManualPct, const string& archivoSalida) {
    double subtotal = p.precio * cantidadComprada;
    double descuentoAutomatico = 0.0;

    // 1. Reglas automáticas originales
    if (cantidadComprada > 5) descuentoAutomatico += subtotal * 0.10;
    if (p.precio > 1000.0) descuentoAutomatico += subtotal * 0.05;
    if (p.nombre == "Impresora") descuentoAutomatico += 50.0 * cantidadComprada;

    // 2. Aplicar descuento manual ingresado por el usuario
    double descuentoManualTotal = subtotal * (descManualPct / 100.0);
    
    // Total de descuentos
    double descuentoTotal = descuentoAutomatico + descuentoManualTotal;
    if (descuentoTotal > subtotal) descuentoTotal = subtotal; // Seguridad

    double precioFinal = subtotal - descuentoTotal;

    // ---> NUEVO: Calcular porcentaje efectivo de descuento aplicado <---
    double porcentajeEfectivo = 0.0;
    if (subtotal > 0) {
        porcentajeEfectivo = (descuentoTotal / subtotal) * 100.0;
    }

    // 3. Escribir en el archivo usando modo "app" (Append - Añadir)
    ofstream archivo(archivoSalida, ios::app);

    if (archivo.is_open()) {
        // Fijamos los decimales a 2 para dinero y porcentajes
        archivo << left << fixed << setprecision(2);
        
        // Escribimos la venta incluyendo la nueva columna
        archivo << setw(20) << p.nombre 
                << setw(10) << cantidadComprada 
                << setw(15) << subtotal 
                << setw(15) << porcentajeEfectivo // Columna de porcentaje
                << setw(15) << descuentoTotal 
                << "$" << precioFinal << "\n";
        
        archivo.close();
        
        // Confirmación en pantalla
        cout << "\n¡Venta registrada con exito!\n";
        cout << "Subtotal: $" << subtotal << "\n";
        cout << "Descuento total aplicado: $" << descuentoTotal << " (" << porcentajeEfectivo << "%)\n";
        cout << "Total a pagar: $" << precioFinal << "\n";
    } else {
        cerr << "Error al abrir el archivo de reporte para escribir.\n";
    }
}

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    vector<Producto> catalogo;
    string archivoDatos = "productos.txt";
    string archivoResultados = "reporte_ventas.txt";

    // Intentamos cargar el archivo
    if (!cargarCatalogo(archivoDatos, catalogo)) {
        return 1; // Salir si hay error
    }

    // Inicializar el archivo de reporte con los nuevos encabezados
    ofstream initArchivo(archivoResultados, ios::app);
    initArchivo << "\nNUEVA SESION DE VENTAS\n";
    // ---> NUEVO: Se añade el encabezado "% Desc." y se ajustan los anchos <---
    initArchivo << left << setw(20) << "Producto" 
                << setw(10) << "Cant." 
                << setw(15) << "Subtotal" 
                << setw(15) << "% Desc." 
                << setw(15) << "Desc. ($)" 
                << "Total Pagado\n";
    initArchivo << "-----------------------------------------------------------------------------------------\n";
    initArchivo.close();

    int opcion;
    int cantidad;
    double descuentoExtra;

    // Flujo interactivo con el usuario
    mostrarMenu(catalogo);
    
    cout << "\nElige el numero del producto que deseas comprar: ";
    cin >> opcion;

    if (opcion < 1 || opcion > catalogo.size()) {
        cout << "Opcion invalida. Cancelando operacion.\n";
        return 1;
    }

    cout << "Cuantas unidades de '" << catalogo[opcion - 1].nombre << "' deseas comprar?: ";
    cin >> cantidad;

    cout << "Ingresa un % de descuento adicional a aplicar (ej. 15 para 15%, 0 para ninguno): ";
    cin >> descuentoExtra;

    // Procesar y guardar
    registrarVenta(catalogo[opcion - 1], cantidad, descuentoExtra, archivoResultados);

    return 0;
}