#pragma once
#include <vector>
#include <queue>
#include <string>

/**
* This structure represents node of tree.
*/
struct TreeNode {
	//pointers to children of node
	TreeNode* leftChild;
	TreeNode* rightChild;
	//frequency or probability
	double frequency;

	char data;
};

/**
* Creates tree node with specified parameters.
* @param leftChild - pointer to left child of new node
* @param rightChild - pointer to right child of new node
* @param frequency - frequency stored in new node
* @param data - data stored in new node
* @return pointer to created node
*/
TreeNode* createNode(TreeNode* leftChild, TreeNode* rightChild, double frequency, char data);

/**
* This class is used to compare two nodes while adding them to the priority queue. It uses overloaded
* operator ().
* @param firstNode - first node to be compared with the other
* @param secondNode - second node to be compare with the other
* @return boolean value - true if frequency stored in the first node is greather than in second node
*						  and false otherwise.
*/
class nodesComparator {
public:
	bool operator()(TreeNode* firstNode, TreeNode* secondNode) {
		return firstNode->frequency > secondNode->frequency;
	}
};

/**
* Constructs Huffmann Tree using priority queue.
* @param letters - std::vector which contains all letters which we want to code.
* @param frequencies - std::vector which contains all frequencies corresponding to every node
* @return priority_queue which contains a Huffmann Tree
*/
std::priority_queue<TreeNode*, std::vector<TreeNode*>, nodesComparator> constructHuffmannTree(
	std::vector<char> letters, std::vector<double> frequencies);

/**
* Recursive function used to view codes for each letter created using Huffmann coding.
* @param node - pointer to current node
* @param code - code for current letter
* @param outputFile - reference to std::stream object which handles outputFile
*/
void viewCodes(TreeNode* node, std::string code, std::fstream& outputFile);

