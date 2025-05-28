
const int8_t default_kaki[3][6] = {
  { 60, 60, 60, 60, 60, 60 },
  { 35, 0, -35, 35, 0, -35 },
  { 50, 50, 50, 50, 50, 50 },
};

// --> PERHITUNGAN INVERS KINEMATIK
int8_t invers(float x, float y, float z, char com) {
  float
    radian = 180 / PI,
    femurLength = 60.00,
    tibiaLength = 50.00,
    coxa_Length = 25.00;

  float legLength = sqrt(pow(x, 2) + pow(y, 2));
  float Z_Length = sqrt(pow(z, 2) + pow((legLength - coxa_Length), 2));
  float Sud_A = atan(legLength / z) * radian;
  float Sud_B = acos((pow(femurLength, 2) + pow(Z_Length, 2) - pow(tibiaLength, 2)) / (2 * femurLength * Z_Length)) * radian;
  float Sud_C = acos((pow(femurLength, 2) + pow(tibiaLength, 2) - pow(Z_Length, 2)) / (2 * femurLength * tibiaLength)) * radian;
  if (com == 'A') {
    int8_t Alpha = atan(y / x) * radian;
    return Alpha;
  } else if (com == 'B') {
    int8_t Betha = (Sud_A + Sud_B) - 98;
    return Betha;
  } else if (com == 'G') {
    int8_t Gamma = Sud_C - 66;
    return Gamma;
  }
}

// --> EKSEKUSI GERAK KAKI 0
void invers_kaki_0(float x, float y, float z) {
  pwm.setPWM(pin_num_pca[0][0], 0, sudut(kalibrasi[0][0] + invers(x, y, z, 'A')));
  servo_1.write(kalibrasi[1][0] + invers(x, y, z, 'B'));
  pwm.setPWM(pin_num_pca[1][0], 0, sudut(kalibrasi[2][0] - invers(x, y, z, 'G')));
}

// --> EKSEKUSI GERAK KAKI 1
void invers_kaki_1(float x, float y, float z) {
  pwm.setPWM(pin_num_pca[0][1], 0, sudut(kalibrasi[0][1] + invers(x, y, z, 'A')));
  servo_2.write(kalibrasi[1][1] + invers(x, y, z, 'B'));
  pwm.setPWM(pin_num_pca[1][1], 0, sudut(kalibrasi[2][1] - invers(x, y, z, 'G')));
}

// --> EKSEKUSI GERAK KAKI 2
void invers_kaki_2(float x, float y, float z) {
  pwm.setPWM(pin_num_pca[0][2], 0, sudut(kalibrasi[0][2] + invers(x, y, z, 'A')));
  servo_3.write(kalibrasi[1][2] + invers(x, y, z, 'B'));
  pwm.setPWM(pin_num_pca[1][2], 0, sudut(kalibrasi[2][2] - invers(x, y, z, 'G')));
}

// --> EKSEKUSI GERAK KAKI 3
void invers_kaki_3(float x, float y, float z) {
  pwm.setPWM(pin_num_pca[0][3], 0, sudut(kalibrasi[0][3] - invers(x, y, z, 'A')));
  servo_4.write(kalibrasi[1][3] - invers(x, y, z, 'B'));
  pwm.setPWM(pin_num_pca[1][3], 0, sudut(kalibrasi[2][3] + invers(x, y, z, 'G')));
}

// --> EKSEKUSI GERAK KAKI 4
void invers_kaki_4(float x, float y, float z) {
  pwm.setPWM(pin_num_pca[0][4], 0, sudut(kalibrasi[0][4] - invers(x, y, z, 'A')));
  servo_5.write(kalibrasi[1][4] - invers(x, y, z, 'B'));
  pwm.setPWM(pin_num_pca[1][4], 0, sudut(kalibrasi[2][4] + invers(x, y, z, 'G')));
}

// --> EKSEKUSI GERAK KAKI 5
void invers_kaki_5(float x, float y, float z) {
  pwm.setPWM(pin_num_pca[0][5], 0, sudut(kalibrasi[0][5] - invers(x, y, z, 'A')));
  servo_6.write(kalibrasi[1][5] - invers(x, y, z, 'B'));
  pwm.setPWM(pin_num_pca[1][5], 0, sudut(kalibrasi[2][5] + invers(x, y, z, 'G')));
}

void trajektori(float i, float timeStep, float x_awal, float x_akhir, float y_awal, float y_akhir, float z_tinggi, int kaki, char com, float totalTime, float s_x, float s_y, float s_z) {
  float t = i * timeStep;
  float
    a = pow((1 - t), 3),
    b = 3 * t * pow((1 - t), 2),
    c = 3 * pow(t, 2) * (1 - t),
    d = pow(t, 3);

  float v0x = hitung_selisih_posisi(x_awal, x_akhir, totalTime);
  float v0y = hitung_selisih_posisi(y_awal, y_akhir, totalTime);

  if (kaki == 0) {
    float px_0 = rotasi(0, 0, 0, offset_body[0][0], offset_body[1][0], s_x, s_y, s_z, 'x');
    float py_0 = rotasi(0, 0, 0, offset_body[0][0], offset_body[1][0], s_x, s_y, s_z, 'y');
    float pz_0 = rotasi(0, 0, 0, offset_body[0][0], offset_body[1][0], s_x, s_y, s_z, 'z');
    if (com == 'U') {
      float px = (a * x_awal) + (b * x_awal) + (c * x_akhir) + (d * x_akhir);
      float py = (a * y_awal) + (b * y_awal) + (c * y_akhir) + (d * y_akhir);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_0(default_kaki[0][0] - px - px_0, default_kaki[1][0] + py + py_0, default_kaki[2][0] - pz - pz_0 + tinggi[0]);
    }
    if (com == 'D') {
      float px = hitung(x_awal, v0x, t);
      float py = hitung(y_awal, v0y, t);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_0(default_kaki[0][0] - px - px_0, default_kaki[1][0] + py + py_0, default_kaki[2][0] - pz - pz_0 + tinggi[0]);
    }
  }
  if (kaki == 1) {
    float px_1 = rotasi(0, 0, 0, offset_body[0][1], offset_body[1][1], s_x, s_y, s_z, 'x');
    float py_1 = rotasi(0, 0, 0, offset_body[0][1], offset_body[1][1], s_x, s_y, s_z, 'y');
    float pz_1 = rotasi(0, 0, 0, offset_body[0][1], offset_body[1][1], s_x, s_y, s_z, 'z');
    if (com == 'U') {
      float px = (a * x_awal) + (b * x_awal) + (c * x_akhir) + (d * x_akhir);
      float py = (a * y_awal) + (b * y_awal) + (c * y_akhir) + (d * y_akhir);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_1(default_kaki[0][1] - px - px_1, default_kaki[1][1] + py + py_1, default_kaki[2][1] - pz - pz_1 + tinggi[0]);
    }
    if (com == 'D') {
      float px = hitung(x_awal, v0x, t);
      float py = hitung(y_awal, v0y, t);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_1(default_kaki[0][1] - px - px_1, default_kaki[1][1] + py + py_1, default_kaki[2][1] - pz - pz_1 + tinggi[0]);
    }
  }
  if (kaki == 2) {
    float px_2 = rotasi(0, 0, 0, offset_body[0][2], offset_body[1][2], s_x, s_y, s_z, 'x');
    float py_2 = rotasi(0, 0, 0, offset_body[0][2], offset_body[1][2], s_x, s_y, s_z, 'y');
    float pz_2 = rotasi(0, 0, 0, offset_body[0][2], offset_body[1][2], s_x, s_y, s_z, 'z');
    if (com == 'U') {
      float px = (a * x_awal) + (b * x_awal) + (c * x_akhir) + (d * x_akhir);
      float py = (a * y_awal) + (b * y_awal) + (c * y_akhir) + (d * y_akhir);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_2(default_kaki[0][2] - px - px_2, default_kaki[1][2] + py + py_2, default_kaki[2][2] - pz - pz_2 + tinggi[0]);
    }
    if (com == 'D') {
      float px = hitung(x_awal, v0x, t);
      float py = hitung(y_awal, v0y, t);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_2(default_kaki[0][2] - px - px_2, default_kaki[1][2] + py + py_2, default_kaki[2][2] - pz - pz_2 + tinggi[0]);
    }
  }
  if (kaki == 3) {
    float px_3 = rotasi(0, 0, 0, offset_body[0][3], offset_body[1][3], s_x, s_y, s_z, 'x');
    float py_3 = rotasi(0, 0, 0, offset_body[0][3], offset_body[1][3], s_x, s_y, s_z, 'y');
    float pz_3 = rotasi(0, 0, 0, offset_body[0][3], offset_body[1][3], s_x, s_y, s_z, 'z');
    if (com == 'U') {
      float px = (a * x_awal) + (b * x_awal) + (c * x_akhir) + (d * x_akhir);
      float py = (a * y_awal) + (b * y_awal) + (c * y_akhir) + (d * y_akhir);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_3(default_kaki[0][3] + px + px_3, default_kaki[1][3] + py + py_3, default_kaki[2][3] - pz - pz_3 + tinggi[0]);
    }
    if (com == 'D') {
      float px = hitung(x_awal, v0x, t);
      float py = hitung(y_awal, v0y, t);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_3(default_kaki[0][3] + px + px_3, default_kaki[1][3] + py + py_3, default_kaki[2][3] - pz - pz_3 + tinggi[0]);
    }
  }
  if (kaki == 4) {
    float px_4 = rotasi(0, 0, 0, offset_body[0][4], offset_body[1][4], s_x, s_y, s_z, 'x');
    float py_4 = rotasi(0, 0, 0, offset_body[0][4], offset_body[1][4], s_x, s_y, s_z, 'y');
    float pz_4 = rotasi(0, 0, 0, offset_body[0][4], offset_body[1][4], s_x, s_y, s_z, 'z');
    if (com == 'U') {
      float px = (a * x_awal) + (b * x_awal) + (c * x_akhir) + (d * x_akhir);
      float py = (a * y_awal) + (b * y_awal) + (c * y_akhir) + (d * y_akhir);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_4(default_kaki[0][4] + px + px_4, default_kaki[1][4] + py + py_4, default_kaki[2][4] - pz - pz_4 + tinggi[0]);
    }
    if (com == 'D') {
      float px = hitung(x_awal, v0x, t);
      float py = hitung(y_awal, v0y, t);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_4(default_kaki[0][4] + px + px_4, default_kaki[1][4] + py + py_4, default_kaki[2][4] - pz - pz_4 + tinggi[0]);
    }
  }
  if (kaki == 5) {
    float px_5 = rotasi(0, 0, 0, offset_body[0][5], offset_body[1][5], s_x, s_y, s_z, 'x');
    float py_5 = rotasi(0, 0, 0, offset_body[0][5], offset_body[1][5], s_x, s_y, s_z, 'y');
    float pz_5 = rotasi(0, 0, 0, offset_body[0][5], offset_body[1][5], s_x, s_y, s_z, 'z');
    if (com == 'U') {
      float px = (a * x_awal) + (b * x_awal) + (c * x_akhir) + (d * x_akhir);
      float py = (a * y_awal) + (b * y_awal) + (c * y_akhir) + (d * y_akhir);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_5(default_kaki[0][5] + px + px_5, default_kaki[1][5] + py + py_5, default_kaki[2][5] - pz - pz_5 + tinggi[0]);
    }
    if (com == 'D') {
      float px = hitung(x_awal, v0x, t);
      float py = hitung(y_awal, v0y, t);
      float pz = (b * z_tinggi) + (c * z_tinggi);
      invers_kaki_5(default_kaki[0][5] + px + px_5, default_kaki[1][5] + py + py_5, default_kaki[2][5] - pz - pz_5 + tinggi[0]);
    }
  }
}

float hitung(float awal, float dat, float t) {
  return awal + (dat * t);
}

float hitung_selisih_posisi(float awal, float akhir, float totalTime) {
  return (akhir - awal) / totalTime;
}
