/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 13:58:05 by hjeannin          #+#    #+#             */
/*   Updated: 2016/01/06 16:49:52 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# define RES_X			1920
# define RES_Y			1080

# define TITLE			"scop"

# define K_ESC			53
# define K_LEFT			123
# define K_RIGHT		124
# define K_DOWN			125
# define K_UP			126
# define K_PAGE_UP		116
# define K_PAGE_DOWN	121
# define K_A			0
# define K_D			2
# define K_Q			12
# define K_E			14
# define K_W			13
# define K_S			1
# define K_T			17
# define K_P			35
# define K_PLUS			24
# define K_MOINS		27

# define SLASH			42
# define NO_SLASH		43

# include <OpenGL/gl3.h>

typedef struct			s_bmp_info
{
	unsigned char		header[54];
	unsigned int		data_pos;
	unsigned int		width;
	unsigned int		height;
	unsigned int		image_size;
}						t_bmp_info;

typedef struct			s_data
{
	void				*init;
	void				*win;
	char				*obj_file;
	char				*texture_file;
	int					parsing_mode;
	GLfloat				color;
	t_bmp_info			b;
	GLuint				texture_id;
	unsigned char		*bmp_data;
	GLfloat				translate[3];
	GLfloat				rot_y;
	GLfloat				scale;
	GLfloat				auto_rot_y;
	GLuint				texture_toggle_status;
	GLfloat				texture_toggle;
	GLuint				texture_toggle_loc;
	GLfloat				proj_matrix[16];
	GLfloat				view_matrix[16];
	GLfloat				trans_matrix[16];
	GLfloat				rot_y_matrix[16];
	GLfloat				scale_matrix[16];
	GLuint				vao;
	GLuint				vbos[2];
	GLuint				vertex_shader;
	GLuint				geometry_shader;
	GLuint				fragment_shader;
	GLuint				program;
	GLuint				position_loc;
	GLuint				proj_loc;
	GLuint				view_loc;
	GLuint				trans_loc;
	GLuint				rot_y_loc;
	GLuint				scale_loc;
	GLuint				color_loc;
	int					vertices_size;
	int					vertices_num_elem;
	GLfloat				*vertices_array;
	GLuint				v_count;
	int					faces_size;
	int					faces_num_elem;
	GLuint				*faces_array;
	GLuint				f_count;
}						t_data;

int						recenter_42(t_data *d);
int						load_bmp(char *filename, t_data *d);

void					auto_rotate(t_data *d);
void					rotate(GLfloat angle, t_data *d);
void					translate(GLfloat magnitude, GLfloat *axe, t_data *d);
void					scale(GLfloat magnitude, t_data *d);

void					get_locations(t_data *d);

void					copy_mat4(GLfloat *in, GLfloat *out);
void					print_mat4(GLfloat *m, char *name);
void					identity_mat4(GLfloat *out);
void					translation_mat4(GLfloat *t, GLfloat *out);
void					rotation_y_mat4(GLfloat angle, GLfloat *out);
void					scale_mat4(GLfloat scale, GLfloat *out);
void					multiply_mat4(GLfloat *a, GLfloat *b, GLfloat *out);

void					set_proj_matrix(GLfloat *proj_matrix, GLfloat fov,
										GLfloat near_cp, GLfloat far_cp);
void					set_view_matrix(t_data *d);
void					set_trans_matrix(t_data *d);
void					set_rot_y_matrix(t_data *d);
void					set_scale_matrix(t_data *d);

int						parse_obj_file(t_data *d);
int						count_needed_array_size(t_data *d, int mode);

GLfloat					*create_float_array(GLuint size);
void					print_float_array(GLfloat *a, GLuint size);
GLuint					*create_uint_array(GLuint size);
void					print_uint_array(GLuint *a, GLuint size);

GLuint					load_shader(GLenum type, char const *file_name);
GLuint					load_hard_shader(GLenum type);
GLuint					compile_shader(GLuint current_shader);
int						init_shaders(t_data *d);

int						init_data(t_data *d);
void					init_int_tab(int *t, int size);

int						init_opengl(t_data *d);
int						draw_img(t_data *d);
int						create_image(t_data *d);
int						print_error(char *msg, int code);
int						check_gl_error(char const *file, int line);

#endif
