// leituras mais baixas e mais altas do sensor:
const int sensorMin = 0;     // Sensor minimo
const int sensorMax = 1024;  // Sensor maximo
int buzzer = 8; //Atribui o valor 8 a variavel buzzer, que representa o pino digital 8, onde o buzzer está conectado

void setup()   {
  pinMode(buzzer, OUTPUT); //Definindo o pino buzzer como de saída.
  Serial.begin(9600);   
}

void loop() {
  // Ler o sensor no analógico A2:
  int sensorReading   = analogRead(A2);
  // Mapeia o alcance do sensor (quatro opções):
  // Ex: 'long   int map(long int, long int, long int, long int, long int)'
  int range = map(sensorReading,   sensorMin, sensorMax, 0, 3);
  
  // Valor do intervalo:
  switch (range) {
   case 0:    // Uma chama a menos de 50 centímetros de distância.
    Serial.println("** Close   Fire **");
    tone(buzzer, 1500);//Ligando o buzzer com uma frequencia de 1500 hz.
    delay(1000);//Intervalo de 500 milissegundos
    noTone(buzzer);  //Desligando o buzzer.
    break;
    
  case 1:    // Uma chama a mais de 50 centímetros de distância.
    Serial.println("**   Distant Fire **");
    break;
    
  case 2:    // Chama não indentificada
    Serial.println("No   Fire");
    break;
  }
  delay(10);  // delay após leitura
}
