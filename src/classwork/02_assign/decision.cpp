//Write the function code that returns the product of hours and hourly_rate.
#include "decision.h"

double gross_pay(double hours, double hourly_rate) {
	double pay;

	if (hours < 40) {
		pay = hours * hourly_rate;

		return pay;
	}

		else if (hours > 40) {
			pay = (hours * hourly_rate) + ((hours - 40) * (hourly_rate * 1.5));

		return pay;
	}
}
