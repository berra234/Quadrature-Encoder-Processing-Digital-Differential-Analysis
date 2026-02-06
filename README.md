Taylor Serisi Tabanlı Gürültüsüz Hız Kestirimi ve Quadrature Decoding

Bu proje, bir Quadrature Encoder'dan gelen konum verilerini yüksek hassasiyetle işleyen ve bu verilerden düşük gürültülü hız bilgisi üreten bir gömülü yazılım uygulamasıdır. 
Standart türev alma yöntemlerinin aksine, bu çalışmada Taylor Serisi açılımı kullanılarak gürültü bileşenleri minimize edilmiştir.
Projenin Öne Çıkan Özellikleri
Durum Makinesi (State Machine) ile Decoding: Enkoderin faz değişimlerini takip etmek için 16 elemanlı bir Lookup Table (LUT) kullanılmıştır.
Bu yöntem, işlemci yükünü azaltırken yön tayinini hatasız yapar.
Sayısal Diferansiyel Analiz: Hız hesabı için basit iki nokta türevi yerine, Taylor serisinden türetilen üç noktalı (Backward Difference) yaklaşımı uygulanmıştır.
Kesme (Interrupt) Yönetimi: Enkoder sinyalleri CHANGE modunda kesmelerle okunarak hiçbir palsin kaçırılmaması sağlanmıştır.
Atomik Veri Erişimi: Çok çekirdekli veya kesme tabanlı sistemlerde veri bütünlüğünü korumak için noInterrupts() ve interrupts() blokları ile kritik veri transferi yapılmıştır.
Donanım Kurulumu
Mikrodenetleyici: Arduino Mega / Uno.
Sensör: Quadrature (Artımlı) Enkoder.
Ekran: 16x2 Karakter LCD (Paralel Bağlantı).
Bağlantı:Kanal A - Dijital Pin 2 (Interrupt 0)
Kanal B -Dijital Pin 3 (Interrupt 1)
