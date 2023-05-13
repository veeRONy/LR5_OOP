#include<iostream>

class Base
{
public:
	Base()
	{
		printf("Base()\n");
	}
	virtual ~Base()
	{
		printf("~Base()\n");
	}
};

class Desc : public Base
{
public:
	Desc()
	{
		printf("Desc()\n");
	}
	~Desc() override
	{
		printf("~Desc()\n");
	}

};

class Base2
{
public:
	Base2()
	{
		printf("Base2()\n");
	}
	~Base2()
	{
		printf("~Base2()\n");
	}
};

class Desc2: public Base2
{
public:
	Desc2()
	{
		printf("Desc2()\n");
	}
	~Desc2()
	{
		printf("~Desc2()\n");
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	printf("Использование обычного дестуктора:\n");
	Base2* x2 = new Desc2();
	delete x2;

	printf("\nРабота виртуального деструктора базового класса и перекрытого деструктора класса-потомка:\n");
	Base* x = new Desc();
	delete x;

	return 0;
}