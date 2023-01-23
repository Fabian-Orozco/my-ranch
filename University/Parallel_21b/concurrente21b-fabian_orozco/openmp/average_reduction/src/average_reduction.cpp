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
  // cuello de botella (requiere mucho tiempo)
  while (std::cin >> value) {
    values.push_back(value);
  }

  double total_sum = 0.0;

  #pragma omp parallel for num_threads(thread_count) schedule(runtime) \
    default(none) shared(values) reduction(+:total_sum)
  for (size_t index = 0; index < values.size(); ++index) {
    total_sum += values[index];
    // no hay condición de carrera porque hay conditionally safe
  }

  const double average = values.size() ? total_sum / values.size() : 0.0;

  std::cout << average << std::endl;

    
  }
