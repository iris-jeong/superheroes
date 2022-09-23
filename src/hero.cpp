#include "hero.h"
#include "strlib.h"
#include <iostream>

Hero::Hero(const std::string& heroDef)
{
    //Use strSplit function to split the input string.
    std::vector<std::string> stringVec = strSplit(heroDef, '|');
    
    //Assign hero's mName, mMaxHealth, and mHealth.
    mName = stringVec[0];
    mMaxHealth = std::stoi(stringVec[2]);
    mHealth = std::stoi(stringVec[2]);
    
    //Use strSplit again to get the individual powers.
    std::vector<std::string> powerVec = strSplit(stringVec[1], ',');
    
    //Use powerFactory to populate the vector of power (mPowers).
    for(std::string power: powerVec) {
        mPowers.push_back(powerFactory(power));
    }
}

std::string Hero::getName()
{
	return mName;
}

Power* Hero::useRandomPower()
{
	// TODO: Complete this function and replace return value
    //set the range for which to generate a random # from
    int minIndex = 0;
    int maxIndex = mPowers.size()-1;
    int range = maxIndex - minIndex + 1;

    //Generate the random index using range
    int indexOfPower = rand() % range + minIndex;

    //Create a pointer to a Power object
    Power* selectedPower;

    //Set the pointer to the randomly selected power
    selectedPower = mPowers[indexOfPower];

    return selectedPower;
}

int Hero::getHealth()
{
	// TODO: Complete this function and replace return value
	return mHealth;
}

void Hero::takeDamage()
{
    mHealth = mHealth - 1;
}

void Hero::resetHealth()
{
    mHealth = mMaxHealth;
}

std::ostream& operator<<(std::ostream& out, const Hero& h)
{
	out << h.mName << " has the following powers..." << std::endl;
	
	for (int i = 0; i < h.mPowers.size(); i++)
	{
		std::cout << "\t" << *(h.mPowers[i]) << std::endl;
	}

	return out;
}
