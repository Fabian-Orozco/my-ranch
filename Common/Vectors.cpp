#include "Vectors.hpp"

#include <assert.h>
#include <iomanip>
#include <iostream>
#include <random>

// ============================================================================

Vectors::Vectors() { }

// ============================================================================
// print all vector content
void Vectors::print_vector(std::vector<int>& vector) {
  assert(&vector);
  std::cout << "vector elements: " << std::setw(5);
  for (size_t index = 0; index < vector.size(); ++index) {
    std::cout << vector[index] << std::setw(3);
  }
  std::cout << std::endl;
  std::cout << "vector index: " << std::setw(8);
  for (size_t index = 0; index < vector.size(); ++index) {
    std::cout << index << std::setw(3);
  }
  std::cout << std::endl;
}

// ============================================================================
// fill vector with random <count> values
void Vectors::fill_vector_rand(std::vector<int>& vector, const int64_t& count
  , const int64_t& min, const int64_t& max){
  
  assert(&vector);
  vector.resize(count);

  std::random_device dev;
  std::mt19937 rng(dev());

  for (int64_t index = 0; index < count; ++index) {
     // range
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);
    int64_t value = dist6(rng);
    vector[index] = value;
  }
}

// ============================================================================
void Vectors::reset_vectors() {
  this->int_vector.resize(0);
  this->chr_vector.resize(0);
  this->str_vector.resize(0);
}

// ============================================================================
