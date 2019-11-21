#include "path.h"

bool path_exists(const Graph &graph, int start_vertex, int end_vertex) {

	std::vector<int> queue, list, current_list;
	int current_vertex;
	bool is = false;

	if (graph.has_vertex(start_vertex) && graph.has_vertex(end_vertex))
	{
		current_vertex = start_vertex;
		queue.push_back(current_vertex);
		while (!queue.empty())
		{
			current_vertex = queue.back();
			queue.pop_back();
			if (current_vertex == end_vertex)
				return true;
			current_list = graph.get_adjacent_vertices(current_vertex);
			for (int i = 0; i < current_list.size(); i++) {
				is = false;
				for (int j = 0; j < list.size(); j++)
					if (list[j] == current_list[i])
					{
						is = true;	//optomize
						break;
					}
				
				if (!is)
					queue.push_back(current_list[i]);
			}
			list.push_back(current_vertex);
		}
	}
	return false;
}
