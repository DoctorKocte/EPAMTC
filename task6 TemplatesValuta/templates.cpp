#include "Conversion.h"

#define USD 2.46
#define EURO 3.1
#define RUB 0.0344
#define BYN 1
#define GBP 3.38

int main() {
	Conversion<double, int> money(USD, 10);
	Conversion<double, int> money2(EURO, 10);
	cout << "10 USD + 10 EURO = " << money.sum(money2) << " BYN" << endl;
}
