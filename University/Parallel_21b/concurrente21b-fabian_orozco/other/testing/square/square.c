// Copyright 2021 <fabian.orozcochaves@ucr.ac.cr>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Returns the squared number
 * @details 
 *    @code
 *       assert(4 == square (-2))
 *    \endcode
 * @param number The number to be suared
 * @return The square of the number
 */
long long square(long long number) {
  return number * number;
}

/**
 * param exponent ... It must be always 0 or positive
 */
long long integer_power(long long base, int exponent) {
  // Defensive programming (para devs).
  // assert(exponent >= 0 );
  // otra forma (para devs y clientes):
  if (exponent < 0){
    fprintf(stderr, "invalid number ");
    return EXIT_FAILURE;
  }
  int i=1;
  int resultado = 1;
  while(i <= exponent) {
      resultado = resultado * base;
      ++i;
  }
  return resultado;
}

const size_t BUFFER_MAX = 1024;
/**
 * @return Error code, 0 on succes
 */
int main(void) {
  // char buffer[BUFFER_MAX];
  FILE* input = stdin;
  FILE* output = stdout;

  long long value = 0ll;
  printf("inserte valores mayores que 0: ");
  while ( (fscanf(input , "%lld" , &value)) == 1 ) {
    const long long result = integer_power(value, value);
    fprintf(output, "%lld\n", result);
  }
  return 0;
}