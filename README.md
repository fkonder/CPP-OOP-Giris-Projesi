# KULLANICI ETKİLEŞİMLİ ARABA MÜZAYEDE SİSTEMİ

Bu CPP projesini 1. sınıfta Nesne Yönelimli Programlamaya giriş dersinde yapmıştım, o zamanlar fonksiyonel oop yazımı ve temiz kod yazımı hakkında şuanki kadar fazla bilgim yoktu. Aslında kodu tekrar yazıp öyle paylaşmak isterdim ama bunu yapmanın çok da doğru olmayacağını düşündüm, o yüzden kodu o dönemde yazdığım şekliyle saf bir şekilde bırakıyorum. Programın doğru olarak çalışmasın için gereken TXT dosyalarını kaybettiğim için programda Klasik arabalar ve Aile arabaları fonksiyonu düzgün çalışmamaktadır ama kodun çalıştığını gösterebilmek için Spor Arabalar kısmını düzelltim, denemek isterseniz seçimlerde Spor arabayı seçip kodun terminalde çıktılarına bakabilirsiniz.

## Kodun İşleyiş Mantığı

Müzayede taşınır ya da taşınmaz mallların açık arttırma yoluyla alım ya da
satımıdır. Geleneksel müzayedelerde alıcıların birbirini izleyen artırma
önerilerinin yönetici tarafından kabul edilecek en yüksek bedele ulaşması işidir,
yani ilan edilen başlangıç fiyatından başlanıp tek talip olduğunda başlangıç
fiyatından satın alınabilen aksi takdirde 2 veya daha fazla alıcının arttırma
yöntemiyle almaya çabalama işidir. Biz ise kodumuzda müzayede sistemini
kullanıcı ve kod arasında geçecek olan bir savaş olarak tanımladık. Kodumuzda
bot %50 ihtimalle fiyat arttırıp sizin teklif ettiğiniz fiyatın üstüne 1-1000TL
arasında ücret ekleyip üst teklif vermekte, %50 ihtimalle de geri çekilmektedir.
Kodumuzda size çeşitlilik sunmak için girişte Klasik Araba, Normal Araba ve
Spor Araba olmak üzere üç farklı seçenek sunulmaktadır, bu seçeneklerden
herhangi birisini seçtiğiniz zaman karşınıza seçtiğiniz araba hakkında marka,
model ve üretim yılı ile ilgili bilgiler gelmektedir -Klasik ve Spor arabalarda
marka, model, üretim yılı haricinde Spor arabada beygir gücü, Klasik
arabadaysa üretim adeti bilgileri yazdırılmaktadır.- Eğer gelen arabayla
ilgileniyorsanız 1’i ilgilenmiyorsanız da 0’ı tuşlayarak gelecek diğer arabaya
geçebiliyorsunuz. Eğer 1’i tuşlayıp arabayı satın almayı tercih ederseniz
arabanın fiyat bilgisi size veriliyor ve botla olan rekabetiniz başlıyor. Girdiğiniz
müzayedede fiyat, almak istemediğiniz kadar arttığında veya satın almaktan
vazgeçtiğinizde 0’ı tuşlayarak arabayı almaktan vazgeçip sonraki arabaya bakabilirsiniz.

## Kodun Genel İçeriği Hakkında Bilgiler

Class Araba(); → Genel araba class’ımız bu classın içerisindeyse de protected
olarak arabaya ait olan Fiyat, Marka, Üretim Yılı, Model bilgileri, public
olaraksa
void Gelecek_Araba(); fonksiyonumuz →İçerisinde bulunan düzenli if, else if,
else sorgulamalarıyla en başta sizin arabaya ilgi duyup duymadığınızı sınayıp
eğer ilgi duyuyorsanız o arabanın fiyatını sizler için ekrana yazdırıp sizden teklif
ister, eğer arabayla ilgilenmiyorsanız da gelecek araba hakkındaki bilgileri
ekrana yazdırıp o arabaya ilgi durumunuzu sorar. Bu fonksiyona kodun kaynağı
demek çokta yanlış olmaz. 
Void car_info → Sırası gelen arabanın marka, model, üretim yılı gibi bilgilerini
dosya okuma ile oluşturduğumuz, sonra da bir arraya atadığımız değerleri çekip
kullanıcının ekranına sunmaktadır.
Class ArabaListesi(); →Bu classı txtden çektiğimiz normal arabaların array ve
uzunluğunu bir class objesinde tutmak için oluşturduk .
Class Spor_Araba : public Araba → Araba classından üretilip Araba classına ek
olarak içerisinde bulunan ekrana yazdırma fonksiyonu -void spor_infoyardımıyla arabanın bilgilerini yazdırırken ek olarak beygir gücü bilgisini de
yazdırmaktadır.
Class SporArabaListesi → Bu classı txtden çektiğimiz spor arabaların array ve
uzunluğunu bir class objesinde tutmak için oluşturduk.
Class Klasik_Araba : public Araba → Araba classından üretilip Araba classına
ek olarak içerisinde bulunan ekrana yazdırma fonksiyonu -void kasik_infoyardımıyla arabanın bilgilerini yazdırırken ek olarak üretim adeti bilgisini de
yazdırmaktadır.
Class KlasikArabaListesi → Bu classı txtden çektiğimiz klasik arabaların array
ve uzunluğunu bir class objesinde tutmak için oluşturduk.
ArabaListesi araba_Oku → Bu fonksiyonda normal arabaların txtden
okunmasını ve virgül sayısına göre sıralanmasını sağladık.
ArabaListesi klasikAraba_Oku → Bu fonksiyonda Klasik arabaların txtden
okunmasını ve virgül sayısına göre sıralanmasını sağladık.
ArabaListesi sporAraba_Oku → Bu fonksiyonda Spor arabaların txtden
okunmasını ve virgül sayısına göre sıralanmasını sağladık. 