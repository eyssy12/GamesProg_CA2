
#include <string>
#include "Item.h"

using std::string;

class HealingKit : public Item
{

public:

	HealingKit(string name, Item::ItemType itemType, int healingRate);

	int getHealingRate();
	void setHealingRate();

private:
	int healingRate;
};
