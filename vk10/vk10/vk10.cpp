// vk10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <fstream>
#include <map>
using namespace std;

void print(const string& item)
{
	cout << item << endl;
}

void main_1()
{
	// 1. Tee ohjelma, joka lukee käyttäjän syötteen ja tulostaa käyttäjän syöttämät erilaiset aakkoset aakkosjärjestyksessä alekkain.(set)
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
}
void main_2()
{
	// 2. Tee ohjelma, joka lukee tekstitiedoston ja tulostaa monta kertaa kukin sana esiintyi tiedostossa. (multiset)	// multiset<string> words;
	ifstream file("tehtava2.txt");	if (!file)
		cout << "Ei auennu tiedosto" << endl;
	multiset<string> wordsList = multiset<string>(istream_iterator<string>(file), istream_iterator<string>());

	for (auto word = wordsList.begin(); word != wordsList.end(); word = wordsList.upper_bound(*word))
		cout << *word << ": " << wordsList.count(*word) << endl;

	file.close();
}
template <class KTy, class Ty>
void PrintMap(map<KTy, Ty> map)
{
	typedef std::map<KTy, Ty>::iterator iterator;
	for (iterator p = map.begin(); p != map.end(); p++)
		cout << p->first << ": " << p->second << endl;
}
void main_3()
{
	// 3. Toteuta tehtävä 2 käyttäen map-kokoelmaa
	static const char* fileName = "tehtava2.txt";

	map<string, unsigned int> words;

	ifstream fileStream(fileName);

	if (fileStream.is_open())
	while (fileStream.good())
	{
		string word;
		fileStream >> word;

		if (words.find(word) == words.end())
			words[word] = 1;
		else
			words[word]++;
	}
	else
	{
		cerr << "Couldn't open the file." << endl;
	}

	PrintMap(words);
}
void main_4()
{
	/*
	4. Selvitä tiedostosta nokia18032009.txt ( harjoitus 5) käyttäjän syöttämän
	myyjän kauppojen lukumäärä, myytyjen osakkeiden ja myyjän kauppojen
	yhteissumma. Tulosta tiedot näytölle ja tiedostoon kaikki.txt.
	*/

}

int _tmain(int argc, _TCHAR* argv[])
{
	char number[2];
	cout << "Number of the excercise (1,2,3,): ";
	cin.getline(number, 2);

	switch (number[0]){
	case '1':
		main_1();
		break;
	case '2':
		main_2();
		break;
	case '3':
		main_3();
		break;
	case '4':
		main_4();
		break;
	};

	system("pause");
	return 0;
}