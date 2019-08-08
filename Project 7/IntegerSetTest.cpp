/* Test IntegerSet class
 * 3/25/2015
 * Alex Debrecht */

#include <iostream>
#include "IntegerSet.h"
using namespace std;

// function main begins program execution
int main() {

	cout << boolalpha; // Set boolalpha to print 'true' and 'false'

	bool ans = true;
	char ansChar;

	while (ans) {
		// Create set to pass to constructor
		int newSet[101];
		int newSet2[101];
		for (int i = 0; i < 101; ++i) {
			newSet[i] = false;
			newSet2[i] = false;
		}

		int lastInt = 0;
		int lastInt2 = 0;
		cout << "Enter the first set (0-100). When finished, enter a number greater than 100." << endl;
		while (lastInt < 101) {
			cin >> lastInt;
			newSet[lastInt] = true;
		}
		cout << "Enter the second set (0-100). When finished, enter a number greater than 100." << endl;
		while (lastInt2 < 101) {
			cin >> lastInt2;
			newSet2[lastInt2] = true;
		}

		// Declare 5 sets and initialize set4
		IntegerSet set1 = IntegerSet(newSet);
		IntegerSet set2 = IntegerSet(newSet2);

		cout << "Set 1: ";
		set1.printSet();
		cout << endl << "Set 2: ";
		set2.printSet();
		cout << endl;

		// Check insert method
		cout << "Enter an integer to add to set 1." << endl;
		int add;
		cin >> add;
		set1.insertElement(add);
		set1.printSet();
		set1.deleteElement(add);
		cout << "New integer removed." << endl << endl;

		// Check delete method
		cout << "Enter an integer to delete from set 1." << endl;
		int remove;
		cin >> remove;
		set1.deleteElement(remove);
		set1.printSet();
		set1.insertElement(remove);
		cout << "Integer restored." << endl << endl;

		// Check union method
		cout << "Set 1 ∪ Set 2 : ";
		set1.unionOfSets(set2).printSet();

		// Check intersection method
		cout << "Set 1 ∩ Set 2: ";
		set1.intersectionOfSets(set2).printSet();

		// Set difference
		cout << "Set 1 - Set 2: ";
		set1.difference(set2).printSet();

		// Absolute complement
		cout << "~Set 1: ";
		set1.complement().printSet();

		// Check equality
		cout << "Set 1 == Set 2: " << set2.isEqualTo(set1) << endl;

		// Check for empty set
		cout << "Is Set 1 empty? " << set1.isEmpty() << endl;
		cout << "Is Set 2 empty? " << set2.isEmpty() << endl;

		// Check subsets
		cout << "Is Set 1 a subset of Set 2? " << set1.subset(set2) << endl;
		cout << "Is Set 2 a subset of Set 1? " << set2.subset(set1) << endl;

		// Ask user if they would like to loop again
		cout << "Would you like to test more sets?" << endl;
		cin >> ansChar;

		// Set boolean based on answer
		if (ansChar == 'n' || ansChar == 'N') ans = false;

	}
}
