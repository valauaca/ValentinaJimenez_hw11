#include <iostream>

using namespace std;


// se declaran las funciones, de esta manera se hace el cambio de variable para volver una ecuacion de segundo orden en una de primer orden


double dx (double t, double x, double v);

double dv ( double t,  double x, double v);

void funcion( double t, double x, double v, double h);


// variables globales

double G;

double M;

double ti, xi, xin, vi, hi;





// la derivada de x es igual a la velocidad 

double dx (double t, double x, double v){

	return v;

}

double dv ( double t,  double x, double v){

	return -(G*M) / (x*x);

}

// funcion que ejecuta el metodo de R
void funcion( double t, double x, double v, double h){

	


	double kx1, kx2, kx3, kx4;
	double kv1, kv2, kv3, kv4;

	
	kx1 = dx( t, x, v);
	kv1 = dv( t, x, v);


	kx2 = dx(t + h/2, x + kx1 * h/2, v + kv1 * h/2);
	kv2 = dv(t + h/2, x + kx1 * h/2, v + kv1 * h/2);

	kx3 = dx(t + h/2, x + kx2 * h/2, v + kv2 * h/2);
	kv3 = dv(t + h/2, x + kx2 * h/2, v + kv2 * h/2);

	kx4 = dx(t + h, x + kx3 * h, v + kv3 * h);
	kv4 = dv(t + h, x + kx3 * h, v + kv3 * h);


	ti= t +h;
	xi= x +h *(kx1 + 2*kx2 + 2*kx3 + kx4 )/6.0 ;
	vi= v + h * (kv1 + 2*kv2 + 2*kv3 + kv4 )/6.0 ;

	


}




int main(){

	
	G= 10;
	M=1000;

	ti= 0.0;
	vi= 0.0;
	hi=0.0001;
	xin=100.0;

	xi=xin;

	while (xi > 0.01*xin){

		cout << ti << " " << xi << " " << vi << endl;
   		funcion(ti, xi, vi, hi);
		
	}



	return 0;
}

