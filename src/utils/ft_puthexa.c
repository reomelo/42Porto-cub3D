/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:39:34 by riolivei-         #+#    #+#             */
/*   Updated: 2023/10/19 17:43:47 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_puthexa(unsigned long n, char *base)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		if (n < 16)
			ft_putchar(base[n]);
		else
		{
			ft_puthexa(n / 16, base);
			ft_puthexa(n % 16, base);
		}
		return (ft_hexlen(n));
	}
}
