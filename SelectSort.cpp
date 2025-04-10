#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int min_index = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_index])
                min_index = j;
        swap(arr[min_index], arr[i]);
    }
}

void printArray(const vector<int>& arr) {
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
}

vector<int> generateArray(int size, string type) {
    vector<int> arr(size);
    if (type == "ordenado") {
        for (int i = 0; i < size; i++) arr[i] = i;
    } else if (type == "inverso") {
        for (int i = 0; i < size; i++) arr[i] = size - i;
    } else { 
        for (int i = 0; i < size; i++) arr[i] = rand() % size;
    }
    return arr;
}

int main() {
    vector<string> types = {"ordenado", "random", "inverso"};
    long long int sizes[] = {5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500};
    
    for (string type : types) {
        cout << "Tipo: " << type << "\n";
        for (int size : sizes) {
            vector<int> arr = generateArray(size, type);
            auto start = high_resolution_clock::now();
            selectionSort(arr);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Tamanio: " << size << ", Tiempo: " << duration.count() << " microseconds" << endl;
        }
        cout << "\n";
    }
    system("pause");

    return 0;
}
