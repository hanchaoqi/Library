#ifndef BOOK_H
#define BOOK_H

#include "Chrono.h"
namespace Book{
	class Book
	{
	public:
		enum State{
			LOANED = true, RESERVER = false
		};
		enum BookType{
			fiction = 0, nofiction, periodical, biography, childern
		};
		class Invalid{};

		bool loan();
		bool back();

		Book(string ISBN, string Name, string Author, Chrono::Date Copy_right_date, BookType Type, State loaned);

		string ISBN() const{ return isbn; }
		string Name()const{ return name; }
		string Author()const{ return author; }
		Chrono::Date Copy_right_date()const{ return copy_right_date; }
		BookType Type()const{ return type; }
		State Loaned()const{ return loaned; }
	private:
		string isbn;
		string name;
		string author;
		Chrono::Date copy_right_date;
		BookType type;
		State loaned;
	};
	string booktype_to_string(Book::BookType type);
	bool is_valid_ISBN(string ISBN);

	bool operator==(const Book& a, const Book& b);
	bool operator!=(const Book& a, const Book& b);

	ostream& operator<<(ostream& os, const Book& book);
}

#endif