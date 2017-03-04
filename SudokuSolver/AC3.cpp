#include "AC3.h"
using namespace std;

void AC3(std::queue<Node*> csp)
{
	queue<pair<Node*, Node*>> arcs = GenerateQueue(csp);
	while (!arcs.empty)
	{
		pair<Node*, Node*> arc = arcs.front();
		arcs.pop();
		if (RemoveInconsistentValues(arc)) {
			for each (Node* neighbor in arc.first->getNeighbors())
			{
				arcs.emplace(make_pair(neighbor, arc.first));
			}
		}
	}
}

bool RemoveInconsistentValues(pair<Node*, Node*> arc)
{
	bool removed(false);
	for each (string val in arc.first->getValues())
	{
		if (arc.second->getValues().find(val) != arc.second->getValues().end())
		{
			if (arc.second->getNbValues() == 1)
			{
				arc.first->getValues().erase(val);
				removed = true;
			}
		}
	}
	return removed;
}

queue<pair<Node*, Node*>> GenerateQueue(queue<Node*> csp)
{
	queue<pair<Node*, Node*>> output;
	while (!csp.empty)
	{
		Node* node = csp.front();
		csp.pop();
		for each (Node* neighbor in node->getNeighbors())
		{
			output.emplace(make_pair(node, neighbor));
		}
	}
	return output;
}
