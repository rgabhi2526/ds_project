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

    int max(int a, int b) 
    {
        return (a > b) ? a : b; 
    }

    int getHeight(Node* node) 
    {
        if (node == NULL) 
        {
            return 0;
        }
        return node->height;
    }

    int getNum(Node* node) 
    {
        if (node == NULL) 
        {
            return 0;
        }
        return node->data;
    }

    Node *insert(Node *root, Node *child)
    {
        if(root == NULL)
        {
            return child;
        }
        if(child->data > root->data)
        {
            root->right = insert(root->right, child);
        }
        else
        {
            root->left = insert(root->left, child);
        }
        updateHeight(root);
        return root;
    }

public:
    Node* root;

    TangoTree()
    {
        root = NULL;
    } 

    Node* createNode(int data) 
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    void updateHeight(Node* node) 
    {
        if(getHeight(node->left) >getHeight(node->right))
        {
         node->height = 1 + getHeight(node->left);
        }
        else if(getHeight(node->left) <getHeight(node->right))
        {
         node->height = 1 + getHeight(node->right);  
        }
    }

    Node *rightRotate(Node *y)
    {
        Node *head = y->left;
        Node *c_1 = head->right;
        Node *c_2 = head->left;
        y->left = NULL;
        head->left = head->right = NULL;

        if(getHeight(c_1) > getHeight(c_2))
        {
            head = insert(head, c_1);
            if(c_2 == NULL)
                head = insert(head, y);
            else
            {
                if(getNum(c_2) > getNum(y))
                {
                    head = insert(head, c_2);
                    head = insert(head, y);
                }
                else
                {
                    head = insert(head, y); 
                    head = insert(head, c_2);
                }
            }
        }
        else if(getHeight(c_1) == getHeight(c_2))
        {
            head = insert(head, c_1);
            if(getNum(c_2) > getNum(y))
            {
                head = insert(head, c_2);
                head = insert(head, y);
            }
            else
            {
                head = insert(head, y); 
                head = insert(head, c_2);
            }
        }
        else
        {
            head = insert(head, c_2);
            if(c_1 == NULL)
                head = insert(head, y);
            else
            {
                if(getNum(c_1) > getNum(y))
                {
                    head = insert(head, c_1);
                    head = insert(head, y);
                }
                else
                {
                    head = insert(head, y); 
                    head = insert(head, c_1);
                }
            }
        }
        return head;
    }

    Node *leftRotate(Node *x)
    {
        Node *head = x->right;
        Node *c_1 = head->left;
        Node *c_2 = head->right;
        x->right = NULL;
        head->left = head->right = NULL;

        if(getHeight(c_1) > getHeight(c_2))
        {
            head = insert(head, c_1);
            if(c_2 == NULL)
                head = insert(head, x);
            else
            {
                if(getNum(c_2) > getNum(x))
                {
                    head = insert(head, c_2);
                    head = insert(head, x);
                }
                else
                {
                    head = insert(head, x); 
                    head = insert(head, c_2);
                }
            }
        }
        else if(getHeight(c_1) == getHeight(c_2))
        {
            head = insert(head, c_1);
            if(getNum(c_2) > getNum(x))
            {
                head = insert(head, c_2);
                head = insert(head, x);
            }
            else
            {
                head = insert(head, x); 
                head = insert(head, c_2);
            }
        }
        else
        {
            head = insert(head, c_2);
            if(c_1 == NULL)
                head = insert(head, x);
            else
            {
                if(getNum(c_1) > getNum(x))
                {
                    head = insert(head, c_1);
                    head = insert(head, x);
                }
                else
                {
                    head = insert(head, x); 
                    head = insert(head, c_1);
                }
            }
        }
        return head;
    }

    Node *balance(Node *head)
    {
        if(head == NULL)
            return head;
        else
        {
            balance(head->left);
            balance(head->right);
            int balanceFactor = getHeight(head->left) - getHeight(head->right);
            if (balanceFactor > 1) 
            {
                return rightRotate(head);
            } 
            else if (balanceFactor < -1) 
            {
                return leftRotate(head);
            }
        }
        return head;
    }

    Node* insertNode(Node* node, int data) 
    {
        if (node == NULL) 
        {
            return createNode(data);
        }
        if (data < node->data) 
        {
            node->left = insertNode(node->left, data);
        } 
        else if (data > node->data) 
        {
            node->right = insertNode(node->right, data);
        } 

        updateHeight(node);
        node = balance(node);
        return node;
    }
};



