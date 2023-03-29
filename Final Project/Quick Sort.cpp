#include <vector>
#include "Node.h"

using namespace std;

// Partition
int partition(vector<Node*>&array, int start, int end) {
	Node* x = array[end]; // the pivot
	int i = start - 1; // highest index to the low side
	for (int j = start; j <= end - 1; j++) { // process each element other than pivot
		if (array[j]->getChar() <= x->getChar()) { // does this element belong on the low side ?
				i = i + 1; // index of a new slot in the low side
			swap(array[i], array[j]); // put this element there
		}
	}
	swap(array[i + 1], array[end]); // pivot goes just to the right of the low side
		return i + 1; // new index of the pivot
}
// Quick Sort
void quickSort(vector<Node*>& array, int start, int end) {
	if (start < end) { // Partition the subarray around the pivot, which ends up in array[q];
		int q = partition(array, start, end);
		quickSort(array, start, q - 1); // recursively sort the low side
		quickSort(array, q + 1, end); // recursively sort the high side
	}
}
