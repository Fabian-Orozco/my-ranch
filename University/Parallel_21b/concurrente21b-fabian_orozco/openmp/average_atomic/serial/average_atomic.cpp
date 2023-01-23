#include <omp.h>

#include <iostream>
#include <vector>

void print_mapping(const char* type, const std::vector<int>& mapping);

int main(int argc, char* argv[]) {
  int thread_count = omp_get_max_threads();
  if (argc >= 2) {
    thread_count = atoi(argv[1]);
  }
  std::vector<double> values;

  double value = 0;
  while (std::cin >> value) {
    values.push_back(value);
  }

  double sum = 0.0;

  // #pragma omp parallel for num_threads(thread_count) schedule(runtime) \
  //   default(none) shared(iteration_count, mapping)

  for (int index = 0; index < values.size(); ++index) {
    sum += values[index];
    // values[index] = omp_get_thread_num(); 
    // no hay condición de carrera porque hay conditionally safe
  }


  const double average = values.size() ? sum / values.size() : 0.0;

  std::cout << average << std::endl;

    
  }

