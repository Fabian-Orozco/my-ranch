/**
 * @file mainSearch.cpp
 * @author Fabian Orozco Chaves (fabian7orozco@gmail.com)
 * @brief main that simulates the search for a number or performs a 
 * <SECONDS> second loop reporting the number of searches performed. 
 * Tip: compile with -O3
 * @version 0.1
 * @date 2021-12-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../Common/Colors.hpp"                       /* prints */
#include "../../Common/Utilities.cpp"                    /* flush | start and finalize program */
#include "../../Common/Vectors.cpp"                      /* int and rand vector */
#include "../../DataStructures/Graph_matrix/Graph.cpp"   /* to simulate breadth and depth search */
#include "../../DataStructures/HashTable/HashTable.cpp"  /* to simulate hash search */

#include "BinarySearch.cpp"         /* algorithm */
#include "LinearSearch.cpp"         /* algorithm */
#include "BreadthFirstSearch.cpp"   /* algorithm */
#include "DepthFirstSearch.cpp"     /* algorithm */
#include "InterpolationSearch.cpp"  /* algorithm */

#include <algorithm>  /* sort */
#include <chrono>     /* set seconds */
#include <cinttypes>  /* int64_t as default int type */
#include <iomanip>    /* setw() | setfill(' ') */
#include <iostream>   /* cout | endl */
#include <string>
#include <vector>
#include <cmath>

#define COUNT 5000  /* qty elements to fill vector */
#define MIN 1       /* minimum value */
#define MAX 74      /* maximum value */

#define SECONDS 10           /* to search */
#define VALUE_TO_SEARCH 10  /* to simulate function */
#define PRINT_VECTOR 0      /* set 1 if want print, else set 0 */

#define SIMULATE 1  /* set 1 if want simulate one search per type, else set 0 */
#define LOOP 1      /* set 1 if want perform loop search per type, else set 0 */


// Methods specification
// ============================================================================
// linear [1] | binary [2] |BFS(with graph) [3] | DFS (with graph) [4] | 
// interpolation [5]

// Simulation of any search type above
void simulate(const char* search_name, const int64_t search_ID, Vectors& vectors
 , Graph& graph, HashTable& hashTable, const int64_t root_tag = 13, const int64_t goal = 52);

// performs a <n> second loop reporting the number of searches performed.
// Simulation of any search type above
void loop_search(const char* search_name, const int64_t& search_ID
  , const int64_t seconds, Vectors& vectors, Graph& graph, HashTable& hashTable);

// prints methods
template <typename T>
void print_result(size_t result, T elem);
void print_search_header(const char* search_name, int64_t seconds);
void print_search_results(int64_t& qtySearches, int64_t& qtyFound
  , int64_t& qtyNotFound);
void init_data_structure(Vectors& vectors, Graph& graph, HashTable& hashTable);


// MAIN
// ============================================================================
int main(int argc, char* argv[]) {
  program_start_txt();

  Vectors vectors;
  Graph graph;
  HashTable hashTable(COUNT);
  init_data_structure(vectors, graph, hashTable);

  #if SIMULATE == 1
    simulate("Linear",        1, vectors, graph, hashTable);
    simulate("Binary",        2, vectors, graph, hashTable);
    simulate("Breadth First", 3, vectors, graph, hashTable, 13, 52);  //steps 74 --> 13
    simulate("Depth First",   4, vectors, graph, hashTable, 13, 52);  //steps 74 --> 13
    simulate("Interpolation", 5, vectors, graph, hashTable);  //steps 74 --> 13
    simulate("Hash",          6, vectors, graph, hashTable);  //steps 74 --> 13
  #endif
  # if LOOP == 1
    loop_search("Linear",  1, SECONDS, vectors, graph, hashTable);
    std::random_shuffle(vectors.rand_vector.begin(), vectors.rand_vector.end());
    loop_search("Binary",  2, SECONDS, vectors, graph, hashTable);
    loop_search("Breadth", 3, SECONDS, vectors, graph, hashTable);
    loop_search("Depth",   4, SECONDS, vectors, graph, hashTable);
    std::random_shuffle(vectors.rand_vector.begin(), vectors.rand_vector.end());
    loop_search("Interpolation", 5, SECONDS, vectors, graph, hashTable);
    loop_search("Hash", 6, SECONDS, vectors, graph, hashTable);
  #endif

  return program_finish_txt();
}


// Methods Implementation
// ============================================================================
void loop_search(const char* search_name, const int64_t& search_ID
  , const int64_t seconds, Vectors& vectors, Graph& graph, HashTable& hashTable) {
  
  print_search_header(search_name, seconds);
  const static int64_t size = vectors.rand_vector.size();
  static int64_t qtySearches = 0, qtyFound = 0, qtyNotFound = 0;
  static int64_t index = 0;

  // sort the vector for specific search cases
  if (search_ID == 2 || search_ID == 5) {
    std::sort(vectors.int_vector.begin(), vectors.int_vector.end());
  }

  const auto start_time = std::chrono::system_clock::now();
  while (true) {
    switch ( search_ID ) {
    case 1:
      linear_search(vectors.int_vector, vectors.rand_vector[index]) == -1 ? 
      ++qtyNotFound : ++qtyFound;
      break;
    case 2:
      binary_search(vectors.int_vector, vectors.rand_vector[index]) == -1 ? 
      ++qtyNotFound : ++qtyFound;
      break;
    case 3:
      breadth_first_search(graph, vectors.rand_vector[index]
      , vectors.rand_vector[index+1]) == -1 ? ++qtyNotFound : ++qtyFound;
      break;
    case 4:
      depth_first_search(graph, vectors.rand_vector[index]
      , vectors.rand_vector[index+1]) == -1 ? ++qtyNotFound : ++qtyFound;
      break;
    case 5:
      interpolation_search(vectors.int_vector, vectors.rand_vector[index]) 
      == -1 ? ++qtyNotFound : ++qtyFound;
      break;
    case 6:
      hashTable.search(abs(vectors.rand_vector[index])) 
      == -1 ? ++qtyNotFound : ++qtyFound;
      break;
    default:
        std::cerr << "error: incorrect search_ID" << std::endl;
      break;
    }

    index = (index + 1) % size;  // circular forward
    ++qtySearches;
    if ( std::chrono::system_clock::now() - start_time 
         > std::chrono::seconds(seconds) ) {
      break;
    }
  }
  print_search_results(qtySearches, qtyFound, qtyNotFound);
}

// ============================================================================
void simulate(const char* search_name, const int64_t search_ID, Vectors& vectors
 , Graph& graph, HashTable& hashTable, const int64_t root_tag, const int64_t goal) {
   
  std::cout << "\n" << txt_underlined << txt_bold << search_name << txt_reset 
    << txt_bold << " Search Simulation" << text_flush();
  if (search_ID == 2 || search_ID == 5) {
    sort(vectors.int_vector.begin(), vectors.int_vector.end());
  }
  switch ( search_ID ) {
  case 1:  // linear search
    print_result(linear_search(vectors.int_vector, VALUE_TO_SEARCH)
      , VALUE_TO_SEARCH);
    if (PRINT_VECTOR) { vectors.print_vector(vectors.int_vector); }
    break;
  case 2:  // binary search
    print_result(binary_search(vectors.int_vector, VALUE_TO_SEARCH)
      , VALUE_TO_SEARCH);
    if (PRINT_VECTOR) { vectors.print_vector(vectors.int_vector); }
    break;
  case 3:  // BFS search
    print_result(breadth_first_search(graph, root_tag, goal), goal);
    std::cout << " root(" << root_tag << ")" << std::endl;
    break;
  case 4:  // DFS search
    print_result(depth_first_search(graph, root_tag, goal), goal);
    std::cout << " root(" << root_tag << ")" << std::endl;
    break;
  case 5:  // interpolation search
    print_result(interpolation_search(vectors.int_vector, VALUE_TO_SEARCH)
      , VALUE_TO_SEARCH);
    std::cout << " root(" << root_tag << ")" << std::endl;
    break;
  case 6:
    print_result(hashTable.search(abs(VALUE_TO_SEARCH)), abs(VALUE_TO_SEARCH));
    break;    
  default:
    std::cerr << "error: incorrect search_ID" << std::endl;
    break;
  }
 } 
// ============================================================================
void init_data_structure(Vectors& vectors, Graph& graph, HashTable& hashTable) {
  vectors.fill_vector_rand(vectors.int_vector, COUNT, MIN, MAX);
  vectors.fill_vector_rand(vectors.rand_vector, COUNT, MIN-20, MAX+20);
  graph.fill_sample_graph(graph);
  hashTable.fill_table_rand(0, MAX+1000);
}

// ============================================================================
// print the search result to linear search
template <typename T>
void print_result(size_t result, T elem) {
  if (result == -1) { 
    std::cout << txt_bold << txt_blue << elem << txt_reset 
      << txt_red << " not found" << text_flush();
  } else {
    std::cout << txt_bold << txt_blue << elem << txt_reset 
      << txt_green << " is found" << txt_reset 
      << " in " << txt_bold << txt_blue << result << txt_reset 
      << " position" << text_flush();
 }
}

// ============================================================================
void print_search_header(const char* search_name, int64_t seconds) {
  std::cout << "\n" << txt_underlined << txt_bold << search_name << txt_reset 
    << txt_bold << " Search loop. Wait " << seconds << "s..." 
    << text_flush();
}
// ============================================================================
void print_search_results(int64_t& qtySearches, int64_t& qtyFound
  , int64_t& qtyNotFound) {
  const static int64_t mill = 1000000;
  const static int64_t thousand = 100000;
  std::cout << "Searches carried out: " << std::setfill(' ') << std::setw(5) 
    << txt_blue << qtySearches << "\t≈ " << qtySearches / mill << "." 
    << (qtySearches % mill) / thousand << "M" << text_flush()
    << "Found: " << std::setfill(' ') << std::setw(20) << txt_green << qtyFound 
    << text_flush()
    << "Not Found: "  << std::setfill(' ') << std::setw(16) << txt_red 
    << qtyNotFound << text_flush();
}

// ============================================================================
