#include <iostream>
#include <string>
using namespace std;
#define MAXIMUMPOINT 193;
#define MINIMUMPOINT -193;
#define ull unsigned long long

//global variable
int N;
int *AliceCards, *BobCards;

long boolArrToLong(bool* arr) {
	long result = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(bool); i++) {
		result += arr[i] << (N - i);
	}
	return result;
}

bool* boolArrCopy(bool* arr) {
	int length = sizeof(arr) / sizeof(bool);
	bool* result = new bool[length];
	for (int i = 0; i < length; i++) {
		result[i] = arr[i];
	}
	return result;
}

int point(bool*arr, int*cards) {
	int result = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i])
			result += cards[i] % 13 == 0 ? 13 : cards[i] % 13;
	}
	return result;
}

int cardToIndex(string card) {
	int suit = -1;
	int number = -1;
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
	if (card.at(1) >= '2' && card.at(1) <= '9') {
		number = card.at(1) - '1';
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

int alphabeta(bool* alice, bool* bob, bool player, int previousCard, int alpha, int beta) {
	if ((boolArrToLong(alice) | 0) == 0) {
		return point(bob, BobCards);
	}
	else if ((boolArrToLong(bob) | 0) == 0) {
		return point(alice, AliceCards);
	}
	int value;
	if (player) { //player: Alice -> max
		value = MINIMUMPOINT;
		for (int i = 0; i < N; i++) {
			bool haveCardToUse = false;
			if (alice[i] && ((AliceCards[i] % 13 == previousCard % 13 || AliceCards[i] / 13 == previousCard / 13) || previousCard == -1)) {
				if (!haveCardToUse)
					haveCardToUse = true;
				bool* parameterAlice = boolArrCopy(alice);
				parameterAlice[i] = false;
				value = alphabeta(parameterAlice, bob, !player, AliceCards[i], value, beta);
				if (alpha > value ? alpha : value >= beta)
					break;
			}
			if (haveCardToUse)
				return value;
			else
				return alphabeta(alice, bob, !player, -1, alpha, beta);
		}
		return value;
	}
	else { //player: Bob -> min
		value = MAXIMUMPOINT;
		for (int i = 0; i < N; i++) {
			bool haveCardToUse = false;
			if (bob[i] && ((BobCards[i] % 13 == previousCard % 13 || BobCards[i] / 13 == previousCard / 13) || previousCard == -1)) {
				if (!haveCardToUse)
					haveCardToUse = true;
				bool* parameterBob = boolArrCopy(bob);
				parameterBob[i] = false;
				value = alphabeta(alice, parameterBob, !player, BobCards[i], alpha, value);
				if (beta > value ? value : beta >= alpha)
					break;
			}
			if (haveCardToUse)
				return value;
			else
				return alphabeta(alice, bob, !player, -1, alpha, beta);
		}
		return value;
	}
}

ull stateGenerateFunction(bool* alice, bool* bob, bool player, int previousCard, int alpha, int beta) {
	//state: (Alice's card)*N + (Bob's card)*N + (Alice:1 Bob:0)*1 + (previous card)*6 + (alpha)*9 + (beta)*9
	ull state = 0;
	state += boolArrToLong(alice) << (25 + N);
	state += boolArrToLong(bob) << 25;
	if (player)
		state += 1 << 24;
	state += previousCard << 18;
	state += alpha << 9;
	state += beta;
	return state;
}

int main()
{
	cin.tie(0);
	cin >> N;
	AliceCards = new int[N];
	Alice = new bool[N];
	BobCards = new int[N];
	Bob = new bool[N];
	string card;
	for (int i = 0; i < N; i++) { //Alice's cards
		cin >> card;
		AliceCards[i] = cardToIndex(card);
		Alice[i] = true;
	}
	for (int i = 0; i < N; i++) { //Bob's cards
		cin >> card;
		BobCards[i] = cardToIndex(card);
		Bob[i] = true;
	}
	cout << alphabeta(Alice, Bob, true, -1, 193, 193);
	return 0;
}