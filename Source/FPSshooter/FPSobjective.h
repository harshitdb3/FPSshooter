// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSobjective.generated.h"

class UParticleSystem;
class USphereComponent;

UCLASS()
class FPSSHOOTER_API AFPSobjective : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSobjective();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere,Category="components")
	USphereComponent* SphereComp;

	UPROPERTY(VisibleAnywhere, Category = "components")
	UStaticMeshComponent* MeshComp;

	
	void CreatePartcleEffects();

	UPROPERTY(EditDefaultsOnly, Category = "components")
	UParticleSystem* ParticleEffects;

	

	
	
public:	
	
	

	virtual void NotifyActorBeginOverlap(AActor* OtherActor)override;
};
