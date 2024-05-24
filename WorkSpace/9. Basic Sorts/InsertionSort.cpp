#include <iostream>

using namespace std;


	void insertionSort(int array[], int size) {
        for(int i = 1; i < size; i++) {    //i = 1 because we are starting from the second index
            int temp = array[i];
            int j = i -1;

            // j > -1 condition is for the 1st index tp check or else we get out of bound excepection
            //PLEASE remember the order when writng the condition in the while loop
            while (j > -1 && temp < array[j] ) {  
                array[j+1] = array[j];
                array[j] = temp;
                j--;
            }
        }
    }



int main() {
    
    int myArray[] = {6,4,2,5,1,3};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    insertionSort(myArray, size);


    for (auto value : myArray) {  
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 
        
     */
    
}

