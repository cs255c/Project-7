/* IntegerSet definition file
 * Implements printing the elements present in a set, adding elements to and
 * deleting elements from a set, taking the union, intersection, complement, and difference of sets,
 * and testing if sets are equal, subsets, or empty.
 * 3/25/2015
 * Alex Debrecht */

#ifndef INTEGERSET_H_
#define INTEGERSET_H_

using namespace std;

class IntegerSet {

	// The integer array is private
	int set[101];

public:
	// Constructors + destructors
	IntegerSet(); // Constructs empty set
	IntegerSet(int[]);
	~IntegerSet();

	// Methods
	IntegerSet unionOfSets(IntegerSet);
	IntegerSet intersectionOfSets(IntegerSet);
	IntegerSet complement(); // Absolute complement
	IntegerSet difference(IntegerSet);
	void insertElement(int);
	void deleteElement(int);
	void printSet(); // Prints set in the form {....}
	bool isEqualTo(IntegerSet);
	bool isEmpty();
	bool subset(IntegerSet);

};

#endif /* INTEGERSET_H_ */
