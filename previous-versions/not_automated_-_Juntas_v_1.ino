#include <Servo.h>
#include <SoftwareSerial.h>

char figures [3][9]  = {"Figure_X", "Figure_O", "Figure_+"};
char sounds  [3][7]  = {"100 Hz", "750 Hz", "2000Hz"};
char gates   [3][11] = {"Left Gate ", "CenterGate", "Right Gate"};
char buf [35]; //create a char to store a buffer of 35 charaters to print strings

int angulo = 0;    // Ajust initial servo position

String a, gate;
String pairsNumber1, pairsNumber3, pairsNumber5;
String pairsNumber2, pairsNumber4, pairsNumber6;

// creating servos' objects
Servo leftGate; //gate 1 = left arm and gate
Servo centerGate; //gate 2 = central arm and gate
Servo rightGate; //gate 3 = right arm and gate

void setup() {

  Serial.begin(9600); // boudrate of serialport communication

  leftGate.attach(2); leftGate.write(angulo); // servo 1 to digital output pin 2 - gate 1 = left arm and gate
  centerGate.attach(3); centerGate.write(angulo); // servo 2 to digital output pin 3 - gate 2 = central arm and gate
  rightGate.attach(4); rightGate.write(angulo); // servo 3 to digital output pin 4 - gate 3 = right arm and gate

  randomSeed(analogRead(5)); //read random noise from analog pin 5 and generate random seeds

  for (int a = 5; a <= 13; a++){
    pinMode (a, OUTPUT);
    digitalWrite (a, LOW);
    delay (10);
  } 
  commands ();
}

void loop() {

  if (Serial.available()) { //if serial receives more than 0 bytes, than there is someting to read

    a = Serial.readString();

    if (a == "commands\r\n") {
      commands ();
    }

    else if (a == "mouseID\r\n") {

      Serial.println("Type Mouse Identification Number");

      while (Serial.available () == 0) {}
      a = Serial.readString();
      mouse_info_pairs();
      delay (100);
    }

    //stage_0 - repertory training
    else if (a == "stage0\r\n") {
      Serial.println ("Put the mouse at the central compartment");
      Serial.println ("Initializing Repertory Trainning in 60 seconds");
      for (int i = 0; i <= 60; i ++) {
        sprintf (buf, "Counting: %ds ...", i);
        Serial.println (buf);
        delay (1000);
      }
      tr_repert ();
    }

    else if (a == "repeat\r\n") {
      delay (100);
      repeatRepert ();
      tr_repert ();
    }

    else if (a == "end\r\n") {
      delay (100);
      EndRepert ();
    }
  }
}

void commands () {
  Serial.println ("List of Commands:"); Serial.println ("Type 'mouseID' to set mouse indentification and pairs");
  Serial.println ("Type 'stage0' to initialize Repertory Trainning");
  Serial.println ("Type 'repeat' after every successufull Repertory Trainning attempt");
  Serial.println ("Type 'end' to finish Repertory Tranning"); Serial.println ("Type 'commands' to see this list again");
}

void mouse_info_pairs() {
  Serial.print ("Recived! Configuring and creating conditions to Mouse "); //print to csv
  Serial.println (a);
  delay (500);

  pairsNumber1 = sounds [random(0, 3)];
  pairsNumber2 = figures[random(0, 3)];

  if (pairsNumber1 == sounds[0]) {
    pairsNumber3 = sounds [random(1, 3)]; //choose between 2 or 3 because 1 was already chosen
    pairsNumber5 = sounds [random(1, 3)];
    delay (50);
    while (pairsNumber5 == pairsNumber3) {
      pairsNumber5 = sounds [random(1, 3)];
    }
    delay (50);
  }

  if (pairsNumber1 == sounds[1]) {
    pairsNumber3 = sounds [random(0, 3)]; //choose between 2 or 3 because 1 was already chosen
    while (pairsNumber3 == sounds[1]) {
      pairsNumber3 = sounds [random(0, 3)];
    }
    delay (50);
    pairsNumber5 = sounds [random(0, 3)];
    while (pairsNumber5 == pairsNumber3 || pairsNumber5 == pairsNumber1) {
      pairsNumber5 = sounds [random(0, 3)];
    }
    delay (50);
  }

  if (pairsNumber1 == sounds[2]) {
    pairsNumber3 = sounds [random(0, 2)]; //choose between 2 or 3 because 1 was already chosen
    pairsNumber5 = sounds [random(0, 2)];
    delay (50);
    while (pairsNumber5 == pairsNumber3) {
      pairsNumber5 = sounds [random(0, 2)];
    }
    delay (50);
  }

  if (pairsNumber2 == figures[0]) {
    pairsNumber4 = figures[random(1, 3)]; //choose between 5 or 6 because 4 was already chosen
    pairsNumber6 = figures[random(1, 3)];
    delay (50);
    while (pairsNumber6 == pairsNumber4) {
      pairsNumber6 = figures[random(1, 3)];
    }
    delay (50);
  }

  if (pairsNumber2 == figures[1]) {
    pairsNumber4 = figures [random(0, 3)]; //choose between 2 or 3 because 1 was already chosen
    while (pairsNumber4 == figures[1]) {
      pairsNumber4 = figures [random(0, 3)];
    }
    delay (50);
    pairsNumber6 = figures [random(0, 3)];
    while (pairsNumber6 == pairsNumber4 || pairsNumber6 == pairsNumber2) {
      pairsNumber6 = figures [random(0, 3)];
    }
    delay (50);
  }

  if (pairsNumber2 == figures[2]) {
    pairsNumber4 = figures[random(0, 2)]; //choose between 5 or 6 because 4 was already chosen
    pairsNumber6 = figures[random(0, 2)];
    delay (50);
    while (pairsNumber6 == pairsNumber4) {
      pairsNumber6 = figures[random(0, 2)];
    }
    delay (50);
  }
  Serial.println ("Pairs:");
  Serial.print ("X = "); Serial.print (pairsNumber1); Serial.print (" and ");
  Serial.println (pairsNumber2);
  delay (200);
  Serial.print ("Y = "); Serial.print (pairsNumber3); Serial.print (" and ");
  Serial.println (pairsNumber4);
  delay (200);
  Serial.print ("Z = "); Serial.print (pairsNumber5); Serial.print (" and ");
  Serial.println (pairsNumber6);
}

// repertory training routine
void tr_repert () {

  Serial.println ("Initializing Repertoy Training"); delay (500); //print this to csv file with timestamp!
  Serial.println ("Randomizing arm to open the gate"); delay (500);

  gate = gates [random (0, 3)]; //randomize a number from 1 to 3 that corresponds to the target gates'

  Serial.print ("Oppening ");
  Serial.println (gate);
  delay (1000);

  //openning the target gate from randomization
  if (gate == gates[0]) {
    open_left_gate();
  }
  if (gate == gates [1]) {
    open_center_gate();
  }
  if (gate == gates [2]) {
    open_right_gate();
  }
}

void repeatRepert () {
  Serial.println ("Closing the Gate");

  if (gate == gates[0]) {
    close_left_gate();
  }
  if (gate == gates[1]) {
    close_center_gate();
  }
  if (gate == gates[2]) {
    close_right_gate();
  }
  Serial.println ("The gate was closed! Wait 5 seconds");
  delay (5000);
  randomSeed(analogRead(random(0, 6)));
}

void EndRepert () { //bonsai needs to calculate the time!
  // bonsai needs to work here !! so it can finish the first trial and randomize again

  Serial.print("Closing the gate");
  delay (100);

  if (gate == gates[0]) {
    close_left_gate();
  }
  if (gate == gates[1]) {
    close_center_gate();
  }
  if (gate == gates[2]) {
    close_right_gate();
  }
  Serial.println ("The gate was closed!");
}

//routine to randomize, configure and store pairs condition

// routine to servos postions
void open_left_gate() {
  for (angulo; angulo <= 150; angulo += 1) { // Comando que muda a posição do servo de 0 para 180°
    leftGate.write(angulo); // Comando para angulo específico
    delay(8);
  }
}
void close_left_gate() {
  for (angulo = 150; angulo >= 1; angulo -= 1) { // Comando que muda a posição do servo de 180 para 0°
    leftGate.write(angulo); // Comando para angulo específico
    delay(8);
  }
}
void open_center_gate() {
  for (angulo; angulo <= 150; angulo += 1) { // Comando que muda a posição do servo de 0 para 180°
    centerGate.write(angulo); // Comando para angulo específico
    delay(8);
  }
}
void close_center_gate() {
  for (angulo = 150; angulo >= 1; angulo -= 1) { // Comando que muda a posição do servo de 180 para 0°
    centerGate.write(angulo); // Comando para angulo específico
    delay(8);
  }
}
void open_right_gate() {
  for (angulo; angulo <= 150; angulo += 1) { // Comando que muda a posição do servo de 0 para 180°
    rightGate.write(angulo); // Comando para angulo específico
    delay(8);
  }
}
void close_right_gate() {
  for (angulo = 150; angulo >= 1; angulo -= 1) { // Comando que muda a posição do servo de 180 para 0°
    rightGate.write(angulo); // Comando para angulo específico
    delay(8);
  }
}
/*void open_all_gates() {
  for (angulo = 0; angulo <= 180; angulo += 1) { // Comando que muda a posição do servo de 0 para 180°
    rightGate.write(angulo); // Comando para angulo específico
    centerGate.write(angulo);
    leftGate.write(angulo);
    delay(8);
  }
}
void close_all_gates() {
  for (angulo = 180; angulo >= 1; angulo -= 1) { // Comando que muda a posição do servo de 180 para 0°
    rightGate.write(angulo); // Comando para angulo específico
    centerGate.write(angulo);
    leftGate.write(angulo);
    delay(8);
  }
}*/
