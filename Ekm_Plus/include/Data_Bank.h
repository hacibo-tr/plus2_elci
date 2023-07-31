#ifndef _DATA_BANK_H
#define _DATA_BANK_H

#include <pgmspace.h>

#define GAZ_134     0
#define GAZ_1234YF  1

const char* const marka_134[] PROGMEM = {
"Alfa Romeo",//0
"Aston Martin",//1
"Audi",//2
"BMW",//3
"Cadillac",//4
"Chevrolet",//5
"Chrysler",//6
"Citroen",//7
"Dacia",//8
"Daewoo",//9
"Daihatsu",//10
"Dodge",//11
"Ds",//12
"Fiat",//13
"Ford",//14
//"Gunsel",//15
"Honda",//16
"Hyundai",//17
"Ikco",//18
"Infiniti",//19
"Isuzu",//20
"Iveco",//21
"Jaguar",//22
"Jeep",//23
"Kia",//24
"Lancia",//25
"Land Rover",//26
"LDV",//27
"Lexus",//28
"Mahindra",//29
"Mazda",//30
"Mcc/Smart",//31
"Mercedes",//32
"MG Motor",//33
"Mini Cooper",//34
"Mitsubishi",//35
"Nissan",//36
"Opel",//37
"Perodua",//38
"Peugeot",//39
"Porsche",//40
"Proton",//41
"Renault",//42
"Rover",//43
"Saab",//44
"Seat",//45
"Skoda",//46
"Smart",//47
"SsangYong",//48
"Subaru",//49
"Suzuki",//50
"Tata",//51
//"Tesla",//52
"Toyota",//53
"VW",//54
"Volvo",//55
"DAEWOO AVIA",  //0    -56
"DAF",            //1  -57
"ISUZU",        //2    -58
"IVECO",    //3        -59
"MAN",   //4           -60
"MERCEDES BENZ",  //5  -61
"MITSUBISHI",  // 6    -62
"NISSAN",   //7        -63
"RENAULT V.I.",  //8   -64
"SCANIA",//9           -65
"VOLVO",//10           -66
"*",//11      -67  
};

const char* const marka_1234yf[] PROGMEM = {
"Alfa Romeo",//0
//"Aston Martin",//1
"Audi",//2
"BMW",//3
"Cadillac",//4
"Chevrolet",//5
"Chrysler",//6
"Citroen",//7
"Dacia",//8
//"Daewoo",//9
//"Daihatsu",//10
//"Dodge",//11
"Ds",//12
"Fiat",//13
"Ford",//14
"Gunsel",//15
"Honda",//16
"Hyundai",//17
//"Ikco",//18
"Infiniti",//19
//"Isuzu",//20
//"Iveco",//21
"Jaguar",//22
"Jeep",//23
"Kia",//24
"Lancia",//25
"Land Rover",//26
"LDV",//27
"Lexus",//28
"Mahindra",//29
"Mazda",//30
"Mcc/Smart",//31
"Mercedes",//32
//"MG Motor",//33
"Mini Cooper",//34
"Mitsubishi",//35
"Nissan",//36
"Opel",//37
//"Perodua",//38
"Peugeot",//39
"Porsche",//40
//"Proton",//41
"Renault",//42
//"Rover",//43
//"Saab",//44
"Seat",//45
"Skoda",//46
"Smart",//47
"SsangYong",//48
"Subaru",//49
"Suzuki",//50
//"Tata",//51
"Tesla",//52
"Toyota",//53
"VW",//54
"Volvo",//55
//"DAEWOO AVIA",  //0    -56
//"DAF",            //1  -57
//"ISUZU",        //2    -58
//"IVECO",    //3        -59
//"MAN",   //4           -60
//"MERCEDES BENZ",  //5  -61
//"MITSUBISHI",  // 6    -62
//"NISSAN",   //7        -63
//"RENAULT V.I.",  //8   -64
//"SCANIA",//9           -65
//"VOLVO",//10           -66
"*",//11      -67  
};

const char* const model_134[] PROGMEM = {
"Alfa Romeo#4 C 240 hp#2013-2019#700#",//--1-131Alfa Romeo--3
"Alfa Romeo#145/146 Twin Spark#1996-2000#700#",//--Alfa Romeo--7
"Alfa Romeo#145/146 D-Turbo#1994-2000#700#",//--Alfa Romeo--11
"Alfa Romeo#145/146 1.9 JTD#1998-2000#700#",//--Alfa Romeo--15
"Alfa Romeo#147 1.6i/1.9JTD/2.0i/1.9JTD 16V/3.2i#2001-2012#550#",//--Alfa Romeo--19
"Alfa Romeo#155#1994-1997#700#",//--Alfa Romeo--23
"Alfa Romeo#155 1.6/1.8/2.0 16V#1995-1997#700#",//--Alfa Romeo--27
"Alfa Romeo#155 1.9 Dizel#1993-1997#700#",//--Alfa Romeo--31
"Alfa Romeo#156#1997-2002#650#",//--Alfa Romeo--35
"Alfa Romeo#156 1.9 JTD#1997-2002#650#",//--Alfa Romeo--39
"Alfa Romeo#156 2.4 JTD#1997-2002#650#",//--Alfa Romeo--43
"Alfa Romeo#156 Facelif#2002-2009#500#",//--Alfa Romeo--47
"Alfa Romeo#156 Facelif 2.4 JTD 20V#2003-2006#550#",//--Alfa Romeo--51
"Alfa Romeo#156 Facelif 2.4 JTD#2002-2003#500#",//--Alfa Romeo--55
"Alfa Romeo#159#2005-2015#460#",//--Alfa Romeo--59
"Alfa Romeo#164#1994-1998#1200#",//--Alfa Romeo--63
"Alfa Romeo#166#1998-2001#700#",//--Alfa Romeo--67
"Alfa Romeo#166#2001-2009#650#",//--Alfa Romeo--71
"Alfa Romeo#Brera#2006-2015#550#",//--Alfa Romeo--75
"Alfa Romeo#Giulia#2016-2022#535#",//--Alfa Romeo--79
"Alfa Romeo#Giulietta#2006-2022#450#",//--Alfa Romeo--83
"Alfa Romeo#GT#2004-2010#550#",//--Alfa Romeo--87
"Alfa Romeo#GT Coupe 1.9JTD#2003-2006#600#",//--Alfa Romeo--91
"Alfa Romeo#GTV 3.0 V6 24V#1997-1999#700#",//--Alfa Romeo--95
"Alfa Romeo#GTV 3.0 V6 24V#1999-2004#575#",//--Alfa Romeo--99
"Alfa Romeo#mito#2008-2015#450#",//--Alfa Romeo--103
"Alfa Romeo#Spider#2006-2015#460#",//--Alfa Romeo--107
"Alfa Romeo#Spider/GTV 1.8#1998-1999#675#",//--Alfa Romeo--111
"Alfa Romeo#Spider/GTV 1.8#1999-2001#575#",//--Alfa Romeo--115
"Alfa Romeo#Spider/GTV 2.0#1996-1999#700#",//--Alfa Romeo--119
"Alfa Romeo#Spider/GTV 2.0#1999-2003#575#",//--Alfa Romeo--123
"Alfa Romeo#Spider 3.0 V6/GTV 2.0 Turbo#1996-1999#700#",//--Alfa Romeo--127
"Alfa Romeo#Spider 3.0 V6/GTV 2.0 Turbo#1999-2001#575#",//--Alfa Romeo--131
"Aston Martin#DB7 Vantage 3.2#1994-2004#900#",//--133-135Aston Martin--135
"Audi#80#1992-1995#675#",//--137-651Audi--139
"Audi#80 2.3#1992-1994#775#",//--Audi--143
"Audi#100#1992-1997#775#",//--Audi--147
"Audi#A1 (8X)#2010-2015#500#",//--Audi--151
"Audi#A1#2016-2022#460#",//--Audi--155
"Audi#A2#2000-2001#525#",//--Audi--159
"Audi#A2#2001-2006#505#",//--Audi--163
"Audi#A3 (8L1) / 16mm Condenser#1996-2003#630#",//--Audi--167
"Audi#A3 (8L1) / 20mm Condenser#1996-2003#750#",//--Audi--171
"Audi#A3#2003-2013#525#",//--Audi--175
"Audi#A3 /Cabrio#2003-2016#525#",//--Audi--179
"Audi#A3 Sportback/2.0 40 TFS#2016-2022#500#",//--Audi--183
"Audi#A3 E-TRON Hybrid#2016-2018#500#",//--Audi--187
"Audi#A4#1994-1997#675#",//--Audi--191
"Audi#A4#1997-2001#725#",//--Audi--195
"Audi#A4 13/20 - 3/20#1998-1998#575#",//--Audi--199
"Audi#A4#2001-2007#500#",//--Audi--203
"Audi#A4 Cabrio#2001-2009#440#",//--Audi--207
"Audi#A4#2007-2012#570#",//--Audi--211
"Audi#A4 Quattro, A4 allroad#2007-2012#600#",//--Audi--215
"Audi#A4 Quattro, A4 allroad 4 Cylnder#2012-2016#550#",//--Audi--219
"Audi#A4 Quattro, A4 allroad 6 Cylnder#2007-2012#630#",//--Audi--223
"Audi#A4 2.0 /3.0  TDI#2016-2022#590#",//--Audi--227
"Audi#A5 Sportback#2009-2012#570#",//--Audi--231
"Audi#A5 Sportback / 4 Cylnder#2012-2016#550#",//--Audi--235
"Audi#A5 Sportback / 6 Cylnder#2012-2016#630#",//--Audi--239
"Audi#A5 Cabriolet / Coupe#2007-2012#570#",//--Audi--243
"Audi#A5 Cabriolet / Coupe#2012-2016#550#",//--Audi--247
"Audi#A5#2016-2022#590#",//--Audi--251
"Audi#A6#1994-1997#750#",//--Audi--255
"Audi#A6#1997-1998#825#",//--Audi--259
"Audi#A6 20mm Condanser#1998-1999#750#",//--Audi--263
"Audi#A6 /16mm Condanser#1998-1998#550#",//--Audi--267
"Audi#A6 V8#1998-1999#575#",//--Audi--271
"Audi#A6 1.8i/1.8T/2.4i/2.7T/2.8i#1999-2004#650#",//--Audi--275
"Audi#A6 2.0i/3.0i#1999-2004#575#",//--Audi--279
"Audi#A6 1.9TDI (AFN/AVF)#1999-2004#575#",//--Audi--283
"Audi#A6 1.9TDI (AVG/AWX)#1999-2004#675#",//--Audi--287
"Audi#A6 1.9TDI (AJM)#1999-1999#675#",//--Audi--291
"Audi#A6 1.9TDI (AJM)#1999-2004#575#",//--Audi--295
"Audi#A6 2.5TDI (AFB/AYM)#1999-2004#575#",//--Audi--299
"Audi#A6 2.5TDI (AKE)#1999-2004#675#",//--Audi--303
"Audi#A6 2.5TDI#1999-1999#675#",//--Audi--307
"Audi#A6 2.5TDI#1999-2004#575#",//--Audi--311
"Audi#A6 (4F) Quattro#2004-2011#530#",//--Audi--315
"Audi#A6 (4G/C7) Quattro#2011-2018#570#",//--Audi--319
"Audi#A6 Quattro#2019-2021#590#",//--Audi--323
"Audi#A6 Hybrid#2012-2015#860#",//--Audi--327
"Audi#A6 2.0 3.0 TDI MHEV R134A Hybrid#2018-2022#590#",//--Audi--331
"Audi#A6 2.0  TFSI  R134A Hybrid#2019-2022#640#",//--Audi--335
"Audi#A7#2010-2018#570#",//--Audi--339
"Audi#A8#1994-1997#750#",//--Audi--343
"Audi#A8#1997-2002#800#",//--Audi--347
"Audi#A8#2003-2010#620#",//--Audi--351
"Audi#A8 (4H)#2010-2018#780#",//--Audi--355
"Audi#A8 (4H) Rear A/C#2010-2018#930#",//--Audi--359
"Audi#A8 2.0 Hybrid#2012-2016#1080#",//--Audi--363
"Audi#A8 4,2 TDI CR CLEAN DIESEL#2016-2018#740#",//--Audi--367
"Audi#A8 4,2 TDI CR CLEAN DIESEL REAR A/C#2016-2018#915#",//--Audi--371
"Audi#A8 3.0 50 TDI#2017-2022#570#",//--Audi--375
"Audi#e-tron 230kw elec R134A#2019-2022#840#",//--Audi--379
"Audi#Allroad 4BH#2000-2006#800#",//--Audi--383
"Audi#Allroad A6 (4FH) 2.7TDi/3.0TDi#2006-2015#530#",//--Audi--387
"Audi#Allroad A6 (4FH) 3.2FSi/4.2FSi#2006-2015#530#",//--Audi--391
"Audi#Avant RS2#1994-1995#750#",//--Audi--395
"Audi#Cabrio#1992-2000#650#",//--Audi--399
"Audi#Cabrio 2.3#1992-1994#750#",//--Audi--403
"Audi#Coupe#1992-1996#650#",//--Audi--407
"Audi#Coupe 2.3#1992-1994#775#",//--Audi--411
"Audi#Coupe S2#1992-2000#775#",//--Audi--415
"Audi#Q2#2016-2022#500#",//--Audi--419
"Audi#Q3#2011-2018#520#",//--Audi--423
"Audi#Q5#2008-2012#570#",//--Audi--427
"Audi#Q5 / 4 Cylinder#2012-2018#550#",//--Audi--431
"Audi#Q5 / 6 Cylinder#2012-2018#630#",//--Audi--435
"Audi#Q5 FYB 17-#2017-2018#525#",//--Audi--439
"Audi#Q5 FYB 17-2,0 TFSI#2016-2018#590#",//--Audi--443
"Audi#Q5 Hiybrid#2011-2015#840#",//--Audi--447
"Audi#Q5 2.0 MHEV Hiybrid R134A#2017-2022#590#",//--Audi--451
"Audi#Q7#2005-2022#700#",//--Audi--455
"Audi#Q7 with Rear A/C#2005-2022#950#",//--Audi--459
"Audi#Q7 E-TRON PHEV  Hybrid#2016-2018#890#",//--Audi--463
"Audi#RS 3 (5 Cylinder motor)#2011-2015#500#",//--Audi--467
"Audi#RS 3#2016-2018#570#",//--Audi--471
"Audi#RS 4#2012-2018#570#",//--Audi--475
"Audi#RS 5#2010-2018#570#",//--Audi--479
"Audi#RS 6#2016-2018#540#",//--Audi--483
"Audi#RS 7#2016-2018#530#",//--Audi--487
"Audi#RS Q3#2015-2018#520#",//--Audi--491
"Audi#R8#2007-2016#680#",//--Audi--495
"Audi#R8#2017-2018#835#",//--Audi--499
"Audi#S1/S1 Sportback#2012-2018#475#",//--Audi--503
"Audi#S2#1992-1996#750#",//--Audi--507
"Audi#S3 16mm Condanser#1999-2003#630#",//--Audi--511
"Audi#S3 20mm Condanser#1999-2003#750#",//--Audi--515
"Audi#S3#2006-2015#525#",//--Audi--519
"Audi#S3#2016-2018#500#",//--Audi--523
"Audi#S4#2003-2008#440#",//--Audi--527
"Audi#S4#2009-2012#600#",//--Audi--531
"Audi#S4#2012-2016#630#",//--Audi--535
"Audi#S4#2017-2022#590#",//--Audi--539
"Audi#S5#2007-2012#570#",//--Audi--543
"Audi#S5#2012-2016#630#",//--Audi--547
"Audi#S5#2017-2022#590#",//--Audi--551
"Audi#S6#1994-1997#775#",//--Audi--555
"Audi#S6#1999-2000#650#",//--Audi--559
"Audi#S6#2000-2004#550#",//--Audi--563
"Audi#S6#2005-2010#530#",//--Audi--567
"Audi#S6#2012-2018#570#",//--Audi--571
"Audi#S6 3.0 TDI#2019-2022#590#",//--Audi--575
"Audi#S7#2014-2018#570#",//--Audi--579
"Audi#S8#1997-2003#800#",//--Audi--583
"Audi#S8#2005-2010#620#",//--Audi--587
"Audi#S8#2012-2018#780#",//--Audi--591
"Audi#S8 with Rear A/C#2012-2018#780#",//--Audi--595
"Audi#SQ5#2013-2018#550#",//--Audi--599
"Audi#SQ5 08-17 condens No.8K0XXX XXX#2013-2018#570#",//--Audi--603
"Audi#SQ5 08-17 condens No.8T0XXX XXX C#2013-2018#630#",//--Audi--607
"Audi#SQ5 FYB 3,0#2017-2022#590#",//--Audi--611
"Audi#SQ7#2016-2019#700#",//--Audi--615
"Audi#SQ7 with Rear A/C#2016-2019#950#",//--Audi--619
"Audi#SQ7 4.0D TDI#2019-2022#680#",//--Audi--623
"Audi#SQ7 4.0D TDI with Rear A/C#2019-2022#850#",//--Audi--627
"Audi#TT 8N Condanser 20 mm#1998-2006#750#",//--Audi--631
"Audi#TT 8N Condanser 16 mm#1998-2006#650#",//--Audi--635
"Audi#TT 8J#2006-2015#525#",//--Audi--639
"Audi#TT#2016-2022#500#",//--Audi--643
"Audi#TT TFSI RS#2016-2022#570#",//--Audi--647
"Audi#V8#1992-1993#875#",//--Audi--651
"BMW#1-Series (E87) 116i/118i/120i#2004-2007#500#",//--653-1123BMW--655
"BMW#1-Series (E87) 118d/120d#2004-2007#500#",//--BMW--659
"BMW#1-Series (E87) 120i/125i/130i/135i#2007-2011#500#",//--BMW--663
"BMW#1-Series (E87) 118d/120d/123d#2007-2011#590#",//--BMW--667
"BMW#1-Series (F20)#2011-2019#550#",//--BMW--671
"BMW#1-Series (F40)#2019-2022#520#",//--BMW--675
"BMW#2-Series ACTIVE TOURER#2014-2022#480#",//--BMW--679
"BMW#2-Series CABRIOLET#2015-2018#500#",//--BMW--683
"BMW#2-Series CABRIOLET M240i/xDrive#2015-2020#550#",//--BMW--687
"BMW#2-Series COUPE#2014-2020#550#",//--BMW--691
"BMW#2-Series GRAN TOURER#2015-2022#480#",//--BMW--695
"BMW#3-Series (E30)#1992-1993#800#",//--BMW--699
"BMW#3-Series (E36) Round Condanser#1993-2000#1000#",//--BMW--703
"BMW#3-Series (E36) Flat Condanser#1993-2000#825#",//--BMW--707
"BMW#3-Series (E46) benzin#1998-2005#740#",//--BMW--711
"BMW#3-Series (E46) dizel#2001-2005#680#",//--BMW--715
"BMW#3-Series (E90/E91/E92/E93)#2005-2012#600#",//--BMW--719
"BMW#3-Series 318d/320d/325d/ Gran Turismo#2013-2020#500#",//--BMW--723
"BMW#3-Series 320i/328i#2013-2016#550#",//--BMW--727
"BMW#3-Series 320i/330i/340i#2016-2020#540#",//--BMW--731
"BMW#3-Series#2013-2022#550#",//--BMW--735
"BMW#4-Series#2013-2022#550#",//--BMW--739
"BMW#5-Series (E34) Round Condanser#1993-1996#1550#",//--BMW--743
"BMW#5-Series (E34) Flat Condanser#1993-1996#1450#",//--BMW--747
"BMW#5-Series (E39)#1996-1998#1225#",//--BMW--751
"BMW#5-Series (E39)#1998-2003#750#",//--BMW--755
"BMW#525td/tds (E39)#1996-1998#1210#",//--BMW--759
"BMW#525td/tds (E39)#1998-2003#1300#",//--BMW--763
"BMW#530d (E39)#1998-2003#680#",//--BMW--767
"BMW#5-Series (E60/61) 520i/523i/525i#2003-2010#810#",//--BMW--771
"BMW#5-Series (E60/61) 530i/535i/540i#2003-2010#810#",//--BMW--775
"BMW#5-Series (E60/61) 545i/550i/M5#2003-2010#810#",//--BMW--779
"BMW#5-Series (E60/61) 520d/525d#2003-2010#700#",//--BMW--783
"BMW#5-Series (E60/61) 530d/535d#2003-2010#700#",//--BMW--787
"BMW#5-Series (F10/F11)#2010-2016#850#",//--BMW--791
"BMW#5-Series Gran Turismo (F07)#2009-2015#850#",//--BMW--795
"BMW#5-Series#2017-2018#550#",//--BMW--799
"BMW#5-Series 520i/530i/540i#2017-2022#600#",//--BMW--803
"BMW#5-Series 530e Hybrid#2017-2022#750#",//--BMW--807
"BMW#5-Series 550i/ 4,4 M5#2017-2022#650#",//--BMW--811
"BMW#6-Series (E63/E64) 630i/645Ci/650i#2004-2011#810#",//--BMW--815
"BMW#6-Series (F12/F13) 640i/650i#2011-2018#850#",//--BMW--819
"BMW#6-Series GRAN TURSIMO#2017-2018#600#",//--BMW--823
"BMW#6-Series GRAN TURSIMO 630i#2017-2022#600#",//--BMW--827
"BMW#6-Series GRAN TURSIMO#2018-2022#550#",//--BMW--831
"BMW#7-Series (E32)#1993-1994#1550#",//--BMW--835
"BMW#7-Series (E32) with Rear A/C#1993-1994#1700#",//--BMW--839
"BMW#7-Series (E38)#1994-1998#1210#",//--BMW--843
"BMW#7-Series (E38)#1998-2001#680#",//--BMW--847
"BMW#7-Series / d#2016-2022#550#",//--BMW--851
"BMW#7-Series / d with Rear A/C#2016-2022#800#",//--BMW--855
"BMW#7-Series 730i/740i#2016-2022#600#",//--BMW--859
"BMW#7-Series 730i/740i with Rear A/C#2016-2022#850#",//--BMW--863
"BMW#7-Series 750i/760i#2016-2022#650#",//--BMW--867
"BMW#7-Series 750i/760i with Rear A/C#2016-2022#880#",//--BMW--871
"BMW#750 L7 (E38)#1994-2001#1270#",//--BMW--875
"BMW#750 L7 (E38) with Rear A/C#1994-2001#1400#",//--BMW--879
"BMW#725 tds (E38)#1996-2001#1210#",//--BMW--883
"BMW#7-Series (E65/E66)#2002-2005#810#",//--BMW--887
"BMW#7-Series (E65/E66)#2005-2008#810#",//--BMW--891
"BMW#7-Series (F01/F02/F04)#2008-2015#850#",//--BMW--895
"BMW#7-Series (F01/F02/F04) with Rear A/C#2008-2015#1000#",//--BMW--899
"BMW#7-Series / d xDrive#2016-2022#550#",//--BMW--903
"BMW#7-Series with Rear A/C#2016-2022#800#",//--BMW--907
"BMW#7-Series 730i/740i with Rear A/C#2016-2022#850#",//--BMW--911
"BMW#7-Series 740e Hybrid#2016-2019#750#",//--BMW--915
"BMW#7-Series 745e Hybrid#2019-2022#750#",//--BMW--919
"BMW#8-Series (E31)#1993-1999#1550#",//--BMW--923
"BMW#8-Series / d xDrive#2018-2022#650#",//--BMW--927
"BMW#8-Series / 4.4M850i xDrive#2020-2022#650#",//--BMW--931
"BMW#8-Series / 840i xDrive#2018-2022#550#",//--BMW--935
"BMW#8-Series /d xDrive Hybrid#2020-2022#550#",//--BMW--939
"BMW#i3#2013-2022#750#",//--BMW--943
"BMW#i3 Heat pump#2013-2022#970#",//--BMW--947
"BMW#i8#2014-2022#630#",//--BMW--951
"BMW#X1 (E84)#2009-2015#600#",//--BMW--955
"BMW#X1#2016-2022#480#",//--BMW--959
"BMW#X1 sDrive 18i/20i#2020-2022#500#",//--BMW--963
"BMW#X1 xDrive 25e#2020-2022#600#",//--BMW--967
"BMW#X2#2016-2022#480#",//--BMW--971
"BMW#X2 20i#2018-2020#520#",//--BMW--975
"BMW#X2 20i#2020-2022#500#",//--BMW--979
"BMW#X2 18i#2020-2022#500#",//--BMW--983
"BMW#X2 M35i#2020-2022#520#",//--BMW--987
"BMW#X2 25e#2020-2022#650#",//--BMW--991
"BMW#X3 (E83) 2.0d/3.0d#2004-2010#680#",//--BMW--995
"BMW#X3 (E83) 2.0i/2.5i/3.0i#2004-2010#740#",//--BMW--999
"BMW#X3 (E83) 2.0d (N47)#2007-2010#700#",//--BMW--1003
"BMW#X3 (F25)#2010-2016#480#",//--BMW--1007
"BMW#X3#2017-2022#550#",//--BMW--1011
"BMW#X4 (F26)#2014-2018#480#",//--BMW--1015
"BMW#X4#2019-2022#550#",//--BMW--1019
"BMW#X5 (E53)#2000-2007#440#",//--BMW--1023
"BMW#X5 (E70) 3.5d/4.4i/3.0d#2007-2018#700#",//--BMW--1027
"BMW#X5 (E70) 3.0Sd/3.0Si/4.8i/M#2007-2018#700#",//--BMW--1031
"BMW#X5 M50d#2018-2020#650#",//--BMW--1035
"BMW#X5#2019-2022#600#",//--BMW--1039
"BMW#X5 40i#2019-2022#580#",//--BMW--1043
"BMW#X5 40i 5-zone climate#2019-2022#800#",//--BMW--1047
"BMW#X5 4.4 50i#2019-2022#650#",//--BMW--1051
"BMW#X5 4.4 50i 5-zone climate#2019-2022#900#",//--BMW--1055
"BMW#X5 3.0 xDrive 45e#2019-2020#850#",//--BMW--1059
"BMW#X6 (E71/E72) 3.0dx/3.5dx/3.5ix#2008-2018#700#",//--BMW--1063
"BMW#X6 (E71/E72) 5.0ix/4.0d#2008-2018#700#",//--BMW--1067
"BMW#X6 (F16/F86)#2016-2019#675#",//--BMW--1071
"BMW#X6 (G06)#2019-2022#650#",//--BMW--1075
"BMW#X6 (E71/E72) Hybrid N63#2009-2018#925#",//--BMW--1079
"BMW#X7 3.0 M50d M50i#2018-2020#650#",//--BMW--1083
"BMW#X7 3.0 M50d M50i 5-zone climate#2018-2020#900#",//--BMW--1087
"BMW#X7#2018-2022#600#",//--BMW--1091
"BMW#X7 5-zone climate#2018-2022#850#",//--BMW--1095
"BMW#X7 40i#2018-2022#580#",//--BMW--1099
"BMW#X7 40i 5-zone climate#2018-2022#800#",//--BMW--1103
"BMW#Z3 Round Condanser#1997-2003#1000#",//--BMW--1107
"BMW#Z3 Flat Condanser#1997-2003#825#",//--BMW--1111
"BMW#Z4 (E85)#2003-2005#740#",//--BMW--1115
"BMW#Z4 (E89)(G29) Sdrive 23i/30i/35i/35is#2009-2022#550#",//--BMW--1119
"BMW#Z8 (E52)#2000-2003#710#",//--BMW--1123
"Cadillac#ATS#2012-2019#550#",//--1125-1163Cadillac--1127
"Cadillac#BLS 2.0T/2.0T flex power/1.9D#2005-2010#680#",//--Cadillac--1131
"Cadillac#BLS 2.8iV6#2005-2010#650#",//--Cadillac--1135
"Cadillac#CTS 2.8iV6/3.6iV6 (LY7)#2005-2008#590#",//--Cadillac--1139
"Cadillac#CTS 2.8iV6/3.6iV6 (LLT)#2008-2015#550#",//--Cadillac--1143
"Cadillac#CTS#2016-2020#500#",//--Cadillac--1147
"Cadillac#Escalade 6.0 hybrid#2011-2014#725#",//--Cadillac--1151
"Cadillac#STS#2005-2010#625#",//--Cadillac--1155
"Cadillac#SRX 3.6iV6/4.6iV8#2004-2010#570#",//--Cadillac--1159
"Cadillac#SRX 3.6iV6/4.6iV8 with rear a/c#2004-2010#800#",//--Cadillac--1163
"Chevrolet#Aveo/Kalos(LHD)GM#2005-2011#520#",//--1165-1271Chevrolet--1167
"Chevrolet#Aveo/Kalos(RHD)GM#2005-2011#570#",//--Chevrolet--1171
"Chevrolet#Aveo benzin#2011-2015#500#",//--Chevrolet--1175
"Chevrolet#Aveo dizel#2011-2015#580#",//--Chevrolet--1179
"Chevrolet#Camaro#2012-2015#540#",//--Chevrolet--1183
"Chevrolet#Captiva (LHD) 2.4i/3.2iV6/3.0i#2007-2015#660#",//--Chevrolet--1187
"Chevrolet#Captiva (LHD) 2.0d/2.2d#2007-2015#520#",//--Chevrolet--1191
"Chevrolet#Cruze#2009-2015#650#",//--Chevrolet--1195
"Chevrolet#Epica (LHD)#2008-2015#820#",//--Chevrolet--1199
"Chevrolet#Epica (RHD)#2008-2015#880#",//--Chevrolet--1203
"Chevrolet#Evanda#2004-2006#730#",//--Chevrolet--1207
"Chevrolet#HHR 2.4i#2008-2015#410#",//--Chevrolet--1211
"Chevrolet#Lacetti/Nubira (LHD)#2005-2015#670#",//--Chevrolet--1215
"Chevrolet#Lacetti/Nubira (RHD)#2005-2015#670#",//--Chevrolet--1219
"Chevrolet#Matiz (LHD)#2005-2010#330#",//--Chevrolet--1223
"Chevrolet#Matiz (RHD)#2005-2010#380#",//--Chevrolet--1227
"Chevrolet#Malibu#2012-2018#680#",//--Chevrolet--1231
"Chevrolet#Orlando 1.8i/2.0d#2011-2015#650#",//--Chevrolet--1235
"Chevrolet#Rezzo (LHD)#2004-2009#700#",//--Chevrolet--1239
"Chevrolet#Rezzo (RHD)#2004-2009#770#",//--Chevrolet--1243
"Chevrolet#Spark (LHD)#2005-2010#330#",//--Chevrolet--1247
"Chevrolet#Spark (RHD)#2005-2010#380#",//--Chevrolet--1251
"Chevrolet#Spark#2010-2015#450#",//--Chevrolet--1255
"Chevrolet#Tacuma (LHD)#2004-2009#700#",//--Chevrolet--1259
"Chevrolet#Tacuma (RHD)#2004-2009#770#",//--Chevrolet--1263
"Chevrolet#Trax#2013-2016#570#",//--Chevrolet--1267
"Chevrolet#Volt#2011-2014#950#",//--Chevrolet--1271
"Chrysler#300 C#2004-2011#740#",//--1273-1383Chrysler--1275
"Chrysler#300 C#2012-2015#680#",//--Chrysler--1279
"Chrysler#300 M 2.7i/3.5i#1998-2004#710#",//--Chrysler--1283
"Chrysler#Crossfire/Crossfire Roadster#2003-2009#880#",//--Chrysler--1287
"Chrysler#Delta#2011-2014#500#",//--Chrysler--1291
"Chrysler#Neon#1995-1999#821#",//--Chrysler--1295
"Chrysler#Neon II#1999-2006#850#",//--Chrysler--1299
"Chrysler#PT Cruiser benzin#2000-2002#710#",//--Chrysler--1303
"Chrysler#PT Cruiser benzin#2002-2003#850#",//--Chrysler--1307
"Chrysler#PT Cruiser Dizel#2010-2015#595#",//--Chrysler--1311
"Chrysler#PT Cruiser Dizel#2004-2009#510#",//--Chrysler--1315
"Chrysler#Sebring#2001-2004#640#",//--Chrysler--1319
"Chrysler#Sebring 2.4Turbo#2001-2004#500#",//--Chrysler--1323
"Chrysler#Sebring#2007-2010#570#",//--Chrysler--1327
"Chrysler#Stratus 2.0i/2.5i#1994-2001#800#",//--Chrysler--1331
"Chrysler#Voyager#1994-2000#960#",//--Chrysler--1335
"Chrysler#Voyager with rear a/c#1994-2000#1360#",//--Chrysler--1339
"Chrysler#Voyager (RG) benzin#2001-2003#960#",//--Chrysler--1343
"Chrysler#Voyager (RG) benzin with rear a/c#2001-2003#1310#",//--Chrysler--1347
"Chrysler#Yoyager (RG) Dizel#2001-2003#910#",//--Chrysler--1351
"Chrysler#Yoyager (RG) benzin#2003-2006#880#",//--Chrysler--1355
"Chrysler#Voyager (RG) benzin with rear a/c#2003-2006#1220#",//--Chrysler--1359
"Chrysler#Yoyager (RG) Dizel#2003-2006#790#",//--Chrysler--1363
"Chrysler#Grand Voyager 2.8CRD/3.8i#2008-2011#790#",//--Chrysler--1367
"Chrysler#Grand Voyager 2.8CRD/3.8i with rear a/c#2008-2011#1110#",//--Chrysler--1371
"Chrysler#Grand Voyager 2.8CRD#2011-2014#820#",//--Chrysler--1375
"Chrysler#Grand Voyager 2.8CRD with rear a/c#2011-2014#1150#",//--Chrysler--1379
"Chrysler#Ypsilon#2011-2015#500#",//--Chrysler--1383
"Citroen#AX#1994-1997#625#",//--1385-1863Citroen--1387
"Citroen#Berlingo#1996-2002#875#",//--Citroen--1391
"Citroen#Berlingo#2003-2008#575#",//--Citroen--1395
"Citroen#Berlingo (B9)#2008-2018#450#",//--Citroen--1399
"Citroen#Berlingo III 0,4X2 67hp#2013-2018#525#",//--Citroen--1403
"Citroen#Berlingo IV 1930cm CONDANSER#2018-2022#470#",//--Citroen--1407
"Citroen#Berlingo IV 2350cm CONDANSER#2018-2022#600#",//--Citroen--1411
"Citroen#C1 1.0i#2005-2012#450#",//--Citroen--1415
"Citroen#C1 1.4HDi#2005-2010#500#",//--Citroen--1419
"Citroen#C1 II#2005-2022#400#",//--Citroen--1423
"Citroen#C2 10041 until#2003-2015#625#",//--Citroen--1427
"Citroen#C2 10042 upwards#2003-2015#500#",//--Citroen--1431
"Citroen#C3 I#2002-2004#625#",//--Citroen--1435
"Citroen#C3 II 1,6 HDI#2008-2010#450#",//--Citroen--1439
"Citroen#C3 II#2004-2010#500#",//--Citroen--1443
"Citroen#C3 10041 until#2002-2010#625#",//--Citroen--1447
"Citroen#C3 10042 upwards#2002-2010#500#",//--Citroen--1451
"Citroen#C3 III#2009-2016#425#",//--Citroen--1455
"Citroen#C3 IV#2016-2020#425#",//--Citroen--1459
"Citroen#C3 Aircross#2017-2022#425#",//--Citroen--1463
"Citroen#C3 Picasso#2009-2015#450#",//--Citroen--1467
"Citroen#C3 Pluriel#2003-2004#625#",//--Citroen--1471
"Citroen#C3 Pluriel#2004-2010#500#",//--Citroen--1475
"Citroen#C3 Pluriel 1,6 i#2003-2004#450#",//--Citroen--1479
"Citroen#C4#2004-2011#450#",//--Citroen--1483
"Citroen#C4 II#2012-2016#425#",//--Citroen--1487
"Citroen#C4 Aircross#2012-2017#500#",//--Citroen--1491
"Citroen#C4 Picasso (Grand)#2006-2018#450#",//--Citroen--1495
"Citroen#C4 Picasso (Grand) with rear a/c#2006-2018#675#",//--Citroen--1499
"Citroen#C4 Space Tourer / Grand Space#2018-2020#450#",//--Citroen--1503
"Citroen#C4 Space Tourer / Grand Space with rear a/c#2018-2020#675#",//--Citroen--1507
"Citroen#C5 1.8i/2.0i/3.0i#2001-2004#675#",//--Citroen--1511
"Citroen#C5 I 2.0D HDi#2000-2004#675#",//--Citroen--1515
"Citroen#C5 II#2004-2010#625#",//--Citroen--1519
"Citroen#C5 II 2.2 HDi (DW12B)/2.7HDi#2006-2008#525#",//--Citroen--1523
"Citroen#C5 III 1.6i/1.8i/2.0i/1.6HDi/3.0HDi#2008-2017#625#",//--Citroen--1527
"Citroen#C5 III 2.0HDi (RHF)#2008-2017#625#",//--Citroen--1531
"Citroen#C5 Aircross 1930cm Condanser#2018-2022#475#",//--Citroen--1535
"Citroen#C5 Aircross 2350cm Condanser#2018-2022#575#",//--Citroen--1539
"Citroen#C5 III 2.0HDi (RHE/RHH)#2010-2017#525#",//--Citroen--1543
"Citroen#C6 2.7HDi/2.2HDi/3.0HDi#2005-2013#525#",//--Citroen--1547
"Citroen#C6 3.0iV6#2005-2009#625#",//--Citroen--1551
"Citroen#C8 2.0HDi/2.2HDi#2002-2015#640#",//--Citroen--1555
"Citroen#C8 2.0i/3.0i/2.2i#2002-2015#675#",//--Citroen--1559
"Citroen#C15 1.4i#2002-2015#675#",//--Citroen--1563
"Citroen#C-Crosser#2007-2015#500#",//--Citroen--1567
"Citroen#C-Elysee#2012-2018#425#",//--Citroen--1571
"Citroen#C-Elysee#2018-2020#450#",//--Citroen--1575
"Citroen#C-Zero Electric 47kw(64hp)#2010-2015#325#",//--Citroen--1579
"Citroen#C-Zero Electric 49kw(67hp)#2013-2020#325#",//--Citroen--1583
"Citroen#Dispatch/Jumpy#1995-2005#975#",//--Citroen--1587
"Citroen#DS3/DS3 Cabrio#2011-2015#425#",//--Citroen--1591
"Citroen#DS4#2011-2015#425#",//--Citroen--1595
"Citroen#DS5#2012-2015#450#",//--Citroen--1599
"Citroen#Dispatch / Dispatch II#1994-2007#950#",//--Citroen--1603
"Citroen#Dispatch III Petrol (Benzin)#2007-2015#675#",//--Citroen--1607
"Citroen#Dispatch III Diesel (Dizel)#2007-2015#540#",//--Citroen--1611
"Citroen#Dispatch III Petrol with rear a/c#2007-2015#950#",//--Citroen--1615
"Citroen#Dispatch III Diesel with rear a/c#2007-2015#850#",//--Citroen--1619
"Citroen#Dispatch IV#2016-2022#500#",//--Citroen--1623
"Citroen#Dispatch IV 2.0 HDI#2016-2022#475#",//--Citroen--1627
"Citroen#Dispatch IV 2.0 HDI Van#2016-2022#500#",//--Citroen--1631
"Citroen#Dispatch IV 2.0 HDI dual zone very hot climates#2016-2022#875#",//--Citroen--1635
"Citroen#Dispatch IV 1.5/1.6 HDI with rear a/c#2016-2022#675#",//--Citroen--1639
"Citroen#Dispatch IV 1.5/1.6 HDI dual zone a/c#2016-2022#975#",//--Citroen--1643
"Citroen#Dispatch IV 2.0 HDI dual zone a/c#2016-2022#775#",//--Citroen--1647
"Citroen#e-Berlingo Hybrid#2017-2022#525#",//--Citroen--1651
"Citroen#Evasion#1994-2002#975#",//--Citroen--1655
"Citroen#Jumper/Relay II 2.0i/2.0DHDi#2002-2006#800#",//--Citroen--1659
"Citroen#Jumper/Relay II 2.2DHDi/2.8DHDi#2002-2006#800#",//--Citroen--1663
"Citroen#Jumper/Relay II with Rear A/C#2002-2006#1000#",//--Citroen--1667
"Citroen#Jumper/RelayIII 2.0DHDi/3.0DHDi#2006-2019#550#",//--Citroen--1671
"Citroen#Jumper/RelayIII with rear a/c#2006-2019#950#",//--Citroen--1675
"Citroen#Jumper/RelayIII Minibus#2006-2019#2600#",//--Citroen--1679
"Citroen#Jumper IV#2016-2020#500#",//--Citroen--1683
"Citroen#Jumper IV with rear a/c#2016-2020#675#",//--Citroen--1687
"Citroen#Jumper IV 2,0 Blue HDI#2018-2020#475#",//--Citroen--1691
"Citroen#Jumper IV 2,0 Blue HDI Van#2018-2020#500#",//--Citroen--1695
"Citroen#Jumper IV 2,0 Blue HDI with rear a/c#2018-2020#775#",//--Citroen--1699
"Citroen#Jumper IV 2,0 Blue HDIvery hot climates with rear#2018-2020#875#",//--Citroen--1703
"Citroen#Jumpy I / II#1994-2006#950#",//--Citroen--1707
"Citroen#Jumpy 1.6DHDi/2.0DHDi#2007-2015#540#",//--Citroen--1711
"Citroen#Jumpy HDi with rear a/c short wheelbase#2007-2015#850#",//--Citroen--1715
"Citroen#Jumpy HDi with rear a/c long wheelbase#2007-2015#950#",//--Citroen--1719
"Citroen#Jumpy 2.0i#2007-2015#675#",//--Citroen--1723
"Citroen#Jumpy 2.0i with rear a/c short wheelbase#2007-2015#950#",//--Citroen--1727
"Citroen#Jumpy 2.0i with rear a/c long wheelbase#2007-2015#1075#",//--Citroen--1731
"Citroen#Nemo#2008-2018#480#",//--Citroen--1735
"Citroen#Relay/Jumper#1994-1996#1000#",//--Citroen--1739
"Citroen#Relay/Jumper with rear a/c#1994-1996#1200#",//--Citroen--1743
"Citroen#Relay/Jumper#1996-2002#800#",//--Citroen--1747
"Citroen#Jumpy 2.0i with rear a/c#1996-2002#1000#",//--Citroen--1751
"Citroen#Saxo#1996-1996#600#",//--Citroen--1755
"Citroen#Saxo#1996-2000#775#",//--Citroen--1759
"Citroen#Space Tourer#2016-2022#500#",//--Citroen--1763
"Citroen#Space Tourer 2.0 HDI#2016-2022#475#",//--Citroen--1767
"Citroen#Space Tourer Van 2.0 HDI#2016-2022#500#",//--Citroen--1771
"Citroen#Space Tourer (VERY HOT CLIMATES)#2016-2022#675#",//--Citroen--1775
"Citroen#Space Tourer 2.0 HDI (VERY HOT CLIMATES)#2016-2022#875#",//--Citroen--1779
"Citroen#Space Tourer (DUAL ZONE)#2016-2022#975#",//--Citroen--1783
"Citroen#Space Tourer 2.0 HDI(DUAL ZONE)#2016-2022#775#",//--Citroen--1787
"Citroen#Synergie/Evasion#1994-2000#975#",//--Citroen--1791
"Citroen#Xantia SD 7H 15#1993-2000#775#",//--Citroen--1795
"Citroen#Xantia SD 7V 16#1993-2000#875#",//--Citroen--1799
"Citroen#Xantia SD 7V 16#1993-2000#975#",//--Citroen--1803
"Citroen#Xantia 3.0#1997-2000#725#",//--Citroen--1807
"Citroen#Xantia 1.9D/1.9D Turbo#1996-2000#825#",//--Citroen--1811
"Citroen#XM 2.0#1993-1996#725#",//--Citroen--1815
"Citroen#XM 2.0#1996-2000#725#",//--Citroen--1819
"Citroen#XM V6#1993-2000#725#",//--Citroen--1823
"Citroen#XM 2.1/2.2D#1993-1996#725#",//--Citroen--1827
"Citroen#XM 2.1/2.2D#1996-2000#725#",//--Citroen--1831
"Citroen#XM 2.5D#1994-1996#825#",//--Citroen--1835
"Citroen#XM 2.5D#1996-2000#825#",//--Citroen--1839
"Citroen#Xsara benzin#1997-2000#975#",//--Citroen--1843
"Citroen#Xsara dizel#1997-2000#875#",//--Citroen--1847
"Citroen#Xsara 1.6i/2.0i/2.0HDi (RHY)#2000-2006#565#",//--Citroen--1851
"Citroen#Xsara 2.0HDi (RHZ)#2000-2006#565#",//--Citroen--1855
"Citroen#Xsara Picasso#1999-2000#675#",//--Citroen--1859
"Citroen#ZX#1993-1998#925#",//--Citroen--1863
"Dacia#Dokker motor#2012-2019#475#",//--1865-1907Dacia--1867
"Dacia#Duster#2010-2022#475#",//--Dacia--1871
"Dacia#Lodgy#2012-2018#475#",//--Dacia--1875
"Dacia#Logan/MCV/Van/Pick up (133)#2005-2013#475#",//--Dacia--1879
"Dacia#Logan/MCV/Van/Pick up (134)#2005-2013#780#",//--Dacia--1883
"Dacia#Logan#2014-2020#480#",//--Dacia--1887
"Dacia#Logan 1.0 SCe75#2016-2020#480#",//--Dacia--1891
"Dacia#Sandero#2008-2015#475#",//--Dacia--1895
"Dacia#Sandero II#2013-2018#450#",//--Dacia--1899
"Dacia#Sandero#2015-2022#480#",//--Dacia--1903
"Dacia#Symbol II#2016-2018#480#",//--Dacia--1907
"Daewoo#Aranos / Cielo#1995-1997#730#",//--1909-2023Daewoo--1911
"Daewoo#Espero#1995-1997#730#",//--Daewoo--1915
"Daewoo#D-Line#2000-2011#850#",//--Daewoo--1919
"Daewoo#Evanda#2002-2007#730#",//--Daewoo--1923
"Daewoo#Kalos (LHD)#2002-2007#600#",//--Daewoo--1927
"Daewoo#Kalos (RHD)#2002-2007#650#",//--Daewoo--1931
"Daewoo#Korando#1999-2003#700#",//--Daewoo--1935
"Daewoo#Lacetti#2003-2005#640#",//--Daewoo--1939
"Daewoo#Lanos#1997-1998#720#",//--Daewoo--1943
"Daewoo#Lanos#1998-2001#720#",//--Daewoo--1947
"Daewoo#Lanos#2001-2003#720#",//--Daewoo--1951
"Daewoo#Leganza#1997-2004#850#",//--Daewoo--1955
"Daewoo#Matiz#1998-2005#525#",//--Daewoo--1959
"Daewoo#Matiz (LHD)#2005-2008#330#",//--Daewoo--1963
"Daewoo#Matiz (RHD)#2005-2008#380#",//--Daewoo--1967
"Daewoo#Musso#1999-2003#700#",//--Daewoo--1971
"Daewoo#Nexia#1995-1997#730#",//--Daewoo--1975
"Daewoo#Nubira#1997-1998#750#",//--Daewoo--1979
"Daewoo#Nubira#1998-2003#750#",//--Daewoo--1983
"Daewoo#Nubira (J200, J150, J190)#2003-2005#680#",//--Daewoo--1987
"Daewoo#Nubira (LHD)#2005-2007#640#",//--Daewoo--1991
"Daewoo#Nubira (RHD)#2005-2007#690#",//--Daewoo--1995
"Daewoo#Racer#1995-1997#730#",//--Daewoo--1999
"Daewoo#Rexton#2002-2004#850#",//--Daewoo--2003
"Daewoo#Rexton with rear a/c#2002-2004#1200#",//--Daewoo--2007
"Daewoo#Rezzo (LHD)#2000-2004#750#",//--Daewoo--2011
"Daewoo#Rezzo (RHD)#2000-2004#820#",//--Daewoo--2015
"Daewoo#Tacuma (LHD)#2001-2005#700#",//--Daewoo--2019
"Daewoo#Tacuma (RHD)#2002-2004#770#",//--Daewoo--2023
"Daihatsu#Applause (A101)#1993-1997#550#",//--2025-2131Daihatsu--2027
"Daihatsu#Applause (A101)#1997-2003#450#",//--Daihatsu--2031
"Daihatsu#Charade (G200)#1993-2003#650#",//--Daihatsu--2035
"Daihatsu#Charade#2004-2010#300#",//--Daihatsu--2039
"Daihatsu#Copen#2003-2015#365#",//--Daihatsu--2043
"Daihatsu#Cuore (L701)#1998-2003#380#",//--Daihatsu--2047
"Daihatsu#Cuore VII (L251)#2003-2007#380#",//--Daihatsu--2051
"Daihatsu#Cuore VIII#2007-2015#300#",//--Daihatsu--2055
"Daihatsu#Feroza (F300)#1993-2003#550#",//--Daihatsu--2059
"Daihatsu#Extol#2004-2007#400#",//--Daihatsu--2063
"Daihatsu#Grand Move (G303)#1996-1998#550#",//--Daihatsu--2067
"Daihatsu#Grand Move (G301)#1998-2003#400#",//--Daihatsu--2071
"Daihatsu#Handivan#1999-2003#380#",//--Daihatsu--2075
"Daihatsu#Hi-Jet 1,3i#1998-2006#850#",//--Daihatsu--2079
"Daihatsu#Materia (M4) 1.3i#2006-2015#350#",//--Daihatsu--2083
"Daihatsu#Move (L901)#1996-2003#380#",//--Daihatsu--2087
"Daihatsu#Rocky (F73/78)#1993-2003#550#",//--Daihatsu--2091
"Daihatsu#Sirion (M100)#1998-2000#400#",//--Daihatsu--2095
"Daihatsu#Sirion (M110, M111) EJ-Motor#2000-2005#380#",//--Daihatsu--2099
"Daihatsu#Sirion (M101, M111) K3-Motor#2000-2005#340#",//--Daihatsu--2103
"Daihatsu#Sirion (M3)#2005-2015#300#",//--Daihatsu--2107
"Daihatsu#Terios (J100)#1997-1998#600#",//--Daihatsu--2111
"Daihatsu#Terios (J100, J102)#1998-2005#400#",//--Daihatsu--2115
"Daihatsu#Terios (J2) (LHD) 1.3i/1.5i#2005-2015#350#",//--Daihatsu--2119
"Daihatsu#Terios (J2) (RHD) 1.3i/1.5i#2005-2015#300#",//--Daihatsu--2123
"Daihatsu#Trevis#2006-2015#300#",//--Daihatsu--2127
"Daihatsu#YRV (M201, M211)#2001-2007#380#",//--Daihatsu--2131
"Dodge#Avenger 2.0i/2.4i#2007-2011#450#",//--2133-2151Dodge--2135
"Dodge#Caliber#2006-2011#510#",//--Dodge--2139
"Dodge#Journey 2.4i/2.0CRD#2008-2011#625#",//--Dodge--2143
"Dodge#Journey with rear a/c#2008-2011#910#",//--Dodge--2147
"Dodge#Nitro#2007-2015#510#",//--Dodge--2151
"Ds#Ds- 3#2015-2018#425#",//--2153-2207Ds--2155
"Ds#Ds- 3 II#2015-2018#425#",//--Ds--2159
"Ds#Ds- 3 Crossback 12mm Condanser#2019-2022#450#",//--Ds--2163
"Ds#Ds- 3 Crossback 16mm Condanser#2019-2022#500#",//--Ds--2167
"Ds#Ds- 4#2015-2018#425#",//--Ds--2171
"Ds#Ds- 4 Crossback#2015-2018#425#",//--Ds--2175
"Ds#Ds- 4 II#2015-2018#425#",//--Ds--2179
"Ds#Ds- 5#2015-2019#450#",//--Ds--2183
"Ds#Ds- 5 Hybrid#2015-2018#450#",//--Ds--2187
"Ds#Ds- 7 12mm Condanser#2015-2022#475#",//--Ds--2191
"Ds#Ds- 7 16mm Condanser#2015-2022#575#",//--Ds--2195
"Ds#Ds- 7 19mm Condanser#2018-2022#475#",//--Ds--2199
"Ds#Ds- 7 23mm Condanser#2018-2022#575#",//--Ds--2203
"Ds#Ds- 7 28mm Condanser#2018-2022#625#",//--Ds--2207
"Fiat#124 Spider#2016-2019#420#",//--2209-2535Fiat--2211
"Fiat#500 / 500C Twin Air#2007-2022#450#",//--Fiat--2215
"Fiat#500L#2012-2022#450#",//--Fiat--2219
"Fiat#Albea#2000-2007#600#",//--Fiat--2223
"Fiat#Barchetta#1996-2006#600#",//--Fiat--2227
"Fiat#Bravo/Brava#1995-2000#625#",//--Fiat--2231
"Fiat#Bravo/Brava 1.9 JTD#1998-2000#650#",//--Fiat--2235
"Fiat#Bravo#2007-2015#500#",//--Fiat--2239
"Fiat#Cinquecento#1991-1997#700#",//--Fiat--2243
"Fiat#Cinquecento Sporting#1994-1998#550#",//--Fiat--2247
"Fiat#Coupe 1.8#1996-2000#740#",//--Fiat--2251
"Fiat#Coupe 16V#1994-1997#732#",//--Fiat--2255
"Fiat#Coupe 20V/20V Turbo#1996-2001#500#",//--Fiat--2259
"Fiat#Croma#1994-1997#1100#",//--Fiat--2263
"Fiat#Croma 2.2i#2005-2011#730#",//--Fiat--2267
"Fiat#Croma 1.9JTD/1.9JTD16V#2005-2011#730#",//--Fiat--2271
"Fiat#Doblo 1.2i/1.6i/1.4i#2001-2010#600#",//--Fiat--2275
"Fiat#Doblo 1.9JTD/1.3JTD#2002-2010#600#",//--Fiat--2279
"Fiat#Doblo (152)#2010-2022#450#",//--Fiat--2283
"Fiat#Ducato/Talento#1994-2002#850#",//--Fiat--2287
"Fiat#Ducato/Talento with rear a/c#1994-2002#1000#",//--Fiat--2291
"Fiat#Ducato (244)#2002-2006#900#",//--Fiat--2295
"Fiat#Ducato (244) with rear a/c#2002-2006#1000#",//--Fiat--2299
"Fiat#Ducato (244) Panorama#2002-2006#800#",//--Fiat--2303
"Fiat#Ducato 2.2D/2.3D/3.0D#2006-2020#550#",//--Fiat--2307
"Fiat#Ducato 2.2D/2.3D/3.0D with rear a/c#2006-2020#950#",//--Fiat--2311
"Fiat#Ducato 2,3D Ecojet#2017-2018#550#",//--Fiat--2315
"Fiat#Egea#2015-2022#450#",//--Fiat--2319
"Fiat#Freemont#2011-2018#625#",//--Fiat--2323
"Fiat#Freemont with rear a/c#2011-2018#910#",//--Fiat--2327
"Fiat#Fiorino#2008-2020#480#",//--Fiat--2331
"Fiat#Fiorino CNG#2009-2022#500#",//--Fiat--2335
"Fiat#Fullback#2016-2020#520#",//--Fiat--2339
"Fiat#Grande Punto(199)1.2i/1.4i/1.3D/1.9D#2005-2016#500#",//--Fiat--2343
"Fiat#Grande Punto(199)#2006-2016#480#",//--Fiat--2347
"Fiat#Idea 1.3JTD/1.4i/1.9JTD/1.2i/1.6D#2004-2012#500#",//--Fiat--2351
"Fiat#Linea 1.4i/1.4i16V/1.3D Multijet#2007-2015#500#",//--Fiat--2355
"Fiat#Linea 1.6D Multijet#2007-2015#460#",//--Fiat--2359
"Fiat#Marea/Marengo#1996-2000#600#",//--Fiat--2363
"Fiat#Multipla 1.6#1999-2005#650#",//--Fiat--2367
"Fiat#Multipla 1.6i#2005-2011#650#",//--Fiat--2371
"Fiat#Multipla 1.9 JTD#1999-2005#650#",//--Fiat--2375
"Fiat#Palio/Weekend 1.2i/1.9D#1997-2002#750#",//--Fiat--2379
"Fiat#Palio/Weekend 1.2i#2002-2006#625#",//--Fiat--2383
"Fiat#Palio/Weekend 1.6i16V#1997-2002#750#",//--Fiat--2387
"Fiat#Palio/Weekend 1.6i16V#2002-2006#625#",//--Fiat--2391
"Fiat#Palio/Weekend 1.2i16V/1.9JTD/1.9D#2001-2006#625#",//--Fiat--2395
"Fiat#Palio/Weekend 1.7TD#1998-2000#750#",//--Fiat--2399
"Fiat#Panda (169) 1.1i/1.2i#2003-2011#500#",//--Fiat--2403
"Fiat#Panda (169) 1.3JTD#2003-2011#500#",//--Fiat--2407
"Fiat#Panda#2012-2022#450#",//--Fiat--2411
"Fiat#Punto#1993-1999#675#",//--Fiat--2415
"Fiat#Punto (188) 1.2i/1.2i16V/1.9D#1999-2003#550#",//--Fiat--2419
"Fiat#Punto (188) 1.9DJTD#1999-2003#550#",//--Fiat--2423
"Fiat#Punto (188) 1.8i#1999-2003#550#",//--Fiat--2427
"Fiat#Punto (188) 1.2i/1.2i16V/1.9D#2003-2015#550#",//--Fiat--2431
"Fiat#Punto 1.3JTD#2003-2015#500#",//--Fiat--2435
"Fiat#Punto#2012-2018#440#",//--Fiat--2439
"Fiat#Qubo 1,3D 75hp#2008-2011#500#",//--Fiat--2443
"Fiat#Qubo 1,4#2008-2020#500#",//--Fiat--2447
"Fiat#Qubo#2010-2020#480#",//--Fiat--2451
"Fiat#Scudo#1996-2007#975#",//--Fiat--2455
"Fiat#Scudo 1.6D/2.0D#2007-2015#540#",//--Fiat--2459
"Fiat#Scudo with rear a/c short wheelbase#2007-2015#850#",//--Fiat--2463
"Fiat#Scudo with rear a/c long wheelbase#2007-2015#950#",//--Fiat--2467
"Fiat#Sedici#2006-2015#430#",//--Fiat--2471
"Fiat#Seicento#1997-2009#500#",//--Fiat--2475
"Fiat#Siena#1997-2003#750#",//--Fiat--2479
"Fiat#Stilo (192) 1.2i/1.4i#2001-2008#500#",//--Fiat--2483
"Fiat#Stilo 1.8i#2001-2008#500#",//--Fiat--2487
"Fiat#Stilo 1.6i/1.9JTD#2001-2008#500#",//--Fiat--2491
"Fiat#Strada Pick up#2002-2011#625#",//--Fiat--2495
"Fiat#Strada Pick up 1.3D#2012-2018#500#",//--Fiat--2499
"Fiat#Talento#1994-2002#850#",//--Fiat--2503
"Fiat#Talento with rear a/c#1994-2002#1000#",//--Fiat--2507
"Fiat#Talento#2016-2019#590#",//--Fiat--2511
"Fiat#Talento with rear a/c#2016-2019#880#",//--Fiat--2515
"Fiat#Tempra#1994-1997#730#",//--Fiat--2519
"Fiat#Tipo#1994-1995#730#",//--Fiat--2523
"Fiat#Tipo New#2015-2022#450#",//--Fiat--2527
"Fiat#Ulysse#1994-2002#975#",//--Fiat--2531
"Fiat#Ulysse (179AX)#2002-2015#600#",//--Fiat--2535
"Ford#B-Max 1.0 EcoBoost/1.6TDCi#2012-2018#600#",//--2537-2931Ford--2539
"Ford#B-Max 1.5TDCi#2012-2018#550#",//--Ford--2543
"Ford#B-Max 1.4i/1.6Ti (Sigma)#2012-2018#650#",//--Ford--2547
"Ford#C-Max 1,0L EcoBoost /1,5L TDCI#2007-2017#530#",//--Ford--2551
"Ford#C-Max 1,5L EcoBoost/ 2,0L TDCI#2007-2017#625#",//--Ford--2555
"Ford#C-Max II/Grand C-Max 1.6TiVCT#2010-2017#600#",//--Ford--2559
"Ford#Cougar#1998-2003#740#",//--Ford--2563
"Ford#Escort#1994-2000#740#",//--Ford--2567
"Ford#Ecosport / Escape#2012-2016#625#",//--Ford--2571
"Ford#Ecosport 1.0 EcoBoost Otm.#2013-2022#700#",//--Ford--2575
"Ford#Ecosport 1.0 EcoBoost#2018-2022#550#",//--Ford--2579
"Ford#Explorer (U2) 4.0iV6#1993-1998#600#",//--Ford--2583
"Ford#Explorer (U2) 4.0iV6#1998-2002#650#",//--Ford--2587
"Ford#Explorer   4.0 OHC 207hp#1998-2002#850#",//--Ford--2591
"Ford#Fiesta#1994-1996#740#",//--Ford--2595
"Ford#Fiesta#1995-1999#740#",//--Ford--2599
"Ford#Fiesta#1999-2002#740#",//--Ford--2603
"Ford#Fiesta (JH) kond 3mm (f)#2002-2008#650#",//--Ford--2607
"Ford#Fiesta (JH) kond 12mm (f)#2004-2008#470#",//--Ford--2611
"Ford#Fiesta (JH) 1.6D TDCi kond 3mm (f)#2004-2008#520#",//--Ford--2615
"Ford#Fiesta  1.6D TDCi kond 12mm (f)#2004-2016#450#",//--Ford--2619
"Ford#Fiesta VI1.25i/1.4i/1.6Ti kond 12mm#2008-2016#390#",//--Ford--2623
"Ford#Fiesta VI 1.4/1,5 TDCI 12mm kond.#2008-2016#390#",//--Ford--2627
"Ford#Fiesta VI1.25i/1.4i/1.6Ti kond 16mm#2008-2016#520#",//--Ford--2631
"Ford#Fiesta VI 1.4/1.5 TDCi kond. 16mm#2008-2016#520#",//--Ford--2635
"Ford#Fiesta VI 1.6 TDCi kond. 16mm#2008-2016#570#",//--Ford--2639
"Ford#Fiesta 1.0L EcoBoost kond. 16mm#2008-2016#620#",//--Ford--2643
"Ford#Fiesta 1.6L EcoBoost kond. 16mm#2008-2016#675#",//--Ford--2647
"Ford#Focus#1998-2004#740#",//--Ford--2651
"Ford#Focus RS#2002-2016#740#",//--Ford--2655
"Ford#Focus II kond 3mm (f)#2004-2011#740#",//--Ford--2659
"Ford#Focus II kond 1.2mm (f)#2004-2011#600#",//--Ford--2663
"Ford#Focus III#2011-2016#530#",//--Ford--2667
"Ford#Focus III 1.0L EcoBoost(74kw/90kw)#2011-2016#540#",//--Ford--2671
"Ford#Focus III 1.0L EcoBoost(184kw)#2011-2016#600#",//--Ford--2675
"Ford#Focus C-Max kond 3mm (f)#2003-2007#740#",//--Ford--2679
"Ford#Focus C-Max kond 1.2mm (f)#2003-2007#600#",//--Ford--2683
"Ford#Fusion (JU) kond 3mm (f)#2002-2010#650#",//--Ford--2687
"Ford#Fusion (JU) kond 1.2mm (f)#2002-2010#470#",//--Ford--2691
"Ford#Galaxy 2.0/2.3/2.8/1.9 TDI#1995-2000#975#",//--Ford--2695
"Ford#Galaxy with rear a/c#1995-2000#1375#",//--Ford--2699
"Ford#Galaxy#2000-2006#725#",//--Ford--2703
"Ford#Galaxy with rear a/c#2000-2006#1075#",//--Ford--2707
"Ford#Galaxy#2006-2015#600#",//--Ford--2711
"Ford#Galaxy with rear a/c#2006-2015#850#",//--Ford--2715
"Ford#Galaxy#2015-2018#525#",//--Ford--2719
"Ford#Galaxy  with rearA/C#2015-2018#740#",//--Ford--2723
"Ford#Ka/StreetKa#1996-2005#650#",//--Ford--2727
"Ford#Ka (RB) 1.3i#2005-2009#650#",//--Ford--2731
"Ford#Ka#2009-2015#500#",//--Ford--2735
"Ford#Kuga 2,0 EcoBoost#2008-2013#600#",//--Ford--2739
"Ford#Kuga 1.5/1.6 /2.0 EcoBoost#2013-2022#530#",//--Ford--2743
"Ford#Kuga 2,0Duratorq-TDCI VI 2.5 Duratec#2008-2017#680#",//--Ford--2747
"Ford#Kuga           2.0 Dizel#2017-2020#630#",//--Ford--2751
"Ford#Kuga 1.5 Duratorq-TDCI#2008-2017#570#",//--Ford--2755
"Ford#Maverick#1993-1998#750#",//--Ford--2759
"Ford#Maverick#2001-2006#850#",//--Ford--2763
"Ford#Mondeo I#1993-1996#740#",//--Ford--2767
"Ford#Mondeo II#1996-2000#740#",//--Ford--2771
"Ford#Mondeo III#2000-2001#820#",//--Ford--2775
"Ford#Mondeo kond 3mm (f)(g)#2001-2007#820#",//--Ford--2779
"Ford#Mondeo kond 1.2mm (f)(g)#2001-2007#700#",//--Ford--2783
"Ford#Mondeo Non 6 gear#2007-2018#520#",//--Ford--2787
"Ford#Mondeo 6-speed automatic#2007-2018#590#",//--Ford--2791
"Ford#Mondeo  1,0 Eco-Boost 2,0 Duratorq#2014-2022#570#",//--Ford--2795
"Ford#Mondeo  2.0 Hybrid#2015-2022#570#",//--Ford--2799
"Ford#Mustang#2015-2022#600#",//--Ford--2803
"Ford#Probe#1994-1998#1050#",//--Ford--2807
"Ford#Puma#1997-2003#740#",//--Ford--2811
"Ford#Ranger#1999-2003#550#",//--Ford--2815
"Ford#Ranger  2.5TDCi/ 3.0TDCi#2006-2011#475#",//--Ford--2819
"Ford#Ranger#2012-2013#650#",//--Ford--2823
"Ford#Ranger III / F-250SD/TERRITORY#2013-2022#565#",//--Ford--2827
"Ford#S-Max#2006-2018#570#",//--Ford--2831
"Ford#S-Max with rear A/C#2006-2018#965#",//--Ford--2835
"Ford#S-Max (2,0L TDCI) with rear A/C#2006-2018#910#",//--Ford--2839
"Ford#Streetka#2003-2006#650#",//--Ford--2843
"Ford#Scorpio#1995-1998#1000#",//--Ford--2847
"Ford#Tourneo Connect 1.8i/1.8D TDCi#2002-2007#740#",//--Ford--2851
"Ford#Transit/Tourneo COURIER1,0L/1,5L TDCI#2006-2018#620#",//--Ford--2855
"Ford#Transit/Tourneo COURIER 1,6L TDCI#2006-2018#670#",//--Ford--2859
"Ford#Transit/Tourneo COURIER#2018-2020#520#",//--Ford--2863
"Ford#Transit/Tourneo COURIER   TDCI#2018-2020#500#",//--Ford--2867
"Ford#Transit/Tourneo Connect Van#2006-2018#525#",//--Ford--2871
"Ford#Transit/Tourneo Connect1,0L/1,6L TDCI#2013-2018#575#",//--Ford--2875
"Ford#Transit/Tourneo Connect1,6L/2,5L TDCI#2013-2018#675#",//--Ford--2879
"Ford#Transit/Tourneo Connect with rear A/C#2013-2018#800#",//--Ford--2883
"Ford#Transit/Tourneo1,6L Eco/2,5L with A/C#2006-2018#875#",//--Ford--2887
"Ford#Transit#1994-1999#900#",//--Ford--2891
"Ford#Transit with rear A/C#1994-1997#1400#",//--Ford--2895
"Ford#Transit with rear A/C#1998-1999#1200#",//--Ford--2899
"Ford#Transit 2.0Di/2.4Di#2000-2005#740#",//--Ford--2903
"Ford#Transit with rear A/C#2000-2005#1560#",//--Ford--2907
"Ford#Transit 2.3i/2.0TDCi#2001-2005#990#",//--Ford--2911
"Ford#Transit/Tourneo#2006-2015#750#",//--Ford--2915
"Ford#Transit/Tourneo with rear A/C#2006-2015#1400#",//--Ford--2919
"Ford#Transit Custom#2012-2022#740#",//--Ford--2923
"Ford#Transit Custom Bus with rear A/C#2012-2022#1050#",//--Ford--2927
"Ford#Transit Custom Van with rear A/C#2012-2022#1150#",//--Ford--2931
"Honda#Accord#1993-1998#725#",//--2933-3151Honda--2935
"Honda#Accord dizel RHD#1996-1998#700#",//--Honda--2939
"Honda#Accord dizel LHD#1996-1998#650#",//--Honda--2943
"Honda#Accord#1998-2003#525#",//--Honda--2947
"Honda#Accord Coupe#1998-2003#625#",//--Honda--2951
"Honda#Accord 2.0i/2.4i#2003-2008#550#",//--Honda--2955
"Honda#Accord 2.2D i-CTDi#2003-2008#475#",//--Honda--2959
"Honda#Accord 2.0i/2.4i/2.2D-i-DTEC#2008-2020#475#",//--Honda--2963
"Honda#Clarity Fuel Cell  Hybrid#2017-2018#445#",//--Honda--2967
"Honda#Civic#1994-1995#525#",//--Honda--2971
"Honda#Civic 2/3/4 kapı#1996-2000#625#",//--Honda--2975
"Honda#Civic 5-door#1995-1997#525#",//--Honda--2979
"Honda#Civic 5- door#1997-2000#525#",//--Honda--2983
"Honda#Civic 5- door dizel RHD#1997-2000#560#",//--Honda--2987
"Honda#Civic 5- door dizel LHD#1997-2000#640#",//--Honda--2991
"Honda#Civic/Civic Coupe 1.4i/1.6i/2.0i#2001-2006#525#",//--Honda--2995
"Honda#Civic 1.7D CTDi#2002-2006#525#",//--Honda--2999
"Honda#Civic VIII#2006-2015#465#",//--Honda--3003
"Honda#Civic IX#2012-2022#430#",//--Honda--3007
"Honda#Civic RHD IX#2012-2022#460#",//--Honda--3011
"Honda#Civic Hybrid IMA LHD#2006-2011#425#",//--Honda--3015
"Honda#Civic Hybrid IMA#2006-2011#475#",//--Honda--3019
"Honda#Concerto#1993-1995#775#",//--Honda--3023
"Honda#CRX#1994-1997#525#",//--Honda--3027
"Honda#CRV RHD#1997-2002#625#",//--Honda--3031
"Honda#CRV (RD)#2002-2007#505#",//--Honda--3035
"Honda#CRV 2.2D i-CTDi (RD)#2004-2007#475#",//--Honda--3039
"Honda#CRV 2.0i/2.2D-CTDi/2.4i#2007-2018#440#",//--Honda--3043
"Honda#CRV  LHD 2.0i/2.2D-CTDi/2.4i#2007-2018#410#",//--Honda--3047
"Honda#CRV 1.5 VTEC#2018-2022#460#",//--Honda--3051
"Honda#CRV 1.5 VTEC with rear A/C#2018-2022#680#",//--Honda--3055
"Honda#CR-Z 1.5 Hybrid IMA#2010-2015#475#",//--Honda--3059
"Honda#FR-V#2005-2009#550#",//--Honda--3063
"Honda#HR-V 1.6i#1999-2006#600#",//--Honda--3067
"Honda#Insight 1.3i (IMA/ Hybrid)LHD#2006-2015#425#",//--Honda--3071
"Honda#Insight 1.3i (IMA/ Hybrid)RHD#2006-2015#475#",//--Honda--3075
"Honda#Jazz (GD)#2001-2008#425#",//--Honda--3079
"Honda#Jazz#2008-2015#395#",//--Honda--3083
"Honda#Legend#1993-1996#775#",//--Honda--3087
"Honda#Legend#1996-2000#725#",//--Honda--3091
"Honda#Legend IV (KB) 3.5i/3.7i#2006-2015#475#",//--Honda--3095
"Honda#Logo#1999-2002#525#",//--Honda--3099
"Honda#NSX#1997-2005#825#",//--Honda--3103
"Honda#Odyssey#1995-1997#625#",//--Honda--3107
"Honda#Odyssey with rear a/c#1995-1997#825#",//--Honda--3111
"Honda#Odyssey#2000-2004#975#",//--Honda--3115
"Honda#Prelude RHD#1994-1996#675#",//--Honda--3119
"Honda#Prelude LHD#1994-1996#625#",//--Honda--3123
"Honda#Prelude#1997-2001#725#",//--Honda--3127
"Honda#S2000#1999-2004#625#",//--Honda--3131
"Honda#Shuttle 2.2i/2.3i#1995-2001#625#",//--Honda--3135
"Honda#Shuttle with rear a/c#1995-2001#825#",//--Honda--3139
"Honda#Stream 1.7i#2001-2006#525#",//--Honda--3143
"Honda#Stream 2.0i#2001-2006#525#",//--Honda--3147
"Honda#Stream with rear a/c#2001-2006#725#",//--Honda--3151
"Hyundai#Accent#1994-1995#675#",//--3153-3547Hyundai--3155
"Hyundai#Accent#1996-1999#670#",//--Hyundai--3159
"Hyundai#Accent#1999-2002#600#",//--Hyundai--3163
"Hyundai#Accent (LC)#2002-2005#550#",//--Hyundai--3167
"Hyundai#Accent (MC)#2005-2010#500#",//--Hyundai--3171
"Hyundai#Accent#2010-2016#420#",//--Hyundai--3175
"Hyundai#Accent#2017-2018#445#",//--Hyundai--3179
"Hyundai#Amica#2000-2003#650#",//--Hyundai--3183
"Hyundai#Atoz/Atos#1998-2004#650#",//--Hyundai--3187
"Hyundai#Atoz/Atos#2005-2009#550#",//--Hyundai--3191
"Hyundai#Azera 3.3i/2.2D CRDi#2007-2015#500#",//--Hyundai--3195
"Hyundai#Azera#2016-2018#575#",//--Hyundai--3199
"Hyundai#Bayon#2020-2022#470#",//--Hyundai--3203
"Hyundai#Coupe#1996-2001#700#",//--Hyundai--3207
"Hyundai#Coupe (GK)#2002-2009#600#",//--Hyundai--3211
"Hyundai#Creta#2016-2020#450#",//--Hyundai--3215
"Hyundai#Elantra (XD)#2000-2006#680#",//--Hyundai--3219
"Hyundai#Elantra 1.6 CVVT#2011-2022#500#",//--Hyundai--3223
"Hyundai#Excel#1994-1999#670#",//--Hyundai--3227
"Hyundai#Excel#2000-2002#600#",//--Hyundai--3231
"Hyundai#Excel#2003-2005#550#",//--Hyundai--3235
"Hyundai#Galloper#1998-2002#780#",//--Hyundai--3239
"Hyundai#Galloper with rear a/c#1998-2002#1175#",//--Hyundai--3243
"Hyundai#Genesis Coupe 2.0i Turbo/3.8i#2010-2014#570#",//--Hyundai--3247
"Hyundai#Getz#2002-2008#500#",//--Hyundai--3251
"Hyundai#Grandeur 3.3i/3.8i/2.2D CRDi#2005-2015#500#",//--Hyundai--3255
"Hyundai#Grace#1993-2007#650#",//--Hyundai--3259
"Hyundai#Grace with rear a/c#1993-2007#1400#",//--Hyundai--3263
"Hyundai#H100#1993-2000#650#",//--Hyundai--3267
"Hyundai#H100 with rear a/c A/C#1993-2000#1400#",//--Hyundai--3271
"Hyundai#H1/H200#1997-2008#650#",//--Hyundai--3275
"Hyundai#H1/H200 with rear A/C#1997-2008#1300#",//--Hyundai--3279
"Hyundai#H1/H300 /Mon 2.5D CRDi#2008-2020#650#",//--Hyundai--3283
"Hyundai#H1/H300 with rear A/C#2008-2020#850#",//--Hyundai--3287
"Hyundai#i10#2008-2015#450#",//--Hyundai--3291
"Hyundai#i10#2015-2020#400#",//--Hyundai--3295
"Hyundai#i10#2020-2022#430#",//--Hyundai--3299
"Hyundai#i20#2009-2015#450#",//--Hyundai--3303
"Hyundai#i20#2015-2020#470#",//--Hyundai--3307
"Hyundai#i20#2020-2022#430#",//--Hyundai--3311
"Hyundai#i30#2008-2022#500#",//--Hyundai--3315
"Hyundai#i40 1.6GDi/2.0GDi/1.7CRDi#2011-2020#550#",//--Hyundai--3319
"Hyundai#i800/iLoad/iMax#2008-2014#650#",//--Hyundai--3323
"Hyundai#i800/iLoad/iMax with rear a/c#2008-2014#850#",//--Hyundai--3327
"Hyundai#i800/iLoad/iMax 2.5D CRDi#2008-2020#650#",//--Hyundai--3331
"Hyundai#i800/iLoad/iMax with rear a/c#2008-2020#850#",//--Hyundai--3335
"Hyundai#IONIQ electric (poe oil)#2016-2022#550#",//--Hyundai--3339
"Hyundai#IONIQ electric With heat pump (poe oil)#2016-2022#1100#",//--Hyundai--3343
"Hyundai#IONIQ 1,6 GDI Hybrid (poe oil)#2016-2022#600#",//--Hyundai--3347
"Hyundai#Kona#2017-2022#500#",//--Hyundai--3351
"Hyundai#ix20#2010-2019#550#",//--Hyundai--3355
"Hyundai#ix35#2010-2015#510#",//--Hyundai--3359
"Hyundai#ix35 Fuel cell 100kw#2013-2018#550#",//--Hyundai--3363
"Hyundai#ix55#2008-2013#700#",//--Hyundai--3367
"Hyundai#ix55 with rear a/c#2008-2013#900#",//--Hyundai--3371
"Hyundai#Lantra#1994-1996#675#",//--Hyundai--3375
"Hyundai#Lantra#1996-2000#700#",//--Hyundai--3379
"Hyundai#Lavita#2001-2004#570#",//--Hyundai--3383
"Hyundai#Matrix 1.6i/1.8i#2001-2006#570#",//--Hyundai--3387
"Hyundai#Montana#2008-2018#650#",//--Hyundai--3391
"Hyundai#Montana with rear a/c#2008-2018#850#",//--Hyundai--3395
"Hyundai#Porter#1993-2007#650#",//--Hyundai--3399
"Hyundai#Porter with rear a/c#1993-2007#1400#",//--Hyundai--3403
"Hyundai#Pony#1994-2015#690#",//--Hyundai--3407
"Hyundai#S Coupe#1994-1996#675#",//--Hyundai--3411
"Hyundai#Santa Fe#2001-2006#600#",//--Hyundai--3415
"Hyundai#Santa Fe (CM)#2006-2018#600#",//--Hyundai--3419
"Hyundai#Santa Fe (CM) with rear a/c#2006-2018#800#",//--Hyundai--3423
"Hyundai#Santa Fe (CM)#2018-2020#700#",//--Hyundai--3427
"Hyundai#Santa Fe (CM) with rear a/c#2018-2020#850#",//--Hyundai--3431
"Hyundai#Satellite#1997-2007#650#",//--Hyundai--3435
"Hyundai#Satellite with rear a/c#1997-2007#1300#",//--Hyundai--3439
"Hyundai#Satellite#2008-2018#650#",//--Hyundai--3443
"Hyundai#Satellite with rear a/c#2008-2018#850#",//--Hyundai--3447
"Hyundai#Solaris#2010-2017#420#",//--Hyundai--3451
"Hyundai#Sonata#1993-1994#800#",//--Hyundai--3455
"Hyundai#Sonata#1995-1997#725#",//--Hyundai--3459
"Hyundai#Sonata III (EF)#1998-2001#700#",//--Hyundai--3463
"Hyundai#Sonata IV (new EF)#2001-2005#680#",//--Hyundai--3467
"Hyundai#Sonata V (NF)#2005-2015#550#",//--Hyundai--3471
"Hyundai#Sonata#2016-2018#575#",//--Hyundai--3475
"Hyundai#Sonata Eco/ Limited 2,0/ Ultima#2016-2018#525#",//--Hyundai--3479
"Hyundai#Sonata Hybrid (poe oil)#2016-2018#675#",//--Hyundai--3483
"Hyundai#Starex#1997-2007#650#",//--Hyundai--3487
"Hyundai#Starex with rear a/c#1997-2007#1300#",//--Hyundai--3491
"Hyundai#Starex#2008-2020#650#",//--Hyundai--3495
"Hyundai#Starex with rear a/c#2008-2020#850#",//--Hyundai--3499
"Hyundai#Terracan 2.9 CRDI/3.5iV6#2001-2008#850#",//--Hyundai--3503
"Hyundai#Trajet#2000-2003#670#",//--Hyundai--3507
"Hyundai#Trajet with rear a/c#2000-2003#850#",//--Hyundai--3511
"Hyundai#Tiburon#2002-2009#600#",//--Hyundai--3515
"Hyundai#Tuscon#2004-2010#510#",//--Hyundai--3519
"Hyundai#Tuscon#2011-2022#600#",//--Hyundai--3523
"Hyundai#Tuscon  1.6 T-GDI Hybrid#2021-2022#650#",//--Hyundai--3527
"Hyundai#Veloster 1.6GDi#2011-2017#420#",//--Hyundai--3531
"Hyundai#Veloster#2017-2018#445#",//--Hyundai--3535
"Hyundai#Veracruz#2008-2016#700#",//--Hyundai--3539
"Hyundai#Veracruz with rear a/c#2008-2016#900#",//--Hyundai--3543
"Hyundai#XG#2000-2005#670#",//--Hyundai--3547
"Ikco#Dena#2016-2018#580#",//--3549-3567Ikco--3551
"Ikco#DFM H30 Cross#2016-2018#580#",//--Ikco--3555
"Ikco#Rana#2016-2018#620#",//--Ikco--3559
"Ikco#Soren Elx#2016-2018#580#",//--Ikco--3563
"Ikco#Samand#2016-2018#580#",//--Ikco--3567
"Infiniti#EX (J50) 3.7i#2007-2015#550#",//--3569-3587Infiniti--3571
"Infiniti#FX (S51) 3.7i/5.0i#2008-2015#550#",//--Infiniti--3575
"Infiniti#G (V36) 3.7i#2007-2015#550#",//--Infiniti--3579
"Infiniti#M (Y51)#2010-2013#550#",//--Infiniti--3583
"Infiniti#M35h (Y51)#2011-2013#550#",//--Infiniti--3587
"Isuzu#Ascender#2003-2005#1100#",//--3589-3627Isuzu--3591
"Isuzu#Campo 3.1D Turbo#1990-2003#650#",//--Isuzu--3595
"Isuzu#Rodeo/D-Max 2.5D/3.0D#2003-2012#650#",//--Isuzu--3599
"Isuzu#D-Max 2.5D/3.0D#2013-2022#530#",//--Isuzu--3603
"Isuzu#D-Max 2.5D/3.0D with rear a/c#2013-2022#800#",//--Isuzu--3607
"Isuzu#Grafter 1.9D#2017-2020#350#",//--Isuzu--3611
"Isuzu#N Series 5.2D#2005-2011#450#",//--Isuzu--3615
"Isuzu#TF#2002-2003#650#",//--Isuzu--3619
"Isuzu#Trooper#1994-2003#750#",//--Isuzu--3623
"Isuzu#Trooper Dizel#1994-2003#750#",//--Isuzu--3627
"Iveco#Daily#1996-2010#720#",//--3629-3651Iveco--3631
"Iveco#Daily Minibus#1996-2010#1200#",//--Iveco--3635
"Iveco#Daily 2,8 CNG/3,0D HPT/ 3,0D HPI#2006-2010#440#",//--Iveco--3639
"Iveco#Daily#2011-2014#450#",//--Iveco--3643
"Iveco#Daily Minibus#2011-2014#1200#",//--Iveco--3647
"Iveco#Daily#2014-2019#475#",//--Iveco--3651
"Jaguar#Daimler Double Six 6.0i#1994-1997#1100#",//--3653-3795Jaguar--3655
"Jaguar#Daimler 4.0V8#1997-2004#675#",//--Jaguar--3659
"Jaguar#E-Pace#2017-2022#650#",//--Jaguar--3663
"Jaguar#F-Pace#2016-2022#550#",//--Jaguar--3667
"Jaguar#F-Type Coupe#2014-2020#700#",//--Jaguar--3671
"Jaguar#I-Pace Electric#2018-2022#850#",//--Jaguar--3675
"Jaguar#S-Type VIN M45255#1999-2002#800#",//--Jaguar--3679
"Jaguar#S-Type VIN M45255#2002-2008#750#",//--Jaguar--3683
"Jaguar#S-Type 2.7D#2004-2008#700#",//--Jaguar--3687
"Jaguar#X-Type (CF1) 2.0i/2.5i/3.0i#2001-2010#810#",//--Jaguar--3691
"Jaguar#X-Type 2.0D/2.2D#2003-2010#735#",//--Jaguar--3695
"Jaguar#XE#2015-2020#550#",//--Jaguar--3699
"Jaguar#XF#2009-2015#750#",//--Jaguar--3703
"Jaguar#XF#2015-2020#550#",//--Jaguar--3707
"Jaguar#XF 2.2D#2011-2015#700#",//--Jaguar--3711
"Jaguar#XFR 5.0i#2009-2018#750#",//--Jaguar--3715
"Jaguar#XJ (X351)#2010-2020#700#",//--Jaguar--3719
"Jaguar#XJ6 3.0i/2.7D TDVi#2003-2010#650#",//--Jaguar--3723
"Jaguar#XJ6 with rear a/c#2003-2010#800#",//--Jaguar--3727
"Jaguar#XJ6/Sovereign#1993-1994#1150#",//--Jaguar--3731
"Jaguar#XJ6/XJR#1994-1997#1100#",//--Jaguar--3735
"Jaguar#XJ8 3.2i/4.0i#1997-2003#675#",//--Jaguar--3739
"Jaguar#XJ8 3.5i/4.2i/4.2i Super V8#2003-2010#650#",//--Jaguar--3743
"Jaguar#XJ8 with rear a/c#2003-2010#800#",//--Jaguar--3747
"Jaguar#XJ12/Double Six#1993-1994#1150#",//--Jaguar--3751
"Jaguar#XJ12/Double Six#1994-1997#1100#",//--Jaguar--3755
"Jaguar#XJR 4.0i#1998-2003#675#",//--Jaguar--3759
"Jaguar#XJR 4.2i#2003-2010#640#",//--Jaguar--3763
"Jaguar#XJR with rear a/c#2003-2010#800#",//--Jaguar--3767
"Jaguar#XJS#1993-1997#925#",//--Jaguar--3771
"Jaguar#XK8#1996-2003#650#",//--Jaguar--3775
"Jaguar#XK8 4.2i#2006-2015#700#",//--Jaguar--3779
"Jaguar#XK8 5.0i#2009-2015#700#",//--Jaguar--3783
"Jaguar#XKR 4.0i/4.2i#2002-2006#675#",//--Jaguar--3787
"Jaguar#XKR 4.2i#2006-2015#700#",//--Jaguar--3791
"Jaguar#XKR 5.0i/5.0iS#2009-2015#700#",//--Jaguar--3795
"Jeep#Cherokee#1994-1996#900#",//--3797-3871Jeep--3799
"Jeep#Cherokee#1997-2000#570#",//--Jeep--3803
"Jeep#Cherokee 2.8CRD#2008-2015#510#",//--Jeep--3807
"Jeep#Cherokee#2014-2018#540#",//--Jeep--3811
"Jeep#Compass#2017-2022#570#",//--Jeep--3815
"Jeep#Grand Cherokee#1993-1996#795#",//--Jeep--3819
"Jeep#Grand Cherokee#1997-1999#680#",//--Jeep--3823
"Jeep#Grand Cherokee#1999-2011#680#",//--Jeep--3827
"Jeep#Grand Cherokee#2012-2022#625#",//--Jeep--3831
"Jeep#Commander 3.0D CRD#2006-2015#680#",//--Jeep--3835
"Jeep#Commander 3.0D CRD with rear a/c#2006-2015#960#",//--Jeep--3839
"Jeep#Compass 2.0D CRD#2006-2010#510#",//--Jeep--3843
"Jeep#Compass#2006-2016#595#",//--Jeep--3847
"Jeep#Compass#2017-2020#570#",//--Jeep--3851
"Jeep#Patriot 2.0 CRD/2.4i#2007-2013#510#",//--Jeep--3855
"Jeep#Wrangler#1994-1996#900#",//--Jeep--3859
"Jeep#Wrangler (TJ)#1996-2006#565#",//--Jeep--3863
"Jeep#Wrangler#2018-2022#540#",//--Jeep--3867
"Jeep#Wrangler (JK) 2.8CRD/3.8i#2007-2018#510#",//--Jeep--3871
"Kia#Carens#1999-2006#800#",//--3873-4147Kia--3875
"Kia#Carens II#2006-2013#450#",//--Kia--3879
"Kia#Carens II#2014-2019#550#",//--Kia--3883
"Kia#Carnival#2000-2006#1150#",//--Kia--3887
"Kia#Carnival 2.5i GV6#2001-2006#1000#",//--Kia--3891
"Kia#Carnival#2006-2015#800#",//--Kia--3895
"Kia#Grand Carnival - Sedona#2016-2018#1125#",//--Kia--3899
"Kia#Ceed#2006-2022#500#",//--Kia--3903
"Kia#Cerato#2004-2008#500#",//--Kia--3907
"Kia#Cerato dizel/Benzin#2008-2022#500#",//--Kia--3911
"Kia#Clarus/Credos 1.8#1996-2003#700#",//--Kia--3915
"Kia#Clarus/Credos 2.0#1996-2003#700#",//--Kia--3919
"Kia#Niro  Hybrid#2019-2020#550#",//--Kia--3923
"Kia#e-Niro Electric#2019-2022#650#",//--Kia--3927
"Kia#e-Niro Electric with heat pump#2019-2022#1000#",//--Kia--3931
"Kia#e-Soul Electric#2019-2022#600#",//--Kia--3935
"Kia#Joice#2000-2006#730#",//--Kia--3939
"Kia#K2500#2004-2007#450#",//--Kia--3943
"Kia#K2700#2000-2004#450#",//--Kia--3947
"Kia#K2900#2008-2012#450#",//--Kia--3951
"Kia#K900#2017-2018#650#",//--Kia--3955
"Kia#Magentis#2001-2005#670#",//--Kia--3959
"Kia#Magentis#2005-2007#500#",//--Kia--3963
"Kia#Magentis (MG)#2005-2015#500#",//--Kia--3967
"Kia#Mentor#1994-2004#700#",//--Kia--3971
"Kia#Niro  Hybrid#2016-2018#550#",//--Kia--3975
"Kia#Opirus#2003-2007#650#",//--Kia--3979
"Kia#Optima#2015-2020#570#",//--Kia--3983
"Kia#Optima#2011-2014#550#",//--Kia--3987
"Kia#Optima#2006-2010#500#",//--Kia--3991
"Kia#Optima 2,0 Hybrid#2016-2018#650#",//--Kia--3995
"Kia#Optima#2002-2005#680#",//--Kia--3999
"Kia#Picanto#2004-2011#450#",//--Kia--4003
"Kia#Picanto (TA)#2011-2020#370#",//--Kia--4007
"Kia#Picanto#2020-2022#400#",//--Kia--4011
"Kia#Pregio#1997-2007#850#",//--Kia--4015
"Kia#Pro-Ceed#2015-2022#500#",//--Kia--4019
"Kia#Pride#2000-2010#570#",//--Kia--4023
"Kia#Rio#2000-2005#650#",//--Kia--4027
"Kia#Rio II#2005-2015#500#",//--Kia--4031
"Kia#Rio III (UB)#2011-2016#420#",//--Kia--4035
"Kia#Rio#2017-2022#450#",//--Kia--4039
"Kia#Seltos#2020-2022#500#",//--Kia--4043
"Kia#Sedona#2000-2006#1150#",//--Kia--4047
"Kia#Sedona#2007-2013#650#",//--Kia--4051
"Kia#Sedona Diesel with rear a/c#2007-2013#800#",//--Kia--4055
"Kia#Sedona Benzin with rear a/c#2007-2013#950#",//--Kia--4059
"Kia#Sephia#1996-2000#700#",//--Kia--4063
"Kia#Shuma#1998-2004#700#",//--Kia--4067
"Kia#Spectra#2000-2004#700#",//--Kia--4071
"Kia#Sportage#1995-2003#700#",//--Kia--4075
"Kia#Sportage#2004-2015#510#",//--Kia--4079
"Kia#Sportage Dizel (QL)#2015-2016#550#",//--Kia--4083
"Kia#Sportage#2017-2022#600#",//--Kia--4087
"Kia#Stinger#2017-2022#650#",//--Kia--4091
"Kia#Stonic#2017-2020#450#",//--Kia--4095
"Kia#Sorento#2002-2007#600#",//--Kia--4099
"Kia#Sorento 3.3i/2.5 CRDi#2007-2015#540#",//--Kia--4103
"Kia#Sorento (XM)#2009-2015#600#",//--Kia--4107
"Kia#Sorento with rear a/c#2009-2015#750#",//--Kia--4111
"Kia#Sorento (UM)#2015-2020#700#",//--Kia--4115
"Kia#Sorento (UM) with rear a/c#2015-2020#850#",//--Kia--4119
"Kia#Sorento#2020-2022#650#",//--Kia--4123
"Kia#Sorento with rear a/c#2020-2022#850#",//--Kia--4127
"Kia#Soul#2009-2018#550#",//--Kia--4131
"Kia#Soul#2019-2022#450#",//--Kia--4135
"Kia#Soul 0 EV Hybrid (Komp.poe oil)#2014-2018#550#",//--Kia--4139
"Kia#XCeed#2019-2022#500#",//--Kia--4143
"Kia#Venga#2009-2019#550#",//--Kia--4147
"Lancia#Dedra#1993-1995#900#",//--4149-4267Lancia--4151
"Lancia#Dedra#1996-1999#730#",//--Lancia--4155
"Lancia#Dedra 2.0 16V#1996-1999#900#",//--Lancia--4159
"Lancia#Dedra Turbo D#1994-1999#730#",//--Lancia--4163
"Lancia#Delta#1994-1999#800#",//--Lancia--4167
"Lancia#Delta#2008-2015#500#",//--Lancia--4171
"Lancia#Delta 1,4 Multi air / Lpg#2010-2015#450#",//--Lancia--4175
"Lancia#Delta 1.6 16V#1996-1999#730#",//--Lancia--4179
"Lancia#Delta 1.8 16V#1996-1999#730#",//--Lancia--4183
"Lancia#Delta Turbo D#1994-1999#730#",//--Lancia--4187
"Lancia#Flavia#2012-2015#450#",//--Lancia--4191
"Lancia#Kappa Sanden komp#1994-2000#730#",//--Lancia--4195
"Lancia#Kappa Denso komp#1994-2000#800#",//--Lancia--4199
"Lancia#Kappa 2.0i/2.4i/3.0i Sanden komp#1994-2002#730#",//--Lancia--4203
"Lancia#Kappa 2.0i/2.4i/3.0i Denso komp#1994-2002#800#",//--Lancia--4207
"Lancia#Lybra 1.6i#1999-2006#700#",//--Lancia--4211
"Lancia#Lybra 1.8i/2.0i/1.9JTD#2001-2007#700#",//--Lancia--4215
"Lancia#Lybra 2.4JTD#1999-2006#700#",//--Lancia--4219
"Lancia#Musa 1.4i/1.4i 16V/1.3D JTD#2004-2012#500#",//--Lancia--4223
"Lancia#Musa 1.9D JTD/1.6D#2004-2012#500#",//--Lancia--4227
"Lancia#Phedra#2002-2011#600#",//--Lancia--4231
"Lancia#Thema#1992-1994#1100#",//--Lancia--4235
"Lancia#Thesis#2002-2009#650#",//--Lancia--4239
"Lancia#Thesis 3.0i/3.2i#2002-2009#730#",//--Lancia--4243
"Lancia#Voyager#2011-2015#820#",//--Lancia--4247
"Lancia#Voyager with rear a/c#2011-2015#1150#",//--Lancia--4251
"Lancia#Ypsilon 1.1#1996-2003#650#",//--Lancia--4255
"Lancia#Ypsilon 1.2/1.4#1996-2003#675#",//--Lancia--4259
"Lancia#Ypsilon 1.2i/1.2i 16V/1.4i/1.3D JTD#2003-2022#500#",//--Lancia--4263
"Lancia#Zeta#1996-2002#975#",//--Lancia--4267
"Land Rover#Defender#1994-1998#1090#",//--4269-4495Land Rover--4271
"Land Rover#Defender TD5 motor 10P#1999-2007#750#",//--Land Rover--4275
"Land Rover#Defender TD5 motor 15P#2001-2007#750#",//--Land Rover--4279
"Land Rover#Defender 2.2 / 2.4TD4#2006-2015#600#",//--Land Rover--4283
"Land Rover#Defender#2019-2022#650#",//--Land Rover--4287
"Land Rover#Defender three zone a/c#2019-2022#1000#",//--Land Rover--4291
"Land Rover#Discovery#1994-1998#900#",//--Land Rover--4295
"Land Rover#Discovery with rear a/c#1994-1998#1150#",//--Land Rover--4299
"Land Rover#Discovery#1998-2004#700#",//--Land Rover--4303
"Land Rover#Discovery with rear a/c#1998-2004#900#",//--Land Rover--4307
"Land Rover#Discovery III 2.7TD#2004-2009#550#",//--Land Rover--4311
"Land Rover#Discovery III 2.7TD with rear a/c#2004-2009#810#",//--Land Rover--4315
"Land Rover#Discovery III 4.4i/4.0i#2004-2009#600#",//--Land Rover--4319
"Land Rover#Discovery III 4.4i/4.0i with rear a/c#2004-2009#900#",//--Land Rover--4323
"Land Rover#Discovery IV (LA) 2.7TDV6#2009-2015#550#",//--Land Rover--4327
"Land Rover#Discovery IV (LA) 2.7TDV6 with rear a/c#2009-2015#810#",//--Land Rover--4331
"Land Rover#Discovery IV (LA) 4.0i#2009-2016#600#",//--Land Rover--4335
"Land Rover#Discovery IV (LA) 4.0i with rear a/c#2009-2016#900#",//--Land Rover--4339
"Land Rover#Discovery IV (LA) 3.0TDV6/5.0i#2009-2016#625#",//--Land Rover--4343
"Land Rover#Discovery IV (LA) 3.0TDV6 with rear a/c#2009-2016#900#",//--Land Rover--4347
"Land Rover#Discovery#2017-2022#800#",//--Land Rover--4351
"Land Rover#Discovery Four zone#2017-2022#1150#",//--Land Rover--4355
"Land Rover#Discovery SPORT#2020-2022#525#",//--Land Rover--4359
"Land Rover#Discovery SPORT with rear a/c#2020-2022#725#",//--Land Rover--4363
"Land Rover#Evoque#2017-2020#650#",//--Land Rover--4367
"Land Rover#Freelander#1997-2000#725#",//--Land Rover--4371
"Land Rover#Freelander#2000-2006#540#",//--Land Rover--4375
"Land Rover#Freelander LHD motor 2.5I#2000-2006#430#",//--Land Rover--4379
"Land Rover#Freelander II 2.2DTD4#2006-2015#730#",//--Land Rover--4383
"Land Rover#Freelander II 3.2i#2006-2015#730#",//--Land Rover--4387
"Land Rover#Range Rover/Classic#1994-1995#900#",//--Land Rover--4391
"Land Rover#Range Rover II benzin#1994-1999#1250#",//--Land Rover--4395
"Land Rover#Range Rover II benzin#1999-2002#1380#",//--Land Rover--4399
"Land Rover#Range Rover II Dizel#1994-2002#1100#",//--Land Rover--4403
"Land Rover#Range RoverIII(LM)4.4i(448S2)/3.0TD#2002-2006#510#",//--Land Rover--4407
"Land Rover#Range RoverIII 4.4i(448PN)/4.2i Sup#2005-2013#700#",//--Land Rover--4411
"Land Rover#Range Rov 2.0/3.0/4.4SDV8/SDV6/TDV6#2014-2020#800#",//--Land Rover--4415
"Land Rover#Range Rov2.0/3.0/4.4SDV8/SDV6/TDV6 four-zone#2017-2020#1150#",//--Land Rover--4419
"Land Rover#Range Rover 2.0 P400e#2020-2022#950#",//--Land Rover--4423
"Land Rover#Range Rover 2.0 P400e four-zone#2020-2022#1100#",//--Land Rover--4427
"Land Rover#Range Rover 3.0#2019-2022#800#",//--Land Rover--4431
"Land Rover#Range Rover 3.0  four-zone#2019-2022#1000#",//--Land Rover--4435
"Land Rover#Range Rover Evoque#2011-2015#650#",//--Land Rover--4439
"Land Rover#Range Rover Evoque#2020-2022#525#",//--Land Rover--4443
"Land Rover#Range Rover Sport4.4i(448PN)/4.2i S#2005-2009#600#",//--Land Rover--4447
"Land Rover#Range Rover Sport 2.7D TDV6#2005-2009#600#",//--Land Rover--4451
"Land Rover#Range Rover Sport 3.0D TDV6#2009-2013#600#",//--Land Rover--4455
"Land Rover#Range Rover Sport 3.6D TDV8#2006-2013#650#",//--Land Rover--4459
"Land Rover#Range Rover Sport 5.0i/5.0i Sup#2009-2013#700#",//--Land Rover--4463
"Land Rover#Range Rover Sport Hybrid#2014-2018#800#",//--Land Rover--4467
"Land Rover#Range Rover Sport Hybrid(Four Zone)#2014-2018#1150#",//--Land Rover--4471
"Land Rover#Range Rover Sport#2020-2022#650#",//--Land Rover--4475
"Land Rover#Range Rover Sport (Four Zone)#2020-2022#1000#",//--Land Rover--4479
"Land Rover#Range Rover Sport 3.0/4.4#2020-2022#800#",//--Land Rover--4483
"Land Rover#Range Rover Sport 3.0(Four Zone)#2020-2022#1000#",//--Land Rover--4487
"Land Rover#Range Rover Sport 4.4(Four Zone)#2014-2020#1100#",//--Land Rover--4491
"Land Rover#Range Rover Velar#2017-2022#550#",//--Land Rover--4495
"LDV#Maxus 2.5D CRD LHD#2005-2009#850#",//--4497-4527LDV--4499
"LDV#Maxus 2.5D CRD RHD#2005-2009#880#",//--LDV--4503
"LDV#V80 4,8 KW comp.#2015-2022#600#",//--LDV--4507
"LDV#V80 7,0 KW comp.#2015-2022#700#",//--LDV--4511
"LDV#V80 Double compressor#2015-2022#600#",//--LDV--4515
"LDV#V80 with rear a/c SWB#2015-2022#1450#",//--LDV--4519
"LDV#V80 with rear a/c LWB#2015-2022#1750#",//--LDV--4523
"LDV#V80 Auxiliary condenser#2015-2022#2020#",//--LDV--4527
"Lexus#CT 200h#2010-2022#470#",//--4529-4715Lexus--4531
"Lexus#ES#2019-2020#610#",//--Lexus--4535
"Lexus#ES 300h Hybrid#2019-2020#550#",//--Lexus--4539
"Lexus#GS 300#1994-1997#850#",//--Lexus--4543
"Lexus#GS 300#1997-2005#600#",//--Lexus--4547
"Lexus#GS 300 (GRS/URZ)#2005-2015#450#",//--Lexus--4551
"Lexus#GS 430#2000-2005#600#",//--Lexus--4555
"Lexus#GS 430#2005-2008#450#",//--Lexus--4559
"Lexus#GS 450h#2006-2015#450#",//--Lexus--4563
"Lexus#GS 460#2008-2015#550#",//--Lexus--4567
"Lexus#GS Hybrid (Komp.poe oil)#2012-2018#500#",//--Lexus--4571
"Lexus#GS 5,0F#2012-2018#570#",//--Lexus--4575
"Lexus#GX 4.6#2010-2022#550#",//--Lexus--4579
"Lexus#GX 4.6 with rear a/c#2010-2022#800#",//--Lexus--4583
"Lexus#GX 4.6 with rear a/c and#2010-2022#800#",//--Lexus--4587
"Lexus#GX 4.6 with rear a/c and refrigerator#2010-2022#870#",//--Lexus--4591
"Lexus#IS 200#1999-2005#600#",//--Lexus--4595
"Lexus#IS Cabrio#2009-2014#430#",//--Lexus--4599
"Lexus#IS 200#2013-2019#570#",//--Lexus--4603
"Lexus#IS 300#2001-2005#600#",//--Lexus--4607
"Lexus#IS 300h 2,5#2013-2020#570#",//--Lexus--4611
"Lexus#IS 250/220d/5.0F#2005-2015#440#",//--Lexus--4615
"Lexus#IS / RC Hybrid (Komp.poe oil)#2013-2022#570#",//--Lexus--4619
"Lexus#LC#2017-2022#550#",//--Lexus--4623
"Lexus#LS 400#1993-2000#700#",//--Lexus--4627
"Lexus#LS 400 with rear a/c#1993-2000#950#",//--Lexus--4631
"Lexus#LS 430#2018-2020#650#",//--Lexus--4635
"Lexus#LS 430 with rear a/c#2001-2007#900#",//--Lexus--4639
"Lexus#LS 4,6 460#2006-2013#600#",//--Lexus--4643
"Lexus#LS 460 with rear a/c#2006-2013#750#",//--Lexus--4647
"Lexus#LS4,6 285kw(387hp)/AWD 272kw(370hp)460#2012-2018#550#",//--Lexus--4651
"Lexus#LS4,6 285kw(387hp)/AWD 272kw(370hp)with rear#2012-2018#700#",//--Lexus--4655
"Lexus#LS 3,4 500 4WD#2018-2022#650#",//--Lexus--4659
"Lexus#LS 3,4 500 4WD with rear a/c#2018-2022#970#",//--Lexus--4663
"Lexus#LS 600h(Komp.poe oil)#2007-2009#900#",//--Lexus--4667
"Lexus#LS 600h (Komp.poe oil)#2009-2018#840#",//--Lexus--4671
"Lexus#NX Hybrid (Komp.poe oil)#2014-2022#500#",//--Lexus--4675
"Lexus#RC 300h#2015-2022#570#",//--Lexus--4679
"Lexus#RX 300#2000-2003#650#",//--Lexus--4683
"Lexus#RX 300#2003-2007#600#",//--Lexus--4687
"Lexus#RX 350#2006-2009#600#",//--Lexus--4691
"Lexus#RX 350#2009-2015#500#",//--Lexus--4695
"Lexus#RX 400h#2005-2010#600#",//--Lexus--4699
"Lexus#RX 450h#2009-2015#600#",//--Lexus--4703
"Lexus#RX#2016-2022#500#",//--Lexus--4707
"Lexus#SC 430#2001-2006#700#",//--Lexus--4711
"Lexus#UX#2019-2022#470#",//--Lexus--4715
"Mcc/Smart#City Coupe /Cabrio#1999-2003#620#",//--4717-4751Mcc/Smart--4719
"Mcc/Smart#City Coupe /Cabrio#2003-2004#450#",//--Mcc/Smart--4723
"Mcc/Smart#Forfour#2014-2019#475#",//--Mcc/Smart--4727
"Mcc/Smart#Fortwo#2004-2007#450#",//--Mcc/Smart--4731
"Mcc/Smart#Fortwo 0.7 Brabus#2004-2007#400#",//--Mcc/Smart--4735
"Mcc/Smart#Fortwo#2007-2015#420#",//--Mcc/Smart--4739
"Mcc/Smart#Fortwo Electric#2007-2015#550#",//--Mcc/Smart--4743
"Mcc/Smart#Fortwo#2016-2019#475#",//--Mcc/Smart--4747
"Mcc/Smart#Roadster/Coupe#2003-2006#650#",//--Mcc/Smart--4751
"Mazda#2 kond 1.2mm (f)#2003-2007#470#",//--4753-4991Mazda--4755
"Mazda#2 kond 3mm (f)#2003-2007#650#",//--Mazda--4759
"Mazda#2#2007-2015#500#",//--Mazda--4763
"Mazda#2 Engine 1,5- 1,5D#2016-2022#420#",//--Mazda--4767
"Mazda#3 1.4i/1.6i/2.0i#2003-2009#500#",//--Mazda--4771
"Mazda#3 1.6D#2003-2009#650#",//--Mazda--4775
"Mazda#3 2.0D/2.3MPS#2007-2009#500#",//--Mazda--4779
"Mazda#3 (BL)#2009-2015#475#",//--Mazda--4783
"Mazda#3#2016-2022#490#",//--Mazda--4787
"Mazda#5 1.8i/2.0i/2.0D CRD#2005-2010#500#",//--Mazda--4791
"Mazda#5 (CW)#2010-2015#480#",//--Mazda--4795
"Mazda#6 LHD 1.8i/2.0i/2.3i#2002-2007#470#",//--Mazda--4799
"Mazda#6 RHD 1.8i/2.0i/2.3i#2002-2007#430#",//--Mazda--4803
"Mazda#6 LHD 2.0D Turbo#2002-2007#470#",//--Mazda--4807
"Mazda#6 RHD 2.0D Turbo#2002-2007#430#",//--Mazda--4811
"Mazda#6 1.8i/2.0i/2.5i#2007-2015#500#",//--Mazda--4815
"Mazda#6 2.0D/2.2D#2007-2015#525#",//--Mazda--4819
"Mazda#6#2016-2021#490#",//--Mazda--4823
"Mazda#121#1993-1994#650#",//--Mazda--4827
"Mazda#121#1995-2003#740#",//--Mazda--4831
"Mazda#323#1994-1996#750#",//--Mazda--4835
"Mazda#323#1996-1998#725#",//--Mazda--4839
"Mazda#323 RHD#1998-2003#625#",//--Mazda--4843
"Mazda#323 LHD#1998-2003#600#",//--Mazda--4847
"Mazda#626#1992-1994#775#",//--Mazda--4851
"Mazda#626#1994-1997#700#",//--Mazda--4855
"Mazda#626#1997-2003#662#",//--Mazda--4859
"Mazda#B-Series 2.5D/2.5TD#1998-2002#550#",//--Mazda--4863
"Mazda#BT-50 2.5D/3.0D#2006-2011#475#",//--Mazda--4867
"Mazda#BT-50 2.5D/3.0D#2012-2015#650#",//--Mazda--4871
"Mazda#CX 7 2.3i/2.2D#2007-2015#490#",//--Mazda--4875
"Mazda#CX 9 3.7i#2007-2015#690#",//--Mazda--4879
"Mazda#CX 3#2016-2020#420#",//--Mazda--4883
"Mazda#CX 5#2012-2022#490#",//--Mazda--4887
"Mazda#CX 9#2017-2018#725#",//--Mazda--4891
"Mazda#CX 30#2019-2022#490#",//--Mazda--4895
"Mazda#Demio LHD#1998-2004#650#",//--Mazda--4899
"Mazda#Demio RHD#1998-2004#600#",//--Mazda--4903
"Mazda#E-Series#1995-2000#550#",//--Mazda--4907
"Mazda#E-Series 2,2D#1997-2003#700#",//--Mazda--4911
"Mazda#E-Series with rear a/c#1995-2000#1150#",//--Mazda--4915
"Mazda#Millenia#2000-2002#750#",//--Mazda--4919
"Mazda#MX3#1991-1994#800#",//--Mazda--4923
"Mazda#MX3#1995-1999#750#",//--Mazda--4927
"Mazda#MX5 (NB) 200000 until#1998-2005#700#",//--Mazda--4931
"Mazda#MX5 (NB) 200001 upwards#1998-2005#425#",//--Mazda--4935
"Mazda#MX5 (NC)#2005-2015#450#",//--Mazda--4939
"Mazda#MX5 (NC)#2016-2022#420#",//--Mazda--4943
"Mazda#MX6#1992-1994#775#",//--Mazda--4947
"Mazda#MX6#1994-1998#700#",//--Mazda--4951
"Mazda#MPV3.0i#1994-1999#1050#",//--Mazda--4955
"Mazda#MPV3.0i with rear a/c#1994-1999#1200#",//--Mazda--4959
"Mazda#MPV II#1999-2005#650#",//--Mazda--4963
"Mazda#MPV II with rear a/c#1999-2005#850#",//--Mazda--4967
"Mazda#Premacy#1999-2005#650#",//--Mazda--4971
"Mazda#RX 8#2003-2012#430#",//--Mazda--4975
"Mazda#Tribute 2.0i/3.0i#2000-2007#900#",//--Mazda--4979
"Mazda#Xedos 6#1992-1994#700#",//--Mazda--4983
"Mazda#Xedos 6#1994-2003#700#",//--Mazda--4987
"Mazda#Xedos 9#1994-2003#750#",//--Mazda--4991
"Mercedes#A-Class (W168)#1998-2005#600#",//--4993-5539Mercedes--4995
"Mercedes#A-Class (W169) 150/170/200#2004-2011#770#",//--Mercedes--4999
"Mercedes#A-Class (W169) 160CDI/180CDI#2004-2011#770#",//--Mercedes--5003
"Mercedes#A-Class (W169) 200CDI/200 Turbo#2004-2011#840#",//--Mercedes--5007
"Mercedes#A-Class (176)#2012-2018#650#",//--Mercedes--5011
"Mercedes#A-Class 2,0 A45 AMG 4Matic#2015-2018#670#",//--Mercedes--5015
"Mercedes#A-Class#2018-2022#590#",//--Mercedes--5019
"Mercedes#A-Class 1.3 A250e#2018-2020#660#",//--Mercedes--5023
"Mercedes#B-Class (W245) 150/200/180CDI/170#2005-2011#770#",//--Mercedes--5027
"Mercedes#B-Class (W245) 200 Turbo/200CDI#2005-2011#840#",//--Mercedes--5031
"Mercedes#B-Class (246)#2011-2018#650#",//--Mercedes--5035
"Mercedes#B-Class B250E / Electric Drive#2015-2018#720#",//--Mercedes--5039
"Mercedes#B-Class#2019-2022#590#",//--Mercedes--5043
"Mercedes#B-Class Hybrid#2020-2022#660#",//--Mercedes--5047
"Mercedes#C-Class (W202) VIN 1A 168 524#1993-2000#950#",//--Mercedes--5051
"Mercedes#C-Class (W202) VIN 1A 168 525#1993-2000#850#",//--Mercedes--5055
"Mercedes#C-Class (W 203)#2000-2004#725#",//--Mercedes--5059
"Mercedes#C-Class (W203) Facelift#2004-2007#850#",//--Mercedes--5063
"Mercedes#C-Class (204)#2007-2014#590#",//--Mercedes--5067
"Mercedes#C-Class (205)#2014-2022#630#",//--Mercedes--5071
"Mercedes#C-Class Coupe#2018-2022#630#",//--Mercedes--5075
"Mercedes#C-Class 2,0 C350E / C350 Hybrid#2015-2018#670#",//--Mercedes--5079
"Mercedes#C-Class 2,1 C300 Hybrid#2015-2018#710#",//--Mercedes--5083
"Mercedes#C-Class Cabriolet Coupe 4,0 C63 AMG#2015-2020#610#",//--Mercedes--5087
"Mercedes#C-Class 1.5/2.0 EQ Boost Hybrid#2021-2022#620#",//--Mercedes--5091
"Mercedes#Citan#2012-2022#550#",//--Mercedes--5095
"Mercedes#CL (216)#2010-2015#1070#",//--Mercedes--5099
"Mercedes#CLA Shooting Brake#2013-2018#650#",//--Mercedes--5103
"Mercedes#CLA Coupe#2019-2022#690#",//--Mercedes--5107
"Mercedes#CLA Coupe 2,0 45 AMG 4 Matic#2015-2018#670#",//--Mercedes--5111
"Mercedes#CLC (203)#2008-2015#850#",//--Mercedes--5115
"Mercedes#CLK (C208)#1997-2002#850#",//--Mercedes--5119
"Mercedes#CLK (C209)#2002-2009#750#",//--Mercedes--5123
"Mercedes#CLS (C219)#2005-2015#950#",//--Mercedes--5127
"Mercedes#CLS (218)#2011-2018#590#",//--Mercedes--5131
"Mercedes#CLS 5,5 63 AMG#2014-2018#640#",//--Mercedes--5135
"Mercedes#CLS#2018-2022#630#",//--Mercedes--5139
"Mercedes#CLS 3,0 AMG Hybrid#2018-2022#590#",//--Mercedes--5143
"Mercedes#E-Class (W124)#1993-1996#950#",//--Mercedes--5147
"Mercedes#E-Class (W124) with rear a/c#1993-1996#1150#",//--Mercedes--5151
"Mercedes#E-Class (W210)#1995-2002#1000#",//--Mercedes--5155
"Mercedes#E-Class (W211)#2002-2009#950#",//--Mercedes--5159
"Mercedes#E-Class (W212)#2009-2015#590#",//--Mercedes--5163
"Mercedes#E-Class (W212) 6.3 E63 AMG#2009-2018#640#",//--Mercedes--5167
"Mercedes#E-Class (207) Coupe/Cabrio#2009-2018#590#",//--Mercedes--5171
"Mercedes#E-Class E450/E53 EQ Boost#2018-2022#590#",//--Mercedes--5175
"Mercedes#E-Class  Coupe/Cabriolet#2017-2022#630#",//--Mercedes--5179
"Mercedes#E-Class 200d/E220d/E300d All-Terrain#2017-2022#610#",//--Mercedes--5183
"Mercedes#E-Class  2,0 E350e Hybrid#2016-2022#670#",//--Mercedes--5187
"Mercedes#E-Class  E350d E400d#2018-2020#630#",//--Mercedes--5191
"Mercedes#Econic (957)#1998-2015#800#",//--Mercedes--5195
"Mercedes#EQV Electric#2019-2022#660#",//--Mercedes--5199
"Mercedes#e-Vito Electric#2018-2022#660#",//--Mercedes--5203
"Mercedes#G 63 AMG#2017-2018#875#",//--Mercedes--5207
"Mercedes#G 65 AMG#2017-2018#875#",//--Mercedes--5211
"Mercedes#G 550#2017-2018#900#",//--Mercedes--5215
"Mercedes#G-Class (W461)#1993-2005#1100#",//--Mercedes--5219
"Mercedes#G-Class (W463)#1993-2005#1050#",//--Mercedes--5223
"Mercedes#G-Class (463.322/323) 270CDI#2001-2005#1070#",//--Mercedes--5227
"Mercedes#GL-Class (X164)#2006-2015#970#",//--Mercedes--5231
"Mercedes#GL-Class (X164) with rear a/c#2006-2015#1220#",//--Mercedes--5235
"Mercedes#GLA#2014-2020#650#",//--Mercedes--5239
"Mercedes#GLA#2020-2022#590#",//--Mercedes--5243
"Mercedes#GLA 45 AMG 4Matic#2020-2022#1010#",//--Mercedes--5247
"Mercedes#GLA 45 AMG S 4Matic#2020-2022#1200#",//--Mercedes--5251
"Mercedes#GLB#2019-2022#690#",//--Mercedes--5255
"Mercedes#GLC / Coupe#2015-2022#630#",//--Mercedes--5259
"Mercedes#GLC / Coupe 2,0 E350e 4Matic Hybrid#2016-2019#670#",//--Mercedes--5263
"Mercedes#GLE / Coupe / GLS#2015-2019#1050#",//--Mercedes--5267
"Mercedes#GLE / Coupe / GLS  with rear a/c#2015-2019#1300#",//--Mercedes--5271
"Mercedes#GLE#2019-2022#720#",//--Mercedes--5275
"Mercedes#GLE 350d/450/580/AMG#2019-2022#770#",//--Mercedes--5279
"Mercedes#GLS#2016-2019#1050#",//--Mercedes--5283
"Mercedes#GLS with rear a/c#2016-2019#1300#",//--Mercedes--5287
"Mercedes#GLS#2019-2022#720#",//--Mercedes--5291
"Mercedes#GLS with rear a/c#2019-2022#1010#",//--Mercedes--5295
"Mercedes#GLK (X204)#2008-2015#590#",//--Mercedes--5299
"Mercedes#M-Class (W163)#1998-2005#750#",//--Mercedes--5303
"Mercedes#M-Class (W164)#2005-2015#970#",//--Mercedes--5307
"Mercedes#M-Klasse (W164) with rear a/c#2006-2015#1220#",//--Mercedes--5311
"Mercedes#M-Class (166)#2011-2015#1050#",//--Mercedes--5315
"Mercedes#M-Class (166) with rear a/c#2011-2015#1300#",//--Mercedes--5319
"Mercedes#MAYBACH#2017-2020#660#",//--Mercedes--5323
"Mercedes#MAYBACH with rear a/c#2017-2020#770#",//--Mercedes--5327
"Mercedes#MAYBACH GLS with rear a/c#2020-2022#1010#",//--Mercedes--5331
"Mercedes#MAYBACH GLS#2020-2022#720#",//--Mercedes--5335
"Mercedes#R-Class (W251/V251)#2006-2015#970#",//--Mercedes--5339
"Mercedes#R-Class (W251/V251) with rear a/c#2006-2015#1220#",//--Mercedes--5343
"Mercedes#S-Class (W140) VIN 1A 128 373#1991-1999#1200#",//--Mercedes--5347
"Mercedes#S-Class (W140) VIN1A128373 with rear a/c#1991-1999#1400#",//--Mercedes--5351
"Mercedes#S-Class (W140) VIN 1A 128 374R#1991-1999#1150#",//--Mercedes--5355
"Mercedes#S-Class (W140) VIN1A128 374R with rear a/c#1991-1999#1250#",//--Mercedes--5359
"Mercedes#S-Class (W220)#1998-2006#950#",//--Mercedes--5363
"Mercedes#S-Class (W220) with rear a/c#1998-2006#1050#",//--Mercedes--5367
"Mercedes#S-Class Coupe (C215) CL500/600#2002-2007#950#",//--Mercedes--5371
"Mercedes#S-Class (W221)#2006-2015#1070#",//--Mercedes--5375
"Mercedes#S-Class (W221) with rear a/c#2006-2015#1180#",//--Mercedes--5379
"Mercedes#S-Class S400#2013-2015#770#",//--Mercedes--5383
"Mercedes#S-Class S400 with rear a/c#2013-2015#870#",//--Mercedes--5387
"Mercedes#S-Class Cabriolet / Coupe#2016-2022#660#",//--Mercedes--5391
"Mercedes#S-Class Cabriolet / Coupe with rear a/c#2016-2022#770#",//--Mercedes--5395
"Mercedes#S-Class S560e#2018-2022#710#",//--Mercedes--5399
"Mercedes#S-Class S560e with rear a/c#2018-2022#820#",//--Mercedes--5403
"Mercedes#SLC CLASS#2015-2020#550#",//--Mercedes--5407
"Mercedes#SLK (R170)#1996-2004#850#",//--Mercedes--5411
"Mercedes#SLK (R171)#2004-2011#670#",//--Mercedes--5415
"Mercedes#SLK (172)#2011-2016#550#",//--Mercedes--5419
"Mercedes#SL (R129)#1991-2002#950#",//--Mercedes--5423
"Mercedes#SL (R230)#2001-2011#920#",//--Mercedes--5427
"Mercedes#SL#2015-2020#550#",//--Mercedes--5431
"Mercedes#Sprinter#1995-2005#860#",//--Mercedes--5435
"Mercedes#Sprinter with rear a/c#1995-2005#1300#",//--Mercedes--5439
"Mercedes#Sprinter#2006-2018#800#",//--Mercedes--5443
"Mercedes#Sprinter with rear a/c#2006-2018#1190#",//--Mercedes--5447
"Mercedes#Sprinter hp A/C (H08)#2006-2018#1000#",//--Mercedes--5451
"Mercedes#Sprinter 2.0d/2.1d#2019-2022#600#",//--Mercedes--5455
"Mercedes#Sprinter D50/D51/D64#2018-2022#600#",//--Mercedes--5459
"Mercedes#Sprinter G42/G43#2018-2022#800#",//--Mercedes--5463
"Mercedes#Sprinter HH7 / HH9 /IR4#2018-2022#1725#",//--Mercedes--5467
"Mercedes#Sprinter H08 and IR4#2018-2022#1800#",//--Mercedes--5471
"Mercedes#Sprinter HH7/HH9 and IR6/IR7#2018-2022#1825#",//--Mercedes--5475
"Mercedes#Sprinter H08 and IR6/IR7#2018-2022#1900#",//--Mercedes--5479
"Mercedes#Sprinter HK4 and IR4 CEILING MOUNTED AIR CONDITIONER#2018-2022#1100#",//--Mercedes--5483
"Mercedes#Sprinter HK4 and IR6/IR7 CEILING MOUNTED AIR CONDITIONER#2018-2022#1200#",//--Mercedes--5487
"Mercedes#Vaneo (414)#2002-2006#600#",//--Mercedes--5491
"Mercedes#Vario#1996-2013#1225#",//--Mercedes--5495
"Mercedes#Vito/V-Klasse Denso 7SB16#1996-2003#850#",//--Mercedes--5499
"Mercedes#Vito/V-Klasse Denso with rear a/c#1996-2003#1100#",//--Mercedes--5503
"Mercedes#Vito/V-Klasse Denso 10PA17C#1996-2003#920#",//--Mercedes--5507
"Mercedes#Vito/V-Klasse Sanden SD7V16#1996-2003#850#",//--Mercedes--5511
"Mercedes#Vito/Viano (W639)#2003-2014#550#",//--Mercedes--5515
"Mercedes#Vito/Viano (W639) with rear a/c#2003-2014#840#",//--Mercedes--5519
"Mercedes#Vito/Viano with rear a/c Long wheelbase#2003-2012#870#",//--Mercedes--5523
"Mercedes#Vito#2014-2022#600#",//--Mercedes--5527
"Mercedes#Vito with rear a/c#2014-2022#950#",//--Mercedes--5531
"Mercedes#X-CLASS#2017-2019#500#",//--Mercedes--5535
"Mercedes#X-CLASS 3.0 X350d 4Matic#2018-2020#1135#",//--Mercedes--5539
"MG Motor#Expres RHD#2003-2005#550#",//--5541-5591MG Motor--5543
"MG Motor#Expres LHD#2003-2005#630#",//--MG Motor--5547
"MG Motor#GS#2016-2019#560#",//--MG Motor--5551
"MG Motor#MG6#2011-2016#560#",//--MG Motor--5555
"MG Motor#TF#2002-2005#620#",//--MG Motor--5559
"MG Motor#TF 1,8 120 88kw(118hp)#2002-2005#720#",//--MG Motor--5563
"MG Motor#ZR RHD#2001-2005#550#",//--MG Motor--5567
"MG Motor#ZR LHD#2001-2005#630#",//--MG Motor--5571
"MG Motor#ZT / ZT-T / V8#2001-2005#450#",//--MG Motor--5575
"MG Motor#ZS RHD#2001-2005#560#",//--MG Motor--5579
"MG Motor#ZS 2,0 115 RHD#2001-2005#535#",//--MG Motor--5583
"MG Motor#ZS LHD#2001-2005#640#",//--MG Motor--5587
"MG Motor#ZS 2,0 115 LHD#2001-2005#610#",//--MG Motor--5591
"Mini Cooper#COUNTRYMAN#2017-2022#500#",//--5593-5623Mini Cooper--5595
"Mini Cooper#COUNTRYMAN 1.5 One D#2017-2022#550#",//--Mini Cooper--5599
"Mini Cooper#COUNTRYMAN 1,5 Cooper Hybrid#2017-2022#650#",//--Mini Cooper--5603
"Mini Cooper#Mini One/Cooper/Cooper S (R50/53)#2001-2009#415#",//--Mini Cooper--5607
"Mini Cooper#Mini/Mini Clubman/Mini Countryman#2007-2022#490#",//--Mini Cooper--5611
"Mini Cooper#Mini (R56/57, R55, R60)#2007-2018#490#",//--Mini Cooper--5615
"Mini Cooper#Mini Hatch Electric#2020-2022#550#",//--Mini Cooper--5619
"Mini Cooper#Mini Hatch 1.5/2.0#2020-2022#490#",//--Mini Cooper--5623
"Mitsubishi#3000 GT#1993-2000#765#",//--5625-5931Mitsubishi--5627
"Mitsubishi#380#2005-2008#455#",//--Mitsubishi--5631
"Mitsubishi#Attrage#2017-2018#290#",//--Mitsubishi--5635
"Mitsubishi#ASX#2008-2019#500#",//--Mitsubishi--5639
"Mitsubishi#Canter TD Large cabin#2006-2017#600#",//--Mitsubishi--5643
"Mitsubishi#Canter#2006-2017#650#",//--Mitsubishi--5647
"Mitsubishi#Carisma#1996-2005#700#",//--Mitsubishi--5651
"Mitsubishi#Challenger#1998-2005#625#",//--Mitsubishi--5655
"Mitsubishi#Challenger#2009-2013#650#",//--Mitsubishi--5659
"Mitsubishi#Challenger with rear a/c#2009-2013#875#",//--Mitsubishi--5663
"Mitsubishi#Colt/Lancer#1992-1996#590#",//--Mitsubishi--5667
"Mitsubishi#Colt/Lancer (CK/P) 1.3i/1.6i#1996-2003#575#",//--Mitsubishi--5671
"Mitsubishi#Colt (Z2/CZ/Z30)#2004-2015#430#",//--Mitsubishi--5675
"Mitsubishi#Eclipse (D3)#1996-2005#650#",//--Mitsubishi--5679
"Mitsubishi#Eclipse Cross#2017-2022#450#",//--Mitsubishi--5683
"Mitsubishi#Express Van#1994-2012#725#",//--Mitsubishi--5687
"Mitsubishi#Express Van with rear a/c#1994-2012#1225#",//--Mitsubishi--5691
"Mitsubishi#Galant#1993-1997#650#",//--Mitsubishi--5695
"Mitsubishi#Galant#1997-2000#690#",//--Mitsubishi--5699
"Mitsubishi#Galloper#1998-2002#780#",//--Mitsubishi--5703
"Mitsubishi#Galloper with rear a/c#1998-2002#1175#",//--Mitsubishi--5707
"Mitsubishi#Grandis#2004-2010#460#",//--Mitsubishi--5711
"Mitsubishi#Grandis with rear a/c#2004-2010#750#",//--Mitsubishi--5715
"Mitsubishi#i-MiEV#2010-2020#325#",//--Mitsubishi--5719
"Mitsubishi#Magna#1991-1996#775#",//--Mitsubishi--5723
"Mitsubishi#Magna#1997-2004#650#",//--Mitsubishi--5727
"Mitsubishi#Magna#2005-2006#675#",//--Mitsubishi--5731
"Mitsubishi#Mirage#2017-2018#290#",//--Mitsubishi--5735
"Mitsubishi#Montero#1994-2000#625#",//--Mitsubishi--5739
"Mitsubishi#Montero with rear a/c#1994-2000#1025#",//--Mitsubishi--5743
"Mitsubishi#Montero#2001-2018#550#",//--Mitsubishi--5747
"Mitsubishi#Montero with rear a/c#2001-2007#750#",//--Mitsubishi--5751
"Mitsubishi#Montero with rear a/c#2008-2018#870#",//--Mitsubishi--5755
"Mitsubishi#Montero Sport#2000-2008#625#",//--Mitsubishi--5759
"Mitsubishi#L200#1994-1997#720#",//--Mitsubishi--5763
"Mitsubishi#L200 2.4i/2.5D/2.5D Turbo#1997-2006#575#",//--Mitsubishi--5767
"Mitsubishi#L200 2.5D DI#2006-2015#555#",//--Mitsubishi--5771
"Mitsubishi#L200#2016-2022#520#",//--Mitsubishi--5775
"Mitsubishi#L300#1994-2004#725#",//--Mitsubishi--5779
"Mitsubishi#L300 with rear a/c#1994-2004#1225#",//--Mitsubishi--5783
"Mitsubishi#L400#1996-2005#650#",//--Mitsubishi--5787
"Mitsubishi#L400 with rear a/c#1996-2005#950#",//--Mitsubishi--5791
"Mitsubishi#Lancer Kombi Estate#1993-1997#700#",//--Mitsubishi--5795
"Mitsubishi#Lancer 1.3i/1.6i#2003-2008#500#",//--Mitsubishi--5799
"Mitsubishi#Lancer 2.0i/EVO VIII#2003-2008#500#",//--Mitsubishi--5803
"Mitsubishi#Lancer (CX/CY)#2008-2015#500#",//--Mitsubishi--5807
"Mitsubishi#Lancer#2016-2018#520#",//--Mitsubishi--5811
"Mitsubishi#Outlander#2003-2007#550#",//--Mitsubishi--5815
"Mitsubishi#Outlander II (CW/W)#2007-2015#500#",//--Mitsubishi--5819
"Mitsubishi#Outlander#2016-2022#450#",//--Mitsubishi--5823
"Mitsubishi#Outlander 2,0-2,4 PHEV Hybrid#2016-2022#540#",//--Mitsubishi--5827
"Mitsubishi#Pajero/Shogun#1994-2000#625#",//--Mitsubishi--5831
"Mitsubishi#Pajero/Shogun with rear a/c#1994-2000#1025#",//--Mitsubishi--5835
"Mitsubishi#Pajero/Shogun#2000-2007#500#",//--Mitsubishi--5839
"Mitsubishi#Pajero/Shogun with rear a/c#2000-2003#790#",//--Mitsubishi--5843
"Mitsubishi#Pajero/Shogun Sport#2000-2007#625#",//--Mitsubishi--5847
"Mitsubishi#Pajero/Shogun Pinin LHD#1999-2005#620#",//--Mitsubishi--5851
"Mitsubishi#Pajero/Shogun Pinin RHD#1999-2005#570#",//--Mitsubishi--5855
"Mitsubishi#Pajero IV (V80)#2007-2018#550#",//--Mitsubishi--5859
"Mitsubishi#Pajero IV (V80) with rear a/c#2007-2018#870#",//--Mitsubishi--5863
"Mitsubishi#Santamo#1999-2006#730#",//--Mitsubishi--5867
"Mitsubishi#SHOGUN#2007-2018#550#",//--Mitsubishi--5871
"Mitsubishi#SHOGUN with rear a/c#2007-2018#870#",//--Mitsubishi--5875
"Mitsubishi#Sigma#1990-1996#765#",//--Mitsubishi--5879
"Mitsubishi#Star Wagon#1994-2004#650#",//--Mitsubishi--5883
"Mitsubishi#Star Wagon with rear a/c#1994-2004#950#",//--Mitsubishi--5887
"Mitsubishi#Space Gear#1995-2005#650#",//--Mitsubishi--5891
"Mitsubishi#Space Gear with rear a/c#1995-2005#975#",//--Mitsubishi--5895
"Mitsubishi#Space Runner/Wagon#1993-1998#720#",//--Mitsubishi--5899
"Mitsubishi#Space Runner/Wagon#1999-1999#550#",//--Mitsubishi--5903
"Mitsubishi#Space Runner/Wagon 2.0 Dizel#1993-1998#720#",//--Mitsubishi--5907
"Mitsubishi#Space Runner (N50)#1999-2004#550#",//--Mitsubishi--5911
"Mitsubishi#Space Star#1998-2006#680#",//--Mitsubishi--5915
"Mitsubishi#Triton#1997-2007#575#",//--Mitsubishi--5919
"Mitsubishi#Triton Crewcab#2006-2015#555#",//--Mitsubishi--5923
"Mitsubishi#Triton Normal cabin#2006-2015#500#",//--Mitsubishi--5927
"Mitsubishi#Verada#1996-2006#670#",//--Mitsubishi--5931
"Nissan#200SX (S14)#1994-2003#700#",//--5933-6339Nissan--5935
"Nissan#300ZX (Z32)#1994-1995#600#",//--Nissan--5939
"Nissan#370Z (Z34)#2009-2022#500#",//--Nissan--5943
"Nissan#Almera (N15) RHD#1995-2000#500#",//--Nissan--5947
"Nissan#Almera (N15) LHD#1995-2000#650#",//--Nissan--5951
"Nissan#Almera (N16)#2000-2006#500#",//--Nissan--5955
"Nissan#Almera Tino V10#2000-2006#500#",//--Nissan--5959
"Nissan#Cabstar (F23)#1994-2000#650#",//--Nissan--5963
"Nissan#Cabstar 3.0Di (TLO)#2004-2007#750#",//--Nissan--5967
"Nissan#Cabstar (F24) 2.5D/ 3.0D#2006-2015#300#",//--Nissan--5971
"Nissan#Cube#2009-2011#450#",//--Nissan--5975
"Nissan#Dualis#2007-2012#450#",//--Nissan--5979
"Nissan#Evalia#2009-2022#450#",//--Nissan--5983
"Nissan#Evalia with rear a/c#2009-2019#650#",//--Nissan--5987
"Nissan#GT-R 3,8 Nismo#2011-2022#500#",//--Nissan--5991
"Nissan#Interstar (X70) 1.9D/2.2D/2.5D/3.0D#2003-2006#850#",//--Nissan--5995
"Nissan#Interstar 7-seat with rear a/c#2003-2006#1300#",//--Nissan--5999
"Nissan#Interstar 16-seat with rear a/c#2003-2006#1400#",//--Nissan--6003
"Nissan#Interstar (X70) 2.5DdCi#2006-2015#750#",//--Nissan--6007
"Nissan#Interstar(X70)2.5DdCi9K with rear a/c#2006-2015#1300#",//--Nissan--6011
"Nissan#Interstar(X70)2.5DdCi16K with rear a/c#2006-2015#1400#",//--Nissan--6015
"Nissan#Juke#2010-2022#450#",//--Nissan--6019
"Nissan#Kubistar (X76) 1.2i/1.2i 16V#2003-2008#660#",//--Nissan--6023
"Nissan#Kubistar (X76) 1.5DdCi/1.6i#2003-2008#660#",//--Nissan--6027
"Nissan#Leaf#2010-2020#425#",//--Nissan--6031
"Nissan#Leaf Denso ESB27 COMP.#2019-2020#850#",//--Nissan--6035
"Nissan#Maxima QX (A32)#1994-2000#650#",//--Nissan--6039
"Nissan#Maxima QX (A33) 2.0V6/3.0V6#2000-2004#650#",//--Nissan--6043
"Nissan#Micra (K11)#1994-2000#450#",//--Nissan--6047
"Nissan#Micra (K11)#2000-2003#500#",//--Nissan--6051
"Nissan#Micra (K12) 1.0i/1.2i/1.4i#2003-2015#475#",//--Nissan--6055
"Nissan#Micra (K12) 1.5dCi#2003-2015#550#",//--Nissan--6059
"Nissan#Micra (K12) 1.6i#2005-2015#550#",//--Nissan--6063
"Nissan#Micra (K13) 1.2i#2010-2015#400#",//--Nissan--6067
"Nissan#Micra C+C (K12) 1.4i#2005-2015#500#",//--Nissan--6071
"Nissan#Micra C+C (K12) 1.6i#2005-2015#450#",//--Nissan--6075
"Nissan#Micra (K14)#2016-2022#435#",//--Nissan--6079
"Nissan#Murano (Z52) 3.5i#2016-2022#550#",//--Nissan--6083
"Nissan#Murano (Z51) 3.5i/2.5DdCi#2008-2015#600#",//--Nissan--6087
"Nissan#Navara (D40) 2.5DdCi manuel A/C#2005-2015#1080#",//--Nissan--6091
"Nissan#Navara (D40)#2005-2015#700#",//--Nissan--6095
"Nissan#Navara (D40) 2.5DdCi with rear a/c#2005-2015#850#",//--Nissan--6099
"Nissan#Navara 2,3D dci#2016-2020#500#",//--Nissan--6103
"Nissan#Note 1.4i#2007-2015#475#",//--Nissan--6107
"Nissan#Note 1.6i#2006-2015#475#",//--Nissan--6111
"Nissan#Note 1.5DdCi#2006-2013#550#",//--Nissan--6115
"Nissan#NP300#2008-2013#600#",//--Nissan--6119
"Nissan#NP300 NAVARA#2014-2022#500#",//--Nissan--6123
"Nissan#NT400 Cabstar#2008-2018#300#",//--Nissan--6127
"Nissan#NV200 (M20) 1.6i#2010-2018#450#",//--Nissan--6131
"Nissan#NV200 (M20) 1.6i with rear a/c#2010-2018#650#",//--Nissan--6135
"Nissan#NV200 (M20) 1.5DdCi#2010-2018#450#",//--Nissan--6139
"Nissan#NV200 (M20) 1.5DdCi with rear a/c#2010-2018#650#",//--Nissan--6143
"Nissan#NV300#2016-2022#590#",//--Nissan--6147
"Nissan#NV300 with rear a/c#2016-2022#880#",//--Nissan--6151
"Nissan#NV400 2,3 CDTI#2011-2019#580#",//--Nissan--6155
"Nissan#NV400 2,3 CDTI 9 seat#2016-2019#1100#",//--Nissan--6159
"Nissan#NV400 2,3 CDTI 16 seat#2016-2019#1700#",//--Nissan--6163
"Nissan#Pathfinder (R51) 4.0i/2.5D dCi#2004-2015#700#",//--Nissan--6167
"Nissan#Pathfinder with rear a/c#2004-2015#850#",//--Nissan--6171
"Nissan#Patrol GR (Y60)#1994-1998#600#",//--Nissan--6175
"Nissan#Patrol (Y61) 2.8D/3.0D#1998-2008#800#",//--Nissan--6179
"Nissan#Pick-up (D21)#1992-1998#800#",//--Nissan--6183
"Nissan#Pick-up (D22)#1998-2002#550#",//--Nissan--6187
"Nissan#Pick-up/Navara (D22) 2.5Di#2002-2007#600#",//--Nissan--6191
"Nissan#Pick-up/Navara (D22) 2.4i#2002-2007#650#",//--Nissan--6195
"Nissan#Pixo#2009-2015#370#",//--Nissan--6199
"Nissan#Primera (P10)#1993-1996#750#",//--Nissan--6203
"Nissan#Primera (W10)#1993-1996#600#",//--Nissan--6207
"Nissan#Primera (P11)#1996-1999#600#",//--Nissan--6211
"Nissan#Primera 1.6/2.0 D Turbo (P11-144)#1999-2002#600#",//--Nissan--6215
"Nissan#Primera 1.8/2.0 (P11-144)#1999-2002#600#",//--Nissan--6219
"Nissan#Primera (P12)#2002-2007#500#",//--Nissan--6223
"Nissan#Primastar (X83) 1.9D dCi#2002-2006#700#",//--Nissan--6227
"Nissan#Primastar 2.0i/2.0D dCi/2.5DdCi#2006-2015#750#",//--Nissan--6231
"Nissan#Primastar with rear a/c#2006-2015#1050#",//--Nissan--6235
"Nissan#Pulsar#1995-2000#500#",//--Nissan--6239
"Nissan#Pulsar#2000-2006#450#",//--Nissan--6243
"Nissan#Qashqai/Qashqai +2#2007-2015#450#",//--Nissan--6247
"Nissan#Qashqai#2015-2022#500#",//--Nissan--6251
"Nissan#QX#1994-2000#650#",//--Nissan--6255
"Nissan#Serena/Vanette Cargo RHD#1992-1996#650#",//--Nissan--6259
"Nissan#Serena/Vanette Cargo RHD with rear a/c#1992-1996#775#",//--Nissan--6263
"Nissan#Serena/Vanette Cargo LHD#1992-1996#675#",//--Nissan--6267
"Nissan#Serena/Vanette Cargo LHD with rear a/c#1992-1996#725#",//--Nissan--6271
"Nissan#Serena/Vanette Cargo RHD#1996-2003#600#",//--Nissan--6275
"Nissan#Serena/Vanette Cargo RHD with rear a/c#1996-2003#725#",//--Nissan--6279
"Nissan#Serena/Vanette Cargo LHD#1996-2003#625#",//--Nissan--6283
"Nissan#Serena/Vanette Cargo LHD with rear a/c#1996-2003#675#",//--Nissan--6287
"Nissan#Sunny (N14/B13)#1992-1995#750#",//--Nissan--6291
"Nissan#Sunny estate/van (Y10)#1992-1994#750#",//--Nissan--6295
"Nissan#Sunny estate/van (Y10)#1994-1996#700#",//--Nissan--6299
"Nissan#Terrano II (R20)#1993-2008#750#",//--Nissan--6303
"Nissan#Tiida 1.6i/1.8i#2007-2011#450#",//--Nissan--6307
"Nissan#Tiida 1.5DdCi#2007-2011#450#",//--Nissan--6311
"Nissan#Urvan (E24)#1994-1996#950#",//--Nissan--6315
"Nissan#Urvan with rear a/c#1994-1996#1200#",//--Nissan--6319
"Nissan#Vanette Cargo (C23H) 2.3D#1996-2001#600#",//--Nissan--6323
"Nissan#Vanette Cargo with rear a/c#1996-2001#700#",//--Nissan--6327
"Nissan#X-Trail 2.0i/2.5i/2.2Di/2.2DdCi#2001-2007#500#",//--Nissan--6331
"Nissan#X-Trail (T31) 2.0i/2.5i/2.0DdCi#2007-2015#450#",//--Nissan--6335
"Nissan#X-Trail#2016-2022#500#",//--Nissan--6339
"Opel#Adam#2013-2015#450#",//--6341-6859Opel--6343
"Opel#Adam#2016-2019#420#",//--Opel--6347
"Opel#Agila (HOO) 1.1i/1.2i/1.3DCDTi#2000-2008#500#",//--Opel--6351
"Opel#Agila 1.0i/1.2i#2008-2015#370#",//--Opel--6355
"Opel#Agila 1.3DCDTi#2008-2015#370#",//--Opel--6359
"Opel#Ampera#2011-2015#950#",//--Opel--6363
"Opel#Antara LHD 2.0D/2.2D#2006-2015#520#",//--Opel--6367
"Opel#Antara LHD 2.4i/3.0i/3.2i#2006-2015#660#",//--Opel--6371
"Opel#Antara 2,0 CDTI#2016-2018#650#",//--Opel--6375
"Opel#Astra F#1991-1994#700#",//--Opel--6379
"Opel#Astra F#1994-1998#900#",//--Opel--6383
"Opel#Astra G Z16XE+YNG/Y17DT/Z17DTL/X20#1998-2001#700#",//--Opel--6387
"Opel#Astra G Y20DTL/Y20DTH+22DTR/Z22SE#1998-2001#700#",//--Opel--6391
"Opel#Astra G Z16XE+YNG/Y17DT/Z17DTL/X20#2002-2005#600#",//--Opel--6395
"Opel#Astra G Y20DTL/Y20DTH+22DTR/Z22SE#2002-2005#600#",//--Opel--6399
"Opel#Astra G Z20LET#2000-2005#700#",//--Opel--6403
"Opel#Astra G butun diger motorlar#1998-2001#700#",//--Opel--6407
"Opel#Astra G butun diger motorlar#2002-2005#600#",//--Opel--6411
"Opel#Astra H Z14XEL/Z14XEP/Z16XEP/Z18XE#2004-2006#475#",//--Opel--6415
"Opel#Astra H Z14XEL/Z14XEP/Z16XEP/Z18XE#2006-2015#450#",//--Opel--6419
"Opel#Astra H Z20LEL#2004-2009#500#",//--Opel--6423
"Opel#Astra H Z20LER#2004-2006#500#",//--Opel--6427
"Opel#Astra H Z20LER#2006-2015#475#",//--Opel--6431
"Opel#Astra H Z20LEH#2005-2015#450#",//--Opel--6435
"Opel#Astra H Z17DTH/Z17DTL#2004-2006#500#",//--Opel--6439
"Opel#Astra H Z17DTH/Z17DTL#2006-2015#475#",//--Opel--6443
"Opel#Astra H Z19DTH/Z19DT#2004-2006#475#",//--Opel--6447
"Opel#Astra H Z19DTH/Z19DT#2006-2015#450#",//--Opel--6451
"Opel#Astra J A14XER/A16XER/A13DTH/A17DTR#2010-2017#600#",//--Opel--6455
"Opel#Astra J A14NET/A16LET stick shift#2010-2017#600#",//--Opel--6459
"Opel#Astra J A14NET/A16LET automatic shift#2010-2017#630#",//--Opel--6463
"Opel#Astra J A20DTH#2010-2017#630#",//--Opel--6467
"Opel#Astra J Calibra (7*)#1993-1997#750#",//--Opel--6471
"Opel#Astra J Calibra (8*)#1994-1997#1000#",//--Opel--6475
"Opel#Astra J Campo-Brava Dizel#1994-2003#750#",//--Opel--6479
"Opel#Astra J Cascada A14NET/A16XHT#2013-2016#600#",//--Opel--6483
"Opel#Astra J Cascada A20DTH/A20DTR#2013-2016#630#",//--Opel--6487
"Opel#Astra K#2015-2019#520#",//--Opel--6491
"Opel#Brava#1993-2003#650#",//--Opel--6495
"Opel#Cavalier/Vectra-A (7*)#1993-1995#750#",//--Opel--6499
"Opel#Cavalier/Vectra-A (8*)#1994-1995#1000#",//--Opel--6503
"Opel#Combo C Z13DT/Y17DT/Z17DTH#2001-2015#560#",//--Opel--6507
"Opel#Combo C Z14XEP/Z16SE/Z12XEP#2001-2015#650#",//--Opel--6511
"Opel#Combo C Y17DTL#2001-2003#650#",//--Opel--6515
"Opel#Combo C Y17DTL#2004-2015#560#",//--Opel--6519
"Opel#Combo D (X12)#2012-2018#450#",//--Opel--6523
"Opel#Combo E 1930cm3 Condanser#2018-2022#470#",//--Opel--6527
"Opel#Combo E 2350cm3 Condanser#2018-2022#600#",//--Opel--6531
"Opel#Corsa B/Combo#1993-2000#900#",//--Opel--6535
"Opel#Corsa C Z10XE/Z10XEP/Z12XE/Z12XEP#2000-2007#650#",//--Opel--6539
"Opel#Corsa C Z14XE/Z14XEP/Z16SE/Z18XE#2000-2007#650#",//--Opel--6543
"Opel#Corsa C Z13DT/Y17DT/Y17DTH#2000-2007#560#",//--Opel--6547
"Opel#Corsa C Y17DTL 2003 until#2000-2003#650#",//--Opel--6551
"Opel#Corsa C Y17DTL 2004 upwards#2003-2007#560#",//--Opel--6555
"Opel#Corsa D#2007-2015#470#",//--Opel--6559
"Opel#Corsa D#2016-2018#450#",//--Opel--6563
"Opel#Corsa E 1,3 CDTI-1,6VXR-1,4 TURBO#2015-2018#420#",//--Opel--6567
"Opel#Corsa E#2015-2018#450#",//--Opel--6571
"Opel#Corsa E#2019-2020#420#",//--Opel--6575
"Opel#Corsa F#2019-2022#370#",//--Opel--6579
"Opel#Corsa F 1.2 Turbo/1.5D#2019-2022#390#",//--Opel--6583
"Opel#CROSLAND X#2017-2022#425#",//--Opel--6587
"Opel#CROSLAND X Additional heater#2017-2022#460#",//--Opel--6591
"Opel#Frontera A#1991-1995#800#",//--Opel--6595
"Opel#Frontera A#1995-1996#750#",//--Opel--6599
"Opel#Frontera A Dizel#1995-1996#700#",//--Opel--6603
"Opel#Frontera A#1996-1998#650#",//--Opel--6607
"Opel#Frontera B#1998-2003#650#",//--Opel--6611
"Opel#GT#2006-2009#470#",//--Opel--6615
"Opel#GTC#2015-2018#600#",//--Opel--6619
"Opel#GTC 1,6D - 1,6 SIDI#2015-2018#630#",//--Opel--6623
"Opel#GRANDLAND X#2017-2022#575#",//--Opel--6627
"Opel#Insignia#2008-2016#600#",//--Opel--6631
"Opel#Insignia B#2017-2020#580#",//--Opel--6635
"Opel#Meriva#2004-2010#650#",//--Opel--6639
"Opel#Meriva Z16SE/Z16+Z18XE/Z16LET#2004-2010#690#",//--Opel--6643
"Opel#Meriva B#2010-2015#580#",//--Opel--6647
"Opel#Mokka#2012-2020#570#",//--Opel--6651
"Opel#Monterey#1994-1998#750#",//--Opel--6655
"Opel#Monterey Dizel#1994-1998#750#",//--Opel--6659
"Opel#Monterey 3.0D Turbo/3.5i#1998-2001#750#",//--Opel--6663
"Opel#Movano 2.5D/2.8D turbo#1998-2003#850#",//--Opel--6667
"Opel#Movano 1.9D DTI/2.2D DTI/2.5D DTI#2000-2003#850#",//--Opel--6671
"Opel#Movano dizel#2003-2006#850#",//--Opel--6675
"Opel#Movano dizel 7-seat with rear a/c#2003-2006#1300#",//--Opel--6679
"Opel#Movano dizel 16-seat with rear a/c#2003-2006#1400#",//--Opel--6683
"Opel#Movano 2.5DCDTi#2006-2015#750#",//--Opel--6687
"Opel#Movano 2.5DCDTi 9-seat with rear a/c#2006-2015#1300#",//--Opel--6691
"Opel#Movano 2.5DCDTi 16-seat with rear a/c#2006-2015#1400#",//--Opel--6695
"Opel#Movano B#2010-2015#600#",//--Opel--6699
"Opel#Movano B with rear a/c#2010-2015#1700#",//--Opel--6703
"Opel#Movano B#2016-2019#580#",//--Opel--6707
"Opel#Movano B with rear a/c#2016-2019#1100#",//--Opel--6711
"Opel#Omega B#1994-2003#950#",//--Opel--6715
"Opel#Omega 2.0 Dizel#1998-2000#950#",//--Opel--6719
"Opel#Omega 2.5 Turbo Dizel#1994-2003#950#",//--Opel--6723
"Opel#Signum 1,9 CDTI#2003-2008#730#",//--Opel--6727
"Opel#Signum 3,0 CDTI#2003-2006#680#",//--Opel--6731
"Opel#Signum 2,8 CDTI / 3,0 CDTI#2006-2008#660#",//--Opel--6735
"Opel#Sintra#1996-1999#910#",//--Opel--6739
"Opel#Tigra#1995-2003#900#",//--Opel--6743
"Opel#Tigra B Z14XEP/Z18XE#2004-2010#650#",//--Opel--6747
"Opel#Tigra B Z13DT#2004-2010#560#",//--Opel--6751
"Opel#Vectra B#1995-2002#925#",//--Opel--6755
"Opel#Vectra B 2.5#1995-2000#925#",//--Opel--6759
"Opel#Vectra 1.7 Turbo Dizel#1995-1996#925#",//--Opel--6763
"Opel#Vectra 2.0 Turbo dizel X20DTH#1997-2002#750#",//--Opel--6767
"Opel#Vectra C Z16XE/Z18XE/Z32SE/Z20NET#2002-2008#730#",//--Opel--6771
"Opel#Vectra C Z22SE/Z22YH/Y20DTH/Y22DTR#2002-2008#730#",//--Opel--6775
"Opel#Vectra C Z19DT/Z19DTH#2002-2008#730#",//--Opel--6779
"Opel#Vectra C Y30DT#2002-2005#680#",//--Opel--6783
"Opel#Vivaro 1.9DDi/1.9DDTi/2.0i/2.5DCDTi#2001-2012#725#",//--Opel--6787
"Opel#Vivaro 1.9DDi/1.9DDTi with rear a/c#2001-2012#1100#",//--Opel--6791
"Opel#Vivaro 2.0CDTi#2006-2015#650#",//--Opel--6795
"Opel#Vivaro 2.0CDTi with rear a/c#2006-2015#950#",//--Opel--6799
"Opel#Vivaro#2016-2019#590#",//--Opel--6803
"Opel#Vivaro Bluinjection#2019-2022#500#",//--Opel--6807
"Opel#Vivaro Electric#2020-2022#575#",//--Opel--6811
"Opel#Zafira (F75)#1998-2001#700#",//--Opel--6815
"Opel#Zafira (F75) with rear a/c#1998-2001#950#",//--Opel--6819
"Opel#Zafira (F75)#2002-2005#600#",//--Opel--6823
"Opel#Zafira (F75) with rear a/c#2002-2005#725#",//--Opel--6827
"Opel#Zafira (F75) Z20LET#2002-2005#700#",//--Opel--6831
"Opel#Zafira B Z16XEP/Z18XER/Z22YH/Z16XE1#2006-2015#450#",//--Opel--6835
"Opel#Zafira B Z19DT/Z19DTL/Z19DTH/Z13DTH#2006-2015#450#",//--Opel--6839
"Opel#Zafira B Z20LER/Z20LEH/Z20LEL#2006-2015#450#",//--Opel--6843
"Opel#Zafira C (P12)#2011-2019#590#",//--Opel--6847
"Opel#Zafira C (P12) A18XER/A18XFR/A18XEL#2011-2018#600#",//--Opel--6851
"Opel#Zafira Life Bluinjection#2019-2022#975#",//--Opel--6855
"Opel#Zafira Life 2.0 Bluinjection#2019-2022#475#",//--Opel--6859
"Perodua#Kelisa 1.3i#2002-2009#330#",//--6861-6875Perodua--6863
"Perodua#Kenari 1.0#2000-2011#330#",//--Perodua--6867
"Perodua#Myvi 1.3i#2006-2015#330#",//--Perodua--6871
"Perodua#Nippa 1.0#1997-2002#330#",//--Perodua--6875
"Peugeot#106#1994-1996#875#",//--6877-7307Peugeot--6879
"Peugeot#106 II#1996-2003#825#",//--Peugeot--6883
"Peugeot#106 II Dizel/1.6 GTI#1996-2003#750#",//--Peugeot--6887
"Peugeot#107 1.4 HDi#2005-2012#500#",//--Peugeot--6891
"Peugeot#107 1.0i#2005-2012#450#",//--Peugeot--6895
"Peugeot#108#2014-2020#400#",//--Peugeot--6899
"Peugeot#205#1993-1998#675#",//--Peugeot--6903
"Peugeot#206#1998-2007#700#",//--Peugeot--6907
"Peugeot#206 2.0i/1.6D HDi#1999-2007#650#",//--Peugeot--6911
"Peugeot#206 CC 1.6i#2000-2007#700#",//--Peugeot--6915
"Peugeot#206 CC 2.0i/1.6D HDi#2000-2007#650#",//--Peugeot--6919
"Peugeot#206+ (T3E) 1.4i#2009-2015#700#",//--Peugeot--6923
"Peugeot#207 1.4i/1.6i/1.4D HDI/#2006-2015#450#",//--Peugeot--6927
"Peugeot#207 1.6D HDi/1.4+1.6VTi#2006-2015#450#",//--Peugeot--6931
"Peugeot#207 CC 1.6THP/1.6VTi/ 1.6DHDi#2007-2015#450#",//--Peugeot--6935
"Peugeot#207+#2012-2014#425#",//--Peugeot--6939
"Peugeot#208#2014-2019#450#",//--Peugeot--6943
"Peugeot#208  1600cm2X12mm#2019-2022#425#",//--Peugeot--6947
"Peugeot#208  1600cm2X16mm#2019-2022#475#",//--Peugeot--6951
"Peugeot#208  2000cm2X12mm Slovakia#2019-2022#450#",//--Peugeot--6955
"Peugeot#208  2000cm2X12mm Morocco#2019-2022#390#",//--Peugeot--6959
"Peugeot#208  2000cm2X16mm#2019-2022#500#",//--Peugeot--6963
"Peugeot#301#2014-2018#425#",//--Peugeot--6967
"Peugeot#307 1.4i/1.6i/2.0i/1.4HDi/2.0HDi#2001-2004#585#",//--Peugeot--6971
"Peugeot#307 1.4i/1.6i/2.0i1.4HDi/2.0HDi#2004-2015#450#",//--Peugeot--6975
"Peugeot#307 1.6HDi#2004-2004#585#",//--Peugeot--6979
"Peugeot#307/307CC 1.6HDi#2004-2015#450#",//--Peugeot--6983
"Peugeot#307 1.4i 16V#2004-2015#450#",//--Peugeot--6987
"Peugeot#306#1993-1997#900#",//--Peugeot--6991
"Peugeot#306#1997-2003#725#",//--Peugeot--6995
"Peugeot#308/308 CC 1.4VTi/1.6VTi/1.6THP#2007-2015#450#",//--Peugeot--6999
"Peugeot#308/308 CC 1.6HDi/2.0HDi#2007-2015#450#",//--Peugeot--7003
"Peugeot#308 (1930cm condanser)#2013-2022#450#",//--Peugeot--7007
"Peugeot#308 (2350cm 12mm condanser)#2013-2022#575#",//--Peugeot--7011
"Peugeot#308 (2350cm 16mm condanser)#2013-2022#575#",//--Peugeot--7015
"Peugeot#405 II#1993-1997#675#",//--Peugeot--7019
"Peugeot#406 Delphi komp#1995-1999#750#",//--Peugeot--7023
"Peugeot#406 Sanden komp#1995-1999#800#",//--Peugeot--7027
"Peugeot#406 V6#1997-1999#750#",//--Peugeot--7031
"Peugeot#406 1.6/1.8/2.0 XU#1999-2004#775#",//--Peugeot--7035
"Peugeot#406 2.0 EW10#1999-2004#620#",//--Peugeot--7039
"Peugeot#406 3.0i#1999-2004#750#",//--Peugeot--7043
"Peugeot#406 2.2 HDI#1999-2004#620#",//--Peugeot--7047
"Peugeot#407 1.8i/2.0i/2.2i/3.0i/1.6HDi2.0HDi#2004-2012#625#",//--Peugeot--7051
"Peugeot#407 2.2HDi/2.7HDi/3.0HDi#2004-2012#525#",//--Peugeot--7055
"Peugeot#508#2011-2018#525#",//--Peugeot--7059
"Peugeot#508 (1900cm 12mm condanser)#2018-2022#450#",//--Peugeot--7063
"Peugeot#508 (2300cm 16mm condanser)#2018-2022#450#",//--Peugeot--7067
"Peugeot#508 (2800cm 16mm condanser)#2018-2022#625#",//--Peugeot--7071
"Peugeot#508 Hybrid#2020-2022#725#",//--Peugeot--7075
"Peugeot#605 2.5D Turbo#1995-1999#850#",//--Peugeot--7079
"Peugeot#605 V6 ESJ#1997-1999#875#",//--Peugeot--7083
"Peugeot#605#1994-1999#885#",//--Peugeot--7087
"Peugeot#607#2000-2005#625#",//--Peugeot--7091
"Peugeot#607 (Facelift)#2005-2015#550#",//--Peugeot--7095
"Peugeot#607 (Facelift) 2.7HDi (DT17)#2005-2015#600#",//--Peugeot--7099
"Peugeot#806#1994-2002#960#",//--Peugeot--7103
"Peugeot#807 2.0i/2.2i/3.0i/2.2DHDi#2002-2010#640#",//--Peugeot--7107
"Peugeot#807 2.0DHDi#2002-2010#540#",//--Peugeot--7111
"Peugeot#1007#2005-2015#600#",//--Peugeot--7115
"Peugeot#2008#2013-2022#450#",//--Peugeot--7119
"Peugeot#3008 (1.6HDi/2.0HDi)#2009-2015#450#",//--Peugeot--7123
"Peugeot#3008 (1900cm condanser)#2009-2015#575#",//--Peugeot--7127
"Peugeot#3008 (2300cm condanser)#2016-2022#575#",//--Peugeot--7131
"Peugeot#3008 Hybrid#2019-2022#725#",//--Peugeot--7135
"Peugeot#4007#2007-2015#500#",//--Peugeot--7139
"Peugeot#5008 (1.6THP/1.6VTi)#2009-2015#450#",//--Peugeot--7143
"Peugeot#5008 (1.6HDi/2.0HDi)#2009-2015#450#",//--Peugeot--7147
"Peugeot#5008 (1900cm condanser)#2016-2022#575#",//--Peugeot--7151
"Peugeot#5008 (2300cm condanser)#2016-2022#575#",//--Peugeot--7155
"Peugeot#Bipper#2008-2018#500#",//--Peugeot--7159
"Peugeot#Boxer#1994-1996#1000#",//--Peugeot--7163
"Peugeot#Boxer with rear a/c#1994-1996#1200#",//--Peugeot--7167
"Peugeot#Boxer#1996-2002#800#",//--Peugeot--7171
"Peugeot#Boxer with rear a/c#1996-2002#1000#",//--Peugeot--7175
"Peugeot#Boxer II (244)#2002-2006#800#",//--Peugeot--7179
"Peugeot#Boxer III 2.2HDi/3.0HDi#2006-2022#550#",//--Peugeot--7183
"Peugeot#Boxer III with rear a/c#2006-2022#950#",//--Peugeot--7187
"Peugeot#Boxer III Minibus#2015-2022#2600#",//--Peugeot--7191
"Peugeot#Expert#1995-2007#960#",//--Peugeot--7195
"Peugeot#Expert 2.0i/1.6HDi/2.0HDi#2007-2015#675#",//--Peugeot--7199
"Peugeot#Expert with rear a/c short wheelbase#2007-2015#950#",//--Peugeot--7203
"Peugeot#Expert with rear a/c Long wheelbase#2007-2015#1075#",//--Peugeot--7207
"Peugeot#Expert IV#2016-2022#500#",//--Peugeot--7211
"Peugeot#e-Expert IV Electric#2020-2022#575#",//--Peugeot--7215
"Peugeot#e-208#2019-2022#985#",//--Peugeot--7219
"Peugeot#e-2008#2020-2022#985#",//--Peugeot--7223
"Peugeot#Ion Electric (POE oil)#2013-2020#325#",//--Peugeot--7227
"Peugeot#Partner 1.1/1.4/1.6 karburatör#1996-2000#875#",//--Peugeot--7231
"Peugeot#Partner 1.1i/1.4i/1.6i#1996-2005#875#",//--Peugeot--7235
"Peugeot#Partner 1.8i/1.8D/1.9D (XUD)/2.0HDi#1996-2005#725#",//--Peugeot--7239
"Peugeot#Partner 1.9D (DW8)#1996-2005#775#",//--Peugeot--7243
"Peugeot#Partner Facelift#2005-2008#575#",//--Peugeot--7247
"Peugeot#Partner III 1.6i/1.6HDi#2008-2018#450#",//--Peugeot--7251
"Peugeot#Partner III#2013-2020#525#",//--Peugeot--7255
"Peugeot#Partner IV 12mm condanser#2018-2022#470#",//--Peugeot--7259
"Peugeot#Partner IV 16mm condanser#2018-2022#600#",//--Peugeot--7263
"Peugeot#RCZ 1.6THP/2.0HDi#2010-2015#425#",//--Peugeot--7267
"Peugeot#Ranch I Benzin#1996-2002#875#",//--Peugeot--7271
"Peugeot#Ranch I Diesel#1996-2002#775#",//--Peugeot--7275
"Peugeot#Ranch II#2003-2011#575#",//--Peugeot--7279
"Peugeot#Rifter 12mm condanser#2018-2022#470#",//--Peugeot--7283
"Peugeot#Rifter 16mm condanser#2018-2022#600#",//--Peugeot--7287
"Peugeot#ION Hybrid#2010-2018#325#",//--Peugeot--7291
"Peugeot#Traveller#2016-2022#475#",//--Peugeot--7295
"Peugeot#Traveller 2.0#2016-2020#475#",//--Peugeot--7299
"Peugeot#Traveller 1.5/1.6 BlueHDI Dual Zone#2016-2022#975#",//--Peugeot--7303
"Peugeot#Traveller 2.0 Dual Zone#2016-2022#775#",//--Peugeot--7307
"Porsche#718 Boxster-Cayman#2016-2020#900#",//--7309-7411Porsche--7311
"Porsche#911 (993)#1993-1997#840#",//--Porsche--7315
"Porsche#911 (996)#1998-2007#900#",//--Porsche--7319
"Porsche#911 (997)#2005-2015#850#",//--Porsche--7323
"Porsche#911 (991)#2011-2015#900#",//--Porsche--7327
"Porsche#911 4,0 GT3 RS#2015-2017#900#",//--Porsche--7331
"Porsche#911#2015-2018#950#",//--Porsche--7335
"Porsche#968#1993-1996#860#",//--Porsche--7339
"Porsche#Boxster (986)#1996-2004#850#",//--Porsche--7343
"Porsche#Boxster (987)#2005-2012#900#",//--Porsche--7347
"Porsche#Boxster (981)#2013-2016#850#",//--Porsche--7351
"Porsche#Carrera GT 5.7#2003-2007#600#",//--Porsche--7355
"Porsche#Cayenne (92A)#2010-2018#850#",//--Porsche--7359
"Porsche#Cayenne (92A) A/C with rear#2010-2018#1100#",//--Porsche--7363
"Porsche#Cayenne#2017-2020#700#",//--Porsche--7367
"Porsche#Cayenne  A/C with rear#2017-2020#950#",//--Porsche--7371
"Porsche#Cayenne Hybrid S (92A)#2010-2016#850#",//--Porsche--7375
"Porsche#Cayenne (955) 3.2/S4.5/Turbo4.5#2002-2007#700#",//--Porsche--7379
"Porsche#Cayenne A/C with rear#2002-2007#1050#",//--Porsche--7383
"Porsche#Cayman#2006-2018#850#",//--Porsche--7387
"Porsche#Macan 2.0#2014-2019#575#",//--Porsche--7391
"Porsche#Macan#2014-2019#560#",//--Porsche--7395
"Porsche#Panamera (970)#2009-2018#580#",//--Porsche--7399
"Porsche#Panamera (970) SE-H#2013-2015#850#",//--Porsche--7403
"Porsche#Panamera E-Hybrid#2016-2020#700#",//--Porsche--7407
"Porsche#Panamera#2016-2018#540#",//--Porsche--7411
"Proton#413#1995-2001#550#",//--7413-7435Proton--7415
"Proton#420#1996-2001#550#",//--Proton--7419
"Proton#Gen-2 1.3i/1.6i#2004-2015#600#",//--Proton--7423
"Proton#Impian/Waja 1.6i#2001-2007#575#",//--Proton--7427
"Proton#Satria Neo 1.3i/1.6i#2006-2015#550#",//--Proton--7431
"Proton#Savvy 1.2i#2005-2015#500#",//--Proton--7435
"Renault#Arkana#2019-2022#480#",//--7437-7887Renault--7439
"Renault#Avantime 2.0i Turbo#2000-2004#880#",//--Renault--7443
"Renault#Avantime 3.0i#2000-2004#880#",//--Renault--7447
"Renault#Captur#2015-2018#450#",//--Renault--7451
"Renault#Captur#2019-2020#420#",//--Renault--7455
"Renault#Captur II#2019-2022#440#",//--Renault--7459
"Renault#Clio#1994-1998#660#",//--Renault--7463
"Renault#Clio II#1998-2005#660#",//--Renault--7467
"Renault#Clio II 2.0i#1999-2004#710#",//--Renault--7471
"Renault#Clio III#2005-2015#510#",//--Renault--7475
"Renault#Clio III Diesel#2005-2015#530#",//--Renault--7479
"Renault#Clio IV#2012-2019#430#",//--Renault--7483
"Renault#Clio V#2019-2020#420#",//--Renault--7487
"Renault#Clio Symbol#2001-2008#650#",//--Renault--7491
"Renault#Duster#2012-2021#475#",//--Renault--7495
"Renault#Escape V#2015-2020#570#",//--Renault--7499
"Renault#Escape V with rear a/c#2015-2020#800#",//--Renault--7503
"Renault#Espace II#1994-1997#1250#",//--Renault--7507
"Renault#Espace III#1996-2002#880#",//--Renault--7511
"Renault#Espace V6 24V#1998-2002#890#",//--Renault--7515
"Renault#Espace 1.9 D Turbo#1999-2002#720#",//--Renault--7519
"Renault#Espace 2.2 D Turbo#1996-2000#800#",//--Renault--7523
"Renault#Espace IV (JKO) 1.9DdCi/2.0i/2.0i T#2002-2010#1000#",//--Renault--7527
"Renault#Espace IV (JKO) 2.2DdCi/3.0DdCi#2002-2010#1000#",//--Renault--7531
"Renault#Espace IV (JKO) 3.5i/2.0DdCi#2002-2010#1000#",//--Renault--7535
"Renault#Extra/Express/Rapid#1994-1998#680#",//--Renault--7539
"Renault#Fluence 1.5DdCi#2010-2016#530#",//--Renault--7543
"Renault#Fluence Z.E.#2011-2016#690#",//--Renault--7547
"Renault#Grand Modus II#2008-2013#510#",//--Renault--7551
"Renault#Grand Scenic III#2009-2015#495#",//--Renault--7555
"Renault#Grand Scenic III 2,0 i#2009-2015#510#",//--Renault--7559
"Renault#Grand Scenic II#2003-2009#550#",//--Renault--7563
"Renault#Kadjar#2015-2022#560#",//--Renault--7567
"Renault#Kangoo#1998-2008#650#",//--Renault--7571
"Renault#Kangoo Be Bop#2009-2013#550#",//--Renault--7575
"Renault#Kangoo II#2008-2022#550#",//--Renault--7579
"Renault#Kangoo Grand II Electric#2021-2022#850#",//--Renault--7583
"Renault#Kerax#2002-2006#1400#",//--Renault--7587
"Renault#Kerax LHD#2007-2015#1280#",//--Renault--7591
"Renault#Kerax RHD#2007-2015#1250#",//--Renault--7595
"Renault#Koleos#2008-2021#550#",//--Renault--7599
"Renault#Laguna#1994-2000#700#",//--Renault--7603
"Renault#Laguna 2.0 F3P 670/674#1994-2000#780#",//--Renault--7607
"Renault#Laguna 2.0 16V N7Q#1996-1999#800#",//--Renault--7611
"Renault#Laguna 2.0 16V F4R#1999-2003#660#",//--Renault--7615
"Renault#Laguna 2.2 D/3.0 V6#1994-2000#780#",//--Renault--7619
"Renault#Laguna 2.2 D Turbo/1.9DdTi#1996-2001#700#",//--Renault--7623
"Renault#LagunaIIXGO1.6i/1.8i/1.9DdCi/2.2DdCi#2001-2005#650#",//--Renault--7627
"Renault#Laguna II (XGO) 2.0i/2.0 IDE#2001-2005#700#",//--Renault--7631
"Renault#Laguna II (XGO) 3.0i#2001-2005#650#",//--Renault--7635
"Renault#Laguna II#2005-2008#650#",//--Renault--7639
"Renault#Laguna II G9T706+G9T707 (2.2dCi)#2005-2009#650#",//--Renault--7643
"Renault#Laguna II L7X733 (3.0i)#2005-2009#650#",//--Renault--7647
"Renault#Laguna III (BT/01)#2007-2015#650#",//--Renault--7651
"Renault#Logan#2004-2011#750#",//--Renault--7655
"Renault#Logan II#2014-2022#480#",//--Renault--7659
"Renault#Magnum#2000-2002#1550#",//--Renault--7663
"Renault#Magnum DXI LHD#2003-2015#1250#",//--Renault--7667
"Renault#Magnum DXI RHD#2003-2015#1210#",//--Renault--7671
"Renault#Mascott 2,8 DCI#1999-2007#850#",//--Renault--7675
"Renault#Mascott 3,0 DXI#2003-2010#750#",//--Renault--7679
"Renault#Master II 2.5D/2.8DTi#1998-2003#850#",//--Renault--7683
"Renault#Master II 1.9DdCi/2.2D dCi/2.5D dCi#2000-2003#850#",//--Renault--7687
"Renault#Master II 9-seat/16-seat#2000-2003#1350#",//--Renault--7691
"Renault#Master II 2.8 D dCi#2003-2007#850#",//--Renault--7695
"Renault#Master II 3.0 D Dxi#2003-2007#750#",//--Renault--7699
"Renault#Master II 3.0D DXi#2007-2010#750#",//--Renault--7703
"Renault#Master III (EV/UV)#2010-2022#580#",//--Renault--7707
"Renault#Master III A/C with rear#2010-2022#1100#",//--Renault--7711
"Renault#Master III WITH REAR HEATER#2010-2022#1700#",//--Renault--7715
"Renault#Maxity#2007-2015#300#",//--Renault--7719
"Renault#Megane#1995-1999#750#",//--Renault--7723
"Renault#Megane 1.4i/1.6i/2.0i#1999-2003#750#",//--Renault--7727
"Renault#Megane 1.9D/1.9DdTi#1999-2003#750#",//--Renault--7731
"Renault#Megane 1.9DdCi#1999-2003#780#",//--Renault--7735
"Renault#Megane II (XMO) 1.4i/1.5DdCi/1.6i#2003-2008#550#",//--Renault--7739
"Renault#Megane II (XMO) 1.9DdCi/2.0i /2.0dCi#2003-2008#550#",//--Renault--7743
"Renault#Megane III#2008-2016#480#",//--Renault--7747
"Renault#Megane IV#2016-2022#540#",//--Renault--7751
"Renault#Megane Scenic#1996-1999#800#",//--Renault--7755
"Renault#Midlum#2000-2015#1200#",//--Renault--7759
"Renault#Modus#2004-2010#510#",//--Renault--7763
"Renault#Premium#2002-2005#1400#",//--Renault--7767
"Renault#Premium DXi#2006-2015#1250#",//--Renault--7771
"Renault#R19#1994-1996#800#",//--Renault--7775
"Renault#R21#1994-1995#750#",//--Renault--7779
"Renault#Rapid#1994-2002#680#",//--Renault--7783
"Renault#Safrane#1995-2000#850#",//--Renault--7787
"Renault#Safrane 2.0 16V/2.5 20V/2.2 D Turbo#1996-2000#780#",//--Renault--7791
"Renault#Sandero II#2014-2022#480#",//--Renault--7795
"Renault#Scenic (JA) 1.4i/1.6i#1999-2003#750#",//--Renault--7799
"Renault#Scenic (JA) 2.0i/1.9DdTi/1.9DdCi#1999-2003#680#",//--Renault--7803
"Renault#Scenic II (JMO) 1.4i/1.5DdCi/1.6i#2003-2009#550#",//--Renault--7807
"Renault#Scenic II (JMO) 2.0i/1.9DdCi/2.0DdCi#2003-2009#550#",//--Renault--7811
"Renault#Scenic/G.Scenic III 1.4i/1.6i/1.5dCi#2009-2015#480#",//--Renault--7815
"Renault#Scenic/G.Scenic III 1.9dCi/2.0dCi#2009-2015#480#",//--Renault--7819
"Renault#Scenic/Grand Scenic III 2.0i#2009-2015#510#",//--Renault--7823
"Renault#Scenic#2016-2018#540#",//--Renault--7827
"Renault#Symbol#2008-2013#650#",//--Renault--7831
"Renault#Symbol II#2014-2018#480#",//--Renault--7835
"Renault#Talisman#2015-2022#540#",//--Renault--7839
"Renault#Thalia#2001-2013#650#",//--Renault--7843
"Renault#Trafic 1.9DdCi (F9Q760)#2001-2008#712#",//--Renault--7847
"Renault#Trafic 1.9DdCi (F9Q762)/2.0i/2.5DdCi#2001-2006#750#",//--Renault--7851
"Renault#Trafic#2015-2022#590#",//--Renault--7855
"Renault#Trafic A/C with rear#2015-2022#880#",//--Renault--7859
"Renault#Twingo 1.2i (C3G)#1993-1997#650#",//--Renault--7863
"Renault#Twingo 1.2i (D7F) / 1.2i 16V (D4F)#1997-2007#740#",//--Renault--7867
"Renault#Twingo II (CNO) 1.2i16V#2007-2015#430#",//--Renault--7871
"Renault#Twingo II (CNO) 1.6i/1.5dci#2007-2015#520#",//--Renault--7875
"Renault#Twingo III#2016-2022#475#",//--Renault--7879
"Renault#Vel Satis 2.0i Turbo/3.5i#2000-2010#650#",//--Renault--7883
"Renault#Wind#2010-2015#510#",//--Renault--7887
"Rover#200-Series#1994-1995#710#",//--7889-7983Rover--7891
"Rover#200-Series RHD#1995-1999#560#",//--Rover--7895
"Rover#200-Series LHD#1995-1999#638#",//--Rover--7899
"Rover#216/218 Coupe/Cabrio RHD#1996-1999#560#",//--Rover--7903
"Rover#216/218 Coupe/Cabrio LHD#1996-1999#638#",//--Rover--7907
"Rover#25 RHD#1999-2005#560#",//--Rover--7911
"Rover#25 LHD#1999-2005#640#",//--Rover--7915
"Rover#400-Series#1994-1995#710#",//--Rover--7919
"Rover#400-Series RHD#1995-1999#560#",//--Rover--7923
"Rover#400-Series LHD#1995-1999#638#",//--Rover--7927
"Rover#416 Tourer RHD#1996-1999#560#",//--Rover--7931
"Rover#416 Tourer LHD#1996-1999#638#",//--Rover--7935
"Rover#45 RHD#1999-2005#560#",//--Rover--7939
"Rover#45 LHD#1999-2005#640#",//--Rover--7943
"Rover#600-Series#1993-1999#725#",//--Rover--7947
"Rover#75#1999-2005#450#",//--Rover--7951
"Rover#820#1994-1999#650#",//--Rover--7955
"Rover#825#1996-1999#650#",//--Rover--7959
"Rover#827#1994-1996#650#",//--Rover--7963
"Rover#825 2.5 D Turbo#1994-1996#650#",//--Rover--7967
"Rover#825 2.5 D Turbo#1996-1999#650#",//--Rover--7971
"Rover#MGF#1995-2002#620#",//--Rover--7975
"Rover#Streetwise LHD#2003-2005#640#",//--Rover--7979
"Rover#Streetwise RHD#2003-2005#560#",//--Rover--7983
"Saab#900#1993-1998#725#",//--7985-8031Saab--7987
"Saab#9-3 benzin (YS3D)#1998-2003#800#",//--Saab--7991
"Saab#9-3 dizel (YS3D)#1998-2003#800#",//--Saab--7995
"Saab#9-3 (YD3F) 2.0i/2.2D/2.2TiD/1.8i#2003-2010#675#",//--Saab--7999
"Saab#9-3 (YD3F) 1.9TiD/2.8t/1.9D#2003-2010#675#",//--Saab--8003
"Saab#9-3#2010-2012#680#",//--Saab--8007
"Saab#9000#1992-1998#950#",//--Saab--8011
"Saab#9-5#1997-2005#875#",//--Saab--8015
"Saab#9-5 1.9D TiD#2005-2009#825#",//--Saab--8019
"Saab#9-5 2.0i/2.3i BioPower#2005-2009#825#",//--Saab--8023
"Saab#9-5 2.0i+2.3i Turbo +/2.3 Aero#2005-2009#825#",//--Saab--8027
"Saab#9-5#2010-2012#600#",//--Saab--8031
"Seat#Alhambra#1995-2000#975#",//--8033-8159Seat--8035
"Seat#Alhambra with rear a/c#1996-2000#1375#",//--Seat--8039
"Seat#Alhambra#2000-2010#725#",//--Seat--8043
"Seat#Alhambra with rear a/c#2000-2010#1075#",//--Seat--8047
"Seat#Alhambra (710)#2012-2015#600#",//--Seat--8051
"Seat#Alhambra (710) with rear a/c#2012-2015#1000#",//--Seat--8055
"Seat#Alhambra#2016-2022#525#",//--Seat--8059
"Seat#Alhambra with rear a/c#2016-2022#875#",//--Seat--8063
"Seat#Altea#2004-2013#525#",//--Seat--8067
"Seat#Arona#2017-2022#460#",//--Seat--8071
"Seat#Arosa#1997-2000#725#",//--Seat--8075
"Seat#Ateca#2016-2022#460#",//--Seat--8079
"Seat#Exeo#2009-2015#500#",//--Seat--8083
"Seat#Ibiza II/Cordoba RHD#1993-1999#915#",//--Seat--8087
"Seat#Ibiza II/Cordoba LHD#1993-1999#865#",//--Seat--8091
"Seat#Ibiza III/Cordoba RHD#1999-2002#775#",//--Seat--8095
"Seat#Ibiza III/Cordoba LHD#1999-2002#775#",//--Seat--8099
"Seat#Ibiza IV/Cordoba (6L2)#2002-2008#550#",//--Seat--8103
"Seat#Ibiza V (6J)#2008-2015#500#",//--Seat--8107
"Seat#Ibiza#2017-2022#460#",//--Seat--8111
"Seat#Ibiza 1,0#2017-2022#440#",//--Seat--8115
"Seat#Inca RHD#1995-2003#912#",//--Seat--8119
"Seat#Inca LHD#1995-2003#865#",//--Seat--8123
"Seat#Leon#1999-2005#775#",//--Seat--8127
"Seat#Leon II#2004-2022#500#",//--Seat--8131
"Seat#Mii#2012-2020#380#",//--Seat--8135
"Seat#Tarraco#2019-2022#500#",//--Seat--8139
"Seat#Toledo I RHD#1993-1999#900#",//--Seat--8143
"Seat#Toledo I LHD#1993-1999#850#",//--Seat--8147
"Seat#Toledo II#1999-2005#775#",//--Seat--8151
"Seat#Toledo III (5P2)#2004-2015#525#",//--Seat--8155
"Seat#Toledo#2016-2019#475#",//--Seat--8159
"Skoda#Citigo#2011-2019#380#",//--8161-8275Skoda--8163
"Skoda#Fabia#2000-2007#550#",//--Skoda--8167
"Skoda#Fabia II#2007-2014#550#",//--Skoda--8171
"Skoda#Fabia III#2015-2019#500#",//--Skoda--8175
"Skoda#Fabia III#2019-2022#490#",//--Skoda--8179
"Skoda#Felicia 1.3#1996-2001#765#",//--Skoda--8183
"Skoda#Felicia 1.6#1996-2001#735#",//--Skoda--8187
"Skoda#Kamiq#2019-2022#460#",//--Skoda--8191
"Skoda#Karoq#2017-2022#500#",//--Skoda--8195
"Skoda#Kodiaq#2017-2022#515#",//--Skoda--8199
"Skoda#Kodiaq Modine Condenser#2017-2020#475#",//--Skoda--8203
"Skoda#Kodiaq All Other Condensers#2017-2020#500#",//--Skoda--8207
"Skoda#Octavia (1U)#1996-2005#775#",//--Skoda--8211
"Skoda#Octavia II (1Z)#2004-2015#525#",//--Skoda--8215
"Skoda#Octavia III#2012-2020#500#",//--Skoda--8219
"Skoda#Octavia IV#2020-2022#500#",//--Skoda--8223
"Skoda#Octavia Modine Condenser#2016-2018#475#",//--Skoda--8227
"Skoda#Rapid#2012-2019#500#",//--Skoda--8231
"Skoda#Rapid Modine Condenser#2017-2019#475#",//--Skoda--8235
"Skoda#Roomster/Praktic Delphi/Zexel komp#2006-2015#550#",//--Skoda--8239
"Skoda#Roomster/Praktik Denso komp#2006-2015#500#",//--Skoda--8243
"Skoda#Scala#2019-2022#460#",//--Skoda--8247
"Skoda#Superb#2002-2008#600#",//--Skoda--8251
"Skoda#Superb II#2008-2015#525#",//--Skoda--8255
"Skoda#Superb III 1.4/1.5/1.8/2.0 TSI#2015-2019#515#",//--Skoda--8259
"Skoda#Superb III 2.0 TSI#2020-2022#500#",//--Skoda--8263
"Skoda#Superb III#2016-2022#500#",//--Skoda--8267
"Skoda#Superb III Modine Condenser#2016-2020#475#",//--Skoda--8271
"Skoda#Yeti#2009-2017#525#",//--Skoda--8275
"Smart#Cabrio/CityCoupe/Roadster/Crossblade#1998-2003#620#",//--8277-8307Smart--8279
"Smart#Cabrio/City/Fortwo (450)#2003-2007#450#",//--Smart--8283
"Smart#Forfour (454)#2004-2006#440#",//--Smart--8287
"Smart#Forfour#2014-2018#475#",//--Smart--8291
"Smart#Fortwo (451)#2007-2015#420#",//--Smart--8295
"Smart#Fortwo (451.391/491) elektrik#2010-2015#550#",//--Smart--8299
"Smart#Fortwo#2015-2018#475#",//--Smart--8303
"Smart#Roadster/Coupe (452)#2003-2006#650#",//--Smart--8307
"SsangYong#Actyon#2006-2012#650#",//--8309-8391SsangYong--8311
"SsangYong#Actyon#2012-2022#430#",//--SsangYong--8315
"SsangYong#Korando#1997-2007#700#",//--SsangYong--8319
"SsangYong#Korando#2011-2020#430#",//--SsangYong--8323
"SsangYong#Korando 2,2e XDI 220#2016-2020#500#",//--SsangYong--8327
"SsangYong#Korando Sports#2012-2018#650#",//--SsangYong--8331
"SsangYong#Kyron#2005-2015#650#",//--SsangYong--8335
"SsangYong#Musso#1996-1999#700#",//--SsangYong--8339
"SsangYong#Musso (FJ)#1999-2006#700#",//--SsangYong--8343
"SsangYong#Musso#2012-2018#650#",//--SsangYong--8347
"SsangYong#Rexton#2002-2006#850#",//--SsangYong--8351
"SsangYong#Rexton with rear a/c#2002-2006#1200#",//--SsangYong--8355
"SsangYong#Rexton II 2.7D#2006-2012#850#",//--SsangYong--8359
"SsangYong#Rexton II A/C Automatic#2006-2012#750#",//--SsangYong--8363
"SsangYong#Rexton II with rear a/c#2006-2012#1200#",//--SsangYong--8367
"SsangYong#Rexton W#2015-2018#720#",//--SsangYong--8371
"SsangYong#Rexton W with rear a/c#2015-2018#1120#",//--SsangYong--8375
"SsangYong#Rexton#2017-2022#550#",//--SsangYong--8379
"SsangYong#Rexton with rear a/c#2017-2022#850#",//--SsangYong--8383
"SsangYong#Rodius#2005-2020#1050#",//--SsangYong--8387
"SsangYong#Stavic#2005-2012#1050#",//--SsangYong--8391
"Subaru#BRZ#2012-2020#390#",//--8393-8547Subaru--8395
"Subaru#Forester (SF) RHD#1997-2003#700#",//--Subaru--8399
"Subaru#Forester (SF) LHD#1997-2003#600#",//--Subaru--8403
"Subaru#Forester (SG) 2.0i/2.0i Turbo/2.5i#2003-2008#600#",//--Subaru--8407
"Subaru#Forester (SH)#2008-2015#500#",//--Subaru--8411
"Subaru#Forester 2,0#2016-2018#375#",//--Subaru--8415
"Subaru#Forester 2,0 6200rpm 2,0XT Turbo#2013-2019#475#",//--Subaru--8419
"Subaru#Impreza#1994-2000#600#",//--Subaru--8423
"Subaru#Impreza#2001-2012#500#",//--Subaru--8427
"Subaru#Impreza#2012-2016#475#",//--Subaru--8431
"Subaru#Impreza#2017-2022#400#",//--Subaru--8435
"Subaru#Justy (G3X) 1.3i/1.5i#2003-2007#430#",//--Subaru--8439
"Subaru#Justy IV#2007-2015#300#",//--Subaru--8443
"Subaru#Legacy#1994-1995#650#",//--Subaru--8447
"Subaru#Legacy LHD#1996-1996#650#",//--Subaru--8451
"Subaru#Legacy LHD#1997-1999#600#",//--Subaru--8455
"Subaru#Legacy LHD#2000-2003#650#",//--Subaru--8459
"Subaru#Legacy RHD#1996-1996#750#",//--Subaru--8463
"Subaru#Legacy RHD#1997-1999#800#",//--Subaru--8467
"Subaru#Legacy RHD#2000-2003#650#",//--Subaru--8471
"Subaru#Legacy/ Legacy Outback (BL/ BP)#2003-2009#430#",//--Subaru--8475
"Subaru#Legacy V 2.5i/2.0D#2009-2015#425#",//--Subaru--8479
"Subaru#Legacy#2017-2018#455#",//--Subaru--8483
"Subaru#Levorg#2015-2020#475#",//--Subaru--8487
"Subaru#Liberty#2000-2009#430#",//--Subaru--8491
"Subaru#Liberty#2009-2015#400#",//--Subaru--8495
"Subaru#Liberty Exiga#2009-2015#500#",//--Subaru--8499
"Subaru#Outback#2003-2009#430#",//--Subaru--8503
"Subaru#Outback (BM/BR)#2009-2022#425#",//--Subaru--8507
"Subaru#Outback 2,0#2015-2018#375#",//--Subaru--8511
"Subaru#SVX#1994-1997#650#",//--Subaru--8515
"Subaru#B9 Tribeca#2006-2009#600#",//--Subaru--8519
"Subaru#B9 Tribeca with rear#2006-2009#870#",//--Subaru--8523
"Subaru#Trezia#2011-2015#360#",//--Subaru--8527
"Subaru#Tribeca (B9)#2005-2015#600#",//--Subaru--8531
"Subaru#Tribeca with rear#2005-2015#870#",//--Subaru--8535
"Subaru#WRX#2011-2015#500#",//--Subaru--8539
"Subaru#WRX#2016-2018#475#",//--Subaru--8543
"Subaru#XV#2012-2022#475#",//--Subaru--8547
"Suzuki#APV#2005-2012#400#",//--8549-8687Suzuki--8551
"Suzuki#APV with rear a/c#2005-2012#550#",//--Suzuki--8555
"Suzuki#Alto#1997-2002#550#",//--Suzuki--8559
"Suzuki#Alto#2002-2009#400#",//--Suzuki--8563
"Suzuki#Alto (GF)#2009-2015#370#",//--Suzuki--8567
"Suzuki#Baleno#1995-2003#600#",//--Suzuki--8571
"Suzuki#Baleno#2016-2019#380#",//--Suzuki--8575
"Suzuki#Celerio#2014-2019#350#",//--Suzuki--8579
"Suzuki#Cappuccino#1993-1996#600#",//--Suzuki--8583
"Suzuki#Grand Vitara#1998-2000#550#",//--Suzuki--8587
"Suzuki#Grand Vitara 1.6i/2.0i/2.5i#2000-2005#440#",//--Suzuki--8591
"Suzuki#Grand Vitara 2.0 D Turbo#2000-2005#440#",//--Suzuki--8595
"Suzuki#Grand Vitara 2.7 V6#2001-2005#500#",//--Suzuki--8599
"Suzuki#Grand Vitara 1.6i/1.9D DDiS/2.0i#2005-2015#570#",//--Suzuki--8603
"Suzuki#Ignis#2000-2003#360#",//--Suzuki--8607
"Suzuki#Ignis II 1.3i/1.5i#2003-2015#430#",//--Suzuki--8611
"Suzuki#Ignis II 1.3D DDiS#2003-2015#480#",//--Suzuki--8615
"Suzuki#Ignis#2017-2022#390#",//--Suzuki--8619
"Suzuki#Jimny#1998-2003#550#",//--Suzuki--8623
"Suzuki#Jimny 1.3i#2004-2015#430#",//--Suzuki--8627
"Suzuki#Jimny 1.5D DDiS#2004-2015#550#",//--Suzuki--8631
"Suzuki#Jimny#2015-2019#430#",//--Suzuki--8635
"Suzuki#Kizashi#2010-2015#530#",//--Suzuki--8639
"Suzuki#Liana#2001-2008#500#",//--Suzuki--8643
"Suzuki#Splash#2008-2015#370#",//--Suzuki--8647
"Suzuki#Super Carry 1.3i#1999-2006#530#",//--Suzuki--8651
"Suzuki#Swift#1993-2015#700#",//--Suzuki--8655
"Suzuki#Swift 1.3i/1.5i/1.6i/1.3D#2004-2010#370#",//--Suzuki--8659
"Suzuki#Swift#2017-2022#390#",//--Suzuki--8663
"Suzuki#SX4 1.5i/1.6i#2006-2015#430#",//--Suzuki--8667
"Suzuki#SX4#2016-2022#400#",//--Suzuki--8671
"Suzuki#Wagon R (EM)#1997-2000#550#",//--Suzuki--8675
"Suzuki#Wagon R (MM) 1.0i/1.2i/1.3D DDiS#2000-2015#480#",//--Suzuki--8679
"Suzuki#Wagon R (MM) 1.3i#2000-2006#475#",//--Suzuki--8683
"Suzuki#Vitara#2015-2022#400#",//--Suzuki--8687
"Tata#Safari 1.9D#1999-2007#1150#",//--8689-8699Tata--8691
"Tata#Xenon#2008-2018#700#",//--Tata--8695
"Tata#Vista#2008-2018#650#",//--Tata--8699
"Toyota#86#2017-2018#440#",//--8701-9259Toyota--8703
"Toyota#4Runner RHD#1993-1996#700#",//--Toyota--8707
"Toyota#4Runner LHD#1993-1996#750#",//--Toyota--8711
"Toyota#Aurion#2006-2012#500#",//--Toyota--8715
"Toyota#Auris#2007-2018#450#",//--Toyota--8719
"Toyota#Auris Hibrid#2010-2019#475#",//--Toyota--8723
"Toyota#Avalon#2000-2006#800#",//--Toyota--8727
"Toyota#Avalon#2017-2018#550#",//--Toyota--8731
"Toyota#Avensis (T22)#1998-2000#450#",//--Toyota--8735
"Toyota#Avensis (T25)#2001-2003#460#",//--Toyota--8739
"Toyota#Avensis (T27)#2004-2018#440#",//--Toyota--8743
"Toyota#Avensis Verso#2001-2006#500#",//--Toyota--8747
"Toyota#Avensis Verso with rear a/c#2001-2006#800#",//--Toyota--8751
"Toyota#Aygo#2005-2015#500#",//--Toyota--8755
"Toyota#Aygo#2015-2022#380#",//--Toyota--8759
"Toyota#Aygo 1,2#2015-2018#400#",//--Toyota--8763
"Toyota#Camry#1994-1996#850#",//--Toyota--8767
"Toyota#Camry (V20)#1996-2001#800#",//--Toyota--8771
"Toyota#Camry (V30)#2001-2005#550#",//--Toyota--8775
"Toyota#Camry Hybrid#2010-2012#530#",//--Toyota--8779
"Toyota#Camry Hybrid#2017-2018#580#",//--Toyota--8783
"Toyota#Carina E#1992-1998#750#",//--Toyota--8787
"Toyota#C-HR Valeo Compresor#2016-2022#425#",//--Toyota--8791
"Toyota#C-HR Denso Compresor#2016-2022#470#",//--Toyota--8795
"Toyota#Celica (T20)#1994-1999#650#",//--Toyota--8799
"Toyota#Celica (ZZT23)#1999-2006#430#",//--Toyota--8803
"Toyota#Coaster#1993-2015#1950#",//--Toyota--8807
"Toyota#Corolla#1994-1997#700#",//--Toyota--8811
"Toyota#Corolla#1997-2000#650#",//--Toyota--8815
"Toyota#Corolla 1.9D Japonya#2000-2002#650#",//--Toyota--8819
"Toyota#Corolla 1.9D ingiltere#2000-2002#470#",//--Toyota--8823
"Toyota#Corolla (E12U)#2002-2008#450#",//--Toyota--8827
"Toyota#Corolla#2008-2018#440#",//--Toyota--8831
"Toyota#Corolla#2018-2022#470#",//--Toyota--8835
"Toyota#Dyna#2007-2015#550#",//--Toyota--8839
"Toyota#Echo#1999-2002#430#",//--Toyota--8843
"Toyota#Echo#2003-2004#410#",//--Toyota--8847
"Toyota#GT 86#2012-2022#390#",//--Toyota--8851
"Toyota#GR Supra#2019-2022#550#",//--Toyota--8855
"Toyota#Hi-Ace#1995-2000#750#",//--Toyota--8859
"Toyota#Hi-Ace with rear a/c#1995-2000#1300#",//--Toyota--8863
"Toyota#Hi-Ace RHD#2000-2005#500#",//--Toyota--8867
"Toyota#Hi-Ace LHD#2000-2005#450#",//--Toyota--8871
"Toyota#Hi-Ace#2006-2018#550#",//--Toyota--8875
"Toyota#Hi-Ace with rear a/c#2000-2005#700#",//--Toyota--8879
"Toyota#Higlander 183kw (249hp)#2014-2020#820#",//--Toyota--8883
"Toyota#Hi-Lux#1993-1996#750#",//--Toyota--8887
"Toyota#Hi-Lux#1997-2005#550#",//--Toyota--8891
"Toyota#Hi-Lux#2005-2015#450#",//--Toyota--8895
"Toyota#Hi-Lux#2016-2022#500#",//--Toyota--8899
"Toyota#iQ#2008-2015#360#",//--Toyota--8903
"Toyota#Kluger#2003-2007#650#",//--Toyota--8907
"Toyota#Kluger#2008-2012#600#",//--Toyota--8911
"Toyota#Kluger with rear a/c#2008-2012#770#",//--Toyota--8915
"Toyota#Landcruiser 3.4#1996-2003#700#",//--Toyota--8919
"Toyota#Landcruiser 3.4 with rear a/c#1996-2003#950#",//--Toyota--8923
"Toyota#Landcruiser 4.5#1995-1998#750#",//--Toyota--8927
"Toyota#Landcruiser Amazon 4.7/4.2 Turbo D#1998-2000#750#",//--Toyota--8931
"Toyota#Landcruiser 3.0 Turbo D#1993-1996#875#",//--Toyota--8935
"Toyota#Landcruiser 3.0 with rear a/c#1993-1996#1600#",//--Toyota--8939
"Toyota#Landcruiser Colorado/Prado#1997-1999#700#",//--Toyota--8943
"Toyota#Landcruiser Colorado/Prado with rear a/c#1997-1999#950#",//--Toyota--8947
"Toyota#Landcruiser Amazon 4.2 Turbo D#1995-1998#850#",//--Toyota--8951
"Toyota#Landcruiser (J12)#2003-2004#650#",//--Toyota--8955
"Toyota#Landcruiser Colorado/Prado coolbox#2003-2004#750#",//--Toyota--8959
"Toyota#Landcruiser Colorado/Prado with rear a/c#2003-2004#800#",//--Toyota--8963
"Toyota#Landcruiser C/P with rear a/c+coolbox#2003-2004#900#",//--Toyota--8967
"Toyota#Landcruiser (J12)#2004-2015#600#",//--Toyota--8971
"Toyota#Landcruiser (J12) coolbox#2004-2015#700#",//--Toyota--8975
"Toyota#Landcruiser (J12) with rear a/c#2004-2015#750#",//--Toyota--8979
"Toyota#Landcruiser (J12) with rear a/c+coolbox#2004-2015#850#",//--Toyota--8983
"Toyota#Landcruiser (J15)#2009-2022#550#",//--Toyota--8987
"Toyota#Landcruiser (J15) Prado coolbox#2009-2022#600#",//--Toyota--8991
"Toyota#Landcruiser (J15) Prado with rear a/c#2009-2022#770#",//--Toyota--8995
"Toyota#Landcruiser (J15) with rear a/c+coolbox#2009-2022#800#",//--Toyota--8999
"Toyota#Landcruiser (J20) kond 22mm#2008-2015#870#",//--Toyota--9003
"Toyota#Landcruiser (J20) with rear a/c#2008-2015#960#",//--Toyota--9007
"Toyota#Landcruiser (J20) with rear a/c +coolbox#2008-2015#1010#",//--Toyota--9011
"Toyota#Landcruiser (J20) kond 16mm#2008-2015#770#",//--Toyota--9015
"Toyota#Landcruiser (J20) with rear a/c#2008-2015#920#",//--Toyota--9019
"Toyota#Landcruiser (J20) with rear a/c +coolbox#2008-2015#970#",//--Toyota--9023
"Toyota#Lexcen#1993-1998#800#",//--Toyota--9027
"Toyota#MR2 (W2)#1993-2000#850#",//--Toyota--9031
"Toyota#MR2 (W3)#2000-2006#500#",//--Toyota--9035
"Toyota#Paseo#1996-1999#600#",//--Toyota--9039
"Toyota#Picnic#1996-2001#750#",//--Toyota--9043
"Toyota#Picnic#2002-2006#500#",//--Toyota--9047
"Toyota#Picnic with rear a/c#2002-2006#800#",//--Toyota--9051
"Toyota#Prius  Hybrid#2016-2022#470#",//--Toyota--9055
"Toyota#Power Van#1995-2000#750#",//--Toyota--9059
"Toyota#Power Van with rear a/c#1995-2000#1300#",//--Toyota--9063
"Toyota#Power Van RHD#2001-2005#500#",//--Toyota--9067
"Toyota#Power Van LHD#2001-2005#450#",//--Toyota--9071
"Toyota#Power Van#2006-2012#550#",//--Toyota--9075
"Toyota#Power Van with rear a/c#2006-2012#700#",//--Toyota--9079
"Toyota#Previa#1993-2006#900#",//--Toyota--9083
"Toyota#Previa with rear a/c#1993-2006#1150#",//--Toyota--9087
"Toyota#Previa#2000-2006#700#",//--Toyota--9091
"Toyota#Previa with rear a/c#2000-2006#880#",//--Toyota--9095
"Toyota#Prius (NHW11)#1999-2004#500#",//--Toyota--9099
"Toyota#Prius#2004-2009#450#",//--Toyota--9103
"Toyota#Prius 1.8HSD Hybrid#2009-2018#470#",//--Toyota--9107
"Toyota#Prius + (ZVW4)#2011-2018#470#",//--Toyota--9111
"Toyota#PROACE SINGLE ZONE EXCEPT HOT CLIMATE#2016-2022#500#",//--Toyota--9115
"Toyota#PROACE DUAL ZONE#2016-2022#500#",//--Toyota--9119
"Toyota#Proace City 1930cm3 Condenser#2020-2022#470#",//--Toyota--9123
"Toyota#Proace City 2350cm3 Condenser#2020-2022#600#",//--Toyota--9127
"Toyota#RAV4#1994-2000#700#",//--Toyota--9131
"Toyota#RAV4 (XA2)#2000-2006#510#",//--Toyota--9135
"Toyota#RAV 4 III (ACA/ACE)#2006-2012#430#",//--Toyota--9139
"Toyota#RAV 4#2013-2015#450#",//--Toyota--9143
"Toyota#RAV 4#2016-2018#500#",//--Toyota--9147
"Toyota#RAV 4#2018-2022#550#",//--Toyota--9151
"Toyota#RAV 4 Hybrid#2015-2022#550#",//--Toyota--9155
"Toyota#RAV 4 2.5 PHEV Hybrid#2020-2022#1500#",//--Toyota--9159
"Toyota#Sienna#2017-2018#810#",//--Toyota--9163
"Toyota#SEQUOIA#2017-2018#920#",//--Toyota--9167
"Toyota#Spacia#1998-2001#700#",//--Toyota--9171
"Toyota#Spacia with rear a/c#1998-2001#900#",//--Toyota--9175
"Toyota#Sports Van#2001-2006#500#",//--Toyota--9179
"Toyota#Sports Van with rear a/c#2001-2006#800#",//--Toyota--9183
"Toyota#Starlet#1994-1999#600#",//--Toyota--9187
"Toyota#Supra#1993-1997#700#",//--Toyota--9191
"Toyota#Tarago#2006-2011#750#",//--Toyota--9195
"Toyota#Tacoma#2017-2020#630#",//--Toyota--9199
"Toyota#Tundra#2017-2020#630#",//--Toyota--9203
"Toyota#Townace#1996-2005#700#",//--Toyota--9207
"Toyota#Townace with rear a/c#1996-2005#900#",//--Toyota--9211
"Toyota#Urban Cruiser#2009-2015#360#",//--Toyota--9215
"Toyota#Verso / Sportsvan#2009-2018#440#",//--Toyota--9219
"Toyota#Yaris 1.1i/1.3i/1.5i#1999-2002#430#",//--Toyota--9223
"Toyota#Yaris 1.1i/1.3i/1.5i#2002-2006#410#",//--Toyota--9227
"Toyota#Yaris 1.4D#2002-2006#440#",//--Toyota--9231
"Toyota#Yaris 1.0i/1.3i/1.4D#2006-2015#370#",//--Toyota--9235
"Toyota#Yaris (P13) 1.5 VVT-i#2011-2020#360#",//--Toyota--9239
"Toyota#Yaris Hibrid#2012-2020#435#",//--Toyota--9243
"Toyota#Yaris 5 door gasoline#2020-2022#350#",//--Toyota--9247
"Toyota#Yaris 5 door Hibrid#2020-2022#450#",//--Toyota--9251
"Toyota#Yaris 3 door#2020-2022#420#",//--Toyota--9255
"Toyota#Yaris 1.6 GR Circuit Pack#2020-2022#320#",//--Toyota--9259
"VW#Amarok#2010-2022#525#",//--9261-9659VW--9263
"VW#Arteon#2017-2022#500#",//--VW--9267
"VW#Beetle#1998-2011#725#",//--VW--9271
"VW#Beetle Coccinelle/ Maggiolino#2012-2018#525#",//--VW--9275
"VW#Bora#1997-2005#775#",//--VW--9279
"VW#Caddy II#1995-2003#865#",//--VW--9283
"VW#Caddy III Maxi#2004-2015#525#",//--VW--9287
"VW#Caddy / Caddy Maxi#2016-2020#500#",//--VW--9291
"VW#Corrado#1992-1995#875#",//--VW--9295
"VW#Crafer#2006-2015#740#",//--VW--9299
"VW#Crafter air-conditioned ceiling#2006-2015#1125#",//--VW--9303
"VW#Crafer#2016-2022#575#",//--VW--9307
"VW#Crafter air-conditioned ceiling#2016-2022#825#",//--VW--9311
"VW#E-Crafer Electric R134a#2018-2022#965#",//--VW--9315
"VW#E-Load Up 60kw Electric#2016-2020#380#",//--VW--9319
"VW#Eos#2006-2015#525#",//--VW--9323
"VW#Fox#2005-2012#450#",//--VW--9327
"VW#E-Golf eaza 100kw#2017-2019#500#",//--VW--9331
"VW#E-Golf With heat pump#2017-2019#950#",//--VW--9335
"VW#E-Up Electric#2013-2016#380#",//--VW--9339
"VW#E-Up 60kw EABA Electric#2016-2020#380#",//--VW--9343
"VW#Golf III/Vento/Cabrio#1992-1997#825#",//--VW--9347
"VW#Golf IV#1997-2005#775#",//--VW--9351
"VW#Golf V#2003-2008#525#",//--VW--9355
"VW#Golf VI#2008-2015#525#",//--VW--9359
"VW#Golf VII#2012-2021#500#",//--VW--9363
"VW#Jetta + Hybrid#2005-2018#525#",//--VW--9367
"VW#LT#1996-2003#775#",//--VW--9371
"VW#Lupo Sanden komp#1998-2000#725#",//--VW--9375
"VW#Lupo Calsonic komp#1999-2005#575#",//--VW--9379
"VW#Lupo Denso komp#2000-2005#562#",//--VW--9383
"VW#Maggionlino#2011-2015#525#",//--VW--9387
"VW#Passat#1992-1997#1175#",//--VW--9391
"VW#Passat RHD#1996-2000#725#",//--VW--9395
"VW#Passat LHD#1996-2000#675#",//--VW--9399
"VW#Passat Links/RHD#2000-2005#612#",//--VW--9403
"VW#Passat W8#2001-2005#512#",//--VW--9407
"VW#Passat (3C)#2005-2010#600#",//--VW--9411
"VW#Passat (362/365)#2010-2011#600#",//--VW--9415
"VW#Passat (362/365)#2011-2015#550#",//--VW--9419
"VW#Passat#2016-2019#500#",//--VW--9423
"VW#Passat#2019-2022#500#",//--VW--9427
"VW#Passat CC#2008-2010#600#",//--VW--9431
"VW#Passat CC#2011-2012#550#",//--VW--9435
"VW#Phaeton#2002-2015#600#",//--VW--9439
"VW#Polo#1994-1999#725#",//--VW--9443
"VW#Polo#2000-2009#560#",//--VW--9447
"VW#Polo#2010-2017#500#",//--VW--9451
"VW#Polo Classic#1996-2002#865#",//--VW--9455
"VW#Polo Estate#1997-2002#865#",//--VW--9459
"VW#Polo Kombi#1997-2002#865#",//--VW--9463
"VW#Polo 1.2i/1.2i12V/1.4i/1.4TDI#2002-2005#562#",//--VW--9467
"VW#Polo 1.6i/1.9SDI/1.9TDI/1.4FSi#2002-2005#562#",//--VW--9471
"VW#Polo (6R) 1.2i/1.6TDi#2009-2016#500#",//--VW--9475
"VW#Polo 1.6 16V#2016-2020#500#",//--VW--9479
"VW#Polo 1.0 MPI / 2.0 TSI#2017-2020#440#",//--VW--9483
"VW#Polo 1.0 TGI / TSI / TDI#2017-2020#460#",//--VW--9487
"VW#Scirocco#2008-2018#525#",//--VW--9491
"VW#Sharan#1995-2000#975#",//--VW--9495
"VW#Sharan with rear a/c#1995-2000#1375#",//--VW--9499
"VW#Sharan#2000-2010#725#",//--VW--9503
"VW#Sharan with rear a/c#2000-2010#1075#",//--VW--9507
"VW#Sharan (7N)#2010-2015#600#",//--VW--9511
"VW#Sharan (7N) with rear a/c#2010-2015#950#",//--VW--9515
"VW#Sharan 1,4 TSI#2016-2018#550#",//--VW--9519
"VW#Sharan#2016-2022#525#",//--VW--9523
"VW#Sharan (7N) with rear a/c#2016-2022#875#",//--VW--9527
"VW#T- Cross#2018-2022#460#",//--VW--9531
"VW#Tiguan#2007-2015#660#",//--VW--9535
"VW#Tiguan#2016-2022#500#",//--VW--9539
"VW#Touareg#2002-2009#700#",//--VW--9543
"VW#Touareg with rear a/c#2002-2009#1050#",//--VW--9547
"VW#Touareg#2004-2010#700#",//--VW--9551
"VW#Touareg with rear a/c#2004-2010#1000#",//--VW--9555
"VW#Touareg (7P5)#2010-2018#850#",//--VW--9559
"VW#Touareg with rear a/c#2010-2018#1100#",//--VW--9563
"VW#Touareg#2018-2022#700#",//--VW--9567
"VW#Touareg 3.0 Hibrid#2020-2022#840#",//--VW--9571
"VW#Touran#2003-2015#525#",//--VW--9575
"VW#Touran#2015-2022#500#",//--VW--9579
"VW#Transporter#1992-1995#975#",//--VW--9583
"VW#Transporter with rear a/c#1992-1995#1375#",//--VW--9587
"VW#Transporter with rear a/c Long Wheelbase#1993-1995#1425#",//--VW--9591
"VW#Transporter#1995-2003#975#",//--VW--9595
"VW#Transporter with rear a/c#1995-2003#1375#",//--VW--9599
"VW#Transporter with rear a/c Long Wheelbase#1995-2003#1425#",//--VW--9603
"VW#Transporter 2.8i16V#2000-2003#1125#",//--VW--9607
"VW#Transporter 2.8i16V with rear a/c#2000-2003#1425#",//--VW--9611
"VW#Transporter T5 (7H.7J) Denso komp#2003-2010#650#",//--VW--9615
"VW#Transporter T5 Denso with rear a/c#2003-2010#950#",//--VW--9619
"VW#Transporter T5 (7H.7J) Sanden komp#2003-2010#650#",//--VW--9623
"VW#Transporter T5 Sanden with rear a/c#2003-2010#1050#",//--VW--9627
"VW#Transporter T6#2015-2019#600#",//--VW--9631
"VW#Transporter T6 with rear a/c#2015-2019#900#",//--VW--9635
"VW#Transporter T6.1#2019-2022#600#",//--VW--9639
"VW#Transporter T6.1 with rear a/c#2019-2022#900#",//--VW--9643
"VW#T-ROC#2017-2022#500#",//--VW--9647
"VW#Up Doowon DV9 komp#2011-2022#380#",//--VW--9651
"VW#Up 1.0#2020-2022#380#",//--VW--9655
"VW#Vento#1992-1998#825#",//--VW--9659
"Volvo#240#1993-1994#750#",//--9661-9963Volvo--9663
"Volvo#440/460/480#1994-1997#650#",//--Volvo--9667
"Volvo#850#1991-1997#790#",//--Volvo--9671
"Volvo#940 / 960 -Series 4-silindir#1993-1998#950#",//--Volvo--9675
"Volvo#940/ 960 -Series 6-silindir#1993-1997#900#",//--Volvo--9679
"Volvo#C30#2006-2013#550#",//--Volvo--9683
"Volvo#C30 Electric#2011-2012#600#",//--Volvo--9687
"Volvo#C70#1998-2006#790#",//--Volvo--9691
"Volvo#C70#2006-2015#535#",//--Volvo--9695
"Volvo#S40/V40#1997-2003#900#",//--Volvo--9699
"Volvo#S40/V40 1.8 GDI#1998-2015#750#",//--Volvo--9703
"Volvo#S40/V40 1.8 GDI#1999-2003#850#",//--Volvo--9707
"Volvo#S40/V40 Dizel#1996-1998#900#",//--Volvo--9711
"Volvo#S40/V40 Dizel#1999-2003#850#",//--Volvo--9715
"Volvo#S40 II (MS)#2004-2015#535#",//--Volvo--9719
"Volvo#S60#2000-2005#1000#",//--Volvo--9723
"Volvo#S60 Komo (h)#2006-2010#700#",//--Volvo--9727
"Volvo#S60 II#2010-2015#820#",//--Volvo--9731
"Volvo#S60#2016-2018#800#",//--Volvo--9735
"Volvo#S60#2018-2022#700#",//--Volvo--9739
"Volvo#S60 T6/T8#2020-2022#725#",//--Volvo--9743
"Volvo#S70#1997-2000#790#",//--Volvo--9747
"Volvo#S80#1998-2005#1000#",//--Volvo--9751
"Volvo#S80#2005-2006#700#",//--Volvo--9755
"Volvo#S80 2,0i / 2,0i F#2007-2011#720#",//--Volvo--9759
"Volvo#S80 2,0D/2,4D/2,5i/3,0i /3,2i/4,4i#2007-2013#800#",//--Volvo--9763
"Volvo#S80#2014-2016#650#",//--Volvo--9767
"Volvo#S90#2016-2022#700#",//--Volvo--9771
"Volvo#S90 T8 Twin Engine Hybrid#2017-2019#725#",//--Volvo--9775
"Volvo#S/V90#1997-1999#900#",//--Volvo--9779
"Volvo#V40#2015-2019#625#",//--Volvo--9783
"Volvo#V50#2004-2015#535#",//--Volvo--9787
"Volvo#V60#2011-2012#820#",//--Volvo--9791
"Volvo#V60 2,0 D3/2,4 D5 77#2010-2012#770#",//--Volvo--9795
"Volvo#V60#2013-2016#720#",//--Volvo--9799
"Volvo#V60#2016-2018#800#",//--Volvo--9803
"Volvo#V60#2018-2020#700#",//--Volvo--9807
"Volvo#V60 3,0 T6 770#2010-2015#770#",//--Volvo--9811
"Volvo#V60 Hybrid#2012-2018#920#",//--Volvo--9815
"Volvo#V70 I#1997-2000#790#",//--Volvo--9819
"Volvo#V70 II#2000-2007#1000#",//--Volvo--9823
"Volvo#V70 II#2007-2012#800#",//--Volvo--9827
"Volvo#V70 II 2,0i / 2,0i F#2007-2011#720#",//--Volvo--9831
"Volvo#V70#2011-2015#800#",//--Volvo--9835
"Volvo#V90#2016-2022#700#",//--Volvo--9839
"Volvo#V90 Twin Engine Hybrid#2016-2018#725#",//--Volvo--9843
"Volvo#XC 40#2017-2020#540#",//--Volvo--9847
"Volvo#XC 40 2.0 D3/D4/T4/T5#2017-2022#550#",//--Volvo--9851
"Volvo#XC 40 Electric#2020-2022#750#",//--Volvo--9855
"Volvo#XC 40 1.5 Recharge Electric#2020-2022#575#",//--Volvo--9859
"Volvo#XC 40 1.5 T4/T5 Twin Engine#2019-2022#575#",//--Volvo--9863
"Volvo#XC 40 1.5 T2/T3#2019-2022#550#",//--Volvo--9867
"Volvo#XC 40 2.0 B4/B5#2020-2022#650#",//--Volvo--9871
"Volvo#XC 60#2008-2015#800#",//--Volvo--9875
"Volvo#XC 60 2,0 D3#2012-2015#770#",//--Volvo--9879
"Volvo#XC 60#2016-2020#700#",//--Volvo--9883
"Volvo#XC 60 Twin Engine Hybrid#2016-2019#725#",//--Volvo--9887
"Volvo#XC 60 B4/B5#2019-2022#725#",//--Volvo--9891
"Volvo#XC 60 B4/B5/B6 Hybrid#2019-2022#700#",//--Volvo--9895
"Volvo#XC 60 D3/D4/D5#2018-2022#700#",//--Volvo--9899
"Volvo#XC 60 2.0 Recharge T6/T8#2020-2022#725#",//--Volvo--9903
"Volvo#XC 70#2002-2007#1000#",//--Volvo--9907
"Volvo#XC 70#2007-2015#800#",//--Volvo--9911
"Volvo#XC 90#2002-2005#1000#",//--Volvo--9915
"Volvo#XC 90 with rear A/C#2002-2005#1300#",//--Volvo--9919
"Volvo#XC 90 mit Komo (h)#2006-2015#700#",//--Volvo--9923
"Volvo#XC 90 with rear A/C#2006-2015#1050#",//--Volvo--9927
"Volvo#XC 90 Excellence#2016-2016#800#",//--Volvo--9931
"Volvo#XC 90#2015-2020#750#",//--Volvo--9935
"Volvo#XC 90 with rear a/c#2015-2020#1000#",//--Volvo--9939
"Volvo#XC 90 Twin Engine Hybrid#2015-2019#700#",//--Volvo--9943
"Volvo#XC 90 Twin Engine with rear a/c Hybrid#2015-2019#1000#",//--Volvo--9947
"Volvo#XC 90 2.0 B5/B6#2019-2022#700#",//--Volvo--9951
"Volvo#XC 90 2.0 B5/B6 with rear a/c#2019-2022#950#",//--Volvo--9955
"Volvo#XC 90 2.0 Recharge T8#2020-2022#775#",//--Volvo--9959
"Volvo#XC 90 2.0 Recharge T8 rear a/c#2020-2022#1050#",//--Volvo--9963
"Mahindra#Genio 2,2D#2014-2018#520#",//--9965-9971Mahindra--9967
//"Mahindra#XUV 500#2014-2018#",//--Mahindra--9971 !!!GRAM BİLGİSİ YOK!!!
"Datsun#MI-DO#2014-2022#500#",//--9973-9979Datsun--9975
"Datsun#ON-DO#2014-2022#500#",//--Datsun--9979
"Cupra#Ateca 2.0 TSI#2020-2022#460#",//--9981-9995Cupra--9983
"Cupra#Formentor#2021-2022#500#",//--Cupra--9987
"Cupra#Leon#2021-2022#500#",//--Cupra--9991
"Cupra#Leon 1.4 eHybrid R134#2021-2022#500#",//--Cupra--9995
"DAEWOO AVIA#D75/D90 3.9D#2002-2009#850#",//--9997-9999DAEWOO AVIA--9999
"DAF#45#1996-2001#1000#",//--10001-10051DAF--10003
"DAF#LF 45#2001-2015#900#",//--DAF--10007
"DAF#LF 55#2001-2015#900#",//--DAF--10011
"DAF#65#1990-1993#850#",//--DAF--10015
"DAF#CF 65#2001-2016#850#",//--DAF--10019
"DAF#75#1990-1993#900#",//--DAF--10023
"DAF#CF 75#2001-2011#850#",//--DAF--10027
"DAF#85#1991-1993#900#",//--DAF--10031
"DAF#CF 85#2001-2011#850#",//--DAF--10035
"DAF#95#1991-1993#1000#",//--DAF--10039
"DAF#95 XF#1997-2003#700#",//--DAF--10043
"DAF#XF 95#2002-2018#700#",//--DAF--10047
"DAF#XF105#2005-2018#700#",//--DAF--10051
"FORD#1833 DC /1833 LR Midilli- double cabin 9 Lt.#....-2022#940#",//--10053-10071FORD--10055
"FORD#1842 /2542HR/2642/3242S HR ADR/3542/4142 12.7Lt.#....-2022#890#",//--FORD--10059
"FORD#1848T - Midilli 12.7Lt.#....-2022#890#",//--FORD--10063
"FORD#2533 / 3233  9Lt.#....-2022#940#",//--FORD--10067
"FORD#F-Max  12.7Lt.#....-2022#890#",//--FORD--10071
"ISUZU#GRAFTER 3.0 N50/5.2D horizontal condenser#2008-2011#500#",//--10073-10103ISUZU--10075
"ISUZU#GRAFTER 3.0 N50 /5.2D vertical condenser#2008-2011#400#",//--ISUZU--10079
"ISUZU#GRAFTER 1.9D#2017-2020#350#",//--ISUZU--10083
"ISUZU#GRAFTER 3.0 N35 Sasi No.JAANLR/JAANMR#2014-2017#350#",//--ISUZU--10087
"ISUZU#GRAFTER 3.0 N35 Sasi No.JAANNR/JAANPR#2014-2017#400#",//--ISUZU--10091
"ISUZU#N-Series 5.2D#2005-2008#450#",//--ISUZU--10095
"ISUZU#N-Series horizontal condenser#2008-2011#500#",//--ISUZU--10099
"ISUZU#N-Series vertical condenser#2008-2011#400#",//--ISUZU--10103
"IVECO#DAILY I#1996-1999#800#",//--10105-10203IVECO--10107
"IVECO#DAILY I#1999-2002#720#",//--IVECO--10111
"IVECO#DAILY II Combi#1999-2002#1200#",//--IVECO--10115
"IVECO#DAILY II#2003-2006#720#",//--IVECO--10119
"IVECO#DAILY II Combi Minibus#2003-2004#1200#",//--IVECO--10123
"IVECO#DAILY III (F1A) Van#2006-2015#720#",//--IVECO--10127
"IVECO#DAILY III (F1C) 3,0 D#2006-2015#440#",//--IVECO--10131
"IVECO#DAILY#2016-2020#475#",//--IVECO--10135
"IVECO#ECODAILY Minibus#2009-2014#1200#",//--IVECO--10139
"IVECO#ECODAILY Van#2009-2014#720#",//--IVECO--10143
"IVECO#ECODAILY 3,0D#2009-2011#440#",//--IVECO--10147
"IVECO#EUROCARGO 2 kondenser#1991-2001#1600#",//--IVECO--10151
"IVECO#EUROCARGO#2001-2003#1020#",//--IVECO--10155
"IVECO#EUROCARGO#2003-2015#440#",//--IVECO--10159
"IVECO#EUROSTAR#1992-2000#1700#",//--IVECO--10163
"IVECO#EUROSTAR side condenser#1992-2000#1900#",//--IVECO--10167
"IVECO#EUROSTAR#2000-2004#1700#",//--IVECO--10171
"IVECO#EUROTECH#1992-1999#1700#",//--IVECO--10175
"IVECO#EUROTECH side condenser#1992-1999#1900#",//--IVECO--10179
"IVECO#EUROTECH#2000-2008#1700#",//--IVECO--10183
"IVECO#EUROTRAKKER#2000-2004#1750#",//--IVECO--10187
"IVECO#STRALIS AT/AD#2001-2012#700#",//--IVECO--10191
"IVECO#STRALIS AT/AD side condenser#2001-2012#1400#",//--IVECO--10195
"IVECO#STRALIS HI-WAY#2012-2015#700#",//--IVECO--10199
"IVECO#TRAKKER#2004-2015#700#",//--IVECO--10203
"MAN#F 2000#1995-1999#1150#",//--10205-10279MAN--10207
"MAN#F 2000 round condenser#1999-2015#1150#",//--MAN--10211
"MAN#F 2000 flat condenser#1999-2015#950#",//--MAN--10215
"MAN#L 2000#1995-1999#1150#",//--MAN--10219
"MAN#L 2000 round condenser#2000-2015#1150#",//--MAN--10223
"MAN#L 2000 flat condenser#2000-2015#950#",//--MAN--10227
"MAN#M 2000 L#1995-1999#1150#",//--MAN--10231
"MAN#M 2000 M#1995-1999#1150#",//--MAN--10235
"MAN#M 2000 round condenser#1999-2015#1150#",//--MAN--10239
"MAN#M 2000 flat condenser#1999-2015#950#",//--MAN--10243
"MAN#M 90#1990-1996#1250#",//--MAN--10247
"MAN#TG-A#2000-2009#900#",//--MAN--10251
"MAN#TGA independent A/C#2000-2009#1050#",//--MAN--10255
"MAN#TGL#2005-2015#650#",//--MAN--10259
"MAN#TGM#2005-2015#750#",//--MAN--10263
"MAN#TGS#2007-2015#900#",//--MAN--10267
"MAN#independent AC#2007-2015#1050#",//--MAN--10271
"MAN#TGX#2007-2015#900#",//--MAN--10275
"MAN#independent A/C#2007-2015#1050#",//--MAN--10279
"MERCEDES BENZ#ACTROS 1996#1997-2002#1100#",//--10281-10363MERCEDES BENZ--10283
"MERCEDES BENZ#ACTROS 2003#2003-2011#1150#",//--MERCEDES BENZ--10287
"MERCEDES BENZ#ACTROS 2003 independent A/C#2003-2011#1600#",//--MERCEDES BENZ--10291
"MERCEDES BENZ#ACTROS#2012-2015#1080#",//--MERCEDES BENZ--10295
"MERCEDES BENZ#ACTTOS independent A/C#2012-2015#1280#",//--MERCEDES BENZ--10299
"MERCEDES BENZ#AROCS#2013-2015#1080#",//--MERCEDES BENZ--10303
"MERCEDES BENZ#AROCS independent A/C#2013-2015#1280#",//--MERCEDES BENZ--10307
"MERCEDES BENZ#ANTOS#2012-2015#1080#",//--MERCEDES BENZ--10311
"MERCEDES BENZ#ANTOS independent A/C#2012-2015#1280#",//--MERCEDES BENZ--10315
"MERCEDES BENZ#ATEGO I#1998-2004#1000#",//--MERCEDES BENZ--10319
"MERCEDES BENZ#ATEGOII K956641#2004-2015#1200#",//--MERCEDES BENZ--10323
"MERCEDES BENZ#ATEGOII K956642#2004-2015#550#",//--MERCEDES BENZ--10327
"MERCEDES BENZ#ATEGO (967)#2013-2015#550#",//--MERCEDES BENZ--10331
"MERCEDES BENZ#AXOR#2001-2004#1150#",//--MERCEDES BENZ--10335
"MERCEDES BENZ#AXOR II#2004-2015#1100#",//--MERCEDES BENZ--10339
"MERCEDES BENZ#ECONIC#1998-2011#800#",//--MERCEDES BENZ--10343
"MERCEDES BENZ#T1/TN 407-410#1993-1995#700#",//--MERCEDES BENZ--10347
"MERCEDES BENZ#T2/LN1 507-711#1993-1995#860#",//--MERCEDES BENZ--10351
"MERCEDES BENZ#UNIMOG U300-500#2000-2004#1400#",//--MERCEDES BENZ--10355
"MERCEDES BENZ#VARIO#1996-2011#1225#",//--MERCEDES BENZ--10359
"MERCEDES BENZ#ZETROS#2008-2015#1250#",//--MERCEDES BENZ--10363
"MITSUBISHI#Canter#2006-2015#650#",//--10365-10367MITSUBISHI--10367
"NISSAN#ATLEON 110,140 514109#1999-2015#900#",//--10369-10387NISSAN--10371
"NISSAN#ATLEON 165,210 514109#1999-2015#950#",//--NISSAN--10375
"NISSAN#ATLEON 514110#1999-2015#750#",//--NISSAN--10379
"NISSAN#CABSTAR E#1998-2015#750#",//--NISSAN--10383
"NISSAN#CABSTAR#2006-2015#300#",//--NISSAN--10387
"RENAULT V.I.#KERAX#1997-1999#1400#",//--10389-10439RENAULT V.I.--10391
"RENAULT V.I.#KERAX#2002-2006#1550#",//--RENAULT V.I.--10395
"RENAULT V.I.#KERAX#2007-2015#1250#",//--RENAULT V.I.--10399
"RENAULT V.I.#MAGNUM#1996-1999#1450#",//--RENAULT V.I.--10403
"RENAULT V.I.#MAGNUM E.TECH#2000-2015#1450#",//--RENAULT V.I.--10407
"RENAULT V.I.#MASCOTT 2.8 DdCi#1999-2010#890#",//--RENAULT V.I.--10411
"RENAULT V.I.#MASCOTT 3.0D Dxi#2007-2015#750#",//--RENAULT V.I.--10415
"RENAULT V.I.#Maxity 2.5D / 3.0D#2007-2015#300#",//--RENAULT V.I.--10419
"RENAULT V.I.#MIDLINER M#1996-1999#1200#",//--RENAULT V.I.--10423
"RENAULT V.I.#MIDLINER S#1995-1999#1200#",//--RENAULT V.I.--10427
"RENAULT V.I.#MIDLUM#1999-2015#1200#",//--RENAULT V.I.--10431
"RENAULT V.I.#PREMIUM#1996-2006#1400#",//--RENAULT V.I.--10435
"RENAULT V.I.#PREMIUM II#2005-2015#1200#",//--RENAULT V.I.--10439
"SCANIA#93 H, M#1988-1996#800#",//--10441-10511SCANIA--10443
"SCANIA#94 C, D, G, L#1996-2015#1450#",//--SCANIA--10447
"SCANIA#113 E, H, M#1991-1996#800#",//--SCANIA--10451
"SCANIA#114 C, G, L#1998-2015#1450#",//--SCANIA--10455
"SCANIA#124 C, G, L#1996-2015#1450#",//--SCANIA--10459
"SCANIA#143 E, H, M#1991-1996#800#",//--SCANIA--10463
"SCANIA#144 C, G, L#1995-2015#1450#",//--SCANIA--10467
"SCANIA#164 C, G, L#2000-2015#1450#",//--SCANIA--10471
"SCANIA#G-Series#2004-2015#1250#",//--SCANIA--10475
"SCANIA#P-Series#2004-2015#1250#",//--SCANIA--10479
"SCANIA#R-Series#2004-2015#1250#",//--SCANIA--10483
"SCANIA#T 93 H#1990-1996#800#",//--SCANIA--10487
"SCANIA#T 94 C, G, L#1996-2015#1450#",//--SCANIA--10491
"SCANIA#T 113 E, H#1990-1996#800#",//--SCANIA--10495
"SCANIA#T 114 C, G, L#1998-2015#1450#",//--SCANIA--10499
"SCANIA#T 124 C, G, L#1996-2015#1450#",//--SCANIA--10503
"SCANIA#T 143 E, H#1991-1996#800#",//--SCANIA--10507
"SCANIA#T 144 C, G, L#1995-2015#1450#",//--SCANIA--10511
"VOLVO#F 10#1990-1993#1400#",//--10513-10587VOLVO--10515
"VOLVO#F 12#1990-1993#1400#",//--VOLVO--10519
"VOLVO#F 16#1990-1993#1400#",//--VOLVO--10523
"VOLVO#FE#2006-2015#1280#",//--VOLVO--10527
"VOLVO#FH#2003-2015#1175#",//--VOLVO--10531
"VOLVO#FH 12#1999-2005#1250#",//--VOLVO--10535
"VOLVO#FH 13#2005-2015#1250#",//--VOLVO--10539
"VOLVO#FH 16#1993-2015#1250#",//--VOLVO--10543
"VOLVO#FL 6#1993-1999#1150#",//--VOLVO--10547
"VOLVO#FL 7#2006-2013#1200#",//--VOLVO--10551
"VOLVO#FL II#2006-2015#1200#",//--VOLVO--10555
"VOLVO#FM 7#1998-2002#1150#",//--VOLVO--10559
"VOLVO#FM 9#2003-2009#1250#",//--VOLVO--10563
"VOLVO#FM 10#1999-2015#1150#",//--VOLVO--10567
"VOLVO#FM 11#2008-2013#1250#",//--VOLVO--10571
"VOLVO#FM 12#1998-2005#1250#",//--VOLVO--10575
"VOLVO#FM 13#2005-2015#1250#",//--VOLVO--10579
"VOLVO#FMX#2010-2015#1250#",//--VOLVO--10583
"VOLVO#NH 12#1999-2008#1250#",//--VOLVO--10587
"KIA#K2500#2004-2007#450#",//--10589-10603KIA--10591
"KIA#K2700#2000-2004#450#",//--KIA--10595
"KIA#K2900#2008-2012#450#",//--KIA--10599
"KIA#K900#2017-2018#650#",//--KIA--10603
                     //10607  model sonu
"*",                       //10091  model sonu
};

const char* const model_1234yf[] PROGMEM = {
"Alfa Romeo#4C 240hp#2013-2019#370#",//--1-15Alfa Romeo--3
"Alfa Romeo#Giulia#2016-2022#535#",//--Alfa Romeo--7
"Alfa Romeo#Giulietta 2,0D JTM 16V 136hp#2015-2022#420#",//--Alfa Romeo--11
"Alfa Romeo#Stelvio#2017-2022#535#",//--Alfa Romeo--15
//"Aston Martin###0#",//--17-19Aston Martin--19
"Audi#A1#2016-2018#450#",//--21-359Audi--23
"Audi#A1#2019-2022#430#",//--Audi--27
"Audi#A1 Sportback 2.0#2018-2022#390#",//--Audi--31
"Audi#A3 Sportback/2.0 40TFS#2016-2022#460#",//--Audi--35
"Audi#A3 E-TRON Hybrid#2016-2018#450#",//--Audi--39
"Audi#A4#2016-2022#525#",//--Audi--43
"Audi#A5#2016-2022#525#",//--Audi--47
"Audi#A6 (4G/C7) Quattro#2011-2020#530#",//--Audi--51
"Audi#A7#2010-2020#530#",//--Audi--55
"Audi#A7 2.0 TFSI/ TDI MHEV Hybrid#2020-2022#510#",//--Audi--59
"Audi#A8 (4H)#2010-2020#700#",//--Audi--63
"Audi#A8 (4H) Rear A/C#2010-2020#890#",//--Audi--67
"Audi#A8 2.0 Hybrid#2012-2016#890#",//--Audi--71
"Audi#A8 3.0 50 TDI#2017-2022#510#",//--Audi--75
"Audi#Q2#2016-2022#460#",//--Audi--79
"Audi#Q3#2016-2020#530#",//--Audi--83
"Audi#Q3 1.5 35TFSI#2020-2021#460#",//--Audi--87
"Audi#Q3#2020-2022#450#",//--Audi--91
"Audi#Q4 e-TRON R1234yf Hybrid#2021-2022#460#",//--Audi--95
"Audi#Q5#2008-2019#520#",//--Audi--99
"Audi#Q5 FYB 17-#2017-2019#525#",//--Audi--103
"Audi#Q5 FYB 17-2,0 TFSI#2016-2019#525#",//--Audi--107
"Audi#Q5 2.0 MHEV Hiybrid#2017-2022#525#",//--Audi--111
"Audi#Q7#2016-2022#680#",//--Audi--115
"Audi#Q7 with Rear A/C#2016-2022#850#",//--Audi--119
"Audi#Q7 E-TRON PHEV  Hybrid#2019-2022#840#",//--Audi--123
"Audi#Q7 4MG 210kw PHEV Hybrid R1234yf#2019-2022#680#",//--Audi--127
"Audi#Q8#2019-2022#680#",//--Audi--131
"Audi#RS 3#2016-2018#520#",//--Audi--135
"Audi#RS 4#2012-2015#525#",//--Audi--139
"Audi#RS 5#2010-2018#570#",//--Audi--143
"Audi#RS 6#2016-2018#435#",//--Audi--147
"Audi#RS 6 4.0 TFSI#2019-2022#575#",//--Audi--151
"Audi#RS 7#2016-2018#530#",//--Audi--155
"Audi#RS 7 4.0 TFSI#2019-2022#575#",//--Audi--159
"Audi#RS Q3#2015-2018#530#",//--Audi--163
"Audi#RS e-tron GT R1234YF#2021-2022#930#",//--Audi--167
"Audi#R8#2017-2018#835#",//--Audi--171
"Audi#S1/S1 Sportback#2012-2018#450#",//--Audi--175
"Audi#S3#2016-2018#460#",//--Audi--179
"Audi#S4#2019-2022#525#",//--Audi--183
"Audi#S5#2017-2022#525#",//--Audi--187
"Audi#S6#2012-2018#530#",//--Audi--191
"Audi#S6 2.9 TFSI#2020-2022#510#",//--Audi--195
"Audi#S7#2014-2018#530#",//--Audi--199
"Audi#S7#2019-2022#510#",//--Audi--203
"Audi#S7 2.9 TFSI#2020-2022#620#",//--Audi--207
"Audi#S8#2014-2018#700#",//--Audi--211
"Audi#S8 with Rear A/C#2014-2018#890#",//--Audi--215
"Audi#SQ5#2016-2018#520#",//--Audi--219
"Audi#SQ5 FYB 3,0 TFSI#2017-2022#525#",//--Audi--223
"Audi#SQ7#2016-2019#680#",//--Audi--227
"Audi#SQ7 with Rear A/C#2016-2019#850#",//--Audi--231
"Audi#SQ7 4.0D TDI#2019-2022#680#",//--Audi--235
"Audi#SQ7 4.0D TDI with Rear A/C#2019-2022#850#",//--Audi--239
"Audi#TT#2016-2022#460#",//--Audi--243
"Audi#TT TFSI RS#2018-2022#520#",//--Audi--247
"Audi#A3 E-TRON Hybrid#2016-2018#500#",//--Audi--251
"Audi#A3 E-TRON R1234YF GAS Hybrid#2016-2018#450#",//--Audi--255
"Audi#A4 2.0 40TFSI MHEV R1234YFHybrid#2019-2022#525#",//--Audi--259
"Audi#A4 2.0 40/45 TFSI MHEV R134A Hybrid#2019-2022#590#",//--Audi--263
"Audi#A5 2.0 30TFSI MHEV R1234YFHybrid#2020-2022#525#",//--Audi--267
"Audi#A6 Hybrid#2012-2015#860#",//--Audi--271
"Audi#A6 2.0 30 TDI MHEV R134A Hybrid#2019-2022#590#",//--Audi--275
"Audi#A7 2.0 35 TDI MHEV R1234yf Hybrid#2020-2022#510#",//--Audi--279
"Audi#A8 2.0 Hybrid#2012-2016#1080#",//--Audi--283
"Audi#A8 3.0 50 TDI Hybrid R1234yf#2017-2022#510#",//--Audi--287
"Audi#A8 3.0 50 TDI Hybrid R134A#2017-2022#570#",//--Audi--291
"Audi#e-tron 230kw /370kw elec R134A#2019-2022#840#",//--Audi--295
"Audi#Q3 1.5 35TFSI R1234yf#2020-2022#460#",//--Audi--299
"Audi#Q4 e-TRON/Sportback R1234yf Hybrid#2021-2022#460#",//--Audi--303
"Audi#Q5 Hiybrid#2011-2016#840#",//--Audi--307
"Audi#Q5 2.0 MHEV Hiybrid R1234yf#2017-2022#525#",//--Audi--311
"Audi#Q5 2.0 MHEV Hiybrid R134A#2017-2022#590#",//--Audi--315
"Audi#Q7 E-TRON PHEV  Hybrid#2016-2018#890#",//--Audi--319
"Audi#Q7 4MG 210kw PHEV Hybrid R1234yf#2019-2022#680#",//--Audi--323
"Audi#Q8#2019-2022#680#",//--Audi--327
"Audi#RS e-tron GT R1234YF#2021-2022#930#",//--Audi--331
"Audi#RS 7 4.0 TFSI#2019-2022#575#",//--Audi--335
"Audi#S4#2019-2022#525#",//--Audi--339
"Audi#S5 R1234YF#2017-2022#525#",//--Audi--343
"Audi#S5 R134A#2017-2022#590#",//--Audi--347
"Audi#S6 2.9 TFSI R1234YF#2020-2022#510#",//--Audi--351
"Audi#S7  R1234YF#2019-2022#510#",//--Audi--355
"Audi#S7 2.9 TFSI#2020-2022#620#",//--Audi--359
"BMW#1-Series#2016-2018#550#",//--361-675BMW--363
"BMW#1-Series (F40)#2019-2022#520#",//--BMW--367
"BMW#2-Series ACTIVE TOURER#2016-2020#500#",//--BMW--371
"BMW#2-Series 218i/ 220d ACTIVE TOURER#2017-2022#480#",//--BMW--375
"BMW#2-Series CABRIOLET#2015-2020#500#",//--BMW--379
"BMW#2-Series CABRIOLET M240i/xDrive#2015-2020#550#",//--BMW--383
"BMW#2-Series COUPE#2015-2020#550#",//--BMW--387
"BMW#2-Series GRAN TOURER#2015-2018#500#",//--BMW--391
"BMW#3-Series 320i/330i/340i#2016-2020#540#",//--BMW--395
"BMW#3-Series#2018-2022#550#",//--BMW--399
"BMW#4-Series#2016-2022#550#",//--BMW--403
"BMW#5-Series#2017-2022#550#",//--BMW--407
"BMW#5-Series 520i/530i/540i#2017-2022#600#",//--BMW--411
"BMW#5-Series 530e Hybrid#2017-2022#750#",//--BMW--415
"BMW#5-Series 550i / 4,4 M5#2017-2022#650#",//--BMW--419
"BMW#6-Series#2016-2018#850#",//--BMW--423
"BMW#6-Series GRAN TURSIMO#2017-2018#600#",//--BMW--427
"BMW#6-Series GRAN TURSIMO 630i/640i#2017-2022#600#",//--BMW--431
"BMW#6-Series GRAN TURSIMO /640i 245kw(333hp)#2018-2022#550#",//--BMW--435
"BMW#7-Series / d#2016-2022#550#",//--BMW--439
"BMW#7-Series / d with Rear A/C#2016-2022#800#",//--BMW--443
"BMW#7-Series 730i/740i#2016-2022#600#",//--BMW--447
"BMW#7-Series 730i/740i with Rear A/C#2016-2022#850#",//--BMW--451
"BMW#7-Series 740e Hybrid#2016-2022#750#",//--BMW--455
"BMW#7-Series 745e#2019-2022#750#",//--BMW--459
"BMW#7-Series 750i/760i#2016-2022#650#",//--BMW--463
"BMW#7-Series 750i/760i with Rear A/C#2016-2022#880#",//--BMW--467
"BMW#8-Series / d xDrive#2018-2022#650#",//--BMW--471
"BMW#8-Series / 4.4M850i xDrive#2020-2022#650#",//--BMW--475
"BMW#8-Series / 840i xDrive#2018-2022#550#",//--BMW--479
"BMW#8-Series /d xDrive Hybrid#2020-2022#550#",//--BMW--483
"BMW#i3#2013-2022#750#",//--BMW--487
"BMW#i3 Heat pump#2013-2022#970#",//--BMW--491
"BMW#i8#2014-2022#630#",//--BMW--495
"BMW#X1#2016-2022#500#",//--BMW--499
"BMW#X1 xDrive 25e#2020-2022#600#",//--BMW--503
"BMW#X2#2016-2022#500#",//--BMW--507
"BMW#X2 18i#2020-2022#500#",//--BMW--511
"BMW#X2 M35i#2020-2022#500#",//--BMW--515
"BMW#X2 25e#2020-2022#650#",//--BMW--519
"BMW#X3#2017-2022#550#",//--BMW--523
"BMW#X4#2014-2018#500#",//--BMW--527
"BMW#X4#2019-2022#550#",//--BMW--531
"BMW#X5#2016-2018#675#",//--BMW--535
"BMW#X5#2019-2022#600#",//--BMW--539
"BMW#X5 M50#2018-2020#650#",//--BMW--543
"BMW#X5 40i#2019-2022#580#",//--BMW--547
"BMW#X5 40i 5-zone climate#2019-2022#800#",//--BMW--551
"BMW#X5 4.4 50i#2019-2022#650#",//--BMW--555
"BMW#X5 4.4 50i 5-zone climate#2019-2022#900#",//--BMW--559
"BMW#X5 3.0 xDrive 45e#2019-2020#850#",//--BMW--563
"BMW#X6#2016-2019#675#",//--BMW--567
"BMW#X6 (G06)#2019-2022#650#",//--BMW--571
"BMW#X7 3.0 M50d M50i#2018-2020#650#",//--BMW--575
"BMW#X7 3.0 M50d M50i 5-zone climate#2018-2020#900#",//--BMW--579
"BMW#X7#2018-2022#600#",//--BMW--583
"BMW#X7 5-zone climate#2018-2022#850#",//--BMW--587
"BMW#X7 40i#2018-2022#580#",//--BMW--591
"BMW#X7 40i 5-zone climate#2018-2022#800#",//--BMW--595
"BMW#Z4#2018-2022#550#",//--BMW--599
"BMW#4-Series#2020-2022#550#",//--BMW--603
"BMW#5-Series 2.0 520i Hybrid#2020-2022#600#",//--BMW--607
"BMW#5-Series 530e Hybrid#2017-2022#750#",//--BMW--611
"BMW#6-Series GRAN TURSIMO#2018-2022#550#",//--BMW--615
"BMW#7-Series 740e#2016-2019#750#",//--BMW--619
"BMW#7-Series 745e#2019-2022#750#",//--BMW--623
"BMW#7-Series 740d mhev#2020-2022#550#",//--BMW--627
"BMW#7-Series 740d mhev with Rear A/C#2020-2022#800#",//--BMW--631
"BMW#8-Series /d xDrive Hybrid#2020-2022#550#",//--BMW--635
"BMW#i3#2013-2022#750#",//--BMW--639
"BMW#i3 Heat pump#2013-2022#970#",//--BMW--643
"BMW#i8#2014-2022#630#",//--BMW--647
"BMW#X1 xDrive 25e#2020-2022#600#",//--BMW--651
"BMW#X2 25e#2020-2022#650#",//--BMW--655
"BMW#X5 40i#2019-2022#580#",//--BMW--659
"BMW#X5 40i 5-zone climate#2019-2022#800#",//--BMW--663
"BMW#X5 3.0 xDrive 45e#2019-2020#850#",//--BMW--667
"BMW#X7#2018-2022#600#",//--BMW--671
"BMW#X7 5-zone climate#2018-2022#850#",//--BMW--675
"Cadillac#ATS#2016-2019#550#",//--677-687Cadillac--679
"Cadillac#CTS#2016-2020#550#",//--Cadillac--683
"Cadillac#Escalade 6.0 hybrid#2011-2014#725#",//--Cadillac--687
"Chevrolet#Malibu#2016-2018#600#",//--689-695Chevrolet--691
"Chevrolet#Trax#2014-2016#620#",//--Chevrolet--695
"Chrysler#300 C#2012-2015#710#",//--697-699Chrysler--699
"Citroen#Berlingo IV#2018-2022#450#",//--701-839Citroen--703
"Citroen#C1 II#2016-2022#350#",//--Citroen--707
"Citroen#C3 IV#2016-2018#425#",//--Citroen--711
"Citroen#C3 Aircross#2017-2022#400#",//--Citroen--715
"Citroen#C4 Cactus#2014-2022#425#",//--Citroen--719
"Citroen#C4 Cactus 1,5 HDI/1,6 HDI#2014-2022#400#",//--Citroen--723
"Citroen#C4 II#2014-2018#375#",//--Citroen--727
"Citroen#C4 II BLUE HDI#2014-2018#425#",//--Citroen--731
"Citroen#C4 Picasso (Grand)#2015-2018#450#",//--Citroen--735
"Citroen#C4 Picasso (Grand) with rear a/c#2015-2018#625#",//--Citroen--739
"Citroen#C4 Space Tourer / Grand Space#2018-2020#450#",//--Citroen--743
"Citroen#C4 Space Tourer / Grand Space with rear a/c#2018-2020#675#",//--Citroen--747
"Citroen#C5 III#2014-2018#475#",//--Citroen--751
"Citroen#C5 Aircross 1930cm Condanser#2018-2022#440#",//--Citroen--755
"Citroen#C5 Aircross 2350cm Condanser#2018-2022#515#",//--Citroen--759
"Citroen#C-Elysee#2014-2020#450#",//--Citroen--763
"Citroen#C-Zero Electric 47kw(64hp)#2010-2015#325#",//--Citroen--767
"Citroen#C-Zero Electric 49kw(67hp)#2013-2020#280#",//--Citroen--771
"Citroen#Jumper/RelayIII Minibus#2006-2019#935#",//--Citroen--775
"Citroen#Dispatch/Jumpy IV#2016-2022#450#",//--Citroen--779
"Citroen#Dispatch/JumpyIV 1.5/1.6HDI very hot climates#2016-2022#650#",//--Citroen--783
"Citroen#Dispatch IV 1.5/1.6 HDI dual zone a/c#2016-2022#900#",//--Citroen--787
"Citroen#Dispatch IV 2.0 HDI dual zone a/c#2016-2022#775#",//--Citroen--791
"Citroen#DS3/DS3 Cabrio#2011-2015#450#",//--Citroen--795
"Citroen#e-Mehari 50kw#2016-2020#350#",//--Citroen--799
"Citroen#Nemo 1,3, HD#2015-2018#430#",//--Citroen--803
"Citroen#Space Tourer#2016-2022#450#",//--Citroen--807
"Citroen#Space Tourer 2.0 HDI(DUAL ZONE)#2016-2022#775#",//--Citroen--811
"Citroen#Space Tourer very hot climates#2016-2022#650#",//--Citroen--815
"Citroen#Space Tourer (DUAL ZONE)#2016-2022#900#",//--Citroen--819
"Citroen#C-Zero Electric 47kw(64hp)#2010-2015#325#",//--Citroen--823
"Citroen#C-Zero Electric 49kw(67hp)#2013-2020#280#",//--Citroen--827
"Citroen#DS5 Hiybrid#2012-2015#450#",//--Citroen--831
"Citroen#e-Berlingo Hybrid R134a#2017-2022#525#",//--Citroen--835
"Citroen#e-Mehari 50kw#2016-2020#350#",//--Citroen--839
"Cupra#Ateca#2020-2022#460#",//--841-867Cupra--843
"Cupra#Formentor 1.4 eHybrid R1234yf#2021-2022#460#",//--Cupra--847
"Cupra#Formentor 1.5 TSI#2021-2022#460#",//--Cupra--851
"Cupra#Leon#2021-2022#460#",//--Cupra--855
"Cupra#Formentor 1.4 eHybrid R1234yf#2021-2022#460#",//--Cupra--859
"Cupra#Leon  eHybrid R1234yf#2021-2022#460#",//--Cupra--863
"Cupra#Leon  eHybrid R134a#2021-2022#500#",//--Cupra--867
"Dacia#Dokker motor#2015-2019#440#",//--869-895Dacia--871
"Dacia#Duster#2015-2022#450#",//--Dacia--875
"Dacia#Symbol II#2016-2018#450#",//--Dacia--879
"Dacia#Logan 1.0 SCe75 Standard(N1)#2016-2020#400#",//--Dacia--883
"Dacia#Logan 1.0 SCe75 (N2)#2016-2020#450#",//--Dacia--887
"Dacia#Sandero#2015-2022#450#",//--Dacia--891
"Dacia#Sandero 1.0#2015-2022#400#",//--Dacia--895
//"Daewoo###0#",//--897-899Daewoo--899
//"Daihatsu###0#",//--901-903Daihatsu--903
//"Dodge###0#",//--905-907Dodge--907
"Ds#Ds- 3 / Crossback#2015-2022#450#",//--909-955Ds--911
"Ds#Ds- 3 II#2015-2018#450#",//--Ds--915
"Ds#Ds- 4#2015-2018#475#",//--Ds--919
"Ds#Ds- 4 Crossback#2015-2018#475#",//--Ds--923
"Ds#Ds- 4 II#2015-2018#475#",//--Ds--927
"Ds#Ds- 5#2015-2019#475#",//--Ds--931
"Ds#Ds- 5 Hybrid#2015-2018#475#",//--Ds--935
"Ds#Ds- 7#2015-2022#450#",//--Ds--939
"Ds#Ds- 7 19mm Condanser#2018-2022#435#",//--Ds--943
"Ds#Ds- 7 23mm Condanser#2018-2022#590#",//--Ds--947
"Ds#Ds- 7 28mm Condanser#2018-2022#600#",//--Ds--951
"Ds#Ds- 5 Hybrid#2015-2018#475#",//--Ds--955
"Fiat#124 Spider#2016-2019#360#",//--957-1007Fiat--959
"Fiat#500C#2010-2022#400#",//--Fiat--963
"Fiat#500L#2018-2022#420#",//--Fiat--967
"Fiat#500X#2014-2022#450#",//--Fiat--971
"Fiat#Doblo#2015-2022#430#",//--Fiat--975
"Fiat#Ducato#2016-2020#535#",//--Fiat--979
"Fiat#Ducato with rear a/c#2016-2020#935#",//--Fiat--983
"Fiat#Egea#2016-2022#420#",//--Fiat--987
"Fiat#Fiorino#2015-2020#430#",//--Fiat--991
"Fiat#Qubo#2010-2020#430#",//--Fiat--995
"Fiat#Talento#2016-2019#590#",//--Fiat--999
"Fiat#Talento with rear a/c#2016-2019#880#",//--Fiat--1003
"Fiat#Tipo New#2015-2022#420#",//--Fiat--1007
"Ford#B-Max 1.0 EcoBoost/1.6TDCi#2016-2018#600#",//--1009-1283Ford--1011
"Ford#B-Max 1.5TDCi#2016-2018#550#",//--Ford--1015
"Ford#B-Max 1.4i/1.6Ti (Sigma)#2016-2018#600#",//--Ford--1019
"Ford#C-Max#2016-2020#550#",//--Ford--1023
"Ford#C-Max 1.5 TDCI#2016-2020#530#",//--Ford--1027
"Ford#C-Max 1.6 TI-VCT#2016-2018#620#",//--Ford--1031
"Ford#C-Max 2.0 TDCI#2016-2020#620#",//--Ford--1035
"Ford#Edge#2016-2022#570#",//--Ford--1039
"Ford#Ecosport / Escape#2016-2018#625#",//--Ford--1043
"Ford#Ecosport / Escape#2018-2022#475#",//--Ford--1047
"Ford#Ecosport 1.0 EcoBoost#2016-2018#630#",//--Ford--1051
"Ford#Fiesta  1.6D TDCi kond 12mm (f)#2016-2022#450#",//--Ford--1055
"Ford#Fiesta  1.0 L Ecoboost Otomatik#2017-2022#650#",//--Ford--1059
"Ford#Fiesta  1.0 L Ecoboost#2017-2019#520#",//--Ford--1063
"Ford#Fiesta  1.5 ST Ecoboost#2018-2022#550#",//--Ford--1067
"Ford#Fiesta  1.1 L Duratech TiVCT#2019-2022#500#",//--Ford--1071
"Ford#Fiesta  1.1 L Duratorq 1,5 TDCI#2017-2022#490#",//--Ford--1075
"Ford#Fiesta VI1.25i/1.4i/1.6Ti kond 12mm#2016-2022#390#",//--Ford--1079
"Ford#Fiesta VI 1.4/1,5 TDCI 12mm kond.#2016-2022#390#",//--Ford--1083
"Ford#Fiesta VI1.25i/1.4i/1.6Ti kond 16mm#2016-2022#520#",//--Ford--1087
"Ford#Fiesta VI 1.4/1.5 TDCi kond. 16mm#2016-2022#520#",//--Ford--1091
"Ford#Fiesta VI 1.6 TDCi kond. 16mm#2016-2022#520#",//--Ford--1095
"Ford#Fiesta 1.0L EcoBoost kond. 16mm#2016-2022#620#",//--Ford--1099
"Ford#Fiesta 1.6L EcoBoost kond. 16mm#2016-2022#675#",//--Ford--1103
"Ford#Focus III1.0L Ecoboost,    TDCI#2016-2018#530#",//--Ford--1107
"Ford#Focus III 1.0L EcoBoost Otomatik#2016-2018#580#",//--Ford--1111
"Ford#Focus III 1.0L EcoBoost(74kw/90kw)#2016-2018#530#",//--Ford--1115
"Ford#Focus III 1.5L/1.6L/ 2.0#2016-2018#600#",//--Ford--1119
"Ford#Focus III 2.0 TDCI#2016-2018#625#",//--Ford--1123
"Ford#Focus RS Electric#2016-2022#600#",//--Ford--1127
"Ford#Focus#2018-2022#480#",//--Ford--1131
"Ford#Focus 2.3 ST#2019-2022#500#",//--Ford--1135
"Ford#Galaxy#2018-2022#525#",//--Ford--1139
"Ford#Galaxy  with rearA/C#2018-2022#740#",//--Ford--1143
"Ford#KA  1.2L Sigma Ti-VCT#2016-2020#590#",//--Ford--1147
"Ford#Kuga           1.5 Benzin#2016-2022#480#",//--Ford--1151
"Ford#Kuga           1.5 Dizel#2016-2022#480#",//--Ford--1155
"Ford#Kuga           2.0 Dizel#2016-2020#600#",//--Ford--1159
"Ford#Mondeo#2015-2022#570#",//--Ford--1163
"Ford#Mustang 2.3L EcoBoost/5.0L 32V Ti-VCT#2014-2022#600#",//--Ford--1167
"Ford#S-Max 2.0L Duratorq TDCI#2016-2022#570#",//--Ford--1171
"Ford#S-Max 2.0L Duratorq TDCI with rearA/C#2016-2022#910#",//--Ford--1175
"Ford#S-Max 1.5L/2.0L Ecoboost#2016-2022#570#",//--Ford--1179
"Ford#S-Max (1.5L/2,0L) with rear A/C#2016-2022#965#",//--Ford--1183
"Ford#S-Max#2018-2022#570#",//--Ford--1187
"Ford#S-Max with rear A/C#2018-2022#965#",//--Ford--1191
"Ford#Transit/Tourneo COURIER 1,0L/1,5LTDCI#2016-2022#575#",//--Ford--1195
"Ford#Transit/Tourneo COURIER 1,6L TDCI#2016-2018#670#",//--Ford--1199
"Ford#Transit/Tourneo Connect Van#2016-2022#525#",//--Ford--1203
"Ford#Transit/Tourneo Connect1,6L/2,5L TDCI#2016-2018#570#",//--Ford--1207
"Ford#Transit/Tourneo Connect with rear A/C#2016-2022#800#",//--Ford--1211
"Ford#Transit/Tourneo1,6L Eco/2,5L with A/C#2016-2018#675#",//--Ford--1215
"Ford#Transit Custom#2012-2022#740#",//--Ford--1219
"Ford#Transit Custom Bus with rear A/C#2012-2022#1050#",//--Ford--1223
"Ford#Transit Custom Van with rear A/C#2012-2022#1150#",//--Ford--1227
"Ford#Puma   1,0 Eco-Boost#2019-2022#500#",//--Ford--1231
"Ford#Puma   Duratorq TDCI#2019-2022#460#",//--Ford--1235
"Ford#Ranger#2016-2022#565#",//--Ford--1239
"Ford#Fiesta  1.0L Ecoboost Otomatik Hybrid#2020-2022#650#",//--Ford--1243
"Ford#Fiesta  1.0L Ecoboost  Hybrid#2020-2022#500#",//--Ford--1247
"Ford#Focus Electric(107kw)  1234YF#2014-2022#600#",//--Ford--1251
"Ford#Focus Electric(107kw)  R134A#2014-2022#750#",//--Ford--1255
"Ford#Kuga New(yeni) 2.0 Hybrid#2019-2022#480#",//--Ford--1259
"Ford#Kuga New(yeni) 2.5 Hybrid#2019-2022#550#",//--Ford--1263
"Ford#Transit Custom#2012-2022#740#",//--Ford--1267
"Ford#Transit Custom Bus with rear A/C#2012-2022#1050#",//--Ford--1271
"Ford#Transit Custom Van with rear A/C#2012-2022#1150#",//--Ford--1275
"Ford#Mondeo   2.0 Hiybrid#2018-2022#570#",//--Ford--1279
"Ford#Puma 1.0  Eco-Boost Hybrid#2019-2022#500#",//--Ford--1283
"Gunsel#B9 Electric#2020-    #595#",//--1285-1287Gunsel--1287
"Honda#Accord#2017-2022#475#",//--1289-1355Honda--1291
"Honda#Accord Hybrid#2017-2022#430#",//--Honda--1295
"Honda#Clarity Fuel Cell  Hybrid#2017-2018#445#",//--Honda--1299
"Honda#Civic#2017-2022#400#",//--Honda--1303
"Honda#Civic RHD#2017-2022#430#",//--Honda--1307
"Honda#CRV#2015-2018#440#",//--Honda--1311
"Honda#CRV#2018-2022#460#",//--Honda--1315
"Honda#CRV LHD#2015-2018#410#",//--Honda--1319
"Honda#CRV 2.0 e-HEV#2019-2022#440#",//--Honda--1323
"Honda#HR-V#2015-2022#420#",//--Honda--1327
"Honda#Jazz / FIT#2015-2020#400#",//--Honda--1331
"Honda#Jazz 1.5 e-HEV#2020-2022#420#",//--Honda--1335
"Honda#Accord Hybrid#2017-2018#430#",//--Honda--1339
"Honda#Clarity Fuel Cell  Hybrid#2017-2020#445#",//--Honda--1343
"Honda#CRV 2.0 e-HEV#2019-2022#440#",//--Honda--1347
"Honda#CR-Z 1.5 Hybrid IMA#2010-2015#475#",//--Honda--1351
"Honda#Jazz 1.5 e-HEV#2020-2022#420#",//--Honda--1355
"Hyundai#Accent#2017-2019#445#",//--1357-1483Hyundai--1359
"Hyundai#Bayon#2020-2022#470#",//--Hyundai--1363
"Hyundai#Elantra#2016-2022#500#",//--Hyundai--1367
"Hyundai#i10#2015-2020#400#",//--Hyundai--1371
"Hyundai#i10#2020-2022#430#",//--Hyundai--1375
"Hyundai#i20#2015-2020#470#",//--Hyundai--1379
"Hyundai#i20#2020-2022#430#",//--Hyundai--1383
"Hyundai#i30#2008-2022#500#",//--Hyundai--1387
"Hyundai#ix35 Fuel cell 100kw#2013-2018#550#",//--Hyundai--1391
"Hyundai#i40#2011-2020#500#",//--Hyundai--1395
"Hyundai#IONIQ electric (poe oil)#2016-2022#550#",//--Hyundai--1399
"Hyundai#IONIQ models with heat pump#2016-2019#1100#",//--Hyundai--1403
"Hyundai#IONIQ models with heat pump#2019-2022#1000#",//--Hyundai--1407
"Hyundai#IONIQ 1,6 GDI Hybrid (poe oil)#2016-2022#600#",//--Hyundai--1411
"Hyundai#Kona#2017-2020#450#",//--Hyundai--1415
"Hyundai#Kona#2020-2022#500#",//--Hyundai--1419
"Hyundai#Santa Fe#2015-2018#550#",//--Hyundai--1423
"Hyundai#Santa Fe with rear a/c#2015-2018#750#",//--Hyundai--1427
"Hyundai#Santa Fe (CM)#2018-2020#625#",//--Hyundai--1431
"Hyundai#Santa Fe (CM) with rear a/c#2018-2020#800#",//--Hyundai--1435
"Hyundai#Tuscon#2015-2018#600#",//--Hyundai--1439
"Hyundai#Tuscon#2019-2022#550#",//--Hyundai--1443
"Hyundai#Tuscon  1.6 T-GDI Hybrid#2021-2022#650#",//--Hyundai--1447
"Hyundai#IONIQ electric (poe oil)#2016-2022#550#",//--Hyundai--1451
"Hyundai#IONIQ models with heat pump#2016-2019#1100#",//--Hyundai--1455
"Hyundai#IONIQ models with heat pump#2019-2022#1000#",//--Hyundai--1459
"Hyundai#IONIQ 1,6 GDI Hybrid (poe oil)#2016-2022#600#",//--Hyundai--1463
"Hyundai#Kona Electric#2018-2020#450#",//--Hyundai--1467
"Hyundai#Tuscon 2.0 CRDI Hybrid#2011-2022#600#",//--Hyundai--1471
"Hyundai#Tuscon  CRDI Hybrid#2020-2022#550#",//--Hyundai--1475
"Hyundai#Tuscon  1.6 T-GDI Hybrid#2021-2022#650#",//--Hyundai--1479
"Hyundai#Kona#2021-2022#500#",//--Hyundai--1483
//"Ikco###0#",//--1485-1487Ikco--1487
"Infiniti#Q30#2016-2020#650#",//--1489-1491Infiniti--1491
//"Isuzu###0#",//--1493-1495Isuzu--1495
//"Iveco###0#",//--1497-1499Iveco--1499
"Jaguar#E-Pace#2017-2022#650#",//--1501-1539Jaguar--1503
"Jaguar#F-Pace#2016-2020#550#",//--Jaguar--1507
"Jaguar#F-Type Coupe#2014-2020#600#",//--Jaguar--1511
"Jaguar#I-Pace Electric#2018-2022#850#",//--Jaguar--1515
"Jaguar#XE#2015-2020#550#",//--Jaguar--1519
"Jaguar#XF#2017-2020#550#",//--Jaguar--1523
"Jaguar#XJ (X351)#2010-2020#700#",//--Jaguar--1527
"Jaguar#XJR#2013-2020#700#",//--Jaguar--1531
"Jaguar#E-Pace#2020-2022#650#",//--Jaguar--1535
"Jaguar#I-Pace Electric#2018-2022#850#",//--Jaguar--1539
"Jeep#Cherokee#2014-2018#510#",//--1541-1571Jeep--1543
"Jeep#Grand Cherokee#2012-2022#570#",//--Jeep--1547
"Jeep#Compass#2017-2022#480#",//--Jeep--1551
"Jeep#Compass Hybrid#2020-2022#500#",//--Jeep--1555
"Jeep#Wrangler#2016-2018#510#",//--Jeep--1559
"Jeep#Wrangler#2018-2022#480#",//--Jeep--1563
"Jeep#Renegade#2018-2020#450#",//--Jeep--1567
"Jeep#Compass#2020-2022#500#",//--Jeep--1571
"Kia#Cadenza#2017-2018#550#",//--1573-1735Kia--1575
"Kia#Carens II#2014-2019#550#",//--Kia--1579
"Kia#Grand Carnival - Sedona#2016-2018#1100#",//--Kia--1583
"Kia#Ceed/Pro-Ceed#2016-2022#500#",//--Kia--1587
"Kia#Cerato dizel/Benzin#2016-2022#500#",//--Kia--1591
"Kia#K900#2017-2018#650#",//--Kia--1595
"Kia#Niro  Hybrid#2016-2020#550#",//--Kia--1599
"Kia#e-Niro  Electric#2019-2022#650#",//--Kia--1603
"Kia#e-Niro  Electric with heat pump#2019-2022#1000#",//--Kia--1607
"Kia#e-Soul  Electric#2019-2022#600#",//--Kia--1611
"Kia#Optima#2015-2018#470#",//--Kia--1615
"Kia#Optima 2,0 Hybrid#2016-2019#650#",//--Kia--1619
"Kia#Picanto#2016-2020#370#",//--Kia--1623
"Kia#Picanto#2020-2022#400#",//--Kia--1627
"Kia#Pro-Ceed#2016-2022#500#",//--Kia--1631
"Kia#Rio#2017-2022#450#",//--Kia--1635
"Kia#Seltos#2020-2022#450#",//--Kia--1639
"Kia#Sportage#2017-2022#600#",//--Kia--1643
"Kia#Stinger#2017-2022#570#",//--Kia--1647
"Kia#Stonic#2017-2020#450#",//--Kia--1651
"Kia#Sorento (UM)#2015-2020#650#",//--Kia--1655
"Kia#Sorento (UM) with rear a/c#2015-2020#800#",//--Kia--1659
"Kia#Sorento#2020-2022#575#",//--Kia--1663
"Kia#Sorento with rear a/c#2020-2022#800#",//--Kia--1667
"Kia#Sorento Hybrid#2020-2022#650#",//--Kia--1671
"Kia#Sorento Hybrid with rear a/c#2020-2022#900#",//--Kia--1675
"Kia#Soul / 0 EV Hybrid#2015-2018#550#",//--Kia--1679
"Kia#Soul#2019-2022#450#",//--Kia--1683
"Kia#XCeed#2019-2022#500#",//--Kia--1687
"Kia#Ceed#2020-2022#500#",//--Kia--1691
"Kia#e-Niro  Electric#2020-2022#650#",//--Kia--1695
"Kia#e-Niro  Electric with heat pump#2020-2022#1000#",//--Kia--1699
"Kia#e-Soul  Electric#2019-2022#600#",//--Kia--1703
"Kia#Niro  Hybrid#2016-2020#550#",//--Kia--1707
"Kia#Optima 2,0 Hybrid#2016-2019#650#",//--Kia--1711
"Kia#Pro-Ceed Hybrid#2020-2022#500#",//--Kia--1715
"Kia#Rio#2020-2022#450#",//--Kia--1719
"Kia#Sorento Hybrid#2020-2022#650#",//--Kia--1723
"Kia#Sorento with rear a/c#2020-2022#900#",//--Kia--1727
"Kia#Sportage#2019-2022#600#",//--Kia--1731
"Kia#XCeed#2020-2022#500#",//--Kia--1735
"Lancia#Ypsilon#2015-2022#450#",//--1737-1739Lancia--1739
"Land Rover#Defender#2019-2022#650#",//--1741-1887Land Rover--1743
"Land Rover#Defender three zone a/c#2019-2022#1000#",//--Land Rover--1747
"Land Rover#Discovery#2017-2022#800#",//--Land Rover--1751
"Land Rover#Discovery SPORT#2017-2020#650#",//--Land Rover--1755
"Land Rover#Discovery Four zone#2017-2022#1150#",//--Land Rover--1759
"Land Rover#Discovery SPORT#2020-2022#525#",//--Land Rover--1763
"Land Rover#Discovery SPORT with rear a/c#2020-2022#725#",//--Land Rover--1767
"Land Rover#Range Rov 2.0/3.0/4.4SDV8/SDV6/TDV6#2017-2020#800#",//--Land Rover--1771
"Land Rover#Range Rov2.0/3.0/4.4SDV8/SDV6/TDV6 four-zone#2017-2020#1150#",//--Land Rover--1775
"Land Rover#Range Rover 2.0 P400e#2020-2022#950#",//--Land Rover--1779
"Land Rover#Range Rover 2.0 P400e four-zone#2020-2022#1100#",//--Land Rover--1783
"Land Rover#Range Rover 3.0/5.0#2019-2022#800#",//--Land Rover--1787
"Land Rover#Range Rover 3.0/5.0  four-zone#2019-2022#1000#",//--Land Rover--1791
"Land Rover#Range Rover Evoque#2017-2020#650#",//--Land Rover--1795
"Land Rover#Range Rover Evoque#2020-2022#525#",//--Land Rover--1799
"Land Rover#Range Rover Sport#2020-2022#650#",//--Land Rover--1803
"Land Rover#Range Rover Sport (Four Zone)#2020-2022#1000#",//--Land Rover--1807
"Land Rover#Range Rover Sport Hybrid#2014-2018#800#",//--Land Rover--1811
"Land Rover#Range Rover Sport Hybrid(Four Zone)#2014-2018#1150#",//--Land Rover--1815
"Land Rover#Range Rover Sport 4.4(Four Zone)#2014-2020#1100#",//--Land Rover--1819
"Land Rover#Range Rover Velar#2017-2022#550#",//--Land Rover--1823
"Land Rover#Defender#2020-2022#650#",//--Land Rover--1827
"Land Rover#Defender three zone a/c#2020-2022#1000#",//--Land Rover--1831
"Land Rover#Discovery#2020-2022#800#",//--Land Rover--1835
"Land Rover#Discovery SPORT#2020-2022#525#",//--Land Rover--1839
"Land Rover#Discovery SPORT with rear a/c#2020-2022#725#",//--Land Rover--1843
"Land Rover#Discovery Four zone#2020-2022#1150#",//--Land Rover--1847
"Land Rover#Range Rover 2.0 P400e#2017-2020#800#",//--Land Rover--1851
"Land Rover#Range Rover 2.0 P400e four-zone#2017-2020#1150#",//--Land Rover--1855
"Land Rover#Range Rover 3.0#2019-2022#800#",//--Land Rover--1859
"Land Rover#Range Rover 3.0  four-zone#2019-2022#1000#",//--Land Rover--1863
"Land Rover#Evoque 2,0D 150 MHEV#2019-2020#650#",//--Land Rover--1867
"Land Rover#Range Rover Evoque#2020-2022#525#",//--Land Rover--1871
"Land Rover#Range Rover Sport 3.0#2015-2017#800#",//--Land Rover--1875
"Land Rover#Range Rover Sport 3.0(Four Zone)#2015-2017#1000#",//--Land Rover--1879
"Land Rover#Range Rover Sport Hybrid#2014-2018#800#",//--Land Rover--1883
"Land Rover#Range Rover Sport Hybrid(Four Zone)#2014-2018#1150#",//--Land Rover--1887
"LDV#V80 4,8 KW comp.#2015-2022#600#",//--1889-1911LDV--1891
"LDV#V80 7,0 KW comp.#2015-2022#700#",//--LDV--1895
"LDV#V80 Double compressor#2015-2022#600#",//--LDV--1899
"LDV#V80 with rear a/c SWB#2015-2022#1450#",//--LDV--1903
"LDV#V80 with rear a/c LWB#2015-2022#1750#",//--LDV--1907
"LDV#V80 Auxiliary condenser#2015-2022#2020#",//--LDV--1911
"Lexus#CT 200h#2015-2022#470#",//--1913-2015Lexus--1915
"Lexus#ES#2019-2022#610#",//--Lexus--1919
"Lexus#ES 300h Hybrid#2019-2020#550#",//--Lexus--1923
"Lexus#GS Hybrid (Komp.poe oil)#2015-2018#500#",//--Lexus--1927
"Lexus#GS 5,0F#2015-2018#570#",//--Lexus--1931
"Lexus#IS/RC Hybrid 2,5 300H(Komp.poe oil)#2013-2022#500#",//--Lexus--1935
"Lexus#IS/RC Hybrid (Komp.poe oil)#2015-2018#570#",//--Lexus--1939
"Lexus#LC#2017-2022#550#",//--Lexus--1943
"Lexus#LC with rear a/c#2017-2021#700#",//--Lexus--1947
"Lexus#LS#2017-2018#550#",//--Lexus--1951
"Lexus#LS with rear a/c#2017-2018#700#",//--Lexus--1955
"Lexus#LS 3,4 500 4WD#2018-2022#650#",//--Lexus--1959
"Lexus#NX Hybrid (Komp.poe oil)#2014-2022#500#",//--Lexus--1963
"Lexus#RC 300h#2015-2022#570#",//--Lexus--1967
"Lexus#RX#2016-2022#520#",//--Lexus--1971
"Lexus#UX#2019-2022#470#",//--Lexus--1975
"Lexus#CT 200h Hybrid#2010-2022#470#",//--Lexus--1979
"Lexus#ES 300h Hybrid#2019-2020#550#",//--Lexus--1983
"Lexus#IS/RC Hybrid 2,5 300H(Komp.poe oil)#2013-2022#500#",//--Lexus--1987
"Lexus#LC#2017-2022#550#",//--Lexus--1991
"Lexus#LS 3,4 500 4WD#2018-2022#650#",//--Lexus--1995
"Lexus#NX Hybrid (Komp.poe oil)#2018-2022#500#",//--Lexus--1999
"Lexus#RC 300h#2015-2022#570#",//--Lexus--2003
"Lexus#RX for R134a#2018-2022#500#",//--Lexus--2007
"Lexus#RX for R1234yf#2018-2022#520#",//--Lexus--2011
"Lexus#UX#2019-2022#470#",//--Lexus--2015
"Mahindra#XUV 500#2014-2018#",//--2017-2019Mahindra--2019
"Mazda#2 Engine 1,5#2016-2020#385#",//--2021-2087Mazda--2023
"Mazda#2 Engine 1,5D#2016-2022#360#",//--Mazda--2027
"Mazda#3 Engine 1,5/2,0#2016-2018#500#",//--Mazda--2031
"Mazda#3 Engine 1,5D/2,2#2016-2018#470#",//--Mazda--2035
"Mazda#3 1,8D/2,0 MHEV#2019-2022#480#",//--Mazda--2039
"Mazda#6 Engine 2,0/2,5#2016-2022#500#",//--Mazda--2043
"Mazda#6 Engine 2,2D#2016-2020#470#",//--Mazda--2047
"Mazda#CX 3 Engine 1,5D#2016-2022#385#",//--Mazda--2051
"Mazda#CX 3 Engine 2,0#2016-2022#360#",//--Mazda--2055
"Mazda#CX 5 Engine 2,0/2,5#2015-2022#500#",//--Mazda--2059
"Mazda#CX 5 Engine 2,2D#2015-2022#470#",//--Mazda--2063
"Mazda#CX 9#2017-2018#615#",//--Mazda--2067
"Mazda#CX 30#2019-2022#480#",//--Mazda--2071
"Mazda#MX 5#2016-2022#360#",//--Mazda--2075
"Mazda#3 1,8D/2,0 MHEV#2019-2022#480#",//--Mazda--2079
"Mazda#CX 30 for R1234yf#2019-2022#480#",//--Mazda--2083
"Mazda#CX 30 for R134a#2019-2022#490#",//--Mazda--2087
"Mcc/Smart#Forfour Electric#2017-2018#430#",//--2089-2103Mcc/Smart--2091
"Mcc/Smart#Forfour#2017-2019#475#",//--Mcc/Smart--2095
"Mcc/Smart#Fortwo#2016-2019#475#",//--Mcc/Smart--2099
"Mcc/Smart#Forfour Electric#2017-2018#430#",//--Mcc/Smart--2103
"Mercedes#A-Class 2,0 A45 AMG 4Matic#2015-2020#630#",//--2105-2563Mercedes--2107
"Mercedes#A-Class#2018-2020#530#",//--Mercedes--2111
"Mercedes#A-Class 1.3 A250e#2018-2020#600#",//--Mercedes--2115
"Mercedes#B-Class B250E / Electric Drive#2015-2018#680#",//--Mercedes--2119
"Mercedes#B-Class#2018-2020#630#",//--Mercedes--2123
"Mercedes#B-Class#2020-2022#530#",//--Mercedes--2127
"Mercedes#B-Class Hybrid#2020-2022#600#",//--Mercedes--2131
"Mercedes#C-Class Cabriolet/Coupe#2014-2022#630#",//--Mercedes--2135
"Mercedes#C-Class 2,0 C350E / C350 Hybrid#2015-2018#670#",//--Mercedes--2139
"Mercedes#C-Class 1,5 C200 Hybrid#2019-2022#630#",//--Mercedes--2143
"Mercedes#C-Class 2,1D C300 BlueTEC Hybrid#2014-2015#710#",//--Mercedes--2147
"Mercedes#C-Class 2,1 C300 Hybrid#2015-2018#690#",//--Mercedes--2151
"Mercedes#C-Class Cabriolet Coupe 4,0 C63 AMG#2015-2020#600#",//--Mercedes--2155
"Mercedes#C-Class 1.5/2.0  EQ Boost Hybrid#2021-2022#570#",//--Mercedes--2159
"Mercedes#Citan#2016-2022#450#",//--Mercedes--2163
"Mercedes#CLA Shooting Brake#2015-2020#630#",//--Mercedes--2167
"Mercedes#CLA Coupe 2,0 45 AMG 4 Matic#2015-2022#630#",//--Mercedes--2171
"Mercedes#CLS#2018-2022#630#",//--Mercedes--2175
"Mercedes#CLS 3,0 AMG Hybrid#2018-2022#590#",//--Mercedes--2179
"Mercedes#E-Class  Coupe/Cabriolet#2017-2022#630#",//--Mercedes--2183
"Mercedes#E-Class  E350d /E400d#2018-2020#630#",//--Mercedes--2187
"Mercedes#E-Class  2,0 E350e Hybrid#2016-2022#670#",//--Mercedes--2191
"Mercedes#E-Class  4,0 E63 AMG 4MATIC#2017-2020#550#",//--Mercedes--2195
"Mercedes#E-Class  E220d All-Terrain#2017-2022#570#",//--Mercedes--2199
"Mercedes#E-Class E450/E53 EQ Boost#2018-2022#590#",//--Mercedes--2203
"Mercedes#E-Class 4.0 E63 AMG S#2018-2022#550#",//--Mercedes--2207
"Mercedes#EQV Electric#2019-2022#660#",//--Mercedes--2211
"Mercedes#e-Vito Electric#2018-2022#660#",//--Mercedes--2215
"Mercedes#G 63 AMG#2017-2018#820#",//--Mercedes--2219
"Mercedes#G 65 AMG#2017-2018#820#",//--Mercedes--2223
"Mercedes#G 550#2017-2018#780#",//--Mercedes--2227
"Mercedes#GLA#2014-2020#630#",//--Mercedes--2231
"Mercedes#GLA#2020-2022#530#",//--Mercedes--2235
"Mercedes#GLA 45 AMG 4Matic#2020-2022#960#",//--Mercedes--2239
"Mercedes#GLA 45 AMG S 4Matic#2020-2022#1050#",//--Mercedes--2243
"Mercedes#GLB#2019-2022#690#",//--Mercedes--2247
"Mercedes#GLC / Coupe#2015-2022#630#",//--Mercedes--2251
"Mercedes#GLC / Coupe 2,0 E350e 4Matic Hybrid#2016-2019#670#",//--Mercedes--2255
"Mercedes#GLE / Coupe / GLS#2015-2019#1000#",//--Mercedes--2259
"Mercedes#GLE / Coupe / GLS  with rear a/c#2015-2019#1250#",//--Mercedes--2263
"Mercedes#GLE / Coupe / GLS#2019-2022#690#",//--Mercedes--2267
"Mercedes#GLE 350d/450/580/AMG#2019-2022#740#",//--Mercedes--2271
"Mercedes#GLS#2016-2019#1000#",//--Mercedes--2275
"Mercedes#GLS with rear a/c#2016-2019#1250#",//--Mercedes--2279
"Mercedes#GLS#2019-2022#690#",//--Mercedes--2283
"Mercedes#GLS with rear a/c#2019-2022#960#",//--Mercedes--2287
"Mercedes#MAYBACH#2017-2020#640#",//--Mercedes--2291
"Mercedes#MAYBACH with rear a/c#2017-2020#730#",//--Mercedes--2295
"Mercedes#MAYBACH GLS with rear a/c#2020-2022#960#",//--Mercedes--2299
"Mercedes#MAYBACH GLS#2020-2022#690#",//--Mercedes--2303
"Mercedes#S-Class S400#2013-2015#730#",//--Mercedes--2307
"Mercedes#S-Class S400 with rear a/c#2013-2015#850#",//--Mercedes--2311
"Mercedes#S-Class Cabriolet / Coupe#2016-2022#640#",//--Mercedes--2315
"Mercedes#S-Class Cabriolet / Coupe with rear a/c#2016-2022#730#",//--Mercedes--2319
"Mercedes#S-Class S560e#2018-2022#670#",//--Mercedes--2323
"Mercedes#S-Class S560e with rear a/c#2018-2022#800#",//--Mercedes--2327
"Mercedes#SL#2015-2020#550#",//--Mercedes--2331
"Mercedes#SLC CLASS#2015-2020#550#",//--Mercedes--2335
"Mercedes#Sprinter D50/D51/D64#2018-2022#600#",//--Mercedes--2339
"Mercedes#Sprinter G42/G43#2018-2022#800#",//--Mercedes--2343
"Mercedes#Sprinter HH7 / HH9 /IR4#2018-2022#1725#",//--Mercedes--2347
"Mercedes#Sprinter H08 and IR4#2018-2022#1800#",//--Mercedes--2351
"Mercedes#Sprinter HH7/HH9 and IR6/IR7#2018-2022#1825#",//--Mercedes--2355
"Mercedes#Sprinter H08 and IR6/IR7#2018-2022#1900#",//--Mercedes--2359
"Mercedes#Sprinter HK4 and IR4 CEILING MOUNTED AIR CONDITIONER#2018-2022#1100#",//--Mercedes--2363
"Mercedes#Sprinter HK4 and IR6/IR7 CEILING MOUNTED AIR CONDITIONER#2018-2022#1200#",//--Mercedes--2367
"Mercedes#Vito#2014-2022#600#",//--Mercedes--2371
"Mercedes#Vito with rear a/c#2014-2022#900#",//--Mercedes--2375
"Mercedes#X-CLASS#2017-2019#500#",//--Mercedes--2379
"Mercedes#A-Class 1.3 A250e#2018-2020#600#",//--Mercedes--2383
"Mercedes#A-Class 1.3 A250e for R134a#2018-2020#660#",//--Mercedes--2387
"Mercedes#B-Class Hybrid for R134a#2020-2022#660#",//--Mercedes--2391
"Mercedes#B-Class Hybrid#2020-2022#600#",//--Mercedes--2395
"Mercedes#C-Class 2,0 C350E / C350 Hybrid#2015-2018#670#",//--Mercedes--2399
"Mercedes#C-Class 1,5 C200 /C300 Hybrid#2019-2022#630#",//--Mercedes--2403
"Mercedes#C-Class 2,1D C300 BlueTEC Hybrid#2014-2015#710#",//--Mercedes--2407
"Mercedes#C-Class 2,1 C300 Hybrid#2015-2018#690#",//--Mercedes--2411
"Mercedes#C-Class 1.5/2.0EQ Boost Hybrid#2021-2022#570#",//--Mercedes--2415
"Mercedes#C-Class 1.5/2.0EQ Boost for R134a Hybrid#2021-2022#620#",//--Mercedes--2419
"Mercedes#CLA Coupe#2020-2022#630#",//--Mercedes--2423
"Mercedes#CLA Coupe for R134a#2020-2022#690#",//--Mercedes--2427
"Mercedes#CLS 3,0 AMG Hybrid#2018-2022#590#",//--Mercedes--2431
"Mercedes#E-Class  Coupe/Cabriolet#2019-2022#630#",//--Mercedes--2435
"Mercedes#E-Class  2,0 E350e Hybrid#2016-2022#670#",//--Mercedes--2439
"Mercedes#E-Class  R744#2019-2022#340#",//--Mercedes--2443
"Mercedes#E-Class  E220d All-Terrain R744#2017-2022#340#",//--Mercedes--2447
"Mercedes#E-Class 4.0 E63 AMG S#2018-2022#550#",//--Mercedes--2451
"Mercedes#E-Class 4.0 E63 AMG S R744#2018-2022#340#",//--Mercedes--2455
"Mercedes#EQV Electric#2019-2022#660#",//--Mercedes--2459
"Mercedes#e-Vito Electric#2018-2022#660#",//--Mercedes--2463
"Mercedes#GLA#2020-2022#530#",//--Mercedes--2467
"Mercedes#GLA for R134a Hybrid#2020-2022#590#",//--Mercedes--2471
"Mercedes#GLC / Coupe#2020-2022#630#",//--Mercedes--2475
"Mercedes#GLE 350/450/580/AMG#2019-2022#740#",//--Mercedes--2479
"Mercedes#GLE 350/450/580/AMG for R134a Hybrid#2019-2022#770#",//--Mercedes--2483
"Mercedes#GLS for R134a#2019-2022#720#",//--Mercedes--2487
"Mercedes#GLS for R134a with rear a/c#2019-2022#1010#",//--Mercedes--2491
"Mercedes#GLS#2019-2022#690#",//--Mercedes--2495
"Mercedes#GLS with rear a/c#2019-2022#960#",//--Mercedes--2499
"Mercedes#MAYBACH GLS with rear a/c#2020-2022#960#",//--Mercedes--2503
"Mercedes#MAYBACH GLS#2020-2022#690#",//--Mercedes--2507
"Mercedes#MAYBACH GLS for R134a with rear a/c#2020-2022#1010#",//--Mercedes--2511
"Mercedes#MAYBACH GLS for R134a#2020-2022#720#",//--Mercedes--2515
"Mercedes#S-Class for R134a S400#2013-2015#770#",//--Mercedes--2519
"Mercedes#S-Class for R134a S400 with rear a/c#2013-2015#870#",//--Mercedes--2523
"Mercedes#S-Class S400#2013-2015#730#",//--Mercedes--2527
"Mercedes#S-Class S400 with rear a/c#2013-2015#850#",//--Mercedes--2531
"Mercedes#S-Class S500/560e Plun-in for R134a#2014-2015#710#",//--Mercedes--2535
"Mercedes#S-Class S500/560e forR134a with rear a/c#2014-2015#820#",//--Mercedes--2539
"Mercedes#S-Class R1234yf#2017-2022#640#",//--Mercedes--2543
"Mercedes#S-Class R1234yf with rear a/c#2017-2022#730#",//--Mercedes--2547
"Mercedes#S-Class for R134a#2017-2022#660#",//--Mercedes--2551
"Mercedes#S-Class for R134a with rear a/c#2017-2022#770#",//--Mercedes--2555
"Mercedes#S-Class for R744#2019-2022#420#",//--Mercedes--2559
"Mercedes#S-Class for R744 with rear a/c#2019-2022#450#",//--Mercedes--2563
"MG Motor#MG3#2013-2018#450#",//--2565-2567MG Motor--2567
"Mini Cooper#Mini Hatch Electric#2020-2022#550#",//--2569-2599Mini Cooper--2571
"Mini Cooper#Mini Hatch 1.5/2.0#2020-2022#480#",//--Mini Cooper--2575
"Mini Cooper#Cooper/ Clubman/ Countryman /Paceman#2015-2022#480#",//--Mini Cooper--2579
"Mini Cooper#COUNTRYMAN 1.5 One D#2017-2022#550#",//--Mini Cooper--2583
"Mini Cooper#COUNTRYMAN#2017-2022#500#",//--Mini Cooper--2587
"Mini Cooper#COUNTRYMAN 1,5 Cooper Hybrid#2017-2022#640#",//--Mini Cooper--2591
"Mini Cooper#Mini Hatch Electric#2020-2022#550#",//--Mini Cooper--2595
"Mini Cooper#COUNTRYMAN 1,5 Cooper Hybrid#2017-2022#650#",//--Mini Cooper--2599
"Mitsubishi#ASX#2015-2019#500#",//--2601-2659Mitsubishi--2603
"Mitsubishi#Attrage#2017-2018#270#",//--Mitsubishi--2607
"Mitsubishi#Canter#2006-2017#650#",//--Mitsubishi--2611
"Mitsubishi#Canter TD Large cabin#2006-2017#600#",//--Mitsubishi--2615
"Mitsubishi#Eclipse Cross#2017-2022#450#",//--Mitsubishi--2619
"Mitsubishi#Mirage#2013-2020#270#",//--Mitsubishi--2623
"Mitsubishi#L200#2019-2022#550#",//--Mitsubishi--2627
"Mitsubishi#Lancer#2016-2018#500#",//--Mitsubishi--2631
"Mitsubishi#i-MiEV#2010-2020#280#",//--Mitsubishi--2635
"Mitsubishi#Outlander#2016-2022#550#",//--Mitsubishi--2639
"Mitsubishi#Outlander 2,0/2,4 PHEV Hybrid R1234yf#2016-2022#515#",//--Mitsubishi--2643
"Mitsubishi#Space Star#2013-2022#270#",//--Mitsubishi--2647
"Mitsubishi#i-MiEV R1234YF#2010-2020#280#",//--Mitsubishi--2651
"Mitsubishi#Outlander 2,0/2,4 PHEV Hybrid R1234yf#2016-2022#515#",//--Mitsubishi--2655
"Mitsubishi#Outlander 2,0/2,4 PHEV for R134a#2016-2022#540#",//--Mitsubishi--2659
"Nissan#370Z (Z34)#2014-2022#500#",//--2661-2747Nissan--2663
"Nissan#e-Evalia (Komp.poe oil)#2014-2022#450#",//--Nissan--2667
"Nissan#e-Evalia with rear a/c#2014-2018#650#",//--Nissan--2671
"Nissan#e-NV200 (Komp.poe oil)#2014-2022#450#",//--Nissan--2675
"Nissan#GT-R 3,8 Nismo#2016-2022#500#",//--Nissan--2679
"Nissan#Juke#2015-2022#450#",//--Nissan--2683
"Nissan#Leaf#2015-2020#425#",//--Nissan--2687
"Nissan#Leaf Denso ESB27 COMP.#2019-2020#850#",//--Nissan--2691
"Nissan#Micra (K14)#2016-2022#435#",//--Nissan--2695
"Nissan#NV400 2,3 CDTI#2016-2019#570#",//--Nissan--2699
"Nissan#NV400 2,3 CDTI 9 seat#2016-2019#1090#",//--Nissan--2703
"Nissan#NV400 2,3 CDTI 16 seat#2016-2019#1690#",//--Nissan--2707
"Nissan#NV400 2,3 CDTI#2019-2022#580#",//--Nissan--2711
"Nissan#Note#2014-2018#400#",//--Nissan--2715
"Nissan#Pulsar#2014-2018#450#",//--Nissan--2719
"Nissan#Qashqai#2014-2022#500#",//--Nissan--2723
"Nissan#X-Trail#2014-2022#500#",//--Nissan--2727
"Nissan#X-Trail 1.3 DIG-T#2020-2022#475#",//--Nissan--2731
"Nissan#e-Evalia Electric (Komp.poe oil)#2014-2022#450#",//--Nissan--2735
"Nissan#e-NV200 (Komp.poe oil)#2014-2022#450#",//--Nissan--2739
"Nissan#Leaf Electric#2010-2020#425#",//--Nissan--2743
"Nissan#Leaf  Electric Denso ESB27 COMP.#2019-2020#850#",//--Nissan--2747
"Opel#Adam#2016-2019#420#",//--2749-2887Opel--2751
"Opel#Ampera-e(Komp.poe oil)#2017-2020#725#",//--Opel--2755
"Opel#Antara 2,0 CDTI#2016-2018#650#",//--Opel--2759
"Opel#Astra K#2016-2019#480#",//--Opel--2763
"Opel#Combo D#2016-2018#435#",//--Opel--2767
"Opel#Combo E#2018-2022#450#",//--Opel--2771
"Opel#Corsa E 1,3 CDTI#2015-2020#390#",//--Opel--2775
"Opel#Corsa F#2019-2022#340#",//--Opel--2779
"Opel#Corsa F 1.2 Turbo/ 1.5D#2019-2022#360#",//--Opel--2783
"Opel#CROSLAND X#2017-2022#400#",//--Opel--2787
"Opel#CROSLAND X Additional heater#2017-2022#425#",//--Opel--2791
"Opel#GRANDLAND X 1900CM2 CONDANSER#2017-2022#450#",//--Opel--2795
"Opel#GRANDLAND X 2300CM2 CONDANSER#2017-2022#525#",//--Opel--2799
"Opel#GTC#2018-2019#600#",//--Opel--2803
"Opel#GTC 1,6D - 1,6 SIDI#2018-2019#630#",//--Opel--2807
"Opel#Insignia B#2017-2018#550#",//--Opel--2811
"Opel#Insignia B#2018-2020#400#",//--Opel--2815
"Opel#KARL#2015-2020#380#",//--Opel--2819
"Opel#Mokka X#2016-2020#570#",//--Opel--2823
"Opel#Movano B#2016-2018#580#",//--Opel--2827
"Opel#Movano B with rear a/c#2016-2018#1700#",//--Opel--2831
"Opel#Viva#2015-2019#380#",//--Opel--2835
"Opel#Vivaro#2016-2019#540#",//--Opel--2839
"Opel#Vivaro Bluinjection#2019-2022#450#",//--Opel--2843
"Opel#Vivaro Electric#2020-2022#450#",//--Opel--2847
"Opel#Zafira C Tourer#2016-2018#630#",//--Opel--2851
"Opel#Zafira C Tourer 2.0 CTI#2018-2019#590#",//--Opel--2855
"Opel#Zafira Life Bluinjection#2019-2022#450#",//--Opel--2859
"Opel#Zafira Life Bluinjection Dual Zone#2019-2022#900#",//--Opel--2863
"Opel#Zafira Life 1930CM2 CONDANSER#2020-2022#525#",//--Opel--2867
"Opel#Zafira Life 2350CM2 CONDANSER#2020-2022#850#",//--Opel--2871
"Opel#Ampera-e(Komp.poe oil)#2017-2020#725#",//--Opel--2875
"Opel#Vivaro Electric#2020-2022#450#",//--Opel--2879
"Opel#Zafira Life 1930CM2 CONDANSER#2020-2022#525#",//--Opel--2883
"Opel#Zafira Life 2350CM2 CONDANSER#2020-2022#850#",//--Opel--2887
//"Perodua###0#",//--2889-2891Perodua--2891
"Peugeot#108#2014-2020#350#",//--2893-3099Peugeot--2895
"Peugeot#208#2014-2019#400#",//--Peugeot--2899
"Peugeot#208  1600cm2X12mm#2019-2022#400#",//--Peugeot--2903
"Peugeot#208  2000cm2X12mm#2019-2022#425#",//--Peugeot--2907
"Peugeot#301#2014-2018#450#",//--Peugeot--2911
"Peugeot#308 (1930cm condanser)#2013-2022#400#",//--Peugeot--2915
"Peugeot#308 (2350cm 12mm condanser)#2013-2022#525#",//--Peugeot--2919
"Peugeot#308 (2350cm 16mm condanser)#2013-2022#575#",//--Peugeot--2923
"Peugeot#508#2015-2018#525#",//--Peugeot--2927
"Peugeot#508 (1900cm 12mm condanser)#2018-2022#400#",//--Peugeot--2931
"Peugeot#508 (2800cm 16mm condanser)#2018-2022#575#",//--Peugeot--2935
"Peugeot#508 Hybrid#2020-2022#700#",//--Peugeot--2939
"Peugeot#2008#2013-2022#400#",//--Peugeot--2943
"Peugeot#3008 (1900cm condanser)#2016-2022#450#",//--Peugeot--2947
"Peugeot#3008 (2300cm condanser)#2016-2022#525#",//--Peugeot--2951
"Peugeot#3008 Hybrid#2019-2022#725#",//--Peugeot--2955
"Peugeot#5008 (1900cm condanser)#2016-2022#450#",//--Peugeot--2959
"Peugeot#5008 (2300cm condanser)#2016-2022#525#",//--Peugeot--2963
"Peugeot#Boxer III#2019-2022#935#",//--Peugeot--2967
"Peugeot#Expert IV Except Hot Climate#2016-2018#450#",//--Peugeot--2971
"Peugeot#Expert IV With Hot Climate#2016-2018#650#",//--Peugeot--2975
"Peugeot#Expert IV Dual Zone#2016-2018#900#",//--Peugeot--2979
"Peugeot#Expert IV 2,0 Bluehdi Single Zone#2016-2022#450#",//--Peugeot--2983
"Peugeot#Expert IV 2,0 Bluehdi Dual Zone#2016-2022#775#",//--Peugeot--2987
"Peugeot#e-208#2019-2022#945#",//--Peugeot--2991
"Peugeot#e-2008#2020-2022#945#",//--Peugeot--2995
"Peugeot#e-Traveller#2020-2022#525#",//--Peugeot--2999
"Peugeot#e-Traveller Dual Zone R1234yf#2020-2022#850#",//--Peugeot--3003
"Peugeot#ion Electric 1234yf (POE oil)#2013-2020#280#",//--Peugeot--3007
"Peugeot#Partner IV#2018-2022#450#",//--Peugeot--3011
"Peugeot#Rifter#2018-2022#450#",//--Peugeot--3015
"Peugeot#Traveller Except Hot Climate#2016-2018#450#",//--Peugeot--3019
"Peugeot#Traveller With Hot Climate#2016-2018#650#",//--Peugeot--3023
"Peugeot#Traveller Dual Zone#2016-2018#900#",//--Peugeot--3027
"Peugeot#Traveller 2,0 Bluehdi Single Zone#2016-2022#450#",//--Peugeot--3031
"Peugeot#Traveller 2,0 Bluehdi Dual Zone#2016-2022#775#",//--Peugeot--3035
"Peugeot#508 Hybrid#2020-2022#700#",//--Peugeot--3039
"Peugeot#508 Hybrid for R134a#2020-2022#725#",//--Peugeot--3043
"Peugeot#3008 Hybrid#2019-2022#725#",//--Peugeot--3047
"Peugeot#Boxer/e-Boxer III for R134a#2020-2020#550#",//--Peugeot--3051
"Peugeot#Boxer/e-Boxer III Minibus R1234yf#2020-2020#935#",//--Peugeot--3055
"Peugeot#Boxer/e-Boxer III Minibus for R134a#2020-2020#2600#",//--Peugeot--3059
"Peugeot#Boxer/e-Boxer III rear a/c for R134a#2020-2020#950#",//--Peugeot--3063
"Peugeot#e-Expert IV Electric for R134a#2020-2022#575#",//--Peugeot--3067
"Peugeot#e-208 for R134a#2019-2022#985#",//--Peugeot--3071
"Peugeot#e-208 R1234yf#2019-2022#945#",//--Peugeot--3075
"Peugeot#e-2008#2020-2022#985#",//--Peugeot--3079
"Peugeot#e-2008 R1234yf#2020-2022#945#",//--Peugeot--3083
"Peugeot#e-Traveller R1234yf#2020-2022#525#",//--Peugeot--3087
"Peugeot#e-Traveller Dual Zone R1234yf#2020-2022#850#",//--Peugeot--3091
"Peugeot#ion Electric R1234yf (POE oil)#2013-2020#280#",//--Peugeot--3095
"Peugeot#Partner III#2013-2020#525#",//--Peugeot--3099
"Porsche#718 Boxster-Cayman#2016-2020#835#",//--3101-3151Porsche--3103
"Porsche#911#2015-2018#875#",//--Porsche--3107
"Porsche#Cayenne#2015-2020#680#",//--Porsche--3111
"Porsche#Cayenne A/C with rear#2015-2020#850#",//--Porsche--3115
"Porsche#Cayenne 3,0 Hybrid#2015-2018#800#",//--Porsche--3119
"Porsche#Cayman#2015-2018#880#",//--Porsche--3123
"Porsche#Cayman 3,0 Hybrid#2015-2018#800#",//--Porsche--3127
"Porsche#Macan#2014-2019#540#",//--Porsche--3131
"Porsche#Panamera E-Hybrid#2016-2020#660#",//--Porsche--3135
"Porsche#Panamera#2016-2020#490#",//--Porsche--3139
"Porsche#Cayenne#2015-2020#680#",//--Porsche--3143
"Porsche#Cayenne A/C with rear#2015-2020#850#",//--Porsche--3147
"Porsche#Panamera E-Hybrid#2016-2020#660#",//--Porsche--3151
//"Proton###0#",//--3153-3155Proton--3155
"Renault#Arkana#2019-2022#480#",//--3157-3303Renault--3159
"Renault#Clio IV#2016-2019#430#",//--Renault--3163
"Renault#Clio V#2019-2022#420#",//--Renault--3167
"Renault#Captur#2016-2018#430#",//--Renault--3171
"Renault#Captur#2019-2020#420#",//--Renault--3175
"Renault#Captur II#2019-2022#420#",//--Renault--3179
"Renault#Captur II 1.6 PHEV Hybrid#2019-2022#580#",//--Renault--3183
"Renault#Duster#2012-2021#450#",//--Renault--3187
"Renault#Escape V#2015-2020#480#",//--Renault--3191
"Renault#Escape V with rear a/c#2015-2020#700#",//--Renault--3195
"Renault#Kadjar#2015-2022#480#",//--Renault--3199
"Renault#Kangoo II#2016-2022#450#",//--Renault--3203
"Renault#Koleos#2015-2021#500#",//--Renault--3207
"Renault#Logan II#2014-2022#450#",//--Renault--3211
"Renault#Master III Electric#2018-2022#820#",//--Renault--3215
"Renault#Master III (EV/UV)#2018-2022#570#",//--Renault--3219
"Renault#Master III A/C with rear#2018-2022#1090#",//--Renault--3223
"Renault#Master III WITH REAR HEATER#2018-2022#1690#",//--Renault--3227
"Renault#Megane IV#2016-2022#480#",//--Renault--3231
"Renault#Sandero II#2014-2022#450#",//--Renault--3235
"Renault#Scenic#2016-2018#480#",//--Renault--3239
"Renault#Symbol II#2016-2018#450#",//--Renault--3243
"Renault#Talisman#2015-2022#480#",//--Renault--3247
"Renault#Trafic#2015-2020#540#",//--Renault--3251
"Renault#Trafic A/C with rear#2015-2020#850#",//--Renault--3255
"Renault#Twingo III#2016-2022#430#",//--Renault--3259
"Renault#Twingo Electric#2020-2022#575#",//--Renault--3263
"Renault#Zoe#2015-2022#1000#",//--Renault--3267
"Renault#Captur II Hybrid R1234yf#2019-2022#420#",//--Renault--3271
"Renault#Captur II 1.6 PHEV Hybrid R1234yf#2019-2022#580#",//--Renault--3275
"Renault#Captur II for R134a#2019-2022#440#",//--Renault--3279
"Renault#Clio V#2020-2022#420#",//--Renault--3283
"Renault#Kangoo Grand II Electric for R134a#2020-2022#850#",//--Renault--3287
"Renault#Master III#2018-2022#820#",//--Renault--3291
"Renault#Scenic E-Hybrid R1234yf#2016-2018#480#",//--Renault--3295
"Renault#Twingo Electric#2020-2022#575#",//--Renault--3299
"Renault#Zoe Electric#2015-2022#1000#",//--Renault--3303
//"Rover###0#",//--3305-3307Rover--3307
//"Saab###0#",//--3309-3311Saab--3311
"Seat#Alhambra#2016-2022#500#",//--3313-3371Seat--3315
"Seat#Alhambra with rear a/c#2016-2022#825#",//--Seat--3319
"Seat#Arona#2017-2022#430#",//--Seat--3323
"Seat#Ateca#2016-2022#460#",//--Seat--3327
"Seat#Ibiza#2017-2022#430#",//--Seat--3331
"Seat#Ibiza 1,0#2017-2022#390#",//--Seat--3335
"Seat#Leon II#2016-2022#460#",//--Seat--3339
"Seat#Mii#2015-2020#330#",//--Seat--3343
"Seat#Tarraco#2019-2022#460#",//--Seat--3347
"Seat#Toledo#2016-2019#450#",//--Seat--3351
"Seat#Leon II#2016-2022#460#",//--Seat--3355
"Seat#Leon II for R134a#2004-2022#500#",//--Seat--3359
"Seat#Mii#2015-2020#330#",//--Seat--3363
"Seat#Tarraco Hybrid R1234yf#2019-2022#460#",//--Seat--3367
"Seat#Tarraco Hybrid for R134a#2019-2022#500#",//--Seat--3371
"Skoda#Citigo#2016-2020#330#",//--3373-3455Skoda--3375
"Skoda#Enyaq#2021-2022#460#",//--Skoda--3379
"Skoda#Fabia III#2015-2022#450#",//--Skoda--3383
"Skoda#Kamiq#2019-2022#430#",//--Skoda--3387
"Skoda#Karoq#2017-2022#460#",//--Skoda--3391
"Skoda#Kodiaq Modine Condenser#2017-2020#460#",//--Skoda--3395
"Skoda#Kodiaq All Other Condensers#2017-2020#460#",//--Skoda--3399
"Skoda#Octavia III#2016-2020#460#",//--Skoda--3403
"Skoda#Octavia IV#2020-2022#460#",//--Skoda--3407
"Skoda#Octavia Modine Condenser#2016-2020#460#",//--Skoda--3411
"Skoda#Rapid / Speedback#2017-2019#450#",//--Skoda--3415
"Skoda#Rapid Modine Condenser#2017-2019#450#",//--Skoda--3419
"Skoda#Scala#2019-2022#430#",//--Skoda--3423
"Skoda#Superb III#2016-2020#460#",//--Skoda--3427
"Skoda#Superb III Modine Condenser#2016-2020#460#",//--Skoda--3431
"Skoda#Yeti#2014-2017#460#",//--Skoda--3435
"Skoda#Citigo#2019-2020#330#",//--Skoda--3439
"Skoda#Enyaq#2021-2022#460#",//--Skoda--3443
"Skoda#Octavia IV#2020-2022#460#",//--Skoda--3447
"Skoda#Octavia IV for R134a#2020-2022#500#",//--Skoda--3451
"Skoda#Superb III Hybrid R1234yf#2020-2022#460#",//--Skoda--3455
"Smart#Forfour Elektrik#2017-2019#430#",//--3457-3471Smart--3459
"Smart#Forfour 0,9 Brabus#2017-2019#475#",//--Smart--3463
"Smart#Fortwo  elektrik#2017-2018#430#",//--Smart--3467
"Smart#Fortwo#2015-2018#475#",//--Smart--3471
"SsangYong#Rexton#2017-2022#520#",//--3473-3491SsangYong--3475
"SsangYong#Rexton with rear a/c#2017-2022#800#",//--SsangYong--3479
"SsangYong#Rodius II/ Turismo#2015-2020#1050#",//--SsangYong--3483
"SsangYong#Tivoli#2015-2020#500#",//--SsangYong--3487
"SsangYong#XLV#2016-2020#500#",//--SsangYong--3491
"Subaru#BRZ#2016-2020#350#",//--3493-3531Subaru--3495
"Subaru#Forester 2,0#2016-2019#375#",//--Subaru--3499
"Subaru#Forester 2,0 6200rpm 2,0XT Turbo#2013-2019#450#",//--Subaru--3503
"Subaru#Impreza#2017-2022#375#",//--Subaru--3507
"Subaru#Legacy#2017-2018#455#",//--Subaru--3511
"Subaru#Levorg#2015-2020#450#",//--Subaru--3515
"Subaru#Outback 2,5#2015-2022#425#",//--Subaru--3519
"Subaru#Outback 2,0#2015-2018#375#",//--Subaru--3523
"Subaru#WRX#2016-2018#450#",//--Subaru--3527
"Subaru#XV#2015-2022#450#",//--Subaru--3531
"Suzuki#Baleno#2016-2019#400#",//--3533-3587Suzuki--3535
"Suzuki#Celerio#2014-2019#380#",//--Suzuki--3539
"Suzuki#Ignis#2017-2022#390#",//--Suzuki--3543
"Suzuki#Jimny#2015-2019#430#",//--Suzuki--3547
"Suzuki#Swift#2017-2022#400#",//--Suzuki--3551
"Suzuki#SX4 S-Cross 1.6#2016-2018#440#",//--Suzuki--3555
"Suzuki#SX4 S-Cross#2016-2022#470#",//--Suzuki--3559
"Suzuki#Vitara#2015-2022#425#",//--Suzuki--3563
"Suzuki#Vitara 1.6 DDIS#2015-2018#440#",//--Suzuki--3567
"Suzuki#Vitara 1.0 Booster jet#2018-2022#475#",//--Suzuki--3571
"Suzuki#Baleno Hybrid R1234yf#2016-2019#400#",//--Suzuki--3575
"Suzuki#Ignis 1.2 Dualjet Hybrid#2017-2022#390#",//--Suzuki--3579
"Suzuki#Swift Hybrid R1234yf#2017-2022#400#",//--Suzuki--3583
"Suzuki#Swift for R134a#2017-2022#390#",//--Suzuki--3587
//"Tata###0#",//--3589-3591Tata--3591
"Tesla#Model 3 Electric#2018-2022#660#",//--3593-3607Tesla--3595
"Tesla#Model S Electric R1234yf#2013-2019#730#",//--Tesla--3599
"Tesla#Model X Electric#2017-2019#720#",//--Tesla--3603
"Tesla#Model X Electric A/C with rear#2017-2019#980#",//--Tesla--3607
"Toyota#Auris#2016-2018#400#",//--3609-3795Toyota--3611
"Toyota#Auris 1.3 VVTI / 1.4 D-4D#2015-2018#420#",//--Toyota--3615
"Toyota#Avalon#2017-2018#500#",//--Toyota--3619
"Toyota#Aygo#2015-2022#350#",//--Toyota--3623
"Toyota#Aygo 1,2#2015-2018#350#",//--Toyota--3627
"Toyota#Camry 1.8 Hybrid#2017-2018#470#",//--Toyota--3631
"Toyota#C-HR Valeo Compresor#2016-2022#400#",//--Toyota--3635
"Toyota#C-HR Denso Compresor#2016-2022#400#",//--Toyota--3639
"Toyota#C-HR Hybrid#2016-2022#470#",//--Toyota--3643
"Toyota#Corolla#2016-2018#420#",//--Toyota--3647
"Toyota#Corolla#2018-2022#470#",//--Toyota--3651
"Toyota#GR Supra#2019-2022#550#",//--Toyota--3655
"Toyota#GT-86#2012-2022#350#",//--Toyota--3659
"Toyota#Landcruiser Prado coolbox#2016-2022#600#",//--Toyota--3663
"Toyota#Landcruiser Prado#2016-2022#550#",//--Toyota--3667
"Toyota#Landcruiser Prado with rear a/c#2016-2022#770#",//--Toyota--3671
"Toyota#Landcruiser with rear a/c+coolbox#2016-2022#800#",//--Toyota--3675
"Toyota#MIRAI#2015-2022#470#",//--Toyota--3679
"Toyota#Prius  Hybrid#2016-2022#470#",//--Toyota--3683
"Toyota#PROACE SINGLE ZONE EXCEPT HOTCLIMATE#2016-2022#450#",//--Toyota--3687
"Toyota#PROACE SINGLE ZONE WITH HOTCLIMATE#2016-2022#650#",//--Toyota--3691
"Toyota#PROACE DUAL ZONE#2016-2022#900#",//--Toyota--3695
"Toyota#PROACE 2.0 SINGLE ZONE#2016-2022#450#",//--Toyota--3699
"Toyota#PROACE 2.0 DUAL ZONE#2016-2022#775#",//--Toyota--3703
"Toyota#PROACE /Verso Electric#2020-2022#525#",//--Toyota--3707
"Toyota#PROACE /Verso Electric DUAL ZONE#2020-2022#850#",//--Toyota--3711
"Toyota#RAV 4#2016-2018#500#",//--Toyota--3715
"Toyota#RAV 4 2.5 Hybrid#2015-2018#500#",//--Toyota--3719
"Toyota#RAV 4#2019-2022#550#",//--Toyota--3723
"Toyota#RAV 4 2.5 PHEV Hybrid#2020-2022#1500#",//--Toyota--3727
"Toyota#Tacoma#2017-2020#540#",//--Toyota--3731
"Toyota#Yaris (P13) 1.5 VVT-i#2017-2020#350#",//--Toyota--3735
"Toyota#Yaris 5 door gasoline#2020-2022#350#",//--Toyota--3739
"Toyota#Yaris 5 door Hibrid#2020-2022#450#",//--Toyota--3743
"Toyota#Yaris 3 door#2020-2022#420#",//--Toyota--3747
"Toyota#Yaris 1.6 GR Circuit Pack#2020-2022#320#",//--Toyota--3751
"Toyota#Auris Hibrid#2010-2015#475#",//--Toyota--3755
"Toyota#Camry Hybrid#2017-2018#580#",//--Toyota--3759
"Toyota#C-HR Hybrid#2016-2022#470#",//--Toyota--3763
"Toyota#Corolla Hybrid#2018-2022#470#",//--Toyota--3767
"Toyota#Mirai#2015-2022#470#",//--Toyota--3771
"Toyota#Prius  Hybrid#2016-2022#470#",//--Toyota--3775
"Toyota#PROACE /Verso Electric#2020-2022#525#",//--Toyota--3779
"Toyota#PROACE /Verso Electric DUAL ZONE#2020-2022#850#",//--Toyota--3783
"Toyota#RAV 4 Hybrid#2016-2022#550#",//--Toyota--3787
"Toyota#RAV 4 2.5 PHEV Hybrid#2020-2022#1500#",//--Toyota--3791
"Toyota#Yaris 5 door Hibrid#2020-2022#450#",//--Toyota--3795
"Volvo#S60#2016-2018#750#",//--3797-4047Volvo--3799
"Volvo#S60#2019-2022#600#",//--Volvo--3803
"Volvo#S60 T4#2019-2022#650#",//--Volvo--3807
"Volvo#S60 T6/T8#2020-2022#675#",//--Volvo--3811
"Volvo#S90#2016-2022#650#",//--Volvo--3815
"Volvo#S90 2.0B4/B5/B6#2020-2022#600#",//--Volvo--3819
"Volvo#S90 T8 Twin Engine Hybrid#2017-2022#675#",//--Volvo--3823
"Volvo#V40#2016-2019#575#",//--Volvo--3827
"Volvo#V60#2016-2018#750#",//--Volvo--3831
"Volvo#V60#2018-2020#650#",//--Volvo--3835
"Volvo#V60 2.4 D5Plug-in Hybrid/Twin Engine#2015-2018#825#",//--Volvo--3839
"Volvo#V90#2016-2022#650#",//--Volvo--3843
"Volvo#V90 Cross Country B4/B5/B6#2020-2022#600#",//--Volvo--3847
"Volvo#V90 2.0 V8 Twin Engine Hybrid#2016-2018#675#",//--Volvo--3851
"Volvo#XC 40#2017-2020#480#",//--Volvo--3855
"Volvo#XC 40 2.0 D3/D4/T4/T5#2017-2022#500#",//--Volvo--3859
"Volvo#XC 40 2.0 B4/B5#2020-2022#575#",//--Volvo--3863
"Volvo#XC 40 Electric#2020-2022#725#",//--Volvo--3867
"Volvo#XC 40 1.5 Recharge Electric#2020-2022#520#",//--Volvo--3871
"Volvo#XC 40 1.5 T4/T5 Twin Engine#2020-2022#520#",//--Volvo--3875
"Volvo#XC 60#2017-2020#650#",//--Volvo--3879
"Volvo#XC 60 B4/B5#2019-2022#625#",//--Volvo--3883
"Volvo#XC 60 B4/B5/B6 Hybrid#2019-2022#600#",//--Volvo--3887
"Volvo#XC 60 2.0 T8 Twin Engine Hybrid#2016-2022#675#",//--Volvo--3891
"Volvo#XC 60 D3/D4/D5#2018-2022#650#",//--Volvo--3895
"Volvo#XC 60 2.0 Recharge T6/T8#2020-2022#675#",//--Volvo--3899
"Volvo#XC 90#2015-2020#650#",//--Volvo--3903
"Volvo#XC 90 with rear a/c#2015-2018#900#",//--Volvo--3907
"Volvo#XC 90 2.0T8 Twin Engine Hybrid#2015-2019#700#",//--Volvo--3911
"Volvo#XC 90 2.0T8 Twin Engine rear a/c#2015-2019#1000#",//--Volvo--3915
"Volvo#XC 90 2.0 B5/B6#2019-2022#600#",//--Volvo--3919
"Volvo#XC 90 2.0 B5/B6 with rear a/c#2019-2022#850#",//--Volvo--3923
"Volvo#XC 90 2.0 Recharge T8#2020-2022#700#",//--Volvo--3927
"Volvo#XC 90 2.0 Recharge T8 rear a/c#2020-2022#975#",//--Volvo--3931
"Volvo#S60#2020-2022#600#",//--Volvo--3935
"Volvo#S60 For R134a#2020-2022#700#",//--Volvo--3939
"Volvo#S60 T6/T8 R1234yf#2020-2022#675#",//--Volvo--3943
"Volvo#S60 T6/T8 For R134a#2020-2022#725#",//--Volvo--3947
"Volvo#S90#2018-2022#700#",//--Volvo--3951
"Volvo#S90 2.0B4/B5/B6#2020-2022#600#",//--Volvo--3955
"Volvo#S90 T8 Twin Engine Hybrid For R1234yf#2017-2022#675#",//--Volvo--3959
"Volvo#V90 Cross Country B4/B5/B6#2020-2022#600#",//--Volvo--3963
"Volvo#V90 Cross Country B4/B5/B6 R134a#2020-2022#700#",//--Volvo--3967
"Volvo#V90 2.0 T8 Twin Engine Hybrid For R1234yf#2016-2018#675#",//--Volvo--3971
"Volvo#XC 40 Electric#2020-2022#725#",//--Volvo--3975
"Volvo#XC 40 Electric R134a#2020-2022#750#",//--Volvo--3979
"Volvo#XC 40 1.5 Recharge Electric#2020-2022#520#",//--Volvo--3983
"Volvo#XC 40 1.5 Recharge Electric R134a#2020-2022#575#",//--Volvo--3987
"Volvo#XC 40 2.0 B4/B5 R134a#2020-2022#650#",//--Volvo--3991
"Volvo#XC 40 2.0 B4/B5#2020-2022#575#",//--Volvo--3995
"Volvo#XC 60 Twin Engine Hybrid For R1234yf#2016-2020#675#",//--Volvo--3999
"Volvo#XC 60 B4/B5#2019-2022#625#",//--Volvo--4003
"Volvo#XC 60 B4/B5 R134a#2019-2022#725#",//--Volvo--4007
"Volvo#XC 60 B4/B5/B6 Hybrid R134a#2019-2022#700#",//--Volvo--4011
"Volvo#XC 60 B4/B5/B6 Hybrid#2019-2022#600#",//--Volvo--4015
"Volvo#XC 90 2.0 B5/B6 Hybrid For R1234yf#2019-2022#600#",//--Volvo--4019
"Volvo#XC 90 2.0 B5/B6 with rear a/c Hybrid For R1234yf#2019-2022#850#",//--Volvo--4023
"Volvo#XC 90 2.0 B5/B6 Hybrid R134a#2019-2022#700#",//--Volvo--4027
"Volvo#XC 90 2.0 B5/B6 with rear a/c Hybrid R134a#2019-2022#950#",//--Volvo--4031
"Volvo#XC 90 2.0 Recharge T8#2020-2022#700#",//--Volvo--4035
"Volvo#XC 90 2.0 Recharge T8 rear a/c#2020-2022#975#",//--Volvo--4039
"Volvo#XC 90 2.0 Recharge T8 R134a#2020-2022#775#",//--Volvo--4043
"Volvo#XC 90 2.0 Recharge T8 rear a/c R134a#2020-2022#1050#",//--Volvo--4047
"VW#Arteon#2017-2022#460#",//--4049-4263VW--4051
"VW#Beetle Coccinelle/ Maggiolino#2016-2018#460#",//--VW--4055
"VW#Caddy/ Caddy Maxi#2016-2020#420#",//--VW--4059
"VW#Caddy/ Caddy Maxi#2020-2022#460#",//--VW--4063
"VW#Crafer#2016-2022#555#",//--VW--4067
"VW#Crafter air-conditioned ceiling#2016-2022#800#",//--VW--4071
"VW#E-Golf eaza 100kw#2017-2019#430#",//--VW--4075
"VW#E-Golf With heat pump#2017-2019#850#",//--VW--4079
"VW#E-Up 60kw EABA Electric#2016-2020#340#",//--VW--4083
"VW#Golf VII#2015-2021#460#",//--VW--4087
"VW#Golf VIII#2020-2022#460#",//--VW--4091
"VW#ID.3#2019-2022#460#",//--VW--4095
"VW#ID.4#2021-2022#460#",//--VW--4099
"VW#Jetta#2014-2018#450#",//--VW--4103
"VW#Passat#2016-2019#460#",//--VW--4107
"VW#Passat#2019-2022#450#",//--VW--4111
"VW#Polo#2016-2018#450#",//--VW--4115
"VW#Polo 1.0 MPI / 2.0 TSI#2017-2020#390#",//--VW--4119
"VW#Polo 1.0 TGI / TSI / TDI#2017-2020#430#",//--VW--4123
"VW#Scirocco#2016-2018#460#",//--VW--4127
"VW#Sharan 1,4 TSI#2016-2022#480#",//--VW--4131
"VW#Sharan 2.0 TDI CR SCR/2.0 TSI#2016-2022#500#",//--VW--4135
"VW#Sharan 2.0 TDI/2.0 TSI with rear a/c#2016-2022#825#",//--VW--4139
"VW#T-Cross#2019-2022#430#",//--VW--4143
"VW#Tiguan#2016-2022#460#",//--VW--4147
"VW#Touareg#2016-2018#800#",//--VW--4151
"VW#Touareg with rear a/c#2016-2018#1000#",//--VW--4155
"VW#Touareg#2018-2022#680#",//--VW--4159
"VW#Touareg 3.0 Hibrid#2020-2022#740#",//--VW--4163
"VW#Touran#2018-2022#460#",//--VW--4167
"VW#Transporter T6#2015-2019#530#",//--VW--4171
"VW#Transporter T6 with rear a/c#2015-2019#830#",//--VW--4175
"VW#Transporter T6.1#2019-2022#530#",//--VW--4179
"VW#Transporter T6.1 with rear a/c#2019-2022#830#",//--VW--4183
"VW#T- Cross#2018-2022#430#",//--VW--4187
"VW#T-ROC#2017-2022#460#",//--VW--4191
"VW#Up#2016-2020#340#",//--VW--4195
"VW#Up 1.0 GTI#2016-2022#450#",//--VW--4199
"VW#Up 1.0#2020-2022#330#",//--VW--4203
"VW#E-Crafer Electric R134a#2018-2022#965#",//--VW--4207
"VW#E-Golf eaza 100kw R1234yf#2017-2019#430#",//--VW--4211
"VW#E-Golf With heat pump R1234yf#2017-2019#850#",//--VW--4215
"VW#E-Load Up 60kw Electric For R1234yf#2016-2020#340#",//--VW--4219
"VW#E-Load Up 60kw Electric For R134a#2016-2020#380#",//--VW--4223
"VW#Golf VIII#2020-2022#460#",//--VW--4227
"VW#ID.3 For R1234yf#2019-2022#460#",//--VW--4231
"VW#ID.3 For R744#2019-2022#420#",//--VW--4235
"VW#ID.4 For R744#2021-2022#420#",//--VW--4239
"VW#ID.4#2021-2022#460#",//--VW--4243
"VW#Passat Hybrid#2018-2022#460#",//--VW--4247
"VW#Tiguan For R1234yf#2021-2022#450#",//--VW--4251
"VW#Tiguan For R134a#2021-2022#500#",//--VW--4255
"VW#Touareg 3.0 Hibrid#2020-2022#740#",//--VW--4259
"VW#Touareg 3.0 Hibrid For R134a#2020-2022#840#",//--VW--4263
"*",    // 2419
};





#endif
