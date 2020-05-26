// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaunchPad.generated.h"


class UBoxComponent;
class UStaticMeshComponent;
UCLASS()
class FPSSHOOTER_API ALaunchPad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaunchPad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,Category="launchpad")
	UStaticMeshComponent* LaunchPadBox;

	UPROPERTY(VisibleAnywhere, Category = "launchpad")
	UBoxComponent* OverlapComp;

	UFUNCTION()
	void OverlapComponent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditInstanceOnly,Category ="launchpad")
	float LaunchStrength;
	UPROPERTY(EditInstanceOnly, Category ="launchpad")
	float LaunchAngle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
