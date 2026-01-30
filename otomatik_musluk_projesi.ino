#include <Servo.h>

const int trigPin = 2;
const int echoPin = 12;
const int buzzerPin = 3;
const int yesilLed = 4;
const int kirmiziLed = 5;
const int servoPin = 9;

int algilamaMesafesi = 15; // 15 cm altına el gelirse açılır
// Bekleme süresini 1 saniyeye (1000 ms) düşürdük, elini çekince hemen kapansın diye
unsigned long emniyetSuresi = 1000; 

Servo muslukServosu;
unsigned long sonHareketZamani = 0;
bool muslukAcikmi = false;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(yesilLed, OUTPUT);
  pinMode(kirmiziLed, OUTPUT);
  
  muslukServosu.attach(servoPin);
  muslukServosu.write(0); // Kapalı konum
  digitalWrite(kirmiziLed, HIGH);
  digitalWrite(yesilLed, LOW);
  Serial.println("Anlik Tepki Modu Hazir!");
}

void loop() {
  long mesafe = mesafeOlc();

  if (mesafe > 0 && mesafe < algilamaMesafesi) {
    // El orada olduğu sürece zamanı sürekli güncelle
    sonHareketZamani = millis(); 
    
    if (!muslukAcikmi) {
      muslukAc();
    }
  }

  // Eğer musluk açıksa ve el çekildikten sonra 1 saniye geçtiyse kapat
  if (muslukAcikmi && (millis() - sonHareketZamani > emniyetSuresi)) {
    muslukKapat();
  }
  
  delay(50);
}

long mesafeOlc() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long sure = pulseIn(echoPin, HIGH);
  return sure * 0.034 / 2;
}

void muslukAc() {
  muslukServosu.write(90); // Açılma açısı
  muslukAcikmi = true;
  digitalWrite(kirmiziLed, LOW);
  digitalWrite(yesilLed, HIGH);
  digitalWrite(buzzerPin, HIGH); delay(100); digitalWrite(buzzerPin, LOW);
}

void muslukKapat() {
  muslukServosu.write(0); // Kapanma açısı
  muslukAcikmi = false;
  digitalWrite(yesilLed, LOW);
  digitalWrite(kirmiziLed, HIGH);
  // Kapanırken kısa bip
  digitalWrite(buzzerPin, HIGH); delay(50); digitalWrite(buzzerPin, LOW);
}