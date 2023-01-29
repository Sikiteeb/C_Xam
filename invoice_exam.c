#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

const INVOICE* InvoiceList[]={
        {"John Smith", "Buenos Aires", { 1, "Mar", 2022 }},
        {"Mary Weaver", "Guatemala City", { 10, "Feb", 2022 }},
        {"James Carpenter", "Santiago de Chile", { 1, "Mar", 2022 }},
        {"Nancy Gardener", "Guatemala City", { 10, "Mar", 2022 }},
        {"Elizabeth Clerk", "Quito", { 12, "Apr", 2022 }},
        {"Thomas Farmhand", "Guatemala City", { 11, "Feb", 2022 }},
        {"Richard Sailor", "Guatemala City", { 10, "Feb", 2022 }},
};

char** Exam(const INVOICE** ppInvoices, int nInvoices, const char* pDestination, const char *pDate, int *pnResults)
{
    if(!ppInvoices || !pDestination || !pDate || !pnResults)
        return NULL;

    int i, j=0;
    char **PassengerList = (char**)malloc(sizeof(char*)*nInvoices);
    char date[11];
    sprintf(date, "%d-%s-%d", ppInvoices[0]->when.day, ppInvoices[0]->when.month, ppInvoices[0]->when.year);

    for(i=0; i<nInvoices; i++) {
        if(strcmp(ppInvoices[i]->pDestination, pDestination)==0 && strcmp(date, pDate)==0) {
            PassengerList[j] = (char*)malloc(sizeof(char)*(strlen(ppInvoices[i]->pPassenger)+1));
            strcpy(PassengerList[j], ppInvoices[i]->pPassenger);
            j++;
        }
    }
    *pnResults = j;

    return PassengerList;
}

int main()
{
    int n;
    char **PassengerList = Exam(InvoiceList, 7, "Guatemala City", "10-Feb-2022", &n);
    if(!PassengerList) {
        printf("Invalid input\n");
        return 0;
    }
    printf("Input date *day-month(3letters)-year: \n");
    scanf("&19s", pDate);

    printf("Input name and destination city: \n");
    scanf("&19s,&19s", passengerList[], pDestination);
    int i;
    printf("List of passengers flying to %s on %s:\n");
    for(i=0; i<n; i++) {

        printf("%s\n", PassengerList[i]);
    }

    for(i=0; i<n; i++) {
        free(PassengerList[i]);
    }
    free(PassengerList);

    return 0;
}
