void submenu_about() {
  //Fifth page of the menu about => (about auther in 4 pages)
  if (submenu == menu_about_index)
  {
    if (counter == 0) //when Line 1 selected
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Line 1");
      lcd.setCursor(0, 1);
      lcd.print("  Line 2");
      page = 1;
      pushed = 0;
    }

    if (counter == 1) //when Line 2 selected
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Line 1");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("Line 2");
      page = 2;
      pushed = 0;
    }

    if (counter == 2) //when Line 3 selected
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Line 3");
      lcd.setCursor(0, 1);
      lcd.print("  Line 4");
      page = 3;
      pushed = 0;
    }

    if (counter == 3) //when Line 4 selected
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Line 3");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("Line 4");
      page = 4;
      pushed = 0;
    }
  }//submenu = 4;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void buttons_action_about() {

  if (submenu == menu_about_index)
  {
    submenu = menu_main_index;
    counter = menu_about_index - 1;
    pushed = 1;
    Ready = 0;


    if (up.isPressed() && down.isPressed())
    {
//      EasyBuzzer.beep(
//        frequency,  // Frequency in Hertz(HZ).
//        4  // The number of beeps.
//      );
      dev_mode = true;
      lcd.clear();
      writeBigString("DEV_ON", 1, 0);
      delay(1000);
    }

  }//end of submenu 4
}
