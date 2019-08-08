/* IntegerSet implementation file
 * Implements printing the elements present in a set, adding elements to and
 * deleting elements from a set, taking the union, intersection, complement, and difference of sets,
 * and testing if sets are equal, subsets, or empty.
 * 3/25/2015
 * Alex Debrecht */

#include "IntegerSet.h"
#include <iostream>
using namespace std;

// Construct empty set
IntegerSet::IntegerSet() {
	for (unsigned int i = 0; i < 101; ++i) {
		set[i] = false;
	}
}

// Construct set by swapping and resizing provided set
IntegerSet::IntegerSet(int inputSet[]) {
	for (unsigned int i = 0; i < 101; ++i) {
		set[i] = inputSet[i];
	}
}

// Default destructor
IntegerSet::~IntegerSet() {

}

// Print all members of the set
void IntegerSet::printSet() {
	bool check = false; // So comma isn't printed for first number

	cout << "{";
	for (unsigned int i = 0; i < 101; ++i) {
		if (set[i] && check) {
			cout << "," << i;
		} else if (set[i]) {
			cout << i;
			check = true;
		}
	}
	cout << "}" << endl;
}

// Set requested element of set to true
void IntegerSet::insertElement(int addToSet) {
	set[addToSet] = true;
}

// Set requested element of set to false
void IntegerSet::deleteElement(int removeFromSet) {
	set[removeFromSet] = false;
}

// Checks if element is present in one or both provided sets, adds element to set if true
IntegerSet IntegerSet::unionOfSets(IntegerSet set1) {
	int temp[101];

	for (unsigned int i = 0; i < 101; ++i) {
		temp[i] = set1.set[i] | set[i]; // If either is true, add to new set
	}

	IntegerSet thisSet = IntegerSet(temp);
	return thisSet;
}

// Checks if element is present in both provided sets, adds element to set if true
IntegerSet IntegerSet::intersectionOfSets(IntegerSet set1) {
	int temp[101];

	for (unsigned int i = 0; i < 101; ++i) {
		temp[i] = set1.set[i] & set[i]; // Add to new set only if both are true
	}

	IntegerSet thisSet = IntegerSet(temp);
	return thisSet;
}

// Tests whether set is equal to provided set
bool IntegerSet::isEqualTo(IntegerSet otherSet) {
	for (unsigned int i = 0; i < 101; ++i) {
		if (set[i] == otherSet.set[i]) {
			// Just keep going if elements are equal
		} else {
			return false; // If there is an element that is not the same, return false and stop checking
		}
	}
	return true; // If entire sets are the same, return true
}

// Take full complement of set
IntegerSet IntegerSet::complement() {

	int temp[101];

	for (unsigned int i = 0; i < 101; ++i) {
		temp[i] = !set[i]; // Add if not in original set
	}

	IntegerSet thisSet = IntegerSet(temp);
	return thisSet;

}

// Take difference of sets
IntegerSet IntegerSet::difference(IntegerSet set1) {

	IntegerSet thisSet = intersectionOfSets(set1);
	thisSet = thisSet.complement();
	thisSet = intersectionOfSets(thisSet);
	return thisSet;

}

// Tests whether set is a subset of provided set
bool IntegerSet::subset(IntegerSet otherSet) {

	return (intersectionOfSets(otherSet).isEqualTo(*this)); // If the intersection of set with otherSet is equal to set, set is a subset of otherSet

}

// Tests whether set is a subset of provided set
bool IntegerSet::isEmpty() {

	for (unsigned int i = 0; i < 101; ++i) {
		if (set[i]) {
			return false;
		}
	}
	return true; // If nothing in set is true, set is empty
}
