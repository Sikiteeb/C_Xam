#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"
#include "time.h"
#pragma warning ( disable : 4996 ) //deprecation warnings off

struct tm timeinfo;
typedef struct date
{
    int day;
    char month[4];
    int year;
}DATE;
typedef struct invoice
{
    const char *pPassenger,
    *pDestination;
    int fare;
    DATE when;
} INVOICE;

const INVOICE* InvoiceList[]={
        new INVOICE {"John Smith", "Buenos Aires", 2000, { 1, "Mar", 2022 }},
        new INVOICE {"Mary Weaver", "Guatemala City", 1700, { 10, "Feb", 2022 }},
        new INVOICE {"James Carpenter", "Santiago de Chile", 2200, { 1, "Mar", 2022 }},
        new INVOICE {"Nancy Gardener", "Guatemala City", 1700, { 10, "Mar", 2022 }},
        new INVOICE {"Elizabeth Clerk", "Quito", 1800, { 12, "Apr", 2022 }},
        new INVOICE {"Thomas Farmhand", "Guatemala City", 1700, { 11, "Feb", 2022 }},
        new INVOICE {"Richard Sailor", "Guatemala City", 1700, { 10, "Feb", 2022 }}};


int main()
{

     scanf("%19s", InvoiceList[i].pPassenger );
     scanf("%19s", InvoiceList[i].pDestination );
     scanf("%19s", InvoiceList[i].Date );


     int length = sizeof InvoiceList[]/sizeof InvoiceList[0];

     INVOICE** traveller(const INVOICE** ppInvoices, int nInvoices, const char* pDestination, const char *pDate, int *pnResults);
        for (int i = 0; i < length; i++) {

        printf("Passenger: %s , Destination:  %s, Date:  %s", InvoiceList[i]->pPassenger,InvoiceList[i]->pDestination, InvoiceList[i]-> Date.day, InvoiceList[i] -> Date.month, InvoiceList[i]-> Date.year );
    }


return 0;
}
//if the call is:
//int n;
//char **PassengerList=Exam(InvoiceList,7,"Guatemala City","10-Feb-2022", &n);
//then the result should include the names, "Mary Weaver" and "Richard Sailor".

char** Exam(const INVOICE** ppInvoices, int nInvoices, const char* pDestination, const char *pDate, int *pnResults)
{

   if(!ppInvoices || !nInvoices || !pDestination || !pDate || !pnResults)
   {
      return 0;
   }









       time(&now);
    localtime_s(&timeinfo, &now);
    for (int i = 0; i < counter; i++)//find the time
    {
        InvoiceList[i]->when.day = timeinfo.tm_mday;//day
        for (int j = 0; j < 12; j++)//fill in the month array
        {
            char months[][4] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
            if (timeinfo.tm_mon + 1 == j+1)
            {
                for (int o = 0; o < 3; o++)
                {
                   InvoiceList[i]->when.month[o] = months[j][o];
                }
                in[i]->date.month[3] = '\0';
            }
        }
        InvoiceList[i]->when.year = timeinfo.tm_year + 1900;//year
    }
    return InvoiceList;

}