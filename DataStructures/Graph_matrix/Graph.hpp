/**
 * @file Graph.hpp
 * @author Fabian Orozco Chaves (fabian7orozco@gmail.com)
 * @brief class directed graph represented by adjacency matrix
 * @version 0.1
 * @date 2021-12-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _GRAPH_HPP
#define _GRAPH_HPP

#include <cinttypes>  /*int64_t as default type to int*/
#include <vector>
#include <list>
#define MAX_VERTICES 10

class Graph {
 public:
  struct Vertex {
    int64_t tag;
    bool exist;
    bool visited;  /// < to Breadth First Search

    bool operator==( const Vertex& other );
    Vertex& operator=( const Vertex& other );
    bool operator<(const Vertex& other );
  };
  struct Edge {
    double weight;
    bool exist;
  };

  // constructor
  Graph();
  Graph( const Graph& other );
  Graph( const bool directed );

  Graph& operator=( const Graph& other );
  static void fill_sample_graph( Graph& graph );

  // get basic info about graph
  bool is_empty() const;
  bool is_full() const;
  void clear();
  int64_t vertices_count() const;
  int64_t edges_count() const;
  void getInfo(const char* string);
  bool in_graph(const int64_t& tag) const;

  // modify graph -> vertex
  Graph& add_vertex( const int64_t tag );
  // Graph& add_vertex( Vertex& vertex );
  Graph& delete_vertex( const int64_t tag );
  
  // modify graph -> edge
  Graph& add_edge( const int64_t x, const int64_t y, const double weight );
  // Graph& add_edge( Vertex& x, Vertex& y, double weight );
  Graph& delete_edge( const int64_t x, const int64_t y);

  // prints
  void print_matrix_exist() const;
  void print_matrix_weigth() const;
  void print_matrix( int64_t mode ) const;  // 1 to exist | 2 to weigth
  void print_queue(std::list<Vertex*> queue) const;
  const bool check_tag(const int64_t tag) const;
  
  // get (modify atributes)
  int64_t get_index( int64_t tag ) const;
  Vertex* get_vertex( const int64_t tag );
  int64_t get_tag( const int64_t index );
  int64_t get_adjV_unvisited( const int64_t index );
  std::vector<Graph::Edge>* get_myEdges( Vertex& vertex );
  
  // set (modify atributes)
  void set_visited( int64_t tag );
  void set_all_unvisited();
 
  // other basic method
  void breadth_first_taversal( const int64_t root_tag );
  void depth_first_taversal( const int64_t root_tag );
  void depth_first_taversal_rec( const int64_t root_tag );

 private:
  std::vector<Vertex> vertices;
  std::vector<std::vector<Edge> > edges;
  bool directed;  // default: false

  void init_graph();
  void getInfoV(Vertex* vertex);
  void DFT_recursive( const int64_t current_tag );

  void create_edge( const int64_t x_index, const int64_t y_index
  , const double weight);
  void clear_edge( const int64_t x_index, const int64_t y_index);

};

#endif  // _GRAPH_HPP
