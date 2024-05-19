#include <iostream>

using namespace std;


class Node {
    public:
        string key;
        int value;
        Node* next;

        Node(string key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

class HashTable {
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];

        int hash(string key) {
            int hash = 0;
            for (int i = 0; i < key.length(); i++) {
                int asciiValue = int(key[i]);
                hash = (hash + asciiValue *  23) % SIZE;
            }
            return hash;
        }

    public:
        // ---------------------------------------------------
        //  Destructor code is similar to keys() function
        //  Watch that video to help understand how this works
        // ---------------------------------------------------
        ~HashTable() {
            for(int i = 0; i < SIZE; i++) {
                Node* head = dataMap[i];
                Node* temp = head;
                while (head) {
                    head = head->next;
                    delete temp;
                    temp = head;
                }
            }
        }
        
        void printTable() {
            for(int i = 0; i < SIZE; i++) {
                cout << i << ":" << endl;
                if(dataMap[i]) {
                    Node* temp = dataMap[i];
                    while (temp) {
                        cout << "   {" << temp->key << ", " << temp->value << "}" << endl;
                        temp = temp->next;
                    }
                }
            }
        }
        
        void set(string key, int value) {
            int index = hash(key);
            Node* newNode = new Node(key, value);
            if (dataMap[index] == nullptr) {
                dataMap[index] = newNode;
            } else {
                Node* temp = dataMap[index];
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    
        //Function to get a value from hash table
        int get(string key) {
            int index = hash(key);
            Node* temp = dataMap[index]; //if dataMap[index] doesn't have value then it points to nullptr
            while (temp != nullptr) {
                if (temp->key == key) return temp->value;
                temp = temp->next;
            }
            return 0;   //My opinion is to use something ele like INT_MIN to make false note
        }  

};


int main() {

    HashTable* myHashTable = new HashTable();

    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);

    cout << "Lumber: " << myHashTable->get("lumber") << endl;
    cout << "Bolts: " << myHashTable->get("bolts") << endl;

    /*
        EXPECTED OUTPUT:
        ----------------
        Lumber: 80
        Bolts: 0

    */  

}