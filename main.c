/*CSC 250 DSU Homework Two-dimensional Array, Mike Benton
  Program using 2 dimension array to recieve user input
  on total points possible on test scores and the student 
  test scores on those tests and output grade
*/

#include<stdio.h>
#include<math.h>

void printGrade(float average); //takes average of points and prints corresponding grade

int main (void)

{
	int row;			    //counter for row
	int column;		        //counter for column
	int studentGrade = 0;	//stores point earned by students	
	int totalGrade = 0;	    //stores total points possible
	int numStudents;	    //stores number of students in class
	int numTests;		    //stores number of tests taken		

	printf("\nProgram to figure out student points\n\n");	
		
	printf("How many students are in your class? :");
	scanf("%d", &numStudents);

	printf("How many tests have been given? :");
	scanf("%d", &numTests);

	printf("\nYou have %d students, and have given %d tests.\n\n", numStudents, numTests);

	int array[numStudents][numTests];  //2D array holds number of students(rows) and number of tests(columns)
					     
	printf("Please enter the total points available for each of the %d tests given:\n\n", numTests);
	
//Enter Values for each test into first row of array ( total points available per test )

	int test = 1;	

	while( test <= numTests  )
	{
		for ( column = 0 ; column < numTests ; column++)
		{
			printf("ENTER TEST %d, TOTAL POINTS POSSIBLE: ", test); 

			scanf("%d", &array[0][column]);

			test++;
		}
		printf("\n"); //formatting			
	}

//Loop to student scores into array (start at row 1, not 0 ; 0 is the header row holding total points possible)

	test = 1; //re-initialize
	int student = 1;
	
	for ( row = 1 ; row <= numStudents ; row++)
	{
		for ( column = 0 ; column < numTests ; column++)
		{
			printf("ENTER STUDENT %d, TEST SCORE %d: ",student, test); 

			scanf("%d", &array[row][column]);

			test++;
		}
		student++;    //increment for next student
		test = 1;     //reset to test 1 for next student
		printf("\n"); //formatting
	}			

//Loop to ADD TOTAL POINTS possible ( first row )

	for ( row = 0 ; row < 1 ; row++ )
	{
		for ( column = 0 ; column < numTests ; column++)
		{
			totalGrade += array[row][column];
		}
	}

//Loop to PRINT VALUES to screen

	for ( row = 1 ; row <= numStudents ; row++)
	{
		for ( column = 0 ; column < numTests ; column++)
		{
			studentGrade += array[row][column];
		}

		printf("The points for student #%d (%d / %d)\n", row, studentGrade, totalGrade);
		
		float gradePoint = (float)studentGrade/(float)totalGrade; //get average
		
		gradePoint = round(gradePoint * 100.0)/100.0;
	
		printf("Average is %.2f\n", gradePoint);

		printGrade(gradePoint);

		studentGrade = 0;	//Re-initialize student grade for next row
		printf("\n");           //formatting
	}
} //END MAIN

void printGrade(float average){

	if( average > .899999 ){
		printf("Students final grade is an A\n");
	}
	else if( average > .799999 ){
		printf("Students final grade is a B\n");
	}
	else if( average > .699999 ){
		printf("Students final grade is a C\n");
	}
	else if( average > .599999 ){
		printf("Students final grade is a D\n");
	}
	else{
		printf("Student has failed the course\n");
	}
}