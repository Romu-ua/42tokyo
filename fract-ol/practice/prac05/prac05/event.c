#include "fractol.h"



int	key_handler(int keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		close_handler(fractol);
	else if (keysym == XK_Left)
		fractol->shift_x += 0.5;
	else if (keysym == XK_Right)
		fractol->shift_x -= 0.5;
	else if (keysym == XK_Up)
		fractol->shift_y -= 0.5;
	else if (keysym == XK_Down)
		fractol->shift_y += 0.5;
	render(fractol);
	return (0);
}


int	mouse_handler(t_fractol *fractol)
{
	
}

int	close_handler(t_fractol *fractol)
{

}

