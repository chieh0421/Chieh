#include <iostream>
#include <string>
using namespace std;
#define MAXIMUMPOINT = 193;
#define MINIMUMPOINT = -193;
#define ull unsigned long long


int cardToIndex(string card) {
	int suit;
	int number;
	int index = 0;
	switch (card.at(0)) {
	case 'C':
		suit = 0;
		break;
	case 'D':
		suit = 1;
		break;
	case 'H':
		suit = 2;
		break;
	case 'S':
		suit = 3;
		break;
	}
	index += suit * 13;
	if (card.at(1) >= 2 && card.at(1) <= 9) {
		number = card.at(1) - 1;
	}
	else {
		switch (card.at(1)) {
		case 'A':
			number = 0;
			break;
		case 'T':
			number = 9;
			break;
		case 'J':
			number = 10;
			break;
		case 'Q':
			number = 11;
			break;
		case 'K':
			number = 12;
			break;
		}
	}
	index += number;
	return index;
}

int alphabeta(ull state, int alpha, int beta) {
	//state: (Alice's card)*N + (Bob's card)*N + (Alice:1 Bob:0)*1 + (previous card)*6 + (alpha)*6 + (beta)*6
	
}

class Hand {
	int *cards;
	int noOfSuit[4];
	int noOfNumber[13];
	int noOfcards;
public:
	Hand(int N) {
		for (int& i : noOfSuit)
			i = 0;
		for (int& i : noOfNumber)
			i = 0;
		cards = new int(N);
		for (int i = 0; i < N; i++)
			cards[i] = -1;
		noOfcards = 0;
	}
	void get(int card) {
		cards[noOfcards] = card;
		noOfcards++;
		card % 13 == 0 ? noOfNumber[12]++ : noOfNumber[card % 13 - 1]++;
		card / 13 == 0 ? noOfSuit[card / 13 - 1]++ : noOfSuit[card / 13]++;
	}
	void use(int card) {
		for (int i = 0; i < sizeof(cards) / sizeof(int); i++) {
			if (cards[i] == card) {
				cards[i] = -1;
				noOfcards--;
				break;
			}				
		}
		card % 13 == 0 ? noOfNumber[12]-- : noOfNumber[card % 13 - 1]--;
		card / 13 == 0 ? noOfSuit[card / 13 - 1]-- : noOfSuit[card / 13]--;
	}
};

//global variable
int N;
int *AliceCards, *BobCards;

int main()
{
	cin.tie(0);
	cin >> N;
	AliceCards = new int[N];
	BobCards = new int[N];
	string card;
	for (int i = 0; i < N; i++) { //Alice's cards
		cin >> card;
		AliceCards[i] = cardToIndex(card);
	}
	for (int i = 0; i < N; i++) { //Bob's cards
		cin >> card;
		BobCards[i] = cardToIndex(card);
	}
	
	return 0;
}