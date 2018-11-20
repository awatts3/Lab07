#ifndef AWATTS3
#define AWATTS3

#include<iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;


void bubblesort (vector<int> &vect) {
	bool done = false;
	int temp;
	for (int i = 1; i <= vect.size()&&!done; i++) {
		done = true;
		for (int j = 0; j < (vect.size() - 1); j++)
		{
			if (vect[j + 1] < vect[j])      
			{
				temp = vect[j];            
				vect[j] = vect[j + 1];
				vect[j + 1] = temp;
				done = false;               
			}
		}


	}
	return;
}

void insertionSort(vector<int> &vect)
{
	int i, key, j;
	for (i = 1; i < vect.size(); i++)
	{
		key = vect[i];
		j = i - 1;

		while (j >= 0 && vect[j] > key)
		{
			vect[j + 1] = vect[j];
			j = j - 1;
		}
		vect[j + 1] = key;
	}
}

void selectionSort(vector<int> &vect)
{
	int i, j, min_idx;


	for (i = 0; i < vect.size() - 1; i++)
	{
	
		min_idx = i;
		for (j = i + 1; j < vect.size(); j++)
			if (vect[j] < vect[min_idx])
				min_idx = j;

		int temp = vect[min_idx];
		vect[min_idx] = vect[i];
		vect[i] = temp;
	
	}
}

template <typename T>
void merge(vector<T>& array, vector<T>& array1, vector<T>& array2) {
	array.clear();

	int i, j, k;
	for (i = 0, j = 0, k = 0; i < array1.size() && j < array2.size(); k++) {
		if (array1.at(i) <= array2.at(j)) {
			array.push_back(array1.at(i));
			i++;
		}
		else if (array1.at(i) > array2.at(j)) {
			array.push_back(array2.at(j));
			j++;
		}
		k++;
	}

	while (i < array1.size()) {
		array.push_back(array1.at(i));
		i++;
	}

	while (j < array2.size()) {
		array.push_back(array2.at(j));
		j++;
	}
}

template <typename T>
void merge_sort(std::vector<T>& array) {
	if (1 < array.size()) {
		std::vector<T> array1(array.begin(), array.begin() + array.size() / 2);
		merge_sort(array1);
		std::vector<T> array2(array.begin() + array.size() / 2, array.end());
		merge_sort(array2);
		merge(array, array1, array2);
	}
}



void quick_sort(vector<int> &vec, int L, int R) {
	int i, j, mid, piv;
	i = L;
	j = R;
	mid = L + (R - L) / 2;
	piv = vec[mid];

	while (i<R || j>L) {
		while (vec[i] < piv)
			i++;
		while (vec[j] > piv)
			j--;

		if (i <= j) {
			
			int temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
			i++;
			j--;
		}
		else {
			if (i < R)
				quick_sort(vec, i, R);
			if (j > L)
				quick_sort(vec, L, j);
			return;
		}
	}
}


#endif // !AWATTS3
