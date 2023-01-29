int main() {
    int n;
    char **PassengerList = Exam(InvoiceList, 7, "Guatemala City", "10-Feb-2022", &n);
    if (!PassengerList) {
        printf("No matches found\n");
    } else {
        printf("Passengers flying to Guatemala City on 10-Feb-2022:\n");
        for (int i = 0; i < n; i++) {
            printf("%s\n", PassengerList[i]);
        }
    }
    return 0;
}



char** Exam(const INVOICE** ppInvoices, int nInvoices, const char* pDestination, const char *pDate, int *pnResults) {
    // error checking
    if (!ppInvoices || !pDestination || !pDate || !pnResults) return 0;

    // extract day, month, and year from pDate
    int day, year;
    char month[4];
    sscanf(pDate, "%d-%3s-%d", &day, month, &year);

    // create an array to store the matching passenger names
    char **results = (char**)malloc(nInvoices * sizeof(char*));
    int nResults = 0;

    // loop through the invoices and check for matches
    for (int i = 0; i < nInvoices; i++) {
        const INVOICE *invoice = ppInvoices[i];
        if (strcmp(invoice->pDestination, pDestination) == 0 &&
            invoice->when.day == day &&
            strcmp(invoice->when.month, month) == 0 &&
            invoice->when.year == year) {
                // found a match, add passenger name to results array
                results[nResults] = (char*)malloc((strlen(invoice->pPassenger) + 1) * sizeof(char));
                strcpy(results[nResults], invoice->pPassenger);
                nResults++;
        }
    }

    // if no matches were found, return 0
    if (nResults == 0) return 0;

    // return the results array and the number of matches
    *pnResults = nResults;
    return results;
}

//if the call is:
//int n;
//char **PassengerList=Exam(InvoiceList,7,"Guatemala City","10-Feb-2022", &n);
//then the result should include the names, "Mary Weaver" and "Richard Sailor".









