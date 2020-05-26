// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSAIguard.generated.h"
class UPawnSensingComponent;
UCLASS()
class FPSSHOOTER_API AFPSAIguard : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSAIguard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Category="SenserPAwn")
	UPawnSensingComponent* PawnSense;

	

	UFUNCTION()
	void PawnSenseFunction(APawn* Senser);

	UFUNCTION()
	void PawnHearComponent(APawn* NoiseInstigator, const FVector& Location, float Volume);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
