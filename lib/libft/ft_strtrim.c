/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:11:50 by riolivei-         #+#    #+#             */
/*   Updated: 2023/10/19 17:47:30 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_str;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_strrchr(set, s1[end - 1]) && end > start)
		end--;
	trim_str = (char *)malloc((end - start + 1) * sizeof(char));
	if (trim_str)
		ft_strlcpy(trim_str, &s1[start], end - start + 1);
	else
		return (0);
	return (trim_str);
}

//char *trim(char *s1)
//{
//    char *ret = ft_calloc(ft_strlen(s1), 1);
//    int i = 0;
//    int y = ft_strlen(s1) - 1;
//    int k = 0;
//    while (i < (int)ft_strlen(s1) && (s1[i] == ' ' || s1[i] == '\t'))
//        i++;
//
//    if(s1[ft_strlen(s1) -1] == '\n')
//        y--;
//    while ((s1[y] == ' ' || s1[y] == '\t'))
//		y--;
//	while (i < y)
//		ret[k++] = s1[i++];
//    return (ret);
//}
/*int main()
{
    char *trim_str = ft_strtrim("abqbc", "abc");
    puts(trim_str);
}*/
