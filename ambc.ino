#include "U8glib.h" 
#include "stdlib.h"


int AnalogPins[5]={A1,A2,A3,A4,A5};
int pinCountA=5;
int DigitalPins[5]={12,11,10,9,8};
int pinCountD=5;
int OK=0;
int linha = 0;
 
float H1= 0;
float H2= 0;float H3=0;float H4=0;float H5=0;
float H6=0;float H7=0;float H8=0;float H9=0;float H10=0;
float H11=0;float H12=0;float H13=0;float H14=0;float H15=0;
float H16=0;float H17=0;float H18=0;float H19=0;float H20=0;
float H21=0;float H22=0;float H23=0;float H24=0;float H25=0;
float tempo=0;

float H1check= 0;
float H2check= 0;float H3check=0;float H4check=0;float H5check=0;
float H6check=0;float H7check=0;float H8check=0;float H9check=0;float H10check=0;
float H11check=0;float H12check=0;float H13check=0;float H14check=0;float H15check=0;
float H16check=0;float H17check=0;float H18check=0;float H19check=0;float H20check=0;
float H21check=0;float H22check=0;float H23check=0;float H24check=0;float H25check=0;

// A linha abaixo define as ligacoes e deve ser ajustada conforme o display utilizado. 
U8GLIB_ST7920_128X64_1X u8g(6, 5, 4 ,7); //Enable, RW, RS, RESET  

int display = 1;  




void setup() {
  if ( u8g.getMode() == U8G_MODE_R3G3B2 )   
   u8g.setColorIndex(255);   // white            //display
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) //display
   u8g.setColorIndex(1);     // max intensity    //display
  else if ( u8g.getMode() == U8G_MODE_BW )       //display
   u8g.setColorIndex(1);     // pixel on         //display


   Serial.begin(9600);
  for (int thisPin=0; thisPin<pinCountA; thisPin++) /*declarando saída de dados*/ 
  {
    pinMode(DigitalPins[thisPin], OUTPUT);
  }
   for (int thisPin=0; thisPin<pinCountD; thisPin++) /*declarando entrada de dados*/  
   {
    pinMode(AnalogPins[thisPin], INPUT);
  }
  for (int thisPin=0; thisPin<pinCountA; thisPin++) {
    digitalWrite(DigitalPins[thisPin], HIGH);
    for (int thisPin2=0; thisPin2<pinCountD; thisPin2++) {
      float compare = analogRead(AnalogPins[thisPin2]) * (5.0 / 1023.0);
      if (compare > 0.4 ){
        delay(200);
        float compare2 = analogRead(AnalogPins[thisPin2]) * (5.0 / 1023.0);
        delay(200);
        if (compare2 > 0.4 ) {
         delay(200);
        float compare3 = analogRead(AnalogPins[thisPin2]) * (5.0 / 1023.0);
        delay(200);
        if (compare3 > 0.4 ) {
        delay(200);
          float compare4 = analogRead(AnalogPins[thisPin2]) * (5.0 / 1023.0);

        if (compare4 > 0.4 ) {
          
        
        if (thisPin2==0) {
        linha = 1;
        }

        if (thisPin2==1) {
        linha = 2;
        }

        if (thisPin2==2) {
        linha = 3;
        }

        if (thisPin2==3) {
        linha = 4;
        }

        if (thisPin2==4) {
        linha = 5;
        }

        Serial.println("erro, linha:");
        Serial.print(linha);
        
        u8g.firstPage();
        do
        {
        u8g_prepare();
        u8g.setFont(u8g_font_robot_de_niro);
        u8g.setPrintPos(4, 18);
        u8g.print("Erro linha:");
        u8g.setPrintPos(50, 18);
        u8g.print(linha);
        delay(2000);
        }
        while ( u8g.nextPage() );
        break;
      }
      }
      }
      }
    }
    digitalWrite(DigitalPins[thisPin], LOW);
}
  Serial.println("OK se não houver erro");
}




  void atualiza() // atualização info display
{
  u8g.setFont(u8g_font_robot_de_niro);
  u8g.drawLine(1, 0, 1, 64); u8g.drawLine(26, 0, 26, 64); u8g.drawLine(51, 0, 51, 64);u8g.drawLine(76, 0, 76, 64); u8g.drawLine(1, 7, 126, 7); //linhas
  u8g.drawLine(101, 0, 101, 64); u8g.drawLine(126, 0, 126, 64); u8g.drawLine(151, 0, 151, 64); u8g.drawLine(101, 57, 126, 57);                 //linhas
  u8g.drawStr(9, 9, "1-5"); u8g.drawStr(32, 9, "6-10"); u8g.drawStr(55, 9, "11-15"); u8g.drawStr(80, 9, "16-20"); u8g.drawStr(105, 9, "21-25");//id hastes
  u8g.setPrintPos(4, 18);
  u8g.print(H1);
  u8g.setPrintPos(29, 18);
  u8g.print(H6);
  u8g.setPrintPos(54, 18);
  u8g.print(H11);
  u8g.setPrintPos(79, 18);
  u8g.print(H16);
  u8g.setPrintPos(104, 18);
  u8g.print(H21);
  u8g.setPrintPos(4, 28);
  u8g.print(H2);
  u8g.setPrintPos(29, 28);
  u8g.print(H7);
  u8g.setPrintPos(54, 28);
  u8g.print(H12);
  u8g.setPrintPos(79, 28);
  u8g.print(H17);
  u8g.setPrintPos(104, 28);
  u8g.print(H22);
  u8g.setPrintPos(4, 38);
  u8g.print(H3);
  u8g.setPrintPos(29, 38);
  u8g.print(H8);
  u8g.setPrintPos(54, 38);
  u8g.print(H13);
  u8g.setPrintPos(79, 38);
  u8g.print(H18);
  u8g.setPrintPos(104, 38);
  u8g.print(H23);
  u8g.setPrintPos(4, 48);
  u8g.print(H4);
  u8g.setPrintPos(29, 48);
  u8g.print(H9);
  u8g.setPrintPos(54, 48);
  u8g.print(H14);
  u8g.setPrintPos(79, 48);
  u8g.print(H19);
  u8g.setPrintPos(104, 48);
  u8g.print(H24);
  u8g.setPrintPos(4, 58);
  u8g.print(H5);
  u8g.setPrintPos(29, 58);
  u8g.print(H10);
  u8g.setPrintPos(54, 58);
  u8g.print(H15);
  u8g.setPrintPos(79, 58);
  u8g.print(H20);
  u8g.setPrintPos(104, 58);
  u8g.print(H25);
  tempo= (float) millis()/ (float) 60000;
  u8g.setPrintPos(105, 66);
  u8g.print(tempo);
}


void linhaA1() {
  for (int thisPin2=0; thisPin2<pinCountD; thisPin2++) {
    float compare1 = analogRead(AnalogPins[thisPin2]) * (5.0 / 1023.0);
    if (compare1 > 0.3) {
      if (thisPin2==0 && H1check==0) {
        H1= (float) millis()/ (float) 60000;
        H1check=H1;
      }
      if (thisPin2==1 && H2check==0) {
        H2= (float) millis()/ (float) 60000;
        H2check=H2;
    }
    if (thisPin2==2 && H3check==0) {
        H3= (float) millis()/ (float) 60000;
        H3check=H3;
    }
    if (thisPin2==3 & H4check==0) {
        H4= (float) millis()/ (float) 60000;
        H4check=H4;
    }
    if (thisPin2==4 && H5check==0) {
        H5= (float) millis()/ (float) 60000;
        H5check=H5;
    }
  }
  }
}

void linhaA2() {
  for (int thisPin2=0; thisPin2<pinCountD; thisPin2++) {
    float compare2 = analogRead(AnalogPins[thisPin2]) * (5.0 / 1023.0);
    if (compare2 > 0.3) {
      if (thisPin2==0 && H6check==0) {
        H6= (float) millis()/ (float) 60000;
        H6check=H6;
      }
      if (thisPin2==1 && H7check==0) {
        H7= (float) millis()/ (float) 60000;
        H7check=H7;
    }
    if (thisPin2==2 && H8check==0) {
        H8= (float) millis()/ (float) 60000;
        H8check=H8;
    }
    if (thisPin2==3 && H9check==0) {
        H9= (float) millis()/ (float) 60000;
        H9check=H9;
    }
    if (thisPin2==4 && H10check==0) {
        H10= (float) millis()/ (float) 60000;
        H10check=H10;
    }
  }
  }
}

void linhaA3() {
  for (int thisPin2=0; thisPin2<pinCountD; thisPin2++) {
    float compare3 = analogRead(AnalogPins[thisPin2]) * (5.0 / 1023.0);
    if (compare3 > 0.3) {
      if (thisPin2==0 && H11check==0) {
        H11= (float) millis()/ (float) 60000;
        H11check=H11;
      }
      if (thisPin2==1 && H12check==0) {
        H12= (float) millis()/ (float) 60000;
        H12check=H12;
    }
    if (thisPin2==2 && H13check==0) {
        H13= (float) millis()/ (float) 60000;
        H13check=H13;
    }
    if (thisPin2==3 && H14check==0) {
        H14= (float) millis()/ (float) 60000;
        H14check=H14;
    }
    if (thisPin2==4 && H15check==0) {
        H15= (float) millis()/ (float) 60000;
        H15check=H15;
    }
  }
  }
}


void linhaA4() {
  for (int thisPin2=0; thisPin2<pinCountD; thisPin2++) {
    float compare4 = analogRead(AnalogPins[thisPin2]) * (5.0 / 1023.0);
    if (compare4 > 0.3) {
      if (thisPin2==0 && H16check==0) {
        H16= (float) millis()/ (float) 60000;
        H16check=H16;
      }
      if (thisPin2==1 && H17check==0) {
        H17= (float) millis()/ (float) 60000;
        H17check=H17;
    }
    if (thisPin2==2 && H18check==0) {
        H18= (float) millis()/ (float) 60000;
        H18check=H18;
    }
    if (thisPin2==3 && H19check==0) {
        H19= (float) millis()/ (float) 60000;
        H19check=H19;
    }
    if (thisPin2==4 && H20check==0) {
        H20= (float) millis()/ (float) 60000;
        H20check=H20;
    }
  }
  }
}

void linhaA5() {
  for (int thisPin2=0; thisPin2<pinCountD; thisPin2++) {
  float compare5 = analogRead(AnalogPins[thisPin2]) * (5.0 / 1023.0);
    if (compare5 > 0.3) {
      if (thisPin2==0 && H21check==0) {
        H21= (float) millis()/ (float) 60000;
        H21check=H21;
      }
      if (thisPin2==1 && H22check==0) {
        H22= (float) millis()/ (float) 60000;
        H22check=H22;
    }
    if (thisPin2==2 && H23check==0) {
        H23= (float) millis()/ (float) 60000;
        H23check=H23;
    }
    if (thisPin2==3 & H24check==0) {
        H24= (float) millis()/ (float) 60000;
        H24check=H24;
    }
    if (thisPin2==4 && H25check==0) {
        H25= (float) millis()/ (float) 60000;
        H25check=H25;
    }
  }
  }
}

void loop() {
  u8g.firstPage();
  do {
    draw();
  } while ( u8g.nextPage() ); // display 

  for (int thisPin=0; thisPin<pinCountA; thisPin++) {
    digitalWrite(DigitalPins[thisPin], HIGH);
    if (thisPin==0) {
      linhaA1();   
    }
    if (thisPin==1) {
      linhaA2();
    }
    if (thisPin==2) {
      linhaA3();
    }
    if (thisPin==3) {
      linhaA4();
    }
    if (thisPin==4) {
      linhaA5();
    }
    digitalWrite(DigitalPins[thisPin], LOW);
    u8g.firstPage();
  do {
    draw();
  } while ( u8g.nextPage() ); // display 
  }
  
}



void u8g_prepare() //display
{
  u8g.setFont(u8g_font_6x10);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop();
}



void draw() //rotina Desenho display
{
  u8g_prepare();
  atualiza();
}
