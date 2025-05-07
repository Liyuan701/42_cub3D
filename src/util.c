#include "../include/cub3D.h"

void error_msg(char *str, int exit_status)
{
	perror(str);
	exit(exit_status);
}