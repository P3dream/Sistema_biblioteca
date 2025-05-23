# Sistema de Biblioteca em C

O sistema de biblioteca foi desenvolvido para a disciplina de Algoritmos e Estruturas de Dados 1 (AEDS 1). Inicialmente implementado em C++, o projeto foi migrado para C devido a dificuldades na implementação da interface gráfica.

## 🖥️ Plataforma
- Desenvolvido especificamente para **Linux**

## 🧠 Estrutura de Dados
- Utiliza **listas encadeadas** para otimização de memória
- Alocação dinâmica de memória sem necessidade de armazenamento sequencial

## ✨ Funcionalidades

### 👨‍🎓 Gestão de Alunos
- Registrar novo aluno
- Imprimir todos os alunos cadastrados
- Buscar aluno por ID
- Remover aluno do sistema

### 📚 Gestão de Livros
- Cadastrar novos livros
- Buscar livro por ID
- Buscar livros por categoria
- Listar todos os livros
- Empréstimo/devolução de livros
- Remover livros do acervo

### 🏫 Gestão de Infraestrutura
- Cadastrar salas, computadores ou armários
- Remover itens de infraestrutura
- Listar toda infraestrutura
- Empréstimo/devolução de recursos
- Filtrar por tipo ou ID

## ⚡ Por que listas encadeadas?
As listas encadeadas permitem:
- Uso eficiente de memória (não-sequencial)
- Alocação dinâmica conforme demanda
- Flexibilidade na manipulação de dados

⚠️ **Observação**: Para grandes volumes de dados (n → ∞), as operações podem perder eficiência.

## 🧮 Complexidade das Operações
Todas as operações principais possuem complexidade **O(n)**:
- Inserção
- Remoção
- Busca

## 🚀 Como Executar
Execute online via OnlineGDB:  
[![Open in OnlineGDB](https://img.shields.io/badge/OnlineGDB-Run%20Now-blue?logo=c&logoColor=white)](https://onlinegdb.com/QrJV0e50M)

## 📌 Considerações Finais
Este projeto representou uma valiosa experiência de aprendizado em estruturas de dados e programação em C. Sinta-se à vontade para:

- Reportar problemas
- Sugerir melhorias
- Contribuir via Pull Requests

Desenvolvido por **Pedro Pizzi (P3dream)**
