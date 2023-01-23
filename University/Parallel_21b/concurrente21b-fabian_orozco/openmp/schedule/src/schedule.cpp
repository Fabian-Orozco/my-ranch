#include <iostream>
#include <omp.h>
#include <vector>

void print_mapping(const char* type, const std::vector<int>& mapping);

int main(int argc, char* argv[]) {
  int thread_count = omp_get_max_threads();
  if (argc >= 2) {
    thread_count = atoi(argv[1]);
  }

  int iteration_count = thread_count;
  if (argc >= 3) {
    iteration_count = atoi(argv[2]);
  }

  int block_size = 0;
  if (argc >= 4) {
    block_size = atoi(argv[3]);
  }
  (void)block_size;

  std::vector<int> mapping(iteration_count);
  std::cout << "          0 1 2 3 4 5 6 7 8 9\n";

  #pragma omp parallel num_threads(thread_count)  \
    default(none) shared(iteration_count, mapping)
  {
    #pragma omp for schedule(static)
  for (int iteration = 0; iteration < iteration_count; ++iteration) {
    mapping[iteration] = omp_get_thread_num(); // no hay condición de carrera porque hay conditionally safe
  }
  #pragma omp single
  print_mapping("static    ", mapping);
    
  #pragma omp for schedule(dynamic)
  for (int iteration = 0; iteration < iteration_count; ++iteration) {
    mapping[iteration] = omp_get_thread_num(); // no hay condición de carrera porque hay conditionally safe
  }

  #pragma omp single
  print_mapping("dynamic   ", mapping);

  #pragma omp for schedule(guided)
  for (int iteration = 0; iteration < iteration_count; ++iteration) {
    mapping[iteration] = omp_get_thread_num(); // no hay condición de carrera porque hay conditionally safe
  }

  #pragma omp single
  print_mapping("guided    ", mapping);


  } // fin de región paralela
  }

void print_mapping(const char* type, const std::vector<int>& mapping){
  std::cout << type;
  for (size_t index = 0; index < mapping.size(); ++index) {
    std::cout << mapping[index] << (index == mapping.size()-1 ? '\n' : ' ');
  }
}
