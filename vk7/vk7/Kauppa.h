#pragma once
#include <string>
using std::string;
#include <iostream>
using std::ostream;
using std::istream;
class Kauppa
{
public:
	Kauppa();
	Kauppa(string kello, double hinta, int maara, string ostaja,
		string myyja);
	~Kauppa();
	friend ostream & operator<<(ostream & out, const Kauppa &k);
	friend istream & operator>>(istream & in, Kauppa &k);
	bool operator <(const Kauppa & k) const;
private:
	string aika_;
	double hinta_;
	int maara_;
	string ostaja_;
	string myyja_;
};