#include<stdio.h>
#include<stdlib.h>
struct patient{
    int unqid;
    char name[10];
    int age;
    char bldgrp[5];
    char mono[11];

    struct patient *next;
};
typedef struct patient ptnt;
ptnt *head,*temp;
int main()
{
    int n,choice;
    printf("Enter the number of patients: ");
    scanf("%d", &n);

    head=(ptnt*) malloc(sizeof(ptnt));
    printf("Enter the Unique ID for patient 1: ");
    scanf("%d", &head->unqid);
    printf("Enter the name of the patient 1: ");
    scanf("%s", &head->name);
    printf("Enter the age of the patient 1: ");
    scanf("%d", &head->age);
    printf("Enter the blood group of the patient 1: ");
    scanf("%s", &head->bldgrp);
    printf("Enter the mobile number of the patient 1: ");
    scanf("%s", &head->mono);

    head->next=NULL;

    createnode(n);
    display();

    do {
        printf("\nChoose an operation:\n");
        printf("1. Insert a new patient\n");
        printf("2. Delete a patient\n");
        printf("3. Total number of registered patient\n");
        printf("4. Search for a patient\n");
        printf("5. Display all patients\n");
        printf("6. Enter the Serial of patients\n");
        printf("7. Add or Remove Medicines from the storage\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(n);
                display();
                break;
            case 2:
                dlt(n);
                display();
                break;
            case 3:
                printf("\nTotal Number of patients is: %d\n", countNodes());
                break;
            case 4:
                srch();
                break;
            case 5:
                display();
                break;
            case 6:
                serial();
                break;
            case 7:
                medicine();
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 8);
}
void createnode(int n){
    ptnt *newptnt;
    temp=head;

    for(int i=2; i<=n; i++){
        newptnt=(ptnt*) malloc(sizeof(ptnt));
        printf("Enter the Unique ID for patient %d: ",i);
        scanf("%d", &newptnt->unqid);
        printf("Enter the name of the patient %d: ",i);
        scanf("%s", &newptnt->name);
        printf("Enter the age of the patient %d: ",i);
        scanf("%d", &newptnt->age);
        printf("Enter the blood group of the patient %d: ",i);
        scanf("%s", &newptnt->bldgrp);
        printf("Enter the mobile number of the patient %d: ",i);
        scanf("%s", &newptnt->mono);

        newptnt->next=NULL;
        temp->next=newptnt;
        temp=temp->next;
    }
}
void display(){
    temp=head;
    while(temp!=NULL){
        printf("ID: %d    Name: %s        Age: %d    BloodGroup: %s    Mobile No: %s\n",temp->unqid,temp->name,temp->age,temp->bldgrp,temp->mono);
        temp=temp->next;
    }
}
int countNodes() {
    int count = 0;
    temp=head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
void insert_beg(){
    ptnt *newptnt;
    temp=head;

    newptnt=(ptnt*) malloc(sizeof(ptnt));
    printf("Enter the Unique ID for new patient: ");
    scanf("%d", &newptnt->unqid);
    printf("Enter the name of the new patient:");
    scanf("%s", &newptnt->name);
    printf("Enter the age of the new patient: ");
    scanf("%d", &newptnt->age);
    printf("Enter the blood group of the new patient: ");
    scanf("%s", &newptnt->bldgrp);
    printf("Enter the mobile number of the new patient: ");
    scanf("%s", &newptnt->mono);

    newptnt->next=temp;
    head=newptnt;
}
void insert_end(){
    ptnt *newptnt;
    temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    newptnt=(ptnt*) malloc(sizeof(ptnt));
    printf("Enter the Unique ID for new patient: ");
    scanf("%d", &newptnt->unqid);
    printf("Enter the name of the new patient:");
    scanf("%s", &newptnt->name);
    printf("Enter the age of the new patient: ");
    scanf("%d", &newptnt->age);
    printf("Enter the blood group of the new patient: ");
    scanf("%s", &newptnt->bldgrp);
    printf("Enter the mobile number of the new patient: ");
    scanf("%s", &newptnt->mono);

    temp->next=newptnt;
    newptnt->next=NULL;
}
void insert(int n){
    n=countNodes();
    int pos;
    printf("Enter the position you want to insert: ");
    scanf("%d", &pos);

    if(pos==1){
        insert_beg();
    }
    else if(pos==n+1){
        insert_end();
    }
    else{
        ptnt *prev,*current,*newptnt;
        temp=head;

        newptnt=(ptnt*) malloc(sizeof(ptnt));
        printf("Enter the Unique ID for new patient: ");
        scanf("%d", &newptnt->unqid);
        printf("Enter the name of the new patient:");
        scanf("%s", &newptnt->name);
        printf("Enter the age of the new patient: ");
        scanf("%d", &newptnt->age);
        printf("Enter the blood group of the new patient: ");
        scanf("%s", &newptnt->bldgrp);
        printf("Enter the mobile number of the new patient: ");
        scanf("%s", &newptnt->mono);

        for(int i=1; i<pos; i++){
            prev=temp;
            current=temp->next;
            temp=temp->next;
        }

        prev->next=newptnt;
        newptnt->next=current;
    }
}
void dlt_beg(){
    temp=head;

    head=temp->next;
    free(temp);
}
void dlt_end(){
    temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }

    free(temp->next);
    temp->next=NULL;
}
void dlt(int n){
    n=countNodes();
    int src,flag=0,pos=0;
    temp=head;
    printf("Enter the Unique ID you want to delete: ");
    scanf("%d", &src);

    while(temp!=NULL){
        pos++;
        if(temp->unqid==src){
            flag=0;
            break;
        }
        else{
            flag++;
        }
        temp=temp->next;
    }

    if(flag!=0){
        printf("\nPatient Not Found\n");
    }

    else{
        if(pos==1){
            dlt_beg();
        }
        else if(pos==n){
            dlt_end();
        }
        else{
            ptnt *prev,*current;
            temp=head;
            for(int i=1; i<pos; i++){
                prev=temp;
                current=temp->next;
                temp=temp->next;
            }
            prev->next=current->next;
            free(current);
        }
    }
}
void srch(){
    temp=head;

    int src,flag=0;
    printf("\nEnter the Unique ID you want to search: ");
    scanf("%d", &src);

    while(temp!=NULL){
        if(temp->unqid==src){
            flag=0;
            break;
        }
        else{
            flag++;
        }
        temp=temp->next;
    }

    if(flag==0){
        printf("%d    %s        %d    %s    %s\n",temp->unqid,temp->name,temp->age,temp->bldgrp,temp->mono);
    }
    else{
        printf("\nPatient Not Found\n");
    }
}




int serial()
{
    int ch;

    do {
        printf("\nChoose an operation:\n");
        printf("1. Insert a new patient\n");
        printf("2. Delete a patient\n");
        printf("3. Display all patients\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayqueue();
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
ptnt *front=NULL, *rear=NULL;
void enqueue()
{
    ptnt *newptnt;
    newptnt = (ptnt*)malloc(sizeof(ptnt));


    temp=head;

    int src,flag=0;
    printf("\nEnter the Unique ID of the patient you want to Add in the queue: ");
    scanf("%d", &src);

    while(temp!=NULL){
        if(temp->unqid==src){
            flag=0;
            break;
        }
        else{
            flag++;
        }
        temp=temp->next;
    }

    if(flag==0){
        newptnt->unqid=temp->unqid;
        strcpy(newptnt->name, temp->name);

        if (rear == NULL) {
            printf("\nPatient Added\n");
            front = rear = newptnt;
        }
        else {
            printf("\nPatient Added\n");
            rear->next = newptnt;
            rear = newptnt;
        }
    }
    else{
        printf("\nPatient Not Found\n");
    }
}

void dequeue()
{
    ptnt *newptnt;
    if(front==NULL){
        printf("\nNo Patient Here\n");
    }
    else{
        printf("\nPatient Removed\n");
        newptnt=front;
        front=front->next;
        free(newptnt);
    }
}
void displayqueue()
{
    ptnt *current = front;

    if (current == NULL) {
        printf("\nThere are no patients in the queue.\n");
    }
    else {
        printf("\nPatients in the queue:\n");
        while (current != NULL) {
            printf("Unique ID: %d, Name: %s --> ", current->unqid, current->name);
            current = current->next;
        }
        printf("\n");
    }
}


struct med{
    char medi[10];
    struct med *next;
};
typedef struct med med;
med *top=NULL;
void medicine()
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

    printf("\nEnter the name of the medicine: ");
    scanf("%s", &newmed->medi);

    newmed->next=top;
    top=newmed;
}
void pop()
{
    med *temp;
    temp=top;

    if(top==NULL){
        printf("\nThere is no medicine in storage\n");
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
        printf("\nThere is no medicine in the storage\n");
    }
    else{
        while(temp!=NULL){
            printf("%s\n", temp->medi);
            temp=temp->next;
        }
    }
}
