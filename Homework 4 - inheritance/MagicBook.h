#ifndef _MAGIC_BOOK_HEADER
#define _MAGIC_BOOK_HEADER
#include "Spell.h"

class MagicBook
{
	Spell * spell_pages;
	unsigned int number_of_pages;
public:
	//constructors and other functions connected with them
	MagicBook();
	MagicBook(unsigned int new_number_of_pages) { spell_pages = nullptr; number_of_pages = new_number_of_pages + 1; }
	MagicBook(const MagicBook &right);
	MagicBook &operator=(const MagicBook&right);
	~MagicBook();
	void print_magic_book();
	void copy_magic_books(const MagicBook&right);
	//setters
	void set_number_of_spells(unsigned int new_number_of_spells) { number_of_pages = new_number_of_spells + 1; }
	// getters
	Spell * get_spell_pages() const { return spell_pages; }
	unsigned int get_number_of_spells() const { return number_of_pages - 1; }
	// other functions
	void add_spell(Spell &new_spell);
	void use_spell(Spell &spell_to_use);
	//static function
	static MagicBook &set_magic_book (MagicBook&obj);
};



#endif // !_MAGIC_BOOK_HEADER
