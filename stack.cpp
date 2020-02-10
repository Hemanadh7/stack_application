#include<iostream>
using namespace std;
void PrintMessages(int);
template<typename type>
class Cell
{
	public:
		type val;
		Cell<type>* next;
	public:
		Cell(type value)
		{ 
			this->val = value;
			this->next = NULL;
		}
};

template<typename TYPE>
class stack
{
	private:
		int length = 0;
		Cell<TYPE>* top = NULL;
	public:
		void push(TYPE value)
		{
			Cell<TYPE>* cell = new Cell<TYPE>(value);
			cell->next = top;
			top = cell;
			length++;
		}
		void pop()
		{
			if(top == NULL)
			{
				cout << "Stack is underflow" << endl;
				return;
			}
			top = top->next;
			length--;
		}
		void Traverse()
		{
			Cell<TYPE>* temp = top;
			if(temp == NULL)
			{
				cout << "Stack is underflow" << endl;
				return;
			}
			while(temp != NULL)
			{
				cout << "[" << temp->val << "]";
				temp = temp->next;
			}
			cout << endl;
			cout << "Length: " << length << endl;
		}	
};

void CheckForStackExistance(bool& stackExists)
{
	int opt;
	if(stackExists == true)
		{
			cout << "Stack already exists, you want to create new one or continue on existed one?" << endl;
			cout << " (1) Create new.\n (2) Continue." << endl;
			cin >> opt;
			switch(opt)
			{
				case 1: stackExists = false; break;
				case 2: stackExists = true; break;
				default: cout << "Invalid Option" << endl;						
			}
		}
}

template<typename sType>
void Stack_Creation(stack<sType>& stk, bool &returnToMenu, int& chancesUsed, bool& terminated)
{
	int option2;
	cout << "Enter any of the options below" << endl;
	cout << " (1) Push.\n (2) Pop.\n (3) Display.\n (4) Return back for stack creation menu.\n (5) Exit" << endl;
	cin >> option2;
	switch(option2)
		{
			case 1:
				{
					sType valueToPush;
					cout << "Enter the data to push" << endl;
					cin >> valueToPush;
					stk.push(valueToPush); 
					break;
				}
				case 2: stk.pop(); break;
				case 3: stk.Traverse(); break;
				case 4: returnToMenu = true; break;
				case 5: terminated = true; break;
				default:
					if(chancesUsed < 3) 
						PrintMessages(++chancesUsed);
					else
					{
						cout << "Returning to Stack Creation Menu....!" << endl;
						returnToMenu = true;
					}
			}	
}

int main()
{
	int option1, totalChancesUsed = 0;
	bool intStackExists = false, floatStackExists = false, charStackExists = false, stringStackExists = false;
	int intchancesUsed = 0, floatchancesUsed = 0, charchancesUsed = 0, stringchancesUsed = 0;
	stack<int>* intStack = NULL;
	stack<float>* floatStack = NULL;
	stack<char>* charStack = NULL;
	stack<string>* stringStack = NULL;
	while(1)
	{
		menu:
		cout << "Enter any of the option below: " << endl;
		cout << " (1) Integer Stack. \n (2) Float Stack. \n (3) Character Stack. \n (4) String Stack. \n (5) Exit. "<< endl;
		cin >> option1;
		switch(option1)
		{
			case 1:
			{
				bool isTerminated = false, returnMenu = false;
				intchancesUsed = 0;
				CheckForStackExistance(intStackExists);
				if(intStackExists == false)
				{
					intStack = new stack<int>();
					cout << "Integer Stack is created, ready for use!" << endl;
					intStackExists = true;
				}
				while(1)
				{	
					Stack_Creation(*intStack, returnMenu, intchancesUsed, isTerminated);
					if(returnMenu) goto menu;
					if(isTerminated)	return 0;
				}
				break;
			}
			case 2:
				{
					bool isTerminated = false, returnMenu = false;
					floatchancesUsed = 0;
					CheckForStackExistance(floatStackExists);
					if(floatStackExists == false)
					{
						floatStack = new stack<float>();
						cout << "Float Stack is created, ready for use!" << endl;
						floatStackExists = true;
					}
					while(1)
					{	
						Stack_Creation(*floatStack, returnMenu, floatchancesUsed, isTerminated);
						if(returnMenu) goto menu;
						if(isTerminated)	return 0;
					}
					break;
				}
			case 3:
				{
					bool isTerminated = false, returnMenu = false;
					charchancesUsed = 0;
					CheckForStackExistance(charStackExists);
					if(charStackExists == false)
					{
						charStack = new stack<char>();
						cout << "Float Stack is created, ready for use!" << endl;
						charStackExists = true;
					}
					while(1)
					{	
						Stack_Creation(*charStack, returnMenu, charchancesUsed, isTerminated);
						if(returnMenu) goto menu;
						if(isTerminated)	return 0;
					}
					break;
				}
			case 4:
				{
					bool isTerminated = false, returnMenu = false;
					stringchancesUsed = 0;
					CheckForStackExistance(stringStackExists);
					if(stringStackExists == false)
					{
						stringStack = new stack<string>();
						cout << "Float Stack is created, ready for use!" << endl;
						stringStackExists = true;
					}
					while(1)
					{	
						Stack_Creation(*stringStack, returnMenu, stringchancesUsed, isTerminated);
						if(returnMenu) goto menu;
						if(isTerminated) return 0;
					}
					break;
				}
			case 5: return 0;
			default:
				if(totalChancesUsed < 3) 
					PrintMessages(++totalChancesUsed);
				else
				{
					cout << "Thanks for using! Terminating now....." << endl;
					return 0;						
				}
		}		
	}	
	return 0;
}

void PrintMessages(int n)
{
	if(n == 1)
		cout << "Wrong option selected, you have 2 more chances" << endl;
	else if(n == 2)
		cout << "Again wrong option selected, you have 1 more chances, please choose right option" << endl;
	else
		cout << "Wrong option, this is your last chance, please choose right one" << endl; 
}
