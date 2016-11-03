#ifndef _SERGEANT_HEADER
#define _SERGEANT_HEADER
# include "Soldier.h"
using namespace std;
class Sergeant : public Soldier
{
	char *soldier_arr_description;
	Soldier *soldier_squad;
	unsigned int soldier_squar_size;
public:
	// Constructor and help functions
	Sergeant();
	Sergeant(char * new_sergeant_name, int new_sergeant_years, int new_sergeant_fight_skills,int new_sergeant_salary,
		char * new_soldier_arr_description, int new_soldier_squar_size);
	Sergeant(const Sergeant &right);
	Sergeant &operator=(const Sergeant&right);
	~Sergeant();
	void copy_sergeants(const Sergeant&right);
	void clean();
	//setters
	void set_soldier_squad(Soldier *temp_soldier_squad) { soldier_squad = temp_soldier_squad; }
	void set_soldier_squar_size(unsigned int temp_soldier_arr_size) { soldier_squar_size = temp_soldier_arr_size; }
	void set_soldier_arr_description(char *new_soldier_arr_description) 
	{
		soldier_arr_description = new char[strlen(new_soldier_arr_description) + 1];
		strcpy_s(soldier_arr_description, strlen(new_soldier_arr_description) + 1, new_soldier_arr_description);
	}
	//getters
	Soldier *get_soldier_squad() const { return soldier_squad; }
	char *get_soldier_arr_descrition () const { return soldier_arr_description; }
	unsigned int get_soldier_squar_size() const { return soldier_squar_size; }
	// other functions
	void print_sergeants_part();
	//static function
	static Sergeant &set_sergeant(Sergeant&obj, unsigned int mage_fighting_skills = 9999999, bool is_it_commander = false);
};

#endif // !_SERGEANT_HEADER
