#include "Lcv.h"

using namespace std;

queue<string> getLcv(Node * node)
{
	queue<string> ordenedValues;
	set<string> values = node->getValues();
	while (!values.empty()) {
		int min(INFINITY);
		string value;
		for each (string var in values)
		{
			int LcvValue(0);
			for each (Node* neighbor in node->getNeighbors())
			{
				if (neighbor->getValues().find(var) != neighbor->getValues().end())
					LcvValue++;
			}
			if (LcvValue < min ) {
				min = LcvValue;
				value = var;
			}
		}
		ordenedValues.push(value);
		values.erase(value);
	}
	return ordenedValues;
}
