#include "powers.h"
#include <iostream>
#include <string>

POWER_ID Power::getID()
{
	return mPowerID;
}

// ~~~~~~ STRENGTH POWER ~~~~~~~~
StrengthPower::StrengthPower() {
    mDescription = "Superior gym steroid strength";
    mPowerID = POWER_STRENGTH;
}

std::string StrengthPower::use() {
    return "flexes on 'em";
}

int StrengthPower::fight(Power* other) {
    //Create variable to hold the result of the fight
    int result;
    
    //Determine the winner of the fight
    switch(other->getID()) {
        case POWER_STRENGTH:
            result = 0;
            std::cout << "It's a tie!" << std::endl;
            break;
        case POWER_FLIGHT:
            result = -1;
            std::cout << "FLIGHT WINS" << std::endl;
            break;
        case POWER_LASER:
            result = 1;
            std::cout << "STRENGTH WINS" << std::endl;
            break;
        case POWER_INTEL:
            result = -1;
            std::cout << "INTEL WINS" << std::endl;
            break;
        case POWER_GADGETS:
            result = 1;
            std::cout << "STRENGTH WINS" << std::endl;
            break;
        case POWER_NATIONAL:
            result = 1;
            std::cout << "STRENGTH WINS" << std::endl;
            break;
    }
    return result;
}

// ~~~~~~ FLIGHT POWER ~~~~~~~~
FlightPower::FlightPower() {
    mDescription = "Incredible flying abilities";
    mPowerID = POWER_FLIGHT;
}

std::string FlightPower::use() {
    return "takes a first class flight outta here, cya!";
}

int FlightPower::fight(Power* other) {
    //Create variable to hold the result of the fight.
    int result;
    
    //Determine the winner of the fight
    switch(other->getID()) {
        case POWER_STRENGTH:
            result = 1;
            std::cout << "FLIGHT WINS" << std::endl;
            break;
        case POWER_FLIGHT:
            result = 0;
            std::cout << "It's a tie!" << std::endl;
            break;
        case POWER_LASER:
            result = -1;
            std::cout << "LASER WINS" << std::endl;
            break;
        case POWER_INTEL:
            result = 1;
            std::cout << "FLIGHT WINS" << std::endl;
            break;
        case POWER_GADGETS:
            result = -1;
            std::cout << "GADGET WINS" << std::endl;
            break;
        case POWER_NATIONAL:
            result = 1;
            std::cout <<  "FLIGHT WINS" << std::endl;
            break;
    }
    return result;
}

// ~~~~~~ LASER POWER ~~~~~~~~
LaserPower::LaserPower() {
    mDescription = "Supersonic rays of doom";
    mPowerID = POWER_LASER;
}

std::string LaserPower::use() {
    return "shoots red hot rays at you... pew pew!";
}

int LaserPower::fight(Power* other) {
    //Create variable to hold the result of the fight.
    int result;
    
    //Determine the winner of the fight
    switch(other->getID()) {
        case POWER_STRENGTH:
            result = -1;
            std::cout << "STRENGTH WINS" << std::endl;
            break;
        case POWER_FLIGHT:
            result = 1;
            std::cout << "LASER WINS" << std::endl;
            break;
        case POWER_LASER:
            result = 0;
            std::cout << "It's a tie!" << std::endl;
            break;
        case POWER_INTEL:
            result = 1;
            std::cout << "LASER WINS" << std::endl;
            break;
        case POWER_GADGETS:
            result = -1;
            std::cout << "GADGET WINS" << std::endl;
            break;
        case POWER_NATIONAL:
            result = 1;
            std::cout << "LASER WINS" << std::endl;
            break;
    }
    return result;
}

// ~~~~~~ INTEL POWER ~~~~~~~~
IntelPower::IntelPower() {
    mDescription = "Supernatural intelligence ";
    mPowerID = POWER_INTEL;
}

std::string IntelPower::use() {
    return "thinks hard";
}

int IntelPower::fight(Power* other) {
    //Create variable to hold the result of the fight.
    int result;
    
    //Determine the winner of the fight
    switch(other->getID()) {
        case POWER_STRENGTH:
            result = 1;
            std::cout << "INTEL WINS" << std::endl;
            break;
        case POWER_FLIGHT:
            result = -1;
            std::cout << "FLIGHT WINS" << std::endl;
            break;
        case POWER_LASER:
            result = -1;
            std::cout << "LASER WINS" << std::endl;
            break;
        case POWER_INTEL:
            result = 0;
            std::cout << "It's a tie!" << std::endl;
            break;
        case POWER_GADGETS:
            result = 1;
            std::cout << "INTEL WINS" << std::endl;
            break;
        case POWER_NATIONAL:
            result = 1;
            std::cout << "INTEL WINS" << std::endl;
            break;
    }
    return result;
}

// ~~~~~~ GADGET POWER ~~~~~~~~
GadgetPower::GadgetPower() {
    mDescription = "Uses cool gadgets like Iron Man but better";
    mPowerID = POWER_GADGETS;
}

std::string GadgetPower::use() {
    return "presses a button that transforms the fake plant nearby into a bazooka to shoot at you. BOOOOM";
}

int GadgetPower::fight(Power *other) {
    //Create variable to hold the result of the fight.
    int result;
    
    //Determine the winner of the fight
    switch(other->getID()) {
        case POWER_STRENGTH:
            result = -1;
            std::cout << "STRENGTH WINS" << std::endl;
            break;
        case POWER_FLIGHT:
            result = 1;
            std::cout << "GADGET WINS" << std::endl;
            break;
        case POWER_LASER:
            result = 1;
            std::cout << "GADGET WINS" << std::endl;
            break;
        case POWER_INTEL:
            result = -1;
            std::cout << "INTEL WINS" << std::endl;
            break;
        case POWER_GADGETS:
            result = 0;
            std::cout << "It's a tie!" << std::endl;
            break;
        case POWER_NATIONAL:
            result = 1;
            std::cout << "GADGET WINS" << std::endl;
            break;
    }
    return result;
}
// ~~~~~~ NATIONAL POWER ~~~~~~~~
NationalPower::NationalPower() {
    mDescription = "Ability to use the entire nation as their army at will.";
    mPowerID = POWER_NATIONAL;
}

std::string NationalPower::use() {
    return "calls on the nation to help gang up on you and pummels you. Bam bam bam!";
}

int NationalPower::fight(Power* other) {
    //Create variable to hold the result of the fight.
    int result;
    
    //Determine the winner of the fight
    switch(other->getID()) {
        case POWER_STRENGTH:
            result = -1;
            std::cout << "STRENGTH WINS" << std::endl;
            break;
        case POWER_FLIGHT:
            result = -1;
            std::cout << "FLIGHT WINS" << std::endl;
            break;
        case POWER_LASER:
            result = -1;
            std::cout << "LASER WINS" << std::endl;
            break;
        case POWER_INTEL:
            result = -1;
            std::cout << "INTEL WINS" << std::endl;
            break;
        case POWER_GADGETS:
            result = -1;
            std::cout << "GADGET WINS" << std::endl;
            break;
        case POWER_NATIONAL:
            result = 0;
            std::cout << "It's a tie!" << std::endl;
            break;
    }
    return result;
}

Power* powerFactory(const std::string& powerName)
{
    if(powerName == "strength") {
        StrengthPower* strength = new StrengthPower;
        return strength;
    }
    else if(powerName == "flight") {
        FlightPower* flight = new FlightPower;
        return flight;
    }
    else if(powerName == "laser") {
        LaserPower* laser = new LaserPower;
        return laser;
    }
    else if(powerName == "intel") {
        IntelPower* intel = new IntelPower;
        return intel;
    }
    else if(powerName == "gadget") {
        GadgetPower* gadget = new GadgetPower;
        return gadget;
    }
    else if(powerName == "national") {
        NationalPower* national = new NationalPower;
        return national;
    }
    else {
        std::cout << "Did not receive valid power." << std::endl;
        return nullptr;
    }
}

std::ostream& operator<<(std::ostream& out, const Power& p)
{
	out << p.mDescription;
	return out;
}
