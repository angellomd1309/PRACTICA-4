/*
FUNDACION KINAL
CENTRO EDUCATIVO TECNICO LARELEORAL KINAL
PEROTO EN ELECTRONICA
QUINTO PERITO
SECCION: A
CURSO: TALLER DE ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS
ALUMNOS: ANGELLO GARELERIEL MANSILLA DIEGUEZ y PARELELO DAVID HERNANDEZ AJIATAZ
CARNETS: 2022380 y 2022472
PRACTICA 4 DISEÑO DE FIRMWARE
*/

#define PHIGH(pin)   digitalWrite(pin, HIGH)//Definimos una pequeña funcion, para abreviar el DigitalWrite.
#define PLOW(pin)   digitalWrite(pin, LOW)

void  PENTRADA(void); //Definimos una funcion para salidas y entradas de los pines.
void  PSALIDA(void);

int SSEG(int a, int b, int c, int d, int e, int f, int g, int RELE); //Definimos una funcion para nuestros leds del display y el modulo Rele.
int TRIG = 11; //Definimos El Pin 2 para Triger.
int ECHO = 12; //Definimos El Pin 3 para Echo.
int DURATION; //Definimos una variable de duracion.
int DISTANCE; //Definimos una variable distancia.
int CONT=0; //Definimos una variable para contar.

void setup() {

 Serial.begin(9600); 
  
PENTRADA(); //Hacemos el llamado a las funciones de Configuracion.
PSALIDA();  

}

void loop() {
  
  digitalWrite(TRIG, LOW); //Apaga el Pin de Trig.
  delay(30); 
  digitalWrite(TRIG, HIGH);//Enciende el Pin Trig. 
  delay(30);
  digitalWrite(TRIG, LOW);//Apaga el Pin Trig.
  
  DURATION = pulseIn(ECHO, HIGH); /* Lee la informacion del pin eco,
  y la guarda en la variable duracion */
  
  DISTANCE= DURATION*0.034/2;  //Convierte la distancia en centimetros . 
  Serial.print(String(DISTANCE)); // La variable String guarda tipo de datos en cadenas
  Serial.println(" cm");
  delay(400);                     

  if(DISTANCE>=6 && DISTANCE <=10) //Si la distancia es entre 6cm o 10cm Ejecutara lo de las llaves.
  {

    CONT++;

    } 
  else  //Lo contrario...
  {

    }

    SSEG(5,4,8,9,10,6,7,3);

           
          
     
}
 void PENTRADA(void){
  pinMode(ECHO, INPUT);
  
 }

void PSALIDA(void)
{

     pinMode(TRIG, OUTPUT);  
     pinMode(3, OUTPUT);
     pinMode(4, OUTPUT);
     pinMode(5, OUTPUT);
     pinMode(6, OUTPUT);
     pinMode(7, OUTPUT);
     pinMode(8, OUTPUT);
     pinMode(9, OUTPUT);
     pinMode(10, OUTPUT); 
     digitalWrite(3,HIGH);       
                     
}
int   SSEG(int a, int b, int c, int d, int e, int f, int g, int RELE){
switch(CONT){
          
          case(0):
              PHIGH(a);
              PHIGH(b);
              PHIGH(c);
              PHIGH(d);
              PHIGH(e);
              PHIGH(f);
              PLOW(g);
            break;
          case(1):
            PLOW(a);
            PHIGH(b);
            PHIGH(c);
            PLOW(d);
            PLOW(e);
            PLOW(f);
            PLOW(g);
         break;
           case(2):
            PHIGH(a);
            PHIGH(b);
            PLOW(c);
            PHIGH(d);
            PHIGH(e);
            PLOW(f);
            PHIGH(g);
         break;
          case(3):
            PHIGH(a);
            PHIGH(b);
            PHIGH(c);
            PHIGH(d);
            PLOW(e);
            PLOW(f);
            PHIGH(g);
         break;
          case(4):
            PLOW(a);
            PHIGH(b);
            PHIGH(c);
            PLOW(d);
            PLOW(e);
            PHIGH(f);
            PHIGH(g);
         break;                
          case(5):
            PHIGH(a);
            PLOW(b);
            PHIGH(c);
            PHIGH(d);
            PLOW(e);
            PHIGH(f);
            PHIGH(g);
         break;       
          case(6):
            PHIGH(a);
            PLOW(b);
            PHIGH(c);
            PHIGH(d);
            PHIGH(e);
            PHIGH(f);
            PHIGH(g);
         break;        
          case(7):
            PHIGH(a);
            PHIGH(b);
            PHIGH(c);
            PLOW(d);
            PLOW(e);
            PLOW(f);
            PLOW(g);
         break;
          case(8):
            PHIGH(a);
            PHIGH(b);
            PHIGH(c);
            PHIGH(d);
            PHIGH(e);
            PHIGH(f);
            PHIGH(g);
         break;
           case(9):
            PHIGH(a);
            PHIGH(b);
            PHIGH(c);
            PHIGH(d);
            PLOW(e);
            PHIGH(f);
            PHIGH(g);
            PLOW(RELE);
            CONT=9;
         break; 
             
    }
  
}
