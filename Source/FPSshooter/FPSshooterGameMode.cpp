// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSshooterGameMode.h"
#include "FPSshooterHUD.h"
#include "FPSshooterCharacter.h"
#include"Kismet/GameplayStatics.h"

AFPSshooterGameMode::AFPSshooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSshooterHUD::StaticClass();
}

void AFPSshooterGameMode::GameOver(APawn* CharacterBoy, bool bSeenORNot)
{
	if (CharacterBoy)
	{
		CharacterBoy->DisableInput(nullptr);

		if (SpectalatingViewPoint)
		{
			TArray<AActor*> ReturnedActor;
			UGameplayStatics::GetAllActorsOfClass(this, SpectalatingViewPoint, ReturnedActor);
			if (ReturnedActor.Num() > 0)
			{
				AActor* NewViewTarget = ReturnedActor[0];
				APlayerController* PC = Cast<APlayerController>(CharacterBoy->GetController());
				if (PC)
				{
					PC->SetViewTargetWithBlend(NewViewTarget, 1.0f, EViewTargetBlendFunction::VTBlend_Cubic);

				}
			}

		}



	}
		AfterGameOver(CharacterBoy,bSeenORNot);

}