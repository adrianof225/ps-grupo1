#include <Arduino.h>
#include "pinagem.hpp"
#include "locomocao.hpp"
#include "obstaculo.hpp"
#include "microstart.hpp"

int Kp = 0;
int Kd = 0;
int Ki = 0;


" float calcular(float erro){
    float proporcional = _Kp * erro;
    _integral += Kp * erro;
    float derivativo = _Kd * (erro - _erroAnterior);

    _erroAnterior = erro;

    return proporcional + _integral + derivativo;
}

void resetar(){
    _integral = 0.;
    _erroAnterior = 0.;
}"

void controle_pid(){

}