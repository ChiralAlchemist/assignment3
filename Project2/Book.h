#pragma once
#include <iostream>
#include <string>
using namespace std;
class Book
{
public:
	Book();
	Book(string author, string subject, string title);
	string getData(string type);
	string getAuthor();
	string getTitle();
	string getSubject();
	~Book();
private:
	string title;
	string author;
	string subject;
};

