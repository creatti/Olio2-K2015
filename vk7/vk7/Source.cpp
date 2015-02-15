#include <vector>
using std::vector;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <iostream>
using std::ostream_iterator;
using std::istream_iterator;
using std::cout;
using std::cerr;
using std::endl;
#include <algorithm>
#include "kauppa.h"
int main()
{
	string poisto;
	vector<Kauppa> V;
	ifstream tied("nokia18032009.txt");
	ofstream tulos("harjoitus5t1.txt");
	if (tied.is_open())
	{
		getline(tied, poisto); // luetaan otsikkorivi pois
		// luetaan tiedostosta tiedot Kauppa-oliohin vektoriin V
		copy(istream_iterator<Kauppa>(tied), istream_iterator<Kauppa>(),
			back_inserter(V));
		sort(V.begin(), V.end()); // j‰rjestell‰‰n vektori hinnan mukaan
		if (tulos.is_open())
			// tulostetaan j‰rjestetty vektori tiedostoon
			copy(V.begin(), V.end(), ostream_iterator<Kauppa>(tulos, "\n"));
		else
		{
			cerr << "tiedoston harjoitus5t1.txt avaus ei onnistunut" << endl;
			return 2;
		}
	}
	else
	{
		cerr << "tiedoston nokia18032009.txt avaus ei onnistunut" << endl;
		return 1;
	}
	return 0;
}