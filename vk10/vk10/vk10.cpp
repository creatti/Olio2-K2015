// vk10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

void print(const string& item)
{
	cout << item << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	set<string> sortedItems;
	string name;
	// cout << i << ". ";
	cin >> name;

	string k;
	for (int i = 0; i <= name.length(); ++i)
	{
		k = name[i];
		sortedItems.insert(k);
	}

	for_each(sortedItems.begin(), sortedItems.end(), &print);
	system("pause");
	return 0;
}

// Käyttäjän syötteestä sortteerataan kirjaimet aakkosjärjestykseen