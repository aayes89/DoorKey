#include <stdint.h>

#define DATA_PIN 2
uint16_t pulse = 1.56;

void setup() {
  // put your setup code here, to run once:
  pinMode(DATA_PIN, OUTPUT);
  char sequence1[] = "8888d1ddd111119dd1f11d11";
  char sequence2[] = "8888e8eee888888ee8e88ec88";
  char sequence3[] = "888e8eee888888ee8e88e888";
  char sequence4[] = "8888e8eee8888";

  transmitt(sequence1, pulse, 4678.4436);
  transmitt(sequence2, pulse, 1782.8766);
  transmitt(sequence3, pulse, 4529.4973);
  transmitt(sequence4, pulse, 7608.6174);
}

void transmitt(char sequence[], uint16_t pulse, uint16_t ms) {
  uint8_t i;
  for (i = 0; i < sizeof(sequence); i++) {
    sendHexDigits(sequence[i], pulse);
  }
  delayMicroseconds(ms);
}

void sendHexDigits(char c, uint16_t pulse) {
  switch (c) {
    case '0':
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 4);
      break;

    // hex = 1, send 3 low pulses and 1 high pulse
    case '1':
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 3);
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, LOW);
      break;

    // hex = 2, send 2 low pulses,  1 high pulse, 1 low pulse
    case '2':
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 2);
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      break;

    // hex = 3, send 2 low pulses,  2 high pulses
    case '3':
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 2);
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 2);
      digitalWrite(DATA_PIN, LOW);
      break;

    // hex = 4, send 1 low pulses,  1 high pulse, 2 low pulse
    case '4':
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      digitalWrite(ATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 2);
      break;

    // hex = 5, send 1 low pulses,  1 high pulse, 2 low pulse
    case '5':
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, LOW);
      break;

    // hex = 6, send 1 low pulses,  2 high pulse, 1 low pulse
    case '6':
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 2);
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      break;

    // hex = 7, send 1 low pulse,  3 high pulse
    case '7':
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 3);
      digitalWrite(DATA_PIN, LOW);
      break;

    // hex = 8, send 1 high pulse,  3 low pulses
    case '8':
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 3);
      break;

    // hex = 9, send 1 high pulse,  2 low pulses, 1 high pulse
    case '9':
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 2);
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, LOW);
      break;

    // hex = a, send 1 high pulse,  1 low pulses, 1 high pulse, 1 low pulse
    case 'a':
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      break;

    // hex = b, send 1 high pulse,  1 low pulses, 2 high pulses
    case 'b':
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 2);
      digitalWrite(DATA_PIN, LOW);
      break;

    // hex = c, send 2 high pulse,  2 low pulses
    case 'c':
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 2);
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 2);
      break;

    // hex = d, send 2 high pulse,  1 low pulses, 1 high pulses
    case 'd':
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 2);
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(DATA_PIN, LOW);
      break;

    // hex = e, send 3 high pulses,  1 low pulses
    case 'e':
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 3);
      digitalWrite(DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      break;

    // hex = f, send 4 high pulses
    case 'f':
      digitalWrite(DATA_PIN, HIGH);
      delayMicroseconds(pulse * 4);
      digitalWrite(DATA_PIN, LOW);
      break;

    default:
      digitalWrite(DATA_PIN, LOW);
      break;
  }
}
  void loop() {}
