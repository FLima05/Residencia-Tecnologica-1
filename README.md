# 💊 Sistema de Gerenciamento de Estoque de Medicamentos

Este projeto é um sistema simples de *controle de estoque de medicamentos*, desenvolvido em linguagem C.

O sistema permite o cadastro de usuários, autenticação e gerenciamento de medicamentos.

---
## Status
Projeto em desenvolvimento.

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
* Validação de dados:

  * Data de validade não pode ser anterior à fabricação
  * Preço de venda não pode ser menor que o de compra
* Visualização completa do estoque

---

## Em desenvolvimento
* Adição da biblioteca *time.h*, para datas de validade
* Sistema de vendas de medicamentos
* Histórico de vendas
* Rastreamento de medicamentos por lote
* Verificação de medicamentos vencidos
* Refatoração do código
  
---
## 🛠️ Tecnologias utilizadas

* Linguagem: *C*

