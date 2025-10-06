# SafeSpeed
SafeSpeed uygulaması;sürücünün hız, şerit ve öndeki araç mesafesini kontrol eden mini bir C++ simülasyonudur. Sistem, hız sınırına yaklaşıldığında veya şerit dışına çıkıldığında uyarı verir, gerekirse hızı otomatik olarak düşürür.
Hız sınırı kontrolü bulunmaktadır.Uygulamada limit 100 km/h olarak belirlendi.
Öndeki araçla mesafe kontrolü yapılmaktadır. Eğer öndeki araca 10 metreden fazla yaklaşırsa, uyarı verir.Otomatik olarak 10 km/h hız düşürür.
Şerit takibi (sol / orta / sağ) yapılır. Uygulamada olunması gereken şerit orta olarak belirlenmiştir.Sürücü diğer şeritlerdeyse ortaya geçirir.
Hız çubuğu: renk değiştirerek görsel uyarı verir.
Şerit görselliği: sol/orta/sağ + [A] ile araç konumu
Hız çubuğu: <90 → yeşil ,90–99 → sarı ≥100 → kırmızı bu koşullara göre denk gelen renkleri verir.
örnek çıktı:
Hız (km/h): 95
Şerit: sol
Ön araç mesafesi (m): 8

[Uyarı] Şeritten çıkıyorsunuz!
[SafeSpeed] Şerit düzeltildi. Şimdi orta şeritte.
[Uyarı] Öndeki araca çok yakın! Mesafeyi açın.
[SafeSpeed] Hızı düşürerek mesafe açılıyor.
Hız: 85 km/h [####################]
C++ kodu ile yazılmıştır.
