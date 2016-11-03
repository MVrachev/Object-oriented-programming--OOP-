# include <iostream>
# include "Sergeant.h"

using namespace std;

Sergeant::Sergeant() : Soldier(), soldier_arr_description(nullptr), soldier_squad(nullptr), soldier_squar_size(0){}

// A Sergeant constructors and a few basic functions

//Sergeant::Sergeant(char * new_sergeant_name, int new_sergeant_years, int new_sergeant_fight_skills, 
//	int new_sergeant_salary, char * new_soldier_arr_description, int new_soldier_squar_size) :
//	Soldier(new_sergeant_name, new_sergeant_years, new_sergeant_fight_skills, new_sergeant_salary), soldier_squar_size(new_soldier_squar_size)
//{
//	if (!new_soldier_arr_description)
//	{
//		cerr << "The soldier squad descrition cannot be empty!" << endl;
//		return;
//	}
//	soldier_arr_description = new char[strlen(new_soldier_arr_description) + 1];
//	strcpy_s(soldier_arr_description, strlen(new_soldier_arr_description) + 1, new_soldier_arr_description);
//	set_soldier_squad();
//}

Sergeant::Sergeant(char * new_sergeant_name, int new_sergeant_years, int new_sergeant_fight_skills, int new_sergeant_salary,
	char * new_soldier_arr_description, int new_soldier_squar_size = 0) :
	Soldier(new_sergeant_name, new_sergeant_years, new_sergeant_fight_skills, new_sergeant_salary), soldier_squar_size(new_soldier_squar_size)
{
	if (!new_soldier_arr_description)
	{
		cerr << "The soldier squad descrition cannot be empty!" << endl;
		return;
	}
	soldier_arr_description = new char[strlen(new_soldier_arr_description) + 1];
	strcpy_s(soldier_arr_description, strlen(new_soldier_arr_description) + 1, new_soldier_arr_description);
}



Sergeant::Sergeant(const Sergeant&right)
{
	copy_sergeants(right);
}

Sergeant &Sergeant::operator=(const Sergeant &right)
{
	if (this != &right)
	{
		clean();
		copy_sergeants(right);
	}
	return *this;
}

Sergeant::~Sergeant()
{
	clean();
	cout << "-------------------------------------------" << endl;
	cout << "The Seargeant destructor has been used!" << endl;
}

void Sergeant::copy_sergeants(const Sergeant&right)
{
	copy_soldiers(right);
	soldier_squar_size = right.soldier_squar_size;
	if (!right.soldier_arr_description)
	{
		cerr << "Problem while copying Soldier squad description!" << endl;
		return;
	}
	soldier_arr_description = new char[strlen(right.soldier_arr_description) + 1];
	strcpy_s(soldier_arr_description, strlen(right.soldier_arr_description) + 1, right.soldier_arr_description);
	soldier_squad = new Soldier[soldier_squar_size];
	for (unsigned int i = 0; i < soldier_squar_size; ++i)
	{
		soldier_squad[i] = right.soldier_squad[i];
	}
}

void Sergeant::clean()
{
	delete[]soldier_arr_description;
	delete[]soldier_squad;
}

// other functions

void Sergeant::print_sergeants_part()
{
	cout << "Information about sergeant." << endl;
	print_soldiers_part();
	cout << "The descrition of his soldier squad is: " << soldier_arr_description << endl;
	cout << "The number of the soldier squad the sergeant is responsable for is: " << soldier_squar_size << endl;
	cout << "He controls the following soldiers: " << endl;
	cout << "*******************" << endl;
	for (unsigned int i = 0; i < soldier_squar_size; ++i)
	{
		soldier_squad[i].print_soldiers_part();
		cout << ".........................................." << endl;
	}
}


Sergeant & Sergeant::set_sergeant(Sergeant&obj, unsigned int mage_fighting_skills, bool is_it_commander)
{
	unsigned int new_soldier_arr_size;
	char new_soldier_squad_descrition[100];
	if (obj.get_name() == nullptr && obj.get_years() == 0 && obj.get_fight_skills() == 0
		&& obj.get_salary() == 0 &&
		obj.get_soldier_arr_descrition() == nullptr && obj.get_soldier_squar_size() == 0)
	{
		cout << "You will create a sergeant. " << endl;
		Soldier::set_soldier(obj, mage_fighting_skills);
		cout << "Give a description to the sergeant army: ";
		cin.ignore();
		cin.getline(new_soldier_squad_descrition, 100);
		obj.set_soldier_arr_description(new_soldier_squad_descrition);
		do
		{
			cout << "How many soldiers do you want your sergeant ot control? ";
			cin >> new_soldier_arr_size;
			cout << endl;
		} while (new_soldier_arr_size == 0);
	}
	else
	{
		new_soldier_arr_size = obj.get_soldier_squar_size();
	}
	obj.set_soldier_squar_size(new_soldier_arr_size);
	obj.soldier_squad = new(nothrow)Soldier[new_soldier_arr_size];
	for (unsigned int i = 0; i < new_soldier_arr_size; ++i)
	{
		cout << "You will create soldier number: " << (i+1) << ". ";
		Soldier::set_soldier(obj.get_soldier_squad()[i], obj.get_fight_skills());
		cout << endl;
	}
	return obj;
}