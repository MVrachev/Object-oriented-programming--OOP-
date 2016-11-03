# include <iostream>
# include "MagicBook.h"
//# include "Spell.h"

using namespace std;

// constructors and functions connected with them

MagicBook::MagicBook()
{
	number_of_pages = 1;
	spell_pages = nullptr;
}

MagicBook::MagicBook(const MagicBook &right)
{
	copy_magic_books(right);
}

MagicBook &MagicBook::operator=(const MagicBook &right)
{
	if (this != &right)
		copy_magic_books(right);
	return *this;
}

void MagicBook::copy_magic_books(const MagicBook&right)
{
	if (right.number_of_pages == 0)
	{
		cerr << "The right object number of pages are 0 which is not possible!";
		return;
	}
	number_of_pages = right.number_of_pages;
	delete[]spell_pages;
	spell_pages = new Spell[right.number_of_pages];
	for ( unsigned int i = 0; i < right.number_of_pages - 1; ++i)
	{
		spell_pages[i] = right.spell_pages[i];
	}
}

MagicBook::~MagicBook()
{
	delete[]spell_pages;
	cout << "Magic book destrutor used!" << endl << endl;
}

// other functions

void MagicBook::print_magic_book()
{
	cout << "The number of the pages in the Magic book is: " << number_of_pages << endl;
	cout << "The spells in the books are: " << endl << endl;
	for (unsigned int i = 0; i < number_of_pages - 1; ++i)
	{
		cout << "//////////////" << endl;
		cout << "Spell number " << (i+1) << " from the magic book." << endl;
		spell_pages[i].print_spells();
	}
}

MagicBook &MagicBook::set_magic_book(MagicBook&obj)
{
	unsigned int new_magic_book_spell_number;
	if (obj.get_number_of_spells() == 0)
	{
		cout << "Now you will create à magic book!" << endl;
		do
		{
			cout << "How many spells shoud it have? ";
			cin >> new_magic_book_spell_number;
		} while (new_magic_book_spell_number == 0);
	}
	else 
		new_magic_book_spell_number = obj.get_number_of_spells();
	obj.set_number_of_spells(new_magic_book_spell_number);
	obj.spell_pages = new Spell[new_magic_book_spell_number + 1];
	unsigned int temp_spell_power;
	unsigned int temp_spell_type;
	for (unsigned int i = 0; i < new_magic_book_spell_number; ++i)
	{
		cout << "Give a descrition for spell number " << (i+1) << "." << endl;
		char str[100];
		cin.ignore();
		cin.getline(str, 100);
		obj.get_spell_pages()[i].set_spell_description(str);
		cout << "How much spell power should the spell require? ";
		cin >> temp_spell_power;
		obj.get_spell_pages()[i].set_spell_power_required(temp_spell_power);
		do
		{
			cout << "What type should the spell be? Weak - 1, Average - 2, Stront - 3. " << endl;
			cin >> temp_spell_type;
		} while (temp_spell_type < 1 || temp_spell_type > 3);
		obj.get_spell_pages()[i].set_spell_type(temp_spell_type);
		cout << ".................................." << endl;
	}

	return obj;
}

void MagicBook::add_spell(Spell &new_spell)
{
	if (number_of_pages == 1)
	{
		cerr << "There should be more than one page!" << endl;
		return;
	}
	for (unsigned int i = 0; i < number_of_pages - 1; ++i)
	{
		if ((spell_pages[i] == new_spell) == true)
		{
			cerr << "This magic already exists!" << endl;
			return;
		}
	}
	Spell *temp = new Spell[number_of_pages];
	for (unsigned int i = 0; i < number_of_pages - 1; ++i)
	{
		temp[i] = spell_pages[i];
	}
	delete[]spell_pages;
	spell_pages = temp;
	temp = nullptr;
	spell_pages[number_of_pages - 1] = new_spell;
	number_of_pages += 1;
}

void MagicBook::use_spell(Spell &spell_to_use)
{
	if (!number_of_pages == 1)
	{
		cerr << "There should be at least two pages to use a magic!" << endl;
		return;
	}
	int spell_using_index = -1;
	for (unsigned int i = 0; i < number_of_pages - 1; ++i)
	{
		if (spell_pages[i] == spell_to_use)
		{
			spell_using_index = i;
			break;
		}
	}
	if (spell_using_index == -1)
	{
		cerr << "The magic you want to use it's not found in that magic book!" << endl;
		return;
	}
	number_of_pages -= 1;
	Spell *temp = new Spell[number_of_pages];
	for (int j = 0; j < spell_using_index; ++j)
	{
		temp[j] = spell_pages[j];
	}
	for (unsigned int k = spell_using_index + 1; k < number_of_pages; ++k)
	{
		temp[k - 1] = spell_pages[k];
	}
	delete[]spell_pages;
	spell_pages = temp;
	temp = nullptr;
}