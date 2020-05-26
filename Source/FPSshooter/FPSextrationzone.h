// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSextrationzone.generated.h"
class UBoxComponent;
class UDecalComponent;

UCLASS()
class FPSSHOOTER_API AFPSextrationzone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSextrationzone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, Category = "component")
		UBoxComponent* OverlapComp;
	UPROPERTY(VisibleAnywhere, Category = "component")
	UDecalComponent* DecalComp;

	UFUNCTION()
		void OverlapFunction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
