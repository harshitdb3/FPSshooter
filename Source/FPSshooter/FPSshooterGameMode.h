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

	void GameOver(APawn* CharacterBoy);
	UFUNCTION(BlueprintImplementableEvent, Category ="aftergame")
	void AfterGameOver(APawn* CharacterBoy);
};



