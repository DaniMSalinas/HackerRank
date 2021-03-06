// containersBall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

string organizingContainer(vector<vector<int>> container) {
	
	unsigned int size = container.size();
	int a = 0;	
	unsigned int row[100], column[100];

	
	for (int i = 0; i < container.size(); i++) {
		for (int j = 0; j < container.size(); j++) {
			row[i] += container[i][j];
			column[j] += container[i][j];
		}
	}

	for (int i = 0; i < container.size(); i++) {
		if (find(begin(row), end(row), column[i]) != end(row)) {
			a++;
		}
	}

	if (a == container.size()) {
		return "Possible";
	}
	else {
		return "Impossible";
	}

}

int main()
{
	ifstream in_file("matrix.txt");
	int size, n;

	if (in_file.is_open()) {
		in_file >> n;
		
		for (int z = 0; z < n; z++) {
			in_file >> size;
			vector<vector<int>> container(size);
			for (int i = 0; i < size; i++) {
				container[i].resize(size);
				for (int j = 0; j < size; j++) {
					in_file >> container[i][j];
				}
			}
			string solution = organizingContainer(container);
			cout << solution << endl;
		}

		in_file.close();

	}
	else {
		cout << "Unable to open \n\n";
	}

    return 0;
}

