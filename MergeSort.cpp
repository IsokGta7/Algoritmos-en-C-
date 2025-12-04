/**
 * @file MergeSort.cpp
 * @brief Implementación de Merge Sort y medición de rendimiento con distintos patrones.
 *
 * Complejidad: O(n log n) en todos los casos al dividir y combinar subarreglos.
 * Se prueban tamaños crecientes y se reportan los tiempos en microsegundos.
 */

#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include "sorting_utils.h"

// Combina dos subarreglos ordenados en un rango [l, r].
void merge(std::vector<int>& arr, int l, int m, int r) {
    const int n1 = m - l + 1;
    const int n2 = r - m;
    std::vector<int> left(n1), right(n2);

    for (int i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            ++i;
        } else {
            arr[k] = right[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k++] = left[i++];
    }
    while (j < n2) {
        arr[k++] = right[j++];
    }
}

// Ordena el vector usando recursividad para dividir y conquistar.
void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r) {
        return;
    }
    const int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    const std::vector<int> sizes{10'000, 20'000, 40'000, 60'000, 80'000, 100'000};
    const std::vector<DataPattern> patterns{DataPattern::Sorted, DataPattern::Random, DataPattern::Reversed};

    for (DataPattern pattern : patterns) {
        std::cout << "Tipo: " << patternLabel(pattern) << '\n';
        for (int size : sizes) {
            std::vector<int> arr = makeArray(size, pattern);
            const auto start = Clock::now();
            mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
            const auto stop = Clock::now();
            const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "Tamano: " << size << ", Tiempo: " << duration.count() << " microsegundos" << std::endl;
        }
        std::cout << '\n';
    }

    return 0;
}
