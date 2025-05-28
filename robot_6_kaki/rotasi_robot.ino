float rotasi(float x, float y, float z, float of_x, float of_y, float sudut_x, float sudut_y, float sudut_z, char com) {
  float
    x1 = x + of_x,
    y1 = y + of_y,
    z1 = z,
    matrik_R1[3][1] = { 0 },
    matrik_temp[3][3] = { 0 },
    matrik_last[3][3] = { 0 },
    sinA = sin(sudut_x),
    sinB = sin(sudut_y),
    sinY = sin(sudut_z),
    cosA = cos(sudut_x),
    cosB = cos(sudut_y),
    cosY = cos(sudut_z);

  float matrik_x[3][3] = {
    { 1, 0, 0 },
    { 0, cosA, -sinA },
    { 0, sinA, cosA },
  };

  float matrik_y[3][3] = {
    { cosB, 0, sinB },
    { 0, 1, 0 },
    { -sinB, 0, cosB },
  };

  float matrik_z[3][3] = {
    { cosY, -sinY, 0 },
    { sinY, cosY, 0 },
    { 0, 0, 1 }
  };

  float matrik_R0[3][1] = {
    { x1 },
    { y1 },
    { z1 }
  };

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        matrik_temp[i][j] += matrik_x[i][k] * matrik_y[k][j];
      }
    }
  }

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        matrik_last[i][j] += matrik_temp[i][k] * matrik_z[k][j];
      }
    }
  }

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 1; ++j) {
      for (int k = 0; k < 3; ++k) {
        matrik_R1[i][j] += matrik_last[i][k] * matrik_R0[k][j];
      }
    }
  }

  if (com == 'x') {
    float x2 = matrik_R1[0][0] - of_x;
    return x2;
  } else if (com == 'y') {
    float y2 = matrik_R1[1][0] - of_y;
    return y2;
  } else if (com == 'z') {
    float z2 = matrik_R1[2][0];
    return z2;
  }
}