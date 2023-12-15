#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - Entry Point..
 * @argc: argument count
 * @argv: argument variable
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */
int main(int argc, char **argv)
{
	FILE *scpt_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	scpt_fd = fopen(argv[1], "r");
	if (scpt_fd == NULL)
		return (f_open_error(argv[1]));
	exit_code = run_monty(scpt_fd);
	fclose(scpt_fd);
	return (exit_code);
}
