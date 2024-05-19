#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

enum DIGNITY {
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 11,
    QUEEN = 12,
    KING = 13,
    ACE = 14,
};

enum SUIT {
    DIAMONDS = 0,
    HEARTS = 1,
    CLUBS = 2,
    SPADES = 3,
};

typedef SUIT suit_t;
typedef DIGNITY dignity_t;

const int MAX_SUIT_SIZE = 9;

struct Card {
    string suit;
    dignity_t dignity;

    bool operator==(const Card& other) const {
        return suit == other.suit && dignity == other.dignity;
    }

    bool operator<(const Card& other) const {
        if (dignity != other.dignity)
            return dignity < other.dignity;
        else
            return suit < other.suit;
    }

    void PrintCard();
};

class CardsSet {
public:
    CardsSet& operator+( const CardsSet& second);
    CardsSet& operator-( const CardsSet& second);
    CardsSet& operator/( const CardsSet& second);

    void AddElement(const Card& card);
    void DelElement(const Card& card);
    void PrintSet() ;

    vector<Card> cards;
    unsigned int size;
    CardsSet() : size(0) {}

    CardsSet(const int newsize) : size(newsize) {
        vector<Card> vec(newsize);
        cards = vec;
    }

    CardsSet(const CardsSet& other) : size(other.size), cards(other.cards) {}

    CardsSet(CardsSet&& other) : size(other.size), cards(move(other.cards)) {
        other.size = 0;
    }

    CardsSet& operator=(const CardsSet& other) {
        if (this != &other) {
            size = other.size;
            cards = other.cards;
        }
        return *this;
    }

    CardsSet& operator=(CardsSet&& other) {
        size = other.size;
        cards = move(other.cards);
        other.size = 0;
        return *this;
    }
};