// Fill out your copyright notice in the Description page of Project Settings.

#include "Asteroids.h"
#include "Projectile.h"
#include "PlayerShip.h"

// Sets default values
APlayerShip::APlayerShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerShip::BeginPlay()
{
	Super::BeginPlay();
	ShipCurrentHealth = MaxHealth;
}

// Called every frame
void APlayerShip::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

// Called to bind functionality to input
/*void APlayerShip::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}*/

void APlayerShip::RotateShip(float inputVal) {
	float val = FMath::Clamp(inputVal, -1.0f, 1.0f) * TurnRate * GetWorld()->GetDeltaSeconds();
	AddActorLocalRotation(FRotator(0, val, 0));
}

void APlayerShip::ThrustShip(float inputVal) {
	float val = FMath::Clamp(inputVal, -1.0f, 1.0f) * ThrustRate;

	UPrimitiveComponent *pc = Cast<UPrimitiveComponent>(GetRootComponent());
	FVector fw = GetActorForwardVector();
	FVector direction = FVector(-fw.Y, fw.X, fw.Z) * val;
	pc->AddForceAtLocation(direction, pc->GetSocketLocation(FName("Thrusters")));
}

void APlayerShip::FireMainWeapon() {
	float gameTime = GetWorld()->GetTimeSeconds();
	if (gameTime - lastFireTime >= FireRate) {

		UStaticMeshComponent *shipMesh = Cast<UStaticMeshComponent>(GetRootComponent());
		if (!shipMesh) return;

		FVector loc = shipMesh->GetSocketLocation(FName("MainGun"));
		FRotator rot = GetActorRotation();

		AProjectile *projectile = Cast<AProjectile>(GetWorld()->SpawnActor(mainGunProjectile, &loc, &rot));
		if (projectile) {
			float projectileSpeed = projectile->GetProjectileSpeed();
			
			UPrimitiveComponent *projectilePC = Cast<UPrimitiveComponent>(projectile->GetRootComponent());
			if (projectilePC) {
				FVector forward = GetActorForwardVector();
				FVector projectileDirection = FVector(-forward.Y, forward.X, forward.Z);
				projectilePC->AddImpulse(projectileDirection * projectileSpeed);
			}
		}

		lastFireTime = gameTime;
	}
}