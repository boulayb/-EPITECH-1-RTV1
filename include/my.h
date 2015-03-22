/*
** my.h for rtv1 in /home/boulay_b/Rendu/SE2/MUL/MUL_2014_rtv1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Feb 23 17:24:23 2015 Boulay Arnaud
** Last update Mon Mar  9 23:53:19 2015 Boulay Arnaud
*/

#ifndef	MY_H_
# define MY_H_

enum			e_size
  {
    W_SIZE_X = 1920,
    W_SIZE_Y = 1080,
    I_SIZE_X = 1920,
    I_SIZE_Y = 1080,
  };

enum			e_eye
  {
    EYE_X = -400,
    EYE_Y = 0,
    EYE_Z = 200,
    DIST = 600,
  };

enum			e_color
  {
    PLAN_COL = 0x24A333,
    SPHERE_COL = 0xDF143C,
    CONE_COL = 0x47B3A8,
    CYLINDRE_COL = 0xFFC63E,
    VOID_COL = 0x000000,
    LIGHT_COL = 0xFFFFFF,
  };

enum			e_light
  {
    LIGHT_X = -300,
    LIGHT_Y = 250,
    LIGHT_Z = 200,
  };

enum			e_angle
  {
    ANGLE_X = 0,
    ANGLE_Y = 10,
    ANGLE_Z = 0,
  };

enum			e_lim
  {
    CYLINDRE_LIM = 100,
    CONE_LIM = 100,
    SPHERE_LIM = 100,
  };

enum			e_cone
  {
    CONE_X = (EYE_X - 100),
    CONE_Y = (EYE_Y - 350),
    CONE_Z = (EYE_Z - 0),
    CONE_R = 60,
  };

enum			e_cylindre
  {
    CYLINDRE_X = (EYE_X - 100),
    CYLINDRE_Y = (EYE_Y + 350),
    CYLINDRE_Z = (EYE_Z + 0),
    CYLINDRE_R = 60,
  };

enum			e_sphere
  {
    SPHERE_X = (EYE_X - 100),
    SPHERE_Y = (EYE_Y + 0),
    SPHERE_Z = (EYE_Z - 75),
    SPHERE_R = 90,
  };

# define ESCAPE		65307
# define LUM		0.9

typedef union		u_color
{
  unsigned int		color;
  unsigned char		bgra[sizeof(unsigned int)];
}			t_color;

typedef	struct		s_mlx
{
  void			*ptr;
  void			*img;
  void			*window;
  char			*data;
  int			bpp;
  int			sizeline;
  int			endian;
}			t_mlx;

typedef struct		s_eye
{
  int			x;
  int			y;
  int			z;
}			t_eye;

typedef struct		s_proj
{
  double		vx;
  double		vy;
  double		vz;
  double		px;
  double		py;
  double		pz;
  double		norme;
  double		k;
}			t_proj;

typedef struct		s_light
{
  double		x;
  double		y;
  double		z;
  double		lx;
  double		ly;
  double		lz;
  double		scalaire;
  double		norme;
  double		cosa;
}			t_light;

typedef struct		s_sphere
{
  double		a;
  double		b;
  double		c;
  double		delta;
  double		lim;
}			t_sphere;

typedef struct		s_cone
{
  double		a;
  double		b;
  double		c;
  double		delta;
  double		lim;
}			t_cone;

typedef struct		s_cylindre
{
  double		a;
  double		b;
  double		c;
  double		delta;
  double		lim;
}			t_cylindre;

typedef struct		s_rt
{
  unsigned int		color;
  struct s_mlx		*mlx;
  struct s_eye		*eye;
  struct s_proj		*proj;
  struct s_sphere	*sphere;
  struct s_cone		*cone;
  struct s_cylindre	*cylindre;
  struct s_light	*light;
}			t_rt;

int			gere_expose(t_mlx *mlx);
int			init_struct(t_rt *rt);
int			init_mlx(t_mlx *mlx);
int			gere_key(int key, t_rt *rt);
int			gere_expose(t_mlx *mlx);
void			my_pixel_put_to_image(t_rt *rt, int x, int y, unsigned int color);
void			my_putchar(char c);
void			my_putstr(char *str);
void			my_exit(t_rt *rt);
void			calc_core(t_rt *rt);
void			sphere(t_rt *rt);
void			cone(t_rt *rt);
void			cylindre(t_rt *rt);
void			plan(t_rt *rt);
void			light_plan(t_rt *rt);
void			light_sphere(t_rt *rt);
void			light_cone(t_rt *rt);
void			light_cylindre(t_rt *rt);
void			shadow_sphere(t_rt *rt);
void			shadow_cylindre(t_rt *rt);
void			shadow_cone(t_rt *rt);
void			rotate_x(t_proj *proj, double angle);
void			rotate_y(t_proj *proj, double angle);
void			rotate_z(t_proj *proj, double angle);

#endif /* !MY_H_ */
