void pixy_1(){
 int i;
  // grab blocks!
  pixy.ccc.getBlocks();
  
  // If there are detect blocks, print them!
  if (pixy.ccc.numBlocks)
  {
    Serial.print("Detected ");
    Serial.println(pixy.ccc.numBlocks);
    for (i=0; i<pixy.ccc.numBlocks; i++)
    {
      Serial.print("  block ");
      Serial.print(i);
      Serial.print(": ");
      pixy.ccc.blocks[i].print();
      
    }
  }  
}
/*infra_red();
    //pixy_1();
    capit_turun();
    gripper();
    delay(1000);
    capit_naik();

    if (pixy.ccc.numBlocks == 0) {
    siap();
    }
    else if (140 <= pixy.ccc.blocks[0].m_x <= 205 && pixy.ccc.blocks[0].m_width >= 90) {
    Serial.print("hop");
    capit_turun();
    }
    else if (pixy.ccc.blocks[0].m_x > 200) {
    putar_kanan_lambat();
    Serial.print("kanan");
    }
    else if (pixy.ccc.blocks[0].m_x < 140) {
    Serial.print("kiri");
    putar_kiri_lambat();

    }
    else if (pixy.ccc.blocks[0].m_width < 90) {
    maju();
    Serial.print("maju");
    }

    delay(50);*/
