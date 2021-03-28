//variaveis da led
const int vermelho = 5;
const int verde = 6;
const int azul = 7;
//variaveis dos botoes
bool estadoLedVermelho = false;
const int botao1 = 2;
const int botao2 = 3;
unsigned long lastDebounceTime1 = 0;
const int botaoDelay = 100;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  
  Serial.begin(9600);//disponibilizar o uso do serial
	//escrever as informações entre parenteses no serial
  Serial.println("AC1 - Meu Primeiro Projeto 2021");
  Serial.println("V1.0");
  Serial.println("FECHADOES COM CRISTO");
}

void loop()
{
  if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(botao1)){
  	Serial.println("botao 1 apertado");
    ledVermelho();
  	lastDebounceTime1 = millis();
  //Caso o botao1 for pressionado, o Led vermelho se acendera
  }
 
  if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(botao2)){
  	Serial.println("botao 2 apertado");
    ledVermelho();
  	lastDebounceTime1 = millis();
  //Caso o botao2 for pressionado o led vermelho se apagara
// O contrario tambem se aplica.
// Caso o botao 2 for pressionado o led acendera
   //Caso o botao 1 for pressionado o led vermelho apagara
  }
 
  if(getTemperatura() > 15){
    ledAzul(true);
   Serial.println("A temperatura ultrapassou 15 graus");
  delay(2000);
  }else{
  	ledAzul(false); 
  //Caso a temperatura ultrapasse 15 graus, o led azul se acendera e será informado no serial que a temperatura limite foi atingida

  }
  
  if(getLuminosidade() > 5){
    ledVerde(true);
   Serial.println("A luminosidade ultrapassou de 5"); 
    delay(2000);
  }else{
  	ledVerde(false); 
  //caso a luminosidade ultrapasse 5, o led verde se acendera e será informado no serial que a luminosidade limite foi atingida

  }
    
  
 
    
  }

void ledVermelho(){
  estadoLedVermelho = !estadoLedVermelho;
  digitalWrite(vermelho,estadoLedVermelho);
//Função do led vermelho
}
void ledVerde(bool estado){
 digitalWrite(verde, estado); 
//função do led verde
}
void ledAzul(bool estado){
	digitalWrite(azul,estado);
  //função do led azul
}

int getTemperatura(){
  	int temperaturaC;
	temperaturaC = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  	return temperaturaC;
  //função de leitura da temperatura
} 
//funcao de leitura da luminosidade
int getLuminosidade(){
  	int luminosidade;
	luminosidade = map(analogRead(A1), 6, 619, -3, 10);
  	return luminosidade;
}
