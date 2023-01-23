// Copyright [2021] <fabian.orozcochaves@ucr.ac.cr>


#ifndef THREADS_HPP
#define THREADS_HPP

#include <inttypes.h>
#include <semaphore.h>
#include <string>
#include <vector>

// struct para datos compartidos; cada hilo tiene acceso a ellos
struct Shared_data {
  uint64_t drive_min_delay;
  uint64_t drive_max_delay;
  bool verbose;
  std::vector<std::string> outputs;
  std::vector<char> cardinal;
  std::vector<sem_t> roundabout_sems;
  sem_t can_print;
} shared_data;

// inicializa los valores del struct
Shared_data* init_share_data() {
  Shared_data* shared_data = new Shared_data;
  shared_data->drive_min_delay = 0;
  shared_data->drive_max_delay = 0;
  shared_data->verbose = false;
  sem_init(&shared_data->can_print, 0, 0);  // inicializa can_print
  shared_data->roundabout_sems.resize(4);  // pide memoria para el vector
  shared_data->cardinal = {'N', 'O', 'S', 'E', '\0'};  // N:0 O:1 S:2 E:3
  return shared_data;
}

// libera la memoria solicitada
void destroy_share_data(Shared_data* shared_data) {
  sem_destroy(&shared_data->can_print);
  // libera la memoria de los semaforos creados
  for (size_t sem = 0; sem < 4; ++sem) {
    sem_destroy(&shared_data->roundabout_sems[sem]);
  }
  delete shared_data;
}

#endif  // THREADS_HPP
