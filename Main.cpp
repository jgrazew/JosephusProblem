//Joseph Circle Problem
//By: Joe Grazewski


#include "stdafx.h"
#include<iostream>

struct circularNode
{
	int data;
	circularNode* next;
};

circularNode *josephusPosition();
void showWinner(circularNode*);

int main()
{

	showWinner(josephusPosition());
	
    return 0;
}


circularNode *josephusPosition()
{
	circularNode *temp;
	circularNode *head;	

	int players;
	int number;

	std::cout << "Enter the number of players in game: " << std::endl;
	std::cin >> players;
	std::cout << "Every xth person gets eliminated- enter x: " << std::endl;
	std::cin >> number;

	//Create a circular list containing the players in our game
	head = new circularNode;
	temp = head;
	temp->data = 1;
	for (int i = 2; i <= players; ++i)
	{
		temp->next = new circularNode;
		temp = temp->next;
		temp->data = i;
	}
	//close the circular list
	temp->next = head;
	//Eliminate every xth player as long until there is 1 remaining
	for (int count = players; count > 1; --count)
	{
		for (int i = 1; i < number; ++i)
			temp = temp->next;
    //circularNode q will be used to delete dynamically allocated memory
		circularNode *q = temp->next; 
    //Eliminate player from list
		temp->next = temp->next->next; 
    //Free eliminated players node from memory
		delete q;						
	}
	return temp;
}

void showWinner(circularNode* show)
{
	std::cout << "The winner is: " << show->data << std::endl;
}
