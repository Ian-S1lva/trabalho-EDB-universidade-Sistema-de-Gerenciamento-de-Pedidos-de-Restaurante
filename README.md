# Projeto 1: Sistema de Gerenciamento de

# Pedidos de Restaurante (orientações)

```
(versão 1.0)
```
## Descrição

Desenvolva um sistema para gerenciar os pedidos de um restaurante, onde
os pedidos são armazenados em uma lista ligada(salão) e, posteriormente,
processados pela cozinha em ordem de chegada utilizando uma fila. A implementação deve ser feita na linguagem C.

## Objetivos

- Implementar um sistema de gerenciamento de pedidos de restaurante
    na linguagem C.
- Armazenar pedidos em uma lista ligada (salão).
- Permitir a remoção de pratos específicos da lista de pedidos (salão).
- Utilizar uma fila para processar os pedidos em ordem de chegada (cozinha).

## Funcionalidades

### Adicionar Pedido (salão)

- Permitir que o cliente adicione um novo pedido.
- Armazenar o pedido na lista ligada de pedidos pendentes.


### Remover Pedido (salão)

- Permitir que o cliente remova um prato específico do pedido.
- Atualizar a lista ligada de pedidos após a remoção.

### Processar Pedido (cozinha)

- Transferir o pedido da lista ligada para a fila de processamento.
- Processar os pedidos em ordem de chegada.

### Listar Pedidos Pendentes (salão)

- Exibir todos os pedidos atualmente armazenados na lista ligada.

### Listar Pedidos em Processamento (cozinha)

- Exibir todos os pedidos atualmente na fila de processamento.

## Estruturas de Dados

### Lista Ligada (salão)

Para armazenar os pedidos pendentes, permitindo inserção e remoção de
pratos específicos.

### Fila (cozinha)

Para processar os pedidos em ordem de chegada.

## Requisitos

### Adicionar Pedido (salão)

- A função deve permitir que o cliente adicione um ou mais pratos ao
    pedido.


### Remover Pedido (salão)

- A função deve permitir que o cliente remova um prato específico de um
    pedido.
- A lista ligada deve ser atualizada para refletir a remoção.

### Processar Pedido

- A função deve transferir o pedido da lista ligada para a fila de processamento.
- Os pedidos na fila devem ser processados em ordem de chegada (FIFO).

### Listar Pedido Pendente (salão)

- A função deve exibir o pedido pendente atualmente na lista ligada.

### Listar Pedidos em Processamento (cozinha)

- A função deve exibir todos os pedidos atualmente na fila de processamento.

## Cardápio

### Entradas

1. Sopa de Cebola
2. Salada Caesar
3. Bruschetta
4. Carpaccio de Carne
5. Camarão ao Alho

### Pratos Principais

1. Lasanha à Bolonhesa
2. Filé Mignon com Fritas
3. Frango Grelhado com Legumes


4. Bacalhau à Gomes de Sá
5. Risoto de Cogumelos

### Sobremesas

1. Tiramisu
2. Cheesecake de Frutas Vermelhas
3. Mousse de Chocolate
4. Pudim de Leite
5. Sorvete de Baunilha com Calda de Morango

## Observações

1. Certifique-se de que a implementação da lista ligada e da fila esteja
    correta e eficiente.
2. O sistema deve lidar adequadamente com tentativas de remoção de
    pratos que não existem na lista ligada.
3. Inclua uma interface de usuário que permita a interação fácil com as
    funcionalidades do sistema.
4. O código deve ser bem comentado e documentado para facilitar a compreensão e manutenção.
5. Modularize o projeto (.c,.h e makefile).

## Regras a seguir

1. Este projeto vale 5,0 pontos.
2. O projeto poderá ser implementado em dupla.
3. Os nomes dos participantes dever ̃ao ser enviados via tarefa a ser informada.
4. Idem caso o projeto for implementado por apenas um aluno.
5. A data limite para envio do projeto será 26/05/25.


6. A forma de envio do projeto será via tarefa a ser informada.
7. O sorteio dos dias de apresentação será realizado no dia 27/05/25 e seu
    resultado divulgado no Sigaa.
8. Apenas um dos participantes ficará responsável por enviar o projeto
    compactado.
9. A execução do projeto deverá ser realizada tanto no Windows, quanto
    no Linux.
10. Detecção de código gerado por IA acarretará em penalidade na avaliação deste projeto.
11. Este documento está sujeito a alterações e qualquer atualização será
informada pelo Sigaa.