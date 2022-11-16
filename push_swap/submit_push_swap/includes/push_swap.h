/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 01:06:57 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/16 19:34:52 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# define FALSE	0
# define TRUE	1

# define SA		00
# define SB		01
# define SSSA	02
# define SSSB	03

# define PA		10
# define PB		11

# define RA		20
# define RB		21
# define RRRA	22
# define RRRB	23

# define RRA	30
# define RRB	31
# define RRRRA	32
# define RRRRB	33

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
}	t_stack;

typedef struct s_info
{
	t_stack	*a;
	t_stack	*b;
	int		*array;
}	t_info;

int		error_exit(int type);
int		make_pos(int a, int b, int a_idx, int b_idx);
void	check_dup(t_info *info, int arr_size);
int		ft_isspace(char c);
int		split_size(char **parsed_str);
void	free_split(char **parsed_str);
int		get_input_size(int argc, char **argv);
void	arr_to_stack(t_info *info, int *arr, int size);
int		ft_atoil(const char *str, int i);
void	set_str_array(int *array, int *arr_idx, char **str);
int		*make_array(int argc, char **argv, int size);
int		is_empty(t_stack *stack);
int		get_min_stack(t_stack *stack);
int		get_max_stack(t_stack *stack);
void	free_stack(t_stack *stack);
int		get_a_idx(int num, t_info *info);
int		set_min(t_info *info);
int		set_mid(int num, t_info *info);
int		set_max(t_info *info);
void	set_pivot_divide(t_info *info);
void	check_sort(int *array, int size, int idx);
void	sort_all(t_info *info);
void	sort_elem(t_info *info);
void	last_sort(t_info *info);
void	sort_triple(t_info *info);
void	rotate_many(t_info *info, int *a, int *b);
void	rotate_one(t_info *info, int idx, int flag);
void	divide_triple(t_info *info, int piv1, int piv2);
void	get_min_rtcnt(t_info *info, int *a, int *b);
void	cmd_sab(t_info *info, int flag);
void	cmd_ss(t_info *info);
void	cmd_pab(t_info *info, int flag);
void	cmd_rab(t_info *info, int flag);
void	cmd_rr(t_info *info);
void	cmd_rrab(t_info *info, int flag);
void	cmd_rrr(t_info *info);
void	new_stack(t_stack *stack);
int		pop(t_stack *stack);
int		pop_bot(t_stack *stack);
void	push(t_stack *stack, int elem);
void	push_bot(t_stack *stack, int elem);

#endif
