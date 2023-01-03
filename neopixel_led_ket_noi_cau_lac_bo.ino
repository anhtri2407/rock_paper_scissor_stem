#include <Adafruit_NeoPixel.h>
#define PIN 6
#define LED_COUNT 256
#define ROW 4
#define COL 16

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

short picture[ROW][COL][3] = {
  {{77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {70, 70, 70}, {255, 194, 14}, {255, 194, 14}, {70, 70, 70}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}},
  {{77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {255, 163, 177}, {237, 28, 36}, {255, 194, 14}, {255, 163, 177}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}},
  {{77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {255, 194, 14}, {255, 194, 14}, {255, 194, 14}, {255, 194, 14}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}},
  {{77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {255, 194, 14}, {255, 194, 14}, {255, 194, 14}, {156, 90, 60}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}, {77, 109, 243}}
};

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  renderPicture();
}

// void draw(unsigned int )

void mapLedxy(int x, int y, uint32_t color) {
  int pixelPos;
  if (x % 2 == 0)
    pixelPos = y + x * 16;
  else
    pixelPos = 15 - y + x * 16;
  strip.setPixelColor(pixelPos, color);
}

void renderPicture() {
  for (int i = 0; i < ROW; i++)
    for (int j = 0; j < COL; j++) {
        mapLedxy(i, j, strip.Color(picture[i][j][0], picture[i][j][1], picture[i][j][2]));
        strip.show();
      }
}