/*-----------------------------------------------------------
particleset class
-----------------------------------------------------------*/
#pragma once
#include "particle.h"

#define MAX_PARTICLES	(200)
class particleSet 
{
public:
	particle *particles[MAX_PARTICLES];
	int num;

	particleSet()
	{
		for(int i=0;i<MAX_PARTICLES;i++) particles[i] = 0;
		num=0;
	}

	~particleSet()
	{
		for(int i=0;i<MAX_PARTICLES;i++)
		{
			if (particles[i] == nullptr) {
				delete particles[i];
			}
		}
	}

	void AddParticle(const vec3 &pos);
	void update(int ms);
};