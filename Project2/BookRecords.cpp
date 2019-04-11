#include "BookRecords.h"



BookRecords::BookRecords()
{
	free = 0;
	list = 0;
}

BookRecords::BookRecords(UiUtils* bookUi)
{
	free = 0;
	list = 0;
	ui = bookUi;
	numberOfBooks = 0;
}

BookRecords::~BookRecords()
{
}

int BookRecords::findSpot(string value, string type)
{
	int* keyOrder = getKeyOrder(type);
	string valueAtLocation = bookData[keyOrder[0]].book.getData(type);
	string nextVal;
	//cout<<"Value is "<< value << " ValueAtLocation " << valueAtLocation << " nextVal " << nextVal << endl;
	if(value < valueAtLocation) 
	{
		return 0;
	}
	
	for (int i = 0; i < numberOfBooks; i++)
	{

		nextVal = bookData[keyOrder[i+1]].book.getData(type);
		valueAtLocation = bookData[keyOrder[i]].book.getData(type);
		//cout << "ValueAtLocation " << valueAtLocation << " nextVal " << nextVal << endl;
		if (value >= valueAtLocation && value < nextVal)
		{
			//cout << "returned from key order" << endl;
			return i+1;
		}
	}
	return numberOfBooks;
}

void BookRecords::printBookRecords(string type)
{
	ui->sendOutput("Hello from Print Book Records");
	int* keyOrder = getKeyOrder(type); //ref to the keyOrder array 
	for (int i = 0; i < numberOfBooks; i++)
	{
		Book currentBook = bookData[keyOrder[i]].book;
		ui->sendOutput("Title: " + currentBook.getTitle());
		ui->sendOutput("By " + currentBook.getAuthor(), 4);
		ui->sendOutput("Subject: " + currentBook.getSubject(), 4);
		ui->sendOutput("");
	}
}

void BookRecords::updateKeyOrder(string key, int spot, int bookDataLoc)
{
	int* keyOrder = getKeyOrder(key);
	int tempVal = keyOrder[spot];
	bool test = spot + 1 > numberOfBooks;

	for (int i = numberOfBooks; i > spot; i--)
	{
		keyOrder[i] = keyOrder[i-1];	
	}
	keyOrder[spot] = bookDataLoc;

}

int * BookRecords::getKeyOrder(string type)
{
	int* keyOrder;
	if (type == "subject")
	{
		keyOrder = subjectOrder;
	}
	else if (type == "author")
	{
		keyOrder = authorOrder;
	}
	else
	{
		keyOrder = titleOrder;
	}

	return keyOrder;
}

void BookRecords::addBook(string author, string subject, string title)
{
	Book newBook = Book(author, subject, title);
	BookNode newBookNode;
	newBookNode.book = newBook;
	newBookNode.next;
	
	//check if is first book
	if (numberOfBooks == 0)
	{
		bookData[0] = newBookNode;
		authorOrder[0] = 0;
		titleOrder[0] = 0;
		subjectOrder[0] = 0;
		numberOfBooks++;
		free++;
		return;
	}
	
	int spot = findSpot(title, "title");
	free++;
	updateKeyOrder("title", spot, free);
	spot = findSpot(subject, "subject");
	updateKeyOrder("subject", spot, free);
	spot = findSpot(author, "author");
	updateKeyOrder("author", spot, free);
	bookData[free] = newBookNode;
	numberOfBooks++;
}

void BookRecords::deleteBook(string title)
{
	//find the book
	//delete the book 
	//update the keys
}


