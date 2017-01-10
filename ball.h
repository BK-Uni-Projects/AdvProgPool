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
// Physics stuff
const float gCoeffRestitution = 0.5f;
const float gCoeffFriction = 0.03f;
const float gGravityAccn = 9.8f;

// Ball data
const float BALL_RADIUS = 0.05f;
const float BALL_MASS = 0.1f;
const float SMALL_VELOCITY = 0.1f;

//Rack position adjustment
const float RACK_OFFSET = 0.5f;

class ball{
public:
	static int ballIndexCnt;
	static int bar_count;
	vec2	position;
	vec2	velocity;
	float	radius;
	float	mass;
	int		index;
	bool	inPlay;

	ball() : position(0.0), velocity(0.0), radius(BALL_RADIUS), mass(BALL_MASS), inPlay(true) {
		index = ballIndexCnt++; 
		Reset();
	}

	bool isCueball() const;
	bool isBlack() const;
	void setinPlay(bool set);
	void Sidebar(void);

	// mechanics
	void Reset(void);
	void ApplyImpulse(vec2 imp);
	void ApplyFrictionForce(int ms);
	void Update(int ms);

	// cushion collisions
	void DoPlaneCollision(const cushion &c);
	bool HasHitCushion(const cushion &c) const;
	void HitCushion(const cushion &c);

	// ball collisions
	void DoBallCollision(ball &b);
	bool HasHitBall(const ball &b) const;
	void HitBall(ball &b);

	// pocket collisions
	void DoPocketCollision(pocket& p) ;
	bool HasHitPocket(const pocket& pocket) const;
	void HitPocket(pocket& pocket);
};

