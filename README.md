# Sincronização do Metrô

Implementação de sincronização entre passageiros e carros utilizando threads POSIX (`pthread`), mutexes e variáveis de condição em C.

## Requisitos

- GCC
- GNU Make
- Biblioteca pthread

## Estrutura

- `sync_car.c`: implementação das operações de sincronização.
- `sync_car.h`: declaração da estrutura `station` e das funções.
- `test_sync_car.c`: testes fornecidos pelo professor.
- `Makefile`: instruções de compilação.
- `evidencias.log`: registro dos comandos e testes executados.

## Compilação

Dentro deste diretório, execute:

```bash
make
```

O comando gera o executável `sync_car`.

## Execução dos testes

Execute:

```bash
./sync_car
```

Para limpar os arquivos gerados pela compilação:

```bash
make clean
```

## Sincronização

A implementação utiliza:

- **Mutex:** protege o estado compartilhado da estação.
- **Variáveis de condição:** coordenam a espera dos passageiros e a confirmação do embarque.
- **Controle de assentos:** impede que mais passageiros embarquem do que a capacidade disponível.
- **Controle de embarque:** garante que o carro aguarde as confirmações dos passageiros autorizados antes de partir.

## Testes realizados

Os testes fornecidos pelo professor foram executados, incluindo dez execuções consecutivas do programa. Todas foram concluídas com sucesso.