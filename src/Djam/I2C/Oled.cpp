#include <Djam/I2C/Oled.h>

void Djam::I2C::Oled::setup(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.setTextSize(2);
  display.setTextColor(WHITE);

  display.clearDisplay();
  display.display();
}

void Djam::I2C::Oled::addPage(String name){
  Page newPage;
  newPage.name = name;
  newPage.value = "";
  pages.push_back(newPage);
}

void Djam::I2C::Oled::setPageValue(String pageName, String pageValue){
  for(Page page : pages){
    if(page.name == pageName){
      page.value = pageValue;
    }
  }
}

void Djam::I2C::Oled::printNextPage(){
  Page currentPage = pages.at(currentPageIndex);
  printKeyValue(currentPage.name, currentPage.value);
  Serial.println("Printing " + currentPage.name + " - " + String(currentPage.value));
  currentPageIndex++;
  if(currentPageIndex >= pages.size()){
    currentPageIndex = 0;
  }
}

void Djam::I2C::Oled::printMessage(String message){
  display.clearDisplay();
  display.setCursor(0,0);
  display.println(message);
  display.display();
}

void Djam::I2C::Oled::printKeyValue(String key, String value){
  display.clearDisplay();

  display.setCursor(0, 0);
  display.print(key);

  display.setCursor(0, 32);
  display.print(value);

  display.display();
}
