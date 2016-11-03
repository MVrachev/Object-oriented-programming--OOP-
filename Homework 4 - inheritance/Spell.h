#ifndef _SPELL_HEADER
#define _SPELL_HEADER

enum Spell_types
{
	WEAK = 1,
	AVERAGE,
	STRONG,
};

class Spell
{
	char *spell_descrition;
	unsigned int spell_type;
	unsigned int spell_power_required;
public:
	Spell();
	Spell(char *new_spell_descrition, int new_spell_type, int new_spell_power_required);
	Spell(const Spell &right);
	Spell &operator=(const Spell &right);
	~Spell();
	void copy_spells(const Spell &right);
	// setters
	void set_spell_description(char * new_descrtion);
	void set_spell_type(unsigned int new_spell_type) { spell_type = new_spell_type; }
	void set_spell_power_required(unsigned int new_spell_power_required) { spell_power_required = new_spell_power_required; }
	//getters
	char *get_spell_descrition() const { return spell_descrition; }
	unsigned int get_spell_type() const { return spell_type; }
	unsigned int get_spell_power_required() const { return spell_power_required; }
	//other help functions
	bool operator==(const Spell &right);
	void print_spells();
};


#endif // !_SPELL_HEADER
