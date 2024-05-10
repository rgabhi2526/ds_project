#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

class ULL{
    private:
        struct node{
            int noe=-1;//number of elements 
            int arr[SIZE];
            struct node* next;
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
            
                while (scanf("%d", &num) != 1) {
                    printf("Invalid input. Please enter an integer: ");
                    while (getchar() != '\n'); 
                }
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
    if(temp==NULL){
        printf("\nNothing to display||List is Empty");
    }
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
    int count = 0;
    struct node* temp = head;

    // Check if the list is empty
    if (temp == NULL){
        printf("List is Empty!! Nothing to search.\n");
        return;
    }

    // Traverse through the nodes
    while(temp != NULL){
        // Traverse inside the Array in the Node
        for(int i = 0; i <= temp->noe; i++){
            if(num == temp->arr[i]){
                printf("\nNumber found !!");
                return;  // Exit function early since number is found
            }
        }
        temp = temp->next;
    }

    // If reached here, number was not found
    printf("\nNumber wasn't found !!");
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
