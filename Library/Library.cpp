#include "Library.h"
namespace Library{
	
	void Library::add_book(string ISBN, string Name, string Author, Chrono::Date Copy_right_date, Book::Book::BookType Type)
	{
		Book::Book book(ISBN, Name, Author, Copy_right_date, Type, Book::Book::RESERVER);
		books.push_back(book);
	}
	void Library::add_patron(string Name, string Certificate_number)
	{
		Patron::Patron p(Name, Certificate_number, 0,Chrono::today());
		patrons.push_back(p);
	}
	void Library::loan_book(Patron::Patron p, Book::Book b)
	{
		vector<Patron::Patron> patron = Patrons();
		vector<Book::Book> book = Books();
		int i = 0;
		for (i = 0; i < patron.size();i++)
		if (patron[i] == p)
			break;
		if (i == patron.size())
			error("Invalid Patron");
		for (i = 0; i < book.size(); i++)
		if (book[i] == b)
			break;
		if (i == book.size())
			error("Invalid Book");
		if (p.is_arrears())
			error("This potron is arrears");
		Transaction tran(p, b, Chrono::today());
		transactions.push_back(tran);
	}
	vector<Patron::Patron> Library::arrears()
	{
		vector<Patron::Patron> r, p = Patrons();
		for (int i = 0; i < p.size(); i++)
		if (p[i].is_arrears())
			r.push_back(p[i]);
		return r;
	}
}