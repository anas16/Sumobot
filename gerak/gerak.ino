/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int angle = 0;
int reangle = 0;

void setup() {
  myservo1.attach(13);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
}

void loop() {
    angle = map(angle,0,1023,0,360);
    reangle = map(reangle,1023,0,0,360);

    maju();
    delay(1000);
    belok_kiri();
    maju();
    delay(1000);
    belok_kanan();
    maju();
    delay(1000);
    balik();
    maju();
    delay(1000);
    muter();
}

void maju() {
    myservo1.write(reangle);      // tell servo to go to position in variable 'pos'
    delay(15); 
    myservo2.write(angle);
    delay(15);                    // waits 15ms for the servo to reach the position
}

void belok_kiri(){
    myservo1.detach();            // roda/servo kiri mati
    delay(15);
    myservo2.write(angle);        // roda/servo kanan tetep maju
    delay(900);                   // goleki delay ben menggoke +-90 drajat
    myservo1.attach(13);          // nyambung servo kiri meneh
  }

void belok_kanan(){
    myservo2.detach();            // roda/servo kanan mati
    delay(15);
    myservo1.write(reangle);      // roda/servo kiri tetep maju
    delay(900);                   // goleki delay ben menggoke +-90 drajat
    myservo2.attach(10);          // nyambung servo kanan meneh
  }

void balik(){
    myservo1.detach();
    delay(15);
    myservo2.write(reangle);
    delay(780);
    myservo2.detach();
    myservo1.attach(13);
    delay(15);
    myservo1.write(reangle);
    delay(780);
    myservo2.attach(10);
  }

void muter(){
    myservo1.write(reangle);
    delay(15);
    myservo2.write(reangle);
    delay(9600);
  }
