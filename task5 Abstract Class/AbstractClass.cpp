#include "Employee.h"
#include "Pensioner.h"
#include "Preschooler.h"
#include "Schoolkid.h"

int main() {
	setlocale(0, "");
	Employee man1("Александр", "Александров", 30);
	man1.show();
	man1.isWork("EPAM");

	Pensioner pen1;
	//pen1.show();
	pen1.setValues("Иван", "Иванов", 50);
	pen1.show();
	pen1.isWork("-");
	//передаем якобы заработок за год, а функция возвращает доход в месяц
	cout << pen1.averageIncome(3530.345) << endl;

	Preschooler ch("Павел", "Павлов", 5); //включение объекта в список при создании объекта
	ch.show();
	ch.setValues("Роман", "Павлов", 7); //переопределяем значения
	ch.show();
	ch.schoolOrGarten(14);
	//передаем кол-во параметров и сами параметры
	cout << ch.costOfSections(2, 342.4, 341.1) << endl;

	//объект выделен динамически(не рекомендуется), поэтому необходимо вручную вызвать деструктор, иначе произойдет утечка памяти
	Schoolkid* sch = new Schoolkid("Алексей", "Алексеев", 15);
	sch->show();
	sch->schoolOrGarten(22);
	sch->~Schoolkid();
}
