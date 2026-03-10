Ctrl + Shift + V para preview de md


```
esquematico.md
```

---

# 📟 Esquemático do Projeto – Grandezas de eletricidade basicas

## 🔌 Componentes

* Arduino Uno / Nano
* Display TFT ILI9341 (SPI)
* 1 Botão
* 1 Potenciômetro
* 1 LED
* 1 Resistor 220Ω (para o LED)

---

# 📺 Conexão do Display ILI9341 (SPI)

| Pino Display | Conectar no Arduino |
| ------------ | ------------------- |
| VCC          | 5V                  |
| GND          | GND                 |
| CS           | Pino **10**         |
| DC           | Pino **9**          |
| RST          | Pino **8**          |
| MOSI         | Pino **11**         |
| MISO         | Pino **12**         |
| SCK          | Pino **13**         |
| LED          | **5V**              |

---

# 🔘 Conexão do Botão

| Componente   | Arduino    |
| ------------ | ---------- |
| Botão pino 1 | **Pino 2** |
| Botão pino 2 | **GND**    |

⚠ O código usa:

```
INPUT_PULLUP
```

Então **não precisa resistor externo**.

---

# 💡 Conexão do LED

| Componente     | Arduino                 |
| -------------- | ----------------------- |
| Anodo (+) LED  | **Pino 6**              |
| Catodo (-) LED | **Resistor 220Ω → GND** |

---

# 🎚 Conexão do Potenciômetro

| Pino do Pot | Arduino |
| ----------- | ------- |
| Esquerda    | **5V**  |
| Meio        | **A0**  |
| Direita     | **GND** |

---

# 📊 Mapa Geral dos Pinos

| Função        | Pino Arduino |
| ------------- | ------------ |
| Botão         | 2            |
| LED           | 6            |
| Potenciômetro | A0           |
| TFT DC        | 9            |
| TFT CS        | 10           |
| TFT MOSI      | 11           |
| TFT MISO      | 12           |
| TFT SCK       | 13           |
| TFT RST       | 8            |

---

# 🧠 Diagrama Simplificado

```
          +-------------------+
          |     ARDUINO       |
          |                   |
Botão ----| D2                |
LED  -----| D6                |
Pot  -----| A0                |
          |                   |
TFT DC ---| D9                |
TFT CS ---| D10               |
TFT MOSI -| D11               |
TFT MISO -| D12               |
TFT SCK --| D13               |
TFT RST --| D8                |
          |                   |
          | 5V ---- TFT LED   |
          | GND --- GND       |
          +-------------------+
```

---

# ⚡ Bibliotecas necessárias

Instalar na **Arduino IDE**:
 
* `Adafruit GFX`
* `Adafruit ILI9341`

---
