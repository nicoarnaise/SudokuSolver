#include "Mrv.h"

using namespace std;

vector<Node*> getMrv(queue<Node*> nodes) {
	int min(INFINITY);
	queue<Node*> poeut = nodes;
	vector<Node*> MrvNodes;
	while (!nodes.empty())
	{
		int nbVal = nodes.front()->getNbValues();
		if ( nbVal <= min) {
			if (nbVal < min)
				MrvNodes.clear();
			MrvNodes.push_back(nodes.front());
			min = nbVal;
		}
		nodes.pop();
	}
	if (MrvNodes.empty()) {
		bool tre = true;
	}
	return MrvNodes;
}