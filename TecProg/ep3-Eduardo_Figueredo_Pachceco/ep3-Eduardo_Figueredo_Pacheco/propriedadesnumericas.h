
/*!  \brief Função: eh_par
 *  Uso: x = eh_par(num);
 *  Verifica se um número é par analisando o resto desse por dois. Caso o resto seja 0 sabe-se que ele é par, caso contrário, ele é impar.
 *  \param num : (long long) número que vai ter paridade testada
 *  \return retorno: (int) 1 se for par. 0 se não for par. 
 */
int eh_par(long long  num);


/*!  \brief Função: eh_primo
 *  Uso: x = eh_primo(num);
 *  \param num : (long long) Essa função recebe um número e verifica se esse é primo
 *  \return retorno: (int) 1 se o número é primo ou (int) 0 se não é primo
 */
int eh_primo(long long  num);


/*!  \brief Função: ehQuadradoPerfeito
 *  Uso: x = ehQuadradoPerfeito(num);
 *  Verifica se existe um número natural x tal que num pode ser escrito como x².
 *   \param num : (long long) Essa função recebe um número e verifica se esse é um quadrado perfeito
 *  
 *   \return retorno: (int) 1 se o número é um quadrado perfeito ou 0 se não é.
 */
int ehQuadradoPerfeito (long long num);


/*!  \brief Função: ehQuadradoPerfeito
 *  Uso: x = ehQuadradoPerfeito(num);
 *  Verifica se existe um número natural x tal que num pode ser escrito como x³.
 *   \param num : (long long) Essa função recebe um número e verifica se  ele é um cubo perfeito.
 *   \return retorno: (int) 1 se o número é um cubo perfeito ou 0 se não é.
 */
int ehCuboPerfeito (long long num);


/*!  \brief Função: ehFibonacci
 *  Uso: x = ehFibonacci(num);
 *  Passa pela sequência de Fibonacci até achar um número maior ou igual àquele inserido no parâmetro.
 *   \param num : (long long) Essa função recebe um número e verifica se esse pertence a sequência de Fibonacci.
 *   \return retorno: (int) 1 se o número pertence a sequÊncia de Fibonacci ou 0 se não pertence.
 */
int ehFibonacci(long long num);



/*!  \brief Função: ehFatorial
 *  Uso: x = ehFatorial(num);
 *  verifica se existe algum número fatorial maior ou igual àquele inserido como parâmetro da função, que vai ser fatorial se for igual ou não vai ser caso existir apenas fatoriais maiores ou menores.
 *  \param num : (long long) Essa função recebe um número e retorna (1) se o número pode ser escrito da forma x! em que x é um inteiro menor ou igual
 *  \return retorno: (int) 1 se o número for um fatorial ou (0) se não pode ser escrito da forma x!.
 */
int ehFatorial(long long num);