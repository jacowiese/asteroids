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
	LARGE
};

/**
 * 
 */
UCLASS()
class ASTEROIDS_API AAsteroid : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	EAsteroidType asteroidType;
	
	
};
