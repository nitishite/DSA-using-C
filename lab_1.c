#include <stdio.h>

#define MAX_CUSTOMERS 100

struct Customer
{
    int accountNumber;
    char name[50];
    double balance;
};

struct Customer customers[MAX_CUSTOMERS];
int numCustomers = 0;

void insertCustomer()
{
    if (numCustomers < MAX_CUSTOMERS)
    {
        struct Customer newCustomer;

        printf("Enter account number: ");
        scanf("%d", &newCustomer.accountNumber);

        printf("Enter name: ");
        scanf("%s", newCustomer.name);

        printf("Enter balance: ");
        scanf("%lf", &newCustomer.balance);

        customers[numCustomers++] = newCustomer;
        printf("Customer added successfully!\n");
    }
    else
    {
        printf("Maximum number of customers reached!\n");
    }
}

void deleteCustomer()
{
    int accountNumber;
    printf("Enter account number to delete: ");
    scanf("%d", &accountNumber);

    int found = 0;
    for (int i = 0; i < numCustomers; i++)
    {
        if (customers[i].accountNumber == accountNumber)
        {
            found = 1;
            for (int j = i; j < numCustomers - 1; j++)
            {
                customers[j] = customers[j + 1];
            }
            numCustomers--;
            printf("Customer deleted successfully!\n");
            break;
        }
    }

    if (!found)
    {
        printf("Customer not found!\n");
    }
}

void searchCustomer()
{
    int accountNumber;
    printf("Enter account number to search: ");
    scanf("%d", &accountNumber);

    int found = 0;
    for (int i = 0; i < numCustomers; i++)
    {
        if (customers[i].accountNumber == accountNumber)
        {
            found = 1;
            printf("Account Number: %d\n", customers[i].accountNumber);
            printf("Name: %s\n", customers[i].name);
            printf("Balance: %.2lf\n", customers[i].balance);
            break;
        }
    }

    if (!found)
    {
        printf("Customer not found!\n");
    }
}

void displayCustomers()
{
    if (numCustomers == 0)
    {
        printf("No customers found!\n");
    }
    else
    {
        printf("Account Number\tName\tBalance\n");
        for (int i = 0; i < numCustomers; i++)
        {
            printf("%d\t\t%s\t%.2lf\n", customers[i].accountNumber, customers[i].name, customers[i].balance);
        }
    }
}

void matrixAddition()
{
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\nFirst Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix1[i][j]);
        }
        printf("%\n");
    }
    printf("\nSecond Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix2[i][j]);
        }
        printf("%\n");
    }

    printf("\nMatrix Addition is:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void matrixSubtraction(int rows, int cols, int (*matrix1)[cols], int (*matrix2)[cols], int (*result)[cols])
{
    printf("\nMatrix Subtraction is:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Banking Management System ---\n");
        printf("1. Insert Customer\n");
        printf("2. Delete Customer\n");
        printf("3. Search Customer\n");
        printf("4. Display Customers\n");
        printf("5. Matrix Addition\n");
        printf("6. Matrix Subtraction\n");
        printf("7. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertCustomer();
            break;
        case 2:
            deleteCustomer();
            break;
        case 3:
            searchCustomer();
            break;
        case 4:
            displayCustomers();
            break;
        case 5:
            matrixAddition();
            break;
        case 6:
        {
            int rows, cols;
            printf("Enter the number of rows: ");
            scanf("%d", &rows);
            printf("Enter the number of columns: ");
            scanf("%d", &cols);

            int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];

            printf("Enter the elements of the first matrix:\n");
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    scanf("%d", &matrix1[i][j]);
                }
            }

            printf("Enter the elements of the second matrix:\n");
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    scanf("%d", &matrix2[i][j]);
                }
            }

            printf("\nFirst Matrix:\n");
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    printf("%d ", matrix1[i][j]);
                }
                printf("\n");
            }
            printf("\nSecond Matrix:\n");
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    printf("%d ", matrix2[i][j]);
                }
                printf("\n");
            }

            matrixSubtraction(rows, cols, matrix1, matrix2, result);
        }
        break;

        case 7:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice, please try again!\n");
        }
    } while (choice != 7);

    return 0;
}