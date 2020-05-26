// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSAIguard.h"
#include"Perception/PawnSensingComponent.h"
#include"DrawDebugHelpers.h"
#include "Math/Vector.h"
// Sets default values
AFPSAIguard::AFPSAIguard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PawnSense = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSense"));
	PawnSense->OnSeePawn.AddDynamic(this, &AFPSAIguard::PawnSenseFunction);
	PawnSense->OnHearNoise.AddDynamic(this, &AFPSAIguard::PawnHearComponent);
}

// Called when the game starts or when spawned
void AFPSAIguard::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFPSAIguard::PawnSenseFunction(APawn* Senser)
{
	if (Senser == nullptr) 
	{

		return;
	}
	DrawDebugSphere(GetWorld(), Senser->GetActorLocation(), 35.0f, 12, FColor::Black, false, 10.0f);
}

void AFPSAIguard::PawnHearComponent(APawn* NoiseInstigator, const FVector& Location, float Volume)
{

	DrawDebugSphere(GetWorld(), Location, 35.0f, 12, FColor::Red, false, 10.0f);

	FVector Direction = Location - GetActorLocation();
	Direction.Normalize();
	FRotator newrotation;
	newrotation = Direction.ToOrientationRotator();
	newrotation.Pitch = 0.0f;
	newrotation.Roll = 0.0f;
	SetActorRotation(newrotation);

}

// Called every frame
void AFPSAIguard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
