// PINOS DIGITAIS DO ARDUINO LIGADOS AOS LEDS E BUZZER
#define CIMA 2
#define BAIXO 4
#define DIREITA 5
#define ESQUERDA 3
#define BUZZER 6

// ENTRADAS ANALOGICAS DO ARDUINO LIGADAS AO JOYSTICK
#define EIXO_X A0
#define EIXO_Y A1

// NUMERO MAXIMO SEQUENCIAL DE LEDS CORRETOS PARA GANHAR O JOGO
#define MAX_LEVEL 10

int ledPins[4] = {CIMA, BAIXO, DIREITA, ESQUERDA};

int leds[MAX_LEVEL];
int direction=-1, j=0, awaiting=0, level=1;

void setup() {
  resetLeds();

  pinMode(CIMA, OUTPUT);
  pinMode(BAIXO, OUTPUT);
  pinMode(DIREITA, OUTPUT);
  pinMode(ESQUERDA, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

bool changeDirection(int dir) {
  if (dir == direction) return false;

  direction = dir;
  return true;
}

void checkWin() {
  if (j == level) {
    if (level < MAX_LEVEL) {
      win();
    }
    else {
      for (int i = 0; i < 5; i++) {
        intTone(800);
        delay(150);
      }
      lose(true);
    }
  }
}

void intTone(int freq) {
  tone(BUZZER, freq);
  delay(150);
  noTone(BUZZER);
}

void resetLeds() {
  for (int i = 0; i < MAX_LEVEL; i++) {
    leds[i] = 0;
  }
}

void lose(boolean winGame) {
  awaiting = false;
  level = 1;
  direction = -1;
  resetLeds();
  if (!(winGame))
    intTone(100);
}

void win() {
  awaiting = false;
  level++;
  direction = -1;
  intTone(1000);
}
 
void loop() {
  if (awaiting) {
    int x = analogRead(EIXO_X);
    int y = analogRead(EIXO_Y);

    if (x == 1023) {
      if (changeDirection(0)) {
        if (leds[j++] != CIMA) {
          lose(false);
          return;
        }
        checkWin();
      }
    }
    else if (x < 50) {
      if (changeDirection(1)) {
        if (leds[j++] != BAIXO) {
          lose(false);
          return;
        }
      }
      checkWin();
    }
    else if (y == 1023) {
      if (changeDirection(2)) {
        if (leds[j++] != DIREITA) {
          lose(false);
          return;
        }
        checkWin();
      }
    }
    else if (y < 50) {
      if (changeDirection(3)) {
        if (leds[j++] != ESQUERDA) {
          lose(false);
          return;
        }
        checkWin();
      }
    }
    
    delay(100); 
  }
  else {
    for (int i = 0; i < level; i++) {
      int led = leds[i];
      if (led == 0) {
        led = ledPins[random(0, 4)];
        while (i > 0 && led == leds[i-1]) { // IMPEDIR DE SAIR O LED IGUAL AO ANTERIOR
          led = ledPins[random(0, 4)];
        }
        leds[i] = led;
      }
      digitalWrite(led, HIGH);
      delay(250);
      digitalWrite(led, LOW);
      delay(250);
    }
    j = 0;
    awaiting = true;
    intTone(500);
  }
} 
