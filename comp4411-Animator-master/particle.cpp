 // SAMPLE_SOLUTION
#include "particle.h"
#include "modelerdraw.h"
#include <FL/gl.h>
#include <FL/glut.h>
#include <GL/glu.h>
#include <cstdio>
#include <math.h>
#include "Force.h"

void Particle::add_force(Force* f) {
	forces.push_back(f);
}

void Particle::nextPos(float deltaT) {
	for (std::vector<Force*>::iterator it = forces.begin(); it != forces.end(); it++)
	{
		(*it)->addForce(this);
	}
	Vec3d k1 = (speed + netForce / mass*deltaT);
	Vec3d k2 = (speed + netForce / mass*(3 / 2)*deltaT);
	Vec3d k3 = (speed + netForce / mass*(3 / 2)*deltaT);
	Vec3d k4 = (speed + netForce / mass*(4 / 2)*deltaT);
	speed += netForce/mass * deltaT;
	position += k2 * deltaT;
}

void Particle::draw() {
	setDiffuseColor(0,0,1);
	glPushMatrix();
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex3f(position[0], position[1], position[2]);
	glEnd();
	glPopMatrix();
	glPointSize(1);
}