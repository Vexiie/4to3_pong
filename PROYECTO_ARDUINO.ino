#include <MatrizLed.h>
#include <Servo.h>

#define pin_x A0
#define pin_y A1
#define pin_x2 A2
#define pin_y2 A3

MatrizLed pantalla;

int x = 0;
int y = 0;
int x2 = 0;
int y2 = 0;

void setup() {
  Serial.begin(9600);
  pantalla.begin(12, 11, 10, 4);
  pantalla.rotar(false);
}


void borrar_pantalla() {
  pantalla.clearDisplay(0);
  pantalla.clearDisplay(3);
  pantalla.clearDisplay(1);
  pantalla.clearDisplay(2);
}

//                       +----------------------+
//                       |                      |
//                       |     TRANSICIONES     |
//                       |                      |
//                       +----------------------+

//==========|| TRANSICION DE BLOQUES DE ABAJO HACIA ARRIBA ||==========\\

void trans_1_on() {

  for (int y = 8; y >= 0; y--) {            //|for (int x = 0; x < 8; x++)
    for (int x = 8; x >= 0; x--) {          //|for (int y = 8; y >= 0; y--)
      pantalla.setRow(y, x, 0b11111111);    //|
      delay(5);
    }
  }
}
//| DE ABAJO A LA DERECHA PRIMERO

void trans_1_off() {

  for (int y = 8; y >= 0; y--) {
    for (int x = 8; x >= 0; x--) {
      pantalla.setRow(y, x, 0b00000000);
      delay(5);
    }
  }
}

void bloques_abajo_arriba() {
  trans_1_on();
  trans_1_off();
}

//==========|| TRANSICION DE BLOQUES DE ARRIBA HACIA ABAJO ||==========\\

void trans_2_on() {
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      pantalla.setRow(x, y, 0b11111111);
      delay(5);
    }
  }
}

void trans_2_off() {
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      pantalla.setRow(x, y, 0b00000000);
      delay(5);
    }
  }
}

void bloques_arriba_abajo() {
  trans_2_on();
  trans_2_off();
}

//==========|| TRANSICION DE ABAJO HACIA ARRIBA ||==========\\

void trans_3_on() {
  for (int x = 7; x >= 0; x--) {
    for (int y = 0; y < 8; y++) {
      pantalla.setRow(y, x, 0b11111111);
      delay(5);
    }
  }
}

void trans_3_off() {
  for (int x = 7; x >= 0; x--) {
    for (int y = 0; y < 8; y++) {
      pantalla.setRow(y, x, 0b00000000);
      delay(5);
    }
  }
}

void todo_abajo_arriba() {
  trans_3_on();
  trans_3_off();
}

//==========|| TRANSICION DE ARRIBA HACIA ABAJO ||==========\\

void trans_4_on() {
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      pantalla.setRow(y, x, 0b11111111);
      delay(5);
    }
  }
}

void trans_4_off() {
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      pantalla.setRow(y, x, 0b00000000);
      delay(5);
    }
  }
}

void todo_arriba_abajo() {
  trans_4_on();
  trans_4_off();
}

//==========|| TRANSICION DE IZQUIERDA A DERECHA ||==========\\

void trans_5_on() {
  for (int x = 8; x >= 0; x--) {
    for (int y = 0; y < 8; y++) {
      pantalla.setColumn(x, y, 0b11111111);
      delay(5);
    }
  }
}

void trans_5_off() {
  for (int x = 8; x >= 0; x--) {
    for (int y = 0; y < 8; y++) {
      pantalla.setColumn(x, y, 0b00000000);
      delay(5);
    }
  }
}

void todo_izquierda_derecha() {
  trans_5_on();
  trans_5_off();
}

//==========|| TRANSICION DE DERECHA A IZQUIERDA ||==========\\

void trans_6_on() {
  for (int x = 0; x < 8; x++) {
    for (int y = 8; y >= 0; y--) {
      pantalla.setColumn(x, y, 0b11111111);
      delay(5);
    }
  }
}

void trans_6_off() {
  for (int x = 0; x < 8; x++) {
    for (int y = 8; y >= 0; y--) {
      pantalla.setColumn(x, y, 0b00000000);
      delay(5);
    }
  }
}

void todo_derecha_izquierda() {
  trans_6_on();
  trans_6_off();
}

//          +----------------------+
//          |                      |
//          |        MENU Y        |
//          |       DUOPLAY        |
//          |                      |
//          +----------------------+

//==========|| DUOPLAY FONDO ROJO ||==========\\

void duoplay_rojo() {
  pantalla.setRow(3, 0, 0b11111111);
  pantalla.setRow(3, 1, 0b10001101);
  pantalla.setRow(3, 2, 0b10110101);
  pantalla.setRow(3, 3, 0b10110101);
  pantalla.setRow(3, 4, 0b10110101);
  pantalla.setRow(3, 5, 0b10110101);
  pantalla.setRow(3, 6, 0b10001100);
  pantalla.setRow(3, 7, 0b11111111);

  pantalla.setRow(2, 0, 0b11111111);
  pantalla.setRow(2, 1, 0b01000100);
  pantalla.setRow(2, 2, 0b01010101);
  pantalla.setRow(2, 3, 0b01010101);
  pantalla.setRow(2, 4, 0b01010100);
  pantalla.setRow(2, 5, 0b01010101);
  pantalla.setRow(2, 6, 0b01000101);
  pantalla.setRow(2, 7, 0b11111111);

  pantalla.setRow(1, 0, 0b11111111);
  pantalla.setRow(1, 1, 0b00101110);
  pantalla.setRow(1, 2, 0b10101110);
  pantalla.setRow(1, 3, 0b10101110);
  pantalla.setRow(1, 4, 0b00101110);
  pantalla.setRow(1, 5, 0b11101110);
  pantalla.setRow(1, 6, 0b11100010);
  pantalla.setRow(1, 7, 0b11111111);

  pantalla.setRow(0, 0, 0b11111111);
  pantalla.setRow(0, 1, 0b00010101);
  pantalla.setRow(0, 2, 0b11010101);
  pantalla.setRow(0, 3, 0b11010101);
  pantalla.setRow(0, 4, 0b00011011);
  pantalla.setRow(0, 5, 0b11011011);
  pantalla.setRow(0, 6, 0b11011011);
  pantalla.setRow(0, 7, 0b11111111);
}

//==========|| DUOPLAY FONDO NEGRO ||==========\\

void duoplay_negro() {
  pantalla.setRow(3, 0, 0b00000000);
  pantalla.setRow(3, 1, 0b01110010);
  pantalla.setRow(3, 2, 0b01001010);
  pantalla.setRow(3, 3, 0b01001010);
  pantalla.setRow(3, 4, 0b01001010);
  pantalla.setRow(3, 5, 0b01001010);
  pantalla.setRow(3, 6, 0b01110011);
  pantalla.setRow(3, 7, 0b00000000);

  pantalla.setRow(2, 0, 0b00000000);
  pantalla.setRow(2, 1, 0b10111011);
  pantalla.setRow(2, 2, 0b10101010);
  pantalla.setRow(2, 3, 0b10101010);
  pantalla.setRow(2, 4, 0b10101011);
  pantalla.setRow(2, 5, 0b10101010);
  pantalla.setRow(2, 6, 0b10111010);
  pantalla.setRow(2, 7, 0b00000000);

  pantalla.setRow(1, 0, 0b00000000);
  pantalla.setRow(1, 1, 0b11010001);
  pantalla.setRow(1, 2, 0b01010001);
  pantalla.setRow(1, 3, 0b01010001);
  pantalla.setRow(1, 4, 0b11010001);
  pantalla.setRow(1, 5, 0b00010001);
  pantalla.setRow(1, 6, 0b00011101);
  pantalla.setRow(1, 7, 0b00000000);

  pantalla.setRow(0, 0, 0b00000000);
  pantalla.setRow(0, 1, 0b11101010);
  pantalla.setRow(0, 2, 0b00101010);
  pantalla.setRow(0, 3, 0b00101010);
  pantalla.setRow(0, 4, 0b11100100);
  pantalla.setRow(0, 5, 0b00100100);
  pantalla.setRow(0, 6, 0b00100100);
  pantalla.setRow(0, 7, 0b00000000);
}

//==========|| MENU PRINCIPAL ||==========\\

void menu_principal() {
  pantalla.setRow(3, 0, 0b00000000);
  pantalla.setRow(3, 1, 0b00011000);
  pantalla.setRow(3, 2, 0b00110000);
  pantalla.setRow(3, 3, 0b01100000);
  pantalla.setRow(3, 4, 0b01100000);
  pantalla.setRow(3, 5, 0b00110000);
  pantalla.setRow(3, 6, 0b00011000);
  pantalla.setRow(3, 7, 0b00000000);

  pantalla.setRow(2, 0, 0b00100001);
  pantalla.setRow(2, 1, 0b00010010);
  pantalla.setRow(2, 2, 0b00111111);
  pantalla.setRow(2, 3, 0b01101101);
  pantalla.setRow(2, 4, 0b11111111);
  pantalla.setRow(2, 5, 0b10100001);
  pantalla.setRow(2, 6, 0b10010010);
  pantalla.setRow(2, 7, 0b00000000);

  pantalla.setRow(1, 0, 0b00000110);
  pantalla.setRow(1, 1, 0b00000000);
  pantalla.setRow(1, 2, 0b00001110);
  pantalla.setRow(1, 3, 0b10000110);
  pantalla.setRow(1, 4, 0b11000110);
  pantalla.setRow(1, 5, 0b01000110);
  pantalla.setRow(1, 6, 0b01001111);
  pantalla.setRow(1, 7, 0b00000000);

  pantalla.setRow(0, 0, 0b00000000);
  pantalla.setRow(0, 1, 0b00011000);
  pantalla.setRow(0, 2, 0b00001100);
  pantalla.setRow(0, 3, 0b00000110);
  pantalla.setRow(0, 4, 0b00000110);
  pantalla.setRow(0, 5, 0b00001100);
  pantalla.setRow(0, 6, 0b00011000);
  pantalla.setRow(0, 7, 0b00000000);
}

//==========|| MENU JUEGOS ||==========\\

void menu_games() {

  pantalla.setRow(3, 0, 0b00000000);
  pantalla.setRow(3, 1, 0b00011011);
  pantalla.setRow(3, 2, 0b00110010);
  pantalla.setRow(3, 3, 0b01100010);
  pantalla.setRow(3, 4, 0b01100010);
  pantalla.setRow(3, 5, 0b00110010);
  pantalla.setRow(3, 6, 0b00011011);
  pantalla.setRow(3, 7, 0b00000000);

  pantalla.setRow(2, 0, 0b00000000);
  pantalla.setRow(2, 1, 0b11011110);
  pantalla.setRow(2, 2, 0b00010010);
  pantalla.setRow(2, 3, 0b00010010);
  pantalla.setRow(2, 4, 0b11011110);
  pantalla.setRow(2, 5, 0b01010010);
  pantalla.setRow(2, 6, 0b11010010);
  pantalla.setRow(2, 7, 0b00000000);

  pantalla.setRow(1, 0, 0b00000000);
  pantalla.setRow(1, 1, 0b10001011);
  pantalla.setRow(1, 2, 0b11011010);
  pantalla.setRow(1, 3, 0b10101011);
  pantalla.setRow(1, 4, 0b10001010);
  pantalla.setRow(1, 5, 0b10001010);
  pantalla.setRow(1, 6, 0b10001011);
  pantalla.setRow(1, 7, 0b00000000);

  pantalla.setRow(0, 0, 0b00000000);
  pantalla.setRow(0, 1, 0b11011110);
  pantalla.setRow(0, 2, 0b00010000);
  pantalla.setRow(0, 3, 0b10011110);
  pantalla.setRow(0, 4, 0b00000010);
  pantalla.setRow(0, 5, 0b00000010);
  pantalla.setRow(0, 6, 0b11011110);
  pantalla.setRow(0, 7, 0b00000000);
}

void menu_configuracion() {

  pantalla.setRow(3, 0, 0b00000000);
  pantalla.setRow(3, 1, 0b01111011);
  pantalla.setRow(3, 2, 0b01000010);
  pantalla.setRow(3, 3, 0b01000010);
  pantalla.setRow(3, 4, 0b01000010);
  pantalla.setRow(3, 5, 0b01000010);
  pantalla.setRow(3, 6, 0b01111011);
  pantalla.setRow(3, 7, 0b00000000);

  pantalla.setRow(2, 0, 0b00000000);
  pantalla.setRow(2, 1, 0b10100101);
  pantalla.setRow(2, 2, 0b10110101);
  pantalla.setRow(2, 3, 0b10101101);
  pantalla.setRow(2, 4, 0b10100101);
  pantalla.setRow(2, 5, 0b10100101);
  pantalla.setRow(2, 6, 0b10100101);
  pantalla.setRow(2, 7, 0b00000000);

  pantalla.setRow(1, 0, 0b00000000);
  pantalla.setRow(1, 1, 0b11101011);
  pantalla.setRow(1, 2, 0b00000010);
  pantalla.setRow(1, 3, 0b11001010);
  pantalla.setRow(1, 4, 0b00001010);
  pantalla.setRow(1, 5, 0b00001010);
  pantalla.setRow(1, 6, 0b00001011);
  pantalla.setRow(1, 7, 0b00000000);

  pantalla.setRow(0, 0, 0b00000000);
  pantalla.setRow(0, 1, 0b11011000);
  pantalla.setRow(0, 2, 0b00001100);
  pantalla.setRow(0, 3, 0b00000110);
  pantalla.setRow(0, 4, 0b11000110);
  pantalla.setRow(0, 5, 0b01001100);
  pantalla.setRow(0, 6, 0b11011000);
  pantalla.setRow(0, 7, 0b00000000);
}

void menu_brillo() {

  pantalla.setRow(0, 0, 0b00011000);
  pantalla.setRow(0, 1, 0b00111100);
  pantalla.setRow(0, 2, 0b01100110);
  pantalla.setRow(0, 3, 0b00000000);
  pantalla.setRow(0, 4, 0b00000000);
  pantalla.setRow(0, 5, 0b01100110);
  pantalla.setRow(0, 6, 0b00111100);
  pantalla.setRow(0, 7, 0b00011000);

  pantalla.setRow(1, 0, 0b00000000);
  pantalla.setRow(1, 1, 0b01000111);
  pantalla.setRow(1, 2, 0b01000101);
  pantalla.setRow(1, 3, 0b01000101);
  pantalla.setRow(1, 4, 0b01000101);
  pantalla.setRow(1, 5, 0b01000101);
  pantalla.setRow(1, 6, 0b01110111);
  pantalla.setRow(1, 7, 0b00000000);

  pantalla.setRow(2, 0, 0b00000000);
  pantalla.setRow(2, 1, 0b11010100);
  pantalla.setRow(2, 2, 0b01000100);
  pantalla.setRow(2, 3, 0b11010100);
  pantalla.setRow(2, 4, 0b10010100);
  pantalla.setRow(2, 5, 0b01010100);
  pantalla.setRow(2, 6, 0b01010111);
  pantalla.setRow(2, 7, 0b00000000);

  pantalla.setRow(3, 0, 0b00000000);
  pantalla.setRow(3, 1, 0b01110011);
  pantalla.setRow(3, 2, 0b01010010);
  pantalla.setRow(3, 3, 0b01111011);
  pantalla.setRow(3, 4, 0b01001010);
  pantalla.setRow(3, 5, 0b01001010);
  pantalla.setRow(3, 6, 0b01111010);
  pantalla.setRow(3, 7, 0b00000000);
}

void snake() {

  //JUGADOR 1
  int punt1 = 0;
  int mat1 = 3;        // MATRIZ EN LA QUE SE ENCUENTRA EL JUGADOR 1
  int posx1 = 1;       // POSICION X DEL JUGADOR 1
  int posy1 = 3;       // POSICION Y DEL JUGADOR 1
  int velx1 = 1;       // VELOCIDAD APLICADA A LA VARIABLE X
  int vely1 = 0;       // VELOCIDAD APLICADA A LA VARIABLE Y
  bool vivo1 = true;   // ESTADO DEL JUGADOR 1 VIVO?

  bool fin = false;    // EL JUEGO LLEGÓ A SU FIN?

  // JUGADOR 2
  int punt2 = 0;
  int mat2 = 0;        // MATRIZ EN LA QUE SE ENCUENTRA EL JUGADOR 1
  int posx2 = 6;       // POSICION X DEL JUGADOR 1
  int posy2 = 4;       // POSICION Y DEL JUGADOR 1
  int velx2 = -1;       // VELOCIDAD APLICADA A LA VARIABLE X
  int vely2 = 0;       // VELOCIDAD APLICADA A LA VARIABLE Y
  bool vivo2 = true;    // ESTADO DEL JUGADOR 2 VIVO?
  int frutax = random(0, 7);
  int frutay = random(0, 7);
  int matfruta = random(0, 4);
  pantalla.setLed(matfruta, frutay, frutax, true);


  while (fin != true) {
    pantalla.setLed(mat1, posy1, posx1, true);

    // JUGADOR 1 POSICION X +
    if (velx1 == 1) {
      vely1 = 0;
      pantalla.setLed(mat1, posy1, posx1, false);
      posx1 = posx1 + 1;
      if (posx1 >= 8) {
        if (mat1 == 0) {
          fin = true;
          borrar_pantalla();
        }
        else {
          mat1 = mat1 - 1;
          posx1 = 0;
          pantalla.setLed(mat1, posy1, posx1, true);
        }
      }
      else {
        pantalla.setLed(mat1, posy1, posx1, true);
      }
    }

    // JUGADOR 2 POSICION X +
    if (velx2 == 1) {
      vely2 = 0;
      pantalla.setLed(mat2, posy2, posx2, false);
      posx2 = posx2 + 1;
      if (posx2 >= 8) {
        if (mat2 == 0) {
          fin = true;
          borrar_pantalla();
        }
        else {
          mat2 = mat2 - 1;
          posx2 = 0;
          pantalla.setLed(mat2, posy2, posx2, true);
        }
      }
      else {
        pantalla.setLed(mat2, posy2, posx2, true);
      }
    }

    // JUGADOR 1 POSICION X -
    if (velx1 == -1) {
      vely1 = 0;
      pantalla.setLed(mat1, posy1, posx1, false);
      posx1 = posx1 - 1;
      if (posx1 <= -1) {
        if (mat1 == 3) {
          fin = true;
          borrar_pantalla();
        }
        else {
          mat1 = mat1 + 1;
          posx1 = 7;
          pantalla.setLed(mat1, posy1, posx1, true);
        }
      }
      else {
        pantalla.setLed(mat1, posy1, posx1, true);
      }
    }

    // JUGADOR 2 POSICION X -
    if (velx2 == -1) {
      vely2 = 0;
      pantalla.setLed(mat2, posy2, posx2, false);
      posx2 = posx2 - 1;
      if (posx2 <= -1) {
        if (mat2 == 3) {
          fin = true;
          borrar_pantalla();
        }
        else {
          mat2 = mat2 + 1;
          posx2 = 7;
          pantalla.setLed(mat2, posy2, posx2, true);
        }
      }
      else {
        pantalla.setLed(mat2, posy2, posx2, true);
      }
    }

    // JUGADOR 1 POSICION Y +
    if (vely1 == 1) {
      velx1 = 0;
      pantalla.setLed(mat1, posy1, posx1, false);
      posy1 = posy1 - 1;
      pantalla.setLed(mat1, posy1, posx1, true);
      if (posy1 <= -1) {
        fin = true;
        borrar_pantalla();
      }
    }

    // JUGADOR 2 POSICION Y +
    if (vely2 == 1) {
      velx2 = 0;
      pantalla.setLed(mat2, posy2, posx2, false);
      posy2 = posy2 - 1;
      pantalla.setLed(mat2, posy2, posx2, true);
      if (posy2 <= -1) {
        fin = true;
        borrar_pantalla();
      }
    }

    // JUGADOR 1 POSICION Y -
    if (vely1 == -1) {
      velx1 = 0;
      pantalla.setLed(mat1, posy1, posx1, false);
      posy1 = posy1 + 1;
      pantalla.setLed(mat1, posy1, posx1, true);
      if (posy1 >= 8) {
        fin = true;
        borrar_pantalla();
      }
    }

    // JUGADOR 2 POSICION Y -
    if (vely2 == -1) {
      velx2 = 0;
      pantalla.setLed(mat2, posy2, posx2, false);
      posy2 = posy2 + 1;
      pantalla.setLed(mat2, posy2, posx2, true);
      if (posy2 >= 8) {
        fin = true;
        borrar_pantalla();
      }
    }
    if (posx1 == frutax && posy1 == frutay && mat1 == matfruta) {
      pantalla.setLed(matfruta, frutay, frutax, false);
      punt1 = punt1 + 10;
      int frutax = random(0, 7);
      int frutay = random(0, 7);
      int matfruta = random(0, 4);
    }
    if (posx2 == frutax && posy2 == frutay && mat2 == matfruta) {
      pantalla.setLed(matfruta, frutay, frutax, false);
      punt2 = punt2 + 10;
      int frutax = random(0, 7);
      int frutay = random(0, 7);
      int matfruta = random(0, 4);
    }
    delay(500);
  }

}

//=====================//JUEGO\\=================\\
//
//void shooter() {
//  //jugador 1
//  int posy = 4;
//  int posx = 0;
//  int balay;
//  int balax;
//
//  //jugador 2
//  int posy2 = 4;
//  int posx2 = 7;
//  int balay2;
//  int balax2;
//  int matbala = 3;
//
//  int fin = false;
//
//  while (fin != true) {
//    int eje_x = analogRead (pin_x);
//    int eje_y = analogRead (pin_y);
//
//    //J1
//    pantalla.setLed(3, posy, 0, true);
//
//    if (eje_y < 300) {
//      pantalla.setLed(3, posy, 0, false);
//      posy = posy - 1;
//      if (posy < 0) {
//        posy = 0;
//        pantalla.setLed(3, posy, 0, true);
//      } else {
//        pantalla.setLed(3, posy, 0, true);
//      }
//    }
//
//    if (eje_y > 800) {
//      pantalla.setLed(3, posy, 0, false);
//      posy = posy + 1;
//      if (posy > 7) {
//        posy = 7;
//        pantalla.setLed(matbala, posy, 0, true);
//      } else {
//        pantalla.setLed(matbala, posy, 0, true);
//      }
//      //bala1
//    if (eje_x > 800){
//      balay = posy;
//      balax = posx;
//      balax = balax + 1;
//
//      pantalla.setLed(matbala,balay, balax, true);
//      }
//
//
//      delay(500);
//    }
//  }

  ////MENU INTERACTIVO
  ////void js_x_y() {
  //  int eje_x = analogRead (pin_x);
  //  int eje_y = analogRead (pin_y);
  //  int eje_x2 = analogRead (pin_x2);
  //  int eje_y2 = analogRead (pin_y2);
  //
  //  //IZQUIERDA
  //  if (eje_x < 300) {
  //    y = 0;
  //    x = -1;
  //  }
  //  //ARRIBA
  //  if (eje_y < 300) {
  //    x = 0;
  //    y = -1;
  //  }
  //  //DERECHA
  //  if (eje_x > 800) {
  //    y = 0;
  //    x = 1;
  //  }
  //  //ABAJO
  //  if (eje_y > 800) {
  //    x = 0;
  //    y = 1;
  //  }
  //  //IZQUIERDA2
  //  if (eje_x2 < 300) {
  //    y2 = 0;
  //    x2 = -1;
  //  }
  //  //ARRIBA 2
  //  if (eje_y2 < 300) {
  //    x2 = 0;
  //    y2 = -1;
  //  }
  //  //DERECHA 2
  //  if (eje_x2 > 800) {
  //
  //    y2 = 0;
  //    x2 = 1;
  //  }
  //  //ABAJO 2
  //  if (eje_y2 > 800) {
  //    x2 = 0;
  //    y2 = 1;
  //  }
  //}
  void eleccion() {
    int opcion = 1;
    int eleccion_final = 0;
    do {
      int eje_x = analogRead (pin_x);
      int eje_y = analogRead (pin_y);
      int eje_x2 = analogRead (pin_x2);
      int eje_y2 = analogRead (pin_y2);
      switch (opcion) {

        case 1:
          while (opcion == 1) {
            menu_principal();
            delay(300);
            int eje_x = analogRead (pin_x);
            int eje_x2 = analogRead (pin_x2);
            if (eje_x < 300 || eje_x2 < 300) {
              opcion = 2;
            }
            if (eje_x > 800 || eje_x2 > 800) {
              opcion = 3;
            }
          }
          break;

        case 2:
          while (opcion == 2) {
            delay(300);
            menu_games();
            int eje_x = analogRead (pin_x);
            int eje_x2 = analogRead (pin_x2);
            if (eje_x < 300 || eje_x2 < 300) {
              trans_5_on;
              opcion = 2;
            }
            if (eje_x > 800 || eje_x2 > 800) {
              trans_6_on;
              opcion = 1;
            }
          }
        case 3:
          while (opcion == 3) {
            menu_configuracion;
            int eje_x = analogRead (pin_x);
            int eje_x2 = analogRead (pin_x2);
            if (eje_x < 300 || eje_x2 < 300) {
              delay(150);
              opcion = 1;
            }
            if (eje_x > 800 || eje_x2 > 800) {
              delay(150);
              opcion = 4;
            }
          }
        case 4:
          while (opcion == 4) {
            menu_brillo();
            int eje_x = analogRead (pin_x);
            int eje_x2 = analogRead (pin_x2);
            if (eje_x < 300 || eje_x2 < 300) {
              delay(150);
              opcion = 3;
            }
            if (eje_y < 300 || eje_y2 < 300 ) {
              pantalla.setIntensidad(15);
              pantalla.apagar();
              delay(1000);
              pantalla.encender();
            }
            if (eje_y > 800 || eje_y2 > 800) {
              pantalla.setIntensidad(1);
              pantalla.apagar();
              delay(1000);
              pantalla.encender();
            }
          }
        default:
          break;
      }
    } while (eleccion_final == 0);
  }

  void loop() {
      trans_2_on();
  duoplay_rojo();
  delay(1000);
  trans_1_on();
  duoplay_negro();
  delay(1000);
  trans_1_off();
  delay(700);
  eleccion();
  }
