1. Proje Hakkında
Bu proje, modern API Gateway sistemlerinde gelen HTTP isteklerini önceliklendirmek amacıyla geliştirilmiş bir Priority Request Scheduler (Öncelikli İstek Zamanlayıcısı) simülasyonudur. Sistem, uluslararası RFC 9213 (Extensible HTTP Priorities) standartlarını baz alarak çalışmaktadır.

Projenin temel amacı, düşük performanslı geleneksel kuyruklar yerine, yüksek verimliliğe sahip Min-Heap veri yapısını kullanarak en öncelikli isteklere en kısa sürede (O(1)) erişim sağlamaktır.

2. Teknik Özellikler
Programlama Dili: C

Veri Yapısı: Min-Heap (Priority Queue)

Standart: RFC 9213 (Urgency: 0-7)

Mimari: Modüler Yapı (Header & Source dosyaları ayrılmış)

Hata Toleransı: Geçersiz girdilerde varsayılan öncelik (Default Priority) atama özelliği.

3. Dosya Yapısı ve Mimari
Proje, "Separation of Concerns" (Sorumlulukların Ayrılması) prensibine uygun olarak modüllere ayrılmıştır:

main.c: Uygulamanın giriş noktası ve kullanıcı test arayüzü.

rfc_parser.c/.h: Ham metin verilerini (u=0, u=5 vb.) sayısal öncelik değerlerine dönüştüren modül.

priority_queue.c/.h: Min-Heap algoritmalarını (heapifyUp, heapifyDown) ve kuyruk operasyonlarını içeren çekirdek modül.

request.h: İstek verilerinin yapısını (ID, Priority, Urgency) tanımlayan model.

scheduler.c/.h: İsteklerin işlenme mantığını ve zamanlayıcı döngüsünü yöneten katman.

4. Algoritma Performansı (Big-O Analizi)
Sistem, sıradan dizilere kıyasla logaritmik hızda çalışır:

Ekleme (Insert): O(log n)

En Öncelikliyi Bulma (Peek): O(1)

En Öncelikliyi Çıkarma (Extract-Min): O(log n)

Alan Karmaşıklığı: O(n)

5. Kurulum ve Çalıştırma
Projeyi derlemek için bir C derleyicisi (GCC, Clang) veya CLion gibi bir IDE kullanılabilir.

Derleme komutu:

Bash
gcc main.c rfc_parser.c priority_queue.c scheduler.c -o PriorityScheduler
Çalıştırma:

Bash
./PriorityScheduler
6. Örnek Kullanım (Runtime)
Program çalıştıktan sonra konsola şu formatta veri girilmelidir:

u=0 -> En Yüksek Öncelik

u=7 -> En Düşük Öncelik

geçersiz veri -> Otomatik olarak u=3 (Varsayılan) atanır.

Hazırlayan: Şeymanur Eke

Bölüm: Yazılım Mühendisliği

Tarih: Nisan 2026
