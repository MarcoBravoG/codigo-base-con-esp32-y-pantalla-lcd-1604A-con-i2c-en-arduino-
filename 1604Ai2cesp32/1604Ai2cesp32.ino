#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Dirección I2C de la pantalla (puede ser 0x27 o 0x3F)
#define I2C_ADDR 0x27  

// Inicialización de la pantalla con dirección I2C, 16 columnas y 4 filas
LiquidCrystal_I2C lcd(I2C_ADDR, 16, 4);

void setup() {
  // Configurar comunicación I2C con los pines de tu ESP32 de 30 pines
  Wire.begin(21, 22);  // SDA en GPIO 21, SCL en GPIO 22

  lcd.init();          // Inicializar la pantalla
  lcd.backlight();     // Encender la luz de fondo

  // Mensaje de bienvenida
  lcd.setCursor(0, 0);
  lcd.print("ESP32 30 pines");
  lcd.setCursor(0, 1);
  lcd.print("LCD 1604A I2C");
  
  delay(3000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Contador: ");

  for (int i = 0; i <= 100; i++) {
    lcd.setCursor(10, 0);  // Mostrar el número después de 'Contador:'
    lcd.print(i);
    lcd.print("   ");  // Borrar dígitos anteriores
    delay(500);
  }
}
