/*
 * EQsolve.cpp
 *
 *  Created on: Mar 4, 2016
 *      Author: roar
 */

#include "EQsolve.h"
#include <sstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Core>

EQsolve::EQsolve() {
	// TODO Auto-generated constructor stub

}

coord3d* EQsolve::solve(double a,double b,double c,double l,double m,double n,double p,double q,double r){
	//double x,y,z,D;
	Eigen::Vector3d v1(l-a,m-b, n-c);
	Eigen::Vector3d v2(p-a,q-b,r-c);
	//coord3d* v1 = new coord3d(l-a,m-b, n-c);
	//coord3d* v2 = new coord3d(p-a,q-b,r-c);
	// D = (a*m*r+b*p*n+c*l*q)-(a*n*q+b*l*r+c*m*p);
	// x = ((b*r*k+c*m*s+d*n*q)-(b*n*s+c*q*k+d*m*r))/D;
	// y = ((a*n*s+c*p*k+d*l*r)-(a*r*k+c*l*s+d*n*p))/D;
	// z = ((a*q*k+b*l*s+d*m*p)-(a*m*s+b*p*k+d*l*q))/D;
	//coord3d* XYZ = new coord3d(v1->getY() * v2->getZ() - v1->getZ() * v2->getY(),(v1->getX() * v2->getZ() - v1->getZ() * v2->getX()),v1->getX() *v2->getY() - v1->getY() * v2->getX() );
	Eigen::Vector3d v3 = v1.cross(v2);
	coord3d* XYZ = new coord3d(v3(0), v3(1), v3(2));
//XYZ->print();	
//printf ("floats: %4.2f",a);

//	std::cout << "a" << a << "b" << b << "c" << c << "d" << d << "l" << l << "m" << m << "n" << n << "k" << k << "p" << p << "q" << q << "r" 
//<< r << "s" << s << std::endl;
//XYZ->print();

	//coord3d* XYZ = new coord3d(x,y,z);
	return XYZ;
}
