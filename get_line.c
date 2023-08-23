#include "shell.h"
/**
 * _getline - functions that scans the buffer for newline chars to extract lines
 * 
 *
 */
ssize_t _getline(info_t *info) 
{
	static char input_buffer[INPUT_BUF_SIZE];
    	static size_t input_len = 0;
    	static size_t input_pos = 0;

    	ssize_t bytes_read = 0;
   	ssize_t total_read = 0;
    	char *line = NULL;

    	while (1) 
	{
        /*If the input buffer is empty, read more data*/
        	if (input_pos == input_len) 
		{
            		bytes_read = read(STDIN_FILENO, input_buffer, INPUT_BUF_SIZE);
            		if (bytes_read <= 0) 
			{
                		return -1; 
            		}
            		input_len = bytes_read;
            		input_pos = 0;
        	}
        /*Search for newline character in the buffer*/
        	while (input_pos < input_len && input_buffer[input_pos] != '\n') 
		{
            		input_pos++;
        	}
        /*If newline character found, extract the line*/
        	if (input_pos < input_len && input_buffer[input_pos] == '\n') 
		{
            		input_buffer[input_pos] = '\0'; /*Replace newline with null terminator*/
            		line = &input_buffer[input_pos - bytes_read]; /*Set line to start of buffer*/
            		input_pos++;
	       	/* Move past newline character*/
            		break;
        	}
        /* Move remaining data to the beginning of the buffer*/
        	if (input_pos == input_len) 
		{
            		memmove(input_buffer, &input_buffer[input_pos - bytes_read], bytes_read);
            		input_pos = bytes_read;
            		input_len = bytes_read;
        	}
        	total_read += bytes_read;
    	}

    /*Update the arg field in the info structure*/
    info->arg = line;

    return strlen(line);
}

/**
 * get_input - Read user input from stdin and store it in info struct
 * @info pointer to info_t struct where iput is stored
 * returns -1 if theres an error or end of input
 * returns 0 if success
 */
ssize_t get_input(info_t *info)
{
	ssize_t bytes_read;
	ssize_t len = 0;
	char *line = NULL;

	bytes_read = _getline(info, &line, &len);

	if (bytes_read == -1 || bytes_read == 0)
	{

		if (line)
			free(line);
		return -1;
	}
	info->arg = line;
	return 0;
}
