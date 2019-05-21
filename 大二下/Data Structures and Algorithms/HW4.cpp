#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#define ul unsigned long
using namespace std;

vector<ul> hash1, hash2, hash1ByLength;
vector<int> v;
string s;
int times;

void hashInit() {
	hash1.clear();
	hash2.clear();
	for (int i = 0; i < int(s.length()); i++) {
		if (i == 0) {
			hash1.push_back(s[i] - 'a');
			hash2.push_back(s[i] - 'a');
		}
		else {
			hash1.push_back((hash1[i - 1] << 5 + (s[i] - 'a')) % (UINT32_MAX));
			hash2.push_back((hash2[i - 1] << 6 + (s[i] - 'a')) % (UINT32_MAX));
		}
	}
}

void hashByLengthInit(int length) {
	hash1ByLength.clear();
	hash1ByLength.push_back(hash1[length - 1]);
	for (int i = length; i < int(s.length()); i++) {
		hash1ByLength.push_back(hash1[i] - ((hash1[i - length] << 5 * length)));
	}
}

inline int subStringHash2(int startPos, int length) {
	return hash2[startPos + length - 1] - startPos == 0 ? 0 : (hash2[startPos - 1] << 6 * length);
}

int p1Check(int length) {
	int counter, currentMaxTimes = 0, rightestPos = -1;
	for (int i = 0; i < int(hash1ByLength.size()); i++) {
		counter = 1;
		for (int j = 0; j < i; j++) {
			if (hash1ByLength[j] == hash1ByLength[i]) {
				if (subStringHash2(i, length) == subStringHash2(j, length))
					counter++;
			}
		}
		if (counter >= currentMaxTimes) {
			currentMaxTimes = counter;
			rightestPos = i;
		}
	}
	return currentMaxTimes >= times ? rightestPos : -1;
}

pair<int, int> p1Search(int minLength, int maxLength) {
	cout << "range:" << minLength << " " << maxLength << "\n";
	if (maxLength == minLength || maxLength - minLength == 1) {
		int pos = p1Check(minLength);
		return pos == -1 ? pair<int, int>(-1, 0) : pair<int, int>(minLength, pos);
	}
	int midLength = (minLength + maxLength) / 2;
	hashByLengthInit(midLength);
	if (p1Check(midLength) == -1)
		return p1Search(minLength, midLength);
	else
		return p1Search(midLength, maxLength);
}

void problemOne() {
	if (int(s.length()) < times) {
		cout << "none\n";
		return;
	}
	else if (int(s.length()) == times) {
		char c = s[0];
		for (int i = 1; i < int(s.length()); i++) {
			if (s[i] - c != 0) {
				cout << "none\n";
				return;
			}
		}
		cout << s.length() << " " << 0 << "\n";
		return;
	}
	else {
		hashInit();
		if (count(s.begin(), s.end(), s[0]) == s.length()) {
			cout << s.length() << " " << 0 << "\n";			
		}
		else {
			pair<int, int>answer = p1Search(1, s.length());
			if (answer.first == -1)
				cout << "none\n";
			else
				cout << answer.first << " " << answer.second << "\n";
		}
	}
}

int p2Search(int left, int right) {
	if (right == left || right - left == 1)
		return left;
	int mid = (left + right) / 2;
	if (s.find(s.substr(0, v[mid]), 1) == s.length() - v[mid]) {
		return p2Search(left, mid);
	}
	else {
		return p2Search(mid, right);
	}
}

void problemTwo() {
	v.clear();
	for (int i = 1; i <= int(s.length()); i++) {
		if (s.substr(0, i) == s.substr(s.length() - i, i)) {
			v.push_back(i);
		}
	}
	if (v.size() == 1) {
		cout << "Just a legend\n";
		return;
	}
	if (s.find(s.substr(0, v[0]), 1) == s.length() - v[0]) {
		cout << "Just a legend\n";
		return;
	}
	int length = v[p2Search(0, v.size() - 1)];
	if (length != int(s.length()) - 1) {
		string answer = s.substr(0, length);
		cout << answer << "\n";
	}
	else
		cout << "Just a legend\n";
}

int main()
{
	cin.tie(0);
	cin >> times;
	while (times != 0) {
		s.clear();
		cin >> s;
		problemOne();
		problemTwo();
		cin >> times;
	}
	return 0;
}