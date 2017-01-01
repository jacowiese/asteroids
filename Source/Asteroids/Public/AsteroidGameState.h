

#pragma once

#include "GameFramework/GameStateBase.h"
#include "AsteroidGameState.generated.h"

class AAsteroid;

/**
 * 
 */
UCLASS()
class ASTEROIDS_API AAsteroidGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Category = Game)
	TArray<AAsteroid*> Asteroids;

	UFUNCTION(BlueprintCallable, Category = Game)
	void SpawnLevelAsteroids(TSubclassOf<AAsteroid> AsteroidType, int numberToSpawn, float playfieldSize);

	UFUNCTION(BlueprintCallable, Category = Game)
	void SpawnAsteroidsAtLocation(TSubclassOf<AAsteroid> AsteroidClass, FVector location, EAsteroidType curAsteroidType, int numberToSpawn);

	UFUNCTION(BlueprintCallable, Category = Game)
	void DestroyAsteroid(AAsteroid *asteroidToDestroy);

	UFUNCTION(BlueprintCallable, Category = Game)
	bool HasAllAsteroidsBeenDestroyed();

};
