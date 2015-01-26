// Stack class template test program. Function main uses a
// function template to manipulate objects of type Stack< T >.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "Stack.h" // Stack class template definition

using std::cin; using std::cout; using std::endl;

void main_1();

// function template to manipulate Stack< T >
template< typename T , int SIZE = 10 >
void testStack
(
Stack< T , SIZE > &theStack, // reference to Stack< T >
T value, // initial value to push
T increment, // increment for subsequent values
const char *stackName) // name of the Stack < T > object
{
	cout << "\nPushing elements onto " << stackName << '\n';
	while (theStack.push(value))
	{
		cout << value << ' ';
		value += increment;
	} // end while
	cout << "\nStack is full. Cannot push " << value
		<< "\n\nPopping elements from " << stackName << '\n';
	while (theStack.pop(value))
		cout << value << ' ';
	cout << "\nStack is empty. Cannot pop\n";
} // end function testStack
int main()
{
	char number[2];
	cout << "Number of the excercise (1,2,3,4): ";
	cin.getline(number, 2);

	switch (number[0]){
	case '1':
		main_1();
		break;
	};

	system("pause");
	return 0;
}

void main_1()
{
	Stack< double, 5 > doubleStack;
	Stack< int > intStack;
	testStack(doubleStack, 1.1, 1.1, "doubleStack");
	testStack(intStack, 1, 1, "intStack");
}