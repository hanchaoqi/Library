#include "Patron.h"

namespace Patron{
	double Patron::cal_costs()
	{
		
		int out_of_dates = Chrono::date_to_count(Chrono::today()) - Chrono::date_to_count(Return_date());
		if (out_of_dates > 0)
			return out_of_dates*Patron::one_day_pays;
		return 0;
	}
	bool Patron::is_arrears()
	{
		if (Costs() > 0)
			return true;
		return false;
	}
	Patron::Patron(string Name, string number, double Costs, Chrono::Date Return_date)
		:name(Name), certificate_number(number), costs(Costs), return_date(Return_date){}

	bool operator==(const Patron& a, const Patron& b)
	{
		if (a.Name() == b.Name() && a.Certificate_number() == b.Certificate_number() && (a.Costs() == b.Costs()) && a.Return_date() == b.Return_date())
			return true;
		return false;
	}
	bool operator!=(const Patron& a, const Patron& b)
	{
		return !(a == b);
	}
}