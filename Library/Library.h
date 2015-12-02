#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Patron.h"

namespace Library{
	struct Transaction{
		Book::Book book;
		Patron::Patron patron;
		Chrono::Date date;
		Transaction(Patron::Patron Patron, Book::Book Book, Chrono::Date Date)
			:patron(Patron), book(Book), date(Date){}
	};
	class Library{
	public:
		void add_book(string ISBN, string Name, string Author, Chrono::Date Copy_right_date, Book::Book::BookType Type);
		void add_patron(string Name, string Certificate_number);
		void loan_book(Patron::Patron patron, Book::Book book);
		vector<Patron::Patron> arrears();

		vector<Book::Book> Books()const{ return books; }
		vector<Patron::Patron> Patrons()const{ return patrons; }
		vector<Transaction> Transactions()const{ return transactions; }
	private:
		vector<Book::Book> books;
		vector<Patron::Patron> patrons;
		vector<Transaction> transactions;
	};
}

#endif