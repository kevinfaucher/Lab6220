#include "SortingClass.hpp"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

SortingClass::SortingClass(int si, int sm, int la) {
    size = si;
    smallest = sm;
    largest = la;

    randArr = new int[si];

    //random array
    for (int i = 0; i < size; i++) {
        int randomNum = smallest + (rand() % (largest - smallest + 1));
        randArr[i] = randomNum;
    }

    //in order array
    inOrderArr = new int[si];

    for (int i = 0; i < size && i <= largest; i++) {
        inOrderArr[i] = i + smallest;

    }

    //Reverse order array
    revOrderArr = new int[size];

    for (int i = 0; i < size && i >= smallest; i++) {
        revOrderArr[i] = largest - i;
    }
}

SortingClass::SortingClass(int si) {
    //(2 pts) largest should be 5000, smallest should be 10
    size = si;
    smallest = 10;
    largest = 5000;
    //  
    inOrderArr = new int[si];
    for (int i = 0; i < size && i <= largest; i++) {
        inOrderArr[i] = i + smallest;
        //
    }

}

SortingClass::SortingClass() {
    //(2 pts) largest should be 5000, smallest should be 10
    size = 50000;
    smallest = 10;
    largest = 5000;

    revOrderArr = new int[size];
    //
    for (int i = 0; i < size && i >= smallest; i++) {
        revOrderArr[i] = largest - i;
    }

}

int *SortingClass::copyArr(string s) {
    //(7 pts) based on s (which can be “rev”, “ord”, or “rand”, creates a new array,
    // copies over the old array, and returns the address of the new array

    //The new array
    int * tempArray;

    if (s == "rev") {
        tempArray = revOrderArr;

    } else if (s == "ord") {
        tempArray = inOrderArr;

    } else if (s == "rand") {
        tempArray = randArr;

    }
    return tempArray;

}

void SortingClass::selectionSort(int arr[]) {
    int tmp;

    for (int i = 0; i < 5 - 1; i++)

        for (int j = i + 1; j < 5; j++)

            if (arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
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
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
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

void SortingClass::merge(int arr[], int left, int m, int l) {
    int firstI, secondI, mergedI;
    int n1 = m - left + 1;
    int n2 = l - m;

    //creating temporary arrays
    int Larr[n1];
    int Rarr[n2];

    //copy the data from the array to left and right arrays
    for (firstI = 0; firstI < n1; firstI++)
        Larr[firstI] = arr[left + firstI];
    for (secondI = 0; secondI < n2; secondI++)
        Rarr[secondI] = arr[m + 1 + secondI];

    //merge the two sub arrays back together
    firstI = 0; // first index of the first subarray
    secondI = 0; // first index of the second subarray
    mergedI = left; // first index of the merged subarrays
    while (firstI < n1 && secondI < n2) {
        if (Larr[firstI] <= Rarr[secondI]) {
            arr[mergedI] = Larr[firstI];
            firstI++;
        } else {
            arr[mergedI] = Rarr[secondI];
            secondI++;
        }
        mergedI++;
    }

    //copy what's left of Larr[]
    while (firstI < n1) {
        arr[mergedI] = Larr[firstI];
        firstI++;
        mergedI++;
    }

    //Copy what is left of Rarr
    while (secondI < n2) {
        arr[mergedI] = Rarr[secondI];
        secondI++;
        mergedI++;
    }
}

void SortingClass::mergeSort(int arr[], int low, int high) {
    // (4 pts)keeps dividing the portion of the array between the low index and the hi
    // index by dividing by 2
    if (low < high) {
        int m = low + (high - low) / 2;

        //sort the two sub arrays, left array and the right array
        mergeSort(arr, low, m);
        mergeSort(arr, m + 1, high);

        merge(arr, low, m, high);
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

void SortingClass::heapify(int arr[], int n, int i) {
    int largest = i; // root = largest
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;

    // condition for if lchild > root
    if (lchild < n && arr[lchild] > arr[largest])
        largest = lchild;

    // if rchild is largest
    if (rchild < n && arr[rchild] > arr[largest])
        largest = rchild;

    // largest != root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void SortingClass::heapSort(int arr[], int n) {
    // build the heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // bubble up and remove root
    for (int i = n - 1; i >= 0; i--) {
        // move the root to the last index position since it is open
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

int SortingClass::getMaximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void SortingClass::countSort(int arr[], int n, int sigDigit) {
    int output[n]; //tmp final arr
    int i, count[10] = {0};


    for (i = 0; i < n; i++)
        count[ (arr[i] / sigDigit) % 10 ]++;

    //count contains position of the digit
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // create the output array in a loop
    for (i = n - 1; i >= 0; i--) {
        output[count[ (arr[i] / sigDigit) % 10 ] - 1] = arr[i];
        count[ (arr[i] / sigDigit) % 10 ]--;
    }

    //creating sorted arr
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void SortingClass::RadixSort(int arr[], int n) {
    // find the max number
    int max = getMaximum(arr, n);

    //keeping track of the digits
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void SortingClass::compareSorts() {

    clock_t startTime = clock();
    double timePassed;
    //SELECTION SORT

    int *arr = copyArr("rand");

    startTime = clock();


    selectionSort(arr);

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
    quickSort(0, size - 1, arr);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Quick: rand " << timePassed << endl;
    arr = copyArr("rev");
    startTime = clock();
    quickSort(0, size - 1, arr);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Quick: rev " << timePassed << endl;
    arr = copyArr("ord");
    startTime = clock();
    quickSort(0, size - 1, arr);
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
    mergeSort(arr, 0, size);
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

    //BUBBLESORT
    arr = copyArr("rand");
    startTime = clock();
    bubbleSort(arr, size);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Bubble: rand " << timePassed << endl;
    arr = copyArr("rev");
    startTime = clock();
    bubbleSort(arr, size);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Bubble: rev " << timePassed << endl;
    arr = copyArr("ord");
    startTime = clock();
    bubbleSort(arr, size);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Bubble: ord " << timePassed << endl;

    //HEAPSORT
    arr = copyArr("rand");
    startTime = clock();
    heapSort(arr, size);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Heap: rand " << timePassed << endl;
    arr = copyArr("rev");
    startTime = clock();
    heapSort(arr, size);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Heap: rev " << timePassed << endl;
    arr = copyArr("ord");
    startTime = clock();
    heapSort(arr, size);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Heap: ord " << timePassed << endl;

    //RADIX SORT
    arr = copyArr("rand");
    startTime = clock();
    RadixSort(arr, size);
    ;
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Heap: rand " << timePassed << endl;
    arr = copyArr("rev");
    startTime = clock();
    RadixSort(arr, size);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Heap: rev " << timePassed << endl;
    arr = copyArr("ord");
    startTime = clock();
    RadixSort(arr, size);
    timePassed = clock() - startTime;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete [] arr;
    cout << "Heap: ord " << timePassed << endl;
}