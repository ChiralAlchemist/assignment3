#include <iostream>
#include "UiUtils.h"
#include <array>
#include <vector>
#include "Book.h"
#include "BookRecords.h"

using namespace std;
int main() 
{
	cout << "Hello World" << endl; 
	
	UiUtils programUi;
	UiUtils *ptrUi = &programUi;
	string userInput;
	BookRecords programRecords = BookRecords(ptrUi);
	//programUi.startingOperations();
	
	while (userInput != "Quit") 
	{
		programUi.sendOutput("Start a new task (Insert, Delete, List, Help,  Quit)");
		vector<string> acceptedTasks = { "Insert", "Delete", "List", "Help",  "Quit" };
		programUi.recieveInput(userInput, acceptedTasks);

		if (userInput == "Insert")
		{
			string bookTitle;
			string author;
			string subject;
			programUi.sendOutput("Enter Book Title");
			programUi.recieveInput(bookTitle);
			programUi.sendOutput("Enter Book Author");
			programUi.recieveInput(author);
			programUi.sendOutput("Enter Book Subject");
			programUi.recieveInput(subject);

			programRecords.addBook(author, subject, bookTitle);
			programUi.conformationOutput("Added " + bookTitle);
			//make a book object
			//add to array of records 


		}
		else if (userInput == "Delete")
		{
			string deleteBook;
			programUi.sendOutput("Enter Book Title to be deleted");
			programUi.recieveInput(deleteBook);


		}
		else if (userInput == "List")
		{
			string keyString;
			programUi.sendOutput("Enter Key to Order By");
			vector<string> keys = { "title", "author", "subject" };
			programUi.recieveInput(keyString, keys);
			programRecords.printBookRecords(keyString);
		}
		else if (userInput == "Help")
		{
			// TODO make a help message describing commands
		}
		else if (userInput == "Quit")
		{
			programUi.sendOutput("Saving Program Data exiting out");

			//TODO write outPut function; 
		}

		programUi.sendOutput(""); //to prevent wall of text
	}
	
	system("pause");
}

