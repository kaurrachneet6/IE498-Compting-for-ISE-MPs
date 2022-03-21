// Rachneet Kaur
// IE 498 HW 3 Ques 1
// Performing arithmetic operation
#include<iostream>
using namespace std;
int main()
{
	int value1, value2; 
	char oper;
	cout << "Type in a simple expression: ";
	cin >> value1 >> oper >> value2;                  // Inputs
	switch (oper)
	{
	case '+': cout << value1 + value2<<"\n"; break;   // Adding the values if operator is '+'
	case '-': cout << value1 - value2<<"\n"; break;   // Substracting the values if operator is '-'
	case '*': cout << value1*value2<<"\n"; break;    // Multiplying the values if operator is '*'
	case '/': if (value2 == 0)                       // Not allowing division if Denominator = 0
		           cout << "Division by 0 is not possible\n";
			  else cout << (float) value1/value2<<"\n";     // Else divide, typecasting to float to show decimal quoitent 
			  break;
	case '%': cout << value1 % value2<<"\n";        // Taking the remainder if operator is '%'
	}

	return 0;
}