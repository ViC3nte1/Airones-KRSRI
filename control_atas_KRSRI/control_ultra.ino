//control ultra
void ultra_u1(){
 int16_t distance_u1 = URM09.getDistance();
  //float temp_u1 = URM09.getTemperature();
}
void ultra_u2(){
  digitalWrite(tring_u2, LOW);
  delayMicroseconds(2);
  digitalWrite(tring_u2, HIGH);
  delayMicroseconds(2);
  digitalWrite(tring_u2, LOW);

  duration_u2 = pulseIn(echo_u2,HIGH); 
  distance_u2 = duration_u2*0.0343/2;
}
void ultra_u3(){
  digitalWrite(tring_u3, LOW);
  delayMicroseconds(2);
  digitalWrite(tring_u3, HIGH);
  delayMicroseconds(2);
  digitalWrite(tring_u3, LOW);

  duration_u3 = pulseIn(echo_u3,HIGH); 
  distance_u3 = duration_u3*0.0343/2;
}

void ultra_u4(){
   int16_t distance_u4 = URM08.getDistance();                // Read distance
  //float temp_u4 = URM08.getTemperature();               // Read temperature
}
void ultra_u5(){
  digitalWrite(tring_u5, LOW);
  delayMicroseconds(2);
  digitalWrite(tring_u5, HIGH);
  delayMicroseconds(2);
  digitalWrite(tring_u5, LOW);

  duration_u5 = pulseIn(echo_u5,HIGH); 
  distance_u5 = duration_u5*0.0343/2;
}
void ultra_u6(){
  digitalWrite(tring_u6, LOW);
  delayMicroseconds(2);
  digitalWrite(tring_u6, HIGH);
  delayMicroseconds(2);
  digitalWrite(tring_u6, LOW);

  duration_u6 = pulseIn(echo_u6,HIGH); 
  distance_u6 = duration_u6*0.0343/2;
}
void ultra_u7(){
  int16_t distance_u7 = URM07.getDistance();                // Read distance
  //float temp_u7 = URM07.getTemperature();               // Read temperature
}

void ultra_u8(){
   int16_t  dist, temp;
  pinMode(trigechoPin,OUTPUT);
  digitalWrite(trigechoPin,LOW);

  digitalWrite(trigechoPin,HIGH);//Set the trig pin High
  delayMicroseconds(10);     //Delay of 10 microseconds
  digitalWrite(trigechoPin,LOW); //Set the trig pin Low

  pinMode(trigechoPin,INPUT);//Set the pin to input mode
  pulseWidthUs = pulseIn(trigechoPin,HIGH);//Detect the high level time on the echo pin, the output high level time represents the ultrasonic flight time (unit: us)

  distance_u8 = pulseWidthUs * VELOCITY_TEMP(20);
}
//display ultra
void display_ultra(){
   int16_t distance_u1 = URM09.getDistance();
  ultra_u2();
  ultra_u3();
  int16_t distance_u4 = URM08.getDistance();
  ultra_u5();
  ultra_u6();
   int16_t distance_u7 = URM07.getDistance();
  ultra_u8();
  ultra_gpr();
  lcd.setCursor(0,0);
  Serial.print("u1 :");
  Serial.print(distance_u1);
  lcd.setCursor(80,0);
  Serial.print("  u2 :");
  Serial.print(distance_u2);
  lcd.setCursor(0,12);
  Serial.print("  u3 :");
  Serial.print(distance_u3);
  lcd.setCursor(80,12);
  Serial.print("u4 :");
  Serial.print(distance_u4);
  lcd.setCursor(0,24);
 Serial.print("u5 :");
 Serial.print(distance_u5);
  lcd.setCursor(80,24);
  Serial.print("gripper :");
  Serial.println(distance_gpr);
  lcd.display();
  Serial.print("u6 :");
  Serial.print(distance_u6);
   Serial.print("  u7 :");
  Serial.println(distance_u7);
   Serial.print("u8 :");
  Serial.print(distance_u8);
  
  
}
// gerak ultra
/*void belok_kiri(){
  if(distance_ <7 & distance_ka <5 & distance_ki>5){
    kiri_lambat();
  }
  else{
    maju_lambat();
  }
}*/
void ultra_gpr(){
  digitalWrite(tring_gpr, LOW);
  digitalWrite(tring_gpr, HIGH);
  digitalWrite(tring_gpr, LOW);

  duration_gpr = pulseIn(echo_gpr,HIGH); 
  distance_gpr = duration_gpr*0.0343/2;
}

void start_ultra(){
  ultra_u2();
  ultra_u6();
  lcd.setCursor(0,60);
  lcd.print("su");
  bool ultra = false;
  bool ka = false;
  bool ki = false;
  while(!ultra){
    if(distance_u6 > distance_u2){
      ka = false;
      ki = true;
      ultra = true;
    }
    else{
      ki = false;
      ka = true;
      ultra = true;
    }
  }
  while (!ka){
      rotasi_90();
      lcd.setCursor(0,16);
      lcd.print("90");
      lcd.display();
      ka = true;
      ki = true;
  }
  while (!ki){
      rotasi_270();
      lcd.setCursor(0,16);
      lcd.print("270");
      lcd.display();
      ki = true;
      ka = true;
  }
 }

void kalibrasi_ultra(){
   int16_t distance_u1 = URM09.getDistance();
  int16_t distance_u4 = URM08.getDistance();
  int16_t distance_u7 = URM07.getDistance();

  if (distance_u1 <= 2 || distance_u1 >= 120) distance_u1 = 0;
  if (distance_u2 <= 4 || distance_u2 >= 120) distance_u2 = 0;
  if (distance_u3 <= 4 || distance_u3 >= 120) distance_u3 = 0;
  if (distance_u4 <= 2 || distance_u4 >= 120) distance_u4 = 0;
  if (distance_u5 <= 4 || distance_u5 >= 120) distance_u5 = 0;
  if (distance_u6 <= 4 || distance_u6 >= 120) distance_u6 = 0;
  if (distance_u7 <= 2 || distance_u7 >= 120) distance_u7 = 0;
  if (distance_u8 <= 2 || distance_u8 >= 120) distance_u8 = 0;
}
