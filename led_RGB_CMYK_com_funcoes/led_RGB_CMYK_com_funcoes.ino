int vermelho = 12;
int verde = 10;
int azul = 9;

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
}
void loop() {
Vermelho();//Função para acionamento na cor vermelha
Verde();//Função para acionamento na cor verde
Azul();//Função para acionamento na cor azul
Branco();//Função para acionamento na cor branca
Magenta();//Função para acionamento na cor magenta
Amarelo();//Função para acionamento na cor amarela
Ciano();//Função para acionamento na cor ciano
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
