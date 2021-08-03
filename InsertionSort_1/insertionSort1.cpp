// insertion sort example
#include <iostream>
#include <iterator>
#include <algorithm> // has copy

using namespace std;

template<class T>
void insert(T a[], int n, const T& x)
{// Insert x into the sorted array a[0:n-1].
   int i;
   for (i = n-1; i >= 0 && x < a[i]; i--)
      a[i+1] = a[i];
   a[i+1] = x;
}

template<class T>
void insertionSort(T a[], int n)
{// Sort a[0:n-1] using the insertion sort method.
   int i = 1;
   for (; i < n; i++)
   {
	   // to check the interim output
	   cout << "After " << i << "-th sort, a[0:9] = ";
	   copy(a, a+10, ostream_iterator<T>(cout, " "));
	   cout << endl;

	   T t = a[i];
	   insert(a, i, t);
   }

   // to check the interim output
   cout << "After " << i << "-th sort, a[0:9] = ";
   copy(a, a+10, ostream_iterator<T>(cout, " "));
   cout << endl;
}

int main()
{
   int a[10] = {3, 2, 4, 1, 6, 9, 8, 7, 5, 0};

   // output the elements
   cout << "a[0:9] = ";
   copy(a, a+10, ostream_iterator<int>(cout, " "));
   cout << endl;

   // sort
   insertionSort(a,10);

   // output the sorted sequence
   cout << "After the sort, a[0:9] = ";
   copy(a, a+10, ostream_iterator<int>(cout, " "));
   cout << endl;

   // 2nd example
   cout << endl;
   cout << endl;
   double dbl_a[10] = {3.15, 2.14, 4.56, 1.18, 6.35, 9.14, 8.75, 7.51, 5.09, 0.69};

   // output the elements
   cout << "dbl_a[0:9] = ";
   copy(dbl_a, dbl_a+10, ostream_iterator<double>(cout, " "));
   cout << endl;

   // sort
   insertionSort(dbl_a,10);

   // output the sorted sequence
   cout << "After the sort, dbl_a[0:9] = ";
   copy(dbl_a, dbl_a+10, ostream_iterator<double>(cout, " "));
   cout << endl;
   return 0;

}
