#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define FILE_A "UnsortedA.txt"
#define FILE_B "UnsortedB.txt"
#define OFILE_A "sortedA.txt"
#define OFILE_B "sortedB.txt"

int comp (const void * elem1, const void * elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int main() {

	clock_t start = clock();

	FILE *firstInput, *secondInput, *firstOutput, *secondOutput;

	firstInput = fopen(FILE_A, "r");
	secondInput = fopen(FILE_B, "r");

	int firstSize = 0;
	int secondSize = 0;
	
	#pragma omp parallel num_threads(2)
	for(FILE *i = firstInput;i!=secondInput;i=secondInput)
	{
		int size=0;
		for(char c = getc(i); c != EOF; c = getc(i)){
			if(c == '\n'){
				size++;
			}
		}
		if(i == firstInput)
			firstSize = size;
		else
			secondSize = size;
	}

//	for(char c = getc(firstInput); c != EOF; c = getc(firstInput)){
//		if(c == '\n'){
//			firstSize++;
//		}
//	}
//	for(char c = getc(secondInput);c != EOF; c = getc(secondInput)){
//		if(c == '\n'){
//			secondSize++;
//		}
//	}

	fseek(firstInput,0,SEEK_SET);
	fseek(secondInput,0,SEEK_SET);

	float firstArray[firstSize];
	int firstIndex = 0;
	float secondArray[secondSize];
	int secondIndex = 0;

	float firstTemp;
	float secondTemp;

	while(fscanf(firstInput, "%f", &firstTemp) != EOF){
		firstArray[firstIndex] = firstTemp;
		firstIndex++;
	}
	while(fscanf(secondInput, "%f", &secondTemp) != EOF){
		secondArray[secondIndex] = secondTemp;
		secondIndex++;
	}

	fclose(firstInput);
	fclose(secondInput);

	qsort(firstArray, firstSize, sizeof(firstArray[0]), comp);
	qsort(secondArray, secondSize, sizeof(secondArray[0]), comp);

	firstOutput = fopen(OFILE_A, "w");
	secondOutput = fopen(OFILE_B, "w");


	for(int i = 0; i < sizeof(firstArray)/sizeof(firstArray[0]); i++){
		fprintf(firstOutput, "%f\n", firstArray[i]);
	}
	for(int i = 0; i < sizeof(secondArray)/sizeof(secondArray[0]); i++){
		fprintf(secondOutput, "%f\n", secondArray[i]);
	}

	fclose(firstOutput);
	fclose(secondOutput);

	clock_t end = clock();
	
	printf("time taken is %f seconds.\n",(double)(end-start)/CLOCKS_PER_SEC);

	return 0;
}

