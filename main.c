

#include <stdio.h>
#include<math.h>

/*CSC 250 DSU Homework Two-dimensional Array, Mike Benton
  A Program using 2 dimensional array to recieve input
  for the number of tests given and the total points possible on test scores,
  and the student test scores and calculate final output grade
*/

//function to take the average of points and print corresponding grade
void printGrade(float average); 

int main (void)

{
	int row;			    //counter for row
	int column;		        //counter for column
	int studentGrade = 0;	//stores points earned by students	
	int totalGrade = 0;	    //stores total points possible
	int numStudents;	    //stores number of students in class
	int numTests;		    //stores number of tests taken		

	printf("\n--------Program to figure out total of student test scores--------\n\n");	
		
	printf("How many students are in your class? :");
	scanf("%d", &numStudents);

	printf("How many tests have been given? :");
	scanf("%d", &numTests);

	printf("\nYou have %d students, and have given %d tests.\n\n", numStudents, numTests);
	
	//Number of students(rows) and number of tests(columns)
	int array[numStudents][numTests];  
					     
	printf("Please enter the total points available for each of the %d tests given:\n\n", numTests);
	
	
//Enter Values for each test into the first(0th) row of array ( this is the total points available per test )

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

//Loop for student scores into array (start at row 1, not 0 ; 0 is the header row holding total points possible)

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

//Loop to ADD TOTAL POINTS possible for tests ( first(0th) row )

	for ( row = 0 ; row < 1 ; row++ )
	{
		for ( column = 0 ; column < numTests ; column++)
		{
			totalGrade += array[row][column];
		}
	}

//Loop to PRINT VALUES of student test scores

	for ( row = 1 ; row <= numStudents ; row++)
	{
		for ( column = 0 ; column < numTests ; column++)
		{
			studentGrade += array[row][column];
		}

		printf("The points for student #%d (%d / %d)\n", row, studentGrade, totalGrade);
		
		//get average
		float gradePoint = (float)studentGrade/(float)totalGrade; 
		
		gradePoint = round(gradePoint * 100.0)/100.0;
	
		printf("Average is %.2f\n", gradePoint);

		printGrade(gradePoint);

		studentGrade = 0;	//Re-initialize student grade for next row
		printf("\n");       //formatting
	}
} //END MAIN


//FUNCTION TO RECIEVE AVERAGE OF TOTAL POINTS AND PRINT GRADE
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
