#include <PID_Line_Follower.h>
/*PID Line Follower Library Powered by Michael Vargas

"El conocimiento no es nada si no se comparte"

Espero que esta libreria sea de tu agrado, puedes contactarme
msvargas97@gmail.com

GitHub:https://github.com/Msvargas97?tab=repositories
*/



//Directivas extras
#include <QTRSensors.h> //Libreria de Pololu utilizada para la entrada del control PID
//Este es un ejemplo de como usar el PID por lo tanto se realiza con los sensores QTR RC de pololu aplica igual para los analogos
//Variables para el uso de la libreria QTR
#define NUM_SENSORS   8     
#define TIMEOUT       2500  
#define EMITTER_PIN   2     

QTRSensorsRC qtrrc((unsigned char[]) {3, 4, 5, 6, 7, 8, 9, 10},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];

 int velocidad=100; //variable para la velocidad, el maximo es 255
  //Estas variables son 'Universales' pero segun las caracteristicas
  //de nuestro robot pueden variar 
 int setPoint = ((NUM_SENSORS-1)*1000)/2;
 double Kp =0.06;
 double Kd = 2.2;
 double Ki = 0.1; 
 int salida_pwm=0; //Variable auxiliar para determinar la velocidad
//Creamos o instaciamos un objeto llamado Control usando la Libreria
PID Control(setPoint,Kp,Ki,Ki,velocidad);


void setup() {
   Serial.begin(9600);//Iniciamos la comunicacion serial
//Se calibran los sensores
delay(500);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);    
  for (int i = 0; i < 150; i++) 
  {
    qtrrc.calibrate();      
  }
  digitalWrite(13, LOW);  
}

void loop() {
  //Esta es la entrada de la funcion del PID
 unsigned int position = qtrrc.readLine(sensorValues);
Control.ComputeSpeed(position); //Llamamos a la funcion para calcular la diferencia de potencial que debemos enviar a los motores con PWM

salida_pwm=Control.Speed(); //Esta funcion nos retorna la salida de la funcion anterior
//Lo ideal seria crear una funcion que controle nuestros motores
//y que sus argumentos sean la velocidad de los motores
// Esta funcion depende del driver o puente H que usemos...
//Esta seria la salida de la velocidad a los motores
 (salida_pwm < 0) ? setMotors(velocidad+salida_pwm, velocidad) : setMotors(velocidad, velocidad-salida_pwm);
 //No se preocupen por esta ultima linea de codigo es un condicional ternario es igual que tener un if
}
//Funcion de ejemplo de control de motores no hace NADA
void setMotors(int velocidad1,int velocidad2){
  
  }
