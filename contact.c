#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "validation.h"

void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    int choice;
    printf("Choose sorting criteria:\n1. sort by name\n2. sort by phone\n3. sort by email\nEnter the choice ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        for(int i = 0;i < addressBook ->contactCount - 1; i++)
        {
            for(int j = i+1;j < addressBook -> contactCount;j++)
            {
                if(strcmp(addressBook -> contacts[i].name, addressBook -> contacts[j].name) > 0)
                {
                    Contact temp = addressBook -> contacts[i];
                    addressBook -> contacts[i] = addressBook -> contacts[j];
                    addressBook -> contacts[j] = temp;
                }
            }
        }
        break;
        case 2:
        for(int i = 0;i < addressBook ->contactCount - 1; i++)
        {
            for(int j = i+1;j < addressBook -> contactCount;j++)
            {
                if(strcmp(addressBook -> contacts[i].phone, addressBook -> contacts[j].phone) > 0)
                {
                    Contact temp = addressBook -> contacts[i];
                    addressBook -> contacts[i] = addressBook -> contacts[j];
                    addressBook -> contacts[j] = temp;
                }
            }
        }
        break;
        case 3:
        for(int i = 0;i < addressBook ->contactCount - 1; i++)
        {
            for(int j = i+1;j < addressBook -> contactCount;j++)
            {
                if(strcmp(addressBook -> contacts[i].email, addressBook -> contacts[j].email) > 0)
                {
                    Contact temp = addressBook -> contacts[i];
                    addressBook -> contacts[i] = addressBook -> contacts[j];
                    addressBook -> contacts[j] = temp;
                }
            }
        }
        break;
        default:
        printf("Invalid choice");
        break;
    }
    
    for(int i =0;i < addressBook -> contactCount;i++)
    {
        printf("Contact %d: Name: %s, Phone: %s, Email: %s\n",i + 1,addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
    }
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    char name[50];
    char phone[20];
    char email[50];

    if(addressBook->contactCount == MAX_CONTACTS)
    {
        printf("Address Book Full\n");
        return;
    }

    printf("Enter the name: ");
    scanf(" %49[^\n]", name);

    if(validName(name) == 0)
    {
        printf("Invalid name\n");
        return;
    }


    printf("Enter the phone_no: ");
    scanf("%19s", phone);

    if(validPhone(phone) == 0)
    {
        printf("Invalid phone number\n");
        return;
    }


    if(phoneExists(addressBook, phone))
    {
        printf("Phone number already exists\n");
        return;
    }


    printf("Enter the email: ");
    scanf("%49s", email);


    if(validEmail(email) == 0)
    {
        printf("Invalid email\n");
        return;
    }


    if(emailExists(addressBook, email))
    {
        printf("Email already exists\n");
        return;
    }


    strcpy(addressBook->contacts[addressBook->contactCount].name,name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email,email);


    addressBook->contactCount++;

    printf("Contact created successfully\n");
}

int searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int choice = 0;
    printf("Choose search criteria:\n1. search by name\n2. search by phone\n3. search by email\nEnter the choice ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
        char name[50];
        printf("Enter the name : ");
        scanf(" %[^\n]",name);
        for(int i = 0;i < addressBook->contactCount;i++)
        {
            if(strcmp(name,addressBook->contacts[i].name) == 0)
            {
                printf("Name: %s,Phone: %s, Email: %s\n", addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
                return i;//index value
            }
        }
        break;
        }
        case 2:
        {
        char phone[50];
        printf("Enter the phone_no : ");
        scanf(" %[^\n]",phone);
        for(int i = 0;i < addressBook->contactCount;i++)
        {
            if(strcmp(phone,addressBook->contacts[i].phone) == 0)
            {
                printf("Name: %s,Phone: %s, Email: %s\n", addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
                return i;
            }
        }
        break;
        }
        case 3:
        {
        char email[50];
        printf("Enter the email : ");
        scanf(" %[^\n]",email);
        for(int i = 0;i < addressBook->contactCount;i++)
        {
            if(strcmp(email,addressBook->contacts[i].email) == 0)
            {
                printf("Name: %s,Phone: %s, Email: %s\n", addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
                return i;
            }
        }
        break;
        }
        default:
        printf("Invalid choice");
        break;
    }
    printf("Contact not found\n");
    return -1;
}

void editContact(AddressBook *addressBook)
{
    int ret = searchContact(addressBook);

    if(ret == -1)
    {
        printf("Contact not found\n");
        return;
    }


    int choice;

    printf("1. Edit name\n");
    printf("2. Edit phone\n");
    printf("3. Edit mail id\n");
    printf("Enter the choice: ");

    scanf("%d",&choice);


    switch(choice)
    {
        case 1:
        {
            char name[50];

            printf("Enter new name: ");
            scanf(" %49[^\n]",name);


            if(validName(name) == 0)
            {
                printf("Invalid name\n");
                return;
            }


            strcpy(addressBook->contacts[ret].name,name);

            printf("Name updated successfully\n");

            break;
        }


        case 2:
        {
            char phone[20];

            printf("Enter new phone number: ");
            scanf("%19s",phone);


            if(validPhone(phone) == 0)
            {
                printf("Invalid phone number\n");
                return;
            }


            if(phoneExistsEdit(addressBook,phone,ret))
            {
                printf("Phone number already exists\n");
                return;
            }


            strcpy(addressBook->contacts[ret].phone,phone);

            printf("Phone updated successfully\n");

            break;
        }


        case 3:
        {
            char email[50];

            printf("Enter new email: ");
            scanf("%49s",email);


            if(validEmail(email) == 0)
            {
                printf("Invalid email\n");
                return;
            }


            if(emailExistsEdit(addressBook,email,ret))
            {
                printf("Email already exists\n");
                return;
            }


            strcpy(addressBook->contacts[ret].email,email);

            printf("Email updated successfully\n");

            break;
        }


        default:
            printf("Invalid choice\n");
    }


    printf("\nUpdated Contact Details:\n");
    printf("Name: %s\n",addressBook->contacts[ret].name);
    printf("Phone: %s\n",addressBook->contacts[ret].phone);
    printf("Email: %s\n",addressBook->contacts[ret].email);
}

void deleteContact(AddressBook *addressBook)
{
    int ret = searchContact(addressBook);

    if(ret == -1)
    {
        return;
    }


    for(int i = ret; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i+1];
    }


    addressBook->contactCount--;

    printf("Contact deleted successfully\n");
}
