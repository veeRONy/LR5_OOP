#include <iostream>
#include <ctime>
using namespace std;


//static и dynamic cast + isA


class ClassA
{
public:
	ClassA()
	{
		printf("ClassA()\n");
	}
	string className()
	{
		return "Class ClassA";
	}
	virtual bool isA(const string& classname)
	{
		return classname == "ClassA";
	}
	virtual ~ClassA()
	{
		printf("~ClassA()\n");
	}
};

class ClassB : public ClassA
{
public:
	ClassB()
	{
		printf("ClassB()\n");
	}
	string className() 
	{
		return "className - ClassB";
	}
	bool isA(const string& classname)
	{
		return (classname == "ClassB") || ClassA::isA(classname);
	}
	void BFunc()
	{
		printf("do BFunc\n");
	}
	~ClassB()
	{
		printf("~ClassB()\n");
	}
};

class ClassC : public ClassB
{
public:
	ClassC()
	{
		printf("ClassC()\n");
	}
	bool isA(const string& classname)
	{
		return (classname == "ClassC") || ClassB::isA(classname);
	}
};

int main()
{
	const int size = 10;
	ClassA* arr[size];
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	printf("Заполнение массива:\n");
	for (int i = 0; i < size; i++)
	{
		cout << i << ". ";
		int r = rand() % 3;
		if (r == 0)
			arr[i] = new ClassA();
		else if (r == 1)
			arr[i] = new ClassB();
		else if (r == 2)
			arr[i] = new ClassC();
		cout << endl;
	}

	printf("\nИспользование static_cast\n");
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->isA("ClassB"))
			static_cast<ClassB*>(arr[i])->BFunc();
	}
	printf("\nИспользование dynamic_cast\n");
	for (int i = 0; i < size; i++)
	{
		ClassB* b = dynamic_cast<ClassB*>(arr[i]);
		if (b != nullptr)
			b->BFunc();
	}
	return 0;
}