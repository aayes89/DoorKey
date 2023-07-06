#include <stdint.h>

#define FS1000A_DATA_PIN 2
uint16_t pulse = 1.56;

void setup() {
  // put your setup code here, to run once:
  pinMode(FS1000A_DATA_PIN, OUTPUT);
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
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 4);
      break;

    // hex = 1, send 3 low pulses and 1 high pulse
    case '1':
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 3);
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      break;

    // hex = 2, send 2 low pulses,  1 high pulse, 1 low pulse
    case '2':
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 2);
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      break;

    // hex = 3, send 2 low pulses,  2 high pulses
    case '3':
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 2);
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 2);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      break;

    // hex = 4, send 1 low pulses,  1 high pulse, 2 low pulse
    case '4':
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 2);
      break;

    // hex = 5, send 1 low pulses,  1 high pulse, 2 low pulse
    case '5':
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      break;

    // hex = 6, send 1 low pulses,  2 high pulse, 1 low pulse
    case '6':
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 2);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      break;

    // hex = 7, send 1 low pulse,  3 high pulse
    case '7':
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 3);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      break;

    // hex = 8, send 1 high pulse,  3 low pulses
    case '8':
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 3);
      break;

    // hex = 9, send 1 high pulse,  2 low pulses, 1 high pulse
    case '9':
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 2);
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      break;

    // hex = a, send 1 high pulse,  1 low pulses, 1 high pulse, 1 low pulse
    case 'a':
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      break;

    // hex = b, send 1 high pulse,  1 low pulses, 2 high pulses
    case 'b':
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 2);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      break;

    // hex = c, send 2 high pulse,  2 low pulses
    case 'c':
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 2);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 2);
      break;

    // hex = d, send 2 high pulse,  1 low pulses, 1 high pulses
    case 'd':
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 2);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 1);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      break;

    // hex = e, send 3 high pulses,  1 low pulses
    case 'e':
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 3);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      delayMicroseconds(pulse * 1);
      break;

    // hex = f, send 4 high pulses
    case 'f':
      digitalWrite(FS1000A_DATA_PIN, HIGH);
      delayMicroseconds(pulse * 4);
      digitalWrite(FS1000A_DATA_PIN, LOW);
      break;

    default:
      digitalWrite(FS1000A_DATA_PIN, LOW);
      break;
  }
}
  void loop() {
  /* //now the decoded pulse definition taken from Universal Radio Hacker tool and your keys

  char sequence1[] = "8888d1ddd111119dd1f11d11";
  char sequence2[] = "8888e8eee888888ee8e88ec88";
  char sequence3[] = "888e8eee888888ee8e88e888";
  char sequence4[] = "8888e8eee8888";
  uint16_t pulse = 1.56;  // pulse width is 1.56 to 1.60 microseconds in my case
  uint8_t i;

  // first sequence
  for (i = 0; i < sizeof(sequence1); i++) {
    sendHexDigits(sequence1[i], pulse);
  }
  // first pause
  delayMicroseconds(4678.4436);

  //second sequence
  for (i = 0; i < sizeof(sequence2); i++) {
    sendHexDigits(sequence2[i], pulse);
  }
  // second pause
  delayMicroseconds(1782.8766);

  //third sequence
  for (i = 0; i < sizeof(sequence3); i++) {
    sendHexDigits(sequence3[i], pulse);
  }
  // third pause
  delayMicroseconds(4529.4973);

  //four sequence
  for (i = 0; i < sizeof(sequence4); i++) {
    sendHexDigits(sequence4[i], pulse);
  }
  // four pause
  delayMicroseconds(7608.6174);*/
}
