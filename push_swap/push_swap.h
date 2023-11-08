#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* typedef	struct t_stk
{

} s_stk; */


void	swap(int *p);
void	push(int *ent, int *out);
void	rotate(int *p);
void	rotinv(int *p);

#endif