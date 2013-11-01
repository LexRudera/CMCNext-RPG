#ifndef PARTY_H
#define PARTY_H

#include <vector>
#include "Inventory.hpp"
#include "Character.hpp"

class Party
{
public:
	Party();
	virtual ~Party();

	Inventory* GetInventory() {return &m_GlobalInv;}

protected:
private:
	Inventory m_GlobalInv;
	std::vector<Character*> m_Members;
};

#endif // PARTY_H
