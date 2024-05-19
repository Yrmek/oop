#include "Cards.h"
int main() {
    CardsSet firstset;
    CardsSet secondset;
    firstset.AddElement({ "Diamonds", JACK });
    firstset.AddElement({ "Spades", THREE });
    firstset.AddElement({ "Diamonds", FIVE });
    firstset.AddElement({ "Diamonds", ACE });
    firstset.AddElement({ "Clubs", JACK });
    firstset.AddElement({ "Hearts", SEVEN });
    firstset.AddElement({ "Spades", QUEEN });

    secondset.AddElement({ "Diamonds", JACK });
    secondset.AddElement({ "Spades", THREE });
    secondset.AddElement({ "Hearts", FIVE });
    secondset.AddElement({ "Diamonds", THREE });
    secondset.AddElement({ "Clubs", JACK });
    secondset.AddElement({ "Hearts", NINE });
    secondset.AddElement({ "Clubs", QUEEN });

    cout << "First set :" << endl;
    firstset.PrintSet();
    cout << "Second set :" << endl;
    secondset.PrintSet();

    cout << "Merge of sets :" << endl;
    (firstset + secondset).PrintSet();
    cout << "Cross of sets :" << endl;
    (firstset - secondset).PrintSet();
    cout << "Intersection of sets :" << endl;
    (firstset / secondset).PrintSet();

    return 0;
}