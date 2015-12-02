#ifndef PATRON_H
#define PATRON_H

#include "Chrono.h"

namespace Patron{
	class Patron{
	public:
		const double one_day_pays = 1;
		string Name()const{ return name; }
		string Certificate_number()const{ return certificate_number; }
		double Costs()const{ return costs; }
		Chrono::Date Return_date()const { return return_date; };
		bool is_arrears();
		Patron(string name, string number, double costs, Chrono::Date date);
	private:
		string name;
		string certificate_number;
		double costs;
		Chrono::Date return_date;
		double cal_costs();
	};

	bool operator==(const Patron& a, const Patron& b);
	bool operator!=(const Patron& a, const Patron& b);
}

#endif//PATRON_H