#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#ifndef CHINESEPOSTMAN_H
#define CHINESEPOSTMAN_H

const int NONE = -1; // anything < 0

class ChinesePostman
{
public:
	// Constructors
	ChinesePostman();
	ChinesePostman(std::string filename);

	// Solve the Chinese Postman Problem
	void solve();
	double optimalCost();	// cost of an optimal Chinese Postman Problem
	void print();	// print results. Must run solve() first.

private:
	// Private Member Functions
	void addEdge(std::string lab, int u, int v, double c);
	void findLeastCostPaths();									// Floyd-Warshall Algorithm?
	void checkValid();											// Determines if the graph is valid
	void findOddVertices();
	void findFeasible();										// Not sure what this does yet...find a path from one odd node to another?
																// Maybe the structure of this function changes since we are doing undirected
	bool improvements();										// Make improvements through cycle cancelling
	int findPath(int from, std::vector<std::vector<int>>repEd);	// find a path between odd vertices. Used in print()

	// Member variables
	bool solveRan;											// has the user run solve() yet?
	int nVertices;											// number of vertices
	std::vector<int> degree;								// degrees of vertices
	std::vector<int> odd;									// odd vertices
	std::vector<std::vector<int>> edges;					// adjacency matrix, counts edges between vertices
	std::vector<std::vector<std::string>> label;			// lables of arcs (for each vertex pair). A lable is the edge identifier.
	std::vector<std::vector<int>> repEdge;					// repeated edges in Chinese Postman Problem
	std::vector<std::vector<double>> cost;					// costs of cheapest edges
	std::vector<std::vector<std::string>> cheapestLabel;	// labels of cheapest edges
	std::vector<std::vector<bool>> defined;					// whether path cost is defined between vertices
	std::vector<std::vector<int>> path;						// spanning tree of the graph
	double basicCost;										// total cost of traversing each edge once
};

#endif