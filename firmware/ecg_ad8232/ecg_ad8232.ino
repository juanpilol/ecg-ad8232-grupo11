// ECG de una derivación con AD8232 + Arduino UNO
// Conexiones: OUTPUT -> A0, LO+ -> D10, LO- -> D11, 3.3V -> 3.3V, GND -> GND
// Salida por puerto serie a 115200 baudios (compatible con el Serial Plotter).
// Imprime "!" mientras algún electrodo esté desconectado.

const int PIN_ECG = A0;
const int PIN_LO_POS = 10;
const int PIN_LO_NEG = 11;

const unsigned long PERIODO_US = 2000;  // 2 ms = 500 muestras por segundo
unsigned long proximaMuestra = 0;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LO_POS, INPUT);
  pinMode(PIN_LO_NEG, INPUT);
  proximaMuestra = micros();
}

void loop() {
  unsigned long ahora = micros();
  if ((long)(ahora - proximaMuestra) < 0) return;  // aún no toca muestrear
  proximaMuestra += PERIODO_US;

  if (digitalRead(PIN_LO_POS) == HIGH || digitalRead(PIN_LO_NEG) == HIGH) {
    Serial.println('!');
  } else {
    Serial.println(analogRead(PIN_ECG));
  }
}
