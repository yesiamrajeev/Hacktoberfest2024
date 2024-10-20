#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int NUM_SUITS = 4;
const int NUM_RANKS = 13;

struct Card {
    int suit;
    int rank;
};

struct Pile {
    vector<Card> cards;
};

bool is_valid_move(const Card& top_card, const Card& bottom_card) {
    return top_card.suit == bottom_card.suit && top_card.rank == bottom_card.rank - 1;
}

bool is_face_up(const Card& card) {
    return card.rank != -1;
}

void move_cards(Pile& source, Pile& destination) {
    while (!source.cards.empty() && is_face_up(source.cards.back()) && is_valid_move(source.cards.back(), destination.cards.empty() ? Card{-1, -1} : destination.cards.back())) {
        destination.cards.push_back(source.cards.back());
        source.cards.pop_back();
    }
}

void print_game(const vector<Pile>& tableau, const vector<Pile>& foundations) {
    for (int i = 0; i < tableau.size(); ++i) {
        cout << "Pile " << i + 1 << ": ";
        for (const Card& card : tableau[i]) {
            cout << card.rank << " of " << card.suit << " ";
        }
        cout << endl;
    }

    cout << "Foundations: ";
    for (const Pile& foundation : foundations) {
        if (!foundation.cards.empty()) {
            cout << foundation.cards.back().rank << " of " << foundation.cards.back().suit << " ";
        } else {
            cout << "Empty ";
        }
    }
    cout << endl;
}

bool is_game_won(const vector<Pile>& foundations) {
    for (const Pile& foundation : foundations) {
        if (foundation.cards.size() != NUM_RANKS) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<Pile> tableau(7);
    vector<Pile> foundations(NUM_SUITS);

    // Initialize the game
    for (int i = 0; i < tableau.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            Card card = {j % NUM_SUITS, NUM_RANKS - i + j};
            if (j == i) {
                card.rank = -1; // Face-down card
            }
            tableau[i].push_back(card);
        }
    }

    while (true) {
        print_game(tableau, foundations);

        int source_pile, destination_pile;
        cout << "Enter source pile and destination pile: ";
        cin >> source_pile >> destination_pile;

        if (source_pile < 1 || source_pile > tableau.size() || destination_pile < 1 || destination_pile > tableau.size() + foundations.size()) {
            cout << "Invalid pile numbers." << endl;
            continue;
        }

        if (destination_pile <= tableau.size()) {
            move_cards(tableau[source_pile - 1], tableau[destination_pile - 1]);
        } else {
            move_cards(tableau[source_pile - 1], foundations[destination_pile - tableau.size() - 1]);
        }

        if (is_game_won(foundations)) {
            cout << "Congratulations! You won the game." << endl;
            break;
        }
    }

    return 0;
}
