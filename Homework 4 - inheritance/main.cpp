# include <iostream>
# include "Soldier.h"
# include "Sergeant.h"
# include "Spell.h"
# include "MagicBook.h"
# include "Mage.h"
# include "Commander.h"
using namespace std;

int main(){
	
	// A check for Soldier construtors
	/*
	Soldier a;
	Soldier::set_soldier(a, 9999999);
	cout << a.get_name() << endl;
	Soldier b(a);
	cout << "b name: ";
	cout << b.get_name() << endl; 
	*/

	//A check for Sergeant copy constructor
	/*
	Sergeant a;
	Sergeant::set_sergeant(a, 9999999);
	a.print_sergeants_part();
	cout << "--------------" << endl;
	Sergeant b(a);
	b.print_sergeants_part();
	*/
	
	// A check for Spell constructors
	/*
	Spell c("A bad magic!", AVERAGE, 100);
	cout << c.get_spell_descrition() << endl;
	cout << c.get_spell_type() << endl;
	cout << c.get_spell_power_required() << endl;
	cout << "***********************" << endl;
	Spell v(c);
	cout << v.get_spell_descrition() << endl;
	cout << v.get_spell_type() << endl;
	cout << v.get_spell_power_required() << endl;
	*/
	
	// A check for MagicBook constructors
	/*
	MagicBook d;
	MagicBook::set_magic_book(d);
	d.print_magic_book();
	cout << endl << "................................." << endl <<  endl;
	//MagicBook v(d);
	MagicBook v;
	v = d;
	v.print_magic_book();
	* /
	

	//A check for the functuon add spell for Magic book
	/*
	Spell * hemp = new Spell[1];
	for (int i = 0; i < 1; ++i)
	{
		cout << "Give a descrition for spell number " << i << endl;
		char str[100];
		cin.getline(str, 100);
		hemp[i].set_spell_description(str);
		hemp[i].set_spell_power_required(i + 1);
		hemp[i].set_spell_type(2);
	}
	cout << "**************" << endl;
	MagicBook d(hemp, 1);
	Spell c("A bad magic!", AVERAGE, 100);
	d.add_spell(c);
	Spell k("ETERNAL LIFE!", STRONG, 81);
	d.add_spell(k);
	d.print();
	*/

	// A check for the use magic book functions
	/*
	Spell k("A bad magic!", AVERAGE, 100);
	MagicBook d;
	MagicBook::set_magic_book(d);
	d.add_spell(k);
	d.print_magic_book();
	//Spell v("ME!", STRONG, 70);
	cout << endl << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;
	d.use_spell(k);
	d.print_magic_book();
	*/
	

	//A check for Mage setter function and copy constructor (operator=)
	/*
	Mage example;
	Mage::set_mage(example, 9999999);
	Spell c("A bad magic!", AVERAGE, 100);
	example.mage_use_spell(c);
	//example.print_mage();
	Mage second_example;
	//Mage second_example(example);
	second_example = example;
	second_example.print_mage();
	*/

	//A check for Commanders setter functions and all constructors
	/*
	Commander example;
	Commander::set_commander(example);
	cout << "PRINTTTTTTTTTTTTTTTTTTTTTTTTTT !!!!!" << endl;
	example.print_commander();
	cout << endl << "+++++++++++++++++++++++++++++++++++++++++" << endl;
	Commander b(example);
	b.print_commander();
	*/
	
	//A check for final functions from the task
	/*
	Commander example;
	Commander::set_commander(example);
	cout << example.whole_army_fight_skill() << endl;
	cout << example.whole_army_expense() << endl;
	cout << example.average_army_fight_skill() << endl;
	*/
	
	//A check for the bonus task!
	Mage example;
	Mage::set_mage(example, 9999999);
	cout << example.mage_most_spells() << endl;
	return 0;
	
}