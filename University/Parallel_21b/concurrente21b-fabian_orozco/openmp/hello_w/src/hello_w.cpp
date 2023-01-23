#include <iostream>
#include <omp.h>

int main(int argc, char* argv[]) {
  int thread_count = omp_get_max_threads();
  if (argc == 2) {
    thread_count = atoi(argv[1]);
  }
  #pragma omp parallel num_threads(thread_count)
  {
    #pragma omp critical
    {
      std::cout << "Hello from secondary thread " << omp_get_thread_num() << " of " << omp_get_num_threads()  << std::endl;
    }
  }
}

  #if 0
  #pragma omp parallel num_threads(2)
  {
    {
      if (omp_get_thread_num() == 0) {
        produce();
      } else {
        consume();
      }
    }
  }
  #endif