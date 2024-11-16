#include <Arduino.h>
#include "pinagem.hpp"
#include "locomocao.hpp"

void microstart(){
    if (PINO_MICROSTART == HIGH){
        parar_movimento();
    else{
            seguir_linha();
        }
    }
}