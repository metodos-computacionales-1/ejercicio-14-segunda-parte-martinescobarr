#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

//constantes
const double K = 100;
const double M = 2;
const double LAMBDA = 1;
const double DeltaT = 0.05;

//funciones

double f_0(double t, double y0, double y1); 
double f_1(double t, double y0, double y1);
void rk4(double t, double h, double & y0, double & y1);

double f_0(double t, double y0, double y1)
{
  return y1;
}

double f_1(double t, double y0, double y1)
{
  return (-K/M)*pow(y0, LAMBDA);
}

// metodo RK 4 orden dado como material del lab

void rk4(double t, double h, double & y0, double & y1) 
{
  double k_10, k_11, k_20, k_21, k_30, k_31, k_40, k_41;
    
  k_10 = h*f_0(t, y0, y1);
  k_11 = h*f_1(t, y0, y1);
  k_20 = h*f_0(t+h/2, y0 + k_10/2, y1 + k_11/2);
  k_21 = h*f_1(t+h/2, y0 + k_10/2, y1 + k_11/2);
  k_30 = h*f_0(t+h/2, y0 + k_20/2, y1 + k_21/2);
  k_31 = h*f_1(t+h/2, y0 + k_20/2, y1 + k_21/2);
  k_40 = h*f_0(t + h, y0 + k_30, y1 + k_31);
  k_41 = h*f_1(t + h, y0 + k_30, y1 + k_31);
    
  y0 = y0 + (1.0/6.0)*(k_10 + 2*k_20 + 2*k_30 + k_40);
  y1 = y1 + (1.0/6.0)*(k_11 + 2*k_21 + 2*k_31 + k_41);
}

int main(void)
{
  ofstream outfile;
  outfile.open("rk4sinfriccion.dat");
  double x, v, time;
  x = 1;
  v = 0;
  for(time = 0; time <= 15; time += DeltaT) {
    outfile<< time << "\t" << x << "\t" << v << endl;
    rk4(time, DeltaT, x, v);
    
  }
  outfile.close();

  return 0;
}
