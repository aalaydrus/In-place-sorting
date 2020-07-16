#include "InsertionSort.h"

InsertionSort::InsertionSort(int aArrayOfNumbers[], unsigned int aArraySize) : ArraySorter( aArrayOfNumbers, aArraySize)
{}

//sorts the array with the "insertion sort" algorithm
void InsertionSort::sort(std::ostream& aOStream)
{
	int i, j;
	
	//initialised as 1 as we will be taking the element before it in the process
	i = 1;

	//loops through the array
	while (i < getRange())
	{
		j = i;

		//we compare the values within elements prior to i
		while ( (j > 0) && (at( j-1 ) > at(j)) )
		{
			swapElements( j, (j - 1) );
			j--;
		}

		i++;

		stepCompleted(aOStream);
		aOStream << "\n";
	}
}
