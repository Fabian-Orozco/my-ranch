// Copyright 2021 Jeisson Hidalgo-Cespedes <jeisson.hidalgo@ucr.ac.cr> CC-BY-4

#include <stdbool.h>
#include <stdio.h>

#include "common.h"
#include "consumer.h"

void* consume(void* data) {
  simulation_t* simulation = (simulation_t*)data;

  while (true) {
    pthread_mutex_lock(&simulation->can_access_consumed_count);
    if (simulation->consumed_count < simulation->unit_count) {
      // reserve la siguiente unidad a producir para mí
      ++simulation->consumed_count;
      // hay indeterminismo respecto al producto que me asigno y el que saco
      // de la cola.
    } else {
      // unlock(can_access_consumed_count)
      pthread_mutex_unlock(&simulation->can_access_consumed_count);
      // break while
      break;
    }
    // unlock(can_access_consumed_count)
    pthread_mutex_unlock(&simulation->can_access_consumed_count);
    
    // wait (can_consume)
    sem_wait(&simulation->can_consume);
    size_t value = 0;
    // hay indeterminismo respecto al producto que me asigno y el que saco
    // de la cola.
    queue_dequeue(&simulation->queue, &value); // cola con mutex (TS)
    printf("\tConsuming %zu\n", value);
    usleep(1000 * random_between(simulation->consumer_min_delay
      , simulation->consumer_max_delay));
  }

  return NULL;
}
