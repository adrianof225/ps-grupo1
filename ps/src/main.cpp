#include <Arduino.h>
#include "pinagem.hpp"
#include "locomocao.hpp"
#include "obstaculo.hpp"
#include "microstart.hpp"


void setup() {
  // sensor linha
  pinMode(PINO_SENSORLINHA_ESQUERDO, INPUT);
  pinMode(PINO_SENSORLINHA_DIREITO, INPUT);

  // pinos motor
  pinMode(PINO_MOTOR_ESQUERDO_1, OUTPUT);
  pinMode(PINO_MOTOR_ESQUERDO_2, OUTPUT);
  pinMode(PINO_MOTOR_DIREITO_1, OUTPUT);
  pinMode(PINO_MOTOR_DIREITO_2, OUTPUT);

  // pinos atuador
  pinMode(PINO_DESTRUIR_CONE, OUTPUT);
  pinMode(PINO_MOVER_CONE, OUTPUT);

  // pino sensor cor e aproximidade
  pinMode(PINO_SENSOR_CORES, INPUT);
  pinMode(PINO_SENSOR_PROXIMIDADE, INPUT);

  // pino failsafe
  pinMode(PINO_MICROSTART, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  failsafe();
  SENSOR_LINHA_DIREITO = digitalRead(PINO_SENSORLINHA_DIREITO);
  SENSOR_LINHA_ESQUERDO = digitalRead(PINO_SENSORLINHA_ESQUERDO);
  seguir_linha();
  verifica_Obstaculo();
  delay(1000);
}
