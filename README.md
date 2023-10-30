# C_Xam
Taltech 2022/2023 C exam

Let us have typedef struct date{int day, char month[4]; int year; DATE;
typedef struct invoice{const char *pPassenger, *pDestination; DATE when;} INVOICE;
and data structure:

const INVOICE* InvoiceList[]={
 {"John Smith", "Buenos Aires", 2000, { 1, "Mar", 2022 }},
 {"Mary Weaver", "Guatemala City", 1700, { 10, "Feb", 2022 }},
 {"James Carpenter", "Santiago de Chile", 2200, { 1, "Mar", 2022 }},
 {"Nancy Gardener", "Guatemala City", 1700, { 10, "Mar", 2022 }},
 {"Elizabeth Clerk", "Quito", 1800, { 12, "Apr", 2022 }},
 {"Thomas Farmhand", "Guatemala City", 1700, { 11, "Feb", 2022 }},
 {"Richard Sailor", "Guatemala City", 1700, { 10, "Feb", 2022 }}},

Write a function with prototype:
char** Exam(const INVOICE** ppInvoices, int nInvoices, const char* pDestination, const char *pDate, int *pnResults);

Date in arguments has format "dd-mm-yyyy".
The return value is the pointer to pointers that point to strings containing names that will fly to 
the specified destination on specified date.
If the call is:
int n;
char **PassengerList=Exam(InvoiceList,7,"Guatemala City","10-Feb-2022", &n);

then the result should include the names: "Mary Weaver" and "Richard Sailor".

The input values may not be zero or point to an empty array string. 
If those conditions are not satisfied, the function must return zero. However, if those conditions are satisfied,
we may be sure that the input data is 100% correct.

Write also main to test the code and print the results.

Testing input:

date
destination 
name

if the call is:
int n;
char **PassengerList=Exam(InvoiceList,7,"Guatemala City","10-Feb-2022", &n);

then the result should include the names, "Mary Weaver" and "Richard Sailor".
