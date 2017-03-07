#include "Mrv.h"

using namespace std;

/* This function gives a vector of vars that have
	excatly the same minimum number of values possible. */
vector<Node*> getMrv(queue<Node*> nodes) {
	int min(11);
	vector<Node*> MrvNodes;
	while (!nodes.empty())
	{
		int nbVal = nodes.front()->getNbValues();
		if ( nbVal <= min && nbVal > 1) {
			if (nbVal < min)
				MrvNodes.clear();
			MrvNodes.push_back(nodes.front());
			min = nbVal;
		}
		nodes.pop();
	}
	return MrvNodes;
}