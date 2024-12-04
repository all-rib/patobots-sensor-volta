int sensorInicial = 6;  // Pino de leitura do sensor inicial
int sensorFinal = 7;    // Pino de leitura do sensor final
unsigned long startTime = 0;
unsigned long endTime = 0;
bool lap = 0;
bool final = 0;
unsigned long tempo ;

void setup() {
  pinMode(sensorInicial, INPUT);
  pinMode(sensorFinal, INPUT);

  Serial.begin(9600);  // Inicia a comunicação serial
}

void loop() {
  if (final == 0){ //Chave para ele só atualizar o end time quando ainda não finalizou a corrida para mostrar o tempo rodando.
  endTime = millis();
  }
  tempo = endTime - startTime; // calcula o tempo

  if (digitalRead(sensorInicial) == HIGH && lap == 0) { // Começa a contagem do tempo
    startTime = millis();
    lap = 1;
  }

  if (digitalRead(sensorFinal) == HIGH && lap == 1) { // Finalização da volta
    if (final == 0){ // Pega o ultimo tempo
          endTime = millis();
          final = 1;
    }
    tempo = endTime - startTime; //Calcula "pela ultima vez"
    Serial.print("Tempo: ");
    Serial.print(tempo / 1000.0, 2);
    Serial.println(" s");
    if(final == 1){ //Se foi o final, ele reseta os parametros para o próximo carro
      delay(1000);
      endTime =0; 
      startTime = 0;
      final = 0;
      lap = 0;
      
    }

  }
  if (lap == 1){ // Se algum carro estiver dando volta continua a printar o tempo
    Serial.print("Tempo: ");
    Serial.print(tempo / 1000.0, 2);
    Serial.println(" s");
  }
}
