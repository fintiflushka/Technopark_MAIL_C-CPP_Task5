#include <iostream>
#include <random>
#include "multiset.h"
using namespace std;

Multiset symmetric_difference(Multiset ms1, Multiset ms2);

int main() 
{
	Multiset ms[5];

	random_device rd; // Начальные значения для генератора.
	mt19937 gen(rd()); // Вихрь Мерсена
	uniform_int_distribution<int> rand_count(2, 5);
	uniform_int_distribution<int> rand_num(-9, 9);

	for (int i = 0; i < 5; i++) 
	{
		int count = rand_count(gen); 
		for (int j = 0; j < count; j++) 
		{
			ms[i].insert(rand_num(gen));
		}
	}

	for (int i = 0; i < 5; i++) 
	{
		cout << "ms[" << i + 1 << ']' << " = ";
		cout << ms[i] << endl;
	}

	cout << endl;

	for (int i = 1; i < 5; i++) 
	{
		Multiset sym_diff = symmetric_difference(ms[i - 1], ms[i]);
		cout << "symmetric_difference of ";
		cout << "ms[" << i + 1 << ']';
		cout << " and ";
		cout << "ms[" << i << ']';
		cout << " = ";
		cout << sym_diff << endl;
	}

	return 0;
}


Multiset symmetric_difference(Multiset ms1, Multiset ms2)
{
	return (ms2 + ms1) - (ms2 * ms1);
}