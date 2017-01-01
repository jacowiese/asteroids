// Fill out your copyright notice in the Description page of Project Settings.

#include "Asteroids.h"
#include "AsteroidsGameModeBase.h"

void AAsteroidsGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) {
	Super::InitGame(MapName, Options, ErrorMessage);

	UE_LOG(LogTemp, Warning, TEXT("AsteroidsGameModeBase::InitGame called!"))
}

void AAsteroidsGameModeBase::InitGameState() {
	Super::InitGameState();

	UE_LOG(LogTemp, Warning, TEXT("AsteroidsGameModeBase::InitGameState called!"))
}
