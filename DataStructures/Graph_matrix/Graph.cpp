#include "Graph.hpp"

#include <iomanip>
#include <iostream>

// ============================================================================
void Graph::init_graph() {
  this->vertices.resize(MAX_VERTICES);
  this->edges.resize(MAX_VERTICES);

  for (int64_t index = 0; index < MAX_VERTICES; ++index) {
    this->vertices[index].exist = false;
    this->vertices[index].visited = false;
    this->edges[index].resize(MAX_VERTICES);

    for (int64_t column = 0; column < MAX_VERTICES; ++column) {
      this->edges[index][column].exist = false;
      this->edges[index][column].weight = -1;
    }
  }
}

// ============================================================================
Graph::Graph() {
  this->directed = false;
  init_graph();
}

// ============================================================================
Graph::Graph( const bool directed ) {
  this->directed = directed;
  init_graph();
}

// ============================================================================
Graph::Graph( const Graph& other ) {
  this->directed = other.directed;
  this->vertices = other.vertices;
  this->edges = other.edges;
}

// ============================================================================
void Graph::fill_sample_graph( Graph& graph ) {
  graph.add_vertex(74).add_vertex(52).add_vertex(35)\
  .add_vertex(8).add_vertex(13).add_vertex(1);

  graph.add_edge(74,52,2);
  graph.add_edge(52,35,2).add_edge(52,13,2);
  graph.add_edge(35,52,2).add_edge(35,8,2);
  graph.add_edge(8,13,2).add_edge(8,35,2);
  graph.add_edge(13,1,2).add_edge(13,8,2);
}

// ============================================================================
void Graph::depth_first_taversal( const int64_t root_tag ) {
  if ( get_index(root_tag) == -1 ) {
    std::cerr << root_tag << " doesn't exist in a graph. error DFT" << std::endl; 
  } else {
    std::cout << "\nDepth first traversal root(" << root_tag << "): "; 
    std::list<Vertex*> stack;
    // mark first vertex as visited
    set_visited(root_tag);
    
    // PROCESS | COMPUTE
    std::cout << root_tag;
    // push vertex in stack
    stack.push_front(get_vertex(root_tag));
    while ( !stack.empty() ) {
      int64_t current_index = get_index(stack.front()->tag);
      int64_t unvisited_index = get_adjV_unvisited( current_index );

      if ( unvisited_index == -1 ) {
        stack.pop_front();
      } else {
        set_visited( this->vertices[unvisited_index].tag );
        std::cout << " " << this->vertices[unvisited_index].tag;
        stack.push_front(&this->vertices[unvisited_index]);
      }
    }
    std::cout << std::endl;
  }
}

// 
// recursive DFT ==============================================================
void Graph::depth_first_taversal_rec( const int64_t root_tag ) {
  if ( get_index(root_tag) == -1 ) {
    std::cerr << root_tag << " doesn't exist in a graph. error DFT" << std::endl; 
  } else {
    std::cout << "\nDFT_recursive root(" << root_tag << "):"; 
    DFT_recursive(root_tag);
  }
  std::cout << std::endl;
}

// ============================================================================
void Graph::DFT_recursive( const int64_t current_tag ) {
  std::cout << " " << current_tag;
  set_visited(current_tag);
  int64_t current_index = get_index(current_tag);
  for (int64_t other_v = 0; other_v < MAX_VERTICES; ++other_v) {
    if (this->edges[current_index][other_v].exist 
      && !this->vertices[other_v].visited) {
        DFT_recursive(this->vertices[other_v].tag);
    }
  }
}

// ============================================================================
int64_t Graph::get_adjV_unvisited( const int64_t root_index ) {
  if (this->vertices[root_index].exist){
    for (int64_t other_v = 0; other_v < MAX_VERTICES; ++other_v) {
      if (this->edges[root_index][other_v].exist 
        && this->vertices[other_v].visited == false) {
        return other_v;
      }
    }
  }
  return -1;
}

// ============================================================================
void Graph::set_all_unvisited() {
  for (int64_t index = 0; index < MAX_VERTICES; ++index) {
    this->vertices[index].visited = false;
  }
}

// ============================================================================
void Graph::breadth_first_taversal( const int64_t tag ) {
  int64_t current_v = get_index(tag);
  if (current_v == -1) {
    std::cerr << tag << " doesn't exist in a graph. error BFT" << std::endl; 
  } else {
    
    std::cout << "\nBreadth first traversal root(" << tag << "): "; 
    std::list<Vertex*> queue;
    queue.push_front(&this->vertices[current_v]);
    this->vertices[current_v].visited = true;

    while ( !queue.empty() ) {
      current_v = get_index(queue.back()->tag);
      // PROCESS | COMPUTE | ROUTE
      std::cout << this->vertices[current_v].tag << " ";
      queue.pop_back();

      for (int64_t adj = 0; adj < MAX_VERTICES; ++adj) {
        if ( this->edges[current_v][adj].exist && !this->vertices[adj].visited) {        
          queue.push_front(&this->vertices[adj]);
          this->vertices[adj].visited = true;
        }
      }
    }
    std::cout << std::endl;
  }
}

// ============================================================================
bool Graph::in_graph(const int64_t& tag) const {
  return (get_index(tag) == -1) ?  0 : 1;
}


// ============================================================================
std::vector<Graph::Edge>* Graph::get_myEdges( Vertex& vertex ) {
  return &edges[ get_index(vertex.tag) ];
}

// ============================================================================
int64_t Graph::get_tag( const int64_t index ) {
  return (this->vertices[index].exist) ? this->vertices[index].tag : -1;
}

// ============================================================================
Graph::Vertex* Graph::get_vertex( const int64_t tag ) {
  int64_t index = get_index(tag);
  return (this->vertices[index].exist) ? &this->vertices[index] : nullptr;
}

// ============================================================================
void Graph::set_visited( int64_t tag ) {
  int64_t index = get_index(tag);
  if (!this->vertices[index].exist) {
    std::cerr << tag << " doesn't exist in graph" << std::endl;
  } else {
    this->vertices[index].visited = true;
  }
}

// ============================================================================
Graph::Vertex& Graph::Vertex::operator=( const Vertex& other ) {
  this->exist = other.exist;
  this->tag = other.tag;
  this->visited = other.visited;
  return *this;
}


// ============================================================================
bool Graph::is_empty() const {
  for (int64_t index = 0; index < MAX_VERTICES; ++index) {
    if (this->vertices[index].exist) 
      return false;
  }
  return true;
}

// ============================================================================
bool Graph::is_full() const {
  return vertices_count() == MAX_VERTICES;
}

// ============================================================================
void Graph::clear() {
  for (int64_t index = 0; index < MAX_VERTICES; ++index) {
    this->vertices[index].tag = -1;
    this->vertices[index].visited = false;
    this->vertices[index].exist = false;

    for (int64_t column; column < MAX_VERTICES; ++column) {
      this->edges[index][column].exist = false;
      this->edges[index][column].weight = 0.0;
    }
  }
  
  this->vertices.clear();
  this->edges.clear();
  // std::vector<Vertex>().swap(this->vertices);
  // std::vector<std::vector<Edge> >().swap(this->edges);
}

// ============================================================================
int64_t Graph::vertices_count() const {
  int64_t counter = 0;
  for (int64_t index = 0; index < MAX_VERTICES; ++index) {
    if (this->vertices[index].exist) ++counter;
  }
  return counter;
}

// ============================================================================
int64_t Graph::edges_count() const {
  int64_t sum = 0;
  int64_t rows = this->edges.size();
  int64_t columns = rows;

  for (int64_t row = 0; row < rows; ++row) {
    for (int64_t column = 0; column < columns; ++column) {
      if (this->edges[row][column].exist) {
        ++sum;
      }  
    }
  }
  return sum;
}
// ============================================================================
Graph& Graph::add_vertex( const int64_t tag ) {
  int64_t index = 0;
  if ( !is_full() ) {
    while (index < MAX_VERTICES && this->vertices[index].exist) {
      ++index;
    } 
    this->vertices[index].exist = true;
    this->vertices[index].tag = tag;
  } else {
    std::cerr << "the graph is full, vertex not added. add error" << std::endl;
  }
  return *this;
}

// ============================================================================
Graph& Graph::delete_vertex( const int64_t tag ) {
  int64_t index = get_index(tag);
  if ( index != -1 ) {
    this->vertices[index].exist = false;
    for (int64_t aux = 0; aux < MAX_VERTICES; ++aux) {
      this->edges[index][aux].exist = false;
      this->edges[aux][index].exist = false;
    }
  } else {
    std::cerr << tag << " doesn't in the graph. delete error" << std::endl;
  }
  return *this;
}

// ============================================================================
Graph& Graph::add_edge( const int64_t x, const int64_t y, const double weight ) {
  if ( check_tag(x) && check_tag(y)) {
    create_edge(get_index(x), get_index(y), weight);
    if (this->directed) {
      create_edge(get_index(y), get_index(x), weight);
    }
  }
  return *this;
}


// ============================================================================
const bool Graph::check_tag(const int64_t tag) const{
  if ( !in_graph(tag) ) {
    std::cerr << tag << " doesn't exist in the graph" << std::endl;
    return false;
  }
  return true;
}

// ============================================================================
Graph& Graph::delete_edge( const int64_t x, const int64_t y) {
  int64_t x_index = get_index(x);
  int64_t y_index = get_index(y);
  
  if (check_tag(x) && check_tag(y) && this->edges[x_index][y_index].exist) {
    clear_edge(x_index, y_index);
    if (this->directed) {
      clear_edge(y_index, x_index);
    }
  } else {
    std::cerr << "the edge " << x << "->" << y << " doesn't exist" << std::endl;
  }
  return *this;
}

// ============================================================================
void Graph::create_edge( const int64_t x_index, const int64_t y_index
  , const double weight) {
  this->edges[x_index][y_index].exist = true;
  this->edges[x_index][y_index].weight = weight;
}

// ============================================================================
void Graph::clear_edge( const int64_t x_index, const int64_t y_index) {
  this->edges[x_index][y_index].exist = false;
  this->edges[x_index][y_index].weight = -1;
}

// ============================================================================
int64_t Graph::get_index( const int64_t tag ) const {
  for (int64_t index = 0; index < MAX_VERTICES; ++index) {
    if (this->vertices[index].exist && this->vertices[index].tag == tag) 
      return index;
  }
  return -1;
}

// ============================================================================
void Graph::print_matrix( int64_t mode ) const {
  std::cout << "\n          ";
  // print the row of tags
  for (int64_t row = 0; row < MAX_VERTICES; ++row) {
    if (this->vertices[row].exist) {
      std::cout << this->vertices[row].tag << std::setfill(' ') << std::setw(5);
    }
  }
  std::cout << std::endl << std::endl;
  // print matrix (row traversal)
  for (int64_t row = 0; row < MAX_VERTICES; ++row) {
    if (this->vertices[row].exist) {
      // print the column of tags
      std::cout << this->vertices[row].tag << std::setfill(' ') << std::setw(6);
      // print matrix (column traversal)
      for (int64_t column = 0; column < MAX_VERTICES; ++column) {
        if (this->vertices[column].exist) {
          if (mode == 1) {   // print exist
          // print corresponding bool (matrix input)
          std::cout << this->edges[row][column].exist << std::setfill(' ') << std::setw(5);
          } 
          else if (mode == 2) {  // print weigth
          std::cout << this->edges[row][column].weight << std::setfill(' ') << std::setw(5);
          }
        } 
      }
      // new line (row end and new begin)
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}

// ============================================================================
void Graph::print_matrix_exist() const {
  if (!is_empty()) {
    print_matrix(1);  // mode "exist"
  }
}

// ============================================================================
void Graph::print_matrix_weigth() const {
  if ( !is_empty() ) {
    print_matrix(2);  // mode "weigth"
  }
}

// ============================================================================
void Graph::print_queue(std::list<Vertex*> queue) const {
  std::cout << "\nqueue: ";
  std::list<Vertex*>::iterator current;
  std::list<Vertex*>::iterator end = queue.end();
  for (current = queue.begin(); current != end; ++current) {
    std::cout << (*current)->tag << "  ";
  }
  std::cout << std::endl;
}

// ============================================================================
void Graph::getInfo(const char* string) {
  std::cout << string << "empty: " << is_empty() << " | full: " << is_full()  
  << " | vertices count " << vertices_count() << " | edges count: " 
  << edges_count() << std::endl;
}

// ============================================================================
Graph& Graph::operator=( const Graph& other ) {
  this->vertices = other.vertices;
  this->edges = other.edges;
  return *this;
}

// ============================================================================
bool Graph::Vertex::operator==( const Vertex& other ) {
  return this->tag == other.tag;
}

// ============================================================================
bool Graph::Vertex::operator<( const Vertex& other ) {
  return this->tag < other.tag;
}
