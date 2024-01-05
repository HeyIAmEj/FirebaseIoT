const int bt_out1 =  14;
const int bt_out2 =  12;
const int bt_out3 =  13;
const int bt_out4 =  15;

void setup(){
  Serial.begin(115200);
  pinMode(bt_out1, INPUT);
  pinMode(bt_out2, INPUT);
  pinMode(bt_out3, INPUT);
  pinMode(bt_out4, INPUT);
}

void select(int number){
  switch (number) {
  case 1:
  Serial.println("acendeu 1");
  break;
  case 2:
  break;
  case 3:
  break;
  case 4:
  break;
  }
}

void loop(){
  
  if(digitalRead(bt_out1) == HIGH){ 
      select(1);
  }
  if(digitalRead(bt_out2) == HIGH){ 
      select(2);
  }
  if(digitalRead(bt_out3) == HIGH){
      select(3);
  }
  if(digitalRead(bt_out4) == HIGH){ 
      select(4);
  }

  delay(1000);
}
