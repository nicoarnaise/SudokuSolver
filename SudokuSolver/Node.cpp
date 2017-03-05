#include "Node.h"
using namespace std;


Node::Node(string input)
{
	if (input == "") {
		for (int i = 1; i < 10; i++)
		{
			values.insert(to_string(i));
		}
	}
	else
	{
		values.insert(input);
	}
}

Node::Node(Node * node) : values(node->getValues()), neighbors(node->getNeighbors())
{
}


Node::~Node()
{
}

void Node::AddNeighbors(vector<Node*> toAdd) {
	for each (Node* var in toAdd)
	{
		if (var != this) {
			neighbors.insert(var);
		}
	}
}

std::string Node::toString()
{
	string output = values.size() == 1 ? (*values.begin()) : "X";
	return output;
}
