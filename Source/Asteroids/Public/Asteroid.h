// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "Asteroid.generated.h"

/*
 * Asteroid Type Enumerator
 */

UENUM(BlueprintType)
enum class EAsteroidType : uint8 {
	SMALL,
	MEDIUM,
	LARGE,
	XLARGE
};

/**
 * 
 */
UCLASS()
class ASTEROIDS_API AAsteroid : public AStaticMeshActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = Properties)
	float Health = 100.0f;

	void WrapToPlayfield();

public:

	AAsteroid();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void InitialiseAsteroid(EAsteroidType asteroidType);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	EAsteroidType asteroidType;
	
	UFUNCTION(BlueprintCallable, Category = Health)
	void TakeHit(float damage);
	
	UFUNCTION(BlueprintImplementableEvent, Category = Health)
	void OnAsteroidDestroyed();

	virtual void Tick(float DeltaSeconds) override;

};
