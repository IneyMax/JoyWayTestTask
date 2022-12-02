// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/Ammo/AmmoBase.h"

// Sets default values
AAmmoBase::AAmmoBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAmmoBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAmmoBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float NewOffset = AmmoConfig.Speed * GetWorld()->DeltaTimeSeconds;
	CurrentFlightDistance += NewOffset;
	
	FHitResult CurrentHitResult;
	RootComponent->AddWorldOffset(GetActorForwardVector() * NewOffset, true, &CurrentHitResult);

	if (CurrentHitResult.bStartPenetrating || CurrentFlightDistance >= AmmoConfig.MaxFlightDistance)
	{
		Destroy();
	}
}

void AAmmoBase::Init(FAmmoConfig NewConfig)
{
	AmmoConfig = NewConfig;
}

