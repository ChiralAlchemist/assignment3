#pragma once
#include "Book.h"
#include "UiUtils.h"
const int MAX_BOOKS = 50;
const int NUL = -1;
struct BookNode
{
	Book book;
	int next;
};

struct MemoryType
{
	int free; 
	BookNode* nodes;
};

class BookRecords
{
public:
	BookRecords();
	BookRecords(UiUtils* bookUi);
	~BookRecords();
	void addBook(string author, string subject, string title);
	void deleteBook(string title);
	void InitializeMemory(int maxItems, MemoryType & storage);
	void GetNode(int & nodeIndex, MemoryType & storage);
	void FreeNode(int nodeIndex, MemoryType & storage);
	int findSpot(string value, string type);
	void printBookRecords(string type);
	void updateKeyOrder(string key, int spot, int bookDataLoc);
private:
	int* getKeyOrder(string type);
	int titleOrder[MAX_BOOKS];
	int authorOrder [MAX_BOOKS];
	int subjectOrder[MAX_BOOKS];
	int list;
	int free; 
	int numberOfBooks;
	BookNode bookData[MAX_BOOKS];
	UiUtils* ui;
};

