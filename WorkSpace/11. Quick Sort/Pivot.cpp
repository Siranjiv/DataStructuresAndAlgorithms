#include <iostream>

using namespace std;

//This is used when we want to swap items in the array
void swap(int array[], int firstIndex, int secondIndex) {
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

    //The pivotIndex is the Pivot as initially it is at the 0th index
    //endIndex is the last index of the array
	int pivot(int array[], int pivotIndex, int endIndex) {
        int swapIndex = pivotIndex;
        for(int i = pivotIndex + 1; i <= endIndex; i++) {   //i will be the index after the pivotIndex initially
            if(array[i] < array[pivotIndex]) {
                swapIndex++;
                swap(array, swapIndex, i);
            }
        }
        swap(array, pivotIndex, swapIndex);
        return swapIndex;

    }



int main() {
    
    int myArray[] = {4,6,1,7,3,2,5};

    int size = sizeof(myArray) / sizeof(myArray[0]);

    //Hint-> Use breakpoint to debug and understand
    int returnedIndex = pivot(myArray, 0, size-1);

    cout << "Returned Index: " << returnedIndex << "\n\n";

    for (auto value : myArray) {
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        Returned Index: 3

        2 1 3 4 6 7 5  
        
     */
    
}

