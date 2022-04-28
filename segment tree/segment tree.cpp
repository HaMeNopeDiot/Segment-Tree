// segment tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "SegmentTree.h"

void swapStable(std::string &word, int i)
{
	if (word[i] == '(')
		word[i] = ')';
	else
		word[i] = '(';
}

int main()
{
	std::string word;
	std::cin >> word;
	if (word.size() % 2 == 1)
	{
		std::cout << "YOU WON'T PASS!"<<'\n';
	}
	else
	{
		SegmentTree A(word.size());
		int k;
		std::cin >> k;
		for (int i = 0; i < k; i++)
		{
			int tmp;
			std::cin >> tmp;
			swapStable(word, tmp);
			std::cout << "Word:" << word << '\n';
			A.regStable(word);

		}
		
	}
	
}

