#pragma once

#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <fstream>

/**
 * Oriented graph.
**/
class Graph {
public:
	std::map<int, std::vector<int>> vertices;

	/// Reads file and fills graph
	void read_from_file(const char* chars);

	/// Gives transponated graph
	Graph get_transponated();

	/// Clears whole graph.
	void clear();

    /// Adds single vertex to the graph.
    void add_vertex(int vertex);

    /// Adds vertices (if necessary) and an arc between them to the graph.
    void add_arc(int start_vertex, int end_vertex);

    /// Returns all vertices of the graph.
    std::vector<int> get_vertices() const;

    /// Returns all vertices, adjacent by arcs to the specified vertex.
    std::vector<int> get_adjacent_vertices(int src_vertex) const;

    /// Returns true if the vertex exists in the graph, false otherwise.
    bool has_vertex(int vertex) const;

    /// Returns true if vertices exist and have an arc between them, false otherwise.
    bool has_arc(int start_vertex, int end_vertex) const;
};
