// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSextrationzone.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "FPSshooterGameMode.h"
#include "FPSshooterCharacter.h"
// Sets default values
AFPSextrationzone::AFPSextrationzone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapComp->SetBoxExtent(FVector(200.0f));
	RootComponent = OverlapComp;
	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AFPSextrationzone::OverlapFunction);
	DecalComp = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComp"));
	DecalComp->DecalSize = FVector(200.0f);
	DecalComp->SetupAttachment(OverlapComp);


}

// Called when the game starts or when spawned
void AFPSextrationzone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSextrationzone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSextrationzone::OverlapFunction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("overlaped with extraction zone"));

	AFPSshooterCharacter* CollectorBoy = Cast<AFPSshooterCharacter>(OtherActor);
	if (CollectorBoy && CollectorBoy->IsCarringObjective)
	{
		AFPSshooterGameMode* GameModer = Cast<AFPSshooterGameMode>(GetWorld()->GetAuthGameMode());
		if (GameModer) {

			GameModer->GameOver(CollectorBoy);
		}


	}


}

