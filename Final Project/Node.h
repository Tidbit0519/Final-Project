#pragma once
class Node
{
public:
	char c;
	int freq;
	Node* l, * r;
	Node(char, int, Node*, Node*);
	int getFreq();
};