/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:12:22 by cnamoune          #+#    #+#             */
/*   Updated: 2024/12/19 19:13:59 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoin(char *s1, char c)
{
	size_t	i;
	char	*result;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	result = malloc(ft_strlen(s1) + 2);
	if (!result)
		return (free(s1), NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i++] = c;
	result[i] = '\0';
	return (free(s1), result);
}

int	main(void)
{
	char	*str = NULL;

	str = ft_strjoin(str, 'H');
	str = ft_strjoin(str, 'e');
	str = ft_strjoin(str, 'l');
	str = ft_strjoin(str, 'l');
	str = ft_strjoin(str, 'o');
	str = ft_strjoin(str, '\0'); // Pour marquer la fin de la chaîne

	write(1, "Résultat final : ", 17);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);

	free(str);
	return (0);
}
