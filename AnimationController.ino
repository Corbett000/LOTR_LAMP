#include <Adafruit_NeoPixel.h>

class AnimationController {
  private:
    uint8_t red = 255;
    uint8_t green = 85;
    uint8_t blue = 0;
    float brightness = 1.0f; // Max brightness level
    Adafruit_NeoPixel* strip;
  public:
    AnimationController() {
      Serial.print("Setting up led strip\n");
      Serial.flush();

      strip = new Adafruit_NeoPixel(NEO_COUNT, PIN, NEO_GRB + NEO_KHZ800);
      if (brightness > 1.0f) brightness = 1.0f;
      if (brightness < 0.0f) brightness = 0.0f;
      
      strip->begin();
      strip->show(); // Initialize all pixels to 'off'
      led_snake();
    }
    // size is the number of neopixels in the snake
    // fade_size is the number of neopixels in the front and back of snake to blend
    void led_snake(int size = 8, int fade_size = 16, int speed_delay = 50) {
      uint16_t neo_count = strip->numPixels();

      // Trim size and fade_size if too large for given strip
      if (size >= neo_count) size = neo_count;
      if (fade_size * 2 + size >= neo_count) fade_size = (neo_count - size) / 2;

      for(int i=0; i < neo_count; i++) {
        // Fade out
        for (int j = 0; j < fade_size; j++) {
          double alpha = pow((double)(j + 1) / (double)(fade_size + 1), 3) * brightness;
          uint32_t fade_color = strip->Color(red * alpha, green * alpha, blue * alpha);
          strip->setPixelColor((i + j) % neo_count, fade_color);
        }
        // Full color
        for (int j = 0; j < size; j++) {
          uint32_t full_color = strip->Color(red * brightness, green * brightness, blue * brightness);
          strip->setPixelColor((i + j + fade_size) % neo_count, full_color);
        }
        // Fade in
        for (int j = 0; j < fade_size; j++) {
          double alpha = pow((double)(fade_size - j)  / (double)(fade_size + 1), 3) * brightness;
          uint32_t fade_color = strip->Color(red * alpha, green * alpha, blue * alpha);
          strip->setPixelColor((i + j + fade_size + size) % neo_count, fade_color);
        }
        strip->show();
        strip->clear();
        delay(speed_delay);
      }
    }

    void fade_in_out_animation(int speed_delay = 25) {
      for (uint8_t i = 0; i < 255; i++) {
        double cur_sine = (double) strip->sine8(i);
        double alpha = cur_sine / 255 * brightness;
        uint32_t fade_color = strip->Color(red * alpha, green * alpha, blue * alpha);
        strip->fill(fade_color, 0);
        strip->show();
        delay(speed_delay);
      }
      strip->clear();
    }


    void ring_on(int speed_delay = 30) {
      uint32_t neo_color = strip->Color(red * brightness, green * brightness, blue * brightness);
      for(int i = 0; i < strip->numPixels(); i++) {
        strip->setPixelColor(i, neo_color);
        strip->show();
        delay(speed_delay);
      }
    }

    void ring_off(int speed_delay = 30) {
      uint32_t neo_color = strip->Color(0, 0, 0); // No light/turn off
      for(int i = 0; i < strip->numPixels(); i++) {
        strip->setPixelColor(i, neo_color);
        strip->show();
        delay(speed_delay);
      }
    }

    void default_animation() {
      Serial.print("Starting default animation!\n");
      Serial.flush();
      strip->clear();

      led_snake();
      led_snake();
      
      ring_on();
      ring_off();
      ring_on();
      ring_off();
      ring_on();
        
      delay(10000); // Wait 10 seconds
    }
};
