//ENTRADAS
int butRed = A5;//Atribui a porta A5 a variável butRed - botão vermelho
int butYel = A4;//Atribui a porta A4 a variável butYel - botão amarelo
int butGre = A3;//Atribui a porta A3 a variável butGre - botão verde
//SAÍDAS
//Led
int ledRed = 13;//Atribui a porta 13 a variável ledRed - LED vermelho
int ledYel = 12;//Atribui a porta 12 a variável ledYel - LED amarelo
int ledGre = 11;//Atribui a porta 11 a variável ledGre - LED verde
//Display
int a = 4;//Atribui a porta 4 a variável "a" - segmento a do display
int b = 5;//Atribui a porta 5 a variável "b" - segmento b do display
int c = 6;//Atribui a porta 6 a variável "c" - segmento c do display
int d = 7;//Atribui a porta 7 a variável "d" - segmento d do display
int e = 8;//Atribui a porta 8 a variável "e" - segmento e do display
int f = 9;//Atribui a porta 9 a variável "f" - segmento f do display
int g = 10;//Atribui a porta 10 a variável "g" - segmento g do display
//Buzzer
int buzzerPin = 3;//Atribui a porta 3 a variável buzzerPin - buzzer
//Tons botões
#define tomRed 294//Tom para LED vermelho
#define tomYel 330//Tom para LED amarelo
#define tomGre 350//Tom para LED verde
//VARIÁVEIS
int rodada = 0;//Variável que armazenará o número de rodadas
int led = 0;//Variável que armazenará o valor randômico que representará o LED que estará ligado
int temp_led_ligado = 600;//Tempo em que o LED deve estar ligado
int temp_led_desligado = 100;//Tempo em que o LED deve estar desligado
int mat[10];//Vetor de 10 posições que armazenará a sequência
int posi_mat = 0;//Posição do vetor
void setup() {
  //Configuração dos pinos de entrada
  pinMode(butRed, INPUT);
  pinMode(butYel, INPUT);
  pinMode(butGre, INPUT);
  //Configuração dos pinos de saída
  pinMode(ledRed, OUTPUT);
  pinMode(ledYel, OUTPUT);
  pinMode(ledGre, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  //Inicialização da comunicação serial
  Serial.begin(9600);
  //Função randômica
  randomSeed(analogRead(A0));//Pega como referência um valor aleatório do canal analógico para gerar os valores randômicos
  inicio();//Chama a função início
}
void loop() {
  led = random(0, 3);//Gera o valor aleatório entre 0 e 2
  mat[posi_mat] = led;//Guarda o valor gerado no vetor
  switch (posi_mat) {//Liga o display conforme posição do vetor (nível do jogo)
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
  for (int j = 0; j <= posi_mat; j++) {//Mostra a sequência dos LEDs sempre que passar o nível
    switch (mat[j]) {//Liga o LED correspondente a valor que está no vetor na posição j
      case 0:
        digitalWrite(ledGre, HIGH);//Liga LED verde
        analogWrite(buzzerPin, tomGre);//Emite tom para LED verde
        delay(200);//Intervalo de 200 milissegundos
        digitalWrite(buzzerPin, LOW);//Desliga buzzer
        delay(temp_led_ligado);
        digitalWrite(ledGre, LOW);//Desliga LED verde
        delay (temp_led_desligado);
        break;
      case 1:
        digitalWrite(ledYel, HIGH);//Liga LED amarelo
        analogWrite(buzzerPin, tomYel);//Emite tom para LED amarelo
        delay(200);//Intervalo de 200 milissegundos
        digitalWrite(buzzerPin, LOW);//Desliga buzzer
        delay(temp_led_ligado);
        digitalWrite(ledYel, LOW);//Desliga LED amarelo
        delay (temp_led_desligado);
        break;
      case 2:
        digitalWrite(ledRed, HIGH);//Liga LED vermelho
        analogWrite(buzzerPin, tomRed);//Emite tom para LED vermelho
        delay(200);//Intervalo de 200 milissegundos
        digitalWrite(buzzerPin, LOW);//Desliga buzzer
        delay(temp_led_ligado);
        digitalWrite(ledRed, LOW);//Desliga LED vermelho
        delay (temp_led_desligado);
        break;
      default:
        break;
    }
  }
  int temp = 0;//Variável temporária utilizada para aguardar o jogador digitar a sequência fornecida pelo jogo
  while (temp <= posi_mat) {
    if (digitalRead(butGre) == HIGH) {//Se butGre for nível alto - botão verde pressionado
      digitalWrite(ledGre, HIGH);//Liga LED verde
      analogWrite(buzzerPin, tomGre);//Emite tom para LED verde
      delay(100);//Intervalo de 100 milissegundos
      digitalWrite(buzzerPin, LOW);//Desliga buzzer
      while (digitalRead(butGre) == HIGH);//Enquanto o botão verde estiver pressionado não faz nada
      digitalWrite(ledGre, LOW);//Desliga o LED verde
      delay(200);//Intervalo de 200 milissegundos
      if ( mat[temp] == 0) {//Se na posição do vetor é verdadeiro (igual a zero)
        temp = temp + 1;//Incrementa a variável temp para dar continuidade na sequência do jogo
        } else//Se não
      {
        Serial.println("ERRO!!!!!");//Imprime na serial Erro
        posi_mat = 11;//Atribui 11 na variável posi_mat
        break;
      }
    }
    if (digitalRead(butYel) == HIGH) {//Se butYel for nível alto - botão amarelo pressionado
      digitalWrite(ledYel, HIGH);//Liga led amarelo
      analogWrite(buzzerPin, tomYel);//Emite tom para LED amarelo
      delay(100);//Intervalo de 100 milissegundos
      digitalWrite(buzzerPin, LOW);//Desliga buzzer
      while (digitalRead(butYel) == HIGH);//Enquanto o botão amarelo estiver pressionado não faz nada
      digitalWrite(ledYel, LOW);
      delay(200);
      if ( mat[temp] == 1) {//Se na posição do vetor é verdadeiro (igual a zero)
        temp = temp + 1;
      } else
      {
        Serial.println("ERRO!!!!!");
        posi_mat = 11;//Atribui 11 na variável posi_mat
        break;
      }
    }
    if (digitalRead(butRed) == HIGH) {//Se butRed for nível alto - botão vermelho pressionado
      digitalWrite(ledRed, HIGH);//Liga led vermelho
      analogWrite(buzzerPin, tomRed);//Emite tom para led vermelho
      delay(100);//Intervalo de 100 milissegundos
      digitalWrite(buzzerPin, LOW);//Desliga buzzer
      while (digitalRead(butRed) == HIGH);
      digitalWrite(ledRed, LOW);
      delay(200);
      if ( mat[temp] == 2) {
        temp = temp + 1;
      } else
      {
        Serial.println("ERRO!!!!!");//Imprime na serial "ERRO!!!!!"
        posi_mat = 11;//Atribui 11 na variável posi_mat
        break;
      }
    }
  }
  posi_mat = posi_mat + 1;
  if (posi_mat == 10) {//Se a posi_mat for igual a 10
    ganhou();//Chama a função ganhou()
    Serial.println("Parabens voce venceu ");//Imprime no serial "Parabens voce venceu"
    posi_mat = 0;//Atribui 0 a variável posi_mat para reiniciar o jogo
    Serial.println("INICIO DE JOGO");//Imprime no serial "INICIO DE JOGO"
  }
  if (posi_mat >= 11) {//Se posi_mat for maior ou igual a 11
    Serial.println(" ---- >>> FIM DE JOGO <<< ----");//Imprime no serial " ---- >>> FIM DE JOGO <<< ----"
    perdeu();//Chama a função perdeu
    posi_mat = 0;//Atribui 0 a variável posi_mat para reiniciar o jogo
    Serial.println("INICIO DE JOGO");//Imprime no serial "INICIO DE JOGO"
    delay(3000);//Intervalo de 3 segundos
  }
  }
    //Função para escrever os números no display
    void zero() {
    digitalWrite(a, 0);
    digitalWrite(b, 0);
    digitalWrite(c, 0);
    digitalWrite(d, 0);
    digitalWrite(e, 0);
    digitalWrite(f, 0);
    digitalWrite(g, 1);
    delay(100);
  }
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
    void inicio() {
    for (int y = 0; y < 2; y++) {//Repetir duas vezes
    tone(buzzerPin, 330, 200);//Frequência e duração da nota Mi
    digitalWrite(ledRed, HIGH);//Liga o LED vermelho
    delay(100);//Intervalo de 200 milissegundos
    tone(buzzerPin, 330, 200);//Frequência e duração da nota Mi
    digitalWrite(ledYel, HIGH);//Liga o LED amarelo
    delay(100);//Intervalo de 200 milissegundos
    tone(buzzerPin, 330, 200);//Frequência e duração da nota Mi
    digitalWrite(ledGre, HIGH);//Liga o LED verde
    delay(100);//Intervalo de 300 milissegundos
    tone(buzzerPin, 262, 300);//Frequência e duração da nota Dó
    delay(100);//Intervalo de 200 milissegundos
    digitalWrite(ledRed, LOW);//Desliga o LED vermelho
    digitalWrite(ledYel, LOW);//Desliga o LED amarelo
    digitalWrite(ledGre, LOW);//Desliga o LED verde
    delay(500);//Intervalo de 0,5 segundos
  }
  }
    void perdeu() {
    for (int x = 0; x < 3; x++) {//Repetir 3 vezes
    for (int z = 0; z < 3; z++) {//Repetir 2 vezes
    tone(buzzerPin, 262, 200);//Frequência e duração da nota Dó
    digitalWrite(ledRed, HIGH);//Liga LED vermelho
    digitalWrite(ledYel, HIGH);//Liga LED amarelo
    digitalWrite(ledGre, HIGH);//Liga LED verde
    delay(250);//Intervalo de 250 milissegundos
    digitalWrite(ledRed, LOW);//Desliga o LED vermelho
    digitalWrite(ledYel, LOW);//Desliga o LED amarelo
    digitalWrite(ledGre, LOW);//Desliga o LED verde
  }
    tone(buzzerPin, 528, 300);//Frequência e duração da nota Dó
    delay(100);//Intervalo de 100 milissegundos
  }
  }
    void ganhou() {
    for (int w = 0; w < 2; w++) {//Repetir 2 vezes
    tone(buzzerPin, 440, 200);//Frequência e duração da nota Lá
    digitalWrite(ledRed, HIGH);//Liga led vermelho
    digitalWrite(ledYel, HIGH);//Liga led amarelo
    digitalWrite(ledGre, HIGH);//Liga led verde
    delay(250);//Intervalo de 250 milissegundos
    digitalWrite(ledRed, LOW);//Desliga led vermelho
    digitalWrite(ledYel, LOW);//Desliga led amarelo
    digitalWrite(ledGre, LOW);//Desliga led verde
    tone(buzzerPin, 495, 200);//Frequência e duração da nota Si
    digitalWrite(ledRed, HIGH);//Liga led vermelho
    digitalWrite(ledYel, HIGH);//Liga led amarelo
    digitalWrite(ledGre, HIGH);//Liga led verde
    delay(250);//Intervalo de 250 milissegundos
    digitalWrite(ledRed, LOW);//Desliga led vermelho
    digitalWrite(ledYel, LOW);//Desliga led amarelo
    digitalWrite(ledGre, LOW);//Desliga led verde
    tone(buzzerPin, 528, 200);//Frequência e duração da nota Dó
    digitalWrite(ledRed, HIGH);//Liga led vermelho
    digitalWrite(ledYel, HIGH);//Liga led amarelo
    digitalWrite(ledGre, HIGH);//Liga led verde
    delay(250);//Intervalo de 250 milissegundos
    digitalWrite(ledRed, LOW);//Desliga led vermelho
    digitalWrite(ledYel, LOW);//Desliga led amarelo
    digitalWrite(ledGre, LOW);//Desliga led verde
    tone(buzzerPin, 528, 200);//Frequência e duração da nota Dó
    digitalWrite(ledRed, HIGH);//Liga led vermelho
    digitalWrite(ledYel, HIGH);//Liga led amarelo
    digitalWrite(ledGre, HIGH);//Liga led verde
    delay(250);//Intervalo de 250 milissegundos
    digitalWrite(ledRed, LOW);//Desliga led vermelho
    digitalWrite(ledYel, LOW);//Desliga led amarelo
    digitalWrite(ledGre, LOW);//Desliga led verde
    delay(500);//Intervalo de 500 milissegundos
  }
  }
