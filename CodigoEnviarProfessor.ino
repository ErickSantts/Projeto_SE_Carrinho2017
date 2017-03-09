#define PinoS3E 2 //PinoS3E. S = Sensor, 3 = Identificador, E = tipo (Entrada/Saida)
#define PinoS3S 3

#define PinoS2E 4
#define PinoS2S 5

#define PinoS1E 6
#define PinoS1S 7
long duracion, distanciaS1, distanciaS2, distanciaS3;   
//variaveis que vão guardar duração, e distancias dos sensores
  
void setup() {                
  Serial.begin (9600);       
  pinMode(PinoS1E, INPUT);     // definição dos pinos de entrada e saida, na legenda a cima da para entender
  pinMode(PinoS1S, OUTPUT);    
  
  pinMode(PinoS2E, INPUT);     
  pinMode(PinoS2S, OUTPUT);    
                              //por exemplo
  pinMode(PinoS3E, INPUT);     // Input e entrada do sensor 3
  pinMode(PinoS3S, OUTPUT);    // Output e a saida do sensor 3
  
  
  pinMode(13, 1);            
  pinMode(12, 1);           // Define a saida porta 12 como motor 2 e porta 13 como motor 1
  
  }
  
void loop() {
  //Calculo sensor 1
  digitalWrite(PinoS1S, LOW);
  delayMicroseconds(2);
  digitalWrite(PinoS1S, HIGH);   // gera pulso de 10ms
  delayMicroseconds(10);
  digitalWrite(PinoS1S, LOW);
  
  duracion = pulseIn(PinoS1E, HIGH);
  distanciaS1 = (duracion/2) / 29;  // calcula a distancia em centimetros

  //Calculo sensor 2
  digitalWrite(PinoS2S, LOW);
  delayMicroseconds(2);
  digitalWrite(PinoS2S, HIGH);   // repete o processo pros demais sensores
  delayMicroseconds(10);
  digitalWrite(PinoS2S, LOW);
  
  duracion = pulseIn(PinoS2E, HIGH);
  distanciaS2 = (duracion/2) / 29;

  //Calculo sensor 3
  digitalWrite(PinoS3S, LOW);
  delayMicroseconds(2);
  digitalWrite(PinoS3S, HIGH);   
  delayMicroseconds(10);
  digitalWrite(PinoS3S, LOW);
  
  duracion = pulseIn(PinoS3E, HIGH);
  distanciaS3 = (duracion/2) / 29;
  
  if (distanciaS1 > 20 || distanciaS1 <= 0){  // se a distancia e maior que 20 cm, imprime todas as distancias 
             Serial.println(distanciaS1);
             Serial.println("cm Sensor1");
             Serial.println(distanciaS2);
             Serial.println("cm Sensor2");
             Serial.println(distanciaS3);
             Serial.println("cm Sensor3"); 
    Serial.println("cm Livre ");
    digitalWrite(13, 1);                     // Liga os dois motores
    digitalWrite(12, 1);                     
    // continua a andar
  }
  
  if (distanciaS1 <= 20 && distanciaS1 >= 1){ //se menor desliga os motores
    digitalWrite(13, 0);
    digitalWrite(12, 0);
    Serial.println("Alarma.......");
   
      if (distanciaS2 < distanciaS3){ // calcula a distancia para decidir para que lado dobrar
             Serial.println(distanciaS1);
             Serial.println("cm Sensor1");
             Serial.println(distanciaS2);
             Serial.println("cm Sensor2");
             Serial.println(distanciaS3);
             Serial.println("cm Sensor3"); 
             digitalWrite(12, 0); // liga um dos motores.
             digitalWrite (12,1);

      }
      
      if (distanciaS3 < distanciaS2){   //mesma coisa, so que inverte os motores, ou sej aqual vai ser desligado e qual ligado.           
             Serial.println(distanciaS1);
             Serial.println("cm Sensor1");
             Serial.println(distanciaS2);
             Serial.println("cm Sensor2");
             Serial.println(distanciaS3);
             Serial.println("cm Sensor3");
             digitalWrite (13, 0);
      digitalWrite (13,1);
     }
     }
  delay(100);                                // espera 100ms
}
