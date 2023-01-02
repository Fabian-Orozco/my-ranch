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
int64_t depth_first_search( Graph graph, const int64_t& root_tag
   , const int64_t& goal ) {
  if (graph.in_graph(root_tag)) {
    
    // std::string route = "route:";
    // std::string steps_str = " ";
    // int64_t steps = 0;
    
    std::list<Graph::Vertex*> stack;
    //label root as explored
    graph.set_visited(root_tag);
    //Q.enqueue(root)
    stack.push_front(graph.get_vertex(root_tag));

    int64_t unvisited_index = 0;
    Graph::Vertex* current_vertex = nullptr;
    //while Q is not empty do

    while ( !stack.empty() ) {
      //v := Q.dequeue()
      current_vertex = stack.front();
      unvisited_index = graph.get_adjV_unvisited(graph.get_index(current_vertex->tag));
      if ( current_vertex->tag == goal ) {
        // route += " " + std::to_string(current_vertex->tag);
        // steps_str = "steps: " + std::to_string(steps);
        // std::cout << route << std::endl;
        // std::cout << steps_str << std::endl;
        //return v
        return graph.get_index(current_vertex->tag);
      }
      if (unvisited_index == -1) {
        stack.pop_front();
      } else {
        
        graph.set_visited(graph.get_tag(unvisited_index));
        // PROCESS | COMPUTE
        // route += " " + std::to_string(current_vertex->tag);
        stack.push_front( graph.get_vertex(graph.get_tag(unvisited_index)));
        //if v is the goal then
      }
      // ++steps;
    }
  }
  return -1;
}  //end procedure
