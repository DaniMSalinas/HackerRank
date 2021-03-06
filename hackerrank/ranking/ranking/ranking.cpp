// ranking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	vector<int> scores = { 100, 100, 50, 40, 40, 20, 10 };
	vector<int> alice = { 5, 25, 50, 60, 120 };

	int z = 0, rank = 1, ref = scores[0];

	while (z < scores.size()) {
		rank++;
		if (scores[z] < ref) {
			ref = scores[z];
		}
		else if (scores[z] == ref) {
			rank--;
		}

		cout << "scores -> " << scores[z] << "; aux: " << ref << endl;
		cout << "pos: " << rank << endl;
		z++;
	}

	for (int i = 0; i < alice.size(); i++) {
		int pos = 1;
		int aux = scores[0];
		int j = 0;

		if (alice[i] > aux) {
			pos = 0;
		}
		else {
			while (j < scores.size() && scores[j] >= alice[i]) {
				pos++;
				if (scores[j] < aux) {
					aux = scores[j];
				}
				else if (scores[j] == aux) {
					pos--;
				}
				if (alice[i] == scores[j]) {
					pos--;
				}
				j++;
			}
		}

		cout << "\n";
		cout << "resultado " << alice[i] << "-> posicion: " << pos + 1 << "\n" << endl;
	}

	return 0;
}

