#### Ejercicio 1
Realizar un algoritmo que muestre por pantalla la tabla de multiplicar del 3 y del 9.
___
##### Algoritmo de solución:
Mostrar "Tabla del 3".
Repetir de 1 a 12 → calcular 3 × i.
Mostrar resultado.
Repetir lo mismo para el 9.
Fin.
___
##### Código en Python
```Python
# Ejercicio 1: Tablas del 3 y del 9
def tablas():
    # Iteración sobre los números base (3 y 9)
    for n in [3, 9]:
        # Impresión del encabezado de la tabla
        print(f"\n--- Tabla del {n} ---")
        
        # Ciclo del 1 al 10 para multiplicar
        for i in range(1, 11):
            # Salida del resultado calculado
            print(f"{n} x {i} = {n * i}")

# Ejecución de la función principal
tablas()
```
___
##### Código en C++
```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Definición del vector con las bases numéricas
    vector<int> bases = {3, 9};
    
    // Recorrido de los números base
    for (int n : bases) {
        // Formateo visual del encabezado
        cout << "\n--- Tabla del " << n << " ---" << endl;
        
        // Cálculo de productos del 1 al 10
        for (int i = 1; i <= 10; ++i) {
            // Visualización de la operación y el resultado
            cout << n << " x " << i << " = " << (n * i) << endl;
        }
    }
    return 0; // Finalización exitosa del programa
}
```
___
##### Código en Julia
```Julia
# Iteración sobre el conjunto de bases (3 y 9)
for n in [3, 9]
    # Impresión del encabezado 
    println("\n--- Tabla del $n ---")
    
    # Rango numérico del 1 al 10
    for i in 1:10
        # Interpolación de valores de 'n' e 'i' y resultado
        println("$n x $i = $(n * i)")
    end
end
```
#### Ejercicio 2
Dado un número entero, visualiza por pantalla la suma de todos los números pares desde 1 hasta ese número, la suma de todos los números impares desde 1 hasta ese número y la suma de todos los múltiplos de 5 desde 1 hasta ese número.
___
##### Algoritmo de solución:
Leer número.
Recorrer de 1 hasta ese número.
Clasificar:
Par → suma pares.
Impar → suma impares.
Múltiplo de 5 → sumar aparte.
Mostrar resultados.
___
##### Código en Python
```Python
# Ingreso del límite superior
limite = int(input("Ingrese un número entero: "))

# Inicialización de 
suma_pares = 0
suma_impares = 0
suma_mult5 = 0

# Iteración del 1 al número ingresado (inclusive)
for i in range(1, limite + 1):
    # Verificación de números pares e impares
    if i % 2 == 0:
        suma_pares += i
    else:
        suma_impares += i
    
    # Verificación de múltiplos de 5
    if i % 5 == 0:
        suma_mult5 += i

# Visualización de los resultados obtenidos
print(f"Suma de pares: {suma_pares}")
print(f"Suma de impares: {suma_impares}")
print(f"Suma de múltiplos de 5: {suma_mult5}")
```
___
##### Código en C++
```C++
int main() {
    int numero;                // Número límite ingresado por el usuario
    int suma_pares = 0;        // Acumula la suma de números pares
    int suma_impares = 0;      // Acumula la suma de números impares
    int suma_multiplos_5 = 0;  // Acumula la suma de múltiplos de 5

    // Pedimos al usuario que ingrese un número
    cout << "Ingrese el numero: " << endl; 
    cin >> numero;  // Leemos el valor ingresado

    // Bucle que recorre desde 1 hasta el número ingresado
    for (int i = 1; i <= numero; i++) {

        // Verificamos si el número es par
        if (i % 2 == 0) {
            suma_pares += i;  // Si es par, se suma a la variable correspondiente
        } else {
            suma_impares += i; // Si es impar, se suma aquí
        }

        // Verificamos si el número es múltiplo de 5
        if (i % 5 == 0) {
            suma_multiplos_5 += i; // Se suma si cumple la condición
        }
    }

    // Mostramos los resultados finales
    cout << "Suma de numeros pares: " << suma_pares << endl;
    cout << "Suma de numeros impares: " << suma_impares << endl;
    cout << "Suma de multiplos de 5: " << suma_multiplos_5 << endl;

    return 0; // Fin del programa
}
```
___
##### Código en Julia
```Julia
# Captura y conversión del dato de entrada
print("Ingrese un número entero: ")
n = parse(Int, readline())

# Definición de variables para las sumas
suma_pares = 0
suma_impares = 0
suma_mult5 = 0

# Bucle de rango desde 1 hasta n
for i in 1:n
    # Clasificación de números pares e impares
    if i % 2 == 0
        global suma_pares += i
    else
        global suma_impares += i
    end

    # Identificación de múltiplos de 5
    if i % 5 == 0
        global suma_mult5 += i
    end
end

# Presentación de totales en pantalla
println("Suma de pares: $suma_pares")
println("Suma de impares: $suma_impares")
println("Suma de múltiplos de 5: $suma_mult5")
```
#### Ejercicio 3
Escriba un programa que muestre la suma de los 20 primeros múltiplos de 3.
___
##### Algoritmo de solución:
Inicializar suma.
Repetir 20 veces:
Calcular i × 3.
Acumular.
Mostrar resultado.
##### Código en Python
```Python
# variable para la suma total
suma_multiplos = 0

# Iteración para obtener los primeros 20 múltiplos
for i in range(1, 21):
    # Cálculo del múltiplo de 3 y adición a la suma
    suma_multiplos += (i * 3)

# Impresión del resultado final
print(f"La suma de los 20 primeros múltiplos de 3 es: {suma_multiplos}")
```
___
##### Código en C++
```C++
#include <iostream>  // Librería para usar cout
using namespace std;

int main() {
    int suma = 0;  // Variable acumuladora para guardar la suma total

    // Bucle que se repite 20 veces (del 1 al 20)
    for (int i = 1; i <= 20; i++) {

        // En cada vuelta se calcula un múltiplo de 3:
        // i * 3 genera: 3, 6, 9, 12, ..., 60
        suma += i * 3;  // Se acumulan los múltiplos en la variable suma
    }

    // Mostramos el resultado final
    cout << "La suma de los 20 primeros multiplos de 3 es: " << suma << endl;

    return 0;  // Fin del programa
}
```
___
##### Código en Julia
```Julia
# Declaración de la variable de suma
suma_multiplos = 0

# Bucle para recorrer el rango del 1 al 20
for i in 1:20
    # Acumulación de los múltiplos de 3 (uso de global para el alcance de la variable)
    global suma_multiplos += (i * 3)
end

# Salida de datos en consola
println("La suma de los 20 primeros múltiplos de 3 es: $suma_multiplos")
```
#### Ejercicio 4
Escriba un programa que: rota, hacia la izquierda, los dígitos de un número tantas veces como indique el promedio de sus dígitos. Ej. si el valor de entrada es 123 se obtendrá el número 312.
___
##### Algoritmo de solución:
Leer número.
Convertir a texto.
Sumar dígitos.
Calcular promedio.
Rotar número según promedio.
Mostrar resultado.
___
##### Código en Python
```Python
numero = input("Ingrese un número entero: ")

# 1. Calcular el promedio de los dígitos (división entera)
suma_digitos = sum(int(d) for d in numero)
promedio = suma_digitos // len(numero)

# 2. Calcular cuántas posiciones rotar (usando módulo por si el promedio es mayor al largo)
desplazamiento = promedio % len(numero)

# 3. Rotar hacia la izquierda: [desde desplazamiento:] + [:hasta desplazamiento]
resultado = numero[desplazamiento:] + numero[:desplazamiento]

print(f"Promedio de dígitos: {promedio}")
print(f"Resultado de la rotación: {resultado}")
```
___
##### Código en C++
```C++
#include <iostream>
#include <string>
#include <numeric>

using namespace std;

int main() {
    string entrada;
    cout << "Ingrese un numero entero: ";
    cin >> entrada;

    int suma = 0;
    int n = entrada.length();

    // Sumatoria de los dígitos convirtiendo caracteres a enteros
    for (char d : entrada) {
        suma += (d - '0');
    }

    // Cálculo del promedio (división entera)
    int promedio = suma / n;
    
    // El número de rotaciones efectivas es el promedio módulo la longitud
    int k = promedio % n;

    // Rotación manual: construir nueva cadena desde el índice k
    string resultado = entrada.substr(k) + entrada.substr(0, k);

    // Salida de datos
    cout << "Promedio de digitos: " << promedio << endl;
    cout << "Numero rotado " << k << " veces a la izquierda: " << resultado << endl;

    return 0;
}
```
___
##### Código en Julia
```Julia
# Lectura de la entrada como cadena
print("Ingrese un número entero: ")
entrada = readline()

# Conversión de caracteres a lista de enteros para procesar dígitos
digitos = [parse(Int, d) for d in entrada]
n = length(entrada)

# Cálculo del promedio y rotaciones necesarias
promedio = div(sum(digitos), n)
k = promedio % n

# Rotación hacia la izquierda mediante concatenación de subcadenas
# Se considera que en Julia los índices comienzan en 1
resultado = entrada[k+1:end] * entrada[1:k]

# Presentación de resultados
println("Promedio de dígitos: $promedio")
println("Número rotado $k veces a la izquierda: $resultado")
```
#### Ejercicio 5
Escriba un programa que lea de la entrada estándar valores que representan años e indique si son o no años bisiestos. El programa seguirá leyendo años hasta un máximo de 10 o hasta que haya leído 3 años bisiestos.
___
##### Algoritmo de solución:
Leer años.
Verificar condición.
Contar bisiestos hasta cumplir límite.
Fin.
Fórmula:
año / 4 = año bisiesto
___
##### Código en Python
```Python
# Inicialización de contadores de control
total_leidos = 0
bisiestos_encontrados = 0

# Ciclo condicionado a los dos límites de parada
while total_leidos < 10 and bisiestos_encontrados < 3:
    anio = int(input("Ingrese un año: "))
    total_leidos += 1
    
    # Evaluación de la condición de año bisiesto
    if (anio % 4 == 0 and anio % 100 != 0) or (anio % 400 == 0):
        print(f"El año {anio} es bisiesto.")
        bisiestos_encontrados += 1
    else:
        print(f"El año {anio} no es bisiesto.")

# Indicador de finalización del proceso
print("\nLimite alcanzado de 10.")
```
___
##### Código en C++
```C++
#include <iostream>  // Librería para entrada y salida
using namespace std;

int main() {
    int anio;           // Variable para almacenar el año ingresado
    int contador = 0;   // Cuenta cuántos años se han ingresado
    int bisiestos = 0;  // Cuenta cuántos años bisiestos se encontraron

    // El bucle se ejecuta mientras:
    // - No se hayan ingresado 10 años
    // - Y no se hayan encontrado 3 años bisiestos
    while (contador < 10 && bisiestos < 3) {
        contador++;  // Aumentamos el contador de intentos

        // Pedimos el año al usuario
        cout << "Año #" << contador << ": ";
        cin >> anio;

        // Condición para verificar si un año es bisiesto:
        // - Es divisible entre 4 y NO entre 100
        // - O es divisible entre 400
        if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
            cout << "→ " << anio << " es bisiesto" << endl;
            bisiestos++;  // Aumentamos el contador de bisiestos
        } else {
            cout << "→ " << anio << " no es bisiesto" << endl;
        }
    }

    // Mensaje final cuando se cumple alguna de las condiciones de salida
    cout << "Programa finalizado." << endl;

    return 0;  // Fin del programa
}
```
___
##### Código en Julia
```Julia
# Definición de variables de seguimiento
total_leidos = 0
bisiestos_encontrados = 0

# Estructura de control de flujo
while total_leidos < 10 && bisiestos_encontrados < 3
    print("Ingrese un año: ")
    input_str = readline()
    anio = parse(Int, input_str)
    global total_leidos += 1
    
    # Validación lógica de año bisiesto
    if (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)
        println("El año $anio es bisiesto.")
        global bisiestos_encontrados += 1
    else
        println("El año $anio no es bisiesto.")
    end
end

# Notificación de cierre del programa
println("\nLimite alcanzado")
```
#### Ejercicio 6
Escriba un programa que calcule de forma aproximada el seno de un ángulo comprendido entre El valor del ángulo se leerá desde la entrada estándar, y se comprobará que se encuentra entre los límites fijados.
___
##### Algoritmo de solución:
Leer ángulo.
Convertir a radianes.
Aplicar serie.
Mostrar resultado.​
Fomula:
sen(x) = x - x elevado a 3/ 3! + x elev a 5/ 5! - x elev a 7/ 7! + ...
____
##### Código en Python
```Python
import math

# 1. Lectura y validación
angulo_deg = float(input("Ingrese un ángulo en grados (0-360): "))

if 0 <= angulo_deg <= 360:
    # 2. Conversión a radianes
    x = angulo_deg * (math.pi / 180)
    
    # 3. Aproximación (Serie de Taylor: 4 términos)
    # sin(x) ≈ x - x^3/3! + x^5/5! - x^7/7!
    aproximacion = x - (x**3/6) + (x**5/120) - (x**7/5040)
    
    print(f"Ángulo: {angulo_deg}°")
    print(f"Valor aproximado: {aproximacion:.6f}")
    print(f"Valor real (math.sin): {math.sin(x):.6f}")
else:
    print("Error: El ángulo está fuera del rango [0, 360].")
```
___
##### Código en C++
```C++
#include <iostream>  // Entrada y salida
#include <cmath>     // Funciones matemáticas como sin(), pow(), tgamma()
using namespace std;

int main() {
    double grados, x;   // 'grados' es el ángulo ingresado, 'x' será en radianes
    double seno = 0;    // Acumulador para la aproximación del seno
    double termino;     // Variable para cada término de la serie
    int n = 10;         // Número de términos de la serie (precisión)

    // Pedimos el ángulo en grados
    cout << "Ingrese un angulo en grados (0 a 360): ";
    cin >> grados;

    // Validamos que el ángulo esté en el rango permitido
    if (grados < 0 || grados > 360) {
        cout << "El angulo esta fuera del rango permitido." << endl;
        return 0; // Termina el programa si no es válido
    }

    // Convertimos grados a radianes
    // Fórmula: radianes = grados * π / 180
    x = grados * 3.1416 / 180;

    // Usamos la serie de Taylor para aproximar el seno:
    // sen(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
    for (int i = 0; i < n; i++) {

        // Determina el signo del término (+ o -)
        // Par → positivo, impar → negativo
        int signo = (i % 2 == 0) ? 1 : -1;

        // Calculamos el término de la serie:
        // x^(2i+1) / (2i+1)!
        // tgamma(k) = (k-1)! → por eso usamos (2*i + 2)
        termino = pow(x, 2*i + 1) / tgamma(2*i + 2);

        // Sumamos o restamos el término según el signo
        seno += signo * termino;
    }

    // Mostramos el resultado aproximado
    cout << "Seno aproximado: " << seno << endl;

    // Mostramos el valor real usando la función sin()
    cout << "Seno real: " << sin(x) << endl;

    return 0; // Fin del programa
}

```
___
##### Código en Julia
```Julia
# En Julia, 'pi' es una constante predefinida. 
print("Ingrese un ángulo entre 0 y 90: ")
grados = parse(Float64, readline())

if grados >= 0 && grados <= 90
    # Usamos la constante nativa 'pi'
    x = grados * (pi / 180.0)
    seno_aprox = 0.0

    for i in 0:9
        exponente = 2 * i + 1
        # Calculamos el término de la serie
        termino = ((-1.0)^i * x^exponente) / factorial(big(exponente))
        seno_aprox += termino
    end

    println("Seno aproximado de $grados grados: ", round(seno_aprox, digits=6))
else
    println("Error: El ángulo está fuera del rango.")
end
```
#### Ejercicio 7
El siguiente programa genera un número aleatorio comprendido entre 1 y el valor de la constante _MAXIMO_ y posteriormente reta al usuario a que lo adivine. Para ello utiliza la función **random** que genera un número aleatorio _x_ donde 0 ≤ _x_ < 1.
___
##### Algoritmo de solución:
Generar número aleatorio.
Pedir intentos.
Dar pistas hasta acertar.
Mostrar intentos.

Fórmula (generación):

número = rand() % 100 + 1
___
##### Código en Python
```Python
import random

MAXIMO = 100
numero_secreto = random.randint(1, MAXIMO)
acierto = False
intentos = 0

while acierto == False:
    n = int(input("Introduzca un número: "))
    intentos = intentos + 1
    
    if n == numero_secreto:
        acierto = True
        print("¡¡acertaste!!")
    elif n < numero_secreto:
        print("El número es mayor")
    else:
        print("El número es menor")

print("Número de intentos:", intentos)
```
___
##### Código en C++
```C++
#include <iostream>  // Entrada y salida
#include <cstdlib>   // Funciones para números aleatorios (rand, srand)
#include <ctime>     // Para usar time() como semilla
using namespace std;

int main() {
    const int MAXIMO = 100;  // Número máximo posible (1 a 100)
    int numero, n;           // 'numero' es el secreto, 'n' es el intento del usuario
    bool acierto = false;    // Controla si el usuario adivinó
    int intentos = 0;        // Cuenta cuántos intentos se hicieron

    // Inicializamos la semilla para que los números aleatorios cambien cada vez
    srand(time(0));

    // Generamos un número aleatorio entre 1 y MAXIMO
    numero = rand() % MAXIMO + 1;

    // Bucle que se repite hasta que el usuario acierte
    while (!acierto) {

        // Pedimos un número al usuario
        cout << "\nIntroduzca un numero: ";
        cin >> n;
        intentos++;  // Aumentamos el contador de intentos

        // Comparamos el número ingresado con el número secreto
        if (n == numero) {
            cout << "\n¡¡Acertaste!!" << endl;
            acierto = true;  // Se termina el bucle
        } 
        else if (n < numero) {
            cout << "\nEl numero es mayor" << endl;  // Pista
        } 
        else {
            cout << "\nEl numero es menor" << endl;  // Pista
        }
    }

    // Mostramos cuántos intentos le tomó al usuario
    cout << "Numero de intentos: " << intentos << endl;

    return 0; // Fin del programa
}

```
___
##### Código en Julia
```Julia
# Definición del límite máximo
const MAXIMO = 100

# Generación del número aleatorio usando la función nativa rand() [0,1)
# Se transforma al rango [1, MAXIMO]
numero_secreto = floor(Int, rand() * MAXIMO) + 1
intento = 0

println("He generado un número entre 1 y $MAXIMO. ¿Puedes adivinarlo?")

# Estructura repetitiva para procesar las entradas
while intento != numero_secreto
    print("Ingresa tu número: ")
    input_str = readline()
    global intento = parse(Int, input_str)
    
    # Lógica de comparación para guiar al usuario
    if intento < numero_secreto
        println("El número secreto es mayor.")
    elseif intento > numero_secreto
        println("El número secreto es menor.")
    else
        println("¡Excelente! Has acertado.")
    end
end
```
#### Ejercicio 8
Escriba un programa que imprima la tabla de multiplicar de un número que se leerá de la entrada estándar. El funcionamiento del programa se muestra en el siguiente ejemplo de ejecución (en negrita, el número introducido por el usuario):
   Introduzca un número: 5
   La tabla de multiplicar del 5 es:
   5 x 1 = 5
   5 x 2 = 10
   . . . 
   5 x 10 = 50
___
##### Algoritmo de solución:
Leer número.
Repetir del 1 al 10.
Mostrar multiplicaciones.
___
##### Código en Python
```Python
# Lectura del número desde la entrada
n = int(input("Introduzca un número: "))

print(f"\nLa tabla de multiplicar del {n} es:")

# Generación de la secuencia del 1 al 10
for i in range(1, 11):
    # Visualización de la operación con el formato requerido
    print(f"{n} x {i} = {n * i}")
```
___
##### Código en C++
```C++
#include <iostream>   // Entrada y salida (cout, cin)
#include <iomanip>    // Para usar setw (alineación de texto)
using namespace std;

int main() {
    int numero;  // Variable para guardar el número ingresado

    // Pedimos al usuario un número
    cout << "Introduzca un numero: ";
    cin >> numero;

    // Mostramos el título de la tabla
    cout << "\nLa tabla de multiplicar del " << numero << " es:\n";

    // Bucle que va del 1 al 10
    for (int i = 1; i <= 10; i++) {

        // Mostramos cada operación:
        // setw(2) alinea el número 'i' en 2 espacios
        // setw(3) alinea el resultado en 3 espacios
        // Esto hace que la tabla se vea ordenada
        cout << numero << " x " << setw(2) << i 
             << " = " << setw(3) << numero * i << endl;
    }

    return 0; // Fin del programa
}
```
___
##### Código en Julia
```Julia
# Captura de la entrada y conversión a entero
print("Introduzca un número: ")
n = parse(Int, readline())

println("\nLa tabla de multiplicar del $n es:")

# Iteración en el rango de 1 a 10
for i in 1:10
    # Impresión con interpolación de variables
    println("$n x $i = $(n * i)")
end
```
#### Ejercicio 9
Escriba un programa que muestre la serie de Fibonacci para los valores comprendidos entre _n_ y _m_.
___
##### Algoritmo de solución:
Leer n y m.
Generar Fibonacci.
Mostrar solo los del rango.
Fin.

Fórmula:
F(n) = F(n-1) + (n-2)
___
##### Código en Python
```Python
# Entrada de los límites del rango
n = int(input("Ingrese el valor mínimo (n): "))
m = int(input("Ingrese el valor máximo (m): "))

# Inicialización de los dos primeros términos de la serie
a, b = 0, 1

print(f"\nSerie de Fibonacci entre {n} y {m}:")

# Generación de la serie mientras el valor sea menor o igual al límite superior
while a <= m:
    # Verificación de pertenencia al rango solicitado
    if a >= n:
        print(a, end=" ")
    
    # Cálculo del siguiente término
    a, b = b, a + b
print() # Salto de línea final
```
___
##### Código en C++
```C++
#include <iostream>  // Librería para entrada y salida
using namespace std;

int main() {
    int n, m;              // 'n' es el inicio del rango, 'm' es el final
    int a = 0, b = 1;      // Primeros valores de la serie de Fibonacci
    int siguiente;         // Variable para guardar el siguiente número

    // Pedimos los valores al usuario
    cout << "Ingrese el valor de n: ";
    cin >> n;
    cout << "Ingrese el valor de m: ";
    cin >> m;

    // Mostramos el mensaje inicial
    cout << "Serie de Fibonacci entre " << n << " y " << m << ":\n";

    // Generamos la serie de Fibonacci hasta que 'a' supere a 'm'
    while (a <= m) {

        // Si el número actual está dentro del rango [n, m], lo mostramos
        if (a >= n) {
            cout << a << " ";
        }

        // Calculamos el siguiente número de la serie
        siguiente = a + b;

        // Avanzamos los valores:
        // 'a' toma el valor de 'b'
        // 'b' toma el valor del nuevo número generado
        a = b;
        b = siguiente;
    }

    return 0;  // Fin del programa
}
```
___
##### Código en Julia
```Julia
# Captura de los valores límites desde la entrada estándar
print("Ingrese el valor mínimo (n): ")
n = parse(Int, readline())
print("Ingrese el valor máximo (m): ")
m = parse(Int, readline())

# Definición de las semillas de la serie
a, b = 0, 1

println("\nSerie de Fibonacci entre $n y $m:")

# Estructura repetitiva controlada por el límite superior
while a <= m
    # Filtro para visualizar solo valores dentro del rango
    if a >= n
        print("$a ")
    end
    
    # Actualización de términos (uso de global para modificar variables de alcance externo)
    global a, b = b, a + b
end
println() # Salto de línea final
```
#### Ejercicio 10
Traduzca un número binario introducido desde el teclado, al sistema hexadecimal (base 16) de forma directa, es decir sin convertir el número binario al sistema decimal.
___
##### Algoritmo de solución:
Leer binario.
Agrupar en bloques de 4 bits.
Convertir cada grupo.
Mostrar resultado.

Fórmula clave:

1 dígito hexadecimal = 4 bits
2elevado a la 4= 16 resultados
binario          hexadecimal 
___
##### Código en Python
```Python
# Entrada del número binario como cadena
binario = input("Ingrese un número binario: ")

# Diccionario para traducción directa de 4 bits a hexadecimal
tabla_hex = {
    "0000": "0", "0001": "1", "0010": "2", "0011": "3",
    "0100": "4", "0101": "5", "0110": "6", "0111": "7",
    "1000": "8", "1001": "9", "1010": "A", "1011": "B",
    "1100": "C", "1101": "D", "1110": "E", "1111": "F"
}

# Relleno con ceros a la izquierda para completar bloques de 4
while len(binario) % 4 != 0:
    binario = "0" + binario

resultado_hex = ""
# Procesamiento de la cadena en saltos de 4 caracteres
for i in range(0, len(binario), 4):
    bloque = binario[i:i+4]
    resultado_hex += tabla_hex[bloque]

# Visualización del valor convertido
print(f"Resultado en hexadecimal: {resultado_hex}")
```
___
##### Código en C++
```C++
#include <iostream>  // Entrada y salida
#include <string>    // Para trabajar con cadenas (string)
using namespace std;

int main() {
    string binario;  // Variable para guardar el número binario ingresado

    // Pedimos el número binario al usuario
    cout << "Ingrese un numero binario: ";
    cin >> binario;

    // Completamos con ceros a la izquierda si la longitud no es múltiplo de 4
    // Esto es necesario porque 1 dígito hexadecimal equivale a 4 bits
    while (binario.length() % 4 != 0) {
        binario = "0" + binario;
    }

    // Mostramos el mensaje inicial
    cout << "Equivalente en hexadecimal: ";

    // Recorremos el string en grupos de 4 bits
    for (int i = 0; i < binario.length(); i += 4) {

        // Extraemos un grupo de 4 bits
        string grupo = binario.substr(i, 4);

        // Convertimos cada grupo binario a su equivalente hexadecimal
        if (grupo == "0000") cout << "0";
        else if (grupo == "0001") cout << "1";
        else if (grupo == "0010") cout << "2";
        else if (grupo == "0011") cout << "3";
        else if (grupo == "0100") cout << "4";
        else if (grupo == "0101") cout << "5";
        else if (grupo == "0110") cout << "6";
        else if (grupo == "0111") cout << "7";
        else if (grupo == "1000") cout << "8";
        else if (grupo == "1001") cout << "9";
        else if (grupo == "1010") cout << "A";
        else if (grupo == "1011") cout << "B";
        else if (grupo == "1100") cout << "C";
        else if (grupo == "1101") cout << "D";
        else if (grupo == "1110") cout << "E";
        else if (grupo == "1111") cout << "F";
    }

    // Salto de línea final
    cout << endl;

    return 0;  // Fin del programa
}
```
___
##### Código en Julia
```Julia
# Lectura de la entrada estándar
print("Ingrese un número binario: ")
binario = readline()

# Mapa de conversión directa de base 2 a base 16
tabla_hex = Dict(
    "0000"=>"0", "0001"=>"1", "0010"=>"2", "0011"=>"3",
    "0100"=>"4", "0101"=>"5", "0110"=>"6", "0111"=>"7",
    "1000"=>"8", "1001"=>"9", "1010"=>"A", "1011"=>"B",
    "1100"=>"C", "1101"=>"D", "1110"=>"E", "1111"=>"F"
)

# Ajuste de la longitud de la cadena (múltiplo de 4)
while length(binario) % 4 != 0
    global binario = "0" * binario
end

resultado_hex = ""
# Iteración por bloques de 4 dígitos
for i in 1:4:length(binario)
    bloque = binario[i:i+3]
    global resultado_hex *= tabla_hex[bloque]
end

# Impresión del resultado final
println("Resultado en hexadecimal: $resultado_hex")
```
#### Ejercicio 11
Una empresa fabrica dos productos A y B y desea saber cuál de ellos es el más aceptado en el mercado. Para ello realiza una encuesta y, por cada persona interrogada se obtiene un par de valores: el primer valor del par indica la aceptación o no del producto A según sea 1 o 0; el segundo valor del par corresponde al producto B. Por ejemplo, el par (1,0) significa que el encuestado acepta el producto A pero no el B. Se pide:
- Total de encuestados.
- Porcentaje de consumidores que aceptan.
- El producto A.
- El producto B.
- Los dos productos.
- El producto A pero no el B.
- El producto B pero no el A.
- Ninguno de los dos productos.
___
##### Algoritmo de solución:
Leer número de encuestados.
Registrar respuestas (A y B).
Contar casos (A, B, ambos, etc.).
Calcular porcentajes.
Mostrar resultados.

Fórmula:
porcentaje = cantidad/total x 100
___
##### Código en Python
```Python
# Inicialización de contadores
total = 0
acc_a = 0
acc_b = 0
acc_ambos = 0
acc_solo_a = 0
acc_solo_b = 0
acc_ninguno = 0

print("Ingrese las respuestas (A y B). Use -1 en el Producto A para finalizar.")

while True:
    a = int(input("Producto A (1/0): "))
    if a == -1: break
    b = int(input("Producto B (1/0): "))
    
    total += 1
    
    # Contadores generales de aceptación
    if a == 1: acc_a += 1
    if b == 1: acc_b += 1
    
    # Clasificación por categorías exclusivas
    if a == 1 and b == 1:
        acc_ambos += 1
    elif a == 1 and b == 0:
        acc_solo_a += 1
    elif a == 0 and b == 1:
        acc_solo_b += 1
    else:
        acc_ninguno += 1

if total > 0:
    # Presentación de resultados y porcentajes
    print(f"\nTotal de encuestados: {total}")
    print(f"Aceptan el producto A: {(acc_a/total)*100:.2f}%")
    print(f"Aceptan el producto B: {(acc_b/total)*100:.2f}%")
    print(f"Aceptan los dos productos: {(acc_ambos/total)*100:.2f}%")
    print(f"Aceptan A pero no B: {(acc_solo_a/total)*100:.2f}%")
    print(f"Aceptan B pero no A: {(acc_solo_b/total)*100:.2f}%")
    print(f"No aceptan ninguno: {(acc_ninguno/total)*100:.2f}%")
```
___
##### Código en C++
```C++
#include <iostream>  // Librería para entrada y salida
using namespace std;

int main() {
    int n;  // Número total de encuestados

    // Pedimos la cantidad de personas encuestadas
    cout << "Ingrese el numero de encuestados: ";
    cin >> n;

    int a, b;  // Variables para respuestas (1 = sí acepta, 0 = no acepta)

    // Contadores
    int contA = 0, contB = 0, contAmbos = 0;
    int contSoloA = 0, contSoloB = 0, contNinguno = 0;

    // Bucle para registrar las respuestas de cada encuestado
    for (int i = 0; i < n; i++) {

        // Pedimos las respuestas (A y B)
        cout << "Encuestado " << i + 1 << " (A B): ";
        cin >> a >> b;

        // Contamos cuántos aceptan A
        if (a == 1) contA++;

        // Contamos cuántos aceptan B
        if (b == 1) contB++;

        // Contamos los que aceptan ambos productos
        if (a == 1 && b == 1) contAmbos++;

        // Aceptan A pero no B
        if (a == 1 && b == 0) contSoloA++;

        // Aceptan B pero no A
        if (a == 0 && b == 1) contSoloB++;

        // No aceptan ninguno
        if (a == 0 && b == 0) contNinguno++;
    }

    // Mostramos resultados
    cout << "\nRESULTADOS:\n";
    cout << "Total de encuestados: " << n << endl;

    // Calculamos porcentajes (multiplicamos por 100 y dividimos entre n)
    cout << "Porcentaje que aceptan A: " << (contA * 100.0 / n) << "%\n";
    cout << "Porcentaje que aceptan B: " << (contB * 100.0 / n) << "%\n";
    cout << "Porcentaje que aceptan ambos: " << (contAmbos * 100.0 / n) << "%\n";
    cout << "Porcentaje que aceptan A pero no B: " << (contSoloA * 100.0 / n) << "%\n";
    cout << "Porcentaje que aceptan B pero no A: " << (contSoloB * 100.0 / n) << "%\n";
    cout << "Porcentaje que no aceptan ninguno: " << (contNinguno * 100.0 / n) << "%\n";

    return 0;  // Fin del programa
}
```
___
##### Código en Julia
```Julia
# Declaración de variables de control
total = 0
acc_a = 0
acc_b = 0
acc_ambos = 0
acc_solo_a = 0
acc_solo_b = 0
acc_ninguno = 0

println("Registro de encuesta (1=Acepta, 0=No). Ingrese -1 en A para terminar.")

while true
    print("Producto A: ")
    a = parse(Int, readline())
    if a == -1 break end
    print("Producto B: ")
    b = parse(Int, readline())
    
    global total += 1
    
    # Actualización de contadores independientes
    if a == 1 global acc_a += 1 end
    if b == 1 global acc_b += 1 end
    
    # Lógica de clasificación exclusiva
    if a == 1 && b == 1
        global acc_ambos += 1
    elseif a == 1 && b == 0
        global acc_solo_a += 1
    elseif a == 0 && b == 1
        global acc_solo_b += 1
    else
        global acc_ninguno += 1
    end
end

if total > 0
    # Cálculo y visualización de métricas
    println("\nTotal de encuestados: $total")
    println("Aceptan el producto A: ", (acc_a/total)*100, "%")
    println("Aceptan el producto B: ", (acc_b/total)*100, "%")
    println("Aceptan los dos productos: ", (acc_ambos/total)*100, "%")
    println("Aceptan A pero no B: ", (acc_solo_a/total)*100, "%")
    println("Aceptan B pero no A: ", (acc_solo_b/total)*100, "%")
    println("No aceptan ninguno: ", (acc_ninguno/total)*100, "%")
end
```
#### Ejercicio 12
Diseñe un diagrama que acepte un número escrito del 1 al 20 en cifras arábigas y lo visualice en números romanos.
___
##### Algoritmo de solución:
Leer número (1–20).
Validar rango.
Convertir usando switch.
Mostrar resultado.
___
##### Código en Python
```Python
# Lectura del número arábigo
n = int(input("Ingrese un número entre 1 y 20: "))

# Validación del rango permitido
if 1 <= n <= 20:
    # Definición de equivalencias para unidades y decenas
    unidades = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
    decenas = ["", "X", "XX"]
    
    # Cálculo de índices mediante división y módulo
    d = n // 10
    u = n % 10
    
    # Construcción y visualización del número romano
    resultado = decenas[d] + unidades[u]
    print(f"El número {n} en romano es: {resultado}")
else:
    print("Error: El número debe estar entre 1 y 20.")
```
___
##### Código en C++
```C++
#include <iostream>  // Librería para entrada y salida
using namespace std;

int main() {
    int n;  // Variable para almacenar el número ingresado

    // Pedimos un número al usuario
    cout << "Ingrese un numero del 1 al 20: ";
    cin >> n;

    // Validamos que el número esté dentro del rango permitido
    if (n < 1 || n > 20) {
        cout << "Numero invalido";
    } else {

        // Usamos switch para convertir el número a romano
        switch (n) {

            case 1: cout << "I"; break;       // 1 → I
            case 2: cout << "II"; break;      // 2 → II
            case 3: cout << "III"; break;     // 3 → III
            case 4: cout << "IV"; break;      // 4 → IV
            case 5: cout << "V"; break;       // 5 → V
            case 6: cout << "VI"; break;      // 6 → VI
            case 7: cout << "VII"; break;     // 7 → VII
            case 8: cout << "VIII"; break;    // 8 → VIII
            case 9: cout << "IX"; break;      // 9 → IX
            case 10: cout << "X"; break;      // 10 → X
            case 11: cout << "XI"; break;     // 11 → XI
            case 12: cout << "XII"; break;    // 12 → XII
            case 13: cout << "XIII"; break;   // 13 → XIII
            case 14: cout << "XIV"; break;    // 14 → XIV
            case 15: cout << "XV"; break;     // 15 → XV
            case 16: cout << "XVI"; break;    // 16 → XVI
            case 17: cout << "XVII"; break;   // 17 → XVII
            case 18: cout << "XVIII"; break;  // 18 → XVIII
            case 19: cout << "XIX"; break;    // 19 → XIX
            case 20: cout << "XX"; break;     // 20 → XX
        }
    }

    return 0;  // Fin del programa
}
```
___
##### Código en Julia
```Julia
# Captura de la entrada del usuario
print("Ingrese un número entre 1 y 20: ")
n = parse(Int, readline())

# Control de límites del algoritmo
if n >= 1 && n <= 20
    # Mapeo de valores (Julia usa índices basados en 1)
    # Se añade un elemento vacío al inicio para manejar el índice 0 (n % 10 == 0)
    unidades = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
    decenas = ["", "X", "XX"]
    
    # Obtención de componentes
    d = div(n, 10)
    u = n % 10
    
    # Concatenación de resultados (sumar 1 al índice para evitar el 0)
    romano = decenas[d + 1] * unidades[u + 1]
    println("El número $n en romano es: $romano")
else
    println("Error: El número debe estar entre 1 y 20.")
end
```
#### Ejercicio 13
Calcular y visualizar la suma y el producto de los números pares comprendidos entre 20 y 400 ambos inclusive.
___
##### Algoritmo de solución:
Recorrer de 20 a 400.
Si es par → sumar y multiplicar.
Mostrar resultados.
Fórmula:

Par → n % 2 = 0
___
##### Código en Python
```Python
# Inicialización de acumuladores
# Python maneja automáticamente números de precisión arbitraria
suma_pares = 0
producto_pares = 1

# Iteración desde 20 hasta 400 con paso de 2
for i in range(20, 401, 2):
    suma_pares += i
    producto_pares *= i

# Visualización de los resultados calculados
print(f"Suma de los pares (20-400): {suma_pares}")
print(f"Producto de los pares (20-400): {producto_pares}")
```
___
##### Código en C++
```C++
#include <iostream>  // Librería para entrada y salida
using namespace std;

int main() {

    int suma = 0;          // Acumulador para la suma de números pares
    long long producto = 1; // Acumulador para el producto (número grande)

    // Recorremos desde 20 hasta 400
    for (int i = 20; i <= 400; i++) {

        // Verificamos si el número es par
        if (i % 2 == 0) {

            suma += i;        // Sumamos el número par
            producto *= i;    // Multiplicamos el número par
        }
    }

    // Mostramos los resultados
    cout << "Suma de los numeros pares entre 20 y 400: " << suma << endl;
    cout << "Producto de los numeros pares entre 20 y 400: " << producto << endl;

    return 0; // Fin del programa
}
```
___
##### Código en Julia
```Julia
# Inicialización de variables
suma_pares = 0
# Se usa BigInt para evitar el desbordamiento numérico en el producto
producto_pares = BigInt(1)

# Estructura repetitiva en el rango de 20 a 400 con incremento de 2
for i in 20:2:400
    global suma_pares += i
    global producto_pares *= i
end

# Impresión de las sumatorias y productos finales
println("Suma de los pares (20-400): $suma_pares")
println("Producto de los pares (20-400): $producto_pares")
```
#### Ejercicio 14
Escribir un algoritmo que lea una secuencia de numeros positivos acabada en 0 y encuentre el menor, el mayor y el promedio de los numero leidos.
___
##### Algoritmo de solución:
Algoritmo:

Leer números hasta 0.
Guardar suma, contador, menor y mayor.
Calcular promedio.
Mostrar resultados.
formula:
promedio = suma / cantidad
___
##### Código en Python
```Python
# Inicialización de variables de control
suma = 0
contador = 0
mayor = None
menor = None

print("Ingrese números positivos (0 para finalizar):")

while True:
    numero = float(input("Número: "))
    
    # Condición de salida del bucle
    if numero == 0:
        break
    
    # Validación de número positivo
    if numero > 0:
        suma += numero
        contador += 1
        
        # Actualización de valores máximos y mínimos
        if mayor is None or numero > mayor:
            mayor = numero
        if menor is None or numero < menor:
            menor = numero
    else:
        print("Por favor, ingrese solo números positivos.")

# Verificación de datos ingresados antes del cálculo
if contador > 0:
    promedio = suma / contador
    print(f"\nResultados:")
    print(f"Mayor: {mayor}")
    print(f"Menor: {menor}")
    print(f"Promedio: {promedio:.2f}")
else:
    print("No se ingresaron números válidos.")
```
___
##### Código en C++
```C++
#include <iostream>  // Librería para entrada y salida
using namespace std;

int main() {
    int num;              // Variable para almacenar cada número ingresado
    int menor, mayor;     // Para guardar el menor y mayor valor
    int suma = 0;         // Acumulador de la suma
    int contador = 0;     // Cantidad de números ingresados

    // Pedimos el primer número
    cout << "Ingrese un numero positivo (0 para terminar): ";
    cin >> num;

    // Si el primer número no es 0, inicializamos menor y mayor
    if (num != 0) {
        menor = num;
        mayor = num;
    }

    // Bucle que se repite hasta que el usuario ingrese 0
    while (num != 0) {

        suma += num;      // Acumulamos la suma
        contador++;       // Contamos el número ingresado

        // Actualizamos el menor
        if (num < menor) {
            menor = num;
        }

        // Actualizamos el mayor
        if (num > mayor) {
            mayor = num;
        }

        // Pedimos el siguiente número
        cout << "Ingrese otro numero positivo (0 para terminar): ";
        cin >> num;
    }

    // Verificamos que se haya ingresado al menos un número
    if (contador > 0) {
        double promedio = (double)suma / contador;  // Calculamos el promedio

        // Mostramos resultados
        cout << "Menor: " << menor << endl;
        cout << "Mayor: " << mayor << endl;
        cout << "Promedio: " << promedio << endl;
    } else {
        cout << "No se ingresaron numeros." << endl;
    }

    return 0; // Fin del programa
}
```
___
##### Código en Julia
```Julia
# Definición de acumuladores y extremos
suma = 0.0
contador = 0
mayor = -Inf
menor = Inf

println("Ingrese números positivos (0 para finalizar):")

while true
    print("Número: ")
    input_val = parse(Float64, readline())
    
    # Verificación del centinela de cierre
    if input_val == 0
        break
    end
    
    # Procesamiento de entradas positivas
    if input_val > 0
        global suma += input_val
        global contador += 1
        
        # Comparación para encontrar extremos
        if input_val > mayor
            global mayor = input_val
        end
        if input_val < menor
            global menor = input_val
        end
    else
        println("Entrada no válida. Use números positivos.")
    end
end

# Visualización de métricas finales
if contador > 0
    promedio = suma / contador
    println("\nEstadísticas:")
    println("Mayor: $mayor")
    println("Menor: $menor")
    println("Promedio: ", round(promedio, digits=2))
else
    println("No se procesaron datos.")
end
```
#### Ejercicio 15
Escribir un algoritmo que calcule y escribe los N números primeros términos de la sucesión de fibonacci (siendo N un número natural leído). La sucesión de números enteros de fibonacci se define de la forma
f1=f2=f1
fn = fn - 2 + fn - 1 con n>2
los primeros términos de esta sucesión son:
1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233,...
___
##### Algoritmo de solución:
Leer cantidad de términos.
Mostrar primeros valores.
Generar siguientes con suma.
Mostrar serie.

Fórmula:
F(n)=F(n−1)+F(n−2)
___
##### Código en Python
```Python
# Lectura del número de términos deseados
n = int(input("Ingrese el número de términos (N): "))

# Validación para asegurar que N sea un número natural
if n <= 0:
    print("Por favor, ingrese un número mayor a 0.")
elif n == 1:
    print("1")
else:
    # Inicialización de los dos primeros términos
    a, b = 1, 1
    print(a, b, end=" ")
    
    # Generación de los términos restantes desde el tercero hasta N
    for _ in range(3, n + 1):
        # Cálculo del siguiente término y actualización de valores
        a, b = b, a + b
        print(b, end=" ")
    print() # Salto de línea final
```
___
##### Código en C++
```C++
#include <iostream>  // Librería para entrada y salida
using namespace std;

int main() {
    int N;  // Cantidad de términos a mostrar

    // Pedimos el número de términos
    cout << "Ingrese la cantidad de terminos: ";
    cin >> N;

    // Validamos que sea un número natural positivo
    if (N <= 0) {
        cout << "Numero invalido.";
        return 0;
    }

    int a = 1, b = 1;  // Primeros dos términos de Fibonacci

    // Caso especial: si N >= 1 mostramos el primero
    if (N >= 1) cout << a << " ";

    // Caso especial: si N >= 2 mostramos el segundo
    if (N >= 2) cout << b << " ";

    // Generamos los siguientes términos desde el tercero
    for (int i = 3; i <= N; i++) {

        int siguiente = a + b;  // f(n) = f(n-1) + f(n-2)

        cout << siguiente << " ";  // Mostramos el término

        // Actualizamos los valores
        a = b;
        b = siguiente;
    }

    return 0;  // Fin del programa
}
```
___
##### Código en Julia
```Julia
# Captura de la entrada estándar
print("Ingrese el número de términos (N): ")
n = parse(Int, readline())

# Control de flujo según el valor de N
if n <= 0
    println("Por favor, ingrese un número natural positivo.")
elseif n == 1
    println("1")
else
    # Definición de las semillas f1 y f2
    a, b = 1, 1
    print("$a $b ")
    
    # Bucle iterativo para calcular fn = fn-1 + fn-2
    for i in 3:n
        # Uso de global para modificar variables en el entorno del bucle
        global a, b = b, a + b
        print("$b ")
    end
    println() # Salto de línea final
end
```
#### Ejercicio 16
Un numero natural se denomina perfecto cuado es igual a la suma de todos sus divisores, primos o no, excepto el mismo. Por ejemplo; 28 = 1 + 2 + 4 + 7+ 14 escribir si un numero natural positivo es perfecto o no?
___
##### Algoritmo de solución:
Leer número.
Sumar divisores propios.
Comparar con el número.
Mostrar resultado.
___
##### Código en Python
```Python
# Lectura del número natural positivo
n = int(input("Ingrese un número natural: "))

# Inicialización del acumulador de divisores
suma_divisores = 0

# Validación de entrada positiva
if n > 0:
    # Bucle para encontrar divisores hasta n/2
    for i in range(1, (n // 2) + 1):
        # Verificación de divisibilidad
        if n % i == 0:
            suma_divisores += i
    
    # Comparación de la suma con el número original
    if suma_divisores == n:
        print(f"El número {n} es perfecto.")
    else:
        print(f"El número {n} no es perfecto.")
else:
    print("Error: Debe ingresar un número natural positivo.")
```
___
##### Código en C++
```C++
#include <iostream>  // Librería para entrada y salida
using namespace std;

int main() {
    int n;              // Número ingresado por el usuario
    int suma = 0;       // Acumulador para la suma de divisores

    // Pedimos el número
    cout << "Ingrese un numero natural positivo: ";
    cin >> n;

    // Validamos que sea positivo
    if (n <= 0) {
        cout << "Numero invalido." << endl;
        return 0;
    }

    // Buscamos los divisores propios (sin incluir el mismo número)
    for (int i = 1; i < n; i++) {

        // Si i divide exactamente a n, es divisor
        if (n % i == 0) {
            suma += i;  // Sumamos el divisor
        }
    }

    // Verificamos si es número perfecto
    if (suma == n) {
        cout << n << " es un numero perfecto." << endl;
    } else {
        cout << n << " no es un numero perfecto." << endl;
    }

    return 0;  // Fin del programa
}

```
___
##### Código en Julia
```Julia
# Captura de la entrada estándar
print("Ingrese un número natural: ")
n = parse(Int, readline())

# Variable para almacenar la suma de los divisores
suma_divisores = 0

# Control de flujo para números positivos
if n > 0
    # Iteración desde 1 hasta la mitad del número (división entera)
    for i in 1:div(n, 2)
        # Identificación de divisores mediante el operador módulo
        if n % i == 0
            global suma_divisores += i
        end
    end
    
    # Evaluación de la condición de número perfecto
    if suma_divisores == n
        println("El número $n es perfecto.")
    else
        println("El número $n no es perfecto.")
    end
else
    println("Error: Ingrese un valor natural positivo.")
end
```
#### Ejercicio 17
Escribir un algoritmo que calcule y saque por pantalla los salarios de todos los empleados de una empresa. Cada empleado se identificará por un número desde el 1 hasta el total de empleados en la empresa. El salario es función de las horas trabajadas, que serán distintas para cada trabajador y se introducirán por teclado. El algoritmo aceptará también por teclado la cantidad que la empresa paga por hora ordinaria. Cuando un trabajador trabaje más de 40 horas, la empresa pagará las horas extras a 1.5 veces la hora ordinaria. 
Sugerencia: usar las variables ptas_hora, horas_trabajadas, salario,
contador, y las constantes NumEmpleados=50 y FactorExtra=1’5.
___
##### Algoritmo de solución:
Leer pago por hora.
Para cada empleado:
Leer horas.
Calcular salario.
Mostrar resultado.

Fórmula:
S=40p+(h−40)⋅1.5p
___
##### Código en Python
```Python
# Definición de constantes del sistema
NUM_EMPLEADOS = 50
FACTOR_EXTRA = 1.5

# Lectura del precio base por hora
ptas_hora = float(input("Ingrese el pago por hora ordinaria: "))

# Proceso iterativo para el cálculo de nómina
for contador in range(1, NUM_EMPLEADOS + 1):
    # Entrada de datos para cada trabajador
    horas_trabajadas = float(input(f"Horas trabajadas por el empleado {contador}: "))
    
    # Lógica de cálculo para horas ordinarias y extras
    if horas_trabajadas <= 40:
        salario = horas_trabajadas * ptas_hora
    else:
        # 40 horas base + el excedente con el factor de recargo
        horas_extra = horas_trabajadas - 40
        salario = (40 * ptas_hora) + (horas_extra * ptas_hora * FACTOR_EXTRA)
    
    # Visualización del resultado por pantalla
    print(f"El salario del empleado {contador} es: {salario:.2f}")
```
___
##### Código en C++
```C++
#include <iostream>  // Librería para entrada y salida
using namespace std;

int main() {
    const int NumEmpleados = 50;  // Número total de empleados
    const double FactorExtra = 1.5; // Pago de horas extra (1.5 veces)

    double ptas_hora;        // Pago por hora ordinaria
    double horas_trabajadas; // Horas trabajadas por cada empleado
    double salario;          // Salario calculado

    // Pedimos el pago por hora
    cout << "Ingrese el pago por hora: ";
    cin >> ptas_hora;

    // Recorremos todos los empleados
    for (int contador = 1; contador <= NumEmpleados; contador++) {

        // Pedimos las horas trabajadas por el empleado
        cout << "\nEmpleado #" << contador << endl;
        cout << "Horas trabajadas: ";
        cin >> horas_trabajadas;

        // Calculamos el salario
        if (horas_trabajadas <= 40) {
            // Si no hay horas extra
            salario = horas_trabajadas * ptas_hora;
        } else {
            // Si hay horas extra
            double horas_extra = horas_trabajadas - 40;

            salario = (40 * ptas_hora) + 
                      (horas_extra * ptas_hora * FactorExtra);
        }

        // Mostramos el salario del empleado
        cout << "Salario del empleado #" << contador 
             << ": " << salario << endl;
    }

    return 0;  // Fin del programa
}
```
___
##### Código en Julia
```Julia
# Declaración de constantes de nómina
const NUM_EMPLEADOS = 50
const FACTOR_EXTRA = 1.5

# Captura de la tarifa horaria ordinaria
print("Ingrese el pago por hora ordinaria: ")
ptas_hora = parse(Float64, readline())

# Bucle de control para la plantilla de empleados
for contador in 1:NUM_EMPLEADOS
    # Lectura de la jornada cumplida
    print("Horas trabajadas por el empleado $contador: ")
    horas_trabajadas = parse(Float64, readline())
    
    # Evaluación de condiciones para el cálculo del salario
    if horas_trabajadas <= 40
        salario = horas_trabajadas * ptas_hora
    else
        # Cálculo de retribución con horas extra incluidas
        horas_extra = horas_trabajadas - 40
        salario = (40 * ptas_hora) + (horas_extra * ptas_hora * FACTOR_EXTRA)
    end
    
    # Presentación del informe de salario
    println("El salario del empleado $contador es: ", round(salario, digits=2))
end
```
#### Ejercicio 18
Escribir un algoritmo que saque en cada linea el cuadrado, el cubo y la raíz cuadrada de los P primeros número naturales. (Considerar predefinida una función RzCuadrada(num)).
___
##### Algoritmo de solución:
Leer cantidad.
Para cada número:
Calcular cuadrado, cubo y raíz.
Mostrar resultados.
formula:
x elevado a 2 ; x elev a 3, raiz de x
___
##### Código en Python
```Python
import math

# Lectura de la cantidad de números a procesar
p = int(input("Ingrese la cantidad de números (P): "))

# Encabezado de la tabla de resultados
print(f"{'N':<5} {'Cuadrado':<10} {'Cubo':<10} {'Raíz':<10}")

# Iteración desde 1 hasta P
for i in range(1, p + 1):
    # Cálculo de potencias y raíz (usando math.sqrt como RzCuadrada)
    cuadrado = i ** 2
    cubo = i ** 3
    raiz = math.sqrt(i)
    
    # Visualización de los resultados formateados por línea
    print(f"{i:<5} {cuadrado:<10} {cubo:<10} {raiz:<10.4f}")
```
___
##### Código en C++
```C++
#include <iostream>  // Entrada y salida
#include <cmath>     // Para usar sqrt()
using namespace std;

// Función que calcula la raíz cuadrada (como indica el enunciado)
double RzCuadrada(double num) {
    return sqrt(num);
}

int main() {
    int P;  // Cantidad de números naturales

    // Pedimos el valor de P
    cout << "Ingrese la cantidad de numeros: ";
    cin >> P;

    // Validamos que sea positivo
    if (P <= 0) {
        cout << "Numero invalido." << endl;
        return 0;
    }

    // Recorremos los P primeros números naturales
    for (int i = 1; i <= P; i++) {

        int cuadrado = i * i;        // i^2
        int cubo = i * i * i;        // i^3
        double raiz = RzCuadrada(i); // √i

        // Mostramos resultados en una línea
        cout << "Numero: " << i
             << " | Cuadrado: " << cuadrado
             << " | Cubo: " << cubo
             << " | Raiz: " << raiz << endl;
    }

    return 0;  // Fin del programa
}
```
___
##### Código en Julia
```Julia
# Captura del valor P desde la entrada estándar
print("Ingrese la cantidad de números (P): ")
p = parse(Int, readline())

# Impresión del encabezado descriptivo
println("N\tCuadrado\tCubo\tRaíz")

# Estructura repetitiva para los primeros P números naturales
for i in 1:p
    # Operaciones de potencia y raíz cuadrada (sqrt)
    cuadrado = i^2
    cubo = i^3
    raiz = sqrt(i)
    
    # Salida de datos alineada por columnas
    println("$i\t$cuadrado\t\t$cubo\t$(round(raiz, digits=4))")
end
```
#### Ejercicio 19
Escribir un algoritmo para un cajero automático que calcule el número óptimo de billetes de 20, 10, 5 y 1 para una cantidad entera de dinero en Euros.
___
##### Algoritmo de solución:
Leer cantidad.
Dividir entre 20, luego 10, 5 y 1.
Mostrar cantidad de billetes.

Fórmula:

División entera: cantidad / valor
Resto: cantidad % valorLeer cantidad.
Dividir entre 20, luego 10, 5 y 1.
Mostrar cantidad de billetes.

Fórmula:

División entera: cantidad / valor
Resto: cantidad % valor
___
##### Código en Python
```Python
# Lectura de la cantidad entera en euros
monto = int(input("Ingrese la cantidad de euros a retirar: "))

# Definición de las denominaciones disponibles
denominaciones = [20, 10, 5, 1]
resultado = {}

# Procesamiento de cada denominación
for billete in denominaciones:
    # Cálculo de la cantidad de billetes y el resto sobrante
    cantidad = monto // billete
    monto = monto % billete
    resultado[billete] = cantidad

# Visualización del desglose óptimo
print("\nDesglose de billetes:")
for billete, cantidad in resultado.items():
    if cantidad > 0:
        print(f"Billetes de {billete}€: {cantidad}")
```
___
##### Código en C++
```C++
#include <iostream>  // Entrada y salida
using namespace std;

int main() {
    int cantidad;  // Cantidad de dinero ingresada

    // Pedimos la cantidad
    cout << "Ingrese la cantidad en euros: ";
    cin >> cantidad;

    // Validamos que sea positiva
    if (cantidad < 0) {
        cout << "Cantidad invalida." << endl;
        return 0;
    }

    // Calculamos el número óptimo de billetes (método voraz)
    int b20 = cantidad / 20;   // Billetes de 20
    cantidad = cantidad % 20;  // Resto

    int b10 = cantidad / 10;   // Billetes de 10
    cantidad = cantidad % 10;  

    int b5 = cantidad / 5;     // Billetes de 5
    cantidad = cantidad % 5;   

    int b1 = cantidad;         // Billetes de 1 (lo que queda)

    // Mostramos resultados
    cout << "Billetes de 20: " << b20 << endl;
    cout << "Billetes de 10: " << b10 << endl;
    cout << "Billetes de 5: " << b5 << endl;
    cout << "Billetes de 1: " << b1 << endl;

    return 0;  // Fin del programa
}
```
___
##### Código en Julia
```Julia
# Captura del monto total desde la entrada estándar
print("Ingrese la cantidad de euros a retirar: ")
monto = parse(Int, readline())

# Lista de valores de billetes de mayor a menor
denominaciones = [20, 10, 5, 1]

println("\nDesglose de billetes:")

# Iteración sobre las denominaciones para calcular el cambio
for billete in denominaciones
    # Uso de división entera para obtener la cantidad de billetes
    cantidad = div(monto, billete)
    
    # Actualización del monto restante mediante el operador módulo
    global monto = monto % billete
    
    # Impresión solo si la cantidad de billetes es mayor a cero
    if cantidad > 0
        println("Billetes de $billete€: $cantidad")
    end
end
```
#### Ejercicio 20
Se definen los números triangulares como los obtenidos por la suma de los números naturales sucesivos 1, 2, 3, .... Es decir, los primeros números triangulares son 1, 3, 6, 10, etc. Elabore un programa para imprimir el n-ésimo número triangular.
___
##### Algoritmo de solución:
Leer n.
Aplicar fórmula.
Mostrar resultado.
formula:
T(n) = n(n+1) / 2
___
##### Código en Python
```Python
# Lectura del índice del número triangular deseado
n = int(input("Ingrese la posición (n) del número triangular: "))

# Inicialización del acumulador
triangular = 0

# Validación de entrada para números naturales
if n > 0:
    # Sumatoria de los números desde 1 hasta n
    for i in range(1, n + 1):
        triangular += i
    
    # Visualización del resultado
    print(f"El {n}-ésimo número triangular es: {triangular}")
else:
    print("Por favor, ingrese un número natural positivo.")
```
___
##### Código en C++
```C++
#include <iostream>  // Entrada y salida
using namespace std;

int main() {
    int n;  // Posición del número triangular

    // Pedimos el valor de n
    cout << "Ingrese el valor de n: ";
    cin >> n;

    // Validamos que sea un número natural positivo
    if (n <= 0) {
        cout << "Numero invalido." << endl;
        return 0;
    }

    // Fórmula del número triangular:
    // Tn = n(n + 1) / 2
    int triangular = n * (n + 1) / 2;

    // Mostramos el resultado
    cout << "El numero triangular " << n 
         << " es: " << triangular << endl;

    return 0;  // Fin del programa
}
```
___
##### Código en Julio
```Julia
# Captura de la posición desde la entrada estándar
print("Ingrese la posición (n) del número triangular: ")
n = parse(Int, readline())

# Control de flujo para validación de entrada
if n > 0
    # Cálculo mediante la sumatoria del rango 1 a n
    # Julia permite usar la función sum() de forma eficiente
    triangular = sum(1:n)
    
    # Impresión del resultado final
    println("El $n-ésimo número triangular es: $triangular")
else
    println("Error: Se requiere un número natural positivo.")
end
```
#### Ejercicio 21
Elabore un programa que imprima el triángulo de Floyd hasta un valor dado. El triángulo contiene los números naturales correlativos, uno en la primera línea, dos en la segunda, etc; es decir, en la fila n-esima aparecen n valores.
___
##### Algoritmo de solución:
Leer filas.
Para cada fila:
Imprimir números desde 1 hasta i.
Fin.
___
##### Código en Python
```Python
# Lectura de la cantidad de filas para el triángulo
filas = int(input("Ingrese el número de filas: "))

# Contador para los números naturales correlativos
numero = 1

print(f"\nTriángulo de Floyd ({filas} filas):")

# Bucle externo controla las filas
for i in range(1, filas + 1):
    # Bucle interno controla la cantidad de elementos por fila (i elementos)
    for j in range(i):
        # Impresión del número seguido de un espacio
        print(numero, end=" ")
        # Incremento del contador global
        numero += 1
    # Salto de línea al terminar cada fila
    print()
```
___
##### Código en C++
```C++
#include <iostream>  // Entrada y salida
using namespace std;

int main() {
    int n;  // Número de filas

    cout << "Ingrese el numero de filas: ";
    cin >> n;

    // Validación
    if (n <= 0) {
        cout << "Numero invalido." << endl;
        return 0;
    }

    // Bucle para las filas
    for (int i = 1; i <= n; i++) {

        // Bucle para imprimir cada fila
        for (int j = 1; j <= i; j++) {
            cout << j << " ";  // Imprime desde 1 hasta i
        }

        cout << endl;  // Salto de línea
    }

    return 0;
}
```
___
##### Código en Julia
```Julia
# Captura de la entrada para determinar la altura del triángulo
print("Ingrese el número de filas: ")
filas = parse(Int, readline())

# Inicialización del primer número natural
numero = 1

println("\nTriángulo de Floyd ($filas filas):")

# Estructura repetitiva para las filas
for i in 1:filas
    # Estructura para imprimir i elementos en la fila i
    for j in 1:i
        # Visualización del número actual
        print("$numero ")
        # Incremento del contador (requiere global en entornos de script)
        global numero += 1
    end
    # Avance a la siguiente línea
    println()
end
```
#### Ejercicio 22
Generar la tabla para "N" varía entre 1.0 y 1.1 con incremento de 0.001. la tabla

| N   | N^2  | N^0,5 |
| --- | ---- | ----- |
| 99  | 9999 | 999   |
```Python
import math

# Definición de encabezados de la tabla
print(f"{'N':<8} {'N^2':<12} {'N^0.5':<12}")
print("-" * 32)

# Generación de la tabla mediante un rango basado en pasos enteros
# Se realizan 101 pasos para cubrir de 1.0 a 1.1 inclusive
for i in range(101):
    # Cálculo del valor N actual con precisión
    n = 1.0 + (i * 0.001)
    
    # Cálculo de potencia cuadrada y raíz cuadrada
    cuadrado = n ** 2
    raiz = math.sqrt(n)
    
    # Visualización de resultados con formato de decimales fijo
    print(f"{n:<8.3f} {cuadrado:<12.6f} {raiz:<12.6f}")
```
___
```C++
#include <iostream>  // Entrada y salida
#include <cmath>     // Para pow() y sqrt()
#include <iomanip>   // Para formato de tabla
using namespace std;

int main() {

    // Encabezado de la tabla
    cout << fixed << setprecision(3);
    cout << "N\t\tN^2\t\tN^0.5" << endl;

    // Bucle desde 1.0 hasta 1.1 con incremento de 0.001
    for (double N = 1.0; N <= 1.1; N += 0.001) {

        double cuadrado = pow(N, 2);   // N^2
        double raiz = pow(N, 0.5);     // N^0.5 (raíz cuadrada)

        // Imprimimos cada fila
        cout << N << "\t\t"
             << cuadrado << "\t\t"
             << raiz << endl;
    }

    return 0;  // Fin del programa
}

```
___
```Julia
# Impresión del encabezado descriptivo
println("N\t\tN^2\t\tN^0.5")
println("------------------------------------------")

# Uso del rango nativo con paso decimal definido
# Julia gestiona la precisión de los rangos de forma eficiente
for n in 1.0:0.001:1.1
    # Cálculo del cuadrado y la raíz cuadrada (sqrt)
    cuadrado = n^2
    raiz = sqrt(n)
    
    # Presentación de datos con redondeo para limpieza visual
    # Se utiliza interpolación para alinear las columnas
    println("$(round(n, digits=3))\t\t$(round(cuadrado, digits=6))\t\t$(round(raiz, digits=6))")
end
```
#### Ejercicio 23.
Un matemático descubre un método para multiplicar cualquier número entero por 11 mediante la suma de sus dígitos. sea un número entero N que se expresa con M dígitos, el producto de dicho número por 11 esta dado por la siguiente regla: "el dígito de las unidades es igual al dígito de las unidades de N, el dígito de las decenas es igual a la suma de los dígitos de unidades y decenas de N, el dígito de las centenas es igual a la suma de los dígitos de decenas y centenas de N, y así sucesivamente". Ejemplo: el producto del número 3247 por 11 es 35717. Escribir un algoritmo para que pueda multiplicar cualquier número entero por 11.
___
##### Algoritmo de solución:
Leer número.
Recorrer de derecha a izquierda.
Sumar dígitos con acarreo.
Construir resultado.
Mostrar resultado.

Fórmula:

dᵢ + dᵢ₊₁ + acarreo
___
##### Código en Python
```Python
# Lectura del número como cadena para procesar sus dígitos
n_str = input("Ingrese un número entero: ")

# Conversión a lista de enteros en orden inverso (unidades primero)
digitos = [int(d) for d in n_str[::-1]]
resultado_digitos = []
acarreo = 0

# El dígito de las unidades del resultado es igual al de N
resultado_digitos.append(digitos[0])

# Proceso de sumas de dígitos contiguos (decenas en adelante)
for i in range(len(digitos) - 1):
    suma = digitos[i] + digitos[i+1] + acarreo
    resultado_digitos.append(suma % 10)
    acarreo = suma // 10

# Procesamiento del último dígito de N más cualquier acarreo pendiente
ultima_suma = digitos[-1] + acarreo
# Se agregan los dígitos finales (pueden ser uno o dos si hay acarreo)
while ultima_suma > 0:
    resultado_digitos.append(ultima_suma % 10)
    ultima_suma //= 10

# Reversión y unión para mostrar el producto final
final = "".join(map(str, resultado_digitos[::-1]))
print(f"El producto de {n_str} x 11 es: {final}")
```
___
##### Código en C++
```C++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string n_str;
    cout << "Ingrese el numero entero: ";
    cin >> n_str;

    string resultado = "";
    int acarreo = 0;
    int n = n_str.length();

    // Procesamos de derecha a izquierda
    for (int i = n; i >= 0; i--) {
        int suma;
        if (i == n) {
            suma = n_str[i-1] - '0';
        } else if (i == 0) {
            suma = (n_str[i] - '0') + acarreo;
        } else {
            suma = (n_str[i] - '0') + (n_str[i-1] - '0') + acarreo;
        }

        if (i == 0) {
            resultado = to_string(suma) + resultado;
        } else {
            resultado = to_string(suma % 10) + resultado;
            acarreo = suma / 10;
        }
    }

    cout << "El producto por 11 es: " << resultado << endl;
    return 0;
}
```
___
##### Código en Julia
```Julia
# Captura del número desde la entrada estándar
print("Ingrese un número entero: ")
n_str = readline()

# Extracción de dígitos en orden inverso
digitos = [parse(Int, d) for d in reverse(n_str)]
resultado = Int[]
acarreo = 0

# Asignación del primer dígito (unidades)
push!(resultado, digitos[1])

# Iteración para calcular sumas de pares adyacentes
for i in 1:(length(digitos) - 1)
    suma = digitos[i] + digitos[i+1] + acarreo
    push!(resultado, suma % 10)
    global acarreo = div(suma, 10)
end

# Inclusión del último dígito y el acarreo final
ultima_suma = digitos[end] + acarreo
while ultima_suma > 0
    push!(resultado, ultima_suma % 10)
    global ultima_suma = div(ultima_suma, 10)
end

# Unión de la lista invertida para obtener el número final
final = join(reverse(resultado))
println("El producto de $n_str x 11 es: $final")
```
#### Ejercicio 24.
La escuela Académica Profesional de Ingeniería de Sistemas quiere realizar los algoritmos necesarios para realizar la evaluación y selección de un conjunto de mil postulantes para el ingreso de admisión para el Programa de Graduación de Ingeniería de Sistemas, considerando los siguientes parámetros:
- Numero de vacantes: 150.
- Número de preguntas es 100.
- La nota mínima de ingreso es 120 puntos.
- El examen consta de tres partes: Las 40 primeras preguntas de Razonamiento y Verbal (2 puntos correcto, -1 si es incorrecto), 30 preguntas de conocimiento en ciencias (3 puntos correcto, -1.5 si es incorrecto), y 30 preguntas de conocimiento en letras (1 punto correcto, -0.5 si es incorrecto).
1. Calcule la nota final del postulante y determine si ingreso o no ingreso el postulante.
2. Calcule la media aritmética de las notas de todos los postulantes.
3. Calcule la varianza de las notas de los postulantes.
4. Calcule la nota mínima y máxima de los ingresantes.
___
##### Algoritmo de solución:
Leer datos de 1000 personas.
Calcular notas.
Calcular media y varianza.
Ordenar notas.
Determinar ingresantes.
Mostrar resultados.
____
##### Código en Python
```Python
import math

# Definición de constantes del proceso de admisión
POSTULANTES = 1000
VACANTES = 150
NOTA_MINIMA = 120

todos_puntajes = []

# Procesamiento de cada uno de los 1000 postulantes
for i in range(1, POSTULANTES + 1):
    print(f"\nDatos del postulante {i}:")
    
    # Lectura de respuestas por secciones
    c_rv = int(input("RV - Correctas (máx 40): "))
    i_rv = int(input("RV - Incorrectas: "))
    
    c_ci = int(input("Ciencias - Correctas (máx 30): "))
    i_ci = int(input("Ciencias - Incorrectas: "))
    
    c_le = int(input("Letras - Correctas (máx 30): "))
    i_le = int(input("Letras - Incorrectas: "))

    # Cálculo del puntaje final basado en ponderaciones
    puntaje = (c_rv * 2 - i_rv * 1) + (c_ci * 3 - i_ci * 1.5) + (c_le * 1 - i_le * 0.5)
    todos_puntajes.append(puntaje)

# Cálculos estadísticos generales (Media y Varianza)
media = sum(todos_puntajes) / POSTULANTES
varianza = sum((x - media)**2 for x in todos_puntajes) / POSTULANTES

# Selección de ingresantes: puntaje >= 120 y dentro de las 150 vacantes
aptos = [p for p in todos_puntajes if p >= NOTA_MINIMA]
aptos.sort(reverse=True)
ingresantes = aptos[:VACANTES]

# Resultados finales
print(f"\nMedia aritmética general: {media:.2f}")
print(f"Varianza de las notas: {varianza:.2f}")

if ingresantes:
    print(f"Total de ingresantes: {len(ingresantes)}")
    print(f"Nota máxima de ingresantes: {max(ingresantes)}")
    print(f"Nota mínima de ingresantes: {min(ingresantes)}")
else:
    print("Ningún postulante alcanzó la nota mínima de ingreso.")
```
___
##### Código en C++
```C++
#include <iostream>
#include <cmath>   // Para varianza
using namespace std;

int main() {
    const int TOTAL = 1000;     // Número de postulantes
    const int VACANTES = 150;   // Vacantes disponibles

    // Variables para cada postulante
    int rm_correctas, rm_incorrectas;
    int c_correctas, c_incorrectas;
    int l_correctas, l_incorrectas;

    double nota[TOTAL];  // Arreglo para guardar notas

    double suma = 0;

    // =========================
    // INGRESO Y CÁLCULO DE NOTAS
    // =========================
    for (int i = 0; i < TOTAL; i++) {

        cout << "\nPostulante #" << i + 1 << endl;

        // Razonamiento (40 preguntas)
        cout << "Correctas RM: ";
        cin >> rm_correctas;
        cout << "Incorrectas RM: ";
        cin >> rm_incorrectas;

        // Ciencias (30 preguntas)
        cout << "Correctas Ciencias: ";
        cin >> c_correctas;
        cout << "Incorrectas Ciencias: ";
        cin >> c_incorrectas;

        // Letras (30 preguntas)
        cout << "Correctas Letras: ";
        cin >> l_correctas;
        cout << "Incorrectas Letras: ";
        cin >> l_incorrectas;

        // Cálculo de la nota
        double nota_final =
            (rm_correctas * 2 - rm_incorrectas * 1) +
            (c_correctas * 3 - c_incorrectas * 1.5) +
            (l_correctas * 1 - l_incorrectas * 0.5);

        nota[i] = nota_final;
        suma += nota_final;
    }

    // =========================
    // MEDIA
    // =========================
    double media = suma / TOTAL;

    // =========================
    // VARIANZA
    // =========================
    double suma_var = 0;
    for (int i = 0; i < TOTAL; i++) {
        suma_var += pow(nota[i] - media, 2);
    }
    double varianza = suma_var / TOTAL;

    // =========================
    // ORDENAR (para obtener ingresantes)
    // =========================
    for (int i = 0; i < TOTAL - 1; i++) {
        for (int j = i + 1; j < TOTAL; j++) {
            if (nota[i] < nota[j]) {
                double temp = nota[i];
                nota[i] = nota[j];
                nota[j] = temp;
            }
        }
    }

    // =========================
    // INGRESANTES
    // =========================
    int ingresantes = 0;
    for (int i = 0; i < VACANTES; i++) {
        if (nota[i] >= 120) {
            ingresantes++;
        }
    }

    double max_ingreso = nota[0];                       // Mayor nota
    double min_ingreso = nota[ingresantes - 1];         // Menor de los que ingresaron

    // =========================
    // RESULTADOS
    // =========================
    cout << "\nRESULTADOS GENERALES\n";
    cout << "Media: " << media << endl;
    cout << "Varianza: " << varianza << endl;

    cout << "Numero de ingresantes: " << ingresantes << endl;
    cout << "Nota maxima de ingresantes: " << max_ingreso << endl;
    cout << "Nota minima de ingresantes: " << min_ingreso << endl;

    return 0;
}
```
___
##### Código en Julia
```Julia
using Statistics

const TOTAL_POSTULANTES = 1000
const VACANTES = 150

# Generamos datos de ejemplo
notas = Float64[]

for i in 1:TOTAL_POSTULANTES
    # Lógica de puntajes
    c1, inc1 = 30, 10
    c2, inc2 = 20, 10
    c3, inc3 = 25, 5
    
    nota = (c1*2 - inc1*1) + (c2*3 - inc2*1.5) + (c3*1 - inc3*0.5)
    push!(notas, nota)
end

# Estadísticas
media = mean(notas)
# varianza poblacional (dividiendo por N)
varianza = var(notas, corrected=false)

# Selección
aptos = filter(x -> x >= 120, notas)
sort!(aptos, rev=true)

ingresantes = aptos[1:min(length(aptos), VACANTES)]

println("--- ESTADÍSTICAS SISTEMA ---")
println("Media: ", round(media, digits=2))
println("Varianza: ", round(varianza, digits=2))

if !isempty(ingresantes)
    println("Ingresantes: ", length(ingresantes))
    println("Nota Máxima: ", maximum(ingresantes))
    println("Nota Mínima: ", minimum(ingresantes))
else
    println("Sin ingresantes.")
end
```
