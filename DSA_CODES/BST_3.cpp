#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
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

  
    void inorderRec(Node* node) {
        if (node) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }

    void preorderRec(Node* node) {
        if (node) {
           cout << node->data << " ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }

    void postorderRec(Node* node) {
        if (node) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->data << " ";
        }
    }

    
    void inorderNonRec() {
        stack<Node*> stack;
        Node* current = root;
        while (!stack.empty() || current != nullptr) {
            if (current != nullptr) {
                stack.push(current);
                current = current->left;
            } else {
                current = stack.top();
                stack.pop();
                cout << current->data << " ";
                current = current->right;
            }
        }
    }

    void preorderNonRec() {
        if (root == nullptr) return;
        stack<Node*> stack;
        stack.push(root);
        while (!stack.empty()) {
            Node* node = stack.top();
            stack.pop();
            cout << node->data << " ";
            if (node->right) stack.push(node->right);
            if (node->left) stack.push(node->left);
        }
    }

    void postorderNonRec() {
        if (root == nullptr) return;
        stack<Node*> stack1, stack2;
        stack1.push(root);
        Node* node;
        while (!stack1.empty()) {
            node = stack1.top();
            stack1.pop();
            stack2.push(node);
            if (node->left) stack1.push(node->left);
            if (node->right) stack1.push(node->right);
        }
        while (!stack2.empty()) {
            node = stack2.top();
            stack2.pop();
           cout << node->data << " ";
        }
    }

   
    Node* buildTreeFromTraversals(int preStart, int inStart, int inEnd, const std::vector<int>& preorder, const std::vector<int>& inorder, std::unordered_map<int, int>& inMap) {
        if (preStart > preorder.size() - 1 || inStart > inEnd) {
            return nullptr;
        }
        Node* root = new Node(preorder[preStart]);
        int inIndex = inMap[root->data];

        root->left = buildTreeFromTraversals(preStart + 1, inStart, inIndex - 1, preorder, inorder, inMap);
        root->right = buildTreeFromTraversals(preStart + 1 + inIndex - inStart, inIndex + 1, inEnd, preorder, inorder, inMap);
        return root;
    }

public:
     Node* root;

    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        clear(root);
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void displayInorder() {
        cout << "Recursive In-order: ";
        inorderRec(root);
        cout << "\nNon-Recursive In-order: ";
        inorderNonRec();
        cout << endl;
    }

    void displayPreorder() {
        cout << "Recursive Pre-order: ";
        preorderRec(root);
        cout << "\nNon-Recursive Pre-order: ";
        preorderNonRec();
        cout << endl;
    }

    void displayPostorder() {
        cout << "Recursive Post-order: ";
        postorderRec(root);
        cout << "\nNon-Recursive Post-order: ";
        postorderNonRec();
        cout << endl;
    }

    void buildTreeFromPreIn(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        root = buildTreeFromTraversals(0, 0, inorder.size() - 1, preorder, inorder, inMap);
    }

private:
    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
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

   
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    BinarySearchTree newBst;
    newBst.buildTreeFromPreIn(preorder, inorder);
    cout << "New tree constructed from preorder and inorder sequences:" << std::endl;
    newBst.displayInorder();
    newBst.displayPreorder();
    newBst.displayPostorder();

    return 0;
}
