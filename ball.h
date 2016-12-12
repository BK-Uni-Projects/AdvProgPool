/*-----------------------------------------------------------
  ball class
  -----------------------------------------------------------*/
#pragma once
#include "vecmath.h"
#include "cushion.h"

/*-----------------------------------------------------------
Macros
-----------------------------------------------------------*/
#define BALL_RADIUS		(0.05f)
#define BALL_MASS		(0.1f)
#define SMALL_VELOCITY		(0.01f)


class ball
{
	static int ballIndexCnt;
public:
	vec2	position;
	vec2	velocity;
	float	radius;
	float	mass;
	int		index;

	ball(): position(0.0), velocity(0.0), radius(BALL_RADIUS), 
		mass(BALL_MASS) {index = ballIndexCnt++; Reset();}
	
	void Reset(void);
	void ApplyImpulse(vec2 imp);
	void ApplyFrictionForce(int ms);
	void DoPlaneCollision(const cushion &c);
	void DoBallCollision(ball &b);
	void Update(int ms);
	
	bool HasHitPlane(const cushion &c) const;
	bool HasHitBall(const ball &b) const;

	void HitPlane(const cushion &c);
	void HitBall(ball &b);
};

