// ALLAH SWT.
//MUHAMMAD SAW.
//BISMILLAH HIRHMAN NIROHIM
#include <HCSR04.h>

#include <Wire.h>
#include <Adafruit_SSD1306.h>

#include <Pixy2.h>

#include "DFRobot_BNO055.h"     
#include "DFRobot_URM09.h"
#define VELOCITY_TEMP(temp) ((331.5 + 0.6 * (float)(temp)) * 100 / 1000000.0)  // The ultrasonic velocity (cm/us) compensated by temperature

#include "Wire.h"

#include "HUSKYLENS.h"
#include "DFMobile.h"

//Sensor warna
#define S0 24
#define S1 26
#define S2 28
#define S3 30
#define sensorOut 32
int led = 34;

int redMin = 88;     // Red minimum value
int redMax = 370;    // Red maximum value
int greenMin = 92;   // Green minimum value
int greenMax = 406;  // Green maximum value
int blueMin = 72;    // Blue minimum value
int blueMax = 291;   // Blue maximum value

// Variables for Color Pulse Width Measurements

int redPW = 0;
int greenPW = 0;
int bluePW = 0;

const int ledPin = 13;

// Variables for final Color values

int redValue;
int greenValue;
int blueValue;

// mapping
bool miror;
bool normal;
bool a;
bool b;

//lcd

Adafruit_SSD1306 lcd(128, 64, &Wire, 4);

//pelacakan
bool pelacakanx = false;
//tombol start
#define button 8
int kondisi = 0;
int v_analog =0;
// set poin
float set_poin;
float set_poin1;
float set_poinx;


int A;
// rintangan
bool rintangan_[40] = { false };
bool normal_[27] = { false };
bool miror_[27] = { false };
// pixy
Pixy2 pixy;

//huskylens
HUSKYLENS huskylens;

int K1 = 13;
int K2 = 12;
int K3 = 11;
int K4 = 10;
int K5 = 9;

int tring_u2 = 42;
int echo_u2 = 44;
long duration_u2;
int distance_u2;

//ultra kiri
int tring_u3 = 47;
int echo_u3 = 49;
long duration_u3;
int distance_u3;

//ultra belakang
int tring_u5 = 6;
int echo_u5 = 7;
long duration_u5;
int distance_u5;

//ultra depan
int tring_u6 = 4;
int echo_u6 = 5;
long duration_u6;
int distance_u6;
int C, back;

//ultra GRIPPER
int tring_gpr = 43;
int echo_gpr = 45;
long duration_gpr;
int distance_gpr;


//infrared
int in_mki = 23;
int in_mt = 25;
//int in_mka = 7;

//button infrared
int buttonstate1;
int buttonstate2;
int buttonstate3;

//URM09 I2C
DFRobot_URM09 URM09;
DFRobot_URM09 URM08;
DFRobot_URM09 URM07;

//URM09 TRIG
int16_t trigechoPin = 29;
uint16_t distance_u8;
uint32_t pulseWidthUs;

int rgb = (redValue + greenValue + blueValue) / 3;


//SEN0253
typedef DFRobot_BNO055_IIC BNO;  // ******** use abbreviations instead of full names ********

BNO bno(&Wire, 0x28);  // input TwoWire interface and IIC address

// show last sensor operate status
void printLastOperateStatus(BNO::eStatus_t eStatus) {
  switch (eStatus) {
    lcd.clearDisplay();
    lcd.setCursor(0, 0);
    case BNO::eStatusOK: lcd.println("everything ok"); break;
    case BNO::eStatusErr: lcd.println("unknow error"); break;
    case BNO::eStatusErrDeviceNotDetect: lcd.println("device not detected"); break;
    case BNO::eStatusErrDeviceReadyTimeOut: lcd.println("device ready time out"); break;
    case BNO::eStatusErrDeviceStatus: lcd.println("device internal status error"); break;
    default:
      lcd.println("unknow status");
      break;
      lcd.display();
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  //WARNA
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);

  // Set Sensor output as input
  pinMode(sensorOut, INPUT);

  // Set Frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  //LCD
  lcd.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  lcd.clearDisplay();
  lcd.setTextSize(1);
  lcd.setTextColor(WHITE);
  lcd.setCursor(0, 0);
  lcd.print("wewe");
  //button
  pinMode(button, INPUT);
  //KOMUNIKASI
  pinMode(K1, OUTPUT);
  pinMode(K2, OUTPUT);
  pinMode(K3, OUTPUT);
  pinMode(K4, OUTPUT);
  pinMode(K5, OUTPUT);
  //ULTRASONIK
  pinMode(tring_u2, OUTPUT);
  pinMode(echo_u2, INPUT);
  pinMode(tring_u3, OUTPUT);
  pinMode(echo_u3, INPUT);
  pinMode(tring_gpr, OUTPUT);
  pinMode(echo_gpr, INPUT);
  pinMode(tring_u5, OUTPUT);
  pinMode(echo_u5, INPUT);
  pinMode(tring_u6, OUTPUT);
  pinMode(echo_u6, INPUT);
  //URM09
  URM09.begin(0x10);
  /*while (!URM09.begin(0x10)) {
    lcd.clearDisplay();
    lcd.setCursor(0, 0);
    lcd.print("I2c device number1 error");
    lcd.display();
  }*/
  while (!URM08.begin(0x12)) {
    lcd.clearDisplay();
    lcd.setCursor(0, 0);
    lcd.print("I2c device number2 error");
    lcd.display();
  }
  while (!URM07.begin(0x13)) {
    lcd.clearDisplay();
    lcd.setCursor(0, 0);
    lcd.print("I2c device number3 error");
    lcd.display();
  }
  URM09.setModeRange(MEASURE_MODE_AUTOMATIC, MEASURE_RANG_500);
  URM08.setModeRange(MEASURE_MODE_AUTOMATIC, MEASURE_RANG_500);
  URM07.setModeRange(MEASURE_MODE_AUTOMATIC, MEASURE_RANG_500);
  delay(100);
  //INFRARED
  pinMode(in_mki, INPUT);
  pinMode(in_mt, INPUT);
  //pinMode(in_mka, INPUT);
  //pixy
  pixy.init();
  Serial.println(pixy.changeProg("line"));
  //SEN0253
  bno.reset();
  while (bno.begin() != BNO::eStatusOK) {
    lcd.clearDisplay();
    lcd.setCursor(0, 0);
    lcd.println("bno begin faild");
    printLastOperateStatus(bno.lastOperateStatus);
    delay(2000);
    lcd.display();
  }
  //HUSKYLENS
  Wire.begin();
  while (!huskylens.begin(Wire)) {
    lcd.clearDisplay();
    lcd.setCursor(0, 0);
    lcd.print(F("Begin failed!"));
    lcd.print(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>I2C)"));
    lcd.print(F("2.Please recheck the connection."));
    lcd.display();
    delay(100);
  }
  huskylens.writeAlgorithm(ALGORITHM_OBJECT_TRACKING);

  capit_naik();
  Serial.print("asd");
  delay(2000);
}

// SEN0253
#define printAxisData(sAxis) \
  Serial.print(" x: "); \
  Serial.print(sAxis.x); \
  Serial.print(" y: "); \
  Serial.print(sAxis.y); \
  Serial.print(" z: "); \
  Serial.println(sAxis.z)

void printResult(HUSKYLENSResult result);

void loop() {
  //tampilan();
  siap();
  // capit_turun_sebagian();
  //kondisi = digitalRead(button);
  int v_analog = !digitalRead(button);

  while (v_analog == 1) {
    Serial.print("GOOOOOO");
    digitalWrite(ledPin, HIGH);

    for (int i = 1; i <= 30; i++) {

      kalibrasi_ultra();
      rotasi_90();
      tampilan();
      rintangan_[i];
      lcd.setCursor(90, 0);
      lcd.print(i);
      lcd.display();

      //start
      /*if (!rintangan_[1]) {
        rotasi_90();
        //setting set poin
        BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
        BNO::sEulAnalog_t sEulAnalog;
        sEulAnalog = bno.getEul();
        set_poin = 90;
        maju_tinggi_lambat();
        rintangan_[1] = true;
      }
      //pengambilan korban pertama
      else if (!rintangan_[2]) {
        int16_t distance_u4 = URM08.getDistance();
        ultra_u2();
        ultra_u6();
        ultra_u3();
        ultra_u5();

        if (distance_u4 >= 40 || ( distance_u2 >= 15 && distance_u3 >= 13)|| (distance_u6 >= 15 && distance_u6 > 13)) {
          siap();
          rintangan_[2] = true;
        } else {
          maju_tinggi_lambat();
        }
      } else if (!rintangan_[3]) {
        siap();
        delay(1000);
        ultra_u2();
        ultra_u6();

        if (distance_u2 > distance_u6) {
          a = false;
          b = true;

          delay(100);
          rintangan_[3] = true;
        } else {
          b = false;
          a = true;

          delay(100);
          rintangan_[3] = true;
        }
      } else if (!rintangan_[4]) {
        if (!a) {
          normal = false;
          miror = true;
          //pelacakan_1a();
          rintangan_[4] = true;
        } else if (!b) {
          normal = true;
          miror = false;
          siap();
          //pelacakan_1b();
          rintangan_[4] = true;
        }
      }


      /*else if (!rintangan_[5]) {

        int16_t distance_u4 = URM08.getDistance();
        if (distance_u4 < 6) {
          siap();
          delay(1000);
          rintangan_[4] = true;
        } else {
          mundur_tinggi_lambat();
        }
      }

      else if (!rintangan_[6]) {
        BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
        BNO::sEulAnalog_t sEulAnalog;
        sEulAnalog = bno.getEul();
        if (sEulAnalog.head >= set_poin - 8 && sEulAnalog.head <= set_poin + 8) {
          siap();
          rintangan_[6] = true;
        } else if (sEulAnalog.head < set_poin - 8) {
          putar_tinggi_kanan_lambat();
        } else if (sEulAnalog.head > set_poin + 8) {
          putar_tinggi_kiri_lambat();
        }
      }

      else if (!rintangan_[7]) {
        ultra_u8();
        ultra_u6();
        ultra_u2();
        int16_t distance_u1 = URM09.getDistance();
        int16_t distance_u7 = URM07.getDistance();

        BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
        BNO::sEulAnalog_t sEulAnalog;
        sEulAnalog = bno.getEul();
        if (sEulAnalog.head >= set_poin - 8 && sEulAnalog.head <= set_poin + 8) {
          maju_tinggi_lambat();
          if ((distance_u2 >= 22 && distance_u8 < 20 && distance_u1 >= 32) || (distance_u7 >= 20 && distance_u6 >= 20 && distance_u8 <= 30)) {
            siap();
            delay(300);
            rintangan_[7] = true;
          } else {
            maju_tinggi_lambat();
          }
        } else if (sEulAnalog.head < set_poin - 8) {
          putar_tinggi_kanan();
        } else if (sEulAnalog.head > set_poin + 8) {
          putar_tinggi_kiri();
        }
        }
        else if (!rintangan_[8]){
          ultra_u8();

          if(distance_u8 >= 15){
            siap();
            delay(100);
            rintangan_[8] = true;
          }
          else{
            mundur_tinggi();
          }

        } */
      //--------------------------------------------------- normal -------------------------------------------------------------
     if (!rintangan_[9]) { //kaca
        miror = true;
        normal = false;
        while (!normal) {
          for (int n = 1; n <= 27; i++) {
            normal_[n];
            tampilan();
            set_poin = 90;

            lcd.setCursor(100, 50);
            lcd.print("n");
            lcd.print(n);
            lcd.display();

            if (!normal_[1]) {
              ultra_u8();
              BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
              BNO::sEulAnalog_t sEulAnalog;
              sEulAnalog = bno.getEul();
              if (sEulAnalog.head >= set_poin + 20 && sEulAnalog.head <= set_poin + 40) {
                siap();
                delay(500);
                mundur_tinggi_lambat();
                delay(2000);
                siap();
                delay(500);
                capit_turun();
                delay(500);
                capit_buka();
                delay(500);
                capit_naik();
                delay(500);
                normal_[1] = true;
              }

              else if (sEulAnalog.head > set_poin + 40) {
                putar_tinggi_kiri();
              } else if (sEulAnalog.head < set_poin + 20) {
                putar_tinggi_kanan();
              }
            }

            else if (!normal_[2]) {
              set_poin = 90;
              ultra_u6();
              BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
              BNO::sEulAnalog_t sEulAnalog;
              sEulAnalog = bno.getEul();
             if (sEulAnalog.head > set_poin - 70 && sEulAnalog.head < 180) {
                putar_tinggi_kiri_lambat();
              } 
              else if (sEulAnalog.head < set_poin + 250 && sEulAnalog.head > 180) {
                putar_tinggi_kanan_lambat();
              }
              else{
                siap();
                delay(1000);
                normal_[2] = true;
              }
            }

           else if (!normal_[3]) {
              ultra_u6();
              int16_t distance_u7 = URM07.getDistance();
              if (distance_u6 <= 5 || distance_u7 <= 10) {
                siap();
                normal_[3] = true;
              } else {
                kanan_tinggi();
              }
            }

            /*else if (!normal_[4]) {
              int16_t distance_u4 = URM08.getDistance();
              ultra_u8();
              ultra_u2();
              ultra_u3();
              warna();
              BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
              BNO::sEulAnalog_t sEulAnalog;
              sEulAnalog = bno.getEul();
             if (sEulAnalog.head > set_poin - 75 && sEulAnalog.head < 180) {
                putar_tinggi_kiri();
              } else if (sEulAnalog.head < set_poin + 250 && sEulAnalog.head > 180) {
                putar_tinggi_kanan();
              }
              else{
                if (distance_u4 >= 40 || (distance_u2 <= 20 && distance_u3 <= 20) || (greenValue < 180 && greenValue > 120)) {
                  siap();
                  delay(1000);
                  normal_[4] = true;
                } else {
                  maju_tinggi_lambat();
                }
              }
            }

            else if (!normal_[5]) {
              pelacakan1();
              normal_[5] = true;
              }

              else if(!normal_[6]){
              int16_t distance_u4 = URM08.getDistance();
              if (distance_u4 <= 5) {
               siap();
               delay(500);
               normal_[6] = true;
              } else {
               mundur_tinggi_lambat();
              }
              }*/

            /*else if (!normal_[7]) {
              ultra_u6();
              // int16_t distance_u1 = URM09.getDistance();
              BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
              BNO::sEulAnalog_t sEulAnalog;
              sEulAnalog = bno.getEul();
             if (sEulAnalog.head > set_poin - 80 && sEulAnalog.head < 180) {
                putar_tinggi_kiri_lambat();
              } else if (sEulAnalog.head < set_poin + 250 && sEulAnalog.head > 180) {
                putar_tinggi_kanan_lambat();
              }
              else{
                  if (distance_u6 >= 7) {
                  siap();
                  delay(1000);
                  normal_[7] = true;
                } else {
                  kiri_tinggi();
                }
              }
            } else if (!normal_[8]) {
              int16_t distance_u1 = URM09.getDistance();
              BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
              BNO::sEulAnalog_t sEulAnalog;
              sEulAnalog = bno.getEul();
              if (sEulAnalog.head <= set_poin - 30 && sEulAnalog.head >= set_poin - 50) {
                if (distance_u1 <= 20) {
                  siap();
                  delay(1000);
                  capit_turun_sebagian();
                  delay(500);
                  capit_buka();
                  delay(1000);
                  capit_naik();
                  normal_[7] = true;
                } else {
                  maju_tinggi_lambat();
                }
              } else if (sEulAnalog.head > set_poin - 30) {
                putar_tinggi_kiri_lambat();
              } else if (sEulAnalog.head < set_poin - 50) {
                putar_tinggi_kanan_lambat();
              }
            }*/

           /* else if (!normal_[9]) {
              ultra_u6();
              BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
              BNO::sEulAnalog_t sEulAnalog;
              sEulAnalog = bno.getEul();
              if (sEulAnalog.head <= set_poin + 180 && sEulAnalog.head >= set_poin + 160) {
                siap();
                delay(1000);
                normal_[9] = true;
              } else if (sEulAnalog.head > set_poin + 180 || sEulAnalog.head < 90) {
                putar_tinggi_kiri_lambat();
              } else if (sEulAnalog.head > set_poin + 160 && sEulAnalog.head > 90) {
                putar_tinggi_kanan_lambat();
              }

            }

            else if (!normal_[10]) {
              ultra_u6();
              int16_t distance_u7 = URM07.getDistance();
              BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
              BNO::sEulAnalog_t sEulAnalog;
              sEulAnalog = bno.getEul();
              if (sEulAnalog.head <= set_poin + 180 && sEulAnalog.head >= set_poin + 160) {
                if (distance_u6 <= 4 && distance_u7 <= 6) {
                  siap();
                  delay(1000);
                  normal_[10] = true;
                } else {
                  maju_tinggi_kanan_lambat();
                }
              }

              else if (sEulAnalog.head > set_poin + 180 || sEulAnalog.head < 90) {
                putar_tinggi_kiri_lambat();
              } else if (sEulAnalog.head < set_poin + 160 && sEulAnalog.head > 90) {
                putar_tinggi_kanan_lambat();
              }
            }

            else if (!normal_[11]) {
              ultra_u8();
              BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
              BNO::sEulAnalog_t sEulAnalog;
              sEulAnalog = bno.getEul();
              if (sEulAnalog.head >= set_poin + 180 && sEulAnalog.head <= set_poin + 190) {
                if (distance_u8 <= 6) {
                  siap();
                  delay(1000);
                  normal_[11] = true;
                } else {
                  maju_tinggi_lambat();
                }
              } else if (sEulAnalog.head > set_poin + 190 || sEulAnalog.head < 90) {
                putar_tinggi_kiri_lambat();
              } else if (sEulAnalog.head < set_poin + 180 && sEulAnalog.head > 90) {
                putar_tinggi_kanan_lambat();
              }
            } else if (!normal_[12]) {
              ultra_u2();
              BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
              BNO::sEulAnalog_t sEulAnalog;
              sEulAnalog = bno.getEul();
              if (sEulAnalog.head >= set_poin + 180 && sEulAnalog.head <= set_poin + 190) {
                if (distance_u2 <= 5) {
                  siap();
                  normal_[12] = true;
                } else {
                  kiri_tinggi();
                }
              }

              else if (sEulAnalog.head > set_poin + 190) {
                putar_tinggi_kiri_lambat();
              } else if (sEulAnalog.head < set_poin + 180) {
                putar_tinggi_kanan_lambat();
              }
            } else if (!normal_[13]) {
              set_poin = 90;
              ultra_u8();
              BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
              BNO::sEulAnalog_t sEulAnalog;
              sEulAnalog = bno.getEul();
              maju_tinggi_lambat();
              if (sEulAnalog.head >= set_poin + 165 && sEulAnalog.head <= set_poin + 180) {
                if (distance_u8 <= 10) {
                  siap();
                  delay(1000);
                  normal_[13] = true;
                } else {
                  maju_tinggi_lambat();
                }
              }

              else if (sEulAnalog.head > set_poin + 180) {
                putar_tinggi_kiri_lambat();
              } else if (sEulAnalog.head < set_poin + 165) {
                putar_tinggi_kanan_lambat();
              }
            } else if (!normal_[14]) {
              ultra_u8();
              int16_t distance_u4 = URM08.getDistance();
              BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
              BNO::sEulAnalog_t sEulAnalog;
              sEulAnalog = bno.getEul();
              if (sEulAnalog.head <= set_poin - 85 && sEulAnalog.head <= set_poin - 265) {
                if (distance_u8 <= 10) {
                  siap();
                  delay(100);
                  capit_naik();
                  normal_[14] = true;
                } else {
                  maju_tinggi_lambat();
                }
              } else if (sEulAnalog.head > set_poin - 85 && sEulAnalog.head < 180) {
                putar_tinggi_kiri_lambat();
              } else if (sEulAnalog.head < set_poin - 265 && sEulAnalog.head > 180) {
                putar_tinggi_kanan_lambat();
              }
            }

            else if (!normal_[15]) {
              int16_t distance_u4 = URM08.getDistance();
              if(distance_u4 >= 40){
                siap();
                delay(1000);
                normal_[15] = true;
              }
              else{
                langkah_tangga_geser_kiri();
              }

            }

            else if (!normal_[16]) {
              ultra_u8();
              if (distance_u8 >= 12) {
                siap();
                miror_[16] = true;
              } else {
                mundur_tinggi_lambat();
              }
            }

            else if (!normal_[17]) {
              ultra_gpr();
              int16_t distance_u7 = URM07.getDistance();
              ultra_u6();
              BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
              BNO::sEulAnalog_t sEulAnalog;
              sEulAnalog = bno.getEul();
              if (sEulAnalog.head <= set_poin + 190 && sEulAnalog.head >= set_poin + 180) {
                if(distance_u7 <= 4 || distance_u6 <= 4)
                siap();
                delay(1000);
                capit_turun();
                delay(1000);
                capit_buka();
                delay(500);
                miror_[17] = true;
              } else if (sEulAnalog.head > set_poin + 190) {
                putar_tinggi_kiri_lambat();
              } else if (sEulAnalog.head < set_poin + 180) {
                putar_tinggi_kanan_lambat();
              }
            }

            else if (!normal_[19]) {
              ultra_u6();
              ultra_gpr();
              BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
              BNO::sEulAnalog_t sEulAnalog;
              sEulAnalog = bno.getEul();
              if (sEulAnalog.head <= set_poin + 190 && sEulAnalog.head >= set_poin + 180) {

                if (distance_gpr <= 7) {
                  siap();
                  delay(1000);
                  capit_tutup();
                  delay(1000);
                  capit_naik();
                  delay(500);
                   mundur_tinggi_lambat();
                  delay(1000);
                  siap();
                  delay(500);
                  normal_[19] = true;
                } else {
                  maju_tinggi_lambat();
                }
              } else if (sEulAnalog.head > set_poin + 190) {
                putar_tinggi_kiri_lambat();
              } else if (sEulAnalog.head < set_poin + 180) {
                putar_tinggi_kanan_lambat();
              }
            }

            else if (!normal_[20]) {
             ultra_u8();
              int16_t distance_u4 = URM08.getDistance();
              BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
              BNO::sEulAnalog_t sEulAnalog;
              sEulAnalog = bno.getEul();
              if (sEulAnalog.head >= set_poin + 160 && sEulAnalog.head <= set_poin + 180) {
                if (distance_u8 <= 10) {
                  siap();
                  delay(100);
                  capit_naik();
                  normal_[14] = true;
                } else {
                  maju_tinggi_lambat();
                }
              } else if (sEulAnalog.head > set_poin + 180) {
                putar_tinggi_kiri_lambat();
              } else if (sEulAnalog.head < set_poin + 160) {
                putar_tinggi_kanan_lambat();
              }
            }
            else if(!normal_[21]){
              ultra_u2();
              if(distance_u2 <= 5){
                siap();
                delay(1000);
                normal_[21] = true;
              }
              else{
                langkah_tangga_geser_kiri();
              }
            }

            else if(!normal_[22]){
              ultra_u8();
              ultra_u2();
              int16_t distance_u4 = URM08.getDistance();
              BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
              BNO::sEulAnalog_t sEulAnalog;
              sEulAnalog = bno.getEul();
              if (sEulAnalog.head <= set_poin + 175 && sEulAnalog.head >= set_poin + 165) {
                if (distance_u2 >= 5) {
                  siap();
                  delay(100);
                  capit_turun_sebagian();
                  normal_[22] = true;
                } else {
                  maju_tinggi_lambat();
                }
              } else if (sEulAnalog.head > set_poin + 175) {
                putar_tinggi_kiri_lambat();
              } else if (sEulAnalog.head < set_poin + 165) {
                putar_tinggi_kanan_lambat();
              }
            }
            else if(!normal_[23]){
             int16_t distance_u4 = URM08.getDistance(); 
               BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
              BNO::sEulAnalog_t sEulAnalog;
              sEulAnalog = bno.getEul();
              if (sEulAnalog.head <= set_poin + 180 && sEulAnalog.head >= set_poin + 170) {
                if(distance_u4 >=17){
                siap();
                delay(1000);
                capit_turun_sebagian();
                capit_buka();
                delay(200);
                miror_[21] = true;
               }

               else{
                maju_tinggi_lambat();
               }
              } else if (sEulAnalog.head > set_poin + 180) {
                putar_tinggi_kiri_lambat();
              } else if (sEulAnalog.head < set_poin + 170) {
                putar_tinggi_kanan_lambat();
              }

            }*/
          }
        }
        // ---------------------------------------------------------------- -miror---------------------------------------------------- -
        while (!miror) {  //kaca
          for (int n = 1; n <= 25; i++) {
            miror_[n];
            tampilan();
            set_poin = 90;

            lcd.setCursor(100, 50);
            lcd.print("m");
            lcd.print(n);
            lcd.display();

            if (!miror_[1]) {
              ultra_u8();

              BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
              BNO::sEulAnalog_t sEulAnalog;
              sEulAnalog = bno.getEul();
              if (sEulAnalog.head >= set_poin - 55 && sEulAnalog.head <= set_poin - 40) {
                siap();
                delay(500);
                mundur_tinggi_lambat();
                delay(1000);
                siap();
                delay(500);
                capit_turun();
                delay(500);
                capit_buka();
                delay(1000);
                capit_naik();
                delay(500);
                miror_[1] = true;
              }

              else if (sEulAnalog.head < set_poin - 55) {
                putar_tinggi_kanan_lambat();
              } else if (sEulAnalog.head > set_poin - 40) {
                putar_tinggi_kiri_lambat();
              }
            }
          }
        }
      }
    }
  }
}

int getRedPW() {

  // Set sensor to read Red only
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}

// Function to read Green Pulse Widths
int getGreenPW() {

  // Set sensor to read Green only
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}

// Function to read Blue Pulse Widths
int getBluePW() {

  // Set sensor to read Blue only
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}
