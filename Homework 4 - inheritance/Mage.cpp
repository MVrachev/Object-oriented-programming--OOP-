# include <iostream>
# include "Mage.h"

using namespace std;

//constructors and functions connected with them

Mage::Mage() : Soldier(), mage_squad_descrition(nullptr),
mage_sergeants(nullptr), magic_power(0), mage_sergeants_amount(0){}

Mage::Mage(char *new_name, unsigned int new_years, unsigned int new_fight_skills, unsigned int new_salary, //for Soldier constructor
	unsigned int new_magic_power, char *new_mage_squad_description, unsigned int new_mage_sergeants_amount) :
	Soldier(new_name, new_years, new_fight_skills, new_salary), magic_power(new_magic_power), mage_squad_descrition(nullptr),
	mage_sergeants(nullptr)
{
	if (new_mage_squad_description == nullptr)
	{
		cerr << "The mage squad descrition cannot be empty!" << endl;
		return;
	}
	mage_squad_descrition = new char[strlen(new_mage_squad_description) + 1];
	strcpy_s(mage_squad_descrition, strlen(new_mage_squad_description) + 1, new_mage_squad_description);
	mage_sergeants_amount = new_mage_sergeants_amount;
}

Mage::Mage(const Mage &right)
{
	copy_mages(right);
}

Mage &Mage::operator=(const Mage &right)
{
	if (this != &right)
	{
		clean();
		copy_mages(right);
	}
	return *this;
}

void Mage::copy_mages(const Mage&right)
{
	copy_soldiers(right);
	if (right.mage_squad_descrition == nullptr || right.magic_power == 0
		|| right.mage_sergeants_amount == 0)
	{
		cerr << "The mage squad descrition or magic power or mage seargeants cannot be empty or 0!" << endl;
		return;
	}
	mage_squad_descrition = new char[strlen(right.mage_squad_descrition) + 1];
	strcpy_s(mage_squad_descrition, strlen(right.mage_squad_descrition) + 1, right.mage_squad_descrition);
	mage_sergeants_amount = right.mage_sergeants_amount;
	mage_sergeants = new Sergeant[mage_sergeants_amount];
	for (unsigned int i = 0; i < mage_sergeants_amount; ++i)
	{
		mage_sergeants[i] = right.mage_sergeants[i];
	}
	magic_power = right.magic_power;
	mage_personal_book = right.mage_personal_book;
}

Mage::~Mage()
{
	clean();
}

void Mage::clean()
{
	delete[]mage_squad_descrition;
	delete[]mage_sergeants;
}


// other functions

Mage &Mage::set_mage(Mage &obj, unsigned int fighting_skill_commander, bool is_it_commander)
{
	unsigned int new_mage_magic_power, sergeant_amount;
	char mage_squad_descrition[100];
	if (obj.get_name() == nullptr && obj.get_years() == 0 && obj.get_fight_skills() == 0 &&
		obj.get_salary() == 0 && obj.get_magic_power() == 0
		&& obj.get_mage_squad_descrition() == nullptr && obj.get_mage_sergeant_amount() == 0)
	{
		cout << "You will create a mage. " << endl;
		Soldier::set_soldier(obj,fighting_skill_commander);
		cout << "How much his magic power woud be? ";
		cin >> new_mage_magic_power;
		cout << "Give description to mage's army: ";
		cin.ignore();
		cin.getline(mage_squad_descrition, 100);
		cout << endl;
		obj.set_mage_squad_descrition(mage_squad_descrition);
		obj.set_magic_power(new_mage_magic_power);
		MagicBook::set_magic_book(obj.get_mage_magic_book());
		do
		{
			cout << "How many sergeants do you want to be controlled by your mage? There should be at least one! ";
			cin >> sergeant_amount;
		} while (sergeant_amount == 0);
	}
	else
		sergeant_amount = obj.get_mage_sergeant_amount();

	obj.mage_sergeants = new Sergeant[sergeant_amount];
	obj.set_new_mage_sergeants_amount(sergeant_amount);
	for (unsigned int i = 0; i < sergeant_amount; ++i)
	{
		Sergeant::set_sergeant(obj.mage_sergeants[i],obj.get_fight_skills());
	}
	return obj;
}

void Mage::print_mage()
{
	cout << "Information about mage" << endl;
	print_soldiers_part();
	cout << "The mage controls the following sergeants: " << endl << endl;
	for (unsigned int i = 0; i < mage_sergeants_amount; ++i)
	{
		cout << "Sergeant number " << i << " .";
		mage_sergeants[i].print_sergeants_part();
	}
}

void Mage::mage_use_spell(Spell &using_spell)
{
	if (using_spell.get_spell_power_required() > magic_power)
	{
		cerr << "The mage cannot use such a powerful spell whic requires so much magic power!" << endl;
		return;
	}
	mage_personal_book.use_spell(using_spell);
}


//// Bonus task! ////

void Mage::sort_spells()
{
	unsigned int spells_amount = mage_personal_book.get_number_of_spells();
	bool sorted = false;
	do
	{
		sorted = false;
		for (unsigned int i = 0; i < spells_amount - 1; ++i)
		{
			if (mage_personal_book.get_spell_pages()[i].get_spell_power_required() > mage_personal_book.get_spell_pages()[i + 1].get_spell_power_required())
			{
				swap(mage_personal_book.get_spell_pages()[i], mage_personal_book.get_spell_pages()[i + 1]);
				sorted = true;
			}
		}
	} while (sorted == true);
}

unsigned int Mage::mage_most_spells()
{
	sort_spells();
	unsigned int most_spells_amount = 0;
	unsigned int mage_magic_power = magic_power;
	for (int i = 0; i < mage_personal_book.get_number_of_spells(); ++i)
	{
		if (magic_power >= mage_personal_book.get_spell_pages()[i].get_spell_power_required())
		{
			++most_spells_amount;
			magic_power -= mage_personal_book.get_spell_pages()[i].get_spell_power_required();
		}
		else
			break;
	}
	return most_spells_amount;
}