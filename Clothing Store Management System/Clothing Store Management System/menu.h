#ifndef MAINN_H
#define MAINN_H

void menu() {

    int i;
    char x;
    float amount = 0.0, discount_amount = 0.0, sub_total = 0.0, total_amount = 0.0;
    
    FILE *fp;

    printf("\n\t\t\t\t        **************************");
    printf("\n\t\t\t\t        +        Main Menu       +");
    printf("\n\t\t\t\t        **************************\n");
    printf("\n\t\t\t\t          1. Enter Sales Data\n");
    printf("\n\t\t\t\t          2. Display Sales Data\n");
    printf("\n\t\t\t\t          3. Delete Sales Data\n");
    printf("\n\t\t\t\t          4. Exit\n");
    printf("\n\t\t\t\t        **************************\n");
    printf("\n\t\t\t\t          Enter your choice: ");
    scanf("%d", &i);

    switch (i) {
        case 1:
            enterSalesData();
            break;
        case 2:
            displaySalesData();
            break;
        case 3:
            del();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Choice, please enter again.\n");
            break;
    }
}

#endif