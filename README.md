# 💊 Sistema de Estoque de Medicamentos

Este projeto é um sistema simples de *controle de estoque de medicamentos*, desenvolvido em linguagem C.

O sistema permite o cadastro de usuários, autenticação e gerenciamento de medicamentos.

---

## 📌 Funcionalidades

### 👤 Usuários

* Cadastro de novos usuários
* Login com validação de credenciais
* Listagem de usuários cadastrados
* Remoção de usuários

### 💊 Medicamentos
* Cadastro de medicamentos com:
  * Nome
  * Quantidade
  * Fabricante
  * Lote
  * Data de fabricação
  * Data de validade
  * Preço de compra e venda
  * Categoria
- Listagem completa do estoque
- Busca de medicamentos por lote

* Validação de dados:
  * Data de validade não pode ser anterior à fabricação
  * Preço de venda não pode ser menor que o de compra

### 🏪 Estoque
- Visualização geral do estoque

### 💰 Sistema de vendas
- Registro de vendas de medicamentos
- Atualização automática do estoque
- Registro de histórico de vendas


## 🧠 Estrutura do sistema

O sistema é baseado em menus interativos:

- Menu principal (login e gerenciamento de usuários)
- Menu interno do sistema (após login)
- Menu de estoque (consulta e vendas)

---

## 🗂️ Arquivos utilizados

O sistema cria e manipula os seguintes arquivos:

- `cadastro.txt` → Armazena usuários e senhas
- `Medicamentos.txt` → Armazena o estoque de medicamentos
- `historico.txt` → Registra todas as vendas realizadas
- `temp.txt` → Arquivo temporário para operações de atualização

---

## 🛠️ Tecnologias utilizadas

- Linguagem C
- Biblioteca padrão:
  - `stdio.h`
  - `string.h`
  - `stdlib.h`

---

## Em desenvolvimento
* Adição da biblioteca *time.h*, para datas de validade.
* Verificação de medicamentos vencidos.
* Editar medicamentos.
* Venda multipla de medicamentos.
* Verificação de medicamentos e usuários duplicados.
* Rastreamento de categoria.(opção na hora da venda).
* Refatoração do código.

---

## Link do trello
https://trello.com/invite/b/69c3ced405958303dddadef9/ATTIdcd118d1dc9de8bae2aeb1846e9bfcb014D62E55/sistema-de-estoque-de-medicamentos
