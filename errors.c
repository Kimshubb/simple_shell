//should include eputs erratoi and print_error functions -elsewhere though
#include "shell.h"
/**
 * print_error - prints error messages with program name included
 * @program name - program name with error
 * @message - error message
 * return 1 if success
 */
void print_error(const char *program name, const char *message)
{
	_vsnprintf(stderr, "%s: %s\n", program_name, message);
}
~

