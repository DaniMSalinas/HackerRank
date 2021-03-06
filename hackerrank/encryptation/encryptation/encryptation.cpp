// encryptation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

void encryption(string _s) {

	int row, column, z = 0, a = 0, j = 0;
	int aux;
	string salida;

	cout << "string size: " << _s.size() << endl;
	cout << "sqrt(size): " << sqrt(_s.size()) << endl;
	row = round(sqrt(_s.size()));
	aux = sqrt(_s.size());
	cout << "rows number: " << row << endl;

	if (aux == row) {
		column = row + 1;
	}
	else {
		column = row;
	}

	cout << "columns number: " << column << endl;

	vector<vector<int>> m(row, vector<int>(column));

	for (int i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			if (z < _s.size()) {
				m[i][j] = _s[z];
				z++;
			}
		}
	}

	cout << endl;

	for (int y = 0; y < column; y++) {
		for (int x = 0; x < row; x++) {
			salida.insert(salida.begin() + a, m[x][y]);
			if (salida[a] == 0) {
				salida.erase(salida.begin() + a);
			}
			else {
				printf("%c", salida[a]);
				a++;
			}
		}
		salida.insert(salida.begin() + a, ' ');
		printf("%c", salida[a]);
		a++;
	}
}

int main() {
	string input;

	cout << "Write the sentence: ";
	cin >> input;

	encryption(input);

	return 0;
}

