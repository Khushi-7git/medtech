#include<stdio.h>
#include<stdlib.h>
#define MAX_MEDICINES 100
#define MAX_NAME_LEN 100
#define MAX_DATE_LEN 100
typedef struct 
{
    char name[MAX_NAME_LEN];
    int quantity;
    char expirydate[MAX_DATE_LEN];
}medicine;
medicine inventory[100];
medicine med;
void addmedicine(int n) { // n takes number of entities I want to insert
    for (int i = 0; i < n; i++) {
        int *name=(int*)malloc(n*sizeof(int));
        printf("Medicine name: ");
        getchar(); 
        scanf("%[^\n]%*c", inventory[i].name); // This reads the whole line of input for name
        printf("Quantity: ");
        scanf("%d", &inventory[i].quantity);
        printf("Expiry date: ");
        getchar(); 
        scanf("%[^\n]%*c", inventory[i].expirydate); 
    }
}
void display(int n){
    for int i = 0; i < n; i++) {
        printf("Medicine %d\n", i + 1);
        printf("Name: %s\n", inventory[i].name);
        printf("quantity: %d\n", inventory[i].quantity);
        printf("expiry date: %s\n", inventory[i].expirydate);
}
printf("--------------------------\n");
}
int main(){
    int choice,n;
    int opt;
    printf(" welcome to your medicmange\n");
    printf("1.Medicine and Equipment Inventory Management\n ");
    printf("2.Manage patient\n");
    printf("3.Medicine Expiration alert\n");
    printf("4.serch medicine\n");
    printf("5.Track medicine stock\n.");
    printf(" enter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1: 
            printf(".Medicine and Equipment Inventory Management\n");
            printf("1.add medicine\n");
            printf("2.remove medicine\n");
            printf("3.update medicine\n");
            printf("enter your choice:");
            scanf("%d",&opt);
            if(opt==1){
                printf(" enter number of entity:");
                scanf("%d",&n);
                addmedicine(n) ;      
                display(n) ;    
            }
            else {
                printf("Option not implemented yet.\n");
            }
            break;

        

        }
  
    }
   
