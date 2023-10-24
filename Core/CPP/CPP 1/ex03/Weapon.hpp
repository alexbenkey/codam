
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
public:
    Weapon();
    Weapon(std::string);
    ~Weapon(void); 

    const std::string&    getType(void);
    void            setType(std::string type);

private:

    std::string _type;
};

#endif