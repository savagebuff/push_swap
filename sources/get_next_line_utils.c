#include "../includes/ft_push_swap.h"

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}

void	*ft_memalloc(size_t size)
{
	char	*str;

	if (size == 0)
		return (NULL);
	str = malloc(size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}

char	*ft_strnew(size_t size)
{
	if (size + 1 == 0)
		return (NULL);
	return ((char *)ft_memalloc(size + 1));
}
