/************************************< HEADER FILES INCLUDED>**********************************************/

#include <stdio.h>
#include <iostream>
#include <conio.h> //                      May Include some extra for just caution
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define size 25    // Constant Value '25' is assigned to word 'size'




/**********************************< DECLARATION OF SOME GLOBAL VARIABLES / ARRAYS>**************************************/

int choice, extra_charges[4] = { 0, 250, 370, 490 }, fares[4] = { 500, 600, 800, 700 }, seats, train_number, class_number, T_Fare, E, A, B, P, seat_limit;
char x, name[size], class_name[size], train_name[size], destinaton[size]; 




/**********************************< DECLARATION OF SOME USER DEFINED FUCTIONS >**************************************/

void LOGO();
void Reservation();
void trains();
void Classes();
void RANDOM();
void Seats(int limit);
int confirmed_ticket();
void ticket(char NAME[], int FARE, int SEAT, int TRAIN, char CLASS[], char T[], char DES[]);
void print_ticket(char NAME[], int FARE, int SEAT, int TRAIN, char CLASS[], char T[], char DES[]);
void KID();




/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^< MAIN PROGRAM >^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

int main()
{
	srand(time(0)); // To have variable seed values of srand.
	LOGO(); // User defined Function
	printf("\n\nPress any key to continue...");
	getch();

	/*******************< MAIN MENU >*******************/
start:
	system("cls");
	printf("               _ _ _ _ _ _ __ _ _ _ _ _ _ _\n");
	printf(". . . . . . .<   National Train Companion   > . . . . . . . .\n");
	printf(":             ' _ _ _ _ _ _ _ __ _ _ _ _ _ '                :\n");
	printf(":                                                           :\n");
	printf(": 1) Reserve a Ticket                                       :\n");
	printf(":                                                           :\n");
	printf(": 2) View all Available Trains                              :\n");
	printf(":                                                           :\n");
	printf(": 3) View all Classes                                       :\n");
	printf(":                                                           :\n");
	printf(": 4) Confirmed Tickets                                      :\n");
	printf(":                                                           :\n");
	printf(": 5) Exit                                                   :\n");
	printf(": _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ; \n\n");

choice:
	fflush(stdin); // Precautionary measure incase of wrong type entry
	choice = 0; // Sets value to 0
	printf(" <o> Choice: ");
	scanf_s(" %d", &choice);  // Input choice

	switch (choice){

	case 1: // Choice 1
	{
			  Reservation();
			  break;
	}
	case 2: // Choice 2
	{
			  system("cls");
			  printf("<o> Trains Details:-\n");
			  trains(); // User Defined Function
			  printf("\nPress any key to return to main menu... ");
			  getch();
			  break;
	}

	case 3: // Choice 3
	{
			  system("cls");
			  printf("<o> Classes Details:-\n");
			  Classes(); // User Defined Funciton
			  printf("\nPress any key to return to main menu... ");
			  getch();
			  
			  break;
	}
	case 4: // Choice 4
	{      
			  system("cls");
			  printf("<o> Confirmed Tickets:-\n");
			  confirmed_ticket(); // User Defined Function
			  break;
	}
	case 5: // Choice 5
	{
			  system("cls");
			  printf("Exit Accomplished.\n");
			  KID(); // User Defined Function
			  getch();
			  return 0;
	}
	default: // In case none of the above choices are made
	{
			   printf("\nInvalid Choice! Try Again:-\n ");
			   goto choice;
	}

	}	
	goto start; // Returns the Execution to the start of Program (Main Menu)
	return 0;
}

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv< MAIN PROGRAM END>vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/



/**********************************< PROTOTYPES OF USER DEFINED FUNCTIONS>**************************************/

void Reservation(){  // For Choice of reserving a Ticket
	system("cls");
	printf("<o> Ticketing:-\n\n");
NAAM:
	printf(">Name: ");
	scanf(" %[^\n]s", name);
	for (int k = 0; k <= strlen(name)-1; ++k)
	{
		if (((name[k] >= 'A') && (name[k] <= 'Z')) || ((name[k] >= 'a') && (name[k] <= 'z')) || (name[k] == ' '))
		{
		}
		else
		{
			printf("  < Invalid Entry Detected > \n\n");
			goto NAAM;
		}
	}
	printf("\n>>Press any key to view Trains<<\n");
	getch();
	system("cls");
	trains();
Train:
	fflush(stdin);
	train_number = 0;
	printf("Enter Train Number: ");
	scanf_s("%d", &train_number);
	int n;
	if (train_number<1001 || train_number>1008)
	{
		printf("Invalid Entry!\n");
		goto Train;
	}
	else if (train_number == 1001 || train_number == 1002)
	{
		n = fares[0];
		
	}
	else if (train_number == 1003 || train_number == 1004)
	{
		n = fares[1];
	}
	else if (train_number == 1005 || train_number == 1006)
	{
		n = fares[2];
	}
	else if (train_number == 1007 || train_number == 1008)
	{
		n = fares[3];
	}
	RANDOM();
	printf("\n>>Press any key to view Classes<<\n");
	getch();
	system("cls");
	Classes();
	printf("\n\n  { Available Tickets at the Moment }\n");
	printf("   <o> Economy\t\t\t-> %d\n", E);
	printf("   <o> A.C Lower/Standard\t-> %d\n",A);
	printf("   <o> Business\t\t\t-> %d\n", B);
	printf("   <o> Parlour\t\t\t-> %d\n", P);
	printf(" >------------------------------------<\n");
Class:
	fflush(stdin);
	class_number = 0;
	printf("\nEnter Class Number: ");
	scanf_s("%d", &class_number);
	if (class_number<1 || class_number>4)
	{
		printf("Invalid Entry!\n");
		goto Class;
	}
	
	switch (class_number){
	case 1:
		strcpy(class_name, "Economy Class");
		seat_limit = E;
		break;
	case 2:
		strcpy(class_name, "A.C Lower/Standard");
		seat_limit = A;
		break;
	case 3:
		strcpy(class_name, "Business Class");
		seat_limit = B;
		break;
	case 4:
		strcpy(class_name, "Parlour Class");
		seat_limit = P;
		break;
	}

	switch (train_number){
	case 1001:
		strcpy(train_name, "Jango Express");
		strcpy(destinaton, "Rawalpindi to Lahore");
		break;
	case 1002:
		strcpy(train_name, "Jango Express");
		strcpy(destinaton, "Lahore to Rawalpindi");
		break;
	case 1003:
		strcpy(train_name, "D33R 9000");
		strcpy(destinaton, "Lahore to Multan");
		break;
	case 1004:
		strcpy(train_name, "D33R 9000");
		strcpy(destinaton, "Multan to Lahore");
		break;
	case 1005:
		strcpy(train_name, "Madni Tyara");
		strcpy(destinaton, "Multan to Larkana");
		break;
	case 1006:
		strcpy(train_name, "Madni Tyara");
		strcpy(destinaton, "Larkana to Multan");
		break;
	case 1007:
		strcpy(train_name, "Goli Express");
		strcpy(destinaton, "Larkana to Karachi");
		break;
	case 1008:
		strcpy(train_name, "Goli Express");
		strcpy(destinaton, "Karachi to Larkana");
		break;
	}
	Seats(seat_limit);

	T_Fare = seats*(n + extra_charges[class_number - 1]);
	system("cls");
	printf("\n<o> Ticket:-\n\n");
	ticket(name, T_Fare, seats, train_number, class_name, train_name, destinaton);
CONFIRM:
	printf("Q: Confirm Ticket? (y/n):>");
	scanf_s(" %c", &x);
	if (x == 'y')
	{
		print_ticket(name, T_Fare, seats, train_number, class_name, train_name, destinaton);
		printf("\n< T.I.C.K.E.T   R.E.S.E.R.V.E.D>\n\n");
	}
	else if (x == 'n')
	{
		printf("\n< T.I.C.K.E.T    N.O.T    R.E.S.E.R.V.E.D >\n\n");
	}
	else
	{
		printf("\nInvalid Entry! Try Again:-\n");
		goto CONFIRM;
	}
	printf("\nPress any key to continue..."); getch();
}






void ticket(char NAME[], int FARE, int SEAT, int TRAIN, char CLASS[], char T[], char DES[]) // For ticket Format Layout
{
	printf("  .----------------------------------------------------.\n");
	printf("<                 N.T.C  T.I.C.K.E.T                     >\n");
	printf("  '----------------------------------------------------'  \n");
	printf("     <o> Name                :    %s\n\n", NAME);
	printf("     <o> Number of seats     :    %d\n\n", SEAT);
	printf("     <o> Train Number        :    %d\n\n", TRAIN);
	printf("     <o> Train               :    %s\n\n", T);
	printf("     <o> Class               :    %s\n\n", CLASS);
	printf("     <o> Destination         :    %s\n\n", DES);
	printf("     <o> Charges             :    %d Rs\n\n", FARE);
	printf(" '------------------------------------------------------'\n\n");
}





void print_ticket(char NAME[], int FARE, int SEAT, int TRAIN, char CLASS[], char T[], char DES[]){ // For creating a txt file of format of Ticket
	FILE *fp;
	fp = fopen("Seats_reserved.txt", "a");
	fprintf(fp, "  .----------------------------------------------------.\n");
	fprintf(fp, "<                 N.T.C  T.I.C.K.E.T                     >\n");
	fprintf(fp, "  '----------------------------------------------------'  \n");
	fprintf(fp, "     <o> Name                :    %s\n\n", NAME);
	fprintf(fp, "     <o> Number of seats     :    %d\n\n", SEAT);
	fprintf(fp, "     <o> Train Number        :    %d\n\n", TRAIN);
	fprintf(fp, "     <o> Train               :    %s\n\n", T);
	fprintf(fp, "     <o> Class               :    %s\n\n", CLASS);
	fprintf(fp, "     <o> Destination         :    %s\n\n", DES);
	fprintf(fp, "     <o> Charges             :    %d Rs\n\n", FARE);
	fprintf(fp, " '------------------------------------------------------'\n\n");
	fclose(fp);
}





void trains() // Function for Available Trains
{
	
	printf(" .-----------------------------------------------------------------------------------------------------.\n");
	printf("|Tr.No |\tTrain Name\t|\t    Destinations\t|\tFares\t|     Departure time    |\n");
	printf("|------|------------------------|-------------------------------|---------------|-----------------------|\n");
	printf("|      |                        |                               |               |                       |\n");
	printf("| 1001 |\tJango Express\t|\tRawalpindi to Lahore\t|\tRS.500\t|\t05:00hrs\t|\n");
	printf("|      |                        |                               |               |                       |\n");
	printf("| 1002 |\tJango Express\t|\tLahore to Rawalpindi\t|\tRS.500\t|\t01:00hrs\t|\n");
	printf("|      |                        |                               |               |                       |\n");
	printf("| 1003 |\tD33R 9000     \t|\tLahore to Multan\t|\tRS.600\t|\t10:30hrs\t|\n");
	printf("|      |                        |                               |               |                       |\n");
	printf("| 1004 |\tD33R 9000     \t|\tMultan to Lahore \t|\tRS.600\t|\t13:00hrs\t|\n");
	printf("|      |                        |                               |               |                       |\n");
	printf("| 1005 |\tMadni Tayara\t|\tMultan to Larkana\t|\tRS.800\t|\t21:00hrs\t|\n");
	printf("|      |                        |                               |               |                       |\n");
	printf("| 1006 |\tMadni Tayara\t|\tLarkana to Multan\t|\tRS.800\t|\t12:00hrs\t|\n");
	printf("|      |                        |                               |               |                       |\n");
	printf("| 1007 |\tGoli Express\t|\tLarkana to Karachi\t|\tRS.700\t|\t06:00hrs\t|\n");
	printf("|      |                        |                               |               |                       |\n");
	printf("| 1008 |\tGoli Express\t|\tKarachi to Larkana\t|\tRS.700\t|\t05:00hrs\t|\n");
	printf("'_______________________________________________________________________________________________________'\n");
	
}






void Classes(){ // Function for Available Classes of Train
	
	printf(".--------------------------------------------------------------------.\n");
	printf("|       Class         |         Services       |     Extra Charges   | \n");
	printf("|--------------------------------------------------------------------| \n");
	printf("|                     -                        -                     |\n");
	printf("|    Economy Class    |    Simple Seat/Berth   |       + %d Rs        |      -> 1 \n", extra_charges[0]);
	printf("|                     -                        -                     |\n");
	printf("|  A.C Lower/Standard |  A.C, Simple Sofa Seat |      + %d Rs       |      -> 2\n", extra_charges[1]);
	printf("|                     -                        -                     |\n");
	printf("|   Business Class    |   A.C, Berth in Cabin  |      + %d Rs       |      -> 3\n", extra_charges[2]);
	printf("|                     -                        -                     |\n");
	printf("|    Parlour CLass    |  A.C, Luxury Seat, TV  |      + %d Rs       |      -> 4\n", extra_charges[3]);
	printf("|                     -                        -                     |\n");
	printf("'--------------------------------------------------------------------' \n");
	
}





void RANDOM(){ // A Function used to randomly show the no. of seats available at the moment
	E = (rand() % 50) + 1;
	A = (rand() % 40) + 1;
	P = (rand() % 30) + 1;
	B = (rand() % 20) + 1;
}





void Seats(int limit){ // A function to input seats by User 
Seat:
	fflush(stdin);
	seats = 0;
	printf("\n>Number of Seats: ");
	scanf_s("%d", &seats);
	if (seats > limit || seats < 1)
	{
		printf("< Out Of Range >\n");
		goto Seat;
	}
}






int confirmed_ticket(){ // A functon to check the reserved tickets
	char buff[1000];
	FILE *fp;
	fp = fopen("Seats_reserved.txt", "r");
	if (!fp)
	{
		printf("\n    < No Reservation Found >\n\nPress any key to return to main menu...");
		getch();
		return 1;
	}
	while (fgets(buff, 1000, fp) != NULL)
		printf("%s", buff);

	printf("Press any key to return to main menu...");
	fclose(fp);
	getch();
}





void LOGO(){ // LOGO FUNCTION OF PROGRAM

	printf(" .^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^.\n");
	printf("<                                                       >\n");
	printf("<       .-^.   |                                        >\n");
	printf("<      /   \\   |\\                                       >\n");
	printf("<      | |\\ \\  | |                                      >\n");
	printf("<      | | \\ \\ | |      ___________                     >\n");
	printf("<      | |  \\ \\| |     | ___   ___ |                    >\n");
	printf("<       \\|   \\ ' /     |/   | |   \\|                    >\n");
	printf("<        |    'v'      |    | |    |                    >\n");
	printf("<                           | |             . .         >\n");
	printf("<                           ; :          .' ____\\       >\n");
	printf("<                          /___\\        /  /            >\n");
	printf("<                                      :  |             >\n");
	printf("<                                      :  |             >\n");
	printf("<                                       \\  \\_____       >\n");
	printf("<                                        '.. ..-'       >\n");
	printf("<                                                       >\n");
	printf("<                                                       >\n");
	printf(" 'v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v'\n");


}




void KID() //Symbolic User defined Function
{
	printf("\t    ._____.\n");
	printf("\t    |     |\n");
	printf("\t    |_____|\n");
	printf("\t.___|_____|___.      'Arigato Guzaimashita'\n");
	printf("\t : '...'  ;\n");
	printf("\t $   ' . ' \n\n");
}



/**********************************<             E              N                     D                >**************************************/