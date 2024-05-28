#include <iostream>

using namespace std;


void swap(int array[], int firstIndex, int secondIndex) {
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}


int pivot(int array[], int pivotIndex, int endIndex) {
    int swapIndex = pivotIndex;
    for (int i = pivotIndex + 1; i <= endIndex; i++) {
        if (array[i] < array[pivotIndex]) {
            swapIndex++;
            swap(array, swapIndex, i);
        }
    }
    swap(array, pivotIndex, swapIndex);

    return swapIndex;
}

    //When we initally run, the leftIndex will be the first item
    //and the rightIndex will be the last item in the array
	void quickSort(int array[], int leftIndex, int rightIndex) {

        if(leftIndex >= rightIndex) return; //This is the BaseCase

        //When we call pivot, it will be on the same range that we used
        //in the instance of quickSort Eg:- if QS is arr 0 6 then pivot will be arr 0 6 as well
        int pivotIndex = pivot(array, leftIndex, rightIndex);

        //We run this for the left side of the array using the pivot index we found
        quickSort(array, leftIndex, pivotIndex-1);

        //We run this for the right side of the array using the pivot index we found
        quickSort(array, pivotIndex+1, rightIndex);
    }



int main() {
    
    int myArray[] = {4,6,1,7,3,2,5};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    quickSort(myArray, 0, size-1);


    for (auto value : myArray) {  
        cout << value << " ";
    }
    
    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 7 
        
     */

}

