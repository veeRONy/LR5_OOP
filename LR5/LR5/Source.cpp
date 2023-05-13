#include <iostream>
using namespace std;


class Base
{
protected:
	int id;

public:
	Base()
	{
		cout << "Конструктор Base()\n";
		id = 0;
	}
	Base(const Base* object)
	{
		this->id = object->id;
		cout << "Коструктор Base(Base* object)\n";
	}
	Base(const Base& object)
	{
		this->id = object.id;
		cout << "Коструктор Base(Base& object)\n";
	}
	virtual string className()
	{
		return "Class Base";
	}
	bool isA(const string& classname)
	{
		return (classname == "Base");
	}
	~Base()
	{
		cout << "Деструктор ~Base()\n";
	}
};

class Desc : public Base
{
public:
	Desc()
	{
		cout << "Коструктор Desc()\n";
		id = 0;
	}
	Desc(const Desc* object)
	{
		this->id = object->id;
		cout << "Коструктор Desc(Desc* object)\n";
	}
	Desc(const Desc& object)
	{
		this->id = object.id;
		cout << "Коструктор Desc(Desc& object)\n";
	}
	string className()
	{
		return "Class Desc";
	}
	bool isA(const string& classname)
	{
		return (classname == "Desc") || Base::isA(classname);
	}
	~Desc()
	{
		cout << "Деструктор ~Desc()\n";
	}
};


Base func1() {
	Base b;
	return b;
}
Base func2() {
	Base* b = new Base();
	return *b;
};
Base* func3() {
	Base b;
	return &b;
};
Base* func4() {
	Base* b = new Base(); 
	return b;
};
Base& func5() {
	Base b;
	return b;
};
Base& func6() {
	Base* b = new Base(); 
	return *b;
};



void function1(Base object)
{
	cout << "func1(Base object)\n";
}
void function2(Base* object)
{
	cout << "func2(Base* object)\n";
}
void function3(Base& object)
{
	cout << "func3(Base& object)\n";
}


int main()
{
	setlocale(LC_ALL, "ru");

	cout << "Проверка механизма передачи объектов как параметров в функции:\n\n";
	cout << "Объекты создаются статически:\n";

	{
		cout << "Base functions:\n";
		Base b1;
		function1(b1);
		function2(&b1);
		function3(b1);
	}


	{
		cout << "\nDesc functions:\n";
		Desc d1;
		function1(d1);
		function2(&d1);
		function3(d1);
	}

	cout << "\n\nОбъекты создаются динамически:\n";
	
	cout << "Base functions:\n";
	Base* b2 = new Base();
	function1(*b2);
	function2(b2);
	function3(*b2);
	delete b2;

	cout << "\nDesc functions:\n";
	Desc* d2 = new Desc();
	function1(*d2);
	function2(d2);
	function3(*d2);
	delete d2;


	cout << "\nПроверка механизма возврата объектов из функции:\n\n";
	{
		Base b1 = func1();
		cout << endl;
		Base b2 = func2();
		cout << endl;
		Base* b3 = func3();
		cout << endl;
		Base* b4 = func4();
		cout << endl;
		Base& b5 = func5();
		cout << endl;
		Base& b6 = func6();
	}

	return 0;
}