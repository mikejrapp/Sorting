#include<iostream>
#include<string>
#include<fstream>
#include<array>

using namespace std;

void insertionSort(int pArray[], int ARRAY_SIZE);
void quickSort(int pArray[], int left, int right);

int main() {
	int unsortedArray[6] = { 5,3,1,2,10,12 };
	const int ARRAY_SIZE = sizeof(unsortedArray) / sizeof(unsortedArray[0]);
	cout << "pre-sort: " << endl;

	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << unsortedArray[i] << " ";
	}

	//insertionSort(unsortedArray,ARRAY_SIZE);
	quickSort(unsortedArray, 0, ARRAY_SIZE - 1);
	cout << "\npost-sort: " << endl;

	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << unsortedArray[i] << " ";
	}


	cin.get();
	return 0;
}

void insertionSort(int pArray[], int ARRAY_SIZE) {
	int index;
	int lowestValue;

	for (int i = 1; i < ARRAY_SIZE; i++) {
		lowestValue = pArray[i];
		index = i;

		while (index > 0 && pArray[index - 1] > lowestValue) {//not at start of array and left position has greater value
			pArray[index] = pArray[index - 1];//shift value from left to right
			index--;// decrement index
		}//end while

		pArray[index] = lowestValue;//insert lowest value in proper place
	}//end for
}

void quickSort(int pArray[], int left, int right) {
	int i = left;
	int j = right;
	int pivot = pArray[(left + right) / 2];
	int temp;

	while (i <= j) {
		while (pArray[i] < pivot) {
			i++;
		}
		while (pArray[j] > pivot) {
			j--;
		}
		if (i <= j) {
			temp = pArray[i];
			pArray[i] = pArray[j];
			pArray[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j) {
		quickSort(pArray, left, j);
	}
	if (i < right) {
		quickSort(pArray, i, right);
	}
}