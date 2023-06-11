#include <Arduino.h>
const int motor1 = 18;
const int motor2 = 19;

const int freq = 30000;
const int canalPWM1 = 0;
const int canalPWM2 = 1;
const int resolucion = 8;

void setup()
{
  // Configurar la señal PWM
  ledcSetup(canalPWM1, freq, resolucion);
  ledcSetup(canalPWM2, freq, resolucion);
  // Asignar el pin al canal PWM
  ledcAttachPin(motor1, canalPWM1);
  ledcAttachPin(motor2, canalPWM2);
}

void loop()
{
  // Para aumentar la velocidad progresivamente en un sentido del giro
  int ciclo1 = 0;
  int ciclo2 = 0;
  ledcWrite(canalPWM1, 0);
  ledcWrite(canalPWM2, 0);
  while (ciclo1 < 255)
  {
    ledcWrite(canalPWM1, ciclo1);
    ciclo1 = ciclo1 + 5;
    delay(250);
  }
   delay(2000);
  // Para aumentar la velocidad progresivamente en el sentido de giro contrario.
  ledcWrite(canalPWM1, 0);
  ledcWrite(canalPWM2, 0);
  while (ciclo2 < 255)
  {
    ledcWrite(canalPWM2, ciclo2);
    ciclo2 = ciclo2 + 5;
    delay(250);
  }
   delay(2000);
}
