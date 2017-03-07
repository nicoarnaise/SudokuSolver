#include "AC3.h"
using namespace std;

void AC3(std::queue<Node*> csp)
{
	deque<pair<Node*, Node*>> arcs = GenerateQueue(csp);
	// while queue is not empty
	while (!arcs.empty())
	{
		// ---- (Xi, Xj) <- Remove-First(queue) ----
		pair<Node*, Node*> arc = arcs.front();
		arcs.pop_front();
		// -----------------------------------------
		if (RemoveInconsistentValues(arc)) {
			for each (Node* neighbor in arc.first->getNeighbors())
			{
				// ---- add (Xk, Xi) to queue ------
				pair<Node*, Node*> tmpPair = make_pair(neighbor, arc.first);
				arcs.push_back(tmpPair);
				// ---------------------------------
			}
		}
	}
}

bool RemoveInconsistentValues(pair<Node*, Node*> arc)
{
	bool removed(false);
	set<string> newValues = arc.first->getValues();
	// for each value of Xi
	for each (string val in arc.first->getValues())
	{
		if (arc.second->getValues().count(val) > 0)
		{
			// the same value is possible in Xj
			if (arc.second->getNbValues() <= 1)
			{
				// Xj has only this value possible so
				// it tells to remove it from Xi
				newValues.erase(val);
				removed = true;
			}
		}
	}
	// now remove all the values it tells to.
	if (removed) {
		arc.first->setValues(newValues);
	}
	return removed;
}

/* This function makes all the arcs we have to test, 
	ignoring all Xi that has been fixed (only one value possible) */
deque<pair<Node*, Node*>> GenerateQueue(queue<Node*> csp)
{
	deque<pair<Node*, Node*>> output;
	while (!csp.empty())
	{
		Node* node = csp.front();
		csp.pop();
		if (node->getNbValues() > 1) {
			for each (Node* neighbor in node->getNeighbors())
			{
				output.push_back(make_pair(node, neighbor));
			}
		}
	}
	return output;
}
