sbit LCD_RS at RD4_bit;
sbit LCD_EN at RD5_bit;
sbit LCD_D4 at RD6_bit;
sbit LCD_D5 at RD7_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISD4_bit;
sbit LCD_EN_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD6_bit;
sbit LCD_D5_Direction at TRISD7_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;


 #define SET_BIT(dataa2, xy) dataa2[(xy)/8] |= (1<<((xy) % 8)) //set the bit in array
#define CLR_BIT(dataa2, xy) dataa2[(xy)/8] &=~(1<<((xy) % 8)) //clera the bit in array
#define GET_BIT(dataa2, xy) (dataa2[(xy)/8] & (1<<((xy) % 8))) //return 1 if bit in array is set.
#define greenled PORTB.F6
#define redled PORTB.F7

unsigned char you = 10;
unsigned char you1,you2,you3,you4;
unsigned char disp1[16];
unsigned char disp2[16];
unsigned char disp3[16];
unsigned char disp4[16];
unsigned short pencil2;
unsigned short recordd1, recordd2;
unsigned int recordd;
unsigned int nex[8];
 unsigned short pencil;
unsigned char setset = 40;
 unsigned char ccc, cccc, detect, detectcount, ccc1;
unsigned long cardnumber;
unsigned long cardnumberr, cardnumberrr;
unsigned char w1;
unsigned char ww,www,www2,wwww;
unsigned short cardnumber2[10];


char uart_rd = 0;
 #define get PORTB.F0
unsigned char _data1 = 49;
  unsigned char _data0 = 48;
  unsigned int count2;
unsigned char card[10];
unsigned char checkcard[10];

unsigned char rfidset = 20;
// unsigned char dataa[1300];
  unsigned char dataa2[150];
  unsigned char i,b,bb;
  unsigned int ii;
  unsigned int xy;
    unsigned int m, mm, mmm;
  unsigned char afterheader;
   unsigned char counttt = 0;
   unsigned char counttt2 = 0;
  bit onee   ;
  unsigned char valuee;
  unsigned int ppp =0;
  unsigned char value0, value1, was0, was1, record0, record1, ready;
  unsigned char count0, count1;

  unsigned char valbyte1, valbyte2, oldbyte, newbyte;
  unsigned char valueee1 = 1;
    unsigned char valueee0 = 0;
unsigned int posbyte, posbit;
unsigned char g,gg,ggg,gggg;
unsigned char cntt;



void clearvariable() {
disp1[0] = ' ';
disp1[1] = ' ';
disp1[2] = ' ';
disp1[3] = ' ';
disp1[4] = ' ';
disp1[5] = ' ';
disp1[6] = ' ';
disp1[7] = ' ';
disp1[8] = ' ';
disp1[9] = ' ';
disp1[10] = ' ';
disp1[11] = ' ';
disp1[12] = ' ';
disp1[13] = ' ';
disp1[14] = ' ';
disp1[15] = ' ';

disp2[0] = ' ';
disp2[1] = ' ';
disp2[2] = ' ';
disp2[3] = ' ';
disp2[4] = ' ';
disp2[5] = ' ';
disp2[6] = ' ';
disp2[7] = ' ';
disp2[8] = ' ';
disp2[9] = ' ';
disp2[10] = ' ';
disp2[11] = ' ';
disp2[12] = ' ';
disp2[13] = ' ';
disp2[14] = ' ';
disp2[15] = ' ';

disp3[0] = ' ';
disp3[1] = ' ';
disp3[2] = ' ';
disp3[3] = ' ';
disp3[4] = ' ';
disp3[5] = ' ';
disp3[6] = ' ';
disp3[7] = ' ';
disp3[8] = ' ';
disp3[9] = ' ';
disp3[10] = ' ';
disp3[11] = ' ';
disp3[12] = ' ';
disp3[13] = ' ';
disp3[14] = ' ';
disp3[15] = ' ';

disp4[0] = ' ';
disp4[1] = ' ';
disp4[2] = ' ';
disp4[3] = ' ';
disp4[4] = ' ';
disp4[5] = ' ';
disp4[6] = ' ';
disp4[7] = ' ';
disp4[8] = ' ';
disp4[9] = ' ';
disp4[10] = ' ';
disp4[11] = ' ';
disp4[12] = ' ';
disp4[13] = ' ';
disp4[14] = ' ';
disp4[15] = ' ';
}

unsigned char getbit(unsigned int pos) {
posbyte = pos / 8;
posbit = pos % 8;
valbyte1 = dataa2[posbyte];
valbyte2 = valbyte1 >> (posbit) & 1;
return valbyte2;
}

    void rfidcard() {
  value0 = 0;
  value1 = 0;
  was0 = 40;
  was1 = 40;
  ii = 0;
  ppp = 0 ;
counttt = 0;
counttt2 = 0;

       ii = 0;
        TMR0L = 106;
       T0CON.TMR0ON = 1;
       INTCON = 0xA0;
 delay_ms(500);
ppp = 0;
counttt = 0;
counttt2 = 0;

INTCON = 0x00;
 T0CON.TMR0ON = 0;
                  value0 = 0;
                  value1 = 0;
                  was0 = 40;
                  was1 = 40;
                  count2 = 0;




                           for(ii = 0; ii < 1198; ii++) {

     if (getbit(ii) == 0){
      value0++;
      if (value0 > 100) {
       value0 = 0;
       ii = 0;
       count2 = 0;
       break;
      }
      was0 = 20;
      if (was1 == 20) {
       if ((value1 < 8) && (value1 > 3)) {
   xy = count2;
      SET_BIT(dataa2, xy);
       count2++;

       value1 = 0;
       was1 = 40;
       }
       else if  ((value1 > 7) && (value1 < 13)) {
   xy = count2;
      SET_BIT(dataa2, xy);

       count2++;
   xy = count2;
      SET_BIT(dataa2, xy);

       count2++;
       value1 = 0;
       was1 = 40;
       }
      }
          }

     else if (getbit(ii) == 1) { //(dataa[ii] == 49){
value1++;
     if (value1 > 100) {
       value1 = 0;
       ii = 0;
       count2 = 0;
       break;
      }
      was1 = 20;

if (was0 == 20) {
       if ((value0 < 8) && (value0 > 3)) {
   xy = count2;
      CLR_BIT(dataa2, xy);

       count2++;
       was0 = 40;
       value0 = 0;
              }
       else if  ((value0 > 7) && (value0 < 13)) {
   xy = count2;
      CLR_BIT(dataa2, xy);

       count2++;
   xy = count2;
      CLR_BIT(dataa2, xy);
       count2++;
       value0 = 0;
       was0 = 40;
       }

      }
     }
     }


   was0 = 20; was1 = 40; afterheader = 40; m = 0; mm = 0; mmm = 0;
     for (ii = 0; ii <300; ii++) {
     if ((getbit(ii) == 1) && (was0 == 20) && (afterheader == 40)) {
      was1 = 20 ; was0 = 40;
     }
         else if ((getbit(ii) == 0) && (was1 == 20) && (afterheader == 40)) {
      was0 = 20; was1 =40; m++;
     }
         else if ((getbit(ii) == 1) && (was1 == 20) && (afterheader == 40)) {
      was1 = 20; was0 = 40; m = 0;
     }
              else if ((getbit(ii) == 0) && (was0 == 20) && (afterheader == 40)) {
      was0 = 20; was1 = 40; m = 0;
     }

     if (m == 9) {
      afterheader = 20;
      m = 0;
      mm = 0;
      continue;
     }

     if ((getbit(ii) == 1) && (mm == 0) && (afterheader == 20)) mm++;
     else if ((getbit(ii) == 0) && (mm == 1) && (afterheader == 20)) {
      mm = 0; mmm++  ; /* UART1_Write(_data1); */
         xy = mmm;
      SET_BIT(dataa2, xy);

     }
     else if ((getbit(ii) == 0) && (mm == 0) && (afterheader == 20)) mm++;
     else if ((getbit(ii) == 1) && (mm == 1) && (afterheader == 20)) {
      mm = 0; mmm++ ; /* UART1_Write(_data0); */
       xy = mmm;
      CLR_BIT(dataa2, xy);

     }


     }


     ii = 0   ;

       nex[0] = getbit(11) * 8 + getbit(12) * 4 +getbit(13) * 2 +getbit(14) * 1  ;
  nex[1] = getbit(16) * 8 + getbit(17) * 4 +getbit(18) * 2 +getbit(19) * 1  ;
  nex[2] = getbit(21) * 8 + getbit(22) * 4 +getbit(23) * 2 +getbit(24) * 1  ;
  nex[3] = getbit(26) * 8 + getbit(27) * 4 +getbit(28) * 2 +getbit(29) * 1  ;
  nex[4] = getbit(31) * 8 + getbit(32) * 4 +getbit(33) * 2 +getbit(34) * 1  ;
  nex[5] = getbit(36) * 8 + getbit(37) * 4 +getbit(38) * 2 +getbit(39) * 1  ;
  nex[6] = getbit(41) * 8 + getbit(42) * 4 +getbit(43) * 2 +getbit(44) * 1  ;
  nex[7] = getbit(46) * 8 + getbit(47) * 4 +getbit(48) * 2 +getbit(49) * 1  ;


cardnumber = (268435456*nex[0]) + (16777216*nex[1]) + (1048576*nex[2])+ (65536*nex[3]) + (4096*nex[4]) + (256*nex[5]) + (16*nex[6]) + (1*nex[7]);
  cardnumber2[0] = cardnumber / 1000000000;
  cardnumber = cardnumber %  1000000000;

  cardnumber2[1] = cardnumber / 100000000;
  cardnumber = cardnumber %  100000000;

cardnumber2[2] = cardnumber / 10000000;
  cardnumber = cardnumber %  10000000;

cardnumber2[3] = cardnumber / 1000000;
  cardnumber = cardnumber %  1000000;

cardnumber2[4] = cardnumber / 100000;
  cardnumber = cardnumber %  100000;

cardnumber2[5] = cardnumber / 10000;
  cardnumber = cardnumber %  10000;

cardnumber2[6] = cardnumber / 1000;
  cardnumber = cardnumber %  1000;

cardnumber2[7] = cardnumber / 100;
  cardnumber = cardnumber %  100;

cardnumber2[8] = cardnumber / 10;
  cardnumber2[9] = cardnumber %  10;

// for (ii = 0; ii < 10; ii++) {
 //    UART1_Write((cardnumber2[ii]+48));
 //    }

   for (ii = 0; ii < 10; ii++) {
    // UART1_Write(dataa2[ii]);
    card[ii] = cardnumber2[ii]+48;
     }

    }



void interrupt() {
        TMR0L = 106;
INTCON.T0IF = 0;

   if (get == 0) {
//      dataa[ppp] = 48;
      onee = 0;
       switch (counttt) {
  case 0:  dataa2[counttt2].F0 = onee;  break;
  case 1:   dataa2[counttt2].F1 = onee;  break;
  case 2: dataa2[counttt2].F2 = onee;  break;
    case 3: dataa2[counttt2].F3 = onee; break;
      case 4: dataa2[counttt2].F4 = onee;  break;
        case 5: dataa2[counttt2].F5 = onee;  break;
          case 6: dataa2[counttt2].F6 = onee;  break;
            case 7: dataa2[counttt2].F7 = onee; break;

}
      }
   else {
  //dataa[ppp] = 49;
 onee = 1;
     switch (counttt) {
  case 0:  dataa2[counttt2].F0 = onee;  break;
  case 1:   dataa2[counttt2].F1 = onee;  break;
  case 2: dataa2[counttt2].F2 = onee;  break;
    case 3: dataa2[counttt2].F3 = onee; break;
      case 4: dataa2[counttt2].F4 = onee;  break;
        case 5: dataa2[counttt2].F5 = onee;  break;
          case 6: dataa2[counttt2].F6 = onee;  break;
            case 7: dataa2[counttt2].F7 = onee; break;

}
   }
counttt = counttt + 1;
if (counttt > 7) {
 counttt2 = counttt2 + 1;
 counttt = 0;
}

ppp = ppp + 1   ;
     if (ppp > 1198) {
ppp = 0;
counttt = 0;
counttt2 = 0;
INTCON = 0x00;
T0CON.TMR0ON = 0;
}
}



void main() {
TRISC = 0x00;     // PORTC O/P
TRISC.F2 = 0;
TRISB = 1;
TRISB.F6 = 0;
TRISB.F7 = 0;

 Lcd_Init();                        // Initialize LCD
g = 20;

  PORTB = 0;
 value0 = 0;
  value1 = 0;
  was0 = 40;
  was1 = 40;
  ii = 0;
  ppp = 0 ;
counttt = 0;
counttt2 = 0;

PWM1_Init(125000);
PWM1_Start();
PWM1_Set_Duty(127);

UART1_Init(9600);               // Initialize UART module at 9600 bps

redled = 1;
  Delay_ms(1000);
  redled = 0;
  greenled = 1;
    delay_ms(1000);
    greenled = 0;
T0CON.T0CS=0;
T0CON.TMR0ON = 1;
T0CON.T08BIT = 1;
PORTB.F0 = 0;
          TMR0L = 106;
INTCON = 0xA0;




  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
  Lcd_Out(1,1,"RFID-BASED PATIENT");                 // Write text in first row

  Lcd_Out(2,1,"MANAGEMENT SYSTEM");                 // Write text in second row
  Delay_ms(3000);
  Lcd_Cmd(_LCD_CLEAR);               // Clear display



  Lcd_Out(1,4,"DESIGNED BY");                 // Write text in first row
  Lcd_Out(2,2,"Name");                 // Write text in second row

  Delay_ms(3000);
  Lcd_Cmd(_LCD_CLEAR);               // Clear display

  Lcd_Out(1,4,"SUPERVISED BY");                 // Write text in first row
  Lcd_Out(2,2,"DR. Name");                 // Write text in second row

  Delay_ms(3000);

  Lcd_Cmd(_LCD_CLEAR);               // Clear display

  Lcd_Out(1,1,"PLACE RFID CARD");                 // Write text in first row
  Lcd_Out(2,2,"ABOVE READER");                 // Write text in second row

  Delay_ms(1000);

     while(1) {
    if (UART1_Data_Ready()) {     // If data is received,
      uart_rd = UART1_Read();     // read the received data,

    if (uart_rd == 252) {   //send card number
             greenled = 1;
   rfidcard();
   delay_ms(1000);
   greenled = 0;
clearvariable();
      for (ii = 0; ii < 10; ii++) {
     UART1_Write(card[ii]);
     delay_ms(10);
//    card[ii] = dataa2[ii];
     }


              }

    else if (uart_rd == 250) {   //send card number
     you = 20;
     you1 = 0;
     }
   else if (uart_rd == 249) {   //send card number
     you = 10;
     you1 = 0;
         Lcd_Cmd(_LCD_CLEAR);               // Clear display
    Lcd_Out(1,1,"NAME:");
 //Lcd_Chr(1, 1, disp1[0]);
 for (i = 0; i < 14; i++) {
  Lcd_Chr_Cp(disp1[i]);
 }

     }


    else if (uart_rd == 248) {   //send card number
     you = 30;
     you2 = 0;
     }
    else if (uart_rd == 247) {   //send card number
     you = 10;
     you2 = 0;
        Lcd_Out(2,1,"JAJA NO: ");
 //Lcd_Chr(1, 1, disp1[0]);
 for (i = 0; i < 14; i++) {
  Lcd_Chr_Cp(disp2[i]);
 }

     }


    else if (uart_rd == 246) {   //send card number
     you = 40;
     you3 = 0;
     }

    else if (uart_rd == 245) {   //send card number
     you = 10;
     you3 = 0;
             Lcd_Out(3,1,"FAC: ");
 //Lcd_Chr(1, 1, disp1[0]);
 for (i = 0; i < 14; i++) {
  Lcd_Chr_Cp(disp3[i]);
 }

     }

    else if (uart_rd == 244) {   //send card number
     you = 50;
     you4 = 0;
     }

    else if (uart_rd == 243) {   //send card number
     you = 10;
     you4 = 0;

 Lcd_Out(4,1,"UG/PG:");
 //Lcd_Chr(1, 1, disp1[0]);
 for (i = 0; i < 14; i++) {
  Lcd_Chr_Cp(disp4[i]);
 }

     }

/*
    else if (uart_rd == 246) {   //send card number
     Lcd_Cmd(_LCD_CLEAR);               // Clear display

 Lcd_Out(1,1,"NAME:");
 //Lcd_Chr(1, 1, disp1[0]);
 for (i = 0; i < 14; i++) {
  Lcd_Chr_Cp(disp1[i]);
 }

 Lcd_Out(2,1,"NO: ");
 // Lcd_Chr(1, 1, disp2[0]);
 for (i = 0; i < 14; i++) {
  Lcd_Chr_Cp(disp2[i]);
 }

   //  Lcd_Out(2,1,disp1);
    // Lcd_Out(3,1,disp1);
    // Lcd_Out(4,1,disp1);
     }
  */
  
    else if ((you == 20)  && (you1 < 15)) {
    disp1[you1] = uart_rd;
    you1++;
    }

    else if ((you == 30) && (you2 < 15)) {
    disp2[you2] = uart_rd;
    you2++;
    }
  else if ((you == 40)  && (you3 < 15)) {
    disp3[you3] = uart_rd;
    you3++;
    }
  else if ((you == 50) && (you4 < 15)) {
    disp4[you4] = uart_rd;
    you4++;
    }

             }
}


}
