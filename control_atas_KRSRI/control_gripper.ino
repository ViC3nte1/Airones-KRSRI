void infra_red() {
  buttonstate1 = digitalRead(in_mki);
  //buttonstate2 = digitalRead(in_mka);
  buttonstate3 = digitalRead(in_mt);
}



void gripper() {
  
  if (buttonstate1 == LOW || buttonstate2 == LOW || buttonstate3 == LOW) {
     capit_buka();
  if (buttonstate1 == buttonstate3 == LOW || buttonstate2 == buttonstate3 == LOW || buttonstate1 == buttonstate3 == buttonstate2 == LOW) {
    capit_tutup();
  }
  }
  else{capit_turun();}
 
}
