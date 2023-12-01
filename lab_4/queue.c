#include <stdio.h>
#include <stdlib.h>

// Structure to represent a customer in the banking system
struct Customer
{
    int accountNumber;
    char name[50];
    float balance;
    struct Customer *next;
};

// Function prototypes
void insert(struct Customer **front, struct Customer **rear);
void delete(struct Customer **front, struct Customer **rear);
void search(struct Customer *front);
void display(struct Customer *front);

void insertCircular(struct Customer **front, struct Customer **rear);
void deleteCircular(struct Customer **front, struct Customer **rear);

void insertFront(struct Customer **front, struct Customer **rear);
void deleteRear(struct Customer **front, struct Customer **rear);

// Function to display the menu
void displayMenu()
{
    printf("\nBanking Management System Menu\n");
    printf("1. Insert Customer (Queue)\n");
    printf("2. Delete Customer (Queue)\n");
    printf("3. Search Customer\n");
    printf("4. Display Customers\n");
    printf("5. Insert Customer (Circular Queue)\n");
    printf("6. Delete Customer (Circular Queue)\n");
    printf("7. Insert Customer (Deque - Front)\n");
    printf("8. Delete Customer (Deque - Rear)\n");
    printf("9. Exit\n");
}

int main()
{
    struct Customer *front = NULL;
    struct Customer *rear = NULL;
    int choice;

    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert(&front, &rear);
            break;
        case 2:
            delete(&front, &rear);
            break;
        case 3:
            search(front);
            break;
        case 4:
            display(front);
            break;
        case 5:
            insertCircular(&front, &rear);
            break;
        case 6:
            deleteCircular(&front, &rear);
            break;
        case 7:
            insertFront(&front, &rear);
            break;
        case 8:
            deleteRear(&front, &rear);
            break;
        case 9:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 9);

    return 0;
}

// Function to insert a customer into the queue
void insert(struct Customer **front, struct Customer **rear)
{
    struct Customer *newCustomer = (struct Customer *)malloc(sizeof(struct Customer));

    printf("Enter Account Number: ");
    scanf("%d", &newCustomer->accountNumber);
    printf("Enter Name: ");
    scanf("%s", newCustomer->name);
    printf("Enter Balance: ");
    scanf("%f", &newCustomer->balance);

    newCustomer->next = NULL;

    if (*rear == NULL)
    {
        *front = *rear = newCustomer;
    }
    else
    {
        (*rear)->next = newCustomer;
        *rear = newCustomer;
    }

    printf("Customer added to the queue successfully.\n");
}

// Function to delete a customer from the queue
void delete(struct Customer **front, struct Customer **rear)
{
    if (*front == NULL)
    {
        printf("Queue is empty. No customer to delete.\n");
        return;
    }

    struct Customer *temp = *front;
    *front = (*front)->next;

    free(temp);

    if (*front == NULL)
    {
        *rear = NULL;
    }

    printf("Customer deleted from the queue successfully.\n");
}

// Function to search for a customer in the queue
void search(struct Customer *front)
{
    int accountNumber;
    printf("Enter Account Number to search: ");
    scanf("%d", &accountNumber);

    struct Customer *current = front;

    while (current != NULL)
    {
        if (current->accountNumber == accountNumber)
        {
            printf("Customer found:\n");
            printf("Account Number: %d\n", current->accountNumber);
            printf("Name: %s\n", current->name);
            printf("Balance: %.2f\n", current->balance);
            return;
        }
        current = current->next;
    }

    printf("Customer not found.\n");
}

// Function to display all customers in the queue
void display(struct Customer *front)
{
    if (front == NULL)
    {
        printf("Queue is empty. No customers to display.\n");
        return;
    }

    printf("Customers in the queue:\n");

    struct Customer *current = front;

    while (current != NULL)
    {
        printf("Account Number: %d\n", current->accountNumber);
        printf("Name: %s\n", current->name);
        printf("Balance: %.2f\n", current->balance);
        printf("------------\n");
        current = current->next;
    }
}

// Function to insert a customer into the circular queue
void insertCircular(struct Customer **front, struct Customer **rear)
{
    struct Customer *newCustomer = (struct Customer *)malloc(sizeof(struct Customer));

    printf("Enter Account Number: ");
    scanf("%d", &newCustomer->accountNumber);
    printf("Enter Name: ");
    scanf("%s", newCustomer->name);
    printf("Enter Balance: ");
    scanf("%f", &newCustomer->balance);

    newCustomer->next = NULL;

    if (*rear == NULL)
    {
        *front = *rear = newCustomer;
        newCustomer->next = *front; // Circular link
    }
    else
    {
        newCustomer->next = (*rear)->next;
        (*rear)->next = newCustomer;
        *rear = newCustomer;
    }

    printf("Customer added to circular queue successfully.\n");
}

// Function to delete a customer from the circular queue
void deleteCircular(struct Customer **front, struct Customer **rear)
{
    if (*front == NULL)
    {
        printf("Circular Queue is empty. No customer to delete.\n");
        return;
    }

    struct Customer *temp = *front;

    if (*front == *rear)
    {
        *front = *rear = NULL;
    }
    else
    {
        *front = (*front)->next;
        (*rear)->next = *front;
    }

    free(temp);

    printf("Customer deleted from circular queue successfully.\n");
}

// Function to insert a customer into the front of the deque
void insertFront(struct Customer **front, struct Customer **rear)
{
    struct Customer *newCustomer = (struct Customer *)malloc(sizeof(struct Customer));

    printf("Enter Account Number: ");
    scanf("%d", &newCustomer->accountNumber);
    printf("Enter Name: ");
    scanf("%s", newCustomer->name);
    printf("Enter Balance: ");
    scanf("%f", &newCustomer->balance);

    newCustomer->next = NULL;

    if (*rear == NULL)
    {
        *front = *rear = newCustomer;
    }
    else
    {
        newCustomer->next = *front;
        *front = newCustomer;
    }

    printf("Customer added to the front of the deque successfully.\n");
}

// Function to delete a customer from the rear of the deque
void deleteRear(struct Customer **front, struct Customer **rear)
{
    if (*front == NULL)
    {
        printf("Deque is empty. No customer to delete.\n");
        return;
    }

    struct Customer *temp = *front;
    struct Customer *prev = NULL;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL)
    {
        *front = *rear = NULL;
    }
    else
    {
        prev->next = NULL;
        *rear = prev;
    }

    free(temp);

    printf("Customer deleted from the rear of the deque successfully.\n");
}
