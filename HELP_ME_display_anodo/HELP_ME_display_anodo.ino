int a = 13;//Correspondente ao LED a
int b = 12;//Correspondente ao LED b
int c = 11;//Correspondente ao LED c
int d = 10;//Correspondente ao LED d
int e = 9;//Correspondente ao LED e
int f = 8;//Correspondente ao LED f
int g = 7;//Correspondente ao LED g
char letra;
char palavra[5]= "HELP";

void setup() {
  pinMode(a, OUTPUT);//Define a como saída
  pinMode(b, OUTPUT);//Define b como saída
  pinMode(c, OUTPUT);//Define c como saída
  pinMode(d, OUTPUT);//Define d como saída
  pinMode(e, OUTPUT);//Define e como saída
  pinMode(f, OUTPUT);//Define f como saída
  pinMode(g, OUTPUT);//Define g como saída
  Serial.begin(9600);//Inicia a comunicação serial
}

//Função para apagar
void espaco() {
  digitalWrite(a, 1);//coloca a em nível alto
  digitalWrite(b, 1);//coloca b em nível baixo
  digitalWrite(c, 1);//coloca c em nível baixo
  digitalWrite(d, 1);//coloca d em nível alto
  digitalWrite(e, 1);//coloca e em nível baixo
  digitalWrite(f, 1);//coloca f em nível baixo
  digitalWrite(g, 1);//coloca g em nível baixo
  delay(100);
}

//Função para escrever o "H"
void letraH() {
  digitalWrite(a, 1);//coloca a em nível alto
  digitalWrite(b, 0);//coloca b em nível baixo
  digitalWrite(c, 0);//coloca c em nível baixo
  digitalWrite(d, 1);//coloca d em nível alto
  digitalWrite(e, 0);//coloca e em nível baixo
  digitalWrite(f, 0);//coloca f em nível baixo
  digitalWrite(g, 0);//coloca g em nível baixo
  delay(100);
}
//Função para escrever o "E"
void letraE() {
  digitalWrite(a, 0);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  delay(100);
}
//Função para escrever o "L"
void letraL() {
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 1);
  delay(100);
}
//Função para escrever o "P"
void letraP() {
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  delay(100);
}

void loop() {

  for(int i = 0; i<= 3; i++){
    letra = palavra[i];
  
  switch (letra) {
    case 'H':
      letraH();
      break;
    case 'E':
      letraE();
      break;
    case 'L':
      letraL();
      break;
    case 'P':
      letraP();
      break;
  }
  Serial.println(letra);
  delay(250);
  }
  espaco();
  delay(700);
}
