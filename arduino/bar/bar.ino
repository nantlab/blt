#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SPI.h>
#include <OSCBundle.h>
#include <OSCBoards.h>

EthernetUDP Udp;
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEC
};

IPAddress ip(192, 168, 178, 10);
const unsigned int inPort = 8010;


#define UPPER_ROW_PIN 11
#define MIDDLE_ROW_PIN 12
#define LOWER_ROW_PIN 13
#define WIDTH 12
#define HEIGHT 3
#define UPPER_ROW_MODULES 11
#define MIDDLE_ROW_MODULES 12
#define LOWER_ROW_MODULES 11
#define PIXELS_PER_MODULE 6
#define CHANNELS_PER_PIXEL 3

Adafruit_NeoPixel upperRow = Adafruit_NeoPixel(UPPER_ROW_MODULES * PIXELS_PER_MODULE, UPPER_ROW_PIN, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel middleRow = Adafruit_NeoPixel(MIDDLE_ROW_MODULES * PIXELS_PER_MODULE, MIDDLE_ROW_PIN, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel lowerRow = Adafruit_NeoPixel(LOWER_ROW_MODULES * PIXELS_PER_MODULE, LOWER_ROW_PIN, NEO_RGB + NEO_KHZ800);

bool isValidRGBColor(int red, int green, int blue) {
  if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
    Serial.print("invalid color: (");
    Serial.print(red);
    Serial.print(",");
    Serial.print(green);
    Serial.print(",");
    Serial.print(blue);
    Serial.println(")");
    return false;
  }
  return true;
}

void setModule(int column, int row, int red, int green, int blue) {
  switch (row) {
    case 0: {
        for (int i = 0; i < PIXELS_PER_MODULE; i++) {
          upperRow.setPixelColor((UPPER_ROW_MODULES-1-column) * PIXELS_PER_MODULE + i, upperRow.Color(red, green, blue));
        }
        upperRow.show();
        break;
      }
    case 1: {
        for (int i = 0; i < PIXELS_PER_MODULE; i++) {
          middleRow.setPixelColor((MIDDLE_ROW_MODULES-1-column) * PIXELS_PER_MODULE + i, middleRow.Color(red, green, blue));
        }
        middleRow.show();
        break;
      }
    case 2: {
        if (column != 0) {
          column--;
          for (int i = 0; i < PIXELS_PER_MODULE; i++) {
            lowerRow.setPixelColor((LOWER_ROW_MODULES-1-column) * PIXELS_PER_MODULE + i, lowerRow.Color(red, green, blue));
          }
          lowerRow.show();
        }
        break;
      }
  }
}
void routeAll(OSCMessage &msg, int addrOffset) {
  int red = -1;
  int green = -1;
  int blue = -1;
  if (msg.isBlob(0)) {
    uint8_t blob[WIDTH * HEIGHT * CHANNELS_PER_PIXEL];
    msg.getBlob(0, blob, WIDTH * HEIGHT * CHANNELS_PER_PIXEL);
    for (int row = 0; row < HEIGHT; row++) {
      for (int column = 0; column < WIDTH; column++) {
        int index = (row * WIDTH + column) * CHANNELS_PER_PIXEL;
        setModule(column, row, blob[index], blob[index + 1], blob[index + 2]);
      }
    }
  } else {
    if (msg.isInt(0)) {
      red = msg.getInt(0);
    }
    if (msg.isInt(1)) {
      green = msg.getInt(1);
    }
    if (msg.isInt(2)) {
      blue = msg.getInt(2);
    }
    if (red != -1 && green != -1 && blue != -1) {
      for (int row = 0; row < HEIGHT; row++) {
        for (int column = 0; column < WIDTH; column++) {
          setModule(column, row, red, green, blue);
        }
      }
    } else {
      Serial.println("routeAll: got invalid color");
    }
  }

}
void routeRow(OSCMessage &msg, int addrOffset) {
  int row = -1;
  if (msg.isInt(0)) {
    row = msg.getInt(0);
  }
  int red = -1;
  int green = -1;
  int blue = -1;

  if (msg.isInt(1)) {
    red = msg.getInt(1);
  }
  if (msg.isInt(2)) {
    green = msg.getInt(2);
  }
  if (msg.isInt(3)) {
    blue = msg.getInt(3);
  }

  if (row != -1 && isValidRGBColor(red, green, blue)) {
    for (int column = 0; column < WIDTH; column++) {
      setModule(column, row, red, green, blue);
    }
  }
}
void routeColumn(OSCMessage &msg, int addrOffset) {
  int column = -1;
  int red = -1;
  int green = -1;
  int blue = -1;

  if (msg.isInt(0)) {
    column = msg.getInt(0);
  }
  if (msg.isInt(1)) {
    red = msg.getInt(1);
  }
  if (msg.isInt(2)) {
    green = msg.getInt(2);
  }
  if (msg.isInt(3)) {
    blue = msg.getInt(3);
  }

  if (column != -1 && isValidRGBColor(red, green, blue)) {
    for (int row = 0; row < HEIGHT; row++) {
      setModule(column, row, red, green, blue);
    }
  }
}

void routePixel(OSCMessage &msg, int addrOffset) {
  int column = -1;
  int row = -1;
  int red = -1;
  int green = -1;
  int blue = -1;

  if (msg.isInt(0)) {
    column = msg.getInt(0);
  }
  if (msg.isInt(1)) {
    row = msg.getInt(1);
  }
  if (msg.isInt(2)) {
    red = msg.getInt(2);
  }
  if (msg.isInt(3)) {
    green = msg.getInt(3);
  }
  if (msg.isInt(4)) {
    blue = msg.getInt(4);
  }
  if (column != -1 && row != -1 && isValidRGBColor(red, green, blue)) {
    setModule(column, row, red, green, blue);
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("successfully set up serial");

  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  Ethernet.begin(mac, ip);
  Udp.begin(inPort);

  Serial.println("successfully set up ethernet");

  upperRow.begin();
  middleRow.begin();
  lowerRow.begin();
  upperRow.show(); // Initialize all pixels to 'off'
  middleRow.show(); // Initialize all pixels to 'off'
  lowerRow.show(); // Initialize all pixels to 'off'

  Serial.println("successfully set up neopixels");
  Serial.print("pixels per module: ");
  Serial.println(PIXELS_PER_MODULE);

  Serial.print("number of modules upper row: ");
  Serial.println(UPPER_ROW_MODULES);
  Serial.print("number of modules middle row: ");
  Serial.println(MIDDLE_ROW_MODULES);
  Serial.print("number of modules lower row: ");
  Serial.println(LOWER_ROW_MODULES);

}

void loop() {
  OSCBundle bundleIN;
  int size;

  if ( (size = Udp.parsePacket()) > 0) {
    while (size--) {
      bundleIN.fill(Udp.read());
    }
    if (!bundleIN.hasError()) {
      bundleIN.route("/all", routeAll);
      bundleIN.route("/column", routeColumn);
      bundleIN.route("/row", routeRow);
      bundleIN.route("/pixel", routePixel);
    }
  }
}

