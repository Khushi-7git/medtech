#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    char name[100];
    int quantity;
    char expirydate[100];
}medicine;
medicine inventory[100];
medicine med;
void addmedicine(int n){ //n takes number of entity i want to insert
    int *name=(int*)malloc(n*sizeof(int));
    for(int i=0;i<=n;i++){
     printf("mecidine name:\t");
     scanf("%c",&inventory[i].name);
     printf("quantity:\t");
     scanf("%c",&inventory[i].quantity);
     printf("expirydate:\t");
     scanf("%c",&inventory[i].expirydate);// Adds new medicine to the inventory  
    }
}
int main(){
    int choice,n;
    printf(" welcome to your medicmange\n");
    printf("1.Medicine and Equipment Inventory Management ");
    printf("2.Manage patient");
    printf("3.Medicine Expiration alert");
    printf("4.serch medicine");
    printf("5.Track medicine stock\n.");
    printf(" enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            int opt;
            printf(".Medicine and Equipment Inventory Management");
            printf("1.add medicine");
            printf("1.remove medicine");
            printf("1.update medicine");
            scanf("enter choice %d",&opt);
            if(opt==1){
                printf(" enter number of entity:\t");
                scanf("%d",&n);
                addmedicine(n) ;               
            }


        

        }
    }
   
