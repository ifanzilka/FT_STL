#ifndef FT_ITERATOR
# define FT_ITERATOR

# include "iterator_tag.hpp"
# include "iterator_category.hpp"
# include "iterator_traits.hpp"
# include "iter_cat.hpp"
# include "Val_type.hpp"
# include "iter_swap.hpp"
# include "Dist_type.hpp"
# include "iter_advance.hpp"
# include "iter_distance.hpp"
# include "random_acsees_iterator.hpp"
# include "reverse_iterator.hpp"


namespace ft
{
	typedef long int ptrdiff_t;  // Разница между двумя указателями
};

/* Page 43 */
/* Описание итераторов */

/* OutputIterator (Итератор вывода)
**
** Возможно занесение и извлечение данных
** *it = X (занесение данных)
** x = *it (извлечение)
*/

/* InputIterator (Итератор ввода)
** 
** Для создания новых полседовательностей 
** for (it = it_start; it < it_end; it++)
**  x = *it (извлекаем данные )
** Должен хрнаить конец!!
**
*/

/* ForwardIterator (Последовательный итератор)
**
** Не обязателен маркер конца
** Можно друг друга сранивать
**
** Итерируется вперед
*/

/* BiderectionalIterator (Двухнаправленный итератор)
**
** Не обязателен маркер конца
** Можно друг друга сранивать
** Итерируется вперед и назад
*/

/* random-access-iterator (Итератор произвольного доступа)
**
** Не обязателен маркер конца
** Можно друг друга сранивать
** Итерируется вперед и назад
** Сложение/Вычитание
** Сравнивание порядка
** Индексация
** Dist() Разница между итерторов
*/


#endif 