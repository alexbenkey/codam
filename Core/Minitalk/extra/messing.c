#include <limits.h>
#include <stdio.h>

int main (void)
{
	printf("max val: %lu\n", SIZE_T_MAX);
}

// #include "./../minitalk.h"
// #include <errno.h>
// #include <signal.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>

// static siginfo_t sig_info;
// static volatile sig_atomic_t sig_num;
// static void *sig_ctxt;

// static void	catcher(int signum, siginfo_t *info, void *vp)
// {
// 	sig_num		= signum;
//     sig_info	= *info;
//     sig_ctxt	= vp;
// }

// static void	set_handler(int signum)
// {
// 	struct sigaction	sa;

// 	sa.sa_flags = SA_SIGINFO;
// 	sa.sa_sigaction = catcher;
// 	sigemptyset(&sa.sa_mask);

//     if (sigaction(signum, &sa, 0) != 0)
//     {
//         int errnum = errno;
//         printf(2 , "Failed to set signal handler (%d: %s)\n", errnum, strerror(errnum));
//         exit(1);
//     }
// }

// static void prt_interrupt(FILE *fp)
// {
//     if (sig_num != 0)
//     {
//         printf(fp, "Signal %d from PID %d\n", sig_info.si_signo, (int)sig_info.si_pid);
//         sig_num = 0;
//     }
// }

// int main(void)
// {
//     set_handler(SIGINT);
//     pause();
//     prt_interrupt(2);
//     return(0);
// }

// int check_block(char type, int *arg);

// #include <stdarg.h>
// #include <unistd.h>
// #include <stdio.h>

// int	ft_printf(char *string, ...)
// {
// 	va_list arg;
// 	int 	i; 
// 	int 	j;

// 	va_start(arg, string);
// 	i = 0;
// 	j = 0;
// 	while(string[i])
// 	{
// 		if(string[i] == '%')
// 		{
// 			string++;
// 			if (string[i] == '%')
// 			{
// 				write(1, "%", 1);
// 				//j += 1;
// 			}
// 			else
// 				j += (check_block(string[i], va_arg(arg, int *)) - 1);
// 		}
// 		else
// 			write(1, &string[i], 1);
// 		i++;
// 	}
// 	va_end(arg);
// 	return (i + j);
// }

// int check_block(char type, int *arg)
// {
// 	int i;

// 	i = 0;
// 	if (type == 'c')
// 	{
// 		write(1, &arg, 1);
// 		i++;
// 	}
// 	else
// 		return (0);
// 	return (i);
// }

// int main(void)
// {
// 	int i;

// 	i = ft_printf("hello world %c %c %c", 'w', 'o', 'w');
// 	printf("int i: %d", i);
// }


// sdxp