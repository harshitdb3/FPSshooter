// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPSshooterGameMode.generated.h"

UCLASS(minimalapi)
class AFPSshooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFPSshooterGameMode();
	UFUNCTION()
	void GameOver(APawn* CharacterBoy, bool bSeenORNot);
	UFUNCTION(BlueprintImplementableEvent, Category = "aftergame")
		void AfterGameOver(APawn* CharacterBoy,bool bSeenORNot);

protected:
	UPROPERTY(EditDefaultsOnly, Category="viewactor")
	TSubclassOf<AActor>  SpectalatingViewPoint;
};



