#include "monty.h"

void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/**
 * monty_push - Function that Push a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *nw;
	int t;

	nw = malloc(sizeof(stack_t));
	if (nw == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}

	for (t = 0; op_toks[1][t]; t++)
	{
		if (op_toks[1][t] == '-' && t == 0)
			continue;
		if (op_toks[1][t] < '0' || op_toks[1][t] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
	nw->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		tmp = (*stack)->next;
		nw->prev = *stack;
		nw->next = tmp;
		if (tmp)
			tmp->prev = nw;
		(*stack)->next = nw;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		nw->prev = tmp;
		nw->next = NULL;
		tmp->next = nw;
	}
}

/**
 * monty_pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *l = (*stack)->next;

	while (l)
	{
		printf("%d\n", l->n);
		l = l->next;
	}
	(void)line_number;
}

/**
 * monty_pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * monty_pop - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * monty_swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *l;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
	}

	l = (*stack)->next->next;
	(*stack)->next->next = l->next;
	(*stack)->next->prev = l;
	if (l->next)
		l->next->prev = (*stack)->next;
	l->next = (*stack)->next;
	l->prev = *stack;
	(*stack)->next = l;
}
