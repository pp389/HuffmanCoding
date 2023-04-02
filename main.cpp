#include <iostream>
#include "Exceptions.h"
#include "LibFiles.h"
#include "HuffmannCoding.h"

int main() {
	try {
		std::string inputFileName, outputFileName;
		std::cout << "Input file name: ";
		std::cin >> inputFileName;
		std::cout << "Output file name: ";
		std::cin >> outputFileName;

		std::fstream inputFile, outputFile;
		openFile(inputFile, inputFileName);
		openFile(outputFile, outputFileName);

		std::vector<char> letters;
		std::vector<double> frequencies;

		char letter;
		double frequency;
		while (inputFile >> letter >> frequency) {
			if (frequency < 0)
				throw Exceptions::InvalidInputValueException("Frequency must be greater or equal to zero!");

			letters.push_back(letter);
			frequencies.push_back(frequency);
		}

		std::priority_queue<TreeNode*, std::vector<TreeNode*>, nodesComparator> huffmannTree = 
			constructHuffmannTree(letters, frequencies);
		viewCodes(huffmannTree.top(), "", outputFile);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}