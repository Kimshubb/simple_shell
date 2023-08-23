/**
 * hsh - reads user input, process it and execute commands separated by ;
 * @info - pointer to info_t struct 
 * @environ - pointer to a pointer
 * returns 0 if success 1 if a failure
 */
int hsh(info_t *info, char **environ)
{
	int builtin_result;
	info_t cmd_info;
	int i = 0;
	int logical_operator;

	while (1)
	{
		_puts("$");
		if (get_input(info) == -1)
		{
			if (isatty(STDIN_FILENO))
				_puts("\n");
			break;
		}
		builtin_result = find_builtin(info);
		if (builtin_result != -1)
		{
			if (builtin_result == 1)
				continue;
			else
				return (info->status);
		}
		char **cmds = strtow(info->args, ";");
		if (cmds != NULL)
		{
			while (cmds[i] != NULL)
			{
				cmd_info = *info;
				cmd_info.arg = cmds[i];
				cmd_info.argv = strtow(cmd_info.arg, " ");
				if (cmd_info.argv != NULL)
				{
					logical_operator = is_chain(&cmd_info, "&&||", NULL);
					if (logical_operator = CMD_NORM || logical_operator == CMD_OR)
					{
						fork_cmd(&cmd_info);
					}
					else if (logical_operator ==CMD_AND)
					{
						if (info->status == 0)
							fork_cmd(&cmd_info);
					}
					free(cmd_info.argv);
				}
				i++;
			}
			free(cmds);
		}
		free_info(info, 1);
	}
	return 0;
}

/**
 * fork_cmd - forks a child status to execute a command 
 * @info - pointer to info_t struct containing command info
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return;
	}
	if (child_pid == 0)
	{
		/*execute cmd using execve if it fails print error mess and exit with error number*/
		execve(info->path, info->argv, info->environ);
		perror("execve");
	}
	else
	{
		/*wait for child process to exit and get its exit status*/
		waitpid(child_pid, &status, 0);
		info->status = WEEXITSATUS(status);
	}
}
