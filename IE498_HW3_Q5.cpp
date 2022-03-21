// Rachneet Kaur
// IE 498 HW 3 Ques 5
// File operations and computing if student passed or not
#include<iostream>
#include<fstream>                                 // For file operations
using namespace std;
int main()
{
	int score = 0;                              // No. of correct answers
	float perc;                                 // Percentage of correct answers
	char corr[21], stud[21];                    // Character arrays to store correct and student's answers
	ifstream file1("CorrectAnswers.txt");      // Opening the files in reading mode
	ifstream file2("StudentAnswers.txt");
	for (int i = 0; i < 20; i++)               // Reading the answers from files
	{
	file1 >>corr[i];
	file2 >> stud[i];
	if (corr[i] == stud[i]) score++;          // If answers match, incrementing the score
    }
	file1.close();
	file2.close();                           // Closing the files after operations completed
	perc = score * 100 / 20;                 // Computing the percentage
	cout << "\nStudent's total no. of correct answers out of 20 are: " << score;
	cout << "\nStudent's percentage of correct answers is: " << perc<<"%"; 
	if (perc >= 75) cout << "\nStudent has passed the exam.\n";         // Passing criteria is 75%
	else cout << "\nStudent has failed the exam.\n";
	return 0;
}