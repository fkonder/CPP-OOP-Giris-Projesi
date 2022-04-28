#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
using namespace std;
        ofstream myfile("alinanaraba.txt");

class Araba {
    protected:
    int Fiyat;
    int modelYili;
    string Marka;
    string Model;
    public:

    //dummy constructor
    Araba() {
    }

    Araba(int Fiyat, int modelYili, string Marka, string Model) {
        this->Fiyat = Fiyat;
        this->Marka = Marka;
        this->modelYili = modelYili;
        this->Model = Model;
    }

    void Gelecek_Araba() {
        srand(time(0));
        int FiyatArtis;
        int KullaniciTeklifi, BotunTeklifi;
        float FiyatArtAzalt;
        FiyatArtAzalt = rand() % 10 + 1;
        FiyatArtis = rand() % 1000 + 1;
        int ArabaIlgi;
        cout << "************************************\nArabayla ilgileniyorsaniz 1, ilgilenmiyorsaniz 0 tuslayin: ";
        cin >> ArabaIlgi;
        basadon:
        if (ArabaIlgi != 0 && ArabaIlgi != 1) {
            cout << "Hatali sayi girdiniz, lutfen tekrar giris yapiniz: " <<
                    endl;
            cin >> ArabaIlgi;
goto basadon;
        }
//ARABAYLA İLGİLENİYOR
        if (ArabaIlgi == 1) {
            cout << "Araba baslangic fiyati: " << Fiyat << endl;
            ArabayaVerilcekPara:
            cout << "Arabaya vermek istediginiz fiyat(Cekilmek icin 0 yazin!):";
            cin >> KullaniciTeklifi;
            if (KullaniciTeklifi <= Fiyat) {
                if (KullaniciTeklifi == 0) {
                    cout << "Cekildiginiz icin rakip muzayedeyi kazandı. " << endl;
                } else {
                    cout << "Teklifiniz baslangic fiyatindan veya rakibin teklifinden dusuk olamaz !" << endl;
                    FiyatArtAzalt = rand() % 10 + 1;
                    FiyatArtis = rand() % 1000 + 1;
goto ArabayaVerilcekPara;
                }
            }
            Fiyat = KullaniciTeklifi;
            if (FiyatArtAzalt < 6) {
                if (KullaniciTeklifi == 0) {
                } else {
                    cout << "Rakibin teklifi: ";
                    BotunTeklifi = KullaniciTeklifi + FiyatArtis;
                    cout << BotunTeklifi << endl;
                    Fiyat = BotunTeklifi;
                    FiyatArtAzalt = rand() % 10 + 1;
                    FiyatArtis = rand() % 1000 + 1;
goto ArabayaVerilcekPara;
                }
            } else if (KullaniciTeklifi == 0) {
            } else {
                cout << "Rakip Cekildi, Arabayi " <<
                        KullaniciTeklifi << " Verip Aldiniz!" << endl;
                myfile << "Arabanin markasi: " << Marka
                        << endl;
                myfile << "Arabanin modeli: " << Model
                        << endl;
                myfile << "Arabanin cikis yili: " <<
                        modelYili << endl;
                myfile << "Arabanin fiyati: " << Fiyat <<
                        endl;
                myfile << "\n";
            }
        }
        if (ArabaIlgi == 0) {
            cout << "Gelecek Arabaya Geciliyor...\n ************************************\n " << endl;
        }
    }

    void car_info() {
        cout << "Sirasi gelen arabanin Markasi: " << Marka << "\n" <<
                "Sirasi gelen arabanin Modeli: " << Model << "\nSirasi gelen arabanin Model Yili: "
                << modelYili << endl;
    }
};

class ArabaListesi {
    protected:
    public:
    friend

    void Gelecek_Araba();

    Araba*arabalar;
    int araba_sayisi;

    ArabaListesi(Araba*arabalar_, int araba_sayisi_) {
        arabalar = arabalar_;
        araba_sayisi = araba_sayisi_;
    }
};

class Spor_Araba :public Araba{
protected:
        int beygirGucu;
public:
        Spor_Araba(){}
        Spor_Araba(int Fiyat,int modelYili,int beygirgucu,string Marka,string
        Model):Araba(Fiyat,modelYili,Marka,Model)
        {
        beygirGucu=beygirgucu;
        }
        void spor_info()
        {
        cout<<"Sirasi gelen arabanin Markasi: "<<Marka<<"\n"<<
        "Sirasi gelen arabanin Modeli: "<<Model<<"\nSirasi gelen arabanin Model Yili:"
        <<modelYili<<"\n"<<"Beygir Gucu: "<<beygirGucu<<
        endl;
        }
        };

class SporArabaListesi {
    protected:
    public:
    friend

    void Gelecek_Araba();

    Spor_Araba*sporArabalar;
    int araba_sayisi;

    SporArabaListesi(Spor_Araba*sporArabalar_, int sporAraba_sayisi_) {
        sporArabalar = sporArabalar_;
        araba_sayisi = sporAraba_sayisi_;
    }
};

class Klasik_Araba :public Araba{
protected:
        int uretimAdeti;
public:
        Klasik_Araba(){}
        Klasik_Araba(int Fiyat,int modelYili,int uretimadeti,string Marka,
        string Model):Araba(Fiyat,modelYili,Marka,Model)
        {
        uretimAdeti=uretimadeti;
        }
        void klasik_info()
        {
        cout<<"Sirasi gelen arabanin Markasi: "<<Marka<<"\n"<<
        "Sirasi gelen arabanin Modeli: "<<Model<<"\nSirasi gelen arabanin Model Yili:"
        <<modelYili<<"\n"<<"Arabanin Uretim Adeti: "<<
        uretimAdeti<<endl;
        }
        };

class KlasikArabaListesi {
    protected:
    public:
    friend

    void Gelecek_Araba();

    Klasik_Araba*klasikArabalar;
    int araba_sayisi;

    KlasikArabaListesi(Klasik_Araba*klasikArabalar_, int
            klasikAraba_sayisi_) {
        klasikArabalar = klasikArabalar_;
        araba_sayisi = klasikAraba_sayisi_;
    }
};
ArabaListesi araba_Oku(string txt_dosyası)
        {
        int fiyat_listesi[10];
        string marka_listesi[10];
        int yil_listesi[10];
        string model_listesi[10];
        for(int i=0;i< 10;i++)
        yil_listesi[i]=0;
        for(int i=0;i< 10;i++)
        fiyat_listesi[i]=0;
        string satir;
//FIYATLAR KAYDETME
        ifstream fiyatlarOku(txt_dosyası);
        if(fiyatlarOku.is_open())
        {
        int i=0;
        while(getline(fiyatlarOku,satir))
        {
        istringstream satirstream(satir); // satırı stream a çeviriyor nasıl ifstream dosyayı stream a çeviriyorsa
        string substring;
        int count=0;
        while(getline(satirstream,substring,',')){ // satırı virgüle göre bölerek sırayla almayı sağlıyor
        if(count==0){
        fiyat_listesi[i]=stoi(substring);
        }
        else if(count==2){
        marka_listesi[i]=substring;
        }
        else if(count==1){
        yil_listesi[i]=stoi(substring); // string i integera çeviriyor stoi
        }
        else if(count==3){
        model_listesi[i]=substring;
        }
        count++;
        }
        i++;
        }
        fiyatlarOku.close();
        }
        int toplam_araba_sayısı=0;
        for(int i=0;i< 10&&fiyat_listesi[i]!=0;i++)
        toplam_araba_sayısı=i+1;
        Araba*arr=new Araba[toplam_araba_sayısı];
        for(int i=0;i<toplam_araba_sayısı; i++){
        arr[i]=Araba(fiyat_listesi[i],yil_listesi[i],marka_listesi[i],
        model_listesi[i]);
        }
        ArabaListesi normalArabaListesi=ArabaListesi(arr,
        toplam_araba_sayısı);
        return normalArabaListesi;
        }
        KlasikArabaListesi klasikAraba_Oku(string txt_dosyası)
        {
        int fiyat_listesi[10];
        string marka_listesi[10];
        int yil_listesi[10];
        int uretilis_adedi[10];
        string model_listesi[10];
        for(int i=0;i< 10;i++)
        yil_listesi[i]=0;
        for(int i=0;i< 10;i++)
        fiyat_listesi[i]=0;
        for(int i=0;i< 10;i++)
        uretilis_adedi[i]=0;
        string satir;
//FIYATLAR KAYDETME
        ifstream fiyatlarOku(txt_dosyası);
        if(fiyatlarOku.is_open())
        {
        int i=0;
        while(getline(fiyatlarOku,satir))
        {
        istringstream satirstream(satir); // satırı stream a çeviriyor nasıl ifstream dosyayı stream a çeviriyorsa
        string substring;
        int count=0;
        while(getline(satirstream,substring,',')){ // satırı virgüle göre bölerek sırayla almayı sağlıyor
        if(count==0){
        fiyat_listesi[i]=stoi(substring);
        }
        else if(count==1){
        yil_listesi[i]=stoi(substring);
        }
        else if(count==2){
        uretilis_adedi[i]=stoi(substring);
        }
        // string i integer a çeviriyor stoi
        else if(count==3){
        marka_listesi[i]=substring;
        }
        else if(count==4){
        model_listesi[i]=substring;
        }
        count++;
        }
        i++;
        }
        fiyatlarOku.close();
        }
        int toplam_araba_sayısı=0;
        for(int i=0;i< 10&&fiyat_listesi[i]!=0;i++){
        toplam_araba_sayısı=i+1;
        }
        Klasik_Araba*arr=new Klasik_Araba[toplam_araba_sayısı];
        for(int i=0;i<toplam_araba_sayısı; i++){
        arr[i]=Klasik_Araba(fiyat_listesi[i],yil_listesi[i],uretilis_adedi[i],
        marka_listesi[i],model_listesi[i]);
        }
        KlasikArabaListesi normalar=KlasikArabaListesi(arr,
        toplam_araba_sayısı);
        return normalar;
        }
        SporArabaListesi sporAraba_Oku(string txt_dosyası)
        {
        int fiyat_listesi[10];
        string marka_listesi[10];
        int beygir_gucu[10];
        int yil_listesi[10];
        string model_listesi[10];
        for(int i=0;i< 10;i++)
        yil_listesi[i]=0;
        for(int i=0;i< 10;i++)
        fiyat_listesi[i]=0;
        for(int i=0;i< 10;i++)
        beygir_gucu[i]=0;
        string satir;
//FIYATLAR KAYDETME
        ifstream fiyatlarOku(txt_dosyası);
        if(fiyatlarOku.is_open())
        {
        int i=0;
        while(getline(fiyatlarOku,satir))
        {
        istringstream satirstream(satir); // satırı stream a çeviriyor nasıl ifstream dosyayı stream a çeviriyorsa
        string substring;
        int count=0;
        while(getline(satirstream,substring,',')){ // satırı virgüle göre bölerek sırayla almayı sağlıyor
        if(count==0){
        fiyat_listesi[i]=stoi(substring);
        }
        else if(count==3){
        marka_listesi[i]=substring;
        }
        else if(count==1){
        yil_listesi[i]=stoi(substring); // string i integer a çeviriyor stoi
        }
        else if(count==4){
        model_listesi[i]=substring;
        }
        else if(count==2){
        beygir_gucu[i]=stoi(substring);
        }
        count++;
        }
        i++;
        }
        fiyatlarOku.close();
        }
        int toplam_araba_sayısı=0;
        for(int i=0;i< 10&&fiyat_listesi[i]!=0;i++){
        toplam_araba_sayısı=i+1;
        }
        Spor_Araba*arr=new Spor_Araba[toplam_araba_sayısı];
        for(int i=0;i<toplam_araba_sayısı; i++){
        arr[i]=Spor_Araba(fiyat_listesi[i],yil_listesi[i],
        beygir_gucu[i],marka_listesi[i],model_listesi[i]);
        }
        SporArabaListesi sporArabaListesi=SporArabaListesi(arr,
        toplam_araba_sayısı);
        return sporArabaListesi;
        }
        int main(){
        myfile.is_open();
        int tercih=0;
        ArabaTercih:
        cout<<"Klasik Arabalarla Ilgileniyorsaniz 1'i \nSpor Arabalarla ilgileniyorsaniz 2'yi \nNormal Arabalarla ilgileniyosaniz 3'u tuslayin:";
        cin>>tercih;
        if(tercih>=1&&tercih<=3){
        if(tercih==1){
        KlasikArabaListesi klasikarabalistesi=
        klasikAraba_Oku("klasikarabalar.txt");
        for(int i=0;i<klasikarabalistesi.araba_sayisi;i++){
        klasikarabalistesi.klasikArabalar[i].klasik_info();
        klasikarabalistesi.klasikArabalar[i].Gelecek_Araba();
        }
        }
        else if(tercih==2){
        SporArabaListesi sporarabalistesi=
        sporAraba_Oku("sporarabalar.txt");
        for(int i=0;i<sporarabalistesi.araba_sayisi;i++){
        sporarabalistesi.sporArabalar[i].spor_info();
        sporarabalistesi.sporArabalar[i].Gelecek_Araba();
        }
        }
        else if(tercih==3){
        ArabaListesi arabalistesi=araba_Oku("araba.txt");
        for(int i=0;i<arabalistesi.araba_sayisi;i++){
        arabalistesi.arabalar[i].car_info();
        arabalistesi.arabalar[i].Gelecek_Araba();
        }
        }
        }
        else{
        cout<<"Hatali Giris Yaptiniz, Lutfen Tekrar giris yapin: ";
        goto ArabaTercih;
        }
        myfile.close();
        system("pause");
        }