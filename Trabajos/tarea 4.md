## 1 Suma de elementos en vector: Leer un vector de enteros y calcular la suma total.
  ```C++
  #include <iostream>
#include <vector>

using namespace std;

int main() {
    int cantidad;

    // 1. Pedir la cantidad de elementos
    cout << "Ingrese la cantidad de elementos del vector: ";
    cin >> cantidad;

    // Crear el vector con el tamaño especificado
    vector<int> numeros(cantidad);

    // 2. Leer los datos del vector
    cout << "\n--- Ingrese los números ---" << endl;
    for (int i = 0; i < cantidad; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> numeros[i];
    }

    // 3. Calcular la suma total
    int suma = 0;
    // Usamos un bucle "for-each" (basado en rango) para recorrer el vector fácilmente
    for (int num : numeros) {
        suma += num;
    }

    // 4. Mostrar el resultado
    cout << "\n La suma total de los elementos es: " << suma << endl;

    return 0;
}
  ```
## 2. Promedio de notas: Ingresar notas en un vector y calcular el promedio.
```C++
#include <iostream>
#include <vector>
#include <iomanip> // Necesario para fijar los decimales

using namespace std;

int main() {
    int cantidad;

    // 1. Pedir la cantidad de notas
    cout << "Ingrese la cantidad de notas a promediar: ";
    cin >> cantidad;

    // Validación básica: evitar la división por cero o arreglos negativos
    if (cantidad <= 0) {
        cout << "❌ La cantidad de notas debe ser mayor a 0." << endl;
        return 1; // Termina el programa con error
    }

    // Crear un vector de tipo double para almacenar decimales
    vector<double> notas(cantidad);

    // 2. Leer las notas y guardarlas en el vector
    cout << "\n--- Ingrese las notas ---" << endl;
    for (int i = 0; i < cantidad; ++i) {
        cout << "Nota " << i + 1 << ": ";
        cin >> notas[i];
    }

    // 3. Calcular la suma total usando los elementos del vector
    double suma = 0.0;
    for (double nota : notas) {
        suma += nota;
    }

    // 4. Calcular el promedio
    double promedio = suma / cantidad;

    // 5. Mostrar el resultado formateado a 2 decimales
    cout << "\n✅ El promedio de las notas es: " << fixed << setprecision(2) << promedio << endl;

    return 0;
}
```
## 3. Matriz identidad: Generar una matriz identidad de tamaño n.
```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    // 1. Pedir el tamaño de la matriz
    cout << "Ingrese el tamano de la matriz identidad (n): ";
    cin >> n;

    // Validar que el tamaño sea un número positivo
    if (n <= 0) {
        cout << "Error: El tamano debe ser un numero entero mayor a 0." << endl;
        return 1;
    }

    // 2. Declarar una matriz (vector de vectores) de tamaño n x n inicializada en 0
    vector<vector<int>> matriz(n, vector<int>(n, 0));

    // 3. Generar la matriz identidad asignando 1 a la diagonal principal
    for (int i = 0; i < n; ++i) {
        matriz[i][i] = 1; 
    }

    // 4. Mostrar la matriz en pantalla
    cout << "\n--- Matriz Identidad de " << n << "x" << n << " ---" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl; // Salto de linea al terminar cada fila
    }

    return 0;
}
```
## 4. Máximo y mínimo: Encontrar el mayor y menor valor en un vector.
```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    // 1. Pedir la cantidad de elementos
    cout << "Ingrese la cantidad de elementos del vector: ";
    cin >> n;

    // Validar que el vector tenga al menos un elemento
    if (n <= 0) {
        cout << "Error: El vector debe tener al menos un elemento." << endl;
        return 1;
    }

    vector<int> numeros(n);

    // 2. Leer los datos del vector
    cout << "\n--- Ingrese los numeros ---" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> numeros[i];
    }

    // 3. Inicializar los valores maximo y minimo con el primer elemento
    int maximo = numeros[0];
    int minimo = numeros[0];

    // 4. Recorrer el resto del vector para comparar
    for (int i = 1; i < n; ++i) {
        if (numeros[i] > maximo) {
            maximo = numeros[i]; // Se encontro un nuevo numero mayor
        }
        if (numeros[i] < minimo) {
            minimo = numeros[i]; // Se encontro un nuevo numero menor
        }
    }

    // 5. Mostrar los resultados
    cout << "\n--- Resultados ---" << endl;
    cout << "El valor maximo es: " << maximo << endl;
    cout << "El valor minimo es: " << minimo << endl;

    return 0;
}
```
## 5. Función factorial: Implementar una función que calcule el factorial de un número.
```C++
#include <iostream>
using namespace std;

// 1. Declaracion de la funcion factorial
// Se usa 'unsigned long long' porque los factoriales crecen extremadamente rapido
unsigned long long calcularFactorial(int n) {
    // Caso base: el factorial de 0 y 1 es 1
    if (n == 0 || n == 1) {
        return 1;
    }
    
    unsigned long long resultado = 1;
    // Multiplicar los numeros desde 2 hasta n
    for (int i = 2; i <= n; ++i) {
        resultado *= i;
    }
    
    return resultado;
}

int main() {
    int numero;

    // 2. Pedir el numero al usuario
    cout << "Ingrese un numero entero positivo para calcular su factorial: ";
    cin >> numero;

    // 3. Validar el input (no existe factorial para numeros negativos)
    if (numero < 0) {
        cout << "Error: El factorial no esta definido para numeros negativos." << endl;
    } else {
        // 4. Llamar a la funcion y mostrar el resultado
        unsigned long long resultado = calcularFactorial(numero);
        cout << "El factorial de " << numero << " (" << numero << "!) es: " << resultado << endl;
    }

    return 0;
}
```
## 6. Ordenamiento burbuja: Implementar Bubble Sort en una cadena de caracteres.
```C++
#include <iostream>
#include <string>

using namespace std;

// 1. Funcion para ordenar la cadena usando Bubble Sort
// Pasamos la cadena por referencia (&) para modificar la original directamente
void ordenamientoBurbuja(string &texto) {
    int n = texto.length();
    bool intercambiado;

    // Bucle externo para las pasadas totales
    for (int i = 0; i < n - 1; ++i) {
        intercambiado = false;

        // Bucle interno para comparar elementos adyacentes
        // n - i - 1 porque los ultimos 'i' elementos ya estaran ordenados
        for (int j = 0; j < n - i - 1; ++j) {
            // Comparamos el valor ASCII de los caracteres
            if (texto[j] > texto[j + 1]) {
                // Intercambio manual de caracteres
                char temporal = texto[j];
                texto[j] = texto[j + 1];
                texto[j + 1] = temporal;
                
                intercambiado = true;
            }
        }

        // Optimizacion: Si en una pasada completa no hubo intercambios,
        // significa que la cadena ya esta completamente ordenada.
        if (!intercambiado) {
            break; 
        }
    }
}

int main() {
    string texto;

    // 2. Pedir la cadena al usuario
    cout << "Ingrese una cadena de caracteres para ordenar: ";
    // Usamos getline por si el usuario ingresa una frase con espacios
    getline(cin, texto);

    cout << "\n--- Resultados ---" << endl;
    cout << "Cadena original: " << texto << endl;

    // 3. Llamar a la funcion de ordenamiento
    ordenamientoBurbuja(texto);

    // 4. Mostrar la cadena ordenada
    cout << "Cadena ordenada: " << texto << endl;

    return 0;
}
```
## 7. Ordenamiento por inserción: Implementar Insertion Sort en un vector de enteros.
```C++
#include <iostream>
#include <vector>

using namespace std;

// 1. Funcion para ordenar el vector usando Insertion Sort
// Pasamos el vector por referencia (&) para evitar copiarlo y modificar el original
void ordenamientoInsercion(vector<int>& arr) {
    int n = arr.size();
    
    // El bucle empieza en el indice 1 (segundo elemento), asumiendo que arr[0] esta ordenado
    for (int i = 1; i < n; ++i) {
        int clave = arr[i]; // Elemento actual que queremos insertar en su posicion correcta
        int j = i - 1;      // Indice del ultimo elemento de la sublista ya ordenada

        // Mover los elementos de arr[0..i-1] que son mayores que la 'clave'
        // a una posicion adelante de su posicion actual
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        // Insertar la 'clave' en su posicion final correcta
        arr[j + 1] = clave;
    }
}

int main() {
    int n;

    // 2. Pedir la cantidad de elementos
    cout << "Ingrese la cantidad de elementos del vector: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: El vector debe tener al menos un elemento." << endl;
        return 1;
    }

    vector<int> numeros(n);

    // 3. Leer los datos del vector
    cout
```
___
## 8. Transposición de matriz: Calcular la matriz transpuesta de una matriz n x m.
```C++
#include <iostream>
#include <vector>
#include <iomanip> // Para dar formato tabular a la salida

using namespace std;

int main() {
    int n, m;

    // 1. Pedir las dimensiones de la matriz original
    cout << "Ingrese el numero de filas (n): ";
    cin >> n;
    cout << "Ingrese el numero de columnas (m): ";
    cin >> m;

    // Validar dimensiones
    if (n <= 0 || m <= 0) {
        cout << "Error: Las dimensiones deben ser mayores a 0." << endl;
        return 1;
    }

    // 2. Declarar las matrices dinámica
    // Matriz original de tamaño n x m
    vector<vector<int>> matrizOriginal(n, vector<int>(m));
    
    // Matriz transpuesta de tamaño m x n (dimensiones invertidas)
    vector<vector<int>> matrizTranspuesta(m, vector<int>(n));

    // 3. Leer los elementos de la matriz original
    cout << "\n--- Ingrese los elementos de la matriz ---" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matrizOriginal[i][j];
        }
    }

    // 4. Calcular la transpuesta
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // El elemento de la fila i, columna j pasa a la fila j, columna i
            matrizTranspuesta[j][i] = matrizOriginal[i][j];
        }
    }

    // 5. Mostrar la matriz original
    cout << "\n--- Matriz Original (" << n << "x" << m << ") ---" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(5) << matrizOriginal[i][j] << " ";
        }
        cout << endl; // Salto de linea al terminar la fila
    }

    // 6. Mostrar la matriz transpuesta
    cout << "\n--- Matriz Transpuesta (" << m << "x" << n << ") ---" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(5) << matrizTranspuesta[i][j] << " ";
        }
        cout << endl; // Salto de linea al terminar la fila
    }

    return 0;
}
```
___
## 9. Multiplicación de matrices: Multiplicar dos matrices cuadradas.
```C++
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;

    // 1. Pedir el tamano de las matrices cuadradas
    cout << "Ingrese la dimension (n) de las matrices cuadradas: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: La dimension debe ser mayor a 0." << endl;
        return 1;
    }

    // 2. Declarar las tres matrices dinamicas de tamano n x n
    vector<vector<int>> matrizA(n, vector<int>(n));
    vector<vector<int>> matrizB(n, vector<int>(n));
    vector<vector<int>> matrizC(n, vector<int>(n, 0)); // Inicializada en 0 para la suma

    // 3. Leer los elementos de la Matriz A
    cout << "\n--- Ingrese los elementos de la Matriz A ---" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Matriz A [" << i << "][" << j << "]: ";
            cin >> matrizA[i][j];
        }
    }

    // 4. Leer los elementos de la Matriz B
    cout << "\n--- Ingrese los elementos de la Matriz B ---" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Matriz B [" << i << "][" << j << "]: ";
            cin >> matrizB[i][j];
        }
    }

    // 5. Calcular la multiplicacion de matrices (Matriz C = A * B)
    for (int i = 0; i < n; ++i) {           // Recorre las filas de A
        for (int j = 0; j < n; ++j) {       // Recorre las columnas de B
            for (int k = 0; k < n; ++k) {   // Realiza el producto punto
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    // 6. Mostrar el resultado (Matriz C)
    cout << "\n--- Matriz Resultante C (A x B) ---" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw
```
___
## 10. Vector dinámico con apuntadores: Crear un vector dinámico usando new y delete.
```C++
#include <iostream>

using namespace std;

int main() {
    int cantidad;

    // 1. Pedir el tamano del vector al usuario
    cout << "Ingrese la cantidad de elementos para el vector dinamico: ";
    cin >> cantidad;

    if (cantidad <= 0) {
        cout << "Error: La cantidad debe ser un numero mayor a 0." << endl;
        return 1;
    }

    // 2. Asignacion dinamica de memoria usando 'new'
    // Se declara un puntero que apuntara al primer elemento del bloque de memoria
    int* vectorDinamico = new int[cantidad];

    // 3. Llenar el vector con datos
    cout << "\n--- Ingrese los valores del vector ---" << endl;
    for (int i = 0; i < cantidad; ++i) {
        cout << "Elemento [" << i << "]: ";
        cin >> vectorDinamico[i];
    }

    // 4. Mostrar los datos ingresados
    cout << "\n--- Contenido del vector dinamico ---" << endl;
    for (int i = 0; i < cantidad; ++i) {
        cout << vectorDinamico[i] << " ";
    }
    cout << endl;

    // 5. Liberar la memoria asignada usando 'delete[]'
    // Es crucial usar corchetes [] porque estamos liberando un arreglo completo, no una sola variable
    delete[] vectorDinamico;

    // 6. Buenas practicas: Anular el puntero despues de liberar la memoria
    vectorDinamico = nullptr;

    cout << "\nMemoria liberada correctamente. Fin del programa." << endl;

    return 0;
}
```
___
## 11. Funciones con parámetros por referencia: Implementar una función que intercambie dos valores usando referencias.
```C++
#include <iostream>

using namespace std;

// 1. Declaracion de la funcion con parametros por referencia
// El ampersand (&) indica que 'a' y 'b' son referencias a las variables originales
void intercambiar(int &a, int &b) {
    // Se requiere una variable temporal para no perder el primer valor
    int temporal = a;
    a = b;
    b = temporal;
}

int main() {
    int valor1, valor2;

    // 2. Pedir los valores al usuario
    cout << "Ingrese el primer valor: ";
    cin >> valor1;
    
    cout << "Ingrese el segundo valor: ";
    cin >> valor2;

    // 3. Mostrar los valores antes del intercambio
    cout << "\n--- Antes del intercambio ---" << endl;
    cout << "Primer valor: " << valor1 << endl;
    cout << "Segundo valor: " << valor2 << endl;

    // 4. Llamar a la funcion
    // No se necesita sintaxis especial al llamar a la funcion, 
    // el programa sabe que espera referencias por su declaracion.
    intercambiar(valor1, valor2);

    // 5. Mostrar los valores despues del intercambio
    cout << "\n--- Despues del intercambio ---" << endl;
    cout << "Primer valor: " << valor1 << endl;
    cout << "Segundo valor: " << valor2 << endl;

    return 0;
}
```
___
