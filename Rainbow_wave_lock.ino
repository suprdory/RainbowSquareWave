#include <Rainbowduino.h>
const byte dim_curve[] = {
  0,   1,   1,   2,   2,   2,   2,   2,   2,   3,   3,   3,   3,   3,   3,   3,
  3,   3,   3,   3,   3,   3,   3,   4,   4,   4,   4,   4,   4,   4,   4,   4,
  4,   4,   4,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   6,   6,   6,
  6,   6,   6,   6,   6,   7,   7,   7,   7,   7,   7,   7,   8,   8,   8,   8,
  8,   8,   9,   9,   9,   9,   9,   9,   10,  10,  10,  10,  10,  11,  11,  11,
  11,  11,  12,  12,  12,  12,  12,  13,  13,  13,  13,  14,  14,  14,  14,  15,
  15,  15,  16,  16,  16,  16,  17,  17,  17,  18,  18,  18,  19,  19,  19,  20,
  20,  20,  21,  21,  22,  22,  22,  23,  23,  24,  24,  25,  25,  25,  26,  26,
  27,  27,  28,  28,  29,  29,  30,  30,  31,  32,  32,  33,  33,  34,  35,  35,
  36,  36,  37,  38,  38,  39,  40,  40,  41,  42,  43,  43,  44,  45,  46,  47,
  48,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  62,
  63,  64,  65,  66,  68,  69,  70,  71,  73,  74,  75,  76,  78,  79,  81,  82,
  83,  85,  86,  88,  90,  91,  93,  94,  96,  98,  99,  101, 103, 105, 107, 109,
  110, 112, 114, 116, 118, 121, 123, 125, 127, 129, 132, 134, 136, 139, 141, 144,
  146, 149, 151, 154, 157, 159, 162, 165, 168, 171, 174, 177, 180, 183, 186, 190,
  193, 196, 200, 203, 207, 211, 214, 218, 222, 226, 230, 234, 238, 242, 248, 255,
};

unsigned char sinT[] = {128, 131, 134, 137, 140, 143, 146, 149,
                        152, 155, 158, 162, 165, 167, 170, 173,
                        176, 179, 182, 185, 188, 190, 193, 196,
                        198, 201, 203, 206, 208, 211, 213, 215,
                        218, 220, 222, 224, 226, 228, 230, 232,
                        234, 235, 237, 238, 240, 241, 243, 244,
                        245, 246, 248, 249, 250, 250, 251, 252,
                        253, 253, 254, 254, 254, 255, 255, 255,
                        255, 255, 255, 255, 254, 254, 254, 253,
                        253, 252, 251, 250, 250, 249, 248, 246,
                        245, 244, 243, 241, 240, 238, 237, 235,
                        234, 232, 230, 228, 226, 224, 222, 220,
                        218, 215, 213, 211, 208, 206, 203, 201,
                        198, 196, 193, 190, 188, 185, 182, 179,
                        176, 173, 170, 167, 165, 162, 158, 155,
                        152, 149, 146, 143, 140, 137, 134, 131,
                        128, 124, 121, 118, 115, 112, 109, 106,
                        103, 100, 97, 93, 90, 88, 85, 82,
                        79, 76, 73, 70, 67, 65, 62, 59,
                        57, 54, 52, 49, 47, 44, 42, 40,
                        37, 35, 33, 31, 29, 27, 25, 23,
                        21, 20, 18, 17, 15, 14, 12, 11,
                        10, 9, 7, 6, 5, 5, 4, 3,
                        2, 2, 1, 1, 1, 0, 0, 0,
                        0, 0, 0, 0, 1, 1, 1, 2,
                        2, 3, 4, 5, 5, 6, 7, 9,
                        10, 11, 12, 14, 15, 17, 18, 20,
                        21, 23, 25, 27, 29, 31, 33, 35,
                        37, 40, 42, 44, 47, 49, 52, 54,
                        57, 59, 62, 65, 67, 70, 73, 76,
                        79, 82, 85, 88, 90, 93, 97, 100,
                        103, 106, 109, 112, 115, 118, 121, 124,
                       };

void setup() {
  // put your setup code here, to run once:
  Rb.init();
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long t = 0;
  byte n = 0;
  byte br = 1;
  char k1, k2, k3;
  char m1, m2, m3 ;
  char w1 , w2 , w3;
  byte r1, r2, r3;
  int th1 = random(360), th2 = random(360), th3 = random(360);
  int xt = 0, yt = 0;
  //char dx = random(7) - 3, dy = random(7) - 3;
  char dx = 0, dy = 0; //translation speed
  char dth1 = 1, dth2 = 1, dth3 = 1;
  int rgb1[3];
  int rgb2[3];
  int rgb3[3];
  byte H1 = random(256), H2 = random(256), H3 = random(256);
  char dH1 = 1, dH2 = -1, dH3 = 0;
  //char txt[5] = {'A', 'r', 'w', 'y', 'n'};
  //char txt[5] = {'T', 'u', 'c', 'k', 'k'};
  unsigned char v1, v2, v3;
  float z, tz;
  char x0 = 7, y0 = 7;
  byte lock = 0,nlock=0,lockcd=0;



  while (1) {
    tz = 1;

    r1 = 30 + 26 * sin(t * 0.02745 * tz); //wave vector magnitude
    r2 = 30 + 26 * sin(t * 0.01945 * tz);
    r3 = 30 + 26 * sin(t * 0.04745 * tz);

    th1 = th1 + dth1;   // wavevector angle
    th2 = th2 + dth2;
    th3 = th3 + dth3;

    k1 = r1 * sin(th1 * 0.01745329);  //wave numbers
    m1 = r1 * cos(th1 * 0.01745329);
    k2 = r2 * sin(th2 * 0.01745329);
    m2 = r2 * cos(th2 * 0.01745329);
    k3 = r3 * sin(th3 * 0.01745329);
    m3 = r3 * cos(th3 * 0.01745329);

    w1 = 8; //wave angular frequency
    w2 = 9;
    w3 = 10;

    H1 = H1 + dH1;   //Hues
    H2 = H2 + dH2;
    H3 = H3 + dH3;

    //xt = xt + dx;  // radial wave centre
    //yt = yt + dy;

    z = pow(10, (.4 * sin(t * 0.003))+.2); //inverse magnification

    for (unsigned char x = 0; x < 8; x++) {
      for (unsigned char y = 0; y < 8; y++) {

        v1 = sinT[(byte)(k1 * (x + xt) * z + m1 * (y + yt) * z  + w1 * t * tz)]; // value or brightness
        v2 = sinT[(byte)(k2 * (x + xt) * z + m2 * (y + yt) * z  + w2 * t * tz)];
        v3 = 0;//sinT[(byte)(k3 * (x + xt) * z + m3 * (y + yt) * z  + w3 * t * tz)];

/*
      //radial wave test
        v1 = sinT[(byte)(30 * sqrt(sq(2 * x - x0) + sq(2 * y - y0)) * z  - wR * t)];
        v2 = 0;
        v3 = 0;

*/
        getRGB(map(H1, 0, 255, 0, 359), 255,  v1, rgb1); //convert HSV to rgb
        getRGB(map(H2, 0, 255, 0, 359), 255,  v2, rgb2);
        getRGB(map(H3, 0, 255, 0, 359), 255,  v3, rgb3);

        //set pixel color, mixing done in rgb space
        Rb.setPixelXY(x, y, min(rgb1[0] + rgb2[0] + rgb3[0], 255) , min(rgb1[1] + rgb2[1] + rgb3[1], 255) , min(rgb1[2] + rgb2[2] + rgb3[2], 255));
        //Rb.setPixelXY(x, y, min(rgb[0], 255) , min( rgb[1], 255) , min( rgb[2] , 255));

        //Rb.drawChar(txt[n % 5], 1, 0, 0x00FFFFFF);
      }
    }


    /* 
    // move centre of radial wave
    if (random(10 / tz) < 1) {
       x0 = x0 + random(3) - 1;
       if (x0 > 14) {
         x0 = 14;
       }
       if (x0 < 0) {
         x0 = 0;
       }
       y0 = y0 + random(3) - 1;
       if (y0 > 14) {
         y0 = 14;
       }
       if (y0 < 0) {
         y0 = 0;
       }
     }
    */


    if ((abs(th1 % 360) == 0 || abs(th1 % 360) == 180 ) && lock == 0 && random(10) < 1 && lockcd ==0) {
      lock = 1;
      dth1 = 0;
      dH1 = 0;
      nlock++;
    }
    if (lock == 1 && (abs(th2 % 360) == 90 || abs(th2 % 360) == 270)) {
      lock = 2;
      dth2 = 0;
      dH2 = 0;
    }
    if (lock == 2 && (abs(th3 % 360) == 90 || abs(th3 % 360) == 270 || abs(th3 % 360) == 0 || abs(th3 % 360) == 180)) {
      lock = 3;
      dth3 = 0;
      dH3 = 0;
    }

    if (lock == 3 && random(500) < 1) {
      lock = 0;
      lockcd=100;  //lock cooldown
    }

    if (lock < 3) {
      if (random(100 / tz) < 1) {
        dth3 = random(7) - 3;
      }
      if (random(100 / tz) < 1) {
        dH3 = random(5) - 2;
      }
    }

    if (lock < 2) {
      if (random(100 / tz) < 1) {
        dth2 = random(7) - 3;
      }
      if (random(100 / tz) < 1) {
        dH2 = random(9) - 4;
      }
    }

    if (lock < 1) {
      if (random(100 / tz) < 1) {
        dth1 = random(7) - 3;
      }
      if (random(100 / tz) < 1) {
        dH1 = random(9) - 4;
      }
    }

    t++;
    if (lockcd >0){
      lockcd--;
    }
    

    //delay(10);
    Serial.print(abs(th1 % 360));
    Serial.print("  ");
    Serial.print(abs(th2 % 360));
    Serial.print("  ");
    Serial.print(abs(th3 % 360));
    Serial.print("  ");
    Serial.print(lock);
    Serial.print("  ");
    Serial.println(nlock);
  }
}

void getRGB(int hue, int sat, int val, int colors[3]) {
  /* convert hue, saturation and brightness ( HSB/HSV ) to RGB
     The dim_curve is used only on brightness/value and on saturation (inverted).
     This looks the most natural.
  */

  val = dim_curve[val];
  sat = 255 - dim_curve[255 - sat];

  int r;
  int g;
  int b;
  int base;

  if (sat == 0) { // Acromatic color (gray). Hue doesn't mind.
    colors[0] = val;
    colors[1] = val;
    colors[2] = val;
  } else  {

    base = ((255 - sat) * val) >> 8;

    switch (hue / 60) {
      case 0:
        r = val;
        g = (((val - base) * hue) / 60) + base;
        b = base;
        break;

      case 1:
        r = (((val - base) * (60 - (hue % 60))) / 60) + base;
        g = val;
        b = base;
        break;

      case 2:
        r = base;
        g = val;
        b = (((val - base) * (hue % 60)) / 60) + base;
        break;

      case 3:
        r = base;
        g = (((val - base) * (60 - (hue % 60))) / 60) + base;
        b = val;
        break;

      case 4:
        r = (((val - base) * (hue % 60)) / 60) + base;
        g = base;
        b = val;
        break;

      case 5:
        r = val;
        g = base;
        b = (((val - base) * (60 - (hue % 60))) / 60) + base;
        break;
    }

    colors[0] = r;
    colors[1] = g;
    colors[2] = b;
  }
}

float mapF(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
