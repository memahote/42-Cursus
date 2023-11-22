/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:45:01 by memahote          #+#    #+#             */
/*   Updated: 2023/11/12 16:45:01 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    if(ac >= 2)
    {
        while(av[i])
        {
            j = 0;
            while(av[i][j])
                std::cout<< (char)toupper(av[i][j++]);
            if(av[i + 1])
                std::cout<<" ";
            i++;
        }
        std::cout<<std::endl;
    }
    else
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
}