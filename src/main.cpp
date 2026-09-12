#include "KanjiDatabase.hpp"
#include "KanjiTest.hpp"
#include "KanjiStudy.hpp"

#include <iostream>

int getModeChoice()
{
    while (true)
    {
        std::cout << "\n---Kanji Learner---\n";
        std::cout << "1. Test Mode\n";
        std::cout << "2. Study Mode\n";
        std::cout << "3. Exit\n";
        std::string choice;
        std::cin >> choice;
        if (choice == "1")
        {
            return 1;
        }
        else if (choice == "2")
        {
            return 2;
        }
        else if (choice == "3")
        {
            return 3;
        }

        std::cout << "Please enter 1, 2, or 3.\n";
    }
}

int main()
{
    KanjiDatabase db;
    std::string fileName;
    
    std::cout << "Welcome to Kanji Learner. Please select a mode\n";
    int mode = getModeChoice();
    if(mode == 3) {
        std::cout<<"goodbye!";
        return 0;
    }
    while (true)
    {
        std::cout <<"Please enter then name of your file.\n";
        std::getline(std::cin>>std::ws,fileName);
        if (db.loadKanjiFile(fileName))
        {
            break;
        }
        std::cout << "File cannot be found, please try again.\n";
    }
    std::cout<<fileName<<" successfully loaded\n";
    KanjiTest test(db);
    KanjiStudy study(db);
    if(mode==1) {
        test.startTest();
    }
    else if(mode == 2) {
        study.startStudy();
    }
    return 0;
}