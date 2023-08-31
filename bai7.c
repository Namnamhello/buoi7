#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
struct contact{
    char name[50];
    char phone[50];
    char address[50];
};


void SaveContact(FILE *file,struct contact contact[], int x){
    fprintf(file,"contact: %d \n",x);
    fprintf(file,"Name: %s\n",contact[x].name);
    fprintf(file,"Phone: %s\n",contact[x].phone);
    fprintf(file,"Address: %s\n",contact[x].address);
    fprintf(file,"\n");
}

void AddContact(FILE *file,struct contact n_contact[],int x){
    printf("Enter name: ");

    gets(n_contact[x].name);
    printf("Enter phone number: ");
    gets(n_contact[x].phone);
    printf("Enter address: ");
    gets(n_contact[x].address);
    printf("\nContact added successfully! \n");
    SaveContact(file,n_contact,x);
    x++;
    // fprintf(file,"contact: %d \n",x);
    // fprintf(file,"Name: %s\n",n_contact[x].name);
    // fprintf(file,"Phone: %s\n",n_contact[x].phone);
    // fprintf(file,"Address: %s\n",n_contact[x].address);
}

void DisplayContact(struct contact contact[], int x){
    printf("List of all contacts: \n");	
    for (int i=1;i<x;i++){       
        printf("contact: %d \n",i);
        printf("Name: %s\n",contact[i].name);
        printf("Phone: %s\n",contact[i].phone);
        printf("Address: %s\n",contact[i].address);
        printf("\n");
    }
}
void SeachContact(struct contact contact[], int x){
    char s[100];
    printf("Enter name to seach for: ");
    gets(s);
    for (int i=1;i<=x;i++){
        if (strcmp(s,contact[i].name)==0){
            printf("Contac found: \n");
            printf("Name: %s\n",contact[i].name);
            printf("Phone: %s\n",contact[i].phone);
            printf("Address: %s\n",contact[i].address);
            printf("\n");
        }

    }
}

int main(){
    FILE *file = fopen("example.txt","w");
    bool check=true;
    int x=1;
    struct contact n[1000];

    printf("Welcome to the Contact Manager! \n"
    "1. Add a new contact\n"
    "2. Display all contacts\n"
    "3. Search for a contact\n"
    "4. Exit\n");

    while (check){
        int t;
        printf("Enter your choice: ");
        scanf("%d",&t);
        getchar();
        switch (t) {
            case 1:AddContact(file,n,x);x++;break;
            case 2:DisplayContact(n,x);break;
            case 3:SeachContact(n,x);break;
            case 4: check=false;break;
            default:printf("Invalid choice!\n");exit(0);
        }
    }
    printf("Goodbye!");
    
    return 0;
}