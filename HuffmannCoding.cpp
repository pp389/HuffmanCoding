#include "HuffmannCoding.h"
#include <fstream>

TreeNode* createNode(TreeNode* leftChild, TreeNode* rightChild, double frequency, char data) {
	TreeNode* newNode = new TreeNode;
	newNode->leftChild = leftChild;
	newNode->rightChild = rightChild;
	newNode->frequency = frequency;
	newNode->data = data;

	return newNode;
}

std::priority_queue<TreeNode*, std::vector<TreeNode*>, nodesComparator> constructHuffmannTree(
	std::vector<char> letters, std::vector<double> frequencies) {

	std::priority_queue<TreeNode*, std::vector<TreeNode*>, nodesComparator> resultTree;

	for (int i = 0; i < letters.size(); i++)
		resultTree.push(createNode(nullptr, nullptr, frequencies[i], letters[i]));

	while (resultTree.size() != 1) {
		//pointer to node which will be created from two others from priority queue
		TreeNode* newNode;
		//nodes from which the new node will be created
		TreeNode* leftChild;
		TreeNode* rightChild;
		//get nodes from priority queue
		leftChild = resultTree.top();
		resultTree.pop();
		rightChild = resultTree.top();
		resultTree.pop();
		//create new node
		newNode = createNode(leftChild, rightChild, leftChild->frequency + rightChild->frequency, '!');
		//add new node to priority_queue
		resultTree.push(newNode);
	}

	return resultTree;
}

void viewCodes(TreeNode* node, std::string code, std::fstream& outputFile) {
	if (node) {
		if (node->data != '!')
			outputFile << node->data << " = " << code << std::endl;

		viewCodes(node->leftChild, code + "0", outputFile);
		viewCodes(node->rightChild, code + "1", outputFile);
	}
}