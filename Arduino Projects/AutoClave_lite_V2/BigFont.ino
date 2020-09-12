void bigFont_init() {
  for (nb = 0; nb < 8; nb++ ) {                 // create 8 custom characters
    for (bc = 0; bc < 8; bc++) bb[bc] = pgm_read_byte( &custom[nb][bc] );
    lcd.createChar ( nb + 1, bb );
  }
}

// ********************************************************************************** //
//                                      SUBROUTINES
// ********************************************************************************** //
// writeBigChar: writes big character 'ch' to column x, row y; returns number of columns used by 'ch'
int writeBigChar(char ch, byte x, byte y) {
  if (ch < ' ' || ch > '_') return 0;               // If outside table range, do nothing
  nb = 0;                                           // character byte counter
  for (bc = 0; bc < 8; bc++) {
    bb[bc] = pgm_read_byte( &bigChars[ch - ' '][bc] ); // read 8 bytes from PROGMEM
    if (bb[bc] != 0) nb++;
  }

  bc = 0;
  for (row = y; row < y + 2; row++) {
    for (col = x; col < x + nb / 2; col++ ) {
      lcd.setCursor(col, row);                      // move to position
       lcd.write(bb[bc++]);                          // write byte and increment to next
    }
  }
  return nb / 2 - 1;                                  // returns number of columns used by char
}

// writeBigString: writes out each letter of string
void writeBigString(char *str, byte x, byte y) {
  char c;
  while ((c = *str++))
    x += writeBigChar(c, x, y) + 1;
}

void writeBigByteNum(byte num, byte digits, byte x, byte y) {
  bool leading = false;
  if (digits > 3)digits = 3;
  char numString[digits];
  byte index = digits - 1;
  while (index)
  {
    numString[index] = num % 10;
    num /= 10;
    index--;
  }
  numString[0] = num % 10;
  for (int i = 0; i < digits; i++)
  {
    if (numString[i] == 0 && !leading && i < digits - 1)
      clearZeros((i * 3) + x);
    else
    {
      writeBigChar(48 + numString[i], x + (i * 3) , y);
      leading = true;
    }
  }
}


void clearZeros(byte x) {
  lcd.setCursor(x, 0);
  lcd.print("   ");
  lcd.setCursor(x, 1);
  lcd.print("   ");
}
