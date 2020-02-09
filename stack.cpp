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
		Cell(){}
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
		Cell<TYPE>* head = NULL;
	public:
		void push(TYPE value)
		{
			Cell<TYPE>* temp = head;
			if(temp == NULL)
			{
				Cell<TYPE>* newCell = new Cell<TYPE>(value);
				newCell->next = NULL;
				head = newCell;
				length++;
				return;
			}
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			Cell<TYPE>* newCell = new Cell<TYPE>(value);
			temp->next = newCell;
			newCell->next = NULL;
			length++;
		}
		void pop()
		{
			Cell<TYPE> *cur = head, *temp = head;
			if(temp == NULL)
			{
				cout << "Stack is underflow" << endl;
				return;
			}
			while(temp->next != NULL)
			{
				cur = temp;
				temp = temp->next;
			}
			cur->next = NULL;
			length--;
		}
		void Traverse()
		{
			Cell<TYPE>* temp = head;
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

int main()
{
	int option1, option2;
	bool intStackExists = false, floatStackExists = false, charStackExists = false, stringStackExists = false;
	int intchancesUsed = 0, floatchancesUsed = 0, charchancesUsed = 0, stringchancesUsed = 0;
	stack<int>* intStack = NULL;
	stack<float>* floatStack = NULL;
	stack<char>* charStack = NULL;
	stack<string>* stringStack = NULL;
	int totalChancesUsed = 0;
	while(1)
	{
		menu:
		cout << "Enter any of the option below: " << endl;
		cout << " (1) Integer Stack. \n (2) Float Stack. \n (3) Character Stack. \n (4) String Stack. \n (5) Exit. "<< endl;
		cin >> option1;
		switch(option1)
		{
			// Integer Stack Creation.
			case 1:
				int inOp;
				intchancesUsed = 0;
				if(intStackExists == true)
				{
					cout << "Stack already exists, you want to create new one or continue on existed one?" << endl;
					cout << " (1) Create new.\n (2) Continue." << endl;
					cin >> inOp;
					switch(inOp)
					{
						case 1: intStackExists = false; break;
						case 2: intStackExists = true; break;
						default: cout << "Invalid Option" << endl;						
					}
				}
				if(intStackExists == false)
				{
					intStack = new stack<int>();
					cout << "Integer Stack is created, ready for use!" << endl;
					intStackExists = true;
				}
				while(1)
				{	
					cout << "Enter any of the options below" << endl;
					cout << " (1) Push.\n (2) Pop.\n (3) Display.\n (4) Return back for stack creation menu.\n (5) Exit" << endl;
					cin >> option2;
					switch(option2)
					{
						// Push
						case 1:
							int valueToPush;
							cout << "Enter the value to push" << endl;
							cin >> valueToPush;
							intStack->push(valueToPush); 
							break;
						// Pop
						case 2: intStack->pop(); break;
						// Display
						case 3: intStack->Traverse(); break;
						// Returning back to creation menu
						case 4: goto menu;
						// Exit
						case 5: return 0;
						default:
							if(intchancesUsed < 3) 
								PrintMessages(++intchancesUsed);
							else
							{
								cout << "Returning to Stack Creation Menu....!" << endl;
								goto menu;
							}
					}
				}
				break;
			// Float Stack Creation.
			case 2:
				int flOp; 
				floatchancesUsed = 0;
				if(floatStackExists == true)
				{
					cout << "Float Stack already exists, you want to create new one or continue on existed one?" << endl;
					cout << " (1) Create new.\n (2) Continue." << endl;
					cin >> flOp;
					switch(flOp)
					{
						case 1: floatStackExists = false; break;
						case 2: floatStackExists = true; break;
						default: cout << "Invalid Option" << endl;						
					}
				}
				if(floatStackExists == false)
				{
					floatStack = new stack<float>();
					cout << "Float Stack is created, ready for use!" << endl;
					floatStackExists = true;
				}
				while(1)
				{	
					cout << "Enter any of the options below" << endl;
					cout << " (1) Push.\n (2) Pop.\n (3) Display.\n (4) Return back for stack creation menu.\n (5) Exit" << endl;
					cin >> option2;
					switch(option2)
					{
						// Push
						case 1:
							float valueToPush;
							cout << "Enter the value to push" << endl;
							cin >> valueToPush;
							floatStack->push(valueToPush); 
							break;
						// Pop
						case 2: floatStack->pop(); break;
						// Display
						case 3: floatStack->Traverse(); break;
						// Returning back to creation menu
						case 4: goto menu;
						// Exit
						case 5: return 0;
						default:
							if(floatchancesUsed < 3) 
								PrintMessages(++floatchancesUsed);
							else
							{
								cout << "Returning to Stack Creation Menu....!" << endl;
								goto menu;
							}
					}
				}
				break;
			// Character Stack Creation.
			case 3:
				int chOp;
				charchancesUsed = 0;
				if(charStackExists == true)
				{
					cout << "Character Stack already exists, you want to create new one or continue on existed one?" << endl;
					cout << " (1) Create new.\n (2) Continue." << endl;
					cin >> chOp;
					switch(chOp)
					{
						case 1: charStackExists = false; break;
						case 2: charStackExists = true; break;
						default: cout << "Invalid Option" << endl;						
					}
				}
				if(charStackExists == false)
				{
					charStack = new stack<char>();
					cout << "Character Stack is created, ready for use!" << endl;
					charStackExists = true;
				}
				while(1)
				{	
					cout << "Enter any of the options below" << endl;
					cout << " (1) Push.\n (2) Pop.\n (3) Display.\n (4) Return back for stack creation menu.\n (5) Exit" << endl;
					cin >> option2;
					switch(option2)
					{
						// Push
						case 1:
							char valueToPush;
							cout << "Enter the character to push" << endl;
							cin >> valueToPush;
							charStack->push(valueToPush); 
							break;
						// Pop
						case 2: charStack->pop(); break;
						// Display
						case 3: charStack->Traverse(); break;
						// Returning back to creation menu
						case 4: goto menu;
						// Exit
						case 5: return 0;
						default:
							if(charchancesUsed < 3) 
								PrintMessages(++charchancesUsed);
							else
							{
								cout << "Returning to Stack Creation Menu....!" << endl;
								goto menu;
							}
					}
				}				 
				break;
			// String Stack Creation.
			case 4:
				int strOp;
				stringchancesUsed = 0;
				if(stringStackExists == true)
				{
					cout << "String Stack already exists, you want to create new one or continue on existed one?" << endl;
					cout << " (1) Create new.\n (2) Continue." << endl;
					cin >> strOp;
					switch(strOp)
					{
						case 1: stringStackExists = false; break;
						case 2: stringStackExists = true; break;
						default: cout << "Invalid Option" << endl;						
					}
				}
				if(stringStackExists == false)
				{
					stringStack = new stack<string>();
					cout << "String Stack is created, ready for use!" << endl;
					stringStackExists = true;
				}
				while(1)
				{	
					cout << "Enter any of the options below" << endl;
					cout << " (1) Push.\n (2) Pop.\n (3) Display.\n (4) Return back for stack creation menu.\n (5) Exit" << endl;
					cin >> option2;
					switch(option2)
					{
						// Push
						case 1:
						{
							string valueToPush;
							cout << "Enter the string to push" << endl;
							cin >> valueToPush;
							stringStack->push(valueToPush); 
							break;
						}
						// Pop
						case 2: stringStack->pop(); break;
						// Display
						case 3: stringStack->Traverse(); break;
						// Returning back to creation menu
						case 4: goto menu;
						// Exit
						case 5: return 0;
						default:
							if(stringchancesUsed < 3) 
								PrintMessages(++stringchancesUsed);
							else
							{
								cout << "Returning to Stack Creation Menu....!" << endl;
								goto menu;
							}
					}
				} 
				break;
			// No Stack Creation.
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

