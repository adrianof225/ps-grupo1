// verifica obstaculo

#include <Arduino.h>
#include "pinagem.hpp"
#include "locomocao.hpp"

int SENSOR_PROXIMIDADE;
int SENSOR_COR;

void destruir_Cone(){
    parar_movimento();
    digitalWrite(PINO_DESTRUIR_CONE, HIGH);
    delay(1000);      // tempo de executar a ação (ativar_arma?)
    digitalWrite(PINO_DESTRUIR_CONE, LOW);
    mover_frente();
}


void empurrar_Cone(){
    parar_movimento();
    digitalWrite(PINO_MOVER_CONE, HIGH);
    delay(1000);
    digitalWrite(PINO_MOVER_CONE, LOW);
    mover_frente();
}


void verifica_Obstaculo(){
    SENSOR_PROXIMIDADE = digitalRead(PINO_SENSOR_PROXIMIDADE);
    SENSOR_COR = digitalRead(PINO_SENSOR_CORES);

    if (SENSOR_PROXIMIDADE == HIGH) {
        if (SENSOR_COR == HIGH) {
            destruir_Cone();
        }
        else {
            empurrar_Cone();
        }
    }
}

