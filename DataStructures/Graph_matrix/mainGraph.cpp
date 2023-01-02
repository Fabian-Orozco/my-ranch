#include "../../Common/Colors.hpp"
#include "../../Common/Utilities.cpp"
#include "Graph.hpp"

#include <iostream>

using namespace std;

int main() {
  program_start_txt();

  Graph g1;

  g1.fill_sample_graph(g1);

  g1.getInfo("g1: ");
  g1.print_matrix_exist();
  g1.print_matrix_weigth();

  g1.breadth_first_taversal(35);
  g1.set_all_unvisited();
  g1.depth_first_taversal(35);
  g1.set_all_unvisited();
  g1.depth_first_taversal_rec(35);

  return program_finish_txt();
}
