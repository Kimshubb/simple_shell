#include "shell.h"
/**
 * main - Simple Unix command line
 * Returns : 0
 */
int main(void)
{
	info_t info = INFO_INIT;

	while (1)
	{
		_puts("$ ");
		if (get_input(&info) == -1)
		{
			if (isatty(STDIN_FILENO))
				_puts("\n");
			break;
		}
		int builtin_result = find_builtin(&info);
		if (builtin_result != -1)
		{
			if (builtin_result == 1)
				continue;
			else
				return (info.status);
		}
		char **argv = strtow(info.args, " ");
		if (argv != NULL)
		{
			info.argv = argv;

			fork_cmd(&info);
			free(argv);
		}
		free_info(&info, 1);
	}
	return (0);
}
