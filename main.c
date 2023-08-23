#include "shell.h"
/**
 * main - Simple Unix command line
 * Returns : 0
 */
int main(int argc, char *argv[])
{
	info_t info = INFO_INIT;
	int builtin_result = 0;
	char **argv_cmd = NULL;
	char line[READ_BUF_SIZE];
	size_t len;

	if (argc == 2)
	{
		FILE *file = fopen(argv[1], "r");
		if (file == NULL)
		{
			perror("Error opening file");
			return EXIT_FAILURE;
		}
		while (fgets(line, sizeof(line), file) != NULL)
		{
			if (line[0] == '#')
				continue;
			len = strlen(line);
			if (len > 0 && line[len - 1 == '\n'])
				line[len - 1] = '\0';

			info.args = line;
			argv_cmd = strtow(info.args, " ");
			if (argv_cmd != NULL)
			{
				info.argv = argv_cmd;
				builtin_result = find_builtin(&info);
				if (builtin_result != -1)
				{
					if (builtin_result == 1)
						continue;
					else
						return info.status;
				}
				fork_cmd(&info);
				free(argv_cmd);
			}
			clear_info(&info);
		}
		fclose(file);
		return 0;
}
//interactive mode
while (1)
{
	_puts("$ ");
	/*read user input*/
	if (get_input(&info) == -1)
	{
		if (isatty(STDIN_FILENO))
		_puts("\n");
		break;
	}
	/*Skip comments*/
	if (info.args[0] == '#')
	{
		free_info(&info, 1);
		continue;
	}
		/*replace $? and $$ variables*/
	info.args  = replace_exit_status(info.args, info.status);
	info.args = replace_p_id(info.args);
	/*find builtins and execute or fork external cmds*/
	builtin_result = find_builtin(&info);
	if (builtin_result != -1)
	{
		if (builtin_result == 1)
			continue;
		else
			return (info.status);
	}
	argv_cmd = strtow(info.args, " ");
	if (argv_cmd != NULL)
	{
		info.argv = argv_cmd;
		fork_cmd(&info);
		free(argv_cmd);
	}
	free_info(&info, 1);
	return (0);
}
