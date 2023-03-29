#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <deque>
#include <vector>
#include "Node.h"

using namespace std;

// Partition
int partition(vector<Node*>& array, int start, int end) {
	Node* x = array[end]; // the pivot
	int i = start - 1; // highest index to the low side
	for (int j = start; j <= end - 1; j++) { // process each element other than pivot
		if (array[j]->getFreq() <= x->getFreq()) { // does this element belong on the low side ?
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

struct compare
{
	bool operator()(Node* l, Node* r)
	{
		// highest priority item has lowest frequency
		if(l->freq < r->freq) 
		{
			return l->freq < r->freq;
		}
		else
		{
			return false;
		}
	}
};

void encode(Node* root, string str,
	unordered_map<char, string>& huffmanCode)
{
	if (root == nullptr)
		return;

	// found a leaf node
	if (!root->l && !root->r) {
		huffmanCode[root->c] = str;
	}

	encode(root->l, str + "0", huffmanCode);
	encode(root->r, str + "1", huffmanCode);
}

int main(int argc, char** argv) {

	// Check for missing argument argc
	if (argc == 1) {
		cout << "You forgot the command line parameter" << endl;
		exit(0);
	}

	// read the file from commandline parameter
	ifstream ifs;
	ifs.open(argv[1], ios::in);

	// check for file not found.
	if (!ifs) {
		cout << "could not find file " << argv[1] << endl;
		exit(0);
	}

	unordered_map<char, int> frequencies;    // Creating a map that key is char and value is int

	char key[1];				   // Create a char array that accepts only one char
	while (ifs.read(key, 1)) {     // Read one char from the file and save it into key
		char value = key[0];
		frequencies[value]++;      // Add the key into the map and +1 into its value
	}
	ifs.close();


	//cout << "number of t's: " << frequencies['t'] << endl;
	for (auto c : frequencies) {
		// print the key and its value out
		cout << "Key: " << c.first << " , value: " << c.second << endl;
	}

	vector <Node* > sortedNodes;

	for (auto f : frequencies)
	{
		Node* node = new Node(f.first, f.second, nullptr, nullptr);
		sortedNodes.push_back(node);
	}

	quickSort(sortedNodes, 0, sortedNodes.size() - 1);
	for (Node* n : sortedNodes) {

	}

	deque<Node*, vector<Node*>> hmTree;

	// Create a leaf node for each character and add it
	// to the priority queue.
	for (auto nodes : sortedNodes) {
		hmTree.push_back(nodes);
	}

	// do till there is more than one node in the queue
	while (hmTree.size() != 1)
	{
		// Remove the two nodes of highest priority
		// (lowest frequency) from the queue
		Node* left = hmTree.front(); hmTree.pop_back();
		cout << "test";
		//Node* right = hmTree.front(); hmTree.pop();

		// Create a new internal node with these two nodes
		// as children and with frequency equal to the sum
		// of the two nodes' frequencies. Add the new node
		// to the priority queue.
		//int sum = left->freq + right->freq;
		//Node* node = new Node('\0', sum, left, right);
		//hmTree.push(node);
	}

}