/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtree_init.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:15:26 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/18 18:15:27 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XTREE_INIT
# define FT_XTREE_INIT

#include "xtree.hpp"

namespace ft
{
    /* Выделяем память под ноду и инициализируем */
    template <class Tree_traits>
    void Tree<Tree_traits>::Init()
    {
        Head = Buynode(0, Black);
        Isnil(Head) = true;

        /* Задаю корень левое и правое указатель на ноду */
        Root() = Head;
        Lmost() = Head;
        Rmost() = Head;

        Size = 0;
    }

}

#endif