#include "UnoJoy.h"

void setup(){
  setupPins(); // Subrotina que configura os pinos do Arduino
  setupUnoJoy();// Inicializa as funções do UnoJoy
}

void loop(){
  // Sempre atualiza o dado a ser enviado ao computador
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
}

void setupPins(void){
  // Configura os pinos digitais
  for (int i = 4; i <= 7; i++){
    pinMode(i,INPUT_PULLUP);
  }
}

dataForController_t getControllerData(void){
  //  Configura local onde dados do controle são armazenados
  //  Serve para limpar o buffer onde os dados do controle são armazenados
  dataForController_t controllerData = getBlankDataForController();  
  //  Associa os pinos digitais com o botão do UnoJoy
  //  A "!" inverte a leitura (INPUT_PULLUP)
  controllerData.triangleOn = !digitalRead(4);
  controllerData.squareOn = !digitalRead(6);
  controllerData.crossOn = !digitalRead(5);
  controllerData.startOn = !digitalRead(7);
  //  Configura o joystick Analógico
  controllerData.leftStickX = map((analogRead(A0)),0,1023,0,255);
  controllerData.leftStickY = map((analogRead(A1)),0,1023,0,255);
  return controllerData;
}

