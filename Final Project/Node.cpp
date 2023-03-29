#include "Node.h"

Node::Node(char ch, int frequency, Node* left, Node* right) {
	c = ch;
	freq = frequency;
	l = left;
	r = right;
}

int Node::getFreq() {
	return freq;
}