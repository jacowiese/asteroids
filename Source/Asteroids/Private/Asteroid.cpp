// Fill out your copyright notice in the Description page of Project Settings.

#include "Asteroids.h"
#include "Asteroid.h"


void AAsteroid::InitialiseAsteroid(EAsteroidType asteroidType) {
	float asteroidScale = 0.3f;

	switch (asteroidType) {
	case EAsteroidType::XLARGE:
		asteroidScale = 1.0f;
		break;

	case EAsteroidType::LARGE:
		asteroidScale = 0.5f;
		break;

	case EAsteroidType::MEDIUM:
		asteroidScale = 0.3f;
		break;

	case EAsteroidType::SMALL:
		asteroidScale = 0.15f;
		break;
	}

	SetActorScale3D(FVector(asteroidScale));
}