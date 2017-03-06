#include "BackTracking.h"

using namespace std;

queue<Node*> BacktrackingSearch(queue<Node*> csp)
{
	return RecursiveBacktracking(csp);
}

queue<Node*> RecursiveBacktracking(queue<Node*> csp)
{
	if (checkAssignment(csp)) {
		return csp;
	}
	if (hasNullValue(csp)) {
		return queue<Node*>();
	}
	Node* var = getDh(getMrv(csp));
	queue<string> values = getLcv(var);
	while (!values.empty()) {
		string value = values.front();
		values.pop();
		// ----- add { var = value } to assignment ----
		set<string> temp = var->getValues();
		set<string> temp2;
		temp2.insert(value);
		var->setValues(temp2);
		// --------------------------------------------
		queue<Node*> newCsp = copyCsp(csp);
		queue<Node*> result = RecursiveBacktracking(newCsp);
		if (!result.empty()) {
			return result;
		}
		while (!newCsp.empty()) {
			delete(newCsp.front());
			newCsp.pop();
		}
		// the value isn't the good one
		temp.erase(value);
		var->setValues(temp);
	}
	return queue<Node*>();
}

bool checkAssignment(queue<Node*> csp)
{
	AC3(csp);
	while (!csp.empty()) {
		if (csp.front()->getNbValues() != 1) {
			return false;
		}
		csp.pop();
	}
	return true;
}

bool hasNullValue(queue<Node*> csp)
{
	while (!csp.empty()) {
		if (csp.front()->getNbValues() < 1) {
			return true;
		}
		csp.pop();
	}
	return false;
}