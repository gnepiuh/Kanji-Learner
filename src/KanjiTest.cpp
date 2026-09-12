#include "KanjiTest.hpp"
#include <iostream>
#include <string>

KanjiTest::KanjiTest(KanjiDatabase &database) : database(database)
{
    score = 0;
}

bool KanjiTest::runQuestion(const Kanji &kanji, int questionNum)
{
    bool firstAttempt = true;

    while (true)
    {
        displayQuestion(kanji, questionNum);

        if (checkAnswer(kanji, getAnswer()))
        {
            if (firstAttempt)
            {
                std::cout << "\nGood job! +1\n";
                return true;
            }
            std::cout << "\nNice! But, you don't get points this time\n";
            return false;
        }
        std::string choice;
        std::cout << "\nNot quite.\n";
        std::cout << "\n1. まだまだ\n";
        std::cout << "2. Give up\n";

        if (getRetryChoice() == "2")
        {
            displayAnswer(kanji);
            return false;
        }
        firstAttempt = false;
    }
}

void KanjiTest::displayQuestion(const Kanji &kanji, int questionNum)
{
    std::cout << "---------Question " << questionNum << " ---------";
    std::cout << "\nWhat is the reading of this kanji?\n";
    std::cout << kanji.character << std::endl;
}

std::string KanjiTest::getRetryChoice()
{
    while (true)
    {
        std::string choice = getAnswer();

        if (choice == "1" || choice == "2")
        {
            return choice;
        }

        std::cout << "\nPlease enter 1 or 2\n";
    }
}

std::string KanjiTest::getAnswer()
{
    std::string answer;
    std::getline(std::cin >> std::ws, answer);
    return answer;
}

bool KanjiTest::checkAnswer(const Kanji &kanji, const std::string &answer)
{
    for (const std::string &reading : kanji.reading)
    {
        if (answer == reading)
        {
            return true;
        }
    }
    for (const std::string &reading : kanji.romaji)
    {
        if (answer == reading)
        {
            return true;
        }
    }
    return false;
}

void KanjiTest::displayAnswer(const Kanji &kanji)
{
    std::cout << "\nThe correct readings for " << kanji.character << " are:\n";
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
    std::cout << std::endl;
}

void KanjiTest::displayResults()
{
    std::cout << "\nはい、おわり\n";
    std::cout << "\nスコアは" << score << "/" << database.getSize() << "です。\n";
    std::cout << "\npercentage: " << static_cast<double>(score) / database.getSize() * 100 << "%";
}

void KanjiTest::startTest()
{
    // system("clear");
    std::cout << "\nSession start\n";
    std::cout << "\n---Please enter your answer in either hiragana or romaji ONLY---\n";

    for (int i = 0; i < database.getSize(); i++)
    {
        Kanji kanji = database.getKanji(i);
        if (runQuestion(kanji, i + 1))
        {
            score++;
        }
    }
    displayResults();
}