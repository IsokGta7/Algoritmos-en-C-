#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <numeric>
using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

vector<int> generateArray(int size, string type) {
    vector<int> arr(size);
    if (type == "ordenado") {
        iota(arr.begin(), arr.end(), 0);
    } else if (type == "inverso") {
        iota(arr.begin(), arr.end(), 1);
        reverse(arr.begin(), arr.end());
    } else { // Random (average case)
        srand((unsigned)time(0));
        generate(arr.begin(), arr.end(), []() { return rand() % 10000; });
    }
    return arr;
}

int main() {
    vector<string> types = {"ordenado", "random", "inverso"};
    int sizes[] = {10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000, 55000}; // Example sizes
    
    for (string type : types) {
        cout << "Tipo: " << type << "\n";
        for (int size : sizes) {
            vector<int> arr = generateArray(size, type);
            auto start = high_resolution_clock::now();
            mergeSort(arr, 0, arr.size() - 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Tamanio: " << size << ", Tiempo: " << duration.count() << " microsegundos" << endl;
        }
        cout << "\n";
    }

    system("pause");
    
    return 0;
}
