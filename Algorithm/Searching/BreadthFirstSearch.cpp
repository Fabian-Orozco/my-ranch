#include <algorithm>
#include <cinttypes>
#include <cstdlib>
#include <iostream>
#include <list>  /*as queue*/
#include <string>
#include <vector>

#include "../../DataStructures/Graph_matrix/Graph.hpp"



//return the type of goal
//procedure breadth_first_search(Graph, root):
int64_t breadth_first_search( Graph graph, const int64_t& root_tag
   , const int64_t& goal ) {

  if (graph.in_graph(root_tag)) {
    // std::string route = "route:";
    // std::string steps_str = " ";
    // int64_t steps = 0;

    //let Q be a queue
    std::list<Graph::Vertex*> queue;
    //label root as explored
    graph.set_visited(root_tag);
    //Q.enqueue(root)
    queue.push_front(graph.get_vertex(root_tag));

    int64_t current_index = 0;
    Graph::Vertex* current_vertex = nullptr;
    //while Q is not empty do
    while ( !queue.empty() ) {
      //v := Q.dequeue()
      current_vertex = graph.get_vertex(queue.back()->tag);

      current_index = graph.get_index(current_vertex->tag);
      // PROCESS | COMPUTE 
      // std::cout << graph.get_tag(current_vertex) << " ";
      // route += " " + std::to_string(current_vertex->tag);
      // steps_str = "steps: " + std::to_string(steps);
      queue.pop_back();  
      //if v is the goal then
      if ( current_vertex->tag == goal ) {
        
        // std::cout << route << std::endl;
        // std::cout << steps_str << std::endl;
        
        //return v
        return current_index;
      }

      std::vector<Graph::Edge>* edges_current_vertex = graph.get_myEdges(*current_vertex);
      //for all edges from v to w in G.adjacentEdges(v) do
      for (int64_t adj_index = 0; adj_index < MAX_VERTICES; ++adj_index) {
        //if w is not labeled as explored then
        if ( ( *edges_current_vertex)[adj_index].exist ) {
          Graph::Vertex* adj_vertex = graph.get_vertex(graph.get_tag(adj_index));
          if ( !adj_vertex->visited ) {
          // label w as explored
            adj_vertex->visited = true;
          // Q.enqueue(w)
            queue.push_front(adj_vertex);
          }
        }
      }
      // ++steps;
    }
  }
  return -1;
}  //end procedure
