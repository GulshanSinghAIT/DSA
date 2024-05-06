#include <iostream>
using namespace std;

struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data=val;
            left=nullptr;
            right=nullptr;
        }
};

class BinarySearchTree {
private:
    
   

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    int height(Node* node) {
        if (node == nullptr) {
            return -1;  
        }
        return 1 +max(height(node->left), height(node->right));
    }

    void mirror(Node* node) {
        if (node == nullptr) {
            return;
        }
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }

public:
    Node* root;
    BinarySearchTree()  {
        root=nullptr;
    }


    void insert(int value) {
        root = insert(root, value);
    }

    void displayInorder() {
        cout << "In-order traversal: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        cout << "Pre-order traversal: ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        cout << "Post-order traversal: ";
        postorder(root);
        cout << endl;
    }

    void displayHeight() {
        cout << "Height of the tree: " << height(root) << endl;
    }

    void createMirrorImage() {
        mirror(root);
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

   
    bst.displayInorder();
    bst.displayPreorder();
    bst.displayPostorder();

   
    bst.displayHeight();

 
    bst.createMirrorImage();
    cout << "Traversals after mirroring:" << endl;
    bst.displayInorder();
    bst.displayPreorder();
    bst.displayPostorder();

    return 0;
}
