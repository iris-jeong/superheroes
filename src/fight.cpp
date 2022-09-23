#include "fight.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool loadHeroes(const std::string& fileName, std::vector<Hero*>& heroVector)
{
    bool success = true;
    heroVector.clear();
    
    //Create a filestream to open the file.
    std::ifstream inputFile(fileName);
    
    //If you can't open the file, return error.
    if(!inputFile.is_open()) {
        std::cout << "Unable to load file \""<< fileName << "\"!" << std::endl;
        success = false;
    }
    else {
        //Get every line in the file, dynamically create Heroes, & add to vector.
        while(!inputFile.eof()) {
            //Get line of input from file.
            std::string heroString;
            std::getline(inputFile, heroString);
            
            //Use the line of input to create a Hero.
            Hero* newHero = new Hero(heroString);
            
            //Add the newly created hero to the heroVector.
            heroVector.push_back(newHero);
        }
    }
	return success;
}

Hero* selectHero(std::vector<Hero*>& heroVector, const std::string& prompt, std::ostream& out, std::istream& in)
{
    //Display the prompt to user.
    out << prompt;
    
    //Receive input from user (their hero selection).
    int heroSelection;
    bool isValidInput = false;
    
    while(!isValidInput) {
        //Receive input from user.
        in >> heroSelection;

        //Check if the user's input is valid.
        if(heroSelection >= 0 && heroSelection < heroVector.size()) {
            isValidInput = true;
            break;
        }
        if(heroVector.size() == 0) {
            std::cout << "You don't have any heroes to choose from. Please load heroes first." << std::endl;
            std::cout << std::endl;
            return nullptr;
        }
        if(heroVector.size() == 1) {
            std::cout << "Not enough heroes for a fight! Load more heroes." << std::endl;
            return nullptr;
        }
        std::cout << "Please enter a valid selection from 0 - " << heroVector.size()-1 << std::endl;
            out << prompt;
    }
    //Return pointer to that hero.
	return heroVector[heroSelection];
}

void heroCombat(Hero* heroA, Hero* heroB, std::ostream& output)
{
    //Reset heroes health.
    heroA->resetHealth();
    heroB->resetHealth();
    
    //While neither of the heroes have 0 health, continue fighting.
    while(heroA->getHealth() > 0 && heroB->getHealth() > 0) {
        output << heroA->getName() << " has " << heroA->getHealth() << " health" <<  std::endl;
        output << heroB->getName() << " has " << heroB->getHealth() << " health" << std::endl;
        
        //Each hero selects a random power with Hero::useRandomPower().
        Power* aPower = heroA->useRandomPower();
        Power* bPower = heroB->useRandomPower();
        
        //Display power descriptions
        std::cout << heroA->getName() << " " << aPower->use() << std::endl;
        std::cout << heroB->getName() << " " << bPower->use() << std:: endl;
        
        //Have appropriate hero takeDamage() (if tie, both lose -1 health).
        int fightResult = aPower->fight(bPower);
        switch (fightResult) {
            case 1:
                heroB->takeDamage();
                break;
            case 0:
                heroA->takeDamage();
                heroB->takeDamage();
                break;
            case -1:
                heroA->takeDamage();
                break;
        }
        output << "---------------------------------------" << std::endl;
    }
    //Determine the winner.
    if(heroA->getHealth() == 0 && heroB->getHealth() > 0) {
        output << heroB->getName() << " WINS!!!" << std::endl;
    }
    else if(heroB->getHealth() == 0 && heroA->getHealth() > 0) {
        output << heroA->getName() << " WINS!!!" << std::endl;
    }
    else {
        output << heroA->getName() << " and " << heroB->getName() << " LOSE!!!" << std::endl;
    }
    output << std::endl;
}

int fight(const std::string& inputFileName, const std::string& outputFileName, unsigned seed)
{
    //Generate an input stream & open inputFileName.
    std::ifstream inputStream(inputFileName);
    //Check if file opens.
    if(!inputStream.is_open()) {//if file doesn't open, return a number other than 0.
        return -1;
    }
    
    //Generate an output stream & open outputFilename.
    std::ofstream outputStream(outputFileName);
    //check if file opens
    if(!outputStream.is_open()) {//if file doesn't open, return a number other than 0.
        return -1;
    }
    //Call the other fight function.
    return fight(inputStream, outputStream, seed);
}

int fight(std::istream& input, std::ostream& output, unsigned seed)
{
    //Seed the random generator.
    std::srand(seed);
    output << "Seed: " << seed << std::endl;
    output << std::endl;
    //Vector of pointers to all the heroes that are loaded.
    std::vector<Hero*> heroVector;
    
    int choice = 0;
    
    //While the user doesn't want to quit program.
    while(choice != 4) {
        //Present a menu to the user using the ostream.
        //Retrieve file name from user using input stream using getline.
        output << "Choose an option:" << std::endl;
        output << "1. Load Heroes" << std::endl;
        output << "2. Print Hero Roster" << std::endl;
        output << "3. Hero Fight!" << std::endl;
        output << "4. Quit" << std::endl;
        output << "> ";
        
        input >> choice;
        output << std::endl;
        
        switch(choice) {
            case 1: { //Load heroes.
                std::string fileName = "";
                output << "Enter the file to load: ";
                input >> fileName;
                loadHeroes(fileName, heroVector);
                output << std::endl;
                break;
            }
            case 2: { //List heroes.
                output << "The following " << heroVector.size() << " heroes are loaded..." << std::endl;
                output << "---------------------------------------" << std::endl;
                for(int i = 0; i < heroVector.size(); i++) {
                    output << *heroVector[i];
                    output << "---------------------------------------" << std::endl;
                }
                output << std::endl;
                break;
            }
            case 3: { //Fight heroes.
                //Print list of heroes to select
                for(int i = 0; i < heroVector.size(); i++) {
                    output << i << ": " << heroVector[i]->getName() << std::endl;
                }
                std::string prompt = "Select your first hero: ";
                Hero* firstHero = selectHero(heroVector, prompt, output, input);
                if(firstHero == nullptr) {
                    break;
                }
                prompt = "Select your second hero: ";
                Hero* secondHero = selectHero(heroVector, prompt, output, input);
                output << "---------------------------------------" << std::endl;
                heroCombat(firstHero, secondHero, output);
                break;
            }
            case 4: { //Quit.
                choice = 4;
                output << "Goodbye" << std::endl;
                break;
            }
            default: { //Error.
                std::cout << "Please enter a valid option 1-4" << std::endl;
                std::cout << std::endl;
                break;
            }
        }
    }
    
	return 0;
}
