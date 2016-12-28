// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PlayerShip.generated.h"

class AProjectile;

UCLASS()
class ASTEROIDS_API APlayerShip : public APawn
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxHealth = 100.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float TurnRate = 165.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float ThrustRate = 6.0f;

	UPROPERTY(EditAnywhere, Category = WeaponSystem)
	float FireRate = 0.250f;

	float lastFireTime = 0.0f;

	UPROPERTY(EditAnywhere, Category = WeaponSystem)
	TSubclassOf<AProjectile> mainGunProjectile;

public:
	UPROPERTY(BlueprintReadonly, Category = Status)
		float ShipCurrentHealth;

	// Sets default values for this pawn's properties
	APlayerShip();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	UFUNCTION(BlueprintCallable, Category = Movement)
	void RotateShip(float inputVal);

	UFUNCTION(BlueprintCallable, Category = Movement)
	void ThrustShip(float inputVal);

	UFUNCTION(BlueprintCallable, Category = WeaponSystem)
	bool FireMainWeapon();
};
