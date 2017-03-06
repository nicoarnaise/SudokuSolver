#include "Lcv.h"

using namespace std;

queue<string> getLcv(Node * node)
{
	queue<string> ordenedValues;
	set<string> values = node->getValues();
	while (!values.empty()) {
		int min(INT32_MAX);
		string value;
		for each (string var in values)
		{
			int LcvValue(0);
			for each (Node* neighbor in node->getNeighbors())
			{
				set<string> neigborValues = neighbor->getValues();
				//if (neighbor->getValues().find(var) != neighbor->getValues().end())
				if (find(neigborValues.begin(), neigborValues.end(), var) != neigborValues.end())
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
