#pragma once
#include <time.h>

// This the version of quicksort that actually performs partitioning, recursive calls, etc. 
template<typename T>
void quicksort(T* ar, int start, int end)
{

	if (start == end) return;  // Base case: No sorting necessary 

	// select pivot index and position pivot;
	//partition ar[start; end];
	int three[3];
	for (int i = 0; i < 3; i++)
	{
		three[i] = rand() % (end - start);
		three[i] += start;
	}
	// Check for median of three
	int pivot = three[0] > three[1] ? three[0] : three[1];
	pivot = pivot < three[2] ? pivot : three[2];
	//Swap Pivot to end index
	T temp = ar[end];
	ar[end] = ar[pivot];
	ar[pivot] = temp;
	//pivot = end;
	//Setting wall and i
	int wall = start;
	int i = start + 1;

	while (i != pivot)
	{
		if (ar[pivot] > ar[wall])
		{
			if (ar[pivot] > ar[i])
			{
				wall++;
			}
			else
			{
				i++;
			}
		}
		else
		{
			if (ar[pivot] > ar[i])
			{
				T temp = ar[i];
				ar[i] = ar[wall];
				ar[wall] = temp;
			}
			else
			{
				i++;
			}
		}
	}
	T temp = ar[wall + 1];
	ar[wall + 1] = ar[pivot];
	ar[pivot] = temp;
	// Assume: Pivot is at index k after partitioning
	quicksort(ar, start, pivot - 1);
	quicksort(ar, pivot + 1, end);
}


// This is the version of quicksort that the user sees. 
// Performs preprocessing, then calls the actual quicksort 
template<typename T>
void quicksort(T* ar, int n)
{
	// Preprocess ar (if required)
	if (n < 2) {
		return;
	}
	if (n == 2)
	{
		if (ar[0] > ar[1])
		{
			T temp = ar[1];
			ar[1] = ar[0];
			ar[0] = temp;
		}
		return;
	}

	// Call Quicksort
	quicksort(ar, 0, n - 1);
}
