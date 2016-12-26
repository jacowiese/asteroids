// Fill out your copyright notice in the Description page of Project Settings.

#include "Asteroids.h"
#include "PlayerShipController.h"
#include "PlayerShip.h"

APlayerShip *APlayerShipController::GetPlayerShip() {
	return Cast<APlayerShip>(GetPawn());
}