#include <iostream>

using namespace std;

    //leftIndex is the left most Item
    //midIndex is the middle Item
    //rightIndex is the right most Item in the array
	void merge(int array [], int leftIndex, int midIndex, int rightIndex) {
        int leftArraySize = midIndex - leftIndex + 1;
        int rightArraySize = rightIndex - midIndex;

        //we are now creating the 2 arrays
        int leftArray[leftArraySize];
        int rightArray[rightArraySize];

        //This is for the left array
        for(int i = 0; i< leftArraySize; i++)
            leftArray[i] = array[leftIndex + i];

        //This is for the right array
        for(int j = 0; j < rightArraySize; j++)
            rightArray[j] = array[midIndex + 1 + j];    //  midIndex + 1 will be the first item side of the right array
    }
 
 
int main() {
    
    int myArray[] = {1,3,7,8,2,4,5,6};

    int size = sizeof(myArray) / sizeof(myArray[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;
    int midIndex = (size / 2) - 1;


   merge(myArray, leftIndex, midIndex, rightIndex);


    for (auto value : myArray) {  
        cout << value << " ";
    }
    
    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 7 8 
        
     */

}

