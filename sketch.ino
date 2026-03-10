#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 9
#define TFT_CS 10

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

int botao = 2;
int led = 6;
int pot = A0;

int missao = 1;
bool botaoAnterior = HIGH;

int respostaSelecionada = 0;

void setup()
{

  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);

  tft.begin();
  tft.fillScreen(ILI9341_BLACK);

  mostrarMissao1();
}

void loop()
{

  selecionarResposta();

  bool estadoBotao = digitalRead(botao);

  if (estadoBotao == LOW && botaoAnterior == HIGH)
  {
    verificarResposta();
    delay(300);
  }

  botaoAnterior = estadoBotao;
}

void selecionarResposta()
{

  int valor = analogRead(pot);

  respostaSelecionada = map(valor, 0, 1023, 0, 2);

  tft.fillRect(0, 200, 320, 40, ILI9341_BLACK);

  tft.setCursor(20, 210);
  tft.setTextColor(ILI9341_YELLOW);
  tft.setTextSize(2);

  if (respostaSelecionada == 0)
    tft.print("Opcao: A");
  if (respostaSelecionada == 1)
    tft.print("Opcao: B");
  if (respostaSelecionada == 2)
    tft.print("Opcao: C");
}

void verificarResposta()
{

  bool correto = false;

  if (missao == 1 && respostaSelecionada == 1)
    correto = true;
  if (missao == 2 && respostaSelecionada == 1)
    correto = true;
  if (missao == 3 && respostaSelecionada == 1)
    correto = true;
  if (missao == 4 && respostaSelecionada == 0)
    correto = true;

  tft.fillRect(0, 240, 320, 40, ILI9341_BLACK);

  tft.setCursor(20, 250);
  tft.setTextSize(2);

  if (correto)
  {

    tft.setTextColor(ILI9341_GREEN);
    tft.print("CORRETO!");

    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);

    missao++;

    if (missao == 2)
      mostrarMissao2();
    if (missao == 3)
      mostrarMissao3();
    if (missao == 4)
      mostrarMissao4();
    if (missao == 5)
      telaFinal();
  }
  else
  {

    tft.setTextColor(ILI9341_RED);
    tft.print("ERRADO!");
  }
}

void mostrarMissao1()
{

  tft.fillScreen(ILI9341_BLACK);

  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE);

  tft.setCursor(20, 40);
  tft.print("MISSAO 1");

  tft.setCursor(20, 80);
  tft.print("V = 10V");

  tft.setCursor(20, 110);
  tft.print("R = 5 Ohm");

  tft.setCursor(20, 140);
  tft.print("I = V/R");

  tft.setCursor(20, 170);
  tft.print("Qual a corrente?");

  tft.setCursor(180, 80);
  tft.print("A)1A");

  tft.setCursor(180, 110);
  tft.print("B)2A");

  tft.setCursor(180, 140);
  tft.print("C)3A");
}

void mostrarMissao2()
{

  tft.fillScreen(ILI9341_BLACK);

  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE);

  tft.setCursor(20, 40);
  tft.print("MISSAO 2");

  tft.setCursor(20, 80);
  tft.print("V = 12V");

  tft.setCursor(20, 110);
  tft.print("I = 3A");

  tft.setCursor(20, 140);
  tft.print("R = V/I");

  tft.setCursor(20, 170);
  tft.print("Qual resistencia?");

  tft.setCursor(180, 80);
  tft.print("A)2");

  tft.setCursor(180, 110);
  tft.print("B)4");

  tft.setCursor(180, 140);
  tft.print("C)6");
}

void mostrarMissao3()
{

  tft.fillScreen(ILI9341_BLACK);

  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE);

  tft.setCursor(20, 40);
  tft.print("MISSAO 3");

  tft.setCursor(20, 80);
  tft.print("V = 9V");

  tft.setCursor(20, 110);
  tft.print("I = 2A");

  tft.setCursor(20, 140);
  tft.print("P = V x I");

  tft.setCursor(20, 170);
  tft.print("Qual potencia?");

  tft.setCursor(180, 80);
  tft.print("A)12W");

  tft.setCursor(180, 110);
  tft.print("B)18W");

  tft.setCursor(180, 140);
  tft.print("C)20W");
}

void mostrarMissao4()
{

  tft.fillScreen(ILI9341_BLACK);

  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE);

  tft.setCursor(20, 40);
  tft.print("MISSAO 4");

  tft.setCursor(20, 80);
  tft.print("R = 20 Ohm");

  tft.setCursor(20, 110);
  tft.print("I = 0.5A");

  tft.setCursor(20, 140);
  tft.print("V = R x I");

  tft.setCursor(20, 170);
  tft.print("Qual tensao?");

  tft.setCursor(180, 80);
  tft.print("A)10V");

  tft.setCursor(180, 110);
  tft.print("B)5V");

  tft.setCursor(180, 140);
  tft.print("C)20V");
}

void telaFinal()
{

  tft.fillScreen(ILI9341_BLACK);

  tft.setTextSize(3);
  tft.setTextColor(ILI9341_GREEN);

  tft.setCursor(30, 120);
  tft.print("PARABENS!");

  tft.setTextSize(2);
  tft.setCursor(30, 170);
  tft.print("Voce venceu!");
}
