// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSobjective.h"
#include "components/SphereComponent.h"
#include "components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FPSshooterCharacter.h"

// Sets default values
AFPSobjective::AFPSobjective()
{
 	

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
		SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RootComponent = MeshComp;
	SphereComp->SetupAttachment(MeshComp);
	

}

// Called when the game starts or when spawned
void AFPSobjective::BeginPlay()
{
	Super::BeginPlay();
	
	CreatePartcleEffects();
}

void AFPSobjective::CreatePartcleEffects()
{

	UGameplayStatics::SpawnEmitterAtLocation(this, ParticleEffects, GetActorLocation());

}



void AFPSobjective::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	AFPSshooterCharacter* MyCharacter = Cast<AFPSshooterCharacter>(OtherActor);
		if (MyCharacter)
		{
			MyCharacter->IsCarringObjective = true;
			Destroy();

		}

	CreatePartcleEffects();

	
	
}

