#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if (arrSize == 0) {
        return nullptr;
    }
    const int *ptr = &arr[arrSize - 1];
    const int *min1 = min(arr, arrSize - 1);
    if (min1 == nullptr) {
        return ptr;
    }
    if (*min1 > *ptr) {
        return ptr;
    }
    else {
        return min1;
    }
}