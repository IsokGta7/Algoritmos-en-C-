# Algoritmos de ordenamiento en C++

Implementaciones sencillas de **Insertion Sort**, **Selection Sort** y **Merge Sort**
con medición de rendimiento sobre distintos tamaños de entrada y patrones de datos
(ordenado, inverso y aleatorio).

## Requisitos
- Compilador compatible con C++17 o superior (g++, clang++ o MSVC)
- CMake no es necesario; se compila cada ejecutable por separado.

## Estructura
```
.
├── InsertionSort.cpp     # Inserción directa y cronometraje
├── MergeSort.cpp         # Ordenamiento por mezcla recursivo y cronometraje
├── SelectSort.cpp        # Selección directa y cronometraje
└── sorting_utils.h       # Utilidades compartidas (patrones y generación de datos)
```

## Compilación
Ejemplos usando g++ con optimizaciones básicas:

```bash
# Insertion Sort
g++ -std=c++17 -O2 InsertionSort.cpp -o insertion_sort

# Selection Sort
g++ -std=c++17 -O2 SelectSort.cpp -o selection_sort

# Merge Sort
g++ -std=c++17 -O2 MergeSort.cpp -o merge_sort
```

> En Windows con MSVC, puede compilarse con `cl /std:c++17 /O2 InsertionSort.cpp`.

## Ejecución y parámetros
Cada binario genera arreglos con tres patrones (ordenado, inverso y aleatorio) y
prueba un conjunto de tamaños definidos como constantes dentro de `main`. Los
valores actuales son:

- **Insertion Sort:** 100, 1 000, 10 000, 50 000 y 100 000 elementos.
- **Selection Sort:** 5 000, 7 500, 10 000, 12 500 y 15 000 elementos.
- **Merge Sort:** 10 000, 20 000, 40 000, 60 000, 80 000 y 100 000 elementos.

Los resultados se muestran en microsegundos en la salida estándar.

### Personalizar tamaños o patrones
- Ajuste los vectores `sizes` en cada `main` para cambiar la batería de pruebas.
- Para modificar los patrones disponibles, edite el enum `DataPattern` y la
  función `patternLabel` en `sorting_utils.h`.

### Reproducibilidad y generación de datos
- La generación aleatoria usa `std::mt19937` con una semilla creada vía
  `std::random_device`, lo que la hace portable en Windows, macOS y Linux sin
  dependencias de `system("pause")` ni `rand()`.

## Casos y complejidad
- **Insertion Sort:** O(n^2) promedio/peor, O(n) mejor caso (arreglo ordenado).
- **Selection Sort:** O(n^2) en todos los casos; el número de comparaciones es fijo.
- **Merge Sort:** O(n log n) estable en todos los casos gracias a la división y mezcla.

## Contribuir
1. Cree una rama a partir de `main`.
2. Aplique cambios siguiendo las convenciones de C++17 y mantenga comentarios
   descriptivos en funciones y bucles principales.
3. Abra un Pull Request describiendo los cambios y las pruebas ejecutadas.

## Licencia
El proyecto se distribuye para fines educativos; adapte la licencia según sus
necesidades si planea publicarlo.
