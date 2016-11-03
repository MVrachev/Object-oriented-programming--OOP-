# include <iostream>
# include "Soldier.h"

using namespace std;

unsigned int Soldier::living_objects_count = 0;

Soldier::Soldier()
{
	name = nullptr;
	years = 0;
	fight_skills = 0;
	salary = 0;
	++living_objects_count;
	
}

Soldier::Soldier(char * new_soldier_name, int new_soldier_years, int new_soldier_fight_skills, int _new_soldier_salary)
{
	name = new (nothrow) char[strlen(new_soldier_name) + 1];
	if (!name)
		cerr << "Problem while creating Soldier name!" << endl;
	else
		strcpy_s(name, strlen(new_soldier_name) + 1, new_soldier_name);
	years = new_soldier_years;
	fight_skills = new_soldier_fight_skills;
	salary = _new_soldier_salary;
	++living_objects_count;
}

Soldier::Soldier(const Soldier &right)
{
	copy_soldiers(right);
}

Soldier &Soldier::operator=(const Soldier &right)
{
	if (this != &right)
	{
		delete[]name;
		copy_soldiers(right);
	}
	return *this;
}

Soldier::~Soldier()
{
	clean_soldiers();
	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	cout << "The soldier destructor has been used!" << endl;
	--living_objects_count;
}

void Soldier::copy_soldiers(const Soldier &right)
{
	years = right.years;
	fight_skills = right.fight_skills;
	salary = right.salary;
	name = new (nothrow)char[strlen(right.name) + 1];
	if (strlen(name) == 1)
		cerr << "Problem while creating Soldier name!" << endl;
	strcpy_s(name, strlen(right.name) + 1, right.name);
}

void Soldier::clean_soldiers()
{
	delete[] name;
}


void Soldier::set_whole_soldier(char new_name[], unsigned int new_obj_years, unsigned int new_obj_fight_skills, unsigned int new_obj_salary)
{
	name = new (nothrow)char[strlen(new_name) + 1];
	strcpy_s(name, strlen(new_name) + 1, new_name);
	years = new_obj_years;
	fight_skills = new_obj_fight_skills;
	salary = new_obj_salary;
}

Soldier & Soldier::set_soldier(Soldier&obj, unsigned int fighting_skill_limit, bool is_it_commander)
{
	char new_obj_name[100];
	unsigned int new_obj_years, new_obj_fighting_skills, new_obj_salary;
	while (obj.get_name() == nullptr && obj.get_years() == 0
		&& obj.get_fight_skills() == 0 && obj.get_salary() == 0)
	{
		cout << "Enter the new object name: ";
		if (!is_it_commander)
			cin.ignore();
		cin.getline(new_obj_name, 100);
		cout << "How old is he? ";
		cin >> new_obj_years;
		do
		{
			cout << "The fighting skills of the new object cannot be greater than " << fighting_skill_limit << "." << endl;
			cout << "How much fighting skills does the new object has? ";
			cin >> new_obj_fighting_skills;
		} while (new_obj_fighting_skills > fighting_skill_limit);
		cout << "How much money should he get? ";
		cin >> new_obj_salary;
		obj.set_whole_soldier(new_obj_name, new_obj_years,
			new_obj_fighting_skills, new_obj_salary);
	}
	return obj;
}

void Soldier::print_soldiers_part()
{
	cout << "The object name is: " << name << endl;
	cout << "He is " << years << " years old." << endl;
	cout << "His fighting skills are " << fight_skills << endl;
	cout << "He gets " << salary << " gold coins a day." << endl;
}


