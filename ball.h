/*-----------------------------------------------------------
  ball class
  -----------------------------------------------------------*/
#pragma once
#include "vecmath.h"
#include "cushion.h"
#include "pocket.h"

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
	
	// mechanics
	void Reset(void);
	void ApplyImpulse(vec2 imp);
	void ApplyFrictionForce(int ms);
	void Update(int ms);

	// cushion collisions
	void DoPlaneCollision(const cushion &c);
	bool HasHitPlane(const cushion &c) const;
	void HitPlane(const cushion &c);

	// ball collisions
	void DoBallCollision(ball &b);
	bool HasHitBall(const ball &b) const;
	void HitBall(ball &b);

	// pocket collisions
	void DoPocketCollision(pocket& p);
	bool HasHitPocket(const pocket& pocket) const;
	void HitPocket(pocket& pocket);
};

