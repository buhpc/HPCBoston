#include <iostream>
#include <omp.h>
#include <fstream>
#include <vector>

using namespace std;



int main() {

	// FILE* inFile;
	vector<float> v1;
	string file1 = "test.txt";

	ifstream fin;
	fin.open(file1);

	float num;
	while (fin >> num) {
		v1.push_back(num);
	}

	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << endl;
	}

	

	
	return 0;
}
