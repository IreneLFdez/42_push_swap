*Este proyecto ha sido creado como parte del currículo de 42 por ilopez-f.*

# ft_printf

## Descripción

El proyecto **ft_printf** consiste en la recodificación de la función estándar `printf` de la librería de C (`<stdio.h>`). El objetivo principal es generar una biblioteca estática (`libftprintf.a`) capaz de parsear una cadena de formato con especificadores variables y retornar el número exacto de caracteres impresos en la salida estándar.

El proyecto abarca los siguientes aspectos técnicos principales:
* Manejo de funciones variádicas en C utilizando la librería `<stdarg.h>`.
* Impresión y conversión numérica en diferentes bases (decimal y hexadecimal).
* Tratamiento de rangos de datos en C, incluyendo casos límite como `INT_MIN` o punteros nulos (`NULL`).

### Especificadores Implementados

| Especificador | Tipo de argumento | Descripción |
| :---: | :---: | :--- |
| `%c` | `char` | Imprime un solo carácter. |
| `%s` | `char *` | Imprime una cadena de texto (imprime `(null)` si el puntero es nulo). |
| `%p` | `void *` | Imprime la dirección de memoria en formato hexadecimal con el prefijo `0x` (imprime `(nil)` si es nulo). |
| `%d` | `int` | Imprime un número entero decimal con signo. |
| `%i` | `int` | Imprime un número entero en base 10 con signo. |
| `%u` | `unsigned int` | Imprime un número entero decimal sin signo. |
| `%x` | `unsigned int` | Imprime un número en base 16 (hexadecimal) en minúsculas. |
| `%X` | `unsigned int` | Imprime un número en base 16 (hexadecimal) en mayúsculas. |
| `%%` | N/A | Imprime el carácter del porcentaje `%` literalmente. |

---

## Elección del Algoritmo y Estructura de Datos

### Estructura de Datos
En este proyecto no se han utilizado estructuras de datos complejas dinámicas (como listas enlazadas, colas o árboles). En su lugar, el proyecto se apoya en:
1. **`va_list` (`<stdarg.h>`)**: Funciona como un iterador sobre la pila de argumentos del sistema, permitiendo extraer secuencialmente los valores mediante `va_arg` en función del especificador leído.
2. **Pila de llamadas (*Call Stack*)**: Se utiliza la propia pila del sistema durante la recursión como búfer implícito de ejecución.

### Algoritmos y Decisiones Técnicas

El código se organiza de forma modular entre `ft_printf.c` y `ft_printf_utils.c`:

1. **Parsing Secuencial ($O(n)$)**:
   La función `ft_printf` recorre la cadena `format` carácter por carácter. Al detectar un `%`, delega a `ft_parse_format`, que identifica el especificador y llama al controlador adecuado acumulando los caracteres impresos.

2. **Recursión para Conversión de Bases y Enteros (`ft_putnbr_count` y `ft_putnbr_base_count`)**:
   * **Justificación**: En lugar de asignar memoria dinámicamente (`malloc`) para invertir cadenas numéricas o usar búferes estáticos auxiliares, se eligió una solución recursiva.
   * **Funcionamiento**: Al dividir recursivamente el número entre la base (`nbr / base_len`) antes de imprimir el resto (`nbr % base_len`), los dígitos se imprimen en el orden correcto de izquierda a derecha durante la desapilación de llamadas.
   * **Tipo Genérico**: `ft_putnbr_base_count` recibe un `unsigned long long`. Esto permite procesar tanto punteros de 64 bits (`%p`), enteros sin signo (`%u`), como conversiones hexadecimales (`%x`, `%X`) dentro de la misma función genérica.

3. **Gestión de Casos Límite
   * **`INT_MIN`**: La negación de `-2147483648` sobrepasa el rango de un `int` positivo en complemento a dos. Se gestiona escribiendo directamente `"-2147483648"` con `write` y retornando explícitamente `11`.
   * **Punteros y Cadenas Nulas**: `ft_putstr_count` maneja punteros a `NULL` devolviendo la longitud de `"(null)"`, y `ft_print_ptr_count` los trata imprimiendo `"(nil)"`.

---

## Instrucciones

### Compilación

El proyecto se compila mediante el `Makefile` incluido con los flags `-Wall -Wextra -Werror`:

```
make
```

Esto generará la biblioteca estática `libftprintf.a` en la raíz del repositorio.

### Reglas del Makefile

* `make`: Compila los archivos fuentes y crea la librería estática.
* `make clean`: Elimina los archivos objeto (`.o`).
* `make fclean`: Elimina los archivos objeto y el archivo `libftprintf.a`.
* `make re`: Recompila todo el proyecto desde cero.

### Uso en un Proyecto

Para utilizar `ft_printf` en tu propio código de C:

1. Incluye la cabecera en tu archivo fuente:
   ```c
   #include "ft_printf.h"
   ```

2. Compila tu programa enlazando la librería:
   ```bash
   cc -Wall -Wextra -Werror main.c libftprintf.a -o mi_programa
   ```

---

## Recursos
- **Man pages de Linux**: printf y stdarg.
- **Inteligencia Artificial**: realización de pruebas.