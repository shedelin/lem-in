/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 20:31:41 by shedelin          #+#    #+#             */
/*   Updated: 2014/02/18 20:31:42 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define EMPTY		0
# define FULL		1
# define START		2
# define END		3
# define NONE		-1

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_room
{
	char			*name;
	char			property;
	int				state;
	int				x;
	int				y;
	struct s_room	*next;
}					t_room;

typedef struct		s_pipe
{
	t_room			*room1;
	t_room			*room2;
	char			*property;
	struct s_pipe	*next;
}					t_pipe;

typedef struct		s_ant
{
	int				num;
	t_room			*pos;
	t_room			*previous;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_nest
{
	int				nb_ants;
	t_room			*rooms;
	t_pipe			*pipes;
	t_ant			*ants;
	t_coord			*coords;
}					t_nest;

t_nest		*lm_get_nest(void);
int			lm_test_ants(char *line);
t_ant		*lm_init_ants(int nb_ants, t_nest *nest);
int			lm_check_rules(t_nest *nest);
int			lm_check_coord(t_nest *nest, t_coord *coord);
int			lm_test_room(t_nest *nest, char *line);
void		lm_add_room(t_nest *nest, char *line, char **property);
int			lm_test_pipe(t_room *rooms, char *line);
void		lm_add_pipe(t_nest *nest, char *line, char **property);
int			lm_check(t_nest *nest);
int			lm_move_ants(t_ant *ants, t_pipe *pipes);
void		lm_print(int num, char *name);
int			lm_strisint(char *str, int len);
void		lm_error(int error);

#endif /* !LEM_IN_H */
