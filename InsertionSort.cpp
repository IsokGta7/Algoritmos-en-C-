#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm> // Para std::sort y std::reverse
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

void insertionSort(vector<int>& arr) {
    int i, key, j;
    int n = arr.size();
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void fillArray(vector<int>& arr, const string& type) {
    if (type == "random") {
        for (int& x : arr) {
            x = rand() % 100000; // Números aleatorios entre 0 y 999
        }
    } else if (type == "sorted") {
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = i;
        }
    } else if (type == "reversed") {
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = arr.size() - i;
        }
    }
}

int main() {
    srand(time(0)); // Inicialización de la semilla para la generación de números aleatorios

    for (int n = 100; n <= 100000; n += 10000) { // Tamaños de arreglo: 100, 200, ..., 1000
        for (const string& type : {"random", "sorted", "reversed"}) {
            vector<int> arr(n);

            // Llenar el arreglo según el caso
            fillArray(arr, type);

            auto start = high_resolution_clock::now();
            insertionSort(arr);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);

            cout << "Tipo: " << type << ", Tamanio: " << n << ", Tiempo: " << duration.count() << " microsegundos" << endl;
        }
    }

    system ("pause");

    return 0;
}
