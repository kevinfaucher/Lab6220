#include "SortingClass.hpp"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

SortingClass::SortingClass(int si, int sm, int la) {
    int size = si;
    int smallest = sm;
    int largest = la;
    int *randArr;
    randArr = new int[si];

    for (int i = 0; i < size; i++) {
        randArr[i] = rand() % (largest - smallest + 1) + smallest;
    }

}

SortingClass::SortingClass(int si) {
    //(2 pts) largest should be 5000, smallest should be 10
    int size = si;

    smallest = 10;
    int *inOrderArr;
    inOrderArr = new int[si];

    for (int i = 0; i < size; i++) {
        inOrderArr[i] = i + smallest;
    }

}

SortingClass::SortingClass() {
    //(2 pts) largest should be 5000, smallest should be 10
    int size = size;
    largest = 5000;
    int *revOrderArr;
    revOrderArr = new int[size];
    for (int i = 0; i < size; i++) {
        revOrderArr[i] = i + largest;
    }

}

int *SortingClass::copyArr(string s) {
    //(7 pts) based on s (which can be “rev”, “ord”, or “rand”, creates a new array,
    // copies over the old array, and returns the address of the new array
    
    //The new array
    int * tempArray;

    if (s == "rev") {
        tempArray = revOrderArr;
        //do something
    } else if (s == "ord") {
        tempArray = inOrderArr;
        //do something
    } else if (s == "rand") {
         tempArray = randArr;
        //do something
        

    }
    return tempArray;
    
}

void SortingClass::selectionSort(int arr[]) {
    // (4 pts) Does what you’d think to the array passed into the method.
    cout << "made it in selection sort" << endl;
    int tmp;
    cout << "made it in selection sort past first loop" << endl;
    for (int i = 0; i < 5 - 1; i++)

        for (int j = i + 1; j < 5; j++)

            if (arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }

    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    cout << endl;

}

void SortingClass::insertionSort(int arr[]) {
    int i, j, tmp, length;
    length = (sizeof (arr) / sizeof (*arr));

    for (i = 1; i < length; i++) {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

void SortingClass::quickSort(int first, int last, int arr[]) {
    if (last - first > 1) { // There is data to be sorted.
        // Partition the table.
        int pivot = partition(first, last, arr);

        // Sort the left half.
        quickSort(first, pivot - 1, arr);

        // Sort the right half.
        quickSort(pivot + 1, last, arr);
    }
}

int SortingClass::partition(int first, int last, int arr[]) {
    int p = first;
    int pivot = arr[first];
    int i = first + 1, j = last;
    int tmp;
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    return p;
}

void SortingClass::merge(int arr[], int f, int m, int l) {
    int n1 = m - f + 1;
    int n2 = l - m;
    int L[n1 + 1];
    int R[n2 + 1];
    for (int i = 1; i <= n1; i++) {
        L[i] = arr[f + i - 1];
    }
    for (int j = 1; j <= n2; j++) {
        R[j] = arr[m + j];
    }
    L[n1 + 1] = 999;
    R[n2 + 1] = 999;
    int i = 1, j = 1;
    for (int k = f; k <= l; k++) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i = i + 1;
        } else {
            arr[k] = R[j];
            j = j + 1;
        }
    }
}

void SortingClass::mergeSort(int a[], int low, int hi) {
    // (4 pts)keeps dividing the portion of the array between the low index and the hi
    // index by dividing by 2
    int q;
    if (low < hi) {
        q = (low + hi) / 2;
        mergeSort(a, low, q);
        mergeSort(a, q + 1, hi);
        merge(a, low, q, hi);
    }
}

void SortingClass::bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void SortingClass::compareSorts() {
    cout << "made it to compareSorts" << endl;
    clock_t startTime = clock();
    double timePassed;
    //SELECTION SORT
    cout << "made it before copyArr" << endl;
    int *arr = copyArr("rand");
    cout << "made it after copyArr" << endl;
    startTime = clock();
    cout << "made it just before selection sort" << endl;

    selectionSort(arr);
    cout << "made it past selection sort" << endl;
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Selection: rand " << timePassed << endl;
    arr = copyArr("rev");
    startTime = clock();
    selectionSort(arr);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Selection: rev " << timePassed << endl;
    arr = copyArr("ord");
    startTime = clock();
    selectionSort(arr);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Selection: ord " << timePassed << endl;
    //INSERTION
    arr = copyArr("rand");
    startTime = clock();
    insertionSort(arr);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Insertion: rand " << timePassed << endl;
    arr = copyArr("rev");
    startTime = clock();
    insertionSort(arr);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Insertion: rev " << timePassed << endl;
    arr = copyArr("ord");
    startTime = clock();
    insertionSort(arr);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Insertion: ord " << timePassed << endl;
    //QUICKSORT
    arr = copyArr("rand");
    startTime = clock();
    quickSort(0, size, arr);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Quick: rand " << timePassed << endl;
    arr = copyArr("rev");
    startTime = clock();
    quickSort(0, size, arr);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Quick: rev " << timePassed << endl;
    arr = copyArr("ord");
    startTime = clock();
    quickSort(0, size, arr);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Quick: ord " << timePassed << endl;
    //MERGE
    arr = copyArr("rand");
    startTime = clock();
    mergeSort(arr, 0, size - 1);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Merge: rand " << timePassed << endl;
    arr = copyArr("rev");
    startTime = clock();
    mergeSort(arr, 0, size - 1);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Merge: rev " << timePassed << endl;
    arr = copyArr("ord");
    startTime = clock();
    mergeSort(arr, 0, size - 1);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Merge: ord " << timePassed << endl;
}
