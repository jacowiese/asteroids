// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "PlayerShipController.generated.h"

class APlayerShip;

/**
 * 
 */
UCLASS()
class ASTEROIDS_API APlayerShipController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Reference)
	APlayerShip *GetPlayerShip();
	
};
