#include "Book.h"
int main()
{
	Chrono::Date d(2014, Chrono::Date::dec, 12);
	try
	{
		Book::Book book("12-12-12-x12", "HelloWorld", "Me", d, Book::Book::childern, Book::Book::RESERVER);
		cout << book << endl;
	}
	catch (Book::Book::Invalid)
	{
		error("Invalid book");
	}
	return 0;
}