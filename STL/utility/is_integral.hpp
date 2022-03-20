/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <ifanzilka@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:14:09 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/20 10:31:51 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IS_INTEGRAL
# define FT_IS_INTEGRAL

#include <iostream>

namespace ft
{
	template<class T, bool v>
	struct integral_constant
	{
		static const bool value = v;
        
		typedef T                   value_type;
		typedef integral_constant   type;
		operator value_type() const
		{
			return (value);
		}
	};
	
	/* Если смогли принять шаблонный параметр */
	template <class T>
    struct	is_integral:				public integral_constant<T, false> {};
	
    template <>
    struct	is_integral<bool>:			public integral_constant<bool, true> {};
	
    template <>
    struct	is_integral<char>:			public integral_constant<bool, true> {};
	
    template <>
    struct	is_integral<signed char>:	public integral_constant<bool, true> {};
	
    template <>
    struct	is_integral<unsigned char>:	public integral_constant<bool, true> {};
	
    template <>
    struct	is_integral<wchar_t>:		public integral_constant<bool, true> {};
	
    template <>
    struct is_integral<char16_t> : 		public integral_constant<bool, true> {};
	
    template <>
    struct	is_integral<short>:			public integral_constant<bool, true> {};
	
    template <>
    struct	is_integral<unsigned short>:public integral_constant<bool, true> {};
	
    template <>
    struct	is_integral<int>:			public integral_constant<bool, true> {};
	
    template <>
    struct	is_integral<unsigned int>:	public integral_constant<bool, true> {};
	
    template <>
    struct	is_integral<long>: 			public integral_constant<bool, true> {};
	
    template <>
    struct	is_integral<unsigned long>: public integral_constant<bool, true> {};
	
    template <>
    struct	is_integral<long long>: 	public integral_constant<bool, true> {};
	
    template <>
	struct	is_integral<unsigned long long>: public integral_constant<bool, true> {};
}

namespace ft_old
{
	template< class T > 
    struct remove_const
    { 
        typedef T type;
        //operator value_type() const { return type;}
    };
    
    template< class T > 
    struct remove_const<const T>
    { 
        typedef T type;
        //operator value_type() const { return type;}
    };

    struct true_type
    {
	    static const bool value = true;
    };

    struct false_type
    {
	    static const bool value = false;
    };

    /* Если не получилось приравнять к станадртным типам */
    template <typename>
	struct is_integral_base : public false_type {};

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