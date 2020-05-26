// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSshooterGameMode.h"
#include "FPSshooterHUD.h"
#include "FPSshooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPSshooterGameMode::AFPSshooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSshooterHUD::StaticClass();
}

void AFPSshooterGameMode::GameOver(APawn* CharacterBoy)
{
	if (CharacterBoy)
	{
		CharacterBoy->DisableInput(nullptr);
	}
		AfterGameOver(CharacterBoy);

}