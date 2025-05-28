//komunikasi gerak robot
void siap() {
  digitalWrite(K1, LOW); digitalWrite(K2, LOW); digitalWrite(K3, LOW); digitalWrite(K4, LOW); digitalWrite(K5, LOW);
  lcd.setCursor(0, 0); Serial.print("S");
}
void maju() {
  digitalWrite(K1, HIGH); digitalWrite(K2, HIGH); digitalWrite(K3, HIGH); digitalWrite(K4, HIGH); digitalWrite(K5, LOW);
  lcd.setCursor(0, 0); Serial.print("A");
}
void mundur() {
  digitalWrite(K1, HIGH); digitalWrite(K2, HIGH); digitalWrite(K3, HIGH); digitalWrite(K4, LOW); digitalWrite(K5, HIGH);
  lcd.setCursor(0, 0); Serial.print("B");
}
void putar_kiri() {
  digitalWrite(K1, HIGH); digitalWrite(K2, HIGH); digitalWrite(K3, HIGH); digitalWrite(K4, LOW); digitalWrite(K5, LOW);
  lcd.setCursor(0, 0); lcd.print("C");
}
void putar_kanan() {
  digitalWrite(K1, HIGH); digitalWrite(K2, HIGH); digitalWrite(K3, LOW); digitalWrite(K4, HIGH); digitalWrite(K5, HIGH);
  lcd.setCursor(0, 0); lcd.print("D");
}
void maju_lambat() {
  digitalWrite(K1, HIGH); digitalWrite(K2, HIGH); digitalWrite(K3, LOW); digitalWrite(K4, HIGH); digitalWrite(K5, LOW);
  lcd.setCursor(0, 0); lcd.print("E");
}
void mundur_lambat() {
  digitalWrite(K1, HIGH); digitalWrite(K2, HIGH); digitalWrite(K3, LOW); digitalWrite(K4, LOW); digitalWrite(K5, HIGH);
  lcd.setCursor(0, 0); lcd.print("f");
}
void putar_kiri_lambat() {
  digitalWrite(K1, HIGH); digitalWrite(K2, HIGH); digitalWrite(K3, LOW); digitalWrite(K4, LOW); digitalWrite(K5, LOW);
  lcd.setCursor(0, 0); lcd.print("g");
}
void putar_kanan_lambat() {
  digitalWrite(K1, HIGH); digitalWrite(K2, LOW); digitalWrite(K3, HIGH); digitalWrite(K4, HIGH); digitalWrite(K5, HIGH);
  lcd.setCursor(0, 0); lcd.print("h");
}
void maju_tinggi() {
  digitalWrite(K1, HIGH); digitalWrite(K2, LOW); digitalWrite(K3, HIGH); digitalWrite(K4, HIGH); digitalWrite(K5, LOW);
  lcd.setCursor(0, 0); lcd.print("i");
}
void mundur_tinggi() {
  digitalWrite(K1, HIGH); digitalWrite(K2, LOW); digitalWrite(K3, HIGH); digitalWrite(K4, LOW); digitalWrite(K5, HIGH);
  lcd.setCursor(0, 0); lcd.print("j");
}
void putar_tinggi_kiri() {
  digitalWrite(K1, HIGH); digitalWrite(K2, LOW); digitalWrite(K3, HIGH); digitalWrite(K4, LOW); digitalWrite(K5, LOW);
  lcd.setCursor(0, 0); lcd.print("K");
}
void putar_tinggi_kanan() {
  digitalWrite(K1, HIGH); digitalWrite(K2, LOW); digitalWrite(K3, LOW); digitalWrite(K4, HIGH); digitalWrite(K5, HIGH);
  lcd.setCursor(0, 0); lcd.print("l");
}
void maju_tinggi_lambat() {
  digitalWrite(K1, HIGH); digitalWrite(K2, LOW); digitalWrite(K3, LOW); digitalWrite(K4, HIGH); digitalWrite(K5, LOW);
  lcd.setCursor(0, 0); lcd.print("M");
}
void mundur_tinggi_lambat() {
  digitalWrite(K1, HIGH); digitalWrite(K2, LOW); digitalWrite(K3, LOW); digitalWrite(K4, LOW); digitalWrite(K5, HIGH);
  lcd.setCursor(0, 0); lcd.print("n");
}
void putar_tinggi_kanan_lambat() {
  digitalWrite(K1, LOW); digitalWrite(K2, HIGH); digitalWrite(K3, HIGH); digitalWrite(K4, HIGH); digitalWrite(K5, HIGH);
  lcd.setCursor(0, 0); lcd.print("o");
}
void kiri_lambat() {
  digitalWrite(K1, LOW); digitalWrite(K2, HIGH); digitalWrite(K3, HIGH); digitalWrite(K4, HIGH); digitalWrite(K5, LOW);
  lcd.setCursor(0, 0); lcd.print("p");
}
void kanan_lambat() {
  digitalWrite(K1, LOW); digitalWrite(K2, HIGH); digitalWrite(K3, HIGH); digitalWrite(K4, LOW); digitalWrite(K5, HIGH);
  lcd.setCursor(0, 0); lcd.print("q");
}
void kiri_tinggi() {
  digitalWrite(K1, LOW); digitalWrite(K2, HIGH); digitalWrite(K3, HIGH); digitalWrite(K4, LOW); digitalWrite(K5, LOW);
  lcd.setCursor(0, 0); lcd.print("r");
}
void kanan_tinggi() {
  digitalWrite(K1, LOW); digitalWrite(K2, HIGH); digitalWrite(K3, LOW); digitalWrite(K4, HIGH); digitalWrite(K5, HIGH);
  lcd.setCursor(0, 0); lcd.print("s");
}
void putar_tinggi_kiri_lambat() {
  digitalWrite(K1, LOW); digitalWrite(K2, HIGH); digitalWrite(K3, LOW); digitalWrite(K4, HIGH); digitalWrite(K5, LOW);
  lcd.setCursor(0, 0); lcd.print("t");
}
void maju_tinggi_kiri_lambat() {
  digitalWrite(K1, LOW); digitalWrite(K2, HIGH); digitalWrite(K3, LOW); digitalWrite(K4, LOW); digitalWrite(K5, HIGH);
  lcd.setCursor(0, 0); lcd.print("u");
}
void maju_tinggi_kanan_lambat() {
  digitalWrite(K1, LOW); digitalWrite(K2, HIGH); digitalWrite(K3, LOW); digitalWrite(K4, LOW); digitalWrite(K5, LOW);
  lcd.setCursor(0, 0); lcd.print("v");
}
void langkah_tangga_geser_kiri() {
  digitalWrite(K1, LOW); digitalWrite(K2, LOW); digitalWrite(K3, HIGH); digitalWrite(K4, HIGH); digitalWrite(K5, HIGH);
  lcd.setCursor(0, 0); lcd.print("w");
}
void langkah_tangga_geser_kanan() {
  digitalWrite(K1, LOW); digitalWrite(K2, LOW); digitalWrite(K3, HIGH); digitalWrite(K4, HIGH); digitalWrite(K5, LOW);
  lcd.setCursor(0, 0); lcd.print("x");
}

void capit_turun() {
  digitalWrite(K1, LOW); digitalWrite(K2, LOW); digitalWrite(K3, LOW); digitalWrite(K4, HIGH); digitalWrite(K5, HIGH);
  lcd.setCursor(0, 0);// lcd.print("ag");
}
void capit_naik() {
  digitalWrite(K1, LOW); digitalWrite(K2, LOW); digitalWrite(K3, LOW); digitalWrite(K4, HIGH); digitalWrite(K5, LOW);
  lcd.setCursor(0, 0); lcd.print("ah");
}
void capit_buka() {
  digitalWrite(K1, LOW); digitalWrite(K2, LOW); digitalWrite(K3, LOW); digitalWrite(K4, LOW); digitalWrite(K5, HIGH);
  lcd.setCursor(0, 0); lcd.print("ai");
}
void capit_tutup() {
  digitalWrite(K1, HIGH); digitalWrite(K2, HIGH); digitalWrite(K3, HIGH); digitalWrite(K4, HIGH); digitalWrite(K5, HIGH);
  lcd.setCursor(0, 0); lcd.print("aj");
}
void capit_turun_sebagian() {
  digitalWrite(K1, LOW); digitalWrite(K2, LOW); digitalWrite(K3, HIGH); digitalWrite(K4, LOW); digitalWrite(K5, HIGH);
  lcd.setCursor(0, 0);// lcd.print("ag");
}
/*void pelacakan() {
  HUSKYLENS();
  infra_red();
  bool out = true;
  bool capit = false;
  bool keluar;
  bool target = false;
  while (!target) {
    while (!capit) {
      if (!huskylens.request()) {
        capit = true;
        target = true;
        Serial.print("out");
      }
      else if (!huskylens.isLearned()) {
        capit = true;
        target = true;
        Serial.print("out");
      }
      else if (!huskylens.available()) {
        capit = true;
        target = true;
        Serial.println("out");
      }
      else {
        HUSKYLENSResult result = huskylens.read();
        Serial.println("target");
        //printResult(result);
        if (result.xCenter < 220 && result.xCenter > 120) {
          siap();
          delay(1000);
          keluar = false;
          capit = true;

        }
        else if (result.xCenter >= 220) {
          putar_tinggi_kanan_lambat();
        } else if (result.xCenter <= 120) {
          putar_tinggi_kiri_lambat();
        }
      }
    }
    while (!keluar) {
      int16_t distance_u4 = URM08.getDistance();
      if (distance_u4 <= 7) {
        siap();
        delay(1000);
        capit_turun();
        delay(1000);
        capit_buka();
        delay(500);

        keluar = true;
        out = false;
      }
      else {
        mundur_tinggi_lambat();
      }
    }
    while (!out) {
      ultra_gpr();
      infra_red();
      lcd.print(distance_gpr);
      if (distance_gpr <= 7 || buttonstate2 == LOW) {
        siap();
        delay(1000);
        capit_tutup();
        delay(1000);
        pelacakanx = true;
        out = true;
      }
      else {
        maju_tinggi_lambat();
      }
    }
    target = true;
  }
}

void peletakan() {
  siap();
  delay(1000);
  capit_buka();
  delay(1000);
}
void pelacakan_1a() {
  bool target1 = false;
  bool target2 = false;
  bool target3 = false;
  int16_t distance_u4 = URM08.getDistance();
  ultra_gpr();
  while (!pelacakanx) {
    if (!target1) {
      Serial.println("1");
      BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
      BNO::sEulAnalog_t sEulAnalog;
      sEulAnalog = bno.getEul();

      if (sEulAnalog.head >= set_poin - 82 && sEulAnalog.head <= set_poin - 70) {
        Serial.print("pelacakan1");
        siap();
        delay(1000);
        mundur_tinggi_lambat();
        delay(1000);
        siap();
        delay(2000);
        pelacakan();
        target2 = false;
        target1 = true;

      } else if (sEulAnalog.head < set_poin - 82) {
        putar_tinggi_kanan_lambat();
      } else if (sEulAnalog.head > set_poin - 70) {
        putar_tinggi_kiri_lambat();
      }
    }
    else if (!target2) {
      int16_t distance_u4 = URM08.getDistance();
      Serial.print("2");
      BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
      BNO::sEulAnalog_t sEulAnalog;
      sEulAnalog = bno.getEul();

      if (sEulAnalog.head >= set_poin - 95 && sEulAnalog.head <= set_poin - 85) {
        siap();
        delay(1000);
        mundur_tinggi_lambat();
        delay(1000);
        Serial.print("target2");
        siap();
        delay(2000);
        pelacakan();
        target3 = false;
        target2 = true;

      } else if (sEulAnalog.head < set_poin - 95) {
        putar_tinggi_kanan_lambat();
      } else if (sEulAnalog.head > set_poin - 85) {
        putar_tinggi_kiri_lambat();
      }
    }
    else if (!target3) {
      Serial.print("3");
      BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
      BNO::sEulAnalog_t sEulAnalog;
      sEulAnalog = bno.getEul();

      if (sEulAnalog.head >= set_poin - 118 && sEulAnalog.head <= set_poin - 108) {
        Serial.print("target3");
        siap();
        delay(1000);
        mundur_tinggi_lambat();
        delay(1000);
        siap();
        delay(2000);
        pelacakan();
        target3 = true;
        pelacakanx = true;
      } else if (sEulAnalog.head < set_poin - 118) {
        putar_tinggi_kanan_lambat();
      } else if (sEulAnalog.head > set_poin - 108) {
        putar_tinggi_kiri_lambat();
      }
    }
  }
}
void pelacakan_1b() {
  bool target1 = false;
  bool target2 = false;
  bool target3 = false;
  int16_t distance_u4 = URM08.getDistance();
  ultra_gpr();
  while (!pelacakanx) {
    if (!target1) {
      Serial.println("1");
      BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
      BNO::sEulAnalog_t sEulAnalog;
      sEulAnalog = bno.getEul();

      if (sEulAnalog.head <= set_poin + 82 && sEulAnalog.head >= set_poin + 70) {
        Serial.print("pelacakan1b");
        siap();
        delay(1000);
        mundur_tinggi_lambat();
        delay(1000);
        siap();
        delay(2000);
        pelacakan();
        target2 = false;
        target1 = true;

      } else if (sEulAnalog.head > set_poin + 82) {
        putar_tinggi_kanan_lambat();
      } else if (sEulAnalog.head < set_poin + 70) {
        putar_tinggi_kiri_lambat();
      }
    }
    else if (!target2) {
      int16_t distance_u4 = URM08.getDistance();
      Serial.print("2");
      BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
      BNO::sEulAnalog_t sEulAnalog;
      sEulAnalog = bno.getEul();

      if (sEulAnalog.head <= set_poin - 265 && sEulAnalog.head >= set_poin + 85) {
        siap();
        delay(1000);
        mundur_tinggi_lambat();
        delay(1000);
        siap();
        delay(2000);
        pelacakan();
        target3 = false;
        target2 = true;

      } else if (sEulAnalog.head > set_poin - 265) {
        putar_tinggi_kiri_lambat();
      } else if (sEulAnalog.head < set_poin + 85) {
        putar_tinggi_kanan_lambat();
      }
    }
    else if (!target3) {
      Serial.print("3");
      BNO::sAxisAnalog_t sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
      BNO::sEulAnalog_t sEulAnalog;
      sEulAnalog = bno.getEul();

      if (sEulAnalog.head <= set_poin - 242 && sEulAnalog.head >= set_poin - 252) {
        Serial.print("target3");
        siap();
        delay(1000);
        mundur_tinggi_lambat();
        delay(1000);
        siap();
        delay(2000);
        pelacakan();
        target3 = true;
        pelacakanx = true;
      } else if (sEulAnalog.head > set_poin - 242) {
        putar_tinggi_kanan_lambat();
      } else if (sEulAnalog.head < set_poin - 252) {
        putar_tinggi_kanan_lambat();
      }
    }
  }
}*/
