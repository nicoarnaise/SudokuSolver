#include "Mrv.h"

using namespace std;

vector<Node*> getMrv(queue<Node*> nodes) {
	int min(INFINITY);
	vector<Node*> MrvNodes;
	while (nodes.size()>0)
	{
		int nbVal = nodes.front()->getNbValues();
		if ( nbVal <= min) {
			if (nbVal < min)
				MrvNodes.clear();
			MrvNodes.emplace(nodes.front);
			min = nbVal;
		}
		nodes.pop();
	}
	return MrvNodes;
}