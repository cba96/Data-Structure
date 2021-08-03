// test heap sort

#pragma 

#include <iostream>
#include <algorithm>
#include <iterator>
#include <ctime>

#include "heapSort.h"

using namespace std;

#define	NUMBER_OF_DATASET	10000000
#define MAX_NUMBER_TO_SHOW	50

template <class T>
void initializeArray(T nArr[], int n)
{
	srand((unsigned) time(NULL));

	for (int i = 1; i <= n; i++)
	{
		nArr[i] = rand() % n;
	}
}

int main(void)
{
	cout << "Heap sort example: " << endl;
	cout << "# of dataset: " << NUMBER_OF_DATASET << endl << endl;

	// use an array from a[1] to a[10]
	// int a[NUMBER_OF_DATASET + 1];
	int *a = new int[NUMBER_OF_DATASET + 1];

	// initialize dataset randomly
	initializeArray(a, NUMBER_OF_DATASET);

	// input data
	// for discarding a[0], we use a + 1...
	if (NUMBER_OF_DATASET <= MAX_NUMBER_TO_SHOW)
	{
		cout << "Input data:" << endl;
		copy(a + 1, a + NUMBER_OF_DATASET + 1, ostream_iterator<int>(cout, " "));
		cout << endl << endl;
	}
	else 
	{
		cout << "Input data:" << endl;
		copy(a + 1, a + MAX_NUMBER_TO_SHOW + 1, ostream_iterator<int>(cout, " "));
		cout << "... omitted" << endl << endl;
	}

	/*
	Timing in C++ (slide: 9)
	100 ticks
	*/
	double clocksPerMillis = double (CLOCKS_PER_SEC) / 1000;
	clock_t startTime = clock();

	// code to be timed comes here...
	heapSort(a, NUMBER_OF_DATASET);

	double elapsedMillis = (clock() - startTime) / clocksPerMillis;

	// output sorted data
	if (NUMBER_OF_DATASET < MAX_NUMBER_TO_SHOW)
	{
		cout << "Output sorted data:" << endl;
		copy(a + 1, a + NUMBER_OF_DATASET + 1, ostream_iterator<int>(cout, " "));
		cout << endl << endl;
	}
	else 
	{
		cout << "Output sorted data:" << endl;
		copy(a + 1, a + MAX_NUMBER_TO_SHOW + 1, ostream_iterator<int>(cout, " "));
		cout << "... omitted" << endl << endl;
	}

	cout << "ElapsedMillis ( 100 ticks): " << elapsedMillis << " ms" << endl;

	/*
	The Fix (slide: 16)
	1000 ticks
	*/
	startTime = clock();

	long numberOfRepetitions = 0;
	do 
	{
		numberOfRepetitions++;
		// put code to initialize a[] here...
		initializeArray(a, NUMBER_OF_DATASET);

		// code to be timed comes here...
		heapSort(a, NUMBER_OF_DATASET);
	} while (clock() - startTime < 1000);

	elapsedMillis = (clock() - startTime) / clocksPerMillis;

	// repeat the same routine for 1 sec,
	// and then divide the elapsed time by the number of repetitions
	double timeForCode = elapsedMillis / numberOfRepetitions;
	cout << "ElapsedMillis (1000 ticks): " << timeForCode << " ms"
		<< " (# of Repetitions: " << numberOfRepetitions << ")"
		<< endl;

	delete a;
	return 0;
}
