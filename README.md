Loja-Fein

Sistema de gerenciamento de loja desenvolvido em C, executado via interface de linha de comando (CLI). O projeto foi construído com foco na aplicação prática de estruturas de dados, modularização de código e persistência em arquivos.

Objetivo

Implementar um sistema simples de controle de produtos e vendas, exercitando conceitos fundamentais da linguagem C e boas práticas de organização de software.

Conceitos Aplicados

Programação estruturada em C

Modularização com separação de responsabilidades (.c / .h)

Manipulação de arquivos para persistência de dados

Uso de estruturas (struct) para modelagem de entidades

Gerenciamento básico de memória

Automação de build com Makefile

Funcionalidades

Cadastro de produtos

Listagem de produtos

Registro de vendas

Controle básico de estoque

Persistência de dados em arquivos locais

Estrutura do Projeto
Loja-Fein/
├── src/        # Código-fonte
├── include/    # Arquivos de cabeçalho
├── data/       # Arquivos de dados persistidos
├── bin/        # Executável gerado
├── Makefile    # Script de compilação
└── README.md
Compilação

É necessário possuir um compilador C (GCC ou similar) e o make instalado.

Para compilar o projeto:

make

Após a compilação, execute o binário gerado:

./bin/loja_fein
