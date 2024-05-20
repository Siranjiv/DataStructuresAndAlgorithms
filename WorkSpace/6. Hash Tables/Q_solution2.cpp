#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool itemInCommon(vector<int> vect1, vector<int> vect2) {
    unordered_map<int, bool> myMap;

    for(auto i : vect1) {
        myMap.insert({i, true});
    }
    
    for(auto j : vect2) {
        if(myMap[j]) return true;
    }

    return false;
}

int main() {

    vector<int> vect1 {1, 3, 5};

    vector<int> vect2 {2, 4, 5};

    cout<< itemInCommon(vect1, vect2);

    //This will give O(2n) because of 2 for loops which will be simplified to O(n)
    //This is better that the first solution
    return 0;
}