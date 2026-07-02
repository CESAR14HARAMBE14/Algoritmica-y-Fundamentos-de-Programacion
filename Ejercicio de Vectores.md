## 1. Escribir un programa que calcule la media de los elementos de un vector.

### Pseudocódigo

```
INICIO
    Definir Entero N
    
    // 1. Solicitar el tamaño del vector
    Mostrar "Ingrese la cantidad de elementos del vector: "
    Leer N
    
    SI N <= 0 ENTONCES
        Mostrar "Error: El vector debe tener al menos 1 elemento."
    SINO
        // 2. Crear y llenar el vector
        Definir vector V de N elementos
        
        Mostrar "Ingrese los elementos del vector:"
        PARA i DESDE 0 HASTA N-1 HACER
            Mostrar "Elemento [", i, "]: "
            Leer V[i]
        FIN PARA

        // 3. Inicializar la variable para la suma
        Definir Real suma = 0.0

        // 4. Recorrer el vector para sumar todos sus componentes
        PARA i DESDE 0 HASTA N-1 HACER
            suma = suma + V[i]
        FIN PARA

        // 5. Calcular y mostrar la media
        Definir Real media = suma / N
        Mostrar "La media de los elementos es: ", media
    FIN SI
FIN
```

### Código en C++

```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;

    // 1. Solicitar el tamaño del vector
    cout << "Ingrese la cantidad de elementos del vector: ";
    cin >> N;

    // Validación de seguridad para evitar divisiones por cero más adelante
    if (N <= 0) {
        cout << "Error: El vector debe tener al menos 1 elemento." << endl;
        return 1;
    }

    // 2. Crear el vector dinámico con el tamaño indicado
    vector<double> V(N);

    // Ingresar datos para el vector
    cout << "\n--- Ingrese los elementos del vector ---" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> V[i];
    }

    // 3. Inicializar la variable que acumulará el total
    double suma = 0.0;

    // 4. Recorrer el vector para sumar los elementos
    for (int i = 0; i < N; i++) {
        suma += V[i];
    }

    // 5. Calcular la media matemática
    double media = suma / N;

    // Mostrar el resultado final
    cout << "\nLa media de los elementos es: " << media << endl;

    return 0;
}
```

___
## 2. Escribir una programa que calcule y devuelva la suma al cuadrado de las componentes de un vector

### Pseudocódigo

```
INICIO
    Definir Entero N
    
    // 1. Solicitar el tamaño del vector
    Mostrar "Ingrese la cantidad de elementos del vector: "
    Leer N
    
    SI N <= 0 ENTONCES
        Mostrar "Error: El vector debe tener al menos 1 elemento."
    SINO
        // 2. Crear y llenar el vector
        Definir vector V de N elementos
        
        Mostrar "Ingrese los elementos del vector:"
        PARA i DESDE 0 HASTA N-1 HACER
            Mostrar "Elemento [", i, "]: "
            Leer V[i]
        FIN PARA

        // 3. Inicializar el acumulador
        Definir Real suma_cuadrados = 0.0

        // 4. Calcular la suma de los cuadrados
        PARA i DESDE 0 HASTA N-1 HACER
            suma_cuadrados = suma_cuadrados + (V[i] * V[i])
        FIN PARA

        // 5. Mostrar el resultado
        Mostrar "La suma de los cuadrados de las componentes es: ", suma_cuadrados
    FIN SI
FIN
```

### Código en C++

```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;

    // 1. Solicitar el tamaño del vector
    cout << "Ingrese la cantidad de elementos del vector: ";
    cin >> N;

    // Validación de seguridad
    if (N <= 0) {
        cout << "Error: El vector debe tener al menos 1 elemento." << endl;
        return 1;
    }

    // 2. Crear el vector dinámico con el tamaño indicado
    vector<double> V(N);

    // Ingresar datos para el vector
    cout << "\n--- Ingrese los elementos del vector ---" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> V[i];
    }

    // 3. Inicializar la variable que acumulará el resultado
    double suma_cuadrados = 0.0;

    // 4. Recorrer el vector para calcular los cuadrados y sumarlos
    for (int i = 0; i < N; i++) {
        suma_cuadrados += (V[i] * V[i]);
    }

    // 5. Mostrar el resultado final
    cout << "\nLa suma de los cuadrados de las componentes es: " << suma_cuadrados << endl;

    return 0;
}
```


___
## 3. Escribir un programa que calcule el producto escalar de dos vectores. Si v y w son los vectores y n su tamaño, el producto escalar se calcula como la sumatoria de V(i)\*W(i)

### Pseudocódigo

```
INICIO
    Definir Entero n
    
    // 1. Solicitar el tamaño de los vectores
    Mostrar "Ingrese el tamaño de los vectores: "
    Leer n
    
    SI n <= 0 ENTONCES
        Mostrar "Error: El tamaño debe ser mayor a 0."
    SINO
        // 2. Crear los vectores V y W
        Definir vector V de n elementos
        Definir vector W de n elementos
        
        Mostrar "Ingrese los elementos del primer vector (V):"
        PARA i DESDE 0 HASTA n-1 HACER
            Mostrar "V[", i, "]: "
            Leer V[i]
        FIN PARA

        Mostrar "Ingrese los elementos del segundo vector (W):"
        PARA i DESDE 0 HASTA n-1 HACER
            Mostrar "W[", i, "]: "
            Leer W[i]
        FIN PARA

        // 3. Inicializar el acumulador
        Definir Real producto_escalar = 0.0

        // 4. Calcular el producto escalar
        PARA i DESDE 0 HASTA n-1 HACER
            producto_escalar = producto_escalar + (V[i] * W[i])
        FIN PARA

        // 5. Mostrar el resultado
        Mostrar "El producto escalar de V y W es: ", producto_escalar
    FIN SI
FIN
```

### Código en C++

```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    // 1. Solicitar el tamaño de los vectores
    cout << "Ingrese el tamano de los vectores: ";
    cin >> n;

    // Validación de seguridad
    if (n <= 0) {
        cout << "Error: El tamano debe ser al menos de 1 elemento." << endl;
        return 1;
    }

    // 2. Crear los vectores dinámicos V y W
    vector<double> V(n);
    vector<double> W(n);

    // Ingresar datos para el vector V
    cout << "\n--- Ingrese los elementos del primer vector (V) ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "V[" << i << "]: ";
        cin >> V[i];
    }

    // Ingresar datos para el vector W
    cout << "\n--- Ingrese los elementos del segundo vector (W) ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "W[" << i << "]: ";
        cin >> W[i];
    }

    // 3. Inicializar la variable que acumulará el resultado
    double producto_escalar = 0.0;

    // 4. Recorrer los vectores para calcular la sumatoria
    for (int i = 0; i < n; i++) {
        producto_escalar += (V[i] * W[i]);
    }

    // 5. Mostrar el resultado final
    cout << "\nEl producto escalar de los vectores V y W es: " << producto_escalar << endl;

    return 0;
}
```


___
## 4. Escribir el programa que calcule el producto de un número por un vector (devuelve el vector resultante de multiplicar todas las componentes del vector inicial por un número)

### Pseudocódigo

```
INICIO
    Definir Entero N
    
    // 1. Solicitar el tamaño del vector
    Mostrar "Ingrese la cantidad de elementos del vector: "
    Leer N
    
    SI N <= 0 ENTONCES
        Mostrar "Error: El vector debe tener al menos 1 elemento."
    SINO
        // 2. Crear y llenar el vector
        Definir vector V de N elementos
        
        Mostrar "Ingrese los elementos del vector:"
        PARA i DESDE 0 HASTA N-1 HACER
            Mostrar "Elemento [", i, "]: "
            Leer V[i]
        FIN PARA

        // 3. Solicitar el número multiplicador (escalar)
        Definir Real escalar
        Mostrar "Ingrese el numero multiplicador: "
        Leer escalar

        // 4. Crear vector resultante y procesar la multiplicación
        Definir vector Resultado de N elementos

        PARA i DESDE 0 HASTA N-1 HACER
            Resultado[i] = V[i] * escalar
        FIN PARA

        // 5. Mostrar el vector resultante
        Mostrar "El vector resultante es: "
        PARA i DESDE 0 HASTA N-1 HACER
            Mostrar Resultado[i]
        FIN PARA
    FIN SI
FIN
```

### Código en C++

```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;

    // 1. Solicitar el tamaño del vector al usuario
    cout << "Ingrese la cantidad de elementos del vector: ";
    cin >> N;

    // Validación de seguridad
    if (N <= 0) {
        cout << "Error: El vector debe tener al menos 1 elemento." << endl;
        return 1;
    }

    // 2. Crear el vector dinámico con el tamaño indicado
    vector<double> V(N);

    cout << "\n--- Ingrese los elementos del vector ---" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> V[i];
    }

    // 3. Solicitar el número por el cual se va a multiplicar
    double escalar;
    cout << "\nIngrese el numero multiplicador (escalar): ";
    cin >> escalar;

    // 4. Vector resultante inicializado con el mismo tamaño 'N'
    vector<double> Resultado(N);

    // Recorrido del vector para multiplicar cada componente
    for (int i = 0; i < N; i++) {
        Resultado[i] = V[i] * escalar;
    }

    // 5. Mostrar el vector resultante formateado
    cout << "\nEl vector resultante es: { ";
    for (int i = 0; i < N; i++) {
        cout << Resultado[i];
        if (i < N - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;

    return 0;
}
```


___
## 5. Escribir un programa que calcule el vector resultante de sumar a cada una de las componentes de un vector dado, un número real.

### Pseudocódigo

```
INICIO
    Definir Entero N
    
    // 1. Solicitar el tamaño del vector
    Mostrar "Ingrese la cantidad de elementos del vector: "
    Leer N
    
    SI N <= 0 ENTONCES
        Mostrar "Error: El vector debe tener al menos 1 elemento."
    SINO
        // 2. Crear y llenar el vector
        Definir vector V de N elementos
        
        Mostrar "Ingrese los elementos del vector:"
        PARA i DESDE 0 HASTA N-1 HACER
            Mostrar "Elemento [", i, "]: "
            Leer V[i]
        FIN PARA

        // 3. Solicitar el número real a sumar
        Definir Real numero_real
        Mostrar "Ingrese el numero real que desea sumar: "
        Leer numero_real

        // 4. Crear vector resultante y procesar la suma
        Definir vector Resultado de N elementos

        PARA i DESDE 0 HASTA N-1 HACER
            Resultado[i] = V[i] + numero_real
        FIN PARA

        // 5. Mostrar el vector resultante
        Mostrar "El vector resultante es: "
        PARA i DESDE 0 HASTA N-1 HACER
            Mostrar Resultado[i]
        FIN PARA
    FIN SI
FIN
```

### Código en C++

```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;

    // 1. Solicitar el tamaño del vector al usuario
    cout << "Ingrese la cantidad de elementos del vector: ";
    cin >> N;

    // Validación de seguridad
    if (N <= 0) {
        cout << "Error: El vector debe tener al menos 1 elemento." << endl;
        return 1;
    }

    // 2. Crear el vector dinámico con el tamaño indicado
    vector<double> V(N);

    cout << "\n--- Ingrese los elementos del vector ---" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> V[i];
    }

    // 3. Solicitar el número real a sumar
    double numero_real;
    cout << "\nIngrese el numero real que desea sumar a cada componente: ";
    cin >> numero_real;

    // 4. Vector resultante inicializado con el mismo tamaño 'N'
    vector<double> Resultado(N);

    // Recorrido del vector para sumar el número a cada componente
    for (int i = 0; i < N; i++) {
        Resultado[i] = V[i] + numero_real;
    }

    // 5. Mostrar el vector resultante formateado
    cout << "\nEl vector resultante es: { ";
    for (int i = 0; i < N; i++) {
        cout << Resultado[i];
        if (i < N - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;

    return 0;
}
```


___
## 6. Escribir un programa que devuelva el mínimo de los elementos de un vector.

### Pseudocódigo

```
INICIO
    Definir Entero N
    
    // 1. Solicitar el tamaño del vector
    Mostrar "Ingrese la cantidad de elementos del vector: "
    Leer N
    
    SI N <= 0 ENTONCES
        Mostrar "Error: El vector debe tener al menos 1 elemento."
    SINO
        // 2. Crear y llenar el vector
        Definir vector V de N elementos
        
        Mostrar "Ingrese los elementos del vector:"
        PARA i DESDE 0 HASTA N-1 HACER
            Mostrar "Elemento [", i, "]: "
            Leer V[i]
        FIN PARA

        // 3. Inicializar la variable de referencia
        Definir Real minimo = V[0]

        // 4. Buscar el mínimo empezando desde la segunda posición
        PARA i DESDE 1 HASTA N-1 HACER
            SI V[i] < minimo ENTONCES
                minimo = V[i]
            FIN SI
        FIN PARA

        Mostrar "El valor mínimo de los elementos es: ", minimo
    FIN SI
FIN
```

### Código en C++

```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;

    // 1. Solicitar el tamaño del vector al usuario
    cout << "Ingrese la cantidad de elementos del vector: ";
    cin >> N;

    // Validación de seguridad
    if (N <= 0) {
        cout << "Error: El vector debe tener al menos 1 elemento." << endl;
        return 1;
    }

    // 2. Crear el vector dinámico con el tamaño indicado
    vector<double> V(N);

    cout << "\n--- Ingrese los elementos del vector ---" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> V[i];
    }

    // 3. Inicializamos 'minimo' estrictamente con el primer elemento ingresado
    double minimo = V[0];

    // 4. Recorrido del vector para evaluar cada celda (inicia en el índice 1)
    for (int i = 1; i < N; i++) {
        // Comprobación para encontrar un nuevo mínimo
        if (V[i] < minimo) {
            minimo = V[i]; // Se actualiza el récord con el número más pequeño
        }
    }

    // Mostrar el vector ingresado para validación visual
    cout << "\nEl vector ingresado es: { ";
    for (int i = 0; i < N; i++) {
        cout << V[i];
        if (i < N - 1) cout << ", ";
    }
    cout << " }" << endl;

    // 5. Impresión del resultado final
    cout << "El valor minimo de los elementos es: " << minimo << endl;

    return 0;
}
```


___
## 7. Escribir un programa que devuelva el máximo de los elementos de un vector.

### Pseudocódigo

```
INICIO
    Definir Entero N
    
    // 1. Solicitar el tamaño del vector
    Mostrar "Ingrese la cantidad de elementos del vector: "
    Leer N
    
    SI N <= 0 ENTONCES
        Mostrar "Error: El vector debe tener al menos 1 elemento."
    SINO
        // 2. Crear y llenar el vector
        Definir vector V de N elementos
        
        Mostrar "Ingrese los elementos del vector:"
        PARA i DESDE 0 HASTA N-1 HACER
            Mostrar "Elemento [", i, "]: "
            Leer V[i]
        FIN PARA

        // 3. Inicializar la variable de referencia
        Definir Real maximo = V[0]

        // 4. Buscar el máximo empezando desde la segunda posición
        PARA i DESDE 1 HASTA N-1 HACER
            SI V[i] > maximo ENTONCES
                maximo = V[i]
            FIN SI
        FIN PARA

        Mostrar "El valor máximo de los elementos es: ", maximo
    FIN SI
FIN
```

### Código en C++

```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;

    // 1. Solicitar el tamaño del vector al usuario
    cout << "Ingrese la cantidad de elementos del vector: ";
    cin >> N;

    // Validación de seguridad
    if (N <= 0) {
        cout << "Error: El vector debe tener al menos 1 elemento." << endl;
        return 1;
    }

    // 2. Crear el vector dinámico con el tamaño indicado
    vector<double> V(N);

    cout << "\n--- Ingrese los elementos del vector ---" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> V[i];
    }

    // 3. Inicializamos 'maximo' estrictamente con el primer elemento ingresado
    double maximo = V[0];

    // 4. Recorrido del vector para evaluar cada celda (inicia en el índice 1)
    for (int i = 1; i < N; i++) {
        // Comprobación para encontrar un nuevo máximo
        if (V[i] > maximo) {
            maximo = V[i]; // Se actualiza el récord
        }
    }

    // Mostrar el vector ingresado para validación visual
    cout << "\nEl vector ingresado es: { ";
    for (int i = 0; i < N; i++) {
        cout << V[i];
        if (i < N - 1) cout << ", ";
    }
    cout << " }" << endl;

    // 5. Impresión del resultado final
    cout << "El valor maximo de los elementos es: " << maximo << endl;

    return 0;
}
```


___
## 8. Escribir un programa que busque el menor y el mayor elemento ingresado en una matriz de m x n.

### Pseudocódigo

```
INICIO
    Definir Entero m (filas), n (columnas)
    
    // 1. Solicitar dimensiones
    Mostrar "Ingrese el número de filas: "
    Leer m
    Mostrar "Ingrese el número de columnas: "
    Leer n
    
    SI m <= 0 O n <= 0 ENTONCES
        Mostrar "Error: Las dimensiones deben ser mayores a 0."
    SINO
        // 2. Crear y llenar la matriz
        Definir matriz M de dimensiones m x n
        Mostrar "Ingrese los elementos de la matriz:"
        
        PARA i DESDE 0 HASTA m-1 HACER
            PARA j DESDE 0 HASTA n-1 HACER
                Mostrar "Elemento [", i, "][", j, "]: "
                Leer M[i][j]
            FIN PARA
        FIN PARA

        // 3. Inicializar valores de referencia
        Definir Real minimo = M[0][0]
        Definir Real maximo = M[0][0]

        // 4. Buscar el menor y el mayor
        PARA i DESDE 0 HASTA m-1 HACER
            PARA j DESDE 0 HASTA n-1 HACER
                SI M[i][j] < minimo ENTONCES
                    minimo = M[i][j]
                FIN SI
                
                SI M[i][j] > maximo ENTONCES
                    maximo = M[i][j]
                FIN SI
            FIN PARA
        FIN PARA

        // 5. Mostrar resultados
        Mostrar "El elemento menor es: ", minimo
        Mostrar "El elemento mayor es: ", maximo
    FIN SI
FIN
```

### Código en C++

```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;

    // 1. Solicitar dimensiones al usuario
    cout << "Ingrese el numero de filas: ";
    cin >> m;
    cout << "Ingrese el numero de columnas: ";
    cin >> n;

    if (m <= 0 || n <= 0) {
        cout << "Error: Las dimensiones deben ser numeros enteros positivos." << endl;
        return 1;
    }

    // 2. Inicializar la matriz con el tamaño dinámico indicado
    vector<vector<double>> M(m, vector<double>(n));

    cout << "\n--- Ingrese los elementos de la matriz ---" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> M[i][j];
        }
    }

    // 3. Inicializamos ambas variables con el primer elemento de la matriz
    double minimo = M[0][0];
    double maximo = M[0][0];

    // 4. Recorrido de la matriz para evaluar cada celda
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Comprobación para el mínimo
            if (M[i][j] < minimo) {
                minimo = M[i][j];
            }
            // Comprobación para el máximo
            if (M[i][j] > maximo) {
                maximo = M[i][j];
            }
        }
    }

    // Mostrar la matriz ingresada para validación visual
    cout << "\nLa matriz ingresada es:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }

    // 5. Impresión de los resultados finales
    cout << "\nEl elemento menor de la matriz es: " << minimo << endl;
    cout << "El elemento mayor de la matriz es: " << maximo << endl;

    return 0;
}
```


___
## 9. Escribir un programa que sume los elementos de cada fila de una matriz de m x n

### Pseudocódigo

```
INICIO
    Definir Entero m (filas), n (columnas)
    
    // 1. Solicitar dimensiones
    Mostrar "Ingrese el número de filas: "
    Leer m
    Mostrar "Ingrese el número de columnas: "
    Leer n
    
    SI m <= 0 O n <= 0 ENTONCES
        Mostrar "Error: Las dimensiones deben ser mayores a 0."
    SINO
        // 2. Crear y llenar la matriz
        Definir matriz M de dimensiones m x n
        Mostrar "Ingrese los elementos de la matriz:"
        
        PARA i DESDE 0 HASTA m-1 HACER
            PARA j DESDE 0 HASTA n-1 HACER
                Mostrar "Elemento [", i, "][", j, "]: "
                Leer M[i][j]
            FIN PARA
        FIN PARA

        // 3. Sumar elementos por fila
        Definir vector SumasFilas con m elementos inicializados en 0.0

        // El bucle externo congela la fila (i)
        PARA i DESDE 0 HASTA m-1 HACER
            // El bucle interno avanza por las columnas (j)
            PARA j DESDE 0 HASTA n-1 HACER
                SumasFilas[i] = SumasFilas[i] + M[i][j]
            FIN PARA
        FIN PARA

        // 4. Mostrar resultados
        Mostrar "Resultados de la suma por filas:"
        PARA i DESDE 0 HASTA m-1 HACER
            Mostrar "Fila ", i, ": ", SumasFilas[i]
        FIN PARA
    FIN SI
FIN
```

### Código en C++


```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;

    // 1. Solicitar dimensiones al usuario
    cout << "Ingrese el numero de filas: ";
    cin >> m;
    cout << "Ingrese el numero de columnas: ";
    cin >> n;

    if (m <= 0 || n <= 0) {
        cout << "Error: Las dimensiones deben ser numeros enteros positivos." << endl;
        return 1;
    }

    // 2. Inicializar la matriz con el tamaño dinámico indicado
    vector<vector<double>> M(m, vector<double>(n));

    cout << "\n--- Ingrese los elementos de la matriz ---" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> M[i][j];
        }
    }

    // 3. Vector resultante para almacenar las sumas de cada fila.
    // Se inicializa con 'm' posiciones (una por fila) en 0.0
    vector<double> SumasFilas(m, 0.0);

    // Recorrido de la matriz para sumar por filas
    // 'i' (filas) está en el exterior, 'j' (columnas) en el interior
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            SumasFilas[i] += M[i][j];
        }
    }

    // Mostrar la matriz ingresada para validación visual
    cout << "\nLa matriz ingresada es:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }

    // 4. Impresión de los resultados finales
    cout << "\nResultados de la suma por filas:" << endl;
    for (int i = 0; i < m; i++) {
        cout << "Fila " << i << ": " << SumasFilas[i] << endl;
    }

    return 0;
}
```


___
## 10. Escribir un programa que sume los elementos de cada columna de una matriz de m x n.

### Pseudocódigo

```
INICIO
    Definir Entero m (filas), n (columnas)
    
    // 1. Solicitar dimensiones
    Mostrar "Ingrese el número de filas: "
    Leer m
    Mostrar "Ingrese el número de columnas: "
    Leer n
    
    SI m <= 0 O n <= 0 ENTONCES
        Mostrar "Error: Las dimensiones deben ser mayores a 0."
    SINO
        // 2. Crear y llenar la matriz
        Definir matriz M de dimensiones m x n
        Mostrar "Ingrese los elementos de la matriz:"
        
        PARA i DESDE 0 HASTA m-1 HACER
            PARA j DESDE 0 HASTA n-1 HACER
                Mostrar "Elemento [", i, "][", j, "]: "
                Leer M[i][j]
            FIN PARA
        FIN PARA

        // 3. Sumar elementos por columna
        Definir vector SumasColumnas con n elementos inicializados en 0.0

        // El bucle externo recorre las columnas (j)
        PARA j DESDE 0 HASTA n-1 HACER
            // El bucle interno recorre las filas (i)
            PARA i DESDE 0 HASTA m-1 HACER
                SumasColumnas[j] = SumasColumnas[j] + M[i][j]
            FIN PARA
        FIN PARA

        // 4. Mostrar resultados
        Mostrar "Resultados de la suma por columnas:"
        PARA j DESDE 0 HASTA n-1 HACER
            Mostrar "Columna ", j, ": ", SumasColumnas[j]
        FIN PARA
    FIN SI
FIN
```

### Código en C++

```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;

    // 1. Solicitar dimensiones al usuario
    cout << "Ingrese el numero de filas: ";
    cin >> m;
    cout << "Ingrese el numero de columnas: ";
    cin >> n;

    if (m <= 0 || n <= 0) {
        cout << "Error: Las dimensiones deben ser numeros enteros positivos." << endl;
        return 1;
    }

    // 2. Inicializar la matriz con el tamaño indicado
    vector<vector<double>> M(m, vector<double>(n));

    cout << "\n--- Ingrese los elementos de la matriz ---" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> M[i][j];
        }
    }

    // 3. Vector resultante para almacenar las sumas de cada columna.
    // Se inicializa con 'n' posiciones (una por columna) en 0.0
    vector<double> SumasColumnas(n, 0.0);

    // Recorrido de la matriz para sumar por columnas
    // Nota: 'j' (columnas) está en el bucle exterior, 'i' (filas) en el interior
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            SumasColumnas[j] += M[i][j];
        }
    }

    // Mostrar la matriz ingresada para mayor claridad
    cout << "\nLa matriz ingresada es:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }

    // 4. Impresión de los resultados
    cout << "\nResultados de la suma por columnas:" << endl;
    for (int j = 0; j < n; j++) {
        cout << "Columna " << j << ": " << SumasColumnas[j] << endl;
    }

    return 0;
}
```


___
## 11. Escribir un programa que sume los elementos de la diagonal que va de izquierda a derecha en una matriz de m x n.

### Pseudocódigo

```
INICIO
    Definir Entero m (filas), n (columnas)
    
    // 1. Solicitar dimensiones
    Mostrar "Ingrese el número de filas: "
    Leer m
    Mostrar "Ingrese el número de columnas: "
    Leer n
    
    SI m <= 0 O n <= 0 ENTONCES
        Mostrar "Error: Las dimensiones deben ser mayores a 0."
    SINO
        // 2. Crear y llenar la matriz
        Definir matriz M de dimensiones m x n
        Mostrar "Ingrese los elementos de la matriz:"
        
        PARA i DESDE 0 HASTA m-1 HACER
            PARA j DESDE 0 HASTA n-1 HACER
                Mostrar "Elemento [", i, "][", j, "]: "
                Leer M[i][j]
            FIN PARA
        FIN PARA

        // 3. Calcular la suma de la diagonal de izquierda a derecha
        Definir Real suma_diagonal = 0.0
        Definir Entero limite
        
        SI m < n ENTONCES
            limite = m
        SINO
            limite = n
        FIN SI

        // Un solo bucle para la diagonal principal
        PARA i DESDE 0 HASTA limite-1 HACER
            suma_diagonal = suma_diagonal + M[i][i]
        FIN PARA

        // 4. Mostrar resultado
        Mostrar "La suma de la diagonal principal es: ", suma_diagonal
    FIN SI
FIN
```

### Código en C++

```C++
#include <iostream>
#include <vector>
#include <algorithm> // Para usar std::min

using namespace std;

int main() {
    int m, n;

    // 1. Solicitar dimensiones al usuario
    cout << "Ingrese el numero de filas: ";
    cin >> m;
    cout << "Ingrese el numero de columnas: ";
    cin >> n;

    if (m <= 0 || n <= 0) {
        cout << "Error: Las dimensiones deben ser numeros positivos." << endl;
        return 1;
    }

    // 2. Inicializar la matriz con el tamaño indicado
    vector<vector<double>> M(m, vector<double>(n));

    cout << "\n--- Ingrese los elementos de la matriz ---" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> M[i][j];
        }
    }

    // 3. Calcular la suma de la diagonal
    double suma_diagonal = 0.0;
    
    // El límite es la dimensión más pequeña para evitar salir de la matriz
    int limite = min(m, n);

    for (int i = 0; i < limite; i++) {
        suma_diagonal += M[i][i];
    }

    // Mostrar la matriz ingresada para validación visual
    cout << "\nLa matriz ingresada es:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }

    // 4. Imprimir el resultado final
    cout << "\nLa suma de la diagonal principal es: " << suma_diagonal << endl;

    return 0;
}
```


___
## 12. Escribir un programa que sume los elementos de la diagonal que va de derecha a izquierda en una matriz de m x n.

### Pseudocódigo

```
INICIO
    Definir Entero m (filas), n (columnas)
    
    Mostrar "Ingrese el número de filas: "
    Leer m
    Mostrar "Ingrese el número de columnas: "
    Leer n
    
    SI m <= 0 O n <= 0 ENTONCES
        Mostrar "Error: Las dimensiones deben ser mayores a 0."
    SINO
        // Crear la matriz vacía con los tamaños indicados por el usuario
        Definir matriz M de dimensiones m x n
        
        Mostrar "Ingrese los elementos de la matriz:"
        
        // Bucle para llenar la matriz
        PARA i DESDE 0 HASTA m-1 HACER
            PARA j DESDE 0 HASTA n-1 HACER
                Mostrar "Elemento en la posicion [", i, "][", j, "]: "
                Leer M[i][j]
            FIN PARA
        FIN PARA

        // Bucle para mostrar la matriz formateada
        Mostrar "La matriz ingresada es:"
        PARA i DESDE 0 HASTA m-1 HACER
            PARA j DESDE 0 HASTA n-1 HACER
                Mostrar M[i][j], "  "
            FIN PARA
            Mostrar Salto de Línea (Enter)
        FIN PARA
    FIN SI
FIN
```

### Código en C++

```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;

    // 1. Solicitar dimensiones
    cout << "Ingrese el numero de filas: ";
    cin >> m;
    cout << "Ingrese el numero de columnas: ";
    cin >> n;

    // Validación básica
    if (m <= 0 || n <= 0) {
        cout << "Error: Las dimensiones deben ser números enteros positivos." << endl;
        return 1;
    }

    // 2. Crear la matriz dinámica con el tamaño ingresado
    // Se inicializa un vector de 'm' filas, donde cada fila es un vector de 'n' columnas
    vector<vector<double>> M(m, vector<double>(n));

    cout << "\n--- Ingrese los elementos de la matriz ---" << endl;

    // 3. Recorrer la matriz para leer los datos ingresados por el usuario
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> M[i][j];
        }
    }

    // 4. Mostrar la matriz en pantalla
    cout << "\nLa matriz que usted ingreso es:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << M[i][j] << "\t"; // '\t' añade una tabulación para alinear las columnas
        }
        cout << endl; // Salto de línea al terminar cada fila
    }

    return 0;
}
```


___
## 13. Escribir un programa que copie los elementos de los bordes en sentido horario en una matriz de m x n en un vector resultante llamado v.

### Pseudocódigo

```
INICIO
    Definir Entero m (filas), n (columnas)
    
    // 1. Solicitar dimensiones
    Mostrar "Ingrese el número de filas: "
    Leer m
    Mostrar "Ingrese el número de columnas: "
    Leer n
    
    SI m <= 0 O n <= 0 ENTONCES
        Mostrar "Error: Las dimensiones deben ser mayores a 0."
    SINO
        // 2. Crear y llenar la matriz
        Definir matriz M de dimensiones m x n
        Mostrar "Ingrese los elementos de la matriz:"
        PARA i DESDE 0 HASTA m-1 HACER
            PARA j DESDE 0 HASTA n-1 HACER
                Mostrar "Elemento [", i, "][", j, "]: "
                Leer M[i][j]
            FIN PARA
        FIN PARA

        // 3. Extraer bordes en sentido horario
        Definir vector V vacio

        // Borde superior
        PARA j DESDE 0 HASTA n-1 HACER
            Agregar M[0][j] a V
        FIN PARA

        // Borde derecho
        PARA i DESDE 1 HASTA m-1 HACER
            Agregar M[i][n-1] a V
        FIN PARA

        // Borde inferior
        SI m > 1 ENTONCES
            PARA j DESDE n-2 HASTA 0 CON PASO -1 HACER
                Agregar M[m-1][j] a V
            FIN PARA
        FIN SI

        // Borde izquierdo
        SI n > 1 ENTONCES
            PARA i DESDE m-2 HASTA 1 CON PASO -1 HACER
                Agregar M[i][0] a V
            FIN PARA
        FIN SI

        // 4. Mostrar resultado
        Mostrar vector V
    FIN SI
FIN
```

### Código en C++

```C++

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;

    // 1. Solicitar dimensiones al usuario
    cout << "Ingrese el numero de filas: ";
    cin >> m;
    cout << "Ingrese el numero de columnas: ";
    cin >> n;

    if (m <= 0 || n <= 0) {
        cout << "Error: Las dimensiones deben ser numeros positivos." << endl;
        return 1;
    }

    // 2. Inicializar la matriz con el tamaño dinámico
    vector<vector<double>> M(m, vector<double>(n));

    cout << "\n--- Ingrese los elementos de la matriz ---" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> M[i][j];
        }
    }

    // 3. Vector resultante para guardar los bordes
    vector<double> v;

    // Borde superior (Izquierda a Derecha)
    for (int j = 0; j < n; j++) {
        v.push_back(M[0][j]);
    }

    // Borde derecho (Arriba hacia Abajo)
    for (int i = 1; i < m; i++) {
        v.push_back(M[i][n - 1]);
    }

    // Borde inferior (Derecha a Izquierda)
    if (m > 1) {
        for (int j = n - 2; j >= 0; j--) {
            v.push_back(M[m - 1][j]);
        }
    }

    // Borde izquierdo (Abajo hacia Arriba)
    if (n > 1) {
        for (int i = m - 2; i >= 1; i--) {
            v.push_back(M[i][0]);
        }
    }

    // 4. Mostrar el vector resultante
    cout << "\nEl vector 'v' resultante con los bordes es:\n{ ";
    for (int k = 0; k < v.size(); k++) {
        cout << v[k];
        if (k < v.size() - 1) cout << ", ";
    }
    cout << " }" << endl;

    return 0;
}
```


___
## 14. Escribir un programa que sume e imprima cada elemento en una matriz de m x n, que forme en ella la letra “N” (como en el bingo)

### Pseudocódigo


```
INICIO
    Definir Entero m (filas), n (columnas)
    
    // 1. Solicitar dimensiones
    Mostrar "Ingrese el número de filas: "
    Leer m
    Mostrar "Ingrese el número de columnas: "
    Leer n
    
    SI m <= 0 O n <= 0 ENTONCES
        Mostrar "Error: Las dimensiones deben ser mayores a 0."
    SINO
        // 2. Crear y llenar la matriz
        Definir matriz M de dimensiones m x n
        Mostrar "Ingrese los elementos de la matriz:"
        PARA i DESDE 0 HASTA m-1 HACER
            PARA j DESDE 0 HASTA n-1 HACER
                Mostrar "Elemento [", i, "][", j, "]: "
                Leer M[i][j]
            FIN PARA
        FIN PARA

        // 3. Buscar la letra "N" y sumar
        Definir Real suma_N = 0.0
        Mostrar "Los elementos que forman la letra N son:"

        PARA i DESDE 0 HASTA m-1 HACER
            PARA j DESDE 0 HASTA n-1 HACER
                // Condición: Primera columna O última columna O diagonal principal
                SI j == 0 O j == n-1 O i == j ENTONCES
                    Mostrar M[i][j], " "
                    suma_N = suma_N + M[i][j]
                FIN SI
            FIN PARA
        FIN PARA

        // 4. Mostrar resultado final
        Mostrar Salto de Linea
        Mostrar "La suma de los elementos de la letra N es: ", suma_N
    FIN SI
FIN
```

### Código en C++

```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;

    // 1. Solicitar dimensiones
    cout << "Ingrese el numero de filas: ";
    cin >> m;
    cout << "Ingrese el numero de columnas: ";
    cin >> n;

    if (m <= 0 || n <= 0) {
        cout << "Error: Las dimensiones deben ser numeros positivos." << endl;
        return 1;
    }

    // 2. Inicializar la matriz con el tamaño dinámico
    vector<vector<double>> M(m, vector<double>(n));

    cout << "\n--- Ingrese los elementos de la matriz ---" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> M[i][j];
        }
    }

    // 3. Identificar la letra "N" e imprimir sus elementos
    double suma_N = 0.0;
    cout << "\nLos elementos que forman la letra 'N' son: \n{ ";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // j == 0      -> Barra izquierda
            // j == n - 1  -> Barra derecha
            // i == j      -> Diagonal principal
            if (j == 0 || j == n - 1 || i == j) {
                cout << M[i][j] << " ";
                suma_N += M[i][j];
            }
        }
    }
    cout << "}" << endl;

    // 4. Imprimir la suma total
    cout << "La suma total de la figura es: " << suma_N << endl;

    return 0;
}
```

___
