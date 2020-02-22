#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	vector<float> v1, v2;

	string file1 = "median-first-array.txt";
	string file2 = "median-second-array.txt";

	ifstream fin;
	fin.open("median-first-array.txt");

	float num;
	while (fin >> num) {
		v1.push_back(num);
	}

	cout << "Done reading in first file" << endl;

	fin.close();
	fin.open("median-second-array.txt");

	while(fin >> num) {
		v2.push_back(num);
	}

	cout << "Done reading in second file" << endl;

	cout << "Printing v1 unsorted: " << endl;
	for (auto value : v1) {
		cout << fixed << setprecision(2) << value << endl;
	}

	cout << "Printing v2 unsorted: " << endl;
	for (auto value : v2) {
		cout << fixed << setprecision(2) << value << endl;
	}

	stable_sort(v1.begin(), v1.end());
	cout << "Printing v1 sorted: " << endl;
	for (auto value : v1) {
		cout << fixed << setprecision(2) << value << endl;
	}

	stable_sort(v2.begin(), v2.end());
	cout << "Printing v2 sorted: " << endl;
	for (auto value : v2) {
		cout << fixed << setprecision(2) << value << endl;
	}

	vector<float> mergedVector(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), mergedVector.begin());

	cout << "Printing merged vector: " << endl;
	for (auto value : mergedVector) {
		cout << fixed << setprecision(2) << value << endl;
	}

	// Find median
	int len = mergedVector.size();
	float median;
	if (len % 2 == 0) {
		median = (mergedVector[len/2] + mergedVector[(len/2) + 1]) / 2.0;
		cout << "HERE" << endl;
	} else {
		median = mergedVector[(len/2) + 1];
	}

	cout << "Size of v1: " << v1.size() << endl;
	cout << "Size of v2: " << v2.size() << endl;
	cout << "Size of merged vector: " << mergedVector.size() << endl;
	cout << "Median: " << median << endl;

	return 0;
}
