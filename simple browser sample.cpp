
#include <iostream>
#include <string>
#include<stack>
#include "LStack.h"

using namespace std;

int main() 
{
	int i;
	char cho;//choose 
	string webs;//web pages
	Stack<string> backward_stack;
	Stack<string> forward_stack;

	cout << "Choose(N)ew page, go (B)ack one page, go (F)orward one page (Q)uit:";
	cin >> cho;
	while (cho != 'Q' && cho != 'q') 
	{
		switch (cho) 
		{
			case'n':
			case'N':
				cout << "Enter new page address:";
				cin >> webs;
				webs.erase(0, 4);//delete "www."
				webs.erase(webs.find('.'), webs.length()-1); //delete ".com" -> webs.find('.')->positon of 2nd dot ".org" or ".com"
				backward_stack.push(webs);//add new page
				if (!forward_stack.isEmpty()) 
				{
					cout << "Forward Stack cleared.\n";
					forward_stack.clear();
				}
				break;
			case 'b':
			case 'B':
				if (backward_stack.isEmpty()) 
				{
					cout << "Error! There is no page before.\n";
    				break;
				}
				webs = backward_stack.pop();//go backward
				if (backward_stack.isEmpty()) 
				{
					cout << "Error! There is no page before.\n";
					backward_stack.push(webs);
				}
				else 
				{
    				forward_stack.push(webs);
    				webs = backward_stack.peek();
    				cout << "You have gone back one page.\n";
				}
				break;
			case 'f':
			case 'F':
				if (forward_stack.isEmpty())
				{
					cout << "Error! There is no Forward page.\n";
					break;
				}
				webs = forward_stack.pop();
				if (forward_stack.isEmpty())
				{
					cout << "Error! There is no Forward page.\n";
					forward_stack.push(webs);
				}
				else
				{
					backward_stack.push(webs);
					webs = forward_stack.peek();
					cout << "You have gone to the Forward page.\n";
				}
				break;
		}
		cout << "You are currently visiting " << webs << ".\n";
		cout << "Choose(N)ew page, go (B)ack one page, go (F)orward one page (Q)uit:";
		cin >> cho;
	}
	cout << "Thank you for using this simple browser. Have a nice day.\n";
}
