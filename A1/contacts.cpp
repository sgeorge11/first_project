//
// Created by stevenson on 2021-06-26.
//

#include <cstdio>

#include "contacts.h"
#include "../read_input.h"

void getName(struct Name *name) {

    char yesNo;
    char *p;
    char line[256];

    printf("Please enter the contact's first name: ");
    fgets(line, sizeof line, stdin);
    sscanf(line, "%31[^\n]", name->firstName);
    if ((p=strchr(name->firstName, '\n')) != nullptr) {
        *p = '\0';
    }

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    fgets(&yesNo, sizeof &yesNo, stdin);

    if (yesNo == 'y' || yesNo == 'Y') {
        printf("Please enter the contact's middle initial(s): ");
        fgets(line, sizeof line, stdin);
        sscanf(line, "%5[^\n]", name->middleInitial);
        if ((p=strchr(name->middleInitial, '\n')) != nullptr) {
            *p = '\0';
        }
    }

    printf("Please enter the contact's last name: ");
    fgets(line, sizeof line, stdin);
    sscanf(line, "%36[^\n]", name->lastName);
    if ((p=strchr(name->lastName, '\n')) != nullptr) {
        *p = '\0';
    }
}

void getAddress(struct Address *address)
{
    char yesNo;
    char *p;
    char line[256];

    do {
        printf("Please enter the contact's street number: ");
        getIntegerFromStdin(&address->streetNumber);
    } while (address->streetNumber < 1);

    printf("Please enter the contact's street name: ");
    fgets(line, sizeof line, stdin);
    sscanf(line, "%41[^\n]", address->street);
    if ((p=strchr(address->street, '\n')) != nullptr) {
        *p = '\0';
    }

    printf("Do you want to enter an apartment number? (y or n): ");
    fgets(&yesNo, sizeof &yesNo, stdin);

    if (yesNo == 'y' || yesNo == 'Y') {
        do {
            printf("Please enter the contact's apartment number: ");
            getIntegerFromStdin(&address->apartmentNumber);
            printf("Apartment Number: %d\n", address->apartmentNumber);
        } while (address->apartmentNumber < 1);
    }

    printf("Please enter the contact's postal code: ");
    fgets(line, sizeof line, stdin);
    sscanf(line, "%8[^\n]", address->postalCode);
    if ((p=strchr(address->postalCode, '\n')) != nullptr) {
        *p = '\0';
    }

    printf("Please enter the contact's city: ");
    fgets(line, sizeof line, stdin);
    sscanf(line, "%41[^\n]", address->city);
    if ((p=strchr(address->city, '\n')) != nullptr) {
        *p = '\0';
    }
}

void getNumbers(struct Numbers *numbers)
{
    char yesNo;
    char *p;
    char line[256];

    printf("Do you want to enter a cell phone number? (y or n): ");
    fgets(&yesNo, sizeof &yesNo, stdin);

    if (yesNo == 'y' || yesNo == 'Y') {
        printf("Please enter the contact's cell phone number: ");
        fgets(line, sizeof line, stdin);
        sscanf(line, "%11[^\n]", numbers->cell);
        if ((p=strchr(numbers->cell, '\n')) != nullptr) {
            *p = '\0';
        }
    }

    printf("Do you want to enter a home phone number? (y or n): ");
    fgets(&yesNo, sizeof &yesNo, stdin);

    if (yesNo == 'y' || yesNo == 'Y') {
        printf("Please enter the contact's home phone number: ");
        fgets(line, sizeof line, stdin);
        sscanf(line, "%11[^\n]", numbers->home);
        if ((p=strchr(numbers->home, '\n')) != nullptr) {
            *p = '\0';
        }
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    fgets(&yesNo, sizeof &yesNo, stdin);

    if (yesNo == 'y' || yesNo == 'Y') {
        printf("Please enter the contact's business phone number: ");
        fgets(line, sizeof line, stdin);
        sscanf(line, "%11[^\n]", numbers->business);
        if ((p=strchr(numbers->business, '\n')) != nullptr) {
            *p = '\0';
        }
    }
}