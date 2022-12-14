### Алгоритм
Будем решать чем-то похожим на динамику.

Будем рекурсивно строить скобочную последовательность, поддерживая баланс в ней $\leq 0$. Для этого в очередную итерацию рекурсии будем передавать, сколько еще скобок осталось открыть - $par\\_to\\_open$, сколько закрыть - $par\\_to\\_close$, и саму сгенерированную последовательность. В первый раз рекурсивную функцию генерации мы передадим $n$, $n$ и пустую строку.

Если $par\\_to\\_open > 0$, то у нас еще остались открывающие скобки. Поскольку они не могут поломать скобочный баланс, мы можем в любом случае добавить их м передать полученную строку на рассмотрение в следующую итерацию рекурсии.

Если $par\\_to\\_open < par\\_to\\_close$, то скобочный баланс $> 0$, значит, мы можем приписать закрывающую скобку и передать результат дальше в рекурсию.

Если на очередной итерации выяснится, что и $par\\_to\\_open$, и $par\\_to\\_close$ оба равны нулю, то приписываем сгенерированную скобочную последовательность к ответу.


### Доказательство корректности
Очевидно, что все полученные скобочные последовательности будут правильными - во время построения мы поддерживали скобочный баланс неотрицательным, а в конце количество использованных открывающих скобок обязательно равно количеству закрывающих скобок.

Кроме того очевидно, что мы получим все возможные скобочные последовательности. Это можно строго доказать по индукции - через нее легко показывается, что на глубине рекурсии $i$ мы получим все возможные скобочные последовательности длины $i$ с неотрицательным скобочным балансом


### Асимптотика
$O(N \cdot C_N)$, где $C_n$ - $n$-е число Каталана