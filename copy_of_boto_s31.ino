const int pinoLed1 = 4;
const int pinoLed2 = 3;
const int pinoBotao = 9;

int estado = 0;
bool botaoAnterior = HIGH;

void setup()
{
  Serial.begin(9600);

  pinMode(pinoLed1, OUTPUT);
  pinMode(pinoLed2, OUTPUT);

  pinMode(pinoBotao, INPUT_PULLUP);
}

void loop()
{
  bool botaoAtual = digitalRead(pinoBotao);

  // Detecta um novo aperto do botão
  if (botaoAnterior == HIGH && botaoAtual == LOW)
  {
    estado++;

    if (estado > 3)
    {
      estado = 1;
    }

    // 1º estado: LED 1 ligado
    if (estado == 1)
    {
      digitalWrite(pinoLed1, HIGH);
      digitalWrite(pinoLed2, LOW);
      Serial.println("LED 1 ligado");
    }

    // 2º estado: LED 1 desligado e LED 2 ligado
    if (estado == 2)
    {
      digitalWrite(pinoLed1, LOW);
      digitalWrite(pinoLed2, HIGH);
      Serial.println("LED 1 desligado, LED 2 ligado");
    }

    // 3º estado: os dois desligados
    if (estado == 3)
    {
      digitalWrite(pinoLed1, LOW);
      digitalWrite(pinoLed2, LOW);
      Serial.println("LED 2 desligado");
    }

    delay(200);
  }

  botaoAnterior = botaoAtual;
}