# include <iostream>
# include "Spell.h"

using namespace std;

Spell::Spell()
{
	spell_descrition = nullptr;
	spell_type = 0;
	spell_power_required = 0;
}

Spell::Spell(char *new_spell_descrition, int new_spell_type, int new_spell_power_required)
{
	if (!new_spell_descrition)
	{
		cerr << "The spell descrtion cannot be blank!" << endl;
		return;
	}
	spell_descrition = new char[strlen(new_spell_descrition) + 1];
	strcpy_s(spell_descrition, strlen(new_spell_descrition) + 1, new_spell_descrition);
	if (new_spell_type < 1 || new_spell_type > 3)
	{
		cerr << "The spell type should be a number between 1 and 3!" << endl;
		return;
	}
	spell_type = new_spell_type;
	if (new_spell_power_required == 0)
	{
		cerr << "The spell should require at least 1 magic power!" << endl;
		return;
	}
	spell_power_required = new_spell_power_required;
}

Spell::Spell(const Spell &right)
{
	copy_spells(right);
}

Spell &Spell::operator=(const Spell &right)
{
	if (this != &right)
	{
		delete[]spell_descrition;
		copy_spells(right);
	}
	return *this;
}

void Spell::copy_spells(const Spell &right)
{
	if (!right.spell_descrition)
	{
		cerr << "The spell descrtion  of the right object cannot cannot be blank!" << endl;
		return;
	}
	spell_descrition = new char[strlen(right.spell_descrition) + 1];
	strcpy_s(spell_descrition, strlen(right.spell_descrition) + 1, right.spell_descrition);
	if (right.spell_type < 1 || right.spell_type > 3)
	{
		cerr << "The spell type of the right object cannot should be a number between 1 and 3!" << endl;
		return;
	}
	spell_type = right.spell_type;
	if (!right.spell_power_required)
	{
		cerr << "The spell of the right object should require at least 1 magic power!" << endl;
		return;
	}
	spell_power_required = right.spell_power_required;
}
Spell::~Spell()
{
	delete[] spell_descrition;
}

void Spell::set_spell_description(char * new_descrtion)
{
	spell_descrition = new (nothrow) char[strlen(new_descrtion) + 1];
	if (!spell_descrition)
	{
		cerr << "Problem while setting a spell name!" << endl;
		return;
	}
	strcpy_s(spell_descrition, strlen(new_descrtion) + 1, new_descrtion);
}

bool Spell::operator==(const Spell &right)
{
	if (strcmp(spell_descrition, right.spell_descrition) != 0)
	{
		return false;
	}
	return true;
}

void Spell::print_spells()
{
	cout << "The descrition of that spell is: " << spell_descrition;
	cout << ". The spell type is: ";
	switch (spell_type)
	{
	case(1) : cout << "weak. " << endl; break;
	case(2) : cout << "average. " << endl; break;
	case(3) : cout << "strong. " << endl; break;
	default: cerr << "Problem with the spell type!" << endl;
		return;
	}
	cout << "The magic power requiring to use the spell is: " << spell_power_required <<  endl;
}
