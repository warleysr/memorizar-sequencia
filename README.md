# Memorizar Sequência
Jogo simples com **Arduino** para memorizar sequência de LEDs.

O jogo consiste em quatro LEDs posicionados de forma espaçadas representando as direções **CIMA, BAIXO, DIREITA** e **ESQUERDA**.

Os LEDs acendem um por vez em uma sequência, começando com apenas um LED e aumentando de acordo com os níveis vencidos. A sequência do próximo nível é a mesma sequência do nível anterior acrescido de outro LED aleatório.

O jogador após memorizar a sequência, deve informar as direções corretas pelo joystick. Caso erre, o jogo recomeça com apenas um LED. Caso o jogador consiga chegar ao nível **MAX_LEVEL** ele vence o jogo.

O Buzzer tem a função de emitir tons diferentes para quando o jogador deve inserir as entradas, quando ele perde e quando ganha. 

### Componentes utilizados
| Componente   | Especificação   | Quantidade   |
|--------------|-----------------|--------------|
| Arduino      | UNO R3          | x1           | 
| Joystick     | KY-023          | x1           |  
| Resistor     | 220 &Omega;     | x1           |
| Buzzer       | Ativo           | x1           |
| LED          | Cor preferida   | x4           |

### Esquemático do circuito
![Schematic](https://i.imgur.com/kgtSl6u.png)

