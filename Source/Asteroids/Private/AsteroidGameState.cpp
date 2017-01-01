

#include "Asteroids.h"
#include "Asteroid.h"
#include "AsteroidGameState.h"

void AAsteroidGameState::SpawnLevelAsteroids(TSubclassOf<AAsteroid> AsteroidType, int numberToSpawn) {
	for (int i = 0; i < numberToSpawn; i++) {

		FTransform transform;
		FVector newLocation = FMath::VRand() * PlayfieldSize;
		newLocation.Z = 0.0f;
		transform.SetLocation(newLocation);

		FActorSpawnParameters spawnParameters;
		spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		auto asteroid = Cast<AAsteroid>(GetWorld()->SpawnActor(AsteroidType, &transform, spawnParameters));
		if (asteroid != nullptr) {
			asteroid->InitialiseAsteroid(EAsteroidType::XLARGE);

			Asteroids.Add(asteroid);
		}
	}
}

void AAsteroidGameState::SpawnAsteroidsAtLocation(TSubclassOf<AAsteroid> AsteroidClass, FVector location, EAsteroidType curAsteroidType, int numberToSpawn) {
	EAsteroidType toSpawnType;
	switch (curAsteroidType) {
	case EAsteroidType::XLARGE:
		toSpawnType = EAsteroidType::LARGE;
		break;
	case EAsteroidType::LARGE:
		toSpawnType = EAsteroidType::MEDIUM;
		break;
	case EAsteroidType::MEDIUM:
		toSpawnType = EAsteroidType::SMALL;
		break;
	case EAsteroidType::SMALL:
		return; // When the current asteroid is SMALL, get out, nothing to spawn
	}

	for (int i = 0; i < numberToSpawn; i++) {
		FTransform transform;
		transform.SetLocation(location);

		FActorSpawnParameters spawnParameters;
		spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		auto asteroid = Cast<AAsteroid>(GetWorld()->SpawnActor(AsteroidClass, &transform, spawnParameters));
		if (asteroid != nullptr) {
			asteroid->InitialiseAsteroid(toSpawnType);

			Asteroids.Add(asteroid);
		}
	}
}

void AAsteroidGameState::DestroyAsteroid(AAsteroid *asteroidToDestroy) {
	for (int i = 0; i < Asteroids.Num(); i++) {
		if (Asteroids[i] == asteroidToDestroy) {
			// Destroy this asteroid!
			Asteroids.RemoveAt(i);
			GetWorld()->DestroyActor(asteroidToDestroy);
			break;
		}
	}
}

bool AAsteroidGameState::HasAllAsteroidsBeenDestroyed() {
	return Asteroids.Num() <= 0;
}
