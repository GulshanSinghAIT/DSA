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
    
    Node* root;
    
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

  
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

  
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) return node;

       
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        }
      
        else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        }
       
        else {
          
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

          
            Node* temp = minValueNode(node->right);
            node->data = temp->data;

            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

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

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }
};

int main() {
    BinarySearchTree bst;

    
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

   
    bst.displayInorder();
    bst.displayPreorder();
    bst.displayPostorder();

   
    bst.deleteNode(20);
    cout << "After deleting node 20:" << endl;
    bst.displayInorder();

  
    bst.deleteNode(30);
    cout << "After deleting node 30:" << endl;
    bst.displayInorder();

    return 0;
}
