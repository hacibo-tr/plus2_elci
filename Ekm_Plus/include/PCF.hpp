
#ifndef PCF575_H
#define PCF575_H

#define Kompresor_SSR_Deg             0xFFFE;
#define Vakum_SSR_Deg                 0xFFFD;
#define Yuksek_Basinc_Valf_Deg        0xFFFB;
#define Gaz_Valf_Deg                  0xFFF7;  
#define Eski_Yag_Valf_Deg             0xFFEF;
#define Yeni_Yag_Valf_Deg             0xFFDF;
#define Alcak_Basinc_Valf_Deg         0xFFBF;
#define Kompresor_Yag_Valf_Deg        0xFF7F;
#define Isitici_Deg                   0xFEFF;
#define Yag_Giris_Nem_Valf_Deg        0xFDFF;
#define Hava_Tahliye_Valf_Deg         0xFBFF;
#define Fan_Deg                       0xF7FF;
#define Yikama_Valf_Deg               0xEFFF;
#define Hibrit_Yag_Valf_Deg           0xDFFF;
#define UV_Yag_Valf_Deg               0xBFFF;
#define Gaz_Analiz_Valf_Deg           0x7FFF;         


enum SSRLER
{
  Vakum_Ssr,
  Kompresor_Ssr,
  Yuksek_Basinc_Valf_Ssr,
  Gaz_Valf_Ssr,
  Eski_Yag_Valf_Ssr,
  Yeni_Yag_Valf_Ssr,
  Alcak_Basinc_Valf_Ssr,
  Kompresor_Yag_Valf_Ssr,
  Isitici_Ssr,
  Yag_Giris_Nem_Valf_Ssr,
  Hava_Tahliye_Valf_Ssr,
  Fan_Ssr,
  Yikama_Valf_Ssr,
  Hibrit_Yag_Valf_Ssr,
  UV_Yag_Valf_Ssr,
  Gaz_Analiz_Valf_Ssr,

};

#endif

 //      if (Buton[Yukari_Buton].Olay == UZUN_BASILDI_OLAYI)
  //       {
  //         Buzer_Kapa;
  //         if (Buton[Yukari_Buton].Durum == 0)
  //           Buton[Yukari_Buton].Olay = OLAYI_TEMIZLE;
  //         if (Vakum_Suresi <= 88)
  //           Vakum_Suresi += 2;         
  //         Lcd_Sayi_Yaz(0, Satir_2 - 12, Vakum_Suresi, 2, 2); 
  //         delay(100);
  //       }
  // if (Buton[Asagi_Buton].Olay == UZUN_BASILDI_OLAYI)
  // {
  //   Buzer_Kapa;
  //   if (Buton[Asagi_Buton].Durum == 0)
  //     Buton[Asagi_Buton].Olay = OLAYI_TEMIZLE;
  //   if (Vakum_Suresi > EKM.Vakum_Suresi_Dk + 1)
  //     Vakum_Suresi -= 2;        
  //   Lcd_Sayi_Yaz(0, Satir_2 - 12, Vakum_Suresi, 2, 2);
  //   delay(100);
  // }

  // if (Yazdirma_Asamasi == 0)
  //   {
  //     Sayi_Giris_Durumu = Seri_No_Gir(8, SATIR_2, &EKM.Seri_No, 6);

  //     if (Sayi_Giris_Durumu == 1)
  //     {
  //       lcd.clear();

  //       Kayittan_Yazi_Yaz(0, SATIR_1,Yazdiriliyor_Yeri);      /// toplam 900ms delay beklemesi var
  //       Printer_Ayarla(27, 64, 0);
  //       delay(200);
  //       Printer_Ayarla(29, 33, 1);
  //       Printer_Ayarla(27, 74, 50);

  //       Printer_Yazdir(EKM.Cihaz_Adi, 13, 10);
  //       delay(100);
  //       Zaman_Al(&Rtc_Zamani);

  //       Printer_Ayarla(29, 33, 0);
  //       Printer_Ayarla(27, 74, 20);

  //       Printer_Yazdir(Dil_Listesi[Yapilan_Islemler_Yeri], 13, 10);
  //       delay(100);
  //       Printer_Yazilacak[0] = (Rtc_Zamani.Gun / 10) + 48;
  //       Printer_Yazilacak[1] = (Rtc_Zamani.Gun % 10) + 48;

  //       Printer_Yazilacak[2] = '/';

  //       Printer_Yazilacak[3] = (Rtc_Zamani.Ay / 10) + 48;
  //       Printer_Yazilacak[4] = (Rtc_Zamani.Ay % 10) + 48;

  //       Printer_Yazilacak[5] = '/';

  //       Printer_Yazilacak[6] = (Rtc_Zamani.Yil / 10) + 48;
  //       Printer_Yazilacak[7] = (Rtc_Zamani.Yil % 10) + 48;

  //       Printer_Yazilacak[8] = ' ';

  //       Printer_Yazilacak[9] = (Rtc_Zamani.Saat / 10) + 48;
  //       Printer_Yazilacak[10] = (Rtc_Zamani.Saat % 10) + 48;

  //       Printer_Yazilacak[11] = ':';

  //       Printer_Yazilacak[12] = (Rtc_Zamani.Dk / 10) + 48;
  //       Printer_Yazilacak[13] = (Rtc_Zamani.Dk % 10) + 48;

  //       Printer_Yazilacak[14] = ':';

  //       Printer_Yazilacak[15] = (Rtc_Zamani.Sn / 10) + 48;
  //       Printer_Yazilacak[16] = (Rtc_Zamani.Sn % 10) + 48;

  //       Printer_Yazdir(Printer_Yazilacak, 13, 10);

  //       memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
  //       strcat(Printer_Yazilacak,Dil_Listesi[Seri_No_Yeri]);
  //       sprintf(Printer_Yazilacak,"%d ", EKM.Seri_No);
  //       Printer_Yazdir(Printer_Yazilacak, 13, 10);
  //       delay(100);
  //       memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
  //       strcat(Printer_Yazilacak,Dil_Listesi[Vakum_Dk_Yaz_Yeri]);
  //       sprintf(Printer_Yazilacak, "%d ", Yazilacaklar.Vakum_Dk);
  //       strcat(Printer_Yazilacak,Dil_Listesi[Dak_Yaz_Yeri]);
  //       Printer_Yazdir(Printer_Yazilacak, 13, 10);
  //       delay(100);
  //       memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
  //       strcat(Printer_Yazilacak,Dil_Listesi[Kacak_Dk_Yaz_Yeri]);
  //       sprintf(Printer_Yazilacak, "%d ", Yazilacaklar.Kacak_Dk);
  //       strcat(Printer_Yazilacak,Dil_Listesi[Dak_Yaz_Yeri]);
  //       Printer_Yazdir(Printer_Yazilacak, 13, 10);
  //       delay(100);
        
  //       memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
  //       strcat(Printer_Yazilacak,Dil_Listesi[Yeni_Yag_ml_Yeri]);
  //       if(Yag_Dolumu == 1)
  //         strcat(Printer_Yazilacak,Dil_Listesi[Evet_Yeri]);
  //       else
  //         strcat(Printer_Yazilacak,Dil_Listesi[Hayir_Yeri]);

  //       //strcat(Printer_Yazilacak,Gr_Yaz_Yeri);
  //       Printer_Yazdir(Printer_Yazilacak, 13, 10);
  //       delay(100);

  //       memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
  //       strcat(Printer_Yazilacak,Dil_Listesi[UV_Yag_ml_Yeri]);
  //       // if(Yag_Dolumu == 1)
  //       //   strcat(Printer_Yazilacak,Evet_Yeri);
  //       // else
  //         strcat(Printer_Yazilacak,Dil_Listesi[Hayir_Yeri]);

  //       //strcat(Printer_Yazilacak,Gr_Yaz_Yeri);
  //       Printer_Yazdir(Printer_Yazilacak, 13, 10);
  //       delay(100);

  //       memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
  //       strcat(Printer_Yazilacak,Dil_Listesi[Hibrit_Yag_ml_Yeri]);
  //       // if(Yag_Dolumu == 1)
  //       //   strcat(Printer_Yazilacak,Evet_Yeri);
  //       // else
  //         strcat(Printer_Yazilacak,Dil_Listesi[Hayir_Yeri]);

  //       //strcat(Printer_Yazilacak,Gr_Yaz_Yeri);
  //       Printer_Yazdir(Printer_Yazilacak, 13, 10);
  //       delay(100);

  //       memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
  //       strcat(Printer_Yazilacak,Dil_Listesi[Doldurulan_Gaz_gr_Yeri]);
  //       sprintf(Printer_Yazilacak, "%d ", Yazilacaklar.Dolan_Gr);
  //       strcat(Printer_Yazilacak,Dil_Listesi[Gr_Yaz_Yeri]);
  //       Printer_Yazdir(Printer_Yazilacak, 13, 10);
  //       delay(100);

  //       memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));
  //       strcat(Printer_Yazilacak,Dil_Listesi[Plaka_Yeri]);
  //       strcat(Printer_Yazilacak,Yazilacaklar.Plaka);
  //       Printer_Yazdir(Printer_Yazilacak, 13, 10);
  //       delay(100);
        
  //       memset(Printer_Yazilacak, 0x00, strlen(Printer_Yazilacak));

  //       Printer_Ayarla(27, 74, 200);
  //       delay(100);
  //      // Yazdirildi = 1;
  //       Butonlari_Temizle();
  //       Yazdirma_Asamasi = 1;    
  //       lcd.clear();
  //       //Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
  //       Kayittan_Yazi_Yaz(16,SATIR_4,Ok_Yaz_Yeri);
  //       //Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);
  //       Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);    
  //     }
  //     else if (Sayi_Giris_Durumu == 99)
  //     {
  //       Butonlari_Temizle();
  //       lcd.clear();
  //       Gaz_Doldurma_Asamasi = Yazdirma_Sorgusu;
  //       Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
  //       Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
  //       Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);
  //       Kayittan_Yazi_Yaz(16,SATIR_4,Ok_Yaz_Yeri);
  //       Yazdirma_Asamasi = 0;          
  //     }
  //   }
  //   else if (Yazdirma_Asamasi == 1)
  //   {
  //     if (Buton[Giris_Buton].Olay == BASILDI_OLAYI)
  //     {
  //       Buton[Giris_Buton].Olay = OLAYI_TEMIZLE;
  //       Giris_Sayfa(1,1);
  //       Gaz_Doldurma_Asamasi = Sifirlama;
  //       Yazdirma_Asamasi = 0;
  //       Butonlari_Temizle();
  //       EKM.Seri_No += 1;
  //       if (EKM.Seri_No > 999999)
  //         EKM.Seri_No = 1;
  //       Veri_Kaydet_UInt(SERI_NO_KAYIT_YERI, EKM.Seri_No);
  //     }
  //     if (Buton[Geri_Buton].Olay == BASILDI_OLAYI)
  //     {
  //       Buton[Geri_Buton].Olay = OLAYI_TEMIZLE;
  //       Butonlari_Temizle();
  //       lcd.clear();
  //       Gaz_Doldurma_Asamasi = Yazdirma_Sorgusu;
  //       Kayittan_Yazi_Yaz(1,SATIR_3,Cikis_Yeri);
  //       Kayittan_Yazi_Yaz(1,SATIR_4,ESC_Yeri);
  //       Kayittan_Yazi_Yaz(14,SATIR_3,Yazdir_Yeri);
  //       Kayittan_Yazi_Yaz(16,SATIR_4,Ok_Yaz_Yeri);
  //       Yazdirma_Asamasi = 0;
  //     }
  //   }
  // }     // else 



