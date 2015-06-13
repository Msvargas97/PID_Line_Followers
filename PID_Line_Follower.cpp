#include "PID_Line_Follower.h"
#include <Arduino.h>


//Libreria Creada por Michael Vargas

/*

Version 1.0

Bitacora:

13/06/2015  ->         Version inicial
------------------------------------------------------
Por favor hacer uso exclusivamente de forma didactica 
copyright 2015

Cualquier duda que tengas pueda hacermela saber
msvargas97@gmail.com

Creditos; Pololu, FKTBot y todas mis investigaciones hechas en internet :)

GitHub:https://github.com/Msvargas97?tab=repositories

Open Source
Msvargas97
2015
*/
PID::PID(int Setpoint,double Kp,double Ki,double Kd,int Max){
	setPoint=Setpoint;
	kp=Kp;
	ki=Ki;
	kd=Kd;
	salida_pwm=proporcional_pasado=derivativo=proporcional=integral=0;

	if(velocidad > 256) velocidad=255;
    else velocidad=Max;

	SetMode(AUTOMATIC);
}

void PID::ComputeSpeed(int position)
{

if(!inAuto)return; //Activar o desactivar el PID

 proporcional = (position) - setPoint; // set point es 3500, asi obtenemos el error
   Zero_Error=proporcional;
 integral = integral + proporcional_pasado; //obteniendo integral
 derivativo = (proporcional - proporcional_pasado); //obteniedo el derivativo
  if (integral > 1000) integral = 1000; //limitamos la integral para no causar problemas
  if (integral < -1000) integral = -1000;
  salida_pwm = ceil(double(( proporcional * kp ) + ( derivativo * kd ) + (integral * ki))) ; //Calculamos la diferencia de potencial y la rendodeamos

  if (  salida_pwm > velocidad )  salida_pwm = velocidad; //limitamos la salida de pwm
  if ( salida_pwm < -velocidad )  salida_pwm = -velocidad;
  
  proporcional_pasado = proporcional;
}
int PID::Speed(){
	return salida_pwm;
}
double PID::getKp(){
	return kp;
}
double PID::getKi(){
	return ki;
}

double PID::getKd(){
	return kd;
}
int PID::getSetpoint(){
	return setPoint;
}
void PID::setKp(double Kp){
	kp=Kp;
}
void PID::setKi(double Ki){
	ki=Ki;
}
void PID::setKd(double Kd){
	kd=Kd;
}
void PID::setSetpoint(int reference){
	setPoint=reference;
}
void PID::SetTunings(int Setpoint,double Kp,double Ki,double Kd)
{
if(Kp<0 || Ki<0 || Kd<0)return;

kp=Kp;
ki=Ki;
kd=Kd;
setPoint=Setpoint;

}

void PID::SetSpeed(int Max)
{
if(Max>256)return;
velocidad=Max;
if(salida_pwm != 0){
if(salida_pwm > velocidad)salida_pwm=velocidad;
else if(salida_pwm < -velocidad ) salida_pwm=-velocidad;
}
}
void PID::SetMode(int Mode)
{
inAuto=Mode;
}
