Projeto feito para a disciplia Estrutura de Dados 1, visando o aprendizado dos tipos de listas na linguagem de programação C.


1. Qual estrutura foi implementada?

Foram implementadas três estruturas de lista para gerenciamento de livros:
Lista Estática (vetor fixo) – com tamanho máximo definido por MAX_LIVROS.
Lista Dinâmica (vetor dinâmico com realocação) – capacidade inicial ajustável e expansível.
Lista Encadeada (simplesmente encadeada) – cada nó aponta para o próximo.



2. Quais funcionalidades foram concluídas com sucesso?
Cadastro de livros (cadastrarLivro)
Consulta por ISBN (consultarLivroPorISBN)
Empréstimo de livros (emprestarLivro)
Devolução de livros (devolverLivro)
Listagem de livros (listarLivros)
Liberação de memória (liberarLista)

Na versão dinâmica e encadeada, todas funcionam corretamente.
Na estática, há erros de atribuição em empréstimo e devolução (foi usado == ao invés de =).


3. O que foi mais fácil e o que foi mais difícil?

Mais fácil: Implementar a lista estática (menos gerenciamento de memória).
Mais difícil: Implementar a lista encadeada (requereu alocação dinâmica, controle de ponteiros e liberação nó a nó).



4. Em quais situações sua estrutura se destacaria?

Estática: Boa para sistemas pequenos, número fixo de livros, acesso rápido via índice.
Dinâmica: Ideal quando o número de livros pode crescer moderadamente.
Encadeada: Melhor para cenários de inserção/remoção frequente sem realocação.

5. Qual foi o desempenho observado com 50, 500 e 5.000 livros?
   
Lista Estática e Dinâmica: Acesso e consulta O(n) – desempenho aceitável para até 5.000 itens, mas pode degradar com muitos dados.
Lista Encadeada: Inserções rápidas (O(1) no início), mas consultas também O(n).
Para 50 → praticamente instantâneo.
Para 500 → sem problemas perceptíveis.
Para 5.000 → ainda viável, mas pode ter latência em consultas repetitivas.

6. Quais operações foram mais custosas na sua estrutura?

Busca por ISBN: O(n) em todas as estruturas.
Redimensionamento (somente na dinâmica): O(n) quando dobra a capacidade.
Liberação de memória (na encadeada): Percorre todos os nós.

7. Você implementaria essa estrutura em um sistema real? Por quê?

A lista dinâmica seria a melhor candidata: boa escalabilidade, simplicidade e baixo overhead.
A lista encadeada só seria usada se houvesse remoções frequentes.
A lista estática não é recomendada para produção devido à limitação fixa.
