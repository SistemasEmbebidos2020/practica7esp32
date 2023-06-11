#include <Arduino.h>

const int ledPin1 = 12;  // Pin utilizado para el LED
const int ledPin2 = 14;  // Pin utilizado para el LED
const int resolution = 10;  // Resolución PWM deseada (en bits)

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  // Configurar la resolución del PWM
  ledcSetup(0, 5000, resolution);  // Canal 0, frecuencia de 5 kHz
  ledcSetup(1, 5000, resolution);  // Canal 0, frecuencia de 5 kHz

  // Asignar el pin al canal PWM
  ledcAttachPin(ledPin1, 0);
  ledcAttachPin(ledPin2, 1);

}

void loop() {
  // Generar una señal PWM con diferentes niveles de brillo
  for (int dutyCycle = 0; dutyCycle < pow(2, resolution); dutyCycle++) {
    ledcWrite(0, dutyCycle);  // Escribir el ciclo de trabajo (0-2^resolution)
    ledcWrite(1, pow(2, resolution)-dutyCycle);  // Escribir el ciclo de trabajo (0-2^resolution)
    delay(10);  // Retardo para visualizar el cambio de brillo
  }
  for (int dutyCycle = pow(2, resolution); dutyCycle > 0; dutyCycle--) {
    ledcWrite(0, dutyCycle);  // Escribir el ciclo de trabajo (0-2^resolution)
    ledcWrite(1, pow(2, resolution)-dutyCycle);  // Escribir el ciclo de trabajo (0-2^resolution)
    delay(10);  // Retardo para visualizar el cambio de brillo
  }
}
