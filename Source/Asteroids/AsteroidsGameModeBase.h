// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "AsteroidsGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDS_API AAsteroidsGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	bool GameInPlay = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	int NumberOfAsteroids = 3;

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	
	virtual void InitGameState() override;

};
