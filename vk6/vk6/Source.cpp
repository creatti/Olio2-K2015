#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;

int main_1();
void main_2();
void main_3();

int main()
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
	};

	system("pause");
	return 0;
}

int main_1()
{
	vector<string> vektori;
	string line;
	ifstream file("merkkijono.txt");


	if (!file)
	{
		cout << "Ei auennu tiedosto" << endl;
		system("pause");
		return -1;
	}

	while (file >> line)
	{
		vektori.push_back(line);
	}
	

	sort(vektori.begin(), vektori.end());

	ofstream file2("tulos.txt");
	ostream_iterator<string> output_iterator(file2, "\n");
	copy(vektori.begin(), vektori.end(), output_iterator);

	return 0;
}

void main_2()
{
	vector<string> words;
	string line;
	ifstream file("merkkijono.txt");


	if (!file)
		cout << "Ei auennu tiedosto" << endl;

	while (file >> line)
	{
		bool found = true;
		int x = 0;
		while (found)
		{
			if (line.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890") != std::string::npos)
			{

				x = line.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890");
				line.erase(x, 1);
			}
			else
				found = false;
		}
		if (line[0] != ' ')
			words.push_back(line);
		else;
	}


	sort(words.begin(), words.end());

		ofstream file2("merkkijono_abc.txt");
		ostream_iterator<string> output_iterator(file2, "\n");
		copy(words.begin(), words.end(), output_iterator);
}

void main_3()
{
	vector<string> words;
	string line;
	ifstream file("merkkijono.txt");


	if (!file)
		cout << "Ei auennu tiedosto" << endl;

	while (file >> line)
	{
		bool found = true;
		int x = 0;
		while (found)
		{
			if (line.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890") != std::string::npos)
			{

				x = line.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890");
				line.erase(x, 1);
			}
			else
				found = false;
		}
		if (line.size() > 2)
			words.push_back(line);
		else;
	}


	sort(words.begin(), words.end());

	ofstream file2("merkkijono_abc_2.txt");
	ostream_iterator<string> output_iterator(file2, "\n");
	copy(words.begin(), words.end(), output_iterator);
}