Projeto feito para a disciplia Estrutura de Dados 1, visando o aprendizado dos tipos de listas na linguagem de programação C.

---

### Comentário de Documentação do Projeto – Estruturas de Dados para Gerenciamento de Biblioteca

Este projeto implementa **três versões de uma estrutura de dados para gerenciamento de livros**, cada uma com suas próprias características de desempenho, complexidade e aplicabilidade:

---

#### **1. Estruturas Implementadas**

* **Lista Estática (`biblioteca_estatica.c`)**

  * Armazena os livros em um vetor de tamanho fixo (`MAX_LIVROS`).
  * Simples de implementar, mas limitada em escalabilidade.
  * Não requer alocação dinâmica, mas pode desperdiçar memória se a capacidade não for bem dimensionada.

* **Lista Dinâmica (`biblioteca_dinamica.c`)**

  * Usa um vetor com alocação dinâmica e redimensionamento automático (dobrando a capacidade quando necessário).
  * Oferece melhor aproveitamento de memória e cresce conforme a necessidade.

* **Lista Encadeada (`biblioteca_encadeada.c`)**

  * Cada livro é um nó ligado ao próximo, permitindo inserções rápidas (O(1) no início).
  * Mais flexível em remoções/inserções, porém com sobrecarga de ponteiros e acesso sequencial.

---

#### **2. Funcionalidades Implementadas**

* **Inicialização da lista**
* **Cadastro de livros**
* **Consulta por ISBN**
* **Empréstimo e devolução de livros**
* **Listagem dos livros e seus status**
* **Liberação de memória** (quando aplicável)

**Observação:** Na versão estática, há um erro de atribuição em `emprestarLivro()` e `devolverLivro()` (`==` usado no lugar de `=`), o que impede a atualização correta do status.

---

#### **3. Facilidade e Dificuldade**

* **Mais fácil:** Implementação da lista estática (estrutura simples, sem gerenciamento de memória dinâmica).
* **Mais difícil:** Lista encadeada (necessidade de gerenciamento manual de nós e liberação memória).

---

#### **4. Casos de Uso Ideais**

* **Estática:** Pequenos sistemas com número fixo de livros e baixa necessidade de alterações.
* **Dinâmica:** Sistemas médios ou grandes, onde a quantidade de livros varia moderadamente.
* **Encadeada:** Aplicações com inserções/remoções frequentes sem necessidade de acesso aleatório rápido.

---

#### **5. Desempenho Observado**

* Operações de busca, empréstimo e devolução: **O(n)** em todas as versões (busca linear).
* Redimensionamento da lista dinâmica: **O(n)** apenas quando a capacidade é expandida.
* Liberação da lista encadeada: **O(n)** (liberação nó a nó).

Testes conceituais:

* **50 livros:** Operações instantâneas.
* **500 livros:** Desempenho aceitável para uso prático.
* **5.000 livros:** Leve aumento no tempo de busca, mas ainda viável.

---

#### **6. Operações Mais Custosas**

* **Busca por ISBN**: Linear em todas as versões.
* **Redimensionamento da lista dinâmica**: Ocorre apenas quando há saturação.
* **Liberação da lista encadeada**: Percorre todos os nós para desalocar memória.

---

#### **7. Aplicação em Sistemas Reais**

* A **lista dinâmica** é a mais indicada para um sistema real devido ao equilíbrio entre simplicidade, escalabilidade e controle de memória.
* A **lista encadeada** seria escolhida apenas em cenários com alta taxa de remoções/inserções.
* A **lista estática** não é recomendada para produção, pois limita a escalabilidade e requer definição prévia da capacidade.

---

Quer que eu **inclua esse comentário como bloco de documentação direto nos três códigos** (em formato `/* ... */`) já organizando por estrutura?
Ou prefere que eu **gere um único arquivo `README.md`** pronto para o repositório Git?

