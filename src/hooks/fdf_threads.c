#include "fdf.h"
#include <math.h>

static void	fdf_clean_vertex(t_vertex *vertex)
{
	vertex->val[1][0] = vertex->val[0][0];
	vertex->val[1][1] = vertex->val[0][1];
	vertex->val[1][2] = vertex->val[0][2];
}

static void	fdf_rotation_vertex(t_main *main, t_vertex *vertex)
{
	double	temp_x;
	double	temp_y;

	if (main->event.x_angle)
	{
		temp_y = vertex->val[1][1];
		vertex->val[1][1] = 0 * vertex->val[1][0] + \
			cos(main->event.x_angle * M_PI / 180) * vertex->val[1][1] - \
				sin(main->event.x_angle * M_PI / 180) * vertex->val[1][2];
		vertex->val[1][2] = 0 * vertex->val[1][0] + \
			sin(main->event.x_angle * M_PI / 180) * temp_y + \
				cos(main->event.x_angle * M_PI / 180) * vertex->val[1][2];
	}
	if (main->event.z_angle)
	{
		temp_x = vertex->val[1][0];
		vertex->val[1][0] = cos(main->event.z_angle * M_PI / 180) \
			* vertex->val[1][0] + sin(main->event.z_angle * M_PI / 180) \
				* vertex->val[1][2];
		vertex->val[1][2] = cos(main->event.z_angle * M_PI / 180) \
			* vertex->val[1][2] - sin(main->event.z_angle * M_PI / 180) \
				* temp_x;
	}
}

static void	fdf_isometric_vertex(t_main *main, t_vertex *vertex)
{
	double	angle1;
	double	angle2;
	double	ax;

	angle1 = M_PI / 4;
	angle2 = asin(tan(M_PI / 6));
	if (main->event.viewmode == 0)
	{
		ax = vertex->val[1][0];
		vertex->val[1][0] = cos(angle1) * vertex->val[1][0] \
			- sin(angle1) * vertex->val[1][2];
		vertex->val[1][2] = sin(angle1) * ax + cos(angle1) * vertex->val[1][2];
		vertex->val[1][1] = cos(angle2) * vertex->val[1][1] \
			+ sin(angle2) * vertex->val[1][2];
		ax = vertex->val[1][1];
		vertex->val[1][2] = cos(angle2) * vertex->val[1][2] - sin(angle2) * ax;
	}
}

static void	fdf_offsetting(t_main *main, t_vertex *vertex)
{
	vertex->val[1][0] = fdf_offsetx(main, fdf_scaling(main, vertex->val[1][0]));
	vertex->val[1][1] = fdf_offsety(main, fdf_scaling(main, vertex->val[1][1]));
}

void *fdf_thread_exec(void *ptr)
{
    struct arg_struct *args = ptr;
    int y = args->min;
    for (; y < args->max; y++)
    {
	    for (int x = 0; x < args->main->minfo.width; x++)
	    {
	    	fdf_clean_vertex(&args->main->vertices[y][x]);
	    	args->main->vertices[y][x].val[1][2] =  args->main->vertices[y][x].val[1][2] * args->main->event.z_mod / 100;
	    	fdf_rotation_vertex(args->main, &args->main->vertices[y][x]);
	    	fdf_isometric_vertex(args->main, &args->main->vertices[y][x]);
	    	fdf_offsetting(args->main, &args->main->vertices[y][x]);
	    	fdf_put_pixel(args->main, &args->main->vertices[y][x]);
	    }
    }
    pthread_exit(NULL);
    return  NULL;
}

void fdf_threads_init(t_main *main, void *(*function)(void *))
{
    int range = (main->minfo.height) / MAX_THREAD;
    int i = 0;
    struct arg_struct args[MAX_THREAD];
    if (!range)
    {
        args[i].main = main;
        args[i].min = 0;
        args[i].max = main->minfo.height;
        pthread_create(&main->thread_array[0], NULL, function, &args[i]);
        pthread_join(main->thread_array[0], NULL);
        return ;
    }
    for (; i < MAX_THREAD - 1; i++)
    {
        args[i].main = main;
        args[i].min = range * i;
        args[i].max = range * (i + 1);
        pthread_create(&main->thread_array[i], NULL, function, &args[i]);
    }
    args[i].main = main;
    args[i].min = range * i;
    args[i].max = main->minfo.height;
    pthread_create(&main->thread_array[i], NULL, function, &args[i]);
    for (int j = 0; j < MAX_THREAD; j++)
        pthread_join(main->thread_array[j], NULL);
}
