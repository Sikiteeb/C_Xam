#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct date {
    int day;
    char month[4];
    int year;
} DATE;

typedef struct invoice {
    const char *pPassenger;
    const char *pDestination;
    DATE when;
} INVOICE;

const INVOICE InvoiceList[] = {
        {"John Smith", "Buenos Aires", {1, "Mar", 2022}},
        {"Mary Weaver", "Guatemala City", {10, "Feb", 2022}},
        {"James Carpenter", "Santiago de Chile", {1, "Mar", 2022}},
        {"Nancy Gardener", "Guatemala City", {10, "Mar", 2022}},
        {"Elizabeth Clerk", "Quito", {12, "Apr", 2022}},
        {"Thomas Farmhand", "Guatemala City", {11, "Feb", 2022}},
        {"Richard Sailor", "Guatemala City", {10, "Feb", 2022}}
};


int isDateValid(DATE *date, const char *pDate) {

    int d, m, y;
    if (sscanf(pDate, "%d-%3s-%d", &d, date->month, &y) != 3) {
        return 0;
    }
    date->day = d;
    date->year = y;


    if (strcmp(date->month, "Jan") && strcmp(date->month, "Feb") && strcmp(date->month, "Mar") &&
        strcmp(date->month, "Apr") && strcmp(date->month, "May") && strcmp(date->month, "Jun") &&
        strcmp(date->month, "Jul") && strcmp(date->month, "Aug") && strcmp(date->month, "Sep") &&
        strcmp(date->month, "Oct") && strcmp(date->month, "Nov") && strcmp(date->month, "Dec")) {
        return 0;
    }


    if (d < 1 || d > 31 || y < 1900 || y > 2100) {
        return 0; 
    }

    return 1;
}

char **TravelAgent(const INVOICE *pInvoices, int nInvoices, const char *pDestination, const char *pDate, int *pnResults) {
    // Validate input parameters
    if (pInvoices == NULL || pDestination == NULL || pDate == NULL || nInvoices <= 0) {
        *pnResults = 0;
        return NULL;
    }


    char **resultList = (char **)malloc(nInvoices * sizeof(char *));
    int resultCount = 0;


    DATE inputDate;
    if (!isDateValid(&inputDate, pDate)) {
        *pnResults = 0;
        free(resultList);
        return NULL;
    }


    for (int i = 0; i < nInvoices; i++) {
        if (strcmp(pInvoices[i].pDestination, pDestination) == 0 &&
            memcmp(&pInvoices[i].when, &inputDate, sizeof(DATE)) == 0) {
            resultList[resultCount++] = strdup(pInvoices[i].pPassenger);
        }
    }

    *pnResults = resultCount;
    return resultList;
}

int main() {
    int n;
    char **PassengerList = TravelAgent(InvoiceList, 7, "Buenos Aires", "1-Mar-2022", &n);

    if (PassengerList) {
        printf("Matching passengers:\n");
        for (int i = 0; i < n; i++) {
            printf("%s\n", PassengerList[i]);
            free(PassengerList[i]);
        }
        free(PassengerList);
    } else {
        printf("No matching passengers found.\n");
    }

    return 0;
}
