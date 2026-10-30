#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "validation.h"

/* Validate Name */
int validName(char *name)
{
    int i = 0;

    if(name[0] == '\0')
        return 0;

    while(name[i] != '\0')
    {
        if(!(isalpha(name[i]) || name[i] == ' '))
            return 0;

        i++;
    }

    return 1;
}

/* Validate Phone Number */
int validPhone(char *phone)
{
    if(strlen(phone) != 10)
        return 0;

    for(int i = 0; phone[i] != '\0'; i++)
    {
        if(!isdigit(phone[i]))
            return 0;
    }

    return 1;
}

/* Validate Email */
int validEmail(char *email)
{
    int at = 0;
    int dot = 0;

    int len = strlen(email);

    for(int i = 0; i < len; i++)
    {
        if(email[i] == '@')
            at++;

        if(email[i] == '.')
            dot++;
    }

    if(at != 1)
        return 0;

    if(dot < 1)
        return 0;

    char *ptr1 = strchr(email, '@');
    char *ptr2 = strrchr(email, '.');

    if(ptr1 == NULL || ptr2 == NULL)
        return 0;

    if(ptr2 < ptr1)
        return 0;

    if(ptr1 == email)
        return 0;

    if(ptr2 == email + len - 1)
        return 0;

    return 1;
}

/* Check Duplicate Phone */
int phoneExists(AddressBook *addressBook, char *phone)
{
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(phone, addressBook->contacts[i].phone) == 0)
            return 1;
    }

    return 0;
}

/* Check Duplicate Email */
int emailExists(AddressBook *addressBook, char *email)
{
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(email, addressBook->contacts[i].email) == 0)
            return 1;
    }

    return 0;
}
int phoneExistsEdit(AddressBook *addressBook, char *phone, int index)
{
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(i != index)
        {
            if(strcmp(phone, addressBook->contacts[i].phone) == 0)
            {
                return 1;
            }
        }
    }

    return 0;
}


int emailExistsEdit(AddressBook *addressBook, char *email, int index)
{
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(i != index)
        {
            if(strcmp(email, addressBook->contacts[i].email) == 0)
            {
                return 1;
            }
        }
    }

    return 0;
}