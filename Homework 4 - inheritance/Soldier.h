#ifndef _SOLDIER_CLASS

#define	_SOLDIER_CLASS

class Soldier
{
protected:
	char *name;
	unsigned int years;
	unsigned int fight_skills;
	unsigned int salary;
	//special vairable responsable for counting living objects
	static unsigned int living_objects_count;
public:
	//constructors and a few simple functions connected with them
	Soldier();
	Soldier(char * new_soldier_name, int new_soldier_years, int new_soldier_fight_skills, int _new_soldier_salary);
	Soldier(const Soldier& right);
	Soldier &operator=(const Soldier&right);
	~Soldier();
	void clean_soldiers();
	void copy_soldiers(const Soldier &right);
	//setters
	void set_whole_soldier(char new_name[], unsigned int new_obj_years, unsigned int new_obj_fight_skills, unsigned int new_obj_salary);
	//getters
	unsigned int get_years() const { return years; }
	int get_fight_skills() const { return fight_skills; }
	int get_salary() const { return salary; }
	char *get_name() const {return name;}
	// other functions
	void print_soldiers_part();
	//static
	static Soldier & set_soldier(Soldier&obj, unsigned int fighting_limit = 9999999, bool is_it_commander = false);
};


#endif // !_SOLDIER CLASS
