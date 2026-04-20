/**
 * @file MOST_Safety_System.cpp
 * @author Jakub Mazurkiewicz (Banach Impact Lab)
 * @brief System bezpieczeństwa "Peace of Mind" dla przystawki MOST.
 * @version 1.1
 * @date 2026-04-20
 * 
 * Opis: Kod obsługuje komunikację GSM poprzez modem MC60. 
 * Pozwala użytkownikowi na wysłanie predefiniowanych powiadomień SMS 
 * do opiekuna w sytuacjach awaryjnych (rozładowana bateria / przeszkoda).
 */

// Definicja modelu modemu dla biblioteki TinyGSM
#define TINY_GSM_MODEM_MC60

#include <TinyGsmClient.h>
#include <SoftwareSerial.h>

/* --- KONFIGURACJA PINÓW --- */
// Piny komunikacji szeregowej (RX Arduino -> TX Modemu, TX Arduino -> RX Modemu)
// Wykorzystujemy piny 2 i 3 ze względu na specyfikację Shielda v2.105
const int RX_PIN = 2;
const int TX_PIN = 3;

// Pin sterujący zasilaniem modemu (zgodnie ze schematem montażowym)
const int PWR_KEY = 7; 

// Wejścia cyfrowe przycisków sterujących (z ochroną przed konfliktami z pinami GSM)
const unsigned int BUTTON1 = 4; // Alert: Niskie napięcie akumulatora
const unsigned int BUTTON2 = 5; // Alert: Przeszkoda terenowa

/* --- DANE KONTAKTOWE I TREŚĆ ALERTÓW --- */
const char number[] = "+48698198903"; // Numer telefonu opiekuna
const char message1[] = "MOST Alert: Bateria rozladowana. Sprawdz lokalizacje w SmartThings.";
const char message2[] = "MOST Alert: Przeszkoda nie do pokonania. Potrzebna pomoc na trasie.";

/* --- INICJALIZACJA OBIEKTÓW --- */
SoftwareSerial SerialAT(RX_PIN, TX_PIN);
TinyGsm modem(SerialAT);

void setup() {
  // Konfiguracja wejść przycisków w trybie INPUT_PULLUP.
  // Dzięki temu nie ma potrzeby stosowania zewnętrznych rezystorów na płytce.
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  
  // Konfiguracja pinu PWR_KEY jako wyjścia sterującego rozruchem modemu
  pinMode(PWR_KEY, OUTPUT);

  // Inicjalizacja portu szeregowego do celów diagnostycznych (monitorowanie pracy)
  Serial.begin(9600);
  delay(10);

  /**
   * PROCEDURA STARTOWA MODEMU (Cold Boot)
   * Modem MC60 wymaga sekwencji impulsów na pinie PWR_KEY, aby zainicjować logikę.
   */
  Serial.println("System MOST: Budzenie modemu GSM...");
  digitalWrite(PWR_KEY, LOW);
  delay(1000); // Impuls inicjujący
  digitalWrite(PWR_KEY, HIGH);
  delay(2000); // Czas podtrzymania napięcia startowego
  digitalWrite(PWR_KEY, LOW);

  // Inicjalizacja transmisji z modemem na standardowej prędkości 9600 bps
  SerialAT.begin(9600);
  delay(3000); // Czas na rejestrację modemu w sieci GSM

  Serial.println("Weryfikacja polaczenia z modemem...");
  if (!modem.restart()) {
    Serial.println("KRYTYCZNY BLAD: Modem nie odpowiada. Sprawdz zasilanie.");
    while (true); // Blokada programu w przypadku awarii hardware'u
  }

  Serial.println("System MOST: Modem gotowy. Monitorowanie przyciskow...");
}

void loop() {
  /**
   * OBSŁUGA PRZYCISKU 1: ALERT ENERGETYCZNY
   * Logika Active Low (wciśnięcie przycisku zwiera pin do masy - stan LOW).
   */
  if (digitalRead(BUTTON1) == LOW) {
    Serial.print("Wysylanie powiadomienia o baterii... ");
    if (modem.sendSMS(number, message1)) {
      Serial.println("Wyslano poprawnie.");
    } else {
      Serial.println("Blad transmisji GSM.");
    }
    delay(5000); // Blokada anty-spamowa: zapobiega wysłaniu serii SMS przy jednym wciśnięciu
  }

  /**
   * OBSŁUGA PRZYCISKU 2: ALERT TERENOWY
   */
  if (digitalRead(BUTTON2) == LOW) {
    Serial.print("Wysylanie powiadomienia o przeszkodzie... ");
    if (modem.sendSMS(number, message2)) {
      Serial.println("Wyslano poprawnie.");
    } else {
      Serial.println("Blad transmisji GSM.");
    }
    delay(5000); // Blokada anty-spamowa
  }
}