#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
        int data;
        Node *left;
        Node *right;
        int height;

        Node(int value) {
        data=value;
        left=nullptr;
        right=nullptr;
        height=1;
    }
};
class AVLTree {
private:
    int height(Node *N) {
        if (N == nullptr)
            return 0;
        return N->height;
    }

  
    Node* rightRotate(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;

       
        x->right = y;
        y->left = T2;

     
        y->height =max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

      
        return x;
    }

  
    Node* leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;

     
        y->left = x;
        x->right = T2;

    
        x->height =max(height(x->left), height(x->right)) + 1;
        y->height =max(height(y->left), height(y->right)) + 1;

    
        return y;
    }

    
    int getBalance(Node *N) {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }

   
    Node* insert(Node* node, int key) {
       
        if (node == nullptr)
            return  new Node(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else 
            return node;

       
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        

        // Left Left Case==right rotate
        if (balance > 1 && key < node->left->data)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->data)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

      
        return node;
    }

   
    void levelOrder(Node* root) {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            cout << node->data<< " ";
            q.pop();
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
    }

public:
     Node* root;
    AVLTree(){
        root=nullptr;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void displayLevelOrder() {
        cout << "Level order traversal: ";
        levelOrder(root);
       cout <<endl;
    }

    void printHeight() {
        cout << "Height of AVL tree: " << height(root) << endl;
    }
};

int main() {
    AVLTree tree;
    
   
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    
   
    tree.displayLevelOrder();

  
    tree.printHeight();

    return 0;
}
