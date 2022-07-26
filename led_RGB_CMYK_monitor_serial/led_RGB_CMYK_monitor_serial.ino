int vermelho = 12;
int verde = 10;
int azul = 9;
char cor = 0;

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  Serial.begin(9600);
}
void loop() {

  if (Serial.available()) {
    cor = Serial.read();
    Serial.println(cor);
  }
    switch (cor) {
      case '1':
        Vermelho();
        break;

      case '2':
        Verde();
        break;

      case '3':
        Azul();
        break;

      case '4':
        Branco();
        break;

      case '5':
        Magenta();
        break;

      case '6':
        Amarelo();
        break;

      case '7':
        Ciano();
        break;

      default:
        Desligado();
        break;
    }
  }

void Vermelho() {
  digitalWrite(vermelho, HIGH);//Coloca vermelho em nível alto, ligando-o
  delay(1000);//Intervalo de 1 segundo
  digitalWrite(vermelho, LOW);//Coloca vermelho em nível baixo
}
void Verde() {
  digitalWrite(verde, HIGH);//Coloca verde em nível alto
  delay(1000);//Intervalo de 1 segundo
  digitalWrite(verde, LOW);//Coloca verde em nível baixo
}
void Azul() {
  digitalWrite(azul, HIGH);//Coloca azul em nível alto
  delay(1000);//Intervalo de 1 segundo
  digitalWrite(azul, LOW);//Coloca azul em nível baixo
}
void Branco() {
  digitalWrite(azul, HIGH);//Coloca azul em nível alto
  digitalWrite(vermelho, HIGH);//Coloca vermelho em nível alto
  digitalWrite(verde, HIGH);//Coloca verde em nível alto, ligando-o
  delay(1000);//Intervalo de 1 segundo
  digitalWrite(azul, LOW);//Coloca azul em nível baixo
  digitalWrite(vermelho, LOW);//Coloca vermelho em nível baixo
  digitalWrite(verde, LOW);//Coloca verde em nível baixo
}
void Magenta() {
  digitalWrite(azul, HIGH);//Coloca azul em nível alto
  digitalWrite(vermelho, HIGH);//Coloca vermelho em nível alto
  delay(1000);//Intervalo de 1 segundo
  digitalWrite(azul, LOW);//Coloca azul em nível baixo
  digitalWrite(vermelho, LOW);//Coloca vermelho em nível baixo
}
void Amarelo() {
  digitalWrite(verde, HIGH);//Coloca verde em nível alto
  digitalWrite(vermelho, HIGH);//Coloca vermelho em nível alto
  delay(1000);//Intervalo de 1 segundo
  digitalWrite(verde, LOW);//Coloca verde em nível baixo
  digitalWrite(vermelho, LOW);//Coloca vermelho em nível baixo
}
void Ciano() {
  digitalWrite(verde, HIGH);//Coloca verde em nível alto
  digitalWrite(azul, HIGH);//Coloca azul em nível baixo alto
  delay(1000);//Intervalo de 1 segundo
  digitalWrite(verde, LOW);//Coloca verde em nível baixo
  digitalWrite(azul, LOW);//Coloca azul em nível baixo
}
//Função desligado
void Desligado() {
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, LOW);
  digitalWrite(azul, LOW);
}
