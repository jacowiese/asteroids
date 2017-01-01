// Fill out your copyright notice in the Description page of Project Settings.

#include "Asteroids.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	float playfieldSize = 5000.0f; // TODO: Remove magic playfield size and set up correctly in blueprint

	bool toBeDestroyed = false;
	FVector location = GetActorLocation();
	if (location.X < -playfieldSize) {
		toBeDestroyed = true;
	}
	if (location.Y < -playfieldSize) {
		toBeDestroyed = true;
	}
	if (location.X > playfieldSize) {
		toBeDestroyed = true;
	}
	if (location.Y > playfieldSize) {
		toBeDestroyed = true;
	}

	if (toBeDestroyed) {
		GetWorld()->DestroyActor(this);
	}
}

// Get Projectile Speed
float AProjectile::GetProjectileSpeed() {
	return ProjectileSpeed;
}

// Get Projectile Damage
float AProjectile::GetProjectileDamage() {
	return ProjectileDamage;
}
