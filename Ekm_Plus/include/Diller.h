
#ifndef DILLER_H
#define DILLER_H

#define DIL_SAYISI            5         //Kaç tane dil ekliyse o sayı yazılacak. 


enum Text_Yerleri
{
    Tup_Kapasite_Yeri,
    Filtre_Kapasite_Yeri,
    R134_A_Yeri,
    R1234_YF_Yeri,
    Vakum_PYagi_Yeri,
    Degistirme_Zamani_Yeri,
    Filtre_Yeri,
    Aractan_Gaz_Cek_Yeri,
    Araca_Gaz_Doldur_Yeri,
    Tupten_Gaz_Cek_Yeri,
    Arac_Veri_Yeri,
    Islem_Yeri,
    Lutfen_Bekleyin_Yeri,
    Bekleyin_Yeri,
    Kacak_Kontrol_Yeri,
    Vakum_Yapiliyor_Yeri,
    Son_Cekilen_Gr_Yeri,
    Vakum_Saat_Yeri,
    Filtre_KLN_Yeri,
    Tupten_Cekilen_Kg_Yeri,
    Cekilen_Kg_Yeri,
    Doldurulan_Kg_Yeri,
    Hava_Tahliyesi_Yeri,
    Kacak_Var_Yeri,
    Islem_Yapilamadi_Yeri,
    Tup_Dolu_Yeri,
    Gaz_Cekilemez_Yeri,
    Vakum_Dusuk_Yeri,
    Tup_Basinci_Yuksek_Yeri,
    Gaz_Yetersiz_Yeri,
    Tamamlandi_Yeri,
    Gaz_Miktari_Sor_Yeri,
    A_C_Calistirin_Yeri,
    Uyari_Yeri,
    Kalibrasyon_Unlem_Yeri,
    Eski_Yag_Tahliyesi_Yeri,
    Filtre_Degistir_Yeri,
    Agirlik_Kal_Yeri,
    Vakum_Kal_Yeri,
    Basinc_Kal_Yeri,
    Cihaz_Tupu_Bos_Olsun_Yeri,
    Kayit_Icin_ENT_Yeri,
    Agirlik_Yerlestir_Yeri,
    Kalibrasyonu_Yeri,
    Devam_Icin_ENT_Yeri,
    C_Yaz_Yeri,
    P_Yaz_Yeri,
    Vakum_Kalibrasyonu_Yeri,
    Adaptorleri_Cikar_Yeri,
    Tarih_Saat_Yeri,
    Dil_Language_Yeri,
    Turkce_Yaz_Yeri,
    Servis_Yeri,
    Sifirlama_Yeri,
    Dara_Yaz_Yeri,
    Kapali_Yaz_Yeri,
    Acik_Yaz_Yeri,
    Sifre_Yanlis_Yeri,
    Kullanim_Bilgileri_Yeri,
    Yapilan_Islemler_Yeri,
    Yeni_Yag_ml_Yeri,
    UV_Yag_ml_Yeri,
    Hibrit_Yag_ml_Yeri,
    Doldurulan_Gaz_gr_Yeri,
    Cekilen_Gaz_gr_Yeri,
    Plaka_Yeri,
    Imza_Kase_Yeri,
    Valf_Test_Yeri,
    Yazilim_Guncelle_Yeri,
    Fab_Kal_Donus_Yeri,
    Sifreyi_Girin_Yeri,
    Basinc_Kazanc_Kal_Yeri,
    Basinc_Sifir_Kal_Yeri,
    Gr_Yaz_Yeri,
    Dak_Yaz_Yeri,
    Ml_Yaz_Yeri,
    Saat_Yaz_Yeri,
    Kg_Yaz_Yeri,
    Kompresor_Yeri,
    Vakum_Valf_Pompa_Yeri,
    Yuksek_Bas_Valf_Yeri,
    Gaz_Dolum_Vaf_Yeri,
    Eski_Yag_Valf_Yeri,
    Yeni_Yag_Valf_Yeri,
    Alcak_Bas_Valf_Yeri,
    Kompresor_Yag_Valf_Yeri,
    Isitma_Kemer_Yeri,
    Yag_Ayristirici_Valf_Yeri,
    Hava_Tahliye_Valf_Yeri,
    Fanlar_Yeri,
    Yikama_Isi_Yeri,
    Hibrit_Yag_Valf_Yeri,
    UV_Yag_Valf_Yeri,
    Gaz_Analiz_Valf_Yeri,
    Hortum_Temizleme_1_Yeri,
    Islem_Yapiliyor_Yeri,
    Yapiliyor_Bekleyin_Yeri,
    Yeni_Yag_Doldurun_Yeri,
    Ayarlar_Yeri,
    Sensorler_Yeri,
    Kalibrasyon_1_Yeri,
    Hatasi_Yeri,
    Baglandi_Yaz_Yeri,
    Ileri_Yaz_Yeri,
    Geri_Yaz_Yeri,
    Devam_Yaz_Yeri,
    Kirmizi_Vanayi_Kapatin_Yeri,
    Otomobil_Yeri,
    Agir_Vasita_Yeri,
    Wifi_Bulunamadi_Yeri,
    Guncelleme_Icin_Yeri,
    Baglanti_Yapin_Yeri,
    Manuel_Yeri,
    Vakum_Dk_Yaz_Yeri,
    Kacak_Dk_Yaz_Yeri,
    Gaz_Miktari_Gr_Yaz_Yeri,
    Yeni_Yag_Gr_Yaz_Yeri,
    Baslasin_mi_Yaz_Yeri,
    Hayir_Yeri,
    Evet_Yeri,
    Devam_Icin_ENT_Bas_Yeri,
    Sistemde_Gaz_Olabilir_Yeri,
    Saatleri_Kontrol_Edin_Yeri,
    Iptal_Esc_Yaz_Yeri,
    Devam_ENT_Yaz_Yeri,
    Islem_Iptal_Edilsin_mi_Yeri,
    Cekilecek_Gaz_Yok_Yeri,
    Filtre_Az_Yeri,
    Siparis_Edin_Yeri,
    Dolum_Yapiliyor_Yeri,
    H_Temizle_ve_Gaz_Yeri,
    elcielektronik_com_Yeri,
    Cikis_Yeri,
    Yazdir_Yeri,
    ESC_Yeri,
    Sira_No_Yeri,
    Yazdiriliyor_Yeri,
    Baglanti_Hatasi_Yeri,
    Yaziliminiz_Yeri,
    Guncel_Yeri,
    Arac_Islemleri_Yeri,
    Bakimlar_Yeri,
    Kompresor_Kapatma_Yeri,
    Yazici_Baslik_Yeri,
    Sifre_Degistir_Yeri,
    Kaydedildi_Yeri,
    Kalibrasyonlar_Yeri,
    Sistem_Vakumlama_Yeri,
    Gaz_Tipi_Yeri,
    Sistem_Vakumlaniyor_Yeri,
    Gun_Ay_Yil_Yeri,
    Sistem_Bosaltma_Yeri,
    Vakum_Yag_Degistir_Yeri,
    Kompresor_Kapatma_Ayar_Yeri,
    Cihaz_Ayarlari_Yeri,
    Servis_Kontrol_Yeri,
    Tank_Kapasite_Ayar_Yeri,
    Filtre_Kapasite_Ayar_Yeri,
    Kullanim_Sifirlama_Yeri,
    Olcum_Yapiliyor_Yeri,
    Manifold_Vanalari_Ac_Yeri,
    Manifold_Vanalari_Kapa_Yeri,
    Kalibrasyon_Bekleyin_Yeri,
    Kalibrasyon_Hatasi_Yeri,
    Kontrol_Ediliyor_Yeri,
    Yazilim_Guncel_Yeri,
    Yazilim_Guncellendi_Yeri,
    Aractan_Gaz_Cekiliyor_Yeri,
    Tank_Kapasitesi_Yeri,
    Yazici_Ayari_Yeri,
    Yazici_Var_Mi_Yeri,
    Diger_Ayarlar_Yeri,
    Yazilim_Guncelleme_Yeri,
    Tekrar_Yazdir_Yeri,
    Wifi_Sifre_Girin_Yeri,
    Wifi_Bulundu_Yeri,
    Diger_Yeri,
    Baglan_Yeri,
    Servis_Raporu_Yeri,
    Atla_Yeri,
    Tankta_Gaz_Var_Yeri,
    Yazici_Test_Yeri,
    Cihaz_Adi_Degistir_Yeri,
    Gonderici_Maili_Gir_Yeri,
    Mail_Sifresi_Gir_Yeri,
    Alici_Maili_Gir_Yeri,
    E_Posta_Yeri,
    E_Posta_ve_Yazdir_Yeri,
    Gonderiliyor_Yeri,
    E_Posta_Uzantisi_Yeri,
    E_Posta_Gonderildi_Yeri,
    E_Posta_Gonderilemedi_Yeri,
    Ent_Yeri,
    Wifi_Yeri,
    Tank_Kap_Yeri,
    Bos_Alan_Yeri,
    
};



const char* const Dil_Listesi[] PROGMEM = {
//"TURKCE"            ,"INGILIZCE"          ,"LEHÇE-POLONYA"        ,"SIRPCA"              ,"ARNAVUTÇA"             
"TUP KAPASITE"        ,"CYLINDER CAP."       ,"POJEMNOSC ZBIORNIKA" ,"KAPACITET BOCE "     ,"KAPACITETI BOMBOLES" ,          //0
"FILTRE KAPASITE"     ,"FILTER CAP."         ,"POJEMNOSC FILTRA"    ,"KAPACITET FILTERA"   ,"KAPACITETI FILTERIT" ,                      //1
"R134a"               ,"R134a"               ,"R134a"               ,"R134a"               ,"R134A"               ,         //2
"R1234yf"             ,"R1234yf"             ,"R1234yf"             ,"R1234yf"             ,"R1234yf"             ,            //3
"VAKUM P.YAGI"        ,"VACUUM P.OIL"        ,"OLEJ POMPY PROZN."   ,"ULJE ZA V. PUMPU"    ,"VAJI I VAKUM POMPES" ,                    //4
"DEGISTIRME ZAMANI"   ,"TIME TO CHANGE"      ,"CZAS DO WYMIANY"     ,"VREME ZA ZAMENU "    ,"KOHA E NDERIMIT"     ,                      //5
"FILTRE"              ,"DRYER FILTER"        ,"FILTR OSUSZACZ"      ,"FILTER SUSAC"        ,"THARESI/DRIER"       ,                   //6
"ARACTAN GAZ CEK"     ,"REC. FROM VEHICLE"   ,"ODZYSK Z POJAZDU"    ,"OBRADA IZ VOZILA"    ,"TERHJEK NGA VETURA"  ,                       //7 "IZVLACENJE IZ VOZILA"
"ARACA GAZ DOLDUR"    ,"CHARGE VEHICLE"      ,"NAPELNIANIE POJAZDU" ,"PUNJENJE VOZILA"     ,"MBUSHE MAKINEN"      ,                  //8
"TUPDEN GAZ CEK"      ,"REC. FROM NEW TANK"  ,"NAPELNIANIE ZBIOR."  ,"IZVL.IZ NOVE BOCE"   ,"TERHJEK NGA BOMBOLA" ,                   //9 ??? 20 karakter
"ARAC VERI"           ,"DATABASE"            ,"PROCEDURA AUTOMAT."  ,"BAZA PODATAKA"       ,"TE DHENAT MAK."      ,                //10
"ISLEM"               ,"PROCESS"             ,"WYKONAJ"             ,"PROCES"              ,"PROCES"              ,       //11
"LUTFEN BEKLEYIN..."  ,"PLEASE WAIT..."      ,"PROSZE CZEKAC"       ,"MOLIMO SACEKAJTE "   ,"JU LUTEM PRISNI"     ,               //12
"    BEKLEYIN...     ","   PLEASE WAIT...   ","  PROSZE CZEKAC...  ","MOLIMO SACEKAJTE "   ,"JU LUTEM PRISNI"     ,               //13
"KACAK KONTROL"       ,"LEAK CONTROL"        ,"TEST SZCZELN."       ,"TEST CURENJA "       ,"KONTROLI I RRJEDHJES",                   //14
"VAKUM YAPILIYOR"     ,"VACUUMING...   "     ,"PROZNIA W TRAKCIE.." ,"VAKUUMIRANJE"        ,"VAKUMIMI"            ,      //15 
"SON CEK. GR :"       ,"LAST REC. GR:"       ,"OS.ODZYSK[g]:"       ,"POSL.IZVL.gr"        ,"GR E TERHEQUR"       ,                        //16 ??? 13 karakter
"VAKUM SAAT  :"       ,"VACUUM HOUR :"       ,"PROZNIA[min]:"       ,"VREME VAKUM.:"       ,"KOHA E VAKUMIMIT"    ,                          //17 VREME VAKUMIRANJA
"FILTRE KALAN:"       ,"FILTER REST :"       ,"PRZEFIL.[kg]:"       ,"FILTER      :"       ,"FIL.KOH.MEBTUR"      ,                       //18     
"TUPTEN C. KG:"       ,"FROM TUBE KG:"       ,"WPROWADZ[kg]:"       ,"IZ CREVA    :"       ,"NGA TUBAT"           ,                 //19     
"CEKILEN KG   :"      ,"RECOVERED KG :"      ,"ODZYSK. [kg]:"       ,"IZVUCENO KG :"       ,"E TERHJEKUR(KG)"     ,                      //20     
"DOLDURULAN KG:"      ,"TOTAL FILL KG:"      ,"NAPELN. [kg]:"       ,"UK.NAPUNJ KG:"       ,"E MBUSHUR  (KG)"     ,                     //21 ??? 14 karakter    
"   HAVA TAHLIYESI   ","    AIR PURGING     ","OCZYSZCZANIE PRZEWOD","IZBACIV. VAZDUHA"    ,"LIRIMI I TEPRICES"   ,                      //22
"KACAK VAR"           ,"LEAK IN SYSTEM"      ,"WYCIEK W UKLADZIE"   ,"CURENJE U SISTEMU"   ,"RRJEDHJE NE SISTEM"  ,                      //23
"ISLEM YAPILAMADI"    ,"PROCESS WAS ENDED"   ,"PROCES ZAKONCZONY"   ,"PROCES JE ZAVRSEN"   ,"PROCESI PERFUNDOJ"   ,                    //24
"TUP DOLU"            ,"TANK IS FULL"        ,"PELNY ZBIORNIK"      ,"REZERVOAR JE PUN"    ,"BOMBOLA FULL"        ,              //25
"GAZ CEKILEMEZ"       ,"GAS RECOVERY STOPPED","ODZYSK ZATRZYMANY"   ,"ZAUST.IZVL. GASA"    ,"U NDAL TERHEQJA"     ,               //26 ??? 20 karakter  
"VAKUM DUSUK"         ,"LOW VACUUM"          ,"SLABA PROZNIA"       ,"SLAB VAKUUM"         ,"VAKUMI I  DOBET"     ,                        //27
"TUP BASINCI YUKSEK"  ,"HIGH PRESS. IN TUBE" ,"WYSOKIE CISN. W UKL.","VISOK PRIT.U CREVU"  ,"PRES.BOMBOL LART"    ,                     //28 ??? 20 karakter 
"    GAZ YETERSIZ    ","  INSUFFICIENT GAS  ","  MALA ILOSC GAZU   ","NEDOVOLJNO GASA"     ,"GAS PA MJAFTUSHEM"   ,                //29
"    TAMAMLANDI"      ,"    COMPLETED"       ,"    ZAKONCZONO"      ,"ZAVRSENO"            ,"U KOMPLETUA"         ,         //30
"    GAZ MIKTARI?    ","    REFRIGERANT?    ","  RODZAJ CZYNNIKA?  ","KOLICINA GASA?"      ,"SASIA GASIT"         ,       //31
"A/C CALISTIRIN      ","START A/C           ","WLACZ KLIM W POJEZDZ","START A/C"           ,"STARTO A/C"          ,     //32     
"UYARI !"             ,"WARNING!"            ,"UWAGA !"             ,"UPOZORENJE"          ,"VEREJTJE"            ,  //33                             
"KALIBRASYON!"        ,"CALIBRATION!"        ,"KALIBRACJA!"         ,"KALIBRACIJA"         ,"KALIBRIMI"           ,   //34
"ESKI YAG TAHLIYESI"  ,"USED OIL DISCHARGE"  ,"OPROZ STAREGO OLEJU" ,"IZVL. STAROG ULJA"   ,"ZB.VAJIT VJETER"     ,                        //35 ??? 20 karakter 
"FILTRE DEGISTIR"     ,"CHANGE FILTER"       ,"WYMIEN FILTR"        ,"ZAMENITE FILTER"     ,"NDERRO FILTERIN"     ,                //36                                         
"AGIRLIK KAL."        ,"WEIGHT CALIB."       ,"KALIBRACJA WAGI"     ,"KALIBRACIJA VAGE"    ,"KALIB PESHES"        ,                     //37
"VAKUM KAL."          ,"VACUUM CALIB."       ,"KALIBRACJA PROZNI"   ,"KALIBRACUJA VAKUUMA" ,"KALIB VAKUMIT"       ,                     //38
"BASINC KAL."         ,"PRESSURE CALIB."     ,"KALIBRACJA CISNIENI" ,"KALIBR. PRITISKA"    ,"KALIB PRESIONI"      ,                     //39     !!!
"CIHAZ TUPU BOS OLSUN","TANK MUST BE EMPTY"  ,"ZBIOR MUSI BYC PUSTY","BOCA DA BUDE PRAZNA" ,"ZBRAZ BOMBOLEN"      ,                          //40  ??? 20 karakter
"KAYIT ICIN (ENT)"    ,"PRESS (ENT) TO SAVE" ,"(ENT) ABY ZAPISAC"   ,"ENTER DA ZAPAMTI"    ,"SHTYP(ENT)PER REGJ." ,                        //41 ??? 20 karakter
"AGIRLIK YERLESTIR"   ,"PLACE CALIB. WEIGHT" ,"UMIESC ODWAZ WZORCOW","STAVI TEG ZA KALIBR.","VENDOS PESHE"        ,                          //42  ??? 20 karakter
"KALIBRASYONU"        ,"CALIBRATION"         ,"KALIBRACJA"          ,"KALIBRACIJA"         ,"KALIBRIMI"           ,                      //43
"DEVAM ICIN (ENT)"    ,"CONTINUE (ENT)"      ,"KONTYNUUJ (ENT)"     ,"NASTAVAK (ENT)"      ,"VAZHDO SHTYP(ENT)"   ,                          //44
"C:"                  ,"C:"                  ,"C:"                  ,"C:"                  ,"C:"                  ,                         //45
"P:"                  ,"P:"                  ,"P:"                  ,"P:"                  ,"C:"                  ,                        //46
"VAKUM KALIBRASYONU"  ,"VACUUM CALIBRATION"  ,"KALIBRACJA PROZNI"   ,"KALIBRACIJA VAKUUMA" ,"KALIBRIMI VAKUMIT"   ,                          //47
"ADAPTORLERI CIKAR"   ,"REMOVE COUPLERS"     ,"ODKREC ZLACZ."       ,"SKINITE PRIKLJUCKE"  ,"NXJIR ADAPTERET"     ,                       //48
"TARIH/SAAT"          ,"DATE/TIME"           ,"DATA/CZAS"           ,"DATUM/VREME"         ,"DATA/ORA"            ,               //49
"DIL-LANGUAGE"        ,"LANGUAGE"            ,"JEZYK-LANGUAGE"      ,"JEZIK"               ,"GJUHA"               ,           //50
"TURKCE"              ,"ENGLISH"             ,"POLSKI"              ,"SRPSKI"              ,"SHQIP"               ,          //51
"SERVIS"              ,"SERVICE"             ,"SERWIS"              ,"SERVIS"              ,"SERVIS"              ,          //52
"SIFIRLAMA"           ,"ZERO"                ,"ZERO"                ,"NULA"                ,"ZERO"                ,       //53
"DARA"                ,"TARE"                ,"TARA"                ,"TARE"                ,"TARE"                ,      //54
"KAPALI"              ,"CLOSED"              ,"ZAMKNIETE"           ,"ZATVORENO"           ,"MBYLLUR"             ,        //55
"ACIK"                ,"OPEN"                ,"OTWARTE"             ,"OTVORENO "           ,"E HAPUR"             ,       //56
"SIFRE YANLIS"        ,"PASSWORD INVALID"    ,"BLEDNE HASLO"        ,"NEISPRAVNA LOZINKA"  ,"KODI GABIM"          ,         //57 
"KULLANIM BILGILERI"  ,"USAGE INFORMATION"   ,"INFOR.DOTYCZACE UZY" ,"INFO. O KORISCENJU"  ,"INFORMACIONET"       ,           //58 ??? 20 karakter
"YAPILAN ISLEMLER"    ,"COMPLETED OPERATIONS","OPERACJE ZAKONCZONE" ,"OPERACIJA KOMPL"     ,"TE PERFUNDUARAT"     ,            //59 ??? 20 karakter  
"YENI YAG      [ml]:" ,"NEW OIL       [ml]:" ,"OLEJ PAG       [ml]:","NOVO ULJE  (ml)"     ,"VAJI I RI"           ,     //60
"UV YAG        [ml]:" ,"UV OIL        [ml]:" ,"BARWNIK UV     [ml]:","UV BOJA    (ml)"     ,"UV NGJYRA"           ,    //61
"HIBRIT YAG    [ml]:" ,"HIBRIT OIL    [ml]:" ,"OLEJ POE       [ml]:","HIBRIDNO ULJE(ml)"   ,"VAJI HIBRIT"         ,     //62
"DOLDURULAN GAZ[GR]:" ,"FILLED REFRIG.[GR]:" ,"NAPELNI. CZYNNIK[g]:","NAPUNJENO GASA (gr)" ,"SHUMA E MBUSHUR"     ,        //63
"CEKILEN GAZ   [GR]:" ,"RECOVER REFRIG.[GR]:","ODZYSKANY CZYNNIK[g]","IZVUCENO GASA  (gr)" ,"SHUMA E TERHEQUR"    ,        //64                
"PLAKA:"              ,"PLATE:"              ,"NUMER REJ.:"         ,"REGISTARSKI BROJ"    ,"REGJISTRIMI"         ,  //65                   
"IMZA/KASE"           ,"SIGNATURE/STAMP"     ,"PODPIS"              ,"POTPIS"              ,"NENSHKRIMI"          ,                         //66       
"VALF TEST"           ,"VALVE TEST"          ,"TEST ZAWOROW"        ,"TEST VENTILA"        ,"TEST VALFI"          ,                        //67            
"YAZILIM GUNCELLE"    ,"SOFTWARE UPDATE"     ,"AKTUALIZACJA OPROGR" ,"SOFTWARE UPDATE"     ,"PERDITSIM"           ,                       //68                 
"FAB.KAL.DONUS"       ,"FAC.CAL.RESET"       ,"PRZYWROC UST FABRY." ,"FABRICKA KALIBRACIJA","KAL.FABBRIKE"        ,                         //69
"SIFREYI GIRIN"       ,"ENTER PASSWORD"      ,"WPISZ HASLO"         ,"UNESITE LOZINKU"     ,"SHKRUAJ KODIN"       ,                        //70
"BASINC KAZANC KAL."  ,"PRESSURE GAIN CAL."  ,"KAL.WSKAZAN CISNIEN" ,"KAL.POVECANJA PRIT." ,"KAL.I PER.PRESION"   ,                          //71 ??? 20 karakter
"BASINC SIFIR KAL."   ,"PRESSURE ZERO CAL."  ,"KALIBRA. CISNIENIA " ,"KAL.PRITISKA"        ,"SHTYPJA 0 KALIBR"    ,                          //72
"gr"                  ,"gr"                  ,"g"                   ,"gr"                  ,"gr"                  ,          //73
"dak"                 ,"min"                 ,"min"                 ,"min"                 ,"min"                 ,          //74
"ml"                  ,"ml"                  ,"ml"                  ,"ml"                  ,"ml"                  ,        //75
"saat"                ,"hour"                ,"godzina"             ,"godina"              ,"viti"                ,         //76
"kg"                  ,"kg"                  ,"kg"                  ,"kg"                  ,"kg"                  ,      //77
"KOMPRESOR"           ,"COMPRESSOR"          ,"SPREZARKA"           ,"KOMPRESOR"           ,"KOMPRESOR"           ,            //78  
"VAKUM VALF+POMPA"    ,"VACUUM VALVE+PUMP"   ,"P.PROZ + ZAWOR"      ,"VENTIL VAKUMA+PUMPA" ,"VALFI VAK POMP"      ,                //79
"YUKSEK BAS.VALF"     ,"HIGH PRESSURE VALVE" ,"ZAWOR HP"            ,"VENTIL VIS.PRITISKA" ,"VALFI SHTYP LART"    ,                 //80 ??? 20 karakter
"GAZ DOLUM VALF"      ,"GAS FILLING VALVE"   ,"ZAWOR NAP. CZYNN."   ,"VENTIL ZA PUNJ.GASA" ,"VALFI PER MBSUHJE"   ,                 //81 ??? 20 karakter
"ESKI YAG VALF"       ,"USED OIL VALVE"      ,"ZAWOR STAREGO OLEJU" ,"VENTIL STAROG ULJA"  ,"VALFI VAJIT VJETER"  ,                 //82 ??? 20 karakter
"YENI YAG VALF"       ,"NEW OIL VALVE"       ,"ZAWOR OLEJU PAG"     ,"VENTIL NOVOG ULJA"   ,"VALFI VAJIT TRI"     ,             //83
"ALCAK BAS.VALF"      ,"LOW PRESSURE VALVE"  ,"ZAWOR LP"            ,"VENTIL NIS.PRITISKA" ,"VALFI SHTYPJES ULT"  ,               //84 ??? 20 karakter
"KOMPRESOR YAG VALF"  ,"COMP. OIL VALVE"     ,"ZAWOR OLEJU SPREZ."  ,"VENTIL KOMPRESORA"   ,"VALFI KOMPRESORIT"   ,             //85
"ISITMA KEMER"        ,"GAS HEATER"          ,"GRZALKA BUTLI"       ,"GREJAC GASA"         ,"NXEMSI GASIT"        ,      //86     
"YAG AYRISTIRICI VALF","OIL SEPERATOR VALVE" ,"ZAWOR SEP. OLEJU"    ,"VENTIL ODVAJACA ULJA","VALFI SEPERATOR"     ,         //87
"HAVA TAHLIYE VALF"   ,"AIR PURGE VALVE"     ,"ZAWOR ODPOWIETRZ."   ,"VENTIL IZVL.VAZDUHA" ,"VALFI I TERPRICES"   ,          //88 ??? 20 karakter
"FANLAR"              ,"COOLING FAN"         ,"WENTYLATOR"          ,"VENTILATOR"          ,"HELIKET"             ,       //89
"YIKAMA ISITICI"      ,"FLASH HEATER"        ,"GRZALKA"             ,"GREJAC ZA ISPIRANJE" ,"NXEMSI I SHPERLARSIT",                   //90     
"HIBRIT YAG VALFI"    ,"HYBRIT OIL"          ,"ZAWOR OLEJU POE"     ,"HIBRIDNO ULJE"       ,"VAJI HIBRID"         ,       //91
"UV YAG VALFI"        ,"UV OIL"              ,"ZAWOR BARWNIA UV"    ,"UV BOJA"             ,"UV NGJYR"            ,     //92
"GAZ ANALIZ VALFI"    ,"GAS ANALYSIS VALVE"  ,"ZAWOR ANALIZY GAZU"  ,"VENTIL ANALIZ.GASA"  ,"VALF ANALIZ GASIT"   ,             //93 ??? 20 karakter
"HORTUM TEMIZLEME"    ,"HOSE FLUSH"          ,"PLUKANIE PRZEOWDOW"  ,"CREVO ZA ISPIRANJE"  ,"PASTRIMI GYPAVE"     ,          //94 
"ISLEM YAPILIYOR"     ,"IN PROGRESS..."      ,"OPERACJA W TRAKCIE"  ,"U TOKU.."            ,"NE PROCES"           ,   //95
"YAPILIYOR BEKLEYIN"  ,"IN PROGRESS WAIT..." ,"PROSZE CZEKAC"       ,"PROCES JE U TOKU"    ,"NE PROCES PRISNI"    ,         //96
"YENI YAG DOLDURUN(^)","FILL NEW OIL(^)"     ,"NAP NOWYM OLEJEM(^)","UBACITE NOVO ULJE(^)" ,"MBUSHENI VAJIN E RI^",           //97
"AYARLAR"             ,"SETTINGS"            ,"USTAWIENIA"          ,"PODESAVANJE"         ,"CILESIMET"           ,         //98
"SENSORLER"           ,"SENSORS"             ,"CZUJNIKI"            ,"SENZORI"             ,"SENZOR"              ,           //99
"KALIBRASYON"         ,"CALIBRATION"         ,"KALIBRACJA"          ,"KALIBRACIJA"         ,"KALIBRIMI"           ,            //100
"HATASI!"             ,"ERROR!"              ,"BLAD"                ,"GRESKA"              ,"GABIMI"              ,        //101
"BAGLANDI"            ,"CONNECTED"           ,"POLACZONO"           ,"POVEZANO"            ,"NE LIDHJE"           ,           //102
"ILERI"               ,"NEXT"                ,"NESTEPNY"            ,"SLEDECE"             ,"VAZHDO"              ,      //103
"GERI "               ,"BACK"                ,"WROC"                ,"NAZAD"               ,"MRAPA"               ,    //104
"    DEVAM"           ," CONTINUE"           ,"KONTYNUUJ"           ,"NASTAVAK"            ,"VAZHDO"              ,    //105
"KIRMIZI VANA KAPATIN","CLOSE RED VALVE     ","ZAMKNIJ HP"          ,"ZATVORI CRVENI VENT" ,"MBYLE VALVEN E KUQE" ,                //106 ??? 20 karakter
"OTOMOBIL"            ,"CAR"                 ,"POJAZDY OSOBOWE"     ,"AUTOMOBIL"           ,"VETURA"              ,  //107
"AGIR VASITA"         ,"HEAVY VEHICLE"       ,"POJAZDY UZYTKOWE"    ,"TESKA VOZILA"        ,"MJETET E RENDA"      ,          //108 
"WIFI BULUNAMADI"     ,"WIFI NOT FOUND"      ,"NIE ODNALEZIONO WIFI","WiFi NIJE PRONADJEN" ,"WIFI NUK U GJET"     ,         //109
"GUNCELLEME ICIN"     ,"FOR UPDATE"          ,"ABY ZAKTUALIZOWAC"   ,"ZA NADOGRADNJU"      ,"PER PERDITESIME"     ,        //110
"BAGLANTI YAPIN"      ,"CONNECT THE WIFI "   ,"PODLACZ WIFI"        ,"POVEZITE NA WiFi"    ,"LIDHUNI"             ,                  //111
"MANUEL"              ,"MANUEL"              ,"TRYB RECZNY"         ,"UPUTSTVO"            ,"MANUEL"              ,                //112
"VAKUM ZAMANI  [DK]:" , "VACUUM TIME [MIN]:" ,"CZAS PROZNI[MIN]:"   ,"VREME VAKUMA [MIN]"  ,"KOHA E VAKUMIMIT"    ,                         //113    
"KACAK KONTROL [DK]:" , "LEAK CONTROL[MIN]:" ,"P.SZCZELNOSCI [MIN]:","KONTROLA CURENJA"    ,"KOHA E KONTROLIT"    ,                        //114    
"GAZ MIKTARI   [GR]:" , "GAS MARJIN   [GR]:" ,"ILOSC GAZU [g]:"     ,"KOLICINA GASA(GR)"   ,"SASIA GASIT(GR)"     ,                      //115
"YENI YAG DOLUM     " , "NEW OIL FILL      " ,"NAP. OLEJEM    "     ,"NOVO ULJE PUNJENJE"  ,"VAJI I RI    "       ,                   //116
"ISLEM BASLASIN MI?"  , "START PROSES?"      ,"ROZPOCZAC PROCES?"   ,"POCINJANJE PROCESA"  ,"TE NIS PROCESI?"     ,                    //117
"HAYIR"               ,"NO "                 ,"NIE"                 ,"NE"                  ,"JO"                  ,      //118
"EVET "               ,"YES"                 ,"TAK"                 ,"DA"                  ,"PO"                  ,     //119
"DEVAM ICIN ENT BAS"  ,"PRESS ENT FOR NEXT"  ,"ENTER ABY KONTYNU."  ,"ENT ZA NASTAVAK"     ,"SHTYP ENT PER VAZHDU",                      //120
"CIHAZDA GAZ OLABILIR","MAY BE GAS IN SYSTEM","MOZLIWY GAZ W UKLADZ","IMA GASA U SISTEMU"  ,"KA GAS NE SISTEM"    ,                 //121 ??? 20 karakter
"SAATLERI KONTROL ET" ,"CHECK THE BAROMETER" ,"SPRAWDZ CISNEINIE"   ,"PROVERI VREME AMB."  ,"SHIKO MANOMETRAT"    , //122
"IPTAL(ESC)"          ,"CANCEL(ESC)"         ,"PRZERWIJ(ESC)"       ,"OTKAZI"              ,"ANULO(ESC)"          ,         //123
"DEVAM(ENT)"          ,"NEXT(ENT)"           ,"KONTYNUUJ(ENT)"      ,"DALJE"               ,"VAZHDO(ENT)"         ,         //124
"IPTAL EDILSIN MI?"   ,"CANCEL THE PROSES?"  ,"PRZERWAC PROCES?"    ,"OTKAZITE PROCES"     ,"TE ANULOHET"         ,        //125
"!CEKILECEK GAZ YOK!" ,"NO GAS IN SYSTEM"    ,"BRAK GAZY W UKLADZIE","NEMA GASA U SISTEMU" ,"NUK KA GAS NE SISTEM",                //126
"FILTRE AZ"           ,"FILTER IS LOW"       ,"W KROTCE WYM. FILTR" ,"FILTER JE SLAB"      ,"FILTERI I DOBET"     ,          //127
"SIPARIS EDIN"        ,"ORDER IT"            ,"ZAMOW"               ,"NARUCITE"            ,"POROSITNI"           ,   //128
"DOLUM YAPILIYOR"     ,"FILLING IN PROGSES"  ,"NAP. W TRAKCIE"      ,"PUNJENJE U TOKU .."  ,"MBUSHJA NE PROCES"   ,          //129
"< H.TEMIZLE +GAZ >"  ,"< HOSE FLUSH +GAS >" ,"< PLUK. WEZY +GAZ >" ,"CREVO ZA ISPIR+GAS"  ,"<PASTRO+GAS>"        ,    //130 ??? 20 karakter
"elcielektronik.com"  ,"brescon.eu"          ,"brescon.eu"          ,"profishop.rs"        ,"autoteuta.al"        ,   //131http://profishop.rs/
"CIKIS"               ,"QUIT"                ,"WYJDZ"               ,"ODUSTATI"            ,"DIL"                 ,                      //132
"YAZDIR"              ,"PRINT"               ,"DRUKUJ"              ,"STAMPA"              ,"SHTYP"               ,                       //133
"(ESC)"               ,"(ESC)"               ,"(ESC)"               ,"(ESC)"               ,"(ESC)"               ,                      //134
"SIRA NO :"           ,"SEQUENCE NO:"        ,"SEKWENCJA NR:"       ,"DEO BROJ"            ,"NUMRI RENDOR"        ,                          //135
"YAZDIRILIYOR"        ,"PRINTING"            ,"DRUKOWANIE"          ,"STAMPANJE"           ,"NE SHTYPJE"          ,                       //136
"BAGLANTI HATASI"     ,"CONNECTION ERROR"    ,"BLAD POLACZENIA"     ,"GRESKA U POVEZIVANJU","GABIM NE LIDHJE"     ,                         //137
"YAZILIMINIZ"         ,"YOUR SOFTWARE"       ,"TWOJE OPROGRAM."     ,"TVOJ PROGRAM"        ,"SOFTVERI"            ,                //138
"   GUNCEL  "         ," UP TO DATE "        ,"AKTUALNE"            ,"DO DATUMA"           ,"PERDITSUAR"          ,                    //139
"ARAC ISLEMLERI"      ,"CAR OPERATIONS"      ,"OBSLUGA POJAZDU"     ,"OPERACIJA VOZILA"    ,"VETURAT"             ,               //140
"BAKIMLAR"            ,"MAINTENANCE"         ,"KONSERWACJA"         ,"UPUTSTVO"            ,"MIREMBAJTJA"         ,                  //141
"KOMP. KAPATMA"       ,"COMP. OFF SET"       ,"KOMP. WYLACZONY"     ,"ISKLJ. KOMPRESORA"   ,"NDAL.KOMPRESOR"      ,                    //142 ??? 20 karakter
"YAZICI BASLIGI"      ,"PRINTER TITLE"       ,"NAGLOWEK"            ,"ZAGLAVLJE"           ,"TITULLI PRINTER"     ,                    //143
"SIFRE DEGISTIR"      ,"CHANGE PASSWORD"     ,"ZMIEN HASLO"         ,"PROMENITI LOZINKU"   ,"NDERRO KODIN"        ,                //144
"KAYIT YAPILDI"       , "  SAVED   "         ,"  ZAPISANO  "        ,"SACUVANO"            ,"U REGJISTURA"        ,               //145
"KALIBRASYONLAR"      , "CALIBRATIONS"       ,"KALIBRACJA"          ,"KALIBRACIJA"         ,"KALIBRIMET"          ,            //146
"SISTEM VAKUMLAMA"    ,"SYSTEM VACUUM"       ,"PROZNIA UKLADU"      ,"VAKUUM SISTEMA"      ,"VAKUMO SISTEMIN"     ,               //147
"GAZ TIPI"            ,"GAS TYPE"            ,"RODZAJ GAZU"         ,"VRSTA GASA"          ,"LLOJI I GASIT"       ,             //148
"SISTEM VAKUMLANIYOR" ,"      VACUMING      ","   PROZNIA   "       ,"VAKUUMIRANJE"        ,"VAKUMIZOHET SISTEMI" ,                  //149
"GUN/AY/YIL"          ,"DAY/MOUNTH/YEAR"     ,"DZIEN/MIES./ROK"     ,"DAN/MESEC/GODINA"    ,"DITA/MUAJI/VITI"     ,              //150
"SISTEM BOSALTMA"     ,"SYSTEM CLEAR"        ,"FORMATOWANIE SYSTEM" ,"CISCENJE SISTEMA"    ,"ZBRAZJA E SISTEMIT"  ,               //151
"VAK.YAGI DEGISTIR"   ,"VAC.OIL CHANGE"      ,"ZMIANA OL. P.PROZ"   ,"ZAMENA ULJA V.PUMPE" ,"NDER..VAJIT..VAK"    ,            //152 ??? 20 karakter
"KOMP.KAPATMA AYAR"   ,"COMP. CLOSE VAL"     ,"ZAW. SPREZ. ZAMKNIE" ,"VENT. ZA KOMPRESOR"  ,"VALVA KOMPRESOR"     ,          //153
"CIHAZ AYARLARI"      ,"DEVICE SETTIGNS"     ,"USTAWIENIA"          ,"PODESAVANJE UREAJA"  ,"CILESIMET E MAKINES" ,             //154
"SERVIS KONTROL"      ,"SERVICE CONTROL"     ,"SERWIS"              ,"SERVIS"              ,"KONTROLLA SERVIS"    ,         //155
"TANK KAP.AYAR"       ,"TANK CAP.SET."       ,"UST. POJ. ZBIORNIKA" ,"PODES.KAPAC.BOCE"    ,"KAPACIT.BOMBOLES"    ,         //156
"FILTRE KAP AY."      ,"FILTER CAP.SET."     ,"UST. POJ. FILTRA"    ,"PODES.KAPAC.FILTERA" ,"KAPACIT.FILTER"      ,     //157
"KULLANIM SIFIRLAMA"  ,"USING RESET"         ,"RESET"               ,"RESET"               ,"RESET"               ,                      //158
"OLCUM YAPILIYOR"     ,"MEASURING"           ,"TRWA POMIAR"         ,"MERENJE"             ,"NE MATJE"            ,                         //159
"MANIFALD VANALARI AC","OPEN MANIFOLD VALVES","OTW. ZAWORY MANOM."  ,"OTV.VENT.MANOMETRA"  ,"HAP.VALF.MANOMENTRA" ,                          //160 ??? 20 karakter
"MANIFALD VANASI KAPA","CLOSE MANIFOLD VALVE","ZAM. ZAWORY MANOM."  ,"ZATV.VENT.MANOMETRA" ,"MBYLL.VALF.MANOMETR" ,                         //161 ??? 20 karakter
"KALIBRAS. BEKLEYIN"  ,"CALIBRATION WAIT"    ,"KALIBRACJA..."       ,"KALIBRACIJA U TOKU"  ,"PRISNI KALIBRIMIN"   ,                      //162
"KALIBRASYON HATASI"  ,"CALIBRATION FAIL"    ,"BLAD KALIBRACJI"     ,"KALIBR. NIJE USPELA" ,"GABIM NE KALIBRIM"   ,                     //163 ??? 20 karakter
"KONTROL EDILIYOR"    , "CHECKING"           ,"SPRAWDZANIE"         ,"PROVERAVANJE"        ,"KONTROLLI NE PROCES" ,                      //164
"YAZILIM GUNCEL"      ,"NO UPDATE"           ,"BRAK AKTUALIZACJI"   ,"NO UPDATE"           ,"E PERDITSUAR"        ,              //165
"YAZILIM GUNCELLENDI" ,"SOFTWARE UPDATED"    ,"AKTUAL. OPROGRAM."   ,"PROGR.JE NADOGRADEN" ,"E PERDITSUAR"        ,              //166
"ARACTAN GAZ CEKIYOR" ,"WITHDRAWING FROM CAR","ODZYSK Z POJAZDU"    ,"IZVL.GASA IZ VOZILA" ,"NE TERHEQJE"         ,           //167 ??? 20 karakter
"TANK KAPASITESI"     ,"TANK CAPACITY"       ,"POJEMNOSC ZBIORNIKA" ,"KAPACITET BOCE GASA" ,"KAPACITET I BOMBOL"  ,                 //168    
"YAZICI AYARI"        ,"PRINTER SETTING"     ,"UST. DRUKOWANIA"     ,"PODESAVANJE STAMPACA","CILESIMET E PRINT"   ,               //169
"YAZICI VAR MI?"      ,"IS THERE A PRINTER?" ,"DRUK. PODLACZONA?"   ,"DA LI JE TU STAMPAC" ,"KA PRINTER?"         ,         //170
"DIGER AYARLAR"       ,"OTHER SETTINGS"      ,"INNE USTAWIENIA"     ,"OSTALA PODESAVANJA"  ,"CILESIMET TJERA"     ,           //171
"YAZILIM GUNCELLEME"  ,"SOFTWARE UPDATE"     ,"AKTUALIZACJA OPROGR.","NADOGRADNJA SOFTVERA","PERDITSO SOFTVER"    ,           //172
"TEKRAR YAZDIR"       ,"PRINT AGAIN"         ,"DRUKUJ JESZCZE RAZ"  ,"PONOVITI STAMPANJE"  ,"PRINTO PERSERI"      ,        //173
"WIFI SIFRESINI GIRIN","ENTER WIFI PASSWORD" ,"WPISZ HASŁO DO WIFI" ,"UNESITE LOZ. ZA WiFi","SHTYP.PASS.WIFI"     ,        //174 ??? 20 karakter
"WIFI BULUNDU"        ," WIFI FOUNDED"       ,"ZNALEZIONO WIFI"     ,"WiFi PRONADEN"       ,"WIFI U GJET"         ,   //175
"DIGERLERI"           ,"OTHERS"              ,"INNE"                ,"OSTALI"              ,"TE TJERET"           ,                        //176
"BAGLAN"              ,"CONNECT"             ,"PODLACZ"             ,"POVEZIVANJE"         ,"LIDHU"               ,                    //177
"SERVIS RAPORU"       ,"SERVICE REPORT"      ,"RAPORT SERWISOWY"    ,"SERVISNI IZVESTAJ"   ,"RAPORTI SERVIS"      ,                          //178
"  GEC"               ," SKIP"               ,"POMIN"               ,"IZADITE"             ,"KALO"                ,                          //179
"TANKTA GAZ VAR!"     ,"TANK HAVE A GAS!"    ,"GAZ W ZBIORNIKU!"    ,"REZERVOAR IMA GAS"   ,"KA GAS NE BOMB"      ,                          //180
"YAZICI TEST"         ,"PRINTER TEST"        ,"TEST DRUKARKI"       ,"TEST STAMPANJA"      ,"TESTO PRINTER"       ,                          //181
"CIHAZ ADI DEGISTIR"  ,"CHANGE DEVICE NAME"  ,"ZMIEN NAZWE URZADZ." ,"NOVI NAZIV MASINE"   ,"NDERRO.EMR.MAK"      ,          //182"PROMENI NAZIV MASINE"PROMENITE IME UREĐAJA
"GONDERICI E-MAILI"   ,"SENDER E-MAIL ADDRES","EMAIL NADAWCY      ","E-MAIL POSILJAOCA"   ,"DERGUESI.EMAIL"      ,                          //183    
"MAIL SIFRESI GIRIN"  ,"ENTER MAIL PASSWORD" ,"WPISZ HASLO DO POCZ.","UNESITE E-MAIL"      ,"PASS.EMAIL"          ,                          //184
"ALICI E-MAILI"       ,"RECIPIENT E-MAIL"    ,"EMAIL KLIENTA"       ,"E-MAIL PRIMAOCA"     ,"PRANUESI.EMIAL"      ,                         //185
"E-POSTA"             ,"E-MAIL"              ,"E-MAIL"              ,"E-MAIL"              ,"E-MAIL"              ,                         //186
"< E-POSTA   YAZDIR >","< E-MAIL     PRINT >","< E-MAIL    DRUKUJ >","E-MAIL STAMPANJE"    ,"E-MAIL.SHTYP"        ,                          //187
"GONDERILIYOR.."      ,"SENDING.."           ,"WYSYLANIE.."         ,"SLANJE"              ,"NE DERGIM"           ,                         //188
"E-POSTA UZANTISI"    ,"E-MAIL EXTENSION"    ,"OCZEKIWANIE"         ,"E-MAIL LOKAL"        ,"E-MAIL LOKAL"        ,                          //189
"E-POSTA GONDERILDI"  ,"E-MAIL SENT"         ,"WYSLANO"             ,"E-MAIL POSLANI"      ,"E-MAIL DUERGUAR"     ,                           //190
"GONDERIM BASARISIZ"  ,"SEND FAILED"         ,"BLAD WYSYLANIA"      ,"SLANJE NEUSPESNO"    ,"E-MAIL DESHTOJ"      ,                         //191
"(ENT)"               ,"(ENT)"               ,"(ENT)"               ,"(ENT)"               ,"(ENT)"               ,                          //192
"WI-FI"               ,"WI-FI"               ,"WI-FI"               ,"WiFi"                ,"WI-FI"               ,                         //193
"TANK KAP  :"         ,"TANK CAP  :"         ,"P.ZBIORNIK:"         ,"KAPAC.BOCE"          ,"KAP.I.BOMBOL"        ,                          //194    
"BOS ALAN  :"         ,"FREE SPACE:"         ,"P. OBSZAR :"         ,"SLOBODAN PROSTOR"    ,"ZBRAZETI"            ,                         //195

}; 

#endif

