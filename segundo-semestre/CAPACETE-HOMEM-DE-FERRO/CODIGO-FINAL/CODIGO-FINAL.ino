#include <Servo.h>
/* LED */
int led = 13;

/* SERVO */
int pinoBotaoServo = 3; 
int ultimoEstadoBotaoServo = HIGH;
int estadoBotaoServo;

Servo servoMascara;  
int anguloServo=120;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
/* EFEITO BOUCE SERVO*/
unsigned long ultimoTempoBouncingServo = 0;
unsigned long atrasoDebounceServo = 50;

void setup() {
  pinMode(led, OUTPUT);
  servoMascara.attach(9); 
  pinMode(pinoBotaoServo, INPUT_PULLUP); 
  digitalWrite(led, HIGH);

delay(800);
digitalWrite(led, LOW);
delay(50);
digitalWrite(led, HIGH);
delay(50);
digitalWrite(led, LOW);
delay(50);
digitalWrite(led, HIGH);
delay(100);
digitalWrite(led, LOW);
delay(500);
digitalWrite(led, HIGH);
}

void loop() {

/* -------------------SERVO--------------------- */
  int leituraBotaoServo = digitalRead(pinoBotaoServo); 

  if(leituraBotaoServo != ultimoEstadoBotaoServo){
    ultimoTempoBouncingServo = millis();
  }
  if((millis()-ultimoTempoBouncingServo) > atrasoDebounceServo){
    if(leituraBotaoServo != estadoBotaoServo){
      estadoBotaoServo = leituraBotaoServo;
      if(leituraBotaoServo == LOW){
        if (anguloServo == 100) {
            anguloServo = 20;
            digitalWrite(led, LOW);
            
        } else {
            anguloServo = 100;
            digitalWrite(led, HIGH);
          }
      }
    }
  }
  servoMascara.write(anguloServo); 
  ultimoEstadoBotaoServo = leituraBotaoServo;

}

