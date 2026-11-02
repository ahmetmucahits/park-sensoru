# Park Sensörü

Arduino ile yaptığım ilk proje. Arabalardaki park sensörünün basit bir versiyonu: önüne bir şey yaklaştıkça buzzer daha sık ötüyor.

Yazılımcı olarak çalışıyorum ama asıl ilgimi çeken şey otonom sistemler. Sensörden veri okuyup ona göre karar veren sistemleri anlamak için en baştan, Arduino ile başlamaya karar verdim. Bu da o yolun ilk adımı.

## Malzemeler

- Arduino Uno
- HC-SR04 ultrasonik mesafe sensörü
- Buzzer
- Breadboard ve kablolar

## Bağlantılar

| Parça | Arduino pini |
|---|---|
| HC-SR04 TRIG | 9 |
| HC-SR04 ECHO | 10 |
| Buzzer (+) | 8 |

Sensörün VCC'si 5V'a, GND'ler GND'ye.

## Nasıl çalışıyor

- 15 cm'den uzak: sessiz
- 10–15 cm: yavaş bip
- 5–10 cm: hızlı bip
- 5 cm ve altı: sürekli ses

Ölçülen mesafe Serial Monitor'e de yazılıyor (9600 baud).
