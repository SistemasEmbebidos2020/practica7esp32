#include <Arduino.h>
#include <driver/dac.h>

#define LED_PIN_1 25   // Pin para el primer LED
#define LED_PIN_2 26   // Pin para el segundo LED
#define DAC_CHANNEL_1 DAC_CHANNEL_1 // Canal DAC para el primer LED
#define DAC_CHANNEL_2 DAC_CHANNEL_2 // Canal DAC para el segundo LED

const int minBrightness = 0;    // Brillo mínimo
const int maxBrightness = 255;  // Brillo máximo
const int fadeSpeed = 1;        // Velocidad de cambio de brillo (mayor valor = cambio más lento)

void setup() {
  // Configurar los pines de los LEDs como salidas
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);

  // Inicializar los canales DAC
  dac_output_enable(DAC_CHANNEL_1);
  dac_output_enable(DAC_CHANNEL_2);
}

void loop() {
  // Controlar el brillo de los LEDs utilizando señales DAC

  // Aumentar el brillo del primer LED (inicia en máximo) y disminuir el brillo del segundo LED (inicia en mínimo)
  for (int brightness1 = maxBrightness, brightness2 = minBrightness; brightness1 >= minBrightness; brightness1 -= fadeSpeed, brightness2 += fadeSpeed) {
    dac_output_voltage(DAC_CHANNEL_1, brightness1);
    dac_output_voltage(DAC_CHANNEL_2, brightness2);
    delay(100);
  }

  // Aumentar el brillo del segundo LED (inicia en mínimo) y disminuir el brillo del primer LED (inicia en máximo)
  for (int brightness1 = minBrightness, brightness2 = maxBrightness; brightness2 >= minBrightness; brightness1 += fadeSpeed, brightness2 -= fadeSpeed) {
    dac_output_voltage(DAC_CHANNEL_1, brightness1);
    dac_output_voltage(DAC_CHANNEL_2, brightness2);
    delay(100);
  }
}
