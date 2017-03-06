#pragma once
#include <set>
#include <vector>
#include <string>
class Node
{
public:
	Node(std::string value);
	Node(Node* node);
	~Node();

	void AddNeighbors(std::vector<Node*> toAdd);
	std::string toString();
	int getNbValues() { return values.size(); }
	void removeValue(std::string input) { values.erase(input); }
	std::set<std::string> getValues() { return values; }
	void setValues(std::set<std::string> input) { values = input; }
	void setNeighbors(std::set<Node*> input) { neighbors = input; }
	std::set<Node*> getNeighbors() { return neighbors; }
	int getNbSameVal(std::set<std::string> input);

private:
	std::set<Node*> neighbors;
	std::set<std::string> values;
};

