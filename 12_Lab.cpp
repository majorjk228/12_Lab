// Лабораторная работа №12, Вариант 3 (2 семестр).
//


#include <iostream>
#include <set>
using namespace std;


typedef multiset<double>TMultiset;//определяем тип для работы с multiset'ом
//typedef TMultiset::iterator it;//итератор
multiset<double> ::iterator it;

//функция для формирования multiset'a
TMultiset make_multiset(int n)
{
	TMultiset m;//пустой multiset
	float a;
	for (int i = 0; i < n; i++)
	{
		cout << "Znachenie: ";
		cin >> a;
		m.insert(a);
	}
	return m;//возвращаем multiset как результат работы функции
}

//функция для печати словаря
void print_multiset(TMultiset m)
{
	for (it = m.begin(); it != m.end(); it++)
		cout << *it << "  ";
}

//функция удаления элемента с заданным значением
TMultiset erase_multiset(TMultiset m, double el)
{
	for (it = m.begin(); it != m.end();)
	{
		double n = *it;
		if (el == n)
		{
			cout << *it << endl;
			m.erase(it++);
		}
		else ++it;
	}
	return m;
}

//функция поиска минимального элемента

float Min_multiset(TMultiset m)
{
	double min, temp;
	it = m.begin();
	min = *it;
	for (it = m.begin(); it != m.end(); ++it)
	{
		temp = *it;
		if (min > temp)
		{
			min = temp;
		}
	}

	return min;
}


//функция поиска максимального элемента

float Max_multiset(TMultiset m)
{
	double max, temp;
	it = m.begin();
	max = *it;
	for (it = m.begin(); it != m.end(); ++it)
	{
		temp = *it;
		if (max < temp)
		{
			max = temp;
		}
	}

	return max;
}

//функция прибавления минимального-максимального значения ко всем элементам мультисета

TMultiset zadanie(TMultiset m, double min, double max)
{
	for (it = m.begin(); it != m.end(); ++it)
	{

		double h = *it + min - max;
		cout << h << "  ";


	}

	return m;
}

//основная функция
void main()
{
	int n;
	cout << "Kolvo-elementov: "; cin >> n;//количество элементов
	TMultiset m = make_multiset(n);//создать словарь
	print_multiset(m);//напечатать словарь
	double d;
	cout << "Kakoi udalit (znachenie)'?";
	cin >> d;
	TMultiset j = erase_multiset(m, d);
	print_multiset(j);
	double h = Min_multiset(j);
	double u;
	//cout << "Minimalnoe znachenie=" << h << endl;
	cout << "Dobavit element: "  << endl;
	cin >> u;
	j.insert(u);
	print_multiset(j);
	cout << endl;
	double g = Max_multiset(j);

	cout << "dobavim max-min" << endl;
	zadanie(j, h, g);


}
