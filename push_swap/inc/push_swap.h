/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 07:23:02 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 14:01:10 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define PUSHSWAP_MSG 0

typedef struct s_two_stack
{
	t_stack	*a;
	t_stack	*b;
	int		n_ra;
	int		n_rb;
	int		n_rra;
	int		n_rrb;
}			t_two;

t_stack	*parse(int ac, char **av);
void	smallsort(t_two *s, int size);
void	smart_insort(t_two *s, int len);

/**		aux_display.c */
void	print_op(char *operation);
void	show(t_two *s);
void	summary_check(t_two *s, int ts);

/**		aux_errors.c */
void	*error_null(char *msg);
void	*error_null_free_stack(t_stack *p, char *msg);
void	error_exit(char *msg);

/**		aux_operations_a.c */
void	sa(t_two *s);
void	pa(int n, t_two *s);
void	ra(int n, t_two *s);
void	rra(int n, t_two *s);

/**		aux_operations_b.c */
void	sb(t_two *s);
void	pb(int n, t_two *s);
void	rb(int n, t_two *s);
void	rrb(int n, t_two *s);

/**		aux_operations_double.c */
void	ss(t_two *s);
void	rr(int n, t_two *s);
void	rrr(int n, t_two *s);
void	sa_ra(t_two *s);
void	ra_sa(t_two *s);

/**		aux_operations_smart.c */
void	uptop_a(t_two *s, int pos);
void	uptop_b(t_two *s, int pos);
void	count_uptop_a(t_two *s, int pos);
void	count_uptop_b(t_two *s, int pos);
void	do_rotations(t_two *s);

/**		aux_shortcuts.c */
int		top(t_stack *s);
int		top2(t_stack *s);
int		top3(t_stack *s);
int		len(t_stack *s);

/*
	void	merge_v0(t_two *s);		//  1.450 - 32.000
	void	merge_v1(t_two *s);		//  978 - 17.000
	void	merge_v2(t_two *s);		//	x
	void	range_sorter(t_two *s);	//	8.000 - 210.000 	
	void	merge_v3(t_two *s);		//	2.500 - 60.000
	void	extra_big_fusion_strike_improved_v42(t_two *s);	//	x
	void	insort(t_two *s, int len); 			// 1300 - 16.000
	int		quicksort_a(t_two *s, int len);		// 1200 - 5.200
	void	simple_part(t_two *s);				// 720 - 5.300
	void	smart_insort_v1(t_two *s, int len);	// 650 - 5.100 
	void	smart_insort_v2(t_two *s, int len);	// 622 - 4.870 
	void	smart_insort_v3(t_two *s, int size);
	x20000 test:100  mean 595  min 504  max 699 
	x3000 test:500  mean 4535  min 4186  max 4904 
*/

#endif /* PUSH_SWAP_H */
