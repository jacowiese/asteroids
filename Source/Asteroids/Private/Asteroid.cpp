// Fill out your copyright notice in the Description page of Project Settings.

#include "Asteroids.h"
#include "AsteroidGameState.h"
#include "Asteroid.h"


AAsteroid::AAsteroid() {
	PrimaryActorTick.bCanEverTick = true;
}

void AAsteroid::InitialiseAsteroid(EAsteroidType asteroidType) {
	this->asteroidType = asteroidType;

	float asteroidScale = 0.3f;
	Health = 1.0f;

	switch (asteroidType) {
	case EAsteroidType::XLARGE:
		asteroidScale = 1.0f;
		Health = 100.0f;
		break;

	case EAsteroidType::LARGE:
		asteroidScale = 0.5f;
		Health = 50.0f;
		break;

	case EAsteroidType::MEDIUM:
		asteroidScale = 0.3f;
		Health = 24.0f;
		break;

	case EAsteroidType::SMALL:
		asteroidScale = 0.15f;
		Health = 6.0f;
		break;
	}
	SetActorScale3D(FVector(asteroidScale));

	FVector rotation = FMath::VRand();
	SetActorRotation(rotation.Rotation());
}

void AAsteroid::TakeHit(float damage) {
	Health -= damage;
	if (Health <= 0) {
		Health = -1.0f;
		OnAsteroidDestroyed();
	}
}

void AAsteroid::Tick(float DeltaSeconds) {
	WrapToPlayfield();
}

void AAsteroid::WrapToPlayfield() {

	AAsteroidGameState *gameState = Cast<AAsteroidGameState>(GetWorld()->GetGameState());
	FVector location = GetActorLocation();
	bool locationChanged = false;

	if (location.X < -gameState->PlayfieldSize) {
		location.X = gameState->PlayfieldSize;
		locationChanged = true;
	}
	else if (location.X > gameState->PlayfieldSize) {
		location.X = -gameState->PlayfieldSize;
		locationChanged = true;
	}

	if (location.Y < -gameState->PlayfieldSize) {
		location.Y = gameState->PlayfieldSize;
		locationChanged = true;
	}
	else if (location.Y > gameState->PlayfieldSize) {
		location.Y = -gameState->PlayfieldSize;
		locationChanged = true;
	}

	if (locationChanged) {
		SetActorLocation(location);
	}

}