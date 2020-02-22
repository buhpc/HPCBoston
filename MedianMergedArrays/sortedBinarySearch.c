#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float avg(float f1, float f2) {
	return ((f1 + f2)/2.0);
}

float min(float f1, float f2) {
	if (f1 <= f2) {
		return f1;
	} else {
		return f2;
	}
}

float max(float f1, float f2) {
	if (f1 >= f2) {
		return f1;
	} else {
		return f2;
	}
}

float findMedian(float* arr1, int count1, float* arr2, int count2) {
	int partitionLesser;
	int partitionGreater;
	
	float* lesserArray;
	float* greaterArray;

	int startLesser = 0;
	int endLesser;

	if (count1 <= count2) {
		lesserArray = arr1;
		greaterArray = arr2;
		endLesser = count1; 
	}
	else {
		lesserArray = arr2;
		greaterArray = arr1;
		endLesser = count2;
	}

	partitionLesser = (startLesser + endLesser)/2;
	partitionGreater = (count1 + count2 + 1)/2 - partitionLesser;

	// printf("partitionLesser: %d partitionGreater: %d\n", partitionLesser, partitionGreater);
	
	int lesserFloat1 = lesserArray[partitionLesser - 1];
	int lesserFloat2 = lesserArray[partitionLesser];

	// printf("greaterArray: \n");
	// for (int i = 0; i < sizeof(greaterArray)/sizeof(greaterArray[0]); i++) {
	// 	printf("index: %d: %d\n", i, greaterArray[i]);
	// }
	int greaterFloat1 = greaterArray[partitionGreater - 1];
	int greaterFloat2 = greaterArray[partitionGreater];

	// printf("start\n");
	// printf("lesser1: %d lesser2: %d greater1: %d greater2: %d\n", lesserFloat1, lesserFloat2, greaterFloat1, greaterFloat2);


	while (lesserFloat1 > greaterFloat2 || greaterFloat1 > lesserFloat2) {
		if (lesserFloat1 > greaterFloat2) {
			endLesser = partitionLesser - 1;
			printf("MOVING LEFT\n");
		} else {
			startLesser = partitionLesser + 1;
			printf("MOVING RIGHT\n");
		}

		partitionLesser = (startLesser + endLesser)/2;
		partitionGreater = (count1 + count2 + 1)/2 - partitionLesser;
		lesserFloat1 = lesserArray[partitionLesser - 1];
		lesserFloat2 = lesserArray[partitionLesser];

		greaterFloat1 = greaterArray[partitionGreater - 1];
		greaterFloat2 = greaterArray[partitionGreater];
	}

	// printf("FOUND\n");
	// printf("\n\n%d %d\n\n", lesserFloat1, lesserFloat2);
	// printf("lesser1: %d lesser2: %d greater1: %d greater2: %d\n", lesserFloat1, lesserFloat2, greaterFloat1, greaterFloat2);
	if ((count1 + count2) % 2 != 0) {
		// printf("\n\n%d %d\n\n", lesserFloat1, lesserFloat2);
		// printf("\n\n1: %d\n\n", max(lesserFloat1, greaterFloat1));
		return max(lesserFloat1, greaterFloat1);
	} else {
		// printf("\n\n2: %f\n\n", avg(max(lesserFloat1, greaterFloat1), min(lesserFloat2, greaterFloat2)));
		return avg(max(lesserFloat1, greaterFloat1), min(lesserFloat2, greaterFloat2));
	}
	return -1;
}

int main() {

	double time_spent = 0.0;
	clock_t begin = clock();

	float num;
	FILE *f1ptr;
	FILE *f2ptr;
	float array1[16];
	float array2[16];

	f1ptr = fopen("testFile1.txt", "r");
	f2ptr = fopen("testFile2.txt", "r");

	int count1 = 0;
	while (fscanf(f1ptr, "%f", &num) != EOF) {
		// printf("%.2f\n", num);
		array1[count1] = num;
		count1++;
	}
	
	int count2 = 0;
	while (fscanf(f2ptr, "%f", &num) != EOF) {
		// printf("%.2f\n", num);
		array2[count2] = num;
		count2++;
	}
	
	printf("DONE: %f\n", findMedian(array1, count1, array2, count2));

	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time elapsed is %f seconds", time_spent);

	return 0;
}
