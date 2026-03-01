# Calculadora de Armor Rating do Skyrim

[Read in English](README.md)

**Objetivo:** Simular o sistema de Armor Rating do Skyrim para calcular a redução de dano com base nas peças de armadura equipadas.

No Skyrim, muitos jogadores não percebem como o sistema de armadura realmente funciona por trás dos panos. Este projeto recria essa lógica em C, levando em conta o armor rating exibido, os bônus de armadura ocultos e o limite de 80% de redução de dano.

## Como Funciona

A fórmula utilizada para a redução de dano é:

```
Redução de Dano % = (AR Exibido + AR Oculto) × 0,12
```

### Conceitos Importantes

*   **Armor Rating Oculto:** Cada peça de armadura equipada (elmo, peitoral, luvas, botas) concede um bônus invisível de **25 pontos**, totalizando **100 pontos ocultos** para o conjunto completo.
*   **Limite de Armadura (Armor Cap):** Skyrim possui um limite máximo de redução de dano físico de **80%**. Para atingir esse limite, você precisa de um Armor Rating total de **667**. Com o bônus oculto de 4 peças, você precisa de apenas **567 exibidos** para atingir o cap.

## Como Rodar

Você pode compilar o projeto usando `gcc`:

```bash
gcc main.c -o main.out
./main.out <dano>
```

**Exemplo:**

```bash
./main.out 100
```

O programa vai solicitar que você insira o armor rating de cada uma das 4 peças equipadas, e então calculará o armor rating total, a porcentagem de redução de dano e o dano final recebido.

## Funções

*   **argc_verify:**
    *   **Args:** `int max_argc`, `int argc`, `char **argv`
    *   **Return:** `void`
    *   **Process:** Valida se a quantidade correta de argumentos de linha de comando foi fornecida. Caso contrário, exibe o formato correto de uso e encerra o programa.

*   **equip_armor:**
    *   **Args:** `armor *armor_equipped`
    *   **Return:** `void`
    *   **Process:** Itera por cada um dos 4 slots de armadura, solicitando ao usuário que insira o armor rating de cada peça. Utiliza um loop `do-while` para garantir que a entrada seja válida (inteiro não-negativo).

*   **calculate_total_char_armor_rating:**
    *   **Args:** `armor *armor_equipped`
    *   **Return:** `int` (armor rating total exibido)
    *   **Process:** Soma o armor rating de todas as peças equipadas e retorna o armor rating total exibido.

*   **calculating_damage_reduction:**
    *   **Args:** `int total_armor_rating`
    *   **Return:** `float` (redução de dano como decimal)
    *   **Process:** Aplica a fórmula `(total_armor_rating × 0,12) / 100` para calcular a porcentagem de redução de dano. Se o resultado exceder o limite de 80%, o valor é limitado a 0,80.
