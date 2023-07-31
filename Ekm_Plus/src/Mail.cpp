
#include "Ekm_Plus.hpp"

/** The smtp port e.g.
 * 25  or esp_mail_smtp_port_25
 * 465 or esp_mail_smtp_port_465
 * 587 or esp_mail_smtp_port_587
 */
#define SMTP_PORT esp_mail_smtp_port_587 // port 465 is not available for Outlook.com

SMTPSession smtp;
void smtpCallback(SMTP_Status status);

void smtpCallback(SMTP_Status status)
{
  /* Print the current status */

  /* Print the sending result */
  if (status.success())
  {
    // ESP_MAIL_PRINTF used in the examples is for format printing via debug Serial port
    // that works for all supported Arduino platform SDKs e.g. AVR, SAMD, ESP32 and ESP8266.
    // In ESP32 and ESP32, you can use Serial.printf directly.

    // ESP_MAIL_PRINTF("Message sent success: %d\n", status.completedCount());
    // ESP_MAIL_PRINTF("Message sent failed: %d\n", status.failedCount());
   

    for (size_t i = 0; i < smtp.sendingResult.size(); i++)
    {
      /* Get the result item */
      SMTP_Result result = smtp.sendingResult.getItem(i);

      // In case, ESP32, ESP8266 and SAMD device, the timestamp get from result.timestamp should be valid if
      // your device time was synched with NTP server.
      // Other devices may show invalid timestamp as the device time was not set i.e. it will show Jan 1, 1970.
      // You can call smtp.setSystemTime(xxx) to set device time manually. Where xxx is timestamp (seconds since Jan 1, 1970)
      time_t ts = (time_t)result.timestamp;

      // ESP_MAIL_PRINTF("Message No: %d\n", i + 1);
      // ESP_MAIL_PRINTF("Status: %s\n", result.completed ? "success" : "failed");
      // ESP_MAIL_PRINTF("Date/Time: %s\n", asctime(localtime(&ts)));
      // ESP_MAIL_PRINTF("Recipient: %s\n", result.recipients.c_str());
      // ESP_MAIL_PRINTF("Subject: %s\n", result.subject.c_str());
    }


    // You need to clear sending result as the memory usage will grow up.
    smtp.sendingResult.clear();
  }
}

unsigned char Mail_Gir(const char* _Mail)
{
  static unsigned char Sutun_No = 0;//, Boy = 0
  static char Sifre[35] = {0};
  static unsigned char Cizgi_Yeri = 0, Cizgi_Boyu = 4, Cizgi_Satir_Yeri = SATIR_3, Yazi_Satir_Yeri = SATIR_3, Sutun_Atlagi = 1;
 // static unsigned int _ms = 0;
  static unsigned char Sayi_Giris_Durumu = 0, Alt_Sinir = 32, Ust_Sinir = 126;
  char Mail_Adresi[35] = {0};

  if (Sayi_Giris_Durumu == 0)
  {     
    memset(Sifre,0,sizeof(Sifre)); 
    strcpy(Mail_Adresi,_Mail);

    Sayi_Giris_Durumu = 1;
    Cizgi_Yeri = 0;
    Cizgi_Satir_Yeri = SATIR_3;
    Yazi_Satir_Yeri = SATIR_3;
    Sutun_No = 0;
    Sutun_Atlagi = 1;
    if(strlen(Mail_Adresi) != 1)
    {
      strtok(Mail_Adresi,"@");
    } 
    else
    {
      Cizgi_Yeri = 1;
    }   
    strcpy(Sifre,Mail_Adresi);
    
    Yazi_Yaz(0,SATIR_3,Mail_Adresi,1);
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
      strcpy(EKM.Girilen_Metin, Sifre);
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

      Lcd_Yaz(Sifre[Sutun_No]);
      Lcd_Set_Cursor(Cizgi_Yeri, Yazi_Satir_Yeri); 
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
      
      Lcd_Yaz(Sifre[Sutun_No]);
      Lcd_Set_Cursor(Cizgi_Yeri, Yazi_Satir_Yeri);
      delay(100);
    }
    else if (Buton[Asagi_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
      Sifre[Sutun_No]--;
      if ((Sifre[Sutun_No] > Ust_Sinir) || (Sifre[Sutun_No] < Alt_Sinir))
        Sifre[Sutun_No] = Ust_Sinir;
      
      Lcd_Yaz(Sifre[Sutun_No]);
      Lcd_Set_Cursor(Cizgi_Yeri, Yazi_Satir_Yeri); 
    }
    if (Buton[Asagi_Buton].Olay == UZUN_BASILDI_OLAYI)
    {
      Buzer_Kapa;
      if (Buton[Asagi_Buton].Durum == 0)
        Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
      Sifre[Sutun_No]--;
      if ((Sifre[Sutun_No] > Ust_Sinir) || (Sifre[Sutun_No] < Alt_Sinir))
        Sifre[Sutun_No] = Ust_Sinir;
      
      Lcd_Yaz(Sifre[Sutun_No]);
      Lcd_Set_Cursor(Cizgi_Yeri, Yazi_Satir_Yeri);
      delay(100);
    }
  }
  return 0;
}

/*
  @return WIFI_BULUNAMADI,IPTAL_ET,BAGLANAMADI,BAGLANDI,DEVAM_EDIYOR
*/
unsigned char Wifi_Baglan(void)
{
  static unsigned char n = 0,Baglanma_Adimi = 0,Secili_Satir_Yeri = 0,Sifre_Girisi = 0;
  static unsigned int _ms = 0;
  static char Baglanilacak_Wifi[50] = {0};
  static char Baglanilacak_Sifre[25] = {0};

  if(Baglanma_Adimi == Sifirlama)
  {
    Ekrani_Temizle();
    Kayittan_Yazi_Yaz(0,SATIR_1,Lutfen_Bekleyin_Yeri);
    Baglanma_Adimi = Wifi_Tarama;
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    n = WiFi.scanNetworks();
  }
  else if (Baglanma_Adimi == Wifi_Tarama)
  {
    if (n != 0)
    {      
      Ekrani_Temizle();
      for (int i = 0; i < n; ++i)
      {
        stpcpy(EKM.Bulunan_Wifiler[i], WiFi.SSID(i).c_str());
        if (i < 4)
        {
          Yazi_Yaz(1, (SATIR_1 + i), EKM.Bulunan_Wifiler[i], 1);
        }
        if (strcmp(EKM.Kayitli_Wifi, EKM.Bulunan_Wifiler[i]) == 0) //// kayıtlı wifi bulundu
        {
          Baglanma_Adimi = Kayitli_Wifi_Secim;   // kayıtlı bulundu yeri
        }
        else
        {
          if (Baglanma_Adimi != Kayitli_Wifi_Secim)
          {
            Baglanma_Adimi = Bulunanlari_Goster;   //// bulunanları gösterme yeri
          }
          else
          {
            Ekrani_Temizle();
            Kayittan_Yazi_Yaz(0, SATIR_1,Wifi_Bulundu_Yeri);
            Yazi_Yaz(0, SATIR_2, EKM.Kayitli_Wifi, 1);
            Kayittan_Yazi_Yaz(0, SATIR_3, Diger_Yeri);      
            Kayittan_Yazi_Yaz(13, SATIR_3, Baglan_Yeri);
            Kayittan_Yazi_Yaz(15,SATIR_4,Ent_Yeri);
            Kayittan_Yazi_Yaz(0,SATIR_4,ESC_Yeri);
          }
        }
        delay(10);
      }
    }
    else
    {       
      Ekrani_Temizle();
      Kayittan_Yazi_Yaz(0, SATIR_1, Wifi_Bulunamadi_Yeri);
      Baglanma_Adimi = Sifirlama;
      return WIFI_BULUNAMADI;
    }
  } 
  else if (Baglanma_Adimi == Bulunanlari_Goster)		/// secim öncesi
  {
    EKM.Imlec = 0;
    Secili_Satir_Yeri = 1;      //// önemli.!!!!     
    Ekrani_Temizle();
      
    Yazi_Yaz(1, SATIR_1, EKM.Bulunan_Wifiler[0], 19);
    Yazi_Yaz(1, SATIR_2, EKM.Bulunan_Wifiler[1], 19);
    Yazi_Yaz(1, SATIR_3, EKM.Bulunan_Wifiler[2], 19);
    Yazi_Yaz(1, SATIR_4, EKM.Bulunan_Wifiler[3], 19);
     
    Baglanma_Adimi = Wifi_Secimi;
    Imlec_Yaz(Secili_Satir_Yeri);
  }
  else if (Baglanma_Adimi == Wifi_Secimi)		// wifi secim
  {
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Baglanma_Adimi = 0;
      return IPTAL_ET;
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
          Ekrani_Temizle();
          Imlec_Yaz(Secili_Satir_Yeri);
          Yazi_Yaz(1, SATIR_1, EKM.Bulunan_Wifiler[EKM.Imlec], 19);
          Yazi_Yaz(1, SATIR_2, EKM.Bulunan_Wifiler[EKM.Imlec + 1], 19);
          Yazi_Yaz(1, SATIR_3, EKM.Bulunan_Wifiler[EKM.Imlec + 2], 19);
          Yazi_Yaz(1, SATIR_4, EKM.Bulunan_Wifiler[EKM.Imlec + 3], 19);
        }
        else if (Secili_Satir_Yeri == 2)
        {
          Ekrani_Temizle();
          Imlec_Yaz(Secili_Satir_Yeri);
          Yazi_Yaz(1, SATIR_1, EKM.Bulunan_Wifiler[EKM.Imlec - 1], 19);
          Yazi_Yaz(1, SATIR_2, EKM.Bulunan_Wifiler[EKM.Imlec], 19);
          Yazi_Yaz(1, SATIR_3, EKM.Bulunan_Wifiler[EKM.Imlec + 1], 19);
          Yazi_Yaz(1, SATIR_4, EKM.Bulunan_Wifiler[EKM.Imlec + 2], 19);  
        }
        else if (Secili_Satir_Yeri == 3)
        {
          Ekrani_Temizle();
          Imlec_Yaz(Secili_Satir_Yeri);
          Yazi_Yaz(1, SATIR_1, EKM.Bulunan_Wifiler[EKM.Imlec - 2], 19);
          Yazi_Yaz(1, SATIR_2, EKM.Bulunan_Wifiler[EKM.Imlec - 1], 19);
          Yazi_Yaz(1, SATIR_3, EKM.Bulunan_Wifiler[EKM.Imlec], 19);
          Yazi_Yaz(1, SATIR_4, EKM.Bulunan_Wifiler[EKM.Imlec + 1], 19);  
        }
        else if (Secili_Satir_Yeri == 4)
        {
          Ekrani_Temizle();
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
          Ekrani_Temizle();
          Imlec_Yaz(Secili_Satir_Yeri);
          Yazi_Yaz(1, SATIR_1, EKM.Bulunan_Wifiler[EKM.Imlec - 1], 19);
          Yazi_Yaz(1, SATIR_2, EKM.Bulunan_Wifiler[EKM.Imlec], 19);
          Yazi_Yaz(1, SATIR_3, EKM.Bulunan_Wifiler[EKM.Imlec + 1], 19);
          Yazi_Yaz(1, SATIR_4, EKM.Bulunan_Wifiler[EKM.Imlec + 2], 19);  
        }
        else if (Secili_Satir_Yeri == 3)
        {
          Ekrani_Temizle();
          Imlec_Yaz(Secili_Satir_Yeri);
          Yazi_Yaz(1, SATIR_1, EKM.Bulunan_Wifiler[EKM.Imlec - 2], 19);
          Yazi_Yaz(1, SATIR_2, EKM.Bulunan_Wifiler[EKM.Imlec - 1], 19);
          Yazi_Yaz(1, SATIR_3, EKM.Bulunan_Wifiler[EKM.Imlec], 19);
          Yazi_Yaz(1, SATIR_4, EKM.Bulunan_Wifiler[EKM.Imlec + 1], 19);                 
        }
        else if (Secili_Satir_Yeri == 4)
        {
          Ekrani_Temizle();
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
       
      Ekrani_Temizle();
      Kayittan_Yazi_Yaz(0, SATIR_1, Wifi_Sifre_Girin_Yeri);
       
      Baglanma_Adimi = Wifi_Sifre_Girisi;
      memset(Baglanilacak_Sifre, 0, sizeof(Baglanilacak_Sifre));
    }
  }
  else if (Baglanma_Adimi == Kayitli_Wifi_Secim)     /// kayıtlı olana bağlansın mı sorgusu
  {       
    if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
      strcpy(Baglanilacak_Wifi, EKM.Kayitli_Wifi);
      strcpy(Baglanilacak_Sifre, EKM.Kayitli_Wifi_Sifresi);
      Baglanma_Adimi = Wifi_Baglanma;   //// bağlanma yeri      
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Baglanma_Adimi = Bulunanlari_Goster;   //// bulunanları gösterme yeri
    }  
  }
  else if (Baglanma_Adimi == Wifi_Sifre_Girisi)   //// wifi şifre girme yeri
  {
    Sifre_Girisi = Wifi_Sifre_Gir();
    if (Sifre_Girisi == 99)
    {
      Baglanma_Adimi = Wifi_Tarama;
    }
    else if (Sifre_Girisi == 1)
    {
      Baglanma_Adimi = Wifi_Baglanma;
      strcpy(Baglanilacak_Sifre, EKM.Girilen_Sifre);    //// eskiden kırıntı kalmasın diye yazıldı ve baglanılacak sifre ile devam edilecek
    }
  }
  else if (Baglanma_Adimi == Wifi_Baglanma)   /// wifi bağlanma yeri
  {
    WiFi.begin(Baglanilacak_Wifi, Baglanilacak_Sifre);
    Ekrani_Temizle();

    Kayittan_Yazi_Yaz(0, SATIR_1, Lutfen_Bekleyin_Yeri);
    Kayittan_Yazi_Yaz(0, SATIR_2,Kontrol_Ediliyor_Yeri);
     
    int wifi_ilk_zaman = millis();

    while (millis() - wifi_ilk_zaman < 30000)
    {
      if (WiFi.status() == WL_CONNECTED)   //((WiFiMulti.run() == WL_CONNECTED))
      {
        Ekrani_Temizle();
        Kayittan_Yazi_Yaz(0, SATIR_1, Baglandi_Yaz_Yeri);
        Yazi_Yaz(0, SATIR_2, Baglanilacak_Wifi, 1);
        Kayittan_Yazi_Yaz(0, SATIR_3, Lutfen_Bekleyin_Yeri);

        Veri_Kaydet_String(WIFI_AD_KAYIT_YERI, Baglanilacak_Wifi);
        Veri_Kaydet_String(WIFI_SIFRE_KAYIT_YERI, Baglanilacak_Sifre);
        memset(EKM.Kayitli_Wifi, 0, sizeof(EKM.Kayitli_Wifi));
        memset(EKM.Kayitli_Wifi_Sifresi, 0, sizeof(EKM.Kayitli_Wifi_Sifresi));

        strcpy(EKM.Kayitli_Wifi, Baglanilacak_Wifi);
        strcpy(EKM.Kayitli_Wifi_Sifresi, Baglanilacak_Sifre);
        Baglanma_Adimi = Wifi_Baglandi;
        break;
      }
    }
    if ((WiFi.status() != WL_CONNECTED))  //if ((WiFiMulti.run() != WL_CONNECTED))
    {     
      ag_yok_hata();
      Baglanma_Adimi = Sifirlama;
      return BAGLANAMADI;
    }
  }
  else if (Baglanma_Adimi == Wifi_Baglandi)
  {
    Baglanma_Adimi = Sifirlama; 
      return BAGLANDI;
  }
  return DEVAM_EDIYOR;
}

/*
  @return IPTAL_ET, TAMAMLANDI, HATA_OLUSTU, DEVAM_EDIYOR
*/
unsigned char Mail_Gonderme(void)
{
  static unsigned char Mail_Asamasi = 0;
  unsigned char Islem_Durumu = 0;
  static unsigned int _ms = 0;

  if (Mail_Asamasi == Sifirlama)
  {
    if (WiFi.status() != WL_CONNECTED)   //((WiFiMulti.run() == WL_CONNECTED))
    {
      Mail_Asamasi = Wifi_Baglanma;
    }
    else
    {
      Mail_Asamasi = Alici_Girisi;
    }      
  }
  else if (Mail_Asamasi == Alici_Girisi)
  {
    Islem_Durumu = Alici_Mail_Girisi();
    if (Islem_Durumu == ALICI_GIRILDI)
    {
      Ekrani_Temizle();
      Kayittan_Yazi_Yaz(1,SATIR_1,Gonderiliyor_Yeri);
      Mail_Asamasi = Mail_Atma;
    }
    else if (Islem_Durumu == IPTAL_ET)
    {
      Mail_Asamasi = Sifirlama;
      return IPTAL_ET;
    }
  }
  else if (Mail_Asamasi == Wifi_Baglanma)
  {
    Islem_Durumu = Wifi_Baglan();
    if(Islem_Durumu == BAGLANDI)
    {
      Buzer_Ac;
      EKM.Buzer_Calma_ms = 50;
      Kayittan_Yazi_Yaz(0, SATIR_1, Baglandi_Yaz_Yeri);
      Bekle_ms(1000);
      Mail_Asamasi = Alici_Girisi;
    }
    else if(Islem_Durumu == BAGLANAMADI)
    {
      Mail_Asamasi = Bekle_ve_Cik;
      _ms = EKM.MS;
    }
    else if(Islem_Durumu == WIFI_BULUNAMADI)
    {
      Mail_Asamasi = Bekle_ve_Cik;
      _ms = EKM.MS;
    }
    else if(Islem_Durumu == IPTAL_ET)
    {
      Mail_Asamasi = Sifirlama;
      return IPTAL_ET;
    }
  }
  else if (Mail_Asamasi == Mail_Atma)
  {
    Islem_Durumu = Mail_AT();
    if(Islem_Durumu == 1)
    {
      Mail_Asamasi = Sifirlama;
      Buzer_Ac;
      EKM.Buzer_Calma_ms = KISA_BUZER;
      Kayittan_Yazi_Yaz(1,SATIR_1,E_Posta_Gonderildi_Yeri);
      Bekle_ms(2000);
      return TAMAMLANDI;
    }
    else
    {
      Mail_Asamasi = Sifirlama;
      EKM.Buzer_Calma_ms = UZUN_BUZER;
      Kayittan_Yazi_Yaz(1,SATIR_1,E_Posta_Gonderilemedi_Yeri);
      Bekle_ms(2000);
      return HATA_OLUSTU;
    }
  }
  else if (Mail_Asamasi == Bekle_ve_Cik)
  {
    if((EKM.MS - _ms) > UZUN_BUZER)
    {
      Mail_Asamasi = Sifirlama;
      return HATA_OLUSTU;
    }
    
  }

  return DEVAM_EDIYOR;
}
/*
  @return ALICI_GIRILDI,IPTAL_ET,DEVAM_EDIYOR
*/
unsigned char Alici_Mail_Girisi(void)
{
  static unsigned char Mail_Giris_Adimi = 0;
  unsigned char Islem_Durumu = 0;
  static unsigned int _ms = 0;
  char Mail_Adresi[35];

  if(Mail_Giris_Adimi == Sifirlama)
  {
    Butonlari_Temizle();
    Ekrani_Temizle();
    EKM.Imlec = 1;
    Imlec_Yaz(EKM.Imlec);
    Mail_Giris_Adimi = Uzanti_Secimi;
    Islem_Durumu = 0;
    Imlec_Yaz(1);
    Yazi_Yaz(1,SATIR_1,"@gmail.com",1);
    Yazi_Yaz(1,SATIR_2,"@hotmail.com",1);
    Kayittan_Yazi_Yaz(1,SATIR_3,Diger_Yeri);
    strcpy(Mail_Adresi,EKM.Alici_Maili);
    if(strlen(Mail_Adresi)>19)
    {
      Mail_Adresi[17] = '.';
      Mail_Adresi[18] = '.';
      Mail_Adresi[19] = 0;
    }
    Yazi_Yaz(1,SATIR_4,Mail_Adresi,99);
  }
  else if(Mail_Giris_Adimi == Uzanti_Secimi)
  {
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
        Ekrani_Temizle();
        strcpy(EKM.Alici_Uzantisi,"@gmail.com");
        Mail_Giris_Adimi = Alici_Girisi;

        Kayittan_Yazi_Yaz(0,SATIR_1,Alici_Maili_Gir_Yeri);
        Mail_Gir("");
      }
      else if(EKM.Imlec == 2)
      {
        Ekrani_Temizle();
        strcpy(EKM.Alici_Uzantisi,"@hotmail.com");
        Mail_Giris_Adimi = Alici_Girisi;

        Kayittan_Yazi_Yaz(0,SATIR_1,Alici_Maili_Gir_Yeri);
        Mail_Gir("");
      }
      else if(EKM.Imlec == 3)
      {
        Ekrani_Temizle();
        Mail_Giris_Adimi = Uzanti_Girisi;   
        Kayittan_Yazi_Yaz(0,SATIR_1,E_Posta_Uzantisi_Yeri);
        Mail_Gir("@");                  
      }
      else if (EKM.Imlec == 4)
      {
        Ekrani_Temizle();
        Mail_Giris_Adimi = Sifirlama;
        return ALICI_GIRILDI;
      }
    }
    if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
    {
      Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
      Mail_Giris_Adimi = Sifirlama;
      return IPTAL_ET;
    }
  }
  else if (Mail_Giris_Adimi == Alici_Girisi)
  {
    Islem_Durumu = Mail_Gir("");
    if(Islem_Durumu == 99)
    {
      Mail_Giris_Adimi = Sifirlama;            
      Butonlari_Temizle();
      return IPTAL_ET;
    }
    else if (Islem_Durumu == 1)
    {
      strcpy(EKM.Alici_Maili,EKM.Girilen_Metin);
      strcat(EKM.Alici_Maili,EKM.Alici_Uzantisi);
      Veri_Kaydet_String(SON_ALICI_MAIL_KAYIT_YERI,EKM.Alici_Maili);
      Mail_Giris_Adimi = Sifirlama;
      Ekrani_Temizle();
      return ALICI_GIRILDI;
    }
  }
  else if (Mail_Giris_Adimi == Uzanti_Girisi)
  {
    Islem_Durumu = Mail_Gir("");
    if(Islem_Durumu == 99)
    {
      Mail_Giris_Adimi = Sifirlama;            
      Butonlari_Temizle();
      return IPTAL_ET;
    }
    else if (Islem_Durumu == 1)
    {
      strcpy(EKM.Alici_Uzantisi,"@");
      strcat(EKM.Alici_Uzantisi,EKM.Girilen_Metin);
      Mail_Giris_Adimi = Alici_Girisi;
      Ekrani_Temizle();
      Kayittan_Yazi_Yaz(0,SATIR_1,Alici_Maili_Gir_Yeri);
      Mail_Gir("");
      Islem_Durumu = 0;      
    }
  }
  return DEVAM_EDIYOR;
}

void Gonderici_Mail_Girisi(void)
{
    static unsigned char Mail_Giris_Adimi = 0, Islem_Adimi = 0;
    static unsigned int _ms = 0;
    if(Mail_Giris_Adimi == 0)
    {
        EKM.Sayfa = Gonderici_Mail_Giris_Sayfasi;
        Butonlari_Temizle();
        Ekrani_Temizle();
        Mail_Giris_Adimi = 1;
        Kayittan_Yazi_Yaz(0,SATIR_1,Gonderici_Maili_Gir_Yeri);
        Yazi_Yaz(5,SATIR_4,"@GMAIL.COM",1);
    }
    else if (Mail_Giris_Adimi == 1)
    {
        Islem_Adimi = Mail_Gir(EKM.Gonderici_Maili);
        if(Islem_Adimi == 99)
        {
            Mail_Giris_Adimi = 0;
            Diger_Ayarlar_Secim_Sayfa(1);
            Butonlari_Temizle();
        }
        else if (Islem_Adimi == 1)
        {
            strcpy(EKM.Gonderici_Maili,EKM.Girilen_Metin);
            strcat(EKM.Gonderici_Maili,"@gmail.com");
            Mail_Giris_Adimi = 2;
            Ekrani_Temizle();
            Kayittan_Yazi_Yaz(0,SATIR_1,Mail_Sifresi_Gir_Yeri);
        }
    }
    else if (Mail_Giris_Adimi == 2)     // sifre giris yeri
    {
       Islem_Adimi = Mail_Gir("");
        if(Islem_Adimi == 99)
        {
            Mail_Giris_Adimi = 0;
            Eepromdan_Verileri_Al();
            Diger_Ayarlar_Secim_Sayfa(1);
            Butonlari_Temizle();
        }
        else if (Islem_Adimi == 1)
        {
            Ekrani_Temizle();
            strcpy(EKM.Gonderici_Sifresi,EKM.Girilen_Metin);
            Veri_Kaydet_String(GONDERICI_MAIL_KAYIT_YERI,EKM.Gonderici_Maili);
            Veri_Kaydet_String(GONDERICI_MAIL_SIFRE_KAYIT_YERI,EKM.Gonderici_Sifresi);
            Kayittan_Yazi_Yaz(1,SATIR_1,Kaydedildi_Yeri);
            Mail_Giris_Adimi = 3;
            _ms = EKM.MS;
            Buzer_Ac;
            EKM.Buzer_Calma_ms = UZUN_BUZER;
        } 
    }
    else if (Mail_Giris_Adimi == 3)
    {
        if((EKM.MS - _ms) > UZUN_BUZER)
        {
            Mail_Giris_Adimi = 0;
            Diger_Ayarlar_Secim_Sayfa(1);            
        }
    }
}

/*
    @brief Status döner, 1: gönderim başarılı, 0: Gönderim başarısız
*/
unsigned char Mail_AT(void)
{
  char Mesaj[500] = {0};
  char Mail_Buff[22] = {0};
  static unsigned int _ms = 0;

  if (WiFi.status() != WL_CONNECTED)   //((WiFiMulti.run() == WL_CONNECTED))
  {
      return WIFI_BAGLANTISI_YOK;
  }

  MailClient.networkReconnect(true);

  /** Enable the debug via Serial port
   * 0 for no debugging
   * 1 for basic level debugging
   *
   * Debug port can be changed via ESP_MAIL_DEFAULT_DEBUG_PORT in ESP_Mail_FS.h
   */
  smtp.debug(0);

  /* Set the callback function to get the sending results */
  smtp.callback(smtpCallback);
  /* Declare the ESP_Mail_Session for user defined session credentials */
  ESP_Mail_Session session;

  /* Set the session config */
  session.server.host_name = "smtp.gmail.com";
  session.server.port = esp_mail_smtp_port_587;
  session.login.email = EKM.Gonderici_Maili;//EKM.Gonderici_Maili;
  session.login.password = EKM.Gonderici_Sifresi;

  /* Set the NTP config time */
  // session.time.ntp_server = F("pool.ntp.org,time.nist.gov");
  // session.time.gmt_offset = 3;
  // session.time.day_light_offset = 0;

  SMTP_Message message;

  /* Set the message headers */
  message.sender.name = EKM.Cihaz_Adi; // This witll be used with 'MAIL FROM' command and 'From' header field.
  message.sender.email = EKM.Gonderici_Maili; // This witll be used with 'From' header field.
  message.subject = Dil_Listesi[(Yapilan_Islemler_Yeri*DIL_SAYISI)+EKM.Dil];
  message.addRecipient(Yazilacaklar.Plaka, EKM.Alici_Maili); // This will be used with RCPT TO command and 'To' header field.

  // strcpy(Mesaj,EKM.Cihaz_Adi);        // baslık için

  //  /* Set the custom message header */
  // message.addHeader(EKM.Cihaz_Adi;
  
  // for(char ix = 0; ix < strlen(Mesaj); ix++)
  // message.subject += Mesaj[ix];               // baslık yazıldı
  
  if (EKM.E_Seri_No == EKM.Seri_No)
  {
    Seri_No_Arttir();
  }

  strcpy(Mesaj,Dil_Listesi[(Sira_No_Yeri*DIL_SAYISI)+EKM.Dil]);
  sprintf(Mail_Buff,"%d ", EKM.Seri_No);
  strcat(Mesaj,Mail_Buff);
  strcat(Mesaj,"<br>");

  //strcat(Mesaj,"<h2>");
  strcat(Mesaj,Dil_Listesi[(Yapilan_Islemler_Yeri*DIL_SAYISI)+EKM.Dil]);
  //strcat(Mesaj,"</h2>");
  strcat(Mesaj,"<br>");

  // strcat(Mesaj,Dil_Listesi[(Vakum_Dk_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
  // sprintf(Mail_Buff,"%d ", Yazilacaklar.Vakum_Dk);
  // strcat(Mesaj,Mail_Buff);
  // strcat(Mesaj,"<br>");

  strcat(Mesaj,Dil_Listesi[(Vakum_Dk_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
  sprintf(Mail_Buff,"%d ", Yazilacaklar.Vakum_Dk);
  strcat(Mesaj,Mail_Buff);
  strcat(Mesaj,Dil_Listesi[(Dak_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
  strcat(Mesaj,"<br>");

  strcat(Mesaj,Dil_Listesi[(Kacak_Dk_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
  sprintf(Mail_Buff,"%d ", Yazilacaklar.Kacak_Dk);
  strcat(Mesaj,Mail_Buff);
  strcat(Mesaj,Dil_Listesi[(Dak_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
  strcat(Mesaj,"<br>");

  strcat(Mesaj,Dil_Listesi[(Yeni_Yag_ml_Yeri*DIL_SAYISI)+EKM.Dil]);
  if(EKM.Yag_Dolumu == 1)
      strcat(Mesaj,Dil_Listesi[(Evet_Yeri*DIL_SAYISI)+EKM.Dil]);
  else
      strcat(Mesaj,Dil_Listesi[(Hayir_Yeri*DIL_SAYISI)+EKM.Dil]);
  strcat(Mesaj,"<br>");

  strcat(Mesaj,Dil_Listesi[(Doldurulan_Gaz_gr_Yeri*DIL_SAYISI)+EKM.Dil]);
  sprintf(Mail_Buff,"%d ", Yazilacaklar.Dolan_Gr);
  strcat(Mesaj,Mail_Buff);
  strcat(Mesaj,Dil_Listesi[(Gr_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
  strcat(Mesaj,"<br>");

  strcat(Mesaj,Dil_Listesi[(Cekilen_Gaz_gr_Yeri*DIL_SAYISI)+EKM.Dil]);
  sprintf(Mail_Buff,"%d ", Yazilacaklar.Cekilen_Gr);
  strcat(Mesaj,Mail_Buff);
  strcat(Mesaj,Dil_Listesi[(Gr_Yaz_Yeri*DIL_SAYISI)+EKM.Dil]);
  strcat(Mesaj,"<br>");

  strcat(Mesaj,Dil_Listesi[(Plaka_Yeri*DIL_SAYISI)+EKM.Dil]);
  strcat(Mesaj,Yazilacaklar.Plaka);
  strcat(Mesaj,"<br>");

  // for(short ix = 0; ix < strlen(Mesaj); ix++)
  // {
  //   message.text.content += Mesaj[ix];
  //   Bekle_ms(10);
  // }


  message.html.content = Mesaj;
  message.text.charSet = "us-ascii";
  message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

  //String textMsg = "This is simple plain text message";
  //message.text.content = Mesaj;

  /** If the message to send is a large string, to reduce the memory used from internal copying  while sending,
   * you can assign string to message.text.blob by cast your string to uint8_t array like this
   *
   * String myBigString = "..... ......";
   * message.text.blob.data = (uint8_t *)myBigString.c_str();
   * message.text.blob.size = myBigString.length();
   *
   * or assign string to message.text.nonCopyContent, like this
   *
   * message.text.nonCopyContent = myBigString.c_str();
   *
   * Only base64 encoding is supported for content transfer encoding in this case.
   */

  /** The Plain text message character set e.g.
   * us-ascii
   * utf-8
   * utf-7
   * The default value is utf-8
   */
  message.text.charSet = F("us-ascii");
  

  /** The content transfer encoding e.g.
   * enc_7bit or "7bit" (not encoded)
   * enc_qp or "quoted-printable" (encoded)
   * enc_base64 or "base64" (encoded)
   * enc_binary or "binary" (not encoded)
   * enc_8bit or "8bit" (not encoded)
   * The default value is "7bit"
   */
  message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

  // If this is a reply message
  // message.in_reply_to = "<parent message id>";
  // message.references = "<parent references> <parent message id>";

  /** The message priority
   * esp_mail_smtp_priority_high or 1
   * esp_mail_smtp_priority_normal or 3
   * esp_mail_smtp_priority_low or 5
   * The default value is esp_mail_smtp_priority_low
   */
  message.priority = esp_mail_smtp_priority::esp_mail_smtp_priority_low;

  _ms = EKM.MS;
  // /* Connect to the server */
  while (!smtp.connect(&session /* session credentials */))
  {
    if((EKM.MS - _ms) > 90000)
      return HATA_OLUSTU;
  }
    //return;
  
  /* Start sending Email and close the session */
  if (!MailClient.sendMail(&smtp, &message))
  {
    
    return HATA_OLUSTU;
   // Serial.println(smtp.errorReason());
  }  
 
  // to clear sending result log
  // smtp.sendingResult.clear();

  // ESP_MAIL_PRINTF("Free Heap: %d\n", MailClient.getFreeHeap());

  return TAMAMLANDI;
}


