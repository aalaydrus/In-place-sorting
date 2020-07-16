
#include "ArraySorter.h"

using namespace std;

ArraySorter::ArraySorter( const int aArrayOfNumbers[], unsigned int aArraySize )
{
    // copy array into sorter
    fArrayOfNumbers = new int[aArraySize];

    for ( unsigned int i = 0; i < aArraySize; i++ )
    {
        fArrayOfNumbers[i] = aArrayOfNumbers[i];
    }
    
    fArraySize = aArraySize;
}

ArraySorter::~ArraySorter()
{
    // delete memory associated with array
    delete [] fArrayOfNumbers;
}

//called at the end of the sorting algorithm to show array state
void ArraySorter::stepCompleted(std::ostream& aOStream)
{
	aOStream << "State: [";

	// prints out every element of the array
	for (int i = 0; i < fArraySize; i++)
	{
		aOStream << fArrayOfNumbers[i];
		if (i < (fArraySize - 1))
		{
			aOStream << ", ";
		}
	};

	aOStream << "]";
}

//exchanges the underlying array elements specified
void ArraySorter::swapElements(unsigned int aSourcIndex, unsigned int aTargetIndex)
{
	//uses "at" method to ensure indices are within bounds
	unsigned int lTemporary = at(aTargetIndex);

	fArrayOfNumbers[aTargetIndex] = at(aSourcIndex);

	fArrayOfNumbers[aSourcIndex] = lTemporary;
}

//processes the index into a range check for validity before returning the value from index
const unsigned int ArraySorter::at(unsigned int aIndex) const
{
	if (aIndex > fArraySize)
	{
		throw range_error("Invalid as index is out of range");
	}
	return fArrayOfNumbers[aIndex];
}

//returns the range of the array
const unsigned int ArraySorter::getRange() const
{
	return fArraySize;
}

//invokes stepCompleted by default. Expected to be called from overriden method(s)
void ArraySorter::sort(std::ostream& aOStream)
{
	stepCompleted(aOStream);
}

//outputs textual representation of the underlying array without emitting newlines at the end
std::ostream& operator<<(std::ostream& aOStream, const ArraySorter& aObject)
{
	aOStream << "[";

	// loops through the underlying array and prints out each element
	for (int i = 0; i < aObject.getRange(); i++)
	{
		aOStream << aObject.at(i);
		if (i < (aObject.getRange() - 1))
		{
			aOStream << ", ";
		}
	};

	aOStream << "]";

	return aOStream;
}