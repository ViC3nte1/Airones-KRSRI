int8_t data_in[2][2] = {
  { 0, 0 },
  { 0, 0 }
};

bool il_stat[2] = { 0, 0 };

void tripod(float x, float y, float z, float s_x, float s_y, float s_z) {

  float px_0 = rotasi(x, y, z, offset_body[0][0], offset_body[1][0], 0, 0, s_z, 'x');
  float py_0 = rotasi(x, y, z, offset_body[0][0], offset_body[1][0], 0, 0, s_z, 'y');
  float pz_0 = rotasi(x, y, z, offset_body[0][0], offset_body[1][0], 0, 0, s_z, 'z');
  float px_1 = rotasi(x, y, z, offset_body[0][1], offset_body[1][1], 0, 0, s_z, 'x');
  float py_1 = rotasi(x, y, z, offset_body[0][1], offset_body[1][1], 0, 0, s_z, 'y');
  float pz_1 = rotasi(x, y, z, offset_body[0][1], offset_body[1][1], 0, 0, s_z, 'z');
  float px_2 = rotasi(x, y, z, offset_body[0][2], offset_body[1][2], 0, 0, s_z, 'x');
  float py_2 = rotasi(x, y, z, offset_body[0][2], offset_body[1][2], 0, 0, s_z, 'y');
  float pz_2 = rotasi(x, y, z, offset_body[0][2], offset_body[1][2], 0, 0, s_z, 'z');
  float px_3 = rotasi(x, y, z, offset_body[0][3], offset_body[1][3], 0, 0, s_z, 'x');
  float py_3 = rotasi(x, y, z, offset_body[0][3], offset_body[1][3], 0, 0, s_z, 'y');
  float pz_3 = rotasi(x, y, z, offset_body[0][3], offset_body[1][3], 0, 0, s_z, 'z');
  float px_4 = rotasi(x, y, z, offset_body[0][4], offset_body[1][4], 0, 0, s_z, 'x');
  float py_4 = rotasi(x, y, z, offset_body[0][4], offset_body[1][4], 0, 0, s_z, 'y');
  float pz_4 = rotasi(x, y, z, offset_body[0][4], offset_body[1][4], 0, 0, s_z, 'z');
  float px_5 = rotasi(x, y, z, offset_body[0][5], offset_body[1][5], 0, 0, s_z, 'x');
  float py_5 = rotasi(x, y, z, offset_body[0][5], offset_body[1][5], 0, 0, s_z, 'y');
  float pz_5 = rotasi(x, y, z, offset_body[0][5], offset_body[1][5], 0, 0, s_z, 'z');

  if (il_stat[0] == 0) {
    if (data_in[0][0] <= totalStep[0]) {
      trajektori(data_in[0][0], timeStep[0], posisi.x3, px_3, posisi.y3, py_3, pz_3, 3, 'U', totalTime, s_x, s_y, 0);
      trajektori(data_in[0][0], timeStep[0], posisi.x1, px_1, posisi.y1, py_1, pz_1, 1, 'U', totalTime, s_x, s_y, 0);
      trajektori(data_in[0][0], timeStep[0], posisi.x5, px_5, posisi.y5, py_5, pz_5, 5, 'U', totalTime, s_x, s_y, 0);
      data_in[0][0]++;
      if (data_in[0][0] >= totalStep[0]) {
        il_stat[0] = 1;
        posisi.x3 = px_3;
        posisi.x1 = px_1;
        posisi.x5 = px_5;
        posisi.y3 = py_3;
        posisi.y1 = py_1;
        posisi.y5 = py_5;
      }
    }
  }
  if (data_in[0][0] >= totalStep[0] & data_in[1][0] <= totalStep[1]) {
    trajektori(data_in[1][0], timeStep[1], posisi.x3, -px_3, posisi.y3, -py_3, 0, 3, 'D', totalTime, s_x, s_y, 0);
    trajektori(data_in[1][0], timeStep[1], posisi.x1, -px_1, posisi.y1, -py_1, 0, 1, 'D', totalTime, s_x, s_y, 0);
    trajektori(data_in[1][0], timeStep[1], posisi.x5, -px_5, posisi.y5, -py_5, 0, 5, 'D', totalTime, s_x, s_y, 0);
    data_in[1][0]++;
    if (data_in[1][0] >= offset_g[0]) il_stat[1] = 1;
    if (data_in[1][0] >= totalStep[1]) {
      data_in[0][0] = 0;
      data_in[1][0] = 0;
      posisi.x3 = -px_3;
      posisi.x1 = -px_1;
      posisi.x5 = -px_5;
      posisi.y3 = -py_3;
      posisi.y1 = -py_1;
      posisi.y5 = -py_5;
    }
  }
  if (il_stat[1] == 1) {
    if (data_in[0][1] <= totalStep[0]) {
      trajektori(data_in[0][1], timeStep[0], posisi.x0, px_0, posisi.y0, py_0, pz_0, 0, 'U', totalTime, s_x, s_y, 0);
      trajektori(data_in[0][1], timeStep[0], posisi.x4, px_4, posisi.y4, py_4, pz_4, 4, 'U', totalTime, s_x, s_y, 0);
      trajektori(data_in[0][1], timeStep[0], posisi.x2, px_2, posisi.y2, py_2, pz_2, 2, 'U', totalTime, s_x, s_y, 0);
      data_in[0][1]++;
      if (data_in[0][1] >= totalStep[0]) {
        il_stat[1] = 0;
        posisi.x0 = px_0;
        posisi.x4 = px_4;
        posisi.x2 = px_2;
        posisi.y0 = py_0;
        posisi.y4 = py_4;
        posisi.y2 = py_2;
      }
    }
  }
  if (data_in[0][1] >= totalStep[0] & data_in[1][1] <= totalStep[1]) {
    trajektori(data_in[1][1], timeStep[1], posisi.x0, -px_0, posisi.y0, -py_0, 0, 0, 'D', totalTime, s_x, s_y, 0);
    trajektori(data_in[1][1], timeStep[1], posisi.x4, -px_4, posisi.y4, -py_4, 0, 4, 'D', totalTime, s_x, s_y, 0);
    trajektori(data_in[1][1], timeStep[1], posisi.x2, -px_2, posisi.y2, -py_2, 0, 2, 'D', totalTime, s_x, s_y, 0);
    data_in[1][1]++;
    il_stat[0] = 0;
    if (data_in[1][1] >= totalStep[1]) {
      data_in[0][1] = 0;
      data_in[1][1] = 0;
      posisi.x0 = -px_0;
      posisi.x4 = -px_4;
      posisi.x2 = -px_2;
      posisi.y0 = -py_0;
      posisi.y4 = -py_4;
      posisi.y2 = -py_2;
    }
  }
}

unsigned long time_d = millis();
void gerak_tripod(int speed, float x, float y, float z, float ss_x, float ss_y, float ss_z) {
  if (millis() - time_d >= speed) {
    tripod(x, y, z, ss_x, ss_y, ss_z);
    time_d = millis();
  }
}