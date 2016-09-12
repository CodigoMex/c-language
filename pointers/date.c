#include <stdio.h>

int main() {
	struct date { int month, day, year; };
	struct date today, *date_ptr;

	date_ptr = &today;
	date_ptr->month = 9;
	date_ptr->day = 25;
	date_ptr->year = 1983;

	printf("Today date is %d/%d/%d.\n",
			date_ptr->month,
			date_ptr->day,
			date_ptr->year % 100);
	return 0;
}
