// subspaces.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int solveSub(int k, vector<int> S) {

	vector<int> buffer(1);

	for (vector<int>::iterator it1 = S.begin(); it1 < S.end(); ++it1) {
		for (vector<int>::iterator it2 = it1 + 1; it2 < S.end(); ++it2) {
			if ((*it1 + *it2) % k != 0) {
				if (find(begin(buffer), end(buffer), *it1) == end(buffer)) {
					buffer.insert(buffer.end(), *it1);
					cout << *it1 << " " << endl;
				}
				if (find(begin(buffer), end(buffer), *it2) == end(buffer)) {
					buffer.insert(buffer.end(), *it2);
				}
			}
		}
	}

	if (buffer.size() > 1) {
		buffer.erase(buffer.begin());
	}

	return buffer.size();
}

int main()
{
	vector<int> s;
	int k, solution;

	//s = { 422346306, 940894801, 696810740, 862741861, 85835055, 313720373 };
	//s = {1, 4, 2, 7};
	//s = { 1,2,3,4,5,6,7,8,9,10 };
	s = { 770528134, 663501748, 384261537, 800309024, 103668401, 538539662, 385488901, 101262949, 557792122, 460584 };
	//s = { 1 };

	k = 5;

	solution = solveSub(k, s);

	cout << "The subspace size is: " << solution << endl;

	return 0;
}
