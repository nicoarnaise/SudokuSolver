#include "BackTracking.h"

using namespace std;

queue<Node*> BacktrackingSearch(queue<Node*> csp)
{
	return RecursiveBacktracking(csp);
}

// the failure is returned by a null queue<Node *>
queue<Node*> RecursiveBacktracking(queue<Node*> csp)
{
	// if assignment is complete then return assignement
	if (checkAssignment(csp)) {
		return csp;
	}
	// if our csp has some var with no values possible return failure
	if (hasNullValue(csp)) {
		return queue<Node*>();
	}
	// var <- Select-Unassigned-Variable(Variables[csp],assignment,csp)
	Node* var = getDh(getMrv(csp));
	// values <- Order-Domain-Values(var, assignment, csp)
	queue<string> values = getLcv(var);
	// ----- for each value in values ----
	while (!values.empty()) {
		string value = values.front();
		values.pop();
		// -----------------------------------
		// in our code, an assignment is done by letting
		// only one possible value to a var in our csp.
		// ----- add { var = value } to assignment ----
		//		We keep the other possible values 
		//		in a temp var in order to get them
		//		back if this value isn't the good one.
		set<string> temp = var->getValues();
		set<string> temp2;
		temp2.insert(value);
		var->setValues(temp2);
		// --------------------------------------------
		// We copy our csp in order to keep the good csp "untouched" if the
		// current value isn't the good one.
		queue<Node*> newCsp = copyCsp(csp);
		queue<Node*> result = RecursiveBacktracking(newCsp);
		// if result != failure then return result
		if (!result.empty()) {
			return result;
		}
		// the value isn't the good one
		// so we destroy our newCsp to keep memory
		while (!newCsp.empty()) {
			delete(newCsp.front());
			newCsp.pop();
		}
		// ---- remove { var = value } from assignment ---- 
		temp.erase(value);
		var->setValues(temp);
		// ------------------------------------------------
	}
	// return failure
	return queue<Node*>();
}

/* This function make the AC-3 algorithm to remove inconsistent values
	and then check if our csp is full of unique values. */
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

/* This function check if our csp has var with no values.
	That means the previous choosed value isn't the good one.*/
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