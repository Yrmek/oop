#include "Cards.h"

const int SUIT_AMOUNT = 4;
const char* suitsArr[SUIT_AMOUNT]{ "Diamonds","Hearts","Clubs","Spades" };
const int DIG_AMOUNT = 13;
const char* dignityArr[DIG_AMOUNT]{ "TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN","JACK","QUEEN","KING","ACE" };

void Card::PrintCard() {
    cout << "_______________________________" << endl;
    cout << "Suit :" << this->suit << endl;
    cout << "Dignity : " << dignityArr[this->dignity - 2] << endl;
    cout << "_______________________________" << endl;
}

void CardsSet::PrintSet() {
    for (auto& card : this->cards) {
        card.PrintCard();
    }
}


CardsSet& CardsSet::MergeSets(const CardsSet& first, const CardsSet& second) {
    CardsSet* result = new CardsSet;

    for (const auto& card : first.cards) {
        result->AddElement(card);
    }

    for (const auto& card : second.cards) {
        if (find(result->cards.begin(), result->cards.end(), card) == result->cards.end()) {
            result->AddElement(card);
        }
    }

    return *result;
}

CardsSet& CardsSet::CrossSets(const CardsSet& first, const CardsSet& second) {
    CardsSet* result = new CardsSet;
    vector<Card> sortedFirst = first.cards;
    vector<Card> sortedSecond = second.cards;
    sort(sortedFirst.begin(), sortedFirst.end());
    sort(sortedSecond.begin(), sortedSecond.end());
    set_intersection(sortedFirst.begin(), sortedFirst.end(), sortedSecond.begin(), sortedSecond.end(), back_inserter(result->cards));
    result->size = result->cards.size();
    return *result;
}

CardsSet& CardsSet::operator-(const CardsSet& first, const CardsSet& second) {
    CardsSet* result = new CardsSet;
    vector<Card> sortedFirst = first.cards;
    vector<Card> sortedSecond = second.cards;
    sort(sortedFirst.begin(), sortedFirst.end());
    sort(sortedSecond.begin(), sortedSecond.end());
    set_difference(sortedFirst.begin(), sortedFirst.end(), sortedSecond.begin(), sortedSecond.end(), back_inserter(result->cards));
    result->size = result->cards.size();
    return *result;
}

void CardsSet::AddElement(const Card& card) {
    cards.push_back(card);
    this->size++;
}

void CardsSet::DelElement(const Card& card) {
    auto it = find(cards.begin(), cards.end(), card);
    if (it != cards.end()) {
        cards.erase(it);
        this->size--;
    }
}