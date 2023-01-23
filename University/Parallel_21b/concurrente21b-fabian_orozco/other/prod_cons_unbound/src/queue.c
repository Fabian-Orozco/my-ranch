// Copyright 2021 Jeisson Hidalgo-Cespedes <jeisson.hidalgo@ucr.ac.cr> CC-BY-4

#include <assert.h>
#include <stdlib.h>

#include "queue.h"

void queue_remove_first_unsafe(queue_t* queue);
bool queue_is_empty_unsafe(queue_t* queue);

int queue_init(queue_t* queue) {
  assert(queue);
  // MUTEEEEX
  int error = pthread_mutex_init(&queue->can_access_queue, /*attr*/ NULL);
  queue->head = NULL;
  queue->tail = NULL;
  return error;
}

int queue_destroy(queue_t* queue) {
  queue_clear(queue);
  // MUTEEEEX
  int error = pthread_mutex_destroy(&queue->can_access_queue);
  return error;
}

bool queue_is_empty(queue_t* queue) {
  assert(queue);
  pthread_mutex_lock(&queue->can_access_queue);
  //control de flujo y de concurrencia con variable
  bool result = queue->head == NULL; //proteccion con variable (por return)
  pthread_mutex_unlock(&queue->can_access_queue);
  return result;
}

bool queue_is_empty_unsafe(queue_t* queue) {
  assert(queue);
  return queue->head == NULL;
}

int queue_enqueue(queue_t* queue, const size_t data) {
  assert(queue);
  int error = EXIT_SUCCESS;

  queue_node_t* new_node = (queue_node_t*) calloc(1, sizeof(queue_node_t));
  if (new_node) {
    new_node->data = data; // memoria local
    // no hay memoria compartida hasta este punto

    pthread_mutex_lock(&queue->can_access_queue);
    if (queue->tail) { // acceso a memoria compartida | hay concurrencia | modi
      queue->tail = queue->tail->next = new_node; // cond. carrera
    } else {
      queue->head = queue->tail = new_node; // cond. carrera
    }
    pthread_mutex_unlock(&queue->can_access_queue);
  } else {
    error = EXIT_FAILURE;
  }
  return error;
}

int queue_dequeue(queue_t* queue, size_t* data) {
  assert(queue);
  int error = 0;

  pthread_mutex_lock(&queue->can_access_queue);
  if (!queue_is_empty_unsafe(queue)) {
    if (data) {
      
      *data = queue->head->data;

    }
    queue_remove_first_unsafe(queue);
  } else {
    error = EXIT_FAILURE;
  }
  pthread_mutex_unlock(&queue->can_access_queue);

  return error;
}

void queue_remove_first_unsafe(queue_t* queue) {
  assert(queue);
  assert(!queue_is_empty_unsafe(queue));
  queue_node_t* node = queue->head;
  queue->head = queue->head->next;
  free(node);
  if (queue->head == NULL) {
    queue->tail = NULL;
  }
}

void queue_clear(queue_t* queue) {
  assert(queue);
  pthread_mutex_lock(&queue->can_access_queue);
  while (!queue_is_empty_unsafe(queue)) {
    queue_remove_first_unsafe(queue);
  }
  pthread_mutex_unlock(&queue->can_access_queue);
}
