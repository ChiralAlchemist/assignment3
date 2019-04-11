#include "Book.h"



Book::Book()
{
	title = "";
	author = "";
	subject = "";
}

Book::Book(string bookAuthor, string bookSubject, string bookTitle)
{
	author = bookAuthor;
	title = bookTitle;
	subject = bookSubject;
}

string Book::getData(string type)
{
	if (type == "title")
	{
		return title;
	}
	
	if (type == "author")
	{
		return author;
	}

	if (type == "subject")
	{
		return subject;
	}

	return "invalid input";
}

string Book::getAuthor()
{
	return author;
}

string Book::getTitle()
{
	return title;
}

string Book::getSubject()
{
	return subject;
}

Book::~Book()
{
}
