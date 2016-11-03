# include <iostream>
# include "Commander.h"

using namespace std;


Commander::Commander() : Soldier(), mage_squad(nullptr), army_description(nullptr), mage_squad_size(0){}

Commander::Commander(const Commander &right)
{
	copy_commander(right);
}

Commander &Commander::operator=(const Commander &right)
{
	if (this != &right)
	{
		clean_commander();
		copy_commander(right);
	}
	return *this;
}

Commander::~Commander()
{
	clean_commander();
}
void Commander::clean_commander()
{
	delete[]army_description;
	delete[]mage_squad;
}

void Commander::copy_commander(const Commander&right)
{
	copy_soldiers(right);
	army_description = new(nothrow) char[strlen(right.army_description) + 1];
	if (!army_description)
	{
		cerr << "The army description cannot be empty!" << endl;
		return;
	}
	strcpy_s(army_description, strlen(right.army_description) + 1, right.army_description);
	mage_squad_size = right.mage_squad_size;
	mage_squad = new Mage[mage_squad_size];
	for (unsigned int i = 0; i < right.mage_squad_size; ++i)
	{
		mage_squad[i] = right.mage_squad[i];
	}
}

//other functions

Commander &Commander::set_commander(Commander &obj)
{
	unsigned int new_mage_squad_size;
	char new_com_army_descrition[100];
	if (obj.get_name() == nullptr && obj.get_years() == 0 && obj.get_fight_skills() == 0
		&& obj.get_salary() == 0 && obj.get_mage_squad() == nullptr
		&& obj.get_army_descrition() == nullptr)
	{
		cout << "You will create a commander. " << endl;
		Soldier::set_soldier(obj, 9999999, true);
		cout << "Give descrition of the army controled by your commander: ";
		cin.ignore();
		cin.getline(new_com_army_descrition, 100);
		obj.set_army_descrition(new_com_army_descrition);
		cout << "How many mages do you want your commander to control in his mage squad? ";
		cin >> new_mage_squad_size;
	}
	obj.set_mage_squar_size(new_mage_squad_size);
	obj.mage_squad = new Mage[new_mage_squad_size];
	cout << "The commander controls the following mages: " << endl << endl;
	for (unsigned int i = 0; i < new_mage_squad_size; ++i)
	{
		Mage::set_mage(obj.get_mage_squad()[i], obj.get_fight_skills());
	}
	return obj;
}

void Commander::print_commander()
{
	cout << "Information about Commander." << endl;
	print_soldiers_part();
	cout << "The descrition of his army is: " << army_description << endl;
	cout << "The commander controls the following mages: " << endl << endl;
	for (unsigned int i = 0; i < mage_squad_size; ++i)
	{
		cout << "Mage number " << i << " .";
		mage_squad[i].print_mage();
	}
}

unsigned int Commander::whole_army_fight_skill()
{
	unsigned int whole_fight_skills = 0;
	whole_fight_skills += fight_skills;
	unsigned int temp_mage_squad_size = mage_squad_size;
	for (unsigned int i = 0; i < mage_squad_size; ++i)
	{
		whole_fight_skills += mage_squad[i].get_fight_skills();
		unsigned int segeant_squad_size = mage_squad[i].get_mage_sergeant_amount();
		for (unsigned int j = 0; j < segeant_squad_size; ++j)
		{
			whole_fight_skills+=mage_squad[i].get_mage_sergeants()[j].get_fight_skills();
			unsigned int soldier_squad_size = mage_squad[i].get_mage_sergeants()[j].get_soldier_squar_size();
			for (int k = 0; k < soldier_squad_size; ++k)
			{
				whole_fight_skills += mage_squad[i].get_mage_sergeants()[j].get_soldier_squad()[k].get_fight_skills();
			}
		}
	}
	return whole_fight_skills;
}

double Commander::average_army_fight_skill()
{
	unsigned int average_fight_skill = whole_army_fight_skill() / living_objects_count;
	return average_fight_skill;
}

unsigned int Commander::whole_army_expense()
{
	unsigned int whole_expense = 0;
	whole_expense += salary;
	unsigned int temp_mage_squad_size = mage_squad_size;
	for (unsigned int i = 0; i < mage_squad_size; ++i)
	{
		whole_expense += mage_squad[i].get_salary();
		unsigned int segeant_squad_size = mage_squad[i].get_mage_sergeant_amount();
		for (unsigned int j = 0; j < segeant_squad_size; ++j)
		{
			whole_expense += mage_squad[i].get_mage_sergeants()[j].get_salary();
			unsigned int soldier_squad_size = mage_squad[i].get_mage_sergeants()[j].get_soldier_squar_size();
			for (int k = 0; k < soldier_squad_size; ++k)
			{
				whole_expense += mage_squad[i].get_mage_sergeants()[j].get_soldier_squad()[k].get_salary();
			}
		}
	}
	return whole_expense;
}