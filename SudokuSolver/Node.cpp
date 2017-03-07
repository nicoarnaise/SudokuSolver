#include "Node.h"
using namespace std;


Node::Node(string input)
{
	// if it has no value => give it all the possibilities
	if (input == "") {
		for (int i = 1; i < 10; i++)
		{
			values.insert(to_string(i));
		}
	}
	else
	{
		// else fix the value
		values.insert(input);
	}
}

/* copy constructor */
Node::Node(Node * node) : values(node->getValues()), neighbors(node->getNeighbors())
{
}


Node::~Node()
{
}

/* Add neighbors to the node */
void Node::AddNeighbors(vector<Node*> toAdd) {
	for each (Node* var in toAdd)
	{
		if (var != this) {
			neighbors.insert(var);
		}
	}
}

/* Gives the vallue if there is only one or an X if not. */
std::string Node::toString()
{
	string output = values.size() == 1 ? (*values.begin()) : "X";
	return output;
}

/* Gives the number of values contained in the set that the node has. */
int Node::getNbSameVal(set<string> input)
{
	int output = 0;
	if (values.size() == 1)
		return 0;
	for each (string var in input)
	{
		if (values.count(var) > 0)
			output++;
	}
	return output;
}
