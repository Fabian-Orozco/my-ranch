#include "HashTable.hpp"
#include <random>

HashTable& HashTable::delete_element(const int64_t element) {
  if (element >= 0 && element < INT64_MAX) {
    int64_t list = hashCode(element);
    table[list].remove(element);
  } else {
    std::cerr << element << " error: enter a positive integer" << std::endl;
  }
  return *this;
}


int64_t HashTable::hashCode(const int64_t& element) {
  if (element >= 0 && element < INT64_MAX) {
    return element % this->qty_elements;
  } else {
    std::cerr << element << " error: enter a positive integer" << std::endl;
  }
  return -1;
}

void HashTable::fill_table_rand(const int64_t min, const int64_t max) {
  if (min >= 0 && max >= 0) {
    std::random_device dev;
    std::mt19937 rng(dev());
    for (int64_t counter = 0; counter < this->qty_elements; ++counter) {
      std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);
      this->insert(dist6(rng));
    }
  } else {
    std::cerr << "error: enter a positive interval" << std::endl;
  }
}

//=============================================================================
void HashTable::fill_table_sec() {
  for (int64_t element = 0; element < this->qty_elements; ++element) {
    this->insert(element);
  }
}

//=============================================================================
HashTable::HashTable(const int64_t qty_elements) {
  if (qty_elements >= 0 && qty_elements < INT64_MAX) {
    this->qty_elements = qty_elements;
    table.resize(qty_elements);
  } else {
    std::cerr << "error: enter a valid integer" << std::endl;
  }
};

//=============================================================================
HashTable::~HashTable(){
  // creates an empty vector with no memory allocated and swaps it with <<table>>, effectively delocating memory
  std::vector<std::list<int64_t>>().swap(table);
};

//=============================================================================
int64_t HashTable::search(const int64_t& element){
  if (qty_elements >= 0 && qty_elements < INT64_MAX) {
    int64_t list = hashCode(element);
    std::list<int64_t>::iterator it = table[list].begin();
    for ( ; it != table[list].end(); ++it){
      if (*it == element) {
        return list;
      }
    }
  } else {
    std::cerr << "error: enter a valid integer" << std::endl;
  }
  return -1;
};

//=============================================================================
HashTable& HashTable::insert(const int64_t element){
  if (element >= 0) {
    int position = hashCode(element);
    table[position].push_front(element);
  } else {
    std::cerr << element << " error: enter a positive integer" << std::endl;
  }
  return *this;
};

//=============================================================================
void HashTable::print_table(){
  std::list<int64_t>::iterator it;
  std::cout << "Hash table:";
  for (size_t list = 0; list < table.size(); ++list) {
    for (it = table[list].begin(); it != table[list].end(); ++it) {
      std::cout << ' ' << *it;
    }
  }
  std::cout << std::endl;
};

//=============================================================================
