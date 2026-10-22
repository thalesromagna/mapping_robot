#include <Arduino.h>
#define DIAMETRO 6.8 // em cm
#define N_FUROS 20
#define ENCODER_DIREITA 34
#define ENCODER_ESQUERDA 35

typedef struct
{
  volatile long n_pulsos;
  const uint8_t pin;
  const float raio = DIAMETRO/2;
  float dist_perc = 0; // em cm
  bool girou;
} Encoder;


Encoder direita{0, ENCODER_DIREITA, DIAMETRO/2, 0, false};

Encoder esquerda{0, ENCODER_ESQUERDA, DIAMETRO/2, 0, false};

void calc_dist(Encoder* enc)
{
  enc->dist_perc = enc->n_pulsos * (PI * enc->raio)/10;
}

float dist_med(Encoder* dir, Encoder* esq)
{
  float dm = (dir->dist_perc + esq->dist_perc)/2;
  return (dm);
}

void setup() {
  Serial.begin(115200);

  pinMode(direita.pin, INPUT);
  pinMode(esquerda.pin, INPUT);       
  direita.girou = digitalRead(direita.pin);
  esquerda.girou = digitalRead(esquerda.pin);
}

void loop() {
  if(digitalRead(direita.pin) == HIGH && direita.girou != digitalRead(direita.pin))
  {
    direita.n_pulsos += 1;
    calc_dist(&direita);
    direita.girou = digitalRead(direita.pin);
    Serial.printf("Direita (cm): %.2f        Esquerda (cm): %.2f       Media: %.2f \n", direita.dist_perc, esquerda.dist_perc, dist_med(&direita, &esquerda));
    delay(10);

  }

  if(digitalRead(esquerda.pin) == HIGH && esquerda.girou != digitalRead(esquerda.pin))
  {
    esquerda.n_pulsos += 1;
    calc_dist(&esquerda);
    esquerda.girou = digitalRead(esquerda.pin);
    Serial.printf("Direita (cm): %.2f        Esquerda (cm): %.2f       Media: %.2f \n", direita.dist_perc, esquerda.dist_perc, dist_med(&direita, &esquerda));
    delay(10);
  }
}
 