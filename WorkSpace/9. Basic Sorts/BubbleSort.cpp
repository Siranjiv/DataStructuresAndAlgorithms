#include <iostream>

using namespace std;


void printArray(int array[],int size)
{
   for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

	void bubbleSort(int array[], int size) {
        for(int i = size - 1; i > 0; i--) { // for loop to know how many swaps
            for(int j = 0; j < i; j++) {    //The number of times it will swap based on the above for loop value
                if(array[j] > array[j+1]) {
                    int temp = array[j];
                    array[j] = array [j+1];
                    array[j+1] = temp;
                    printArray(array,size); //This is extra code for me to check the process
                }
            }
        }
    }



int main() {
    
    int myArray[] = {6,4,2,5,1,3};

    //sizeof returns the number of bytes so here int returns 4 bytes
    // so sizeof(myArray) return 24 because 4 * 6(6 being the number of elements)
    // and sizeof(myArray[0]) will give 4 where 4*1 
    //So the final size will be 24 / 4 = 6
    int size = sizeof(myArray) / sizeof(myArray[0]); 



    std::cout << "Original array: ";
    printArray(myArray, size);

    //here in myArray you pass the first item of the array where you are not also passing the size
    bubbleSort(myArray, size);

    std::cout << "Sorted array: ";
    printArray(myArray, size);



    // for (auto value : myArray) {  
    //     cout << value << " ";
    // }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 
        
     */
    
}

