/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_MALLOC_H
# define MALLOC_MALLOC_H

# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <sys/mman.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <string.h>
# include <unistd.h>

# include "libft/includes/libft.h"
# define N 1024
# define M 102400
# define TINY 1
# define HEX_STR "0123456789abcdef"
# define HEX_LEN sizeof(void *) * 2 + 3
# define TINY_STR "TINY"
# define SMALL_STR "SMALL"
# define LARGE_STR "LARGE"
# define SMALL (N + 1)
# define LARGE (M + 1)
# define P_SIZE (size_t) sysconf(_SC_PAGESIZE)
# define SECTOR_SIZE 4
# define N_ALLOC ((N) * SECTOR_SIZE / P_SIZE * P_SIZE)
# define M_ALLOC ((M) * SECTOR_SIZE / P_SIZE * P_SIZE)
# define L1 ((int[]){RLIMIT_CORE, RLIMIT_CPU, RLIMIT_DATA, RLIMIT_FSIZE})
# define L2 ((char *[]){"CORE", "CPU", "DATA", "FSIZE"})
# define L3 ((int[]){RLIMIT_MEMLOCK, RLIMIT_NOFILE, RLIMIT_NPROC, RLIMIT_RSS})
# define L4 ((char *[]){"MEMLOCK", "NOFILE", "NPROC", "RSS"})
# define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
# define GET_SECT_DIV_LEN(X) (X == T_TINY ? N : M)
# define OFFSETOF(type, member) ((size_t) &((type *)0)->member)
# define OFST_OF(t, m) OFFSETOF(t, m)
# define TYPE_M(t,m) const typeof(((t*)0)->m)
# define CONTAINER_OF(p,t,m)({TYPE_M(t,m)*mp=(p);(t*)((char*)mp-OFST_OF(t,m));})
# define T_MALLOC_Z_STORAGE_SIZE 30
# define SIZE_TMT sizeof(t_malloc_t)
# define SIZE_TMZ sizeof(t_malloc_z)
# define CLEAR_MT_MZ_ON_FREE 0

typedef enum			e_malloc_type
{
	T_TINY,
	T_SMALL,
	T_LARGE
}						t_malloc_type;

typedef struct			s_malloc_t
{
	size_t				size;
	void				*ptr;
	struct s_malloc_t	*back;
	struct s_malloc_t	*front;
	t_malloc_type		type;
	int					i;
	void				*ptr_sect[SECTOR_SIZE];
	int					ptr_slot[SECTOR_SIZE];
	int					ptr_sizes[SECTOR_SIZE];
	time_t				ptr_times[SECTOR_SIZE];
}						t_malloc_t;

typedef struct			s_malloc_z
{
	t_malloc_t			storage[T_MALLOC_Z_STORAGE_SIZE];
	struct s_malloc_z	*prev;
	struct s_malloc_z	*next;
}						t_malloc_z;

typedef struct			s_malloc_mgr
{
	int					init;
	int					i;
	t_malloc_type		cur_size;
	char				*a_large;
	t_malloc_t			*list_tiny;
	t_malloc_t			*list_small;
	t_malloc_t			*list_large;
	t_malloc_z			*list_zone;
	t_malloc_z			*cur_zone;
	t_malloc_t			*cur_tmalloc;
	void				*cur_ptr;
	char				ptr_str_1[HEX_LEN];
	char				ptr_str_2[HEX_LEN];
}						t_malloc_mgr;

t_malloc_mgr			g_malloc;

void					free(void *ptr);
void					*malloc(size_t size);
t_malloc_type			get_malloc_type(size_t size);
void					*realloc(void *ptr, size_t size);
void					realloc_move_back_zone(void *ptr, t_malloc_t *cur);

void					show_alloc_mem(void);
void					show_alloc_mem_large(int extra);
void					show_alloc_mem_ex(void);
void					print_tree_t_malloc(t_malloc_t **root, t_malloc_type t,
						int in_zone, int extra);

int						init_malloc(void);
void					*malloc_error();
int						check_nmap(void *ptr, size_t size, char *error);
char					*ptr_addr_to_str(void *ptr_address, int print, char *
						store);
void					*mmap_anon(size_t size, char *fail_string);
void					*mmap_anon_shared(size_t size, char *fail_string);
void					*malloc_tiny(size_t size);
void					*malloc_small(size_t size);
void					*malloc_large(size_t size);
void					*malloc_tree(t_malloc_t **root, t_malloc_t *new_m);
int						delete_t_malloc(t_malloc_t *themalloc);

void					print_rlimits(void);
t_malloc_t				*create_t_malloc(size_t size, t_malloc_type type);

int						t_malloc_check_gap(t_malloc_t *current,
											t_malloc_t *front, size_t size);
int						ptr_inside(void *array, size_t size,
									void *other_pointer);
int						find_tiny_zone(t_malloc_t *themalloc);

void					insert_tree_t_malloc(t_malloc_t **root,
						t_malloc_t *new_m, int (*cmpf)(void *, void *));
t_malloc_t				*delete_tree_t_malloc(t_malloc_t **root, void *ptr,
										int (*cmpf)(void *, void *));
t_malloc_t				*resolve_tree_t_malloc(t_malloc_t **root);
t_malloc_t				*findmin_tree_t_malloc(t_malloc_t *root);
void					count_zone_ptr_alloc(t_malloc_z **root, t_malloc_type t,
											int *c);

void					*insert_tree_zone_slot(size_t size, t_malloc_t **root,
									size_t block_size);
t_malloc_t				*delete_tree_t_malloc_zone(t_malloc_t **root, void *ptr,
											int (*cmpf)(void *, void *));
void					*check_tree_zone_slot(size_t size, t_malloc_t **root,
									size_t block_size, int i);
t_malloc_t				*resolve_tree_t_malloc_zone(t_malloc_t **root,
													void *ptr);

int						ptr_compare(void *p1, void *p2);

t_malloc_t				*alloc_t_malloc_zone(void);
t_malloc_t				*search_t_malloc_z(t_malloc_z **root);
t_malloc_t				*ins_get_t_t_malloc_z(t_malloc_z **root,
							t_malloc_z *new_m, int (*cmpf)(void *, void *));
t_malloc_z				*findmin_tree_t_malloc_z(t_malloc_z *root);
t_malloc_z				*delete_t_malloc_z(t_malloc_z **root, t_malloc_t *ptr,
									int (*cmpf)(void *, void *));
#endif
