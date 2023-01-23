// Copyright [2021] <fabian.orozcochaves@ucr.ac.cr>

#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <thread>

#include "Shared_data.hpp"

// ==============================UTILITIES=====================================
int analyze_arguments(int argc, char* argv[], Shared_data* shared_data);
void print_routes(const std::vector<std::string>& route);
void drive(Shared_data* shared_data);
int start_simulation(uint64_t segment_capacity, Shared_data* shared_data);
void vehicle(Shared_data* shared_data, uint64_t rank, char enter_from
  , char exit_to);
int checkChar(const char& input);
size_t getIndex(const char& character);

// =================================MAIN=======================================
  // inicializa los datos compartidos
  // analiza argumentos
  // inicia la simulacion
int main(int argc, char* argv[]) {
  Shared_data* shared_data;
  shared_data = init_share_data();

  analyze_arguments(argc, argv, shared_data);

  uint64_t segment_capacity = 0;
  std::cin >> segment_capacity;
  // Si no se pudo inicializar
  if (!segment_capacity) {
    std::cerr << "error: segment_capacity no inicializado" << std::endl;
    return EXIT_FAILURE;
  }

  start_simulation(segment_capacity, shared_data);

  destroy_share_data(shared_data);
  return EXIT_SUCCESS;
}  // end procedure

// ==============================START SIMULATION==============================

  // inicializa semaforos
  // lee de la entrada estandar
  // crea los vectores segun lo anterior y los ejecuta
  // e imprime las rutas
int start_simulation(uint64_t segment_capacity, Shared_data* shared_data) {
  // Inicializa el vector de semaforos
  for (size_t sem = 0; sem < 4; ++sem) {
    sem_init(&shared_data->roundabout_sems[sem], 0 , segment_capacity);
  }

  // declare const enter_from = read_char(stdin)
  // declare const exit_to = read_char(stdin)
  std::string line = "";
  // declare rank = 0
  uint64_t rank = 0;
  std::vector<std::thread> vehicles;
  // while can_read(stdin) do
  while (std::cin >> line) {
    // se encuentra en rutas validas
    if (line.size() >= 2 && checkChar(line[0]) && checkChar(line[1])) {
        // reserva el espacio para que el vehiculo escriba
        shared_data->outputs.push_back("");
        // create_thread(vehicle, enter_from, exit_to)
        vehicles.push_back(std::thread(vehicle, shared_data, rank++, line[0]
          , line[1]));
    }
  }
  for (size_t vehicle = 0; vehicle < vehicles.size(); ++vehicle) {
    // da luz verde para printear sus resultados
    sem_post(&shared_data->can_print);
  }
  // libera/une los hilos al hilo principal
  for (size_t vehicle = 0; vehicle < vehicles.size(); ++vehicle) {
    vehicles[vehicle].join();
  }
  print_routes(shared_data->outputs);
  return EXIT_SUCCESS;
}

// ============================VEHICLE=========================================
  // realiza el recorrido del vehiculo, agrega su ruta personal y reporta en el
  // caso de tener el modo detallado (verbose)
void vehicle(Shared_data* shared_data, uint64_t rank, char enter_from
  , char exit_to) {
  std::string verbose_route = "";
  std::string my_route = "";
  // current_sem := index_roundabout_sems[enter_from]
  uint64_t current_sem = getIndex(enter_from);
  // declare integer next
  size_t next_sem;

  // para casos NN, SS, OO, EE
  sem_wait(&shared_data->roundabout_sems[current_sem]);
  drive(shared_data);
  if (shared_data->verbose == true) {
    verbose_route = std::to_string(rank) + ": "
    + shared_data->cardinal[current_sem] + "\n";
    std::cout << verbose_route;
  }
  my_route += std::string(" ") + shared_data->cardinal[current_sem];
  sem_post(&shared_data->roundabout_sems[current_sem]);

  do {
    next_sem = (current_sem + 1) % 4;
    current_sem = next_sem;
    // wait(roundabout_sems[current_sem])
    sem_wait(&shared_data->roundabout_sems[current_sem]);
    // drive()
    drive(shared_data);
    //   if verbose = true do
    if (shared_data->verbose == true) {
      // print rank + ": " + current_sem
      verbose_route = std::to_string(rank) + ": "
      + shared_data->cardinal[current_sem] + "\n";
      std::cout << verbose_route;
    }
    // signal(roundabout_sems[current_sem])
    sem_post(&shared_data->roundabout_sems[current_sem]);
    // my_route += " " + current_sem
    my_route += std::string(" ") + shared_data->cardinal[current_sem];
    // while current_sem not_equal_to exit_to
  } while (shared_data->cardinal[current_sem] != exit_to);
  sem_wait(&shared_data->can_print);
  // outputs[rank] = my_route
  shared_data->outputs[rank] = (my_route);
}

// ==========================ANALYZE ARGUMENTS=================================
  // analiza los tiempos introducidos, verifica errores;
  // además de activar o desactivar el modo verbose
int analyze_arguments(int argc, char* argv[], Shared_data* shared_data) {
  try {
    // if argc >= 3 then
    if (argc >= 3) {
      // drive_min_delay := integer(argv[1])
      shared_data->drive_min_delay = std::stoll(argv[1]);
      // drive_max_delay := integer(argv[2])
      shared_data->drive_max_delay = std::stoll(argv[2]);
      // en caso de que se ingresaran al reves
      if (shared_data->drive_min_delay > shared_data->drive_max_delay) {
        std::swap(shared_data->drive_min_delay, shared_data->drive_max_delay);
      }
    }
    // if argc >= 4 then
    if (argc >= 4) {
      // verbose := argv[3] = "-v"
      (std::string(argv[3]) == "-v") ?
        shared_data->verbose = true : shared_data->verbose = false;
    }
  }
  catch(const std::invalid_argument& e) {
    std::cerr << "error: invalid_arguments" << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}  // end procedure

// =============================PRINT ROUTES===================================
  // imprime el vector con los resultados de los recorridos de todos los
  // vehiculos
void print_routes(const std::vector<std::string>& outputs) {
  // for current_rank := 0 to thread_count do
  for (size_t current_rank = 0; current_rank < outputs.size(); ++current_rank) {
  //   print current_rank + outputs[current_rank].front()
  // + outputs[current_rank].back() + ": " + outputs
    std::cout << current_rank << outputs[current_rank].substr(0, 2)
    <<  outputs[current_rank].back() << ":" << outputs[current_rank]
    << std::endl;
  }  // end for
}  // end procedure

// ==============================DRIVE=========================================
  // genera un delay oara simular la conduccion del vehiculo
void drive(Shared_data* shared_data) {
  // declare const range = drive_max_delay - drive_min_delay
  const int range = shared_data->drive_max_delay
    - shared_data->drive_min_delay;
  // declare duration := drive_min_delay
  uint64_t duration = shared_data->drive_min_delay;

  // if range > 0 then
  if (range > 0) {
  //   duration += rand() % range
    duration += rand() % range;  //NOLINT
  }  // end if
  std::this_thread::sleep_for(std::chrono::milliseconds(duration));
}

// =============================CHECKCHAR======================================
  // metodo auxiliar para verificar que el caracter es correcto (en la stdin)
int checkChar(const char& input) {
  if (input == 'N' || input == 'O' || input == 'S' || input == 'E') {
    return 1;
  }
  return 0;
}

// ==============================GETINDEX======================================
  // metodo que retorna un numero según el caracter enviado, esto para el manejo
  // del contador del semaforo actual en el metodo vehiculo
size_t getIndex(const char& character) {
  switch (character) {
    case 'N':
      return 0;
      break;
    case 'O':
      return 1;
      break;
    case 'S':
      return 2;
      break;
    case 'E':
      return 3;
      break;
    default:
      return -1;
  }
}
// =============================ENDOFCODE======================================
