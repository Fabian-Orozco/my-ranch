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

  #pragma omp parallel num_threads(thread_count) \
    default(none) shared(values, total_sum)
  {
    double my_partial_sum = 0.0;
    #pragma omp for schedule(runtime)
    for (size_t index = 0; index < values.size(); ++index) {
      my_partial_sum += values[index];
      // values[index] = omp_get_thread_num(); 
      // no hay condición de carrera porque hay conditionally safe
    }
    // #pragma critical(can_sum)
    // OPERACION ATOMICA
    #pragma omp atomic
    total_sum += my_partial_sum;
  }

  const double average = values.size() ? total_sum / values.size() : 0.0;

  std::cout << average << std::endl;

    
  }

/* VERSION 1
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

  #pragma omp parallel num_threads(thread_count) \
    default(none) shared(values, total_sum)
  {
    double my_partial_sum = 0.0;
    #pragma omp for schedule(runtime)
    for (size_t index = 0; index < values.size(); ++index) {
      my_partial_sum += values[index];
      // values[index] = omp_get_thread_num(); 
      // no hay condición de carrera porque hay conditionally safe
    }
    #pragma omp critical(can_sum)
    total_sum += my_partial_sum;
  }

  const double average = values.size() ? total_sum / values.size() : 0.0;

  std::cout << average << std::endl;

    
  }
*/
