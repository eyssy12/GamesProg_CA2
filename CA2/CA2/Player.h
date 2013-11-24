
#include <string>


using std::string;

class Player
{
public:

	//constructor
	Player(string name, int hp, Weapon weapon);

	//methods

private:

	//variables
	string mName;
	int mHp;
	Weapon mWeapon;

};