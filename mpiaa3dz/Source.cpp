#define CATCH_CONFIG_RUNNER

#include "Library.h"

int main(int argc, char* argv[])
{
	Graph g;
	g.read_from_file("input.txt");

	std::vector<int> ans = g.VertexCover();

	result_to_file(ans, "output.txt");
	return 1;
}