#include <iostream>

using namespace std;


void merge(int array[], int leftIndex, int midIndex, int rightIndex) {
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for (int i = 0; i < leftArraySize; i++)
        leftArray[i] = array[leftIndex + i];
    for (int j = 0; j < rightArraySize; j++)
        rightArray[j] = array[midIndex + 1 + j];

    int i = 0;
    int j = 0;
    int index = leftIndex;

    while (i < leftArraySize && j < rightArraySize) {
        if (leftArray[i] <= rightArray[j]) {
            array[index] = leftArray[i];
            index++;
            i++;
        }
        else {
            array[index] = rightArray[j];
            index++;
            j++;
        }

    }

    while (i < leftArraySize) {
        array[index] = leftArray[i];
        index++;
        i++;
    }

    while (j < rightArraySize) {
        array[index] = rightArray[j];
        index++;
        j++;
    }

}
    /*Please Check with the call stack for recursion*/
    //leftIndex is the first item at idex 0 of the array
    // right index is the last item of the array index
	void mergeSort(int array[], int leftIndex, int rightIndex) {

        //This is the base case
        if(leftIndex >= rightIndex) return;

        //Equation to calculte the middle Index
        int midIndex = leftIndex + (rightIndex - leftIndex) / 2;    //Hint:- We drop everything in the right decimal place

        //This will keep on running until the we get one item for the stack (until we meet the baseCase)
        //This is used to keep on breaking the array with the middle index until we get one index from the Left array
        mergeSort(array, leftIndex, midIndex);

        //Same as above but for the right side array of every sub array
        mergeSort(array,midIndex+1, rightIndex);

        //After one side of sub arrays have 1 element we can call the merge Function
        merge(array, leftIndex, midIndex, rightIndex);

    }



int main() {
    
    int myArray[] = {3,1,4,2};

    int size = sizeof(myArray) / sizeof(myArray[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;


    mergeSort(myArray, leftIndex, rightIndex);


    for (auto value : myArray) {  
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 
        
     */
    
}

