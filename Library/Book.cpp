#include "Chrono.h"

class Book
{
public:
	enum State{
		Loaned = true,Reserver=false
	};
	class Invalid{};

	bool loan();
	bool back();

	Book(string ISBN, string Name, string Author, Chrono::Date Copy_right_date, State loaned);

	string ISBN() const{ return isbn; }
	string Name()const{ return name; }
	string Author()const{ return author; }
	Chrono::Date Copy_right_date()const{ return copy_right_date; }
private:
	string isbn;
	string name;
	string author;
	Chrono::Date copy_right_date;
	State loaned;
};

bool is_valid_ISBN(string ISBN);

int main()
{
	Chrono::Date d(2014, Chrono::Date::dec, 12);
	Book book("12-12-12-x12", "HelloWorld", "Me", d, Book::Reserver);
	return 0;
}

bool is_valid_ISBN(string ISBN)
{//n-n-n-x
	const char split = '-';
	string n1, n2, n3, x;
	int i, flag = 1;
	for (i = 0; i < ISBN.length(); i++)
	{
		if (!(ISBN[i] >= '0'&&ISBN[i] <= '9'))
		{
			return false;
		}			
		else if (ISBN[i] == split)
		{
			flag++;
			if (flag == 4)
			{
				i++;
				break;
			}
		}
		
	}
	for (; i < ISBN.length(); i++)
	{
		if (!((ISBN[i] >= '0'&&ISBN[i] <= '9') || (ISBN[i] >= 'a'&&ISBN[i] <= 'z') || (ISBN[i] >= 'A'&&ISBN[i] <= 'Z')))
			return false;
	}
	return true;
}

Book::Book(string ISBN, string Name, string Author, Chrono::Date Copy_right_date, State Loaned)
:isbn(ISBN), name(Name), author(Author), copy_right_date(Copy_right_date), loaned(Loaned)
{
	if (!is_valid_ISBN(ISBN))
		throw Invalid();
}
bool Book::loan()
{
	if (loaned == Reserver)
		loaned = Loaned;
	else
		return false;
	return true;
}
bool Book::back()
{
	if (loaned == Loaned)
		loaned = Reserver;
	else
		return false;
	return true;
}