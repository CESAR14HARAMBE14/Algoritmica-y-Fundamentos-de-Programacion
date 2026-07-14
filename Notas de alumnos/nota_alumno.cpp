#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// 1. Estructura de datos actualizada
struct Alumno {
    string nombre;
    string apellido;
    string codigo;   // <--- NUEVO CAMPO
    double promedio;
};

// 2. Regla de ordenamiento
bool ordenarDescendente(const Alumno& a, const Alumno& b) {
    return a.promedio > b.promedio;
}

int main() {
    vector<Alumno> listaAlumnos;
    string archivoDatos = "registro_alumnos.txt";

    // ==========================================
    // FASE 1: CARGAR DATOS ANTERIORES
    // ==========================================
    ifstream archivoLeyendo(archivoDatos);
    if (archivoLeyendo.is_open()) {
        string nom, ape, cod;
        double prom;
        
        // Ahora leemos tres campos de texto separados por coma, más el número
        while (getline(archivoLeyendo, nom, ',')) {
            getline(archivoLeyendo, ape, ',');
            getline(archivoLeyendo, cod, ','); // Leemos el código
            archivoLeyendo >> prom;
            archivoLeyendo >> ws; // Limpiar salto de línea
            
            listaAlumnos.push_back({nom, ape, cod, prom});
        }
        archivoLeyendo.close();
        cout << "[Info] Se cargaron " << listaAlumnos.size() << " alumnos del historial.\n";
    }

    // ==========================================
    // FASE 2: REGISTRAR NUEVOS ALUMNOS
    // ==========================================
    ofstream archivoCrudo(archivoDatos, ios::app);
    ofstream archivoTabla("registro_humano.txt", ios::app);

    if (!archivoCrudo.is_open() || !archivoTabla.is_open()) {
        cerr << "Error: No se pudieron crear los archivos de registro.\n";
        return 1;
    }

    int cantidad;
    cout << "\n--- REGISTRO DE NUEVOS ALUMNOS ---\n";
    cout << "¿Cuantos alumnos deseas registrar hoy? (Ingresa 0 para saltar y solo ordenar): ";
    cin >> cantidad;

    if (cantidad > 0) {
        // Se actualiza el encabezado del archivo humano
        archivoTabla << "\n--- NUEVA SESION DE REGISTRO ---\n";
        archivoTabla << left << setw(20) << "Nombre" 
                     << setw(20) << "Apellido(s)" 
                     << setw(15) << "Codigo" 
                     << "Promedio\n";
        archivoTabla << "------------------------------------------------------------------\n";
    }

    for (int i = 0; i < cantidad; ++i) {
        string nombre, apellido, codigo;
        double promedio;

        cout << "\nDatos del alumno " << (i + 1) << ":\n";
        
        cout << "Nombre: ";
        cin >> ws; 
        getline(cin, nombre);
        
        cout << "Apellido(s): ";
        getline(cin, apellido);
        
        cout << "Codigo: ";
        getline(cin, codigo); // Pedimos el código
        
        cout << "Promedio: ";
        cin >> promedio;

        // Añadir a la memoria
        listaAlumnos.push_back({nombre, apellido, codigo, promedio});

        // Guardar en archivo CSV (ahora con 4 datos)
        archivoCrudo << nombre << "," << apellido << "," << codigo << "," << promedio << "\n";
        
        // Guardar en tabla humana
        archivoTabla << left << setw(20) << nombre 
                     << setw(20) << apellido 
                     << setw(15) << codigo 
                     << fixed << setprecision(2) << promedio << "\n";
    }

    archivoCrudo.close();
    archivoTabla.close();

    // ==========================================
    // FASE 3: ORDENAR Y GENERAR REPORTE DE MÉRITO
    // ==========================================
    if (listaAlumnos.empty()) {
        cout << "\nNo hay alumnos para ordenar. Saliendo del programa...\n";
        return 0;
    }

    cout << "\nOrden de Merito generado\n";
    
    sort(listaAlumnos.begin(), listaAlumnos.end(), ordenarDescendente);

    ofstream archivoMerito("orden_merito.txt");
    
    string separador = "-------------------------------------------------------------------------\n";
    // Actualizamos los encabezados de la tabla de mérito
    string encabezado = "Puesto | Promedio | Codigo      | Nombre               | Apellido\n";
    
    archivoMerito << encabezado << separador;

    for (size_t i = 0; i < listaAlumnos.size(); ++i) {
        // Ajustamos los anchos (setw) para que las columnas cuadren con el encabezado
        archivoMerito << left << setw(9) << (i + 1) 
                      << setw(11) << fixed << setprecision(2) << listaAlumnos[i].promedio 
                      << setw(14) << listaAlumnos[i].codigo
                      << setw(23) << listaAlumnos[i].nombre 
                      << listaAlumnos[i].apellido << "\n";
    }
    
    archivoMerito.close();

    cout << "------------------------------------------------------\n";

    return 0;
}