#include "Kauppa.h"


Kauppa::Kauppa() :aika_(""), hinta_(0), maara_(0), myyja_(""), ostaja_("")
{}

Kauppa::Kauppa(string aika, double hinta, int maara, string myyja, string ostaja) : aika_(aika), hinta_(hinta), maara_(maara), myyja_(myyja), ostaja_(ostaja)
{}

Kauppa::~Kauppa()
{}

ostream &operator<<(ostream &out, const Kauppa &k)
{
	out << k.aika_ << "		" << k.hinta_ << "		" << k.maara_ << "		" << k.myyja_ << "		" << k.ostaja_;
	return out;
}

istream & operator>>(istream & in, Kauppa &k)
{
	in >> k.aika_ >> k.hinta_ >> k.maara_ >> k.myyja_ >> k.ostaja_;
	return in;
}

bool Kauppa::operator<(const Kauppa & k) const
{
	if (hinta_ < k.hinta_)
		return true;
	else
		return false;
}