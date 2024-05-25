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

//Here we are sorting the arrays to sub arrays

        //This is for the left array
        for(int i = 0; i< leftArraySize; i++)
            leftArray[i] = array[leftIndex + i];

        //This is for the right array
        for(int j = 0; j < rightArraySize; j++)
            rightArray[j] = array[midIndex + 1 + j];    //  midIndex + 1 will be the first item side of the right array
            

        int index = leftIndex;  //This is the first item in the main array
        int i = 0;  //Keep track of the first sub array
        int j = 0;  //Keep track of the second sub array

        while(i < leftArraySize && j < rightArraySize) {    //This while loop will run until one of the 2 sub arrays are empty
            if (leftArray[i] <= rightArray[j]) {
                array[index] = leftArray[i];    //insert the left array i index value to main array
                index++;    //move main array index by one
                i++;    //move the left sub array index
            } else {
                array[index] = rightArray[j];   //insert the right array j index value to main array
                index++;    //move main array index by one
                j++;    //move the right sub array index
            } 
        }

        while (i < leftArraySize) {         //This loop will work when the right array in empty and left array has values
            array[index] = leftArray[i];
            index++;
            i++;
        }

        while (j < rightArraySize) {       //This loop will work when the left array in empty and left array has values
            array[index] = rightArray[j];
            index++;
            j++;
        }
        

    }
 
 
int main() {
    
    int myArray[] = {1,3,7,8,2,4,5,6};

    int size = sizeof(myArray) / sizeof(myArray[0]);
    
    //This is to calculate the indexes
    int leftIndex = 0;  //The left most index will be zero
    int rightIndex = size - 1;  //The right most index will be the size - 1
    int midIndex = (size / 2) - 1;  //This will calculate the middle index

    //Use Breakpoints to understand more
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

