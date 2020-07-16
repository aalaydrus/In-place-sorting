#include "SelectionSort.h"

SelectionSort::SelectionSort(int aArrayOfNumbers[], unsigned int aArraySize) : ArraySorter( aArrayOfNumbers, aArraySize )
{}

//sorts the array with the "selection sort" algorithm
void SelectionSort::sort(std::ostream& aOStream)
{
	//variable to store the minimum element
	int min;

	for (int i = 0; i < ( getRange() - 1 ); i++)
	{
		//sets first value to be minimun as it is has not been sorted
		min = i;

		//we compare the values within elements after i
		for (int j = (i + 1); j < ( getRange() ); j++)
		{
			//if value is lower than min, the current index is recorded to store the new minimun
			if (at(j) < at(min))
			{
				min = j;
			}
		}

		//swaps the value in i with min, once the selection finishes
		if ( at(min) != at(i) )
		{
			swapElements(i, min);
		}

		//outputs the current iteration
		stepCompleted(aOStream);
		aOStream << "\n";
	}
}
