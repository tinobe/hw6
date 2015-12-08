#include <cmath>
#include <fstream>

using namespace std;

void f(double*, const double, const double, const double, const double, const double, const double);

int main(){
const double x0=1,y0=1,z0=1,a=10,b=28,c=8/3.0;
const double t0=0; const double t_end=100; const double dt=0.001;
const int step=int( (t_end-t0)/dt); double x=x0,y=y0,z=z0;
double k1[3],k2[3],k3[3],k4[3];

ofstream out("Data.txt");
out << 0 << " " << x << " " << y << " " << z << endl;
	for(int i=1;i<step;i++){
		f(k1,x,y,z,a,b,c);	// k1
		f(k2,x+(dt/2.0)*k1[0],y+(dt/2.0)*k1[1],z+(dt/2.0)*k1[2],a,b,c);	//k2
		f(k3,x+(dt/2.0)*k2[0],y+(dt/2.0)*k2[1],z+(dt/2.0)*k2[2],a,b,c);	//k3
		f(k4,x+(dt/2.0)*k3[0],y+(dt/2.0)*k3[1],z+(dt/2.0)*k3[2],a,b,c);	//k4
		x+=(dt/6.0)*(k1[0]+2*k2[0]+2*k3[0]+k4[0]);
		y+=(dt/6.0)*(k1[1]+2*k2[1]+2*k3[1]+k4[1]);
		z+=(dt/6.0)*(k1[2]+2*k2[2]+2*k3[2]+k4[2]);
	out << i*dt << " " << x << " " << y << " " << z << endl;
	}

out.close();
return 0;
}

void f(double* k, const double x, const double y, const double z, const double a, const double b, const double c){
k[0]=a*(y-x); k[1]=x*(b-z)-y; k[2]=x*y-c*z;
}
