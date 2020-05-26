// Fill out your copyright notice in the Description page of Project Settings.


#include "LaunchPad.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"
// Sets default values
ALaunchPad::ALaunchPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LaunchPadBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaunchPadBox"));
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetBoxExtent(FVector(75, 75, 50));
	RootComponent = OverlapComp;
	LaunchPadBox->SetupAttachment(OverlapComp);

	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &ALaunchPad::OverlapComponent);

	LaunchAngle = 35.0f;
	LaunchStrength = 1500;


}

// Called when the game starts or when spawned
void ALaunchPad::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALaunchPad::OverlapComponent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FRotator RotationDirection = GetActorRotation();
	RotationDirection.Pitch += LaunchAngle;
	FVector LaunchDirection = RotationDirection.Vector() * LaunchStrength;
	ACharacter* FPScharacter = Cast<ACharacter>(OtherActor);
	if (FPScharacter)
	{
		FPScharacter->LaunchCharacter(LaunchDirection, true, true);


	} 
	else if(OtherComp && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulse(LaunchDirection, NAME_None, true);

	}




}

// Called every frame
void ALaunchPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

