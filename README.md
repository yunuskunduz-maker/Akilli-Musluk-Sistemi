# Akıllı Musluk Sistemi (Arduino & Mesafe Sensörü)

Bu proje, bir HC-SR04 mesafe sensörü, Arduino Nano ve SG90 mikro servo motor kullanarak otomatik bir musluk sistemi oluşturmayı amaçlar. Elinizi musluğun altına yaklaştırdığınızda su otomatik olarak açılır ve elinizi çektiğinizde kısa bir gecikmeyle kapanır. Sistem, su tasarrufu sağlamak ve hijyeni artırmak için tasarlanmıştır.

## İçerik

* [Proje Hakkında](#proje-hakkında)
* [Video Tanıtımı](#video-tanıtımı)
* [Gereksinimler](#gereksinimler)
* [Bağlantı Şeması (Fritzing)](#bağlantı-şeması-fritzing)
* [Kurulum Adımları](#kurulum-adımları)
* [Kullanım](#kullanım)
* [Kod Açıklaması](#kod-açıklaması)
* [Katkıda Bulunma](#katkıda-bulunma)

## Proje Hakkında

Geleneksel muslukların aksine, bu akıllı sistem elinizi algıladığında suyu otomatik olarak açar ve elinizi çektiğinizde kapatır. Bu sayede gereksiz su tüketiminin önüne geçilir ve musluğa fiziksel temas ihtiyacı ortadan kalktığı için hijyen seviyesi artırılır. Özellikle halka açık alanlarda veya yoğun kullanılan ev lavabolarında pratik bir çözüm sunar.

## Video Tanıtımı

## Gereksinimler

Bu projeyi kurmak için ihtiyacınız olan donanım ve yazılımlar:

**Donanım:**
* Arduino Nano (veya benzeri bir Arduino kartı)
* HC-SR04 Mesafe Sensörü
* SG90 Mikro Servo Motor
* Buzzer (5V)
* Yeşil LED (isteğe bağlı olarak)
* Kırmızı LED (isteğe bağlı olarak)
* 220 Ohm veya 330 Ohm Dirençler (LED'ler için, isteğe bağlı ama önerilir)
* 6V Pil Paketi (4 adet AA/AAA pil) - Servo için harici besleme
* Jumper Kablolar (Erkek-Erkek)
* Breadboard (Devreyi kurmak için)
* USB Kablosu (Arduino'ya kod yüklemek için)

**Yazılım:**
* Arduino IDE (Kod yüklemek için)

## Bağlantı Şeması (Fritzing)

Aşağıdaki Fritzing şeması, tüm bileşenlerin Arduino Nano'ya nasıl bağlanacağını göstermektedir. Güç bağlantılarına özellikle dikkat edin.

**[Buraya Fritzing Şemasının Resmini Ekleyin (Fritzing_AkilliMusluk_Breadboard.png)]**
*Örnek görsel kodu:* `![](images/Fritzing_AkilliMusluk_Breadboard.png)`

**Pin Bağlantı Listesi:**

| Bileşen | Arduino Nano Pini | Notlar |
| :--- | :--- | :--- |
| **HC-SR04 VCC** | 5V | Mesafe sensörü için güç |
| **HC-SR04 Trig** | D2 | Tetikleyici pin |
| **HC-SR04 Echo** | D12 | Geri dönen sinyal pin |
| **HC-SR04 GND** | GND | Toprak |
| **Servo Sinyal (Turuncu/Sarı)** | D9 | Servo kontrol pini |
| **Servo VCC (Kırmızı)** | **Harici 6V Pil (+) ** | **ÖNEMLİ: Doğrudan pil paketine bağlanmalı** |
| **Servo GND (Kahverengi/Siyah)** | Arduino GND & Pil (-) | Ortak toprak hattı |
| **Buzzer (+)** | D3 | Sesli bildirim için |
| **Buzzer (-)** | GND | Toprak |
| **Yeşil LED (+)** | D4 | Musluk açık göstergesi (Direnç ile bağlanabilir) |
| **Yeşil LED (-)** | GND | Toprak |
| **Kırmızı LED (+)** | D5 | Musluk kapalı göstergesi (Direnç ile bağlanabilir) |
| **Kırmızı LED (-)** | GND | Toprak |
| **6V Pil Paketi (+)** | Arduino Nano VIN | Arduino için ana güç kaynağı |
| **6V Pil Paketi (-)** | Arduino GND | Ortak toprak hattı |

## Kurulum Adımları

1.  **Arduino IDE Kurulumu:** Eğer yüklü değilse, [Arduino IDE'yi buradan indirin ve kurun](https://www.arduino.cc/en/software).
2.  **Kütüphane Yükleme:** Servo motoru kontrol etmek için `Servo.h` kütüphanesine ihtiyacımız var. Bu kütüphane Arduino IDE ile birlikte gelir, ekstra bir yüklemeye gerek yoktur.
3.  **Kodu Kopyala:** Bu GitHub deposundaki `Akilli_Musluk_Sistemi.ino` dosyasının içeriğini kopyalayın veya tüm depoyu ZIP olarak indirin.
4.  **Kodu Arduino IDE'ye Yapıştır:** Arduino IDE'yi açın, yeni bir taslak oluşturun ve kopyaladığınız kodu yapıştırın.
5.  **Kart ve Port Seçimi:**
    * `Araçlar > Kart > Arduino Nano` seçin.
    * `Araçlar > İşlemci > ATmega328P (Old Bootloader)` seçili olduğundan emin olun.
    * `Araçlar > Port` menüsünden Arduino Nano'nuzun bağlı olduğu COM portunu seçin.
6.  **Kodu Yükle:** USB kablosu bağlıyken (pil bağlantıları çıkarılmış halde) kodu Arduino Nano'nuza yükleyin.
7.  **Donanımı Birleştir:** Yukarıdaki bağlantı şemasını ve pin listesini takip ederek tüm bileşenleri breadboard üzerine kurun. **Özellikle Servo'nun harici güç bağlantısına ve ortak GND hattına dikkat edin.**
8.  **Güç Ver:** USB kablosunu çıkarın ve 6V pil paketinizi bağlayın. Sistem otomatik olarak çalışmaya başlayacaktır.

## Kullanım

* Elinizi mesafe sensörünün (HC-SR04) önüne, belirlediğiniz `algilamaMesafesi` (varsayılan 15 cm) altına yaklaştırın.
* Musluk açılacak, yeşil LED yanacak ve kısa bir bip sesi duyulacaktır.
* Elinizi sensörün görüş alanından çektiğinizde, `emniyetSuresi` (varsayılan 1 saniye) kadar bekledikten sonra musluk kapanacak, kırmızı LED yanacak ve iki kısa bip sesi duyulacaktır.

## Kod Açıklaması

* `algilamaMesafesi`: Musluğun tetiklenmesi için elinizin sensöre ne kadar yaklaşması gerektiğini belirler (cm cinsinden).
* `emniyetSuresi`: Elinizi sensörden çektikten sonra musluğun kapanması için beklenecek süredir (milisaniye cinsinden). Su tasarrufu için kısa tutulmuştur.
* `mesafeOlc()` fonksiyonu, HC-SR04 sensöründen doğru mesafe okumasını sağlar.
* `muslukAc()` ve `muslukKapat()` fonksiyonları, servo motoru kontrol eder, LED'leri yakıp söndürür ve buzzer ile geri bildirim sağlar.

## Katkıda Bulunma

Bu projeyi daha da geliştirmek isterseniz pull request göndermekten çekinmeyin. Her türlü katkı memnuniyetle karşılanır.
