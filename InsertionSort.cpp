/**
 * @file InsertionSort.cpp
 * @brief Demostración del algoritmo de inserción con casos ordenado, inverso y aleatorio.
 *
 * Complejidad: O(n^2) en el peor y promedio, O(n) en el mejor caso.
 * Este ejecutable genera arreglos de distintos tamaños y mide el tiempo
 * de ordenamiento usando std::chrono.
 */

#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include "sorting_utils.h"

// Ordena un vector in-place mediante el algoritmo Insertion Sort.
void insertionSort(std::vector<int>& arr) {
    const int n = static_cast<int>(arr.size());
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    const std::vector<int> sizes{100, 1'000, 10'000, 50'000, 100'000};
    const std::vector<DataPattern> patterns{DataPattern::Random, DataPattern::Sorted, DataPattern::Reversed};

    for (int size : sizes) {
        for (DataPattern pattern : patterns) {
            std::vector<int> arr = makeArray(size, pattern);
            const auto start = Clock::now();
            insertionSort(arr);
            const auto stop = Clock::now();
            const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "Tipo: " << patternLabel(pattern)
                      << ", Tamano: " << size
                      << ", Tiempo: " << duration.count() << " microsegundos" << std::endl;
        }
    }

    return 0;
}
