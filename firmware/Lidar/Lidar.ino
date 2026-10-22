#include <Wire.h>
#include <VL53L0X.h>
#define HORARIO 1 
#define R 3.5 // raio da polia grande em cm
#define r 1.5 // raio da polia pequena em cm
#define AL 6 // vou calcular a distância uma vez a cada 6 graus 
#define PASSOS 15

const float razao = R/r;

Bonezegei_ULN2003_Stepper Stepper(8, 9, 10, 11); 

VL53L0X sensor;


const float grau_passo = 360.0f * razao / 2048.0f; // angulo para 1 passo do motor
float angulo_convertido = grau_passo * PASSOS; // a cada x graus uma medida vai ser calculada
int passos_sensor_rev = round(2048 / razao);
int total_passos = 0;

float ang_perc = 0.0f ;

void setup() 
{ 
  Serial.begin(115200);
  Wire.begin();

  Stepper.begin(); 
  Stepper.setSpeed(12); 
} 

void loop() 
{ 
    Stepper.step(HORARIO, PASSOS);
    delay(10);

    float dist = sensor.readRangeContinuousMillimeters();
    delay(120);

   
      total_passos = (total_passos + PASSOS) % passos_sensor_rev;

      ang_perc =360.0 * total_passos/passos_sensor_rev;

      
       if(dist >= 0)
    {
      
      Serial.println(String(ang_perc, 2) + "," + String(dist[0], 1));

    }
}
