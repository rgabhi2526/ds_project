// Program to implement Unrolled Linked List
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

class ULL{
    private:
        struct node{
            int noe;//number of elements 
            int arr[SIZE];
            struct node* next;
            node(){
                noe = -1;
            }
        };
    public:
        node* head;
        int threshold = ((SIZE/2) + 1);
        ULL(){
            head = NULL;
        }
        void insert(int);
        void display();
};


int main(){
    ULL L1;
    int choice;
    int num;
    while(1){
        printf("\nEnter any key to proceed.\n");
        getchar();
        getchar();
        system("clear");
        printf("\nEnter \n1. Insert\n2. Delete\n3. Search");
        printf("\n4. Display\n5. Exit");
        printf("\n Enter a choice:");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter the number to be inserted: ");
                scanf("%d", &num);
                L1.insert(num);
                printf("Insertion Successful");
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                L1.display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nError! Enter the valid Choice.\n");
                break;
                 
        }
    }
}


// Method for Inserting in Unrolled Linked List
void ULL::insert(int num){
    if(head == NULL){
        struct node* newnode = new node;
        newnode->next = NULL;
        head = newnode;
        head->noe++;
        newnode->arr[head->noe] = num;
    }
    else{
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        if(temp->noe == SIZE-1){
            struct node* newnode = new node;
            newnode->next = NULL;
            temp->next = newnode;
            int n = threshold;
            while(n != SIZE){
                newnode->noe++;
                newnode->arr[newnode->noe] = temp->arr[n];
                n++;
            }
            temp->noe = threshold-1;
            newnode->noe++;
            newnode->arr[newnode->noe] = num;
        }
        else{
            temp->noe++;
            temp->arr[temp->noe] = num;
        }
    }
}


// Method for Displaying in Unrolled Linked List
void ULL::display(){
    struct node* temp = head;
    // For Displaying the nodes
    while(temp != NULL){
        // For Displaying the Array inside the Node
        for(int i=0; i<=temp->noe; i++){
            printf("%d\t",temp->arr[i]);
        }
        printf("\n");
        temp = temp->next;
    }
}









