#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LEN 100
#define MAX_DATE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    char manufacturedate[MAX_DATE_LEN];
    char expirydate[MAX_DATE_LEN];
} medicine;
//constructed the linklist for patient record

typedef struct Patient {
    int id;
    char name[100];
    struct Patient* next;
} Patient;

// Function to create a new patient record
Patient* create_patient(int id, const char* name) {
    
    Patient* new_patient = (Patient*)malloc(sizeof(Patient));
    if (new_patient == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
  
    new_patient->id = id;
    strncpy(new_patient->name, name, sizeof(new_patient->name) - 1);
    new_patient->name[sizeof(new_patient->name) - 1] = '\0'; 
    
    
    new_patient->next = NULL;

    return new_patient;
}

// Function to add a patient record to the linked list
void add_patient(Patient** head, int id, const char* name) {
    Patient* new_patient = create_patient(id, name);
    if (new_patient == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = new_patient;
    } else {
    
        Patient* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_patient;
    }
}

// Function to print all patient records
void print_patients(Patient* head) {
    if (head == NULL) {
        printf("No patients to display.\n");
        return;
    }

    Patient* temp = head;
    while (temp != NULL) {
        printf("Patient ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

void free_patients(Patient* head) {
    Patient* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
// Function to remove a patient record by ID
void remove_patient(Patient** head, int id) {
    if (*head == NULL) {
        printf("No patients in the list.\n");
        return;
    }

    Patient* temp = *head;
    Patient* prev = NULL;


    if (temp != NULL && temp->id == id) {
        *head = temp->next; 
        free(temp); 
        printf("Patient with ID %d has been removed.\n", id);
        return;
    }

   
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

  
    if (temp == NULL) {
        printf("Patient with ID %d not found.\n", id);
        return;
    }

  
    prev->next = temp->next;

   
    free(temp);
    printf("Patient with ID %d has been removed.\n", id);
}

medicine inventory[MAX_MEDICINES];
int current_size = 0;

void addmedicine(int n) {
    for (int i = 0; i < n; i++) {
        if (current_size >= MAX_MEDICINES) {
            printf("Inventory full, cannot add more medicines.\n");
            break;
        }
        printf("Medicine name: ");
        getchar(); 
        scanf("%[^\n]%*c", inventory[current_size].name);
        printf("Quantity: ");
        scanf("%d", &inventory[current_size].quantity);
        printf("Manufacture date: ");
        getchar(); 
        scanf("%[^\n]%*c", inventory[current_size].manufacturedate);
        printf("Expiry date: ");
        getchar(); 
        scanf("%[^\n]%*c", inventory[current_size].expirydate);

        current_size++;
    }
}
void searchmed(char name){
    if (current_size == 0) { 
        printf("No medicine in inventory.\n");}
    for(int i=0;i<current_size;i++){
        if(inventory[i].name==name){
            printf("found! details as follow!");
            printf("Name: %s\n", inventory[i].name); 
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Manufacture date: %s\n", inventory[i].manufacturedate);
            printf("Expiry date: %s\n", inventory[i].expirydate);
        }
    }
}

void display() {
    if (current_size == 0) {  
        printf("No medicine in inventory.\n");
    } else {
        for (int i = 0; i < current_size; i++) {
            printf("Medicine %d\n", i + 1);
            printf("Name: %s\n", inventory[i].name); 
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Manufacture date: %s\n", inventory[i].manufacturedate);
            printf("Expiry date: %s\n", inventory[i].expirydate);
            printf("--------------------------\n");
        }
    }
}

void removemed(char name[MAX_NAME_LEN]) {  
    int found = 0;
    for (int i = 0; i < current_size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < current_size - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            current_size--; 
            printf("Medicine %s deleted.\n", name);
            break;
        }
    }
    if (found == 0) { 
        printf("Medicine not found.\n");
    }
}

int main() {
    int choice, n;
    char name[MAX_NAME_LEN]; 

    printf("Welcome to your medicmange\n");
    printf("----------------------------------------------------------------------\n");
    printf("1. Medicine and Equipment Inventory Management\n");
    printf("2. Manage patient\n");
    printf("3. Medicine Expiration alert\n");// Future feature to update a medicine (not implemented)
    printf("4. Search medicine\n");
    printf("5. Track medicine stock\n");  // Future feature to update a medicine (not implemented)
    printf("6. Exit\n");
    printf("----------------------------------------------------------------------\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                while (1) {
                    printf("_________________________________________________________________________\n");
                    printf("Medicine and Equipment Inventory Management\n");
                    printf("1. Add medicine\n");
                    printf("2. Remove medicine\n");
                    printf("3. Update medicine\n");
                    printf("4. Exit\n");
                    printf("_________________________________________________________________________\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    if (choice == 1) {  
                        printf("Enter number of entities: ");
                        scanf("%d", &n);
                        addmedicine(n);
                        printf("---------------------------------------------------------------------------\n");
                        display();
                    }
                    else if (choice == 2) {
                        printf("Enter medicine name to delete: ");
                        scanf("%s", name);
                        removemed(name);
                    }
                    else if (choice == 3) {
                        // Future feature to update a medicine (not implemented)
                        printf("Update medicine feature is not implemented yet.\n");
                    }
                    else if (choice == 4) {
                        printf("Thanks for using, see you soon.\n");
                        break;
                    }
                    else {
                        printf("Invalid choice.\n");
                    }
                }
                break;
            case 2:
             while (1){
               printf("manage patient");
               printf("---------------------------------------------------------------------------\n");
               printf("1.add patient record.\n");
               printf("2.remove patient record.\n");
               printf("3.search patient record.\n");
               printf("4.exit.\n");
               printf("---------------------------------------------------------------------------\n");
               printf("Enter your choice: ");
               scanf("%d", &choice);
                if(choice==1){
                 Patient* head = NULL; 
                 int number_of_patients, id;
                 char name[100];
            
               
                printf("Enter the number of patients you want to add: ");
                scanf("%d", &number_of_patients);
            
              
                for (int i = 0; i < number_of_patients; i++) {
                    printf("Enter details for patient %d:\n", i + 1);
                    
                    printf("Enter Patient ID: ");
                    scanf("%d", &id);
                    
                    
                    printf("Enter Patient Name: ");
                    getchar();  
                    fgets(name, sizeof(name), stdin);  
                    name[strcspn(name, "\n")] = '\0';            
                    add_patient(&head, id, name);
                }
                printf("---------------------------------------------------------------------------\n");
                printf("\nPatient Records:\n");
                print_patients(head);
                free_patients(head);
                
                return 0;
            }
                else if(choice==2){
                 Patient* head = NULL; 
                 int number_of_patients, id, remove_id;
                 char name[100];
                 printf("\nEnter the Patient ID to remove: ");
                 scanf("%d", &remove_id);

         
                 remove_patient(&head, remove_id);


                 printf("\nUpdated Patient Records:\n");
                 print_patients(head);
            }
                else if(choice==3){
                      // Future feature to update a medicine (not implemented)
                 printf("this function is currently unavailable !!!!");
            }
                else if(choice==4){
                 printf("thanks for using");
                 break;
            }
                else {
                 printf("Invalid choice.\n");
            }

             }

        case 6:
                printf("Exiting program.\n");
                return 0;  
        default:
                printf("Invalid choice.\n");
        case 3:
         while (1)
         {     // Future feature to update a medicine (not implemented)
            printf("currently unavaiable.\n");
            printf("4.exit");
            if(choice==4){
                printf("thank");
                break;
            }

        }
        case 4:
          while (1){
            char name;
            printf("search medicine !!!.\n");
            printf("enter the medicine name");
            scanf("%s",&name);
            printf("---------------------------------------------------------------------------\n");
            searchmed(name);


        }

    return 0;  
}
}
}