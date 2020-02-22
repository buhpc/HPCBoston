#include "cnpy.h"
#include <math.h>
#include <iostream>
#include <string>
#include <vector>

int main(char* argv[]){

	printf("test\n");

	std::string str="sdf";

	cnpy::npz_t dataSet = cnpy::npz_load("recipes.npz");

	cnpy::NpyArray recipesArray = dataSet["recipes"];

	std::vector<std::string> recipesStrArray = dataSet.data<std::string>();

	for(int i=0; i<10; i++){
		fprintf("%s", recipesArray.[i] );
	}

}