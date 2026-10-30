#ifndef VALIDATION_H
#define VALIDATION_H

#include "contact.h"

int validName(char *name);
int validPhone(char *phone);
int validEmail(char *email);

int phoneExists(AddressBook *addressBook, char *phone);
int emailExists(AddressBook *addressBook, char *email);

int phoneExistsEdit(AddressBook *addressBook, char *phone, int index);
int emailExistsEdit(AddressBook *addressBook, char *email, int index);

#endif