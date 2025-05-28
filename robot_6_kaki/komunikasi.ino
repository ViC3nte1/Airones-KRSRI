void command(int a, int b, int c, int d, int e) {

  // --> Stop
  if (a == 1 & b == 1 & c == 1 & d == 1 & e == 1) {  // --> 31
    data_k[0] = 50;
    data_k[1] = 0;
    data_k[2] = 0;
    data_k[3] = 0;
    i_sudut[0] = 0;
    i_sudut[1] = 0;
    i_sudut[2] = 0;
    Serial.print("aZ");
  } else if (a == 0 & b == 0 & c == 0 & d == 0 & e == 1) {  // --> 1
    maju();
    Serial.print("a");
  } else if (a == 0 & b == 0 & c == 0 & d == 1 & e == 0) {  // --> 2
    mundur();
    Serial.print("b");
  } else if (a == 0 & b == 0 & c == 0 & d == 1 & e == 1) {  // --> 3
    putar_kiri();
    Serial.print("c");
  } else if (a == 0 & b == 0 & c == 1 & d == 0 & e == 0) {  // --> 4
    putar_kanan();
    Serial.print("d");
  } else if (a == 0 & b == 0 & c == 1 & d == 0 & e == 1) {  // --> 5
    maju_lambat();
     Serial.print("e");
  } else if (a == 0 & b == 0 & c == 1 & d == 1 & e == 0) {  // --> 6
    mundur_lambat();
     Serial.print("f");
  } else if (a == 0 & b == 0 & c == 1 & d == 1 & e == 1) {  // --> 7
    putar_kiri_lambat();
     Serial.print("g");
  } else if (a == 0 & b == 1 & c == 0 & d == 0 & e == 0) {  // --> 8
    putar_kanan_lambat();
     Serial.print("h");
  } else if (a == 0 & b == 1 & c == 0 & d == 0 & e == 1) {  // --> 9
    maju_tinggi();
     Serial.print("i");
  } else if (a == 0 & b == 1 & c == 0 & d == 1 & e == 0) {  // --> 10
    mundur_tinggi();
     Serial.print("j");
  } else if (a == 0 & b == 1 & c == 0 & d == 1 & e == 1) {  // --> 11
    putar_tinggi_kiri();
     Serial.print("k");
  } else if (a == 0 & b == 1 & c == 1 & d == 0 & e == 0) {  // --> 12
    putar_tinggi_kanan();
     Serial.print("l");
  } else if (a == 0 & b == 1 & c == 1 & d == 0 & e == 1) {  // --> 13
    maju_tinggi_lambat();
     Serial.print("m");
  } else if (a == 0 & b == 1 & c == 1 & d == 1 & e == 0) {  // --> 14
    mundur_tinggi_lambat();
     Serial.print("n");
  } else if (a == 0 & b == 1 & c == 1 & d == 1 & e == 1) {  // --> 15
  } else if (a == 1 & b == 0 & c == 0 & d == 0 & e == 0) {  // --> 16
    putar_tinggi_kanan_lambat();
    Serial.print("oo");
  } else if (a == 1 & b == 0 & c == 0 & d == 0 & e == 1) {  // --> 17
    kiri_lambat();
     Serial.print("o");
  } else if (a == 1 & b == 0 & c == 0 & d == 1 & e == 0) {  // --> 18
    kanan_lambat();
     Serial.print("p");
  } else if (a == 1 & b == 0 & c == 0 & d == 1 & e == 1) {  // --> 19
    kiri_tinggi();
     Serial.print("q");
  } else if (a == 1 & b == 0 & c == 1 & d == 0 & e == 0) {  // --> 20
    kanan_tinggi();
     Serial.print("r");
  } else if (a == 1 & b == 0 & c == 1 & d == 0 & e == 1) {  // --> 21
    putar_tinggi_kiri_lambat();
     Serial.print("s");
  } else if (a == 1 & b == 0 & c == 1 & d == 1 & e == 0) {  // --> 22
    maju_tinggi_kiri_lambat();
     Serial.print("t");
  } else if (a == 1 & b == 0 & c == 1 & d == 1 & e == 1) {  // --> 23
    maju_tinggi_kanan_lambat();
     Serial.print("u");
  } else if (a == 1 & b == 1 & c == 0 & d == 0 & e == 0) {  // --> 24
    langkah_tangga_geser_kiri();
     Serial.print("v");
  } else if (a == 1 & b == 1 & c == 0 & d == 0 & e == 1) {  // --> 25
    langkah_tangga_geser_kanan();
     Serial.print("w");
  } else if (a == 1 & b == 1 & c == 0 & d == 1 & e == 0) { // --> 26
    capit_turun_sebagian();
    Serial.print("ak");
  } else if (a == 1 & b == 1 & c == 0 & d == 1 & e == 1) {  // --> 27
    capit_buka_sebagian();
     Serial.print("x");
  } else if (a == 1 & b == 1 & c == 1 & d == 0 & e == 0) {  // --> 28
    capit_turun();
     Serial.print("y");
  } else if (a == 1 & b == 1 & c == 1 & d == 0 & e == 1) {  // --> 29
    capit_naik();
     Serial.print("z");
  } else if (a == 1 & b == 1 & c == 1 & d == 1 & e == 0) {  // --> 30
    capit_buka();
     Serial.print("aa");
  } else if (a == 0 & b == 0 & c == 0 & d == 0 & e == 0) {  // --> 0
    capit_tutup();
     Serial.print("ab");
  }
}

void main_robot() {
  int a = digitalRead(pin_command[0]);
  int b = digitalRead(pin_command[1]);
  int c = digitalRead(pin_command[2]);
  int d = digitalRead(pin_command[3]);
  int e = digitalRead(pin_command[4]);
  command(a, b, c, d, e);
}

void capit_naik() {
  kalibrasi_offset[0][0] = 120;
   delay(100);
   pembersih(45,50);
}
void capit_turun() {
  kalibrasi_offset[0][0] = 0;
   delay(100);
   pembersih(30,45);
}
void capit_turun_sebagian(){
   kalibrasi_offset[0][0] = 40;
   delay(300);
   pembersih(0,0);   
}
void capit_buka() {
  kalibrasi_offset[1][0] = 70;
}
void capit_tutup() {
  kalibrasi_offset[1][0] = 0;
}
void capit_buka_sebagian() {
  kalibrasi_offset[1][0] = 20;
}
