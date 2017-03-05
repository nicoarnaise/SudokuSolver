#pragma once
#include <queue>
#include "Node.h"
#include "Dh.h"
#include "Mrv.h"
#include "Lcv.h"
#include "AC3.h"
#include "Utilities.h"

std::queue<Node*> BacktrackingSearch(std::queue<Node*> csp);

std::queue<Node*> RecursiveBacktracking(std::queue<Node*> csp);

bool checkAssignment(std::queue<Node*> csp);