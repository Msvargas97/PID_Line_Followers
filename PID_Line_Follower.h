#ifndef PID_LINE_FOLLOWER_H_INCLUDED
#define PID_LINE_FOLLOWER_H_INCLUDED

#include "Arduino.h";

#define MANUAL 0
#define AUTOMATIC 1

class PID
{
  public:

 PID(int Setpoint,double Kp,double Ki,double Kd,int Max); //Instanciar parametros
 void ComputeSpeed(int position); //Calculamos la diferencia de potencial
 double getKp(); // Obtenemos el valor de las variables usadas
 double getKi();
 double getKd();
 int getSetpoint();
 int Speed(); //Obtenemos la velocidad o diferencia de potencial
 void setKp(double Kp); //Asignamos por separado cada parametro del PID
 void setKi(double Ki);
 void setKd(double Kd );
 void setSetpoint(int reference);
 void SetTunings(int Setpoint,double Kp,double Ki,double Kd); //Asignamos nuevos parametros al PID
 void SetSpeed(int Max); //Cambiamos la velocidad maxima 
 void SetMode(int Mode); //Podemos encender o apagar el PID
 bool Zero_Error=true; //Nos sirve para saber si el robot esta totalmente en linea

private:
	//Variables del PID
int  salida_pwm,proporcional_pasado,derivativo,proporcional,integral;
int velocidad;
int setPoint;
double kp,ki,kd;
bool inAuto=false;
};


#endif // PID_LINE_FOLLOWER_H_INCLUDED
