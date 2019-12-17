#include "huffman.h"
#include <conio.h>
#include <iostream>
#include <fstream>

std::ifstream f;

void main() {
	const auto *tree = buildTree();
	std::string input = {};

	build_dict(input);
	try {
		auto encoded = encode(tree, input);
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	f.open("data.txt");
	while (f.peek() != EOF) {
		std::string data = {};
		std::string decoded = {};
		std::getline(f, data);
		decode(tree, data, decoded);
		std::cout << "Decoded data: " << decoded << std::endl;
	}

	deleteTree(tree);
	_getch();
}
