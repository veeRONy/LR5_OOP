

#include <iostream>
using namespace std;

class Animal
{
public:
	void sound_notvirt()
	{
		printf("basemethod\n");
	}
	virtual void sound_virt()
	{
		printf("basemethod\n");
	}
};

class Cat : public Animal
{
public:
	void sound_notvirt()
	{
		printf("Mew-mew\n");
	}
	void sound_virt() override
	{
		cout << "Mew-mew\n";
	}
};

class Dog : public Animal
{
public:
	void sound_notvirt()
	{
		printf("Wow-wow\n");
	}
	void sound_virt() override
	{
		cout << "Wow-wow\n";
	}
};


int main()
{
	setlocale(LC_ALL, "ru");

	// создаем массив указателей на Animal
	const int size = 10;
	Animal* zoo[size]{0};

	// рандомно записываем в массив указатели на объекты классов потомков
	for (int i = 0; i < size; i++)
	{
		int r = rand() % 2;
		if (r == 0)
			zoo[i] = new Cat();
		else if (r == 1)
			zoo[i] = new Dog();
	}

	printf("Вызов не виртуальной функции для всех элементов массива:\n");
	for (int i = 0; i < size; i++)
	{
		zoo[i]->sound_notvirt();
	}


	printf("\nВызов виртуальной функции для всех элементов массива:\n");
	for (int i = 0; i < size; i++)
	{
		zoo[i]->sound_virt();
	}


	return 0;
}