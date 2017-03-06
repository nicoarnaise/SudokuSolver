#include "Mrv.h"

using namespace std;

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