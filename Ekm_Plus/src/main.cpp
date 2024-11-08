#include <Arduino.h>
#include "Ekm_Plus.hpp"

//WiFiMulti WiFiMulti;
//the ESP32 IP address(the grey):IP address: 192.168.1.188

 //String ssid = "" ; String password = "" ;

#define LOADCELL_DOUT_PIN       39
#define LOADCELL_SCK_PIN        12
#define VAKUMSENSOR_DOUT_PIN    15
#define VAKUMSENSOR_SCK_PIN     2
#define BASINCSENSOR_DOUT_PIN   14 
#define BASINCSENSOR_SCK_PIN    4
#define LCD_KONTRAST_PINI       26

//// 5-16-18-34-35-36


#define GERI_BUTON_PINI         5  
#define GIRIS_BUTON_PINI        35
#define ASAGI_BUTON_PINI        16  
#define YUKARI_BUTON_PINI       18    
#define SOL_BUTON_PINI          36    
#define SAG_BUTON_PINI          34

#define LCD_RESOLUTION          8

#define BUTON_BASMA_SURESI_MS    50
#define BUTON_UZUN_BASMA_SURESI_MS 2000

#define Geri_Basildi     !digitalRead(GERI_BUTON_PINI)
#define Giris_Basildi    !digitalRead(GIRIS_BUTON_PINI)
#define Asagi_Basildi    !digitalRead(ASAGI_BUTON_PINI)
#define Yukari_Basildi   !digitalRead(YUKARI_BUTON_PINI)
#define Saga_Basildi     !digitalRead(SAG_BUTON_PINI)
#define Sola_Basildi     !digitalRead(SOL_BUTON_PINI)

#define L_SCK_1        digitalWrite(LOADCELL_SCK_PIN, HIGH)
#define L_SCK_0        digitalWrite(LOADCELL_SCK_PIN, LOW)
#define L_DIN          digitalRead(LOADCELL_DOUT_PIN)

#define V_SCK_1        digitalWrite(VAKUMSENSOR_SCK_PIN, HIGH)
#define V_SCK_0        digitalWrite(VAKUMSENSOR_SCK_PIN, LOW)
#define V_DIN          digitalRead(VAKUMSENSOR_DOUT_PIN)

#define B_SCK_1        digitalWrite(BASINCSENSOR_SCK_PIN, HIGH)
#define B_SCK_0        digitalWrite(BASINCSENSOR_SCK_PIN, LOW)
#define B_DIN          digitalRead(BASINCSENSOR_DOUT_PIN)

#define TERAZI   1
#define VAKUM    2
#define BASINC   3

#define ASAGI  1
#define YUKARI 2

//#define Sicaklik_Sensoru_Oku()  Sicaklik_Sensoru.requestTemperatures();
LiquidCrystal lcd(LCD_RS_PINI,lCD_EN_PINI,LCD_D4_PINI,LCD_D5_PINI,LCD_D6_PINI,LCD_D7_PINI);

// extern struct Buttons Buton[6];
EKM_Plus EKM;
Veriler Yazilacaklar;
rtc_zaman Rtc_Zamani;
Buttons Buton[6];

const byte rxPin = 3;   // pin map for printer
const byte txPin = 1;   // pin map for printer

OneWire oneWire(SICAKLIK_SENSOR_PINI);// Setup a oneWire instance to communicate with any OneWire devices
DallasTemperature Sicaklik_Sensoru(&oneWire);// Pass our oneWire reference to Dallas Temperature sensor 

// for DS1306 OLED display
// #define SCREEN_WIDTH 128 // OLED display width, in pixels
// #define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

hw_timer_t * timer = NULL;

void Butonlari_Temizle(void)
{
  Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
  Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
  Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
  Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
  Buton[Sol_Buton].Olay = OLAYI_TEMIZLE;
  Buton[Sag_Buton].Olay = OLAYI_TEMIZLE;
}

void IRAM_ATTR onTimer()
{
  static unsigned int _ms = 0;

  EKM.MS ++;
  _ms++;

  if(_ms >= 1000 )
  {
    EKM.Islem_Sn ++;
    _ms = 0;
  }
  if(EKM.Islem_Sn >= 60)
  {
    EKM.Islem_Sn = 0;
    EKM.Islem_Dk ++;
  }
  if(EKM.Buzer_Calma_ms)
  {
    EKM.Buzer_Calma_ms --;
    if(EKM.Buzer_Calma_ms == 0)
      Buzer_Kapa;
  }
}

void Buton_Sorgula(unsigned char Buton_No, bool Durumu)
{
  static unsigned char buzer_acik = 0;
  
  if (Durumu)
  {
    if (Buton[Buton_No].Olay == OLAY_YOK)
    {
      if (Buton[Buton_No].Basildi > 0)
        Buton[Buton_No].Sayac++;
      if (Buton[Buton_No].Sayac < BUTON_BASMA_SURESI_MS)
      {
        if (Buton[Buton_No].Basildi == 0)
        {
          Buton[Buton_No].Basildi = 1;
        }
      }
      else
      {
        
        Buton[Buton_No].Durum = 1;

        if(buzer_acik != Buton_No + 1)
        {
          if(EKM.Buzer_Calma_ms == 0)
          {
            Buzer_Ac;
            buzer_acik = Buton_No + 1;
            EKM.Buzer_Calma_ms = 15;
          }
        }
        if (Buton[Buton_No].Sayac > BUTON_UZUN_BASMA_SURESI_MS)
        {
          if (Buton[Buton_No].Basildi == 1)
          {
            Buton[Buton_No].Basildi = 2;
            Buton[Buton_No].Olay = UZUN_BASILDI_OLAYI;
          }
        }
      }
    }
  }
  else
  {
    if (buzer_acik == (Buton_No + 1))
    {
      buzer_acik = 0;
    }
    Buton[Buton_No].Durum = 0;
    if (Buton[Buton_No].Sayac > BUTON_BASMA_SURESI_MS)
    {

      if (Buton[Buton_No].Basildi == 1)
      {
        Buton[Buton_No].Basildi = 0;

        Buton[Buton_No].Olay = BASILDI_OLAYI;
      }
      // else if (Buton[Buton_No].Basildi == 2)
      // {
      //   Buton[Buton_No].Basildi = 0;

      //   Buton[Buton_No].Olay = OLAY_YOK;
      // }
    }
    else if ((Buton[Buton_No].Sayac > 0) && (Buton[Buton_No].Sayac < BUTON_BASMA_SURESI_MS))
    {
      if (Buton[Buton_No].Basildi == 0)
      {
        Buton[Buton_No].Olay = OLAY_YOK;
      }
    }
    Buton[Buton_No].Sayac = 0;

    if (Buton[Buton_No].Olay == OLAYI_TEMIZLE)
    {
      Buton[Buton_No].Olay = OLAY_YOK;
      Buton[Buton_No].Basildi = 0;
    }

    if (Buton[Buton_No].Olay != OLAY_YOK)
      Buton[Buton_No].Temizleme_ms++;

    if (Buton[Buton_No].Temizleme_ms > 1000)  ///5000
    {
      Buton[Buton_No].Basildi = 0;
      Buton[Buton_No].Olay = OLAY_YOK;
      Buton[Buton_No].Temizleme_ms = 0;
    }
  }
}

void Butonlari_Sorgula(void)
{
  static unsigned int _ms = 0;

  if(_ms == EKM.MS)
    return;
  
  _ms = EKM.MS;

  if (Giris_Basildi)
    Buton_Sorgula(Giris_Buton, true);
  else
    Buton_Sorgula(Giris_Buton, false);

  if (Geri_Basildi)
    Buton_Sorgula(Geri_Buton, true);
  else
    Buton_Sorgula(Geri_Buton, false);

  if (Yukari_Basildi)
    Buton_Sorgula(Yukari_Buton, true);
  else
    Buton_Sorgula(Yukari_Buton, false);

  if (Asagi_Basildi)
    Buton_Sorgula(Asagi_Buton, true);
  else
    Buton_Sorgula(Asagi_Buton, false);

  if (Saga_Basildi)
    Buton_Sorgula(Sag_Buton, true);
  else
    Buton_Sorgula(Sag_Buton, false);

  if (Sola_Basildi)
    Buton_Sorgula(Sol_Buton, true);
  else
    Buton_Sorgula(Sol_Buton, false);

}

void Tarih_Saat_Ayarla(unsigned char Saat, unsigned char Dakika, unsigned char Gun, unsigned char Ay, unsigned char Yil)
{
  unsigned char _Dk = 0, _Sa = 0, _Gn = 0, _Ay = 0, _Yil = 0;

  _Yil = Yil % 100;

  _Dk = ((Dakika / 10) << 4) + (Dakika % 10);
  _Sa = ((Saat / 10) << 4) + (Saat % 10);
  _Gn = ((Gun / 10) << 4) + (Gun % 10);
  _Ay = ((Ay / 10) << 4) + (Ay % 10);
  _Yil = ((_Yil / 10) << 4) + (_Yil % 10);


  Wire.beginTransmission(0x68);               // Start I2C protocol with DS1307 address
  Wire.write(0);                              // Send register address
  Wire.write(0);                              // Reset sesonds and start oscillator

  Wire.write(_Dk);                         // Write minute
  Wire.write(_Sa);                           // Write hour
  Wire.write(2);                            // Write day
  Wire.write(_Gn);                           // Write date
  Wire.write(_Ay);                          // Write month
  Wire.write(_Yil);                           // Write year
  Wire.endTransmission();                     // Stop transmission and release the I2C bus
  delay(200);
}

void Printer_Ayarla(char Ayar_1, char Ayar_2, char Ayar_3)
{
  if (Ayar_1 != 0)
    Serial.write(Ayar_1);

  Serial.write(Ayar_2);
  Serial.write(Ayar_3);
}

void Printer_Yazdir(const char* Yazilacak, char Cr, char Lf)
{
  // Serial.write(0x1D);
  // Serial.write(0x21);
  // Serial.write(0x01);

  // Serial.write(0x1B);
  // Serial.write(0x4A);
  // Serial.write(0x32);

  Serial.print(Yazilacak);
  if (Cr != 0 )
  {
    Serial.write(Cr);
  }
  if (Lf != 0)
  {
    Serial.write(Lf);
  }
}

void Eepromdan_Verileri_Al(void)
{
  char Eeprom_Kontrolu[5] = {0};

EEPROM.readString(EEPROM_VERI_KONTROL_YERI, (char*)Eeprom_Kontrolu, 2);

  if ((Eeprom_Kontrolu[0] != 'U') && (SATIS_YERI == TURKIYE))
  { 
      EEPROM.writeString(EEPROM_VERI_KONTROL_YERI, "U");
      EEPROM.writeString(GONDERICI_MAIL_KAYIT_YERI, "elciservis@gmail.com");
      EEPROM.writeString(GONDERICI_MAIL_SIFRE_KAYIT_YERI, "cingfyhreujogpgg");
      EEPROM.writeString(SON_ALICI_MAIL_KAYIT_YERI, "elciservis@gmail.com");//  ibrahimkaya1781@gmail.com
      EEPROM.writeString(CIHAZ_ADI_KAYIT_YERI, "EKMPLUS");
      EEPROM.writeUChar(YAZICI_DURUM_KAYIT_YERI, YOK);
      EEPROM.writeUChar(CIHAZ_DIL_YERI, 0);
  }

  if ((Eeprom_Kontrolu[0] != 'U') && (SATIS_YERI == SMARTCON))
  {  
      EEPROM.writeString(EEPROM_VERI_KONTROL_YERI, "U");
      EEPROM.writeString(GONDERICI_MAIL_KAYIT_YERI, "bresconeu@gmail.com");
      EEPROM.writeString(GONDERICI_MAIL_SIFRE_KAYIT_YERI, "tjqmshawktynubzq");
      EEPROM.writeString(SON_ALICI_MAIL_KAYIT_YERI, "bresconeu@gmail.com");
      EEPROM.writeString(CIHAZ_ADI_KAYIT_YERI, "SMARTCON");
      EEPROM.writeUChar(YAZICI_DURUM_KAYIT_YERI, VAR);
      EEPROM.writeUChar(CIHAZ_DIL_YERI, 1);  
  }

  if ((Eeprom_Kontrolu[0] != 'U') && (SATIS_YERI == STARKA))
  {  
      EEPROM.writeString(EEPROM_VERI_KONTROL_YERI, "U");
      EEPROM.writeString(GONDERICI_MAIL_KAYIT_YERI, "strmail204@gmail.com");
      EEPROM.writeString(GONDERICI_MAIL_SIFRE_KAYIT_YERI, "bpryjndkqyofvvss");
      EEPROM.writeString(SON_ALICI_MAIL_KAYIT_YERI, "strmail204@gmail.com"); 
      EEPROM.writeString(CIHAZ_ADI_KAYIT_YERI, "STR-PLUS"); 
      EEPROM.writeUChar(YAZICI_DURUM_KAYIT_YERI, YOK);
      EEPROM.writeUChar(CIHAZ_DIL_YERI, 5);
  }

  Eeprom_Kontrolu[0] = 0;

  EEPROM.readString(EEPROM_KONTROL_YERI, (char*)Eeprom_Kontrolu, 2);
  if (Eeprom_Kontrolu[0] != 'A')
  {
    EEPROM.writeString(EEPROM_KONTROL_YERI, "A");

    // EEPROM.writeString(CIHAZ_ADI_KAYIT_YERI, "EKMPLUS+");
    EEPROM.writeString(WIFI_AD_KAYIT_YERI, "Y1");
    EEPROM.writeString(WIFI_SIFRE_KAYIT_YERI, "!!!!!!!!");

    EEPROM.writeString(YAZ_VERSIYON_KAYIT_YERI, "00");
    EEPROM.writeString(YAZ_REVIZYON_KAYIT_YERI, "00");

    EEPROM.writeUShort(VAKUM_SURE_KAYIT_YERI, 20);
    EEPROM.writeUShort(KACAK_SURE_KAYIT_YERI, 5);
    EEPROM.writeUShort(DOLUM_MIKTAR_KAYIT_YERI, 10);
    EEPROM.writeUShort(TUP_DARA_KAYIT_YERI, 100);
    EEPROM.writeUShort(TUP_GAZ_MIKTAR_KAYIT_YERI, 420);

    EEPROM.writeUShort(GAZ_SENSOR_DARA_KAYIT_YERI, 100);

    EEPROM.writeUShort(VAKUM_REF_ATM_KAYIT_YERI, 1000);

    EEPROM.writeUShort(TERAZI_REF_GR_KAYIT_YERI, 2000);
    EEPROM.writeUShort(SON_SECILEN_MARKA_YERI,0);
    EEPROM.writeUShort(SON_CEKILEN_GAZ_YERI, 0);

    EEPROM.writeUChar(TANK_KAPASITE_KAYIT_YERI, 12);
    EEPROM.writeUChar(ISITICI_DURUM_KAYIT_YERI, 1);
    EEPROM.writeUChar(GAZ_SENSORU_DURUM_KAYIT_YERI, 1);
    // EEPROM.writeUChar(YAZICI_DURUM_KAYIT_YERI, VAR);
    // EEPROM.writeUChar(CIHAZ_DIL_YERI, 0);
    EEPROM.writeUChar(KONTRAST_KAYIT_YERI,100);
    EEPROM.writeUChar(GAZ_TIPI_KAYIT_YERI, 0);

    EEPROM.writeInt(TERAZI_DARA_KAYIT_YERI, 310528);
    EEPROM.writeInt(VAKUM_DARA_KAYIT_YERI, -338847);
    EEPROM.writeInt(BASINC_DARA_KAYIT_YERI, -326400);

    EEPROM.writeFloat(TERAZI_BOLEN_KAYIT_YERI, 36.76);
    EEPROM.writeFloat(VAKUM_BOLEN_KAYIT_YERI, 238.94);
    EEPROM.writeFloat(BASINC_BOLEN_KAYIT_YERI, 354.00);

    EEPROM.writeUInt(TOPLAM_VAKUM_SURE_KAYIT_YERI, 0);
    EEPROM.writeUInt(TOPLAM_GAZ_DOLUM_KAYIT_YERI, 0);
    EEPROM.writeUInt(SERI_NO_KAYIT_YERI, 1);
    EEPROM.writeUInt(FILTRE_KALAN_KAPASITE_KAYIT_YERI, 100000);
    
    EEPROM.writeUInt(KOMPRESOR_KAPANMA_KAYIT_YERI,800);
    EEPROM.writeUInt(FILTRE_KAPASITE_KAYIT_YERI,100);
    EEPROM.writeUInt(TOPLAM_TUPTEN_CEKILEN_KAYIT_YERI, 0);
    EEPROM.writeUInt(TOPLAM_ARACTAN_CEKILEN_KAYIT_YERI, 0);  

    EEPROM.commit();

  }

  EEPROM.readString(CIHAZ_ADI_KAYIT_YERI, (char*)EKM.Cihaz_Adi, 21);
  EEPROM.readString(WIFI_AD_KAYIT_YERI, (char*)EKM.Kayitli_Wifi, 50);
  EEPROM.readString(WIFI_SIFRE_KAYIT_YERI, (char*)EKM.Kayitli_Wifi_Sifresi, 25);
  EEPROM.readString(YAZ_VERSIYON_KAYIT_YERI, (char*)EKM.Yaz_Versiyon, 10);
  EEPROM.readString(YAZ_REVIZYON_KAYIT_YERI, (char*)EKM.Yaz_Revizyon, 10);
  EEPROM.readString(GONDERICI_MAIL_KAYIT_YERI, (char*)EKM.Gonderici_Maili, 35);
  EEPROM.readString(GONDERICI_MAIL_SIFRE_KAYIT_YERI, (char*)EKM.Gonderici_Sifresi, 25);
  EEPROM.readString(SON_ALICI_MAIL_KAYIT_YERI, (char*)EKM.Alici_Maili, 35);

  EKM.Tank_Kapasitesi = EEPROM.readUChar(TANK_KAPASITE_KAYIT_YERI);

  EKM.Vakum_Suresi_Dk = EEPROM.readUShort(VAKUM_SURE_KAYIT_YERI);
  EKM.Kacak_Suresi_Dk = EEPROM.readUShort(KACAK_SURE_KAYIT_YERI);
  EKM.Dolum_Miktari_Gr = EEPROM.readUShort(DOLUM_MIKTAR_KAYIT_YERI);
  EKM.Son_Secilen_Marka = EEPROM.readUShort(SON_SECILEN_MARKA_YERI);
  EKM.Son_Cekilen_Gr = EEPROM.readUShort(SON_CEKILEN_GAZ_YERI);
  EKM.Ref_Atm = EEPROM.readUShort(VAKUM_REF_ATM_KAYIT_YERI);
  EKM.Ref_Gr = EEPROM.readUShort(TERAZI_REF_GR_KAYIT_YERI);

   EKM.Ref_Atm = 1000;

  EKM.Acilma_Sayisi = EEPROM.readUChar(ACILMA_SAYISI_KAYIT_YERI);
  EKM.Isitici_Etkin = EEPROM.readUChar(ISITICI_DURUM_KAYIT_YERI);
  EKM.Yazici = EEPROM.readUChar(YAZICI_DURUM_KAYIT_YERI);
  EKM.Dil = EEPROM.readUChar(CIHAZ_DIL_YERI);
  EKM.Lcd_Kontrast_Degeri = EEPROM.readUChar(KONTRAST_KAYIT_YERI);
  EKM.Gaz_Tipi = EEPROM.readUChar(GAZ_TIPI_KAYIT_YERI);
  if(EKM.Gaz_Tipi > 1)
    EKM.Gaz_Tipi = 0;
  EKM.Terazi_Darasi = EEPROM.readInt(TERAZI_DARA_KAYIT_YERI);
  EKM.Vakum_Darasi = EEPROM.readInt(VAKUM_DARA_KAYIT_YERI);

  EKM.Toplam_Vakum_Dk = EEPROM.readUInt(TOPLAM_VAKUM_SURE_KAYIT_YERI);

  EKM.Toplam_Dolum_Gr = EEPROM.readUInt(TOPLAM_GAZ_DOLUM_KAYIT_YERI);
  EKM.Seri_No = EEPROM.readUInt(SERI_NO_KAYIT_YERI);
  EKM.Filtre_Kalan_Gr = EEPROM.readUInt(FILTRE_KALAN_KAPASITE_KAYIT_YERI);

  EKM.Kompresor_Kapanma = EEPROM.readUInt(KOMPRESOR_KAPANMA_KAYIT_YERI);
  EKM.Basinc_Darasi = EEPROM.readInt(BASINC_DARA_KAYIT_YERI);
  EKM.Filtre_Kapasitesi_Kg = EEPROM.readUInt(FILTRE_KAPASITE_KAYIT_YERI);

  EKM.Toplam_Tupten_Cekilen_Gr = EEPROM.readUInt(TOPLAM_TUPTEN_CEKILEN_KAYIT_YERI);
  EKM.Toplam_Aractan_Cekilen_Gr = EEPROM.readUInt(TOPLAM_ARACTAN_CEKILEN_KAYIT_YERI);

  EKM.Terazi_Boleni = EEPROM.readFloat(TERAZI_BOLEN_KAYIT_YERI);
  EKM.Vakum_Boleni = EEPROM.readFloat(VAKUM_BOLEN_KAYIT_YERI);
  EKM.Basinc_Boleni = EEPROM.readFloat(BASINC_BOLEN_KAYIT_YERI);

  
}

void Rtc_Kur(void)
{
   Wire.begin();              // Start our wire and real time clock
  // RTC.begin();
  // if (! RTC.isrunning()) {                       // Make sure RTC is running
  //   //    Serial.println("RTC is NOT running!");
  // }
}

void Ekrani_Kur(void)
{
  ledcSetup(0,5000,LCD_RESOLUTION);
  ledcAttachPin(LCD_KONTRAST_PINI,0);
  lcd.begin(20,4);
  ledcWrite(0,EKM.Lcd_Kontrast_Degeri);
  
}

void Lcd_Yaz(char Gelen)
{
  lcd.print(Gelen);
}

void Lcd_Set_Cursor(unsigned char Cizgi_Yeri,unsigned char Yazi_Satir_Yeri)
{
  lcd.setCursor(Cizgi_Yeri, Yazi_Satir_Yeri);
}

void Zaman_Al(struct rtc_zaman *Zaman)          //byte *second,byte *minute,byte *hour,byte *day,byte *date,byte *month,byte *year
{
  static unsigned int _ms = 0;
  static unsigned char Saniye = 0, Dakika = 0, Saat = 0, Gun = 0, Gun_Adi = 0, Ay = 0, Yil = 0;
  if ((EKM.MS - _ms) > 999)
  {
    _ms = EKM.MS;
    Wire.beginTransmission(0x68);                 // Start I2C protocol with DS1307 address
    Wire.write(0);                                // Send register address
    Wire.endTransmission(false);                  // I2C restart
    Wire.requestFrom(0x68, 7);                    // Request 7 bytes from DS1307 and release I2C bus at end of reading


    Saniye = Wire.read();                         // Read seconds from register 0
    Dakika = Wire.read();                         // Read minuts from register 1
    Saat = Wire.read();                         // Read hour from register 2
    Gun_Adi = Wire.read();                         // Read day from register 3
    Gun = Wire.read();                         // Read date from register 4
    Ay = Wire.read();                         // Read month from register 5
    Yil = Wire.read();                         // Read year from register 6
  }
  Zaman->Sn = (Saniye >> 4) * 10 + (Saniye & 0x0F);
  Zaman->Dk = (Dakika >> 4) * 10 + (Dakika & 0x0F);
  Zaman->Saat = (Saat >> 4)   * 10 + (Saat & 0x0F);
  Zaman->Gun_Adi = Gun_Adi >> 4 ;
  Zaman->Gun = (Gun >> 4)   * 10 + (Gun & 0x0F);
  Zaman->Ay  = (Ay >> 4)  * 10 + (Ay & 0x0F);
  Zaman->Yil   = (Yil >> 4)   * 10 + (Yil & 0x0F);
}

void Zamani_Goster(void)
{
  char Time[]     = "  :  :  ";
  char Calendar[] = "  /  /20  ";
  char Saniye = 0, Dakika = 0, Saat = 0, Gun = 0, Ay = 0, Yil = 0;
  static char E_Sn = 99;

  Zaman_Al(&Rtc_Zamani);  //&second,&minute,&hour,&day,&date,&month,&year

  // Convert BCD to decimal
  Saniye = Rtc_Zamani.Sn;
  Dakika = Rtc_Zamani.Dk;
  Saat   = Rtc_Zamani.Saat;
  Gun   = Rtc_Zamani.Gun;
  Ay  = Rtc_Zamani.Ay;
  Yil   = Rtc_Zamani.Yil;
  // End conversion
  if (E_Sn != Saniye)
  {
    E_Sn = Saniye;
    Time[7]     = Saniye % 10 + 48;
    Time[6]     = Saniye / 10 + 48;
    Time[4]     = Dakika % 10 + 48;
    Time[3]     = Dakika / 10 + 48;
    Time[1]     = Saat   % 10 + 48;
    Time[0]     = Saat   / 10 + 48;
    Calendar[9] = Yil   % 10 + 48;
    Calendar[8] = Yil   / 10 + 48;
    Calendar[4] = Ay  % 10 + 48;
    Calendar[3] = Ay  / 10 + 48;
    Calendar[1] = Gun   % 10 + 48;
    Calendar[0] = Gun   / 10 + 48;

    Yazi_Yaz(5,  SATIR_3, Calendar, 2); 
    // if (EKM.Sayfa == Tarih_Saat_Ayar_Sayfasi)
    // {
      Time[5] = 32; /// 32 = boşluk
      Time[6] = 32;
      Time[7] = 32;
      Yazi_Yaz(7, SATIR_4, Time, 2); 
       
    // }
    // else
    // {
    // Yazi_Yaz(7, SATIR_4, Time, 2);       
    // }
  }

}

void Bekle_us(void)
{
  unsigned char ix = 0;

  for (ix = 0; ix < 5; ix++);

}

void Bekle_ms(unsigned int _ms)
{
  unsigned int beklenen = 0;
  beklenen = EKM.MS;
  while ((EKM.MS - beklenen) < _ms)
  {
  }
}

void Lcd_Sure_Yaz(unsigned char x_Pos, unsigned char y_Pos, signed int Sayi, unsigned char Boyut, unsigned char Hane)
{
  char Gidecek_Sayi[15] = {0};
  char Gidecek[15] = {0};
  unsigned char yuzbinler = 0, onbinler = 0, binler = 0, yuzler = 0, onlar = 0, birler = 0;
  //static unsigned int _ms = 0;


  yuzbinler = Sayi / 100000;
  Sayi -= yuzbinler * 100000;

  onbinler = Sayi / 10000;
  Sayi -= onbinler * 10000;

  binler = Sayi / 1000;
  Sayi -= binler * 1000;

  yuzler = Sayi / 100;
  Sayi -= yuzler * 100;

  onlar = Sayi / 10;
  Sayi -= onlar * 10;

  birler = Sayi;

  if (Hane != 0)
  {
    if (Hane == 6)
    {
      Gidecek_Sayi[0] = yuzbinler + 48;
      Gidecek_Sayi[1] = onbinler + 48;
      Gidecek_Sayi[2] = binler + 48;
      Gidecek_Sayi[3] = yuzler + 48;
      Gidecek_Sayi[4] = onlar + 48;
      Gidecek_Sayi[5] = birler + 48;
      Gidecek_Sayi[6] = 0;
    }
    else if (Hane == 5)
    {
      //Gidecek_Sayi[1] = yuzbinler + 48;
      Gidecek_Sayi[0] = onbinler + 48;
      Gidecek_Sayi[1] = binler + 48;
      Gidecek_Sayi[2] = yuzler + 48;
      Gidecek_Sayi[3] = onlar + 48;
      Gidecek_Sayi[4] = birler + 48;
      Gidecek_Sayi[5] = 0;
    }
    else if (Hane == 4)
    {
      //Gidecek_Sayi[1] = yuzbinler + 48;
      // Gidecek_Sayi[2] = onbinler + 48;
      Gidecek_Sayi[0] = binler + 48;
      Gidecek_Sayi[1] = yuzler + 48;
      Gidecek_Sayi[2] = onlar + 48;
      Gidecek_Sayi[3] = birler + 48;
      Gidecek_Sayi[4] = 0;
    }
    else if (Hane == 3)
    {
      //  Gidecek_Sayi[1] = yuzbinler + 48;
      //  Gidecek_Sayi[2] = onbinler + 48;
      //  Gidecek_Sayi[3] = binler + 48;
      Gidecek_Sayi[0] = yuzler + 48;
      Gidecek_Sayi[1] = onlar + 48;
      Gidecek_Sayi[2] = birler + 48;
      Gidecek_Sayi[3] = 0;
    }
    else if (Hane == 2)
    {
      //  Gidecek_Sayi[1] = yuzbinler + 48;
      //  Gidecek_Sayi[2] = onbinler + 48;
      //  Gidecek_Sayi[3] = binler + 48;
      //  Gidecek_Sayi[4] = yuzler +48;
      Gidecek_Sayi[0] = onlar + 48;
      Gidecek_Sayi[1] = birler + 48;
      Gidecek_Sayi[2] = 0;
    }
    else
    {
      //  Gidecek_Sayi[1] = yuzbinler + 48;
      //  Gidecek_Sayi[2] = onbinler + 48;
      //  Gidecek_Sayi[3] = binler + 48;
      //  Gidecek_Sayi[4] = yuzler +48;
      //  Gidecek_Sayi[5] = onlar +48;
      Gidecek_Sayi[0] = birler + 48;
      Gidecek_Sayi[1] = 0;
    }

  }
  else
  {
    if (yuzbinler != 0)
    {
      Gidecek_Sayi[0] = yuzbinler + 48;
      Gidecek_Sayi[1] = onbinler + 48;
      Gidecek_Sayi[2] = binler + 48;
      Gidecek_Sayi[3] = yuzler + 48;
      Gidecek_Sayi[4] = onlar + 48;
      Gidecek_Sayi[5] = birler + 48;
      Gidecek_Sayi[6] = 0;
    }
    else if (onbinler != 0)
    {
      //Gidecek_Sayi[1] = yuzbinler + 48;
      Gidecek_Sayi[0] = onbinler + 48;
      Gidecek_Sayi[1] = binler + 48;
      Gidecek_Sayi[2] = yuzler + 48;
      Gidecek_Sayi[3] = onlar + 48;
      Gidecek_Sayi[4] = birler + 48;
      Gidecek_Sayi[5] = 0;
    }
    else if (binler != 0)
    {
      //Gidecek_Sayi[1] = yuzbinler + 48;
      // Gidecek_Sayi[2] = onbinler + 48;
      Gidecek_Sayi[0] = binler + 48;
      Gidecek_Sayi[1] = yuzler + 48;
      Gidecek_Sayi[2] = onlar + 48;
      Gidecek_Sayi[3] = birler + 48;
      Gidecek_Sayi[4] = 0;
    }
    else if (yuzler != 0)
    {
      //  Gidecek_Sayi[1] = yuzbinler + 48;
      //  Gidecek_Sayi[2] = onbinler + 48;
      //  Gidecek_Sayi[3] = binler + 48;
      Gidecek_Sayi[0] = yuzler + 48;
      Gidecek_Sayi[1] = onlar + 48;
      Gidecek_Sayi[2] = birler + 48;
      Gidecek_Sayi[3] = 0;
    }
    else if (onlar != 0)
    {
      //  Gidecek_Sayi[1] = yuzbinler + 48;
      //  Gidecek_Sayi[2] = onbinler + 48;
      //  Gidecek_Sayi[3] = binler + 48;
      //  Gidecek_Sayi[4] = yuzler +48;
      Gidecek_Sayi[0] = onlar + 48;
      Gidecek_Sayi[1] = birler + 48;
      Gidecek_Sayi[2] = 0;
    }
    else
    {
      //  Gidecek_Sayi[1] = yuzbinler + 48;
      //  Gidecek_Sayi[2] = onbinler + 48;
      //  Gidecek_Sayi[3] = binler + 48;
      //  Gidecek_Sayi[4] = yuzler +48;
      //  Gidecek_Sayi[5] = onlar +48;
      Gidecek_Sayi[0] = birler + 48;
      Gidecek_Sayi[1] = 0;
    }

  }
  //strcat(Gidecek_Sayi," ");
  strcat(Gidecek, Gidecek_Sayi);

  Yazi_Yaz(x_Pos, y_Pos, Gidecek, Boyut);
  //   
}

/**
 * @brief Boyut 99 olursa 3 basamaklı olarak yazar ve son hane ondalık olur. Ör: 023.5 gibi
 */
void Lcd_Sayi_Yaz(unsigned char x_Pos, unsigned char y_Pos, signed int Sayi, unsigned char Boyut, unsigned char Hane)
{
  char Gidecek_Sayi[15] = {0}, u = 0;
  char Gidecek[15] = {0};
  unsigned char yuzbinler = 0, onbinler = 0, binler = 0, yuzler = 0, onlar = 0, birler = 0;
  //static unsigned int _ms = 0;

  if (Sayi > 999999)
  {
    Sayi = 999999;
  }
  if (Sayi < -999999)
  {
    Sayi = -999999;
  }
  if (Sayi < 0)
  {
    Sayi = 0 - Sayi;
    u = 1;    
  }

  yuzbinler = Sayi / 100000;
  Sayi -= yuzbinler * 100000;

  onbinler = Sayi / 10000;
  Sayi -= onbinler * 10000;

  binler = Sayi / 1000;
  Sayi -= binler * 1000;

  yuzler = Sayi / 100;
  Sayi -= yuzler * 100;

  onlar = Sayi / 10;
  Sayi -= onlar * 10;

  birler = Sayi;

  if(Boyut == 99)
  {
    if (u == 1)
    {
      Gidecek_Sayi[0] = '-';
      Gidecek_Sayi[1] = onbinler + 48;
      Gidecek_Sayi[2] = binler + 48;
      Gidecek_Sayi[3] = '.';
      Gidecek_Sayi[4] = yuzler + 48;
      Gidecek_Sayi[5] = 0;  
    }
    else
    {
      Gidecek_Sayi[4] = 32;
      Gidecek_Sayi[0] = onbinler + 48;
      Gidecek_Sayi[1] = binler + 48;
      Gidecek_Sayi[2] = '.';
      Gidecek_Sayi[3] = yuzler + 48;
      Gidecek_Sayi[5] = 0;
    }  
  }
  else
  {
    if (Hane != 0)
    {
      if (u == 1)
      {
        Gidecek_Sayi[0] = '-';
        if (Hane == 6)
        {
          Gidecek_Sayi[1] = yuzbinler + 48;
          Gidecek_Sayi[2] = onbinler + 48;
          Gidecek_Sayi[3] = binler + 48;
          Gidecek_Sayi[4] = yuzler + 48;
          Gidecek_Sayi[5] = onlar + 48;
          Gidecek_Sayi[6] = birler + 48;
          Gidecek_Sayi[7] = 0;
        }
        else if (Hane == 5)
        {
          //Gidecek_Sayi[1] = yuzbinler + 48;
          Gidecek_Sayi[1] = onbinler + 48;
          Gidecek_Sayi[2] = binler + 48;
          Gidecek_Sayi[3] = yuzler + 48;
          Gidecek_Sayi[4] = onlar + 48;
          Gidecek_Sayi[5] = birler + 48;
          Gidecek_Sayi[6] = 0;
        }
        else if (Hane == 4)
        {
          //Gidecek_Sayi[1] = yuzbinler + 48;
          // Gidecek_Sayi[2] = onbinler + 48;
          Gidecek_Sayi[1] = binler + 48;
          Gidecek_Sayi[2] = yuzler + 48;
          Gidecek_Sayi[3] = onlar + 48;
          Gidecek_Sayi[4] = birler + 48;
          Gidecek_Sayi[5] = 0;
        }
        else if (Hane == 3)
        {
          //  Gidecek_Sayi[1] = yuzbinler + 48;
          //  Gidecek_Sayi[2] = onbinler + 48;
          //  Gidecek_Sayi[3] = binler + 48;
          Gidecek_Sayi[1] = yuzler + 48;
          Gidecek_Sayi[2] = onlar + 48;
          Gidecek_Sayi[3] = birler + 48;
          Gidecek_Sayi[4] = 0;
        }
        else if (Hane == 2)
        {
          //  Gidecek_Sayi[1] = yuzbinler + 48;
          //  Gidecek_Sayi[2] = onbinler + 48;
          //  Gidecek_Sayi[3] = binler + 48;
          //  Gidecek_Sayi[4] = yuzler +48;
          Gidecek_Sayi[1] = onlar + 48;
          Gidecek_Sayi[2] = birler + 48;
          Gidecek_Sayi[3] = 0;
        }
        else
        {
          //  Gidecek_Sayi[1] = yuzbinler + 48;
          //  Gidecek_Sayi[2] = onbinler + 48;
          //  Gidecek_Sayi[3] = binler + 48;
          //  Gidecek_Sayi[4] = yuzler +48;
          //  Gidecek_Sayi[5] = onlar +48;
          Gidecek_Sayi[1] = birler + 48;
          Gidecek_Sayi[2] = 0;
        }
      }
      else
      {
        if (Hane == 6)
        {
          Gidecek_Sayi[6] = 32;
          Gidecek_Sayi[0] = yuzbinler + 48;
          Gidecek_Sayi[1] = onbinler + 48;
          Gidecek_Sayi[2] = binler + 48;
          Gidecek_Sayi[3] = yuzler + 48;
          Gidecek_Sayi[4] = onlar + 48;
          Gidecek_Sayi[5] = birler + 48;
          Gidecek_Sayi[7] = 0;
        }
        else if (Hane == 5)
        {
          //Gidecek_Sayi[1] = yuzbinler + 48;
          Gidecek_Sayi[5] = 32;
          Gidecek_Sayi[0] = onbinler + 48;
          Gidecek_Sayi[1] = binler + 48;
          Gidecek_Sayi[2] = yuzler + 48;
          Gidecek_Sayi[3] = onlar + 48;
          Gidecek_Sayi[4] = birler + 48;
          Gidecek_Sayi[6] = 0;
        }
        else if (Hane == 4)
        {
          //Gidecek_Sayi[1] = yuzbinler + 48;
          // Gidecek_Sayi[2] = onbinler + 48;
          Gidecek_Sayi[4] = 32;
          Gidecek_Sayi[0] = binler + 48;
          Gidecek_Sayi[1] = yuzler + 48;
          Gidecek_Sayi[2] = onlar + 48;
          Gidecek_Sayi[3] = birler + 48;
          Gidecek_Sayi[5] = 0;
        }
        else if (Hane == 3)
        {
          //  Gidecek_Sayi[1] = yuzbinler + 48;
          //  Gidecek_Sayi[2] = onbinler + 48;
          //  Gidecek_Sayi[3] = binler + 48;
          Gidecek_Sayi[3] = 32;
          Gidecek_Sayi[0] = yuzler + 48;
          Gidecek_Sayi[1] = onlar + 48;
          Gidecek_Sayi[2] = birler + 48;
          Gidecek_Sayi[4] = 0;
        }
        else if (Hane == 2)
        {
          //  Gidecek_Sayi[1] = yuzbinler + 48;
          //  Gidecek_Sayi[2] = onbinler + 48;
          //  Gidecek_Sayi[3] = binler + 48;
          //  Gidecek_Sayi[4] = yuzler +48;
          Gidecek_Sayi[2] = 32;
          Gidecek_Sayi[0] = onlar + 48;
          Gidecek_Sayi[1] = birler + 48;
          Gidecek_Sayi[3] = 0;
        }
        else
        {
          //  Gidecek_Sayi[1] = yuzbinler + 48;
          //  Gidecek_Sayi[2] = onbinler + 48;
          //  Gidecek_Sayi[3] = binler + 48;
          //  Gidecek_Sayi[4] = yuzler +48;
          //  Gidecek_Sayi[5] = onlar +48;
          Gidecek_Sayi[1] = 32;
          Gidecek_Sayi[0] = birler + 48;
          Gidecek_Sayi[2] = 0;
        }
      }
    }
    else
    {
      if (u == 1)
      {
        Gidecek_Sayi[0] = '-';
        if (yuzbinler != 0)
        {
          Gidecek_Sayi[1] = yuzbinler + 48;
          Gidecek_Sayi[2] = onbinler + 48;
          Gidecek_Sayi[3] = binler + 48;
          Gidecek_Sayi[4] = yuzler + 48;
          Gidecek_Sayi[5] = onlar + 48;
          Gidecek_Sayi[6] = birler + 48;
          Gidecek_Sayi[7] = 0;
        }
        else if (onbinler != 0)
        {
          //Gidecek_Sayi[1] = yuzbinler + 48;
          Gidecek_Sayi[1] = onbinler + 48;
          Gidecek_Sayi[2] = binler + 48;
          Gidecek_Sayi[3] = yuzler + 48;
          Gidecek_Sayi[4] = onlar + 48;
          Gidecek_Sayi[5] = birler + 48;
          Gidecek_Sayi[6] = 0;
        }
        else if (binler != 0)
        {
          //Gidecek_Sayi[1] = yuzbinler + 48;
          // Gidecek_Sayi[2] = onbinler + 48;
          Gidecek_Sayi[1] = binler + 48;
          Gidecek_Sayi[2] = yuzler + 48;
          Gidecek_Sayi[3] = onlar + 48;
          Gidecek_Sayi[4] = birler + 48;
          Gidecek_Sayi[5] = 0;
        }
        else if (yuzler != 0)
        {
          //  Gidecek_Sayi[1] = yuzbinler + 48;
          //  Gidecek_Sayi[2] = onbinler + 48;
          //  Gidecek_Sayi[3] = binler + 48;
          Gidecek_Sayi[1] = yuzler + 48;
          Gidecek_Sayi[2] = onlar + 48;
          Gidecek_Sayi[3] = birler + 48;
          Gidecek_Sayi[4] = 0;
        }
        else if (onlar != 0)
        {
          //  Gidecek_Sayi[1] = yuzbinler + 48;
          //  Gidecek_Sayi[2] = onbinler + 48;
          //  Gidecek_Sayi[3] = binler + 48;
          //  Gidecek_Sayi[4] = yuzler +48;
          Gidecek_Sayi[1] = onlar + 48;
          Gidecek_Sayi[2] = birler + 48;
          Gidecek_Sayi[3] = 0;
        }
        else
        {
          //  Gidecek_Sayi[1] = yuzbinler + 48;
          //  Gidecek_Sayi[2] = onbinler + 48;
          //  Gidecek_Sayi[3] = binler + 48;
          //  Gidecek_Sayi[4] = yuzler +48;
          //  Gidecek_Sayi[5] = onlar +48;
          Gidecek_Sayi[1] = birler + 48;
          Gidecek_Sayi[2] = 0;
        }
      }
      else
      {
        if (yuzbinler != 0)
        {
          Gidecek_Sayi[0] = 32;
          Gidecek_Sayi[1] = yuzbinler + 48;
          Gidecek_Sayi[2] = onbinler + 48;
          Gidecek_Sayi[3] = binler + 48;
          Gidecek_Sayi[4] = yuzler + 48;
          Gidecek_Sayi[5] = onlar + 48;
          Gidecek_Sayi[6] = birler + 48;
          Gidecek_Sayi[7] = 0;
        }
        else if (onbinler != 0)
        {
          //Gidecek_Sayi[1] = yuzbinler + 48;
          Gidecek_Sayi[0] = 32;
          Gidecek_Sayi[1] = onbinler + 48;
          Gidecek_Sayi[2] = binler + 48;
          Gidecek_Sayi[3] = yuzler + 48;
          Gidecek_Sayi[4] = onlar + 48;
          Gidecek_Sayi[5] = birler + 48;
          Gidecek_Sayi[6] = 0;
        }
        else if (binler != 0)
        {
          //Gidecek_Sayi[1] = yuzbinler + 48;
          // Gidecek_Sayi[2] = onbinler + 48;
          Gidecek_Sayi[0] = 32;
          Gidecek_Sayi[1] = binler + 48;
          Gidecek_Sayi[2] = yuzler + 48;
          Gidecek_Sayi[3] = onlar + 48;
          Gidecek_Sayi[4] = birler + 48;
          Gidecek_Sayi[5] = 0;
        }
        else if (yuzler != 0)
        {
          //  Gidecek_Sayi[1] = yuzbinler + 48;
          //  Gidecek_Sayi[2] = onbinler + 48;
          //  Gidecek_Sayi[3] = binler + 48;
          Gidecek_Sayi[0] = 32;
          Gidecek_Sayi[1] = yuzler + 48;
          Gidecek_Sayi[2] = onlar + 48;
          Gidecek_Sayi[3] = birler + 48;
          Gidecek_Sayi[4] = 0;
        }
        else if (onlar != 0)
        {
          //  Gidecek_Sayi[1] = yuzbinler + 48;
          //  Gidecek_Sayi[2] = onbinler + 48;
          //  Gidecek_Sayi[3] = binler + 48;
          //  Gidecek_Sayi[4] = yuzler +48;
          Gidecek_Sayi[0] = 32;
          Gidecek_Sayi[1] = onlar + 48;
          Gidecek_Sayi[2] = birler + 48;
          Gidecek_Sayi[3] = 0;
        }
        else
        {
          //  Gidecek_Sayi[1] = yuzbinler + 48;
          //  Gidecek_Sayi[2] = onbinler + 48;
          //  Gidecek_Sayi[3] = binler + 48;
          //  Gidecek_Sayi[4] = yuzler +48;
          //  Gidecek_Sayi[5] = onlar +48;
          Gidecek_Sayi[0] = 32;
          Gidecek_Sayi[1] = birler + 48;
          Gidecek_Sayi[2] = 0;
        }
      }
    }
  }
  
  //strcat(Gidecek_Sayi," ");
  strcat(Gidecek, Gidecek_Sayi);

  lcd.setCursor(x_Pos, y_Pos);
  lcd.print(Gidecek);

 // Yazi_Yaz(x_Pos, y_Pos, Gidecek, Boyut);
  //   
}

signed int Bubble_Sort(signed int Siralanacak[Bubble_Sayisi + 1])
{
  unsigned char ix = 0, iz = 0;//iy = 0,
  signed int Sayi[Bubble_Sayisi + 1] = {0}, temp = 0;
  signed int Ortalama = 0;

  for (ix = 0; ix < Bubble_Sayisi + 1; ix++)
    Sayi[ix] = Siralanacak[ix];

  for ( ix = 0; ix < Bubble_Sayisi; ix++)
  {
    for ( iz = ix; iz < Bubble_Sayisi; iz++)
    {
      // Dizideki sayı çiftlerini kontrol et.
      if (Sayi[ix] > Sayi[iz])
      {
        // Yanlış sıralanmış sayı çiftlerinin yerini değiştir.
        temp = Sayi[ix];
        Sayi[ix] = Sayi[iz];
        Sayi[iz] = temp;
      }
    }
  }
  //Sayi[(Bubble_Sayisi/2)-2] + Sayi[(Bubble_Sayisi/2)+2]
  Ortalama =  Sayi[(Bubble_Sayisi / 2) - 1] + Sayi[Bubble_Sayisi / 2] + Sayi[(Bubble_Sayisi / 2) + 1] ;
  Ortalama = Ortalama / 3 ;
  return Ortalama;

}

unsigned char HX_710_Oku(unsigned char Secim, unsigned char clks, float *Okunan_Veri)
{
  //#define ORTALAMA_SAYISI   3
  //#define VAKUM_ORTALAMA_SAYISI   6
  static unsigned char VBr_Say = 0, BBr_Say = 0, Gr_Say = 0;//Ortalama_Say_Gr = 0, Ortalama_Say_Br = 0, 
  unsigned char ix  = 0;
  unsigned int v = 0;
  signed int Okunan = 0;
  static unsigned int t_ms = 0, v_ms = 0, b_ms = 0;
  static signed int  Orta_VBr[Bubble_Sayisi + 1] = {0}, Orta_BBr[Bubble_Sayisi + 1] = {0}, Orta_Gr[Bubble_Sayisi + 1] = {0};//Okunan_Gr = 0, Okunan_Br = 0, 
 // float Ortalama_Gr = 0, Ortalama_Br = 0;
  if (Secim == TERAZI)
  {
    if (!L_DIN)     /// düşende okuncak
    {
      if((EKM.MS - t_ms) < 20)
      {
        return 0;
      }
      t_ms = EKM.MS;  
      Bekle_us();
      for (ix = 0; ix < clks; ix++)
      {
        L_SCK_1;
        Bekle_us();

        L_SCK_0;
        Bekle_us();
        if (ix < 24)
        {
          v = v << 1;
          if (L_DIN)
            v |= 1u;
        }
      }
      Okunan = v;
      Okunan &= 0xFFFF00;
      if (Okunan & 0x800000u)
      {
        Okunan |= 0xff000000;
      }
      if (Gr_Say < Bubble_Sayisi)
      {
        Orta_Gr[Gr_Say] = Okunan;
        Gr_Say++;
        return 0;
      }
      Okunan = Bubble_Sort(Orta_Gr);    //Orta_Bul(Orta_Gr);
      Gr_Say = 0;
      //       Orta_Gr[0] = Okunan;
      //       Gr_Say = 1;

      //      Okunan_Gr += Okunan;
      //      Ortalama_Say_Gr++;
      //      if (Ortalama_Say_Gr > ORTALAMA_SAYISI)
      //      {
      //        Ortalama_Gr = (float)Okunan_Gr / (float)(ORTALAMA_SAYISI + 2);
      *Okunan_Veri = Okunan; //  Ortalama_Gr;
      //        Okunan_Gr = Ortalama_Gr;
      //        Ortalama_Say_Gr = 0;
      return 1;
      //            }
    }
    return 0;
  }
  else if(Secim == VAKUM) 
  {
    if (!V_DIN)     /// düşende okuncak
    {
      if((EKM.MS - v_ms) < 20)
      {
        return 0;
      }
      v_ms = EKM.MS;
      Bekle_us();
      for (ix = 0; ix < clks; ix++)
      {
        V_SCK_1;
        Bekle_us();

        V_SCK_0;
        Bekle_us();
        if (ix < 24)
        {
          v = v << 1;
          if (V_DIN)
            v |= 1u;
        }
      }
      Okunan = v;
      Okunan &= 0xFFFF00;
      if (Okunan & 0x800000u)
      {
        Okunan |= 0xff000000;
      }

      if (VBr_Say < Bubble_Sayisi)
      {
        Orta_VBr[VBr_Say] = Okunan;
        VBr_Say++;
        return 0;
      }
      Okunan = Bubble_Sort(Orta_VBr);
      VBr_Say = 0;
      //      Orta_Br[0] = Okunan;
      //      Br_Say = 1;
      //      Ortalama_Br += Okunan;
      //      Ortalama_Say_Br++;
      //      if (Ortalama_Say_Br >  VAKUM_ORTALAMA_SAYISI)
      //      {
      //        Ortalama_Br = Ortalama_Br / (VAKUM_ORTALAMA_SAYISI + 2);
      *Okunan_Veri = Okunan;  // Ortalama_Br;
      //        Ortalama_Say_Br = 0;
      return 1;
      //  }
    }
    return 0;
  }
  else if(Secim == BASINC) 
  {
    if (!B_DIN)     /// düşende okuncak
    {
      if((EKM.MS - b_ms) < 20)
      {
        return 0;
      }
      b_ms = EKM.MS;
      Bekle_us();
      for (ix = 0; ix < clks; ix++)
      {
        B_SCK_1;
        Bekle_us();

        B_SCK_0;
        Bekle_us();
        if (ix < 24)
        {
          v = v << 1;
          if (B_DIN)
            v |= 1u;
        }
      }
      Okunan = v;
      Okunan &= 0xFFFF00;
      if (Okunan & 0x800000u)
      {
        Okunan |= 0xff000000;
      }

      if (BBr_Say < Bubble_Sayisi)
      {
        Orta_BBr[BBr_Say] = Okunan;
        BBr_Say++;
        return 0;
      }
      Okunan = Bubble_Sort(Orta_BBr);
      BBr_Say = 0;
      //      Orta_Br[0] = Okunan;
      //      Br_Say = 1;
      //      Ortalama_Br += Okunan;
      //      Ortalama_Say_Br++;
      //      if (Ortalama_Say_Br >  VAKUM_ORTALAMA_SAYISI)
      //      {
      //        Ortalama_Br = Ortalama_Br / (VAKUM_ORTALAMA_SAYISI + 2);
      *Okunan_Veri = Okunan;  // Ortalama_Br;
      //        Ortalama_Say_Br = 0;
      return 1;
      //  }
    }
    return 0;
  }
  return 0;
}

#define Bag_Sayisi    10
unsigned char Terazi_Oku(float *okunan)
{
  static float Okunan_Gr = 0;
  static unsigned short Ortalama_Say = 0;
  static float Ortalama_Deg = 0;
  static signed int Okunanlar[Bag_Sayisi+2] = {0};
  unsigned char ix = 0;
  signed int Gidecek_Gr = 0;
  if (HX_710_Oku(TERAZI, 27, &Okunan_Gr))
  {
    Okunan_Gr = Okunan_Gr - EKM.Terazi_Darasi;
    Okunan_Gr = Okunan_Gr / (float)EKM.Terazi_Boleni;
    if(Ortalama_Say < Bag_Sayisi)
    {
      Okunanlar[Ortalama_Say] = Okunan_Gr;
      Ortalama_Say ++;      
      Ortalama_Deg += Okunan_Gr;
      Okunan_Gr = Ortalama_Deg / Ortalama_Say;
      Gidecek_Gr = Okunan_Gr/5;
      Gidecek_Gr = Gidecek_Gr * 5;
      *okunan = Gidecek_Gr;  // - EKM.Bos_Tup_Gr;   ///// Önemli!! Sorulacak
      return 1;
    }
    else
    {
      Ortalama_Deg = 0;
      Okunanlar[Ortalama_Say] = Okunan_Gr;        //// 10 = okunan
      for(ix = 0; ix < Bag_Sayisi+1 ; ix ++)
        Ortalama_Deg += Okunanlar[ix];
      
      Okunan_Gr = Ortalama_Deg / (Ortalama_Say+1);
      Gidecek_Gr = Okunan_Gr/5;
      Gidecek_Gr = Gidecek_Gr * 5;
      *okunan = Gidecek_Gr;
    //  *okunan = Okunan_Gr;  // - EKM.Bos_Tup_Gr;   ///// Önemli!! Sorulacak
      for(ix = 0; ix < Bag_Sayisi; ix++)
      {
        Okunanlar[ix] = Okunanlar[ix + 1];
      }
      return 1;
    }
  }
  //    Ortalama_Say++;
  //    Ortalama_Deg += Okunan_Gr;
  //    if (Ortalama_Say >= 10)
  //    {
  //      Ortalama_Deg = Ortalama_Deg / (float)(Ortalama_Say + 1);
  //      Ortalama_Say = 0;
  //      *okunan = Ortalama_Deg;
  //      return 1;
  //    }

  return 0;

}

unsigned char Vakum_Oku(float *okunan)
{
  static float Okunan_Br = 0;
  static unsigned short Ortalama_Say = 0;
  float Ortalama_Deg = 0;
  static signed int Okunanlar[Bag_Sayisi+2] = {0};
  unsigned char ix = 0;

  if (HX_710_Oku(VAKUM, 27, &Okunan_Br))
  {
    Okunan_Br = Okunan_Br - EKM.Vakum_Darasi;
    Okunan_Br = Okunan_Br / (float)EKM.Vakum_Boleni;
    if(Ortalama_Say < Bag_Sayisi)
    {
      Okunanlar[Ortalama_Say] = Okunan_Br;
      Ortalama_Say ++;      
      Ortalama_Deg += Okunan_Br;
      Okunan_Br = Ortalama_Deg / Ortalama_Say;
      *okunan = Okunan_Br;
      return 1;
    }
    else
    {
      Ortalama_Deg = 0;
      Okunanlar[Ortalama_Say] = Okunan_Br;        //// 10 = okunan
      for(ix = 0; ix < Bag_Sayisi+1 ; ix ++)
        Ortalama_Deg += Okunanlar[ix];
      
      Okunan_Br = Ortalama_Deg / (Ortalama_Say+1);
      *okunan = Okunan_Br;  
      for(ix = 0; ix < Bag_Sayisi; ix++)
      {
        Okunanlar[ix] = Okunanlar[ix + 1];
      }
      return 1;
    }
  }
  //  Ortalama_Say++;
  //  Ortalama_Deg += Okunan_Br;
  //  if (Ortalama_Say >= 400)
  //  {
  //    Ortalama_Deg = Ortalama_Deg / (Ortalama_Say + 1);
  //    Ortalama_Say = 0;
  //    *okunan = Ortalama_Deg;
  //    return 1;
  //  }
  return 0;

}

unsigned char Basinc_Oku(float *okunan)
{
  static float Okunan_Br = 0;
  static unsigned short Ortalama_Say = 0;
  static float Ortalama_Deg = 0;
  static signed int Okunanlar[Bag_Sayisi+2] = {0};
  unsigned char ix = 0;

  if (HX_710_Oku(BASINC, 27, &Okunan_Br))
  {
    Okunan_Br = Okunan_Br - EKM.Basinc_Darasi;
    Okunan_Br = Okunan_Br / (float)EKM.Basinc_Boleni;
    if(Ortalama_Say < Bag_Sayisi)
    {
      Okunanlar[Ortalama_Say] = Okunan_Br;
      Ortalama_Say ++;      
      Ortalama_Deg += Okunan_Br;
      Okunan_Br = Ortalama_Deg / Ortalama_Say;
      *okunan = Okunan_Br;
      return 1;
    }
    else
    {
      Ortalama_Deg = 0;
      Okunanlar[Ortalama_Say] = Okunan_Br;        //// 10 = okunan
      for(ix = 0; ix < Bag_Sayisi+1 ; ix ++)
        Ortalama_Deg += Okunanlar[ix];
      
      Okunan_Br = Ortalama_Deg / (Ortalama_Say+1);
      *okunan = Okunan_Br;  // - EKM.Bos_Tup_Gr;   ///// Önemli!! Sorulacak
      for(ix = 0; ix < Bag_Sayisi; ix++)
      {
        Okunanlar[ix] = Okunanlar[ix + 1];
      }
      return 1;
    }
  }
  return 0;

}

void Veri_Kaydet_Float(int Yeri, float veri)
{
  EEPROM.writeFloat(Yeri, veri);
  EEPROM.commit();
}

void Veri_Kaydet_Uchar(int Yeri, unsigned char veri)
{
  EEPROM.writeUChar(Yeri, veri);
  EEPROM.commit();
}

void Veri_Kaydet_Ushort(int Yeri, unsigned short veri)
{
  EEPROM.writeUShort(Yeri, veri);
  EEPROM.commit();
}

void Veri_Kaydet_UInt(int Yeri, unsigned int veri)
{
  EEPROM.writeUInt(Yeri, veri);
  EEPROM.commit();
}

void Veri_Kaydet_Int(int Yeri, signed int veri)
{
  EEPROM.writeInt(Yeri, veri);
  EEPROM.commit();
}

void Veri_Kaydet_Short(int Yeri, signed short veri)
{
  EEPROM.writeShort(Yeri, veri);
  EEPROM.commit();
}

void Veri_Kaydet_String(int Yeri, char* veri)
{
  EEPROM.writeString(Yeri, veri);
  EEPROM.commit();

}

void Vakum_Darasini_Eepromdan_Oku(void)
{
  EKM.Vakum_Darasi = EEPROM.readInt(VAKUM_DARA_KAYIT_YERI);
}

void Ayarlar_Giris(void)
{
  static unsigned char Ayar_Giris_Adimi = 0;
  static unsigned int Sifre = 0;
  unsigned char Islem_Durumu = 0;
  if(Ayar_Giris_Adimi == 0)
  {
    lcd.clear();
    EKM.Sayfa = Ayar_Giris_Sayfasi;
    Ayar_Giris_Adimi = 1;
    Sifre = 0;
    Kayittan_Yazi_Yaz( 3,SATIR_1,Sifreyi_Girin_Yeri);
    Buyuk_Sayi_Gir(7,SATIR_3,&Sifre,5);    
  }
  else if (Ayar_Giris_Adimi == 1)
  {
    Islem_Durumu = Buyuk_Sayi_Gir(7,SATIR_3,&Sifre,5);
    if(Islem_Durumu == TAMAMLANDI)
    {
      if(Sifre_Kontrol(Sifre))
      {
        Ayar_Giris_Adimi = 0;
        Ayar_Secim_Sayfa(1);        
      }
      else
      {
        lcd.clear();
        Kayittan_Yazi_Yaz(0,SATIR_1,Sifre_Yanlis_Yeri);
        Bekle_ms(2000);
        Ayar_Giris_Adimi = 0;
      }
    }
    if(Islem_Durumu == IPTAL_ET)
    {
      Ayar_Giris_Adimi = 0;
      Giris_Sayfa(2,3);
    }
  }
}

void Giris_Cikislari_Ayarla(void)
{
  pinMode(BUZER_PINI, OUTPUT);     //alarm for gas sensor when there is leakage--detector MQ2
  //pinMode(GAZ_SENSOR_PINI, INPUT);    //gas sensor--detector MQ2

  pinMode(GERI_BUTON_PINI, INPUT);
  pinMode(YUKARI_BUTON_PINI, INPUT);
  pinMode(ASAGI_BUTON_PINI, INPUT);
  pinMode(GIRIS_BUTON_PINI, INPUT);
  pinMode(SAG_BUTON_PINI, INPUT);
  pinMode(SOL_BUTON_PINI, INPUT);

  pinMode(LOADCELL_SCK_PIN, OUTPUT);
  pinMode(LOADCELL_DOUT_PIN, INPUT);
  //digitalWrite(LOADCELL_DOUT_PIN, HIGH);

  pinMode(VAKUMSENSOR_SCK_PIN, OUTPUT);
  pinMode(VAKUMSENSOR_DOUT_PIN, INPUT);
  digitalWrite(VAKUMSENSOR_DOUT_PIN, HIGH);

  pinMode(BASINCSENSOR_SCK_PIN, OUTPUT);
  pinMode(BASINCSENSOR_DOUT_PIN, INPUT);
  digitalWrite(BASINCSENSOR_DOUT_PIN, HIGH);

}




void Imlec_Yaz(unsigned char Yer)
{
  static unsigned E_Satir = 0;

       if(Yer == 1)
  {    if(E_Satir != SATIR_1){lcd.setCursor(0, E_Satir); lcd.print(" ");E_Satir = SATIR_1;}
       lcd.setCursor(0, SATIR_1); }
    
  else if(Yer == 2)     
  {    if(E_Satir != SATIR_2){lcd.setCursor(0, E_Satir); lcd.print(" ");E_Satir = SATIR_2;}
       lcd.setCursor(0, SATIR_2); }
    
  else if(Yer == 3)   
  {    if(E_Satir != SATIR_3){lcd.setCursor(0, E_Satir); lcd.print(" ");E_Satir = SATIR_3;}
       lcd.setCursor(0, SATIR_3); }    

  else if(Yer == 4)
  {    if(E_Satir != SATIR_4){lcd.setCursor(0, E_Satir); lcd.print(" ");
       if(EKM.Sayfa == Dil_Secim_Sayfasi){lcd.setCursor(10, E_Satir);lcd.print(" ");}E_Satir = SATIR_4; }
       lcd.setCursor(0, SATIR_4); }

  else if(Yer == 5)
  {    if(E_Satir != SATIR_5){lcd.setCursor(0, E_Satir); lcd.print(" ");
       if(EKM.Sayfa == Dil_Secim_Sayfasi){lcd.setCursor(10, E_Satir);lcd.print(" ");}E_Satir = SATIR_1; }
       lcd.setCursor(10, SATIR_1); }

  else if(Yer == 6)
  {    if(E_Satir != SATIR_6){lcd.setCursor(0, E_Satir); lcd.print(" ");
       if(EKM.Sayfa == Dil_Secim_Sayfasi){lcd.setCursor(10, E_Satir);lcd.print(" ");}E_Satir = SATIR_2; }
       lcd.setCursor(10, SATIR_2); } 

  else if(Yer == 7)
  {    if(E_Satir != SATIR_7){lcd.setCursor(0, E_Satir); lcd.print(" ");
       if(EKM.Sayfa == Dil_Secim_Sayfasi){lcd.setCursor(10, E_Satir);lcd.print(" ");}E_Satir = SATIR_3; }
       lcd.setCursor(10, SATIR_3); } 

  else if(Yer == 8)
  {    if(E_Satir != SATIR_8){lcd.setCursor(0, E_Satir); lcd.print(" ");
       if(EKM.Sayfa == Dil_Secim_Sayfasi){lcd.setCursor(10, E_Satir);lcd.print(" ");}E_Satir = SATIR_4; }
       lcd.setCursor(10, SATIR_4); } 
  
  lcd.print(">");
}

void Kayittan_Yazi_Yaz(unsigned char x_pos, unsigned char y_pos, unsigned int Text_yeri)
{
  unsigned int Yer = 0;

  lcd.setCursor(x_pos, y_pos);
  Yer = Text_yeri * DIL_SAYISI;
  Yer += EKM.Dil;         //// turkce = 0, Ingilizce = 1
  lcd.print(Dil_Listesi[Yer]);

}

void Yazi_Yaz(unsigned char x_pos, unsigned char y_pos, const char* text, byte text_size)
{
  char Yazilacak[50] = {0}, Gelen[50] = {0};
  unsigned char u = 0, ix = 0;

  lcd.setCursor(x_pos, y_pos);
  strcpy(Gelen, (const char *)text);
  Gelen[40] = 0;
  u = strlen(Gelen);
  if (text_size == 99)
  {
    if (u > 20)
    {
      if((x_pos == 0) && (y_pos <= SATIR_3))
      {
        for(ix = 0; ix < 20; ix ++)
          Yazilacak[ix] = Gelen[ix];
        lcd.print(Yazilacak);
        for(ix = 0; ix < 20; ix++)
          Yazilacak[ix] = Gelen[ix+20];
        lcd.setCursor(x_pos, y_pos+1);
        lcd.print(Yazilacak);
        return;
     }
    }
  }
  else if (text_size == 19)
  {
    if (u > 18)
    {
      Gelen[18] = 0;
    }
  }
  strcat(Yazilacak, Gelen);
  lcd.print(Yazilacak);
}

void Cizgi_Cek(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char renk)
{
  if (renk)
  {
  //   lcd.noCursor();
  //   // lcd.noBlink();
     lcd.setCursor(x1,y1);
  // //  lcd.blink();
     lcd.cursor();
  //  lcd.print("_");
  }
  else
  {
    lcd.setCursor(x1,y1);
    
     lcd.noCursor();
  }
  
}

void Blink_Yap(unsigned char x1, unsigned char y1,unsigned char Durum)
{
  if (Durum)
  {
   // lcd.noCursor();
    lcd.noBlink();
    lcd.setCursor(x1,y1);
    lcd.blink();
   // lcd.cursor();
  }
  else
  {
    lcd.noBlink();
    lcd.setCursor(x1,y1);
   // lcd.noCursor();
    
  }
}

void Ayar_Secim_Sayfa(unsigned char Imlec_Yeri)
{
  EKM.Sayfa = Ayar_Secim_Sayfasi;
  lcd.clear();
  Butonlari_Temizle();
  Kayittan_Yazi_Yaz(1,SATIR_1,Cihaz_Ayarlari_Yeri);
  Kayittan_Yazi_Yaz(1,SATIR_2,Kalibrasyonlar_Yeri);
  Kayittan_Yazi_Yaz(1,SATIR_3,Bakimlar_Yeri);
  Kayittan_Yazi_Yaz(1,SATIR_4,Kompresor_Kapatma_Yeri);
  EKM.Imlec = Imlec_Yeri;
  Imlec_Yaz(EKM.Imlec);
  EKM.Sayfa = Ayar_Secim_Sayfasi;        
  Ayar_Secimi();
  
}

void Cihaz_Ayarlar_Sayfa(unsigned char Imlec_Yeri)
{
  EKM.Sayfa = Cihaz_Ayarlari_Sayfasi;

  Butonlari_Temizle();
  lcd.clear();
  EKM.Imlec = Imlec_Yeri;
  Imlec_Yaz(EKM.Imlec);

  Kayittan_Yazi_Yaz(1,SATIR_1,Dil_Language_Yeri);
  Kayittan_Yazi_Yaz(1,SATIR_2,Sistem_Vakumlama_Yeri);
  Kayittan_Yazi_Yaz(1,SATIR_3,Sistem_Bosaltma_Yeri);  
  Kayittan_Yazi_Yaz(1,SATIR_4,Diger_Ayarlar_Yeri);
}

unsigned char Kacak_Bekle(void)
{
  static unsigned char Kacak_Bekleme_Asamasi = 0, Islem_Durumu = 0, Buzer_Sayac = 0;
  //static float ;
  static signed int Vakum_Deg = 0, Ilk_Vakum_Deg = 0;
  static unsigned int _ms = 0, Islem_Baslama_Dk = 0;
  static unsigned short Kacak_Sayac = 0;

  if (Kacak_Bekleme_Asamasi == 0)
  {
  //  SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,KAPAT);
    Kacak_Sayac = 0;
    if(EKM.Kacak_Suresi_Dk == 0)
      return TAMAMLANDI;

    SSR_Kontrol(Alcak_Basinc_Valf_Ssr,AC);
    SSR_Kontrol(Yuksek_Basinc_Valf_Ssr,AC);

    lcd.clear();
    Kayittan_Yazi_Yaz(0,SATIR_1,Lutfen_Bekleyin_Yeri);
    Kayittan_Yazi_Yaz(3,SATIR_2,Kacak_Kontrol_Yeri);
    Kayittan_Yazi_Yaz(15,SATIR_3,Atla_Yeri);
    Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
    Kacak_Bekleme_Asamasi = 1;
    _ms = EKM.MS;
  }
  else if (Kacak_Bekleme_Asamasi == 1)
  {
    if((EKM.MS - _ms) > 2000)
    {
      Ilk_Vakum_Deg = EKM.Vakum_Br + KACAK_TOLERANSI;
      Kacak_Bekleme_Asamasi = 2;
      Islem_Baslama_Dk = EKM.Islem_Dk; 
      Kalan_Sure_Goster(0,0,0,0);    //// sıfırlamak gerekiyor.
    }
    else if((EKM.MS - _ms) > 1000)
    {
      Vakum_Oku(&EKM.Vakum_Br);
    }
  }
  else if (Kacak_Bekleme_Asamasi == 2)
  {
    Islem_Durumu = Kalan_Sure_Goster(6,SATIR_4,EKM.Kacak_Suresi_Dk,0); 

    Vakum_Oku(&EKM.Vakum_Br);

    Isitici_Kontrol(ACIK);

    if(Islem_Durumu == DEVAM_EDIYOR)
    {
      Vakum_Deg = (EKM.Vakum_Br-50) - Ilk_Vakum_Deg;   //// ilk değeri tolerans eklendi
      if(Vakum_Deg < 0)
      {
        Vakum_Deg = 0;
        Kacak_Sayac = 0;
      }
      else if (Vakum_Deg > KACAK_SINIRI)
      {
        Kacak_Sayac ++;
        if(Kacak_Sayac > 1000)
        {
          Kacak_Bekleme_Asamasi = 4;
          Yazilacaklar.Kacak_Dk = EKM.Islem_Dk - Islem_Baslama_Dk;

          Kacak_Sayac = 0;
          Isitici_Kontrol(KAPALI);
          SSR_Kontrol(IPTAL_ET,KAPAT);
          lcd.clear();
          Kayittan_Yazi_Yaz(4,SATIR_1,Kacak_Var_Yeri);
          Kayittan_Yazi_Yaz(1,SATIR_2,Islem_Yapilamadi_Yeri);
          Buzer_Ac;
          EKM.Buzer_Calma_ms = 500;
          _ms = EKM.MS;
          return DEVAM_EDIYOR;
        }
      }

      if((EKM.MS - _ms) > 200)
      {
        _ms = EKM.MS;
        if(Buton[Yukari_Buton].Durum == 1)
        {
          Lcd_Sayi_Yaz(8,SATIR_3,EKM.Vakum_Br,1,3);//ikaya 160922
        }
        else
        {
          Yazi_Yaz(8,SATIR_3,"%",1);
          Lcd_Sayi_Yaz(9,SATIR_3,(Vakum_Deg/10),1,3);
        }
        
      }
      if(Buton[Giris_Buton].Olay == BASILDI_OLAYI)
      {
        Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
        if(Vakum_Deg < KACAK_SINIRI)
          Kacak_Bekleme_Asamasi = 3;
      }


    }
    else if (Islem_Durumu == TAMAMLANDI)
    {
      Kacak_Bekleme_Asamasi = 3;
    }
  }
  else if (Kacak_Bekleme_Asamasi == 3)
  {
    Vakum_Deg = (EKM.Vakum_Br-50) - Ilk_Vakum_Deg;

    Yazilacaklar.Kacak_Dk = (EKM.Islem_Dk - Islem_Baslama_Dk);
    Kacak_Sayac = 0;
    Isitici_Kontrol(KAPALI);
    SSR_Kontrol(IPTAL_ET,KAPAT);

    Kacak_Bekleme_Asamasi = 0;

    return TAMAMLANDI;
    
  }
  else if (Kacak_Bekleme_Asamasi == 4)
  {
    if((EKM.MS - _ms) > 1000)
    {
      _ms = EKM.MS;
      Buzer_Ac;
      EKM.Buzer_Calma_ms = 500;
      Buzer_Sayac ++;
    }
    if(Buzer_Sayac >=2)
    {
      Buzer_Sayac = 0;
      Kacak_Bekleme_Asamasi = 0;

      return KACAK_VAR;
    }
  }
  return DEVAM_EDIYOR;
}

void Tarih_Saat_Ayar_Sayfa(void)
{
  //unsigned char Saniye = 0, Dakika = 0, Saat = 0, Gun = 0, Ay = 0, Yil = 0;
  //char Gidecek[12] = {0};

  Zaman_Al(&Rtc_Zamani);  //&second,&minute,&hour,&day,&date,&month,&year

  // Convert BCD to decimal
  // Saniye = Rtc_Zamani.Sn;
  // Dakika = Rtc_Zamani.Dk;
  // Saat   = Rtc_Zamani.Saat;
  // Gun   = Rtc_Zamani.Gun;
  // Ay  = Rtc_Zamani.Ay;
  // Yil   = Rtc_Zamani.Yil;

  EKM.Sayfa = Tarih_Saat_Ayar_Sayfasi;
  Tarih_Saat_Ayari(99);       /// sıfırlama için 99 yapıldı
  Butonlari_Temizle();
  lcd.clear();
  Zamani_Goster();
  Kayittan_Yazi_Yaz(0, SATIR_2, Tarih_Saat_Yeri);
  Kayittan_Yazi_Yaz(0, SATIR_1, Gun_Ay_Yil_Yeri);
  Cizgi_Cek(6,SATIR_3,0,0,1);
}

void Tarih_Saat_Ayari(unsigned char Durum)
{
  static unsigned char Cizgi_Yeri = 0, Satir_No = 0, Sutun_No = 0, Satir_Yeri = 0, Sutun_Atlagi = 0;
  static signed char Saat = 0, Dakika = 0, Gun = 0, Ay = 0, Yil = 0;

  if (Durum == 99)
  {
    Cizgi_Yeri = 6;
    Satir_No = 1;
    Sutun_No = 1;
    Satir_Yeri = SATIR_3;
    Sutun_Atlagi = 3;

    Dakika = Rtc_Zamani.Dk;
    Saat   = Rtc_Zamani.Saat;
    Gun    = Rtc_Zamani.Gun;
    Ay     = Rtc_Zamani.Ay;
    Yil    = Rtc_Zamani.Yil;
  }
  if(Buton[Sol_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Sol_Buton].Olay = OLAYI_TEMIZLE;
    if(Satir_No == 1)
    {
      if(Sutun_No == 3)
      {
        Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, 0, 0);
        Cizgi_Yeri -= 5;
        Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, Satir_Yeri, 1);
        Sutun_No --;
      }
      else if (Sutun_No > 1)
      {
        Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, 0, 0);
        Cizgi_Yeri -= 3;
        Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, Satir_Yeri, 1);
        Sutun_No --; 
      }
    }
    else
    {
      if(Sutun_No == 1)
      {
        Cizgi_Cek(Cizgi_Yeri, Satir_Yeri,0, 0, 0);
        Satir_No = 1;
        Sutun_No = 3;
        Cizgi_Yeri = 14;
        Satir_Yeri = SATIR_3;
        Cizgi_Cek(Cizgi_Yeri, Satir_Yeri,0, 0, 1);
      }
      else
      {
        Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, 0, 0);
        Cizgi_Yeri -= 3;
        Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, Satir_Yeri, 1);
        Sutun_No --; 
      }
       
    }
  }
  if(Buton[Sag_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Sag_Buton].Olay = OLAYI_TEMIZLE;
    if(Satir_No == 1)
    {      
      if (Sutun_No < 3)
      {
        Sutun_No ++;
        if (Sutun_No < 3)
        {
          Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, 0, 0);
          Cizgi_Yeri += Sutun_Atlagi;
          Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, 0, 1);
        }
        else  // satir 1 sutun 3  if (Satir_No == 1)
        {
          Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, 0, 0);
          Cizgi_Yeri += 5;
          Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, 0, 1);
        }
      }
      else
      {
        Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, 0, 0);
        Sutun_No = 1;
        Satir_No = 2;
        Satir_Yeri = SATIR_4;
        Cizgi_Yeri = 8;
        Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, 0, 1);
      }
    }
    else
    {
      if (Sutun_No == 1)
      {
        Sutun_No ++;
        Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, 0, 0);
        Cizgi_Yeri += Sutun_Atlagi;
        Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, 0, 1);
      }
    }
  }
  if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
    if (Satir_No == 1)
    {
      Cizgi_Yeri = 0;
      Satir_No = 0;
      Sutun_No = 0;
      Satir_Yeri = 0;
      Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, 0, 0);
      Diger_Ayarlar_Secim_Sayfa(2);
    }
  }
  else if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;

    lcd.clear();
    Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, 0, 0);
    Kayittan_Yazi_Yaz(1, SATIR_1, Kaydedildi_Yeri);
    Tarih_Saat_Ayarla(Saat, Dakika, Gun, Ay, Yil);
    delay(2000);
    Cizgi_Yeri = 0;
    Satir_No = 0;
    Sutun_No = 0;
    Satir_Yeri = 0;
    
    Diger_Ayarlar_Secim_Sayfa(2);
  }
  else if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
    if (Satir_No == 1)
    {
      if (Sutun_No == 1)
      {
        Gun++;
        if (Gun > 31)     //// aylara göre gün sınırlaması olacak mı? olacaksa bu sınırlama kaydetme sırasında hata vermeli. Sorulacak!!
          Gun = 1;
        Lcd_Sure_Yaz(Cizgi_Yeri-1, Satir_Yeri, Gun, 2, 2); //x,y,sayi,boyut,hane
        lcd.setCursor(Cizgi_Yeri, Satir_Yeri);  
      }
      else if (Sutun_No == 2)
      {
        Ay++;
        if (Ay > 12)
          Ay = 1;
        Lcd_Sure_Yaz(Cizgi_Yeri-1, Satir_Yeri, Ay, 2, 2); //x,y,sayi,boyut,hane
        lcd.setCursor(Cizgi_Yeri, Satir_Yeri);
      }
      else if (Sutun_No == 3)
      {
        Yil++;
        if (Yil > 99)
          Yil = 0;
        Lcd_Sure_Yaz(Cizgi_Yeri-3, Satir_Yeri, (2000 + Yil), 2, 4); //x,y,sayi,boyut,hane
        lcd.setCursor(Cizgi_Yeri, Satir_Yeri); 
      }
    }
    else
    {
      if (Sutun_No == 1)
      {
        Saat++;
        if (Saat > 23)
          Saat = 0;
        Lcd_Sure_Yaz(Cizgi_Yeri-1, Satir_Yeri, Saat, 2, 2); //x,y,sayi,boyut,hane
        lcd.setCursor(Cizgi_Yeri, Satir_Yeri); 
      }
      else if (Sutun_No == 2)
      {
        Dakika ++;
        if (Dakika > 59)
          Dakika = 0;
        Lcd_Sure_Yaz(Cizgi_Yeri-1, Satir_Yeri, Dakika, 2, 2); //x,y,sayi,boyut,hane
        lcd.setCursor(Cizgi_Yeri, Satir_Yeri); 
      }
    }
  }
  else if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
    if (Satir_No == 1)
    {
      if (Sutun_No == 1)
      {
        Gun--;
        if (Gun < 1)     //// aylara göre gün sınırlaması olacak mı? olacaksa bu sınırlama kaydetme sırasında hata vermeli. Sorulacak!!
          Gun = 31;
        Lcd_Sure_Yaz(Cizgi_Yeri-1, Satir_Yeri, Gun, 2, 2); //x,y,sayi,boyut,hane
        lcd.setCursor(Cizgi_Yeri, Satir_Yeri); 
      }
      else if (Sutun_No == 2)
      {
        Ay--;
        if (Ay < 1)
          Ay = 12;
        Lcd_Sure_Yaz(Cizgi_Yeri-1, Satir_Yeri, Ay, 2, 2); //x,y,sayi,boyut,hane
        lcd.setCursor(Cizgi_Yeri, Satir_Yeri); 
      }
      else if (Sutun_No == 3)
      {
        Yil--;
        if (Yil < 0)
          Yil = 99;
        Lcd_Sure_Yaz(Cizgi_Yeri-3, Satir_Yeri, (2000 + Yil), 2, 4); //x,y,sayi,boyut,hane
        lcd.setCursor(Cizgi_Yeri, Satir_Yeri); 
      }
    }
    else
    {
      if (Sutun_No == 1)
      {
        Saat--;
        if (Saat < 0)
          Saat = 23;
        Lcd_Sure_Yaz(Cizgi_Yeri-1, Satir_Yeri, Saat, 2, 2); //x,y,sayi,boyut,hane
        lcd.setCursor(Cizgi_Yeri, Satir_Yeri); 
      }
      else if (Sutun_No == 2)
      {
        Dakika --;
        if (Dakika < 0)
          Dakika = 59;
        Lcd_Sure_Yaz(Cizgi_Yeri-1, Satir_Yeri, Dakika, 2, 2); //x,y,sayi,boyut,hane
        lcd.setCursor(Cizgi_Yeri, Satir_Yeri); 
      }
    }
  }
}

void Yazici_Baslik_Ayar_Sayfa(void)
{
  //char Gidecek[12] = {0};
  lcd.clear(); 
  Yazici_Baslik_Ayari(99);     //// sıfırlama için 99 yapıldı
  EKM.Sayfa = Yazici_Baslik_Ayar_Sayfasi;

  Butonlari_Temizle();
}

void Yazici_Baslik_Ayari(unsigned char Durum)
{
  static unsigned char Cizgi_Yeri = 0, Sutun_No = 0, Satir_Yeri = 0;
  static char Cihaz_Adi[21] = {0};

  if (Durum == 99)
  {
    Butonlari_Temizle();
  
    Cizgi_Yeri = 0;
    Sutun_No = 0;
    Satir_Yeri = 0;
    lcd.clear();
    strcpy(Cihaz_Adi, EKM.Cihaz_Adi);
    lcd.print(Cihaz_Adi);
    Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, 0, 0);
    Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, 0, 1);
    lcd.setCursor(Cizgi_Yeri, Satir_Yeri);
  }
  if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
    Cizgi_Cek(Cizgi_Yeri, Satir_Yeri,0, 0, 0);
    Cizgi_Yeri = 0;
    Sutun_No = 0;
    Satir_Yeri = 0;
    //Sutun_Yeri = 0;
    Diger_Ayarlar_Secim_Sayfa(1);
  }
  else if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
    
    Cizgi_Cek(Cizgi_Yeri, Satir_Yeri,0, 0, 0);
    lcd.clear();
    Kayittan_Yazi_Yaz(1,SATIR_1,Kaydedildi_Yeri);
    Buzer_Ac;
    EKM.Buzer_Calma_ms = UZUN_BUZER;      
    
    Veri_Kaydet_String(CIHAZ_ADI_KAYIT_YERI, Cihaz_Adi);
    memcpy(EKM.Cihaz_Adi, Cihaz_Adi, strlen(Cihaz_Adi));
    delay(UZUN_BUZER);
    Diger_Ayarlar_Secim_Sayfa(1);

  }
  else if (Buton[Sol_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Sol_Buton].Olay = OLAYI_TEMIZLE;
    if (Sutun_No > 0)
    {
      Cizgi_Cek(Cizgi_Yeri, Satir_Yeri,0, 0, 0);
      Cizgi_Yeri -= 1;
      Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, 0, 1);
      Sutun_No --;         
    }
  }
  else if (Buton[Sag_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Sag_Buton].Olay = OLAYI_TEMIZLE;
    if (Sutun_No < 15)
    {
      Cizgi_Cek(Cizgi_Yeri, Satir_Yeri,0, 0, 0);
      Cizgi_Yeri += 1;
      Cizgi_Cek(Cizgi_Yeri, Satir_Yeri, 0, 0, 1);
      Sutun_No ++;         
    }
  }
  else if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;

    if (Cihaz_Adi[Sutun_No] != 32)
      Cihaz_Adi[Sutun_No]++;
    if ((Cihaz_Adi[Sutun_No] > 90) || (Cihaz_Adi[Sutun_No] == 32) || (Cihaz_Adi[Sutun_No] < 65))
    {
      if (Cihaz_Adi[Sutun_No] == 91)
        Cihaz_Adi[Sutun_No] = 32;
      else
        Cihaz_Adi[Sutun_No] = 65;
    }

    lcd.print(Cihaz_Adi[Sutun_No]);
    lcd.setCursor(Cizgi_Yeri, Satir_Yeri); 
  }
  else if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;

    if (Cihaz_Adi[Sutun_No] != 32)
      Cihaz_Adi[Sutun_No]--;

    if ((Cihaz_Adi[Sutun_No] < 65) || (Cihaz_Adi[Sutun_No] > 90))
    {
      if (Cihaz_Adi[Sutun_No] == 64)
        Cihaz_Adi[Sutun_No] = 32;
      else
        Cihaz_Adi[Sutun_No] = 90;
    }

    lcd.print(Cihaz_Adi[Sutun_No]);
    lcd.setCursor(Cizgi_Yeri, Satir_Yeri); 
  }

  if (Buton[Yukari_Buton].Olay == UZUN_BASILDI_OLAYI)
  {
    Buzer_Kapa;
    if (Buton[Yukari_Buton].Durum == 0)
      Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
    Cihaz_Adi[Sutun_No]++;

    if (Cihaz_Adi[Sutun_No] != 32)
      Cihaz_Adi[Sutun_No]++;
    if ((Cihaz_Adi[Sutun_No] > 90) || (Cihaz_Adi[Sutun_No] == 32) || (Cihaz_Adi[Sutun_No] < 65))
    {
      if (Cihaz_Adi[Sutun_No] == 91)
        Cihaz_Adi[Sutun_No] = 32;
      else
        Cihaz_Adi[Sutun_No] = 65;
    }

    lcd.print(Cihaz_Adi[Sutun_No]);
    lcd.setCursor(Cizgi_Yeri, Satir_Yeri); 
    delay(100);
  }

  if (Buton[Asagi_Buton].Olay == UZUN_BASILDI_OLAYI)
  {
    Buzer_Kapa;
    if (Buton[Asagi_Buton].Durum == 0)
      Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;

    if (Cihaz_Adi[Sutun_No] != 32)
      Cihaz_Adi[Sutun_No]--;

    if ((Cihaz_Adi[Sutun_No] < 65) || (Cihaz_Adi[Sutun_No] > 90))
    {
      if (Cihaz_Adi[Sutun_No] == 64)
        Cihaz_Adi[Sutun_No] = 32;
      else
        Cihaz_Adi[Sutun_No] = 90;
    }

    lcd.print(Cihaz_Adi[Sutun_No]);
    lcd.setCursor(Cizgi_Yeri, Satir_Yeri); 
    delay(100);
  }
}

unsigned char Kalan_Sure_Goster(unsigned char x_pos, unsigned char y_pos, unsigned char Sayilacak_Dk, unsigned char Sayilacak_Sn)
{

  static unsigned char Gosterim_Adimi = 0;
  signed int Kalan_Dk = 0, Kalan_Sn = 0;
  static signed int Bitis_Dk = 0, Bitis_Sn = 0;
  static unsigned int E_Sn = 0;

  if ((Sayilacak_Dk == 0) && (Sayilacak_Sn == 0))
  {
    Gosterim_Adimi = 0;
    return TAMAMLANDI;
  }
  if (Gosterim_Adimi == 0)
  {
    Gosterim_Adimi = 1;
    Bitis_Sn = Sayilacak_Sn + EKM.Islem_Sn;
    Bitis_Dk = Sayilacak_Dk + EKM.Islem_Dk;

    if (Bitis_Sn >= 60)
    {
      while (Bitis_Sn >= 60)
      {
        Bitis_Sn -= 60;
        Bitis_Dk++;
      }
    }  
  }
  else if (Gosterim_Adimi == 1)
  {
    if ((EKM.Islem_Dk == Bitis_Dk) && (EKM.Islem_Sn >= Bitis_Sn))
    {
      Gosterim_Adimi = 0;

      Kalan_Sn = Bitis_Sn - EKM.Islem_Sn;
      Kalan_Dk = Bitis_Dk - EKM.Islem_Dk;

      if (Kalan_Sn < 0)
      {
        Kalan_Sn += 60;
        Kalan_Dk --;
      }

      Lcd_Sure_Yaz(x_pos, y_pos, Kalan_Dk, 2, 3);
      Yazi_Yaz(x_pos + 3, y_pos, ":", 2);
      Lcd_Sure_Yaz(x_pos + 4, y_pos, Kalan_Sn, 2, 2);
       
      return TAMAMLANDI;
    }
    else
    {
      if (E_Sn != EKM.Islem_Sn)
      {
        Kalan_Sn = Bitis_Sn - EKM.Islem_Sn;
        Kalan_Dk = Bitis_Dk - EKM.Islem_Dk;
        E_Sn = EKM.Islem_Sn;

        if (Kalan_Sn < 0)
        {
          Kalan_Sn += 60;
          Kalan_Dk --;
        }

        Lcd_Sure_Yaz(x_pos, y_pos, Kalan_Dk, 2, 3);
        Yazi_Yaz(x_pos + 3, y_pos, ":", 2);
        Lcd_Sure_Yaz(x_pos + 4, y_pos, Kalan_Sn, 2, 2);
         
      }
    }
  }
  return DEVAM_EDIYOR;
}

unsigned char Buyuk_Sayi_Gir(unsigned char Sutun, unsigned char Satir, unsigned int *Girilen, unsigned char Sayi_Hane)
{
  static unsigned char Cizgi_Yeri = 0, Sutun_No = 0, Cizgi_Boyu = 0, Cizgi_Satir_Yeri = 0, Sayi_Girme_Adimi = 0;
  unsigned char yuzbinler = 0, onbinler = 0, binler = 0, yuzler = 0, onlar = 0, birler = 0;
  static char Girilen_Sayi[7] = {0};
  unsigned int Sayi = 0;
  //  unsigned int

  if (Sayi_Girme_Adimi == 0) 
  {
    Sayi = *Girilen;
    Sayi_Girme_Adimi = 1;
    Cizgi_Boyu = 9;
    Cizgi_Yeri = Sutun;
    //Satir_No = 1;
    Sutun_No = 0;

    yuzbinler = Sayi / 100000;
    Sayi -= yuzbinler * 100000;

    onbinler = Sayi / 10000;
    Sayi -= onbinler * 10000;

    binler = Sayi / 1000;
    Sayi -= binler * 1000;

    yuzler = Sayi / 100;
    Sayi -= yuzler * 100;

    onlar = Sayi / 10;
    Sayi -= onlar * 10;

    birler = Sayi;

    if (Sayi_Hane == 6)
    {
      Girilen_Sayi[0] = yuzbinler + 48;
      Girilen_Sayi[1] = onbinler + 48;
      Girilen_Sayi[2] = binler + 48;
      Girilen_Sayi[3] = yuzler + 48;
      Girilen_Sayi[4] = onlar + 48;
      Girilen_Sayi[5] = birler + 48;
      Girilen_Sayi[6] = 0;
    }
    else if (Sayi_Hane == 5)
    {
      //Gidecek_Sayi[1] = yuzbinler + 48;
      Girilen_Sayi[0] = onbinler + 48;
      Girilen_Sayi[1] = binler + 48;
      Girilen_Sayi[2] = yuzler + 48;
      Girilen_Sayi[3] = onlar + 48;
      Girilen_Sayi[4] = birler + 48;
      Girilen_Sayi[5] = 0;
    }
    else if (Sayi_Hane == 4)
    {
      //Girilen_Sayi[1] = yuzbinler + 48;
      // Girilen_Sayi[2] = onbinler + 48;
      Girilen_Sayi[0] = binler + 48;
      Girilen_Sayi[1] = yuzler + 48;
      Girilen_Sayi[2] = onlar + 48;
      Girilen_Sayi[3] = birler + 48;
      Girilen_Sayi[4] = 0;
    }
    else if (Sayi_Hane == 3)
    {
      //  Girilen_Sayi[1] = yuzbinler + 48;
      //  Girilen_Sayi[2] = onbinler + 48;
      //  Girilen_Sayi[3] = binler + 48;
      Girilen_Sayi[0] = yuzler + 48;
      Girilen_Sayi[1] = onlar + 48;
      Girilen_Sayi[2] = birler + 48;
      Girilen_Sayi[3] = 0;
    }
    else if (Sayi_Hane == 2)
    {
      //  Girilen_Sayi[1] = yuzbinler + 48;
      //  Girilen_Sayi[2] = onbinler + 48;
      //  Girilen_Sayi[3] = binler + 48;
      //  Girilen_Sayi[4] = yuzler +48;
      Girilen_Sayi[0] = onlar + 48;
      Girilen_Sayi[1] = birler + 48;
      Girilen_Sayi[2] = 0;
    }
    else
    {
      //  Girilen_Sayi[1] = yuzbinler + 48;
      //  Girilen_Sayi[2] = onbinler + 48;
      //  Girilen_Sayi[3] = binler + 48;
      //  Girilen_Sayi[4] = yuzler +48;
      //  Girilen_Sayi[5] = onlar +48;
      Girilen_Sayi[0] = birler + 48;
      Girilen_Sayi[1] = 0;
    }
    Yazi_Yaz(Cizgi_Yeri, Satir, Girilen_Sayi, 2);
    
    Cizgi_Cek(Cizgi_Yeri,Satir,0,0,1);
    //Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 1); /// 40-25=15
    
  }
  else if (Sayi_Girme_Adimi == 1)
  {
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 0);
      Cizgi_Yeri = 0;
      Cizgi_Boyu = 0;
      Sutun_No = 0;
      Cizgi_Satir_Yeri = 0;
      Sayi_Girme_Adimi = 0;
      return IPTAL_ET;    //// kayıt olmadan geri çıkıldı. önceki menüye dönecek
    }
    else if (Buton[Sag_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Sag_Buton].Olay = OLAYI_TEMIZLE;
      if (Sutun_No < (Sayi_Hane - 1))
      {
        Cizgi_Cek(Cizgi_Yeri,Satir,0,0,0);
        Sutun_No ++;
        Cizgi_Yeri ++;
        Cizgi_Cek(Cizgi_Yeri, Satir, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 1);
      }
    }
    else if (Buton[Sol_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Sol_Buton].Olay = OLAYI_TEMIZLE;
      if(Sutun_No)
      {
        Cizgi_Cek(Cizgi_Yeri,Satir,0,0,0);
        Sutun_No --;
        Cizgi_Yeri --;
        Cizgi_Cek(Cizgi_Yeri, Satir, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 1);
      }
      
    }
    else if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      Cizgi_Cek(Cizgi_Yeri, Satir, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri,0 );
      lcd.clear();      
      *Girilen = atoi(Girilen_Sayi);
  
      Cizgi_Yeri = 0;
      Sayi_Girme_Adimi = 0;
      return TAMAMLANDI;
    }
    else if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
      Girilen_Sayi[Sutun_No]++;
      if ((Girilen_Sayi[Sutun_No] > 57) || (Girilen_Sayi[Sutun_No] < 48))
      {
        Girilen_Sayi[Sutun_No] = 48;
      }
      lcd.print(Girilen_Sayi[Sutun_No]);
      lcd.setCursor(Cizgi_Yeri, Satir);
    }
    else if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
      Girilen_Sayi[Sutun_No]--;

      if ((Girilen_Sayi[Sutun_No] < 48) || (Girilen_Sayi[Sutun_No] > 57))
      {
        Girilen_Sayi[Sutun_No] = 57;
      }

      lcd.print(Girilen_Sayi[Sutun_No]);
      lcd.setCursor(Cizgi_Yeri, Satir);
    
    }
  }  
  return DEVAM_EDIYOR;
}

unsigned char Sayi_Girisi(unsigned char Sutun, unsigned char Satir, unsigned short *Girilen, unsigned char Sayi_Hane)
{
  static unsigned char Cizgi_Yeri = 0, Sutun_No = 0, Cizgi_Boyu = 0, Cizgi_Satir_Yeri = 0, Sayi_Girme_Adimi = 0;
  unsigned char onbinler = 0, binler = 0, yuzler = 0, onlar = 0, birler = 0;
  static char Girilen_Sayi[6] = {0};
  unsigned int Sayi = 0;

  if (Sayi_Girme_Adimi == 0)
  {
    Sayi = *Girilen;
    Sayi_Girme_Adimi = 1;
    Sutun_No = 0;
    Cizgi_Yeri = Sutun;

    onbinler = Sayi / 10000;
    Sayi -= onbinler * 10000;

    binler = Sayi / 1000;
    Sayi -= binler * 1000;

    yuzler = Sayi / 100;
    Sayi -= yuzler * 100;

    onlar = Sayi / 10;
    Sayi -= onlar * 10;

    birler = Sayi;

    if (Sayi_Hane == 5)
    {
      //Gidecek_Sayi[1] = yuzbinler + 48;
      Girilen_Sayi[0] = onbinler + 48;
      Girilen_Sayi[1] = binler + 48;
      Girilen_Sayi[2] = yuzler + 48;
      Girilen_Sayi[3] = onlar + 48;
      Girilen_Sayi[4] = birler + 48;
      Girilen_Sayi[5] = 0;
    }
    else if (Sayi_Hane == 4)
    {
      //Girilen_Sayi[1] = yuzbinler + 48;
      // Girilen_Sayi[2] = onbinler + 48;
      Girilen_Sayi[0] = binler + 48;
      Girilen_Sayi[1] = yuzler + 48;
      Girilen_Sayi[2] = onlar + 48;
      Girilen_Sayi[3] = birler + 48;
      Girilen_Sayi[4] = 0;
    }
    else if (Sayi_Hane == 3)
    {
      //  Girilen_Sayi[1] = yuzbinler + 48;
      //  Girilen_Sayi[2] = onbinler + 48;
      //  Girilen_Sayi[3] = binler + 48;
      Girilen_Sayi[0] = yuzler + 48;
      Girilen_Sayi[1] = onlar + 48;
      Girilen_Sayi[2] = birler + 48;
      Girilen_Sayi[3] = 0;
    }
    else if (Sayi_Hane == 2)
    {
      //  Girilen_Sayi[1] = yuzbinler + 48;
      //  Girilen_Sayi[2] = onbinler + 48;
      //  Girilen_Sayi[3] = binler + 48;
      //  Girilen_Sayi[4] = yuzler +48;
      Girilen_Sayi[0] = onlar + 48;
      Girilen_Sayi[1] = birler + 48;
      Girilen_Sayi[2] = 0;
    }
    else
    {
      //  Girilen_Sayi[1] = yuzbinler + 48;
      //  Girilen_Sayi[2] = onbinler + 48;
      //  Girilen_Sayi[3] = binler + 48;
      //  Girilen_Sayi[4] = yuzler +48;
      //  Girilen_Sayi[5] = onlar +48;
      Girilen_Sayi[0] = birler + 48;
      Girilen_Sayi[1] = 0;
    }
    Yazi_Yaz(Cizgi_Yeri, Satir, Girilen_Sayi, 2);
    Cizgi_Cek(Cizgi_Yeri,Satir,0,0,1);
    //Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 1); /// 40-25=15
    
  }
  else if (Sayi_Girme_Adimi == 1)
  {
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 0);
      Cizgi_Yeri = 0;
      Cizgi_Boyu = 0;
      Sutun_No = 0;
      Cizgi_Satir_Yeri = 0;
      Sayi_Girme_Adimi = 0;
      return IPTAL_ET;    //// kayıt olmadan geri çıkıldı. önceki menüye dönecek
    }
    else if (Buton[Sag_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Sag_Buton].Olay = OLAYI_TEMIZLE;
      if (Sutun_No < (Sayi_Hane - 1))
      {
        Cizgi_Cek(Cizgi_Yeri,Satir,0,0,0);
        Sutun_No ++;
        Cizgi_Yeri ++;
        Cizgi_Cek(Cizgi_Yeri, Satir, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 1);
      }
    }
    else if (Buton[Sol_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Sol_Buton].Olay = OLAYI_TEMIZLE;
      if(Sutun_No)
      {
        Cizgi_Cek(Cizgi_Yeri,Satir,0,0,0);
        Sutun_No --;
        Cizgi_Yeri --;
        Cizgi_Cek(Cizgi_Yeri, Satir, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 1);
      }
      
    }

    else if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      Cizgi_Cek(Cizgi_Yeri, Satir, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri,0);
      lcd.clear();
      Sayi = atoi(Girilen_Sayi);
      if(Sayi < 65535)
        *Girilen = Sayi;
      else
        *Girilen = 65535;
  
      Cizgi_Yeri = 0;
      Sayi_Girme_Adimi = 0;
      return TAMAMLANDI;
    }
    else if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
      Girilen_Sayi[Sutun_No]++;
      if ((Girilen_Sayi[Sutun_No] > 57) || (Girilen_Sayi[Sutun_No] < 48))
      {
        Girilen_Sayi[Sutun_No] = 48;
      }
      lcd.print(Girilen_Sayi[Sutun_No]);
      lcd.setCursor(Cizgi_Yeri, Satir);
    }
    else if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
      Girilen_Sayi[Sutun_No]--;

      if ((Girilen_Sayi[Sutun_No] < 48) || (Girilen_Sayi[Sutun_No] > 57))
      {
        Girilen_Sayi[Sutun_No] = 57;
      }

      lcd.print(Girilen_Sayi[Sutun_No]);
      lcd.setCursor(Cizgi_Yeri, Satir);
    
    }
  }  
  return DEVAM_EDIYOR;
}

void Dil_Secimi(void)
{
  static unsigned char Secim_Adimi = 0;

  if(Secim_Adimi == 0)
  {
    lcd.clear();
    EKM.Sayfa = Dil_Secim_Sayfasi;
    Secim_Adimi = 1;
    EKM.Imlec = 1;
    Imlec_Yaz(EKM.Imlec);
    EKM.Dil = 0;Kayittan_Yazi_Yaz(1 ,SATIR_1,Turkce_Yaz_Yeri);
    EKM.Dil = 1;Kayittan_Yazi_Yaz(1 ,SATIR_2,Turkce_Yaz_Yeri);
    EKM.Dil = 2;Kayittan_Yazi_Yaz(1 ,SATIR_3,Turkce_Yaz_Yeri);
    EKM.Dil = 3;Kayittan_Yazi_Yaz(1 ,SATIR_4,Turkce_Yaz_Yeri);
    EKM.Dil = 4;Kayittan_Yazi_Yaz(11,SATIR_1,Turkce_Yaz_Yeri);
    EKM.Dil = 5;Kayittan_Yazi_Yaz(11,SATIR_2,Turkce_Yaz_Yeri);
    EKM.Dil = 6;Kayittan_Yazi_Yaz(11,SATIR_3,Turkce_Yaz_Yeri);
    EKM.Dil = 7;Kayittan_Yazi_Yaz(11,SATIR_4,Turkce_Yaz_Yeri);        
     // dil sayısına kadar eklendikçe açılacak
   // EKM.Dil = 3;
    //Kayittan_Yazi_Yaz(1,SATIR_2,Turkce_Yaz_Yeri*4);
    EKM.Dil = EEPROM.readUChar(CIHAZ_DIL_YERI);
  }
  else if (Secim_Adimi == 1)
  {
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {   Buton[Geri_Buton].Olay =  OLAYI_TEMIZLE;Secim_Adimi = 0;Cihaz_Ayarlar_Sayfa(1);}
      
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {   Buton[Giris_Buton].Olay =  OLAYI_TEMIZLE;Secim_Adimi = 0;EKM.Dil = EKM.Imlec - 1;Veri_Kaydet_Uchar(CIHAZ_DIL_YERI, EKM.Dil);Cihaz_Ayarlar_Sayfa(1); }
    
    if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
    {   Buton[Yukari_Buton].Olay =  OLAYI_TEMIZLE;if(EKM.Imlec > 1) EKM.Imlec --;Imlec_Yaz(EKM.Imlec); }  
   
    if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
    {   Buton[Asagi_Buton].Olay =  OLAYI_TEMIZLE;if(EKM.Imlec < DIL_SAYISI)EKM.Imlec ++;Imlec_Yaz(EKM.Imlec);}  
    
  }
}

void Wifi_Baglanma_Sayfa(void)
{
  static unsigned char Baglanma_Asamasi = 0, Islem_Durumu = 0;
  static unsigned int _ms = 0;

  if (Baglanma_Asamasi == Sifirlama)
  {
    EKM.Sayfa = Wifi_Baglanma_Sayfasi;
    Baglanma_Asamasi = Wifi_Baglanma;
  }
  else if (Baglanma_Asamasi == Wifi_Baglanma)
  {
    Islem_Durumu = Wifi_Baglan();
    if(Islem_Durumu == BAGLANDI)
    {
      Buzer_Ac;
      EKM.Buzer_Calma_ms = 50;
      lcd.clear();
      Kayittan_Yazi_Yaz(0, SATIR_1, Baglandi_Yaz_Yeri);
      _ms = EKM.MS;
      Baglanma_Asamasi = Bekle_ve_Cik;      
    }
    else if(Islem_Durumu == BAGLANAMADI)
    {
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
      Baglanma_Asamasi = Bekle_ve_Cik;
      _ms = EKM.MS;
    }
    else if(Islem_Durumu == WIFI_BULUNAMADI)
    {
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
      Baglanma_Asamasi = Bekle_ve_Cik;
      _ms = EKM.MS;
    }
    else if(Islem_Durumu == IPTAL_ET)
    {
      Baglanma_Asamasi = Sifirlama;
      lcd.clear();
      Diger_Ayarlar_Secim_Sayfa(2);
    }
  }
  else if (Baglanma_Asamasi == Bekle_ve_Cik)
  {
    if((EKM.MS - _ms) > UZUN_BUZER)
    {
      Baglanma_Asamasi = Sifirlama;
      Diger_Ayarlar_Secim_Sayfa(2);
    }
    
  }

}

void Diger_Ayarlar_Secim_Sayfa(unsigned char Sayfa)
{
  EKM.Sayfa = Diger_Ayarlar_Sayfasi;
  lcd.clear();
  if(Sayfa == 1)
  {
    Kayittan_Yazi_Yaz(1,SATIR_1,Servis_Yeri);
    Kayittan_Yazi_Yaz(1,SATIR_2,Yazilim_Guncelle_Yeri);
    Kayittan_Yazi_Yaz(1,SATIR_3,Cihaz_Adi_Degistir_Yeri);
    Kayittan_Yazi_Yaz(1,SATIR_4,Gonderici_Maili_Gir_Yeri);
  }
  else
  {
    Kayittan_Yazi_Yaz(1,SATIR_1,Wifi_Yeri);
    if(EKM.Yazici == VAR)
      Kayittan_Yazi_Yaz(1,SATIR_2,Tarih_Saat_Yeri);
  }
  EKM.Diger_Ayarlar_Sayfa = Sayfa;
  EKM.Imlec = 1;
  Imlec_Yaz(EKM.Imlec);
}

void Diger_Ayarlar_Secimi(void)
{
  if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
    Butonlari_Temizle();
    Cihaz_Ayarlar_Sayfa(4);
  }
  if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
    Butonlari_Temizle();
    if(EKM.Diger_Ayarlar_Sayfa == 1)
    {
      if (EKM.Imlec == 1)
      {
        Servis_Ayar_Giris();
      }
      else if (EKM.Imlec == 2)
      {
        Yazilim_Guncelle();
      }
      else if (EKM.Imlec == 3)
      {
        Yazici_Baslik_Ayar_Sayfa();
      }
      else if (EKM.Imlec == 4)
      {
        Gonderici_Mail_Girisi();
      }   
    }
    else if(EKM.Diger_Ayarlar_Sayfa == 2)
    {
      if (EKM.Imlec == 1)
      {
        Wifi_Baglanma_Sayfa();
      }
      else if (EKM.Imlec == 2)
      {
        Tarih_Saat_Ayar_Sayfa();
      }   
    }
  }
  if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
    EKM.Imlec_Yonu = YUKARI;
    if(EKM.Imlec > 1)
    {
      EKM.Imlec --;
      Imlec_Yaz(EKM.Imlec);
    }
    else
    {
      Diger_Ayarlar_Secim_Sayfa(1);
    }
  }
  if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
    if (EKM.Diger_Ayarlar_Sayfa == 1)
    {
      if (EKM.Imlec < 4)
      {
        EKM.Imlec ++;
        Imlec_Yaz(EKM.Imlec);
      }
      else
      {
        Diger_Ayarlar_Secim_Sayfa(2);
      }   
    }
    else
    {
      if (EKM.Yazici == VAR)
      {
        if (EKM.Imlec < 2)
        {
          EKM.Imlec ++;
          Imlec_Yaz(EKM.Imlec);
        }
      }
    }      
  }
  // if (Buton[Sag_Buton].Olay == BASILDI_OLAYI)
  // {
  //   Buton[Sag_Buton].Olay = OLAYI_TEMIZLE;
  //   if(EKM.Yazici == VAR)
  //     Tarih_Saat_Ayar_Sayfa();
  // }
}

void Cihaz_Ayarlari(void)
{
  if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
    Ayar_Secim_Sayfa(1);
  }
  if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;

    if (EKM.Imlec == 1)
    {
      Dil_Secimi();
    }
    else if (EKM.Imlec == 2)
    {
      Sistem_Vakumlama();
    }
    else if (EKM.Imlec == 3)
    {
      Sistem_Bosaltma();
    }
    else if (EKM.Imlec == 4)
    {
      Diger_Ayarlar_Secim_Sayfa(1);
    }    
  }
  if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
    EKM.Imlec_Yonu = YUKARI;
    if(EKM.Imlec > 1)
      EKM.Imlec --;
    Imlec_Yaz(EKM.Imlec);
  }
  if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
    if (EKM.Imlec < 4)
      EKM.Imlec ++;
    Imlec_Yaz(EKM.Imlec);
  }
}

void Terazi_Dara(void)
{
  static unsigned char Dara_Adimi = 0;
  static float Terazi_Deg = 0;
  static unsigned int _ms = 0;
  if(Dara_Adimi == 0)
  {
    lcd.clear();
    EKM.Sayfa = Terazi_Dara_Sayfasi;
    Dara_Adimi = 1;
    Kayittan_Yazi_Yaz(0,SATIR_1,Kalibrasyon_Unlem_Yeri);
    Kayittan_Yazi_Yaz(0,SATIR_2,Cihaz_Tupu_Bos_Olsun_Yeri);
    Kayittan_Yazi_Yaz(0,SATIR_4,Kayit_Icin_ENT_Yeri);
    HX_710_Oku(TERAZI,27,&Terazi_Deg);
    if(EKM.Terazi_Boleni == 0)
      EKM.Terazi_Boleni = 1;
    Lcd_Sayi_Yaz(3,SATIR_3,(int)(Terazi_Deg/EKM.Terazi_Boleni),2,5);
    lcd.print("gr,");
    lcd.print(EKM.Terazi_Darasi);
    _ms = EKM.MS;
  }
  else if (Dara_Adimi == 1)
  {
    HX_710_Oku(TERAZI,27,&Terazi_Deg);

    if((EKM.MS - _ms) > 200)
    {
      Lcd_Sayi_Yaz(3,SATIR_3,(int)Terazi_Deg/(EKM.Terazi_Boleni),2,5);
      lcd.print("gr,");
      lcd.print(EKM.Terazi_Darasi);
      _ms = EKM.MS;
    }

    if(Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      Dara_Adimi = 2;
      EKM.Terazi_Darasi = Terazi_Deg;
      Veri_Kaydet_Int(TERAZI_DARA_KAYIT_YERI,EKM.Terazi_Darasi);
      _ms = EKM.MS;
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_1,Kaydedildi_Yeri);
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
    }
    if(Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Dara_Adimi = 0;
      lcd.clear();
      Terazi_Kalibrasyon_Secimi();
    }
  }
  else if (Dara_Adimi == 2)
  {
    if(!EKM.Buzer_Calma_ms)
    {
      Dara_Adimi = 0;
      lcd.clear();
      Terazi_Kalibrasyon_Secimi();
    }
  }
}

void Kalibrasyon_Secim_Sayfa(unsigned char Imlec_Yeri)
{
  EKM.Sayfa = Kalibrasyon_Secim_Sayfasi;
  Butonlari_Temizle();
  lcd.clear();
  EKM.Imlec = Imlec_Yeri;
  Imlec_Yaz(EKM.Imlec);

  Kayittan_Yazi_Yaz(1,SATIR_1,Agirlik_Kal_Yeri);
  Kayittan_Yazi_Yaz(1,SATIR_2,Vakum_Kal_Yeri);
  Kayittan_Yazi_Yaz(1,SATIR_3,Basinc_Kal_Yeri);
  Kayittan_Yazi_Yaz(1,SATIR_4,Gaz_Tipi_Yeri);

}

void Terazi_Kalibrasyon_Secimi(void)
{
  static unsigned char Secim_Adimi = 0;

  if(Secim_Adimi == 0)
  {
    lcd.clear();
    EKM.Sayfa = Terazi_Kalibrasyon_Secim_Sayfasi;
    EKM.Imlec = 1;
    Imlec_Yaz(EKM.Imlec);
    Kayittan_Yazi_Yaz(1,SATIR_1,Dara_Yaz_Yeri);
    Kayittan_Yazi_Yaz(1,SATIR_2,Kalibrasyon_1_Yeri);
    Secim_Adimi = 1;
  }
  else if (Secim_Adimi == 1)
  {
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Secim_Adimi = 0;
      Kalibrasyon_Secim_Sayfa(1);
    }

    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      if (EKM.Imlec == 1)
      {
        Secim_Adimi = 0;
        Terazi_Dara();
      }
      else if (EKM.Imlec == 2)
      {
        Secim_Adimi = 0;
        Terazi_Kalibrasyonu();
      }
    }
    if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
      if(EKM.Imlec < 2)
      {
        EKM.Imlec ++;
        Imlec_Yaz(EKM.Imlec);
      }  
        
    }
    if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
    
      if (EKM.Imlec > 1)
      {
        EKM.Imlec --;
        Imlec_Yaz(EKM.Imlec);       
      }
    }
  }
}

void Terazi_Kalibrasyonu(void)
{
  static unsigned char Kalibrasyon_Adimi = 0, Sayi_Giris_Durumu = 0;
  static signed int  Okuma_Adet_Sayac = 0;
  static float Ilk_Deger = 0, Son_Deger = 0, Fark = 0, Ortalama_Gr = 0, Terazi_Degeri = 0;
  static unsigned int _ms = 0;
  if (Kalibrasyon_Adimi == 0)
  {
    _ms = EKM.MS;
    lcd.clear();
    EKM.Sayfa = Terazi_Kalibrasyon_Sayfasi;
    Kayittan_Yazi_Yaz(1,SATIR_1,Kalibrasyon_Unlem_Yeri);
    Kayittan_Yazi_Yaz(1,SATIR_2,Olcum_Yapiliyor_Yeri);
    Kayittan_Yazi_Yaz(0,SATIR_4,Bekleyin_Yeri); 
    EKM.Sayfa = Terazi_Kalibrasyon_Sayfasi;
    Kalibrasyon_Adimi = 1;
    Okuma_Adet_Sayac = 0;
    if (EKM.Terazi_Boleni == 0)
      EKM.Terazi_Boleni = 1;
  }
  else if (Kalibrasyon_Adimi == 1)
  {
    if (HX_710_Oku(TERAZI, 27, &Terazi_Degeri))
    {
      if ((EKM.MS - _ms) > 5000)
      {
        Ortalama_Gr += Terazi_Degeri;
        Okuma_Adet_Sayac++;
      }
      Lcd_Sayi_Yaz(3,SATIR_3,(int)(Terazi_Degeri/EKM.Terazi_Boleni),2,5);
      lcd.print("gr,");
      lcd.print((int)EKM.Terazi_Boleni);        
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Terazi_Kalibrasyon_Secimi();
      Kalibrasyon_Adimi = 0;
      Ortalama_Gr = 0;
      Okuma_Adet_Sayac = 0;
      Terazi_Degeri = 0;
      Sayi_Giris_Durumu = 0;
      Ilk_Deger = 0;
      Son_Deger = 0;
    }
    if ((EKM.MS - _ms) > 10000)
    {
      Kalibrasyon_Adimi = 2;
      lcd.clear();

      Kayittan_Yazi_Yaz(0,SATIR_1,Agirlik_Yerlestir_Yeri);
      Kayittan_Yazi_Yaz(0,SATIR_3,Gr_Yaz_Yeri);
      lcd.print(":");
      Sayi_Girisi(7, SATIR_3, &EKM.Ref_Gr, 5);
       
    }
  }
  else if (Kalibrasyon_Adimi == 2)
  {
    Sayi_Giris_Durumu = Sayi_Girisi(7, SATIR_3, &EKM.Ref_Gr, 5);
    if (Sayi_Giris_Durumu == 1)
    {
      //      Okuma_Adet_Sayac -= 3;
      Ilk_Deger = Ortalama_Gr / (float)Okuma_Adet_Sayac;
      //      EKM.Terazi_Darasi = Ilk_Deger;                  ////// hata var ????? daha sonra ilk değer eepromdan alınmalı
      //      Veri_Kaydet_Int(TERAZI_DARA_KAYIT_YERI, EKM.Terazi_Darasi);

      Kalibrasyon_Adimi = 3;
      lcd.clear();
      Kayittan_Yazi_Yaz(0,SATIR_1,Lutfen_Bekleyin_Yeri);
       
      Ortalama_Gr = 0;
      Okuma_Adet_Sayac = 0;
      Terazi_Degeri = 0;
      Sayi_Giris_Durumu = 0;
      _ms = EKM.MS;
    }
    else if (Sayi_Giris_Durumu == 99)
    {
      Terazi_Kalibrasyon_Secimi();
      Kalibrasyon_Adimi = 0;
      Ortalama_Gr = 0;
      Okuma_Adet_Sayac = 0;
      Terazi_Degeri = 0;
      Sayi_Giris_Durumu = 0;
      Ilk_Deger = 0;
      Son_Deger = 0;
      Butonlari_Temizle();
    }
  }
  else if (Kalibrasyon_Adimi == 3)
  {
    if (HX_710_Oku(TERAZI, 27, &Terazi_Degeri))
    {
      if ((EKM.MS - _ms) > 5000)
      {
        Ortalama_Gr += Terazi_Degeri;
        Okuma_Adet_Sayac++;
      }

      Lcd_Sayi_Yaz(3,SATIR_3,(int)(Terazi_Degeri/EKM.Terazi_Boleni),2,5);
      lcd.print("gr,");
      lcd.print((int)EKM.Terazi_Boleni);
       
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Terazi_Kalibrasyon_Secimi();
      Kalibrasyon_Adimi = 0;
      Ortalama_Gr = 0;
      Okuma_Adet_Sayac = 0;
      Terazi_Degeri = 0;
      Sayi_Giris_Durumu = 0;
      Fark = 0;
    }
    if ((EKM.MS - _ms) > 10000)
    {
      Son_Deger = Ortalama_Gr / (float)Okuma_Adet_Sayac;
      Fark = Son_Deger - Ilk_Deger;
      if (Fark > 0)
      {
        lcd.clear();
 
       Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
         
        Buzer_Ac;
        EKM.Buzer_Calma_ms = UZUN_BUZER;
      }
      else
      {
        lcd.clear();
    
        Kayittan_Yazi_Yaz(1,SATIR_1,Kalibrasyon_1_Yeri);
        Kayittan_Yazi_Yaz(1,SATIR_2,Hatasi_Yeri);   
         
        Buzer_Ac;
        delay(1000);
        Buzer_Kapa;
        delay(1000);
        Buzer_Ac;
        delay(1000);
        Buzer_Kapa;

        Terazi_Kalibrasyon_Secimi();
        Kalibrasyon_Adimi = 0;
        Ortalama_Gr = 0;
        Okuma_Adet_Sayac = 0;
        Terazi_Degeri = 0;
        Sayi_Giris_Durumu = 0;
        Fark = 0;
        return;
      }
      EKM.Terazi_Boleni = (float)Fark / (float)EKM.Ref_Gr;
      Veri_Kaydet_Float(TERAZI_BOLEN_KAYIT_YERI, EKM.Terazi_Boleni);
      Veri_Kaydet_Ushort(TERAZI_REF_GR_KAYIT_YERI, EKM.Ref_Gr);
      
      Kalibrasyon_Adimi = 4;
      Ortalama_Gr = 0;
      Okuma_Adet_Sayac = 0;
      Terazi_Degeri = 0;
      Sayi_Giris_Durumu = 0;
      Fark = 0;

    }
  }
  else if (Kalibrasyon_Adimi == 4)
  {
    if(!EKM.Buzer_Calma_ms)
    {
      Kalibrasyon_Adimi = 0;
      Terazi_Kalibrasyon_Secimi();
    }
  }

}
// dara kalibrasyondan bagımsız ama kalibrasyon daraya bağımlı
void Basinc_Dara(void)
{
  static unsigned char Dara_Adimi = 0;
  static float Basinc_Deg = 0;
  static unsigned int _ms = 0;
  if(Dara_Adimi == 0)
  {
    lcd.clear();
    EKM.Sayfa = Basinc_Dara_Sayfasi;
    Dara_Adimi = 1;
    Kayittan_Yazi_Yaz(0,SATIR_1,Kalibrasyon_Unlem_Yeri);
    Kayittan_Yazi_Yaz(0,SATIR_2,Sifirlama_Yeri);
    Kayittan_Yazi_Yaz(0,SATIR_4,Kayit_Icin_ENT_Yeri);

    HX_710_Oku(BASINC,27,&Basinc_Deg);
    if(EKM.Basinc_Boleni == 0)
      EKM.Basinc_Boleni = 1;
    Lcd_Sayi_Yaz(3,SATIR_3,(int)(Basinc_Deg/EKM.Basinc_Boleni),99,3); //Lcd_Sayi_Yaz(14,SATIR_3,EKM.Basinc_Br,99,3);
    lcd.print("bar,");
    lcd.print(EKM.Basinc_Darasi);
    _ms = EKM.MS;
  }
  else if (Dara_Adimi == 1)
  {
    HX_710_Oku(BASINC,27,&Basinc_Deg);

    if((EKM.MS - _ms) > 200)
    {
      Lcd_Sayi_Yaz(3,SATIR_3,(int)(Basinc_Deg/EKM.Basinc_Boleni),99,3);
      lcd.print("bar,");
      lcd.print(EKM.Basinc_Darasi);
      _ms = EKM.MS;
    }

    if(Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      Dara_Adimi = 2;
      EKM.Basinc_Darasi = Basinc_Deg;
      Veri_Kaydet_Int(BASINC_DARA_KAYIT_YERI,EKM.Basinc_Darasi);
      _ms = EKM.MS;
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_1,Kaydedildi_Yeri);
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
    }
    if(Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Dara_Adimi = 0;
      lcd.clear();
      Basinc_Kalibrasyon_Secimi();
    }
  }
  else if (Dara_Adimi == 2)
  {
    if(!EKM.Buzer_Calma_ms)
    {
      Dara_Adimi = 0;
      lcd.clear();
      Basinc_Kalibrasyon_Secimi();
    }
  }
}

void Basinc_Kalibrasyonu(void)
{
  static unsigned char Kalibrasyon_Adimi = 0;
  static float Basinc_Degeri = 0;
  static unsigned int _ms = 0;

  if (Kalibrasyon_Adimi == 0)
  {
    _ms = EKM.MS;
    lcd.clear();
    EKM.Sayfa = Basinc_Kalibrasyon_Sayfasi;
    Kayittan_Yazi_Yaz(1,SATIR_1,Kalibrasyon_Unlem_Yeri);
    // Kayittan_Yazi_Yaz(1,SATIR_2,Olcum_Yapiliyor_Yeri);
    // Kayittan_Yazi_Yaz(1,SATIR_4,Bekleyin_Yeri); 
    Kayittan_Yazi_Yaz(0,SATIR_4,Devam_Icin_ENT_Yeri);
    EKM.Sayfa = Basinc_Kalibrasyon_Sayfasi;
    Kalibrasyon_Adimi = 1;
  }
  else if (Kalibrasyon_Adimi == 1)
  {
    if (Basinc_Oku(&Basinc_Degeri))
    {
      Lcd_Sayi_Yaz(3,SATIR_3,(int)(Basinc_Degeri),99,3);
      lcd.print("Bar");
      // lcd.print((int)EKM.Basinc_Boleni);        
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Basinc_Kalibrasyon_Secimi();
      Kalibrasyon_Adimi = 0;
      Basinc_Degeri = 0;
    }
    if (Buton[Yukari_Buton].Durum == 1)
    {
      Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
      if((EKM.MS - _ms) > 200)
      {
        if(EKM.Basinc_Boleni > 1)
          EKM.Basinc_Boleni --;
        _ms = EKM.MS;
      }      
    }
    if (Buton[Asagi_Buton].Durum == 1)
    {
      Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
      if((EKM.MS - _ms) > 200)
      {
        EKM.Basinc_Boleni ++;
        _ms = EKM.MS;
        if(EKM.Basinc_Boleni > 20000)
        EKM.Basinc_Boleni = 20000;
      }      
    }
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
      Veri_Kaydet_Float(BASINC_BOLEN_KAYIT_YERI,EKM.Basinc_Boleni);  
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;

      Kalibrasyon_Adimi = 2;
      Basinc_Degeri = 0;
    }
  }
  else if (Kalibrasyon_Adimi == 2)
  {
    if(!EKM.Buzer_Calma_ms)
    {
      Kalibrasyon_Adimi = 0;
      Basinc_Kalibrasyon_Secimi();
    }
  }

}

void Basinc_Kalibrasyon_Secimi(void)
{
  static unsigned char Secim_Adimi = 0;

  if(Secim_Adimi == 0)
  {
    lcd.clear();
    EKM.Sayfa = Basinc_Kalibrasyon_Secim_Sayfasi;
    EKM.Imlec = 1;
    Imlec_Yaz(EKM.Imlec);
    Kayittan_Yazi_Yaz(1,SATIR_1,Basinc_Sifir_Kal_Yeri);
    Kayittan_Yazi_Yaz(1,SATIR_2,Basinc_Kazanc_Kal_Yeri);
    Secim_Adimi = 1;
  }
  else if (Secim_Adimi == 1)
  {
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Secim_Adimi = 0;
      Kalibrasyon_Secim_Sayfa(3);
    }

    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      if (EKM.Imlec == 1)
      {
        Secim_Adimi = 0;
        Basinc_Dara();
      }
      else if (EKM.Imlec == 2)
      {
        Secim_Adimi = 0;
        Basinc_Kalibrasyonu();
      }
    }
    if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
      if(EKM.Imlec < 2)
      {
        EKM.Imlec ++;
        Imlec_Yaz(EKM.Imlec);
      }  
        
    }
    if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
    
      if (EKM.Imlec > 1)
      {
        EKM.Imlec --;
        Imlec_Yaz(EKM.Imlec);       
      }
    }
  }
}

void Vakum_Kalibrasyonu(void)
{
  static unsigned char Kalibrasyon_Adimi = 0;
  static signed int  Ortalama_Br = 0, Ilk_Deger = 0, Son_Deger = 0, Fark = 0, Okuma_Adet_Sayac = 0;
  static float Vakum_Degeri = 0;
  static unsigned int _ms = 0;
  unsigned char ix = 0;

  if (Kalibrasyon_Adimi == 0)
  {
    lcd.clear();
    EKM.Sayfa = Vakum_Kalibrasyon_Sayfasi;
    Kayittan_Yazi_Yaz(1,SATIR_1,Vakum_Kalibrasyonu_Yeri);
    Kayittan_Yazi_Yaz(0,SATIR_2,Manifold_Vanalari_Ac_Yeri);
    Kayittan_Yazi_Yaz(0,SATIR_3,Adaptorleri_Cikar_Yeri);
    
    for(ix = 0; ix < 3; ix ++)
    {
      Buzer_Ac;
      Bekle_ms(UZUN_BUZER);
      Buzer_Kapa;
      Bekle_ms(200);
    }    
    Kayittan_Yazi_Yaz(0,SATIR_4,Devam_Icin_ENT_Yeri);
    Kalibrasyon_Adimi = 1;
    _ms = EKM.MS;
  }
  if (Kalibrasyon_Adimi == 1)
  {
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Kalibrasyon_Adimi = 0;
      Kalibrasyon_Secim_Sayfa(2);
    }
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      Kalibrasyon_Adimi = 2;
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_1,Kalibrasyon_Bekleyin_Yeri);
      SSR_Kontrol(Alcak_Basinc_Valf_Ssr,AC);
      SSR_Kontrol(Yuksek_Basinc_Valf_Ssr,AC);
      Kalan_Sure_Goster(8, SATIR_4,0,0);  
      _ms = EKM.MS; 
       
    }
    if (EKM.Vakum_Boleni == 0)
      EKM.Vakum_Boleni = 1;
  }
  else if (Kalibrasyon_Adimi == 2)
  {
    if (HX_710_Oku(VAKUM, 27, &Vakum_Degeri))
    {
      if ((EKM.MS - _ms) > (10000))
      {
        Ortalama_Br += Vakum_Degeri;
        Okuma_Adet_Sayac++;
      }
      Lcd_Sayi_Yaz(1,SATIR_2,(int)(Vakum_Degeri/EKM.Vakum_Boleni),2,5);
      lcd.print("vac");
      Lcd_Sayi_Yaz(1,SATIR_3,(int)(EKM.Vakum_Boleni),2,5);
      lcd.print("VAC_G");
    }
    if ((EKM.MS - _ms) > 30000)
    {
      Kalibrasyon_Adimi = 3;
      Ilk_Deger = Ortalama_Br / Okuma_Adet_Sayac;
      Ortalama_Br = 0;
      Okuma_Adet_Sayac = 0;
      Kayittan_Yazi_Yaz(0,SATIR_1,Manifold_Vanalari_Kapa_Yeri);
      Kayittan_Yazi_Yaz(0,SATIR_4,Devam_Icin_ENT_Yeri);
    }

  }
  else if (Kalibrasyon_Adimi == 3)
  {
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_1,Kalibrasyon_Bekleyin_Yeri);
      Kalan_Sure_Goster(8, SATIR_4,0,0);  
      SSR_Kontrol(Vakum_Ssr,AC),
      Bekle_ms(500);
      SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,AC);
      SSR_Kontrol(Alcak_Basinc_Valf_Ssr,AC);
      SSR_Kontrol(Yuksek_Basinc_Valf_Ssr,AC);
      _ms = EKM.MS;
      Kalibrasyon_Adimi = 4;
    }        
  }
  else if (Kalibrasyon_Adimi == 4)
  {
    if (HX_710_Oku(VAKUM, 27, &Vakum_Degeri))
    {
      if ((EKM.MS - _ms) > 70000)
      {
        Ortalama_Br += (signed int)Vakum_Degeri;
        Okuma_Adet_Sayac++;
      }
      Lcd_Sayi_Yaz(1,SATIR_2,(int)(Vakum_Degeri/EKM.Vakum_Boleni),2,5);
      lcd.print("vac");
      Lcd_Sayi_Yaz(1,SATIR_3,(int)(EKM.Vakum_Boleni),2,5);
      lcd.print("VAC_G");       
    }
    if (Kalan_Sure_Goster(6, SATIR_4, 1, 30)) //// kontrol
    {
      Son_Deger = Ortalama_Br / Okuma_Adet_Sayac;
      Fark = Ilk_Deger - Son_Deger;
      SSR_Kontrol(IPTAL_ET,KAPAT);
      if (Fark > 0)
      {
        lcd.clear();      
        Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);    
         
        Buzer_Ac;
        EKM.Buzer_Calma_ms = UZUN_BUZER;
      }
      else
      {
        lcd.clear();
        Kayittan_Yazi_Yaz(1,SATIR_1,Kalibrasyon_Hatasi_Yeri);
        SSR_Kontrol(IPTAL_ET,KAPAT);
        Buzer_Ac;
        delay(1000);
        Buzer_Kapa;
        delay(1000);
        Buzer_Ac;
        delay(1000);
        Buzer_Kapa;

        Kalibrasyon_Secim_Sayfa(2);
        Kalibrasyon_Adimi = 0;
        Ortalama_Br = 0;
        Okuma_Adet_Sayac = 0;
        Vakum_Degeri = 0;
        Fark = 0;
        return;
      }
      EKM.Vakum_Boleni = (float)Fark / (float)EKM.Ref_Atm;
      Veri_Kaydet_Float(VAKUM_BOLEN_KAYIT_YERI, EKM.Vakum_Boleni);
      EKM.Vakum_Darasi = Son_Deger;
      Veri_Kaydet_Int(VAKUM_DARA_KAYIT_YERI,EKM.Vakum_Darasi);
      
      Kalibrasyon_Adimi = 5;
      
    }
  }
  else if (Kalibrasyon_Adimi == 5)
  {
    if(Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Kalibrasyon_Secim_Sayfa(2);
      Kalibrasyon_Adimi = 0;
      Ortalama_Br = 0;
      Okuma_Adet_Sayac = 0;
      Vakum_Degeri = 0;
      Fark = 0;
    }    
  }
}

void Kalibrasyon_Secimi(void)
{
  if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
    Ayar_Secim_Sayfa(2);
  }

  if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
    if (EKM.Imlec == 1)
    {
      Terazi_Kalibrasyon_Secimi();
    }
    else if (EKM.Imlec == 2)
    {
      Vakum_Kalibrasyonu();
    }
    else if (EKM.Imlec == 3)
    {
      Basinc_Kalibrasyon_Secimi();
    }
    else if (EKM.Imlec == 4)
    {
      Gaz_Tipi_Secimi();
    }

  }
  if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
    if(EKM.Imlec < 4)
    {
      EKM.Imlec ++;
      Imlec_Yaz(EKM.Imlec);
    }  
       
  }
  if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
  
    if (EKM.Imlec > 1)
    {
      EKM.Imlec --;
      Imlec_Yaz(EKM.Imlec);       
    }
  }
}

void Yazici_Secimi(void)
{
  static unsigned char Secim_Asamasi = 0;

  if(Secim_Asamasi == 0)
  {
    Secim_Asamasi = 1;
    lcd.clear();
    EKM.Sayfa = Yazici_Secim_Ayar_Sayfasi;
    Kayittan_Yazi_Yaz(1,SATIR_1,Yazici_Var_Mi_Yeri);
    Kayittan_Yazi_Yaz(1,SATIR_2,Evet_Yeri);
    Kayittan_Yazi_Yaz(1,SATIR_3,Hayir_Yeri);
    EKM.Imlec = 2;
    Imlec_Yaz(EKM.Imlec);
  }
  else if (Secim_Asamasi == 1)
  {
    if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
      if(EKM.Imlec < 3)
      {
        EKM.Imlec ++;
        Imlec_Yaz(EKM.Imlec);
      }  
        
    }
    if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
    
      if (EKM.Imlec > 2)
      {
        EKM.Imlec --;
        Imlec_Yaz(EKM.Imlec);       
      }
    }
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      Butonlari_Temizle();
      if (EKM.Imlec == 2)
      {
        Secim_Asamasi = 2;
        lcd.clear();
        Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
        EKM.Yazici = VAR;
        Veri_Kaydet_Uchar(YAZICI_DURUM_KAYIT_YERI,EKM.Yazici);
        Buzer_Ac;
        EKM.Buzer_Calma_ms = UZUN_BUZER;
      }
      else if (EKM.Imlec == 3)
      {
        Secim_Asamasi = 2;
        lcd.clear();
        Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
        EKM.Yazici = YOK;
        Veri_Kaydet_Uchar(YAZICI_DURUM_KAYIT_YERI,EKM.Yazici);
        Buzer_Ac;
        EKM.Buzer_Calma_ms = UZUN_BUZER;
      }
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Secim_Asamasi = 0;
      Servis_Ayar_Sayfa(1);
    }
      
  }
  else if (Secim_Asamasi == 2)
  {
    if(EKM.Buzer_Calma_ms == 0)
    {
      Secim_Asamasi = 0;
      Servis_Ayar_Sayfa(1);
    }
  }

}

void Tank_Kapasite_Ayari(void)
{
  static unsigned char Ayar_Asamasi = 0;
  unsigned char Islem_Durumu = 0;
  unsigned short Kapasite = 0;
  if(Ayar_Asamasi == 0)
  {
    EKM.Sayfa = Tank_Kapasite_Ayar_Sayfasi;
    Ayar_Asamasi = 1;
    Kapasite = EKM.Tank_Kapasitesi;
    lcd.clear();
    Kayittan_Yazi_Yaz(1,SATIR_1,Tank_Kapasitesi_Yeri);
    Sayi_Girisi(7,SATIR_3,&Kapasite,2);
  }
  else if (Ayar_Asamasi == 1)
  {
    Islem_Durumu = Sayi_Girisi(7,SATIR_3,&Kapasite,2);
    if(Islem_Durumu == 1)
    {
      lcd.clear();
      EKM.Tank_Kapasitesi = Kapasite;
      Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
      Veri_Kaydet_Uchar(TANK_KAPASITE_KAYIT_YERI,EKM.Tank_Kapasitesi);
      Ayar_Asamasi = 2;
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
    }
    else if(Islem_Durumu == 99)
    {
      lcd.clear();
      Ayar_Asamasi = 0;
      Servis_Ayar_Sayfa(2);
    }
  }
  else if (Ayar_Asamasi == 2)
  {
    if(EKM.Buzer_Calma_ms == 0)
    {
      Ayar_Asamasi = 0;
      Servis_Ayar_Sayfa(2);
    }
      
  }
}

void Filtre_Kapasite_Ayari(void)
{
  static unsigned char Ayar_Asamasi = 0;
  unsigned char Islem_Durumu = 0;
  static unsigned int Kullanilan_Filtre = 0;
  if(Ayar_Asamasi == 0)
  {
    Ayar_Asamasi = 1;
    EKM.Sayfa = Filtre_Kapasite_Ayar_Sayfasi;
    lcd.clear();
    Kullanilan_Filtre = EKM.Filtre_Kapasitesi_Kg * 1000;
    Kullanilan_Filtre -= EKM.Filtre_Kalan_Gr; 
    Kayittan_Yazi_Yaz(1,SATIR_1,Filtre_Kapasite_Yeri);
    Buyuk_Sayi_Gir(7,SATIR_3,&EKM.Filtre_Kapasitesi_Kg,3);
  }
  else if (Ayar_Asamasi == 1)
  {
    Islem_Durumu = Buyuk_Sayi_Gir(7,SATIR_3,&EKM.Filtre_Kapasitesi_Kg,3);
    if(Islem_Durumu == 1)
    {
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
      if ((EKM.Filtre_Kapasitesi_Kg * 1000) > Kullanilan_Filtre)
      {
        EKM.Filtre_Kalan_Gr = (EKM.Filtre_Kapasitesi_Kg * 1000) - Kullanilan_Filtre;
      }
      else
      {
        EKM.Filtre_Kalan_Gr = 0;
      }
      Veri_Kaydet_UInt(FILTRE_KALAN_KAPASITE_KAYIT_YERI,EKM.Filtre_Kalan_Gr);
      Veri_Kaydet_UInt(FILTRE_KAPASITE_KAYIT_YERI,EKM.Filtre_Kapasitesi_Kg);
      Ayar_Asamasi = 2;
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
    }
    else if(Islem_Durumu == 99)
    {
      lcd.clear();
      Ayar_Asamasi = 0;
      Eepromdan_Verileri_Al();
      Servis_Ayar_Sayfa(3);
    }
  }
  else if (Ayar_Asamasi == 2)
  {
    if(EKM.Buzer_Calma_ms == 0)
    {
      Ayar_Asamasi = 0;
      Eepromdan_Verileri_Al();
      Servis_Ayar_Sayfa(3);
    }
      
  }
}

void Kullanim_Sifirlama(void)
{
  lcd.clear();
  Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
  EKM.Son_Cekilen_Gr = 0;
  EKM.Filtre_Kalan_Gr = EKM.Filtre_Kapasitesi_Kg*1000;
  EKM.Filtre_Sayisi = 0;
  EKM.Toplam_Aractan_Cekilen_Gr = 0;
  EKM.Toplam_Tupten_Cekilen_Gr = 0;
  EKM.Toplam_Dolum_Gr = 0;
  EKM.Toplam_Vakum_Dk = 0;
  EKM.Seri_No = 0;

  Veri_Kaydet_Ushort(SON_CEKILEN_GAZ_YERI,EKM.Son_Cekilen_Gr);
  Veri_Kaydet_Ushort(FILTRE_SAYISI_YERI,EKM.Filtre_Sayisi);

  Veri_Kaydet_UInt(FILTRE_KALAN_KAPASITE_KAYIT_YERI,EKM.Filtre_Kalan_Gr);
  Veri_Kaydet_UInt(TOPLAM_ARACTAN_CEKILEN_KAYIT_YERI,EKM.Toplam_Aractan_Cekilen_Gr);
  Veri_Kaydet_UInt(TOPLAM_TUPTEN_CEKILEN_KAYIT_YERI,EKM.Toplam_Tupten_Cekilen_Gr);
  Veri_Kaydet_UInt(TOPLAM_GAZ_DOLUM_KAYIT_YERI,EKM.Toplam_Dolum_Gr);
  Veri_Kaydet_UInt(TOPLAM_VAKUM_SURE_KAYIT_YERI,EKM.Toplam_Vakum_Dk);
  Veri_Kaydet_UInt(SERI_NO_KAYIT_YERI, EKM.Seri_No);
  Bekle_ms(1000);
  Servis_Ayar_Sayfa(4);

}

void Servis_Ayar_Sayfa(unsigned char Imlec_Yeri)
{
  
  lcd.clear();
  Butonlari_Temizle();
  
  EKM.Imlec = Imlec_Yeri;
  Imlec_Yaz(EKM.Imlec);
  Kayittan_Yazi_Yaz(1,SATIR_1,Yazici_Ayari_Yeri);
  Kayittan_Yazi_Yaz(1,SATIR_2,Tank_Kapasite_Ayar_Yeri);
  Kayittan_Yazi_Yaz(1,SATIR_3,Filtre_Kapasite_Ayar_Yeri);
  Kayittan_Yazi_Yaz(1,SATIR_4,Kullanim_Sifirlama_Yeri);
  EKM.Sayfa = Servis_Ayar_Secim_Sayfasi;         
  Servis_Ayar_Secimi();
  
}

void Servis_Ayar_Secimi(void)
{
  if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
    Diger_Ayarlar_Secim_Sayfa(1);
  }
  if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
    if (EKM.Imlec == 1)
    {
      Yazici_Secimi();
    }
    else if (EKM.Imlec == 2)
    {
      Tank_Kapasite_Ayari();
    }
    else if (EKM.Imlec == 3)
    {
      Filtre_Kapasite_Ayari();
    }
    else if (EKM.Imlec == 4)
    {
      Kullanim_Sifirlama();
    }
  }
  if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
    EKM.Imlec_Yonu = ASAGI;
    if (EKM.Imlec < 4)
    {
      EKM.Imlec ++;
      Imlec_Yaz(EKM.Imlec);         
    }
  }
  if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
    EKM.Imlec_Yonu = YUKARI;
    if (EKM.Imlec > 1)
    {
      EKM.Imlec --;
      Imlec_Yaz(EKM.Imlec);         
    }
  }
}

void Servis_Ayar_Giris(void)
{
  static unsigned char Ayar_Giris_Adimi = 0;
  static unsigned int Sifre = 0;
  unsigned char Islem_Durumu = 0;
  if(Ayar_Giris_Adimi == 0)
  {
    lcd.clear();
    EKM.Sayfa = Servis_Giris_Sayfasi;
    Ayar_Giris_Adimi = 1;
    Sifre = 0;
    Kayittan_Yazi_Yaz( 3,SATIR_1,Sifreyi_Girin_Yeri);
    Buyuk_Sayi_Gir(7,SATIR_3,&Sifre,5);    
  }
  else if (Ayar_Giris_Adimi == 1)
  {
    Islem_Durumu = Buyuk_Sayi_Gir(7,SATIR_3,&Sifre,5);
    if(Islem_Durumu == TAMAMLANDI)
    {
      if(Sifre_Kontrol(Sifre))
      {
        Ayar_Giris_Adimi = 0;
        Servis_Ayar_Sayfa(1);        
      }
      else
      {
        lcd.clear();
        Kayittan_Yazi_Yaz(3,SATIR_1,Sifre_Yanlis_Yeri);
        Bekle_ms(2000);
        Ayar_Giris_Adimi = 0;
      }
    }
    else if (Islem_Durumu == IPTAL_ET)
    {
      Ayar_Giris_Adimi = 0;
      Diger_Ayarlar_Secim_Sayfa(1);
    }
  }
}

void Ekranda_Gr_Goster (signed int Gr)
{
  static unsigned int _ms  = 0;

  if((EKM.MS - _ms) > 100)
    {
      if(Gr < 0)
        Gr = 0;
      Lcd_Sayi_Yaz(7,SATIR_3,Gr,1,5);
      // Lcd_Sayi_Yaz(7,SATIR_4,EKM.Vakum_Br,1,5);
      _ms = EKM.MS;
    }
}

/**
 * @brief
 * @return unsigned char GAZ_VAR, GAZ_YOK, DEVAM_EDIYOR. Gaz var = Vac > Ref atm + 200
 */
unsigned char Sistemde_Gaz_Var_Mi(void)
{
  if(EKM.Vakum_Br > EKM.Ref_Atm + 200)
  {
    return GAZ_VAR;
  }
  else
  {
    return GAZ_YOK;
  }      
  return DEVAM_EDIYOR;
}

void Isitici_Kontrol(unsigned char Durum)
{
  static unsigned int _ms = 0;
  static unsigned char Kontrol_Asamasi = 0;

  if(Durum == ACIK)
  {
    Basinc_Oku(&EKM.Basinc_Br);

    if(Kontrol_Asamasi == 0)
    {
      _ms = EKM.MS;
      Kontrol_Asamasi = 1;
      SSR_Kontrol(Isitici_Ssr,AC);
    }
    else if (Kontrol_Asamasi == 1)
    {
      if((EKM.MS-_ms) > 180000)   //// 2dk 120000ms
      {
        _ms = EKM.MS;
        if(EKM.Basinc_Br >= 90)
        {
          SSR_Kontrol(Isitici_Ssr,KAPAT);
        }
        else if (EKM.Basinc_Br <= 70)
        {
          if (EKM.Sicaklik < 50)
          {
            SSR_Kontrol(Isitici_Ssr,AC);
          }
        }
      }
    }
  }
  else
  {
    Kontrol_Asamasi = 0;
    SSR_Kontrol(Isitici_Ssr,KAPAT);
  }
}

void Sicaklik_Oku(void)
{
  static unsigned int _ms = 0;
  if((EKM.MS - _ms) < 500)
    return;
  _ms = EKM.MS;
  Sicaklik_Sensoru.setWaitForConversion(0);
  Sicaklik_Sensoru.requestTemperatures(); 
  EKM.Sicaklik = Sicaklik_Sensoru.getTempCByIndex(0);
}

unsigned char Hava_Tahliye_Kontrol(void)
{
  static unsigned int _ms = 0;
  static unsigned char Tahliye_Asamasi = 0,Valf_Durumu = 0, Valf_Say = 0;
  unsigned char Basinc_Siniri = 0;
  float Basinc_Deg = 0;
  char Basinc_Tablosu[] = {
                  29,30,31,32,34,35,36,37,39,40,
                  41,43,44,46,47,49,50,52,54,55,
                  57,59,61,63,64,66,68,70,73,75,
                  77,79,81,84,86,89,91,94,96,99,
                  101,104,107,110,113,116,119,122,
                  125,128,131,135,138,142,145,149,
                  152,156,160,164,168,172 };
  Sicaklik_Oku();
  Basinc_Oku(&EKM.Basinc_Br);
  Basinc_Deg = EKM.Basinc_Br / 100; /// 1000 olması lazım. tablo 10 kat old. için 100e bolundu

  if(EKM.Sicaklik < 8)
    EKM.Sicaklik = 8;
  if(EKM.Sicaklik > 65) //// tablo 60 dereceye kadar. fazlasında stack taşması olur
    EKM.Sicaklik = 65;
  
  Basinc_Siniri = Basinc_Tablosu[EKM.Sicaklik];

  if(Tahliye_Asamasi == 0)
  {
    Valf_Say = 0;
    Valf_Durumu = KAPALI;

    if(Basinc_Deg < 80)
    {
      SSR_Kontrol(Hava_Tahliye_Valf_Ssr,KAPAT);
      SSR_Kontrol(Fan_Ssr,AC);
      SSR_Kontrol(Kompresor_Ssr,AC);
      SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,AC);
      
      return TAMAMLANDI;
    }
    Tahliye_Asamasi = 1;
  }
  else if(Tahliye_Asamasi == 1)
  {
    if(Basinc_Deg < 80)
    {
      SSR_Kontrol(Hava_Tahliye_Valf_Ssr,KAPAT);
      SSR_Kontrol(Fan_Ssr,AC);
      SSR_Kontrol(Kompresor_Ssr,AC);
      SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,AC);
      Tahliye_Asamasi = 0;
      return TAMAMLANDI;
    }
    if(Basinc_Deg > Basinc_Siniri + 5)    //// 0.5 bar buyukse
    {
      Tahliye_Asamasi = 2;
      lcd.clear();
      Kayittan_Yazi_Yaz(0,SATIR_1,Hava_Tahliyesi_Yeri);
      Kayittan_Yazi_Yaz(0,SATIR_2,Bekleyin_Yeri);
      
      SSR_Kontrol(Fan_Ssr,KAPAT);
      SSR_Kontrol(Kompresor_Ssr,KAPAT);
      SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,KAPAT);
      delay(100);
      SSR_Kontrol(Hava_Tahliye_Valf_Ssr,AC);
      Valf_Durumu = ACIK;
      _ms = EKM.MS;
      Lcd_Sayi_Yaz(7,SATIR_3,EKM.Basinc_Br,99,3);
      lcd.print("/");
      lcd.print(Basinc_Siniri / 10);
      lcd.print(".");
      lcd.print(Basinc_Siniri % 10);//Basinc_Tablosu[EKM.Sicaklik]
      return DEVAM_EDIYOR;
    }
    else
    {
      Tahliye_Asamasi = 0;

      SSR_Kontrol(Hava_Tahliye_Valf_Ssr,KAPAT);
      SSR_Kontrol(Fan_Ssr,AC);
      SSR_Kontrol(Kompresor_Ssr,AC);
      SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,AC);
      
      return TAMAMLANDI;
    }
  }
  else if(Tahliye_Asamasi == 2)
  {
    if(Basinc_Deg < 80)   //// 8,0bar
    {
      SSR_Kontrol(Hava_Tahliye_Valf_Ssr,KAPAT);
      SSR_Kontrol(Fan_Ssr,AC);
      SSR_Kontrol(Kompresor_Ssr,AC);
      SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,AC);
      Tahliye_Asamasi = 0;
      return TAMAMLANDI;
    }
    if(Basinc_Deg > Basinc_Siniri + 5)  ////0.5 bar yuksek ise
    {/// 300 ac 200 kapat, 200 aç 300 kapat.
      if((EKM.MS - _ms) > 200)
      {
        Valf_Say ++;
        if(Basinc_Deg > Basinc_Siniri + 40)
        {

        }
        else if(Basinc_Deg > Basinc_Siniri + 20)
        {
          if(Valf_Durumu == ACIK)
          {
            if(Valf_Say >= 2)
            {
              SSR_Kontrol(Hava_Tahliye_Valf_Ssr,KAPAT);
              Valf_Durumu = KAPALI;
              Valf_Say = 0;
            }
          }
          else
          {
            if(Valf_Say >= 1)
            {
              SSR_Kontrol(Hava_Tahliye_Valf_Ssr,AC);
              Valf_Durumu = ACIK;
              Valf_Say = 0;
            }
          }            
        }
        else 
        {
          if(Valf_Durumu == ACIK)
          {
            if(Valf_Say >= 1)
            {
              SSR_Kontrol(Hava_Tahliye_Valf_Ssr,KAPAT);
              Valf_Durumu = KAPALI;
              Valf_Say = 0;
            }
          }
          else
          {
            if(Valf_Say >= 2)
            {
              SSR_Kontrol(Hava_Tahliye_Valf_Ssr,AC);
              Valf_Durumu = ACIK;
              Valf_Say = 0;
            }
          }            
        }
        Lcd_Sayi_Yaz(7,SATIR_3,EKM.Basinc_Br,99,3);
        lcd.print("/");
        lcd.print(Basinc_Siniri / 10);
        lcd.print(".");
        lcd.print(Basinc_Siniri % 10);
        _ms = EKM.MS;
      }
      return DEVAM_EDIYOR;
    }
    else
    {
      Tahliye_Asamasi = 0;
      SSR_Kontrol(Hava_Tahliye_Valf_Ssr,KAPAT);
      SSR_Kontrol(Fan_Ssr,AC);
      SSR_Kontrol(Kompresor_Ssr,AC);
      SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,AC);
      return TAMAMLANDI;
    }
  }
  return DEVAM_EDIYOR;

}

unsigned char Hemen_Yag_Cek()
{
  static unsigned int _ms = 0;
  static unsigned char Yag_Cekme_Asamasi = 0;

  if(Yag_Cekme_Asamasi == 0)
    {
      SSR_Kontrol(Kompresor_Yag_Valf_Ssr,AC);
      _ms = EKM.MS;
      Yag_Cekme_Asamasi = 1;
    }
    else if (Yag_Cekme_Asamasi == 1)
    {
      if((EKM.MS-_ms) > 850)   //// 850 ms açık kalacak
      {
        SSR_Kontrol(Kompresor_Yag_Valf_Ssr,KAPAT);
        Yag_Cekme_Asamasi = 0;
        return TAMAMLANDI;
      }      
    }
    return DEVAM_EDIYOR;
}

void Yag_Cek_Kontrol(unsigned char Durum)
{
  static unsigned int _ms = 0;
  static unsigned char Yag_Cekme_Asamasi = 0,Valf_Durumu = 0;

  if(Durum == ACIK)
  {
    if(Yag_Cekme_Asamasi == 0)
    {
      _ms = EKM.MS;
      Valf_Durumu = KAPALI;
      Yag_Cekme_Asamasi = 1;
    }
    else if (Yag_Cekme_Asamasi == 1)
    {
      if(EKM.Vakum_Br < EKM.Ref_Atm)
        return;

      if(Valf_Durumu == KAPALI)
      {
        if((EKM.MS-_ms) > 120000)   //// 2dk 120000ms
        {
          Valf_Durumu = ACIK;
            SSR_Kontrol(Kompresor_Yag_Valf_Ssr,AC);
          _ms = EKM.MS;
        }
      }
      else
      {
        if((EKM.MS-_ms) > 850)   //// 850 ms açık kalacak
        {
          Valf_Durumu = KAPALI;
          SSR_Kontrol(Kompresor_Yag_Valf_Ssr,KAPAT);
          _ms = EKM.MS;
        }
      }
    }
  }
  else
  {
    Yag_Cekme_Asamasi = 0;
    Valf_Durumu = KAPALI;
    SSR_Kontrol(Kompresor_Yag_Valf_Ssr,KAPAT);
  }
}

unsigned char Emniyet(void)
{
  if(EKM.Basinc_Br > 20000)   /// 20bar
  {
    return BASINC_YUKSEK;
  }
  return DEVAM_EDIYOR;
}

unsigned char Kapasite_Kontrol(void)
{
  static unsigned int _ms = 0;
  static unsigned char Kontrol_Asamasi = 0;
  unsigned short Kapasite_Gr = 0;

  //Terazi_Oku(&EKM.Terazi_Gr);   /// buraya geldiği yerde okunuyor. 
  
  if(Kontrol_Asamasi == 0)
  {
    Kontrol_Asamasi = 1;
    _ms = EKM.MS;
  }
  else if(Kontrol_Asamasi == 1)
  {
    if((EKM.MS - _ms) > 1000)     /// 1sn sadece terazi okunsun.
    {
      Kontrol_Asamasi = 2;
      Kapasite_Gr = EKM.Tank_Kapasitesi*1000;
      if(EKM.Terazi_Gr > 0)
        Kapasite_Gr -= EKM.Terazi_Gr;

      if(EKM.Gaz_Cekilme_Yeri == TUPTEN_GAZ_CEKILIYOR)
      {
        if(Kapasite_Gr >= EKM.Cekilecek_Gaz_Miktari)    //// 500gr tolerans ekeldim. silinebilir
        {          
          return YER_VAR;
        }
        else
        {
          Kontrol_Asamasi = 0;
          return TANK_DOLU;
        }
      }
      else
      {
        if((Kapasite_Gr / 1000) <= EKM.Tank_Kapasitesi)  /// burada tolerans yok.!
        {          
          return YER_VAR;
        }
        else
        {
          return TANK_DOLU;
        }
      }
    }    
  }
  else if(Kontrol_Asamasi == 2)
  {
    if((EKM.MS - _ms) > 10000)     /// sn'1 kontrol
    {
      _ms = EKM.MS;
      Kontrol_Asamasi = 0;   
    } 
    else if((EKM.MS - _ms) > 5000)     /// sn'5 kontrol
    {
      _ms = EKM.MS;
      Kapasite_Gr = EKM.Tank_Kapasitesi*1000;
      if(EKM.Terazi_Gr > 0)
        Kapasite_Gr -= EKM.Terazi_Gr;

      if((Kapasite_Gr / 1000) <= EKM.Tank_Kapasitesi)  /// burada tolerans yok.!
      {          
        return YER_VAR;
      }
      else
      {
        return TANK_DOLU;
      }      
    }    
  }
  return DEVAM_EDIYOR;
}

unsigned char Gaz_Cekme_Hazirlik(void)
{
  static unsigned int _ms = 0;
  static unsigned char Hazirlik_Asamasi = 0, Islem_Durumu = 0;

  if(Hazirlik_Asamasi == 0)
  {
    EKM.Ilk_Terazi_Gr = EKM.Terazi_Gr;    /// kontrol.! terzi_gr önceki adımda süreklü okunuyor olmalı.
    _ms =  EKM.MS;
    SSR_Kontrol(Kompresor_Ssr,AC);    /// hava tahliyede açılmıştı.! sorulacak
    Hazirlik_Asamasi = 1;
  }
  else if(Hazirlik_Asamasi == 1)
  {
    if((EKM.MS - _ms) > 100)
    {
      Hazirlik_Asamasi = 2;
      SSR_Kontrol(Fan_Ssr,AC);       /// hava tahliyede açılmıştı.! sorulacak
      _ms = EKM.MS;
    }
  }
  else if(Hazirlik_Asamasi == 2)
  {
    if((EKM.MS - _ms) > 200)
    {
      Islem_Durumu = Hemen_Yag_Cek();
      if(Islem_Durumu == TAMAMLANDI)
      {
        Hazirlik_Asamasi = 3;
        _ms = EKM.MS;
      }        
    }
  }
  else if(Hazirlik_Asamasi == 3)
  {
    if((EKM.MS - _ms) > 100)
    {
      SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,AC);  /// hava tahliyede açılmıştı.! sorulacak
      Yag_Cek_Kontrol(ACIK);
      Hazirlik_Asamasi = 0;
      return TAMAMLANDI;
    }
  }
  return DEVAM_EDIYOR;
}

/**
 * @brief ilk okumada hata döner. Değeri 99.! ilk okumadan hız 99 gelir. Sn'de 99gr demek
 * @param Gaz_Miktari
 * @return unsigned short, HATAOLUSTU, Hız değeri. 
 */
unsigned short Hiz_Hesapla(signed int Gaz_Miktari)
{
  static unsigned int _ms = 0;
  unsigned short Hiz = 0;
  static unsigned short Onceki_Gaz_Miktari = 0;

  if((EKM.MS - _ms) > 2000)
  {
    _ms = EKM.MS;
    Onceki_Gaz_Miktari = Gaz_Miktari;
    return HATA_OLUSTU;
  }
  else if ((EKM.MS - _ms) > 1000)
  {
    _ms = EKM.MS;
    Hiz = Gaz_Miktari - Onceki_Gaz_Miktari;
    Onceki_Gaz_Miktari = Gaz_Miktari;
    return Hiz;
  }
  return HATA_OLUSTU;
}

unsigned char Gaz_Cekmeyi_Bitir(void)
{
  static unsigned int _ms = 0;
  static unsigned char Bitirme_Asamasi = 0, Valf_Durum = 0, Valf_Say = 0;
  unsigned short Gaz_Miktari = 0;
  if(Bitirme_Asamasi == 0)
  {
    _ms = EKM.MS;
    SSR_Kontrol(Fan_Ssr,KAPAT);
    Bitirme_Asamasi = 1;
  }
  else if(Bitirme_Asamasi == 1)
  {
    if((EKM.MS - _ms) > 250)
    {
      _ms = EKM.MS;
      SSR_Kontrol(Kompresor_Ssr,KAPAT);
      Bitirme_Asamasi = 2;      
    }
  }
  else if (Bitirme_Asamasi == 2)
  {
    if((EKM.MS - _ms) > 500)
    {
      if(EKM.Terazi_Gr >= EKM.Ilk_Terazi_Gr)
        Gaz_Miktari = EKM.Terazi_Gr - EKM.Ilk_Terazi_Gr;
      else
        Gaz_Miktari = 0;
      SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,KAPAT);      

      if(EKM.Gaz_Cekilme_Yeri == TUPTEN_GAZ_CEKILIYOR)
      {        
        SSR_Kontrol(IPTAL_ET,KAPAT);
        lcd.clear();      
        Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
        Lcd_Sayi_Yaz(7,SATIR_3,Gaz_Miktari,1,5);
        Buzer_Ac;
        EKM.Buzer_Calma_ms += UZUN_BUZER;
        Bitirme_Asamasi = 0;    

        return TAMAMLANDI;
      }
      else
      {    
        if(EKM.Vakum_Br > EKM.Ref_Atm + 200)
        {          
          SSR_Kontrol(IPTAL_ET,KAPAT);
          lcd.clear();      
          Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
          Lcd_Sayi_Yaz(7,SATIR_3,Gaz_Miktari,1,5);
          Buzer_Ac;
          EKM.Buzer_Calma_ms += UZUN_BUZER;
          
          Bitirme_Asamasi = 0;
          return TAMAMLANDI;
        }
        Bitirme_Asamasi = 3; 
      }      
    }
  }
  else if (Bitirme_Asamasi == 3)
  {   
    lcd.clear();
    Kayittan_Yazi_Yaz(1,SATIR_1,Eski_Yag_Tahliyesi_Yeri);
    Kayittan_Yazi_Yaz(0,SATIR_2,Bekleyin_Yeri);
    _ms = EKM.MS;
    SSR_Kontrol(Kompresor_Yag_Valf_Ssr,AC);  
    Bitirme_Asamasi = 4;  
  }
  else if (Bitirme_Asamasi == 4)
  {
    if((EKM.MS - _ms) > 600)
    {
      SSR_Kontrol(Kompresor_Yag_Valf_Ssr, KAPAT);
      _ms = EKM.MS;
      SSR_Kontrol(Eski_Yag_Valf_Ssr,AC);
      Bitirme_Asamasi = 5;
      Valf_Say = 1;
      Valf_Durum = ACIK;
    }
  }
  else if (Bitirme_Asamasi == 5)
  {
    if(Valf_Durum == ACIK)
    {
      if(Valf_Say < 25)
      {
        if((EKM.MS - _ms) > 750)
        {
          SSR_Kontrol(Eski_Yag_Valf_Ssr,KAPAT);
          Valf_Durum = KAPALI;
          _ms = EKM.MS;
        }
      }
      else 
      {
        if((EKM.MS - _ms) > 2000)
        {
          SSR_Kontrol(Eski_Yag_Valf_Ssr,KAPAT);
          Valf_Durum = KAPALI;
          Valf_Say = 0;
          _ms = EKM.MS;
          if(EKM.Gaz_Cekilme_Yeri == ARABADAN_GAZ_CEKILIYOR)
          {
            if(EKM.Terazi_Gr >= EKM.Ilk_Terazi_Gr)
              Gaz_Miktari = EKM.Terazi_Gr - EKM.Ilk_Terazi_Gr;
            else
              Gaz_Miktari = 0;
            SSR_Kontrol(IPTAL_ET,KAPAT);
            lcd.clear();      
            Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
            Lcd_Sayi_Yaz(7,SATIR_3,Gaz_Miktari,1,5);
            Buzer_Ac;
            EKM.Buzer_Calma_ms += UZUN_BUZER;
          }
          Bitirme_Asamasi = 0;
          return TAMAMLANDI;
        }
      }        
    }
    else
    {
      if((EKM.MS - _ms) > 1000)
      {
        SSR_Kontrol(Eski_Yag_Valf_Ssr,AC);
        Valf_Durum = ACIK;
        _ms = EKM.MS;
        Valf_Say++;
      }
    }
  }
  return DEVAM_EDIYOR;
}

unsigned char Hortum_Temizle(void)
{
  static unsigned int _ms = 0,Komoff_Sayac = 0,Baslama_Dk = 0;
  static unsigned char Temizleme_Asamasi = 0;
  unsigned char Islem_Durumu = 0;

  Vakum_Oku(&EKM.Vakum_Br);
  if(Temizleme_Asamasi == 0)
  {
    _ms = EKM.MS;
    Temizleme_Asamasi = 1;
  }
  else if(Temizleme_Asamasi == 1)
  {
    if((EKM.MS - _ms) > 3000)
    {
      if(EKM.Vakum_Br > EKM.Ref_Atm)
        Temizleme_Asamasi = 2;
      else
      {
        Buzer_Ac;
        EKM.Buzer_Calma_ms = UZUN_BUZER;
        SSR_Kontrol(IPTAL_ET,KAPAT);
        lcd.clear();
        Kayittan_Yazi_Yaz(0,SATIR_1,Cekilecek_Gaz_Yok_Yeri);
        Temizleme_Asamasi = 0;
        return TAMAMLANDI;
      }
    }
  }
  else if(Temizleme_Asamasi == 2)
  {
    Islem_Durumu = Gaz_Cekme_Hazirlik();
    if(Islem_Durumu == TAMAMLANDI)
    {
      Temizleme_Asamasi = 3;
      SSR_Kontrol(Gaz_Valf_Ssr,KAPAT);
      Yag_Cek_Kontrol(KAPALI);
      Baslama_Dk = EKM.Islem_Dk;
      Kalan_Sure_Goster(0,0,0,0);
    }
  }
  else if (Temizleme_Asamasi == 3)
  { 
    // if((EKM.MS - Ekran_ms) > 200)
    // {
    //   Ekran_ms = EKM.MS;
    //   Lcd_Sayi_Yaz(5,SATIR_3,EKM.Vakum_Br,1,5);
    //   lcd.print("/");
    //   lcd.print(EKM.Kompresor_Kapanma); 
    //   Kalan_Sure_Goster(6,SATIR_4,15,0);    
         
    // }

    if (EKM.Vakum_Br < EKM.Kompresor_Kapanma)   //// ref atm - komp fark ile bulunacak
    {
      //SSR_Kontrol(Kompresor_Ssr,KAPAT);/// dikkat. orjinalde Kapatmadı Sorulacak
      Komoff_Sayac++;
      if(Komoff_Sayac > 1000)
      {
      Kalan_Sure_Goster(6,SATIR_4,0,0);
        Temizleme_Asamasi = 4;
        _ms = EKM.MS;
        Komoff_Sayac = 0;
      }
      
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI) 
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Temizleme_Asamasi = 0;  
      SSR_Kontrol(IPTAL_ET,KAPAT);
      lcd.clear(); 
      Kayittan_Yazi_Yaz(1,SATIR_1,elcielektronik_com_Yeri);
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
      return ANA_MENU_DON;
    }
    if((EKM.Islem_Dk - Baslama_Dk) > 15)
    {
      Temizleme_Asamasi = 0;  
      SSR_Kontrol(IPTAL_ET,KAPAT);
      lcd.clear(); 
      Kayittan_Yazi_Yaz(1,SATIR_1,elcielektronik_com_Yeri);
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
      return ANA_MENU_DON;
    }
  }
  else if (Temizleme_Asamasi == 4)
  {
    // if((EKM.MS - Ekran_ms) > 200)
    // {
    //   Ekran_ms = EKM.MS;
    //   Lcd_Sayi_Yaz(5,SATIR_3,EKM.Vakum_Br,1,5);
    //   lcd.print("/");
    //   lcd.print(EKM.Kompresor_Kapanma);
    //   Kalan_Sure_Goster(6,SATIR_4,0,5);          
    // }
    if((EKM.MS - _ms) > 5000)
    {
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
      SSR_Kontrol(IPTAL_ET,KAPAT);
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
      Temizleme_Asamasi = 0;
      return TAMAMLANDI;
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI) 
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Temizleme_Asamasi = 0;  
      SSR_Kontrol(IPTAL_ET,KAPAT);
      lcd.clear(); 
      Kayittan_Yazi_Yaz(1,SATIR_1,elcielektronik_com_Yeri);
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
      return ANA_MENU_DON;
    }
  }
  return DEVAM_EDIYOR;
}

/**
 * @brief
 * @param Cekilecek_Yer
 * @return unsigned char, TAMAMLANDI, IPTAL_ET, DEVAM_EDIYOR, GAZ_YOK, ANA_MENU_DON
 */
unsigned char Gaz_Cek(unsigned char Cekilecek_Yer)
{
  static unsigned char Gaz_Durum = 0,Gaz_Cekme_Asamasi = Sifirlama,Temizle = 0;
  static unsigned int _ms = 0, Gaz_Cekme_ms = 0, kap_kontrol_ms = 0;
  static unsigned short Kompresor_Acilma_Yeri = 0;
  static signed int Cekilen_Gaz = 0;
  unsigned char Islem_Durumu = 0;

  Terazi_Oku(&EKM.Terazi_Gr);
  Vakum_Oku(&EKM.Vakum_Br);
  Basinc_Oku(&EKM.Basinc_Br);

  if(Gaz_Cekme_Asamasi == Sifirlama)      // gaz çekme başlangıç
  {    
    Gaz_Cekme_Asamasi = Gaz_Kontrolu;
    lcd.clear();
    Kayittan_Yazi_Yaz(7,SATIR_1,Islem_Yeri);
    Kayittan_Yazi_Yaz(0,SATIR_2,Yapiliyor_Bekleyin_Yeri);

    SSR_Kontrol(Yuksek_Basinc_Valf_Ssr,AC);
    SSR_Kontrol(Alcak_Basinc_Valf_Ssr,AC);    

    EKM.Gaz_Cekilme_Yeri = Cekilecek_Yer;
    _ms = EKM.MS;
    EKM.Ilk_Terazi_Gr = EKM.Terazi_Gr;
    Kompresor_Acilma_Yeri = EKM.Ref_Atm - 25;       ///// 25mBar çok az değil mi?? sorulacak
    return DEVAM_EDIYOR;
   // Lcd_Sayi_Yaz(7,SATIR_3,(EKM.Terazi_Gr-Ilk_Gaz_Gr),1,5);
  }
  else if (Gaz_Cekme_Asamasi == Gaz_Kontrolu)    // gaz var mı kontrol. Kontrol.!! Burada mı olacak? Butaya geldiğiyerde mi??
  {
    if((EKM.MS - _ms) < 3000)     /// 3sn gazı kontrol ediyoruz. 
    {
      Islem_Durumu = Sistemde_Gaz_Var_Mi();
      if (Islem_Durumu == GAZ_VAR)
      {
        if (Gaz_Durum < 250)
        {
          Gaz_Durum++;
          return DEVAM_EDIYOR;
        }          
      }
      else if (Islem_Durumu == GAZ_YOK)     
      {
        Gaz_Durum = 0;
        return DEVAM_EDIYOR;
      }
      else
      {
        return DEVAM_EDIYOR;
      }          
    }
    //////////// 3sn sonunda aşağı akar
    SSR_Kontrol(Yuksek_Basinc_Valf_Ssr,KAPAT);
    SSR_Kontrol(Alcak_Basinc_Valf_Ssr,KAPAT);
    SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,KAPAT);
    if (Gaz_Durum >= 20)      //// 3 sn'yede toplam 30 ölçüm alabilir. bu sayı 30'dan büyük olamaz. Sınırlama kalmış. büyük olabilir.!
    {     
      Gaz_Cekme_Asamasi = Kapasite_Kontrolu;   
      return DEVAM_EDIYOR;
    }
    else            //// geri döndüğü yerde işlemlere devam edilecek. Bu işlem artık bitti.
    {
      lcd.clear();
      Gaz_Cekme_Asamasi = Sifirlama;
      Gaz_Durum = 0;
      Islem_Durumu = 0;
      SSR_Kontrol(IPTAL_ET,KAPAT);    /// hepsini kapatır
      if(Cekilecek_Yer == TUPTEN_GAZ_CEKILIYOR)
      {
        Kayittan_Yazi_Yaz(0,SATIR_1,Cekilecek_Gaz_Yok_Yeri);
        Lcd_Sayi_Yaz(7,SATIR_3,0,1,5);
        Buzer_Ac;
        EKM.Buzer_Calma_ms += UZUN_BUZER;
      }
      return GAZ_YOK;
    }
    return DEVAM_EDIYOR;    
  }
  else if (Gaz_Cekme_Asamasi == Kapasite_Kontrolu)    
  {
    Islem_Durumu = Kapasite_Kontrol();
    if(Islem_Durumu == YER_VAR)
    {
      if(Hava_Tahliye_Kontrol() == TAMAMLANDI)
      {
        Gaz_Cekme_Asamasi = Hazirlik;
      }              
      _ms = EKM.MS;
    }
    else if(Islem_Durumu == TANK_DOLU)      //// gaz çekilemez. yer yok
    {
      Gaz_Cekme_Asamasi = Sifirlama;
      SSR_Kontrol(IPTAL_ET,KAPAT);  /// hepsini kapatır
      lcd.clear();
      Kayittan_Yazi_Yaz(6,SATIR_1,Tup_Dolu_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_2,Gaz_Cekilemez_Yeri);
      return ANA_MENU_DON;
    }
  }
  else if (Gaz_Cekme_Asamasi == Hazirlik)    
  {
    Islem_Durumu = Gaz_Cekme_Hazirlik();
    if(Islem_Durumu == TAMAMLANDI)
    {
      if(Cekilecek_Yer == TUPTEN_GAZ_CEKILIYOR)
      {
        lcd.clear();
        Kayittan_Yazi_Yaz(0,SATIR_1,Islem_Yapiliyor_Yeri);
      }
      else
      {
        lcd.clear();
        Kayittan_Yazi_Yaz(0,SATIR_1,Islem_Yapiliyor_Yeri);
      }
      Gaz_Cekme_Asamasi = Gaz_Cekimi;
      _ms = EKM.MS;
      Gaz_Cekme_ms = EKM.MS;
    }
  }
  else if (Gaz_Cekme_Asamasi == Gaz_Cekimi)    // gaz bitene kadar bekleme ve kontrol.
  {
    Cekilen_Gaz = EKM.Terazi_Gr - EKM.Ilk_Terazi_Gr; 
    if(Cekilen_Gaz < 0)
      Cekilen_Gaz = 0;
      //kap_kontrol_ms = EKM.MS;

    //if((EKM.MS - kap_kontrol_ms) < 3000){Kapasite_Kontrol();Buzer_Ac;delay(75);Buzer_Kapa;delay(75) kap_kontrol_ms = EKM.MS; } 
    Ekranda_Gr_Goster(Cekilen_Gaz);
    
    if(Kapasite_Kontrol() == TANK_DOLU)
    {
      Gaz_Cekme_Asamasi = Gaz_Cekme_Bitir;
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
      SSR_Kontrol(IPTAL_ET,KAPAT);  /// hepsini kapatır
      lcd.clear();
      Kayittan_Yazi_Yaz(6,SATIR_1,Tup_Dolu_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_2,Gaz_Cekilemez_Yeri);
      Bekle_ms(EKM.Buzer_Calma_ms);
      return DEVAM_EDIYOR;
    }
    if(Buton[Yukari_Buton].Durum == 1)
    {
      Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
      Lcd_Sayi_Yaz(5,SATIR_4,(signed int)EKM.Vakum_Br,1,4);
      lcd.print("/");
      Lcd_Sayi_Yaz(10,SATIR_4,(signed int)EKM.Kompresor_Kapanma,1,4);
      Temizle = 1;
    }
    else
    {
      if(Temizle == 1)
      {
        Temizle = 0;
        Yazi_Yaz(0,SATIR_4,"                   ",19);
      }
    }
    
    if(Cekilecek_Yer == TUPTEN_GAZ_CEKILIYOR)
    {
      if(Cekilen_Gaz >= EKM.Cekilecek_Gaz_Miktari)
      {
        Gaz_Cekme_Asamasi = Sifirlama;  
        EKM.Son_Cekilen_Gr = Cekilen_Gaz;
        Veri_Kaydet_Ushort(SON_CEKILEN_GAZ_YERI,EKM.Son_Cekilen_Gr);
        EKM.Toplam_Tupten_Cekilen_Gr += Cekilen_Gaz;
        Veri_Kaydet_UInt(TOPLAM_TUPTEN_CEKILEN_KAYIT_YERI,EKM.Toplam_Tupten_Cekilen_Gr);
        SSR_Kontrol(Kompresor_Ssr,KAPAT);
        SSR_Kontrol(Yuksek_Basinc_Valf_Ssr,KAPAT);
        SSR_Kontrol(Alcak_Basinc_Valf_Ssr,KAPAT);
        SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,KAPAT);
        SSR_Kontrol(Fan_Ssr,KAPAT);  
        lcd.clear();
        Buzer_Ac;
        EKM.Buzer_Calma_ms = UZUN_BUZER;
        return TAMAMLANDI;
      }
    }
    Islem_Durumu = Sistemde_Gaz_Var_Mi();  
    Yag_Cek_Kontrol(ACIK);
    if(Emniyet() == BASINC_YUKSEK)
    {
      Gaz_Cekme_Asamasi = Sifirlama;

      SSR_Kontrol(IPTAL_ET,KAPAT);
      lcd.clear();
      Kayittan_Yazi_Yaz(0,SATIR_1,Tup_Basinci_Yuksek_Yeri);
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
      if(Cekilecek_Yer == TUPTEN_GAZ_CEKILIYOR)
      {
        EKM.Son_Cekilen_Gr = Cekilen_Gaz;
        Veri_Kaydet_Ushort(SON_CEKILEN_GAZ_YERI,EKM.Son_Cekilen_Gr);
        EKM.Toplam_Tupten_Cekilen_Gr += Cekilen_Gaz;
        Veri_Kaydet_UInt(TOPLAM_TUPTEN_CEKILEN_KAYIT_YERI,EKM.Toplam_Tupten_Cekilen_Gr);
      }
      else
      {
        if(EKM.Filtre_Kalan_Gr > Cekilen_Gaz)
          EKM.Filtre_Kalan_Gr -= Cekilen_Gaz;
        else
          EKM.Filtre_Kalan_Gr = 0;

        Veri_Kaydet_UInt(FILTRE_KALAN_KAPASITE_KAYIT_YERI,EKM.Filtre_Kalan_Gr);
        EKM.Toplam_Aractan_Cekilen_Gr+=Cekilen_Gaz;
        Veri_Kaydet_UInt(TOPLAM_ARACTAN_CEKILEN_KAYIT_YERI,EKM.Toplam_Aractan_Cekilen_Gr);
      }
      Yag_Cek_Kontrol(KAPALI);    
      return ANA_MENU_DON;
    }

    if (Islem_Durumu == GAZ_VAR)
    {
      Gaz_Durum = 200;
      if((EKM.MS - Gaz_Cekme_ms) > GAZ_CEKME_ISLEM_ZAMAN_SINIRI)   //// basınc düşmüyor. İptal yada geçiş gerekli. hız kontrol edilecek!!
      {
        if(Hiz_Hesapla(Cekilen_Gaz) < 5)      
        {
          Kayittan_Yazi_Yaz(1,SATIR_4,Devam_Icin_ENT_Bas_Yeri);
          Gaz_Cekme_Asamasi = Gaz_Cekim_Iptal_Secenegi;
        }        
      }
      return DEVAM_EDIYOR;
    }
    else if (Islem_Durumu == GAZ_YOK)
    {
      if(Gaz_Durum)
      {
        Gaz_Durum --;
        return DEVAM_EDIYOR;
      }
      if(EKM.Vakum_Br < EKM.Ref_Atm)
      {
  //      if((EKM.MS - Gaz_Cekme_ms) > GAZ_CEKME_ZAMAN_SINIRI)   //// basınc düştü ama yeterli değil. Daha fazla düşmüyor.
  //      {
          Kayittan_Yazi_Yaz(1,SATIR_4,Devam_Icin_ENT_Bas_Yeri);
          Gaz_Cekme_Asamasi = Gaz_Cekim_Iptal_Secenegi;
  //      }
      }
      if (EKM.Vakum_Br < EKM.Kompresor_Kapanma)   //// ref atm - komp fark ile bulunacak
      {
        SSR_Kontrol(Kompresor_Ssr,KAPAT);
        Gaz_Cekme_Asamasi = Buharlasma_Bekle;
        _ms = EKM.MS;
      }
    }
    else
    {
      return DEVAM_EDIYOR;
    } 
    return DEVAM_EDIYOR;
  }
  else if (Gaz_Cekme_Asamasi == Buharlasma_Bekle)    /// gaz çekme işleminden çıkılabilmesi için ara adım. 
  {
    Cekilen_Gaz = EKM.Terazi_Gr - EKM.Ilk_Terazi_Gr;
    if(Cekilen_Gaz < 0)
      Cekilen_Gaz = 0;
    Ekranda_Gr_Goster(Cekilen_Gaz);

    if(Cekilecek_Yer == TUPTEN_GAZ_CEKILIYOR)
    {
      if(Cekilen_Gaz >= EKM.Cekilecek_Gaz_Miktari)
      {
        Gaz_Cekme_Asamasi = Sifirlama;  
        EKM.Son_Cekilen_Gr = Cekilen_Gaz;
        Veri_Kaydet_Ushort(SON_CEKILEN_GAZ_YERI,EKM.Son_Cekilen_Gr);
        EKM.Toplam_Tupten_Cekilen_Gr += Cekilen_Gaz;
        Veri_Kaydet_UInt(TOPLAM_TUPTEN_CEKILEN_KAYIT_YERI,EKM.Toplam_Tupten_Cekilen_Gr);
        SSR_Kontrol(Kompresor_Ssr,KAPAT);
        SSR_Kontrol(Yuksek_Basinc_Valf_Ssr,KAPAT);
        SSR_Kontrol(Alcak_Basinc_Valf_Ssr,KAPAT);
        SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,KAPAT);
        SSR_Kontrol(Fan_Ssr,KAPAT);  
        Yag_Cek_Kontrol(KAPALI);
        lcd.clear();
        return TAMAMLANDI;
      }
    }

    if((EKM.MS - _ms) > BUHARLASMA_BEKLEME_SURESI)
    {
      Gaz_Cekme_Asamasi = Gaz_Cekme_Bitir;
      _ms = EKM.MS;
    }
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      Gaz_Cekme_Asamasi = Gaz_Cekme_Bitir;  
      Butonlari_Temizle();
      _ms = EKM.MS;
  
      return DEVAM_EDIYOR;
    }

    if (EKM.Vakum_Br > Kompresor_Acilma_Yeri)   //// ref atm - komp fark ile bulunacak
    {
      SSR_Kontrol(Kompresor_Ssr,AC);
      Gaz_Cekme_Asamasi = Gaz_Cekimi;
      Gaz_Cekme_ms = EKM.MS;
    }
    return DEVAM_EDIYOR;
  }
  else if (Gaz_Cekme_Asamasi == Gaz_Cekme_Bitir)
  {
    Islem_Durumu = Gaz_Cekmeyi_Bitir();
    if(Islem_Durumu == TAMAMLANDI)
    {
      Gaz_Cekme_Asamasi = Bitirme_Beklemesi;  
      _ms = EKM.MS;
      Islem_Durumu = 0;  
      Yazilacaklar.Cekilen_Gr = Cekilen_Gaz;
      EKM.Son_Cekilen_Gr = Cekilen_Gaz;
      Veri_Kaydet_Ushort(SON_CEKILEN_GAZ_YERI,EKM.Son_Cekilen_Gr);
      if(EKM.Gaz_Cekilme_Yeri == TUPTEN_GAZ_CEKILIYOR)
      {
        EKM.Toplam_Tupten_Cekilen_Gr += Cekilen_Gaz;
        Veri_Kaydet_UInt(TOPLAM_TUPTEN_CEKILEN_KAYIT_YERI,EKM.Toplam_Tupten_Cekilen_Gr);
      }
      else
      {
        if(Cekilen_Gaz < 0)
          Cekilen_Gaz = 0;

        if(EKM.Filtre_Kalan_Gr > Cekilen_Gaz)
          EKM.Filtre_Kalan_Gr -= Cekilen_Gaz;
        else
          EKM.Filtre_Kalan_Gr = 0;

        Veri_Kaydet_UInt(FILTRE_KALAN_KAPASITE_KAYIT_YERI,EKM.Filtre_Kalan_Gr);
        EKM.Toplam_Aractan_Cekilen_Gr+=Cekilen_Gaz;
        Veri_Kaydet_UInt(TOPLAM_ARACTAN_CEKILEN_KAYIT_YERI,EKM.Toplam_Aractan_Cekilen_Gr);
      }
      Yag_Cek_Kontrol(KAPALI);
    }

  }
  else if (Gaz_Cekme_Asamasi == Bitirme_Beklemesi)
  {
    if((EKM.MS - _ms) > UZUN_BUZER)
    {
      Gaz_Cekme_Asamasi = Sifirlama;
      return TAMAMLANDI;
    }
  }
  else if (Gaz_Cekme_Asamasi == Gaz_Cekim_Iptal_Secenegi)    /// gaz çekme işleminden çıkılabilmesi için ara adım. 
  {
    Cekilen_Gaz = EKM.Terazi_Gr - EKM.Ilk_Terazi_Gr;
    if(Cekilen_Gaz < 0)
      Cekilen_Gaz = 0;
    Ekranda_Gr_Goster(Cekilen_Gaz);
    if (EKM.Vakum_Br < EKM.Kompresor_Kapanma)   //// ref atm - komp fark ile bulunacak
    {
      SSR_Kontrol(Kompresor_Ssr,KAPAT);
      Gaz_Cekme_Asamasi = Buharlasma_Bekle;
      _ms = EKM.MS;
    }
    if(Cekilecek_Yer == TUPTEN_GAZ_CEKILIYOR)
    {
      if(Cekilen_Gaz >= EKM.Cekilecek_Gaz_Miktari)
      {
        Gaz_Cekme_Asamasi = Sifirlama;  
        Yazilacaklar.Cekilen_Gr = Cekilen_Gaz;
        EKM.Son_Cekilen_Gr = Cekilen_Gaz;
        Veri_Kaydet_Ushort(SON_CEKILEN_GAZ_YERI,EKM.Son_Cekilen_Gr);
        if(EKM.Gaz_Cekilme_Yeri == TUPTEN_GAZ_CEKILIYOR)
        {
          EKM.Toplam_Tupten_Cekilen_Gr += Cekilen_Gaz;
          Veri_Kaydet_UInt(TOPLAM_TUPTEN_CEKILEN_KAYIT_YERI,EKM.Toplam_Tupten_Cekilen_Gr);
        }
        else
        {
          if(Cekilen_Gaz < 0)
          Cekilen_Gaz = 0;

          if(EKM.Filtre_Kalan_Gr > Cekilen_Gaz)
            EKM.Filtre_Kalan_Gr -= Cekilen_Gaz;
          else
            EKM.Filtre_Kalan_Gr = 0;

          Veri_Kaydet_UInt(FILTRE_KALAN_KAPASITE_KAYIT_YERI,EKM.Filtre_Kalan_Gr);
          EKM.Toplam_Aractan_Cekilen_Gr+=Cekilen_Gaz;
          Veri_Kaydet_UInt(TOPLAM_ARACTAN_CEKILEN_KAYIT_YERI,EKM.Toplam_Aractan_Cekilen_Gr);
        }
        SSR_Kontrol(Kompresor_Ssr,KAPAT);
        SSR_Kontrol(Yuksek_Basinc_Valf_Ssr,KAPAT);
        SSR_Kontrol(Alcak_Basinc_Valf_Ssr,KAPAT);
        SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,KAPAT);
        SSR_Kontrol(Fan_Ssr,KAPAT);  
        Yag_Cek_Kontrol(KAPALI);
        lcd.clear();
        return TAMAMLANDI;
      }
    }

    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;        
      lcd.clear();
      if(EKM.Gaz_Cekilme_Yeri == ARABADAN_GAZ_CEKILIYOR)
      {
        if(EKM.Vakum_Suresi_Dk > 0)
        {
          Gaz_Cekme_Asamasi = Gaz_Cekim_Iptal_Sorgusu;
          lcd.clear();
          Kayittan_Yazi_Yaz(0,SATIR_1,Sistemde_Gaz_Olabilir_Yeri);
          Kayittan_Yazi_Yaz(0,SATIR_2,Saatleri_Kontrol_Edin_Yeri);
          Kayittan_Yazi_Yaz(0,SATIR_3,Cikis_Yeri);
          Kayittan_Yazi_Yaz(0,SATIR_4,ESC_Yeri);
          Kayittan_Yazi_Yaz(11,SATIR_3,Devam_Yaz_Yeri);
          Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
        }
        else
        {
          Gaz_Cekme_Asamasi = Gaz_Cekme_Bitir;
        }
        
      }
      else
      {
        Gaz_Cekme_Asamasi = Gaz_Cekme_Bitir;         
      }
      
    }
    Islem_Durumu = Sistemde_Gaz_Var_Mi();
    if (Islem_Durumu == 1)
    {
      Gaz_Durum = 200;
      return DEVAM_EDIYOR;
    }
    else if (Islem_Durumu == 0)
    {
      if(Gaz_Durum)
      {
        Gaz_Durum --;
        return DEVAM_EDIYOR;
      }
    }
    else
    {
      return DEVAM_EDIYOR;
    }
    Gaz_Cekme_Asamasi = Gaz_Cekme_Bitir;  
  }
  else if (Gaz_Cekme_Asamasi == Gaz_Cekim_Iptal_Sorgusu)    /// İptal-Devam sorgulama 
  {
    Cekilen_Gaz = EKM.Terazi_Gr - EKM.Ilk_Terazi_Gr;
    if(Cekilen_Gaz < 0)
      Cekilen_Gaz = 0;
    Ekranda_Gr_Goster(Cekilen_Gaz);
    if (EKM.Vakum_Br < EKM.Kompresor_Kapanma)   //// ref atm - komp fark ile bulunacak
    {
      SSR_Kontrol(Kompresor_Ssr,KAPAT);
      Gaz_Cekme_Asamasi = Buharlasma_Bekle;
      _ms = EKM.MS;
    }
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI) /// sonraki adıma geçer.
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;        
      Gaz_Cekme_Asamasi = Gaz_Cekme_Bitir;  
      return DEVAM_EDIYOR;
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI) /// işlemi iptal eder. Son defa sormaya gider.
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      lcd.clear();
      Kayittan_Yazi_Yaz(0,SATIR_2,Islem_Iptal_Edilsin_mi_Yeri);
      Kayittan_Yazi_Yaz(0,SATIR_4,Hayir_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Evet_Yeri);
      Gaz_Cekme_Asamasi = Gaz_Cekim_Iptal_Onayi;
    }

    Islem_Durumu = Sistemde_Gaz_Var_Mi();
    if (Islem_Durumu == 1)
    {
      Gaz_Durum = 200;
      return DEVAM_EDIYOR;
    }
    else if (Islem_Durumu == 0)
    {
      if(Gaz_Durum)
      {
        Gaz_Durum --;
        return DEVAM_EDIYOR;
      }
    }
    else
    {
      return DEVAM_EDIYOR;
    }
    Gaz_Cekme_Asamasi = Gaz_Cekme_Bitir;  
   
  }
  else if (Gaz_Cekme_Asamasi == Gaz_Cekim_Iptal_Onayi)    /// Iptal için son onay
  {
    Cekilen_Gaz = EKM.Terazi_Gr - EKM.Ilk_Terazi_Gr;
    if(Cekilen_Gaz < 0)
      Cekilen_Gaz = 0;
    Ekranda_Gr_Goster(Cekilen_Gaz);

    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI) /// iptal eder.
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;        
      Gaz_Cekme_Asamasi = Sifirlama;

      Yazilacaklar.Cekilen_Gr = Cekilen_Gaz;
      EKM.Son_Cekilen_Gr = Cekilen_Gaz;
      Veri_Kaydet_Ushort(SON_CEKILEN_GAZ_YERI,EKM.Son_Cekilen_Gr);

      if(Cekilen_Gaz < 0)
          Cekilen_Gaz = 0;

      if(EKM.Filtre_Kalan_Gr > Cekilen_Gaz)
        EKM.Filtre_Kalan_Gr -= Cekilen_Gaz;
      else
        EKM.Filtre_Kalan_Gr = 0;

      Veri_Kaydet_UInt(FILTRE_KALAN_KAPASITE_KAYIT_YERI,EKM.Filtre_Kalan_Gr);
      EKM.Toplam_Aractan_Cekilen_Gr+=Cekilen_Gaz;
      Veri_Kaydet_UInt(TOPLAM_ARACTAN_CEKILEN_KAYIT_YERI,EKM.Toplam_Aractan_Cekilen_Gr);
      Yag_Cek_Kontrol(KAPALI);
      SSR_Kontrol(IPTAL_ET,KAPAT);  
      lcd.clear();
      return IPTAL_ET;
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI) /// geri sorgulama adımına döner.
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      lcd.clear();
      Gaz_Cekme_Asamasi = Gaz_Cekim_Iptal_Secenegi;
      Kayittan_Yazi_Yaz(0,SATIR_1,Sistemde_Gaz_Olabilir_Yeri);
      Kayittan_Yazi_Yaz(0,SATIR_2,Saatleri_Kontrol_Edin_Yeri);
      Kayittan_Yazi_Yaz(0,SATIR_3,Cikis_Yeri);
      Kayittan_Yazi_Yaz(0,SATIR_4,ESC_Yeri);
      Kayittan_Yazi_Yaz(11,SATIR_3,Devam_Yaz_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
    }
    Islem_Durumu = Sistemde_Gaz_Var_Mi();
    if (Islem_Durumu == 1)
    {
      Gaz_Durum = 200;
      return DEVAM_EDIYOR;
    }
    else if (Islem_Durumu == 0)
    {
      if(Gaz_Durum)
      {
        Gaz_Durum --;
        return DEVAM_EDIYOR;
      }
    }
    else
    {
      return DEVAM_EDIYOR;
    }
    Gaz_Cekme_Asamasi = Gaz_Cekme_Bitir;  
  }
  
  return DEVAM_EDIYOR;
}

unsigned char Islem_Yazdir(void)
{
  static unsigned char  Yazdirma_Asamasi = 0;
  unsigned char Sayi_Giris_Durumu = 0;
  char Printer_Yazilacak[50] = {0};
  char Printer_Buff[22] = {0};
  if (Yazdirma_Asamasi == 0)
  {
    Sayi_Giris_Durumu = Plaka_Gir();
    if (Sayi_Giris_Durumu == 1)
    {
      lcd.clear();
      Yazdirma_Asamasi = 1;
      //Kayittan_Yazi_Yaz(6,SATIR_1,Sira_No_Yeri);
    }
    else if (Sayi_Giris_Durumu == 99)
    {
      Butonlari_Temizle();
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
      Yazdirma_Asamasi = 0;       
      return YAZDIRMA_SOR;   
    }
  }
  else if (Yazdirma_Asamasi == 1)
  {
    // Sayi_Giris_Durumu = Buyuk_Sayi_Gir(6, SATIR_3, &EKM.Seri_No, 6);

    // if (Sayi_Giris_Durumu == 1)
    // {
      // Veri_Kaydet_UInt(SERI_NO_KAYIT_YERI, EKM.Seri_No);
      if (EKM.E_Seri_No == EKM.Seri_No)
      {
        Seri_No_Arttir();
      }
      lcd.clear();

      Kayittan_Yazi_Yaz(0, SATIR_1,Yazdiriliyor_Yeri);      /// toplam 900ms delay beklemesi var
      
      Printer_Ayarla(0, 27, 64);
      delay(200);
      Printer_Ayarla(29, 33, 1);
      Printer_Ayarla(27, 74, 50);

      Printer_Yazdir(EKM.Cihaz_Adi, 13, 10);
      delay(100);
      Zaman_Al(&Rtc_Zamani);

      Printer_Ayarla(29, 33, 0);
      Printer_Ayarla(27, 74, 20);

      Printer_Yazdir(Dil_Listesi[(Yapilan_Islemler_Yeri*DIL_SAYISI)+EKM.Dil], 13, 10);
      delay(100);
      Printer_Yazilacak[0] = (Rtc_Zamani.Gun / 10) + 48;
      Printer_Yazilacak[1] = (Rtc_Zamani.Gun % 10) + 48;

      Printer_Yazilacak[2] = '/';

      Printer_Yazilacak[3] = (Rtc_Zamani.Ay / 10) + 48;
      Printer_Yazilacak[4] = (Rtc_Zamani.Ay % 10) + 48;

      Printer_Yazilacak[5] = '/';

      Printer_Yazilacak[6] = (Rtc_Zamani.Yil / 10) + 48;
      Printer_Yazilacak[7] = (Rtc_Zamani.Yil % 10) + 48;

      Printer_Yazilacak[8] = ' ';

      Printer_Yazilacak[9] = (Rtc_Zamani.Saat / 10) + 48;
      Printer_Yazilacak[10] = (Rtc_Zamani.Saat % 10) + 48;

      Printer_Yazilacak[11] = ':';

      Printer_Yazilacak[12] = (Rtc_Zamani.Dk / 10) + 48;
      Printer_Yazilacak[13] = (Rtc_Zamani.Dk % 10) + 48;

      Printer_Yazilacak[14] = ':';

      Printer_Yazilacak[15] = (Rtc_Zamani.Sn / 10) + 48;
      Printer_Yazilacak[16] = (Rtc_Zamani.Sn % 10) + 48;

      Printer_Yazdir(Printer_Yazilacak, 13, 10);

      memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
      memset(Printer_Buff, 0x00, strlen(Printer_Buff));
      strcat(Printer_Yazilacak,Dil_Listesi[(Sira_No_Yeri*DIL_SAYISI)+EKM.Dil]);
      sprintf(Printer_Buff,"%d ", EKM.Seri_No);
      strcat(Printer_Yazilacak,Printer_Buff);
      Printer_Yazdir(Printer_Yazilacak, 13, 10);
      delay(100);

      memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
      memset(Printer_Buff, 0x00, strlen(Printer_Buff));
      strcat(Printer_Yazilacak,Dil_Listesi[(Vakum_Dk_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
      sprintf(Printer_Buff, "%d ", Yazilacaklar.Vakum_Dk);
      strcat(Printer_Yazilacak,Printer_Buff);
      strcat(Printer_Yazilacak,Dil_Listesi[(Dak_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
      Printer_Yazdir(Printer_Yazilacak, 13, 10);
      delay(100);

      memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
      memset(Printer_Buff, 0x00, strlen(Printer_Buff));
      strcat(Printer_Yazilacak,Dil_Listesi[(Kacak_Dk_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
      sprintf(Printer_Buff, "%d ", Yazilacaklar.Kacak_Dk);
      strcat(Printer_Yazilacak,Printer_Buff);
      strcat(Printer_Yazilacak,Dil_Listesi[(Dak_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
      Printer_Yazdir(Printer_Yazilacak, 13, 10);
      delay(100);
      
      memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
      memset(Printer_Buff, 0x00, strlen(Printer_Buff));
      strcat(Printer_Yazilacak,Dil_Listesi[(Yeni_Yag_ml_Yeri*DIL_SAYISI)+EKM.Dil]);
      if(EKM.Yag_Dolumu == 1)
        strcat(Printer_Yazilacak,Dil_Listesi[(Evet_Yeri*DIL_SAYISI)+EKM.Dil]);
      else
        strcat(Printer_Yazilacak,Dil_Listesi[(Hayir_Yeri*DIL_SAYISI)+EKM.Dil]);

      //strcat(Printer_Yazilacak,Gr_Yaz_Yeri);
      Printer_Yazdir(Printer_Yazilacak, 13, 10);
      delay(100);

      // memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
      // strcat(Printer_Yazilacak,Dil_Listesi[UV_Yag_ml_Yeri*DIL_SAYISI]);
      // // if(Yag_Dolumu == 1)
      // //   strcat(Printer_Yazilacak,Evet_Yeri);
      // // else
      //   strcat(Printer_Yazilacak,Dil_Listesi[Hayir_Yeri*DIL_SAYISI]);

      // //strcat(Printer_Yazilacak,Gr_Yaz_Yeri);
      // Printer_Yazdir(Printer_Yazilacak, 13, 10);
      // delay(100);

      // memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
      // strcat(Printer_Yazilacak,Dil_Listesi[Hibrit_Yag_ml_Yeri*DIL_SAYISI]);
      // // if(Yag_Dolumu == 1)
      // //   strcat(Printer_Yazilacak,Evet_Yeri);
      // // else
      //   strcat(Printer_Yazilacak,Dil_Listesi[Hayir_Yeri*DIL_SAYISI]);

      // //strcat(Printer_Yazilacak,Gr_Yaz_Yeri);
      // Printer_Yazdir(Printer_Yazilacak, 13, 10);
      // delay(100);

      memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
      strcat(Printer_Yazilacak,Dil_Listesi[(Doldurulan_Gaz_gr_Yeri*DIL_SAYISI)+EKM.Dil]);
      sprintf(Printer_Buff, "%d ", Yazilacaklar.Dolan_Gr);
      strcat(Printer_Yazilacak,Printer_Buff);
      strcat(Printer_Yazilacak,Dil_Listesi[(Gr_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
      Printer_Yazdir(Printer_Yazilacak, 13, 10);
      delay(100);

      memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
      strcat(Printer_Yazilacak,Dil_Listesi[(Cekilen_Gaz_gr_Yeri*DIL_SAYISI)+EKM.Dil]);
      sprintf(Printer_Buff, "%d ", Yazilacaklar.Cekilen_Gr);
      strcat(Printer_Yazilacak,Printer_Buff);
      strcat(Printer_Yazilacak,Dil_Listesi[(Gr_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
      Printer_Yazdir(Printer_Yazilacak, 13, 10);
      delay(100);

      memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
      strcat(Printer_Yazilacak,Dil_Listesi[(Plaka_Yeri*DIL_SAYISI)+EKM.Dil]);
      strcat(Printer_Yazilacak,Yazilacaklar.Plaka);
      Printer_Yazdir(Printer_Yazilacak, 13, 10);
      delay(100);
      
      memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));

      Printer_Ayarla(27, 74, 200);
      delay(100);
      // Yazdirildi = 1;
      Butonlari_Temizle();
      Yazdirma_Asamasi = 2;    
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_1,Tekrar_Yazdir_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
      //Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,Geri_Yaz_Yeri);    
    // }
    // else if (Sayi_Giris_Durumu == 99)
    // {
    //   Butonlari_Temizle();
    //   lcd.clear();
    //   Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
    //   Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
    //   Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);
    //   Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
    //   Yazdirma_Asamasi = 0;       
    //   return YAZDIRMA_SOR;   
    // }
  }
  else if (Yazdirma_Asamasi == 2)
  {
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      // Giris_Sayfa(1,1);
      Yazdirma_Asamasi = 0;
      Butonlari_Temizle();      
      return YAZDIRMA_SOR;
    }
    else if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      Butonlari_Temizle();
      lcd.clear();
      // Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
      // Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      // Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);
      // Kayittan_Yazi_Yaz(16,SATIR_4,Ent_Yeri);
      Yazdirma_Asamasi = 0;
      return DEVAM_EDIYOR;
    }
  }
  return DEVAM_EDIYOR;
}

void Seri_No_Arttir(void)
{
  EKM.Seri_No += 1;
  if (EKM.Seri_No > 999999)
    EKM.Seri_No = 1;
  Veri_Kaydet_UInt(SERI_NO_KAYIT_YERI, EKM.Seri_No);
}

void Aractan_Gaz_Cek(void)
{
  static unsigned char Gaz_Cekme_Asamasi = 0;
  static unsigned int _ms = 0;
  unsigned char Islem_Durumu = 0;

  Terazi_Oku(&EKM.Terazi_Gr);
  if (Gaz_Cekme_Asamasi == Sifirlama)
  {
    memset(&Yazilacaklar, 0, sizeof(Yazilacaklar));
    Gaz_Cekme_Asamasi = Sistemden_Gaz_Cekme;
    EKM.Vakum_Suresi_Dk = 0;
    EKM.Kacak_Suresi_Dk = 0;
    EKM.Dolum_Miktari_Gr = 0;
    EKM.Sayfa = Aractan_Gaz_Cekme_Sayfasi;
    EKM.E_Seri_No = EKM.Seri_No;
    _ms = 0;
  }
  else if (Gaz_Cekme_Asamasi == Sistemden_Gaz_Cekme)	      
  {                                                          
    Islem_Durumu = Gaz_Cek(ARABADAN_GAZ_CEKILIYOR);
    if(Islem_Durumu == TAMAMLANDI)     /// gaz çekme işlemi tamamlandı.
    {              
      lcd.clear();
      // Buzer_Ac;      //// gazcek'd ötüyor
      // EKM.Buzer_Calma_ms = UZUN_BUZER;
      if(Kapasite_Kontrol() == TANK_DOLU)
      {
        Kayittan_Yazi_Yaz(6,SATIR_1,Tup_Dolu_Yeri);
      }
      else
      {
        Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
      }
      if(Yazilacaklar.Cekilen_Gr >= 0)
      {
        Lcd_Sayi_Yaz(7,SATIR_2,Yazilacaklar.Cekilen_Gr,1,5);
        Yazi_Yaz(13,SATIR_2,"GR",2);
      }
      if(EKM.Yazici == VAR)
      {
        Gaz_Cekme_Asamasi = Yazdirma_Sorgusu;
        Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
        Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
        Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);
        Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
      }
      else
      {
        Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
        Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
        Kayittan_Yazi_Yaz(13,SATIR_3,E_Posta_Yeri);
        Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
        Gaz_Cekme_Asamasi = Mail_Sorgusu;
      }                
    }
    else if (Islem_Durumu == IPTAL_ET) 
    {
      if(EKM.Yazici == VAR)
      {
        Gaz_Cekme_Asamasi = Yazdirma_Sorgusu;
        lcd.clear();
        Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
        Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
        Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);
        Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
      }
      else
      {
        lcd.clear();
        Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
        Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
        Kayittan_Yazi_Yaz(13,SATIR_3,E_Posta_Yeri);
        Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
        Gaz_Cekme_Asamasi = Mail_Sorgusu;
      }
    }
    else if (Islem_Durumu == GAZ_YOK) //// çekilecek gaz yok
    {
      Gaz_Cekme_Asamasi = Anamenu_Beklemesi;
      _ms = EKM.MS;
      Kayittan_Yazi_Yaz(0,SATIR_1,Cekilecek_Gaz_Yok_Yeri);
      Lcd_Sayi_Yaz(7,SATIR_3,0,1,5);
      Buzer_Ac;
      EKM.Buzer_Calma_ms += UZUN_BUZER;

    }
    else if (Islem_Durumu == ANA_MENU_DON)
    {
      Gaz_Cekme_Asamasi = Cikis_Bekle;
    }
  }
  else if (Gaz_Cekme_Asamasi == Yazdirma_Sorgusu)   /// sadece yazıcı var ise buraya gelebilir
  {
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      Butonlari_Temizle();
      Gaz_Cekme_Asamasi = Yazdirma_Secimi;
      lcd.clear();
      Kayittan_Yazi_Yaz(0,SATIR_3,E_Posta_ve_Yazdir_Yeri);
    }
    else if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Butonlari_Temizle();
      Gaz_Cekme_Asamasi = Sifirlama;
      Giris_Sayfa(1,1);
    }
  }
  else if (Gaz_Cekme_Asamasi == Yazdirma_Secimi)  // sadece yazıcı varsa buraya gelir, o yuzden geri basılırsa yazdırma sorgusuna gidebilir
  {
    if (Buton[Sag_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Sag_Buton].Olay = OLAYI_TEMIZLE;
      Gaz_Cekme_Asamasi = Islem_Yazdirma;
      lcd.clear();
    }
    else if (Buton[Sol_Buton].Olay == BASILDI_OLAYI)
     {
       Buton[Sol_Buton].Olay = OLAYI_TEMIZLE;
       Gaz_Cekme_Asamasi = Plaka_Girisi;
       lcd.clear();
       Kayittan_Yazi_Yaz(1,SATIR_1,Plaka_Yeri);
     }
     else if(Buton[Geri_Buton].Olay == BASILDI_OLAYI)
     {
      Gaz_Cekme_Asamasi = Yazdirma_Sorgusu;
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
     }
  }
  else if (Gaz_Cekme_Asamasi == Islem_Yazdirma)
  {
    Islem_Durumu = Islem_Yazdir();
    if(Islem_Durumu == YAZDIRMA_SOR)
    {
      lcd.clear();
      Gaz_Cekme_Asamasi = Yazdirma_Sorgusu;
      Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
    }
    // else if (Islem_Durumu == ANA_MENU_DON)    //// kullanılmıyor
    // {
    //   Gaz_Cekme_Asamasi = Sifirlama;
    //    Giris_Sayfa(1,1);
    // }
  } 
  else if (Gaz_Cekme_Asamasi == Plaka_Girisi)
  {
    Islem_Durumu = Plaka_Gir();
    if(Islem_Durumu == 1)
    {
      lcd.clear();
      Gaz_Cekme_Asamasi = Mail_Atma;
      // Kayittan_Yazi_Yaz(6,SATIR_1,Sira_No_Yeri);
    }
    else if (Islem_Durumu == 99)
    {
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
      if(EKM.Yazici == VAR)
      {
        Gaz_Cekme_Asamasi = Yazdirma_Sorgusu;
        Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);
      }
      else
      {
        Kayittan_Yazi_Yaz(13,SATIR_3,E_Posta_Yeri);
        Gaz_Cekme_Asamasi = Mail_Sorgusu;
      }
    }
  }
  // else if (Gaz_Cekme_Asamasi == Seri_No_Girisi)
  // {
  //   Islem_Durumu = Buyuk_Sayi_Gir(6, SATIR_3, &EKM.Seri_No, 6);
  //   if(Islem_Durumu == 1)
  //   {
  //     lcd.clear();
  //     Veri_Kaydet_UInt(SERI_NO_KAYIT_YERI, EKM.Seri_No);
  //     Gaz_Cekme_Asamasi = Mail_Atma;
  //   }
  //   else if (Islem_Durumu == 99)
  //   {
  //     lcd.clear();
  //     Kayittan_Yazi_Yaz(1,SATIR_1,Plaka_Yeri);
  //     Gaz_Cekme_Asamasi = Plaka_Girisi;
  //   }
  // }
  else if (Gaz_Cekme_Asamasi == Mail_Sorgusu)   // sadece yazıcı yoksa buraya gelebilir. email attıktan sonra ekrana gereli yazılar yazılıp bu adıma yönlenecek
  {
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      Gaz_Cekme_Asamasi = Plaka_Girisi;
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_1,Plaka_Yeri);
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
     {
       Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
       Gaz_Cekme_Asamasi = Sifirlama;
       Butonlari_Temizle();
       Giris_Sayfa(1,1);
     }
  }
  else if (Gaz_Cekme_Asamasi == Mail_Atma)
  {
    Islem_Durumu = Mail_Gonderme();
    if((Islem_Durumu == TAMAMLANDI) || (Islem_Durumu == IPTAL_ET) || (Islem_Durumu == HATA_OLUSTU))
    {
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
      if(EKM.Yazici == VAR)
      {
        Gaz_Cekme_Asamasi = Yazdirma_Sorgusu;
        Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);
      }
      else
      {
        Kayittan_Yazi_Yaz(13,SATIR_3,E_Posta_Yeri);
        Gaz_Cekme_Asamasi = Mail_Sorgusu;
      }
    }
  }
  else if (Gaz_Cekme_Asamasi == Anamenu_Beklemesi)
  {
    if((EKM.MS - _ms) > UZUN_BUZER)
      {
        Gaz_Cekme_Asamasi = Sifirlama;
        Giris_Sayfa(1,1);    
      }
  } 
  else if (Gaz_Cekme_Asamasi == Cikis_Bekle)
  {
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
     {
       Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
       Gaz_Cekme_Asamasi = Sifirlama;
       Butonlari_Temizle();
       Giris_Sayfa(1,1);
     }
  }    
}

void Tupten_Gaz_Cek(void)
{
  static unsigned char Gaz_Cekme_Asamasi = 0;
  static unsigned int _ms = 0;
  unsigned char Islem_Durumu = 0;
  unsigned int Kapasite_Gr = 0;
 // Terazi_Oku(&EKM.Terazi_Gr);

  if (Gaz_Cekme_Asamasi == Sifirlama)
  {
    lcd.clear();
    Kayittan_Yazi_Yaz(0,SATIR_1,Gaz_Miktari_Sor_Yeri);
    Gaz_Cekme_Asamasi = Miktar_Giris;
    Kapasite_Gr = EKM.Tank_Kapasitesi * 1000;
    Kayittan_Yazi_Yaz(1,SATIR_3,Tank_Kap_Yeri);
    Kayittan_Yazi_Yaz(1,SATIR_4,Bos_Alan_Yeri);
    Lcd_Sayi_Yaz(12,SATIR_3,(EKM.Tank_Kapasitesi* 1000) ,1,5);
    Lcd_Sayi_Yaz(12,SATIR_4,(Kapasite_Gr - EKM.Terazi_Gr),1,5);
    EKM.Cekilecek_Gaz_Miktari = Kapasite_Gr - EKM.Terazi_Gr;
    EKM.Vakum_Suresi_Dk = 0;
    EKM.Kacak_Suresi_Dk = 0;
    EKM.Dolum_Miktari_Gr = 0;
    _ms = 0;
    EKM.Sayfa = Tupten_Gaz_Cekme_Sayfasi;
  }
  else if (Gaz_Cekme_Asamasi == Miktar_Giris)
  {
    Islem_Durumu = Sayi_Girisi(7,SATIR_2,&EKM.Cekilecek_Gaz_Miktari,5);
    if(Islem_Durumu == 1)
    {
      Kayittan_Yazi_Yaz(0,SATIR_1,Lutfen_Bekleyin_Yeri);
      Islem_Durumu = 0;
      Gaz_Cekme_Asamasi = Sistemden_Gaz_Cekme;
    }
    else if (Islem_Durumu == 99)
    {
      Gaz_Cekme_Asamasi = Sifirlama;
      Islem_Durumu = 0;
      Butonlari_Temizle();
      Giris_Sayfa(1,3);
    }
    
  }
  else if (Gaz_Cekme_Asamasi == Sistemden_Gaz_Cekme)	      
  {                                                          
    Islem_Durumu = Gaz_Cek(TUPTEN_GAZ_CEKILIYOR);
    if(Islem_Durumu == TAMAMLANDI)     /// gaz çekme işlemi tamamlandı.
    {    
      lcd.clear();
      if(Kapasite_Kontrol() == TANK_DOLU)
      {
        Kayittan_Yazi_Yaz(6,SATIR_1,Tup_Dolu_Yeri);
      }
      else
      {
        Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
      }
      Lcd_Sayi_Yaz(7,SATIR_2,EKM.Son_Cekilen_Gr,1,5);
      Yazi_Yaz(13,SATIR_2,"GR",2);
              
      // Buzer_Ac;          // gaz cek'de ötüyor
      // EKM.Buzer_Calma_ms = UZUN_BUZER;
      Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      Gaz_Cekme_Asamasi = Cikis_Bekle;      
    }
    else if (Islem_Durumu == GAZ_YOK) //// çekilecek gaz yok
    {
      Gaz_Cekme_Asamasi =Cikis_Bekle;// Anamenu_Beklemesi;
      _ms = EKM.MS;
      
    }
    else if (Islem_Durumu == ANA_MENU_DON) //// tank dolu
    {
      Gaz_Cekme_Asamasi = Cikis_Bekle;
      _ms = EKM.MS;
     
    }
  }
  else if (Gaz_Cekme_Asamasi == Anamenu_Beklemesi)
  {
    if((EKM.MS - _ms) > UZUN_BUZER)
      {
        Gaz_Cekme_Asamasi = Sifirlama;
        Giris_Sayfa(1,3);
      }
  }   
  else if (Gaz_Cekme_Asamasi == Cikis_Bekle)
  {
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
     {
       Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
       Gaz_Cekme_Asamasi = Sifirlama;
       Butonlari_Temizle();
       Giris_Sayfa(1,3);
     }
  } 
}

/**
 * @brief
 * @warning iptal etme dönmez.
 * @return unsigned char, TAMAMLANDI, VAKUM_DUSUK, DEVAM_EDIYOR
 */
unsigned char Vakum_Yap(void)
{
  static unsigned char Vakum_Asamasi = 0, Islem_Durumu = 0,Islem_Baslama_Dk = 0;
  static unsigned int _ms = 0;
  //static unsigned short Vakum_Suresi = 0;   //// ekm.vakum süresi olabilir. !?? kontrol
  signed int Vakum_Deg = 0;

  Vakum_Oku(&EKM.Vakum_Br);

  if (Vakum_Asamasi == 0)     //// vakum başlangıç ve sıfırlama
  {
    Vakum_Asamasi = 1;
  //  Vakum_Suresi = EKM.Vakum_Suresi_Dk;

    SSR_Kontrol(Vakum_Ssr,AC);
   // Vakum_ms = EKM.MS;
    Veri_Kaydet_Short(VAKUM_SURE_KAYIT_YERI,EKM.Vakum_Suresi_Dk);
    _ms = EKM.MS;
    lcd.clear();
    Kayittan_Yazi_Yaz(0,SATIR_1,Lutfen_Bekleyin_Yeri);
    Kayittan_Yazi_Yaz(1,SATIR_2,Vakum_Yapiliyor_Yeri); 
    Kayittan_Yazi_Yaz(15,SATIR_3,Atla_Yeri);
    Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
    Islem_Baslama_Dk = EKM.Islem_Dk; 
    Kalan_Sure_Goster(0,0,0,0);
  }
  else if (Vakum_Asamasi == 1)
  {
    if((EKM.MS - _ms) > 500)
    {
      SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,AC);
      SSR_Kontrol(Alcak_Basinc_Valf_Ssr,AC);
      SSR_Kontrol(Yuksek_Basinc_Valf_Ssr,AC);
      Vakum_Asamasi = 2;
    }
  }
  else if (Vakum_Asamasi == 2)
  {
    Islem_Durumu = Kalan_Sure_Goster(6,SATIR_4,EKM.Vakum_Suresi_Dk,0);

    if(Islem_Durumu == DEVAM_EDIYOR)
    {
      Vakum_Deg = (EKM.Vakum_Br-50)/10;
      if(Vakum_Deg < 0)
        Vakum_Deg = 0;

      if((EKM.MS - _ms) > 200)
      {
        _ms = EKM.MS;
        if(Buton[Yukari_Buton].Durum == 1)
        {
          Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
          Lcd_Sayi_Yaz(8,SATIR_3,(signed int)EKM.Vakum_Br,1,3);
        }
        else
        {
          Yazi_Yaz(8,SATIR_3,"%",1);
          Lcd_Sayi_Yaz(9,SATIR_3,Vakum_Deg,1,3);
        }
        
      }
      if(Buton[Giris_Buton].Olay == BASILDI_OLAYI)
      {
        Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
        Vakum_Asamasi = 3;
      }

    }
    else if (Islem_Durumu == TAMAMLANDI)
    {
      Vakum_Asamasi = 3;
    }
  }
  else if (Vakum_Asamasi == 3)
  {
    EKM.Toplam_Vakum_Dk += (EKM.Islem_Dk - Islem_Baslama_Dk);
    Veri_Kaydet_UInt(TOPLAM_VAKUM_SURE_KAYIT_YERI,EKM.Toplam_Vakum_Dk);
    Yazilacaklar.Vakum_Dk = EKM.Islem_Dk - Islem_Baslama_Dk;
    Isitici_Kontrol(KAPALI);
    SSR_Kontrol(Vakum_Ssr,KAPAT);
    SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,KAPAT);
    Vakum_Asamasi = 0;

    if(EKM.Vakum_Br < 100)
    {
      return TAMAMLANDI;
    }
    else
    {
      return VAKUM_DUSUK;
    }
  }
  return DEVAM_EDIYOR;
}

unsigned char Bakim_Kontrol(void)
{
  static unsigned int _ms = 0;
  static unsigned char Bakim_Kontrol_Asamasi = 0;

  if(Bakim_Kontrol_Asamasi == 0)
  {
    Bakim_Kontrol_Asamasi = 1;
    EKM.Vakum_Bakim_Dk = VAKUM_BAKIM_SAATI * 60;
    EKM.Toplam_Vakum_Dk = EEPROM.readUInt(TOPLAM_VAKUM_SURE_KAYIT_YERI); 

    if(EKM.Toplam_Vakum_Dk >= VAKUM_BAKIM_SAATI * 60)
    {
      _ms = EKM.MS;      
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
      lcd.clear();
      Kayittan_Yazi_Yaz(5,SATIR_1,Uyari_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_2,Vakum_PYagi_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_3,Degistirme_Zamani_Yeri);
      Lcd_Sayi_Yaz(1,SATIR_4,EKM.Toplam_Vakum_Dk,1,4);
      Bekle_ms(1000);
    }
  }
  else if (Bakim_Kontrol_Asamasi == 1)
  {
    if((EKM.MS - _ms) > 5000)
    {
      if(EKM.Filtre_Kalan_Gr <= 0)
      {
        Bakim_Kontrol_Asamasi = 0;
        return FILTRE_BITMIS;        
      }
      else if(EKM.Filtre_Kalan_Gr <= 20000)
      {
        Bakim_Kontrol_Asamasi = 0;
        return FILTRE_AZ;
      }
      else
      {
        Bakim_Kontrol_Asamasi = 0;
        return TAMAMLANDI;
      }
    }
  }
  return DEVAM_EDIYOR;
  
}

unsigned char Yag_Ekle(void)
{
  static unsigned char Yag_Ekleme_Asamasi = 0, Ssr_Durum = 0;
  unsigned char Sayac = 0;
  static unsigned int _ms = 0, uyari_ms = 0;

  if(Yag_Ekleme_Asamasi == 0)
  {
    lcd.clear();
    SSR_Kontrol(IPTAL_ET,KAPAT);
    Yag_Ekleme_Asamasi = 1;
    Kayittan_Yazi_Yaz(0,SATIR_1,Yeni_Yag_Doldurun_Yeri);
    Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
    for(Sayac = 0; Sayac < 9; Sayac ++)
    {
      Buzer_Ac;
      Bekle_ms(10);
      Buzer_Kapa;
      Bekle_ms(90);
    } 
    _ms = EKM.MS; 
    uyari_ms = EKM.MS; 
  }
  else if(Yag_Ekleme_Asamasi == 1)
  {
    if (Buton[Yukari_Buton].Durum == 1)
    { 
      if(Ssr_Durum == 0)
      {
        SSR_Kontrol(Yeni_Yag_Valf_Ssr,AC);
        Ssr_Durum = 1;
      }     
      uyari_ms = EKM.MS;
    }
    else
    {
      if(Ssr_Durum == 1)
      {
        if((EKM.MS - _ms)>370)
        {
          SSR_Kontrol(Yeni_Yag_Valf_Ssr,KAPAT);
          Ssr_Durum = 0;
        }
      }
      else
      {
        _ms = EKM.MS;
      }
      
    }
    if((EKM.MS - uyari_ms) > 3000)
    {
      Buzer_Ac;
      EKM.Buzer_Calma_ms = 500;
      uyari_ms = EKM.MS;
    }
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      Buzer_Kapa;
      Yag_Ekleme_Asamasi = 0;
      SSR_Kontrol(Yeni_Yag_Valf_Ssr,KAPAT);
      Ssr_Durum = 0;
      return TAMAMLANDI;
    }
  }
  return DEVAM_EDIYOR;
}

unsigned char Gaz_Doldur(void)
{
  static unsigned char Gaz_Doldurma_Asamasi = 0, Hiz_Yavas = 0;
  unsigned char Islem_Durumu = 0;
  static unsigned int _ms = 0;
  static signed int Doldurulan_Gr = 0;
  unsigned short Hiz = 0;

  if(Gaz_Doldurma_Asamasi == 0)
  {
    lcd.clear();
    Veri_Kaydet_Ushort(DOLUM_MIKTAR_KAYIT_YERI,EKM.Dolum_Miktari_Gr);
    if(EKM.Dolum_Miktari_Gr == 0)
    {
      return TAMAMLANDI;
    }

    EKM.Ilk_Terazi_Gr = EKM.Terazi_Gr;
    Kayittan_Yazi_Yaz(1,SATIR_1,Dolum_Yapiliyor_Yeri);
    Kayittan_Yazi_Yaz(0,SATIR_2,Bekleyin_Yeri);
    SSR_Kontrol(Gaz_Valf_Ssr,AC);
    Isitici_Kontrol(ACIK);
    Gaz_Doldurma_Asamasi = 1;
    Doldurulan_Gr = 0;
    Lcd_Sayi_Yaz(7,SATIR_3,Doldurulan_Gr,1,0);
  }
  else if (Gaz_Doldurma_Asamasi == 1)
  {
    Doldurulan_Gr = EKM.Ilk_Terazi_Gr - EKM.Terazi_Gr ;
    if(Doldurulan_Gr < 0)
      Doldurulan_Gr = 0;

    Hiz = Hiz_Hesapla(Doldurulan_Gr);

    if(Hiz < 10)
    {
      Hiz_Yavas ++;
    }
    else
    {
      if(Hiz != HATA_OLUSTU)
      {
        if(Hiz_Yavas)
        {
          Hiz_Yavas --;
        } 
      }
    }
    Ekranda_Gr_Goster(Doldurulan_Gr);

    if(Doldurulan_Gr + 20 >= EKM.Dolum_Miktari_Gr)
    {
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
      if(Doldurulan_Gr + 20 >= EKM.Dolum_Miktari_Gr)
        Doldurulan_Gr = EKM.Dolum_Miktari_Gr;
      Lcd_Sayi_Yaz(7,SATIR_3,Doldurulan_Gr,1,5);    /// ekranda gr göster 100ms'de bir yazar. Direkt olarak yazması için bu şekilde yapıldı
      _ms = EKM.MS;
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
      SSR_Kontrol(Gaz_Valf_Ssr,KAPAT);
      SSR_Kontrol(IPTAL_ET,KAPAT);
      Isitici_Kontrol(KAPALI);
      Gaz_Doldurma_Asamasi = 2;
      
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
      Lcd_Sayi_Yaz(7,SATIR_3,Doldurulan_Gr,1,5);
      _ms = EKM.MS;
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
      SSR_Kontrol(Gaz_Valf_Ssr,KAPAT);
      SSR_Kontrol(IPTAL_ET,KAPAT);
      Gaz_Doldurma_Asamasi = 2;
    }
    if(Hiz_Yavas >= 30) /// 30 sn boyunca düşük hız demek
    {
      Kayittan_Yazi_Yaz(0,SATIR_1,A_C_Calistirin_Yeri);
      Kayittan_Yazi_Yaz(0,SATIR_2,Kirmizi_Vanayi_Kapatin_Yeri);
      Buzer_Ac;
      EKM.Buzer_Calma_ms = 500;
      Hiz_Yavas = 0;
    }           
  }
  else if (Gaz_Doldurma_Asamasi == 2)
  {
    if((EKM.MS - _ms) > 2000)
    {
      Kayittan_Yazi_Yaz(1,SATIR_2,H_Temizle_ve_Gaz_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      Gaz_Doldurma_Asamasi = 3;
    }
  }
  else if (Gaz_Doldurma_Asamasi == 3)
  {
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;

      Yazilacaklar.Dolan_Gr = Doldurulan_Gr;
      EKM.Toplam_Dolum_Gr += Doldurulan_Gr;
      Veri_Kaydet_Int(TOPLAM_GAZ_DOLUM_KAYIT_YERI,EKM.Toplam_Dolum_Gr);
      Gaz_Doldurma_Asamasi = 0;
      return TAMAMLANDI;

    }
    if (Buton[Sol_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Sol_Buton].Olay = OLAYI_TEMIZLE;
      Yazilacaklar.Dolan_Gr = Doldurulan_Gr;
      EKM.Toplam_Dolum_Gr += Doldurulan_Gr;
      Veri_Kaydet_Int(TOPLAM_GAZ_DOLUM_KAYIT_YERI,EKM.Toplam_Dolum_Gr);
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_1,Hortum_Temizleme_1_Yeri);
      Gaz_Doldurma_Asamasi = 4;
    }
    if (Buton[Sag_Buton].Durum == 1)
    {
      Buton[Sag_Buton].Olay = OLAYI_TEMIZLE;
      SSR_Kontrol(Alcak_Basinc_Valf_Ssr,AC);
      SSR_Kontrol(Gaz_Valf_Ssr,AC);
      Doldurulan_Gr = EKM.Ilk_Terazi_Gr - EKM.Terazi_Gr;
      if(Doldurulan_Gr < 0)
        Doldurulan_Gr = 0;
      Ekranda_Gr_Goster(Doldurulan_Gr);
    }
    else
    {
      SSR_Kontrol(IPTAL_ET,KAPAT);
    }
  }
  else if (Gaz_Doldurma_Asamasi == 4)
  {
    Islem_Durumu = Hortum_Temizle();
    if(Islem_Durumu == ANA_MENU_DON)
    {
      Gaz_Doldurma_Asamasi = 0;
    }
    else if (Islem_Durumu == TAMAMLANDI)
    {
      Gaz_Doldurma_Asamasi = 0;
      return ANA_MENU_DON;
    }
    return Islem_Durumu;
    
  }
  return DEVAM_EDIYOR;
}

void Gaz_Dolum_Sayfasi(void)
{
  static unsigned char Gaz_Doldurma_Asamasi = Sifirlama;
  static unsigned int _ms = 0;
  unsigned char Islem_Durumu = 0;

  Terazi_Oku(&EKM.Terazi_Gr);
  Basinc_Oku(&EKM.Basinc_Br);

  if (Gaz_Doldurma_Asamasi == Sifirlama)    //// ilk sıfırlama ve değerleri alma
  {
    //Vakum_Darasini_Eepromdan_Oku();
    EKM.Sayfa = Gaz_Doldurma_Sayfasi;
    //EKM.Vakum_Darasi += (10 * EKM.Vakum_Boleni);	
    EKM.Yag_Dolumu = 0;
    lcd.clear();
    if (EKM.Vakum_Suresi_Dk > 0)
    {
      Kayittan_Yazi_Yaz(0,SATIR_2,Yeni_Yag_Gr_Yaz_Yeri);
      Kayittan_Yazi_Yaz(0,SATIR_3,Hayir_Yeri);
      Gaz_Doldurma_Asamasi = Yag_Sorgusu_ve_Basinc_Kontrol;	
    }
    else
    {
      if(EKM.Dolum_Miktari_Gr > 0)
      {
        if((EKM.Terazi_Gr < 1000) || (EKM.Terazi_Gr < EKM.Dolum_Miktari_Gr))
        {
          Kayittan_Yazi_Yaz(0,SATIR_2,Gaz_Yetersiz_Yeri);         
          Buzer_Ac;
          EKM.Buzer_Calma_ms = UZUN_BUZER;
          Gaz_Doldurma_Asamasi = Cikis_Bekle;
        } 
        else
        {
          Gaz_Doldurma_Asamasi = Baslama_Sorgusu;
          Kayittan_Yazi_Yaz(1,SATIR_2,Baslasin_mi_Yaz_Yeri);
        } 
      } 
      else    //// vakum = 0, gaz mik = 0. işlem yok bitir.
      {
        Gaz_Doldurma_Asamasi = Cikis_Bekle;
        Buzer_Ac;
        EKM.Buzer_Calma_ms = UZUN_BUZER;
        Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
      }	
    }    
  }
  else if (Gaz_Doldurma_Asamasi == Yag_Sorgusu_ve_Basinc_Kontrol)   //// yag sorgusu ve Tüpteki gaz kontrol
  {
    if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;      
      Kayittan_Yazi_Yaz(0,SATIR_3, Evet_Yeri);
      EKM.Yag_Dolumu = 1;
    }
    
    if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;        
      Kayittan_Yazi_Yaz(0,SATIR_3,Hayir_Yeri);
      EKM.Yag_Dolumu = 0;
    }
    
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;        
      lcd.clear();
      if(EKM.Dolum_Miktari_Gr > 0)
      {
        if((EKM.Terazi_Gr < 1000) || (EKM.Terazi_Gr < EKM.Dolum_Miktari_Gr))
        {
          Buzer_Ac;EKM.Buzer_Calma_ms = UZUN_BUZER;
          Kayittan_Yazi_Yaz(0,SATIR_2,Gaz_Yetersiz_Yeri);
          Gaz_Doldurma_Asamasi = Cikis_Bekle;
        } 
        else
        {
          Gaz_Doldurma_Asamasi = Baslama_Sorgusu;
          Kayittan_Yazi_Yaz(1,SATIR_2,Baslasin_mi_Yaz_Yeri);
        } 
      } 
      else
      {
        Gaz_Doldurma_Asamasi = Baslama_Sorgusu;
        Kayittan_Yazi_Yaz(1,SATIR_2,Baslasin_mi_Yaz_Yeri);
      }       
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Butonlari_Temizle();
      Giris_Sayfa(1,1);
      //Vakum_Darasini_Eepromdan_Oku();
      Gaz_Doldurma_Asamasi = Sifirlama;
    }
  }
  else if (Gaz_Doldurma_Asamasi == Baslama_Sorgusu)
  {
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;

      memset(&Yazilacaklar, 0,sizeof(Yazilacaklar)); //// printer için alınan veriler sıfırlanır.// eski işlem verileri lazım olur diye yenisine başlamadan silinmiyor
      
      EKM.E_Seri_No = EKM.Seri_No;

      lcd.clear();
      if(EKM.Vakum_Suresi_Dk > 0)
      {
        lcd.clear();
        Kayittan_Yazi_Yaz(0,SATIR_2,Lutfen_Bekleyin_Yeri);

        Gaz_Doldurma_Asamasi = Sistemden_Gaz_Cekme;
        _ms = EKM.MS;
      }
      else
      {
        Gaz_Doldurma_Asamasi = Gaz_Doldurma;
      }
      
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Gaz_Doldurma_Asamasi = Sifirlama;
    //  Vakum_Darasini_Eepromdan_Oku();
      Butonlari_Temizle();
      Giris_Sayfa(1,1);      
    }
  }
  else if (Gaz_Doldurma_Asamasi == Sistemden_Gaz_Cekme)	      /// gaz cekme işlemi. Hata var ise sorguya geçecek. hata yok ise vakuma
  {                                                           /// Vakum süresi girilmezse gaz çekme işlemi yapılmaz. direkt doluma geçer
    Islem_Durumu = Gaz_Cek(ARABADAN_GAZ_CEKILIYOR);

    if(Islem_Durumu == TAMAMLANDI)     /// gaz çekme işlemi tamamlandı.
    {
      Gaz_Doldurma_Asamasi = Vakum_Yapma;
    }
    else if (Islem_Durumu == IPTAL_ET)  /// hata var, dolum işlemini iptal edecek
    {
      lcd.clear();
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;

      Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
      if(EKM.Yazici == VAR)
      {
        Gaz_Doldurma_Asamasi = Yazdirma_Sorgusu; 
        Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);     
      }
      else
      {
        Kayittan_Yazi_Yaz(13,SATIR_3,E_Posta_Yeri);
        Gaz_Doldurma_Asamasi = Mail_Sorgusu;
      }
    }
    else if (Islem_Durumu == GAZ_YOK)
    {
      Gaz_Doldurma_Asamasi = Vakum_Yapma;
    }
  }
  else if (Gaz_Doldurma_Asamasi == Vakum_Yapma)     //// vakum yeri
  {
    Islem_Durumu = Vakum_Yap();

    if (Islem_Durumu == TAMAMLANDI)
    {
      Gaz_Doldurma_Asamasi = Kacak_Bekleme;
    }
    else if (Islem_Durumu == VAKUM_DUSUK)
    {
      lcd.clear();
      Kayittan_Yazi_Yaz(4,SATIR_1,Vakum_Dusuk_Yeri);
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;

      Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
      if(EKM.Yazici == VAR)
      {
        Gaz_Doldurma_Asamasi = Yazdirma_Sorgusu; 
        Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);     
      }
      else
      {
        Kayittan_Yazi_Yaz(13,SATIR_3,E_Posta_Yeri);
        Gaz_Doldurma_Asamasi = Mail_Sorgusu;
      }
    }
  }
  else if (Gaz_Doldurma_Asamasi == Kacak_Bekleme)     //// vakum yeri
  {
    Islem_Durumu = Kacak_Bekle();

    if (Islem_Durumu == TAMAMLANDI)
    {
      if(EKM.Yag_Dolumu == 0)
      {
        Gaz_Doldurma_Asamasi = Gaz_Doldurma;
      }
      else
      {
        Gaz_Doldurma_Asamasi = Yag_Ekleme;
      }
      
    }
    else if (Islem_Durumu == KACAK_VAR)
    {
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
      if(EKM.Yazici == VAR)
      {
        Gaz_Doldurma_Asamasi = Yazdirma_Sorgusu; 
        Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);     
      }
      else
      {
        Kayittan_Yazi_Yaz(13,SATIR_3,E_Posta_Yeri);
        Gaz_Doldurma_Asamasi = Mail_Sorgusu;
      }
    }
  }
  else if (Gaz_Doldurma_Asamasi == Yag_Ekleme)     //// vakum yeri
  {
    Islem_Durumu = Yag_Ekle();
    if(Islem_Durumu == TAMAMLANDI)
    {
      Gaz_Doldurma_Asamasi = Gaz_Doldurma;
    }
  }
  else if (Gaz_Doldurma_Asamasi == Gaz_Doldurma)
  {
    Islem_Durumu = Gaz_Doldur();

    if(Islem_Durumu == TAMAMLANDI)
    {
      Gaz_Doldurma_Asamasi = Bakim_Kontrolu;
    }
    else if(Islem_Durumu == ANA_MENU_DON)
    {
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
      // if(Yazilacaklar.Dolan_Gr >= 0)
      // {
      //   Lcd_Sayi_Yaz(7,SATIR_2,Yazilacaklar.Dolan_Gr,1,5);
      //   Yazi_Yaz(13,SATIR_2,"GR",2);
      // }
  
      Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
      if(EKM.Yazici == VAR)
      {
        Gaz_Doldurma_Asamasi = Yazdirma_Sorgusu; 
        Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);     
      }
      else
      {
        Kayittan_Yazi_Yaz(13,SATIR_3,E_Posta_Yeri);
        Gaz_Doldurma_Asamasi = Mail_Sorgusu;
      }    
    }
  }
  else if (Gaz_Doldurma_Asamasi == Cikis_Bekle)
  {
     if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
     {
       Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
       Gaz_Doldurma_Asamasi = Sifirlama;
       Butonlari_Temizle();
       Giris_Sayfa(1,2);
     }
  }
  else if (Gaz_Doldurma_Asamasi == Kacak_Cikisi)
  {
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
     {
       Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
       Gaz_Doldurma_Asamasi = Bakim_Kontrolu;
     }
  }
  else if (Gaz_Doldurma_Asamasi == Bakim_Kontrolu)
  {
    Islem_Durumu = Bakim_Kontrol();

    if(Islem_Durumu == TAMAMLANDI)
    {
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
      if(Yazilacaklar.Dolan_Gr >= 0)
      {
        Lcd_Sayi_Yaz(7,SATIR_2,Yazilacaklar.Dolan_Gr,1,5);
        Yazi_Yaz(13,SATIR_2,"GR",2);
      }
      
      Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
      if(EKM.Yazici == VAR)
      {
        Gaz_Doldurma_Asamasi = Yazdirma_Sorgusu; 
        Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);     
      }
      else
      {
        Kayittan_Yazi_Yaz(13,SATIR_3,E_Posta_Yeri);
        Gaz_Doldurma_Asamasi = Mail_Sorgusu;
      }
    }
    else if (Islem_Durumu == FILTRE_BITMIS)
    {
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
      lcd.clear();
      Kayittan_Yazi_Yaz(7,SATIR_1,Filtre_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_2,Degistirme_Zamani_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,Devam_Icin_ENT_Bas_Yeri);
      Gaz_Doldurma_Asamasi = Giris_Bekle;
    }
    else if(Islem_Durumu == FILTRE_AZ)
    {
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
      lcd.clear();
      Kayittan_Yazi_Yaz(5,SATIR_1,Uyari_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_2,Filtre_Az_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_3,Siparis_Edin_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,Devam_Icin_ENT_Bas_Yeri);
      Gaz_Doldurma_Asamasi = Giris_Bekle;
    }
  }
  else if (Gaz_Doldurma_Asamasi == Giris_Bekle)
  {
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
     // Gaz_Doldurma_Asamasi = Yazdirma_Sorgusu;
     // Giris_Sayfa(1,2);
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
      if(Yazilacaklar.Dolan_Gr >= 0)
      {
        Lcd_Sayi_Yaz(7,SATIR_2,Yazilacaklar.Dolan_Gr,1,5);
        Yazi_Yaz(13,SATIR_2,"GR",2);
      }
      
      Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
      if(EKM.Yazici == VAR)
      {
        Gaz_Doldurma_Asamasi = Yazdirma_Sorgusu; 
        Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);     
      }
      else
      {
        Kayittan_Yazi_Yaz(13,SATIR_3,E_Posta_Yeri);
        Gaz_Doldurma_Asamasi = Mail_Sorgusu;
      }      
    }
  }
  else if (Gaz_Doldurma_Asamasi == Anamenu_Beklemesi)
  {
    if((EKM.MS - _ms) > UZUN_BUZER)
      {
        Gaz_Doldurma_Asamasi = Sifirlama;
        Giris_Sayfa(1,2);
      }
  }  
  else if (Gaz_Doldurma_Asamasi == Yazdirma_Sorgusu)
  {
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      Butonlari_Temizle();
      Gaz_Doldurma_Asamasi = Yazdirma_Secimi;
      lcd.clear();
      Kayittan_Yazi_Yaz(0,SATIR_3,E_Posta_ve_Yazdir_Yeri);
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
     {
       Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
       Gaz_Doldurma_Asamasi = Sifirlama;
       Butonlari_Temizle();
       Giris_Sayfa(1,2);
     }
  }
  else if (Gaz_Doldurma_Asamasi == Yazdirma_Secimi)  // sadece yazıcı varsa buraya gelir, o yuzden geri basılırsa yazdırma sorgusuna gidebilir
  {
    if (Buton[Sag_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Sag_Buton].Olay = OLAYI_TEMIZLE;
      Gaz_Doldurma_Asamasi = Islem_Yazdirma;
      lcd.clear();
    }
    else if (Buton[Sol_Buton].Olay == BASILDI_OLAYI)
     {
       Buton[Sol_Buton].Olay = OLAYI_TEMIZLE;
       Gaz_Doldurma_Asamasi = Plaka_Girisi;
       lcd.clear();
       Kayittan_Yazi_Yaz(1,SATIR_1,Plaka_Yeri);
     }
     else if(Buton[Geri_Buton].Olay == BASILDI_OLAYI)
     {
      Gaz_Doldurma_Asamasi = Yazdirma_Sorgusu;
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
     }
  }
  else if (Gaz_Doldurma_Asamasi == Islem_Yazdirma)
  {
    Islem_Durumu = Islem_Yazdir();
    if(Islem_Durumu == YAZDIRMA_SOR)
    {
      lcd.clear();
      Gaz_Doldurma_Asamasi = Yazdirma_Sorgusu;
      Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
      if(Yazilacaklar.Dolan_Gr >= 0)
        {
          Lcd_Sayi_Yaz(7,SATIR_2,Yazilacaklar.Dolan_Gr,1,5);
          Yazi_Yaz(13,SATIR_2,"GR",2);
        }
      Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
    }
    else if (Islem_Durumu == ANA_MENU_DON)
    {
      Gaz_Doldurma_Asamasi = Sifirlama;
      Butonlari_Temizle();
      Giris_Sayfa(1,2);
    }
  }
  else if (Gaz_Doldurma_Asamasi == Mail_Sorgusu)   // sadece yazıcı yoksa buraya gelebilir. email attıktan sonra ekrana gereli yazılar yazılıp bu adıma yönlenecek
  {
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      Gaz_Doldurma_Asamasi = Plaka_Girisi;
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_1,Plaka_Yeri);
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
     {
       Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
       Gaz_Doldurma_Asamasi = Sifirlama;
       Butonlari_Temizle();
       Giris_Sayfa(1,1);
     }
  }
  else if (Gaz_Doldurma_Asamasi == Plaka_Girisi)
  {
    Islem_Durumu = Plaka_Gir();
    if(Islem_Durumu == 1)
    {
      lcd.clear();
      Gaz_Doldurma_Asamasi = Mail_Atma;
      // Kayittan_Yazi_Yaz(6,SATIR_1,Sira_No_Yeri);
    }
    else if (Islem_Durumu == 99)
    {
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
      if(EKM.Yazici == VAR)
      {
        Gaz_Doldurma_Asamasi = Yazdirma_Sorgusu;
        Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);
      }
      else
      {
        Kayittan_Yazi_Yaz(13,SATIR_3,E_Posta_Yeri);
        Gaz_Doldurma_Asamasi = Mail_Sorgusu;
      }
    }
  }
  // else if (Gaz_Doldurma_Asamasi == Seri_No_Girisi)
  // {
  //   Islem_Durumu = Buyuk_Sayi_Gir(6, SATIR_3, &EKM.Seri_No, 6);
  //   if(Islem_Durumu == 1)
  //   {
  //     lcd.clear();
  //     Veri_Kaydet_UInt(SERI_NO_KAYIT_YERI, EKM.Seri_No);
  //     Gaz_Doldurma_Asamasi = Mail_Atma;
  //   }
  //   else if (Islem_Durumu == 99)
  //   {
  //     lcd.clear();
  //     Kayittan_Yazi_Yaz(1,SATIR_1,Plaka_Yeri);
  //     Gaz_Doldurma_Asamasi = Plaka_Girisi;
  //   }
  // }
  else if (Gaz_Doldurma_Asamasi == Mail_Atma)
  {
    Islem_Durumu = Mail_Gonderme();
    if((Islem_Durumu == TAMAMLANDI) || (Islem_Durumu == IPTAL_ET) || (Islem_Durumu == HATA_OLUSTU))
    {
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
      Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
      Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
      if(EKM.Yazici == VAR)
      {
        Gaz_Doldurma_Asamasi = Yazdirma_Sorgusu;
        Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);
      }
      else
      {
        Kayittan_Yazi_Yaz(13,SATIR_3,E_Posta_Yeri);
        Gaz_Doldurma_Asamasi = Mail_Sorgusu;
      }
    }
  }
}

void Pcf_Yaz(uint16_t Valf_Adresi)
{
  Wire.beginTransmission(0x20);
  Wire.write(Valf_Adresi);
  Wire.write(Valf_Adresi >> 8);
  Wire.endTransmission();
}

void SSR_Kontrol(unsigned char SSR,unsigned char Durum)
{
  static uint16_t Son_Yazilan_Deger = 0xFFFF;

  if(Durum == AC)
  {
    if(SSR == Vakum_Ssr)
    {
      Son_Yazilan_Deger &= Vakum_SSR_Deg;
    }
    else if (SSR == Kompresor_Ssr)
    {
      Son_Yazilan_Deger &= Kompresor_SSR_Deg;
    }
    else if (SSR == Yuksek_Basinc_Valf_Ssr)
    {
      Son_Yazilan_Deger &= Yuksek_Basinc_Valf_Deg;
    }
    else if (SSR == Gaz_Valf_Ssr)
    {
      Son_Yazilan_Deger &= Gaz_Valf_Deg;
    }
    else if (SSR == Eski_Yag_Valf_Ssr)
    {
      Son_Yazilan_Deger &= Eski_Yag_Valf_Deg;
    }
    else if (SSR == Yeni_Yag_Valf_Ssr)
    {
      Son_Yazilan_Deger &= Yeni_Yag_Valf_Deg;
    }
    else if (SSR == Alcak_Basinc_Valf_Ssr)
    {
      Son_Yazilan_Deger &= Alcak_Basinc_Valf_Deg;
    }
    else if (SSR == Kompresor_Yag_Valf_Ssr)
    {
      Son_Yazilan_Deger &= Kompresor_Yag_Valf_Deg;
    }
    else if (SSR == Isitici_Ssr)
    {
      Son_Yazilan_Deger &= Isitici_Deg;
    }
    else if (SSR == Yag_Giris_Nem_Valf_Ssr)
    {
      Son_Yazilan_Deger &= Yag_Giris_Nem_Valf_Deg;
    }
    else if (SSR == Hava_Tahliye_Valf_Ssr)
    {
      Son_Yazilan_Deger &= Hava_Tahliye_Valf_Deg;
    }
    else if (SSR == Fan_Ssr)
    {
      Son_Yazilan_Deger &= Fan_Deg;
    }
    else if (SSR == Yikama_Valf_Ssr)
    {
      Son_Yazilan_Deger &= Yikama_Valf_Deg;
    }
    else if (SSR == Hibrit_Yag_Valf_Ssr)
    {
      Son_Yazilan_Deger &= Hibrit_Yag_Valf_Deg;
    }
    else if (SSR == UV_Yag_Valf_Ssr)
    {
      Son_Yazilan_Deger &= UV_Yag_Valf_Deg;
    }
    else if (SSR == Gaz_Analiz_Valf_Ssr)
    {
      Son_Yazilan_Deger &= Gaz_Analiz_Valf_Deg;
    }
  }
  else
  {
    if(SSR == Vakum_Ssr)
    {
      Son_Yazilan_Deger |= ~Vakum_SSR_Deg;
    }
    else if (SSR == Kompresor_Ssr)
    {
      Son_Yazilan_Deger |= ~Kompresor_SSR_Deg;
    }
    else if (SSR == Yuksek_Basinc_Valf_Ssr)
    {
      Son_Yazilan_Deger |= ~Yuksek_Basinc_Valf_Deg;
    }
    else if (SSR == Gaz_Valf_Ssr)
    {
      Son_Yazilan_Deger |= ~Gaz_Valf_Deg;
    }
    else if (SSR == Eski_Yag_Valf_Ssr)
    {
      Son_Yazilan_Deger |= ~Eski_Yag_Valf_Deg;
    }
    else if (SSR == Yeni_Yag_Valf_Ssr)
    {
      Son_Yazilan_Deger |= ~Yeni_Yag_Valf_Deg;
    }
    else if (SSR == Alcak_Basinc_Valf_Ssr)
    {
      Son_Yazilan_Deger |= ~Alcak_Basinc_Valf_Deg;
    }
    else if (SSR == Kompresor_Yag_Valf_Ssr)
    {
      Son_Yazilan_Deger |= ~Kompresor_Yag_Valf_Deg;
    }
    else if (SSR == Isitici_Ssr)
    {
      Son_Yazilan_Deger |= ~Isitici_Deg;
    }
    else if (SSR == Yag_Giris_Nem_Valf_Ssr)
    {
      Son_Yazilan_Deger |= ~Yag_Giris_Nem_Valf_Deg;
    }
    else if (SSR == Hava_Tahliye_Valf_Ssr)
    {
      Son_Yazilan_Deger |= ~Hava_Tahliye_Valf_Deg;
    }
    else if (SSR == Fan_Ssr)
    {
      Son_Yazilan_Deger |= ~Fan_Deg;
    }
    else if (SSR == Yikama_Valf_Ssr)
    {
      Son_Yazilan_Deger |= ~Yikama_Valf_Deg;
    }
    else if (SSR == Hibrit_Yag_Valf_Ssr)
    {
      Son_Yazilan_Deger |= ~Hibrit_Yag_Valf_Deg;
    }
    else if (SSR == UV_Yag_Valf_Ssr)
    {
      Son_Yazilan_Deger |= ~UV_Yag_Valf_Deg;
    }
    else if (SSR == Gaz_Analiz_Valf_Ssr)
    {
      Son_Yazilan_Deger |= ~Gaz_Analiz_Valf_Deg;
    }
    else if ( SSR == IPTAL_ET)
    {
      Son_Yazilan_Deger = 0xFFFF;
    }
  }

  Pcf_Yaz(Son_Yazilan_Deger);
 // delay(10);

}

void Valf_Test_Sayfa()
{
  EKM.Sayfa = Valf_Test_Sayfasi;
  EKM.Imlec = 1;
  lcd.clear();
  Kayittan_Yazi_Yaz(0, SATIR_1,Kompresor_Yeri);
  Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
       
}

void Valf_Testi(void)
{
  static unsigned char Kompresor_Acik = 0, Vakum_Acik = 0, Yuksek_Basinc_Valfi_Acik = 0, Gaz_Valfi_Acik = 0, Yag_Nem_Valfi_Acik = 0, Hava_Tahliye_Valfi_Acik = 0, Hibrit_Yag_Valfi_Acik = 0, Gaz_Analiz_Valfi_Acik = 0;
  static unsigned char Eski_Yag_Valfi_Acik = 0, Yeni_Yag_Valfi_Acik = 0, Alcak_Basinc_Valfi_Acik = 0, Kopm_Yag_Valfi_Acik = 0, Isitici_Acik = 0, Fanlar_Acik = 0, Yikama_Isitici_Acik = 0, UV_Yag_Valfi_Acik = 0;
  static unsigned char Yaziliyor = 0, Test_Birim_Sayisi = 0;

  if(EKM.Yazici == VAR)
  {
    Test_Birim_Sayisi = 17;
  }
  else
  {
    Test_Birim_Sayisi = 16;
  }

  if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
    Butonlari_Temizle();
    Giris_Sayfa(2,1);
  }
  if (Buton[Giris_Buton].Durum == 1)
  {
    if (EKM.Imlec == 1)
    {
      if(Kompresor_Acik == 0)
      {
        Yazi_Yaz(0,SATIR_3,"                    ",1);
        Kayittan_Yazi_Yaz(0,SATIR_3,Acik_Yaz_Yeri);
        SSR_Kontrol(Kompresor_Ssr,AC);
        Kompresor_Acik = 1;
      }
        
    }
    else if (EKM.Imlec == 2)
    {
      if(Vakum_Acik == 0)
      {
        Yazi_Yaz(0,SATIR_3,"                    ",1);
        Kayittan_Yazi_Yaz(0,SATIR_3,Acik_Yaz_Yeri);
        SSR_Kontrol(Vakum_Ssr,AC);
        Vakum_Acik = 1;
      }
    }
    else if (EKM.Imlec == 3)
    {
      if(Yuksek_Basinc_Valfi_Acik == 0)
      {
        Yazi_Yaz(0,SATIR_3,"                    ",1);
        Kayittan_Yazi_Yaz(0,SATIR_3,Acik_Yaz_Yeri);
        SSR_Kontrol(Yuksek_Basinc_Valf_Ssr,AC);
        Yuksek_Basinc_Valfi_Acik = 1;
      }
    }
    else if (EKM.Imlec == 4)
    {
      if(Gaz_Valfi_Acik == 0)
      {
        Yazi_Yaz(0,SATIR_3,"                    ",1);
        Kayittan_Yazi_Yaz(0,SATIR_3,Acik_Yaz_Yeri);
        SSR_Kontrol(Gaz_Valf_Ssr,AC);
        Gaz_Valfi_Acik = 1;
      }
    }
    else if (EKM.Imlec == 5)
    {
      if(Eski_Yag_Valfi_Acik == 0)
      {
        Yazi_Yaz(0,SATIR_3,"                    ",1);
        Kayittan_Yazi_Yaz(0,SATIR_3,Acik_Yaz_Yeri);
        SSR_Kontrol(Eski_Yag_Valf_Ssr,AC);
        Eski_Yag_Valfi_Acik = 1;
      }
    }
    else if (EKM.Imlec == 6)
    {
      if(Yeni_Yag_Valfi_Acik == 0)
      {
        Yazi_Yaz(0,SATIR_3,"                    ",1);
        Kayittan_Yazi_Yaz(0,SATIR_3,Acik_Yaz_Yeri);
        SSR_Kontrol(Yeni_Yag_Valf_Ssr,AC);
        Yeni_Yag_Valfi_Acik = 1;
      }
    }
    else if (EKM.Imlec == 7)
    {
      if(Alcak_Basinc_Valfi_Acik == 0)
      {
        Yazi_Yaz(0,SATIR_3,"                    ",1);
        Kayittan_Yazi_Yaz(0,SATIR_3,Acik_Yaz_Yeri);
        SSR_Kontrol(Alcak_Basinc_Valf_Ssr,AC);
        Alcak_Basinc_Valfi_Acik = 1;
      }
    }
    else if (EKM.Imlec == 8)
    {
      if(Kopm_Yag_Valfi_Acik == 0)
      {
        Yazi_Yaz(0,SATIR_3,"                    ",1);
         Kayittan_Yazi_Yaz(0,SATIR_3,Acik_Yaz_Yeri);
        SSR_Kontrol(Kompresor_Yag_Valf_Ssr,AC);
        Kopm_Yag_Valfi_Acik = 1;
      }
    }
    else if (EKM.Imlec == 9)
    {
      if(Isitici_Acik == 0)
      {
        Yazi_Yaz(0,SATIR_3,"                    ",1);
        Kayittan_Yazi_Yaz(0,SATIR_3,Acik_Yaz_Yeri);
        SSR_Kontrol(Isitici_Ssr,AC);
        Isitici_Acik = 1;
      }
    }
    else if (EKM.Imlec == 10)
    {
      if(Yag_Nem_Valfi_Acik == 0)
      {
        Yazi_Yaz(0,SATIR_3,"                    ",1);
        Kayittan_Yazi_Yaz(0,SATIR_3,Acik_Yaz_Yeri);
        SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,AC);
        Yag_Nem_Valfi_Acik = 1;
      }
    }
    else if (EKM.Imlec == 11)
    {
      if(Hava_Tahliye_Valfi_Acik == 0)
      {
        Yazi_Yaz(0,SATIR_3,"                    ",1);
        Kayittan_Yazi_Yaz(0,SATIR_3,Acik_Yaz_Yeri);
        SSR_Kontrol(Hava_Tahliye_Valf_Ssr,AC);
        Hava_Tahliye_Valfi_Acik = 1;
      }
    }
    else if (EKM.Imlec == 12)
    {
      if(Fanlar_Acik == 0)
      {
        Yazi_Yaz(0,SATIR_3,"                    ",1);
        Kayittan_Yazi_Yaz(0,SATIR_3,Acik_Yaz_Yeri);
        SSR_Kontrol(Fan_Ssr,AC);
        Fanlar_Acik = 1;
      }
    }
    else if (EKM.Imlec == 13)
    {
      if(Yikama_Isitici_Acik == 0)
      {
        Yazi_Yaz(0,SATIR_3,"                    ",1);
        Kayittan_Yazi_Yaz(0,SATIR_3,Acik_Yaz_Yeri);
        SSR_Kontrol(Yikama_Valf_Ssr,AC);
        Yikama_Isitici_Acik = 1;
      }
    }
    else if (EKM.Imlec == 14)
    {
      if(Hibrit_Yag_Valfi_Acik == 0)
      {
        Yazi_Yaz(0,SATIR_3,"                    ",1);
        Kayittan_Yazi_Yaz(0,SATIR_3,Acik_Yaz_Yeri);
        SSR_Kontrol(Hibrit_Yag_Valf_Ssr,AC);
        Hibrit_Yag_Valfi_Acik = 1;
      }
    }
    else if (EKM.Imlec == 15)
    {
      if(UV_Yag_Valfi_Acik == 0)
      {
        Yazi_Yaz(0,SATIR_3,"                    ",1);
         Kayittan_Yazi_Yaz(0,SATIR_3,Acik_Yaz_Yeri);
        SSR_Kontrol(UV_Yag_Valf_Ssr,AC);
        UV_Yag_Valfi_Acik = 1;
      }
    }
    else if (EKM.Imlec == 16)
    {
      if(Gaz_Analiz_Valfi_Acik == 0)
      {
        Yazi_Yaz(0,SATIR_3,"                    ",1);
        Kayittan_Yazi_Yaz(0,SATIR_3,Acik_Yaz_Yeri);
        SSR_Kontrol(Gaz_Analiz_Valf_Ssr,AC);
        Gaz_Analiz_Valfi_Acik = 1;
      }
    }
    else if (EKM.Imlec == 17)
    {
      if(Yaziliyor == 0)
      {
        Yazi_Yaz(0,SATIR_3,"                    ",1);
        Kayittan_Yazi_Yaz(0,SATIR_3,Yazdiriliyor_Yeri);
        Yazici_Test();
        Yaziliyor = 1;
      }
    }
     
  }
  else
  {    
    if(Kompresor_Acik == 1)
    {
      Butonlari_Temizle();
      Yazi_Yaz(0,SATIR_3,"                    ",1);
      Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
      SSR_Kontrol(Kompresor_Ssr,KAPAT);
      Kompresor_Acik = 0;
       
    }
       
    if(Vakum_Acik == 1)
    {
      Butonlari_Temizle();
      Yazi_Yaz(0,SATIR_3,"                    ",1);
      Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
      SSR_Kontrol(Vakum_Ssr,KAPAT);
      Vakum_Acik = 0;
       
    }
  
    if(Yuksek_Basinc_Valfi_Acik == 1)
    {
      Butonlari_Temizle();
      Yazi_Yaz(0,SATIR_3,"                    ",1);
      Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
      SSR_Kontrol(Yuksek_Basinc_Valf_Ssr,KAPAT);
      Yuksek_Basinc_Valfi_Acik = 0;
       
    }
  
    if(Gaz_Valfi_Acik == 1)
    {
      Butonlari_Temizle();
      Yazi_Yaz(0,SATIR_3,"                    ",1);
      Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
      SSR_Kontrol(Gaz_Valf_Ssr,KAPAT);
      Gaz_Valfi_Acik = 0;
       
    }
  
    if(Eski_Yag_Valfi_Acik == 1)
    {
      Butonlari_Temizle();
      Yazi_Yaz(0,SATIR_3,"                    ",1);
      Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
      SSR_Kontrol(Eski_Yag_Valf_Ssr,KAPAT);;
      Eski_Yag_Valfi_Acik = 0;
       
    }
  
    if(Yeni_Yag_Valfi_Acik == 1)
    {
      Butonlari_Temizle();
      Yazi_Yaz(0,SATIR_3,"                    ",1);
      Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
      SSR_Kontrol(Yeni_Yag_Valf_Ssr,KAPAT);
      Yeni_Yag_Valfi_Acik = 0;
       
    }
  
    if(Alcak_Basinc_Valfi_Acik == 1)
    {
      Butonlari_Temizle();
      Yazi_Yaz(0,SATIR_3,"                    ",1);
      Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
      SSR_Kontrol(Alcak_Basinc_Valf_Ssr,KAPAT);
      Alcak_Basinc_Valfi_Acik = 0;
    }
  
    if(Kopm_Yag_Valfi_Acik == 1)
    {
      Butonlari_Temizle();
      Yazi_Yaz(0,SATIR_3,"                    ",1);
      Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
      SSR_Kontrol(Kompresor_Yag_Valf_Ssr,KAPAT);
      Kopm_Yag_Valfi_Acik = 0;
       
    }
  
    if(Isitici_Acik == 1)
    {
      Butonlari_Temizle();
      Yazi_Yaz(0,SATIR_3,"                    ",1);
      Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
      SSR_Kontrol(Isitici_Ssr,KAPAT);
      Isitici_Acik = 0;
       
    }
  
    if(Yag_Nem_Valfi_Acik == 1)
    {
      Butonlari_Temizle();
      Yazi_Yaz(0,SATIR_3,"                    ",1);
      Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
      SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,KAPAT);
      Yag_Nem_Valfi_Acik = 0;
       
    }
  
    if(Hava_Tahliye_Valfi_Acik == 1)
    {
      Butonlari_Temizle();
      Yazi_Yaz(0,SATIR_3,"                    ",1);
      Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
      SSR_Kontrol(Hava_Tahliye_Valf_Ssr,KAPAT);
      Hava_Tahliye_Valfi_Acik = 0;
       
    }
  
    if(Fanlar_Acik == 1)
    {
      Butonlari_Temizle();
      Yazi_Yaz(0,SATIR_3,"                    ",1);
      Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
      SSR_Kontrol(Fan_Ssr,KAPAT);
      Fanlar_Acik = 0;
       
    }
  
    if(Yikama_Isitici_Acik == 1)
    {
      Butonlari_Temizle();
      Yazi_Yaz(0,SATIR_3,"                    ",1);
      Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
      SSR_Kontrol(Yikama_Valf_Ssr,KAPAT);
      Yikama_Isitici_Acik = 0;
       
    }
  
    if(Hibrit_Yag_Valfi_Acik == 1)
    {
      Butonlari_Temizle();
      Yazi_Yaz(0,SATIR_3,"                    ",1);
      Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
      SSR_Kontrol(Hibrit_Yag_Valf_Ssr,KAPAT);
      Hibrit_Yag_Valfi_Acik = 0;
       
    }  
  
    if(UV_Yag_Valfi_Acik == 1)
    {
      Butonlari_Temizle();
      Yazi_Yaz(0,SATIR_3,"                    ",1);
      Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
      SSR_Kontrol(UV_Yag_Valf_Ssr,KAPAT);
      UV_Yag_Valfi_Acik = 0;
       
    }

    if(Gaz_Analiz_Valfi_Acik == 1)
    {
      Butonlari_Temizle();
      Yazi_Yaz(0,SATIR_3,"                    ",1);
      Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
      SSR_Kontrol(Gaz_Analiz_Valf_Ssr,KAPAT);
      Gaz_Analiz_Valfi_Acik = 0;
       
    }

    if(Yaziliyor == 1)
    {
      Butonlari_Temizle();
      Yazi_Yaz(0,SATIR_3,"                    ",1);
      Kayittan_Yazi_Yaz(0,SATIR_3,Kapali_Yaz_Yeri);
      
      Yaziliyor = 0;
    }
    
  }

  if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
  {
    Butonlari_Temizle();

    if(EKM.Imlec < Test_Birim_Sayisi)
    {
      EKM.Imlec ++;
    }
    else
    {
      EKM.Imlec = 1;
    }
    
    if (EKM.Imlec == 1)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Kompresor_Yeri);
       
    }
    else if (EKM.Imlec == 2)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Vakum_Valf_Pompa_Yeri);
       
    }
    else if (EKM.Imlec == 3)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Yuksek_Bas_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 4)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Gaz_Dolum_Vaf_Yeri);
       
    }
    else if (EKM.Imlec == 5)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Eski_Yag_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 6)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Yeni_Yag_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 7)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Alcak_Bas_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 8)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Kompresor_Yag_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 9)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Isitma_Kemer_Yeri);
       
    }
    else if (EKM.Imlec == 10)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Yag_Ayristirici_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 11)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Hava_Tahliye_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 12)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Fanlar_Yeri);
       
    }
    else if (EKM.Imlec == 13)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Yikama_Isi_Yeri);
       
    }
    else if (EKM.Imlec == 14)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Hibrit_Yag_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 15)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,UV_Yag_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 16)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Gaz_Analiz_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 17)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Yazici_Test_Yeri);
       
    }

  }
  if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
  {
    Butonlari_Temizle();
    if(EKM.Imlec > 1)
    {
      EKM.Imlec --;
    }
    else
    {
      EKM.Imlec = Test_Birim_Sayisi;
    }
    
    if (EKM.Imlec == 1)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Kompresor_Yeri);
       
    }
    else if (EKM.Imlec == 2)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Vakum_Valf_Pompa_Yeri);
       
    }
    else if (EKM.Imlec == 3)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Yuksek_Bas_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 4)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Gaz_Dolum_Vaf_Yeri);
       
    }
    else if (EKM.Imlec == 5)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Eski_Yag_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 6)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Yeni_Yag_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 7)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Alcak_Bas_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 8)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Kompresor_Yag_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 9)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Isitma_Kemer_Yeri);
       
    }
    else if (EKM.Imlec == 10)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Yag_Ayristirici_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 11)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Hava_Tahliye_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 12)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Fanlar_Yeri);
       
    }
    else if (EKM.Imlec == 13)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Yikama_Isi_Yeri);
       
    }
    else if (EKM.Imlec == 14)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Hibrit_Yag_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 15)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,UV_Yag_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 16)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Gaz_Analiz_Valf_Yeri);
       
    }
    else if (EKM.Imlec == 17)
    {
      Yazi_Yaz(0,SATIR_1,"                    ",1);
       Kayittan_Yazi_Yaz(0,SATIR_1,Yazici_Test_Yeri);
       
    }
  }

}

void Giris_Sayfa(unsigned char Sayfa, unsigned char Imlec)
{
  lcd.clear();
  //EKM.Dil = 1;
  Imlec_Yaz(Imlec);
  EKM.Imlec = Imlec;
  EKM.Giris_Sayfa = Sayfa;
  if(Sayfa == 1)
  {
     Kayittan_Yazi_Yaz(1,SATIR_1,Aractan_Gaz_Cek_Yeri);
     Kayittan_Yazi_Yaz(1,SATIR_2,Araca_Gaz_Doldur_Yeri);
     Kayittan_Yazi_Yaz(1,SATIR_3,Tupten_Gaz_Cek_Yeri);
     Kayittan_Yazi_Yaz(1,SATIR_4,Hortum_Temizleme_1_Yeri);
  }
  else if (Sayfa == 2)
  {
     Kayittan_Yazi_Yaz(1,SATIR_1,Valf_Test_Yeri);
     Kayittan_Yazi_Yaz(1,SATIR_2,Kullanim_Bilgileri_Yeri);
     Kayittan_Yazi_Yaz(1,SATIR_3,Ayarlar_Yeri);
     Kayittan_Yazi_Yaz(1,SATIR_4,Sensorler_Yeri);
  }
  
  Butonlari_Temizle();
  EKM.Sayfa = Giris_Sayfasi;
}

void Gaz_Doldurma_Secimi(void)
{
  static unsigned char Secim_Adimi = 0;
  static unsigned char Sayi_Giris_Durumu = 0;
  if(Secim_Adimi == 0)
  {
    EKM.Sayfa = Gaz_Doldurma_Secim_Sayfasi;
    lcd.clear();
    Secim_Adimi = 1;
    Yazi_Yaz(1,SATIR_1,"MANUEL",1);
    Kayittan_Yazi_Yaz(1,SATIR_2,Arac_Veri_Yeri);
    Imlec_Yaz(1);
    EKM.Imlec = 1;
  }
  else if (Secim_Adimi == 1)
  {
    if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
      if(EKM.Imlec < 2)
      {
        EKM.Imlec ++;
        Imlec_Yaz(EKM.Imlec);          
      }
    }
    if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
      if(EKM.Imlec > 1)
      {
        EKM.Imlec --;
        Imlec_Yaz(EKM.Imlec);          
      }
    }
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {

      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      if(EKM.Imlec == 1)
      {
        lcd.clear();
        Kayittan_Yazi_Yaz(0,SATIR_2,Vakum_Dk_Yaz_Yeri);
        Sayi_Girisi(8,SATIR_3,&EKM.Vakum_Suresi_Dk,3);
        Secim_Adimi = 2;
      }
      else if(EKM.Imlec == 2)
      {
        Secim_Adimi = 0;
        EKM.Vakum_Suresi_Dk = 20;
        EKM.Kacak_Suresi_Dk = 10;
        Marka_Secim(EKM.Son_Secilen_Marka);     
        EKM.Sayfa = Marka_Secim_Sayfasi;
      }
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Butonlari_Temizle();
      Giris_Sayfa(1,2);
     // Vakum_Darasini_Eepromdan_Oku();
      Secim_Adimi = 0;
    }
  }
  else if (Secim_Adimi == 2)
  {
    Sayi_Giris_Durumu = Sayi_Girisi(8,SATIR_3,&EKM.Vakum_Suresi_Dk,3);
    if(Sayi_Giris_Durumu == 1)
    {
      lcd.clear();
      Sayi_Giris_Durumu = 0;
      if(EKM.Vakum_Suresi_Dk > 0)
      {
        Secim_Adimi = 3;
        Kayittan_Yazi_Yaz(0,SATIR_2,Kacak_Dk_Yaz_Yeri);
        Sayi_Girisi(8,SATIR_3,&EKM.Kacak_Suresi_Dk,3);
      }        
      else
      {
        Secim_Adimi = 4;
        Kayittan_Yazi_Yaz(0,SATIR_2,Gaz_Miktari_Gr_Yaz_Yeri);
        Sayi_Girisi(8,SATIR_3,&EKM.Dolum_Miktari_Gr,5);
      }     
      
    }
    else if (Sayi_Giris_Durumu == 99)
    {
      Secim_Adimi = 0;
      lcd.clear();
    }
  }
  else if (Secim_Adimi == 3)
  {
    Sayi_Giris_Durumu = Sayi_Girisi(8,SATIR_3,&EKM.Kacak_Suresi_Dk,3);
    if(Sayi_Giris_Durumu == 1)
    {
      lcd.clear();
      Secim_Adimi = 4;
      Sayi_Giris_Durumu = 0;
      Kayittan_Yazi_Yaz(0,SATIR_2,Gaz_Miktari_Gr_Yaz_Yeri);
      Sayi_Girisi(8,SATIR_3,&EKM.Dolum_Miktari_Gr,5);
    }
    else if (Sayi_Giris_Durumu == 99)
    {
      lcd.clear();
      Kayittan_Yazi_Yaz(0,SATIR_2,Vakum_Dk_Yaz_Yeri);
      Sayi_Girisi(8,SATIR_3,&EKM.Vakum_Suresi_Dk,3);
      Secim_Adimi = 2;
    }
  }
  else if (Secim_Adimi == 4)
  {
    Sayi_Giris_Durumu = Sayi_Girisi(8,SATIR_3,&EKM.Dolum_Miktari_Gr,5);
    if(Sayi_Giris_Durumu == 1)
    {
      lcd.clear();
      Secim_Adimi = 0;
      Sayi_Giris_Durumu = 0;
      lcd.noCursor();
      EKM.Sayfa = Gaz_Doldurma_Sayfasi;
    }
    else if (Sayi_Giris_Durumu == 99)
    {
      if(EKM.Vakum_Suresi_Dk > 0)
      {
        Secim_Adimi = 3;
        Sayi_Giris_Durumu = 0;
        lcd.clear();
        Kayittan_Yazi_Yaz(0,SATIR_2,Kacak_Dk_Yaz_Yeri);
        Sayi_Girisi(8,SATIR_3,&EKM.Kacak_Suresi_Dk,3);
      }
      else
      {
        Secim_Adimi = 2;
        Sayi_Giris_Durumu = 0;
        lcd.clear();
        Kayittan_Yazi_Yaz(0,SATIR_2,Vakum_Dk_Yaz_Yeri);
        Sayi_Girisi(8,SATIR_3,&EKM.Vakum_Suresi_Dk,3);
      }
    }
  }

}

void Kullanim_Bilgileri(void)
{
  static unsigned char Kullanim_Sayfa = 0;

  if(Kullanim_Sayfa == 0)
  {
    lcd.clear();
    lcd.setCursor(19, 4);
    lcd.write(byte(1));
    Eepromdan_Verileri_Al();
    Kayittan_Yazi_Yaz(0,SATIR_1,Son_Cekilen_Gr_Yeri);
    Lcd_Sayi_Yaz(13,SATIR_1,EKM.Son_Cekilen_Gr,0,0);
    Kayittan_Yazi_Yaz(0,SATIR_2,Vakum_Saat_Yeri);
    Lcd_Sayi_Yaz(13,SATIR_2,(EKM.Toplam_Vakum_Dk/60),0,0);
    Kayittan_Yazi_Yaz(0,SATIR_3,Filtre_KLN_Yeri);
    Lcd_Sayi_Yaz(13,SATIR_3,(EKM.Filtre_Kalan_Gr/1000),0,0);
    Kayittan_Yazi_Yaz(0,SATIR_4,Tupten_Cekilen_Kg_Yeri);
    Lcd_Sayi_Yaz(13,SATIR_4,(EKM.Toplam_Tupten_Cekilen_Gr/1000),0,0);
    Kullanim_Sayfa = 1;
    EKM.Sayfa = Kullanim_Bilgileri_Sayfasi;
  }
  else if (Kullanim_Sayfa == 1)
  {
    if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
     {
       Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
       Kullanim_Sayfa = 2;
     }
  }
  else if (Kullanim_Sayfa == 2)
  {
    lcd.clear();
    lcd.setCursor(19, 4);
    lcd.write(byte(1));
    Kayittan_Yazi_Yaz(0,SATIR_1,Arac_Islemleri_Yeri);
    
    Kayittan_Yazi_Yaz(0,SATIR_2,Cekilen_Kg_Yeri);
    Lcd_Sayi_Yaz(14,SATIR_2,(EKM.Toplam_Aractan_Cekilen_Gr/1000),0,0);
    Kayittan_Yazi_Yaz(0,SATIR_3,Doldurulan_Kg_Yeri);
    Lcd_Sayi_Yaz(14,SATIR_3,(EKM.Toplam_Dolum_Gr/1000),0,0);
    Kullanim_Sayfa = 3;
  }
  else if (Kullanim_Sayfa == 3)
  {
    if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
     {
       Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
       Butonlari_Temizle();
       Kullanim_Sayfa = 0;
       Giris_Sayfa(2,2);
     }
  }
}

void Hortum_Temizleme_Sayfa(void)
{
  static unsigned char Islem_Durumu = 0;
  static unsigned char Temizleme_Asamasi = 0;
  static unsigned int _ms = 0;

  if(Temizleme_Asamasi == Sifirlama)
  {
    Islem_Durumu = Hortum_Temizle();
    if(Islem_Durumu == TAMAMLANDI)
    {
      Temizleme_Asamasi = Bakim_Kontrolu;
      Islem_Durumu = DEVAM_EDIYOR;
      _ms = EKM.MS;
    }
    else if(Islem_Durumu == ANA_MENU_DON)
    {
      Temizleme_Asamasi = Anamenu_Beklemesi;
      _ms = EKM.MS;
      Islem_Durumu = DEVAM_EDIYOR;
    }
  }
  else if (Temizleme_Asamasi == Bakim_Kontrolu)
  {
    if((EKM.MS - _ms) > 3000)
      Islem_Durumu = Bakim_Kontrol();

    if(Islem_Durumu == TAMAMLANDI)
    {     
      Temizleme_Asamasi = Sifirlama;
      Islem_Durumu = DEVAM_EDIYOR;
      Giris_Sayfa(1,4);
    }
    else if (Islem_Durumu == FILTRE_BITMIS)
    {
      if(EKM.Buzer_Calma_ms)
      {
        _ms = EKM.MS;
        return;
      }
      else if((EKM.MS - _ms)>3000)
      {
        Buzer_Ac;
        EKM.Buzer_Calma_ms = UZUN_BUZER;
        lcd.clear();
        Kayittan_Yazi_Yaz(7,SATIR_1,Filtre_Yeri);
        Kayittan_Yazi_Yaz(1,SATIR_2,Degistirme_Zamani_Yeri);
        Kayittan_Yazi_Yaz(1,SATIR_4,Devam_Icin_ENT_Bas_Yeri);
        Temizleme_Asamasi = Giris_Bekle;
        Islem_Durumu = DEVAM_EDIYOR;
      }     
    }
    else if(Islem_Durumu == FILTRE_AZ)
    {
      if(EKM.Buzer_Calma_ms)
      {
        _ms = EKM.MS;
        return;
      }
      else if((EKM.MS - _ms)>3000)
      {
        Buzer_Ac;
        EKM.Buzer_Calma_ms = UZUN_BUZER;
        lcd.clear();
        Kayittan_Yazi_Yaz(5,SATIR_1,Uyari_Yeri);
        Kayittan_Yazi_Yaz(1,SATIR_2,Filtre_Az_Yeri);
        Kayittan_Yazi_Yaz(1,SATIR_3,Siparis_Edin_Yeri);
        Kayittan_Yazi_Yaz(1,SATIR_4,Devam_Icin_ENT_Bas_Yeri);
        Temizleme_Asamasi = Giris_Bekle;
        Islem_Durumu = DEVAM_EDIYOR;
      }
    }
  }
  else if (Temizleme_Asamasi == Giris_Bekle)
  {
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
     {
       Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
       Temizleme_Asamasi = Sifirlama;
       Butonlari_Temizle();
       Giris_Sayfa(1,4);
     }
  }
  else if (Temizleme_Asamasi == Anamenu_Beklemesi)
  {
    if((EKM.MS - _ms) > UZUN_BUZER)
      {
        Temizleme_Asamasi = Sifirlama;
        Giris_Sayfa(1,4);
      }
  }

}

void Islem_Secimi(void)
{
 // static unsigned char Sayfa = 1;

  if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
    if (EKM.Giris_Sayfa == 2)
    {
      Giris_Sayfa(1,1);
    }
    else
    {
      Bilgiler_Sayfa();
    }
    EKM.Imlec = 1;
    EKM.Giris_Sayfa = 1;
  }

  if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
    if(EKM.Giris_Sayfa == 1)
    {
      if (EKM.Imlec == 1)
      {
       Aractan_Gaz_Cek();
      }
      else if (EKM.Imlec == 2)
      {
        Gaz_Doldurma_Secimi();
      }
      else if (EKM.Imlec == 3)
      {
         Tupten_Gaz_Cek();
      }
      else if (EKM.Imlec == 4)
      {
        lcd.clear();
        EKM.Sayfa = Hortum_Temizleme_Sayfasi;
        Kayittan_Yazi_Yaz(2,SATIR_1,Hortum_Temizleme_1_Yeri);
        Hortum_Temizleme_Sayfa();
      }
    }
    else
    {
      if (EKM.Imlec == 1)
      {
        Valf_Test_Sayfa();
       
      }
      else if (EKM.Imlec == 2)
      {
         Kullanim_Bilgileri();
         
      }
      else if (EKM.Imlec == 3)
      {
         Ayarlar_Giris();
         
      }
      else if (EKM.Imlec == 4)
      {
        Bilgiler_Sayfa();
        EKM.Giris_Sayfa = 1;
      }
    }
  }
  if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
    
    EKM.Imlec_Yonu = ASAGI;
    if(EKM.Imlec < 4)
    {
      EKM.Imlec ++;
      Imlec_Yaz(EKM.Imlec);
       
    }
    else
    {
      if (EKM.Giris_Sayfa == 1)
      {
        EKM.Imlec = 1;
        EKM.Giris_Sayfa = 2;
        lcd.clear();
        Imlec_Yaz(EKM.Imlec);

         Kayittan_Yazi_Yaz(1,SATIR_1,Valf_Test_Yeri);
         Kayittan_Yazi_Yaz(1,SATIR_2,Kullanim_Bilgileri_Yeri);
         Kayittan_Yazi_Yaz(1,SATIR_3,Ayarlar_Yeri);
         Kayittan_Yazi_Yaz(1,SATIR_4,Sensorler_Yeri);
         
      }
    }      
  }
  if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
    EKM.Imlec_Yonu = YUKARI;
    if (EKM.Imlec > 1)
    {
      EKM.Imlec --;
      Imlec_Yaz(EKM.Imlec);
       
    }
    else
    {
      if(EKM.Giris_Sayfa == 2)
      {
        EKM.Imlec = 4;
        EKM.Giris_Sayfa = 1;

        lcd.clear();
        Imlec_Yaz(EKM.Imlec);

         Kayittan_Yazi_Yaz(1,SATIR_1,Aractan_Gaz_Cek_Yeri);
         Kayittan_Yazi_Yaz(1,SATIR_2,Araca_Gaz_Doldur_Yeri);
         Kayittan_Yazi_Yaz(1,SATIR_3,Tupten_Gaz_Cek_Yeri);
         Kayittan_Yazi_Yaz(1,SATIR_4,Hortum_Temizleme_1_Yeri);
         

      }
    }
  }
  // if (Buton[Sag_Buton].Olay == BASILDI_OLAYI)
  // {
  //   Buton[Sag_Buton].Olay = OLAYI_TEMIZLE;
  //   if(EKM.Lcd_Kontrast_Degeri < 255)
  //     EKM.Lcd_Kontrast_Degeri ++;
  //   ledcWrite(0,EKM.Lcd_Kontrast_Degeri);
  // }
  // if (Buton[Sol_Buton].Olay == BASILDI_OLAYI)
  // {
  //   Buton[Sol_Buton].Olay = OLAYI_TEMIZLE;
  //   if(EKM.Lcd_Kontrast_Degeri > 0)
  //     EKM.Lcd_Kontrast_Degeri --;
  //   ledcWrite(0,EKM.Lcd_Kontrast_Degeri);
  // }
}

void Sistem_Bosaltma(void)    ////// guvenliğe gerek yok. bu kısım sadece boşaltma. vakumlama yok
{
  static unsigned char Bosaltma_Adimi = 0;

  if(Bosaltma_Adimi == 0)
  {
    Bosaltma_Adimi = 1;
    EKM.Sayfa = Sistem_Bosaltma_Sayfasi;
    lcd.clear();
    Kayittan_Yazi_Yaz(1,SATIR_1,Sistem_Bosaltma_Yeri);
    SSR_Kontrol(Isitici_Ssr,AC);
    SSR_Kontrol(Yuksek_Basinc_Valf_Ssr,AC);
    SSR_Kontrol(Gaz_Valf_Ssr,AC);
    SSR_Kontrol(Alcak_Basinc_Valf_Ssr,AC);
    SSR_Kontrol(Kompresor_Yag_Valf_Ssr,AC);
    SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,AC);
    SSR_Kontrol(Fan_Ssr,AC);
  }
  else if (Bosaltma_Adimi == 1)
  {
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Bosaltma_Adimi = 0;
      SSR_Kontrol(IPTAL_ET,KAPAT);
      Butonlari_Temizle();
      Giris_Sayfa(1,1);
    }
  }

}

void Bakimlar_Sayfa(void)
{
  static unsigned char Bakim_Adimi = 0;
  static unsigned int _ms = 0;
  if(Bakim_Adimi == 0)
  {
    lcd.clear();
    EKM.Sayfa = Bakim_Sayfasi;
    Bakim_Adimi = 1;
    Kayittan_Yazi_Yaz(1,SATIR_1,Filtre_Degistir_Yeri);
    Kayittan_Yazi_Yaz(1,SATIR_2,Vakum_Yag_Degistir_Yeri);
    EKM.Imlec = 1;
    Imlec_Yaz(EKM.Imlec);
  }
  else if (Bakim_Adimi == 1)
  {
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      EKM.Imlec = 3;
      Bakim_Adimi = 0;
      Ayar_Secim_Sayfa(3);
    }
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      if (EKM.Imlec == 1)
      {
        lcd.clear();
        Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
        EKM.Filtre_Kalan_Gr = EKM.Filtre_Kapasitesi_Kg * 1000;
        Veri_Kaydet_UInt(FILTRE_KALAN_KAPASITE_KAYIT_YERI,EKM.Filtre_Kalan_Gr);
        EKM.Filtre_Sayisi++;
        Veri_Kaydet_Ushort(FILTRE_SAYISI_YERI,EKM.Filtre_Sayisi);
        _ms = EKM.MS;
        Buzer_Ac;
        EKM.Buzer_Calma_ms = UZUN_BUZER;
        Bakim_Adimi = 2;
      }
      else if (EKM.Imlec == 2)
      {
        lcd.clear();
        Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);
        EKM.Toplam_Vakum_Dk = 0;
        Veri_Kaydet_UInt(TOPLAM_VAKUM_SURE_KAYIT_YERI,EKM.Toplam_Vakum_Dk);
        _ms = EKM.MS;
        Buzer_Ac;
        EKM.Buzer_Calma_ms = UZUN_BUZER;
        Bakim_Adimi = 2;
      }
    }
    if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
      EKM.Imlec_Yonu = ASAGI;
      if (EKM.Imlec < 2)
      {
        EKM.Imlec ++;
        Imlec_Yaz(EKM.Imlec);         
      }
    }
    if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
      EKM.Imlec_Yonu = YUKARI;
      if (EKM.Imlec > 1)
      {
        EKM.Imlec --;
        Imlec_Yaz(EKM.Imlec);         
      }
    }
  }
  else if (Bakim_Adimi == 2)
  {
    if((EKM.MS - _ms) > UZUN_BUZER)
    {
      Bakim_Adimi = 0;
      Ayar_Secim_Sayfa(3);
    }
  }

}

void Kompresor_Kapatma_Ayari(void)
{
  static unsigned char Ayar_Adimi = 0;
  static unsigned int _ms = 0;
  
  if(Ayar_Adimi == 0)
  {
    Ayar_Adimi = 1;
    lcd.clear();
    EKM.Sayfa = Kompresor_Kapatma_Ayar_Sayfasi;

    Kayittan_Yazi_Yaz(1,SATIR_1,Kompresor_Kapatma_Ayar_Yeri);
    Lcd_Sayi_Yaz(8,SATIR_3,(EKM.Ref_Atm-EKM.Kompresor_Kapanma),2,4);
  }
  else if (Ayar_Adimi == 1)
  {
    if (Buton[Yukari_Buton].Durum == 1)
    {
      Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
      if((EKM.MS - _ms > 200))
      {
        if (EKM.Kompresor_Kapanma > 0)
        {
          EKM.Kompresor_Kapanma -= 10;
          _ms = EKM.MS;
          Lcd_Sayi_Yaz(8,SATIR_3,(EKM.Ref_Atm-EKM.Kompresor_Kapanma),2,4);                  
        }
      }     
    }
    if (Buton[Asagi_Buton].Durum == 1)
    {
      Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
      if((EKM.MS - _ms > 200))
      {
        if (EKM.Kompresor_Kapanma < EKM.Ref_Atm)
        {
          EKM.Kompresor_Kapanma += 10;
          _ms = EKM.MS;
          Lcd_Sayi_Yaz(8,SATIR_3,(EKM.Ref_Atm-EKM.Kompresor_Kapanma),2,4);                  
        }
      }     
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      lcd.clear();
      Ayar_Adimi = 0;
      EKM.Kompresor_Kapanma = EEPROM.readUInt(KOMPRESOR_KAPANMA_KAYIT_YERI);
      Ayar_Secim_Sayfa(4);
    }
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      Ayar_Adimi = 2;      
      lcd.clear();
      Kayittan_Yazi_Yaz(1,SATIR_1,Tamamlandi_Yeri);

      Veri_Kaydet_UInt(KOMPRESOR_KAPANMA_KAYIT_YERI,EKM.Kompresor_Kapanma);
      _ms = EKM.MS;
      Buzer_Ac;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
    }
  }
  else if (Ayar_Adimi == 2)
  {
    if((EKM.MS - _ms) > UZUN_BUZER)
    {
      Ayar_Adimi = 0;
      Ayar_Secim_Sayfa(4);
    }
  }
}

void Ayar_Secimi(void)
{
  if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
    EKM.Imlec = 1;
    Butonlari_Temizle();
    Giris_Sayfa(2,3);
  }
  if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
    if (EKM.Imlec == 1)
    {
      Cihaz_Ayarlar_Sayfa(1);
      EKM.Imlec = 1;
    }
    else if (EKM.Imlec == 2)
    {
      Kalibrasyon_Secim_Sayfa(1);
    }
    else if (EKM.Imlec == 3)
    {
      Bakimlar_Sayfa();
    }
    else if (EKM.Imlec == 4)
    {
      Kompresor_Kapatma_Ayari();
    }
  }
  if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
    EKM.Imlec_Yonu = ASAGI;
    if (EKM.Imlec < 4)
    {
      EKM.Imlec ++;
      Imlec_Yaz(EKM.Imlec);         
    }
  }
  if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
    EKM.Imlec_Yonu = YUKARI;
    if (EKM.Imlec > 1)
    {
      EKM.Imlec --;
      Imlec_Yaz(EKM.Imlec);         
    }
  }
}

unsigned char Sifre_Kontrol(unsigned int Sifre)
{
//  unsigned int Puk_Sifre = 14538; 

  // if (strcmp(Sifre, EKM.Servis_Sifresi) && strcmp(Sifre, Puk_Sifre ))
  // {
  //   return 0;       /// şifre yanlış
  // }
  // else
  // {
  //   return 1;     /// şifre doğru
  // }
  if(EKM.Sayfa == Ayar_Giris_Sayfasi)
  {
    if((14538 == Sifre))// || ||(0 == Sifre)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else if (EKM.Sayfa == Servis_Giris_Sayfasi)
  {
    if( (25150 == Sifre))//(0 == Sifre) ||
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return 0;
}

unsigned char Plaka_Gir(void)
{
  static unsigned char Sutun_No = 0;//, Boy = 0
  static char Sifre[20] = {0};
  static unsigned char Cizgi_Yeri = 4, Cizgi_Boyu = 4, Cizgi_Satir_Yeri = SATIR_3, Yazi_Satir_Yeri = SATIR_3, Sutun_Atlagi = 1;
  static unsigned int _ms = 0;
  static unsigned char Sayi_Giris_Durumu = 0, Alt_Sinir = 48, Ust_Sinir = 90,Ara_Sinir_Alt = 57,Ara_Sinir_Ust = 65;
  if (Sayi_Giris_Durumu == 0)
  {
    Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 1);
     
    Sayi_Giris_Durumu = 1;
    Cizgi_Yeri = 4;
    Sutun_No = 0;
    Cizgi_Satir_Yeri = SATIR_3;
    Yazi_Satir_Yeri = SATIR_3;
    if ((EKM.MS - _ms) > 300000)  /// 5dk geçmişse
    {
      memset(Sifre,0,sizeof(Sifre));
    }
    lcd.clear();
    memset(Yazilacaklar.Plaka,0,sizeof(Yazilacaklar.Plaka));
    Kayittan_Yazi_Yaz(Cizgi_Yeri,SATIR_1,Plaka_Yeri);
    Yazi_Yaz(Cizgi_Yeri,SATIR_3,Sifre,0);
    lcd.setCursor(Cizgi_Yeri, Yazi_Satir_Yeri);
  }
  if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
    Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 0);
    memset(Sifre,0,sizeof(Sifre));
    Sayi_Giris_Durumu = 0;
    Butonlari_Temizle();
    return 99;			/// geri adım atılcak

  }
  else if (Buton[Sol_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Sol_Buton].Olay = OLAYI_TEMIZLE;
    if (Sutun_No > 0)
    {
      Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 0);
      Cizgi_Yeri -= Sutun_Atlagi;
      Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 1);
      Sutun_No --;       
    }
  }
  else if (Buton[Sag_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Sag_Buton].Olay = OLAYI_TEMIZLE;
    if ((Sifre[Sutun_No] < Alt_Sinir) || (Sifre[Sutun_No] > Ust_Sinir))
      Sifre[Sutun_No] = Alt_Sinir;

    if (Sutun_No < 12)
    {
      Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 0);
      Cizgi_Yeri += Sutun_Atlagi;
      Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 1);
      Sutun_No ++;
       
    }
  }
  else if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
    Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 0);
    Butonlari_Temizle();
    strtok(Sifre, " ");
    strcpy(Yazilacaklar.Plaka, Sifre);
    _ms = EKM.MS;
    Sayi_Giris_Durumu = 0;
    return 1;
    
  }
  else if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;

    Sifre[Sutun_No]++;
    if (Sifre[Sutun_No] < Alt_Sinir)
      Sifre[Sutun_No] = Alt_Sinir + 1;  
    if (Sifre[Sutun_No] > Ust_Sinir)
      Sifre[Sutun_No] = 32;//Alt_Sinir
    if ((Sifre[Sutun_No] > Ara_Sinir_Alt) && (Sifre[Sutun_No] < Ara_Sinir_Ust))
      Sifre[Sutun_No] = Ara_Sinir_Ust;
  //  lcd.setCursor(Cizgi_Yeri, Yazi_Satir_Yeri);
    lcd.print(Sifre[Sutun_No]);
    lcd.setCursor(Cizgi_Yeri, Yazi_Satir_Yeri); 
  }
  if (Buton[Yukari_Buton].Olay == UZUN_BASILDI_OLAYI)
  {
    Buzer_Kapa;
    if (Buton[Yukari_Buton].Durum == 0)
      Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
    Sifre[Sutun_No]++;
    if (Sifre[Sutun_No] < Alt_Sinir)
      Sifre[Sutun_No] = Alt_Sinir + 1;
    if ((Sifre[Sutun_No] > Ara_Sinir_Alt) && (Sifre[Sutun_No] < Ara_Sinir_Ust))
      Sifre[Sutun_No] = Ara_Sinir_Ust;
    if (Sifre[Sutun_No] > Ust_Sinir)
      Sifre[Sutun_No] = 32;//Alt_Sinir
  //  lcd.setCursor(Cizgi_Yeri, Yazi_Satir_Yeri);
    lcd.print(Sifre[Sutun_No]);
    lcd.setCursor(Cizgi_Yeri, Yazi_Satir_Yeri);
    delay(100);
  }
  else if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
  {
    Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
    Sifre[Sutun_No]--;
    if ((Sifre[Sutun_No] > Ust_Sinir) || (Sifre[Sutun_No] < Alt_Sinir))
      Sifre[Sutun_No] = Ust_Sinir;
    if ((Sifre[Sutun_No] > Ara_Sinir_Alt) && (Sifre[Sutun_No] < Ara_Sinir_Ust))
      Sifre[Sutun_No] = Ara_Sinir_Alt;
   // lcd.setCursor(Cizgi_Yeri, Yazi_Satir_Yeri);
    lcd.print(Sifre[Sutun_No]);
    lcd.setCursor(Cizgi_Yeri, Yazi_Satir_Yeri); 
  }
  if (Buton[Asagi_Buton].Olay == UZUN_BASILDI_OLAYI)
  {
    Buzer_Kapa;
    if (Buton[Asagi_Buton].Durum == 0)
      Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
    Sifre[Sutun_No]--;
    if ((Sifre[Sutun_No] > Ust_Sinir) || (Sifre[Sutun_No] < Alt_Sinir))
      Sifre[Sutun_No] = Ust_Sinir;
    if ((Sifre[Sutun_No] > Ara_Sinir_Alt) && (Sifre[Sutun_No] < Ara_Sinir_Ust))
      Sifre[Sutun_No] = Ara_Sinir_Alt;
   // lcd.setCursor(Cizgi_Yeri, Yazi_Satir_Yeri);
    lcd.print(Sifre[Sutun_No]);
    lcd.setCursor(Cizgi_Yeri, Yazi_Satir_Yeri); 
    delay(100);
  }
  
  return 0;
}

unsigned char Wifi_Sifre_Gir(void)
{
  static unsigned char Sutun_No = 0;//, Boy = 0
  static char Sifre[25] = {0};
  static unsigned char Cizgi_Yeri = 0, Cizgi_Boyu = 4, Cizgi_Satir_Yeri = SATIR_3, Yazi_Satir_Yeri = SATIR_3, Sutun_Atlagi = 1;
 // static unsigned int _ms = 0;
  static unsigned char Sayi_Giris_Durumu = 0, Alt_Sinir = 32, Ust_Sinir = 126;
  if (Sayi_Giris_Durumu == 0)
  {    
    memset(Sifre,0,sizeof(Sifre)); 
    Sayi_Giris_Durumu = 1;
    Cizgi_Yeri = 0;
    Cizgi_Satir_Yeri = SATIR_3;
    Yazi_Satir_Yeri = SATIR_3;
    Sutun_No = 0;
    Sutun_Atlagi = 1;
    Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 1);

  }
  else if (Sayi_Giris_Durumu == 1)
  {
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 0);
      memset(Sifre,0,sizeof(Sifre));
      Sayi_Giris_Durumu = 0;
      return 99;			/// geri adım atılcak

    }
    else if (Buton[Sol_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Sol_Buton].Olay = OLAYI_TEMIZLE;
      if (Sutun_No > 0)
      {
        Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 0);
        Cizgi_Yeri -= Sutun_Atlagi;
        Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 1);
        Sutun_No --;       
      }
    }
    else if (Buton[Sag_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Sag_Buton].Olay = OLAYI_TEMIZLE;
      if ((Sifre[Sutun_No] < Alt_Sinir) || (Sifre[Sutun_No] > Ust_Sinir))
        Sifre[Sutun_No] = Alt_Sinir;

      if (Sutun_No < 19)
      {
        Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 0);
        Cizgi_Yeri += Sutun_Atlagi;
        Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 1);
        Sutun_No ++;
        
      }
    }
    else if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      Cizgi_Cek(Cizgi_Yeri, Cizgi_Satir_Yeri, (Cizgi_Yeri + Cizgi_Boyu), Cizgi_Satir_Yeri, 0);
      strtok(Sifre, " ");
      strcpy(EKM.Girilen_Sifre, Sifre);
      memset(Sifre,0,sizeof(Sifre));
      Sayi_Giris_Durumu = 0;
      return 1;
      
    }
    else if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;

      Sifre[Sutun_No]++;
      if (Sifre[Sutun_No] < Alt_Sinir)
        Sifre[Sutun_No] = Alt_Sinir + 1;
      if (Sifre[Sutun_No] > Ust_Sinir)
        Sifre[Sutun_No] = Alt_Sinir;

      lcd.print(Sifre[Sutun_No]);
      lcd.setCursor(Cizgi_Yeri, Yazi_Satir_Yeri); 
    }
    if (Buton[Yukari_Buton].Olay == UZUN_BASILDI_OLAYI)
    {
      Buzer_Kapa;
      if (Buton[Yukari_Buton].Durum == 0)
        Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
      Sifre[Sutun_No]++;
      if (Sifre[Sutun_No] < Alt_Sinir)
        Sifre[Sutun_No] = Alt_Sinir + 1;
      if (Sifre[Sutun_No] > Ust_Sinir)
        Sifre[Sutun_No] = Alt_Sinir;
      
      lcd.print(Sifre[Sutun_No]);
      lcd.setCursor(Cizgi_Yeri, Yazi_Satir_Yeri);
      delay(100);
    }
    else if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
      Sifre[Sutun_No]--;
      if ((Sifre[Sutun_No] > Ust_Sinir) || (Sifre[Sutun_No] < Alt_Sinir))
        Sifre[Sutun_No] = Ust_Sinir;
      
      lcd.print(Sifre[Sutun_No]);
      lcd.setCursor(Cizgi_Yeri, Yazi_Satir_Yeri); 
    }
    if (Buton[Asagi_Buton].Olay == UZUN_BASILDI_OLAYI)
    {
      Buzer_Kapa;
      if (Buton[Asagi_Buton].Durum == 0)
        Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
      Sifre[Sutun_No]--;
      if ((Sifre[Sutun_No] > Ust_Sinir) || (Sifre[Sutun_No] < Alt_Sinir))
        Sifre[Sutun_No] = Ust_Sinir;
      
      lcd.print(Sifre[Sutun_No]);
      lcd.setCursor(Cizgi_Yeri, Yazi_Satir_Yeri);
      delay(100);
    }
  }
  return 0;
}

void Bilgiler_Sayfa(void)
{
  static unsigned char Bilgi_Adimi = 0;
  static unsigned int _ms = 0;

  if(Bilgi_Adimi == 0)
  {
    EKM.Sayfa = Bilgiler_Sayfasi;
    lcd.clear();
      
    Yazi_Yaz(0, SATIR_2, "TANK:", 1);

    if(Terazi_Oku(&EKM.Terazi_Gr))
    {

      Lcd_Sayi_Yaz(5,SATIR_2,EKM.Terazi_Gr,1,5);
    }

    if(EKM.Gaz_Tipi == GAZ_134)
    {
       Kayittan_Yazi_Yaz(0, SATIR_3, R134_A_Yeri);
    }
    else if (EKM.Gaz_Tipi == GAZ_1234YF)
    {
       Kayittan_Yazi_Yaz(0, SATIR_3, R1234_YF_Yeri);
    }
    Yazi_Yaz(0, SATIR_4, "cap:", 1);
    Lcd_Sayi_Yaz(4,SATIR_4,EKM.Tank_Kapasitesi,1,2);
    Kayittan_Yazi_Yaz(12, SATIR_2, C_Yaz_Yeri);
    Lcd_Sayi_Yaz(14,SATIR_2,EKM.Sicaklik,1,3);
    Kayittan_Yazi_Yaz(12, SATIR_3, P_Yaz_Yeri);
    Yazi_Yaz(12, SATIR_4, "V:", 1);

    if(Basinc_Oku(&EKM.Basinc_Br))
    {
      Lcd_Sayi_Yaz(14,SATIR_3,EKM.Basinc_Br,99,3);
    }

    if(Vakum_Oku(&EKM.Vakum_Br))
    {
      Lcd_Sayi_Yaz(14,SATIR_4,EKM.Vakum_Br,1,2);
    }  

     
    Bilgi_Adimi = 1;
  }
  else if(Bilgi_Adimi == 1)
  {    
    Terazi_Oku(&EKM.Terazi_Gr);  
    Basinc_Oku(&EKM.Basinc_Br);
    Vakum_Oku(&EKM.Vakum_Br);          
    Sicaklik_Oku();              
      
    if((EKM.MS - _ms) > 10)
    {
      _ms = EKM.MS;
      if(EKM.Terazi_Gr < 0)
        EKM.Terazi_Gr = 0;
      if(EKM.Basinc_Br < 0)
        EKM.Basinc_Br = 0;
      if(EKM.Vakum_Br < 0)
        EKM.Vakum_Br = 0;
      Lcd_Sayi_Yaz(5,SATIR_2,EKM.Terazi_Gr,1,5);
      Lcd_Sayi_Yaz(14,SATIR_2,EKM.Sicaklik,1,2);
      Lcd_Sayi_Yaz(14,SATIR_3,EKM.Basinc_Br,99,3);
      Lcd_Sayi_Yaz(14,SATIR_4,EKM.Vakum_Br,1,5);   
    }  
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Bilgi_Adimi = 0;
      Butonlari_Temizle();
      Giris_Sayfa(1,1);
    }
            
  } 
  
}

void Gaz_Tipi_Secimi(void)
{
  static unsigned char Secim_Adimi = 0;

  if(Secim_Adimi == 0)
  {
    Secim_Adimi = 1;
    EKM.Sayfa = Gaz_Tipi_Degisim_Sayfasi;
    lcd.clear();
    EKM.Imlec = 1;
    Imlec_Yaz(EKM.Imlec);
    Kayittan_Yazi_Yaz(1,SATIR_1,R134_A_Yeri);
    Kayittan_Yazi_Yaz(1,SATIR_2,R1234_YF_Yeri);
  }
  else if (Secim_Adimi == 1)
  {
    if(Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
      if(EKM.Imlec < 2)
      {
        EKM.Imlec++;
        Imlec_Yaz(EKM.Imlec);
      }
    }
    if(Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
      if(EKM.Imlec > 1)
      {
        EKM.Imlec--;
        Imlec_Yaz(EKM.Imlec);
      }
    }
    if(Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Secim_Adimi = 0;
      Kalibrasyon_Secim_Sayfa(4);
    }
    if(Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      Secim_Adimi = 0;
      
      if(EKM.Imlec == 1)
      {
        EKM.Gaz_Tipi = GAZ_134;
      }
      else if (EKM.Imlec == 2)
      {
        EKM.Gaz_Tipi = GAZ_1234YF;
      }
      Veri_Kaydet_Uchar(GAZ_TIPI_KAYIT_YERI,EKM.Gaz_Tipi);
      Marka_Sayisi();
      EKM.Son_Secilen_Marka = 0;
      Veri_Kaydet_Ushort(SON_SECILEN_MARKA_YERI,EKM.Son_Secilen_Marka);
      Kalibrasyon_Secim_Sayfa(4);
    }
  }
}

void Sistem_Vakumlama(void) /// guvenlik var
{
  static unsigned char Vakumlama_Adimi = 0, Islem_Durumu = 0;
  static unsigned int _ms = 0;
  Vakum_Oku(&EKM.Vakum_Br);

  if(Vakumlama_Adimi == 0)
  {
    EKM.Sayfa = Sistem_Vakumlama_Sayfasi;
    Vakumlama_Adimi = 1;
    lcd.clear();
    Kayittan_Yazi_Yaz(0, SATIR_1, Lutfen_Bekleyin_Yeri);
    SSR_Kontrol(Gaz_Valf_Ssr,AC);
    SSR_Kontrol(Kompresor_Yag_Valf_Ssr,AC);
    SSR_Kontrol(Yag_Giris_Nem_Valf_Ssr,AC);
    SSR_Kontrol(Fan_Ssr,AC);
    _ms = EKM.MS;
  }
  else if (Vakumlama_Adimi == 1)
  {
    if((EKM.MS - _ms) > 1200)
    {
      if(EKM.Vakum_Br > EKM.Ref_Atm + 750)
      {
        Vakumlama_Adimi = Bakim_Kontrolu;
        lcd.clear();
        SSR_Kontrol(IPTAL_ET,KAPAT);
        Kayittan_Yazi_Yaz(0,SATIR_1,Tup_Basinci_Yuksek_Yeri);
        Buzer_Ac;
        EKM.Buzer_Calma_ms = UZUN_BUZER;
      }
      else
      {
        Kayittan_Yazi_Yaz(0,SATIR_1,Sistem_Vakumlaniyor_Yeri);
        Kalan_Sure_Goster(8,SATIR_2,60,0);
        Lcd_Sayi_Yaz(8,SATIR_3,EKM.Vakum_Br,1,4);
        SSR_Kontrol(Isitici_Ssr,AC);        
        SSR_Kontrol(Vakum_Ssr,AC);
        Vakumlama_Adimi = 2;
      }
    }
  }
  else if (Vakumlama_Adimi == 2)
  {
    Islem_Durumu = Kalan_Sure_Goster(8,SATIR_2,60,0);

    if (Islem_Durumu == 1)
    {
      lcd.clear();
      Kayittan_Yazi_Yaz(3,SATIR_1, Tamamlandi_Yeri);
      SSR_Kontrol(IPTAL_ET,KAPAT);
      Vakumlama_Adimi = Bakim_Kontrolu;
      _ms = EKM.MS;

    }
    if(Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Vakumlama_Adimi = 0;
      SSR_Kontrol(IPTAL_ET,KAPAT);
      Ayar_Secim_Sayfa(1);
    }
  }
  else if (Vakumlama_Adimi == Bakim_Kontrolu)
  {
    if((EKM.MS - _ms) > 3000)
      Islem_Durumu = Bakim_Kontrol();

    if(Islem_Durumu == TAMAMLANDI)
    {     
      Vakumlama_Adimi = Sifirlama;
      Islem_Durumu = DEVAM_EDIYOR;
      SSR_Kontrol(IPTAL_ET,KAPAT);
      Ayar_Secim_Sayfa(1);
    }
    else if (Islem_Durumu == FILTRE_BITMIS)
    {
      if(EKM.Buzer_Calma_ms)
      {
        _ms = EKM.MS;
        return;
      }
      else if((EKM.MS - _ms)>3000)
      {
        Buzer_Ac;
        EKM.Buzer_Calma_ms = UZUN_BUZER;
        lcd.clear();
        Kayittan_Yazi_Yaz(7,SATIR_1,Filtre_Yeri);
        Kayittan_Yazi_Yaz(1,SATIR_2,Degistirme_Zamani_Yeri);
        Kayittan_Yazi_Yaz(1,SATIR_4,Devam_Icin_ENT_Bas_Yeri);
        Vakumlama_Adimi = Giris_Bekle;
        Islem_Durumu = DEVAM_EDIYOR;
      }     
    }
    else if(Islem_Durumu == FILTRE_AZ)
    {
      if(EKM.Buzer_Calma_ms)
      {
        _ms = EKM.MS;
        return;
      }
      else if((EKM.MS - _ms)>3000)
      {
        Buzer_Ac;
        EKM.Buzer_Calma_ms = UZUN_BUZER;
        lcd.clear();
        Kayittan_Yazi_Yaz(5,SATIR_1,Uyari_Yeri);
        Kayittan_Yazi_Yaz(1,SATIR_2,Filtre_Az_Yeri);
        Kayittan_Yazi_Yaz(1,SATIR_3,Siparis_Edin_Yeri);
        Kayittan_Yazi_Yaz(1,SATIR_4,Devam_Icin_ENT_Bas_Yeri);
        Vakumlama_Adimi = Giris_Bekle;
        Islem_Durumu = DEVAM_EDIYOR;
      }
    }
  }
  else if (Vakumlama_Adimi == Giris_Bekle)
  {
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
     {
       Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
       Vakumlama_Adimi = Sifirlama;
       SSR_Kontrol(IPTAL_ET,KAPAT);
       Ayar_Secim_Sayfa(1);
     }
  }
  else if (Vakumlama_Adimi == Anamenu_Beklemesi)
  {
    if((EKM.MS - _ms) > UZUN_BUZER)
      {
        Vakumlama_Adimi = Sifirlama;
        SSR_Kontrol(IPTAL_ET,KAPAT);
        Ayar_Secim_Sayfa(1);
      }
  }
}

void Sayfalari_Sorgula(void)
{
  char Id_No[20] = {0};

  if (EKM.Sayfa == Acilis_Sayfasi)
  {
         if (SATIS_YERI == TURKIYE) {Yazi_Yaz(1,SATIR_1,"elcielektronik.com",1);}
    else if (SATIS_YERI == SMARTCON){Yazi_Yaz(1,SATIR_1,"brescon.eu",1)        ;}
    else if (SATIS_YERI == STARKA)  {Yazi_Yaz(1,SATIR_1,"starkaautotech.de",1)        ;}  
      
   



    
    if(EKM.Gaz_Tipi == GAZ_134)
    {
      Kayittan_Yazi_Yaz(1, SATIR_2, R134_A_Yeri);
      
    }
    else if (EKM.Gaz_Tipi == GAZ_1234YF)
    {
      Kayittan_Yazi_Yaz(1, SATIR_2, R1234_YF_Yeri);
    }
    Yazi_Yaz(1,SATIR_3,"Plus_V1R2.28",1);//versiyon no
    //Yazi_Yaz(1,SATIR_3,"Plus_  _",1);
    //Yazi_Yaz(6,SATIR_3,EKM.Yaz_Versiyon,1);
    //Yazi_Yaz(9,SATIR_3,EKM.Yaz_Revizyon,1);
    strcpy(EKM.Yaz_Versiyon,"V1");
    strcpy(EKM.Yaz_Revizyon,"R2.28");
    


    
    sprintf(Id_No,"ID NO:%i",EKM.Chipid);
    Yazi_Yaz(1,SATIR_4,Id_No,1);

    Veri_Kaydet_String(YAZ_VERSIYON_KAYIT_YERI, EKM.Yaz_Versiyon);
    Veri_Kaydet_String(YAZ_REVIZYON_KAYIT_YERI, EKM.Yaz_Revizyon);

    Wifi_Baglanti_Kontrol();
    Butonlari_Temizle();
    Giris_Sayfa(1,1);
  }
  else if (EKM.Sayfa == Giris_Sayfasi)
  {
    Terazi_Oku(&EKM.Terazi_Gr);
	  Vakum_Oku(&EKM.Vakum_Br);
	  Basinc_Oku(&EKM.Basinc_Br);
    Islem_Secimi();
  }
  else if (EKM.Sayfa == Gaz_Doldurma_Secim_Sayfasi)
  {
    Gaz_Doldurma_Secimi();
  }
  else if (EKM.Sayfa == Marka_Secim_Sayfasi)
  {
    Marka_Secim(0);
  }
  else if (EKM.Sayfa == Model_Secim_Sayfasi)
  {
    Modelleri_Goster();
  }
  else if (EKM.Sayfa == Gaz_Doldurma_Sayfasi)
  {
    Gaz_Dolum_Sayfasi();
  }
  else if (EKM.Sayfa == Aractan_Gaz_Cekme_Sayfasi)
  {
    Aractan_Gaz_Cek();
  }
  else if (EKM.Sayfa == Tupten_Gaz_Cekme_Sayfasi)
  {
    Tupten_Gaz_Cek();
  }
  else if (EKM.Sayfa == Hortum_Temizleme_Sayfasi)
  {
    Hortum_Temizleme_Sayfa();
  }
  else if (EKM.Sayfa == Yazilim_Guncelleme_Sayfasi)
  {
    Yazilim_Guncelle();
  }
  else if (EKM.Sayfa == Kullanim_Bilgileri_Sayfasi)
  {
    Kullanim_Bilgileri();
  }
  else if (EKM.Sayfa == Bilgiler_Sayfasi)
  {
    Bilgiler_Sayfa();
  }
  else if (EKM.Sayfa == Vakum_Bakim_Uyari_Sayfasi)
  {
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
     // Acilis_Ekrani();
      EKM.Sayfa = Acilis_Sayfasi;
    }
  }
  else if (EKM.Sayfa == Tarih_Saat_Ayar_Sayfasi)
  {
    Tarih_Saat_Ayari(0);
  }
  else if (EKM.Sayfa == Yazici_Baslik_Ayar_Sayfasi)
  {
    Yazici_Baslik_Ayari(0);
  }
  else if (EKM.Sayfa == Ayar_Giris_Sayfasi)
  {
    Ayarlar_Giris();
  }
  else if (EKM.Sayfa == Ayar_Secim_Sayfasi)
  {
    Ayar_Secimi();
  }
  else if (EKM.Sayfa == Cihaz_Ayarlari_Sayfasi)
  {
    Cihaz_Ayarlari();
  }
  else if (EKM.Sayfa == Kalibrasyon_Secim_Sayfasi)
  {
    Kalibrasyon_Secimi();
  }
  else if (EKM.Sayfa == Terazi_Kalibrasyon_Secim_Sayfasi)
  {
    Terazi_Kalibrasyon_Secimi();
  }
  else if (EKM.Sayfa == Terazi_Dara_Sayfasi)
  {
    Terazi_Dara();
  }
  else if (EKM.Sayfa == Terazi_Kalibrasyon_Sayfasi)
  {
    Terazi_Kalibrasyonu();
  }
  else if (EKM.Sayfa == Basinc_Kalibrasyon_Secim_Sayfasi)
  {
    Basinc_Kalibrasyon_Secimi();
  }
  else if (EKM.Sayfa == Basinc_Dara_Sayfasi)
  {
    Basinc_Dara();
  }
  else if (EKM.Sayfa == Basinc_Kalibrasyon_Sayfasi)
  {
    Basinc_Kalibrasyonu();
  }
  else if (EKM.Sayfa == Vakum_Kalibrasyon_Sayfasi)
  {
    Vakum_Kalibrasyonu();
  }
  else if (EKM.Sayfa == Valf_Test_Sayfasi)
  {
    Valf_Testi();
  }
  else if (EKM.Sayfa == Gaz_Tipi_Degisim_Sayfasi)
  {
    Gaz_Tipi_Secimi();
  }
  else if (EKM.Sayfa == Dil_Secim_Sayfasi)
  {
    Dil_Secimi();
  }
  else if (EKM.Sayfa == Bakim_Sayfasi)
  {
    Bakimlar_Sayfa();
  }
  else if (EKM.Sayfa == Sistem_Bosaltma_Sayfasi)
  {
    Sistem_Bosaltma();
  }
  else if (EKM.Sayfa == Sistem_Vakumlama_Sayfasi)
  {
    Sistem_Vakumlama();
  }
  else if (EKM.Sayfa == Kompresor_Kapatma_Ayar_Sayfasi)
  {
    Kompresor_Kapatma_Ayari();
  }
  else if (EKM.Sayfa == Servis_Giris_Sayfasi)
  {
    Servis_Ayar_Giris();
  }
  else if (EKM.Sayfa == Servis_Ayar_Secim_Sayfasi)
  {
    Servis_Ayar_Secimi();
  }
  else if (EKM.Sayfa == Yazici_Secim_Ayar_Sayfasi)
  {
    Yazici_Secimi();
  }
  else if (EKM.Sayfa == Tank_Kapasite_Ayar_Sayfasi)
  {
    Tank_Kapasite_Ayari();
  }
  else if (EKM.Sayfa == Filtre_Kapasite_Ayar_Sayfasi)
  {
    Filtre_Kapasite_Ayari();
  }
  else if (EKM.Sayfa == Diger_Ayarlar_Sayfasi)
  {
    Diger_Ayarlar_Secimi();
  }
  else if (EKM.Sayfa == Gonderici_Mail_Giris_Sayfasi)
  {
    Gonderici_Mail_Girisi();
  }
  else if (EKM.Sayfa == Wifi_Baglanma_Sayfasi)
  {
    Wifi_Baglanma_Sayfa();
  }

}

unsigned char Marka_Sayisi(void)
{
  unsigned short ix = 0;

  if(EKM.Gaz_Tipi == GAZ_134)
  {
    while(strcmp("*",marka_134[ix]))
    {
      ix++;
    }
  }
  else if(EKM.Gaz_Tipi == GAZ_1234YF)
  {
    while(strcmp("*",marka_1234yf[ix]))
    {
      ix++;
    }
  }
  
  EKM.Marka_Sayisi = ix;
  ix = 0;

  return EKM.Marka_Sayisi;

  // if(EKM.Gaz_Tipi == 0)
  // {
  //   while(strcmp("*",model_134[ix]))
  //   {
  //     ix++;
  //   }
  //   EKM.Model_Sayisi = ix;
  // }
  // else
  // {
  //   while(strcmp("*",model_1234yf[ix]))
  //   {
  //     ix++;
  //   }
  //   EKM.Model_Sayisi = ix;
  // }
  // return EKM.Marka_Sayisi;
}

void Markari_Goster(unsigned char Marka_No)
{

  if(EKM.Gaz_Tipi == GAZ_134)
  {
    if(EKM.Marka_Sayisi > (Marka_No + 3))
    {
      Yazi_Yaz(1,SATIR_1,(char*)marka_134[Marka_No],1);
      Yazi_Yaz(1,SATIR_2,(char*)marka_134[Marka_No+1],1);
      Yazi_Yaz(1,SATIR_3,(char*)marka_134[Marka_No+2],1);
      Yazi_Yaz(1,SATIR_4,(char*)marka_134[Marka_No+3],1);
    }
    else
    {
      Yazi_Yaz(1,SATIR_1,(char*)marka_134[EKM.Marka_Sayisi-4],1);
      Yazi_Yaz(1,SATIR_2,(char*)marka_134[EKM.Marka_Sayisi-3],1);
      Yazi_Yaz(1,SATIR_3,(char*)marka_134[EKM.Marka_Sayisi-2],1);
      Yazi_Yaz(1,SATIR_4,(char*)marka_134[EKM.Marka_Sayisi-1],1);
    }
  }
  else if(EKM.Gaz_Tipi == GAZ_1234YF)
  {
    if(EKM.Marka_Sayisi > (Marka_No + 3))
    {
      Yazi_Yaz(1,SATIR_1,(char*)marka_1234yf[Marka_No],1);
      Yazi_Yaz(1,SATIR_2,(char*)marka_1234yf[Marka_No+1],1);
      Yazi_Yaz(1,SATIR_3,(char*)marka_1234yf[Marka_No+2],1);
      Yazi_Yaz(1,SATIR_4,(char*)marka_1234yf[Marka_No+3],1);
    }
    else
    {
      Yazi_Yaz(1,SATIR_1,(char*)marka_1234yf[EKM.Marka_Sayisi-4],1);
      Yazi_Yaz(1,SATIR_2,(char*)marka_1234yf[EKM.Marka_Sayisi-3],1);
      Yazi_Yaz(1,SATIR_3,(char*)marka_1234yf[EKM.Marka_Sayisi-2],1);
      Yazi_Yaz(1,SATIR_4,(char*)marka_1234yf[EKM.Marka_Sayisi-1],1);
    }
  }

}

void Model_Yerini_Bul_ve_Goster(void)
{
  char Marka[15] = {0}, Model[100] = {0}, Yil[15] = {0};
  char *tok;
  unsigned short ix = 0;
  
  if(EKM.Gaz_Tipi == GAZ_134)
  {
    do
    {
      if(strcmp(model_134[ix] , "*") != 0)
      {
        memcpy(Model,model_134[ix],strlen(model_134[ix]));
        tok = strtok(Model,"#");
        ix++;
      }
      else
      {
        ix = 55555;
        break;
      }

    } while (strcmp(EKM.Secilen_Marka,tok));

    if(ix != 55555)
    {
      ix --;
      EKM.Secili_Model_Yeri = ix;  

      memset(Marka,0x00,strlen(Marka));
      lcd.clear();
      strcpy(Marka,tok);
      Yazi_Yaz(0,SATIR_1,Marka,1);
      
      memset(Model,0x00,strlen(Model));
      tok = strtok(NULL,"#");
      strcpy(Model,tok);
      Yazi_Yaz(0,SATIR_2,Model,99);

      tok = strtok(NULL,"#");
      strcpy(Yil,tok);
      Yazi_Yaz(0,SATIR_4,Yil,1);

      tok = strtok(NULL,"#");
      EKM.Dolum_Miktari_Gr = atoi(tok);
      Yazi_Yaz(13,SATIR_4,tok,1);
       
    }    
  }
  else if(EKM.Gaz_Tipi == GAZ_1234YF)
  {
    do
    {
      if(strcmp(model_1234yf[ix] , "*") != 0)
      {
        memcpy(Model,model_1234yf[ix],strlen(model_1234yf[ix]));
        tok = strtok(Model,"#");
        ix++;
      }
      else
      {
        ix = 55555;
        break;
      }

    } while (strcmp(EKM.Secilen_Marka,tok));

    if(ix != 55555)
    {
      ix --;
      EKM.Secili_Model_Yeri = ix;

      memset(Marka,0x00,strlen(Marka));
      lcd.clear();
      strcpy(Marka,tok);
      Yazi_Yaz(0,SATIR_1,Marka,1);
      
      memset(Model,0x00,strlen(Model));
      tok = strtok(NULL,"#");
      strcpy(Model,tok);
      Yazi_Yaz(0,SATIR_2,Model,99);

      tok = strtok(NULL,"#");
      strcpy(Yil,tok);
      Yazi_Yaz(0,SATIR_4,Yil,1);

      tok = strtok(NULL,"#");
      EKM.Dolum_Miktari_Gr = atoi(tok);
      Yazi_Yaz(13,SATIR_4,tok,1);
       
    }    
  }

}

void Modelleri_Goster(void)
{
  unsigned static short ix = 0;
  unsigned static char Gosterim_Adimi = 0;
  char Marka[15] = {0}, Model[100] = {0}, Yil[15] = {0};
  char *tok;

  if(Gosterim_Adimi == 0)
  {
    ix = EKM.Secili_Model_Yeri;
    Gosterim_Adimi ++;
  }
  else if(Gosterim_Adimi == 1)
  {
    if(EKM.Gaz_Tipi == GAZ_134)
    {
      if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
      {
        Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
        ix++;

        if(strcmp(model_134[ix] , "*") != 0)
        {
          memcpy(Model,model_134[ix],strlen(model_134[ix]));
          tok = strtok(Model,"#");
          if(strcmp(EKM.Secilen_Marka,tok) == 0)      /// seçilen marka ise
          {
            memset(Marka,0x00,strlen(Marka));
            strcpy(Marka,tok);
            lcd.clear();
            Yazi_Yaz(0,SATIR_1,Marka,1);
            
            memset(Model,0x00,strlen(Model));
            tok = strtok(NULL,"#");
            strcpy(Model,tok);
            Yazi_Yaz(0,SATIR_2,Model,99);

            tok = strtok(NULL,"#");
            strcpy(Yil,tok);
            Yazi_Yaz(0,SATIR_4,Yil,1);

            tok = strtok(NULL,"#");
            EKM.Dolum_Miktari_Gr = atoi(tok);           
            Yazi_Yaz(13,SATIR_4,tok,1);
             
          }
          else
          {
            ix --;        //// modeller bitti. Arttırmayı geri aldık
            // Son_Model_Yeri = ix - 1;
            // ix = EKM.Secili_Model_Yeri;
          }
          
        }
      }
      else if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
      {
        Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
        ix--;

        if(strcmp(model_134[ix] , "*") != 0)
        {
          memcpy(Model,model_134[ix],strlen(model_134[ix]));
          tok = strtok(Model,"#");
          if(strcmp(EKM.Secilen_Marka,tok) == 0)      /// seçilen marka ise
          {
            memset(Marka,0x00,strlen(Marka));
            strcpy(Marka,tok);
            lcd.clear();
            Yazi_Yaz(0,SATIR_1,Marka,1);
            
            memset(Model,0x00,strlen(Model));
            tok = strtok(NULL,"#");
            strcpy(Model,tok);
            Yazi_Yaz(0,SATIR_2,Model,99);

            tok = strtok(NULL,"#");
            strcpy(Yil,tok);          
            Yazi_Yaz(0,SATIR_4,Yil,1);

            tok = strtok(NULL,"#");
            EKM.Dolum_Miktari_Gr = atoi(tok);
            Yazi_Yaz(13,SATIR_4,tok,1);
             
          }
          else
          {
            ix ++;        //// modeller bitti. Azaltmayı geri aldık
          }
          
        }
      }
      else if(Buton[Giris_Buton].Olay == BASILDI_OLAYI)
      {
        Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
        Gosterim_Adimi = 0;
        Gaz_Dolum_Sayfasi();
      }
      else if(Buton[Geri_Buton].Olay == BASILDI_OLAYI)
      {
        Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
        Gosterim_Adimi = 0;
        Marka_Secim(EKM.Son_Secilen_Marka);               //// son girilen markayı göstermesi için 9999 girildi
        EKM.Sayfa = Marka_Secim_Sayfasi;
      }
    }
    else if(EKM.Gaz_Tipi == GAZ_1234YF)
    {
      if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
      {
        Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
        ix++;

        if(strcmp(model_1234yf[ix] , "*") != 0)
        {
          memcpy(Model,model_1234yf[ix],strlen(model_1234yf[ix]));
          tok = strtok(Model,"#");
          if(strcmp(EKM.Secilen_Marka,tok) == 0)      /// seçilen marka ise
          {
            memset(Marka,0x00,strlen(Marka));
            strcpy(Marka,tok);
            lcd.clear();
            Yazi_Yaz(0,SATIR_1,Marka,1);
            
            memset(Model,0x00,strlen(Model));
            tok = strtok(NULL,"#");
            strcpy(Model,tok);
            Yazi_Yaz(0,SATIR_2,Model,99);

            tok = strtok(NULL,"#");
            strcpy(Yil,tok);
            Yazi_Yaz(0,SATIR_4,Yil,1);

            tok = strtok(NULL,"#");
            EKM.Dolum_Miktari_Gr = atoi(tok);
            Yazi_Yaz(13,SATIR_4,tok,1);
             
          }
          else
          {
            ix --;        //// modeller bitti. Arttırmayı geri aldık
          }
          
        }
      }
      else if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
      {
        Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
        ix--;

        if(strcmp(model_1234yf[ix] , "*") != 0)
        {
          memcpy(Model,model_1234yf[ix],strlen(model_1234yf[ix]));
          tok = strtok(Model,"#");
          if(strcmp(EKM.Secilen_Marka,tok) == 0)      /// seçilen marka ise
          {
            memset(Marka,0x00,strlen(Marka));
            strcpy(Marka,tok);
            lcd.clear();
            Yazi_Yaz(0,SATIR_1,Marka,1);
            
            memset(Model,0x00,strlen(Model));
            tok = strtok(NULL,"#");
            strcpy(Model,tok);
            Yazi_Yaz(0,SATIR_2,Model,99);

            tok = strtok(NULL,"#");
            strcpy(Yil,tok);
            Yazi_Yaz(0,SATIR_4,Yil,1);

            tok = strtok(NULL,"#");
            EKM.Dolum_Miktari_Gr = atoi(tok);
            Yazi_Yaz(13,SATIR_4,tok,1);
             
          }
          else
          {
            ix ++;        //// modeller bitti. Azaltmayı geri aldık
          }
          
        }
      }
      else if(Buton[Giris_Buton].Olay == BASILDI_OLAYI)
      {
        Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
        Gosterim_Adimi = 0;
        Gaz_Dolum_Sayfasi();
        
      }
      else if(Buton[Geri_Buton].Olay == BASILDI_OLAYI)
      {
        Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
        Gosterim_Adimi = 0;
        Marka_Secim(EKM.Son_Secilen_Marka);               //// son girilen markayı göstermesi için 9999 girildi
        EKM.Sayfa = Marka_Secim_Sayfasi;
      }
    }
  }
}

void Marka_Secim(unsigned short No)
{
  
  static unsigned char Secim_Adimi = 0, Marka_No = 0, Imlec_Yeri = 1;

  if (Secim_Adimi == 0)
  {
    Marka_No = No;
    if(No < EKM.Marka_Sayisi - 3)
    {
      if(No == 0)
      {
        Imlec_Yeri = 1;
      }
      EKM.Imlec = Imlec_Yeri;
      
    }
    else
    {
      
      if(No == (EKM.Marka_Sayisi - 4))
      {
        EKM.Imlec = 1;
      }
      else if(No == (EKM.Marka_Sayisi - 3))
      {
        EKM.Imlec = 2;
      }
      else if(No == (EKM.Marka_Sayisi - 2))
      {
        EKM.Imlec = 3;
      }
      else if(No == (EKM.Marka_Sayisi - 1))
      {
        EKM.Imlec = 4;
      }
    }
    lcd.clear();
    // Imlec_Yaz(EKM.Imlec);
    // Markari_Goster(Marka_No);
    Secim_Adimi = 1;

    if(EKM.Imlec == 1)
    {
      lcd.clear();
      Imlec_Yaz(EKM.Imlec);
      Markari_Goster(Marka_No);
       
    }
    else if(EKM.Imlec == 2)
    {
      lcd.clear();
      Imlec_Yaz(EKM.Imlec);
      Markari_Goster(Marka_No-1);
       
    }
    else if(EKM.Imlec == 3)
    {
      lcd.clear();
      Imlec_Yaz(EKM.Imlec);
      Markari_Goster(Marka_No-2);
       
    }
    else if(EKM.Imlec == 4)
    {
      lcd.clear();
      Imlec_Yaz(EKM.Imlec);
      Markari_Goster(Marka_No-3);
       
    }
  }    
  else if (Secim_Adimi == 1)
  {
    if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;

      if(Marka_No < EKM.Marka_Sayisi-1)
        Marka_No++;
      else
      {
        Marka_No = 0;
        EKM.Imlec = 0; 
      }

      if(EKM.Imlec < 4)
        EKM.Imlec++;

      if(EKM.Imlec == 1)
      {
        lcd.clear();
        Imlec_Yaz(EKM.Imlec);
        Markari_Goster(Marka_No);
        
      }
      else if(EKM.Imlec == 2)
      {
        lcd.clear();
        Imlec_Yaz(EKM.Imlec);
        Markari_Goster(Marka_No-1);
        
      }
      else if(EKM.Imlec == 3)
      {
        lcd.clear();
        Imlec_Yaz(EKM.Imlec);
        Markari_Goster(Marka_No-2);
        
      }
      else if(EKM.Imlec == 4)
      {
        lcd.clear();
        Imlec_Yaz(EKM.Imlec);
        Markari_Goster(Marka_No-3);
        
      }
    }
    if (Buton[Asagi_Buton].Olay == UZUN_BASILDI_OLAYI)
    {
      Buzer_Kapa;
      if (Buton[Asagi_Buton].Durum == 0)
        Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
      
      if(Marka_No < EKM.Marka_Sayisi-1)
        Marka_No++;
      else
      {
        Marka_No = 0;
        EKM.Imlec = 0; 
      }

      if(EKM.Imlec < 4)
        EKM.Imlec++;

      if(EKM.Imlec == 1)
      {
        lcd.clear();
        Imlec_Yaz(EKM.Imlec);
        Markari_Goster(Marka_No);
        
      }
      else if(EKM.Imlec == 2)
      {
        lcd.clear();
        Imlec_Yaz(EKM.Imlec);
        Markari_Goster(Marka_No-1);
        
      }
      else if(EKM.Imlec == 3)
      {
        lcd.clear();
        Imlec_Yaz(EKM.Imlec);
        Markari_Goster(Marka_No-2);
        
      }
      else if(EKM.Imlec == 4)
      {
        lcd.clear();
        Imlec_Yaz(EKM.Imlec);
        Markari_Goster(Marka_No-3);
        
      }
      Bekle_ms(100);
    }
    if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;

      if(Marka_No > 0)
        Marka_No--;
      else
      {
        Marka_No = EKM.Marka_Sayisi-1;
        EKM.Imlec = 5;
      }
        

      if(EKM.Imlec > 1)
        EKM.Imlec--;

      if(EKM.Imlec == 1)
      {
        lcd.clear();
        Imlec_Yaz(EKM.Imlec);
        Markari_Goster(Marka_No);
        
      }
      else if(EKM.Imlec == 2)
      {
        lcd.clear();
        Imlec_Yaz(EKM.Imlec);
        Markari_Goster(Marka_No-1);
        
      }
      else if(EKM.Imlec == 3)
      {
        lcd.clear();
        Imlec_Yaz(EKM.Imlec);
        Markari_Goster(Marka_No-2);
        
      }
      else if(EKM.Imlec == 4)
      {
        lcd.clear();
        Imlec_Yaz(EKM.Imlec);
        Markari_Goster(Marka_No-3);
        
      }
    }
    if (Buton[Yukari_Buton].Olay == UZUN_BASILDI_OLAYI)
    {
      Buzer_Kapa;
      if (Buton[Yukari_Buton].Durum == 0)
        Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;

      if(Marka_No > 0)
        Marka_No--;
      else
      {
        Marka_No = EKM.Marka_Sayisi-1;
        EKM.Imlec = 5;
      }
        

      if(EKM.Imlec > 1)
        EKM.Imlec--;

      if(EKM.Imlec == 1)
      {
        lcd.clear();
        Imlec_Yaz(EKM.Imlec);
        Markari_Goster(Marka_No);
        
      }
      else if(EKM.Imlec == 2)
      {
        lcd.clear();
        Imlec_Yaz(EKM.Imlec);
        Markari_Goster(Marka_No-1);
        
      }
      else if(EKM.Imlec == 3)
      {
        lcd.clear();
        Imlec_Yaz(EKM.Imlec);
        Markari_Goster(Marka_No-2);
        
      }
      else if(EKM.Imlec == 4)
      {
        lcd.clear();
        Imlec_Yaz(EKM.Imlec);
        Markari_Goster(Marka_No-3);
        
      }
      Bekle_ms(100);
    }
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      Imlec_Yeri = EKM.Imlec;
      Secim_Adimi = 0;
      memset(EKM.Secilen_Marka,0,sizeof(EKM.Secilen_Marka));
      if(EKM.Gaz_Tipi == GAZ_134)
      {
        memcpy(EKM.Secilen_Marka,marka_134[Marka_No],strlen(marka_134[Marka_No]));
      }
      else if (EKM.Gaz_Tipi == GAZ_1234YF)
      {
        memcpy(EKM.Secilen_Marka,marka_1234yf[Marka_No],strlen(marka_1234yf[Marka_No]));
      }
          
      
      Model_Yerini_Bul_ve_Goster();
    // Modelleri_Goster(EKM.Secilen_Marka);
      EKM.Son_Secilen_Marka = Marka_No;
      Veri_Kaydet_Ushort(SON_SECILEN_MARKA_YERI,EKM.Son_Secilen_Marka);
      EKM.Sayfa = Model_Secim_Sayfasi;
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
      {
        Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
        Secim_Adimi = 0;
        Butonlari_Temizle();
        Gaz_Doldurma_Secimi();
      }
  }
}

void guncelle_hata(void) // bağlandı ancak serverde dosya bulunamadı     //// started but no file found on server
{
 
  lcd.clear();
  Buzer_Ac;
  EKM.Buzer_Calma_ms = 3000;
  Kayittan_Yazi_Yaz(5,SATIR_2,Yaziliminiz_Yeri);
  Kayittan_Yazi_Yaz(5,SATIR_3,Guncel_Yeri);
  
  delay(3000);
}

void ag_yok_hata()  // aga bağlanamadı. //// Failed to start network.
{
  lcd.clear();
  Buzer_Ac;
  EKM.Buzer_Calma_ms = 3000;
  Kayittan_Yazi_Yaz(1,SATIR_1,Baglanti_Hatasi_Yeri);   
  delay(3000);

}

void Yazilim_Guncelle(void)
{
  static unsigned char n = 0, Secili_Satir_Yeri = 0, Sifre_Girisi = 0;//u = 0,
  static unsigned char Guncelleme_Adimi = 0;

  //static uint32_t chipid = 0;            // mac adresinden elde ediliyor
  //uint64_t chipidver = 0;
  static char Baglanilacak_Wifi[50] = {0};
  static char Baglanilacak_Sifre[25] = {0};
  char Indirme_Linki[100] = {0};
  char Gonderme_Linki[200] = {0};
  char Istatislikler[50] = {0};     // max 44 hane olabilir. 10 x 3 + filtre kalan 5, filtre adet 5 = 40 hane + 4 adet 
  char Chip_ID[10] = {0};
  static char Rev[10] = {0}, Ver[10] = {0};

  if (Guncelleme_Adimi == 0)
  {
    lcd.clear();
    EKM.Sayfa = Yazilim_Guncelleme_Sayfasi;
    Kayittan_Yazi_Yaz(0,SATIR_1, Lutfen_Bekleyin_Yeri);  
    if(EKM.Wifi_Durumu != BAGLANDI)
    {
      WiFi.mode(WIFI_STA);
      WiFi.disconnect();
      delay(100);
      n = WiFi.scanNetworks();
      Guncelleme_Adimi = 1;
    }
    else
    {
      Guncelleme_Adimi = 10;
      Kayittan_Yazi_Yaz(0,SATIR_2,Kontrol_Ediliyor_Yeri);
    }    
  }
  else if (Guncelleme_Adimi == 1)			//// bulunanlara aktarma
  {
    if (n != 0)
    {      
      lcd.clear();
        
      Kayittan_Yazi_Yaz(0, SATIR_1, Yazilim_Guncelleme_Yeri);
      for (int i = 0; i < n; ++i)
      {
        // Print SSID and RSSI for each network found
        //        Serial.print(i + 1);
        //        Serial.print(": ");
        stpcpy(EKM.Bulunan_Wifiler[i], WiFi.SSID(i).c_str());
        //        Serial.println(EKM.Bulunan_Wifiler[i]);//WiFi.SSID(i)
        //        Serial.print(" (");
        //        Serial.print(WiFi.RSSI(i));
        //        Serial.print(")");
        //        Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
        if (i < 4)
        {
          // if (i == 0)
              
          // else
              

          Yazi_Yaz(1, (SATIR_1 + i), EKM.Bulunan_Wifiler[i], 1);
           
        }
        if (strcmp(EKM.Kayitli_Wifi, EKM.Bulunan_Wifiler[i]) == 0) //// kayıtlı wifi bulundu
        {
          Guncelleme_Adimi = 7;   // kayıtlı bulundu yeri
          //          break;        //// başkasına bağlanacaksa tekrar tarama yapmayalım. hepsini tarayıp çıkalım diye break iptal edildi
        }
        else
        {
          if (Guncelleme_Adimi != 7)
            Guncelleme_Adimi = 2;   //// bulunanları gösterme yeri
        }
        delay(10);
      }
    }
    else
    {       
      lcd.clear();
      Kayittan_Yazi_Yaz(0, SATIR_1, Wifi_Bulunamadi_Yeri);
        // BAðLANIYOR//CONNECTING
      Guncelleme_Adimi = 0;
      Diger_Ayarlar_Secim_Sayfa(1);
      return;
    }

  }
  else if (Guncelleme_Adimi == 2)		/// secim öncesi
  {
    EKM.Imlec = 0;
    Secili_Satir_Yeri = 1;      //// önemli.!!!!
     
    lcd.clear();
      
    Yazi_Yaz(1, SATIR_1, EKM.Bulunan_Wifiler[0], 19);
    Yazi_Yaz(1, SATIR_2, EKM.Bulunan_Wifiler[1], 19);
    Yazi_Yaz(1, SATIR_3, EKM.Bulunan_Wifiler[2], 19);
    Yazi_Yaz(1, SATIR_4, EKM.Bulunan_Wifiler[3], 19);
     
    Guncelleme_Adimi = 3;
    Imlec_Yaz(Secili_Satir_Yeri);
  }
  else if (Guncelleme_Adimi == 3)		// wifi secim
  {
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Guncelleme_Adimi = 0;
      Diger_Ayarlar_Secim_Sayfa(1);
    }
    if (Buton[Yukari_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
      if (EKM.Imlec > 0)
      {
        EKM.Imlec --;
        if (Secili_Satir_Yeri > 1)
          Secili_Satir_Yeri --;

        if (Secili_Satir_Yeri == 1)
        {
          lcd.clear();
          Imlec_Yaz(Secili_Satir_Yeri);
          Yazi_Yaz(1, SATIR_1, EKM.Bulunan_Wifiler[EKM.Imlec], 19);
          Yazi_Yaz(1, SATIR_2, EKM.Bulunan_Wifiler[EKM.Imlec + 1], 19);
          Yazi_Yaz(1, SATIR_3, EKM.Bulunan_Wifiler[EKM.Imlec + 2], 19);
          Yazi_Yaz(1, SATIR_4, EKM.Bulunan_Wifiler[EKM.Imlec + 3], 19);
        }
        else if (Secili_Satir_Yeri == 2)
        {
          lcd.clear();
          Imlec_Yaz(Secili_Satir_Yeri);
          Yazi_Yaz(1, SATIR_1, EKM.Bulunan_Wifiler[EKM.Imlec - 1], 19);
          Yazi_Yaz(1, SATIR_2, EKM.Bulunan_Wifiler[EKM.Imlec], 19);
          Yazi_Yaz(1, SATIR_3, EKM.Bulunan_Wifiler[EKM.Imlec + 1], 19);
          Yazi_Yaz(1, SATIR_4, EKM.Bulunan_Wifiler[EKM.Imlec + 2], 19);  
        }
        else if (Secili_Satir_Yeri == 3)
        {
          lcd.clear();
          Imlec_Yaz(Secili_Satir_Yeri);
          Yazi_Yaz(1, SATIR_1, EKM.Bulunan_Wifiler[EKM.Imlec - 2], 19);
          Yazi_Yaz(1, SATIR_2, EKM.Bulunan_Wifiler[EKM.Imlec - 1], 19);
          Yazi_Yaz(1, SATIR_3, EKM.Bulunan_Wifiler[EKM.Imlec], 19);
          Yazi_Yaz(1, SATIR_4, EKM.Bulunan_Wifiler[EKM.Imlec + 1], 19);  
        }
        else if (Secili_Satir_Yeri == 4)
        {
          lcd.clear();
          Imlec_Yaz(Secili_Satir_Yeri);
          Yazi_Yaz(1, SATIR_1, EKM.Bulunan_Wifiler[EKM.Imlec - 3], 19);
          Yazi_Yaz(1, SATIR_2, EKM.Bulunan_Wifiler[EKM.Imlec - 2], 19);
          Yazi_Yaz(1, SATIR_3, EKM.Bulunan_Wifiler[EKM.Imlec - 1], 19);
          Yazi_Yaz(1, SATIR_4, EKM.Bulunan_Wifiler[EKM.Imlec], 19);           
        }
      }
    }
    if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
      if (EKM.Imlec < n - 1)
      {
        EKM.Imlec ++;
        if (Secili_Satir_Yeri < 4)
          Secili_Satir_Yeri ++;        

        if (Secili_Satir_Yeri == 2)     /// 1 den başladığındna ==1 olamaz. en az 2 olabilir
        {
          lcd.clear();
          Imlec_Yaz(Secili_Satir_Yeri);
          Yazi_Yaz(1, SATIR_1, EKM.Bulunan_Wifiler[EKM.Imlec - 1], 19);
          Yazi_Yaz(1, SATIR_2, EKM.Bulunan_Wifiler[EKM.Imlec], 19);
          Yazi_Yaz(1, SATIR_3, EKM.Bulunan_Wifiler[EKM.Imlec + 1], 19);
          Yazi_Yaz(1, SATIR_4, EKM.Bulunan_Wifiler[EKM.Imlec + 2], 19);  
        }
        else if (Secili_Satir_Yeri == 3)
        {
          lcd.clear();
          Imlec_Yaz(Secili_Satir_Yeri);
          Yazi_Yaz(1, SATIR_1, EKM.Bulunan_Wifiler[EKM.Imlec - 2], 19);
          Yazi_Yaz(1, SATIR_2, EKM.Bulunan_Wifiler[EKM.Imlec - 1], 19);
          Yazi_Yaz(1, SATIR_3, EKM.Bulunan_Wifiler[EKM.Imlec], 19);
          Yazi_Yaz(1, SATIR_4, EKM.Bulunan_Wifiler[EKM.Imlec + 1], 19);                 
        }
        else if (Secili_Satir_Yeri == 4)
        {
          lcd.clear();
          Imlec_Yaz(Secili_Satir_Yeri);
          Yazi_Yaz(1, SATIR_1, EKM.Bulunan_Wifiler[EKM.Imlec - 3], 19);
          Yazi_Yaz(1, SATIR_2, EKM.Bulunan_Wifiler[EKM.Imlec - 2], 19);
          Yazi_Yaz(1, SATIR_3, EKM.Bulunan_Wifiler[EKM.Imlec - 1], 19);            
          Yazi_Yaz(1, SATIR_4, EKM.Bulunan_Wifiler[EKM.Imlec], 19);
        }
      }
    }
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      strcpy(Baglanilacak_Wifi, EKM.Bulunan_Wifiler[EKM.Imlec]);
       
      lcd.clear();
      Kayittan_Yazi_Yaz(0, SATIR_1, Wifi_Sifre_Girin_Yeri);
       
      Guncelleme_Adimi = 5;
      memset(Baglanilacak_Sifre, 0, sizeof(Baglanilacak_Sifre));
    }
  }
  else if (Guncelleme_Adimi == 5)   //// wifi şifre girme yeri
  {
    Sifre_Girisi = Wifi_Sifre_Gir();
    if (Sifre_Girisi == 99)
    {
      Guncelleme_Adimi = 2;
    }
    else if (Sifre_Girisi == 1)
    {
      Guncelleme_Adimi = 6;
      strcpy(Baglanilacak_Sifre, EKM.Girilen_Sifre);    //// eskiden kırıntı kalmasın diye yazıldı ve baglanılacak sifre ile devam edilecek
      
    }
  }
  else if (Guncelleme_Adimi == 6)   /// wifi bağlanma yeri
  {
    //WiFiMulti.addAP(Baglanilacak_Wifi, Baglanilacak_Sifre);
    WiFi.begin(Baglanilacak_Wifi, Baglanilacak_Sifre);
    lcd.clear();

    Kayittan_Yazi_Yaz(0, SATIR_1, Lutfen_Bekleyin_Yeri);
    Kayittan_Yazi_Yaz(0, SATIR_2,Kontrol_Ediliyor_Yeri);
     
    int wifi_ilk_zaman = millis();

    while (millis() - wifi_ilk_zaman < 30000)
    {
      if (WiFi.status() == WL_CONNECTED)   //((WiFiMulti.run() == WL_CONNECTED))
      {
        lcd.clear();
        Kayittan_Yazi_Yaz(0, SATIR_1, Baglandi_Yaz_Yeri);
        Yazi_Yaz(0, SATIR_2, Baglanilacak_Wifi, 1);
        Kayittan_Yazi_Yaz(0, SATIR_3, Lutfen_Bekleyin_Yeri);
        
        strcpy(Rev, EKM.Yaz_Revizyon);
        strcpy(Ver, EKM.Yaz_Versiyon);

        Guncelleme_Adimi = 10;

        Veri_Kaydet_String(WIFI_AD_KAYIT_YERI, Baglanilacak_Wifi);
        Veri_Kaydet_String(WIFI_SIFRE_KAYIT_YERI, Baglanilacak_Sifre);
        memset(EKM.Kayitli_Wifi, 0, sizeof(EKM.Kayitli_Wifi));
        memset(EKM.Kayitli_Wifi_Sifresi, 0, sizeof(EKM.Kayitli_Wifi_Sifresi));

        strcpy(EKM.Kayitli_Wifi, Baglanilacak_Wifi);
        strcpy(EKM.Kayitli_Wifi_Sifresi, Baglanilacak_Sifre);
        
        break;
      }
    }
    if ((WiFi.status() != WL_CONNECTED))  //if ((WiFiMulti.run() != WL_CONNECTED))
    {
      WiFi.mode(WIFI_STA);
      WiFi.disconnect();      
      delay(100);
      n = WiFi.scanNetworks();
      
      ag_yok_hata();
      Guncelleme_Adimi = 1; /// 2 = tekrar wifi seçim yeri.??  parola değiştir yada tekrar tara sorgusu?
    }
  }
  else if (Guncelleme_Adimi == 7)     /// kayıtlı olana bağlansın mı sorgusu
  {
     
    lcd.clear();

    Kayittan_Yazi_Yaz(0, SATIR_1,Wifi_Bulundu_Yeri);
    Yazi_Yaz(0, SATIR_2, EKM.Kayitli_Wifi, 1);
    Kayittan_Yazi_Yaz(0, SATIR_3, Diger_Yeri);      
    Kayittan_Yazi_Yaz(13, SATIR_3, Baglan_Yeri);
    Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
    Kayittan_Yazi_Yaz(0,SATIR_4,ESC_Yeri);
    
    Guncelleme_Adimi = 8;
    EKM.Imlec = 1;
    return;
  }
  else if (Guncelleme_Adimi == 8)   // kayıtlı olana bağlanma yada yeni seçme sorgu secimi
  {
  
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      strcpy(Baglanilacak_Wifi, EKM.Kayitli_Wifi);
      strcpy(Baglanilacak_Sifre, EKM.Kayitli_Wifi_Sifresi);
      Guncelleme_Adimi = 6;   //// bağlanma yeri      
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Guncelleme_Adimi = 2;   //// bulunanları gösterme yeri
    }
  }
  else if (Guncelleme_Adimi == 10)  //// yazılım güncellenme yeri
  {
    HTTPClient http;

    sprintf(Chip_ID,"%i",EKM.Chipid);
    sprintf(Istatislikler,"%i,%i,%i,%i,%i",EKM.Toplam_Tupten_Cekilen_Gr,EKM.Toplam_Aractan_Cekilen_Gr,EKM.Toplam_Dolum_Gr,EKM.Filtre_Kalan_Gr,EKM.Filtre_Sayisi);
    if (SATIS_YERI == TURKIYE)
    {
      strcat(Gonderme_Linki,"http://elcielektronik.com/plus2data/data_yaz.php?data=");//http://elcielektronik.com/plus2data/data_yaz.php?data=
    }
    else if (SATIS_YERI == SMARTCON)
    {
      strcat(Gonderme_Linki,"http://elcielektronik.com/smartcondata/data_yaz.php?data=");//http://elcielektronik.com/plus2data/data_yaz.php?data=
    }
    else if (SATIS_YERI == STARKA)
    {
      strcat(Gonderme_Linki,"http://elcielektronik.com/str-plusdata/data_yaz.php?data=");//http://elcielektronik.com/plus2data/data_yaz.php?data=
    }

 //   strcat(Gonderme_Linki,"http://elcielektronik.com/smartcondata/data_yaz.php?data=");//http://elcielektronik.com/plus2data/data_yaz.php?data=
    strcat(Gonderme_Linki,Chip_ID);
    strcat(Gonderme_Linki,",");
    strcat(Gonderme_Linki,"V1");  //// kart versiyonları
    strcat(Gonderme_Linki,",");
    strcat(Gonderme_Linki,"R1");  ///// kart revizyonları
    strcat(Gonderme_Linki,",");
    strcat(Gonderme_Linki,EKM.Yaz_Versiyon);  /// yaz. versiyonları
    strcat(Gonderme_Linki,",");
    strcat(Gonderme_Linki,EKM.Yaz_Revizyon);  // yazılım revizyonları
    strcat(Gonderme_Linki,",");
    strcat(Gonderme_Linki,Istatislikler);
    // #warning "Bunu Unutma!!!!"
    //  Serial.println(Gonderme_Linki);
    //  Serial.println(EKM.Acilma_Sayisi);
    http.begin(Gonderme_Linki);      //Specify request destination
    http.addHeader("Content-Type", "text/plain");  //Specify content-type header
    http.POST("plus2");   //Send the request

    Bekle_ms(10);

    ESPhttpUpdate.rebootOnUpdate(false);        ///// yazılım yüklemeden sonra reset atmaz ve reset atılana kadar yeni yazılım aktif olmaz. Reset atma en sona eklendi. Kalkmamalı. !
    sprintf(Chip_ID, "/%d", EKM.Chipid);
    if (SATIS_YERI == TURKIYE)
    {
      strcat(Indirme_Linki, "https://elcielektronik.com/version/plus2");
    }
    else if (SATIS_YERI == SMARTCON)
    {
      strcat(Indirme_Linki, "https://elcielektronik.com/version/brescon/smartcon");    //smartcharge600/Ver_");
    }
    else if (SATIS_YERI == STARKA)
    {
      strcat(Indirme_Linki, "https://elcielektronik.com/version/starka/str-plus");    
    }

    //strcat(Indirme_Linki, "https://elcielektronik.com/version/brescon/smartcon");    //smartcharge600/Ver_");
    strcat(Indirme_Linki, Chip_ID);
    strcat(Indirme_Linki, Chip_ID);
    strcat(Indirme_Linki,".bin");

    // strcat(Indirme_Linki, Ver);
    // strcat(Indirme_Linki, "/Rev_");
    // strcat(Indirme_Linki, Rev);
    

    //    Serial.println(Indirme_Linki);
    delay(1000);
    //    WiFiClient client;
    //    t_httpUpdate_return ret = httpUpdate.update(client, "https://elcielektronik.com/version/smartcharge600/Ver_00/Rev_00/811602.bin");//"https://elcielektronik.com/version/smartcharge600/175494/175494.bin"
    t_httpUpdate_return ret = ESPhttpUpdate.update(Indirme_Linki);   // https://elcielektronik.com/version/smartcharge600/Ver_00/Rev_00/811602.bin    "https://elcielektronik.com/version/smartcharge600/Ver_00/Rev_00/811602.bin"
    switch (ret)
    {
      case HTTP_UPDATE_FAILED:
        //Serial.printf("HTTP_UPDATE_FAILED Error (%d): %s\n", httpUpdate.getLastError(), httpUpdate.getLastErrorString().c_str());

        lcd.clear();
        Kayittan_Yazi_Yaz(0, SATIR_1, Yaziliminiz_Yeri);
        Kayittan_Yazi_Yaz(0, SATIR_2, Guncel_Yeri);
          
        delay(3000);
          
        Guncelleme_Adimi = 0;
        Diger_Ayarlar_Secim_Sayfa(1);
          //          Serial.println("Ikinci_deneme");
        
        break;

      case HTTP_UPDATE_NO_UPDATES:
        lcd.clear();
        Kayittan_Yazi_Yaz(0,SATIR_1,Yazilim_Guncel_Yeri);
         
        delay(3000);
      //  state = 0; // farklý bir çalýþma olabilir....//// may be a different operation....
        //        
        Guncelleme_Adimi = 0;
        Diger_Ayarlar_Secim_Sayfa(1);
        break;

      case HTTP_UPDATE_OK:    ///// buraya gelmeden reset atıyor. !
        //        Serial.println("Yuklendi");
        lcd.clear();
        Kayittan_Yazi_Yaz(0,SATIR_1,Yazilim_Guncellendi_Yeri);
         
        // Veri_Kaydet_String(YAZ_VERSIYON_KAYIT_YERI, Ver);
        // Veri_Kaydet_String(YAZ_REVIZYON_KAYIT_YERI, Rev);
        delay(3000);
        Guncelleme_Adimi = 0;
        ESP.restart();
        break;
    }

  }

}

void Wifi_Baglanti_Kontrol(void)
{
  static unsigned short n = 0; // Secili_Satir_Yeri = 0, Sifre_Girisi = 0, Yaz_Deneme = 0;//u = 0,
  static unsigned char Kontrol_Adimi = 0;

  HTTPClient http;

  static unsigned int _ms = 0;

  char Gonderme_Linki[200] = {0};
  char Istatislikler[50] = {0};     // max 44 hane olabilir. 10 x 3 + filtre kalan 5, filtre adet 5 = 40 hane + 4 adet , 
  char Chip_ID[10] = {0};

  if(EKM.Wifi_Durumu == BAGLANDI)       /// wifi bağlandıysa veya sorma dendiyse geri dönecek
  {
    if((EKM.MS - _ms) > 1000)
    {
      _ms = EKM.MS;
      if (WiFi.status() == WL_CONNECTED)
        return;
    }
    else 
      return;
    
  }
    
  if(Kontrol_Adimi == 99)   /// wifi bulunamadı ise sürekli zorlamaya gerek yok. saatte 1 defa bakacak
  {         
    if((EKM.MS - _ms) > 3600000)
    {
      _ms = EKM.MS;
      Kontrol_Adimi = 0;
    }                /// baglantı sırasında 4-6sn tepki vermiyor. sadece açılışta elcielektronik yazısı sırasında deneme yapılıyor
    return;
  }  

  if(Kontrol_Adimi == 0)
  {   
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();    /// baglantı kesmeden tarama yapılabilir mi??? 
    delay(100);
    n = WiFi.scanNetworks();
    Kontrol_Adimi = 1; 
    if(EKM.Acilma_Sayisi < 100)
    {
      EKM.Acilma_Sayisi ++;
      Veri_Kaydet_Uchar(ACILMA_SAYISI_KAYIT_YERI,EKM.Acilma_Sayisi);
    }
  }
  else if (Kontrol_Adimi == 1) 
  {
    if (n != 0)
    {
      for (int i = 0; i < n; ++i)
      {
        stpcpy(EKM.Bulunan_Wifiler[i], WiFi.SSID(i).c_str());

        if (strcmp(EKM.Kayitli_Wifi, EKM.Bulunan_Wifiler[i]) == 0) //// kayıtlı wifi bulundu
        {
          Kontrol_Adimi = 3;   // Kayıtli wifiye bağlanma yeri
        }
        else
        {
          if (Kontrol_Adimi != 3)
            Kontrol_Adimi = 2;   //// kayıtlı wifi bulunamdı
        }
        delay(5);
      }
    }
    else    /// wifi bulunamadı. lutfen bağlantı yapın uyarısı
    {
      EKM.Wifi_Durumu = WIFI_BULUNAMADI;
      Kontrol_Adimi = 99;
    }
  }
  else if (Kontrol_Adimi == 2)
  {
    EKM.Wifi_Durumu = BAGLANAMADI;      //// wifi sinyali var ama kayıtlı wifi yok. 
    Kontrol_Adimi = 99;
  }
  else if (Kontrol_Adimi == 3)   /// wifi bağlanma yeri
  {
    //WiFiMulti.addAP(EKM.Kayitli_Wifi, EKM.Kayitli_Wifi_Sifresi);
    WiFi.begin(EKM.Kayitli_Wifi,EKM.Kayitli_Wifi_Sifresi);
    EKM.Wifi_ms = EKM.MS;
    Kontrol_Adimi = 4;
  }

  else if (Kontrol_Adimi == 4)
  {
    if ((EKM.MS - EKM.Wifi_ms) < 60000)
    {
      if (WiFi.status() == WL_CONNECTED)   //((WiFiMulti.run() == WL_CONNECTED))
      {
       // gonder_link = gonder_link+","+String(esp_ver)+","+String(esp_dat)+","+String(pic_version)+","+String(topyen_gr)+","+String(topcekeski_gr)+","+String(topdol_gr)+","+String(f_adet);
        sprintf(Chip_ID,"%i",EKM.Chipid);
        sprintf(Istatislikler,"%i,%i,%i,%i,%i",EKM.Toplam_Tupten_Cekilen_Gr,EKM.Toplam_Aractan_Cekilen_Gr,EKM.Toplam_Dolum_Gr,EKM.Filtre_Kalan_Gr,EKM.Filtre_Sayisi);
        if (SATIS_YERI == TURKIYE)
        {
          strcat(Gonderme_Linki,"http://elcielektronik.com/plus2data/data_yaz.php?data=");//http://elcielektronik.com/plus2data/data_yaz.php?data=
        }
        else if (SATIS_YERI == SMARTCON)
        {
          strcat(Gonderme_Linki,"http://elcielektronik.com/smartcondata/data_yaz.php?data=");//http://elcielektronik.com/plus2data/data_yaz.php?data=
        }
        else if (SATIS_YERI == STARKA)
        {
          strcat(Gonderme_Linki,"http://elcielektronik.com/str-plusdata/data_yaz.php?data=");//http://elcielektronik.com/plus2data/data_yaz.php?data=
        }




        strcat(Gonderme_Linki,Chip_ID);
        strcat(Gonderme_Linki,",");
        strcat(Gonderme_Linki,"V1");  //// kart versiyonları
        strcat(Gonderme_Linki,",");
        strcat(Gonderme_Linki,"R1");  ///// kart revizyonları
        strcat(Gonderme_Linki,",");
        strcat(Gonderme_Linki,EKM.Yaz_Versiyon);  /// yaz. versiyonları
        strcat(Gonderme_Linki,",");
        strcat(Gonderme_Linki,EKM.Yaz_Revizyon);  // yazılım revizyonları
        strcat(Gonderme_Linki,",");
        strcat(Gonderme_Linki,Istatislikler);
        // #warning "Bunu Unutma!!!!"
        //  Serial.println(EKM.Acilma_Sayisi);
        if (EKM.Acilma_Sayisi > 1)
        {
          http.begin(Gonderme_Linki);      //Specify request destination
          http.addHeader("Content-Type", "text/plain");  //Specify content-type header
          http.POST("plus2");   //Send the request
          EKM.Acilma_Sayisi = 0;
          Veri_Kaydet_Uchar(ACILMA_SAYISI_KAYIT_YERI,EKM.Acilma_Sayisi);
        }
        EKM.Wifi_Durumu = BAGLANDI;
        Kontrol_Adimi = 5;        
      }
    }
    else
    {
      if (WiFi.status() != WL_CONNECTED)  //((WiFiMulti.run() != WL_CONNECTED))
      {
        // #warning "Bunu Unutma!!!!"
        // Serial.println(EKM.Kayitli_Wifi);
        // Serial.println(EKM.Kayitli_Wifi_Sifresi);
        
        EKM.Wifi_Durumu = BAGLANAMADI;
        Kontrol_Adimi = 99;
        
      }
    } 
  }
}

void Yazici_Test(void)
{
  char Printer_Yazilacak[50] = {0};
  char Printer_Buff[22] = {0};

  Printer_Ayarla(0, 27, 64);
  delay(200);
  Printer_Ayarla(29, 33, 1);
  Printer_Ayarla(27, 74, 50);
  Printer_Yazdir(EKM.Cihaz_Adi, 13, 10);
  delay(100);
  Zaman_Al(&Rtc_Zamani);

  Printer_Ayarla(29, 33, 0);
  Printer_Ayarla(27, 74, 20);

  Printer_Yazdir(Dil_Listesi[(Yapilan_Islemler_Yeri*DIL_SAYISI)+EKM.Dil], 13, 10);
  delay(100);
  Printer_Yazilacak[0] = (Rtc_Zamani.Gun / 10) + 48;
  Printer_Yazilacak[1] = (Rtc_Zamani.Gun % 10) + 48;

  Printer_Yazilacak[2] = '/';

  Printer_Yazilacak[3] = (Rtc_Zamani.Ay / 10) + 48;
  Printer_Yazilacak[4] = (Rtc_Zamani.Ay % 10) + 48;

  Printer_Yazilacak[5] = '/';

  Printer_Yazilacak[6] = (Rtc_Zamani.Yil / 10) + 48;
  Printer_Yazilacak[7] = (Rtc_Zamani.Yil % 10) + 48;

  Printer_Yazilacak[8] = ' ';

  Printer_Yazilacak[9] = (Rtc_Zamani.Saat / 10) + 48;
  Printer_Yazilacak[10] = (Rtc_Zamani.Saat % 10) + 48;

  Printer_Yazilacak[11] = ':';

  Printer_Yazilacak[12] = (Rtc_Zamani.Dk / 10) + 48;
  Printer_Yazilacak[13] = (Rtc_Zamani.Dk % 10) + 48;

  Printer_Yazilacak[14] = ':';

  Printer_Yazilacak[15] = (Rtc_Zamani.Sn / 10) + 48;
  Printer_Yazilacak[16] = (Rtc_Zamani.Sn % 10) + 48;

  Printer_Yazdir(Printer_Yazilacak, 13, 10);

  memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
  memset(Printer_Buff, 0x00, strlen(Printer_Buff));
  strcat(Printer_Yazilacak,Dil_Listesi[(Sira_No_Yeri*DIL_SAYISI)+EKM.Dil]);
  sprintf(Printer_Buff,"%d ", EKM.Seri_No);
  strcat(Printer_Yazilacak,Printer_Buff);
  Printer_Yazdir(Printer_Yazilacak, 13, 10);
  delay(100);

  memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
  memset(Printer_Buff, 0x00, strlen(Printer_Buff));
  strcat(Printer_Yazilacak,Dil_Listesi[(Vakum_Dk_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
  sprintf(Printer_Buff, "%d ", Yazilacaklar.Vakum_Dk);
  strcat(Printer_Yazilacak,Printer_Buff);
  strcat(Printer_Yazilacak,Dil_Listesi[(Dak_Yaz_Yeri*DIL_SAYISI+EKM.Dil)]);
  Printer_Yazdir(Printer_Yazilacak, 13, 10);
  delay(100);

  memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
  memset(Printer_Buff, 0x00, strlen(Printer_Buff));
  strcat(Printer_Yazilacak,Dil_Listesi[(Kacak_Dk_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
  sprintf(Printer_Buff, "%d ", Yazilacaklar.Kacak_Dk);
  strcat(Printer_Yazilacak,Printer_Buff);
  strcat(Printer_Yazilacak,Dil_Listesi[(Dak_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
  Printer_Yazdir(Printer_Yazilacak, 13, 10);
  delay(100);
  
  memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
  memset(Printer_Buff, 0x00, strlen(Printer_Buff));
  strcat(Printer_Yazilacak,Dil_Listesi[(Yeni_Yag_ml_Yeri*DIL_SAYISI)+EKM.Dil]);
  
  strcat(Printer_Yazilacak,Dil_Listesi[(Hayir_Yeri*DIL_SAYISI)+EKM.Dil]);

  Printer_Yazdir(Printer_Yazilacak, 13, 10);
  delay(100);

  // memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
  // strcat(Printer_Yazilacak,Dil_Listesi[UV_Yag_ml_Yeri*DIL_SAYISI]);

  // strcat(Printer_Yazilacak,Dil_Listesi[Hayir_Yeri*DIL_SAYISI]);

  // Printer_Yazdir(Printer_Yazilacak, 13, 10);
  // delay(100);

  // memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
  // strcat(Printer_Yazilacak,Dil_Listesi[Hibrit_Yag_ml_Yeri*DIL_SAYISI]);

  // strcat(Printer_Yazilacak,Dil_Listesi[Hayir_Yeri*DIL_SAYISI]);

  // Printer_Yazdir(Printer_Yazilacak, 13, 10);
  // delay(100);

  memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
  strcat(Printer_Yazilacak,Dil_Listesi[(Doldurulan_Gaz_gr_Yeri*DIL_SAYISI)+EKM.Dil]);
  sprintf(Printer_Buff, "%d ", Yazilacaklar.Dolan_Gr);
  strcat(Printer_Yazilacak,Printer_Buff);
  strcat(Printer_Yazilacak,Dil_Listesi[(Gr_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
  Printer_Yazdir(Printer_Yazilacak, 13, 10);
  delay(100);

  memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
  strcat(Printer_Yazilacak,Dil_Listesi[(Cekilen_Gaz_gr_Yeri*DIL_SAYISI)+EKM.Dil]);
  sprintf(Printer_Buff, "%d ", Yazilacaklar.Cekilen_Gr);
  strcat(Printer_Yazilacak,Printer_Buff);
  strcat(Printer_Yazilacak,Dil_Listesi[(Gr_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
  Printer_Yazdir(Printer_Yazilacak, 13, 10);
  delay(100);

  memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
  strcat(Printer_Yazilacak,Dil_Listesi[(Plaka_Yeri*DIL_SAYISI)+EKM.Dil]);
  strcat(Printer_Yazilacak,Yazilacaklar.Plaka);
  Printer_Yazdir(Printer_Yazilacak, 13, 10);
  delay(100);
  
  memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));

  Printer_Ayarla(27, 74, 200);
  delay(100);
}

void Kontrast_Ayar_Sorgula(void)
{
  static unsigned char Sorgu_Adimi = 0;
  static unsigned int _ms = 0;

  if (Sorgu_Adimi == 0)
  {
    if((Buton[Sol_Buton].Durum == 1) && (Buton[Sag_Buton].Durum == 1))
    {
      if(EKM.Sayfa == Giris_Sayfasi)
      {
        if((EKM.MS - _ms) > 5000)
        {         
          Buzer_Ac;
          EKM.Buzer_Calma_ms = UZUN_BUZER;
          Sorgu_Adimi = 1;
          Lcd_Sayi_Yaz(17,SATIR_1,EKM.Lcd_Kontrast_Degeri,1,3);
        }
      }
    }
    else
    {
      _ms = EKM.MS;
    }
  }
  else if (Sorgu_Adimi == 1)
  {
    if((Buton[Sol_Buton].Durum == 0) && (Buton[Sag_Buton].Durum == 0))
    {
      // Buton[Sol_Buton].Olay = OLAYI_TEMIZLE;
      // Buton[Sag_Buton].Olay = OLAYI_TEMIZLE;
      Sorgu_Adimi = 2;
    }
  }
  else if (Sorgu_Adimi == 2)
  {
    if(Buton[Sag_Buton].Durum == 1)
    {
      Buton[Sag_Buton].Durum = 0;
      Buton[Sag_Buton].Olay = OLAY_YOK;
      Buton[Sag_Buton].Basildi = 0;

      if(EKM.Lcd_Kontrast_Degeri < 255)
      {
        EKM.Lcd_Kontrast_Degeri ++;
        Buzer_Ac;
        EKM.Buzer_Calma_ms = 10;
        Lcd_Sayi_Yaz(17,SATIR_1,EKM.Lcd_Kontrast_Degeri,1,3);
        ledcWrite(0,EKM.Lcd_Kontrast_Degeri);
        Bekle_ms(200);
        _ms = EKM.MS;
      }
    }

    if(Buton[Sol_Buton].Durum == 1)
    {
      Buton[Sol_Buton].Durum = 0;
      Buton[Sol_Buton].Olay = OLAY_YOK;
      Buton[Sol_Buton].Basildi = 0;

      if (EKM.Lcd_Kontrast_Degeri)
      {
       EKM.Lcd_Kontrast_Degeri --;
       Buzer_Ac;
       EKM.Buzer_Calma_ms = 10;
       Lcd_Sayi_Yaz(17,SATIR_1,EKM.Lcd_Kontrast_Degeri,1,3);
       ledcWrite(0,EKM.Lcd_Kontrast_Degeri);
       Bekle_ms(200);
       _ms = EKM.MS;
      }
      
    }
    if((EKM.MS - _ms) > 10000)
    {
      Buton[Sol_Buton].Olay = OLAYI_TEMIZLE;
      Buton[Sag_Buton].Olay = OLAYI_TEMIZLE;
      Butonlari_Temizle();
      Giris_Sayfa(1,1);
      Veri_Kaydet_Uchar(KONTRAST_KAYIT_YERI,EKM.Lcd_Kontrast_Degeri);
      Buzer_Ac;
      EKM.Buzer_Calma_ms = 200;
      Sorgu_Adimi = 0;
    }
    if(Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Butonlari_Temizle();
      Giris_Sayfa(1,1);
      Buton[Sol_Buton].Olay = OLAYI_TEMIZLE;
      Buton[Sag_Buton].Olay = OLAYI_TEMIZLE;
      Sorgu_Adimi = 0;
    }
  }
}

void Ekrani_Temizle(void)
{
  lcd.clear();
}

void setup(void)
{
  uint64_t chipidver = 0;

  chipidver = ESP.getEfuseMac();
  uint32_t high = (chipidver >> 32) % 0xFFFFFFFF;
  EKM.Chipid = high * 33;

  Giris_Cikislari_Ayarla();
  micros();
  EEPROM.begin(1024);
  Serial.begin(19200); // DİKKAATTT!!!: Seri porttan yazan serial ile printer'ın bağlı olduğu serial aynı. Bu yüzden testler bitince hiçbir yerde seri port ile ilgili yazı kalmamalı.!!!
  
  timer = timerBegin(0, 80, true);  // timer 0, MWDT clock period = 12.5 ns * TIMGn_Tx_WDT_CLK_PRESCALE -> 12.5 ns * 80 -> 1000 ns = 1 us, countUp
  timerAttachInterrupt(timer, &onTimer, true); // edge (not level) triggered
  timerAlarmWrite(timer, 1000, true); // 1000000 * 1 us = 1 s, autoreload true
  timerAlarmEnable(timer); // enable

  Eepromdan_Verileri_Al();

  Ekrani_Kur();
  Rtc_Kur();

  byte Asagi_Ok[8] = {0x0,0x4,0x4,0x4,0x4,0x15,0xE,0x4};
  lcd.createChar(1,Asagi_Ok);

  Buzer_Ac;
  EKM.Buzer_Calma_ms = 1000;

  Sicaklik_Sensoru.begin();
  delay(10);
  Sicaklik_Sensoru.setResolution(9);

  Buton[Giris_Buton].Olay = OLAY_YOK;
  Buton[Geri_Buton].Olay = OLAY_YOK;
  Buton[Asagi_Buton].Olay = OLAY_YOK;
  Buton[Yukari_Buton].Olay = OLAY_YOK;

  SSR_Kontrol(IPTAL_ET,KAPAT);
  Marka_Sayisi();

  unsigned char by = 0;
   
  by = strlen (EKM.Kayitli_Wifi);
  EKM.Kayitli_Wifi[by] = 0;

  EKM.Imlec = 1;
   
  lcd.clear();
  EKM.Sayfa = Acilis_Sayfasi;
  
}

void loop()
{
  Butonlari_Sorgula();
  Sayfalari_Sorgula();
  Kontrast_Ayar_Sorgula();
  if (EKM.Sayfa == Giris_Sayfasi)
  {
    Wifi_Baglanti_Kontrol();
  }
  // if (Buton[Sol_Buton].Olay == BASILDI_OLAYI)
  // {
  //    Butonlari_Temizle();
  //    Yazici_Test();
  // }
  //   unsigned char Durum = 0;
  //  Serial.println("Gonderiliyor");
  //   Durum = Mail_AT();
    
  //   if(Durum == WIFI_BAGLANTISI_YOK)
  //   {
  //     Serial.println("Baglanti_Yok");
  //   }
  //   else if(Durum == 0)
  //   {
  //     Serial.println("Gonderilemedi");
  //   }
  //   else if(Durum == 1)
  //   {
  //     Serial.println("Gonderildi");
  //   }
    
  //  }

  // if (Buton[Sol_Buton].Olay == BASILDI_OLAYI)
  // {
  //   Buton[Sol_Buton].Olay = OLAYI_TEMIZLE;
  //   EKM.Lcd_Kontrast_Degeri++;
  //   ledcWrite(0,EKM.Lcd_Kontrast_Degeri);
  // }
  // if (Buton[Sag_Buton].Olay == BASILDI_OLAYI)
  // {
  //   Buton[Sag_Buton].Olay = OLAYI_TEMIZLE;
  //   EKM.Lcd_Kontrast_Degeri--;
  //   ledcWrite(0,EKM.Lcd_Kontrast_Degeri);
  // }
  //Yazilim_Guncelle();

}

// void Serial_Oku(void)
// {
 
//   if(Serial.available())
//   {
//     EKM.Serial_Gelen = Serial.read();
//     if(EKM.Serial_Gelen == 'O')
//       Buton[Giris_Buton].Olay = BASILDI_OLAYI;
//     else if (EKM.Serial_Gelen == 'G')
//       Buton[Geri_Buton].Olay = BASILDI_OLAYI;
//     else if (EKM.Serial_Gelen == 'Y')
//       Buton[Yukari_Buton].Olay = BASILDI_OLAYI;
//     else if (EKM.Serial_Gelen == 'A')
//       Buton[Asagi_Buton].Olay = BASILDI_OLAYI;
//     else if (EKM.Serial_Gelen == 'K')
//       EKM.Sayfa = Yazilim_Guncelleme_Sayfasi;

//   }
// }

