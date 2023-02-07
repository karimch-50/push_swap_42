/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:13:37 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:08:39 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static size_t	ft_arg_len(char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_join_args(char *s1, char *s2)
{
	char	*output;
	char	*p_s1;
	char	*p_s2;
	int		i;

	p_s2 = s2;
	while (*p_s2 == ' ')
		p_s2++;
	if (*p_s2 == '\0')
		return (NULL);
	p_s1 = s1;
	output = malloc(ft_arg_len(s1) + ft_arg_len(s2) + 2);
	if (!output)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		output[i++] = *s1++;
	output[i++] = ' ';
	while (s2 && *s2)
		output[i++] = *s2++;
	output[i] = '\0';
	if (p_s1)
		free(p_s1);
	return (output);
}
