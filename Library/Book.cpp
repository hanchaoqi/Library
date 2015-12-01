#include "Book.h"
namespace Book{
	string booktype_to_string(Book::BookType type)
	{
		string result;
		switch (type)
		{
		case Book::fiction:
			result = "fiction";
			break;
		case Book::nofiction:
			result = "nofiction";
			break;
		case Book::periodical:
			result = "periodical";
			break;
		case Book::biography:
			result = "biography";
			break;
		case Book::childern:
			result = "childern";
			break;
		}
		return result;
	}
	bool is_valid_ISBN(string ISBN)
	{//n-n-n-x
		const char split = '-';
		string n1, n2, n3, x;
		int i, flag = 1;
		for (i = 0; i < ISBN.length(); i++)
		{
			if (ISBN[i] == split)
			{
				flag++;
				if (flag == 4)
				{
					i++;
					break;
				}

			}
			else if (!(ISBN[i] >= '0'&&ISBN[i] <= '9'))
			{
				return false;
			}

		}
		for (; i < ISBN.length(); i++)
		{
			if (!((ISBN[i] >= '0'&&ISBN[i] <= '9') || (ISBN[i] >= 'a'&&ISBN[i] <= 'z') || (ISBN[i] >= 'A'&&ISBN[i] <= 'Z')))
				return false;
		}
		return true;
	}

	bool operator==(const Book& a, const Book& b)
	{
		if (a.ISBN() == b.ISBN())
			return true;
		return false;
	}
	bool operator!=(const Book& a, const Book& b)
	{
		return !(a == b);
	}

	ostream& operator<<(ostream& os, const Book& book)
	{
		Chrono::Date d = book.Copy_right_date();
		string Loaned;
		if (book.Loaned())
			Loaned = "Loaned";
		else
			Loaned = "Reserver";
		return os << '(' << book.ISBN() << ','
			<< book.Name() << ',' << book.Author() << ','
			<< book.Copy_right_date() << ',' << booktype_to_string(book.Type()) << ',' << Loaned << ')';
	}

	Book::Book(string ISBN, string Name, string Author, Chrono::Date Copy_right_date, BookType Type, State Loaned)
		:isbn(ISBN), name(Name), author(Author), copy_right_date(Copy_right_date), type(Type), loaned(Loaned)
	{
		if (!is_valid_ISBN(ISBN))
			throw Invalid();
	}
	bool Book::loan()
	{
		if (loaned == RESERVER)
			loaned = LOANED;
		else
			return false;
		return true;
	}
	bool Book::back()
	{
		if (loaned == LOANED)
			loaned = RESERVER;
		else
			return false;
		return true;
	}
}