// Nicholas Cosentino
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
//Name this randomSearch at some point ***DONE***
//put it in a vector ***DONE***
//selection sort ***DONE*** and use a binary search to find the value of 33 ***DONE***
//put its occurence and position for each occurence ***DONE***

//Declaring the vector
vector<int> randomNumbers;

//Prototypes
int binarySearch(vector<int>&, int, int);
void selectionSort(vector<int>&, int);


int main() {
	//Target is the value we specifically want
	int target;
	int size = 0;
	int occurence = 0;
	//Eventually used for moving values into the vector
	int pushbackPlaceholder;

	//Input file information
	ifstream randomInput;
	randomInput.open("C:\\Users\\Nicholas\\Desktop\\RandomNumbers.txt", ios::in);
	//Test for file validity
	if (!randomInput) {
		cout << "File Location not found";
		return 0;
	}

	//Loop for pushing values into an array
	while (!randomInput.eof()) {
		//Not sure if there is a more efficient
		//route to do this task
		randomInput >> pushbackPlaceholder;
		randomNumbers.push_back(pushbackPlaceholder);
		size++;

	}
	cout << "The Unsorted List:\n";
	//Printing out values before sorting
	for (int i = 0; i < size; i++) {
		cout << randomNumbers[i] << '\n';

	}
	cout << "\nThe Sorted List:\n";
	//Printing out values after sorting
	selectionSort(randomNumbers, size);

	for (int i = 0; i < size; i++) {
		cout << randomNumbers[i] << '\n';

	}
	cout << "The size is " << size << '\n';

	//Prompt for desired search value
	cout << "What value would you like to search for: ";
	cin >> target;

	//Finding a position for the desired search value
	int valuePosition = binarySearch(randomNumbers, size, target);

	//Test for if the value occurs
	if (valuePosition == -1) {
		cout << "The value was not found";
	}

	//Finding if there are any values before or after the element
	//we found in the array that matches the target value and moving
	//to its position
	else {

		while (randomNumbers[valuePosition - 1] == target) {
			valuePosition -= 1;
		}
		while (randomNumbers[valuePosition] == target) {
			occurence++;
			cout << "The value " << target << " is in the " << valuePosition << " position \n";
			valuePosition++;
		}
		cout << "It occurs " << occurence << " times\n";



	}

	randomInput.close();

}

//Basic selection sort algorithm
void selectionSort(vector<int>& randomNumbers, int size) {
	int swapPlaceholder;
	int index;
	for (int i = 0; i < size - 1; i++) {
		index = i;
		for (int j = i + 1; j < size; j++) {
			if (randomNumbers[j] < randomNumbers[index]) {
				index = j;
			}
		}
		swapPlaceholder = randomNumbers[index];
		randomNumbers[index] = randomNumbers[i];
		randomNumbers[i] = swapPlaceholder;


	}
}
//Basic binary search algorithm
int binarySearch(vector<int>& randomNumbers, int size, int target) {
	int leftBound = 0;
	int rightBound = size - 1;
	int middle;
	while (leftBound <= rightBound) {
		middle = floor((leftBound + rightBound) / 2);
		if (randomNumbers[middle] < target) {
			leftBound = middle + 1;
		}
		else if (randomNumbers[middle] > target) {
			rightBound = middle - 1;
		}
		else {
			return middle;
		}
	}
	return -1;
}
