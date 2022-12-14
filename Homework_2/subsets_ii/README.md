### Алгоритм
Будем решать задачу чем-то похожим на динамику. 

Отсортируем исходный массив. Для каждого уникального значения $val_i$ массива посчитаем количество его вхождений в массив $cnt_i$. 

Пусть изначально вектор подмножеств содержит только пустое множество. Будем итеративно "добавлять к ответу" $val_i$. Пусть у нас уже посчитаны все возможные подмножества, состоящие из $val_i, i < k$. Тогда чтобы посчитать все возможные подмножества, состоящие из $val_i, i \leq k$, достаточно к каждому из уже содержащихся в ответе подмножеств приписать $val_i$ каждое возможное количество раз от 1 до $cnt_i$ и дописать полученные множества к ответу.

### Асимптотика
Всего мы построим $O(2^{|nums|})$ подмножеств, причем каждое будет строиться за $O(|nums|)$. Значит, итоговая асимптотика - $O(2^{|nums|} \cdot |nums|)$
