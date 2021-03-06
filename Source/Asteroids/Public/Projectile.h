// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class ASTEROIDS_API AProjectile : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "WeaponSystem")
	float ProjectileSpeed = 1500.0f;

	UPROPERTY(EditAnywhere, Category = "WeaponSystem")
	float ProjectileDamage = 4.0f;

	UPROPERTY(EditAnywhere, Category = "WeaponSystem")
	float Life = 3.0f;

public:	
	// Sets default values for this actor's properties
	AProjectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	float GetProjectileSpeed();

	UFUNCTION(BlueprintCallable, Category = "DamageSystem")
	float GetProjectileDamage();
	
};
