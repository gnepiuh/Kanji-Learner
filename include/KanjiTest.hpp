#pragma once

#include "KanjiDatabase.hpp"

struct KanjiTest
{
    KanjiTest(KanjiDatabase &database);
    void startTest();
    bool runQuestion(const Kanji &kanji, int questionNum);
    void displayQuestion(const Kanji &kanji, int questionNum);
    std::string getRetryChoice();
    std::string getAnswer();
    bool checkAnswer(const Kanji &kanji, const std::string &answer);
    void displayAnswer(const Kanji &kanji);
    void displayResults();

private:
    KanjiDatabase &database;
    int score;
};
