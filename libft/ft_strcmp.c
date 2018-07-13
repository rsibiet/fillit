/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:07:18 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/11/26 15:30:35 by ddesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*cur1;
	unsigned char	*cur2;

	cur1 = (unsigned char *)s1;
	cur2 = (unsigned char *)s2;
	i = 0;
	while (cur1[i] && cur2[i] && cur1[i] == cur2[i])
		i++;
	return (cur1[i] - cur2[i]);
}
