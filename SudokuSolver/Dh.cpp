#include "Dh.h"

using namespace std;

/* This function gives the fist var that has the maximum constraints on
	its neighbors. */
Node* getDh(vector<Node*> nodes)
{
	Node* DhNode;
	int max(-1);
	for each (Node* node in nodes)
	{
		int constrainedValue(0);
		set<Node*> neighbors = node->getNeighbors();
		for each (Node* neighbor in neighbors)
		{
			constrainedValue += node->getNbSameVal(neighbor->getValues());
		}
		if (constrainedValue > max) {
			max = constrainedValue;
			DhNode = node;
		}
	}
	return DhNode;
}
