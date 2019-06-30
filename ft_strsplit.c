/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:17:15 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/28 15:41:32 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/lem_in.h"

static void	ft_count_words(char *str, char del, int *words)
{
	int	i;

	i = 0;
	*words = 0;
	while (str[i])
	{
		while (str[i] == del)
			i++;
		if (str[i] != del && str[i] != '\0')
			*words += 1;
		while (str[i] != del && str[i] != '\0')
			i++;
	}
}

static void	str_alloc(char **str_new, char *str, char del)
{
	int	word_len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		word_len = 0;
		while (str[i] == del)
			i++;
		while (str[i] != del && str[i] != '\0')
		{
			word_len++;
			i++;
		}
		if (word_len)
		{
			if (!(str_new[j] = (char*)malloc(sizeof(char) * (word_len + 1))))
				exit(0);
			str_new[j][word_len] = '\0';
			j++;
		}
	}
}

char		**ft_strsplit(char *str, char del)
{
	char	**str_new;
	int		words;
	int		i;
	int		j;
	int		k;

	if (str != NULL && str[0] == del)
		return (NULL);
	ft_count_words(str, del, &words);
	if (!(str_new = (char**)malloc(sizeof(char*) * (words + 1))))
		exit(0);
	str_new[words] = NULL;
	str_alloc(str_new, str, del);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == del)
			i++;
		k = 0;
		while (str[i] != del && str[i] != '\0')
			str_new[j][k++] = str[i++];
		j++;
	}
	return (str_new);
}
