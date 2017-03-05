#include "BackTracking.h"

using namespace std;

queue<Node*> BacktrackingSearch(queue<Node*> csp)
{
	return RecursiveBacktracking(csp);
}

queue<Node*> RecursiveBacktracking(queue<Node*> csp)
{
	AC3(csp);
	if (checkAssignment(csp)) {
		return csp;
	}
	Node* var = getDh(getMrv(csp));
	queue<string> values = getLcv(var);
	while (!values.empty()) {
		string value = values.front();
		values.pop();
		// Thanks to AC3, the values here are all consistent.
		// ----- add { var = value } to assignment ----
		set<string> temp = var->getValues();
		set<string> temp2;
		temp2.insert(value);
		var->setValues(temp2);
		// --------------------------------------------
		queue<Node*> result = RecursiveBacktracking(copyCsp(csp));
		if (!result.empty()) {
			return result;
		}
		temp.erase(value);
		var->setValues(temp);
	}
	return queue<Node*>();
}

bool checkAssignment(queue<Node*> csp)
{
	while (!csp.empty()) {
		if (csp.front()->getNbValues() > 1) {
			return false;
		}
		csp.pop();
	}
	return true;
}
