#include <iostream>

using namespace std;

int factorial(int n) {
    if (n==1) return 1;
    return n * factorial(n-1);

}

int main() {

    cout<<factorial(4);
    return 0;
}

//Debug using the break point and also take note of the call stack on how the factorial work

//the call stack would look like this after all functions being called

//1!
//2!
//3!
//4!