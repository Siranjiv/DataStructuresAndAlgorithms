#include <iostream>

using namespace std;


void funcThree() {
    cout << "Three" << endl;
}

void funcTwo() {
    funcThree();
    cout << "Two" << endl;
}

void funcOne() {
    funcTwo();
    cout << "One" << endl;
}


int main() {

    funcOne();

}

//You can use the breakpoint and check the call stack

//the call stack goes like a stack based on the above code

//funcThree
//funcTwo
//funcOne
//main
