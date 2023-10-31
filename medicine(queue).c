#include<stdio.h>
#include<stdlib.h>
struct med{
    char medi[10];
    struct med *next;
};
typedef struct med med;
med *top=NULL;
int main()
{
    int ch;

    do {
        printf("\nChoose an operation:\n");
        printf("1. Insert a new medicine\n");
        printf("2. Delete a medicine\n");
        printf("3. Display all medicines\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                displaystack();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (ch != 4);

}
void push()
{
    med *newmed;
    newmed=(med*) malloc(sizeof(med));

    printf("Enter the name of the medicine: ");
    scanf("%s", &newmed->medi);

    newmed->next=top;
    top=newmed;
}
void pop()
{
    med *temp;
    temp=top;

    if(top==NULL){
        printf("\nNo medicine to remove\n");
    }
    else{
        printf("\n%s is removed\n", temp->medi);
        top=top->next;
        free(temp);
    }
}
void displaystack()
{
    med *temp;
    temp=top;

    if(top==NULL){
        printf("There is no medicine in the storage");
    }
    else{
        while(temp!=NULL){
            printf("%s\n", temp->medi);
            temp=temp->next;
        }
    }
}
