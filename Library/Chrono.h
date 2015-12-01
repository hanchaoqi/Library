#include "std_lib_facilities.h"
namespace Chrono{
	class Date{
	public:
		enum Month{
			jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
		};
		class Invalid{};
		Date(int yy, Month mm, int dd);
		Date();
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
		int Date::year()const{ return y; }
		Date::Month Date::month()const{ return m; }
		int Date::day()const{ return d; }
	private:
		int y, d;
		Month m;
	};

	bool is_date(int y, Date::Month m, int d);
	bool is_leapyear(int y);
	int date_to_count(Date dd);
	Date count_to_date(int n);
	Date& default_date();
	Date::Month int_to_month(int n);

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	ostream& operator<<(ostream& os, const Date& d);
	istream& operator>>(istream& is, Date& dd);
}
