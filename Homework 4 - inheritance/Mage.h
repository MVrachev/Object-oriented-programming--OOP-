#ifndef _MAGE_HEADER
#define _MAGE_HEADER
# include "Soldier.h"
# include "Sergeant.h"
# include "MagicBook.h"

class Mage : public Soldier
{
	char* mage_squad_descrition;
	Sergeant *mage_sergeants;
	unsigned int magic_power;
	MagicBook mage_personal_book;
	unsigned int mage_sergeants_amount;
public:
	//constructors and other functions connected with them
	Mage();
	Mage::Mage(char *new_name, unsigned int new_years, unsigned int fight_skills, unsigned int salary, //for Soldier constructor
		unsigned int new_magic_power, char *new_mage_squad_description, unsigned int new_mage_sergeants_amount); // for Mage constructor
	Mage(const Mage&right);
	Mage &operator=(const Mage &right);
	~Mage();
	void clean();
	void copy_mages(const Mage&right);
	//setters
	void set_mage_squad_descrition(char *new_mage_squad_descrition)
	{
		mage_squad_descrition = new char[strlen(new_mage_squad_descrition) + 1];
		strcpy_s(mage_squad_descrition, strlen(new_mage_squad_descrition) + 1, new_mage_squad_descrition);
	}
	void set_magic_power(unsigned int new_magic_power) { magic_power = new_magic_power; }
	void set_new_mage_sergeants_amount(unsigned int new_mage_sergeants_amount) { mage_sergeants_amount = new_mage_sergeants_amount; }
	void set_magic_book(MagicBook &new_obj_book) { mage_personal_book = new_obj_book; }
	//getters
	Sergeant *get_mage_sergeants() const { return mage_sergeants; }
	unsigned int get_mage_sergeant_amount() const { return mage_sergeants_amount; }
	unsigned int get_magic_power() const { return magic_power; }
	char *get_mage_squad_descrition() const { return mage_squad_descrition; }
	MagicBook &get_mage_magic_book() { return mage_personal_book;}
	//other functions
	void print_mage();
	void mage_use_spell(Spell &using_spell);
	unsigned int mage_most_spells();
	void sort_spells();
	//static function
	static Mage &set_mage(Mage &obj, unsigned int fighting_skill_commander, bool is_it_commander = false);
};

#endif // !_MAGE_HEADER
