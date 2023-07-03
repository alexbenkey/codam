/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   all.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:57:55 by jbax          #+#    #+#                 */
/*   Updated: 2023/05/09 16:40:03 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H
/* INCLUDES */
# include <termios.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "../libft/libft.h"
# include "structures.h"
# include "builtins_data_struct.h"
# define _POSIX_SOURCE
# include <sys/wait.h>
# include <sys/types.h>

/* NOT OURS BUT MUST BE DECLARED*/
void		rl_clear_history(void);
void		rl_replace_line(const char *text, int clear_undo);
/* DEFINE'S */
# define EMPTY 1
# define FULL 0
/* 1 Global */
int	g_exit_code;
/* OUR FUNCTIONS*/
/**
 * @brief jordan
 * Set the signal parent object
 * set the use of ctr + c to read from newline
 */
void		set_signal_parrent(void);
/**
 * @brief jordan
 * sets the signals to do nothing
 */
void		block_signal(void);
void		reset_signal(void);
/**
 * @brief jordan
 * use the readline and handels eof and history
 * @return char* line read
 */
char		*read_the_line(void);
char		*first_read_line(void);
/* builtins */
int			what_cmd(t_tokens *bigdata, t_super *super);
void		ft_export(t_super *super, char **args, int output_fd);
void		ft_unset(t_super *super, char **arg);
void		ft_exit_builtin(char **arg);
void		ft_pwd(int output_fd);
int			ft_change_dir(char **args, t_super *super);
void		ft_echo(char **arg, int output_fd);
void		ft_put_env(t_super *super, int fd);
void		ft_othercmd(char **arg, t_super *super, int ispipe, int fd);

int			print_all_tokens(t_tokens *list);
char		**copy_env(char **env);

/* splits the string in a malloc'ed copy of the content 
of the env string */
char		*ft_env_content(char *env);
/* splits the string in a malloc'ed copy of the variable name 
of the env string */
char		*ft_env_name(char *env);
/* gives the env array index of the exact match of var names 
-1 if there isn't */
int			ft_env_index(char **env, char *var);
char		*singlearg(char *arg, int *index);
/* pointer is char after $.
returns (malloct) content of var in string of pointer, 
pointer points to the first char of the var
retuns empty string if var has no content but is still malloct
returns 0 if no match can be found. */
char		*ft_getvar(char *ptr, char **env);
char		*ft_replacevar(char *head, int index, char **env);
/*returns a list of matching files/dir */
t_list		*get_wildcard(char *wild);
void		exit_errbug(char *error, char *debug);
int			tmpfileswitch(char **line);
int			is_empty(char *line);
/*is_file treu >= 1*/
char		**arr_expander(char **arr, char **env, int is_file);
/* eoh wil be freed and is expected to only have the rellevand data
so use substring
eoh = end of heredoc (the string that ends the heredoc)
tmpfindex wil start trying to creat a temp file 
that ends with that number, use 1 for normal behavior
retuns malloced pointer of the tmp file name */
char		*heredoc(char *eoh, int tmpfindex);
/* set a fd in append mode 0 if error*/
int			setfd_append(char *filename);
/* set a fd in write mode 0 if error*/
int			setfd_write(char *filename);
/* sets a fd in read mode 0 if error*/
int			setfd_read(char *filename);

// @alex functions 
// cutting_tools.c:
int			cut_to_files(t_tokens *list, int i, int val);
int			cut_to_args(t_tokens *list, int i);
int			cut_off_file_symbol(t_tokens *list, int i);

// fill_node.c
void		fill_node(t_tokens *top, char *input, int start, int end);
t_tokens	*get_node(int start, int *arr, char *input, t_tokens *tmp);
void		free_list(t_tokens *list);

// heredoc_wrap.c
t_tokens	*heredoc_func(t_tokens *list, t_tokens *tmp);

// internal_splitters.c
void		split_on_flags(t_tokens *list);

// libft_variations.c
int			ar_len(int *arr);
int			*ft_arrdup(int *source, int len);
int			*ms_arrdup(int *arr, int len);
int			*ft_subarr(int *arr, size_t start, size_t len);

// main_parser.c
t_tokens	*main_loop(char *input);
int			*tokanize(char *input, int *arr);
t_tokens	*primary_split(char *input, int *arr, t_tokens *list);

// memory_tools.c
void		*ms_calloc(size_t nmemb, size_t size);
void		free_arr_null(char ***ptr);
void		free_str_null(char **ptr);
void		free_some_stuff(char **args);

//mini_tokanizer.c
void		attach_token(t_tokens *list, int i);
void		update_mini_tok(t_tokens *list, int i, int val);

//parse_cleaner.c
void		trim_spaces(t_tokens *list);
char		*mini_space_trimmer(char *string);
int			check_empty_delims(char *input, int *arr);

//parse_operators.c
int			*check_operators(char *input, int *arr);

//parse_quotes.c
int			label_quotess(char *str, int *arr);
int			*label_quotes(char *input, int *arr, int data);
char		get_quote_type(int type);

//parse_splitter.c
t_tokens	*split_on_amps(t_tokens *list);
t_tokens	*split_on_or(t_tokens *list);
t_tokens	*split_on_pipes(t_tokens *list);

//parsing_list.c
int			get_node_length(int *arr, int start);
t_tokens	*setup_new_node(t_tokens *top);
void		ms_lstadd_back(t_tokens **lst, t_tokens *new);
t_tokens	*lst_end(t_tokens *top);
t_tokens	*new_node(char *input);

//parsing_tools.c
int			*calloc_array(int len, int type);
int			*make_arr(int len);
int			*label_spaces(char *input, int *arr);
void		print_array(int *arr);
int			print_all_tokens(t_tokens *list);

//seeking_tools.c
int			find_pipe(int *arr, int max, int position);
/**
 * finds the first instance of a specified token in the array. 
 * returns -1 if there is no instance of the token
 */
int			find_tokens(int val, t_tokens *list);
t_tokens	*find_files(t_tokens *list);
t_tokens	*find_args(t_tokens *list);

//simple_tools.c
int			*label_vals(int start, int end, int *arr, int sig);
t_tokens	*check_for_commands(t_tokens *list);
int			count_args(char **args);
int			content_before(char *input, int i);
int			content_after(char *input, int i);

//split_not_quote.c
char		**split_quote(char const *s, char c);

//splitting_tools.c
t_tokens	*split_into_list(char *input, int *arr, t_tokens *list);
void		fill_node_split(t_tokens	*node, int split_point, int noc);
/**
 * splits the content of a node at the position given as 'split_points' and 
 * places the righthand part of the string in a new node in the linked list. 
 * noc determines the amount of characters to be splitted on 
 * (i.e. for '&&' noc would be 2)
 * if node_nr is given, it determines the node in which the string 
 * should be split
 */
void		split_to_node(t_tokens *node, int split_point, int noc);

//syntax_chcker_main.c
int			syntax_checker(char *input, int *arr);

//syntax_checker_tools.c
int			check_or(char *input, int *arr, int i);
int			check_ampersand(char *input, int *arr, int i);
int			check_pipes(char *input, int *arr, int i);
int			check_l_arrow(char *input, int *arr, int i);
int			check_r_arrow(char *input, int *arr, int i);

//syntax_checkers.c
int			pipe_checker(char *input, int i);
int			or_error_checker(char *input, int i);
int			amp_checker(char *input, int i);
int			red_op_checker(char *input, int i);	

//syntax_messaging.c
void		syntax_err_message(int val);
void		write_relevant_message(char *input, int i);

//tokanize_tools.c
int			*command_after_pipe(char *input, int *arr);
int			*check_commands(char *input, int *arr);
int			*make_red_op(char *input, int *arr, int i);
int			*make_red_ip(char *input, int *arr, int i);

//transpose.c
void		transpose_file(t_tokens *list, int length, int start, int val);
void		transpose_arg(t_tokens *list, int length, int start);
void		add_in_node_file(t_tokens *list, int length, int i);
void		add_in_node_arg(t_tokens *list, int length, int i);

#endif
