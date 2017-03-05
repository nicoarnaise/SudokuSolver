#include "Dh.h"

using namespace std;

Node* getDh(vector<Node*> nodes)
{
	Node* DhNode = nullptr;
	int max(-1);
	for each (Node* node in nodes)
	{
		int constrainedValue(0);
		set<Node*> neighbors = node->getNeighbors();
		for each (Node* neighbor in neighbors)
		{
			constrainedValue += 9 - neighbor->getNbValues();
		}
		if (constrainedValue > max) {
			max = constrainedValue;
			DhNode = node;
		}
	}
	if (DhNode == nullptr)
	{
		bool tre = true;
	}
	return DhNode;
}
