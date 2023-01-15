#pragma once

//Am ales sa folosesc clasa Traducere drept clasa abstracta.
class Traducere
{
private:
	Traducere();
	~Traducere();
public:
	virtual void translate() = 0;
	
};

class traducereEngleza : public Traducere
{
	virtual void translate();
};

class traducereFranceza : public Traducere
{
	virtual void translate();
};

class traducereJaponeza : public Traducere
{
	virtual void translate();
};
