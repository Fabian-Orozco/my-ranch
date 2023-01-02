#ifndef VECTORS_H
#define VECTORS_H

#include <cinttypes>
#include <string>
#include <vector>

class Vectors {
  public:
    std::vector<int> int_vector;
    std::vector<int> rand_vector;
    std::vector<char> chr_vector;
    std::vector<std::string> str_vector;

    Vectors();

    static void fill_vector_rand( std::vector<int>& vector, const int64_t& count
    , const int64_t& min , const int64_t& max );

    static void print_vector( std::vector<int>& vector );

    void reset_vectors();
};

#endif  // VECTORS_H
