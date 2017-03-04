#include "Node.h"
using namespace std;


Node::Node(string input)
{
	if (input == "") {
		for (int i = 1; i < 10; i++)
		{
			values.emplace("" + i);
		}
	}
	else
	{
		values.emplace(input);
	}
}


Node::~Node()
{
}

void Node::AddNeighbors(vector<Node*> toAdd) {
	for each (Node* var in toAdd)
	{
		if (var != this) {
			neighbors.emplace(var);
		}
	}
}
