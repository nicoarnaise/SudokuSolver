#include "AC3.h"
using namespace std;

void AC3(std::queue<Node*> csp)
{
	deque<pair<Node*, Node*>> arcs = GenerateQueue(csp);
	while (!arcs.empty())
	{
		pair<Node*, Node*> arc = arcs.front();
		arcs.pop_front();
		if (RemoveInconsistentValues(arc)) {
			for each (Node* neighbor in arc.first->getNeighbors())
			{
				pair<Node*, Node*> tmpPair = make_pair(neighbor, arc.first);
				if (find(arcs.begin(), arcs.end(), tmpPair) == arcs.end()) {
					arcs.push_back(tmpPair);
				}
			}
		}
	}
	bool done = true;
}

bool RemoveInconsistentValues(pair<Node*, Node*> arc)
{
	bool removed(false);
	set<string> newValues = arc.first->getValues();
	for each (string val in arc.first->getValues())
	{
		if (arc.second->getValues().count(val) != 0)
		{
			if (arc.second->getNbValues() == 1)
			{
				//arc.first->getValues().erase(val);
				newValues.erase(val);
				removed = true;
			}
		}
	}
	if (removed)
		arc.first->setValues(newValues);
	return removed;
}

deque<pair<Node*, Node*>> GenerateQueue(queue<Node*> csp)
{
	deque<pair<Node*, Node*>> output;
	while (!csp.empty())
	{
		Node* node = csp.front();
		csp.pop();
		for each (Node* neighbor in node->getNeighbors())
		{
			output.push_back(make_pair(node, neighbor));
		}
	}
	return output;
}
