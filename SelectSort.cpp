/**
 * @file SelectSort.cpp
 * @brief Ejecución del algoritmo Selection Sort y medición en diferentes patrones de datos.
 *
 * Complejidad: O(n^2) en todos los casos por las comparaciones anidadas.
 * Se evalúan tamaños configurables y se reportan los tiempos de ejecución.
 */

#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include "sorting_utils.h"

// Busca el mínimo restante en cada iteración y lo coloca en su posición final.
void selectionSort(std::vector<int>& arr) {
    const int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        std::swap(arr[min_index], arr[i]);
    }
}

int main() {
    const std::vector<int> sizes{5'000, 7'500, 10'000, 12'500, 15'000};
    const std::vector<DataPattern> patterns{DataPattern::Sorted, DataPattern::Random, DataPattern::Reversed};

    for (DataPattern pattern : patterns) {
        std::cout << "Tipo: " << patternLabel(pattern) << '\n';
        for (int size : sizes) {
            std::vector<int> arr = makeArray(size, pattern);
            const auto start = Clock::now();
            selectionSort(arr);
            const auto stop = Clock::now();
            const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "Tamano: " << size << ", Tiempo: " << duration.count() << " microsegundos" << std::endl;
        }
        std::cout << '\n';
    }

    return 0;
}
