void SEN0253(){
  BNO::sAxisAnalog_t   sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
  BNO::sEulAnalog_t    sEulAnalog;
  BNO::sQuaAnalog_t    sQuaAnalog;
  sAccAnalog = bno.getAxis(BNO::eAxisAcc);    // read acceleration
  sMagAnalog = bno.getAxis(BNO::eAxisMag);    // read geomagnetic
  sGyrAnalog = bno.getAxis(BNO::eAxisGyr);    // read gyroscope
  sLiaAnalog = bno.getAxis(BNO::eAxisLia);    // read linear acceleration
  sGrvAnalog = bno.getAxis(BNO::eAxisGrv);    // read gravity vector
  sEulAnalog = bno.getEul();                  // read euler angle
  sQuaAnalog = bno.getQua();                  // read quaternion
  Serial.println();
  Serial.println("======== analog data print start ========");
  Serial.print("acc analog: (unit mg)       "); printAxisData(sAccAnalog);
  Serial.print("mag analog: (unit ut)       "); printAxisData(sMagAnalog);
  Serial.print("gyr analog: (unit dps)      "); printAxisData(sGyrAnalog);
  Serial.print("lia analog: (unit mg)       "); printAxisData(sLiaAnalog);
  Serial.print("grv analog: (unit mg)       "); printAxisData(sGrvAnalog);
  Serial.print("eul analog: (unit degree)   "); Serial.print(" head: "); Serial.print(sEulAnalog.head); Serial.print(" roll: "); Serial.print(sEulAnalog.roll);  Serial.print(" pitch: "); Serial.println(sEulAnalog.pitch);
  Serial.print("qua analog: (no unit)       "); Serial.print(" w: "); Serial.print(sQuaAnalog.w); printAxisData(sQuaAnalog);
  Serial.println("========  analog data print end  ========");

  delay(300);
}


void rotasi_90(){
   bool rot_90 = LOW;
  while(!rot_90){
 BNO::sAxisAnalog_t   sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
  BNO::sEulAnalog_t    sEulAnalog;
  BNO::sQuaAnalog_t    sQuaAnalog;
  sAccAnalog = bno.getAxis(BNO::eAxisAcc);    // read acceleration
  sMagAnalog = bno.getAxis(BNO::eAxisMag);    // read geomagnetic
  sGyrAnalog = bno.getAxis(BNO::eAxisGyr);    // read gyroscope
  sLiaAnalog = bno.getAxis(BNO::eAxisLia);    // read linear acceleration
  sGrvAnalog = bno.getAxis(BNO::eAxisGrv);    // read gravity vector
  sEulAnalog = bno.getEul();                  // read euler angle
  sQuaAnalog = bno.getQua();                  // read quaternion
 
    if( sEulAnalog.head >= 89 && sEulAnalog.head <= 91 ){
      siap();
      Serial.print("siap");
      rot_90 = HIGH;
    }
     else if(sEulAnalog.head < 85){
      putar_tinggi_kanan();
      Serial.print("kanan");
    }
    else if(sEulAnalog.head > 95){
      putar_tinggi_kiri();
      Serial.print("kiri");
    }
  }
}

void rotasi_180(){
  bool rot_180 = LOW;
  while(!rot_180){
    BNO::sAxisAnalog_t   sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
  BNO::sEulAnalog_t    sEulAnalog;
  BNO::sQuaAnalog_t    sQuaAnalog;
  sAccAnalog = bno.getAxis(BNO::eAxisAcc);    // read acceleration
  sMagAnalog = bno.getAxis(BNO::eAxisMag);    // read geomagnetic
  sGyrAnalog = bno.getAxis(BNO::eAxisGyr);    // read gyroscope
  sLiaAnalog = bno.getAxis(BNO::eAxisLia);    // read linear acceleration
  sGrvAnalog = bno.getAxis(BNO::eAxisGrv);    // read gravity vector
  sEulAnalog = bno.getEul();                  // read euler angle
  sQuaAnalog = bno.getQua();                  // read quaternion
  
    if( sEulAnalog.head >= set_poin - 90&& sEulAnalog.head <= 181){
      siap();
      Serial.print("siap");
      rot_180 = HIGH;
    }
     else if(sEulAnalog.head < 175){
      putar_kanan_lambat();
      Serial.print("kanan");
    }
    else if(sEulAnalog.head > 185){
      putar_kiri_lambat();
      Serial.print("kiri");
    }
  }
}

void rotasi_270(){
  putar_kiri_lambat();
  bool rot_270 = LOW;
  while(!rot_270){
    BNO::sAxisAnalog_t   sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
  BNO::sEulAnalog_t    sEulAnalog;
  BNO::sQuaAnalog_t    sQuaAnalog;
  sAccAnalog = bno.getAxis(BNO::eAxisAcc);    // read acceleration
  sMagAnalog = bno.getAxis(BNO::eAxisMag);    // read geomagnetic
  sGyrAnalog = bno.getAxis(BNO::eAxisGyr);    // read gyroscope
  sLiaAnalog = bno.getAxis(BNO::eAxisLia);    // read linear acceleration
  sGrvAnalog = bno.getAxis(BNO::eAxisGrv);    // read gravity vector
  sEulAnalog = bno.getEul();                  // read euler angle
  sQuaAnalog = bno.getQua();                  // read quaternion
  
    if( sEulAnalog.head >= 269 && sEulAnalog.head <= 271){
      siap();
      Serial.print("siap");
      rot_270 = HIGH;
    }
     else if(sEulAnalog.head < 265){
      putar_tinggi_kanan();
      Serial.print("kanan");
    }
    else if(sEulAnalog.head > 275){
      putar_tinggi_kiri();
      Serial.print("kiri");
    }
  }
}

void rotasi_0(){
  bool rot_0 = LOW;
  while(!rot_0){
     BNO::sAxisAnalog_t   sAccAnalog, sMagAnalog, sGyrAnalog, sLiaAnalog, sGrvAnalog;
  BNO::sEulAnalog_t    sEulAnalog;
  BNO::sQuaAnalog_t    sQuaAnalog;
  sAccAnalog = bno.getAxis(BNO::eAxisAcc);    // read acceleration
  sMagAnalog = bno.getAxis(BNO::eAxisMag);    // read geomagnetic
  sGyrAnalog = bno.getAxis(BNO::eAxisGyr);    // read gyroscope
  sLiaAnalog = bno.getAxis(BNO::eAxisLia);    // read linear acceleration
  sGrvAnalog = bno.getAxis(BNO::eAxisGrv);    // read gravity vector
  sEulAnalog = bno.getEul();                  // read euler angle
  sQuaAnalog = bno.getQua();                  // read quaternion
  
    if( sEulAnalog.head >= 359 || sEulAnalog.head <= 2){
      siap();
      Serial.print("siap");
      rot_0 = HIGH;
    }
     else if(sEulAnalog.head < 355 && sEulAnalog.head > 180){
      putar_kanan_lambat();
      Serial.print("kanan");
    }
    else if(sEulAnalog.head > 5 && sEulAnalog.head < 180){
      putar_kiri_lambat();
      Serial.print("kiri");
    }
  }
}
