# Ejercicios propuestos
## Ejercicio 1
Hacer un programa que calcule el factorial de todos los números hasta un número dado por teclado.
### Pseudocódigo:
> **INICIO**
>   **REPETIR**
>     **ESCRIBIR** "Introduzca un número natural ($n \ge 0$): "
>     **LEER** $n$
>     **SI** $n < 0$ **ENTONCES**
>       **ESCRIBIR** "Error: El número debe ser mayor o igual a cero."
>     **FINSI**
>   **HASTA QUE** $n \ge 0$
> $factorial \leftarrow 1$
> **PARA** $i \leftarrow 0$ **HASTA** $n$ **HACER**
>     **SI** $i > 0$ **ENTONCES**
>       $factorial \leftarrow factorial \cdot i$
>     **FINSI**
>     **ESCRIBIR** "El factorial de ", $i, " es: ", factorial$
>   **FINPARA**
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
while True:
    try:
        n = int(input("Introduzca un número natural (n >= 0): "))
        if n >= 0:
            break
        print("Error: El número debe ser mayor o igual a cero.")
    except ValueError:
        print("Error: Ingrese un número entero válido.")

factorial = 1
for i in range(n + 1):
    if i > 0:
        factorial *= i
    print(f"El factorial de {i} es: {factorial}")
```
---
#### Código en C++:
```cpp
#include <iostream>

int main() {
    int n;
    
    do {
        std::cout << "Introduzca un numero natural (n >= 0): ";
        if (!(std::cin >> n)) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            n = -1;
        }
        if (n < 0) {
            std::cout << "Error: El numero debe ser mayor o igual a cero." << std::endl;
        }
    } while (n < 0);

    double factorial = 1; // Usamos double para manejar números grandes

    for (int i = 0; i <= n; ++i) {
        if (i > 0) {
            factorial *= i;
        }
        std::cout << "El factorial de " << i << " es: " << factorial << std::endl;
    }

    return 0;
}
```
---
#### Código en Julia:
```Julia
n = -1
while n < 0
    print("Introduzca un número natural (n >= 0): ")
    input_val = readline()
    parsed = tryparse(Int, input_val)
    if parsed !== nothing && parsed >= 0
        global n = parsed
    else
        println("Error: El número debe ser mayor o igual a cero.")
    end
end

factorial_acc = BigInt(1)
for i in 0:n
    if i > 0
        global factorial_acc *= i
    end
    println("El factorial de $i es: $factorial_acc")
end
```
---
### Prueba de escritorio:
Simulación con entrada $n = 3$:

| **Iteración (i)** | **Condición (i>0)** | **Operación (factorial⋅i)** | **factorial (Resultado)** | **Salida Pantalla**       |
| ----------------- | ------------------- | --------------------------- | ------------------------- | ------------------------- |
| Inicial           | -                   | -                           | 1                         | -                         |
| 0                 | Falso               | -                           | 1                         | "El factorial de 0 es: 1" |
| 1                 | Verdadero           | $1 \cdot 1$                 | 1                         | "El factorial de 1 es: 1" |
| 2                 | Verdadero           | $1 \cdot 2$                 | 2                         | "El factorial de 2 es: 2" |
| 3                 | Verdadero           | $2 \cdot 3$                 | 6                         | "El factorial de 3 es: 6" |

---
### Resultados:
```
Introduzca un número natural (n >= 0): 3
El factorial de 0 es: 1
El factorial de 1 es: 1
El factorial de 2 es: 2
El factorial de 3 es: 6
```
---
## Ejercicio 2
Realizar un algoritmo que calcule la potencia de un número real elevado a un número real dado su numerador y denominador, sin utilizar funciones ni procedimientos.
### Pseudocódigo:
> **INICIO**
>   **ESCRIBIR** "Ingrese la base (número real): "
>   **LEER** $base$
>   **ESCRIBIR** "Ingrese el numerador de la potencia: "
>   **LEER** $num$
>   **ESCRIBIR** "Ingrese el denominador de la potencia: "
>   **LEER** $den$
> **SI** $den = 0$ **ENTONCES**
>     **ESCRIBIR** "Error: El denominador no puede ser cero."
>   **SINO**
>     // Fase 1: Potencia entera $P = base^{|num|}$
>     $potenciaBase \leftarrow 1$
>     $n\_abs \leftarrow$ ABS($num$)
>     **PARA** $i \leftarrow 1$ **HASTA** $n\_abs$ **HACER**
>       $potenciaBase \leftarrow potenciaBase \cdot base$
>     **FINPARA**
> **SI** $num < 0$ **ENTONCES**
>       $potenciaBase \leftarrow 1 / potenciaBase$
>     **FINSI**
> // Fase 2: Raíz enésima mediante Newton-Raphson
>     // $x_{n+1} = \frac{1}{D} \cdot \left( (D-1) \cdot x_n + \frac{P}{x_n^{D-1}} \right)$
>     $x \leftarrow potenciaBase / den$ // Estimación inicial
>     **SI** $x = 0$ **ENTONCES** $x \leftarrow 1$ **FINSI**
> **PARA** $j \leftarrow 1$ **HASTA** 100 **HACER** >       $f\_der \leftarrow 1$
>       **PARA** $k \leftarrow 1$ **HASTA** $den - 1$ **HACER**
>         $f\_der \leftarrow f\_der \cdot x$
>       **FINPARA**
>       $x \leftarrow \frac{1}{den} \cdot ( (den - 1) \cdot x + (potenciaBase / f\_der) )$
>     **FINPARA**
> **ESCRIBIR** "El resultado es: ", $x$
>   **FINSI**
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
base = float(input("Ingrese la base: "))
num = int(input("Ingrese el numerador: "))
den = int(input("Ingrese el denominador: "))

if den == 0:
    print("Error: Denominador no puede ser cero.")
else:
    # Potencia entera
    p_base = 1.0
    for _ in range(abs(num)):
        p_base *= base
    
    if num < 0:
        p_base = 1.0 / p_base

    # Raíz (Newton-Raphson)
    x = p_base / den if p_base != 0 else 0
    if x == 0 and p_base != 0: x = 1.0
    
    if p_base > 0:
        for _ in range(100):
            f_der = 1.0
            for _ in range(den - 1):
                f_der *= x
            x = (1.0 / den) * ((den - 1) * x + (p_base / f_der))
    
    print(f"El resultado es: {x:.6f}")
```
---
#### Código en C++:
```cpp
#include <iostream>
#include <iomanip>

int main() {
    double base, p_base = 1.0, x;
    int num, den;

    std::cout << "Base: "; std::cin >> base;
    std::cout << "Numerador: "; std::cin >> num;
    std::cout << "Denominador: "; std::cin >> den;

    if (den == 0) {
        std::cout << "Error: Denominador cero." << std::endl;
        return 1;
    }

    int n_abs = (num < 0) ? -num : num;
    for (int i = 0; i < n_abs; ++i) p_base *= base;
    if (num < 0) p_base = 1.0 / p_base;

    x = p_base / den;
    if (x <= 0) x = 1.0;

    for (int j = 0; j < 100; ++j) {
        double f_der = 1.0;
        for (int k = 0; k < den - 1; ++k) f_der *= x;
        x = (1.0 / den) * ((den - 1) * x + (p_base / f_der));
    }

    std::cout << "El resultado es: " << std::fixed << std::setprecision(6) << x << std::endl;
    return 0;
}
```
---
#### Código en Julia:
```Julia
print("Base: ")
base = parse(Float64, readline())
print("Numerador: ")
num = parse(Int, readline())
print("Denominador: ")
den = parse(Int, readline())

if den == 0
    println("Error: Denominador cero.")
else
    p_base = 1.0
    for i in 1:abs(num)
        global p_base *= base
    end
    if num < 0
        global p_base = 1.0 / p_base
    end

    x = p_base / den
    if x <= 0 global x = 1.0 end

    for j in 1:100
        f_der = 1.0
        for k in 1:(den - 1)
            global f_der *= x
        end
        global x = (1.0 / den) * ((den - 1) * x + (p_base / f_der))
    end

    println("El resultado es: ", round(x, digits=6))
end
```
---
### Prueba de escritorio:
Cálculo de $8^{2/3}$ (que es $\sqrt[3]{8^2} = \sqrt[3]{64} = 4$):

|**Variable**|**Valor / Operación**|**Resultado**|
|---|---|---|
|$base, num, den$|$8, 2, 3$|Entradas|
|$potenciaBase$|$8 \cdot 8$|64|
|$x$ (inicial)|$64 / 3$|21.33|
|Iteración 1|$x = \frac{1}{3} (2 \cdot 21.33 + \frac{64}{21.33^2})$|14.33|
|Iteración 2|$x = \frac{1}{3} (2 \cdot 14.33 + \frac{64}{14.33^2})$|9.65|
|...|...|...|
|Iteración N|Convergencia|**4.0000**|

---
### Resultados:
```
Ingrese la base: 8
Ingrese el numerador: 2
Ingrese el denominador: 3
El resultado es: 4.000000

Ingrese la base: 2
Ingrese el numerador: 1
Ingrese el denominador: 2
El resultado es: 1.414214
```
___
## Ejercicio 3
Construya un programa que imprima la suma de los cuadrados de los 100 primeros números naturales.

$$\sum_{i=1}^{100} i^2 = 1^2 + 2^2 + 3^2 + \dots + 100^2$$

### Pseudocódigo:
> **INICIO**
>   $suma \leftarrow 0$
>   **PARA** $i \leftarrow 1$ **HASTA** 100 **HACER**
>     $cuadrado \leftarrow i \cdot i$
>     $suma \leftarrow suma + cuadrado$
>   **FINPARA**
>   **ESCRIBIR** "La suma de los cuadrados es: ", $suma$
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
suma = 0

for i in range(1, 101):
    suma += i**2

print(f"La suma de los cuadrados de los primeros 100 números naturales es: {suma}")
```
---
#### Código en C++:
```cpp
#include <iostream>

int main() {
    long long suma = 0; // Usamos long long para prevenir desbordamiento

    for (int i = 1; i <= 100; ++i) {
        suma += (long long)i * i;
    }

    std::cout << "La suma de los cuadrados de los primeros 100 numeros es: " << suma << std::endl;

    return 0;
}
```
---
#### Código en Julia:
```Julia
suma = 0

for i in 1:100
    global suma += i^2
end

println("La suma de los cuadrados de los primeros 100 números naturales es: $suma")
```
---
### Prueba de escritorio:
Simulación de las primeras 4 iteraciones para validar la lógica:

|**Iteración (i)**|**Cálculo (i2)**|**Suma Acumulada**|
|---|---|---|
|Inicial|-|0|
|1|$1^2 = 1$|$0 + 1 = 1$|
|2|$2^2 = 4$|$1 + 4 = 5$|
|3|$3^2 = 9$|$5 + 9 = 14$|
|4|$4^2 = 16$|$14 + 16 = 30$|
|...|...|...|
|100|$100^2 = 10000$|**338350**|

---
### Resultados:
```
La suma de los cuadrados de los primeros 100 números naturales es: 338350
```
---
## Ejercicio 4
Un número gemelo es aquel cuya primera mitad de dígitos es igual a la segunda mitad. Si la cantidad de dígitos es impar, no deberá tomarse en cuenta el dígito del medio Ej. 123123. Hacer un programa para contar los números gemelos de una secuencia de números de entrada.
___
### Pseudocódigo:
> **INICIO**
>   $contadorGemelos \leftarrow 0$
>   **ESCRIBIR** "¿Cuántos números desea ingresar?: "
>   **LEER** $cantidad$
> **PARA** $k \leftarrow 1$ **HASTA** $cantidad$ **HACER**
>     **ESCRIBIR** "Ingrese número: "
>     **LEER** $numTexto$
>     $longitud \leftarrow$ LONGITUD($numTexto$)
> **SI** $longitud < 2$ **ENTONCES**
>       **CONTINUAR**
>     **FINSI**
> $mitad \leftarrow \text{TRUNCAR}(longitud / 2)$
>     $primeraMitad \leftarrow$ SUBSTR($numTexto, 1, mitad$)
>     $segundaMitad \leftarrow$ SUBSTR($numTexto, longitud - mitad + 1, mitad$)
> **SI** $primeraMitad = segundaMitad$ **ENTONCES**
>       $contadorGemelos \leftarrow contadorGemelos + 1$
>     **FINSI**
>   **FINPARA**
> **ESCRIBIR** "Total de números gemelos: ", $contadorGemelos$
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
try:
    n = int(input("¿Cuántos números desea ingresar?: "))
    contador_gemelos = 0

    for i in range(n):
        num_str = input(f"Ingrese el número {i+1}: ")
        longitud = len(num_str)
        
        if longitud >= 2:
            mitad = longitud // 2
            primera_mitad = num_str[:mitad]
            segunda_mitad = num_str[longitud - mitad:]
            
            if primera_mitad == segunda_mitad:
                contador_gemelos += 1
                
    print(f"Total de números gemelos encontrados: {contador_gemelos}")
except ValueError:
    print("Error: Ingrese una cantidad válida.")
```
---
#### Código en C++:
```cpp
#include <iostream>
#include <string>

int main() {
    int cantidad, contadorGemelos = 0;

    std::cout << "¿Cuantos numeros desea ingresar?: ";
    if (!(std::cin >> cantidad)) return 1;

    for (int i = 0; i < cantidad; ++i) {
        std::string numStr;
        std::cout << "Ingrese numero: ";
        std::cin >> numStr;

        int len = numStr.length();
        if (len >= 2) {
            int mitad = len / 2;
            std::string primera = numStr.substr(0, mitad);
            std::string segunda = numStr.substr(len - mitad, mitad);

            if (primera == segunda) {
                contadorGemelos++;
            }
        }
    }

    std::cout << "Total de numeros gemelos encontrados: " << contadorGemelos << std::endl;
    return 0;
}
```
---
#### Código en Julia:
```Julia
print("¿Cuántos números desea ingresar?: ")
cantidad = parse(Int, readline())
contador_gemelos = 0

for i in 1:cantidad
    print("Ingrese número: ")
    num_str = readline()
    len_str = length(num_str)
    
    if len_str >= 2
        mitad = div(len_str, 2)
        primera_mitad = num_str[1:mitad]
        segunda_mitad = num_str[end-mitad+1:end]
        
        if primera_mitad == segunda_mitad
            global contador_gemelos += 1
        end
    end
end

println("Total de números gemelos encontrados: $contador_gemelos")
```
---
### Prueba de escritorio:

|**Iteración**|**Número (numTexto)**|**Longitud**|**Mitad (Lhalf​)**|**Primera Mitad**|**Segunda Mitad**|**¿Es Gemelo?**|
|---|---|---|---|---|---|---|
|1|"123123"|6|3|"123"|"123"|**Sí**|
|2|"45945"|5|2|"45"|"45"|**Sí**|
|3|"1234"|4|2|"12"|"34"|No|
|4|"7"|1|-|-|-|No|

---
### Resultados:
```
¿Cuántos números desea ingresar?: 3
Ingrese número: 123123
Ingrese número: 45945
Ingrese número: 1020
Total de números gemelos encontrados: 2
```
---
## Ejercicio 5
Calcule la suma y producto de fracciones, antes de realizar las operaciones es necesario que las dos fracciones estén simplificadas a su mínima expresión.
### Pseudocódigo:
> **INICIO**
>   **ESCRIBIR** "Fracción 1 (numerador y denominador): "
>   **LEER** $n1, d1$
>   **ESCRIBIR** "Fracción 2 (numerador y denominador): "
>   **LEER** $n2, d2$
> // Simplificar Fracción 1
>   $comun1 \leftarrow MCD(n1, d1)$
>   $n1 \leftarrow n1 / comun1$, $d1 \leftarrow d1 / comun1$
> // Simplificar Fracción 2
>   $comun2 \leftarrow MCD(n2, d2)$
>   $n2 \leftarrow n2 / comun2$, $d2 \leftarrow d2 / comun2$
> // Operación Suma: $\frac{n1}{d1} + \frac{n2}{d2} = \frac{n1 \cdot d2 + n2 \cdot d1}{d1 \cdot d2}$
>   $sumaNum \leftarrow (n1 \cdot d2) + (n2 \cdot d1)$
>   $sumaDen \leftarrow d1 \cdot d2$
>   $comunSuma \leftarrow MCD(sumaNum, sumaDen)$
> // Operación Producto: $\frac{n1}{d1} \cdot \frac{n2}{d2} = \frac{n1 \cdot n2}{d1 \cdot d2}$
>   $prodNum \leftarrow n1 \cdot n2$
>   $prodDen \leftarrow d1 \cdot d2$
>   $comunProd \leftarrow MCD(prodNum, prodDen)$
> **ESCRIBIR** "Suma simplificada: ", $sumaNum/comunSuma, "/", sumaDen/comunSuma$
>   **ESCRIBIR** "Producto simplificado: ", $prodNum/comunProd, "/", prodDen/comunProd$
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
def obtener_mcd(a, b):
    while b:
        a, b = b, a % b
    return abs(a)

def simplificar(n, d):
    mcd = obtener_mcd(n, d)
    return n // mcd, d // mcd

# Entrada de datos
n1 = int(input("N1: "))
d1 = int(input("D1: "))
n2 = int(input("N2: "))
d2 = int(input("D2: "))

# 1. Simplificación previa
n1, d1 = simplificar(n1, d1)
n2, d2 = simplificar(n2, d2)

# 2. Suma
s_num = (n1 * d2) + (n2 * d1)
s_den = d1 * d2
s_num, s_den = simplificar(s_num, s_den)

# 3. Producto
p_num = n1 * n2
p_den = d1 * d2
p_num, p_den = simplificar(p_num, p_den)

print(f"\nSuma: {s_num}/{s_den}")
print(f"Producto: {p_num}/{p_den}")
```
---
#### Código en C++:
```cpp
#include <iostream>

long long mcd(long long a, long long b) {
    return b == 0 ? a : mcd(b, a % b);
}

int main() {
    long long n1, d1, n2, d2;
    std::cout << "Fraccion 1 (n d): "; std::cin >> n1 >> d1;
    std::cout << "Fraccion 2 (n d): "; std::cin >> n2 >> d2;

    // Simplificar iniciales
    long long c1 = mcd(n1, d1); n1 /= c1; d1 /= c1;
    long long c2 = mcd(n2, d2); n2 /= c2; d2 /= c2;

    // Calcular Suma
    long long sn = (n1 * d2) + (n2 * d1);
    long long sd = d1 * d2;
    long long cs = mcd(sn, sd);

    // Calcular Producto
    long long pn = n1 * n2;
    long long pd = d1 * d2;
    long long cp = mcd(pn, pd);

    std::cout << "\nSuma: " << sn/cs << "/" << sd/cs << std::endl;
    std::cout << "Producto: " << pn/cp << "/" << pd/cp << std::endl;

    return 0;
}
```
---
### Prueba de escritorio:
Considerando $F_1 = 4/8$ y $F_2 = 6/9$:

|**Paso**|**Operación**|**Resultado**|
|---|---|---|
|**Simplificar $F_1$**|$MCD(4, 8) = 4$|$1/2$|
|**Simplificar $F_2$**|$MCD(6, 9) = 3$|$2/3$|
|**Suma Proceso**|$(1 \cdot 3 + 2 \cdot 2) / (2 \cdot 3)$|$7/6$|
|**Suma Simpl.**|$MCD(7, 6) = 1$|**$7/6$**|
|**Prod. Proceso**|$(1 \cdot 2) / (2 \cdot 3)$|$2/6$|
|**Prod. Simpl.**|$MCD(2, 6) = 2$|**$1/3$**|

---
### Resultado
```
Fracción 1 (n d): 4 8
Fracción 2 (n d): 6 9

--- Procesando ---
Fracción 1 simplificada: 1/2
Fracción 2 simplificada: 2/3

Suma simplificada: 7/6
Producto simplificado: 1/3
```
___
## Ejercicio 6
Escriba un programa que lea dos fechas dadas por un día, mes y año e indique cuál de ellas es anterior en el tiempo a la otra. El programa seguirá leyendo pares de fechas hasta que se introduzca un valor 0 como día de la primera fecha (en tal caso, no seguirá leyendo dicha fecha).
### Pseudocódigo:
> **INICIO**
>   **REPETIR**
>     **ESCRIBIR** "Ingrese día de la primera fecha (0 para salir): "
>     **LEER** $d1$
> **SI** $d1 \neq 0$ **ENTONCES**
>       **ESCRIBIR** "Ingrese mes y año de la primera fecha: "
>       **LEER** $m1, a1$
>       **ESCRIBIR** "Ingrese segunda fecha (día mes año): "
>       **LEER** $d2, m2, a2$
> **SI** $a1 < a2$ **ENTONCES**
>         **ESCRIBIR** "La primera fecha es anterior."
>       **SINO SI** $a1 > a2$ **ENTONCES**
>         **ESCRIBIR** "La segunda fecha es anterior."
>       **SINO** // Años iguales
>         **SI** $m1 < m2$ **ENTONCES**
>           **ESCRIBIR** "La primera fecha es anterior."
>         **SINO SI** $m1 > m2$ **ENTONCES**
>           **ESCRIBIR** "La segunda fecha es anterior."
>         **SINO** // Meses iguales
>           **SI** $d1 < d2$ **ENTONCES**
>             **ESCRIBIR** "La primera fecha es anterior."
>           **SINO SI** $d1 > d2$ **ENTONCES**
>             **ESCRIBIR** "La segunda fecha es anterior."
>           **SINO**
>             **ESCRIBIR** "Ambas fechas son iguales."
>           **FINSI**
>         **FINSI**
>       **FINSI**
>     **FINSI**
>   **HASTA QUE** $d1 = 0$
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
while True:
    d1 = int(input("\nDía fecha 1 (0 para salir): "))
    if d1 == 0:
        break
        
    m1 = int(input("Mes fecha 1: "))
    a1 = int(input("Año fecha 1: "))
    
    print("Segunda fecha:")
    d2 = int(input("Día fecha 2: "))
    m2 = int(input("Mes fecha 2: "))
    a2 = int(input("Año fecha 2: "))

    if (a1, m1, d1) < (a2, m2, d2):
        print("La primera fecha es anterior.")
    elif (a1, m1, d1) > (a2, m2, d2):
        print("La segunda fecha es anterior.")
    else:
        print("Las fechas son idénticas.")
```
---
#### Código en C++:
```cpp
#include <iostream>

int main() {
    int d1, m1, a1, d2, m2, a2;

    while (true) {
        std::cout << "\nDia fecha 1 (0 para salir): ";
        std::cin >> d1;
        if (d1 == 0) break;

        std::cout << "Mes y año fecha 1: ";
        std::cin >> m1 >> a1;
        std::cout << "Segunda fecha (dia mes año): ";
        std::cin >> d2 >> m2 >> a2;

        if (a1 < a2) std::cout << "La primera es anterior.";
        else if (a1 > a2) std::cout << "La segunda es anterior.";
        else if (m1 < m2) std::cout << "La primera es anterior.";
        else if (m1 > m2) std::cout << "La segunda es anterior.";
        else if (d1 < d2) std::cout << "La primera es anterior.";
        else if (d1 > d2) std::cout << "La segunda es anterior.";
        else std::cout << "Son iguales.";
        std::cout << std::endl;
    }
    return 0;
}
```
---
#### Código en Julia:
```Julia
while true
    print("\nDía fecha 1 (0 para salir): ")
    d1 = parse(Int, readline())
    if d1 == 0 break end
    
    print("Mes y año fecha 1: ")
    m1 = parse(Int, readline())
    a1 = parse(Int, readline())
    
    print("Segunda fecha (día mes año): ")
    d2 = parse(Int, readline())
    m2 = parse(Int, readline())
    a2 = parse(Int, readline())

    if (a1, m1, d1) < (a2, m2, d2)
        println("La primera es anterior.")
    elseif (a1, m1, d1) > (a2, m2, d2)
        println("La segunda es anterior.")
    else
        println("Son iguales.")
    end
end
```
---

### Prueba de escritorio:

|**Intento**|**Fecha 1**|**Fecha 2**|**Comparación**|**Resultado**|
|---|---|---|---|---|
|1|15/05/2024|10/05/2024|$a1=a2, m1=m2, d1>d2$|Segunda anterior|
|2|01/01/2025|31/12/2024|$a1 > a2$|Segunda anterior|
|3|10/02/2024|10/03/2024|$a1=a2, m1<m2$|Primera anterior|
|4|0|-|Salida|Fin|

---
### Resultados:
```
Día fecha 1 (0 para salir): 10
Mes y año fecha 1: 5 2024
Segunda fecha (dia mes año): 15 5 2024
La primera fecha es anterior.

Día fecha 1 (0 para salir): 0
```
___
## Ejercicio 7
Modifique el programa anterior para que permita un número máximo de intentos (dado por la constante _MAXINTENTOS_, superados los cuales terminará imprimiendo el mensaje "_Lo siento, ha perdido_".)
### Pseudocódigo:

> **INICIO**
>   $MAXINTENTOS \leftarrow 3$
>   $intentos \leftarrow 0$
>   **REPETIR**
>     **ESCRIBIR** "Fecha 1 - Ingrese día (0 para salir): "
>     **LEER** $d1$
> **SI** $d1 = 0$ **ENTONCES**
>       **ROMPER CICLO**
>     **FINSI**
> **ESCRIBIR** "Resto de la Fecha 1 (mes y año) y Fecha 2 completa: "
>     **LEER** $m1, a1, d2, m2, a2$
> // Lógica de comparación
>     **SI** $(a1 < a2)$ **O** $(a1 = a2$ **Y** $m1 < m2)$ **O** $(a1 = a2$ **Y** $m1 = m2$ **Y** $d1 < d2)$ **ENTONCES**
>       **ESCRIBIR** "La primera fecha es anterior."
>     **SINO SI** $a1 = a2$ **Y** $m1 = m2$ **Y** $d1 = d2$ **ENTONCES**
>       **ESCRIBIR** "Ambas fechas son iguales."
>     **SINO**
>       **ESCRIBIR** "La segunda fecha es anterior."
>     **FINSI**
> $intentos \leftarrow intentos + 1$
> **SI** $intentos \ge MAXINTENTOS$ **ENTONCES**
>       **ESCRIBIR** "Lo siento, ha perdido."
>       **ROMPER CICLO**
>     **FINSI**
> **HASTA QUE** $d1 = 0$
> **FIN**

---
### Algoritmos:
#### Código en Python:
```Python
MAXINTENTOS = 3
intentos = 0

while intentos < MAXINTENTOS:
    try:
        d1 = int(input(f"Intento {intentos + 1}/{MAXINTENTOS} - Fecha 1 Día (0 para salir): "))
        if d1 == 0:
            break
        
        m1 = int(input("Fecha 1 Mes: "))
        a1 = int(input("Fecha 1 Año: "))
        
        d2 = int(input("Fecha 2 Día: "))
        m2 = int(input("Fecha 2 Mes: "))
        a2 = int(input("Fecha 2 Año: "))

        if (a1, m1, d1) < (a2, m2, d2):
            print("Resultado: La primera fecha es anterior.")
        elif (a1, m1, d1) > (a2, m2, d2):
            print("Resultado: La segunda fecha es anterior.")
        else:
            print("Resultado: Ambas fechas son iguales.")
        
        intentos += 1
        
        if intentos == MAXINTENTOS:
            print("Lo siento, ha perdido.")
            
    except ValueError:
        print("Error: Ingrese números enteros válidos.")
```
___
#### Código en C++:
```cpp
#include <iostream>

int main() {
    const int MAXINTENTOS = 3;
    int intentos = 0;
    int d1, m1, a1, d2, m2, a2;

    while (intentos < MAXINTENTOS) {
        std::cout << "Intento " << intentos + 1 << "/" << MAXINTENTOS << " - Fecha 1 Dia (0 para salir): ";
        std::cin >> d1;
        
        if (d1 == 0) break;

        std::cout << "Mes y Año: "; std::cin >> m1 >> a1;
        std::cout << "Fecha 2 - Dia, Mes y Año: "; std::cin >> d2 >> m2 >> a2;

        if (a1 < a2 || (a1 == a2 && m1 < m2) || (a1 == a2 && m1 == m2 && d1 < d2))
            std::cout << "Resultado: La primera fecha es anterior." << std::endl;
        else if (a1 == a2 && m1 == m2 && d1 == d2)
            std::cout << "Resultado: Ambas fechas son iguales." << std::endl;
        else
            std::cout << "Resultado: La segunda fecha es anterior." << std::endl;

        intentos++;

        if (intentos == MAXINTENTOS) {
            std::cout << "Lo siento, ha perdido." << std::endl;
        }
    }

    return 0;
}
```

#### Código en Julia:
```Julia
const MAXINTENTOS = 3
intentos = 0

while intentos < MAXINTENTOS
    print("Intento $(intentos + 1)/$MAXINTENTOS - Fecha 1 Día (0 para salir): ")
    d1 = parse(Int, readline())
    
    if d1 == 0
        break
    end

    print("Fecha 1 - Mes y Año: ")
    input_f1 = split(readline())
    m1, a1 = parse(Int, input_f1[1]), parse(Int, input_f1[2])

    print("Fecha 2 - Día, Mes y Año: ")
    input_f2 = split(readline())
    d2, m2, a2 = parse(Int, input_f2[1]), parse(Int, input_f2[2]), parse(Int, input_f2[3])

    if (a1, m1, d1) < (a2, m2, d2)
        println("Resultado: La primera fecha es anterior.")
    elseif (a1, m1, d1) == (a2, m2, d2)
        println("Resultado: Ambas fechas son iguales.")
    else
        println("Resultado: La segunda fecha es anterior.")
    end

    global intentos += 1

    if intentos == MAXINTENTOS
        println("Lo siento, ha perdido.")
    end
end
```

---

### Prueba de escritorio:

| **Iteración** | **intentos** | **d1** | **Comparación**           | **intentos final** | **Salida**                          |
| ------------- | ------------ | ------ | ------------------------- | ------------------ | ----------------------------------- |
| 1             | 0            | 10     | $10/01/2020 < 10/01/2021$ | 1                  | "Primera anterior"                  |
| 2             | 1            | 05     | $05/02/2022 > 01/01/2022$ | 2                  | "Segunda anterior"                  |
| 3             | 2            | 20     | $20/03/2023 = 20/03/2023$ | 3                  | "Iguales" + "Lo siento, ha perdido" |

---
### Resultados:
```
Intento 1/3 - Fecha 1 Día (0 para salir): 10
Fecha 1 Mes: 1
Fecha 1 Año: 2020
Fecha 2 Día: 10
Fecha 2 Mes: 1
Fecha 2 Año: 2021
Resultado: La primera fecha es anterior.
... (repite hasta el intento 3) ...
Lo siento, ha perdido.
```

---
## Ejercicio 8
Modifique el programa anterior para que permita un número máximo de intentos (dado por la constante _MAXINTENTOS_, superados los cuales terminará imprimiendo el mensaje "_Lo siento, ha perdido_".)
### Pseudocódigo:
> **INICIO**
>   **CONSTANTE** $MAXINTENTOS \leftarrow 3$
>   $intentos \leftarrow 0$
>   $continuar \leftarrow$ **VERDADERO**
> **MIENTRAS** $intentos < MAXINTENTOS$ **Y** $continuar$ **HACER**
>     **ESCRIBIR** "Intento ", $intentos + 1$, "/", $MAXINTENTOS$
>     **ESCRIBIR** "Fecha 1 - Ingrese día (0 para salir): "
>     **LEER** $d1$
> **SI** $d1 = 0$ **ENTONCES**
>       $continuar \leftarrow$ **FALSO**
>     **SINO**
>       **ESCRIBIR** "Fecha 1 - Ingrese mes y año: "
>       **LEER** $m1, a1$
>       **ESCRIBIR** "Fecha 2 - Ingrese día, mes y año: "
>       **LEER** $d2, m2, a2$
> **SI** $(a1 < a2)$ **O** $(a1 = a2 \text{ Y } m1 < m2)$ **O** $(a1 = a2 \text{ Y } m1 = m2 \text{ Y } d1 < d2)$ **ENTONCES**
>         **ESCRIBIR** "La primera fecha es anterior."
>       **SINO SI** $(a1 = a2 \text{ Y } m1 = m2 \text{ Y } d1 = d2)$ **ENTONCES**
>         **ESCRIBIR** "Ambas fechas son iguales."
>       **SINO**
>         **ESCRIBIR** "La segunda fecha es anterior."
>       **FINSI**
> $intentos \leftarrow intentos + 1$
>     **FINSI**
>   **FINMIENTRAS**
> **SI** $intentos = MAXINTENTOS$ **Y** $continuar$ **ENTONCES**
>     **ESCRIBIR** "Lo siento, ha perdido."
>   **FINSI**
> **FIN**

---
### Algoritmos:
#### Código en Python:
```Python
MAXINTENTOS = 3
intentos = 0
continuar = True

while intentos < MAXINTENTOS and continuar:
    try:
        print(f"\n--- Intento {intentos + 1} de {MAXINTENTOS} ---")
        d1 = int(input("Fecha 1 - Día (0 para salir): "))
        
        if d1 == 0:
            continuar = False
        else:
            m1 = int(input("Fecha 1 - Mes: "))
            a1 = int(input("Fecha 1 - Año: "))

            d2 = int(input("Fecha 2 - Día: "))
            m2 = int(input("Fecha 2 - Mes: "))
            a2 = int(input("Fecha 2 - Año: "))

            fecha1 = (a1, m1, d1)
            fecha2 = (a2, m2, d2)

            if fecha1 < fecha2:
                print("Resultado: La primera fecha es anterior.")
            elif fecha1 > fecha2:
                print("Resultado: La segunda fecha es anterior.")
            else:
                print("Resultado: Ambas fechas son iguales.")
            
            intentos += 1
    except ValueError:
        print("Error: Ingrese solo números enteros.")

if intentos == MAXINTENTOS and continuar:
    print("\nLo siento, ha perdido.")
```

---
#### Código en C++:
```cpp
#include <iostream>

int main() {
    const int MAXINTENTOS = 3;
    int intentos = 0;
    bool continuar = true;
    int d1, m1, a1, d2, m2, a2;

    while (intentos < MAXINTENTOS && continuar) {
        std::cout << "\n--- Intento " << intentos + 1 << " de " << MAXINTENTOS << " ---" << std::endl;
        std::cout << "Fecha 1 - Dia (0 para salir): ";
        std::cin >> d1;

        if (d1 == 0) {
            continuar = false;
        } else {
            std::cout << "Fecha 1 - Mes y Año: ";
            std::cin >> m1 >> a1;
            std::cout << "Fecha 2 - Dia, Mes y Año: ";
            std::cin >> d2 >> m2 >> a2;

            if (a1 < a2 || (a1 == a2 && m1 < m2) || (a1 == a2 && m1 == m2 && d1 < d2)) {
                std::cout << "Resultado: La primera fecha es anterior." << std::endl;
            } else if (a1 == a2 && m1 == m2 && d1 == d2) {
                std::cout << "Resultado: Ambas fechas son iguales." << std::endl;
            } else {
                std::cout << "Resultado: La segunda fecha es anterior." << std::endl;
            }
            intentos++;
        }
    }

    if (intentos == MAXINTENTOS && continuar) {
        std::cout << "\nLo siento, ha perdido." << std::endl;
    }

    return 0;
}
```

---
#### Código en Julia:
```Julia
const MAXINTENTOS = 3
intentos = 0
continuar = true

while intentos < MAXINTENTOS && continuar
    println("\n--- Intento $(intentos + 1) de $MAXINTENTOS ---")
    print("Fecha 1 - Día (0 para salir): ")
    d1 = parse(Int, readline())

    if d1 == 0
        global continuar = false
    else
        print("Fecha 1 - Mes y Año (separados por espacio): ")
        f1_rest = split(readline())
        m1, a1 = parse(Int, f1_rest[1]), parse(Int, f1_rest[2])

        print("Fecha 2 - Día, Mes y Año (separados por espacio): ")
        f2 = split(readline())
        d2, m2, a2 = parse(Int, f2[1]), parse(Int, f2[2]), parse(Int, f2[3])

        if (a1, m1, d1) < (a2, m2, d2)
            println("Resultado: La primera fecha es anterior.")
        elseif (a1, m1, d1) > (a2, m2, d2)
            println("Resultado: La segunda fecha es anterior.")
        else
            println("Resultado: Ambas fechas son iguales.")
        end
        global intentos += 1
    end
end

if intentos == MAXINTENTOS && continuar
    println("\nLo siento, ha perdido.")
end
```

---
### Prueba de escritorio:

|**Iteración**|**MAXINTENTOS**|**intentos**|**d1**|**Comparación**|**Salida**|
|---|---|---|---|---|---|
|1|3|0|10|$10/01/2020 < 15/01/2020$|"Primera anterior"|
|2|3|1|20|$20/05/2021 > 10/02/2021$|"Segunda anterior"|
|3|3|2|05|$05/05/2022 = 05/05/2022$|"Iguales"|
|Fin Bucle|3|3|-|Condición $3 < 3$ es Falsa|"Lo siento, ha perdido"|

---
### Resultados:
```
--- Intento 1 de 3 ---
Fecha 1 - Día (0 para salir): 1
Fecha 1 - Mes: 1
Fecha 1 - Año: 2024
Fecha 2 - Día: 1
Fecha 2 - Mes: 1
Fecha 2 - Año: 2025
Resultado: La primera fecha es anterior.

--- Intento 2 de 3 ---
... (se repite hasta el intento 3) ...

Lo siento, ha perdido.
```

---
## Ejercicio 9
Modifique el programa anterior para que imprima la tabla de multiplicar completa del 1 al 10.
___
## Ejercicio 10
El siguiente programa calcula el factorial de un número:
> **inicio**
> **mostrar** fin_linea, "Introduzca un entero positivo: "
> **leer** $n$
> _factorial_ $\leftarrow$ 1
> **para** $i \leftarrow 1 .. n, +1$
>     _factorial_ $\leftarrow$ _factorial_ $*$ $i$
> **finPara**
> **mostrar** fin_linea, "El factorial de ", $n$, " es: ", _factorial_
> **fin**

Modifíquelo transformando la estructura **para** en una estructura **mientras**. Luego traduzca las dos versiones del programa a un lenguaje de programación como C++.
### Pseudocódigo:
> **INICIO**
>   **ESCRIBIR** "Introduzca un entero positivo: "
>   **LEER** $n$
>   $factorial \leftarrow 1$
>   $i \leftarrow 1$ // Inicialización del contador
> **MIENTRAS** $i \le n$ **HACER**
>     $factorial \leftarrow factorial \cdot i$
>     $i \leftarrow i + 1$ // Incremento del contador
>   **FINMIENTRAS**
> **ESCRIBIR** "El factorial de ", $n$, " es: ", $factorial$
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
try:
    n = int(input("Introduzca un entero positivo: "))
    if n < 0:
        print("Error: El número debe ser positivo.")
    else:
        factorial = 1
        i = 1
        while i <= n:
            factorial *= i
            i += 1
        print(f"El factorial de {n} es: {factorial}")
except ValueError:
    print("Error: Ingrese un número entero válido.")
```

---
#### Código en C++:
```cpp
#include <iostream>

int main() {
    int n;
    std::cout << "Introduzca un entero positivo: ";
    if (!(std::cin >> n) || n < 0) {
        std::cout << "Entrada no valida." << std::endl;
        return 1;
    }

    unsigned long long factorial = 1;
    int i = 1;
    
    while (i <= n) {
        factorial *= i;
        i++;
    }

    std::cout << "El factorial de " << n << " es: " << factorial << std::endl;

    return 0;
}
```

---
#### Código en Julia:
```Julia
print("Introduzca un entero positivo: ")
input_str = readline()
n = parse(Int, input_str)

if n < 0
    println("Error: El número debe ser positivo.")
else
    factorial = BigInt(1)
    i = 1
    while i <= n
        global factorial *= i
        global i += 1
    end
    println("El factorial de $n es: $factorial")
end
```

---
### Prueba de escritorio:
Considerando una entrada de $n = 4$:

| **Paso**    | **n** | **i** | **Condición (i≤n)** | **factorial**    | **i (nuevo)** |
| ----------- | ----- | ----- | ------------------- | ---------------- | ------------- |
| Inicial     | 4     | 1     | -                   | 1                | -             |
| Iteración 1 | 4     | 1     | $1 \le 4$ (V)       | $1 \cdot 1 = 1$  | 2             |
| Iteración 2 | 4     | 2     | $2 \le 4$ (V)       | $1 \cdot 2 = 2$  | 3             |
| Iteración 3 | 4     | 3     | $3 \le 4$ (V)       | $2 \cdot 3 = 6$  | 4             |
| Iteración 4 | 4     | 4     | $4 \le 4$ (V)       | $6 \cdot 4 = 24$ | 5             |
| Fin Bucle   | 4     | 5     | $5 \le 4$ (F)       | 24               | -             |

---
### Resultados:
```
Introduzca un entero positivo: 4
El factorial de 4 es: 24
```
---
## Ejercicio 11
A partir de un conjunto de puntos, enteros o reales, calcular el número de puntos que están situados dentro de las áreas delimitadas por las circunferencias c1 = (centro en (5,4) radio 2) y c2 = (centro en (-5,-4) radio 3), incluyendo sus puntos fronterizos.
___
Para resolver este problema, utilizaremos la ecuación canónica de la circunferencia: $(x - h)^2 + (y - k)^2 \le R^2$. Un punto $(x, y)$ está dentro de la circunferencia si la suma de los cuadrados de las diferencias de sus coordenadas respecto al centro es menor o igual al cuadrado del radio.
### Pseudocódigo:
> **INICIO**
>   $contadorPuntos \leftarrow 0$
>   **ESCRIBIR** "¿Cuántos puntos desea evaluar?: "
>   **LEER** $n$
> **PARA** $i \leftarrow 1$ **HASTA** $n$ **HACER**
>     **ESCRIBIR** "Ingrese coordenadas del punto ", $i, " (x, y): "$
>     **LEER** $px, py$
> // Verificación para C1: Centro (5, 4), Radio 2
>     $distanciaC1 \leftarrow (px - 5)^2 + (py - 4)^2$
>     // Verificación para C2: Centro (-5, -4), Radio 3
>     $distanciaC2 \leftarrow (px + 5)^2 + (py + 4)^2$
> **SI** $distanciaC1 \le 4$ **O** $distanciaC2 \le 9$ **ENTONCES**
>       $contadorPuntos \leftarrow contadorPuntos + 1$
>     **FINSI**
>   **FINPARA**
> **ESCRIBIR** "Total de puntos dentro de las áreas: ", $contadorPuntos$
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
try:
    n = int(input("¿Cuántos puntos desea evaluar?: "))
    contador_puntos = 0

    for i in range(1, n + 1):
        print(f"\nPunto {i}:")
        px = float(input("  x: "))
        py = float(input("  y: "))

        # (x - h)^2 + (y - k)^2 <= R^2
        en_c1 = (px - 5)**2 + (py - 4)**2 <= 4
        en_c2 = (px + 5)**2 + (py + 4)**2 <= 9

        if en_c1 or en_c2:
            contador_puntos += 1
            print("  El punto está dentro de un área.")
        else:
            print("  El punto está fuera.")

    print(f"\nTotal de puntos dentro de las áreas: {contador_puntos}")
except ValueError:
    print("Error: Entrada no válida.")
```
---
#### Código en C++:
```cpp
#include <iostream>

int main() {
    int n;
    int contadorPuntos = 0;

    std::cout << "¿Cuantos puntos desea evaluar?: ";
    if (!(std::cin >> n)) return 1;

    for (int i = 1; i <= n; ++i) {
        double px, py;
        std::cout << "\nPunto " << i << " (x y): ";
        std::cin >> px >> py;

        double distC1 = (px - 5) * (px - 5) + (py - 4) * (py - 4);
        double distC2 = (px + 5) * (px + 5) + (py + 4) * (py + 4);

        if (distC1 <= 4.0 || distC2 <= 9.0) {
            contadorPuntos++;
        }
    }

    std::cout << "\nTotal de puntos dentro: " << contadorPuntos << std::endl;

    return 0;
}
```
---
#### Código en Julia:
```Julia
print("¿Cuántos puntos desea evaluar?: ")
n = parse(Int, readline())
contador_puntos = 0

for i in 1:n
    println("\nPunto $i:")
    print("  x: ")
    px = parse(Float64, readline())
    print("  y: ")
    py = parse(Float64, readline())

    # Ecuaciones de las circunferencias
    dist_c1 = (px - 5)^2 + (py - 4)^2
    dist_c2 = (px + 5)^2 + (py + 4)^2

    if dist_c1 <= 4 || dist_c2 <= 9
        global contador_puntos += 1
    end
end

println("\nTotal de puntos dentro de las áreas: $contador_puntos")
```
---
### Prueba de escritorio:

|**Punto (px,py)**|**(px−5)2+(py−4)2**|**≤4?**|**(px+5)2+(py+4)2**|**≤9?**|**Resultado (OR)**|
|---|---|---|---|---|---|
|(5, 4)|$0^2 + 0^2 = 0$|**V**|$10^2 + 8^2 = 164$|F|**Dentro**|
|(7, 4)|$2^2 + 0^2 = 4$|**V**|$12^2 + 8^2 = 208$|F|**Dentro** (Borde C1)|
|(-5, -7)|$10^2 + 11^2 = 221$|F|$0^2 + (-3)^2 = 9$|**V**|**Dentro** (Borde C2)|
|(0, 0)|$25 + 16 = 41$|F|$25 + 16 = 41$|F|**Fuera**|

---
### Resultados:
```
¿Cuántos puntos desea evaluar?: 3

Punto 1: (5, 4) -> El punto está dentro de un área.
Punto 2: (0, 0) -> El punto está fuera.
Punto 3: (-5, -5) -> El punto está dentro de un área.

Total de puntos dentro de las áreas: 2
```
---
## Ejercicio 12
Una compañía desea transmitir datos por teléfono pero están preocupados de que sus teléfonos estén "pinchados". Todos sus datos es transmiten como enteros de cuatro dígitos. Se le ha pedido a usted escribir un programa que cifre los datos para poderlos transmitir con mayor seguridad. Su programa deberá leer un entero de 4 dígitos y cifrarlo como sigue: sustituya cada dígito por (ese_digito+7)%10. Luego intercambie el primer y tercer dígitos luego el segundo y cuarto dígitos. Luego imprima el entero cifrado. Escriba otro programa que recoja un entero de cuatro dígitos cifrado y lo descifre para formar el número original.
___
Este problema de criptografía básica se basa en una transposición de posiciones y una sustitución aritmética módulo 10. Para descifrar, simplemente invertimos los pasos: volvemos a intercambiar las posiciones y aplicamos la operación inversa $(c + 3) \pmod{10}$.
### Pseudocódigo (Cifrado):
> **INICIO**
>   **ESCRIBIR** "Ingrese un número entero de 4 dígitos: "
>   **LEER** $n$
>   $d1 \leftarrow (n / 1000) \pmod{10}$
>   $d2 \leftarrow (n / 100) \pmod{10}$
>   $d3 \leftarrow (n / 10) \pmod{10}$
>   $d4 \leftarrow n \pmod{10}$
>   $c1 \leftarrow (d1 + 7) \pmod{10}$
>   $c2 \leftarrow (d2 + 7) \pmod{10}$
>   $c3 \leftarrow (d3 + 7) \pmod{10}$
>   $c4 \leftarrow (d4 + 7) \pmod{10}$
> // Intercambiar: 1 con 3, 2 con 4
>   $n\_cifrado \leftarrow (c3 \cdot 1000) + (c4 \cdot 100) + (c1 \cdot 10) + c2$
>   **ESCRIBIR** "Número cifrado: ", $n\_cifrado$ 
> **FIN**
### Pseudocódigo (Descifrado):
> **INICIO**
>   **ESCRIBIR** "Ingrese el número de 4 dígitos cifrado: "
>   **LEER** $nc$
>   $c1 \leftarrow (nc / 1000) \pmod{10}$
>   $c2 \leftarrow (nc / 100) \pmod{10}$
>   $c3 \leftarrow (nc / 10) \pmod{10}$
>   $c4 \leftarrow nc \pmod{10}$
> // Deshacer intercambio (1-3, 2-4)
>   // Original c1 está en pos 3, c2 en pos 4, c3 en pos 1, c4 en pos 2
>   $d1 \leftarrow (c3 + 3) \pmod{10}$
>   $d2 \leftarrow (c4 + 3) \pmod{10}$
>   $d3 \leftarrow (c1 + 3) \pmod{10}$
>   $d4 \leftarrow (c2 + 3) \pmod{10}$
> $n\_original \leftarrow (d1 \cdot 1000) + (d2 \cdot 100) + (d3 \cdot 10) + d4$
>   **ESCRIBIR** "Número original: ", $n\_original$
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
def cifrar(n):
    d = [(int(digit) + 7) % 10 for digit in f"{n:04d}"]
    # Swap 0-2 and 1-3
    return f"{d[2]}{d[3]}{d[0]}{d[1]}"

def descifrar(n):
    c = [int(digit) for digit in f"{n:04d}"]
    # Deshacer swap: c[0] es pos 3, c[1] es pos 4, c[2] es pos 1, c[3] es pos 2
    res = [0]*4
    res[0] = (c[2] + 3) % 10
    res[1] = (c[3] + 3) % 10
    res[2] = (c[0] + 3) % 10
    res[3] = (c[1] + 3) % 10
    return "".join(map(str, res))

op = input("1. Cifrar\n2. Descifrar\nOpción: ")
num = int(input("Ingrese el número de 4 dígitos: "))
if op == '1':
    print(f"Cifrado: {cifrar(num)}")
else:
    print(f"Descifrado: {descifrar(num)}")
```

---
#### Código en C++:
```cpp
#include <iostream>
#include <iomanip>

void procesar(int n, bool cifrar) {
    int d[4];
    d[0] = (n / 1000) % 10;
    d[1] = (n / 100) % 10;
    d[2] = (n / 10) % 10;
    d[3] = n % 10;

    if (cifrar) {
        for(int i=0; i<4; i++) d[i] = (d[i] + 7) % 10;
        std::cout << "Cifrado: " << d[2] << d[3] << d[0] << d[1] << std::endl;
    } else {
        int r[4];
        r[0] = (d[2] + 3) % 10;
        r[1] = (d[3] + 3) % 10;
        r[2] = (d[0] + 3) % 10;
        r[3] = (d[1] + 3) % 10;
        std::cout << "Descifrado: " << r[0] << r[1] << r[2] << r[3] << std::endl;
    }
}

int main() {
    int opcion, num;
    std::cout << "1. Cifrar\n2. Descifrar\nSeleccion: ";
    std::cin >> opcion;
    std::cout << "Numero: ";
    std::cin >> num;
    procesar(num, opcion == 1);
    return 0;
}
```

---
#### Código en Julia:
```Julia
function cifrar(n)
    s = lpad(n, 4, '0')
    d = [(parse(Int, c) + 7) % 10 for c in s]
    return "$(d[3])$(d[4])$(d[1])$(d[2])"
end

function descifrar(n)
    s = lpad(n, 4, '0')
    c = [parse(Int, x) for x in s]
    # Invertir: c[1] es pos 3, c[2] es pos 4, c[3] es pos 1, c[4] es pos 2
    d1 = (c[3] + 3) % 10
    d2 = (c[4] + 3) % 10
    d3 = (c[1] + 3) % 10
    d4 = (c[2] + 3) % 10
    return "$d1$d2$d3$d4"
end

println("1. Cifrar, 2. Descifrar:")
op = readline()
println("Número:")
num = readline()

if op == "1"
    println("Resultado: ", cifrar(num))
else
    println("Resultado: ", descifrar(num))
end
```

---
### Prueba de escritorio:
**Caso: Cifrar el número 1234**
1. Dígitos: $1, 2, 3, 4$
2. Sustitución $(d+7) \pmod{10}$:
    - $1+7=8$
    - $2+7=9$
    - $3+7=10 \to 0$
    - $4+7=11 \to 1$
3. Estado intermedio: $8, 9, 0, 1$
4. Intercambio (1 con 3, 2 con 4):
    - Pos 1 ($8$) $\leftrightarrow$ Pos 3 ($0$)
    - Pos 2 ($9$) $\leftrightarrow$ Pos 4 ($1$)
5. Resultado final: **0189**
---
### Resultados:
```
1. Cifrar
2. Descifrar
Opción: 1
Ingrese el número de 4 dígitos: 1234
Cifrado: 0189

3. Cifrar
4. Descifrar
Opción: 2
Ingrese el número de 4 dígitos: 0189
Descifrado: 1234
```

---
## Ejercicio 13
Se desea calcular independiente la suma de los números pares e impares comprendidos entre 1 y 200.
___
Para este problema, utilizaremos un bucle que recorra el rango $[1, 200]$ y, mediante el operador módulo ($\%$), determinaremos si cada número es par o impar para sumarlo al acumulador correspondiente.
### Pseudocódigo:
> **INICIO**
>   $sumaPares \leftarrow 0$
>   $sumaImpares \leftarrow 0$
> **PARA** $i \leftarrow 1$ **HASTA** 200 **HACER**
>     **SI** $i \pmod 2 = 0$ **ENTONCES**
>       $sumaPares \leftarrow sumaPares + i$
>     **SINO**
>       $sumaImpares \leftarrow sumaImpares + i$ 
>     **FINSI**
>   **FINPARA**
> **ESCRIBIR** "La suma de los números pares es: ", $sumaPares$
>   **ESCRIBIR** "La suma de los números impares es: ", $sumaImpares$
> **FIN**
---
### Algoritmos:

#### Código en Python:
```Python
suma_pares = 0
suma_impares = 0

for i in range(1, 201):
    if i % 2 == 0:
        suma_pares += i
    else:
        suma_impares += i

print(f"Suma de pares: {suma_pares}")
print(f"Suma de impares: {suma_impares}")
```
---
#### Código en C++:
```cpp
#include <iostream>

int main() {
    int sumaPares = 0;
    int sumaImpares = 0;

    for (int i = 1; i <= 200; ++i) {
        if (i % 2 == 0) {
            sumaPares += i;
        } else {
            sumaImpares += i;
        }
    }

    std::cout << "Suma de pares: " << sumaPares << std::endl;
    std::cout << "Suma de impares: " << sumaImpares << std::endl;

    return 0;
}
```
---
#### Código en Julia:
```Julia
suma_pares = 0
suma_impares = 0

for i in 1:200
    if i % 2 == 0
        global suma_pares += i
    else
        global suma_impares += i
    end
end

println("Suma de pares: $suma_pares")
println("Suma de impares: $suma_impares")
```
---
### Prueba de escritorio:
Simulación simplificada para el rango del 1 al 6:

| **i**   | **i(mod2)** | **sumaPares** | **sumaImpares** |
| ------- | ----------- | ------------- | --------------- |
| Inicial | -           | 0             | 0               |
| 1       | 1 (Impar)   | 0             | 1               |
| 2       | 0 (Par)     | 2             | 1               |
| 3       | 1 (Impar)   | 2             | 4               |
| 4       | 0 (Par)     | 6             | 4               |
| 5       | 1 (Impar)   | 6             | 9               |
| 6       | 0 (Par)     | 12            | 9               |

---
### Resultados:
```
Suma de pares: 10100
Suma de impares: 10000
```
---
## Ejercicio 14
Calcular la suma de los cuadrados de los 100 primeros números naturales.
___
Para resolver este problema, calcularemos la suma de los cuadrados de los números del 1 al 100 utilizando una estructura iterativa. Matemáticamente, el programa evalúa la siguiente sumatoria:

$$\sum_{i=1}^{100} i^2 = 1^2 + 2^2 + 3^2 + \dots + 100^2$$
### Pseudocódigo:
> **INICIO**
>   $suma \leftarrow 0$
>   **PARA** $i \leftarrow 1$ **HASTA** 100 **HACER**
>     $cuadrado \leftarrow i \cdot i$
>     $suma \leftarrow suma + cuadrado$
>   **FINPARA**
>   **ESCRIBIR** "La suma de los cuadrados es: ", $suma$
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
suma = 0

for i in range(1, 101):
    suma += i**2

print(f"La suma de los cuadrados de los primeros 100 números es: {suma}")
```
---
#### Código en C++:
```cpp
#include <iostream>

int main() {
    long long suma = 0;

    for (int i = 1; i <= 100; ++i) {
        suma += (long long)i * i;
    }

    std::cout << "La suma de los cuadrados de los primeros 100 numeros es: " << suma << std::endl;

    return 0;
}
```
---
#### Código en Julia:
```Julia
suma = 0

for i in 1:100
    global suma += i^2
end

println("La suma de los cuadrados de los primeros 100 números es: $suma")
```
---
### Prueba de escritorio:

| **Iteración (i)** | **Operación (i2)** | **suma (Acumulado)** |
| ----------------- | ------------------ | -------------------- |
| Inicial           | -                  | 0                    |
| 1                 | $1^2 = 1$          | $0 + 1 = 1$          |
| 2                 | $2^2 = 4$          | $1 + 4 = 5$          |
| 3                 | $3^2 = 9$          | $5 + 9 = 14$         |
| 4                 | $4^2 = 16$         | $14 + 16 = 30$       |
| ...               | ...                | ...                  |
| 100               | $100^2 = 10000$    | 338350               |

---
### Resultados:
```
La suma de los cuadrados de los primeros 100 números es: 338350
```
___
## Ejercicio 15
Escribir un algoritmo que, dados dos intervalos cerrados [a,b] y [c, d] de la recta real, devuelva la intersección de ambos intervalos.
___
Para encontrar la intersección de dos intervalos cerrados $[a, b]$ y $[c, d]$, debemos identificar el punto de inicio más tardío y el punto de fin más temprano. La intersección existe si y solo si el inicio máximo es menor o igual al fin mínimo.
### Pseudocódigo:
> **INICIO**
>   **ESCRIBIR** "Ingrese el intervalo 1 [a, b]: "
>   **LEER** $a, b$
>   **ESCRIBIR** "Ingrese el intervalo 2 [c, d]: "
>   **LEER** $c, d$
> // El inicio de la intersección es el máximo de los inicios
>   **SI** $a > c$ **ENTONCES**
>     $inicioInterseccion \leftarrow a$
>   **SINO**
>     $inicioInterseccion \leftarrow c$
>   **FINSI**
> // El fin de la intersección es el mínimo de los finales
>   **SI** $b < d$ **ENTONCES**
>     $finInterseccion \leftarrow b$
>   **SINO**
>     $finInterseccion \leftarrow d$
>   **FINSI**
> // Verificar si existe intersección real
>   **SI** $inicioInterseccion \le finInterseccion$ **ENTONCES**
>     **ESCRIBIR** "La intersección es: [", $inicioInterseccion, ", ", finInterseccion, "]" &nbsp;&nbsp;**SINO** &nbsp;&nbsp;&nbsp;&nbsp;**ESCRIBIR** "La intersección es el conjunto vacío ($\emptyset$)"
>   **FINSI**
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
try:
    a = float(input("Intervalo 1 - a: "))
    b = float(input("Intervalo 1 - b: "))
    c = float(input("Intervalo 2 - c: "))
    d = float(input("Intervalo 2 - d: "))

    # Lógica de intersección
    inicio = max(a, c)
    fin = min(b, d)

    if inicio <= fin:
        print(f"La intersección es: [{inicio}, {fin}]")
    else:
        print("La intersección es el conjunto vacío (∅)")
except ValueError:
    print("Error: Ingrese valores numéricos válidos.")
```
---
#### Código en C++:
```cpp
#include <iostream>
#include <algorithm>

int main() {
    double a, b, c, d;

    std::cout << "Ingrese el primer intervalo [a, b]: ";
    std::cin >> a >> b;
    std::cout << "Ingrese el segundo intervalo [c, d]: ";
    std::cin >> c >> d;

    double inicio = std::max(a, c);
    double fin = std::min(b, d);

    if (inicio <= fin) {
        std::cout << "La interseccion es: [" << inicio << ", " << fin << "]" << std::endl;
    } else {
        std::cout << "La interseccion es el conjunto vacio." << std::endl;
    }

    return 0;
}
```
---
#### Código en Julia:
```Julia
print("Intervalo 1 - a: ")
a = parse(Float64, readline())
print("Intervalo 1 - b: ")
b = parse(Float64, readline())

print("Intervalo 2 - c: ")
c = parse(Float64, readline())
print("Intervalo 2 - d: ")
d = parse(Float64, readline())

inicio = max(a, c)
fin = min(b, d)

if inicio <= fin
    println("La intersección es: [$inicio, $fin]")
else
    println("La intersección es el conjunto vacío (∅)")
end
```
---
### Prueba de escritorio:
Considerando los intervalos $I_1 = [1, 5]$ e $I_2 = [3, 8]$:

| **Variable**            | **Valor**     |
| ----------------------- | ------------- |
| $a$                     | 1             |
| $b$                     | 5             |
| $c$                     | 3             |
| $d$                     | 8             |
| $inicio = \max(1, 3)$   | 3             |
| $fin = \min(5, 8)$      | 5             |
| **Condición** $3 \le 5$ | **Verdadero** |
| **Resultado**           | **[3, 5]**    |

---
### Resultados:
```
Ingrese el primer intervalo [a, b]: 1 5
Ingrese el segundo intervalo [c, d]: 3 8
La interseccion es: [3, 5]
```
---
## Ejercicio 16
Determine el numero de dígitos de un numero positivo N ingresado por teclado.
Ejemplo: 999 tiene tres dígitos            1222 tiene 4 dígitos.
___
Para determinar cuántos dígitos tiene un número entero positivo $N$, la lógica más eficiente consiste en dividir el número sucesivamente entre 10 hasta que el cociente sea cero, contando cada una de estas divisiones.
### Pseudocódigo:
> **INICIO**
>   **REPETIR**
>     **ESCRIBIR** "Ingrese un número entero positivo ($N > 0$): "
>     **LEER** $N$
>     **SI** $N \le 0$ **ENTONCES**
>       **ESCRIBIR** "Error: El número debe ser positivo."
>     **FINSI**
>   **HASTA QUE** $N > 0$
> $contador \leftarrow 0$
>   $aux \leftarrow N$
> **MIENTRAS** $aux > 0$ **HACER**
>     $aux \leftarrow \text{TRUNCAR}(aux / 10)$
>     $contador \leftarrow contador + 1$
>   **FINMIENTRAS**
> **ESCRIBIR** "El número ", $N$, " tiene ", $contador$, " dígitos."
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
while True:
    try:
        n = int(input("Ingrese un número entero positivo ($N > 0$): "))
        if n > 0:
            break
        print("Error: El número debe ser mayor a cero.")
    except ValueError:
        print("Error: Ingrese un número entero válido.")

contador = 0
aux = n

if aux == 0: # Caso especial si se permitiera el cero
    contador = 1
else:
    while aux > 0:
        aux //= 10  # División entera
        contador += 1

print(f"El número {n} tiene {contador} dígitos.")
```
---
#### Código en C++:
```cpp
#include <iostream>

int main() {
    long long n;
    
    do {
        std::cout << "Ingrese un numero entero positivo (N > 0): ";
        if (!(std::cin >> n)) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            n = -1;
        }
    } while (n <= 0);

    int contador = 0;
    long long aux = n;

    while (aux > 0) {
        aux /= 10;
        contador++;
    }

    std::cout << "El numero " << n << " tiene " << contador << " digitos." << std::endl;

    return 0;
}
```
---
#### Código en Julia:
```Julia
n = 0
while n <= 0
    print("Ingrese un número entero positivo (N > 0): ")
    input_val = readline()
    parsed = tryparse(Int, input_val)
    if parsed !== nothing && parsed > 0
        global n = parsed
    else
        println("Error: Debe ingresar un entero positivo.")
    end
end

contador = 0
aux = n

while aux > 0
    global aux = div(aux, 10)
    global contador += 1
end

println("El número $n tiene $contador dígitos.")
```
---
### Prueba de escritorio:
Considerando la entrada $N = 999$:

| **Iteración** | **aux** | **Condición (aux>0)** | **Operación (aux//10)** | **contador** |
| ------------- | ------- | --------------------- | ----------------------- | ------------ |
| Inicio        | 999     | -                     | -                       | 0            |
| 1             | 999     | Verdadero             | 99                      | 1            |
| 2             | 99      | Verdadero             | 9                       | 2            |
| 3             | 9       | Verdadero             | 0                       | 3            |
| Fin           | 0       | Falso                 | -                       | 3            |

---
### Resultados:
```
Ingrese un número entero positivo (N > 0): 1222
El número 1222 tiene 4 dígitos.

Ingrese un número entero positivo (N > 0): 999
El número 999 tiene 3 dígitos.
```
## Ejercicio 17
Hacer un algoritmo y un programa en c++ para evaluar una una función de la siguiente forma: $aX^4-bX^3+2cX^2-X+d$ donde $a,b,c,d$ son ingresado por teclado y el valor para x enteros (8,100)
muestre todos los f(x)=
___
Para resolver este problema, evaluaremos el polinomio dado en el rango de valores enteros solicitado. Es importante notar que el intervalo $(8, 100)$ es abierto, lo que significa que los valores de $X$ irán desde $9$ hasta $99$.
La función a evaluar es:
$$f(x) = aX^4 - bX^3 + 2cX^2 - X + d$$
### Pseudocódigo:
> **INICIO**
>   **ESCRIBIR** "Ingrese los coeficientes a, b, c, d: "
>   **LEER** $a, b, c, d$
> **PARA** $x \leftarrow 9$ **HASTA** 99 **HACER**
>     $termino1 \leftarrow a \cdot (x \cdot x \cdot x \cdot x)$
>     $termino2 \leftarrow b \cdot (x \cdot x \cdot x)$
>     $termino3 \leftarrow 2 \cdot c \cdot (x \cdot x)$
>     $resultado \leftarrow termino1 - termino2 + termino3 - x + d$
>     **ESCRIBIR** "f(", $x$, ") = ", $resultado$
>   **FINPARA**
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
try:
    a = float(input("Ingrese a: "))
    b = float(input("Ingrese b: "))
    c = float(input("Ingrese c: "))
    d = float(input("Ingrese d: "))

    # Rango (8, 100) -> 9 al 99 inclusive
    for x in range(9, 100):
        fx = (a * x**4) - (b * x**3) + (2 * c * x**2) - x + d
        print(f"f({x}) = {fx}")
except ValueError:
    print("Error: Ingrese valores numéricos válidos.")
```
---
#### Código en C++:
```cpp
#include <iostream>
#include <cmath>

int main() {
    double a, b, c, d;

    std::cout << "Ingrese los coeficientes (a b c d): ";
    if (!(std::cin >> a >> b >> c >> d)) {
        std::cout << "Error en la entrada." << std::endl;
        return 1;
    }

    // Evaluacion en el intervalo (8, 100)
    for (int x = 9; x < 100; ++x) {
        double res = (a * std::pow(x, 4)) - (b * std::pow(x, 3)) + (2 * c * std::pow(x, 2)) - x + d;
        std::cout << "f(" << x << ") = " << res << std::endl;
    }

    return 0;
}
```
---
#### Código en Julia:
```Julia
print("Ingrese a, b, c, d (separados por espacio): ")
input_data = split(readline())
if length(input_data) == 4
    a = parse(Float64, input_data[1])
    b = parse(Float64, input_data[2])
    c = parse(Float64, input_data[3])
    d = parse(Float64, input_data[4])

    for x in 9:99
        fx = a*x^4 - b*x^3 + 2*c*x^2 - x + d
        println("f($x) = $fx")
    end
else
    println("Error: Se requieren 4 coeficientes.")
end
```
---
### Prueba de escritorio:
Considerando $a=1, b=1, c=1, d=1$ y el primer valor del ciclo ($x=9$):

| **Variable** | **Valor / Operación**              | **Resultado Parcial** |
| ------------ | ---------------------------------- | --------------------- |
| $x$          | 9                                  | -                     |
| $aX^4$       | $1 \cdot 9^4 = 1 \cdot 6561$       | 6561                  |
| $bX^3$       | $1 \cdot 9^3 = 1 \cdot 729$        | 729                   |
| $2cX^2$      | $2 \cdot 1 \cdot 9^2 = 2 \cdot 81$ | 162                   |
| $-X + d$     | $-9 + 1$                           | -8                    |
| **f(9)**     | $6561 - 729 + 162 - 8$             | **5986**              |

---
### Resultados:
```
Ingrese los coeficientes (a b c d): 1 1 1 1
f(9) = 5986
f(10) = 9191
f(11) = 13541
...
f(99) = 95138881
```

---
## Ejercicio 18
Escribir un algoritmo en pseudocódigo que saque por pantalla el nombre y número de días del mes que pida el usuario por teclado en forma de número natural del 1 al 12. Usar sólo el tipo predefinido de los naturales. Si introduce un número fuera del rango 1..12, sacar el mensaje ‘Mes inválido’. Utilizar la sentencia CASO.
___
Para este problema, utilizaremos una estructura de control selectiva múltiple (**CASO** o **según**) que permite evaluar una variable y ejecutar un bloque de instrucciones específico para cada valor del 1 al 12.
### Pseudocódigo:
> **INICIO**
>   **ESCRIBIR** "Introduzca el número del mes (1 al 12): "
>   **LEER** $mes$
> **SEGÚN** $mes$ **HACER**
>     1: **ESCRIBIR** "Enero tiene 31 días."
>     2: **ESCRIBIR** "Febrero tiene 28 días (o 29 si es bisiesto)."
>     3: **ESCRIBIR** "Marzo tiene 31 días."
>     4: **ESCRIBIR** "Abril tiene 30 días."
>     5: **ESCRIBIR** "Mayo tiene 31 días."
>     6: **ESCRIBIR** "Junio tiene 30 días."
>     7: **ESCRIBIR** "Julio tiene 31 días."
>     8: **ESCRIBIR** "Agosto tiene 31 días."
>     9: **ESCRIBIR** "Septiembre tiene 30 días."
>     10: **ESCRIBIR** "Octubre tiene 31 días."
>     11: **ESCRIBIR** "Noviembre tiene 30 días."
>     12: **ESCRIBIR** "Diciembre tiene 31 días."
>     **SINO:**
>       **ESCRIBIR** "Mes inválido"
>   **FINSEGÚN**
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
try:
    mes = int(input("Introduzca el número del mes (1-12): "))

    # Simulación de estructura CASO mediante un diccionario o match (Python 3.10+)
    match mes:
        case 1: print("Enero tiene 31 días.")
        case 2: print("Febrero tiene 28 o 29 días.")
        case 3: print("Marzo tiene 31 días.")
        case 4: print("Abril tiene 30 días.")
        case 5: print("Mayo tiene 31 días.")
        case 6: print("Junio tiene 30 días.")
        case 7: print("Julio tiene 31 días.")
        case 8: print("Agosto tiene 31 días.")
        case 9: print("Septiembre tiene 30 días.")
        case 10: print("Octubre tiene 31 días.")
        case 11: print("Noviembre tiene 30 días.")
        case 12: print("Diciembre tiene 31 días.")
        case _: print("Mes inválido")
except ValueError:
    print("Error: Debe introducir un número natural.")
```

---
#### Código en C++:
```cpp
#include <iostream>

int main() {
    unsigned int mes;
    std::cout << "Introduzca el numero del mes (1-12): ";
    
    if (!(std::cin >> mes)) {
        std::cout << "Error: Entrada no valida." << std::endl;
        return 1;
    }

    switch (mes) {
        case 1:  std::cout << "Enero tiene 31 dias." << std::endl; break;
        case 2:  std::cout << "Febrero tiene 28 o 29 dias." << std::endl; break;
        case 3:  std::cout << "Marzo tiene 31 dias." << std::endl; break;
        case 4:  std::cout << "Abril tiene 30 dias." << std::endl; break;
        case 5:  std::cout << "Mayo tiene 31 dias." << std::endl; break;
        case 6:  std::cout << "Junio tiene 30 dias." << std::endl; break;
        case 7:  std::cout << "Julio tiene 31 dias." << std::endl; break;
        case 8:  std::cout << "Agosto tiene 31 dias." << std::endl; break;
        case 9:  std::cout << "Septiembre tiene 30 dias." << std::endl; break;
        case 10: std::cout << "Octubre tiene 31 dias." << std::endl; break;
        case 11: std::cout << "Noviembre tiene 30 dias." << std::endl; break;
        case 12: std::cout << "Diciembre tiene 31 dias." << std::endl; break;
        default: std::cout << "Mes invalido" << std::endl; break;
    }

    return 0;
}
```
---
#### Código en Julia:
```Julia
print("Introduzca el número del mes (1-12): ")
input_str = readline()
mes = tryparse(Int, input_str)

if mes === nothing
    println("Error: No es un número válido.")
else
    if mes == 1 println("Enero tiene 31 días.")
    elseif mes == 2 println("Febrero tiene 28 o 29 días.")
    elseif mes == 3 println("Marzo tiene 31 días.")
    elseif mes == 4 println("Abril tiene 30 días.")
    elseif mes == 5 println("Mayo tiene 31 días.")
    elseif mes == 6 println("Junio tiene 30 días.")
    elseif mes == 7 println("Julio tiene 31 días.")
    elseif mes == 8 println("Agosto tiene 31 días.")
    elseif mes == 9 println("Septiembre tiene 30 días.")
    elseif mes == 10 println("Octubre tiene 31 días.")
    elseif mes == 11 println("Noviembre tiene 30 días.")
    elseif mes == 12 println("Diciembre tiene 31 días.")
    else
        println("Mes inválido")
    end
end
```
---
### Prueba de escritorio:

| **Entrada (mes)** | **Evaluación en CASO**     | **Salida por pantalla**    |
| ----------------- | -------------------------- | -------------------------- |
| 4                 | Coincide con caso 4        | "Abril tiene 30 días."     |
| 12                | Coincide con caso 12       | "Diciembre tiene 31 días." |
| 13                | No coincide (SINO/Default) | "Mes inválido"             |
| 0                 | No coincide (SINO/Default) | "Mes inválido"             |

---
### Resultados:
```
Introduzca el número del mes (1-12): 2
Febrero tiene 28 o 29 días.

Introduzca el número del mes (1-12): 15
Mes inválido
```

---
## Ejercicio 19
Trazar la ejecución del siguiente algoritmo, y hallar el resultado producido cuando los datos de entrada son: 49 y 70.
>ALGORITMO Divisor
>VARIABLES
>**Z** primero, segundo
>INICIO
>Leer (primero, segundo)
>MIENTRAS <> segundo HACER
>	SI primero > segundo ENTONCES
>		primero = primero - segundo
>	SINO
>	segundo = segundo - primero
>	FINSI
>FINMIENTRAS
>Escribir (primero)
>FIN Divisor>

**Escriba su programa fuente en C++**
___
Este algoritmo implementa el **Algoritmo de Euclides** mediante restas sucesivas para encontrar el **Máximo Común Divisor (MCD)** de dos números.
### Pseudocódigo:
> **ALGORITMO** Divisor
> **INICIO**
>   **ESCRIBIR** "Ingrese el primer número: "
>   **LEER** $primero$
>   **ESCRIBIR** "Ingrese el segundo número: "
>   **LEER** $segundo$
> **MIENTRAS** $primero \neq segundo$ **HACER**
>     **SI** $primero > segundo$ **ENTONCES**
>       $primero \leftarrow primero - segundo$
>     **SINO**
>       $segundo \leftarrow segundo - primero$
>     **FINSI**
>   **FINMIENTRAS**
> **ESCRIBIR** "El resultado es: ", $primero$
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
try:
    primero = int(input("Ingrese el primer número: "))
    segundo = int(input("Ingrese el segundo número: "))

    while primero != segundo:
        if primero > segundo:
            primero = primero - segundo
        else:
            segundo = segundo - primero

    print(f"El resultado es: {primero}")
except ValueError:
    print("Error: Ingrese números enteros.")
```
---
#### Código en C++:
```cpp
#include <iostream>

int main() {
    int primero, segundo;

    std::cout << "Ingrese el primer numero: ";
    std::cin >> primero;
    std::cout << "Ingrese el segundo numero: ";
    std::cin >> segundo;

    while (primero != segundo) {
        if (primero > segundo) {
            primero = primero - segundo;
        } else {
            segundo = segundo - primero;
        }
    }

    std::cout << "El resultado es: " << primero << std::endl;

    return 0;
}
```
---
#### Código en Julia:
```Julia
print("Ingrese el primer número: ")
primero = parse(Int, readline())
print("Ingrese el segundo número: ")
segundo = parse(Int, readline())

while primero != segundo
    if primero > segundo
        global primero = primero - segundo
    else
        global segundo = segundo - primero
    end
end

println("El resultado es: $primero")
```
---
### Prueba de escritorio:

| **Paso**    | **Condición (p=s)** | **Comparación (p>s)** | **Acción**          | **primero** | **segundo** |
| ----------- | -------------------- | --------------------- | ------------------- | ----------- | ----------- |
| Inicio      | -                    | -                     | Leer datos          | 49          | 70          |
| Iteración 1 | $49 \neq 70$ (V)     | $49 > 70$ (F)         | $s = 70 - 49$       | 49          | 21          |
| Iteración 2 | $49 \neq 21$ (V)     | $49 > 21$ (V)         | $p = 49 - 21$       | 28          | 21          |
| Iteración 3 | $28 \neq 21$ (V)     | $28 > 21$ (V)         | $p = 28 - 21$       | 7           | 21          |
| Iteración 4 | $7 \neq 21$ (V)      | $7 > 21$ (F)          | $s = 21 - 7$        | 7           | 14          |
| Iteración 5 | $7 \neq 14$ (V)      | $7 > 14$ (F)          | $s = 14 - 7$        | 7           | 7           |
| Fin Bucle   | $7 \neq 7$ (F)       | -                     | Salir y mostrar $p$ | 7           | 7           |

---
### Resultados:
```
Ingrese el primer número: 49
Ingrese el segundo número: 70
El resultado es: 7
```
---
## Ejercicio 20
Pasar a binario un número decimal que se ha leído por teclado.
___
Para convertir un número decimal a binario, se utiliza el método de las divisiones sucesivas entre 2. Los residuos obtenidos (0 o 1) en cada división, leídos en orden inverso (del último al primero), conforman el número en sistema binario.
### Pseudocódigo:
> **INICIO**
>   **ESCRIBIR** "Ingrese un número decimal positivo: "
>   **LEER** $n$
> **SI** $n = 0$ **ENTONCES**
>     **ESCRIBIR** "El binario es: 0"
>   **SINO**
>     $binario \leftarrow ""$ (cadena vacía)
>     $aux \leftarrow n$
> **MIENTRAS** $aux > 0$ **HACER**
>       $residuo \leftarrow aux \pmod 2$
>       $binario \leftarrow \text{CONCATENAR}(residuo, binario)$
>       $aux \leftarrow \text{TRUNCAR}(aux / 2)$
>     **FINMIENTRAS**
> **ESCRIBIR** "El número ", $n$, " en binario es: ", $binario$
>   **FINSI**
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
try:
    n = int(input("Ingrese un número decimal positivo: "))
    
    if n < 0:
        print("Error: Ingrese un número positivo.")
    elif n == 0:
        print("El binario es: 0")
    else:
        original = n
        binario = ""
        while n > 0:
            residuo = n % 2
            binario = str(residuo) + binario
            n //= 2
        
        print(f"El número {original} en binario es: {binario}")
except ValueError:
    print("Error: Entrada no válida.")
```
---
#### Código en C++:
```cpp
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    long long n;
    std::cout << "Ingrese un numero decimal positivo: ";
    
    if (!(std::cin >> n) || n < 0) {
        std::cout << "Entrada no valida." << std::endl;
        return 1;
    }

    if (n == 0) {
        std::cout << "El binario es: 0" << std::endl;
        return 0;
    }

    std::string binario = "";
    long long aux = n;

    while (aux > 0) {
        binario += std::to_string(aux % 2);
        aux /= 2;
    }

    // Invertimos la cadena porque los residuos se obtienen al revés
    std::reverse(binario.begin(), binario.end());

    std::cout << "El numero " << n << " en binario es: " << binario << std::endl;

    return 0;
}
```
---
#### Código en Julia:
```Julia
print("Ingrese un número decimal positivo: ")
input_str = readline()
n = tryparse(Int, input_str)

if n === nothing || n < 0
    println("Error: Ingrese un entero positivo válido.")
else
    if n == 0
        println("El binario es: 0")
    else
        original = n
        binario = ""
        temp_n = n
        while temp_n > 0
            residuo = temp_n % 2
            binario = string(residuo) * binario
            temp_n = div(temp_n, 2)
        end
        println("El número $original en binario es: $binario")
    end
end
```
---
### Prueba de escritorio:
Considerando la entrada $n = 13$:

| **Iteración** | **aux** | **aux(mod2) (Residuo)** | **binario (Acumulado)** | **aux//2** |
| ------------- | ------- | ----------------------- | ----------------------- | ---------- |
| Inicio        | 13      | -                       | ""                      | -          |
| 1             | 13      | 1                       | "1"                     | 6          |
| 2             | 6       | 0                       | "01"                    | 3          |
| 3             | 3       | 1                       | "101"                   | 1          |
| 4             | 1       | 1                       | "1101"                  | 0          |
| **Fin**       | 0       | -                       | **"1101"**              | -          |

---
### Resultados:
```
Ingrese un número decimal positivo: 13
El número 13 en binario es: 1101

Ingrese un número decimal positivo: 25
El número 25 en binario es: 11001
```
---
## Ejercicio 21
Elabore un programa que lea un número entero y escriba el número resultante de invertir sus cifras.
___
Para invertir las cifras de un número entero, utilizamos una lógica similar a la de contar dígitos, pero reconstruyendo el número en cada paso multiplicando el acumulador por 10 y sumando el residuo de la división entre 10.
### Pseudocódigo:
> **INICIO**
>   **ESCRIBIR** "Ingrese un número entero positivo: "
>   **LEER** $n$
>   $aux \leftarrow n$
>   $invertido \leftarrow 0$
> **MIENTRAS** $aux > 0$ **HACER**
>     $digito \leftarrow aux \pmod{10}$
>     $invertido \leftarrow (invertido \cdot 10) + digito$
>     $aux \leftarrow \text{TRUNCAR}(aux / 10)$
>   **FINMIENTRAS**
> **ESCRIBIR** "El número invertido es: ", $invertido$
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
try:
    n = int(input("Ingrese un número entero positivo: "))
    if n < 0:
        print("Por favor, ingrese un número positivo.")
    else:
        aux = n
        invertido = 0
        while aux > 0:
            digito = aux % 10
            invertido = (invertido * 10) + digito
            aux //= 10
        print(f"El número resultante es: {invertido}")
except ValueError:
    print("Error: Entrada no válida.")
```
---
#### Código en C++:
```cpp
#include <iostream>

int main() {
    long long n, invertido = 0;
    
    std::cout << "Ingrese un numero entero positivo: ";
    if (!(std::cin >> n) || n < 0) {
        std::cout << "Entrada no valida." << std::endl;
        return 1;
    }

    long long aux = n;
    while (aux > 0) {
        int digito = aux % 10;
        invertido = (invertido * 10) + digito;
        aux /= 10;
    }

    std::cout << "El numero resultante es: " << invertido << std::endl;

    return 0;
}
```
---
#### Código en Julia:
```Julia
print("Ingrese un número entero positivo: ")
input_str = readline()
n = tryparse(Int, input_str)

if n === nothing || n < 0
    println("Error: Ingrese un entero positivo válido.")
else
    aux = n
    invertido = 0
    while aux > 0
        digito = aux % 10
        global invertido = (invertido * 10) + digito
        global aux = div(aux, 10)
    end
    println("El número resultante es: $invertido")
end
```
---
### Prueba de escritorio:
Considerando la entrada $n = 1234$:

| **Paso** | **aux** | **digito (aux(mod10))** | **invertido ((inv⋅10)+dig)** | **aux (nuevo)** |
| -------- | ------- | ----------------------- | ---------------------------- | --------------- |
| Inicio   | 1234    | -                       | 0                            | 1234            |
| Iter 1   | 1234    | 4                       | $(0 \cdot 10) + 4 = 4$       | 123             |
| Iter 2   | 123     | 3                       | $(4 \cdot 10) + 3 = 43$      | 12              |
| Iter 3   | 12      | 2                       | $(43 \cdot 10) + 2 = 432$    | 1               |
| Iter 4   | 1       | 1                       | $(432 \cdot 10) + 1 = 4321$  | 0               |
| **Fin**  | 0       | -                       | **4321**                     | -               |

---
### Resultados:
```
Ingrese un número entero positivo: 1234
El número resultante es: 4321

Ingrese un número entero positivo: 508
El número resultante es: 805
```
## Ejercicio 22
Elabore un programa C++ que lea por teclado un número *n* entero positivo y presente por pantalla una pirámide de n filas que responda al siguiente esquema:
>**1
>2 3 2
>3 4 5 4 3
>4 5 6 7 6 5 4
>5 6 7 8 9 8 7 6 5
>6 7 8 9 0 1 0 9 8 7 6
>7 8 9 0 1 2 3 2 1 0 9 8 7
>8 9 0 1 2 3 4 5 4 3 2 1 0 9 8
>9 0 1 2 3 4 5 6 7 6 5 4 3 2 1 0 9
>0 1 2 3 4 5 6 7 8 9 8 7 6 5 4 3 2 1 0**  

___
Este es un problema de lógica de bucles anidados. Cada fila $i$ comienza con el valor de $i$, aumenta hasta alcanzar el valor $2i - 1$ y luego desciende nuevamente hasta $i$. Para que los números se mantengan en un solo dígito como en el esquema (ciclo 0-9), aplicamos la operación módulo 10 ($x \pmod{10}$).
### Pseudocódigo:
> **INICIO**
>   **ESCRIBIR** "Ingrese el número de filas: "
>   **LEER** $n$
> **PARA** $i \leftarrow 1$ **HASTA** $n$ **HACER**
>     // Parte ascendente de la fila
>     **PARA** $j \leftarrow 0$ **HASTA** $i - 1$ **HACER**
>       **ESCRIBIR** $(i + j) \pmod{10}$
>     **FINPARA**
> // Parte descendente de la fila
>     **PARA** $j \leftarrow i - 2$ **HASTA** 0 **CON PASO -1** **HACER**
>       **ESCRIBIR** $(i + j) \pmod{10}$
>     **FINPARA**
> **ESCRIBIR** salto_de_linea
>   **FINPARA**
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
try:
    n = int(input("Ingrese el número de filas (n > 0): "))
    if n <= 0:
        print("Por favor, ingrese un número positivo.")
    else:
        for i in range(1, n + 1):
            # Parte ascendente
            for j in range(i):
                print((i + j) % 10, end=" ")
            
            # Parte descendente
            for j in range(i - 2, -1, -1):
                print((i + j) % 10, end=" ")
            
            print()  # Salto de línea
except ValueError:
    print("Error: Ingrese un número entero válido.")
```
---
#### Código en C++:
```cpp
#include <iostream>

int main() {
    int n;
    std::cout << "Ingrese el numero de filas: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "Entrada no valida." << std::endl;
        return 1;
    }

    for (int i = 1; i <= n; ++i) {
        // Parte ascendente
        for (int j = 0; j < i; ++j) {
            std::cout << (i + j) % 10 << " ";
        }

        // Parte descendente
        for (int j = i - 2; j >= 0; --j) {
            std::cout << (i + j) % 10 << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}
```
---
#### Código en Julia:
```Julia
print("Ingrese el número de filas: ")
input_str = readline()
n = tryparse(Int, input_str)

if n === nothing || n <= 0
    println("Error: Ingrese un entero positivo.")
else
    for i in 1:n
        # Parte ascendente
        for j in 0:(i-1)
            print((i + j) % 10, " ")
        end
        
        # Parte descendente
        for j in (i-2):-1:0
            print((i + j) % 10, " ")
        end
        
        println() # Salto de línea
    end
end
```
---
### Prueba de escritorio:
Simulación para $n = 3$:

| **Fila (i)** | **Bucle Ascendente (j)**       | **Impresión** | **Bucle Descendente (j)** | **Impresión** | **Fila Completa** |
| ------------ | ------------------------------ | ------------- | ------------------------- | ------------- | ----------------- |
| 1            | $j=0: (1+0)\%10$               | 1             | (No entra)                | -             | 1                 |
| 2            | $j=0,1: (2+0, 2+1)\%10$        | 2, 3          | $j=0: (2+0)\%10$          | 2             | 2 3 2             |
| 3            | $j=0,1,2: (3+0, 3+1, 3+2)\%10$ | 3, 4, 5       | $j=1,0: (3+1, 3+0)\%10$   | 4, 3          | 3 4 5 4 3         |

---
### Resultados:
```
Ingrese el número de filas: 5
1 
2 3 2 
3 4 5 4 3 
4 5 6 7 6 5 4 
5 6 7 8 9 8 7 6 5 
```
---
## Ejercicio 23
La función trigonométrica seno para un ángulo x (en radianes) se calcula con la siguiente serie:
$$ x - x^3 / 3! + x^5 / 5! - x^7 / 7! + \dots $$
1. escriba un método de encabezamiento double seno(double x, int n) que calcule el seno de un ángulo $x$, usando los primeros $n$ términos de la serie anterior.
2. Utilice el método anterior en un programa que muestre la tabla siguiente:
   $$
\begin{array}{|l|l|}
\hline
\text{Angulo} & \text{Tangente} \\ \hline
0 & 0 \\ \hline
\pi/8 & \dots \\ \hline
\pi/4 & \dots \\ \hline
\dots & \dots \\ \hline
2\pi & \dots \\ \hline
\end{array}
$$
Notas:
- Recuerde que $\tan{x}=\dfrac{\sin{x}}{\cos{x}}$ y $\cos^2{x}+\sin^2{x}=1$
- En caso de que $\cos{x}$ sea $0$, se debe escribir $\tan{}$ "infinito"
- Calcule la función seno con 10 términos (n=10)
___
Para calcular la función seno mediante series de Taylor y posteriormente obtener la tangente, debemos ser cuidadosos con la precisión numérica y el signo del coseno al utilizar la identidad pitagórica.
### Pseudocódigo:
> **INICIO**
>   **CONSTANTE** $PI \leftarrow 3.14159265358979$
> **FUNCIÓN** seno($x, n$)
>     $resultado \leftarrow 0$
>     **PARA** $k \leftarrow 0$ **HASTA** $n-1$ **HACER**
>       $termino \leftarrow \dfrac{(-1)^k \cdot x^{2k+1}}{(2k+1)!}$
>       $resultado \leftarrow resultado + termino$
>     **FINPARA**
>     **RETORNAR** $resultado$
>   **FINFUNCIÓN**
> **ESCRIBIR** "Angulo | Tangente"
>   **PARA** $i \leftarrow 0$ **HASTA** 16 **HACER**
>     $x \leftarrow i \cdot (PI / 8)$
>     $s \leftarrow$ seno($x, 10$)
>     $c\_cuadrado \leftarrow 1 - (s \cdot s)$
>     **SI** $c\_cuadrado < 0$ **ENTONCES** $c\_cuadrado \leftarrow 0$ **FINSI**
>     $c \leftarrow \text{RAIZ}(c\_cuadrado)$
> // Determinar signo de coseno según cuadrante
>     **SI** $(x > PI/2$ **Y** $x < 3\cdot PI/2)$ **ENTONCES** $c \leftarrow -c$ **FINSI**
> **SI** |$c$| $< 10^{-10}$ **ENTONCES**
>       **ESCRIBIR** $x$, " | Infinito"
>     **SINO**
>       $t \leftarrow s / c$
>       **ESCRIBIR** $x$, " | ", $t$
>     **FINSI**
>   **FINPARA**
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
import math

def factorial(n):
    res = 1
    for i in range(2, n + 1):
        res *= i
    return res

def seno(x, n):
    suma = 0
    for k in range(n):
        numerador = ((-1)**k) * (x**(2*k + 1))
        denominador = factorial(2*k + 1)
        suma += numerador / denominador
    return suma

print(f"{'Ángulo (rad)':<15} | {'Tangente':<15}")
print("-" * 32)

for i in range(17):
    x = i * (math.pi / 8)
    s = seno(x, 10)
    
    # cos^2(x) = 1 - sin^2(x)
    cos_cuad = max(0, 1 - s**2)
    c = math.sqrt(cos_cuad)
    
    # Ajuste de signo para coseno en cuadrantes II y III
    if math.pi/2 < (x % (2*math.pi)) < 3*math.pi/2:
        c = -c
        
    if abs(c) < 1e-10:
        tan_str = "Infinito"
    else:
        tan_str = f"{s/c:.4f}"
    
    # Mostrar ángulo simplificado para legibilidad
    ang_str = f"{i}π/8" if i > 0 else "0"
    print(f"{ang_str:<15} | {tan_str:<15}")
```
---
#### Código en C++:
```cpp
#include <iostream>
#include <cmath>
#include <iomanip>

double factorial(int n) {
    double res = 1;
    for (int i = 2; i <= n; ++i) res *= i;
    return res;
}

double seno(double x, int n) {
    double suma = 0;
    for (int k = 0; k < n; ++k) {
        suma += (std::pow(-1, k) * std::pow(x, 2 * k + 1)) / factorial(2 * k + 1);
    }
    return suma;
}

int main() {
    const double PI = 3.141592653589793;
    std::cout << std::fixed << std::setprecision(4);
    std::cout << std::setw(12) << "Angulo" << " | " << "Tangente" << std::endl;
    std::cout << "---------------------------" << std::endl;

    for (int i = 0; i <= 16; ++i) {
        double x = i * (PI / 8.0);
        double s = seno(x, 10);
        double c2 = 1.0 - (s * s);
        if (c2 < 0) c2 = 0;
        double c = std::sqrt(c2);

        // Ajuste de signo según cuadrante
        double x_mod = std::fmod(x, 2 * PI);
        if (x_mod > PI / 2.0 && x_mod < 1.5 * PI) c = -c;

        if (std::abs(c) < 1e-10) {
            std::cout << std::setw(12) << i << "pi/8" << " | " << "Infinito" << std::endl;
        } else {
            std::cout << std::setw(12) << i << "pi/8" << " | " << (s / c) << std::endl;
        }
    }
    return 0;
}
```
---
#### Código en Julia:
```Julia
function factorial_custom(n)
    res = 1.0
    for i in 2:n
        res *= i
    end
    return res
end

function seno(x, n)
    suma = 0.0
    for k in 0:(n-1)
        suma += ((-1.0)^k * x^(2*k + 1)) / factorial_custom(2*k + 1)
    end
    return suma
end

println("Angulo         | Tangente")
println("--------------------------")

for i in 0:16
    x = i * (pi / 8)
    s = seno(x, 10)
    c_val = sqrt(max(0, 1 - s^2))
    
    # Signo del coseno
    x_check = x % (2*pi)
    if x_check > pi/2 && x_check < 3*pi/2
        c_val = -c_val
    end
    
    if abs(c_val) < 1e-10
        println("$(i)pi/8".* " "^(15-length("$(i)pi/8")) * "| Infinito")
    else
        val = round(s/c_val, digits=4)
        println("$(i)pi/8".* " "^(15-length("$(i)pi/8")) * "| $val")
    end
end
```
---
### Prueba de escritorio:
Considerando $x = \pi/4$ e $i=2$:

| **Variable**             | **Valor / Operación**                    |
| ------------------------ | ---------------------------------------- |
| $x$                      | $2 \cdot (\pi/8) = \pi/4 \approx 0.7854$ |
| $s = \text{seno}(x, 10)$ | $\approx 0.7071$                         |
| $c^2 = 1 - s^2$          | $1 - 0.5 = 0.5$                          |
| $c = \sqrt{0.5}$         | $0.7071$                                 |
| Signo $c$                | Cuadrante I $\to$ Positivo               |
| $s / c$                  | $0.7071 / 0.7071 = 1.0$                  |
| **Resultado**            | **1.0000**                               |

---
### Resultados:
```
Angulo       | Tangente
---------------------------
0            | 0.0000
1pi/8        | 0.4142
2pi/8        | 1.0000
3pi/8        | 2.4142
4pi/8        | Infinito
5pi/8        | -2.4142
...          | ...
16pi/8       | 0.0000
```
---
## Ejercicio 24
La secuencia de los números Fibonacci empieza con los enteros: **1, 1, 2, 3, 5, 8, 13, 21, …….** donde cada número después de los primeros dos es la suma de los dos números anteriores. Escribir un algoritmo que pida el ingreso de un número natural primo y determine si es un número Fibonacci. Si lo es imprima la terna del Fibonacci anterior al número, el número y el siguiente número Fibonacci.
___
Para determinar si un número primo ingresado pertenece a la secuencia de Fibonacci, generaremos la serie de forma iterativa hasta alcanzar o superar dicho número. Si existe una coincidencia, calcularemos el término siguiente sumando los dos últimos valores obtenidos.
### Pseudocódigo:
> **INICIO**
>   **ESCRIBIR** "Ingrese un número natural primo: "
>   **LEER** $n$
> // Verificar si es primo
>   $esPrimo \leftarrow$ **VERDADERO**
>   **SI** $n < 2$ **ENTONCES** $esPrimo \leftarrow$ **FALSO**
>   **SINO**
>     **PARA** $i \leftarrow 2$ **HASTA** $\text{RAIZ}(n)$ **HACER**
>       **SI** $n \pmod i = 0$ **ENTONCES** $esPrimo \leftarrow$ **FALSO** **FINSI**
>     **FINPARA**
>   **FINSI**
> **SI** $esPrimo =$ **FALSO** **ENTONCES**
>     **ESCRIBIR** "El número no es primo."
>   **SINO**
>     // Buscar en Fibonacci
>     $a \leftarrow 1$, $b \leftarrow 1$
>     **MIENTRAS** $b < n$ **HACER**
>       $temp \leftarrow a + b$
>       $a \leftarrow b$
>       $b \leftarrow temp$
>     **FINMIENTRAS**
> **SI** $b = n$ **ENTONCES**
>       $siguiente \leftarrow a + b$
>       **ESCRIBIR** "Terna: ", $a, ", ", b, ", ", siguiente$
>     **SINO**
>       **ESCRIBIR** "Es primo, pero no es un número Fibonacci."
>     **FINSI**
>   **FINSI**
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
import math

def es_primo(num):
    if num < 2: return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0: return False
    return True

try:
    n = int(input("Ingrese un número natural primo: "))
    
    if not es_primo(n):
        print("El número ingresado no es primo.")
    else:
        # Generar Fibonacci
        a, b = 1, 1
        while b < n:
            a, b = b, a + b
            
        if b == n:
            siguiente = a + b
            print(f"Es Fibonacci. Terna: {a}, {b}, {siguiente}")
        else:
            print("Es primo, pero no pertenece a la secuencia de Fibonacci.")
except ValueError:
    print("Error: Ingrese un número entero válido.")
```
---
#### Código en C++:
```cpp
#include <iostream>
#include <cmath>

bool verificarPrimo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    std::cout << "Ingrese un numero natural primo: ";
    if (!(std::cin >> n)) return 1;

    if (!verificarPrimo(n)) {
        std::cout << "El numero no es primo." << std::endl;
    } else {
        int a = 1, b = 1;
        while (b < n) {
            int temp = a + b;
            a = b;
            b = temp;
        }

        if (b == n) {
            std::cout << "Es Fibonacci. Terna: " << a << ", " << b << ", " << a + b << std::endl;
        } else {
            std::cout << "Es primo, pero no es Fibonacci." << std::endl;
        }
    }
    return 0;
}
```
---
#### Código en Julia:
```Julia
function es_primo(n)
    if n < 2 return false end
    for i in 2:floor(Int, sqrt(n))
        if n % i == 0 return false end
    end
    return true
end

print("Ingrese un número natural primo: ")
n = parse(Int, readline())

if !es_primo(n)
    println("El número no es primo.")
else
    a, b = 1, 1
    while b < n
        temp = a + b
        global a = b
        global b = temp
    end

    if b == n
        println("Es Fibonacci. Terna: $a, $b, $(a + b)")
    else
        println("Es primo, pero no es Fibonacci.")
    end
end
```
---
### Prueba de escritorio:
Considerando la entrada $n = 13$ (Número primo):

| **Paso**       | **a** | **b** | **Condición (b<13)** | **Acción**           |
| -------------- | ----- | ----- | -------------------- | -------------------- |
| Inicio         | 1     | 1     | $1 < 13$ (V)         | $temp=2, a=1, b=2$   |
| Iter 1         | 1     | 2     | $2 < 13$ (V)         | $temp=3, a=2, b=3$   |
| Iter 2         | 2     | 3     | $3 < 13$ (V)         | $temp=5, a=3, b=5$   |
| Iter 3         | 3     | 5     | $5 < 13$ (V)         | $temp=8, a=5, b=8$   |
| Iter 4         | 5     | 8     | $8 < 13$ (V)         | $temp=13, a=8, b=13$ |
| Fin Bucle      | 8     | 13    | $13 < 13$ (F)        | -                    |
| **Validación** | -     | -     | $b = 13$ (V)         | **Terna: 8, 13, 21** |

---
### Resultados:
```
Ingrese un número natural primo: 13
Es Fibonacci. Terna: 8, 13, 21

Ingrese un número natural primo: 7
Es primo, pero no es Fibonacci.
```
___
## Ejercicio 25
La media armónica de $n$ números enteros está definida por:$$X_h = \frac{n}{\sum_{i}^{n} (\frac{1}{x_i})}$$Y la media geométrica por:$$ X_g = \sqrt[n]{X_1 X_2 X_3 \dots X_n} $$Hacer un algoritmo para calcular la diferencia entre la media armónica y la media geométrica de M números enteros positivos.
___
Para resolver este problema, calcularemos ambas medias de forma simultánea dentro de un ciclo iterativo. Es importante recordar que, según la desigualdad de las medias, la media geométrica siempre será mayor o igual a la media armónica ($X_g \ge X_h$).
### Pseudocódigo:
> **INICIO**
>   **ESCRIBIR** "Ingrese la cantidad de números (M): "
>   **LEER** $M$
>   $sumaReciprocos \leftarrow 0$
>   $producto \leftarrow 1$
> **PARA** $i \leftarrow 1$ **HASTA** $M$ **HACER**
>     **ESCRIBIR** "Ingrese el número ", $i, ": "$
>     **LEER** $x$
>     $sumaReciprocos \leftarrow sumaReciprocos + (1 / x)$
>     $producto \leftarrow producto \cdot x$
>   **FINPARA**
>   $mediaArmonica \leftarrow M / sumaReciprocos$
>   $mediaGeometrica \leftarrow producto^{(1/M)}$
>   $diferencia \leftarrow mediaGeometrica - mediaArmonica$
> **ESCRIBIR** "Media Armónica: ", $mediaArmonica$
>   **ESCRIBIR** "Media Geométrica: ", $mediaGeometrica$
>   **ESCRIBIR** "Diferencia (Mg - Mh): ", $diferencia$
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
try:
    m = int(input("Ingrese la cantidad de números (M): "))
    if m <= 0:
        print("M debe ser un entero positivo.")
    else:
        suma_reciprocos = 0
        producto = 1
        
        for i in range(1, m + 1):
            x = float(input(f"Ingrese el número {i}: "))
            suma_reciprocos += 1 / x
            producto *= x
            
        media_h = m / suma_reciprocos
        media_g = producto ** (1 / m)
        diferencia = media_g - media_h
        
        print(f"\nMedia Armónica: {media_h:.4f}")
        print(f"Media Geométrica: {media_g:.4f}")
        print(f"Diferencia: {diferencia:.4f}")
except ValueError:
    print("Error: Ingrese valores numéricos válidos.")
```
---
#### Código en C++:
```cpp
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int m;
    double sumaReciprocos = 0.0, producto = 1.0;

    std::cout << "Ingrese la cantidad de numeros (M): ";
    if (!(std::cin >> m) || m <= 0) return 1;

    for (int i = 1; i <= m; ++i) {
        double x;
        std::cout << "Ingrese el numero " << i << ": ";
        std::cin >> x;
        sumaReciprocos += (1.0 / x);
        producto *= x;
    }

    double mediaH = m / sumaReciprocos;
    double mediaG = std::pow(producto, 1.0 / m);

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\nMedia Armonica: " << mediaH << std::endl;
    std::cout << "Media Geometrica: " << mediaG << std::endl;
    std::cout << "Diferencia: " << (mediaG - mediaH) << std::endl;

    return 0;
}
```
---
#### Código en Julia:
```Julia
print("Ingrese la cantidad de números (M): ")
m = parse(Int, readline())

if m > 0
    suma_reciprocos = 0.0
    producto = 1.0

    for i in 1:m
        print("Ingrese el número $i: ")
        x = parse(Float64, readline())
        global suma_reciprocos += (1.0 / x)
        global producto *= x
    end

    media_h = m / suma_reciprocos
    media_g = producto ^ (1.0 / m)

    println("\nMedia Armónica: ", round(media_h, digits=4))
    println("Media Geométrica: ", round(media_g, digits=4))
    println("Diferencia: ", round(media_g - media_h, digits=4))
else
    println("M debe ser mayor a cero.")
end
```
---
### Prueba de escritorio:
Considerando $M=2$ y los números $4$ y $16$:

|**Variable**|**Valor / Operación**|**Resultado**|
|---|---|---|
|$M$|2|2|
|$x_1$|4|-|
|$x_2$|16|-|
|$\sum (1/x_i)$|$(1/4) + (1/16) = 0.25 + 0.0625$|0.3125|
|$\prod x_i$|$4 \cdot 16$|64|
|$X_h$|$2 / 0.3125$|**6.4**|
|$X_g$|$\sqrt{64}$|**8.0**|
|**Diferencia**|$8.0 - 6.4$|**1.6**|

---
### Resultados:
```
Ingrese la cantidad de números (M): 2
Ingrese el número 1: 4
Ingrese el número 2: 16

Media Armónica: 6.4000
Media Geométrica: 8.0000
Diferencia: 1.6000
```
---
## Ejercicio 68
Calcular el número $e$, considerando los primeros 20 primeros términos: $e = 1 + \frac{1}{1!} + \frac{1}{2!} + \frac{1}{3!} + \frac{1}{4!} + \dots = 2,71827$
___
Para calcular una aproximación del número $e$ mediante su serie de potencias, sumamos los recíprocos de los factoriales de los primeros 20 números (empezando desde 0). La fórmula general es:
$$e = \sum_{n=0}^{k-1} \frac{1}{n!} = \frac{1}{0!} + \frac{1}{1!} + \frac{1}{2!} + \dots + \frac{1}{19!}$$
### Pseudocódigo:
> **INICIO**
>   $e \leftarrow 1.0$
>   $factorial \leftarrow 1.0$
>   **PARA** $i \leftarrow 1$ **HASTA** 19 **HACER**
>     $factorial \leftarrow factorial \cdot i$
>     $e \leftarrow e + (1 / factorial)$
>   **FINPARA**
>   **ESCRIBIR** "El valor aproximado de e con 20 términos es: ", $e$
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
def calcular_e(terminos):
    e_aprox = 1.0
    factorial = 1.0
    
    for i in range(1, terminos):
        factorial *= i
        e_aprox += 1 / factorial
        
    return e_aprox

n_terminos = 20
resultado = calcular_e(n_terminos)
print(f"El valor aproximado de e con {n_terminos} términos es: {resultado:.10f}")
```
---
#### Código en C++:
```cpp
#include <iostream>
#include <iomanip>

int main() {
    double e = 1.0;
    double factorial = 1.0;
    const int terminos = 20;

    for (int i = 1; i < terminos; ++i) {
        factorial *= i;
        e += (1.0 / factorial);
    }

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "El valor aproximado de e con " << terminos << " terminos es: " << e << std::endl;

    return 0;
}
```
---
#### Código en Julia:
```Julia
function calcular_e(n_terminos)
    e_aprox = 1.0
    factorial = 1.0
    
    for i in 1:(n_terminos - 1)
        factorial *= i
        e_aprox += 1 / factorial
    end
    
    return e_aprox
end

n = 20
println("El valor aproximado de e con $n términos es: ", calcular_e(n))
```
---
### Prueba de escritorio:
Simulación de los primeros 5 términos:

|**Término (i)**|**Operación Factorial**|**1/i!**|**e (Acumulado)**|
|---|---|---|---|
|Inicial ($i=0$)|$0! = 1$|1.0|1.0|
|1|$1! = 1$|1.0|$1.0 + 1.0 = 2.0$|
|2|$2! = 2$|0.5|$2.0 + 0.5 = 2.5$|
|3|$3! = 6$|0.16666...|$2.5 + 0.1666 = 2.6666$|
|4|$4! = 24$|0.04166...|$2.6666 + 0.0416 = 2.7083$|

---
### Resultados:
```
El valor aproximado de e con 20 términos es: 2.7182818285
```
___
## Ejercicio 71
La. función de probabilidad binomial es$$ P(K) = \frac{N!}{K!(N - K)!} p^K q^{N - K} $$Donde$$ p + q = 1 \quad \text{para } 0 < p \le 1 $$Escriba un programa que acepte los valores de $p$ y $N$ e imprima una tabla de probabilidad como $K$ varíe desde $0$ hasta $N$.
___
Para calcular la probabilidad binomial, debemos determinar el coeficiente binomial $\binom{N}{K}$ y multiplicarlo por las potencias de la probabilidad de éxito $p$ y fracaso $q$. Es fundamental manejar el cálculo de los factoriales o el coeficiente de forma que no genere desbordamientos innecesarios en números grandes.
### Pseudocódigo:
> **INICIO**
>   **ESCRIBIR** "Ingrese la probabilidad de éxito (p): "
>   **LEER** $p$
>   **ESCRIBIR** "Ingrese el número de ensayos (N): "
>   **LEER** $N$
> $q \leftarrow 1 - p$
> **ESCRIBIR** "K | P(K)"
>   **PARA** $k \leftarrow 0$ **HASTA** $N$ **HACER**
> 
>     $combinatoria \leftarrow \text{FACTORIAL}(N) / (\text{FACTORIAL}(k) \cdot \text{FACTORIAL}(N - k))$
> 
>     $probabilidad \leftarrow combinatoria \cdot (p^k) \cdot (q^{N-k})$
> 
>     **ESCRIBIR** $k$, " | ", $probabilidad$
>   **FINPARA**
> **FIN**
---
### Algoritmos:
#### Código en Python:
```Python
import math

def combinatoria(n, k):
    return math.factorial(n) // (math.factorial(k) * math.factorial(n - k))

try:
    p = float(input("Ingrese la probabilidad de éxito (p): "))
    n = int(input("Ingrese el número de ensayos (N): "))

    if 0 <= p <= 1 and n >= 0:
        q = 1 - p
        print(f"\n{'K':<5} | {'P(K)':<10}")
        print("-" * 20)
        
        for k in range(n + 1):
            prob = combinatoria(n, k) * (p**k) * (q**(n - k))
            print(f"{k:<5} | {prob:.6f}")
    else:
        print("Error: p debe estar entre 0 y 1, y N debe ser positivo.")
except ValueError:
    print("Error: Ingrese valores numéricos válidos.")
```
---
#### Código en C++:
```cpp
#include <iostream>
#include <cmath>
#include <iomanip>

double factorial(int n) {
    double res = 1.0;
    for (int i = 2; i <= n; ++i) res *= i;
    return res;
}

double combinatoria(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    double p;
    int n;

    std::cout << "Ingrese probabilidad (p): ";
    std::cin >> p;
    std::cout << "Ingrese ensayos (N): ";
    std::cin >> n;

    if (p < 0 || p > 1 || n < 0) {
        std::cout << "Valores invalidos." << std::endl;
        return 1;
    }

    double q = 1.0 - p;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "\nK     | P(K)" << std::endl;
    std::cout << "-------------" << std::endl;

    for (int k = 0; k <= n; ++k) {
        double prob = combinatoria(n, k) * std::pow(p, k) * std::pow(q, n - k);
        std::cout << std::left << std::setw(5) << k << " | " << prob << std::endl;
    }

    return 0;
}
```
---
#### Código en Julia:
```Julia
function combinatoria(n, k)
    return factorial(big(n)) / (factorial(big(k)) * factorial(big(n - k)))
end

print("Ingrese la probabilidad de éxito (p): ")
p = parse(Float64, readline())
print("Ingrese el número de ensayos (N): ")
n = parse(Int, readline())

if 0 <= p <= 1 && n >= 0
    q = 1 - p
    println("\nK     | P(K)")
    println("-------------")
    for k in 0:n
        prob = Float64(combinatoria(n, k) * (p^k) * (q^(n - k)))
        println(rpad(k, 5), " | ", round(prob, digits=6))
    end
else
    println("Error: Parámetros fuera de rango.")
end
```
---
### Prueba de escritorio:
Considerando $N = 3$ y $p = 0.5$ ($q = 0.5$):

|**K**|**(K3​)**|**pK**|**q3−K**|**Cálculo (P(K))**|**Resultado**|
|---|---|---|---|---|---|
|0|1|$0.5^0 = 1$|$0.5^3 = 0.125$|$1 \cdot 1 \cdot 0.125$|0.1250|
|1|3|$0.5^1 = 0.5$|$0.5^2 = 0.25$|$3 \cdot 0.5 \cdot 0.25$|0.3750|
|2|3|$0.5^2 = 0.25$|$0.5^1 = 0.5$|$3 \cdot 0.25 \cdot 0.5$|0.3750|
|3|1|$0.5^3 = 0.125$|$0.5^0 = 1$|$1 \cdot 0.125 \cdot 1$|0.1250|

---
### Resultados:
```
Ingrese la probabilidad de éxito (p): 0.5
Ingrese el número de ensayos (N): 3

K     | P(K)
-------------
0     | 0.125000
1     | 0.375000
2     | 0.375000
3     | 0.125000
```
---