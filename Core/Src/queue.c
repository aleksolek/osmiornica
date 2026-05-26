/**
 ******************************************************************************
 * @file    queue.c
 * @brief   This file provides implementation of a simple queue
 ******************************************************************************
 */

#include "queue.h"
#include "stm32_assert.h"
#include "usart.h"
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SWITCH_NUMBER 5

typedef struct node {
  uint32_t switchNumber;
  struct node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

static bool Queue_IsEmpty(void) { return head == NULL; }

// static void Queue_Print(void) {
//   UART_Write("QUEUE: ", 7);
//   for (Node *temp = head; temp != NULL; temp = temp->next) {
//     UART_PutChar((uint8_t *)&temp->switchNumber);
//     UART_PutChar(" ");
//   }
//   UART_PutChar("\n");
// }

void Queue_Add(uint32_t switchNumber) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  assert_param(new_node != NULL);
  assert_param(switchNumber <= MAX_SWITCH_NUMBER);

  new_node->next = NULL;
  new_node->switchNumber = switchNumber;
  if (head == NULL) {
    head = new_node;
  } else {
    tail->next = new_node;
  }
  tail = new_node;
}

void Queue_Remove(uint32_t switchNumber) {
  if (Queue_IsEmpty()) {
    return;
  }
  Node *temp_node;
  Node *prev_node = NULL;
  for (temp_node = head; temp_node != NULL; temp_node = temp_node->next) {
    if (temp_node->switchNumber == switchNumber) {
      break;
    }
    prev_node = temp_node;
  }
  if (temp_node != NULL) {
    if (head == temp_node) {
      head = temp_node->next;
    } else {
      prev_node->next = temp_node->next;
    }
    if (temp_node->next == NULL) {
      tail = prev_node;
    }
    free(temp_node);
  }
}
