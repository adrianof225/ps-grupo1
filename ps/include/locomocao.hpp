// código locomoção

#include <Arduino.h>
#include "pinagem.hpp"

const int VELOCIDADE = 150;
int SENSOR_LINHA_ESQUERDO;
int SENSOR_LINHA_DIREITO;


void mover_frente() { 
    analogWrite(PINO_MOTOR_ESQUERDO_1, VELOCIDADE);
    analogWrite(PINO_MOTOR_ESQUERDO_2, 0);
    analogWrite(PINO_MOTOR_DIREITO_1, VELOCIDADE);
    analogWrite(PINO_MOTOR_DIREITO_2, 0);
}


void mover_esquerda() { 
    analogWrite(PINO_MOTOR_ESQUERDO_1, 0);
    analogWrite(PINO_MOTOR_ESQUERDO_2, VELOCIDADE);
    analogWrite(PINO_MOTOR_DIREITO_1, VELOCIDADE);
    analogWrite(PINO_MOTOR_DIREITO_2, 0);
}


void mover_direita() { 
    analogWrite(PINO_MOTOR_ESQUERDO_1, VELOCIDADE);
    analogWrite(PINO_MOTOR_ESQUERDO_2, 0);
    analogWrite(PINO_MOTOR_DIREITO_1, 0);
    analogWrite(PINO_MOTOR_DIREITO_2, VELOCIDADE);
}


void parar_movimento() { 
    analogWrite(PINO_MOTOR_ESQUERDO_1, 0);
    analogWrite(PINO_MOTOR_ESQUERDO_2, 0);
    analogWrite(PINO_MOTOR_DIREITO_1, 0);
    analogWrite(PINO_MOTOR_DIREITO_2, 0);
}


void seguir_linha(){
    if (SENSOR_LINHA_DIREITO == HIGH && SENSOR_LINHA_ESQUERDO == HIGH){
        mover_frente();
    } else if (SENSOR_LINHA_DIREITO == HIGH && SENSOR_LINHA_ESQUERDO == LOW){
        mover_direita();
        } else if (SENSOR_LINHA_DIREITO == LOW && SENSOR_LINHA_ESQUERDO == HIGH){
        mover_esquerda();}
}
