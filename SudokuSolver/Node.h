#pragma once
#include <set>
#include <vector>
class Node
{
public:
	Node(std::string value);
	~Node();

	void AddNeighbors(std::vector<Node*> toAdd);

private:
	std::set<Node*> neigbors;
	std::set<std::string> values;
};

