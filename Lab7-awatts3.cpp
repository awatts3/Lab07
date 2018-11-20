/*
Andrew Watts
Lab 07
COSC 2030
*/


#include "RandomUtilities.h"
#include "winTimer.h"
#include"Lab7-awatts3.h"
#include "ContainerPrinting.h"
#include <list>
#include <iostream>
#include <vector>
#include <algorithm>
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

vector<int>
getNums(size_t listSize, double minNum, double maxNum)
{
	vector<int> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}
	return theList;
}
ostream& operator<<(ostream& os, const vector<double>& vec) { //this is to let me print a vector, I found it on cplusplus.com
	typedef vector<double>::const_iterator iter_t;
	const iter_t iter_begin = vec.begin();
	const iter_t iter_end = vec.end();
	os << "[";
	for (iter_t iter = iter_begin; iter != iter_end; ++iter) {
		cout << ((iter != iter_begin) ? "," : "") << *iter;
	}
	os << "]";
	return os;
}




int main()
{
	int n = 0;
	while (n != -1) {
		cout << "Enter size for numbers: ";

		cin >> n;
		cout << "Enter seed for rand: ";
		unsigned int seed;
		cin >> seed;
		srand(seed);
		Timer time;

		vector<int> numbers = getNums(n, 1, 500);
		vector<int> numsReset = numbers;



		//cout << numbers << endl<<endl;

		//	time.start();
		//sort(numbers.begin(),numbers.end());
		//time.stop();
		//cout << "std sort completed in " << time() << " seconds" << endl<<endl;
		////cout << numbers << endl<<endl;

		//time.start();
		//bubblesort(numbers);
		//time.stop();
		//cout << "bubble sort completed in " << time() << " seconds" << endl<<endl;
		////cout << numbers << endl<<endl;

		//numbers = numsReset;
		//time.start();
		//insertionSort(numbers);
		//time.stop();
		//cout << "insertion sort completed in " << time() << " seconds" << endl << endl;
		////cout << numbers << endl<<endl;

		
		//numbers = numsReset;
		//time.start();
		//selectionSort(numbers);
		//time.stop();
		//cout << "selection Sort completed in " << time() << " seconds" << endl << endl;
		////cout << numbers << endl << endl;

		numbers = numsReset;
		time.start();
		merge_sort(numbers);
		time.stop();
		cout << "merge Sort completed in " << time() << " seconds" << endl << endl;
		//cout << numbers << endl << endl;

		//numbers = numsReset;
		//time.start();
		//quick_sort(numbers,0,numbers.size()-1);
		//time.stop();
		//cout << "quick Sort completed in " << time() << " seconds" << endl << endl;
		////cout << numbers << endl << endl;
	}
	system("pause");
	return(0);
}