

#pragma once

#include "GameFramework/GameStateBase.h"
#include "Asteroid.h"
#include "AsteroidGameState.generated.h"


/**
 * 
 */
UCLASS()
class ASTEROIDS_API AAsteroidGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Category = Game)
	float PlayfieldSize = 5000.0f;

	UPROPERTY(BlueprintReadWrite, Category = Game)
	TArray<AAsteroid*> Asteroids;

	UFUNCTION(BlueprintCallable, Category = Game)
	void SpawnLevelAsteroids(TSubclassOf<AAsteroid> AsteroidType, int numberToSpawn);

	UFUNCTION(BlueprintCallable, Category = Game)
	void SpawnAsteroidsAtLocation(TSubclassOf<AAsteroid> AsteroidClass, FVector location, EAsteroidType curAsteroidType, int numberToSpawn);

	UFUNCTION(BlueprintCallable, Category = Game)
	void SpawnAsteroidsAtParent(TSubclassOf<AAsteroid> AsteroidClass, AAsteroid* parentAsteroid, EAsteroidType curAsteroidType, int numberToSpawn);

	UFUNCTION(BlueprintCallable, Category = Game)
	void DestroyAsteroid(AAsteroid *asteroidToDestroy);

	UFUNCTION(BlueprintCallable, Category = Game)
	bool HasAllAsteroidsBeenDestroyed();

};
