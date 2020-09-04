/**
********   Simulación Compuertas Lógicas   *******
 * 
 En esta tarea del Electivo de Telemática 2, se programará la ESP32
 para realizar una tarea simple de Compuertas Lógicas, utilizando un Led RGB, 
 un potenciómetro, y dos pulsadores.

 In the next homework of "Electivo de Telemática 2", we are programmed an ESP32
 to do a simple task of Logical Gates, for this work, we usea a RGB Led, a potentiometer
 and two button switches.
 
 Autor: Mauricio Arismendi Aedo  --> m.arismendi02@ufromail.cl
 Profesor: Erik Soto Alvarado
 Asignatura: IIE208, Electivo de Telemática 2, 2020. 
      ***Universidad de La Frontera***
            *****Temuco, Chile*****
 
 */
 
//Input

int button1value_pin  = 22;
int button2value_pin  = 23;
int potentiometer1_pin = 36;

//Inicializacion

bool button1_value = 0;
bool button2_value = 0;

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

  Serial.begin(115200); //leemos en 115200 baudios
  
  //inicializamos los pulsadores como entrada y su resistencia pullup interna
  pinMode (button1value_pin, INPUT_PULLUP); 
  pinMode (button2value_pin, INPUT_PULLUP);

  //Inicializamos los RGB mediante el código dado por el fabricante

  /*Preparamos los led con los siguientes parametros:
  * Canal PWM, Frecuencia, que puede variar entre 5000 (es suficiente, para que 
  * el ojo humano no detecte la variación)
  * Resolución: de 1 a 16 bits, 8 es suficiente 
  * en nuestro caso influirá en el brillo del led
  */
 ledcSetup(ledChannel0, freq, resolution);
 ledcSetup(ledChannel1, freq, resolution);
 ledcSetup(ledChannel2, freq, resolution);

  /*Estas funciones fijan cada pin del controlador al led de destino
   * Los parámetros son: pin, channel PWM (el ESP32 tiene 16)
   */
  ledcAttachPin(greenLed, ledChannel0);
  ledcAttachPin(redLed, ledChannel1);
  ledcAttachPin(blueLed, ledChannel2);
 

}
 
void loop(){

  //lectura de pulsadores
  button1_value = digitalRead(button1value_pin);
  button2_value = digitalRead(button2value_pin);
  
 // button1value = 0;
 // button2value = 1;
  
  //Representar salida pulsador en monitor serial
//  Serial.print(button1_value);
//  Serial.print(button2_value);
  
  //lectura potenciometro
  potentiometer1_value = analogRead(potentiometer1_pin);
  
  //potentiometer1_value = 100;
  Serial.println(potentiometer1_value); //para ver el valor que toma el potenciometro en el monitor serial

 if (potentiometer1_value <= 819){ //AND
  
    if (button1_value && button2_value){ 
      color(0, 255, 255);  //ROJO
      delay(1000);      
    }
       
    else{
      color(255, 255, 255); //apagado
      delay(1000);
    }
    
  }
  
 else if ((potentiometer1_value > 819) && (potentiometer1_value <= 1638)){ //OR
    
    if (button1_value || button2_value){ 
      color(0, 255, 0);  //magenta (?)
      delay(1000);   
    }
  
    else {
      color(255, 255, 255); //apagado
      delay(1000);
  }
  }
  
  else if ((potentiometer1_value > 1638) && (potentiometer1_value <= 2457)){ //NAND
    
      if (button1_value &&  button2_value){ 
      color(255, 255, 255);  //apagado
      delay(1000);
      }
    
      else { 
      color(0, 150, 255);  //amarillo
      delay(1000);
      }
  }
  
  else if ((potentiometer1_value > 2457) && (potentiometer1_value <= 3276)){   //NOR
    
      if (button1_value || button2_value){ 
      color(255, 255, 255);  //apagado
      delay(1000);
      }
      
      else{ 
      color(255, 255, 0);  //azul
      delay(1000);
      }
  }
  
  else {                                //XOR
    if (button1_value ^ button2_value){ 
      color(255, 0, 255); //verde
      delay(1000);
      }
      
      else { 
      color(255, 255, 255); //apagado
      delay(1000);
      }
  }
}

void color(int red, int green, int blue){
  
  //Escritura de PWM verde
  ledcWrite(ledChannel0, 255-green);
  
  //Escritura de PWM rojo
  ledcWrite(ledChannel1, 255-red); 

  //Escritura de PWM azul
   ledcWrite(ledChannel2, 255-blue); 
}
