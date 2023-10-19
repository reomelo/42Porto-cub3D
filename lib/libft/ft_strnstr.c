/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:19:34 by riolivei-         #+#    #+#             */
/*   Updated: 2023/10/19 17:47:19 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_str(char *big, char *little, size_t i)
{
	int	j;

	j = 0;
	while (little[j])
	{
		if (big[i + j] != little[j])
			return (0);
		j++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*big_str;
	char	*little_str;
	size_t	little_len;
	size_t	i;

	big_str = (char *)big;
	little_str = (char *)little;
	i = 0;
	little_len = ft_strlen(little);
	if (little_str[0] == '\0')
		return (big_str);
	if (big_str[0] == '\0')
		return (NULL);
	while (little_len + i <= len)
	{
		if (big_str[i] == little_str[0])
		{
			if (ft_check_str(big_str, little_str, i))
				return (&big_str[i]);
		}
		i++;
	}
	return (NULL);
}
/*  
int main()
{
    char *ptr;

    ptr = ft_strnstr("", "ola", 10);
    printf("%s", ptr);
} */