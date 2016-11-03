#ifndef _COMMANDER_HEADER
#define _COMMANDER_HEADER
# include "Mage.h"
class Commander : public Soldier
{
	char *army_description;
	Mage *mage_squad;
	unsigned int mage_squad_size;
public:
	// Constructor and help functions
	Commander();
	Commander(const Commander&right);
	Commander &operator=(const Commander&right);
	~Commander();
	void clean_commander();
	void copy_commander(const Commander&right);
	//setters
	void set_army_descrition(char * new_com_army_descrition)
	{ 
		army_description = new char[strlen(new_com_army_descrition) + 1];
		strcpy_s(army_description, strlen(new_com_army_descrition) + 1, new_com_army_descrition);
	}
	void set_mage_squad(Mage *new_com_mage_squad){ mage_squad = new_com_mage_squad; }
	void set_mage_squar_size(unsigned int new_mage_squad_size) { mage_squad_size = new_mage_squad_size; }
	//getters
	Mage *get_mage_squad() const { return mage_squad; }
	char *get_army_descrition() const { return army_description; }
	//other functions
	void print_commander();
	double average_army_fight_skill();
	unsigned int whole_army_fight_skill();
	unsigned int whole_army_expense();
	//static functions
	static Commander &set_commander(Commander &obj);
};
#endif // !_COMMANDER_HEADER
