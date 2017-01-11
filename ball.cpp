/*-----------------------------------------------------------
  ball class members
  -----------------------------------------------------------*/
#include <random>

#include "ball.h"
#include "table.h"
#include "pocket.h"
#include "ruleset.h"

extern table gTable;
extern ruleset gGame;

int ball::ballIndexCnt = 0;
int ball::bar_count = 0;

bool ball::isCueball() const{
	if (index==0)	{
		return true;
	}
	return false;
}

bool ball::isBlack() const{
	if (index == 9)	{
		return true;
	}
	return false;
}

void ball::setinPlay(bool set) {
	inPlay = set;
}

void ball::Sidebar(void) {
	bar_count++;
	setinPlay(false);

	//set velocity to zero
	velocity = 0.0;

	//Set side bar ball position
	position(1) = TABLE_Z -(bar_count*(BALL_RADIUS*2.1));
	position(0) = TABLE_X + 0.5;
}

void ball::SidebarCueball(void) {
	if (inPlay) {
		setinPlay(false);

		//set velocity to zero
		velocity = 0.0;

		//Set side bar ball position
		position(1) = TABLE_Z;
		position(0) = TABLE_X + 0.8;
	}

}


void ball::Reset(void){
	// Arrange balls into sets
	if (index > 0 && index % 2 == 1) {
		set = 1;
	}
	if (index > 0 && index % 2 == 0) {
		set = 2;
	}
	if(isBlack()) {
		set = 3;
	}

	//set velocity to zero
	velocity = 0.0;

	//work out rack position
	if(isCueball())	{
		setinPlay(true);
		position(1) = 0.8;
		position(0) = 0.0;
		return;
	}
	
	// Build Triangle from balls voodoo
	static const float sep = (BALL_RADIUS*2.1f);
	static const float rowSep = (BALL_RADIUS*1.6f);
	int row = 1;
	int rowIndex = index;
	while(rowIndex > row)	{
		rowIndex -= row;
		row++;
	}
	position(1) =  -(rowSep * (row-1))-RACK_OFFSET;
	position(0) = (((row-1)*sep)/2.0f) - (sep*(row-rowIndex));
}

void ball::ApplyImpulse(vec2 imp){
	velocity = imp;
}

void ball::ApplyFrictionForce(int ms){
	if(velocity.Magnitude()<=0.0) return;

	//accelaration is opposite to direction of motion
	vec2 accelaration = -velocity.Normalised();
	//friction force = constant * mg
	//F=Ma, so accelaration = force/mass = constant*g
	accelaration *= (gCoeffFriction * gGravityAccn);
	//integrate velocity : find change in velocity
	vec2 velocityChange = ((accelaration * ms)/1000.0f);
	//cap magnitude of change in velocity to remove integration errors
	if(velocityChange.Magnitude() > velocity.Magnitude()) velocity = 0.0;
	else velocity += velocityChange;
}

void ball::Update(int ms){
	//apply friction
	ApplyFrictionForce(ms);
	//integrate position
	position += ((velocity * ms)/(500));
	//set small velocities to zero
	if(velocity.Magnitude()<SMALL_VELOCITY) velocity = 0.0;
}

/**	
all collision methods
*/
void ball::DoBallCollision(ball &b) {
	if (HasHitBall(b)) HitBall(b);
}

bool ball::HasHitBall(const ball &b) const {
	vec2 relPosn = position - b.position;
	float dist = float(relPosn.Magnitude());
	vec2 relPosnNorm = relPosn.Normalised();
	vec2 relVelocity = velocity - b.velocity;

	// collision tests
	if (relVelocity.Dot(relPosnNorm) >= 0.0) return false;			//if moving apart, cannot have hit	

	if (dist > (radius + b.radius)) return false;					//if distnce is more than sum of radii, have not hit

	return true;
		
}

void ball::HitBall(ball &b){
	
	/** Game Physics section*/
	//find direction from other ball to this ball
	vec2 relDir = (position - b.position).Normalised();

	//split velocities into 2 parts:  one component perpendicular, and one parallel to 
	//the collision plane, for both balls
	//(NB the collision plane is defined by the point of contact and the contact normal)
	float perpV = float(velocity.Dot(relDir));
	float perpV2 = float(b.velocity.Dot(relDir));
	vec2 parallelV = velocity - (relDir*perpV);
	vec2 parallelV2 = b.velocity - (relDir*perpV2);

	//Calculate new perpendicluar components:
	//v1 = (2*m2 / m1+m2)*u2 + ((m1 - m2)/(m1+m2))*u1;
	//v2 = (2*m1 / m1+m2)*u1 + ((m2 - m1)/(m1+m2))*u2;
	float sumMass = mass + b.mass;
	float perpVNew = (float)((perpV*(mass - b.mass)) / sumMass) + (float)((perpV2*(2.0*b.mass)) / sumMass);
	float perpVNew2 = (float)((perpV2*(b.mass - mass)) / sumMass) + (float)((perpV*(2.0*mass)) / sumMass);

	//find new velocities by adding unchanged parallel component to new perpendicluar component
	velocity = parallelV + (relDir*perpVNew);
	b.velocity = parallelV2 + (relDir*perpVNew2);

	

}

/** 
Cushion Collision methods 
*/
void ball::DoPlaneCollision(const cushion &b) {
	if (HasHitCushion(b)) HitCushion(b);
}

bool ball::HasHitCushion(const cushion &c) const {
	//if moving away from plane, cannot hit
	if (velocity.Dot(c.normal) >= 0.0) return false;

	//if in front of plane, then have not hit
	vec2 relPos = position - c.vertices[0];
	double sep = relPos.Dot(c.normal);
	if (sep > radius) return false;
	return true;
}

void ball::HitCushion(const cushion &c) {
	//reverse velocity component perpendicular to plane
	double comp = velocity.Dot(c.normal) * (1.0 + gCoeffRestitution);
	vec2 delta = -(c.normal * comp);
	velocity += delta;
}

/** 
Pocket Collision methods
*/
void ball::DoPocketCollision(pocket &p) {
	if (HasHitPocket(p)) HitPocket(p);
}

bool ball::HasHitPocket(const pocket &pocket) const {
	vec2 relPosn = position - pocket.position;
	float dist = (float)relPosn.Magnitude();
	vec2 relPosnNorm = relPosn.Normalised();
	vec2 relVelocity = velocity - 0.0f;

	if (relVelocity.Dot(relPosnNorm) >= 0.0) return false;			//if moving apart, cannot have hit	
	if (dist > (radius + pocket.colRadius)) return false;					//if distnce is more than sum of radii, have not hit
	return true;	// TODO yeah... make it work
}

void ball::HitPocket(pocket &pocket){
	bool doParticles = false;

	// process cueball entering pocket
	if (isCueball()) {
		// declare foul
		// change turn
		// place cueball at start point
		//inPlay = false;
		SidebarCueball();
		//Reset();
		return;
	}

	// Process Blackball entering pocket
	if (isBlack()) {
		// check if player is on black
		// declare winner
	}
	Sidebar();

	// only do particles if flagged to do so
	if (doParticles) {		
		//make some particles
		int n = (rand() % 5) * 2 + 5;
		vec3 pos(pocket.position(0), 0, pocket.position(1));

		for (int i = 0; i < n; i++) {
			gTable.parts.AddParticle(pos);
		}
	}
}
