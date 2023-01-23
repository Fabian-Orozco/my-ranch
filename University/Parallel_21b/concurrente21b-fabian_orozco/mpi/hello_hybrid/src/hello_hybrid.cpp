// Copyright Fabian Orozco fabian.orozcochaves@ucr.ac.cr
#include <mpi.h>
#include <iostream>

using namespace std;

// proceso representado por todo el main
int main(int argc, char* argv[]) {

  if( MPI_Init( &argc, &argv ) == MPI_SUCCESS)) {
    // numero de proceso
    int process_number = -1;
    MPI_Comm_rank(MPI_COMM_WORLD, &process_number);

    // cantidad de procesos en el mundo por defecto
    size_t process_count = -1;
    MPI_Comm_size(MPI_COMM_WORLD, &process_count);

    // nombre de la maquina
    char process_hostname[MPI_MAX_PROCESSOR_NAME] = {'\0'};
    int hostname_length = -1;
    MPI_Get_processor_name(process_hostname, &hostname_length);

    cout << "Hello from main thread of process " << process_number << " of " \
      << process_count << " on " << process_hostname << endl;

    MPI_Finalize();
  } else {
    cerr << "error: could not init MPI" << endl;
  }
  return 0;
}