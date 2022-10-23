## Решение

Сделаем динамику по подотрезкам $dp_{l, r}$ - список всех **BST** на $[l, r]$. Будем пересчитывать ее в порядке увеличения длины отрезка. Ответ для отрезков длины 0 и 1 тривиальный, научимся пересчитывать динамику для отрезков побольше

Пусть хотим посчитать $dp_{L, R}$. Переберем $root$ - значение корня **BST**. Тогда в левом поддереве могут быть все возможные **BST** на $[L, root - 1]$, а в правом - все возможные **BST** на $[root + 1, R]$ (если отрезок получается вырожденым, то считаем, что он имеет длину 0). Все возможные **BST** на меньших по длине подотрезках мы уже знаем, так что левое и правое поддеревья получаются вложенными переборами по $dp_{L, root - 1}$ и $dp_{root + 1, R}$

Время на построение $dp_{l, r}$ для отрезка длины $k = r - l + 1$ равно количеству полученных деревьев. Пусть это $T(k)$, тогда получаем рекурренту $T(k) = \sum_{v=0}^{k}(T(v) \cdot T(k - v - 1))$. Внимательно приглядевшись, видим, что $T(k) = C_k$ - то есть, это числа Каталана

Значит, суммарно алгоритм работает за $O(\sum_{k=1}^n ((n - k + 1) \cdot C_k)) = O(\sum_{k=1}^n ((n - k + 1) \cdot \frac{4^k}{k^{3/2}}))$. Очень грубо это можно оценить через $O(4^n \cdot \sqrt{n})$