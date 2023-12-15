#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - Function Rotating the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *t, *b;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	t = (*stack)->next;
	b = (*stack)->next;
	while (b->next != NULL)
		b = b->next;

	t->next->prev = *stack;
	(*stack)->next = t->next;
	b->next = t;
	t->next = NULL;
	t->prev = b;

	(void)line_number;
}

/**
 * monty_rotr - Function Roting the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *t, *b;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	t = (*stack)->next;
	b = (*stack)->next;
	while (b->next != NULL)
		b = b->next;

	b->prev->next = NULL;
	(*stack)->next = b;
	b->prev = *stack;
	b->next = t;
	t->prev = b;

	(void)line_number;
}

/**
 * monty_stack - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - stack to a queue Function.
 * @stack: Pointing to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
