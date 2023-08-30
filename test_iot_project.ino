#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const int ROW_NUM    = 4; // four rows
const int COLUMN_NUM = 4; // four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6};      // connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; // connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

int cursorColumn = 0;
 

void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();
}

void loop()
{

  char key = keypad.getKey();

  if (key) {
    lcd.setCursor(cursorColumn, 0); // move cursor to   (cursorColumn, 0)
    lcd.print(key);                 // print key at (cursorColumn, 0)

    cursorColumn++;                 // move cursor to next position
    if(cursorColumn == 16) {        // if reaching limit, clear LCD
      lcd.clear();
      cursorColumn = 0;
    }
  }

  // lcd.clear();                 // clear display
  // lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  // lcd.print("Arduino");        // print message at (0, 0)
  // lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  // lcd.print("GetStarted.com"); // print message at (2, 1)
  // delay(2000);                 // display the above for two seconds

  // lcd.clear();                  // clear display
  // lcd.setCursor(3, 0);          // move cursor to   (3, 0)
  // lcd.print("DIYables");        // print message at (3, 0)
  // lcd.setCursor(0, 1);          // move cursor to   (0, 1)
  // lcd.print("www.diyables.io"); // print message at (0, 1)
  // delay(2000);                  // display the above for two seconds
}