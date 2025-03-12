#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_MEDICINES 100
#define MAX_NAME_LEN 100
#define MAX_DATE_LEN 100
typedef struct 
{
    char name[MAX_NAME_LEN];
    int quantity;
    char manufacturedate[MAX_NAME_LEN];
    char expirydate[MAX_DATE_LEN];
}medicine;
medicine inventory[100];
medicine med;
int current_size = 0;
void addmedicine(int n) { // n takes number of entities I want to insert
    for (int i = 0; i < n; i++) {
        if (current_size >= MAX_MEDICINES) {
            printf("Inventory full, cannot add more medicines.\n");
            break;
        }
        printf("Medicine name: ");
        getchar(); 
        scanf("%[^\n]%*c", inventory[i].name); // This reads the whole line of input for name
        printf("Quantity: ");
        scanf("%d", &inventory[i].quantity);
        printf("manufacture name:");
        getchar();
        scanf("%[^\n]%*c", inventory[i].manufacturedate); 
        printf("Expiry date: ");
        getchar(); 
        scanf("%[^\n]%*c", inventory[i].expirydate); 
        current_size++; 
    }
}
void display(int n){
    if(current_size==0){
        printf("no medicine in inventory");
    }
    for(int i = 0; i < current_size; i++) {
        printf("Medicine %d\n", i + 1);
        printf("Name: %s\n", inventory[i].name);
        printf("quantity: %d\n", inventory[i].quantity);
        printf("manufacturedate: %s\n", inventory[i].manufacturedate);
        printf("expiry date: %s\n", inventory[i].expirydate);
}
printf("--------------------------\n");
}
void removemed(char name ){
    int found=0;
    for(int i=0;i<current_size;i++){
        if (strcmp(inventory[i].name, name) == 0){
            found=1;
            for (int j = i; j < current_size- 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            current_size--; // Reduce size
            printf("Medicine %s deleted.\n", name);
            break;
        }
    if(found==0){
        printf(" medicine not found ");
    }   
    }
    

        }
int main(){
    int choice,n;
    int choice;
    char name[MAX_NAME_LEN]; 
    printf(" welcome to your medicmange\n");
    printf("----------------------------------------------------------------------\n");
    printf("1.Medicine and Equipment Inventory Management\n ");
    printf("2.Manage patient\n");
    printf("3.Medicine Expiration alert\n");
    printf("4.serch medicine\n");
    printf("5.Track medicine stock\n.");
    printf("5.exit\n.");
    printf("----------------------------------------------------------------------\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
    switch(choice){
        case 1: 
        while(1){
        printf("_________________________________________________________________________\n");
            printf(".Medicine and Equipment Inventory Management\n");
            printf("1.add medicine\n");
            printf("2.remove medicine\n");
            printf("3.update medicine\n");
            printf("4.exit\n.");
            printf("_________________________________________________________________________\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);        
            if(choice==1){
                printf(" enter number of entity:");
                scanf("%d",&n);
                addmedicine(n) ; 
                printf("---------------------------------------------------------------------------\n");     
                display(n) ;    
            }
            else if(choice==2){
                printf(" medicine you want to delete:");
                scanf("%s",&name);
                removemed( name );    
            }
            else if (choice == 3) {
                // Future feature to update a medicine (not implemented)
                printf("Update medicine feature is not implemented yet.\n");
            }
            else if(choice==4){
                printf(" thanks for using see you soon");
                break;
            }
            else{
                printf(" invalid choice");
            }}
        break;   
        case 6:
        printf("Exiting program.\n");
        return 0;  // Added return to exit the program properly
    default:
        printf("Invalid choice.\n");


        }
  
    }
    return 0;
}
