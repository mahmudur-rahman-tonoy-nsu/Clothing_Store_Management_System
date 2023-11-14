#ifndef LOGIN_H
#define LOGIN_H

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
	menu();
}

#endif