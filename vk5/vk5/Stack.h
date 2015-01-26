// Stack class template.
#pragma once
template< typename T , int SIZE = 10 >
class Stack
{
public:
	Stack(); // default constructor (stack size 10)
	~Stack();
	bool push(const T&); // push an element onto the stack
	bool pop(T&); // pop an element off the stack
	// determine whether Stack is empty
	bool isEmpty() const;
	bool isFull() const;
private:
	int top; // location of the top element
	T *stackPtr; // pointer to the stack
}; // end class Stack
// constructor
template< typename T, int SIZE >
Stack< T , SIZE >::Stack()
{
	// size = s > 0 ? s : 10;
	top = -1; // Stack initially empty
	stackPtr = new T[SIZE]; // allocate memory for elements
} // end Stack constructor

// destructor
template<typename T, int SIZE>
Stack<T, SIZE>::~Stack()
{
	delete[] stackPtr;
}// end ~Stack destructor

// push element onto stack;
// if successful, return true; otherwise, return false
template< typename T, int SIZE >
bool Stack< T , SIZE >::push(const T &pushValue)
{
	if (!isFull())
	{
		stackPtr[++top] = pushValue; // place item on Stack
		return true; // push successful
	} // end if
	return false; // push unsuccessful
} // end function push
// pop element off stack;
// if successful, return true; otherwise, return false
template< typename T, int SIZE >
bool Stack< T , SIZE>::pop(T &popValue)
{
	if (!isEmpty())
	{
		popValue = stackPtr[top--]; // remove item from Stack
		return true; // pop successful
	} // end if
	return false; // pop unsuccessful
} // end function pop

template<typename T, int SIZE>
bool Stack<T, SIZE>::isEmpty() const
{
	return top == -1;
}
template<typename T, int SIZE>
bool Stack<T, SIZE>::isFull() const
{
	return top == SIZE - 1;
}