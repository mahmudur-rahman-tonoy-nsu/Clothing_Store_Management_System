/**
Clothing Store Management System

Name: Md Mahmudur Rahman Tonoy
ID  : 2322988642
Section: 09
**/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ascii_art.h"

// function prototypes
void login();
void mainn();
void enterSalesData();
void displaySalesData();
void del();

// creating structure
struct item {
    int productid;
    char productname[50];
    float price;
    int qnt;
};

int main(void){

    printf("%s", ascii_art);
    login();
    mainn();
    return 0;
}


// function definition for login
void login(){

 char username[20];
 char password [20];

 printf("\n\t\t\t\t        *********************************************");
 printf("\n\t\t\t\t        *                 WELCOME                   *");
 printf("\n\t\t\t\t        *                   TO                      *");
 printf("\n\t\t\t\t        *            THE CLOTHING STORE             *");
 printf("\n\t\t\t\t        *                MANAGEMENT                 *");
 printf("\n\t\t\t\t        *                 SYSTEM                    *");
 printf("\n\t\t\t\t        *********************************************");

 printf("\n\t\t\t\t\t\t\t   LOGIN ");
 printf("\n\n\t\t\t\t\t\tEnter Username: ");
 gets(username);

 printf("\n\t\t\t\t\t\tEnter Password: ");
 gets (password);

{
     if (strcmp (username, "tonoy")==0)
   {
        if(strcmp (password, "football")==0)
		{
		   printf("  \n\n\n \t\t\t        WELCOME TO THE CLOTHING STORE MANAGEMENT SYSTEM !!!!");
		   printf("  \n\n\n \t\t\t\t\t\t LOGIN IS SUCCESSFUL\n\n\n");
        }
	 else
	    {
         printf("\n      \t\t\t\t ----SORRY !!!!  Your Entered password is wrong----\n\n\n");
         login();
        }
    }
 else
	    {
         printf("\n      \t\t\t\t ----SORRY !!!!  Your Entered name is wrong----\n\n\n");
         login();
        }
}
	mainn();
}


// function definition of menu
void mainn() {

    int i;
    char x;
    float amount = 0.0, discount_amount = 0.0, sub_total = 0.0, total_amount = 0.0;
    struct item i1;
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


// function definition which takes input of items, calculates total amount and stores in file
void enterSalesData() {
    int i;
    char x;
    float amount = 0.0, discount_amount = 0.0, sub_total = 0.0, total_amount = 0.0;
    struct item i1;

    FILE *fp;
    fp = fopen("test.txt", "a");

    do {
        printf("\nEnter Product ID: ");
        scanf("%d", &i1.productid);
        printf("Enter Product Name: ");
        scanf("%s", i1.productname);
        printf("Enter Price for the item: ");
        scanf("%f", &i1.price);
        printf("Enter Quantity: ");
        scanf("%d", &i1.qnt);

        amount = i1.price * i1.qnt;
        sub_total += amount;

        printf("\nEnter the discount for this product (Enter 0 for no discount): ");
        scanf("%f", &discount_amount);

        total_amount = sub_total - discount_amount;


        printf("\nBill Details");
        printf("\n-------------");
        printf("\nProduct ID: %d", i1.productid);
        printf("\nProduct Name: %s", i1.productname);
        printf("\nPrice for the item: %.2f", i1.price);
        printf("\nQuantity: %d", i1.qnt);
        printf("\nAmount: %.2f", amount);
        printf("\nSub Total: %.2f", sub_total);
        printf("\nDiscount Amount: %.2f", discount_amount);
        printf("\nTotal Amount: %.2f", total_amount);
        printf("\n-------------");
        printf("\n Total Price %.2f", total_amount);

        fprintf(fp, "%s %d %.2f %d\n", i1.productname, i1.productid, i1.price, i1.qnt);
        fflush(fp);

        char c;
        printf("\n\n Press 'N' for Main menu & Y to add another item : ");
        scanf(" %c", &c);
        switch (c) {
            case 'y':
            case 'Y':
                break;
            default:
                mainn();
        }
    } while (1);

       fclose(fp);
}


// function definition which displays the items which are stored in file
void displaySalesData() {

    int productid;
    struct item i1;
    FILE *fp;

    fp = fopen("test.txt", "r");

    if (fp == NULL) {

        printf("File not oppened");

    }
     while (fscanf(fp, "%s %d %f %d", &i1.productname, &i1.productid, &i1.price, &i1.qnt) == 4) {

        printf("Name: %s\n", i1.productname);
        printf("ID: %d\n", i1.productid);
        printf("Price: %.2f\n",i1.price);
        printf("Quantity: %d\n", i1.qnt);
        printf("\n");
    }
    fclose(fp);

    printf("\nPress Enter to return to the Main Menu: ");

    mainn();
}


// function definition which deletes items according to user's input
void del() {

    char productname[50];
    struct item i1;
    FILE *fp, *fp1;

    printf("\nEnter the product name you want to delete: ");
    scanf("%s", &productname);

    fp = fopen("test.txt", "r");
    fp1 = fopen("temp1.txt", "w");

    if (fp == NULL) {
        fprintf(stderr, "Can't open file");
        exit(0);
    }


   while (fscanf(fp, "%s %d %f %d", i1.productname, &i1.productid, &i1.price, &i1.qnt) == 4) {

      if (strcmp(i1.productname, productname ) != 0) {
       fprintf(fp1, "%s %d %.2f %d\n", i1.productname, i1.productid, i1.price, i1.qnt);
      }
    }

    fclose(fp);
    fclose(fp1);

    remove("test.txt");
    rename("temp1.txt", "test.txt");

    printf("\Item deleted Successfully.");
    printf("\nPress Enter to return to Main Menu: ");

    mainn();
}

