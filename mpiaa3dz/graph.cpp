#include "graph.h"

void Graph::read_from_file(const char* chars) {
	clear();
	std::ifstream in(chars);
	if (!in)
		return;

	int a, b;

	while (!in.eof()) {
		in >> a >> b;
		add_arc(a, b);
		add_arc(b, a);
	}
	in.close();
}

void Graph::clear(){
	vertices.clear();
}

void Graph::add_vertex(int vertex) {
    if (!has_vertex(vertex)) {
        vertices[vertex] = std::vector<int>();
    }
}

void Graph::add_arc(int start_vertex, int end_vertex) {
    add_vertex(start_vertex);
    add_vertex(end_vertex);
	vertices[start_vertex].push_back(end_vertex);
}


std::vector<int> Graph::get_adjacent_vertices(int src_vertex) const {
    const auto it = vertices.find(src_vertex);
    if (it == vertices.end()) {
        return std::vector<int>();
    }
    return std::vector<int>(it->second.begin(), it->second.end());
}

bool Graph::has_vertex(int vertex) const {
    return (vertices.find(vertex) != vertices.end());
}

bool Graph::has_arc(int start_vertex, int end_vertex) const {

	if (!has_vertex(start_vertex) || !has_vertex(end_vertex))
			return false;

		for (int i = 0; i < vertices.at(start_vertex).size(); i++)
			if (vertices.at(start_vertex)[i] == end_vertex)
				return true;

		return false;
}

std::vector<int> Graph::VertexCover() const{
	std::vector<int> ans;
	std::map<int, bool> visited;
	// Initialize all vertices as not visited. 
	for (const auto& p : vertices)
		visited[p.first] = false;


	// Consider all edges one by one 
	for (const auto& p : vertices) {
		int u = p.first;
		// An edge is only picked when both visited[u] and visited[v] 
		// are false 
		if (visited[u] == false)
		{
			// Go through all adjacents of u and pick the first not 
			// yet visited vertex (We are basically picking an edge 
			// (u, v) from remaining edges. 
			for (int v : p.second) {
				if (visited[v] == false)
				{
					// Add the vertices (u, v) to the result set. 
					// We make the vertex u and v visited so that 
					// all edges from/to them would be ignored 
					visited[v] = true;
					visited[u] = true;
					break;
				}
			}
		}
	}

	// Print the vertex cover 
	for (const auto& p : visited)
		if (p.second)
			ans.push_back(p.first);
	return ans;
}