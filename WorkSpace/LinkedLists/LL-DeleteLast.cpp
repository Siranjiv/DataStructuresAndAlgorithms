#include <iostream>

using namespace std;


class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getHead() {
            if (head == nullptr) {
                cout << "Head: nullptr" << endl;
            } else {
                cout << "Head: " << head->value << endl;
            }
        }

        void getTail() {
            if (tail == nullptr) {
                cout << "Tail: nullptr" << endl;
            } else { 
                cout << "Tail: " << tail->value << endl;
            }  
        }

        void getLength() {
            cout << "Length: " << length << endl;
        }

		void append(int value) {
            Node* newNode = new Node(value);
            if(length==0) {
                head=newNode;
                tail=newNode;
            } else {    
                tail->next=newNode;
                tail=newNode;
            }
            length++;
        }
        //DeleteLast Function
        void deleteLast() {
            if(length == 0) return;
            Node* temp = head;
            Node* pre = head;
            while(temp->next) { //temp->next != nullptr
                pre=temp;
                temp=temp->next;
            }

            tail = pre;
            tail->next = nullptr;
            length--;

            if(length==0) // This is after length-- meaning if there is only one Node
            {
                tail=nullptr;
                head=nullptr;            
            }
            delete temp;
        }
	    
};



int main() {
        
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(2);

    cout<<"LL before deleteLast():"<<endl;
    myLinkedList->printList();

    myLinkedList->deleteLast();
    cout<<"\n\nLL after first deleteLast():"<<endl;
    myLinkedList->printList();  

    myLinkedList->deleteLast();
    cout<<"\n\nLL after second deleteLast():"<<endl;
    myLinkedList->printList();  

    myLinkedList->deleteLast();
    cout<<"\n\nLL after third deleteLast():"<<endl;
    myLinkedList->printList();  
        
}
