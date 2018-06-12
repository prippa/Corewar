#include "visualizer.h"

static void	*thread_function(void *data)
{
	t_arena	*arena;

	arena = (t_arena *)data;
	set_random(arena);
	return (0);
}

void		draw_arena_split(t_arena *arena)
{
	int		start;
	int		offset;
	int		i;
	int		thread_count;
	pthread_t	threads[arena->thread_count];
	pthread_attr_t	threads_attr[arena->thread_count];

	thread_count = arena->thread_count;
	offset = (ARENA_HEIGHT) / thread_count;
	start = 0;
	i = -1;
	while (++i < thread_count)
	{
		arena->start_for_thread = start;
		start += offset;
		arena->end_for_thread = start;
		pthread_attr_init(&(threads_attr[i]));
		pthread_create(&(threads[i]),
						&(threads_attr[i]),
						thread_function,
						(void *)arena);
	}
	i = -1;
	while (++i < arena->thread_count)
		pthread_join(threads[i], NULL);
}