#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


class BinarySearchTree {

private:
    Node* insertRec(Node* node, int key) {
        if (node == nullptr)
            return new Node(key);
        if (key < node->data)
            node->left = insertRec(node->left, key);
        else if (key > node->data)
            node->right = insertRec(node->right, key);
        return node;
    }

   
    void inorderRec(Node* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }

    void preorderRec(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }

    void postorderRec(Node* node) {
        if (node != nullptr) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->data << " ";
        }
    }
   
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

 
    void insert(int key) {
        root= insertRec(root, key);
    }

  
    void inorder() {
        cout << "In-order traversal: ";
        inorderRec(root);
        cout << endl;
    }

  
    void preorder() {
        cout << "Pre-order traversal: ";
        preorderRec(root);
        cout << endl;
    }

  
    void postorder() {
        cout << "Post-order traversal: ";
        postorderRec(root);
        cout << endl;
    }

  
    Node* clone(Node* node) {
        if (node == nullptr)
            return nullptr;
        Node* newNode = new Node(node->data);
        newNode->left = clone(node->left);
        newNode->right = clone(node->right);
        return newNode;
    }

    
    void clear(Node* &node) {
        if (node == nullptr)
            return;
        clear(node->left);
        clear(node->right);
        delete node;
        node = nullptr;
    }

};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);


    bst.inorder();
    bst.preorder();
    bst.postorder();

 
    BinarySearchTree clonedTree;
    clonedTree.root = bst.clone(bst.root);

    cout << "Cloned Tree Traversals:" << endl;
    clonedTree.inorder();
    clonedTree.preorder();
    clonedTree.postorder();

  
    bst.clear(bst.root);
    cout << "Original tree cleared." << endl;

 
    bst.inorder();
    bst.preorder();
    bst.postorder();

    return 0;
}
