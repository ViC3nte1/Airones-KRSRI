int data_num = 0;
int data_s = 0;
bool data_select = 0;
bool data_gripper = 0;
bool control = 0;
char com;
bool monitor = 0;
void kalibrasi_servo() {
  if (Serial.available() > 0) {
    com = char(Serial.read());
    if (com == 'm') monitor = !monitor;
    if (com == 'g') data_select = !data_select;
    if (com == 'x') data_gripper = !data_gripper;
    if (com == 'c') control = !control;
    if (data_select == 0) {
      if (control == 0) {
        if (com == 'w') {
          int ww;
          ww++;
          kalibrasi[data_s][data_num] += ww;
        }
        if (com == 's') {
          int ss;
          ss++;
          kalibrasi[data_s][data_num] -= ss;
        }
        if (com == '1') data_num = 0;
        if (com == '2') data_num = 1;
        if (com == '3') data_num = 2;
        if (com == '4') data_num = 3;
        if (com == '5') data_num = 4;
        if (com == '6') data_num = 5;
        if (com == '7') data_s = 0;
        if (com == '8') data_s = 1;
        if (com == '9') data_s = 2;
      }
      if (control == 1) {
        if (com == 'w') {
          int ww;
          ww++;
          i_sudut[data_num] += ww * 0.1;
        }
        if (com == 's') {
          int ss;
          ss++;
          i_sudut[data_num] -= ss * 0.1;
        }
        if (com == '1') data_num = 1;
        if (com == '2') data_num = 2;
      }
    }
    if (data_select == 1) {
      if (data_gripper == 0) {
        if (com == 'w') {
          int ww;
          ww++;
          kalibrasi_offset[1][0] += ww;
        }
        if (com == 's') {
          int ss;
          ss++;
          kalibrasi_offset[1][0] -= ss;
        }
      }
      if (data_gripper == 1) {
        if (com == 'w') {
          int ww;
          ww++;
          kalibrasi_offset[0][0] += ww;
        }
        if (com == 's') {
          int ss;
          ss++;
          kalibrasi_offset[0][0] -= ss;
        }
      }
    }
  }
  if (data_select == 0 & data_gripper == 0 & monitor == 1 & control == 0) Serial.println("S" + String(data_s) + "K" + String(data_num) + ": " + String(kalibrasi[data_s][data_num]));
  if (data_select == 1 & data_gripper == 0 & monitor == 1 & control == 0) Serial.println("capit buka: " + String(kalibrasi_offset[1][0]));
  if (data_select == 1 & data_gripper == 1 & monitor == 1 & control == 0) Serial.println("capit turun: " + String(kalibrasi_offset[0][0]));
  if (monitor == 0 & control == 0) Serial.println("code: " + String(digitalRead(pin_command[0])) + String(digitalRead(pin_command[1])) + String(digitalRead(pin_command[2])) + String(digitalRead(pin_command[3])) + String(digitalRead(pin_command[4])));
  if (control == 1 & data_select == 0) Serial.println("sudut " + String(data_num) + ": " + String(i_sudut[data_num]));
}