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

    Node *insert(Node *temp, Node *child)
    {
        if(temp == NULL)
        {
            return child;
        }
        if(child->data > temp->data)
        {
            temp->right = insert(temp->right, child);
        }
        else
        {
            temp->left = insert(temp->left, child);
        }
        updateHeight(temp);
        temp=balance(temp);
        return temp;
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
        if(getHeight(node->left) > getHeight(node->right))
        {
            node->height = 1 + getHeight(node->left);
        }
        else if(getHeight(node->left) < getHeight(node->right))
        {
            node->height = 1 + getHeight(node->right);  
        }
    }

    Node *rightRotate(Node *y)
    {
        printf("r");
        Node *head = y->left;
        Node *c_1 = head->right;
        Node *c_2 = head->left;
        y->left = NULL;
        y->height=getHeight(y->right)+1;
        head->left = head->right = NULL;
        head->height=1;
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
        printf("l");
        Node *head = x->right;
        Node *c_1 = head->left;
        Node *c_2 = head->right;
        x->right = NULL;
        x->height=getHeight(x->left)+1;
        head->left = head->right = NULL;
        head->height=1;

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
            if(c_1 == NULL)//balance function needs to be introduced
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

    Node* minValueNode(Node* node)
    {
        Node* current = node;
        while (current && current->left != NULL)
        {
            current = current->left;
        }
        return current;
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

    void callins(int num)
    {
        root = insertNode(root, num);
    }

    void display(struct Node* root)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            display(root->left);
            printf("%d||",root->data);
            display(root->right);
        }
    }

    void calldisp()
    {
        display(root);
        printf("\n");
    }

    int callsearch(int num)
    {
        return search(root, num);
    }

    int search(struct Node* root, int key)
    {
        if(root == NULL)
        {
            return 0;
        }
        else if( root->data == key)
        {
            return 1;
        }
        else if( key < root->data)
            return search(root->left, key);
        else
        {
            return search(root->right, key);
        }
    }

    Node* deleteNode(Node* root, int data) 
    {
        if (root == NULL)
        {
            return root;
        }

        if (data < root->data)
        {
            root->left = deleteNode(root->left, data);
        }
        else if(data > root->data)
        {
            root->right = deleteNode(root->right, data);
        }
        else 
        {
            if( (root->left == NULL) || (root->right == NULL) ) 
            {
                Node* temp = root->left ? root->left : root->right;

                if(temp == NULL) 
                {
                    temp = root;
                    root = NULL;
                }
                else
                {
                    *root = *temp;
                }

                free(temp);
            }
            else 
            {
                Node* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (root == NULL)
        {
            return root;
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balanceFactor = getHeight(root->left) - getHeight(root->right);

        if (balanceFactor > 1 && getHeight(root->left->left) >= getHeight(root->left->right))
        {
            return rightRotate(root);
        }

        if (balanceFactor > 1 && getHeight(root->left->right) > getHeight(root->left->left)) 
        {
            root->left =  leftRotate(root->left);
            return rightRotate(root);
        }

        if (balanceFactor < -1 && getHeight(root->right->right) >= getHeight(root->right->left))
        {
            return leftRotate(root);
        }

        if (balanceFactor < -1 && getHeight(root->right->left) > getHeight(root->right->right)) 
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    int calldel(int num)
    {
        root = deleteNode(root, num);
        if (root == NULL)
        {
            return 0; 
        }
        return 1; 
    } 
};



int main()
{
    TangoTree t1;
    int choice, num;
    while(1)
    {
        printf("\nEnter any key to proceed.\n");
        getchar();
        getchar();
        system("clear");
        printf("Enter \n1. Insert \n2. Delete\n3. Display");
        printf("\n4. Search\n5. Exit");
        printf("\n Enter a choice:");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the number to be inserted: ");
                scanf("%d", &num);
                t1.callins(num);
                printf("Insertion Successful");
                break;
            case 2:
                printf("Enter the number to be deleted: ");
                scanf("%d",&num);
                if(t1.calldel(num))
                {
                    printf("Deletion successful");
                }
                else
                {
                    printf("Deletion failed");
                }
                break;
            case 3:
                t1.calldisp();
                break;
            case 4:
                printf("Enter the number to be searched for: ");
                scanf("%d", &num);
                if(t1.callsearch(num) == 1){
                    printf("Number Found !!\n");
                }
                else{
                    printf("Number not Found !!\n");
                }
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Enter the Valid Choice !\n");
                break;
        }
    }
}
