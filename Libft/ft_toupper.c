/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 21:33:01 by ysalama           #+#    #+#             */
/*   Updated: 2026/10/24 11:36:43 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Issues:
//
// 1. Something relating to negative numbers and how 256 should be added.
//

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c -= 32);
	return (c);
}
