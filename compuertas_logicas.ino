/**
********   Simulación Compuertas Lógicas   *******
 * 
 * 
 * 
 */
 
//Input

int button1value_pin  = 22;
int button2value_pin  = 23;
int potentiometer1_pin = 36;

//Inicializacion

int button1_value = 0;
int button2_value = 0;

int potentiometer1_value;

// output

// --- RGB ---
int greenLed = 12; 
int redLed   = 13; 
int blueLed  = 17;

// Propiedades de la señal a usar 
int freq = 5000;
int ledChannel0 = 0;
int ledChannel1 = 1;
int ledChannel2 = 2;

int resolution = 8; 

void setup(){
  
//Ahora sí configuramos entradas y salidas con pinmode:

  Serial.begin(115200);
  pinMode (button1value_pin, INPUT);
  pinMode (button2value_pin, INPUT);

  
  ledcAttachPin(greenLed, ledChannel0);
  ledcAttachPin(redLed, ledChannel1);
  ledcAttachPin(blueLed, ledChannel2);
 
 ledcSetup(ledChannel0, freq, resolution);
 ledcSetup(ledChannel1, freq, resolution);
 ledcSetup(ledChannel2, freq, resolution);

  digitalWrite(greenLed, HIGH);
  digitalWrite(redLed, HIGH);
  digitalWrite(blueLed, HIGH);
  delay(1000);
}
 
void loop(){
  
  //lectura de pulsadores
  button1_value = digitalRead(button1value_pin);
  button2_value = digitalRead(button2value_pin);
  
 // button1value = 0;
 // button2value = 1;
  
  //Representar salida pulsador en monitor serial
  //Serial.print(button1value);
  //Serial.print(button2value);
  
  //lectura potenciometro
  potentiometer1_value = analogRead(potentiometer1_pin);
  
  //potentiometer1_value = 100;
  Serial.println(potentiometer1_value); //para ver el valor que toma el potenciometro en el monitor serial
  delay(500);

  if ((potentiometer1_value >= 0) && (potentiometer1_value <= 819)){ //AND
    
    if (button1_value == 0 && button2_value == 0){ 
      color(0, 0, 0);  //apagado
      delay(1000);    
    }
    
    else if (button1_value == 0 && button2_value == 1){ 
      color(0, 0, 0);  //apagado
      delay(1000);     
    }
    
    else if (button1_value == 1 && button2_value == 0){
      color(0, 0, 0);  //apagado
      delay(1000);
    }
    
    else {
      color(255, 0, 0);  //color rojo
      delay(1000);
    }
  }
  
 /* else if (potentiometer1_value > 819 && potentiometer1_value <= 1638 ){ //OR
    
    if (button1_value == 0 && button2_value == 0){ 
      color(0, 0, 0);  //apagado
      delay(1000);   
    }
    
    else if (button1_value == 1 && button2_value == 0){ 
      color(255, 0, 255); //color magenta?
      delay(1000);     
    }
    
    else if (button1_value == 0 && button2_value == 1){
      color(255, 0, 255);//color magenta?
      delay(1000);
    }
    
    else {
      color(255, 0, 255); //color magenta?
      delay(1000);
  }
  }
  
  else if (potentiometer1_value > 1638 && potentiometer1_value <= 2457){ //NANDEEEKUREWAAAAAA!!!
    
      if (button1_value == 0 && button2_value == 0){ 
      color(255, 255, 0);  //amarillo?
      delay(1000);
      }
      else if (button1_value == 0 && button2_value == 1){ 
      color(255, 255, 0);  //amarillo?
      delay(1000);
      }
      else if (button1_value == 1 && button2_value == 0){ 
      color(255, 255, 0);  //amarillo?
      delay(1000);
      }
      else { 
      color(0, 0, 0);  //apagado
      delay(1000);
       }
  }
  
  else if (potentiometer1_value > 2457 && potentiometer1_value <= 3276){//NOR
    
      if (button1_value == 0 && button2_value == 0){ 
      color(0, 0, 255);  //azul
      delay(1000);
      }
      
      else if (button1_value == 0 && button2_value == 1){ 
      color(0, 0, 0);  //apagado
      delay(1000);
      }
      
      else if (button1_value == 1 && button2_value == 0){ 
      color(0, 0, 0);  //apagado
      delay(1000);
      }
      
      else { 
      color(0, 0, 0);  //apagado
      delay(1000);
      }
  }
  
  else { //XOR
    if (button1_value == 0 && button2_value == 0){ 
      color(0, 0, 255);  //apagado
      delay(1000);
      }
      
      else if (button1_value == 0 && button2_value == 1){ 
      color(0, 255, 0);  //verde
      delay(1000);
      }
      
      else if (button1_value == 1 && button2_value == 0){ 
      color(0, 255, 0);  //verde
      delay(1000);
      }
      
      else { 
      color(0, 0, 0);  //apagado
      delay(1000);
      }
  } */
}

void color(int red, int green, int blue){
  
  //Escritura de PWM verde
  ledcWrite(ledChannel0, 255-green);
  
  //Escritura de PWM rojo
  ledcWrite(ledChannel1, 255-red); 

  //Escritura de PWM azul
   ledcWrite(ledChannel2, 255-blue); 
}
