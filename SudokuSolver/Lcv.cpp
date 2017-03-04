#include "Lcv.h"

using namespace std;

string getLcv(Node * node)
{
	string val;
	int min(INFINITY);
	for each (string var in node->getValues())
	{
		int LcvValue(0);
		for each (Node* neighbor in node->getNeigbhors)
		{
			if (neighbor->getValues().find(var) != neighbor->getValues().end)
				LcvValue++;
		}
		if (LcvValue < min) {
			min = LcvValue;
			val = var;
		}
	}
	return val;
}
