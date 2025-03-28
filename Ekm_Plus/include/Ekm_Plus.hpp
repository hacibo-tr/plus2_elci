
#ifndef _EKM_PLUS_H_
#define _EKM_PLUS_H_

#include <Arduino.h>

//#include "TPrinter.h"//this library works tested
//#include <HardwareSerial.h>//for printer
//#include <Q2HX711.h>
//#include <Adafruit_SPIDevice.h>
//#include <RTClib.h>
//#include "CountDown.h"
#include <LiquidCrystal.h>

#include <OneWire.h>
#include <Wire.h>
#include <DallasTemperature.h>

#include "Data_Bank.h"
#include "Diller.h"
#include "PCF.hpp"
#include <EEPROM.h>
//#include <Preferences.h>    //as EEPROM
/*================================================ for firmware update ===========================================================*/

#include <WiFi.h>   /// açmayı unutma!
#include <HTTPClient.h>
#include <ESP32httpUpdate.h>
#include "Mail.hpp"
#include <ESP_Mail_Client.h>
//#include "Mail_Gonder.hpp"

#define TURKIYE                 1
#define SMARTCON                2
#define STARKA                  3


 #define SATIS_YERI              TURKIYE//
// #define SATIS_YERI              SMARTCON
// #define SATIS_YERI               STARKA 
#define Geri_Buton     0
#define Giris_Buton    1
#define Yukari_Buton   2
#define Asagi_Buton    3
#define Sag_Buton      4
#define Sol_Buton      5

#define BUZER_PINI              13        
#define SICAKLIK_SENSOR_PINI    25   

#define LCD_RS_PINI           19
#define lCD_EN_PINI           23
#define LCD_D4_PINI           32
#define LCD_D5_PINI           33
#define LCD_D6_PINI           27
#define LCD_D7_PINI           17

#define Buzer_Ac       digitalWrite(BUZER_PINI, HIGH)//HIGH
#define Buzer_Kapa     digitalWrite(BUZER_PINI, LOW)

#define SATIR_1   0
#define SATIR_2   1
#define SATIR_3   2
#define SATIR_4   3
#define SATIR_5   4
#define SATIR_6   5
#define SATIR_7   6
#define SATIR_8   7


#define OLAY_YOK             0
#define OLAYI_TEMIZLE        1
#define BASILDI_OLAYI        2
#define UZUN_BASILDI_OLAYI   3

#define HATA_OLUSTU         99
#define IPTAL_ET            99
#define WIFI_BAGLANTISI_YOK 255
#define ALICI_GIRILDI       7
// #define ANA_MENU_DON        255

#define AC                  1                 
#define KAPAT               2
#define ACIK                3   
#define KAPALI              4
#define VAR                 5
#define YOK                 6

#define BAGLANDI            1
#define BAGLANAMADI         2
#define WIFI_BULUNAMADI     3



#define ARABADAN_GAZ_CEKILIYOR      1
#define TUPTEN_GAZ_CEKILIYOR        2

#define EEPROM_KONTROL_YERI                   0
#define CIHAZ_DIL_YERI                        2
#define VAKUM_SURE_KAYIT_YERI                 16
#define KACAK_SURE_KAYIT_YERI                 32
#define DOLUM_MIKTAR_KAYIT_YERI               48   // doldurulacak gaz miktarı. Dolumdan hemen önce belirlenip kayıt ediliyor
#define BASINC_BOLEN_KAYIT_YERI            	  64    
#define BASINC_DARA_KAYIT_YERI                80
#define TANK_KAPASITE_KAYIT_YERI              96
#define TUP_DARA_KAYIT_YERI            	      112

#define GAZ_SENSORU_DURUM_KAYIT_YERI          144
#define ISITICI_DURUM_KAYIT_YERI              160
#define YAZICI_DURUM_KAYIT_YERI               176
#define GAZ_SENSOR_DARA_KAYIT_YERI            192

#define TERAZI_BOLEN_KAYIT_YERI               240
#define TERAZI_DARA_KAYIT_YERI                256
#define VAKUM_DARA_KAYIT_YERI                 272
#define VAKUM_BOLEN_KAYIT_YERI                288
#define VAKUM_REF_ATM_KAYIT_YERI              304
#define TERAZI_REF_GR_KAYIT_YERI              320
#define SERI_NO_KAYIT_YERI                    336
#define TOPLAM_VAKUM_SURE_KAYIT_YERI          352
#define KOMPRESOR_KAPANMA_KAYIT_YERI          368
#define TOPLAM_GAZ_DOLUM_KAYIT_YERI           384
#define CIHAZ_ADI_KAYIT_YERI                  400

#define TUP_GAZ_MIKTAR_KAYIT_YERI             432
#define GAZ_TIPI_KAYIT_YERI                   448
#define TOPLAM_ARACTAN_CEKILEN_KAYIT_YERI     464

#define SON_CEKILEN_GAZ_YERI                  496
#define YAZ_VERSIYON_KAYIT_YERI               512
#define YAZ_REVIZYON_KAYIT_YERI               528
#define SON_SECILEN_MARKA_YERI                544
#define TOPLAM_TUPTEN_CEKILEN_KAYIT_YERI      560
#define FILTRE_KALAN_KAPASITE_KAYIT_YERI      576
#define FILTRE_SAYISI_YERI                    592
#define FILTRE_KAPASITE_KAYIT_YERI            608
#define KONTRAST_KAYIT_YERI                   624
#define ACILMA_SAYISI_KAYIT_YERI              640

#define WIFI_AD_KAYIT_YERI                    650 /// 50 byte
#define WIFI_SIFRE_KAYIT_YERI                 700 /// 25 byte
#define GONDERICI_MAIL_KAYIT_YERI             725 ///35 byte
#define GONDERICI_MAIL_SIFRE_KAYIT_YERI       760 ///25
#define SON_ALICI_MAIL_KAYIT_YERI             785 //35
#define EEPROM_VERI_KONTROL_YERI              810 //5


// #define Sifirlama                               0
// #define Yag_Sorgusu_ve_Basinc_Kontrol           1
// #define Baslama_Sorgusu                         2
// #define Sistemde_Gaz_Var_Mi_Kontrolu            3
// #define Sistemden_Gaz_Cekme                     4
// #define Vakum_Yapma                             5
// #define Kacak_Bekleme                           6
// #define Yag_Ekleme                              7
// #define Gaz_Doldurma                            8
// #define Gaz_Ekleme                              9
// #define Hortum_Temizleme                        10
// #define Islem_Yazdirma                          11
// #define Islem_Iptali                            12
// #define Cikis_Bekle                             13
// #define Kacak_Cikisi                            14
// #define Bakim_Kontrolu                          15
// #define Giris_Bekle                             16
// #define Anamenu_Beklemesi                       17
// #define Yazdirma_Sorgusu                        18

// #define Gaz_Cekim_Baslangic       0
// #define Gaz_Kontrolu              1
// #define Kapasite_Kontrolu         2
// #define Hazirlik                  3
// #define Gaz_Cekimi                4
// #define Buharlasma_Bekle          5
// #define Gaz_Cekme_Bitir           6
// #define Gaz_Cekim_Iptal_Secenegi  7
// #define Gaz_Cekim_Iptal_Sorgusu   8
// #define Gaz_Cekim_Iptal_Onayi     9
// #define Gaz_Yok_Iptali            10

#define BUTON_BASILDI_MS   200
#define BUTON_UZUN_BASILDI_MS  2000
#define GAZ_CEKME_ISLEM_ZAMAN_SINIRI      900000   /// 15 dk
#define GAZ_CEKME_ZAMAN_SINIRI            600000   // 10dk
#define BUHARLASMA_BEKLEME_SURESI          58000

#define Bubble_Sayisi                     10
#define KACAK_TOLERANSI                   80
#define KACAK_SINIRI                      10
#define VAKUM_BAKIM_SAATI                 30
#define UZUN_BUZER                        2000
#define KISA_BUZER                        100
struct Buttons {
  const int debounce = 10;

  unsigned char Basildi;
  unsigned char Olay;
  unsigned short Degeri_Degisti;
  unsigned short Sayac;
  unsigned short Temizleme_ms;
  unsigned char Durum;
};


struct EKM_Plus {

  volatile unsigned int MS;
  volatile unsigned int Wifi_ms;

  unsigned short Vakum_Suresi_Dk;
  //	unsigned char Kacak_Suresi_Sn;
  unsigned short Kacak_Suresi_Dk;
  unsigned char Isitici_Suresi_Dk;

  char Bulunan_Wifiler[20][50];
  char Girilen_Sifre[25];
  char Girilen_Metin[25];
  char Kayitli_Wifi[50];
  char Kayitli_Wifi_Sifresi[25];
  char Secilen_Marka[15];
  char Gonderici_Maili[35];
  char Gonderici_Sifresi[25];
  char Alici_Maili[35];
  char Alici_Uzantisi[30];

  char Cihaz_Adi[21];
  
  char Yaz_Versiyon[10];
  char Yaz_Revizyon[10];

  unsigned char Sayfa;
  unsigned char Giris_Sayfa;
  unsigned char Diger_Ayarlar_Sayfa;
  unsigned char Imlec;
  unsigned char Imlec_Yonu;
  unsigned char Buzer_Acik;
  unsigned char Kalibre_Yapiliyor;
  unsigned char Marka_Sayisi;
  unsigned char Gaz_Tipi;
  unsigned char Tank_Kapasitesi;
  unsigned char Wifi_Durumu;
  unsigned char Lcd_Kontrast_Degeri;
  unsigned char Acilma_Sayisi;
  unsigned char Serial_Gelen;
  unsigned char Yag_Dolumu;
  unsigned char Seri_No_Arttir;
  signed char Sicaklik;

  // unsigned char Printer_Baslik_Sifirla;
  // unsigned char Tarih_Saat_Ayar_Sifirla;
  // unsigned char Terazi_Kalibre_Sifirla;
  // unsigned char Vakum_Kalibre_Sifirla;
  // unsigned char Silindir_Degisim_Sifirla;
  // unsigned char Gaz_Dolum_Sifirla;
  // unsigned char Yazilim_Guncelleme_Sifirla;
  // unsigned char Wifi_Sifre_Gir_Sifirla;
  // unsigned char Sifre_Degisim_Sifirla;
  // unsigned char Sayi_Giris_Sifirla;


  unsigned char Vakum_Etkin;
  unsigned char Isitici_Etkin;
  unsigned char Vakum_Isi_Farki;
  unsigned char Dil;
  unsigned char Gaz_Cekilme_Yeri;     
  unsigned char Yazici;

  unsigned short Dolum_Miktari_Gr;
  unsigned short Cekilecek_Gaz_Miktari;
  unsigned short Model_Sayisi;
  unsigned short Secili_Model_Yeri;
  
  unsigned short Ref_Atm;
  unsigned short Ref_Gr;
  unsigned short Vakum_Test_1_mBr;
  unsigned short Vakum_Test_2_mBr;
  
  unsigned short Filtre_Sayisi;
  unsigned short Son_Secilen_Marka;
  unsigned short Buzer_Calma_ms;
  unsigned short Son_Cekilen_Gr;

  signed int Vakum_Darasi;
  signed int Terazi_Darasi;
  signed int Basinc_Darasi;
  unsigned int Toplam_Dolum_Gr;
  unsigned int Toplam_Tupten_Cekilen_Gr;
  unsigned int Toplam_Aractan_Cekilen_Gr;
  unsigned int Toplam_Vakum_Dk;
  unsigned int Vakum_Bakim_Dk;
  unsigned int Seri_No;
  unsigned int E_Seri_No;
  unsigned int Islem_Dk;
  unsigned int Islem_Sn;
  unsigned int Filtre_Kapasitesi_Kg;
  unsigned int Kompresor_Kapanma;
  unsigned int Filtre_Kalan_Gr;
  unsigned int Servis_Sifresi;
  unsigned int Chipid;

  float Terazi_Gr;
  float Vakum_Br;
  float Basinc_Br;
  

  float Ilk_Terazi_Gr;
  float Terazi_Boleni;
  float Vakum_Boleni;
  float Basinc_Boleni;
};



struct Veriler{

  unsigned short Dolan_Gr;
  unsigned short Cekilen_Gr;
  unsigned short Vakum_Dk;
  unsigned short Kacak_Dk;
  unsigned short Vakum_Degeri_mBr;
  unsigned short Kacak_Degeri_mBr;
  unsigned short Yil;

  char Plaka[20];
  unsigned char Gun;
  unsigned char Ay;
  unsigned char Saat;
  unsigned char Dakika;
  unsigned char Saniye;

};


struct rtc_zaman {
  uint8_t Sn;
  uint8_t Dk;
  uint8_t Saat;
  uint8_t Gun;
  uint8_t Gun_Adi;
  uint8_t Ay;
  uint16_t Yil;
};

extern struct Buttons Buton[6];
extern struct EKM_Plus EKM;
extern struct Veriler Yazilacaklar;
extern struct rtc_zaman Rtc_Zamani;


enum Geri_Donusler
{
  DEVAM_EDIYOR,        
  TAMAMLANDI,                                       
  GAZ_YOK,             
  GAZ_VAR,            
  TANK_DOLU,            
  YER_VAR,  
  VAKUM_DUSUK,    
  KACAK_VAR, 
  FILTRE_BITMIS, 
  FILTRE_AZ,    
  ANA_MENU_DON,
  YAZDIRMA_SOR,
  BASINC_YUKSEK,
  MAIL_SOR,
};

enum Adimlar
{
  Sifirlama,                               
  Yag_Sorgusu_ve_Basinc_Kontrol,           
  Baslama_Sorgusu,                         
  Sistemde_Gaz_Var_Mi_Kontrolu,            
  Sistemden_Gaz_Cekme,                     
  Vakum_Yapma,                             
  Kacak_Bekleme,                          
  Yag_Ekleme,                              
  Gaz_Doldurma,                            
  Gaz_Ekleme,                              
  Hortum_Temizleme,                        
  Islem_Yazdirma,                          
  Islem_Iptali,                            
  Cikis_Bekle,                             
  Kacak_Cikisi,                            
  Bakim_Kontrolu,                          
  Giris_Bekle,                             
  Anamenu_Beklemesi,                       
  Yazdirma_Sorgusu, 
  Miktar_Giris,                       
  Gaz_Cekim_Baslangic,       
  Gaz_Kontrolu,              
  Kapasite_Kontrolu,         
  Hazirlik,                  
  Gaz_Cekimi,                
  Buharlasma_Bekle,          
  Gaz_Cekme_Bitir,           
  Gaz_Cekim_Iptal_Secenegi,  
  Gaz_Cekim_Iptal_Sorgusu,   
  Gaz_Cekim_Iptal_Onayi,    
  Gaz_Yok_Iptali,         
  Mail_Sorgusu,   
  Mail_Atma,
  Yazdirma_Secimi,
  Wifi_Baglanma,
  Alici_Girisi,
  Uzanti_Girisi,
  Uzanti_Secimi,
  Wifi_Tarama,
  Kayitli_Wifi_Secim,
  Bulunanlari_Goster,
  Wifi_Secimi,
  Wifi_Sifre_Girisi,
  Wifi_Baglandi,
  Bekle_ve_Cik,
  Plaka_Girisi,
  Bitirme_Beklemesi,
};

enum Sayfalar
{
  Acilis_Sayfasi,
  Giris_Sayfasi,
  Bilgiler_Sayfasi,
  Marka_Secim_Sayfasi,
  Model_Secim_Sayfasi,

  Otomatik_Dolum_Sayfasi,
  Manuel_Dolum_Sayfasi,

  Parametreler_Sayfasi,
  Ayar_Secim_Sayfasi,
  Cihaz_Ayarlari_Sayfasi,
  Tarih_Saat_Ayar_Sayfasi,
  Yazici_Baslik_Ayar_Sayfasi,
  Parola_Degistirme_Sayfasi,
  Servis_Ayarlari_Sayfasi,
  Vakum_Sure_Ayar_Sayfasi,
  Kacak_Sure_Ayar_Sayfasi,
  Vakum_Test_1_Sayfasi,
  Vakum_Test_2_Sayfasi,
  Sifre_Sayfasi,
  Vakum_Ayar_Sayfasi,
  Kalibrasyon_Secim_Sayfasi,
  Valf_Test_Sayfasi,
  Vakum_Kalibrasyon_Sayfasi,
  Gaz_Doldurma_Sayfasi,
  Yazilim_Guncelleme_Sayfasi,
  Vakum_Bakim_Uyari_Sayfasi,
  Gaz_Doldurma_Secim_Sayfasi,
  Tupten_Gaz_Cekme_Sayfasi,
  Aractan_Gaz_Cekme_Sayfasi,
  Kullanim_Bilgileri_Sayfasi,
  Hortum_Temizleme_Sayfasi,
  Ayar_Giris_Sayfasi,
  Gaz_Tipi_Degisim_Sayfasi,
  Dil_Secim_Sayfasi,
  Sistem_Bosaltma_Sayfasi,
  Sistem_Vakumlama_Sayfasi,
  Bakim_Sayfasi,
  Kompresor_Kapatma_Ayar_Sayfasi,
  Servis_Giris_Sayfasi,
  Servis_Ayar_Secim_Sayfasi,
  Terazi_Ayar_Sayfasi,
  Terazi_Dara_Sayfasi,
  Terazi_Kalibrasyon_Sayfasi,
  Terazi_Kalibrasyon_Secim_Sayfasi,
  Basinc_Ayar_Sayfasi,
  Basinc_Dara_Sayfasi,
  Basinc_Kalibrasyon_Sayfasi,
  Basinc_Kalibrasyon_Secim_Sayfasi,
  Tank_Kapasite_Ayar_Sayfasi,
  Filtre_Kapasite_Ayar_Sayfasi,
  Yazici_Secim_Ayar_Sayfasi,
  Diger_Ayarlar_Sayfasi,
  Gonderici_Mail_Giris_Sayfasi,
  Wifi_Baglanma_Sayfasi,
};
extern void Lcd_Yaz(char Gelen);
extern void Lcd_Set_Cursor(unsigned char Cizgi_Yeri,unsigned char Yazi_Satir_Yeri);
extern void Butonlari_Temizle(void);
extern void Buton_Sorgula(unsigned char Buton_No, bool Durumu);
extern void Tarih_Saat_Ayarla(unsigned char Saat, unsigned char Dakika, unsigned char Gun, unsigned char Ay, unsigned char Yil);
extern void Printer_Ayarla(char Ayar_1, char Ayar_2, char Ayar_3);
extern void Printer_Yazdir(const char* Yazilacak, char Cr, char Lf);
extern void Eepromdan_Verileri_Al(void);
extern void Rtc_Kur(void);
extern void Ekrani_Kur(void);
extern void Zaman_Al(struct rtc_zaman *Zaman);
extern void Zamani_Goster(void);
extern void Bekle_us(void);
extern void Bekle_ms(unsigned int _ms);
extern void Lcd_Sure_Yaz(unsigned char x_Pos, unsigned char y_Pos, signed int Sayi, unsigned char Boyut, unsigned char Hane);
extern void Lcd_Sayi_Yaz(unsigned char x_Pos, unsigned char y_Pos, signed int Sayi, unsigned char Boyut, unsigned char Hane);
extern void Yazici_Test(void);
extern unsigned char Emniyet(void);

extern signed int Bubble_Sort(signed int Siralanacak[Bubble_Sayisi + 1]);
extern unsigned char HX_710_Oku(unsigned char Secim, unsigned char clks, float *Okunan_Veri);
extern unsigned char Terazi_Oku(float *okunan);
extern unsigned char Vakum_Oku(float *okunan);

extern void Veri_Kaydet_Float(int Yeri, float veri);
extern void Veri_Kaydet_Uchar(int Yeri, unsigned char veri);
extern void Veri_Kaydet_Ushort(int Yeri, unsigned short veri);
extern void Veri_Kaydet_UInt(int Yeri, unsigned int veri);
extern void Veri_Kaydet_Int(int Yeri, signed int veri);
extern void Veri_Kaydet_Short(int Yeri, signed short veri);
extern void Veri_Kaydet_String(int Yeri, char* veri);
extern void Vakum_Darasini_Eepromdan_Oku(void);
extern void Sistem_Bosaltma(void);
extern void Kullanim_Bilgileri(void);
extern void Ayar_Secimi(void);
extern void Ayarlar_Giris(void);
extern void Giris_Cikislari_Ayarla(void);
extern void Imlec_Yaz(unsigned char Yer);
extern void Kayittan_Yazi_Yaz(unsigned char x_pos, unsigned char y_pos, unsigned int Text_yeri);
extern void Yazi_Yaz(unsigned char x_pos, unsigned char y_pos, const char* text, byte text_size);
extern void Cizgi_Cek(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char renk);
extern void Giris_Sayfa(unsigned char Sayfa, unsigned char Imlec);
extern void Ayar_Secim_Sayfa(unsigned char Imlec_Yeri);
extern void Diger_Ayarlar_Secim_Sayfa(unsigned char Sayfa);
extern void Diger_Ayarlar_Secimi(void);
extern void Cihaz_Ayarlar_Sayfa(unsigned char Imlec_Yeri);
extern void Dil_Secimi(void);
extern void Sistem_Vakumlama(void);
extern unsigned char Kacak_Bekle(unsigned char xpos, unsigned char ypos, unsigned short Bekleme_Dk, unsigned char Bekleme_Sn, unsigned char Gosterim);
extern void Tarih_Saat_Ayar_Sayfa(void);
extern void Tarih_Saat_Ayari(unsigned char Durum);
extern void Yazici_Baslik_Ayar_Sayfa(void);
extern void Yazici_Baslik_Ayari(unsigned char Durum);
extern unsigned char Kalan_Sure_Goster(unsigned char x_pos, unsigned char y_pos, unsigned char Sayilacak_Dk, unsigned char Sayilacak_Sn);
extern unsigned char Buyuk_Sayi_Gir(unsigned char Sutun, unsigned char Satir, unsigned int *Girilen, unsigned char Sayi_Hane);
extern unsigned char Sayi_Girisi(unsigned char Sutun, unsigned char Satir, unsigned short *Girilen, unsigned char Sayi_Hane);
extern void Cihaz_Ayarlari(void);
extern void Terazi_Kalibrasyon_Secimi(void);
extern void Basinc_Kalibrasyon_Secimi(void);
extern void Kalibrasyon_Secim_Sayfa(unsigned char Imlec_Yeri);
extern void Terazi_Kalibrasyonu(void);
extern void Vakum_Kalibrasyonu(void);
extern void Kalibrasyon_Secimi(void);
extern void Pcf_Yaz(uint16_t Valf_Adresi);
extern void SSR_Kontrol(unsigned char SSR,unsigned char Durum);
extern void Valf_Test_Sayfa(void);
extern void Valf_Testi(void);
extern void Servis_Ayar_Sayfa(unsigned char Imlec_Yeri);
extern void Servis_Ayar_Giris(void);
extern void Servis_Ayar_Secimi(void);
extern void Gaz_Dolum_Sayfasi(void);
extern void Islem_Secimi(void);
extern unsigned char Gaz_Cek(void);
extern unsigned char Vakum_Yap(void);
extern unsigned char Sifre_Kontrol(unsigned int Sifre);
extern unsigned char Plaka_Gir(void);
extern unsigned char Wifi_Sifre_Gir(void);
extern void Vakum_Uyari_Sayfa(void);
extern void Bilgiler_Sayfa(void);
extern void Sayfalari_Sorgula(void);
extern void Gaz_Tipi_Secimi(void);
extern void Wifi_Baglanma_Sayfa(void);
extern void Isitici_Kontrol(unsigned char Durum);
extern unsigned char Hava_Tahliye_Kontrol(void);
extern unsigned char Hemen_Yag_Cek();
extern void Yag_Cek_Kontrol(unsigned char Durum);
extern unsigned char Kapasite_Kontrol(void);
extern unsigned char Gaz_Cekme_Hazirlik(void);
extern unsigned char Sistemde_Gaz_Var_Mi(void);
extern void Ekranda_Gr_Goster (signed int Gr);
extern unsigned short Hiz_Hesapla(float Gaz_Miktari);
extern unsigned char Gaz_Cekmeyi_Bitir(void);
extern unsigned char Gaz_Cek(unsigned char Cekilecek_Yer);

extern unsigned char Marka_Sayisi(void);
extern void Model_Yerini_Bul_ve_Goster(void);
extern void Markari_Goster(unsigned char Marka_No);
extern void Modelleri_Goster(void);
extern void Marka_Secim(unsigned short No);

extern void Wifi_Baglanti_Kontrol(void);
extern void guncelle_hata(void);
extern void ag_yok_hata(void);
extern void Yazilim_Guncelle(void);
extern void Ekrani_Temizle(void);
extern void Seri_No_Arttir(void);

#endif
// extern void Enter_Ciz()
// {
//   display.drawLine(125, 15, 125, 22, WHITE);
//   display.drawLine(125, 22, 115, 22, WHITE);
//   display.drawTriangle(115, 22, 120, 25, 120, 19, WHITE);
//   display.fillTriangle(115, 22, 120, 25, 120, 19, WHITE);// display.setRotation(3);
//   display.display();
// }

// unsigned short Gaz_Sensoru_Oku(unsigned short *Sensor_Degeri)
// {
//   unsigned int _ms = 0;
//   static unsigned short Deger = 0;

//   if ((EKM.MS - _ms) > 500)
//   {
//     _ms = EKM.MS;
//     Deger = analogRead(GAZ_SENSOR_PINI);

//     if (Deger > EKM.Gaz_Sensor_Dara)
//       Deger -= EKM.Gaz_Sensor_Dara;
//     else
//       Deger = 0;

//     *Sensor_Degeri = Deger;
//     return 1;
//   }
//   return 0;
// }


// unsigned char Gaz_Sensor_Bekleme(unsigned char Gosterim)
// {
//   static unsigned char Bekleme_Adimi = 0;
//   static unsigned int Kalan_Sure = 0, Bekleme_Ms = 0, E_Sure = 0;

//   if (Gosterim == 99)
//   {
//     Bekleme_Ms = EKM.MS + Acilis_Beklemesi_Ms;
//     Kalan_Sure = Bekleme_Ms - EKM.MS;
//     Bekleme_Adimi = 1;
//     //    Gosterim = 0;
//   }
//   if (Bekleme_Adimi == 0)
//   {
//     Bekleme_Ms = Acilis_Beklemesi_Ms;

//     if (EKM.MS < Bekleme_Ms)
//     {
//       Bekleme_Adimi = 1;
//       Kalan_Sure = Bekleme_Ms - EKM.MS;
//       display.setFont();
//     }
//     else
//       Bekleme_Adimi = 3;
//   }
//   if (Bekleme_Adimi == 1)
//   {
//     Bekleme_Adimi = 2;
//     if (Gosterim == 1)
//     {
//       display.clearDisplay();
//       display.setTextColor(WHITE, BLACK);
//       display.setFont(&FreeSans9pt7b);
//       Yazi_Yaz(0, 24, "  Please Wait", 1);
//       Yazi_Yaz(84, 54, "sec", 1);   ///// 42+12
//       Kalan_Sure = Bekleme_Ms - EKM.MS;
//       display.setFont();
//       Lcd_Sure_Yaz(40, 42, (Kalan_Sure / 1000), 2, 2);
//       display.display();
//     }
//     return 1;
//   }
//   else if (Bekleme_Adimi == 2)
//   {
//     if ((EKM.MS - E_Sure) > 1100)
//     {
//       E_Sure = EKM.MS;
//       if (Gosterim == 1)
//       {
//         display.clearDisplay();
//         display.setTextColor(WHITE, BLACK);
//         display.setFont(&FreeSans9pt7b);
//         Yazi_Yaz(0, 24, "  Please Wait", 1);
//         Yazi_Yaz(84, 54, "sec", 1);   ///// 42+12
//         Kalan_Sure = Bekleme_Ms - EKM.MS;
//         display.setFont();
//         Lcd_Sure_Yaz(40, 42, (Kalan_Sure / 1000), 2, 2);
//         display.display();
//       }
//     }
//     else if ((EKM.MS - E_Sure) > 1000)
//     {
//       if (Gosterim == 1)
//       {
//         E_Sure = EKM.MS;
//         Kalan_Sure = Bekleme_Ms - EKM.MS;
//         display.setFont();
//         Lcd_Sure_Yaz(40, 42, (Kalan_Sure / 1000), 2, 2);
//         display.display();
//       }
//       if (EKM.MS < Bekleme_Ms)
//         return 1;
//       else
//         Bekleme_Adimi = 3;
//     }
//   }
//   else if (Bekleme_Adimi == 3)
//   {
//     return 0;
//     Bekleme_Adimi = 0;
//   }
//   return 1;
// }
