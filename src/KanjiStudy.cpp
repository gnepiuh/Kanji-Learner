#include "KanjiStudy.hpp"
#include <iostream>

KanjiStudy::KanjiStudy(KanjiDatabase &database) : database(database) {}

void KanjiStudy::displayKanji(const Kanji &kanji)
{
    std::cout << "\n"
              << kanji.character << "\n\n";
    std::cout << "Hiragana: ";
    for (const std::string &Hiragana : kanji.reading)
    {
        std::cout << Hiragana << " ";
    }
    std::cout << "\nRomaji: ";
    for (const std::string &Romaji : kanji.romaji)
    {
        std::cout << Romaji << " ";
    }
    std::cout << "\nMeaning: " << kanji.meaning << std::endl;
}

void KanjiStudy::startStudy()
{
    std::cout << "--- Study Mode ---\n\n";
    int studied = 0;
    for (int i = 0; i < database.getSize(); i++)
    {
        std::cout << "--- Kanji #" << i + 1 << " ---\n";
        const Kanji &kanji = database.getKanji(i);
        displayKanji(kanji);
        std::cout << "Press enter to continue, 2 to quit\n";
        std::string enter;
        std::getline(std::cin, enter);
        studied++;
        if (enter == "2")
        {
            break;
        }
    }
    std::cout << "You have studied " << studied << " kanji today!";
}