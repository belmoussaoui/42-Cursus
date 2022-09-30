#import <Cocoa/Cocoa.h>

int	mac_mouse_hide(void)
{
	[NSCursor hide];
	return (0);
}

int	mac_mouse_move(int x, int y)
{
	CGPoint	point;

	point.x = x;
	point.y = y;
	CGWarpMouseCursorPosition(point);
	CGAssociateMouseAndMouseCursorPosition(true);
	return (0);
}

int	mlx_mouse_move(void *mlx, void *win, int x, int y) {(void) mlx; (void) win; (void) (x + y); return 0;}
int	mlx_mouse_get_pos(void *mlx, void *win, int *x, int *y) {(void) mlx; (void) win; (void) (*x + *y); return 0;}
int	mlx_mouse_hide(void *mlx, void *win) {(void) mlx; (void) win; return 0;}