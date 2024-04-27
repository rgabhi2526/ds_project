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
        void search(int);
        void deleteelement(int);
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
                printf("Enter the number to get deleted:");
                scanf("%d",&num);
                L1.deleteelement(num);
                break;
            case 3:
                printf("enter the number to search :");
                scanf("%d",&num);
                L1.search(num);
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


// Method for Displaying the Unrolled Linked List
void ULL::display(){
    struct node* temp = head;
    // For Traversing through the nodes
    while(temp != NULL){
        // For Traversing inside the Array in the Node
        for(int i=0; i<=temp->noe; i++){
            printf("%d\t",temp->arr[i]);
        }
        printf("\n");
        temp = temp->next;
    }
}


// Method to Search for a Number in Unrolled Linked List
void ULL::search(int num){
    int count;
    struct node* temp = head;
    // For Traversing through the nodes
    while(temp != NULL){
        // For Traversing inside the Array in the Node
        for(int i=0; i<=temp->noe; i++){
           if( num==temp->arr[i]){
               count++;
           }
        }
        temp = temp->next;
    }
    if(count==0){
        printf("\nNumber wasn't found !!");
    }
    else{
        printf("\n Number found !!");
    }
}



// Method for Deleting from Unrolled Linked List
void ULL::deleteelement(int num){
    if(head == NULL){
        printf("List is empty,So Cannot delete.\n");
        return;
    }
    struct node* temp = head;
    while(temp != NULL){
        int i;
        for(i = 0; i <= temp->noe; i++){
            if(temp->arr[i] == num){
                break;
            }
        }
        if(i <= temp->noe){
            for(int j = i; j < temp->noe; j++){
                temp->arr[j] = temp->arr[j + 1];
            }

            temp->noe--;

            if(temp->noe == -1){
                if(temp == head){
                    head = temp->next;
                    delete temp;
                    temp = head;
                }
                else{
                    struct node* prev = head;
                    while(prev->next != temp){
                        prev = prev->next;
                    }
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                }
            }
            printf("###Deletion successful###.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Number is not in the list,check again.\n");
}





