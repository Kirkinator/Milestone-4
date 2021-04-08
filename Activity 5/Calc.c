#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
//My structure to take down the users name and job description
struct student {
	char name[50];
	char job[50];

};
union Data { //Union to display copyright information
	int date;
	float version;
	char string[50];

};

void display(struct student s); //Calling my Structure for name and job title of user 
int sum(int*); //declare my array for sum of 10 numbers

int main()
{
	// create some variables that allow the user to input 2 numbers
	int a, b, math;

	int c[10], i, s; //variables for array

	union Data data;
	data.date = 2021;
	printf("publication date : %d\n", data.date);

	data.version = 1.03;
	printf("version : %f\n", data.version);

	strcpy(data.string, "Christopher Scanlon-Kirk");
	printf("Developed by : %s\n", data.string);


	//Passing structure to function will take your name and job description
	struct student s1;
	printf("Enter your first name:\n");
	scanf("%s", s1.name);
	printf("Enter your Job title:\n");
	scanf("%s", &s1.job);
	display(s1);// this will display the name and job you listed at the beginning


	/*Prompts the user to select a choice 1-5 that will determine the math to be done*/
	printf("Select an option: \n1. Addition\n 2. Subtraction\n 3. Multiplication\n 4.Division\n 5.Sum of 10 numbers\n\n");


	//takes the user input for their 1-5 calculation choice. (+-*/)
	scanf("%d", &math);

	// Added this if/else loop to notify the user they made an invalid choice
	if (math > 6)
	{
		printf("You entered an incorrect input\n");
	}
	else
	{
		/*Asks the user to enter their two numbers for their math calculation*/
		printf("Enter two numbers for your calculation you have chosen in this format (a, b). If you selected option 5, ignore this prompt and move onto the next after inputing two numbers.");
		/*Takes the user input for a and b with "%d" format*/
		scanf_s("%d %d", &a, &b);
	}
	//if/else loops that will help determine which action to perform based on previous user input.
	if (math == 1) //Addition loop
	{
		printf("The Addition of %d and %d is %d\n", a, b, (a + b));
	}
	else if (math == 2) //Subtraction loop
	{
		printf("The Subtraction of %d and %d is %d\n", a, b, (a - b));
	}
	else if (math == 3) // Multiplication loop
	{
		printf("The Multiplication of %d and %d is %d\n", a, b, (a * b));
	}
	else if (math == 4) //Division loop
	{
		if (b != 0) //If/else loop statement that doesnt let users divide by 0
			printf("The Division of %d and %d is %d\n", a, b, (a / b));
		else
			printf("Number cannot be divided by 0\n");
	}
	else if (math == 5) //sum of numbers array
	{
		printf("\nEnter 10 numbers");
		for (i = 0; i < 10; i++)
			scanf_s("%d", &c[i]);

		s = sum(c); //Calling the function
		printf("\nSum = %d", s);
	}

	else // Lets the user know the inputs are wrong and which ones you can choose
	{
		printf("Please enter an option that is 1-6.\n");
	}

	return 0;
}
//array to determine the sum of 10 numbers
int sum(int* p)
{
	int i, s = 0;
	for (i = 0; i < 10; i++)
	{
		s = s + *p;  //value at address
		p++;
	}
	return s;
}
//my function for displaying the name and job title for the structure
void display(struct student s) {
	printf("\nDisplaying Information\n");
	printf("\nName: %s", s.name);
	printf("\njob: %s\n", s.job);
}

