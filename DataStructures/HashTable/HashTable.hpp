/**
 * @file HashTable.hpp
 * @author Fabian Orozco Chaves (fabian7orozco@gmail.com)
 * @brief hash table inserting with direct addressing. Collisions resolved by chaining.
 * @version 0.1
 * @date 2021-12-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef HASHT_HPP
#define HASHT_HPP

#include <list>
#include <vector>
#include <iostream>
#include <cinttypes>

class HashTable{
	public:
		// Constructor specifies the number of entries in the table
		HashTable(int64_t qty_elements);
		// Destroyer (clears table)
		~HashTable();

		int64_t hashCode(const int64_t& element);
		// Insert the element in the table
		HashTable& insert(const int64_t element);
		HashTable& delete_element(const int64_t element);
		// Returns the key position (list) or -1 if not found
		int64_t search(const int64_t& element);

		void fill_table_rand(const int64_t min, const int64_t max);
		void fill_table_sec();
	
		void print_table();

	private:
		// Number of entries in the table
		int64_t qty_elements;

		// lists vector
		std::vector<std::list<int64_t> > table;
};
#endif
