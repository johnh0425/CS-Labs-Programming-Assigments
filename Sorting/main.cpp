#include <iostream>
using namespace std;

void Quicksort_midpoint(int numbers[], int i, int k);       // quick sort by setting pivot as the midpoint value of array
int Partition_midpoint(int numbers[], int i, int k);        // called by quicksort_midpoint that partitions array for sorting through setting midpoint value as pivot
void Quicksort_medianOfThree(int numbers[], int i, int k);      // quick sort by setting pivot as the median of three value (far left, midpoint, and far right)
int Partition_Median(int numbers[], int i, int k);              // called by quicksort_medianofthree that partitions array for sorting through setting the median of three values as pivot
int findMedian(int numbers[], int i, int midpoint, int k);      // called by parition_median that finds the median of three passed in values
void InsertionSort(int numbers[], int numbersSize);             // insertion sort
int genRandInt(int low, int high);                      // gets random integer
void fillArrays(int arr1[], int arr2[],int arr3[]);     // fill up 3 arrays with random integers

int main() {
    const int NUMBERS_SIZE = 50000;     // size of all 3 arrays
    int arr1[NUMBERS_SIZE];         // creates a new array1
    int arr2[NUMBERS_SIZE];         // creates a new array2
    int arr3[NUMBERS_SIZE];         // creates a new array3
    fillArrays(arr1, arr2, arr3);
    const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
    clock_t Start = clock();        // start the clock
    //call sort function here
    Quicksort_midpoint(arr1, 0, 30000);     // call quicksort using midpoint as pivot
    // Testcases
    // Quicksort_midpoint(arr1, 0, 20);
    // Quicksort_midpoint(arr1, 0, 1500);
    // Quicksort_midpoint(arr1, 0, 50000);
    clock_t End = clock();          // end clock
    int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    std::cout << "Quick Sort Midpoint Time: " << elapsedTime << std::endl;        // prints time for quicksort midpoint to sort
    Start = clock();        // start clock
    Quicksort_medianOfThree(arr2, 0, 30000);        // call quick sort using median of three values as pivot
    // Testcases
    // Quicksort_medianOfThree(arr2, 0, 20);
    // Quicksort_medianOfThree(arr2, 0, 1500);
    // Quicksort_medianOfThree(arr2, 0, 50000);
    End = clock();      // end clock
    elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    std::cout << "Quick Sort Median of Three Time: " << elapsedTime << std::endl;     // prints time for quicksort median of three to sort
    Start = clock();            // start clock
    InsertionSort(arr3, 30000);         // call insertion sort
    // Testcases
    // InsertionSort(arr3, 20);
    // InsertionSort(arr3, 1500);
    // InsertionSort(arr3, 50000);
    End = clock();      // end clock
    elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    std::cout << "Insertion Sort Time: " << elapsedTime << std::endl;         // prints time for insertion sort to sort
}

int genRandInt(int low, int high) {         // gets random numbers to be inserted into array
   return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]){     // fills all 3 arrays passed in with the same values
    const int NUMBERS_SIZE = 50000;
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);       // fills array 1
        arr2[i] = arr1[i];          // fills array 2
        arr3[i] = arr1[i];          // fills array 3
    }
}

void Quicksort_midpoint(int numbers[], int i, int k) {          // quick sort algorthim that uses midpoint value as pivot
    if (i >= k) {       // returns when k (indicating far right bound that needs to be sorted) is smaller than i (far left bound)
        return;         
    }
    int lowEndIndex = Partition_midpoint(numbers, i, k);        // call partition function which splits the array into smaller groups for quicker sorting using the midpoint as pivot
    Quicksort_midpoint(numbers, i, lowEndIndex);        // quicksort the left side of array that was split
    Quicksort_midpoint(numbers, lowEndIndex + 1, k);        // quicksort the right side of array that was split
}

int Partition_midpoint(int numbers[], int i, int k) {       // partition function splits the array into smalled groups for quicker sorting using the midpoint as pivot
    int midpoint = i + (k - i) / 2;
    int pivot = numbers[midpoint];      // pick the middle element as the pivot
    bool done = false;
    while (!done) {
        while (numbers[i] < pivot) {    
            i += 1;
        }
        while (pivot < numbers[k]) {
            k -= 1;
        }
        if (i >= k) {       // if zero or one element remains, then all numbers are partitioned
            done = true;
        }
        else {      // swap the low index and high index number
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;

            i += 1;     // update both low index and high index numbers
            k -= 1;
        }
    }
    return k;
 }

void Quicksort_medianOfThree(int numbers[], int i, int k) {   // quick sort algorthim that uses median of three values as pivot to sort
    if (i >= k) {        // returns when k (indicating far right bound that needs to be sorted) is smaller than i (far left bound)
        return;
    }
    int lowEndIndex = Partition_Median(numbers, i, k);      // call partition function which splits the array into smaller groups for quicker sorting using the median of three points as pivot
    Quicksort_medianOfThree(numbers, i, lowEndIndex);           // quicksort the left side of array that was split
    Quicksort_medianOfThree(numbers, lowEndIndex + 1, k);       // quicksort the right side of array that was split
}
int Partition_Median(int numbers[], int i, int k) {     //partition function which splits the array into smaller groups for quicker sorting using the median of three points as pivot
    int midpoint = i + (k - i) / 2;
    int pivot = findMedian(numbers, i, midpoint, k);        // calls function to return the median of number at the far left side of array, far right side of array, or midpoint of array
    bool done = false;
    while (!done) {
        while (numbers[i] < pivot) {
            i += 1;
        }
        while (pivot < numbers[k]) {
            k -= 1;
        }
        if (i >= k) {       // if zero or one element remains, then all numbers are partitioned
            done = true;
        }
        else {      // swap the low index and high index number
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;

            i += 1;         // update both low index and high index numbers
            k -= 1;
        }
    }
    return k;
 }

int findMedian(int numbers[], int i, int midpoint, int k) {         // finds the median of the three numbers passed in
    if (((numbers[i] <= numbers[midpoint]) && (numbers[midpoint] <= numbers[k])) || ((numbers[k] <= numbers[midpoint]) && (numbers[midpoint] <= numbers[i]))) {
        return numbers[midpoint];       // returns when the midpoint element is the middle of the three
    }
    else if (((numbers[midpoint] <= numbers[i]) && (numbers[i] <= numbers[k])) || ((numbers[k] <= numbers[i])&& (numbers[i] <= numbers[midpoint]))) {
        return numbers[i];      // returns when the far left element is the middle value of the three
    }
    else {
        return numbers[k];      // returns when the far right element is the middle value of the three
    }
 }

void InsertionSort(int numbers[], int numbersSize) {        // insertion sort algorthim
    int i = 0;
    int j = 0;
    int swap = 0;       // temporary variable for swapping
    for (i = 1; i < numbersSize; ++i) {
        j = i;      // insert numbers[i] into sorted part and stopping once number[i] is in correct spot
        while (j > 0 && numbers[j] < numbers[j - 1]) {      // swaps when number at j is is greater than its next value
            swap = numbers[j];      // swap number[j] and number[j-1]
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = swap;
            --j;
        }
    }
}