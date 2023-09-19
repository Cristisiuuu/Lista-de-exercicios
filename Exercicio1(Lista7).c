1° Critique a seguinte formulação do problema de busca: dado x e um vetor crescente v[0..n-1], encontrar um índice j tal que v[j-1] ≤ x ≤ v[j]. Critique a formulação construída em torno de "v[j-1] < x < v[j]". 

// Isso ocorre porque a formulação indica que "v[j-1]" é estritamente menor que "x" e "v[j]" é estritamente maior que "x". No entanto, se o vetor "v" contém valores iguais, isso pode levar a problemas, pois a busca pode não encontrar um índice válido.

