#include "Library.h"
int main()
{
	try
	{
		Library::Library lib;
		lib.add_book("89-89-09-sq2","Three body","ci",Chrono::today(),Book::Book::fiction);
		lib.add_patron("qi", "123");
		lib.loan_book(lib.Patrons()[0], lib.Books()[0]);
	}
	catch (...)
	{
		cout << "error" << endl;
	}
	return 0;
}