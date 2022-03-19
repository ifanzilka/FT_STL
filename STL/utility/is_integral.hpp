/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:14:09 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/19 17:52:29 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IS_INTEGRAL
# define FT_IS_INTEGRAL

namespace ft
{
	template< class T > 
    struct remove_const
    { 
        typedef T type;
    };
    
    template< class T > 
    struct remove_const<const T>
    { 
        typedef T type; 
    };

    // struct true_type
    // {
    //     static const int value = 1;
    // };

    // struct false_type
    // {
    //     static const int value = 0;
    // };

    struct true_type
    {
	    static const bool value = true;
    };

    struct false_type
    {
	    static const bool value = false;
    };

    /* Если не получилось приравнять к станадртным типам */
    template <typename> struct is_integral_base : public false_type {};

    /* Пытаемся приравнять к одному из классов ниже*/
    template<> 
    struct is_integral_base<bool>:               public true_type {};
    
    template<>
    struct is_integral_base<char>:               public true_type {};
    
    template<>
    struct is_integral_base<signed char>:        public true_type {};
    
    template<>
    struct is_integral_base<unsigned char>:      public true_type {};
    
    template<>
    struct is_integral_base<wchar_t>:            public true_type {};
    
    // #include <iostream>
    // //INCLUDE IOSTREAM!!!
    // template<>
    // struct is_integral_base<char16_t>:           public true_type {};
    
    // template<>
    // struct is_integral_base<char32_t>:           public true_type {};
    
    template<>
    struct is_integral_base<short>:              public true_type {};
    
    template<>
    struct is_integral_base<unsigned short>:     public true_type {};
    
    template<>
    struct is_integral_base<int>:                public true_type {};
    
    template<>
    struct is_integral_base<unsigned int>:       public true_type {};
    
    template<>
    struct is_integral_base<long>:               public true_type {};
    
    template<>
    struct is_integral_base<unsigned long>:      public true_type {};
    
    template<>
    struct is_integral_base<long long>:          public true_type {};
    
    template<>
    struct is_integral_base<unsigned long long>: public true_type {};
    
    template<>
    struct is_integral_base<__int128_t>:         public true_type {};
    
    template<>
    struct is_integral_base<__uint128_t>:        public true_type {};

    
    /* Сюда приходит T который мы хотим понять число это или итератор*/
    template < class T >
    struct is_integral : public is_integral_base<typename remove_const<T>::type>
    {
    
    };

};

#endif