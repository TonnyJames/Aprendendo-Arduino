int a = 13;//Correspondente ao LED a
int b = 12;//Correspondente ao LED b
int c = 11;//Correspondente ao LED c
int d = 10;//Correspondente ao LED d
int e = 9;//Correspondente ao LED e
int f = 8;//Correspondente ao LED f
int g = 7;//Correspondente ao LED g
int buttonPin = 2;//Correspondente ao botão
int leitura = 0;//Leitura do botão
int ultleitura = 0;//Última leitura do botão
int contador = 0;//Correspondente ao contador

void setup() {
  pinMode(a, OUTPUT);//Define a como saída
  pinMode(b, OUTPUT);//Define b como saída
  pinMode(c, OUTPUT);//Define c como saída
  pinMode(d, OUTPUT);//Define d como saída
  pinMode(e, OUTPUT);//Define e como saída
  pinMode(f, OUTPUT);//Define f como saída
  pinMode(g, OUTPUT);//Define g como saída
  pinMode(buttonPin, INPUT);//Define buttonPin como entrada
  Serial.begin(9600);//Inicia a comunicação serial
}

//Função para escrever o no zero
void zero() {
  digitalWrite(a, 0);//coloca a em nível baixo
  digitalWrite(b, 0);//coloca b em nível baixo
  digitalWrite(c, 0);//coloca c em nível baixo
  digitalWrite(d, 0);//coloca d em nível baixo
  digitalWrite(e, 0);//coloca e em nível baixo
  digitalWrite(f, 0);//coloca f em nível baixo
  digitalWrite(g, 1);//coloca g em nível alto
  delay(100);
}
//Função para escrever o no um
void um() {
  digitalWrite(a, 1);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 1);
  delay(100);
}
//Função para escrever o no dois
void dois() {
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 1);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 1);
  digitalWrite(g, 0);
  delay(100);
}
//Função para escrever o no três
void tres() {
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 0);
  delay(100);
}
//Função para escrever o no quatro
void quatro() {
  digitalWrite(a, 1);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  delay(100);
}
//Função para escrever o no cinco
void cinco() {
  digitalWrite(a, 0);
  digitalWrite(b, 1);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 1);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  delay(100);
}
//Função para escrever o no seis
void seis() {
  digitalWrite(a, 0);
  digitalWrite(b, 1);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  delay(100);
}
//Função para escrever o no sete
void sete() {
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 1);
  delay(100);
}
//Função para escrever o no oito
void oito() {
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  delay(100);
}
//Função para escrever o no nove
void nove() {
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 1);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  delay(100);
}

void loop() {
  leitura = digitalRead(buttonPin);//Lê o estado de buttonPin e armazena em leitura
  if (leitura != ultleitura) { // Compara a leitura do botão com a leitura anterior
    if (leitura == HIGH) { //Se leitura for igual a HIGH
      contador++;//Incrementa contador em 1
    }
  }
  ultleitura = leitura;//Atribui a ultleitura o conteúdo de leitura
  switch (contador) {
    case 0:
      zero();//Executa a função zero
      break;
    case 1:
      um();//Executa a função um
      break;
    case 2:
      dois();//Executa a função dois
      break;
    case 3:
      tres();//Executa a função três
      break;
    case 4:
      quatro();//Executa a função quatro
      break;
    case 5:
      cinco();//Executa a função cinco
      break;
    case 6:
      seis();//Executa a função seis
      break;
    case 7:
      sete();//Executa a função sete
      break;
    case 8:
      oito();//Executa a função oito
      break;
    case 9:
      nove();//Executa a função nove
      break;
  }
  Serial.println(contador);//Imprime na serial o conteúdo de contador
  if (contador >= 10) { //Se contador for maior ou igual a 10
    contador = 0;//Retorna contador a zero
  }
}
