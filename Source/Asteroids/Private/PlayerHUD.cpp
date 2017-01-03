

#include "Asteroids.h"
#include "PlayerShip.h"
#include "PlayerHUD.h"

void APlayerHUD::DrawHUD() {
	Super::DrawHUD();

	DrawBars();
}

void APlayerHUD::DrawBars() {
	APlayerShip *playerShip = Cast<APlayerShip>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (playerShip) {

		float healthWidth = playerShip->ShipCurrentHealth / playerShip->MaxHealth;
		DrawText(TEXT("Ship Hull:"), FLinearColor::White, LocationX, LocationY);
		DrawRect(FLinearColor::Yellow, LocationX + 60, LocationY, BarWidth, BarHeight);
		DrawRect(FLinearColor::Blue, LocationX + 61, LocationY + 1, (BarWidth - 2) * healthWidth, BarHeight - 2);

		float rateWidth = 1-((playerShip->FireRate - playerShip->MinFireRate) / (playerShip->MaxFireRate - playerShip->MinFireRate));
		DrawText(TEXT("Fire Rate:"), FLinearColor::White, LocationX, LocationY + 20);
		DrawRect(FLinearColor::Yellow, LocationX + 60, LocationY + 20, BarWidth, BarHeight);
		DrawRect(FLinearColor::Red, LocationX + 61, LocationY + 21, (BarWidth - 2) * rateWidth, BarHeight - 2);
	}
}