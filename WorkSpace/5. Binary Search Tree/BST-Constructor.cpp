#include <iostream>

using namespace std;


	class Node {
        public:
            int value;
            Node* left;
            Node* right;
            
            Node(int value) {
                this->value = value;
                left = nullptr;
                left = nullptr;
            }
    };


class BinarySearchTree {
    public:
		Node* root;

    public:
        BinarySearchTree() {
            root = nullptr;
        }

        //<==This is an alternative way and correct but the Other way is preferable==>
		// BinarySearchTree(int value) {
        //     Node* newNode = new Node(value);
        //     root = newNode;
        // }
		


        // ---------------------------------------------------
        //  Below is a helper function used by the destructor
        //  Deletes all nodes in BST
        //  Similar to DFS PostOrder in Tree Traversal section
        // ---------------------------------------------------
        void destroy(Node* currentNode) {
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }

        ~BinarySearchTree() { destroy(root); }
        
};



int main() {
        
    BinarySearchTree* myBST = new BinarySearchTree();

    // ROOT MUST BE PUBLIC FOR THIS LINE TO WORK:
    cout << "Root: " << myBST->root;

    /*
        EXPECTED OUTPUT:
        ----------------
        Root: 0x0

    */

}

