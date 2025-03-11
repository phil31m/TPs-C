#include <iostream>

using namespace std;

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, int val) {
        if (node == nullptr) return new Node(val);
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        return node;
    }

    Node* search(Node* node, int val) {
        if (node == nullptr || node->data == val) return node;
        if (val < node->data) return search(node->left, val);
        else return search(node->right, val);
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* deleteNode(Node* node, int val) {
        if (node == nullptr) return node;
        if (val < node->data) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->data) {
            node->right = deleteNode(node->right, val);
        } else {
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

    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        clear(root);
    }

    void insert(int val) {
        root = insert(root, val);
    }

    bool search(int val) {
        return search(root, val) != nullptr;
    }

    void deleteNode(int val) {
        root = deleteNode(root, val);
    }

    void inOrder() {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    cout << "Insertion des éléments : 5 3 7 2 4 6 8" << endl;
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    for (int val : values) {
        bst.insert(val);
    }
    cout << "Parcours infixe :" << endl;
    bst.inOrder();

    cout << "Recherche de 4 : " << (bst.search(4) ? "Trouvé" : "Non trouvé") << endl;

    cout << "Suppression de 4" << endl;
    bst.deleteNode(4);
    cout << "Parcours infixe après suppression :" << endl;
    bst.inOrder();

    return 0;
}