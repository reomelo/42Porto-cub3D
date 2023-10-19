/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:28:58 by riolivei-         #+#    #+#             */
/*   Updated: 2023/10/19 17:44:47 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		((char *)s)[i] = '\0';
		i++;
		n--;
	}
}

/* 
int main()
{
    char s[] = "AAAAAAAAAAAAAA";
    char b[] = "AAAAAAAAAAAAAA";
    
    ft_bzero(s + 2, 4);
    puts(s);
    
    bzero(b + 2, 4);
    puts(b);
} */