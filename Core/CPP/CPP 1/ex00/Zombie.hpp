#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>

class Zombie {

public:
	void 		announce(void);
	std::string get_name(void) const;
	void		set_name(std::string);


private:
	std::string _name;

};

#endif