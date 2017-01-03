

#pragma once

#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

class APlayerShip;

/**
 * 
 */
UCLASS()
class ASTEROIDS_API APlayerHUD : public AHUD
{
	GENERATED_BODY()
	
private:
	void DrawBars();

public:

	UPROPERTY(BlueprintReadWrite, Category = Setup)
	float LocationX = 20.0f;

	UPROPERTY(BlueprintReadWrite, Category = Setup)
	float LocationY = 20.0f;

	UPROPERTY(BlueprintReadWrite, Category = Setup)
	float BarWidth = 150.0f;

	UPROPERTY(BlueprintReadWrite, Category = Setup)
	float BarHeight = 15.0f;

	virtual void DrawHUD() override;
	
};
