#include <stdio.h>
void choice(char x);
int main(){
	char x = '0';
	int  i = 0;
	char v = '0';
	char A[100], ch = '0';
	printf("Here is the feedback form for the the services we offered you in the train;s journey!!!!\n");
	printf("Did we respond to your customer services today?\n");
	printf("a)Yes b)Somewhat c)no\n");
	choice(v);
	printf("Was our customer service provided to you in a accessible manner?\n");
	printf("a)yes b)somewhat c)no\n");
	choice(v);
	printf("How would you rate our railway stations and platforms\n");
	printf("a)Great b)Fair c)Bad\n");
	choice(v);
	printf("How would you rate our trains?");
	printf("a)Comfortable b)Normal c)Uncomfortable\n");
	choice(v);
	printf("How would you rate our ticketing process?\n");
	printf("a)Rapid b)Normal c)Tiresome\n");
	choice(v);
	printf("\n\nt\t\t\t*********************\n");
	printf("Please fill out the form below to tell what we can do The form should not be more than 100 words and press enter to terminate\n\n");
	while (ch != '\n'){
		ch = getchar();
		A[i] = ch;
		i++;
	}
	getchar();
	return 0;
}

void choice(char x){
	scanf(" %c", &x);
	if (x == 'a'){
		printf("Thnx for the appreceation we will try to do more outstanding\n");
	}
	else if (x == 'b'){
		printf("Ok tell us in the form at last that how we can improve our service\n");

	}
	else if (x == 'c'){
		printf("Oh sry that we cannot come up to your expectations.Plz tell us in the form below that what we can do to make our service better\n");

	}
	
}