#ifndef LIBFT_H
# define LIBFT_H

	#include <stddef.h>

	int		ft_isalpha(int c);
	int		ft_isdigit(int c);
	int 	ft_isalnum(int c);
	int		ft_isascii(int c);
	int		ft_isprint(int c);
	int		ft_strlen(const char *s);
	void	*ft_memset(void *b, int c, int len);
	void	ft_bzero(void *s, size_t n);
	char	*ft_itoa(int n);

#endif
