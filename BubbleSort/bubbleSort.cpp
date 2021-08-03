// bubble sort

#include <iostream>
#include <iterator>
#include <algorithm> // has copy
#include <iomanip> 

using namespace std;

#define	NUMBER_OF_DATASET	10

template<class T>
void bubble(T arrTemp[], int nIdx)
{
	// Bubble largest element in a[0:n-1] to right.
	for (int i = 0; i < nIdx - 1; i++)
	{
		if (arrTemp[i] > arrTemp[i+1])
		{
			swap(arrTemp[i], arrTemp[i + 1]);
		}
	}
}

template<class T>
void bubbleSort(T a[], int n)
{// Sort a[0:n - 1] using bubble sort.
	for (int i = n; i > 1; i--)
		bubble(a, i);
}

template <class T>
void initializeArray(T nArr[], int n)
{
	srand((unsigned) time(NULL));

	for (int i = 0; i < n; i++)
	{
		nArr[i] = rand() % n;
	}
}

int main()
{
	cout << "Bubble sort example: " << endl; 
	cout << "# of dataset: " << NUMBER_OF_DATASET << endl << endl;

	int *a = new int[NUMBER_OF_DATASET + 1];
	initializeArray(a, NUMBER_OF_DATASET);

	// input data
	// for discarding a[0], we use a + 1...
	if (NUMBER_OF_DATASET < 100)
	{
		cout << "Input data:" << endl;
		copy(a, a + NUMBER_OF_DATASET, ostream_iterator<int>(cout, " "));
		cout << endl << endl;
	}

	/*
	Timing in C++ (slide: 9)
	100 ticks
	*/
	double clocksPerMillis = double (CLOCKS_PER_SEC) / 1000;
	clock_t startTime = clock();

	// code to be timed comes here...
	bubbleSort(a, NUMBER_OF_DATASET);

	double elapsedMillis = (clock() - startTime) / clocksPerMillis;

	// output sorted data
	if (NUMBER_OF_DATASET < 100)
	{
		cout << "Output sorted data:" << endl;
		copy(a, a + NUMBER_OF_DATASET, ostream_iterator<int>(cout, " "));
		cout << endl << endl;
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
		bubbleSort(a, NUMBER_OF_DATASET);
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
