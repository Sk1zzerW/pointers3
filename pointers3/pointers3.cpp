#include <iostream>

bool isPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

int* removePrimes(int* arr, int& size) {
    int* newArray = new int[size];
    int newSize = 0;

    for (int i = 0; i < size; ++i) {
        if (!isPrime(arr[i])) {
            newArray[newSize++] = arr[i];
        }
    }

    int* resultArray = new int[newSize];
    for (int i = 0; i < newSize; ++i) {
        resultArray[i] = newArray[i];
    }

    delete[] newArray;
    size = newSize;

    return resultArray;
}

int main() {
    int size = 6;
    int arr[] = { 1, 2, 3, 4, 5, 6 };

    int* newArr = removePrimes(arr, size);

    std::cout << "f ";
    for (int i = 0; i < size; ++i) {
        std::cout << newArr[i] << " ";
    }
    std::cout << std::endl;

    delete[] newArr;
    return 0;
}
