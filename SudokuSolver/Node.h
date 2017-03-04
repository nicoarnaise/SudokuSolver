#pragma once
#include <set>
#include <vector>
class Node
{
public:
	Node(std::string value);
	~Node();

	void AddNeighbors(std::vector<Node*> toAdd);
	int getNbValues() { return values.size(); }
	std::set<std::string> getValues() { return values; }
	set<Node*> getNeigbhors() { return neighbors; }

private:
	std::set<Node*> neighbors;
	std::set<std::string> values;
};

