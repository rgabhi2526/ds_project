#include <stdio.h>
#include <stdlib.h>

class TangoTree 
{
    struct Node 
    {
        int data;
        Node* left;
        Node* right;
        int height;
    };
public:
    Node* root;
    TangoTree()
    {
     root = NULL;
    }
    
// creating newnode and inserting data into the new node
    Node* createNode(int data) 
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    int getHeight(Node* node) 
    {
        if (node == NULL) {
            return 0;
        }
        return node->height;
    }

    void updateHeight(Node* node) 
    {
        if(getHeight(node->left) >= getHeight(node->left))
        {
         node->height = 1 + getHeight(node->left);
        }
        else
        {
         node->height = 1 + getHeight(node->right);  
        }
    }

    Node* leftRotate(Node* z) {
        Node* y = z->right;
        Node* T2 = y->left;
        y->left = z;
        z->right = T2;
        updateHeight(z);
        updateHeight(y);
        return y;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Node* insertNode(Node* node, int data) 
    {
        if (node == NULL) {
            return createNode(data);
        }
        if (data < node->data) {
            node->left = insertNode(node->left, data);
        } else if (data > node->data) {
            node->right = insertNode(node->right, data);
        } 

        updateHeight(node);
        int balanceFactor = getHeight(node->left) - getHeight(node->right);
        if (balanceFactor > 1) 
        {
            if (data < node->left->data) 
            {
                return rightRotate(node);
            }
            else 
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        } 
        else if (balanceFactor < -1) 
        {
            if (data > node->right->data) 
            {
                return leftRotate(node);
            } 
            else 
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }
        return node;
    }

    Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if(data > root->data)
        root->right = deleteNode(root->right, data);

    else {
        if( (root->left == NULL) || (root->right == NULL) ) {
            Node* temp = root->left ? root->left : root->right;

            if(temp == NULL) {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balanceFactor = getHeight(root->left) - getHeight(root->right);

    if (balanceFactor > 1 && getHeight(root->left->left) >= getHeight(root->left->right))
        return rightRotate(root);

    if (balanceFactor > 1 && getHeight(root->left->right) > getHeight(root->left->left)) {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    if (balanceFactor < -1 && getHeight(root->right->right) >= getHeight(root->right->left))
        return leftRotate(root);

    if (balanceFactor < -1 && getHeight(root->right->left) > getHeight(root->right->right)) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
};

int max(int a, int b) {
    return (a > b)? a : b;
}

int main() {
    TangoTree tree;
    tree.root = tree.insertNode(tree.root, 10);
    tree.root = tree.insertNode(tree.root, 20);
    tree.root = tree.insertNode(tree.root, 5);
    tree.root = tree.insertNode(tree.root, 15);


    tree.root = tree.deleteNode(tree.root, 15);
    return 0;
}
