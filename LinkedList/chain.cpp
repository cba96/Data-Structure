// 자료구조
// - 프로그램 설명
// - 참고용어
// 단순 연결 리스트 (Singly Linked List)
// 이중 연결 리스트 (Doubly Linked List)
// 이중 원형 연결 리스트 (Doubly Circular Linked List) = 이중 연결 리스트 (Doubly Linked List) + 원형 리스트 (Circular List)

#include <iostream>
#include <ctime>

#include "linearList.h"
#include "chain.h"

#define	MAX_NUMBER	10

using namespace std;

int main()
{
	// Initialization
	linearList<double> *x = new chain<double>;
	chain<int> y, z;

	cout << "Initial size of x, y, and z = "
		<< x->size() << ", "
		<< y.size() << ", "
		<< z.size() << endl;

	cout << endl;
	cout << "===============================================================================" << endl;
	cout << "Check whether the linked list is empty or not,..." << endl;
	cout << "===============================================================================" << endl;
	if (x->empty()) cout << "x is empty" << endl;
	else cout << "x is not empty" << endl;
	if (y.empty()) cout << "y is empty" << endl;
	else cout << "y is not empty" << endl;

	cout << endl;
	cout << "===============================================================================" << endl;
	cout << "Insertion" << endl;
	cout << "===============================================================================" << endl;

	int nInsertedNumber = 0 , nIndex = 0;
	cout << "Inserted 6 integers..." << endl;
	srand((unsigned) time(NULL)); // to use rand() function
	y.insert(nIndex = 0, nInsertedNumber = (rand() % MAX_NUMBER) + 1);
	cout << "Added a new element " << nInsertedNumber << " to index " << nIndex << endl;
	y.insert(nIndex = 1, nInsertedNumber = (rand() % MAX_NUMBER) + 1);
	cout << "Added a new element " << nInsertedNumber << " to index " << nIndex << endl;
	y.insert(nIndex = 0, nInsertedNumber = (rand() % MAX_NUMBER) + 1);
	cout << "Added a new element " << nInsertedNumber << " to index " << nIndex << endl;
	y.insert(nIndex = 2, nInsertedNumber = (rand() % MAX_NUMBER) + 1);
	cout << "Added a new element " << nInsertedNumber << " to index " << nIndex << endl;
	y.insert(nIndex = 3, nInsertedNumber = (rand() % MAX_NUMBER) + 1);
	cout << "Added a new element " << nInsertedNumber << " to index " << nIndex << endl;
	y.insert(nIndex = 2, nInsertedNumber = (rand() % MAX_NUMBER) + 1);
	cout << "Added a new element " << nInsertedNumber << " to index " << nIndex << endl;
	cout << "Done. " << "|y| = " << y.size();
	if (y.empty()) cout << " (y is empty)" << endl;
	else cout << " (y is not empty)" << endl;

	cout << "Members of the linked list: " << y << endl;

	// Try to make an illigalIndexException
	cout << endl << "Try to insert an element with out of index!!!" << endl;
	try 
	{
		y.insert(-3, 0);
	} catch (illegalIndex e)
	{
		cout << "Illegal index exception" << endl;
		cout << "Insert index must be between 0 and list size" << endl;
		cout << "Detail: ";
		e.outputMessage();
	}

	cout << endl;
	cout << "===============================================================================" << endl;
	cout << "Search an element (IndexOf)" << endl;
	cout << "===============================================================================" << endl;
	int index = y.indexOf(4);
	if (index < 0) cout << "4 not found" << endl;
	else cout << "The index of 4 is " << index << endl;

	index = y.indexOf(7);
	if (index < 0) cout << "7 not found" << endl;
	else cout << "The index of 7 is " << index << endl;

	cout << endl;
	cout << "===============================================================================" << endl;
	cout << "Get i-th element" << endl;
	cout << "===============================================================================" << endl;
	cout << "Element with index 0 is " << y.get(0) << endl;
	cout << "Element with index 3 is " << y.get(3) << endl;

	cout << endl;
	cout << "===============================================================================" << endl;
	cout << "Delete an element with index i (Erase)" << endl;
	cout << "===============================================================================" << endl;
	int nDeletedElement = 0;
	nDeletedElement = y.get(1);
	y.erase(1);
	cout << "Element with index 1 (" << nDeletedElement << ") erased" << endl;
	cout << "The list is "  << y << endl;
	cout << "|y| = " << y.size();
	if (y.empty()) cout << " (y is empty)" << endl;
	else cout << " (y is not empty)" << endl;

	cout << endl;
	nDeletedElement = y.get(2);
	y.erase(2);
	cout << "Element 2 (" << nDeletedElement << ") erased" << endl;
	cout << "The list is "  << y << endl;
	cout << "|y| = " << y.size();
	if (y.empty()) cout << " (y is empty)" << endl;
	else cout << " (y is not empty)" << endl;

	cout << endl;
	nDeletedElement = y.get(0);
	y.erase(0);
	cout << "Element 0 (" << nDeletedElement << ") erased" << endl;
	cout << "The list is "  << y << endl;
	cout << "|y| = " << y.size();
	if (y.empty()) cout << " (y is empty)" << endl;
	else cout << " (y is not empty)" << endl;

	cout << endl;
	cout << "===============================================================================" << endl;
	cout << "Copy" << endl;
	cout << "===============================================================================" << endl;

	// Create a new linked list with another linked list,...
	chain<int> w(y);
	
	// delete an 0-th element in the y linked list
	y.erase(0);
	y.erase(0);

	// Check how it works!!!
	cout << "w should be old y, new y has first 2 elements removed" << endl;
	cout << "w is " << w << endl;
	cout << "y is " << y << endl;

	return 0;
}
