## Решение
Если сумма длин строк $S1$ и $S2$ не равна длине строки $S3$, то сразу вернем $false$.

Заметим такой *факт* - если строка $S3$ получается интерливингом $S1$ и $S2$, то строка $S3[:-1]$ получается либо интерливингом $S1$ и $S2[:-1]$, либо $S1[:-1]$ и $S2$

Заведем динамику $dp_{n, m}$ = булевый флаг - можем ли мы получить $S_3[:n + m]$ интерливингом $S_1[:n]$ и $S_2[:m]$. Воспользуемся *фактом* - $dp_{i, j} = true$, если выполнено одно из:
1) $i = 0, j = 0$ - База динамики
2) $S_3[n + m]$ совпадает с $S_2[m]$ и весь предыдущий префикс мы умеем получать интерливингом $S_1[:n]$ и $S_2[:m - 1]$ (то есть $dp_{n, m - 1} = true$). 
3) $S_3[n + m]$ совпадает с $S_1[n]$ и есть $dp_{n - 1, m} = true$.

Суммарно подсчет всей динамики работает за $O(|S_1| \cdot |S_2|)$